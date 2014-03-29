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
   //query.exec("insert into staff values('0004','tom','123','��','����','�ȷ�',23,'0','130428199104182254')");
   /*query.exec("insert into dishes values('01','��������',25,'h','1')");
   query.exec("insert into dishes values('02','������',24,'h','2')");
   query.exec("insert into dishes values('03','��ţ��',29,'h','3')");
   query.exec("insert into dishes values('04','�������',36,'h','4')");

   query.exec("insert into dishes values('05','���빽',25,'c','1')");
   query.exec("insert into dishes values('06','�Ļƹ�',24,'c','2')");
   query.exec("insert into dishes values('07','��ţ��',29,'c','3')");

   query.exec("insert into dishes values('08','����',36,'s','4')");
   query.exec("insert into dishes values('09','�ձ�',24,'s','2')");
   query.exec("insert into dishes values('10','��ͷ',29,'s','3')");

   query.exec("insert into dishes values('11','����',36,'d','4')");
   query.exec("insert into dishes values('12','ѩ��',29,'d','3')");
   query.exec("insert into dishes values('13','���',36,'d','4')");*/
    return true;
}
#endif // CONNECTION_H
