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
    QList<Bill> staffStatistics(QString starttime,QString endtime);//---------Ա��������ͳ��

    QList<Dished> dishesStatistics(QString starttime,QString endtime);//---------��Ʒͳ��


    QList<Dished> moneyStatistics(QString starttime,QString endtime);//---------���۶�ͳ��

};

#endif // QSTATISTICSMANAGEMENT_H
