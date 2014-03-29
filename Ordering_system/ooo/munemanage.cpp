#include "munemanage.h"
#include "ui_munemanage.h"
#include "function.h"
#include "addmune.h"
#include <QSqlQuery>
#include "xiugaimune.h"
#include <QInputDialog>
#include "selectfood.h"
#define DEBUG
Munemanage::Munemanage(QWidget *parent,QString id) :
    QMainWindow(parent),user_id(id),
    ui(new Ui::Munemanage)
{
    ui->setupUi(this);
    ui->label_2->setText(user_id);
    aa=new QDishesManagement();
       // ui->pushButton_5->setIcon();
#ifdef DEBUG
    QSqlQuery query,query1,query2,query3;
        query.exec("select * from dishes where dish_category='h'");
        query1.exec("select * from dishes where dish_category='c'");
        query2.exec("select * from dishes where dish_category='s'");
        query3.exec("select * from dishes where dish_category='d'");
        while(query.next())
        {

            a=query.value(0).toString();
            b=query.value(1).toString();
            c=query.value(2).toString();
            d=query.value(3).toString();
            e=query.value(4).toString();
            qDebug()<<a<<b<<c<<d;
            FoodDetail food1(a,b,c,d,e);
            hotfoodList.insert(0,food1);
        }
        while(query1.next())
        {

            a=query1.value(0).toString();
            b=query1.value(1).toString();
            c=query1.value(2).toString();
            d=query1.value(3).toString();
            e=query1.value(4).toString();
            qDebug()<<a<<b<<c<<d;
            FoodDetail food2(a,b,c,d,e);
            coldfoodList.insert(0,food2);
        }
        while(query2.next())
        {

            a=query2.value(0).toString();
            b=query2.value(1).toString();
            c=query2.value(2).toString();
            d=query2.value(3).toString();
            e=query2.value(4).toString();
            qDebug()<<a<<b<<c<<d;
            FoodDetail food3(a,b,c,d,e);
            staplefoodList.insert(0,food3);
        }
        while(query3.next())
        {

            a=query3.value(0).toString();
            b=query3.value(1).toString();
            c=query3.value(2).toString();
            d=query3.value(3).toString();
            e=query3.value(4).toString();
            qDebug()<<a<<b<<c<<d;
            FoodDetail food4(a,b,c,d,e);
            drinkList.insert(0,food4);
        }

#endif
    // QGridLayout *layout = new QGridLayout;
    QVBoxLayout * layout = new QVBoxLayout;
    // layout->setContentsMargins(0, 24, 0, 0);
    tabWidget = new QTabWidget;

    QScrollArea *scrollArea1 = new QScrollArea;
    scrollArea1->setWidget(new Widget_Hot(this,hotfoodList));

    QScrollArea *scrollArea2 = new QScrollArea;
    scrollArea2->setWidget(new Widget_Hot(this,coldfoodList));

    QScrollArea *scrollArea3 = new QScrollArea;
    scrollArea3->setWidget(new Widget_Hot(this,staplefoodList));

    QScrollArea *scrollArea4 = new QScrollArea;
    scrollArea4->setWidget(new Widget_Hot(this,drinkList));


    tabWidget->addTab(scrollArea1, tr("热菜"));
    tabWidget->addTab(scrollArea2, tr("凉菜"));
    tabWidget->addTab(scrollArea3, tr("主食"));
    tabWidget->addTab(scrollArea4, tr("酒水"));

    layout->addWidget(tabWidget);
    ui->groupBox_MenuDedail->setLayout(layout);

}

Munemanage::~Munemanage()
{
    delete ui;
}

void Munemanage::on_pushButton_3_clicked()
{
    this->close();
    Function *fu=new Function(0,user_id);
    fu->show();
}

void Munemanage::on_pushButton_clicked()
{
    this->close();
    addmune *a=new addmune(0,user_id);
    a->show();
}

void Munemanage::buttonClicked(){
    Selectfood selectfood;
    QSqlQuery query;

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    qDebug()<<"outline "+clickedOperator;
    FoodDetail tmp = selectfood.getFoodDetailByName(clickedOperator);



    QStringList items;
    items<< tr("删除菜品") << tr("修改菜品");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("请选择操作"),clickedOperator, items, 0, false, &ok);
    if (ok && !item.isEmpty()){
        //FoodDetail tmp = getFoodDetailByName(clickedOperator);
        // tmp.setFoodCount(item);
        // foodDetailList.insert(0,tmp);
        // updateModel();
        if(item=="删除菜品")
        {
            QString id=tmp.getFoodID();
            //服务器删除
            Dishes dish;
            dish.dish_number=id;
            aa->delDish(dish);
            //判断是否成功


            //本地删除
            query.exec("delete from dishes where dish_number='"+id+"'");
            this->close();
            Munemanage *reshow=new Munemanage(0,user_id);
            reshow->show();

        }
        else if(item=="修改菜品")
        {
            a=tmp.getFoodID();
            b=tmp.getFoodName();
            c=tmp.getFoodPrice();
            d=tmp.getFoodCategory();
            e=tmp.getFoodIconID();
            this->close();
            xiugaimune *x=new xiugaimune(0,user_id,a,b,c,d,e);
            x->show();
        }
    }
}

