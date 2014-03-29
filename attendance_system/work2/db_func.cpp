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
        QMessageBox::critical(0,QObject::tr("错误"),QObject::tr("数据库打开失败!"),QMessageBox::Yes);
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
    QString sql;
    sql="select * from baseinfo where cardID='"+staff.card_ID+"'";
    query.exec(sql);
    if(query.next())
    {
        QMessageBox::critical(0,QObject::tr("错误"),QObject::tr("数据库中已有此卡号!"),QMessageBox::Yes);
        return 0;
    }
    else
    {
        sql="insert into baseinfo values('"+staff.card_ID+"','"+staff.staff_name+"','"+staff.staff_sex+"','"+staff.staff_photo+"','"+staff.staff_ID+"','"+staff.staff_birth+"','"+staff.staff_phone+"','"+staff.staff_address+"','"+staff.staff_department+"','"+staff.staff_position+"','"+staff.staff_login_pass+"')";
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
}

int db_func::deleteStaff(struct Staff staff)
{
    QMessageBox::StandardButton rb=QMessageBox::warning(0,QObject::tr("警告"),QObject::tr("你确定要删除该员工信息吗？"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(rb==QMessageBox::No)
        return 0;
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
        QMessageBox::information(0,QObject::tr("错误"),QObject::tr("删除失败!"),QMessageBox::Yes);
        return 0;
    }
}

struct Staff db_func::findStaff(QString cardID)
{
    struct Staff staff;
    db.exec("SET NAMES latin1");
    QSqlQuery query;
    //QString sql="select * from baseinfo where cardID like '"+staff.card_ID+"' and staff_name like '"+staff.staff_name+"' and staff_sex like '"+staff.staff_sex+"' and staff_ID like '"+staff.staff_ID+"' and staff_birth like '"+staff.staff_birth+"' and staff_phone like '"+staff.staff_phone+"' and staff_address like '"+staff.staff_address+"' and staff_department like '"+staff.staff_department+"' and staff_position like '"+staff.staff_position+"'";
    QString sql="select * from baseinfo where cardID='"+cardID+"'";
    out<<sql<<endl;
    query.exec(sql);
    if(query.next())
    {
        //out<<query.value(0).toString()<<query.value(1).toString()<<query.value(2).toString()<<query.value(7).toString()<<endl;
        out <<"select from baseinfo succeed!"<<endl;
        staff.card_ID=query.value(0).toString();
        staff.staff_name=query.value(1).toString();
        staff.staff_sex=query.value(2).toString();
        staff.staff_photo=query.value(3).toString();
        staff.staff_phone=query.value(6).toString();
        staff.staff_department=query.value(8).toString();
        staff.staff_position=query.value(9).toString();

        return staff;
    }
    else
    {
        out <<"select from baseinfo failed!"<<endl;
        QMessageBox::information(0,QObject::tr("错误"),QObject::tr("查询失败!"),QMessageBox::Yes);
        //return;
    }
}

int db_func::updateStaff(struct Staff staff)
{
    QMessageBox::StandardButton rb=QMessageBox::warning(0,QObject::tr("警告"),QObject::tr("你确定要修改该员工信息吗？"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(rb==QMessageBox::No)
        return 0;
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
        QMessageBox::information(0,QObject::tr("错误"),QObject::tr("更新失败!"),QMessageBox::Yes);
        out <<"update baseinfo failed!"<<endl;
        return 0;
    }
}
