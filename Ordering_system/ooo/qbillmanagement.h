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
    void initBills();//---------��ʼ���˵��б���Ϣ

    QList<Dished> queryBill(Bill);//---------��ʾ/��ѯ�˵���ϸ
};

#endif // QBILLMANAGEMENT_H
