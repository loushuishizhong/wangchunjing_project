#ifndef SELECTFOOD_H
#define SELECTFOOD_H

#include <QDialog>
#include <QLabel>
#include <QToolButton>
#include "qtabwidget.h"
#include "widget_hot.h"
#include "qscrollarea.h"
#include "qstringlistmodel.h"
#include "qstringlist.h"
#include "qlistview.h"
#include "qstandarditemmodel.h"
#include "qtreeview.h"
#include "QVBoxLayout"
#include "QDate"
#include "QDateTime"
#include "qmessagebox.h"
#include "fooddetail.h"
#include <QList>
#include <QInputDialog>
#include "qtablemanagement.h"


namespace Ui {
class Selectfood;
}

class Selectfood : public QDialog
{
    Q_OBJECT
       
public:
    explicit Selectfood(QWidget *parent = 0,QString id="",QString num="");
    ~Selectfood();
     QString user_id;
     QString table_num;
     QTableManagement *aa;
    
     void updateModel();
     FoodDetail getFoodDetailByName(QString  foodName);



private:
    Ui::Selectfood *ui;
    QTabWidget * tabWidget;
    //QString m_id;
    //QString m_tableNumber;
    QStringListModel * m_stringListModel;
    QStringList * m_stringList;
    QListView * m_listView;
    QAbstractItemModel * m_abstractItemModel;
    QAbstractItemModel *createFoodsModel(QObject *parent);

    QList<FoodDetail> foodDetailList;
    QAbstractItemModel *m_itemModel;
    //菜单分类冷、热、酒水、主食
    QList<FoodDetail> hotfoodList;
    QList<FoodDetail> coldfoodList;
    QList<FoodDetail> drinkList;
    QList<FoodDetail> staplefoodList;
    QString a,b,c,d,e;


    //
    void addFood(QAbstractItemModel *model,  FoodDetail & foodDetail);

    QTreeView *sourceView;
    int row;

    //数量
    int count;
    QString s_count;
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    //void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
 //   void on_pushButton_modify_clicked();
   // void on_groupBox_foodList_clicked();
    void on_pushButton_clicked();
    void getModelIndex(QModelIndex);
    void buttonClicked();
};

#endif // SELECTFOOD_H
