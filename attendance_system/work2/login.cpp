#include "login.h"
#include "ui_login.h"

#include <QMessageBox>
#include <QDebug>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->lineEdit_cardID->setFocus();
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    struct PortSettings myComSetting = {BAUD14400,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,10};//定义一个结构体，
    myCom = new Posix_QextSerialPort("/dev/ttyS1",myComSetting,QextSerialBase::Polling);//定义串口对象，并传递参数，在构造函数里对其进行初始化
    bool bl =  myCom ->open(QIODevice::ReadWrite);//以可读写方式打开串口
    qDebug()<<bl;
    readTimer = new QTimer(this);
    readTimer->start(100);//设置延时为100ms
    connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));
}

login::~login()
{
    delete ui;
}

void login::readMyCom() //读串口函数
{
    QString str;
    QByteArray recv = myCom->readAll();//读取串口缓冲区的所有数据给临时变量
    if(recv.length()!=0)
    {
        for(int i=0;i<(recv.length()-4);i++)
        {
            str+=recv[i+1];
        }
        qDebug()<<"从串口读到的数据为:"<<str;
        this->ui->lineEdit_cardID->setText(str);//将串口的数据显示在窗口中
    }
}
void login::on_pushButton_login_clicked()
{
    db_func d;
    d.db_open();
    if(ui->lineEdit_cardID->text().isEmpty())
    {
        QMessageBox::information(this,tr("请输入用户名"),tr("请先输入用户名再登录"),QMessageBox::Yes);
        ui->lineEdit_cardID->setFocus();
    }
    else if(ui->lineEdit_password->text().isEmpty())
    {
        QMessageBox::information(this,tr("请输入用户密码"),tr("请先输入用户密码再登录"),QMessageBox::Yes);
        ui->lineEdit_password->setFocus();
    }
    else
    {
        QSqlQuery query;
        user_ID=ui->lineEdit_cardID->text();
        user_pass=ui->lineEdit_password->text();
        QString sql="select staff_name,staff_login_pass from baseinfo where cardID='"+user_ID+"' and staff_login_pass='"+user_pass+"'";
        query.exec(sql);
        if(query.next())
        {
            this->close();
            QString sql="";
            myindex *i=new myindex(0,sql);
            i->show();
        }
        else
        {
            QMessageBox::information(this,tr("error"),tr("请重新输入用户名和密码再登录"),QMessageBox::Yes);
        }
    }
    d.db_close();
}

void login::on_pushButton_cancle_clicked()
{
    this->close();
}
