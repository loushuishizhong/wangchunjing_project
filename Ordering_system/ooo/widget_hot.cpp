#include "widget_hot.h"
static const QSize resultSize(60, 60);

Widget_Hot::Widget_Hot(QWidget *parent, QList<FoodDetail>foodDetail):
        QWidget(parent),menuFoodNames(foodDetail)
{

    // QScrollArea * scrollArea = new QScrollArea;

    //this->scroll(320,480);
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);


 int menuFoodListSize = menuFoodNames.size();


    for (int i = 0; i < menuFoodListSize; ++i) {
        int row = (i / 2);
        int column = ((i) % 2) ;
        FoodDetail tmp = menuFoodNames.at(i);
        QString iconFileName =tmp.getFoodIconID();
        //qDebug()<<"iconfile = "<<iconFileName;
        QIcon icon(iconFileName);
        QPushButton * pushbutton = new QPushButton(tmp.getFoodName(),this);
        pushbutton->setIconSize(resultSize);
        pushbutton->setIcon(icon);
       // connect(pushbutton,SIGNAL(clicked()),this,SLOT(buttonClicked()));
        connect(pushbutton,SIGNAL(clicked()),this->parent(),SLOT(buttonClicked()));
        mainLayout->addWidget(pushbutton, row, column);
    }


    this->setLayout(mainLayout);
}

void Widget_Hot::buttonClicked(){

// m_dialogNewTable = new Dialog_NewTable;

    //QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    //QString clickedOperator = clickedButton->text();
   // qDebug()<<clickedOperator;


}

