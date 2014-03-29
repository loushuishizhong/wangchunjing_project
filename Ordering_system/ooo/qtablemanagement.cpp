#include "qtablemanagement.h"
#include <QString>
#include <QMessageBox>


QTableManagement::QTableManagement()
{
}
void QTableManagement::initTables()//---------��ʼ��̨λ��Ϣ
{
    QString s6="tr+";
    DM1800 *dm=new DM1800();
    dm->sendData(s6);
    dm->myCom->close();
}
int  QTableManagement::newTable(Tableinfo tableinfo)//---------��̨/���
{
    QString s1="tn+"+tableinfo.table_number+"+"+tableinfo.table_status+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s1);

    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("ʧ��"),QObject::tr("ʧ�ܣ�"),QMessageBox::Ok);
            break;
        }
    }
    if(dm->str=="T")
    {
        QMessageBox::information(0,QObject::tr("�ɹ�"),QObject::tr("�ɹ���"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;

}
int  QTableManagement::orderTable(Tableinfo tableinfo)//---------Ԥ��
{
    QString s2="to+"+tableinfo.table_number+"+"+tableinfo.table_status+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s2);
    dm->myCom->close();
}
int  QTableManagement::checkOut(Tableinfo tableinfo)//---------��ѯ��ϸ��Ϣ
{
    QString s3="tc+"+tableinfo.table_number+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s3);
    dm->myCom->close();
}
int QTableManagement::pay(Tableinfo tableinfo)//����
{
    QString s4="tj+"+tableinfo.table_number+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s4);

    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("����ʧ��"),QObject::tr("����ʧ�ܣ�"),QMessageBox::Ok);
            break;
        }
    }
    if(dm->str=="T")
    {
        QMessageBox::information(0,QObject::tr("���˳ɹ�"),QObject::tr("���˳ɹ���"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;
}

int  QTableManagement::sendDishedInfo(Dished dished,Staff staff,Bill bill)//---------����̨λ�����Ϣ���䵽���
{
    QString s4="tk+"+dished.dish_number+"+"+bill.bill_number+"+"+dished.dished_count+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s4);

    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("ʧ��"),QObject::tr("ʧ�ܣ�"),QMessageBox::Ok);
            break;
        }

    }
    if(dm->str=="T")
    {
        //QMessageBox::information(0,QObject::tr("�ɹ�"),QObject::tr("�ɹ���"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;
}
int  QTableManagement::sendDishedinfo_2(Dished dished,Staff staff,Bill bill)//------�����˵�
{
    QString s5="tb+"+bill.bill_number+"+"+bill.bill_amount_money+"+"+bill.bill_datetime+"+"+staff.staff_number+"+"+bill.table_number+"+"+bill.bill_status+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s5);
    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("ʧ��"),QObject::tr("ʧ�ܣ�"),QMessageBox::Ok);
            break;
        }

    }
    if(dm->str=="T")
    {
        QMessageBox::information(0,QObject::tr("�ɹ�"),QObject::tr("�ɹ���"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;
}
