#include "findstaff.h"
#include "ui_findstaff.h"

findStaff::findStaff(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::findStaff)
{
    ui->setupUi(this);
}

findStaff::~findStaff()
{
    delete ui;
}

void findStaff::on_pushButton_find_clicked()
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

    if(ui->lineEdit_phone->text()==NULL) staff.staff_phone="%";
    else staff.staff_phone=ui->lineEdit_phone->text();

    if(ui->comboBox_department->currentText()==NULL) staff.staff_department="%";
    else staff.staff_department=ui->comboBox_department->currentText();

    if(ui->comboBox_position->currentText()==NULL) staff.staff_position="%";
    else staff.staff_position=ui->comboBox_position->currentText();

    //qDebug()<<staff.card_ID<<","<<staff.staff_name<<staff.staff_ID<<staff.staff_sex;
    QString sql="cardID like '"+staff.card_ID+"' and staff_name like '"+staff.staff_name+"' and staff_sex like '"+staff.staff_sex+"' and staff_ID like '"+staff.staff_ID+"' and staff_phone like '"+staff.staff_phone+"' and staff_department like '"+staff.staff_department+"' and staff_position like '"+staff.staff_position+"'";

    this->close();
    myindex *i=new myindex(0,sql);
    i->show();
    i->on_action_staff_manage_triggered();
}

void findStaff::on_pushButton_clear_clicked()
{
    ui->lineEdit_cardID->clear();
    ui->lineEdit_name->clear();
    ui->comboBox_sex->setCurrentIndex(0);
    ui->lineEdit_ID->clear();
    ui->lineEdit_phone->clear();
    ui->comboBox_department->setCurrentIndex(0);
    ui->comboBox_position->setCurrentIndex(0);
    ui->lineEdit_cardID->setFocus();
}

void findStaff::on_pushButton_back_clicked()
{
    this->close();
    QString sql="";
    myindex *i=new myindex(0,sql);
    i->show();
    i->on_action_staff_manage_triggered();
}
