#include "qstatisticsmanagement.h"

QStatisticsManagement::QStatisticsManagement()
{
}
QList<Bill> QStatisticsManagement::staffStatistics(QString starttime,QString endtime)//---------员工出勤率统计
{
    QString s1="ta+"+starttime+"+"+endtime+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s1);
    dm->myCom->close();
}
QList<Dished> QStatisticsManagement::dishesStatistics(QString starttime,QString endtime)//---------菜品统计
{
    QString s2="tb+"+starttime+"+"+endtime+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s2);
    dm->myCom->close();
}
QList<Dished> QStatisticsManagement::moneyStatistics(QString starttime,QString endtime)//---------销售额统计
{
    QString s3="td+"+starttime+"+"+endtime+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s3);
    dm->myCom->close();
}
