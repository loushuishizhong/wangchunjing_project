#include "qbillmanagement.h"


QBillManagement::QBillManagement()
{
}
void QBillManagement::initBills()//---------��ʼ���˵��б���Ϣ
{
    QString s1="ba+";
    DM1800 *dm=new DM1800();
    dm->sendData(s1);
    dm->myCom->close();

}
QList<Dished> QBillManagement::queryBill(Bill bill)//---------��ʾ/��ѯ�˵���ϸ
{
    QString s2="bg+"+bill.bill_number+"+";
}
