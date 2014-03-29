#include "function.h"
#include "ui_function.h"
#include "taiweimanage.h"
#include "munemanage.h"
#include "zhangdanmanage.h"
#include "usermanage.h"
#include "tongji.h"
#include <QSqlQuery>

Function::Function(QWidget *parent, QString id) :
    QMainWindow(parent),user_id(id),
    ui(new Ui::Function)
{
    a=new QDishesManagement();
    b=new QStaffManagement();
    ui->setupUi(this);

    ui->label_2->setText(user_id);
}

Function::~Function()
{
    delete ui;
}

void Function::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Function::on_taiweiButton_clicked()
{

    this->close();
    Taiweimanage *t=new Taiweimanage(0,user_id);
    t->show();
}

void Function::on_muneButton_clicked()
{
    this->close();
    Munemanage *m=new Munemanage(0,user_id);
    m->show();
}

void Function::on_zhangdanButton_clicked()
{
    this->close();
    Zhangdanmanage *z=new Zhangdanmanage(0,user_id);
    z->show();
}

void Function::on_userButton_clicked()
{
    this->close();
    Usermanage *u=new Usermanage(0,user_id);
    u->show();
}

void Function::on_tongjiButton_clicked()
{
    this->close();
    tongji *d=new tongji(0,user_id);
    d->show();
}

void Function::on_pushButton_6_clicked()
{
    QSqlQuery query;

    a->initDishes();
    DM1800 *dm=new DM1800();
    while(dm->str!="T")
    {
         if(dm->str=="F")break;
        if(dm->str!=NULL)
        {
            int i=0;

            Dishes dish;
            while(dm->str.at(i)!='+')
            {
               dish.dish_number.append(dm->str.at(i));
               i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {
               dish.dish_name.append(dm->str.at(i));
               i++;
            }
              i++;
            while(dm->str.at(i)!='+')
            {
               dish.dish_short_name.append(dm->str.at(i));
               i++;
            }
              i++;
            while(dm->str.at(i)!='+')
            {
               dish.dish_price.append(dm->str.at(i));
               i++;
            }
            i++;
          while(dm->str.at(i)!='+')
          {
             dish.dish_category.append(dm->str.at(i));
             i++;
          }
            dm->str.clear();

            //添加到数据库
            query.exec("insert into dishes values('"+dish.dish_number+"','"+dish.dish_short_name+"','"+dish.dish_price+"','"+dish.dish_category+"')");
        }
    }

    dm->str.clear();
    dm->myCom->close();


    b->initStaff();
    DM1800 *dm2=new DM1800();
    while(dm2->str!="T")
    {
          if(dm2->str=="F")break;
        if(dm2->str!=NULL)
        {
            //jie xi
            int i=0;
           //QString res;
           Staff staff;
            while(dm2->str.at(i)!='+')
            {
              // res.append(dm.str.at(i));
               staff.staff_number.append(dm2->str.at(i));
               i++;
            }
            i++;
            while(dm2->str.at(i)!='+')
            {
               staff.staff_name.append(dm2->str.at(i));
               i++;
            }
              i++;
            while(dm2->str.at(i)!='+')
            {
               staff.staff_sex.append(dm2->str.at(i));
               i++;
            }
              i++;
            while(dm2->str.at(i)!='+')
            {
               staff.staff_native.append(dm->str.at(i));
               i++;
            }
            i++;
          while(dm2->str.at(i)!='+')
          {
             staff.staff_address.append(dm2->str.at(i));
             i++;
          }
          while(dm2->str.at(i)!='+')
          {
             staff.staff_ID_card_number.append(dm2->str.at(i));
             i++;
          }
          while(dm2->str.at(i)!='+')
          {
             staff.staff_level.append(dm2->str.at(i));
             i++;
          }
          while(dm2->str.at(i)!='+')
          {
             staff.staff_age.append(dm2->str.at(i));
             i++;
          }
          while(dm2->str.at(i)!='+')
          {
             staff.staff_login_pass.append(dm2->str.at(i));
             i++;
          }
            dm2->str.clear();
            //添加到数据库

            query.exec("insert into staff values('"+staff.staff_number+"','"+staff.staff_name+"','"+staff.staff_login_pass+"','"+staff.staff_sex+"','"+staff.staff_native+"','"+staff.staff_address+"','"+staff.staff_age+"','"+staff.staff_level+"','"+staff.staff_ID_card_number+"')");
        }
    }
    dm2->myCom->close();
}
