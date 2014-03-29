#include "adduser.h"
#include "ui_adduser.h"
#include "usermanage.h"
#include <QSqlQuery>
adduser::adduser(QWidget *parent, QString id) :
    QDialog(parent),user_id(id),
    ui(new Ui::adduser)
{
    ui->setupUi(this);
    ui->label_10->setText(user_id);
    ui->lineEdit_6->setEchoMode(QLineEdit::Password);
    a=new QStaffManagement();
}

adduser::~adduser()
{
    delete ui;
}

void adduser::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void adduser::on_pushButton_2_clicked()
{
    this->close();
    Usermanage *u=new Usermanage(0,user_id);
    u->show();
}

void adduser::on_pushButton_clicked()
{
    Staff staff;

    staff.staff_number=ui->lineEdit_2->text();
    staff.staff_name=ui->lineEdit->text();
    staff.staff_login_pass=ui->lineEdit_6->text();
    staff.staff_sex=ui->comboBox_2->currentText();
    staff.staff_native=ui->lineEdit_4->text();
    staff.staff_address=ui->lineEdit_3->text();
    staff.staff_ID_card_number=ui->lineEdit_5->text();
    staff.staff_age=ui->lineEdit_7->text();
    staff.staff_level=ui->comboBox->currentText();

    a->addStaff(staff);

    QSqlQuery query;
    query.exec("insert into staff values('"+staff.staff_number+"','"+staff.staff_name+"','"+staff.staff_login_pass+"','"+staff.staff_sex+"','"+staff.staff_native+"','"+staff.staff_address+"','"+staff.staff_age+"','"+staff.staff_level+"','"+staff.staff_ID_card_number+"')");
    ////判断是否处理成功
}
