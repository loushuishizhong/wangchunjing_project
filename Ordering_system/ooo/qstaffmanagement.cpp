#include "qstaffmanagement.h"
#include <QSqlQuery>
#include <QtSql>
#include <QMessageBox>

QStaffManagement::QStaffManagement()
{
}
void QStaffManagement::initStaff()
{

    QString s0="yg+";
    DM1800 *dm=new DM1800();
    dm->sendData(s0);
    dm->myCom->close();
}

int QStaffManagement::deleteStaff(Staff staff)//---------删除用户信息
{
    QString s1="sd+"+staff.staff_number+"+"+staff.staff_name+"+"+staff.staff_login_pass+"+"+staff.staff_sex+"+"+staff.staff_native+"+"+staff.staff_address+"+"+staff.staff_ID_card_number+"+"+staff.staff_age+"+"+staff.staff_level+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s1);
    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("失败"),QObject::tr("失败！"),QMessageBox::Ok);
            break;
        }
    }
    if(dm->str=="T")
    {
        QMessageBox::information(0,QObject::tr("成功"),QObject::tr("成功！"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;
}
int QStaffManagement::addStaff(Staff staff)//---------添加新员工
{
    QString s2="sa+"+staff.staff_number+"+"+staff.staff_name+"+"+staff.staff_login_pass+"+"+staff.staff_sex+"+"+staff.staff_native+"+"+staff.staff_address+"+"+staff.staff_ID_card_number+"+"+staff.staff_age+"+"+staff.staff_level+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s2);
    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("失败"),QObject::tr("失败！"),QMessageBox::Ok);
            break;
        }
    }
    if(dm->str=="T")
    {
        QMessageBox::information(0,QObject::tr("成功"),QObject::tr("成功！"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;
}
int QStaffManagement::updateStaff(Staff staff)//---------修改员工信息
{
    QString s3="su+"+staff.staff_number+"+"+staff.staff_name+"+"+staff.staff_login_pass+"+"+staff.staff_sex+"+"+staff.staff_native+"+"+staff.staff_address+"+"+staff.staff_ID_card_number+"+"+staff.staff_age+"+"+staff.staff_level+"+";
    DM1800 *dm=new DM1800();
    dm->sendData(s3);
    while(dm->str!="T")
    {
        if(dm->str=="F")
        {
            QMessageBox::information(0,QObject::tr("失败"),QObject::tr("失败！"),QMessageBox::Ok);
            break;
        }
    }
    if(dm->str=="T")
    {
        QMessageBox::information(0,QObject::tr("成功"),QObject::tr("成功！"),QMessageBox::Ok);
    }
    dm->myCom->close();
    return 0;
}
int QStaffManagement::roleCheck(Staff staff)//---------权限检查
   {
            QSqlQuery query;
            query.prepare("select staff_level from staff where staff_number=?");
            query.addBindValue(staff.staff_number);
            query.exec();
            query.next();
            if(query.value(0).toString()=="0")
                return 0;
            if(query.value(0).toString()=="1")
                return 1;
            if(query.value(0).toString()=="2")
                return 2;
    }

int QStaffManagement::loginCheck(Staff staff)//---------用户登录验证
{

}
