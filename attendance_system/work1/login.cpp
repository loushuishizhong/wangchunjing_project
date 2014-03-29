#include "login.h"
#include "ui_login.h"

#include <QMessageBox>
#include <QDebug>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->lineEdit_user->setFocus();
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

login::~login()
{
    //d.db_close();
    delete ui;
}

void login::on_pushButton_login_clicked()
{
    db_func d;
    d.db_open();
    if(ui->lineEdit_user->text().isEmpty()||ui->lineEdit_password->text().isEmpty())
    {
        QMessageBox::information(this,tr("error1请输入用户名和密码"),tr("error1请先输入用户名和密码再登录"),QMessageBox::Yes);
        ui->lineEdit_user->setFocus();
    }
    else
    {
        QSqlQuery query;
        user_name=ui->lineEdit_user->text();
        user_pass=ui->lineEdit_password->text();
        QString sql="select staff_name,staff_login_pass from baseinfo where staff_name='"+user_name+"' and staff_login_pass='"+user_pass+"'";
        query.exec(sql);
        if(query.next())
        {
            this->close();
            i.show();
        }
        else
        {
            QMessageBox::information(this,tr("error2"),tr("error2请重新输入用户名和密码再登录"),QMessageBox::Yes);
        }
    }
    d.db_close();
}

void login::on_pushButton_cancle_clicked()
{
    this->close();
}
