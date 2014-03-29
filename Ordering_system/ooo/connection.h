#ifndef CONNECTION_H
#define CONNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bh1800.s3db");
    if(!db.open()){
        QMessageBox::critical(0,qApp->tr("Cannot open database"),qApp->tr("Unable to establish a connection."),QMessageBox::Ok);
        //printf("connect failed!\n");
        return false;
    }
   //QSqlQuery query(db);
   //query.exec("insert into staff values('0004','tom','123','ÄÐ','ºªµ¦','ÀÈ·»',23,'0','130428199104182254')");
   /*query.exec("insert into dishes values('01','¹¬±£¼¦¶¡',25,'h','1')");
   query.exec("insert into dishes values('02','¿¾ÑòÈâ',24,'h','2')");
   query.exec("insert into dishes values('03','¿¾Å£Èâ',29,'h','3')");
   query.exec("insert into dishes values('04','À±³´ò¹×Ó',36,'h','4')");

   query.exec("insert into dishes values('05','½ðÕë¹½',25,'c','1')");
   query.exec("insert into dishes values('06','ÅÄ»Æ¹Ï',24,'c','2')");
   query.exec("insert into dishes values('07','½´Å£Èâ',29,'c','3')");

   query.exec("insert into dishes values('08','´óÃ×',36,'s','4')");
   query.exec("insert into dishes values('09','ÉÕ±ý',24,'s','2')");
   query.exec("insert into dishes values('10','ÂøÍ·',29,'s','3')");

   query.exec("insert into dishes values('11','¿ÉÀÖ',36,'d','4')");
   query.exec("insert into dishes values('12','Ñ©±Ì',29,'d','3')");
   query.exec("insert into dishes values('13','ºì²è',36,'d','4')");*/
    return true;
}
#endif // CONNECTION_H
