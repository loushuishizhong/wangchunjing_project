#include "db_func.h"

QTextStream out(stdout);

int db_func::db_open()
{
     db = QSqlDatabase::addDatabase("QMYSQL");
     db.setHostName("localhost");
     db.setDatabaseName("staff");
     db.setUserName("root");
     db.setPassword("7758991");
    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("error"),QObject::tr("open error!"),QMessageBox::Yes);
        return -1;
    }
    else
    {

        out <<"Database open succeed!"<<endl;
        return 1;
    }
}

int db_func::db_close()
{
    QSqlDatabase::removeDatabase("QMYSQL");
    db.close();
    return 1;
}

int db_func::addStaff(struct Staff staff)
{
    db.exec("SET NAMES latin1");
    QSqlQuery query;
    QString sql="insert into baseinfo values('"+staff.card_ID+"','"+staff.staff_name+"','"+staff.staff_sex+"','"+staff.staff_photo+"','"+staff.staff_ID+"','"+staff.staff_birth+"','"+staff.staff_phone+"','"+staff.staff_address+"','"+staff.staff_department+"','"+staff.staff_position+"','"+staff.staff_login_pass+"')";
    out<<sql<<endl;
    int res=query.exec(sql);
    if(res)
    {
        out <<"insert into baseinfo succeed!"<<endl;
        return 1;
    }
    else
    {
        out <<"insert into baseinfo failed!"<<endl;
        return 0;
    }
}

int db_func::deleteStaff(struct Staff staff)
{
    QSqlQuery query;
    QString sql="delete from baseinfo where cardID='"+staff.card_ID+"'";
    int res=query.exec(sql);
    if(res)
    {
        out <<"delete from baseinfo succeed!"<<endl;
        return 1;
    }
    else
    {
        out <<"delete from baseinfo failed!"<<endl;
        return 0;
    }
}

QString db_func::findPhotoDir(QString cardID)
{
    db.exec("SET NAMES latin1");
    QSqlQuery query;
    //QString sql="select * from baseinfo where cardID like '"+staff.card_ID+"' and staff_name like '"+staff.staff_name+"' and staff_sex like '"+staff.staff_sex+"' and staff_ID like '"+staff.staff_ID+"' and staff_birth like '"+staff.staff_birth+"' and staff_phone like '"+staff.staff_phone+"' and staff_address like '"+staff.staff_address+"' and staff_department like '"+staff.staff_department+"' and staff_position like '"+staff.staff_position+"'";
    QString sql="select staff_photo from baseinfo where cardID='"+cardID+"'";
    out<<sql<<endl;
    query.exec(sql);
    if(query.next())
    {
        //out<<query.value(0).toString()<<query.value(1).toString()<<query.value(2).toString()<<query.value(7).toString()<<endl;
        out <<"select from baseinfo succeed!"<<endl;
        return query.value(0).toString();
    }
    else
    {
        out <<"select from baseinfo failed!"<<endl;
        return 0;
    }
}

int db_func::updateStaff(struct Staff staff)
{
    db.exec("SET NAMES latin1");
    QSqlQuery query;
    QString sql="update baseinfo set cardID='"+staff.card_ID+"',staff_name='"+staff.staff_name+"',staff_sex='"+staff.staff_sex+"',staff_photo='"+staff.staff_photo+"',staff_birth='"+staff.staff_birth+"',staff_phone='"+staff.staff_phone+"',staff_address='"+staff.staff_address+"',staff_department='"+staff.staff_department+"',staff_position='"+staff.staff_position+"',staff_login_pass='"+staff.staff_login_pass+"' where cardID='"+staff.card_ID+"' ";
    int res=query.exec(sql);
    if(res)
    {
        out <<"update baseinfo succeed!"<<endl;
        return 1;
    }
    else
    {
        out <<"update baseinfo failed!"<<endl;
        return 0;
    }
}
