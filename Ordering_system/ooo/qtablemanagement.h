#ifndef QTABLEMANAGEMENT_H
#define QTABLEMANAGEMENT_H
#include"dished.h"
#include"tableinfo.h"
#include "bill.h"
#include"staff.h"
#include "DM1800.h"
class QTableManagement
{
public:
    QTableManagement();
    void initTables();//---------��ʼ��̨λ��Ϣ

            int  newTable(Tableinfo);//---------��̨/���

            int  orderTable(Tableinfo);//---------Ԥ��

            int  checkOut(Tableinfo);//------�굥

            int pay(Tableinfo);//--------����

            int  sendDishedInfo(Dished,Staff,Bill);//---------����̨λ�����Ϣ���䵽���
            int  sendDishedinfo_2(Dished,Staff,Bill);//------�����˵�
};

#endif // QTABLEMANAGEMENT_H
