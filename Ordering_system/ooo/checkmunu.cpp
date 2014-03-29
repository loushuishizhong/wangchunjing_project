#include "checkmunu.h"
#include "ui_checkmunu.h"
#include "taiweimanage.h"
#include "function.h"


checkmunu::checkmunu(QWidget *parent, QString id,QString num) :
        QDialog(parent),user_id(id),table_num(num),
        ui(new Ui::checkmunu)
{
    b=new QTableManagement();
    Tableinfo table_1;
    table_1.table_number=table_num;
    table_1.table_status="0";
    b->checkOut(table_1);//---------详单

    //解析
    DM1800 *dm=new DM1800();
    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            //失败
            break;
        }
        if(dm->str!=NULL)
        {
            //jie xi
            int i=0;
            QString res;
            while(dm->str.at(i)!='+')
            {
                res.append(dm->str.at(i));
                i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {
                res.append(dm->str.at(i));
                i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {
                res.append(dm->str.at(i));
                i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {
                res.append(dm->str.at(i));
                i++;
            }
            dm->str.clear();
            //添加到界面
            ui->listWidget->addItem(res);
        }
    }
    dm->myCom->close();
    ui->setupUi(this);
    ui->label_3->setText(user_id);
    ui->label_5->setText(table_num);
}

checkmunu::~checkmunu()
{
    delete ui;
}

void checkmunu::changeEvent(QEvent *e)
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

void checkmunu::on_pushButton_clicked()
{
    this->close();
    Taiweimanage *z=new Taiweimanage(0,user_id);
    z->show();
}

void checkmunu::on_pushButton_3_clicked()
{
    this->close();
    Function *fu=new Function(0,user_id);
    fu->show();
}

void checkmunu::on_pushButton_2_clicked()//结账
{
    Tableinfo table;
    table.table_number=table_num;
    b->pay(table);
}
