#ifndef QBILLMANAGEMENT_H
#define QBILLMANAGEMENT_H
#include "staff.h"
#include "dished.h"
#include <QList>
#include "bill.h"
#include "DM1800.h"

class QBillManagement
{
public:
    QBillManagement();
    void initBills();//---------初始化菜单列表信息

    QList<Dished> queryBill(Bill);//---------显示/查询账单明细
};

#endif // QBILLMANAGEMENT_H
