#include "xiugaimune.h"
#include "ui_xiugaimune.h"
#include "function.h"
#include "munemanage.h"
#include <QDir>
#include<QString>
#include <QInputDialog>
#include<QFileDialog>
#include <QSqlQuery>
#include <QDebug>

xiugaimune::xiugaimune(QWidget *parent, QString id, QString a, QString b, QString c, QString d, QString e) :
    QDialog(parent),user_id(id),aa(a),bb(b),cc(c),dd(d),ee(e),
    ui(new Ui::xiugaimune)
{

    ui->setupUi(this);
    ui->label_3->setText(user_id);
    ui->lineEdit->setText(aa);
    ui->lineEdit_2->setText(bb);
    ui->lineEdit_3->setText(bb);
    ui->lineEdit_5->setText(cc);
    ui->lineEdit_4->setText(dd);
    ui->lineEdit_6->setText(ee);
}

xiugaimune::~xiugaimune()
{
    delete ui;
}

void xiugaimune::changeEvent(QEvent *e)
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

void xiugaimune::on_pushButton_3_clicked()
{
    this->close();
    Function *fu=new Function(0,user_id);
    fu->show();
}

void xiugaimune::on_pushButton_2_clicked()
{
    this->close();
    Munemanage *mu=new Munemanage(0,user_id);
    mu->show();

}

void xiugaimune::on_pushButton_4_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this);
       if(!dir.isEmpty())
       {
           ui->lineEdit_6->setText(dir);
       }
}

void xiugaimune::on_pushButton_clicked()//确定按钮
{
    QSqlQuery query;
    QString price;
    QString id,name,category,icon,short_name;
    Dishes dish;
    id=ui->lineEdit->text();
    name=ui->lineEdit_3->text();
    short_name=ui->lineEdit_2->text();
    price=ui->lineEdit_5->text();
    category=ui->lineEdit_4->text();
    icon=ui->lineEdit_6->text();
    qDebug()<<id<<name<<price<<category<<icon;
    //float a=float(price);
    query.exec("update dishes set dish_short_name='"+name+"',dish_price='"+price+"',dish_category='"+category+"',dish_icon_filepath='"+icon+"' where dish_number='"+id+"'");
    qDebug()<<"update dishes set dish_number='"+id+"',dish_short_name='"+name+"',dish_price="+price+",dish_category='"+category+"',dish_icon_filepath='"+icon+"'";

    dish.dish_number=id;
    dish.dish_name=name;
    dish.dish_price=price;
    dish.dish_category=category;
    dish.dish_short_name=short_name;

    dish_man.updateDish(dish);

    //判断是否成功

    this->close();
    Munemanage *mm=new Munemanage(0,user_id);
    mm->show();
}
