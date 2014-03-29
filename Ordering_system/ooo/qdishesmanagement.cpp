#include "qdishesmanagement.h"
#include <QMessageBox>
QDishesManagement::QDishesManagement()
{
}
void QDishesManagement::initDishes()//---------初始化菜单列表信息
{

    QString s0="di+";
    DM1800 *dm=new DM1800();
    dm->sendData(s0);
    dm->myCom->close();
}
int QDishesManagement::addDish(Dishes dishes)//---------添加新菜品
{
    QString s1="dn+"+dishes.dish_number+"+"+dishes.dish_name+"+"+dishes.dish_short_name+"+"+dishes.dish_category+"+"+dishes.dish_price+"+";
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
int QDishesManagement::delDish(Dishes dishes)//---------删除菜品
{
    QString s2="dd+"+dishes.dish_number+"+"+dishes.dish_name+"+"+dishes.dish_short_name+"+"+dishes.dish_category+"+"+dishes.dish_price+"+";
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
int QDishesManagement::updateDish(Dishes dishes)//---------更改菜品信息
{
    QString s3="du+"+dishes.dish_number+"+"+dishes.dish_name+"+"+dishes.dish_short_name+"+"+dishes.dish_category+"+"+dishes.dish_price+"+";
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
