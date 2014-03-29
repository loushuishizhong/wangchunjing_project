#include "choice.h"
#include "ui_choice.h"
#include "taiweimanage.h"
#include "selectfood.h"
#include "checkmunu.h"
#include "function.h"

#include <QtGui>

Choice::Choice(QWidget *parent, QString id,QString num) :
        QDialog(parent),user_id(id),table_num(num),
        ui(new Ui::Choice)
{
    ui->setupUi(this);
    ui->label_3->setText(user_id);
    ui->label_5->setText(table_num);
    a=new QTableManagement();
}

Choice::~Choice()
{
    delete ui;
}

void Choice::on_pushButton_2_clicked()
{
    this->close();
    Taiweimanage *t=new Taiweimanage(0,user_id);
    t->show();
}

void Choice::on_pushButton_clicked()
{
    this->close();
    if(ui->comboBox->currentText()=="开台/点菜")
    {
        Tableinfo table;
        table.table_number=table_num;
        table.table_status="1";
        a->newTable(table);

        //判断是否处理成功

        Selectfood *s=new Selectfood(0,user_id,table_num);
        s->show();
    }
    else if(ui->comboBox->currentText()=="结账")
    {
        checkmunu *z=new checkmunu(0,user_id,table_num);
        z->show();
    }
    else if(ui->comboBox->currentText()=="预订")
    {
        Tableinfo table_2;
        table_2.table_number=table_num;
        table_2.table_status="2";
        a->orderTable(table_2);

        //判断是否预订成功
        DM1800 *dm=new DM1800();
        while(dm->str!="T")
        {
            if(dm->str=="F")
            {
                QMessageBox::information(this,tr("预订失败"),tr("预订失败！"),QMessageBox::Ok);
                break;
            }
        }
        if(dm->str=="T")
        {
            QMessageBox::information(this,tr("预订成功"),tr("恭喜您预订成功，预订台位%1！").arg(table_num),QMessageBox::Ok);
        }
        dm->myCom->close();
        Function *fu=new Function(0,user_id);
        fu->show();
    }

    else if(ui->comboBox->currentText()=="取消预订")
    {
        Tableinfo table_2;
        table_2.table_number=table_num;
        table_2.table_status="0";
        a->orderTable(table_2);

        //判断是否预订成功
        DM1800 *dm=new DM1800();
        while(dm->str!="T")
        {
            if(dm->str=="F")
            {
                QMessageBox::information(this,tr("取消预订失败"),tr("取消预订失败！"),QMessageBox::Ok);
                break;
            }
        }
        if(dm->str=="T")
        {
            QMessageBox::information(this,tr("取消预订成功"),tr("取消预订成功，取消预订台位%1！").arg(table_num),QMessageBox::Ok);
        }
        dm->myCom->close();
        Function *fu=new Function(0,user_id);
        fu->show();
    }
}
