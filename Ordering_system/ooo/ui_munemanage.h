/********************************************************************************
** Form generated from reading UI file 'munemanage.ui'
**
** Created: Thu Jul 25 12:59:02 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUNEMANAGE_H
#define UI_MUNEMANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Munemanage
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_MenuDedail;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Munemanage)
    {
        if (Munemanage->objectName().isEmpty())
            Munemanage->setObjectName(QString::fromUtf8("Munemanage"));
        Munemanage->resize(320, 400);
        centralwidget = new QWidget(Munemanage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_MenuDedail = new QGroupBox(centralwidget);
        groupBox_MenuDedail->setObjectName(QString::fromUtf8("groupBox_MenuDedail"));
        groupBox_MenuDedail->setGeometry(QRect(10, 20, 301, 291));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 330, 95, 41));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(174, 330, 101, 41));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(230, 0, 91, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        Munemanage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Munemanage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 19));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Munemanage->setMenuBar(menubar);
        statusbar = new QStatusBar(Munemanage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Munemanage->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(Munemanage);

        QMetaObject::connectSlotsByName(Munemanage);
    } // setupUi

    void retranslateUi(QMainWindow *Munemanage)
    {
        Munemanage->setWindowTitle(QApplication::translate("Munemanage", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox_MenuDedail->setTitle(QApplication::translate("Munemanage", "\350\217\234\345\215\225\346\230\216\347\273\206", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Munemanage", "\346\267\273\345\212\240\346\226\260\350\217\234\345\223\201", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Munemanage", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Munemanage", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        menu->setTitle(QApplication::translate("Munemanage", "\350\217\234\345\215\225\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Munemanage: public Ui_Munemanage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUNEMANAGE_H
