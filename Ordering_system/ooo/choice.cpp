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
    if(ui->comboBox->currentText()=="��̨/���")
    {
        Tableinfo table;
        table.table_number=table_num;
        table.table_status="1";
        a->newTable(table);

        //�ж��Ƿ���ɹ�

        Selectfood *s=new Selectfood(0,user_id,table_num);
        s->show();
    }
    else if(ui->comboBox->currentText()=="����")
    {
        checkmunu *z=new checkmunu(0,user_id,table_num);
        z->show();
    }
    else if(ui->comboBox->currentText()=="Ԥ��")
    {
        Tableinfo table_2;
        table_2.table_number=table_num;
        table_2.table_status="2";
        a->orderTable(table_2);

        //�ж��Ƿ�Ԥ���ɹ�
        DM1800 *dm=new DM1800();
        while(dm->str!="T")
        {
            if(dm->str=="F")
            {
                QMessageBox::information(this,tr("Ԥ��ʧ��"),tr("Ԥ��ʧ�ܣ�"),QMessageBox::Ok);
                break;
            }
        }
        if(dm->str=="T")
        {
            QMessageBox::information(this,tr("Ԥ���ɹ�"),tr("��ϲ��Ԥ���ɹ���Ԥ��̨λ%1��").arg(table_num),QMessageBox::Ok);
        }
        dm->myCom->close();
        Function *fu=new Function(0,user_id);
        fu->show();
    }

    else if(ui->comboBox->currentText()=="ȡ��Ԥ��")
    {
        Tableinfo table_2;
        table_2.table_number=table_num;
        table_2.table_status="0";
        a->orderTable(table_2);

        //�ж��Ƿ�Ԥ���ɹ�
        DM1800 *dm=new DM1800();
        while(dm->str!="T")
        {
            if(dm->str=="F")
            {
                QMessageBox::information(this,tr("ȡ��Ԥ��ʧ��"),tr("ȡ��Ԥ��ʧ�ܣ�"),QMessageBox::Ok);
                break;
            }
        }
        if(dm->str=="T")
        {
            QMessageBox::information(this,tr("ȡ��Ԥ���ɹ�"),tr("ȡ��Ԥ���ɹ���ȡ��Ԥ��̨λ%1��").arg(table_num),QMessageBox::Ok);
        }
        dm->myCom->close();
        Function *fu=new Function(0,user_id);
        fu->show();
    }
}
