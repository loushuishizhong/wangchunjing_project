#include "myindex.h"
#include "ui_myindex.h"
#include <QDebug>
#include <QTextCodec>
#include <QFileDialog>

#include "db_func.h"

myindex::myindex(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myindex)
{
    ui->setupUi(this);

    sql="";

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    this->ui->stackedWidget->hide();
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(tableViewClicked()));//触发点击事件

    system_date=QDate::currentDate();//获取系统时间
    //qDebug()<<system_date.toString("yyyy-MM-dd");

    ui->dateEdit_start->setDisplayFormat("yyyy-MM-dd");//设置显示格式
    ui->dateEdit_end->setDisplayFormat("yyyy-MM-dd");

    ui->dateEdit_end->setDate(system_date);//设置初始值，起始日期与终止日期相差一个月
    system_date.setDate(system_date.year(),system_date.month()-1,system_date.day());
    ui->dateEdit_start->setDate(system_date);

    ui->calendarWidget_starttime->hide();
    connect(ui->pushButton_starttime,SIGNAL(clicked()),ui->calendarWidget_starttime,SLOT(show()));
    ui->calendarWidget_starttime->setSelectionMode(QCalendarWidget::SingleSelection);
    connect(ui->calendarWidget_starttime,SIGNAL(clicked(const QDate &)),this,SLOT(setdate()));
    ui->calendarWidget_endtime->hide();
    connect(ui->pushButton_endtime,SIGNAL(clicked()),ui->calendarWidget_endtime,SLOT(show()));
    ui->calendarWidget_endtime->setSelectionMode(QCalendarWidget::SingleSelection);
    connect(ui->calendarWidget_endtime,SIGNAL(clicked(const QDate &)),this,SLOT(setdate1()));

    connect(ui->tableView_2,SIGNAL(clicked(QModelIndex)),this,SLOT(tableViewClicked_2()));//触发点击事件
}

myindex::~myindex()
{
    delete ui;
}

void myindex::readMyCom() //读串口函数
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

void myindex::on_pushButton_exit_clicked()
{
    this->close();
}

void myindex::on_pushButton_baseinfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->show();

    model=new QSqlTableModel();

    model->database().exec("SET NAMES latin1");
    model->setTable("baseinfo");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->setFilter(sql);
    model->select();
    if(!model->query().next())
    {
        QMessageBox::information(this,tr("提示"),tr("查询到的数据为空!"),QMessageBox::Yes);
    }
    sql="";

    model->removeColumn(10);

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("卡号"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("性别"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("照片"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("身份证号"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("出生年月"));

    model->setHeaderData(6,Qt::Horizontal,QObject::tr("电话"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("住址"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("部门"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("职位"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("密码"));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    model->database().close();

    struct PortSettings myComSetting = {BAUD14400,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,10};//定义一个结构体，
    myCom = new Posix_QextSerialPort("/dev/ttyS1",myComSetting,QextSerialBase::Polling);//定义串口对象，并传递参数，在构造函数里对其进行初始化
    bool bl =  myCom ->open(QIODevice::ReadWrite);//以可读写方式打开串口
    qDebug()<<bl;

    readTimer = new QTimer(this);
    readTimer->start(100);//设置延时为100ms
    connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));

}

void myindex::tableViewClicked()    //触发点击事件
{
    int curRow = ui->tableView->currentIndex().row();

    ui->lineEdit_cardID->setText(model->index(curRow,0).data().toString());
    ui->lineEdit_name->setText(model->index(curRow,1).data().toString());

    if(model->index(curRow,2).data().toString() == "男")
        ui->comboBox_sex->setCurrentIndex(1);
    else
        ui->comboBox_sex->setCurrentIndex(2);

    QString click_dir=model->index(curRow,3).data().toString();
    QPixmap *pixmap=new QPixmap(click_dir);
    ui->label_photo->setPixmap(*pixmap);

    ui->lineEdit_ID->setText(model->index(curRow,4).data().toString());

    int date=model->index(curRow,5).data().toInt();
    int year=date/100-1990+1;
    int month=date%100;
    ui->comboBox_year->setCurrentIndex(year);
    ui->comboBox_month->setCurrentIndex(month);

    ui->lineEdit_phone->setText(model->index(curRow,6).data().toString());

    ui->lineEdit_address->setText(model->index(curRow,7).data().toString());
    if(model->index(curRow,8).data().toString()==NULL)
        ui->comboBox_department->setCurrentIndex(0);
    else if(model->index(curRow,8).data().toString()=="销售部")
        ui->comboBox_department->setCurrentIndex(1);
    else if(model->index(curRow,8).data().toString()=="董事会")
        ui->comboBox_department->setCurrentIndex(2);
    else if(model->index(curRow,8).data().toString()=="后勤部")
        ui->comboBox_department->setCurrentIndex(3);
    else if(model->index(curRow,8).data().toString()=="技术部")
        ui->comboBox_department->setCurrentIndex(4);
    else
        ui->comboBox_department->setCurrentIndex(5);

    if(model->index(curRow,9).data().toString()==NULL)
        ui->comboBox_position->setCurrentIndex(0);
    if(model->index(curRow,9).data().toString()=="经理")
        ui->comboBox_position->setCurrentIndex(1);
    else if(model->index(curRow,9).data().toString()=="员工")
        ui->comboBox_position->setCurrentIndex(2);
    else
        ui->comboBox_position->setCurrentIndex(3);
}

void myindex::on_pushButton_selectphoto_clicked()
{
    photo_dir = QFileDialog::getOpenFileName(this);
    if(!photo_dir.isEmpty())
    {
        QPixmap *pixmap=new QPixmap(photo_dir);
        ui->label_photo->setPixmap(*pixmap);
    }
}

void myindex::on_pushButton_add_clicked()   //add staff
{
    struct Staff staff;
    staff.card_ID=ui->lineEdit_cardID->text();
    staff.staff_name=ui->lineEdit_name->text();
    staff.staff_sex=ui->comboBox_sex->currentText();

    staff.staff_photo=photo_dir;
    qDebug()<<staff.staff_photo;

    staff.staff_birth=ui->comboBox_year->currentText()+ui->comboBox_month->currentText();
    staff.staff_ID=ui->lineEdit_ID->text();
    staff.staff_phone=ui->lineEdit_phone->text();
    staff.staff_address=ui->lineEdit_address->text();
    staff.staff_department=ui->comboBox_department->currentText();
    staff.staff_position=ui->comboBox_position->currentText();
    staff.staff_login_pass=ui->lineEdit_password->text();
    if(staff.card_ID==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("卡号不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_name==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("姓名不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_sex==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("性别不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_phone==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("电话不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_ID==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("身份证号不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_photo==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("照片不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_address==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("住址不能为空!"),QMessageBox::Yes);
    }
    else
    {
        db_func d;
        d.db_open();
        if(!d.addStaff(staff))
        {
            QMessageBox::information(this,tr("错误"),tr("添加失败!"),QMessageBox::Yes);
        }
        else
        {
            on_pushButton_clear_clicked();
            on_pushButton_baseinfo_clicked();
        }
        d.db_close();
    }
}

void myindex::on_pushButton_delete_clicked()    //delete staff
{
    struct Staff staff;
    staff.card_ID=ui->lineEdit_cardID->text();
    db_func d;
    d.db_open();
    if(!d.deleteStaff(staff))
    {
        QMessageBox::information(this,tr("错误"),tr("删除失败!"),QMessageBox::Yes);
    }
    else
    {
        on_pushButton_clear_clicked();
        on_pushButton_baseinfo_clicked();
    }
    d.db_close();
}

void myindex::on_pushButton_find_clicked()  //find staff
{
    struct Staff staff;
    if(ui->lineEdit_cardID->text()==NULL) staff.card_ID="%";
    else staff.card_ID=ui->lineEdit_cardID->text();

    if(ui->lineEdit_name->text()==NULL) staff.staff_name="%";
    else staff.staff_name=ui->lineEdit_name->text();

    if(ui->comboBox_sex->currentText()==NULL) staff.staff_sex="%";
    else staff.staff_sex=ui->comboBox_sex->currentText();

    if(ui->lineEdit_ID->text()==NULL) staff.staff_ID="%";
    else staff.staff_ID=ui->lineEdit_ID->text();

    if(ui->comboBox_year->currentText()==NULL || ui->comboBox_month->currentText()==NULL) staff.staff_birth="%";
    else staff.staff_birth=ui->comboBox_year->currentText()+ui->comboBox_month->currentText();

    if(ui->lineEdit_phone->text()==NULL) staff.staff_phone="%";
    else staff.staff_phone=ui->lineEdit_phone->text();

    if(ui->lineEdit_address->text()==NULL) staff.staff_address="%";
    else staff.staff_address=ui->lineEdit_address->text();

    if(ui->comboBox_department->currentText()==NULL) staff.staff_department="%";
    else staff.staff_department=ui->comboBox_department->currentText();

    if(ui->comboBox_position->currentText()==NULL) staff.staff_position="%";
    else staff.staff_position=ui->comboBox_position->currentText();

    qDebug()<<staff.card_ID<<","<<staff.staff_name<<staff.staff_ID<<staff.staff_sex;

    sql="cardID like '"+staff.card_ID+"' and staff_name like '"+staff.staff_name+"' and staff_sex like '"+staff.staff_sex+"' and staff_ID like '"+staff.staff_ID+"' and staff_birth like '"+staff.staff_birth+"' and staff_phone like '"+staff.staff_phone+"' and staff_address like '"+staff.staff_address+"' and staff_department like '"+staff.staff_department+"' and staff_position like '"+staff.staff_position+"'";
    on_pushButton_baseinfo_clicked();
}

void myindex::on_pushButton_upadate_clicked()
{
    struct Staff staff;
    staff.card_ID=ui->lineEdit_cardID->text();
    staff.staff_name=ui->lineEdit_name->text();
    staff.staff_sex=ui->comboBox_sex->currentText();
    staff.staff_photo=photo_dir;
    staff.staff_birth=ui->comboBox_year->currentText()+ui->comboBox_month->currentText();
    staff.staff_ID=ui->lineEdit_ID->text();
    staff.staff_phone=ui->lineEdit_phone->text();
    staff.staff_address=ui->lineEdit_address->text();
    staff.staff_department=ui->comboBox_department->currentText();
    staff.staff_position=ui->comboBox_position->currentText();
    staff.staff_login_pass=ui->lineEdit_password->text();

    db_func d;
    d.db_open();
    if(d.updateStaff(staff))
    {
        QMessageBox::information(this,tr("错误"),tr("更新失败!"),QMessageBox::Yes);
    }
    else
    {
        on_pushButton_clear_clicked();
        on_pushButton_baseinfo_clicked();
    }
    d.db_close();
}

void myindex::on_pushButton_clear_clicked()
{
    ui->lineEdit_cardID->clear();
    ui->lineEdit_name->clear();
    ui->comboBox_sex->setCurrentIndex(0);
    ui->lineEdit_ID->clear();
    ui->label_photo->clear();
    ui->comboBox_year->setCurrentIndex(0);
    ui->comboBox_month->setCurrentIndex(0);
    ui->lineEdit_phone->clear();
    ui->lineEdit_address->clear();
    ui->comboBox_department->setCurrentIndex(0);
    ui->comboBox_position->setCurrentIndex(0);
    ui->lineEdit_password->clear();
}

//**********************************//


void myindex::on_pushButton_workinfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget->show();

    model1=new QSqlQueryModel;
    QString sql1="select t1.cardID,t2.staff_name,t1.brush_card_time,t1.staff_photos from workinfo t1,baseinfo t2 where t1.cardID=t2.cardID";
    db_func d;
    d.db_open();
    d.db.exec("SET NAMES 'latin1'");
    if(sql!=NULL)
        model1->setQuery(sql);
    else
        model1->setQuery(sql1);
    if(!model1->query().next())
    {
        QMessageBox::information(this,tr("提示"),tr("查询到的数据为空!"),QMessageBox::Yes);
    }
    sql="";
    d.db_close();

    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("卡号"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("姓名"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("刷卡时间"));
    model1->setHeaderData(3,Qt::Horizontal,QObject::tr("刷卡照片"));

    ui->tableView_2->setModel(model1);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void myindex::tableViewClicked_2()
{
    int curRow = ui->tableView_2->currentIndex().row();
    QString cardID=model1->index(curRow,0).data().toString();
    QString click_dir=model1->index(curRow,3).data().toString();
    qDebug()<<click_dir;
    db_func d1;
    QSqlDatabase db = QSqlDatabase::database();//获取默认连接的数据库
    d1.db=db;
    QString org_dir=d1.findPhotoDir(cardID);
    qDebug()<<org_dir;

    QPixmap *pixmap1=new QPixmap(org_dir);
    ui->label_org_photo->setPixmap(*pixmap1);

    QPixmap *pixmap2=new QPixmap(click_dir);
    ui->label_cur_photo->setPixmap(*pixmap2);
}

void myindex::setdate()
{
    ui->dateEdit_start->clear();//无效果
    ui->dateEdit_start->setDate(ui->calendarWidget_starttime->selectedDate());
    ui->calendarWidget_starttime->hide();
    if(ui->calendarWidget_starttime->selectedDate()<=ui->calendarWidget_endtime->selectedDate())
    {
        QMessageBox::warning(this,tr("Error!"),tr("时间选择有误，请重新选择！"),QMessageBox::Yes);
    }
}
void myindex::setdate1()
{
    ui->dateEdit_end->clear();
    ui->dateEdit_end->setDate(ui->calendarWidget_endtime->selectedDate());
    ui->calendarWidget_endtime->hide();
    if(ui->calendarWidget_endtime->selectedDate()<=ui->calendarWidget_starttime->selectedDate())
    {
        QMessageBox::warning(this,tr("Error!"),tr("时间选择有误，请重新选择！"),QMessageBox::Yes);
    }
}

void myindex::on_pushButton_find_2_clicked()
{
    struct Staff staff;
    if(ui->lineEdit_cardID_2->text()==NULL) staff.card_ID="%";
    else staff.card_ID=ui->lineEdit_cardID_2->text();

    if(ui->lineEdit_name_2->text()==NULL) staff.staff_name="%";
    else staff.staff_name=ui->lineEdit_name_2->text();

    if(ui->comboBox_sex_2->currentText()==NULL) staff.staff_sex="%";
    else staff.staff_sex=ui->comboBox_sex_2->currentText();

    if(ui->lineEdit_phone_2->text()==NULL) staff.staff_phone="%";
    else staff.staff_phone=ui->lineEdit_phone_2->text();

    if(ui->lineEdit_ID_2->text()==NULL) staff.staff_ID="%";
    else staff.staff_ID=ui->lineEdit_ID_2->text();

    if(ui->comboBox_department_2->currentText()==NULL) staff.staff_department="%";
    else staff.staff_department=ui->comboBox_department_2->currentText();

    if(ui->comboBox_position_2->currentText()==NULL) staff.staff_position="%";
    else staff.staff_position=ui->comboBox_position_2->currentText();

    QString startTime=ui->dateEdit_start->date().toString("yyyyMMdd")+"0000";
    QString endTime=ui->dateEdit_end->date().toString("yyyyMMdd")+"0000";

    qDebug()<<startTime<<","<<endTime;

    sql="select t1.cardID,t2.staff_name,t1.brush_card_time,t1.staff_photos from workinfo t1,baseinfo t2 where t2.cardID in (select cardID from workinfo where brush_card_time > '"+startTime+"' and brush_card_time < '"+endTime+"') and t2.cardID like '"+staff.card_ID+"' and staff_name like '"+staff.staff_name+"' and staff_sex like '"+staff.staff_sex+"' and staff_ID like '"+staff.staff_ID+"' and staff_phone like '"+staff.staff_phone+"' and staff_department like '"+staff.staff_department+"' and staff_position like '"+staff.staff_position+"' and t1.cardID=t2.cardID";
    //qDebug()<<sql;
    on_pushButton_workinfo_clicked();
}



void myindex::on_pushButton_clear_2_clicked()
{
    ui->lineEdit_cardID_2->clear();
    ui->lineEdit_name_2->clear();
    ui->comboBox_sex_2->setCurrentIndex(0);
    ui->lineEdit_phone_2->clear();
    ui->lineEdit_ID_2->clear();
    ui->comboBox_department_2->setCurrentIndex(0);
    ui->comboBox_position_2->setCurrentIndex(0);
    ui->label_cur_photo->clear();
    ui->label_org_photo->clear();
    ui->label_cur->hide();
    ui->label_org->hide();
    QDate date=QDate::currentDate();
    ui->dateEdit_end->setDate(date);
    date.setDate(system_date.year(),system_date.month()-1,system_date.day());
    ui->dateEdit_start->setDate(date);

}
