#ifndef QSTATISTICSMANAGEMENT_H
#define QSTATISTICSMANAGEMENT_H
#include <QDate>
//#include<QList>
//#include<qstringlist.h>
//#include<qstringlistmodel.h>
//#include<qlist.h>
#include"bill.h"
#include"dished.h"
#include "DM1800.h"



class QStatisticsManagement
{
public:
    QStatisticsManagement();
    QList<Bill> staffStatistics(QString starttime,QString endtime);//---------员工出勤率统计

    QList<Dished> dishesStatistics(QString starttime,QString endtime);//---------菜品统计


    QList<Dished> moneyStatistics(QString starttime,QString endtime);//---------销售额统计

};

#endif // QSTATISTICSMANAGEMENT_H
