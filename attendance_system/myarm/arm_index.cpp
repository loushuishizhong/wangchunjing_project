#include "arm_index.h"
#include "ui_arm_index.h"

arm_index::arm_index(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::arm_index)
{
    ui->setupUi(this);

    //串口
    struct PortSettings myComSetting = {BAUD9600,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,10};//定义一个结构体，
    myCom = new Posix_QextSerialPort("/dev/ttySAC3",myComSetting,QextSerialBase::Polling);//定义串口对象，并传递参数，在构造函数里对其进行初始化
    //qDebug()<<"aaaaa";
    bool bl =  myCom ->open(QIODevice::ReadWrite);//以可读写方式打开串口
    qDebug()<<bl;
    readTimer = new QTimer(this);
    readTimer->start(1000);//设置延时为1000ms
    connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));

    //http
    manager = new QNetworkAccessManager(this);  //新建QNetworkAccessManager对象
    manager1 = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));//关联信号和槽
    connect(manager1,SIGNAL(finished(QNetworkReply*)),this,SLOT(addFinished(QNetworkReply*)));

    //ftp
    ftp=new QFtp(this);
    ftp->connectToHost("192.168.137.231");//连接到服务器
    ftp->login("ftp"); //登录
    connect(ftp,SIGNAL(commandStarted(int)),this,SLOT(ftpCommandStarted(int)));//当每条命令开始执行时发出相应的信号
    connect(ftp,SIGNAL(commandFinished(int,bool)),this,SLOT(ftpCommandFinished(int,bool)));//当每条命令执行结束时发出相应的信号

    //camera
    video=new videodevice();
    fd=video->open_device("/dev/video0");

}

arm_index::~arm_index()
{
    delete ui;;
    video->close_device(fd);
}

/*****************************************
 *串口
 ****************************************/
void arm_index::readMyCom() //读串口函数
{
    QString str;
    QByteArray recv = myCom->readAll();//读取串口缓冲区的所有数据给临时变量
    if(recv.length()!=0)
    {
        this->clearAll();           //清空显示
        for(int i=0;i<(recv.length()-4);i++)
        {
            str+=recv[i+1];
        }
        qDebug()<<"read data from UART:"<<str;
        ui->label_cardID->clear();
        ui->label_cardID->setText(str);//将串口的数据显示在窗口中
        manager->get(QNetworkRequest(QUrl("http://192.168.137.231/cgi-bin/find_Staff.cgi?cardID="+str+""))); //发送请求
    }
}

/*************************************
 *http
 ************************************/
void arm_index::replyFinished(QNetworkReply *reply)  //http当回复结束后
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");

    for(int i=0;i<3;i++)
        reply->readLine();
    //使用utf8编码，这样才可以显示中文
    QString sign = codec->toUnicode(reply->readLine());
    QString result = codec->toUnicode(reply->readLine());
    if(sign=="error\n")
        ui->label_welcom->setText(result);
    if(sign=="ok\n")
        ui->label_welcom->setText(result);
    if(sign=="result\n")
    {
        QString name;
        QString department;
        QString photo;
        int i=0;
        if(result.length()>0)
        {
            while(result.at(i)!=',')
            {
                name=name+result.at(i);
                i++;
            }
            ui->label_name->setText(name);
            i++;
            while(result.at(i)!=',')
            {
                department=department+result.at(i);
                i++;
            }
            ui->label_department->setText(department);
            i++;
            int num=0;
            while(num<4)
            {
                while(result.at(i)!='/')
                    i++;
                num++;
                i++;
            }
            while(result.at(i)!='\n')
            {
                photo=photo+result.at(i);
                i++;
            }
            qDebug()<<photo;
        }

        ftp->cd("/org_images"); //跳转到org_images目录下
        file=new QFile("1.jpg");
        if (!file->open(QIODevice::WriteOnly)) {
            QMessageBox::information(0, tr("FTP"),tr("无法保存文件 %1: %2.").arg("1.jpg").arg(file->errorString()));
            delete file;
            return;
        }
        ftp->get(photo,file);//FTP下载图片

//        QPixmap *pixmap=new QPixmap("1.jpg");
//        QPixmap image=pixmap->scaled(ui->label_org_photo->width(),ui->label_org_photo->height());
//        ui->label_org_photo->setPixmap(image);

//        QDir qdir;          //删除本地下载的照片
//        qdir.remove("1.jpg");

        this->takePhoto();//拍照
    }
    reply->deleteLater();   //最后要释放reply对象
}

void arm_index::addFinished(QNetworkReply *reply)  //当http回复结束后
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    for(int i=0;i<3;i++)
        codec->toUnicode(reply->readLine());
    //使用utf8编码，这样才可以显示中文
    QString sign = codec->toUnicode(reply->readLine());
    QString result = codec->toUnicode(reply->readLine());
    qDebug()<<result;
    if(sign=="error\n")
        ui->label_welcom->setText(result);
    if(sign=="ok\n")
        ui->label_welcom->setText(result);
    reply->deleteLater();   //最后要释放reply对象
}

/****************************************
 *ftp
 ***************************************/
void arm_index::ftpCommandStarted(int)
{
    if(ftp->currentCommand()==QFtp::ConnectToHost){
        ui->label_welcom->setText(tr("正在连接到服务器…"));
    }
    if(ftp->currentCommand()==QFtp::Login){
        ui->label_welcom->setText(tr("正在登录…"));
    }
    if(ftp->currentCommand()==QFtp::Get){
        ui->label_welcom->setText(tr("正在下载…"));
        //sleep(1);
    }
    else if(ftp->currentCommand()==QFtp::Close){
        ui->label_welcom->setText(tr("正在关闭连接…"));
    }
}

void arm_index::ftpCommandFinished(int,bool error)
{
    if(ftp->currentCommand()==QFtp::ConnectToHost){
        if(error)ui->label_welcom->setText(tr("连接服务器出现错误：%1").arg(ftp->errorString()));
        else ui->label_welcom->setText(tr("连接到服务器成功"));
    }
    if(ftp->currentCommand()==QFtp::Login){
        if(error) ui->label_welcom->setText(tr("登 录 出 现 错 误 ：%1").arg(ftp->errorString()));
        else ui->label_welcom->setText(tr("登录成功"));
    }
    if(ftp->currentCommand()==QFtp::Get){
        if(error)
            ui->label_welcom->setText(tr("下 载 出 现 错 误 ：%1").arg(ftp->errorString()));
        else{
            ui->label_welcom->setText(tr("已经完成下载"));
            QPixmap *pixmap=new QPixmap("1.jpg");
            QPixmap image=pixmap->scaled(ui->label_org_photo->width(),ui->label_org_photo->height());
            ui->label_org_photo->setPixmap(image);
            QDir qdir;
            qdir.remove("1.jpg");   //删除本地下载的照片

        }

    }
    else if(ftp->currentCommand()==QFtp::Close){
        ui->label_welcom->setText(tr("已经关闭连接"));
    }
}

/********************************************
 *拍照
 *******************************************/
void arm_index::takePhoto()
{
    QUuid id = QUuid::createUuid();
    QString strId = id.toString();
    QTime theTime = QTime::currentTime();
    dir=strId+QString::number(theTime.hour(),10)+QString::number(theTime.minute(),10)+QString::number(theTime.second(),10)+".jpg";

    video->v4l2_save_rgb16_to_jpg(fd,320,240,dir.toAscii().data());
    frame = new QImage(dir);
    QImage image=frame->scaled(ui->label_new_photo->width(),ui->label_new_photo->height());
    ui->label_new_photo->setPixmap(QPixmap::fromImage(image,Qt::AutoColor));

    //frame->save(dir,"JPG");

    /****************
     *FTP上传图片
     ****************/
    ftp->cd("/rec_images"); //跳转到rec_images目录下
    QFile *file2=new QFile(dir);
    file2->open(QIODevice::ReadOnly);
    ftp->put(file2,dir);
    ftp->close(); //关闭连接

    QDir qdir;
    qdir.remove(dir);       //删除本地采集到的照片
    //qdir.remove("1.jpg");   //删除本地下载的照片

    /****************
     *添加考勤记录
     ****************/
    QString cardID=ui->label_cardID->text();
    QString staff_photo="/srv/ftp/rec_images/"+dir;
    manager1->get(QNetworkRequest(QUrl("http://192.168.137.231/cgi-bin/add_record.cgi?ID="+cardID+"&photo="+staff_photo+"")));
}

void arm_index::clearAll()
{
    ui->label_cardID->clear();
    ui->label_name->clear();
    ui->label_department->clear();
    ui->label_new_photo->clear();
    ui->label_org_photo->clear();
    ui->label_welcom->setText("祝你今天有一个快乐的心情!");
}
