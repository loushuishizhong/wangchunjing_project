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
    void initTables();//---------初始化台位信息

            int  newTable(Tableinfo);//---------开台/点菜

            int  orderTable(Tableinfo);//---------预订

            int  checkOut(Tableinfo);//------详单

            int pay(Tableinfo);//--------结账

            int  sendDishedInfo(Dished,Staff,Bill);//---------将该台位点菜信息传输到后厨
            int  sendDishedinfo_2(Dished,Staff,Bill);//------传到账单
};

#endif // QTABLEMANAGEMENT_H
