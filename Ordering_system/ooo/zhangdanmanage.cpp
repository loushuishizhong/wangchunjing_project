#include "zhangdanmanage.h"
#include "ui_zhangdanmanage.h"
#include "function.h"
#include "checkmunu.h"
#include <QStandardItemModel>
Zhangdanmanage::Zhangdanmanage(QWidget *parent,QString id) :
        QMainWindow(parent),user_id(id),
        ui(new Ui::Zhangdanmanage)
{
    ui->setupUi(this);
    ui->label_2->setText(user_id);
    a=new QBillManagement();
    a->initBills();
    //QString ss2=a->dc.receiveData();

    //处理接收数据
    //数据解析


    QStandardItemModel *model = new QStandardItemModel(0, 4, parent);
    

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("台位号"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("流水账号"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("总价钱"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("状态"));
    //插入数据。。。循环

    DM1800 *dm=new DM1800();
    while(dm->str!="T")
    {
        if(dm->str=="F")break;
        if(dm->str!=NULL)
        {
            model->insertRow(0);
            int i=0;
            while(dm->str.at(i)!='+')
            {
                QString res;
                res.append(dm->str.at(i));
                model->setData(model->index(0, 0), res);
                i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {
                QString res;
                res.append(dm->str.at(i));
                model->setData(model->index(0, 1), res);
                i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {
                QString res;
                res.append(dm->str.at(i));
                model->setData(model->index(0, 2), res);
                i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {
                QString res;
                res.append(dm->str.at(i));
                model->setData(model->index(0, 3), res);
                i++;
            }
            dm->str.clear();
        }
    }

    ui->tableView->setModel(model);
    dm->myCom->close();
}

Zhangdanmanage::~Zhangdanmanage()
{
    delete ui;
}

void Zhangdanmanage::on_pushButton_2_clicked()
{
    this->close();
    Function *fu=new Function(0,user_id);
    fu->show();
}
