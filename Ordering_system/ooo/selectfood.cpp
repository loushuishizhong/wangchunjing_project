#include "selectfood.h"
#include "ui_selectfood.h"
#include "function.h"
#include <QScrollArea>
#include <Qlabel>
#include <QMovie>
#include <QIcon>
#include <QSqlQuery>

#define DEBUG

void Selectfood::addFood(QAbstractItemModel *model, FoodDetail & foodDetail)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), foodDetail.getFoodName());
    model->setData(model->index(0, 1), foodDetail.getFoodPrice());
    model->setData(model->index(0, 2), foodDetail.getFoodCount());
}

Selectfood::Selectfood(QWidget *parent, QString id,QString num) :
    QDialog(parent),user_id(id),table_num(num),
    ui(new Ui::Selectfood)
{
    ui->setupUi(this);
    ui->label_4->setText(user_id);
    ui->label_2->setText(table_num);
    aa=new QTableManagement();
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
            //qDebug()<<a<<b<<c<<d;
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
            //qDebug()<<a<<b<<c<<d;
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
            //qDebug()<<a<<b<<c<<d;
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
            //qDebug()<<a<<b<<c<<d;
            FoodDetail food4(a,b,c,d,e);
            drinkList.insert(0,food4);
        }

#endif

    //菜单信息
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
    ui->groupBox_foodMenu->setLayout(layout);

    //已点菜信息

    sourceView = new QTreeView;
    sourceView->setRootIsDecorated(false);
    sourceView->setAlternatingRowColors(true);

    QHBoxLayout *sourceLayout = new QHBoxLayout;
    sourceLayout->addWidget(sourceView);
    ui->groupBox_foodList->setLayout(sourceLayout);


    connect(sourceView,SIGNAL(clicked(QModelIndex)),this,SLOT(getModelIndex(QModelIndex)));


}
void Selectfood::getModelIndex(QModelIndex index)
{

    QMap<int,QVariant> temp = m_abstractItemModel->itemData(index);
    QVariant varTmp =temp.value(0);
   // qDebug()<<index.row()<<","<<varTmp.value<QString>();

    row = index.row();
}

Selectfood::~Selectfood()
{
    delete ui;
}

void Selectfood::on_pushButton_5_clicked()
{
    this->close();
    Function *fu=new Function(0,user_id);
    fu->show();
}
void Selectfood::on_pushButton_clicked()
{

    QStringList items;
    items << tr("0") << tr("1") << tr("2") << tr("3")<< tr("4")<< tr("5")<< tr("6")<< tr("7")<< tr("8")<< tr("9");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("修改菜品数量"),
                                         tr("请确认数量"), items, 0, false, &ok);
    s_count = item;
    if (ok && !item.isEmpty()){
         m_abstractItemModel->setData(m_abstractItemModel->index(row, 2), s_count);
    }

}

void Selectfood::buttonClicked(){

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    qDebug()<<"outline "+clickedOperator;


    //选择数量

    QStringList items;
    items<< tr("1") << tr("2") << tr("3")<< tr("4")<< tr("5")<< tr("6")<< tr("7")<< tr("8")<< tr("9");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("请选择数量"),clickedOperator, items, 0, false, &ok);
        if (ok && !item.isEmpty()){
        FoodDetail tmp = getFoodDetailByName(clickedOperator);
        tmp.setFoodCount(item);
        foodDetailList.insert(0,tmp);
        updateModel();

    }

}

void Selectfood::updateModel()
{
    m_abstractItemModel = createFoodsModel(this);
    //  connect(m_abstractItemModel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(update()));
    sourceView->setModel(m_abstractItemModel);

}

FoodDetail Selectfood::getFoodDetailByName(QString  foodName)
{
    QSqlQuery query;
    query.exec("select * from dishes where dish_short_name='"+foodName+"'");
    query.next();
    a=query.value(0).toString();
    b=query.value(1).toString();
    c=query.value(2).toString();
    d=query.value(3).toString();
    e=query.value(4).toString();
    FoodDetail tmp(a,b,d,c,e);
    return tmp;

}


QAbstractItemModel *Selectfood::createFoodsModel(QObject *parent)
{
    QStandardItemModel *model = new QStandardItemModel(0, 3, parent);
    //QStringListModel * listModel;

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("菜名"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("价格"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("数量"));

    //
    QListIterator<FoodDetail> i(foodDetailList);
    while(i.hasNext()){
        FoodDetail tmp =i.next();
        //  qDebug()<<"tmp username = "<<tmp.getFoodName();
        addFood(model,tmp);
    }

    return model;
}




void Selectfood::on_pushButton_3_clicked()
{
    Dished dished;
    Staff staff;
    Bill bill;
    QDateTime datetime = QDateTime::currentDateTime();
    QString dateAndTime = datetime.toString("yyyyMMddhhmm");
    bill.bill_datetime=dateAndTime;
    bill.staff_number=user_id;
    bill.table_number=table_num;
    bill.bill_number=dateAndTime+user_id+table_num;
    dished.bill_number=bill.bill_number;
    bill.bill_status="1";
    //a="";
    int s=0;
    int k=0;
    int n=0;
    int f=foodDetailList.size();
    for(int i=0;i<f;i++)
    {
        FoodDetail tmp=foodDetailList.at(i);
        dished.dished_count=tmp.getFoodCount();
        n=tmp.getFoodCount().toInt();
        b=tmp.getFoodName();
        k=tmp.getFoodPrice().toInt();
        dished.dish_number=tmp.getFoodID();

        aa->sendDishedInfo(dished,staff,bill);//传到后厨
        s=s+k*n;
        qDebug()<<dished.dish_number<<n<<b<<k<<s;
        //判断是否处理成功
    }



    bill.bill_amount_money=QString::number(s);
    qDebug()<<bill.bill_number<<bill.bill_amount_money;

    aa->sendDishedinfo_2(dished,staff,bill);//传到账单


    //判断是否处理成功

}

void Selectfood::on_pushButton_2_clicked()
{
    if(sourceView->currentIndex().row()+1!=foodDetailList.size())
    {
        m_abstractItemModel->removeRow(sourceView->currentIndex().row());
        foodDetailList.removeAt(foodDetailList.size()-1-sourceView->currentIndex().row());
    }
    else
    {
         m_abstractItemModel->removeRow(sourceView->currentIndex().row() );
         foodDetailList.removeAt(0);
    }
     //qDebug()<<foodDetailList.size()<<sourceView->currentIndex().row();
     //qDebug()<<sourceView->currentIndex().row();
}
