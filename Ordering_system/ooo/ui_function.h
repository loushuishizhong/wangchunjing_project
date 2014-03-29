/********************************************************************************
** Form generated from reading UI file 'function.ui'
**
** Created: Thu Jul 25 12:59:02 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTION_H
#define UI_FUNCTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Function
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *taiweiButton;
    QPushButton *muneButton;
    QPushButton *zhangdanButton;
    QPushButton *userButton;
    QPushButton *tongjiButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Function)
    {
        if (Function->objectName().isEmpty())
            Function->setObjectName(QString::fromUtf8("Function"));
        Function->resize(320, 400);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(15);
        Function->setFont(font);
        Function->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Function);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 40, 241, 321));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        taiweiButton = new QPushButton(layoutWidget);
        taiweiButton->setObjectName(QString::fromUtf8("taiweiButton"));
        taiweiButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(taiweiButton, 0, 0, 1, 1);

        muneButton = new QPushButton(layoutWidget);
        muneButton->setObjectName(QString::fromUtf8("muneButton"));
        muneButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(muneButton, 0, 1, 1, 1);

        zhangdanButton = new QPushButton(layoutWidget);
        zhangdanButton->setObjectName(QString::fromUtf8("zhangdanButton"));
        zhangdanButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(zhangdanButton, 1, 0, 1, 1);

        userButton = new QPushButton(layoutWidget);
        userButton->setObjectName(QString::fromUtf8("userButton"));
        userButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(userButton, 1, 1, 1, 1);

        tongjiButton = new QPushButton(layoutWidget);
        tongjiButton->setObjectName(QString::fromUtf8("tongjiButton"));
        tongjiButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(tongjiButton, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(pushButton_8, 3, 0, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(pushButton_7, 3, 1, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(210, 0, 111, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        Function->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Function);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 19));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Function->setMenuBar(menubar);
        statusbar = new QStatusBar(Function);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Function->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addSeparator();

        retranslateUi(Function);
        QObject::connect(pushButton_7, SIGNAL(clicked()), Function, SLOT(close()));

        QMetaObject::connectSlotsByName(Function);
    } // setupUi

    void retranslateUi(QMainWindow *Function)
    {
        Function->setWindowTitle(QApplication::translate("Function", "MainWindow", 0, QApplication::UnicodeUTF8));
        taiweiButton->setText(QApplication::translate("Function", "\345\217\260\344\275\215\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        muneButton->setText(QApplication::translate("Function", "\350\217\234\345\215\225\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        zhangdanButton->setText(QApplication::translate("Function", "\350\264\246\345\215\225\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        userButton->setText(QApplication::translate("Function", "\347\224\250\346\210\267\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        tongjiButton->setText(QApplication::translate("Function", "\347\273\237\350\256\241\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Function", "\345\220\214\346\255\245", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Function", "\345\205\266\344\273\226\345\272\224\347\224\250", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Function", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Function", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        menu->setTitle(QApplication::translate("Function", "\344\270\273\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Function: public Ui_Function {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTION_H
