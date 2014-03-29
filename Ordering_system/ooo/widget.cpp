
#include "widget.h"
static const QSize resultSize(60, 60);

Widget::Widget(QWidget *parent, QList<FoodDetail>foodDetail):
        QWidget(parent),menuFoodNames(foodDetail)
{

    // QScrollArea * scrollArea = new QScrollArea;

    //this->scroll(320,480);
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);


 int menuFoodListSize = menuFoodNames.size();


    for (int i = 0; i < menuFoodListSize; ++i) {
        int row = ((menuFoodListSize - i+1) / 3);
        int column = ((i) % 3) ;
        FoodDetail tmp = menuFoodNames.at(i);
        QString iconFileName = ":/Images/"+tmp.getFoodIconID()+".PNG";
        qDebug()<<"iconfile = "<<iconFileName;
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

void Widget::buttonClicked(){

// m_dialogNewTable = new Dialog_NewTable;

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
   // qDebug()<<clickedOperator;


}

