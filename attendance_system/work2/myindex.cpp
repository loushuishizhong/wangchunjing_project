#include "myindex.h"
#include "ui_myindex.h"

myindex::myindex(QWidget *parent,QString mysql) :
    QMainWindow(parent),sql(mysql),
    ui(new Ui::myindex)
{
    ui->setupUi(this);
    this->ui->stackedWidget->hide();
}

myindex::~myindex()
{
    delete ui;
}

void myindex::on_action_staff_manage_triggered()
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
}

void myindex::on_action_exit_triggered()
{
    this->close();
}

void myindex::on_pushButton_add_clicked()
{
    this->close();
    addStaff *a=new addStaff();
    a->show();
}

void myindex::on_pushButton_delete_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    struct Staff staff;
    staff.card_ID=model->index(curRow,0).data().toString();
    staff.staff_photo=model->index(curRow,3).data().toString();
    if(staff.card_ID==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("请选择要删除的员工!"),QMessageBox::Yes);
    }
    else
    {
        db_func d;
        d.db_open();
        d.deleteStaff(staff);
        //QMessageBox::information(this,tr("错误"),tr("删除失败!"),QMessageBox::Yes);
        QDir dir;
        dir.remove(staff.staff_photo);
        this->on_action_staff_manage_triggered();
        d.db_close();
    }
}

void myindex::on_pushButton_update_clicked()
{
    struct Staff staff;
    int curRow = ui->tableView->currentIndex().row();
    staff.card_ID=model->index(curRow,0).data().toString();
    staff.staff_name=model->index(curRow,1).data().toString();
    staff.staff_sex=model->index(curRow,2).data().toString();
    staff.staff_photo=model->index(curRow,3).data().toString();
    staff.staff_ID=model->index(curRow,4).data().toString();
    staff.staff_birth=model->index(curRow,5).data().toString();
    staff.staff_phone=model->index(curRow,6).data().toString();
    staff.staff_address=model->index(curRow,7).data().toString();
    staff.staff_department=model->index(curRow,8).data().toString();
    staff.staff_position=model->index(curRow,9).data().toString();
    this->close();
    updateStaff *a=new updateStaff(0,&staff);
    a->show();
}

void myindex::on_pushButton_find_clicked()
{
    this->close();
    findStaff *f=new findStaff();
    f->show();
}

void myindex::on_pushButton_refresh_clicked()
{
    on_action_staff_manage_triggered();
}

void myindex::on_pushButton_exit_clicked()
{
    this->close();
}

/*************************************************************/
void myindex::on_action_workinfo_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget->show();
    ui->stackedWidget_2->hide();

    QDate system_date=QDate::currentDate();//获取系统时间
    ui->dateEdit_start->setDisplayFormat("yyyy-MM-dd");//设置显示格式
    ui->dateEdit_end->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit_end->setDate(system_date);//设置初始值，起始日期与终止日期相差一个月
    system_date.setDate(system_date.year(),system_date.month()-1,system_date.day());
    ui->dateEdit_start->setDate(system_date);
    ui->calendarWidget_start->hide();
    connect(ui->pushButton_starttime,SIGNAL(clicked()),ui->calendarWidget_start,SLOT(show()));
    ui->calendarWidget_start->setSelectionMode(QCalendarWidget::SingleSelection);
    connect(ui->calendarWidget_start,SIGNAL(clicked(const QDate &)),this,SLOT(setdate()));
    ui->calendarWidget_end->hide();
    connect(ui->pushButton_endtime,SIGNAL(clicked()),ui->calendarWidget_end,SLOT(show()));
    ui->calendarWidget_end->setSelectionMode(QCalendarWidget::SingleSelection);
    connect(ui->calendarWidget_end,SIGNAL(clicked(const QDate &)),this,SLOT(setdate1()));


    model1=new QSqlQueryModel;
    QString sql1="select t1.cardID,t2.staff_name,t1.brush_card_date,t1.brush_card_time,t1.staff_photos from workinfo t1,baseinfo t2 where t1.cardID=t2.cardID";
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
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("刷卡日期"));
    model1->setHeaderData(3,Qt::Horizontal,QObject::tr("刷卡时间"));
    model1->setHeaderData(4,Qt::Horizontal,QObject::tr("刷卡照片"));
    ui->tableView_1->setModel(model1);
    ui->tableView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->tableView_1,SIGNAL(clicked(QModelIndex)),this,SLOT(tableViewClicked()));//触发点击事件
}

void myindex::setdate()
{
    ui->dateEdit_start->clear();//无效果
    ui->dateEdit_start->setDate(ui->calendarWidget_start->selectedDate());
    ui->calendarWidget_start->hide();
    if(ui->calendarWidget_start->selectedDate()>=ui->calendarWidget_end->selectedDate())
    {
        QMessageBox::warning(this,tr("Error!"),tr("时间选择有误，请重新选择！"),QMessageBox::Yes);
    }
}
void myindex::setdate1()
{
    ui->dateEdit_end->clear();
    ui->dateEdit_end->setDate(ui->calendarWidget_end->selectedDate());
    ui->calendarWidget_end->hide();
    if(ui->calendarWidget_end->selectedDate()<=ui->calendarWidget_start->selectedDate())
    {
        QMessageBox::warning(this,tr("Error!"),tr("时间选择有误，请重新选择！"),QMessageBox::Yes);
    }
}

void myindex::on_pushButton_find_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget_2->show();
    ui->pushButton_find_2->setEnabled(false);
}

void myindex::on_pushButton_all_clicked()
{
    on_action_workinfo_triggered();
    ui->pushButton_find_2->setEnabled(true);
}

void myindex::on_pushButton_back_clicked()
{
    ui->stackedWidget->hide();
}

void myindex::on_pushButton_OK_clicked()
{
    struct Staff staff;
    if(ui->lineEdit_cardID->text()==NULL) staff.card_ID="%";
    else staff.card_ID=ui->lineEdit_cardID->text();

    if(ui->lineEdit_name->text()==NULL) staff.staff_name="%";
    else staff.staff_name=ui->lineEdit_name->text();

    /*if(ui->comboBox_sex_2->currentText()==NULL) staff.staff_sex="%";
    else staff.staff_sex=ui->comboBox_sex_2->currentText();*/

    if(ui->lineEdit_phone->text()==NULL) staff.staff_phone="%";
    else staff.staff_phone=ui->lineEdit_phone->text();

    if(ui->lineEdit_ID->text()==NULL) staff.staff_ID="%";
    else staff.staff_ID=ui->lineEdit_ID->text();

    if(ui->comboBox_department->currentText()==NULL) staff.staff_department="%";
    else staff.staff_department=ui->comboBox_department->currentText();

    if(ui->comboBox_position->currentText()==NULL) staff.staff_position="%";
    else staff.staff_position=ui->comboBox_position->currentText();

    QString startTime=ui->dateEdit_start->date().toString("yyyyMMdd");
    QString endTime=ui->dateEdit_end->date().toString("yyyyMMdd");

    qDebug()<<startTime<<","<<endTime;

    sql="select t1.cardID,t2.staff_name,t1.brush_card_date,t1.brush_card_time,t1.staff_photos from workinfo t1,baseinfo t2 where t2.cardID in (select cardID from workinfo where brush_card_date > '"+startTime+"' and brush_card_time < '"+endTime+"') and t2.cardID like '"+staff.card_ID+"' and staff_name like '"+staff.staff_name+"' and staff_ID like '"+staff.staff_ID+"' and staff_phone like '"+staff.staff_phone+"' and staff_department like '"+staff.staff_department+"' and staff_position like '"+staff.staff_position+"' and t1.cardID=t2.cardID";
    on_action_workinfo_triggered();
    ui->stackedWidget_2->hide();
    ui->pushButton_find_2->setEnabled(true);
}

void myindex::on_pushButton_clear_clicked()
{
    ui->lineEdit_cardID->clear();
    ui->lineEdit_name->clear();
    //ui->comboBox_sex->setCurrentIndex(0);
    ui->lineEdit_phone->clear();
    ui->lineEdit_ID->clear();
    ui->comboBox_department->setCurrentIndex(0);
    ui->comboBox_position->setCurrentIndex(0);

    QDate date=QDate::currentDate();//获取系统时间
    ui->dateEdit_end->setDate(date);
    date.setDate(date.year(),date.month()-1,date.day());
    ui->dateEdit_start->setDate(date);
}

void myindex::on_pushButton_cancle_clicked()
{
    ui->stackedWidget_2->hide();
    ui->pushButton_find_2->setEnabled(true);
}

void myindex::tableViewClicked()
{
    struct Staff staff;
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->stackedWidget_2->show();
    ui->pushButton_find_2->setEnabled(true);

    int curRow = ui->tableView_1->currentIndex().row();
    QString cardID=model1->index(curRow,0).data().toString();
    QString click_dir=model1->index(curRow,4).data().toString();
    qDebug()<<click_dir;
    db_func d1;
    QSqlDatabase db = QSqlDatabase::database();//获取默认连接的数据库
    d1.db=db;
    staff=d1.findStaff(cardID);
    QString org_dir=staff.staff_photo;
    qDebug()<<org_dir;

    QPixmap *pixmap1=new QPixmap(org_dir);
    QPixmap image1=pixmap1->scaled(ui->label_org_photo->width(),ui->label_org_photo->height());
    ui->label_org_photo->setPixmap(image1);

    QPixmap *pixmap2=new QPixmap(click_dir);
    QPixmap image2=pixmap2->scaled(ui->label_cur_photo->width(),ui->label_cur_photo->height());
    ui->label_cur_photo->setPixmap(image2);

    ui->label_cardID_2->setText(staff.card_ID);
    ui->label_name_2->setText(staff.staff_name);
    ui->label_sex_2->setText(staff.staff_sex);
    ui->label_phone_2->setText(staff.staff_phone);
    ui->label_department_2->setText(staff.staff_department);
    ui->label_position_2->setText(staff.staff_position);
}

void myindex::on_pushButton_clicked()
{
    ui->stackedWidget_2->hide();
}
