/********************************************************************************
** Form generated from reading UI file 'zhangdanmanage.ui'
**
** Created: Thu Jul 25 12:59:02 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHANGDANMANAGE_H
#define UI_ZHANGDANMANAGE_H

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
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Zhangdanmanage
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTableView *tableView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Zhangdanmanage)
    {
        if (Zhangdanmanage->objectName().isEmpty())
            Zhangdanmanage->setObjectName(QString::fromUtf8("Zhangdanmanage"));
        Zhangdanmanage->resize(320, 400);
        centralwidget = new QWidget(Zhangdanmanage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 281, 251));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 20, 241, 211));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 300, 241, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(240, 0, 81, 17));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        Zhangdanmanage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Zhangdanmanage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 19));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Zhangdanmanage->setMenuBar(menubar);
        statusbar = new QStatusBar(Zhangdanmanage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Zhangdanmanage->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(Zhangdanmanage);

        QMetaObject::connectSlotsByName(Zhangdanmanage);
    } // setupUi

    void retranslateUi(QMainWindow *Zhangdanmanage)
    {
        Zhangdanmanage->setWindowTitle(QApplication::translate("Zhangdanmanage", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Zhangdanmanage", "\350\264\246\345\215\225\346\230\216\347\273\206", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Zhangdanmanage", "\346\237\245\350\257\242\346\266\210\350\264\271\346\230\216\347\273\206", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Zhangdanmanage", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Zhangdanmanage", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        menu->setTitle(QApplication::translate("Zhangdanmanage", "\350\264\246\345\215\225\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Zhangdanmanage: public Ui_Zhangdanmanage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHANGDANMANAGE_H
