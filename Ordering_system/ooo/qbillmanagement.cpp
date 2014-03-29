#include "qbillmanagement.h"


QBillManagement::QBillManagement()
{
}
void QBillManagement::initBills()//---------初始化账单列表信息
{
    QString s1="ba+";
    DM1800 *dm=new DM1800();
    dm->sendData(s1);
    dm->myCom->close();

}
QList<Dished> QBillManagement::queryBill(Bill bill)//---------显示/查询账单明细
{
    QString s2="bg+"+bill.bill_number+"+";
}
