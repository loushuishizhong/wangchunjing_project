#ifndef BILL_H
#define BILL_H
#include<QString>
class Bill
{
public:
    Bill();
    QString bill_number	;//流水单号(账单号)
    QString bill_amount_money;//	账单金额
    QString bill_datetime;//	账单建立时间
    QString staff_number;//	员工编号
    QString table_number;//	账单所属编号
    QString bill_status;//	账单状态

};

#endif // BILL_H
