#ifndef WIDGET_HOT_H
#define WIDGET_HOT_H



#include <QWidget>
#include "qgridlayout.h"
#include "qlist.h"
#include "qpushbutton.h"
#include "qstring.h"
#include "qmenu.h"
#include "qaction.h"
#include "qdebug.h"
#include "qtoolbutton.h"
#include "qimage.h"
#include "qscrollarea.h"
#include "fooddetail.h"
//class Dialog_NewTable;
class Widget_Hot : public QWidget
{
    Q_OBJECT
public:
    //Widget_Hot(QWidget *parent = 0);
    Widget_Hot(QWidget *parent,QList<FoodDetail> foodDetail);
    QList<FoodDetail> menuFoodNames;
  //  Dialog_NewTable * m_dialogNewTable;
private slots:
    void buttonClicked();
};

#endif // WIDGET_HOT_H
