#include "addmune.h"
#include "ui_addmune.h"
#include "munemanage.h"
#include "function.h"
#include <QFileDialog>
#include <QComboBox>
#include <QSqlQuery>

addmune::addmune(QWidget *parent, QString id) :
    QDialog(parent),user_id(id),
    ui(new Ui::addmune)
{
    ui->setupUi(this);
    ui->label_9->setText(user_id);
    a=new QDishesManagement();
}

addmune::~addmune()
{
    delete ui;
}

void addmune::changeEvent(QEvent *e)
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

void addmune::on_pushButton_2_clicked()
{
    this->close();
    Munemanage *mu=new Munemanage(0,user_id);
    mu->show();

}

void addmune::on_pushButton_3_clicked()
{
    this->close();
    Function *fu=new Function(0,user_id);
    fu->show();
}



void addmune::on_comboBox_activated(QString )
{

}

void addmune::on_pushButton_clicked()
{
    Dishes dishes;
    dishes.dish_number=ui->lineEdit->text();
    dishes.dish_name=ui->lineEdit_3->text();
    dishes.dish_icon_filepath=ui->lineEdit_6->text();
    dishes.dish_short_name=ui->lineEdit_2->text();
    dishes.dish_category=ui->lineEdit_4->text();
    dishes.dish_price=ui->lineEdit_5->text();
    a->addDish(dishes);

    //判断是否处理成功
    QSqlQuery query;
    query.exec("insert into dishes values('"+dishes.dish_number+"','"+dishes.dish_name+"','"+dishes.dish_price+"','"+dishes.dish_category+"','"+dishes.dish_icon_filepath+"')");
}

void addmune::on_pushButton_4_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this);
       if(!dir.isEmpty())
       {
           ui->lineEdit_6->setText(dir);

       }
}
