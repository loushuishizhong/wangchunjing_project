#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "function.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
//#include "bianliang.h"
#include "DM1800.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlQueryModel *staffnumModel=new QSqlQueryModel(this);
    staffnumModel->setQuery("select staff_number from staff");
    ui->comboBox->setModel(staffnumModel);
    //DM1800 dm;
    //dm.sendData(tr("fdsafd"));
    ui->lineEdit->setEchoMode(QLineEdit::Password);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::information(this,tr("ÇëÊäÈëÃÜÂë"),tr("ÇëÏÈÊäÈëÃÜÂëÔÙµÇÂ¼"),QMessageBox::Yes);
        ui->lineEdit->setFocus();
    }else
    {
        QSqlQuery query;
        query.prepare("select staff_login_pass from staff where staff_number=?");
        query.addBindValue(user_id);
        query.exec();
        query.next();
        if(query.value(0).toString()==ui->lineEdit->text())
        {
        this->close();
        Function *f=new Function(0,user_id);
        f->show();}
        else
        {
            QMessageBox::information(this,tr("ÃÜÂë´íÎó"),tr("ÇëÖØÐÂÊäÈëÃÜÂëÔÙµÇÂ¼"),QMessageBox::Yes);
            ui->lineEdit->clear();
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged( )
{
    user_id=ui->comboBox->currentText();
}
