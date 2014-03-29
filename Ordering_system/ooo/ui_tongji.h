/********************************************************************************
** Form generated from reading UI file 'tongji.ui'
**
** Created: Thu Jul 25 13:10:20 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TONGJI_H
#define UI_TONGJI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QDateEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tongji
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QWidget *page_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *beginButton;
    QDateEdit *beginEdit;
    QPushButton *stopButton;
    QDateEdit *stopEdit;
    QCalendarWidget *calendarWidget;
    QCalendarWidget *calendarWidget_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *tongji)
    {
        if (tongji->objectName().isEmpty())
            tongji->setObjectName(QString::fromUtf8("tongji"));
        tongji->resize(320, 400);
        centralwidget = new QWidget(tongji);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 61, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 0, 51, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 0, 41, 16));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 340, 91, 21));
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(10, 50, 301, 291));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 301, 213));
        toolBox->addItem(page, QString::fromUtf8("\345\221\230\345\267\245\350\200\203\345\213\244"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 301, 213));
        toolBox->addItem(page_2, QString::fromUtf8("\350\217\234\345\223\201\351\224\200\345\224\256"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 301, 213));
        toolBox->addItem(page_3, QString::fromUtf8("\351\224\200\345\224\256\351\242\235"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 301, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        beginButton = new QPushButton(layoutWidget);
        beginButton->setObjectName(QString::fromUtf8("beginButton"));

        horizontalLayout->addWidget(beginButton);

        beginEdit = new QDateEdit(layoutWidget);
        beginEdit->setObjectName(QString::fromUtf8("beginEdit"));

        horizontalLayout->addWidget(beginEdit);

        stopButton = new QPushButton(layoutWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        horizontalLayout->addWidget(stopButton);

        stopEdit = new QDateEdit(layoutWidget);
        stopEdit->setObjectName(QString::fromUtf8("stopEdit"));

        horizontalLayout->addWidget(stopEdit);

        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 40, 151, 141));
        calendarWidget_2 = new QCalendarWidget(centralwidget);
        calendarWidget_2->setObjectName(QString::fromUtf8("calendarWidget_2"));
        calendarWidget_2->setGeometry(QRect(160, 40, 151, 141));
        tongji->setCentralWidget(centralwidget);
        menubar = new QMenuBar(tongji);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 19));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        tongji->setMenuBar(menubar);
        statusbar = new QStatusBar(tongji);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        tongji->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(tongji);

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(tongji);
    } // setupUi

    void retranslateUi(QMainWindow *tongji)
    {
        tongji->setWindowTitle(QApplication::translate("tongji", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("tongji", "\346\227\245\346\234\237\351\200\211\346\213\251\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("tongji", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        pushButton_3->setText(QApplication::translate("tongji", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("tongji", "\345\221\230\345\267\245\350\200\203\345\213\244", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("tongji", "\350\217\234\345\223\201\351\224\200\345\224\256", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("tongji", "\351\224\200\345\224\256\351\242\235", 0, QApplication::UnicodeUTF8));
        beginButton->setText(QApplication::translate("tongji", "\350\265\267\345\247\213\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("tongji", "\347\273\210\346\255\242\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("tongji", "\347\273\237\350\256\241\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class tongji: public Ui_tongji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TONGJI_H
