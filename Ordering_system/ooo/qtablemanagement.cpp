#include "qtablemanagement.h"
#include <QString>
#include <QMessageBox>


QTableManagement::QTableManagement()
{
}
void QTableManagement::initTables()//---------初始化台位信息
{
    QString s6="tr+";
    DM1800 *dm=new DM1800();
    dm->sendData(s6);
    dm->myCom->close();
}
int  QTableManagement::newTable(Tableinfo tableinfo)//---------开台/点菜
{
    QString s1="tn+"+tableinfo.table_number+"+"+tableinfo.table_status+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s1);

    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("失败"),QObject::tr("失败！"),QMessageBox::Ok);
            break;
        }
    }
    if(dm->str=="T")
    {
        QMessageBox::information(0,QObject::tr("成功"),QObject::tr("成功！"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;

}
int  QTableManagement::orderTable(Tableinfo tableinfo)//---------预订
{
    QString s2="to+"+tableinfo.table_number+"+"+tableinfo.table_status+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s2);
    dm->myCom->close();
}
int  QTableManagement::checkOut(Tableinfo tableinfo)//---------查询详细信息
{
    QString s3="tc+"+tableinfo.table_number+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s3);
    dm->myCom->close();
}
int QTableManagement::pay(Tableinfo tableinfo)//结账
{
    QString s4="tj+"+tableinfo.table_number+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s4);

    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("结账失败"),QObject::tr("结账失败！"),QMessageBox::Ok);
            break;
        }
    }
    if(dm->str=="T")
    {
        QMessageBox::information(0,QObject::tr("结账成功"),QObject::tr("结账成功！"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;
}

int  QTableManagement::sendDishedInfo(Dished dished,Staff staff,Bill bill)//---------将该台位点菜信息传输到后厨
{
    QString s4="tk+"+dished.dish_number+"+"+bill.bill_number+"+"+dished.dished_count+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s4);

    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("失败"),QObject::tr("失败！"),QMessageBox::Ok);
            break;
        }

    }
    if(dm->str=="T")
    {
        //QMessageBox::information(0,QObject::tr("成功"),QObject::tr("成功！"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;
}
int  QTableManagement::sendDishedinfo_2(Dished dished,Staff staff,Bill bill)//------传到账单
{
    QString s5="tb+"+bill.bill_number+"+"+bill.bill_amount_money+"+"+bill.bill_datetime+"+"+staff.staff_number+"+"+bill.table_number+"+"+bill.bill_status+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s5);
    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("失败"),QObject::tr("失败！"),QMessageBox::Ok);
            break;
        }

    }
    if(dm->str=="T")
    {
        QMessageBox::information(0,QObject::tr("成功"),QObject::tr("成功！"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;
}
