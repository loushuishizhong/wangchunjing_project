/********************************************************************************
** Form generated from reading UI file 'usermanage.ui'
**
** Created: Thu Jul 25 12:59:02 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGE_H
#define UI_USERMANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Usermanage
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_5;
    QComboBox *comboBox;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QTableView *tableView;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Usermanage)
    {
        if (Usermanage->objectName().isEmpty())
            Usermanage->setObjectName(QString::fromUtf8("Usermanage"));
        Usermanage->resize(322, 400);
        centralwidget = new QWidget(Usermanage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 301, 171));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 180, 301, 151));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 60, 221, 91));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout_3->addWidget(lineEdit_5);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_3->addWidget(lineEdit_4);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_3->addWidget(lineEdit_3);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(71, 10, 81, 21));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(220, 10, 71, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 10, 51, 21));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 10, 59, 21));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(11, 120, 59, 31));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(11, 90, 59, 31));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(11, 60, 59, 31));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 40, 61, 21));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(160, 40, 51, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 40, 42, 21));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(250, 40, 38, 20));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 30, 71, 41));
        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(70, 40, 31, 20));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(15, 30, 291, 141));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 340, 301, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(240, 0, 81, 16));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Usermanage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Usermanage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 322, 19));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Usermanage->setMenuBar(menubar);
        statusbar = new QStatusBar(Usermanage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Usermanage->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(Usermanage);

        QMetaObject::connectSlotsByName(Usermanage);
    } // setupUi

    void retranslateUi(QMainWindow *Usermanage)
    {
        Usermanage->setWindowTitle(QApplication::translate("Usermanage", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Usermanage", "\346\223\215\344\275\234\345\221\230\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Usermanage", "\350\257\246\347\273\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Usermanage", "\347\224\250\346\210\267ID\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Usermanage", " \347\224\250\346\210\267\345\220\215 \357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Usermanage", " \347\216\260\344\275\217\345\235\200 \357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Usermanage", " \347\261\215  \350\264\257 \357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Usermanage", " \350\272\253\344\273\275\350\257\201 \357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Usermanage", "\345\221\230\345\267\245\347\272\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Usermanage", "\344\270\200\347\272\247", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Usermanage", "\344\272\214\347\272\247", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Usermanage", "\344\270\211\347\272\247", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("Usermanage", " \346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Usermanage", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Usermanage", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("Usermanage", " \345\271\264   \351\276\204\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Usermanage", "\346\267\273\345\212\240\346\226\260\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Usermanage", "\345\210\240\351\231\244\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Usermanage", "\346\233\264\346\226\260\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Usermanage", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Usermanage", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        menu->setTitle(QApplication::translate("Usermanage", "\347\224\250\346\210\267\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Usermanage: public Ui_Usermanage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGE_H
