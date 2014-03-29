#ifndef MUNEMANAGE_H
#define MUNEMANAGE_H

#include <QMainWindow>
#include "qtabwidget.h"
#include "widget_hot.h"
#include "qscrollarea.h"
#include "qstringlistmodel.h"
#include "qstringlist.h"
#include "qlistview.h"
#include "qstandarditemmodel.h"
#include "qtreeview.h"
#include "fooddetail.h"
#include "qdishesmanagement.h"

namespace Ui {
class Munemanage;
}

class Munemanage : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Munemanage(QWidget *parent = 0,QString id="");
    ~Munemanage();
    QString user_id;
    QDishesManagement *aa;
    
private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void buttonClicked();

private:
    Ui::Munemanage *ui;
    QTabWidget * tabWidget;
    QList<FoodDetail> hotfoodList;
    QList<FoodDetail> coldfoodList;
    QList<FoodDetail> drinkList;
    QList<FoodDetail> staplefoodList;
    QString a,b,c,d,e;
};

#endif // MUNEMANAGE_H
