/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created: Thu Jul 25 12:59:02 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adduser
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QDialog *adduser)
    {
        if (adduser->objectName().isEmpty())
            adduser->setObjectName(QString::fromUtf8("adduser"));
        adduser->resize(320, 400);
        label = new QLabel(adduser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(15);
        label->setFont(font);
        groupBox = new QGroupBox(adduser);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 281, 271));
        QFont font1;
        font1.setPointSize(10);
        groupBox->setFont(font1);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 241, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(12);
        label_2->setFont(font2);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 4, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 5, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 6, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 7, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 8, 1, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 2, 1, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        label_11->setFont(font3);

        gridLayout->addWidget(label_11, 2, 0, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font3);

        gridLayout->addWidget(label_12, 3, 0, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 3, 1, 1, 1);

        pushButton = new QPushButton(adduser);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 340, 75, 31));
        pushButton_2 = new QPushButton(adduser);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 340, 75, 31));
        layoutWidget1 = new QWidget(adduser);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(240, 0, 80, 16));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout->addWidget(label_10);


        retranslateUi(adduser);

        QMetaObject::connectSlotsByName(adduser);
    } // setupUi

    void retranslateUi(QDialog *adduser)
    {
        adduser->setWindowTitle(QApplication::translate("adduser", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("adduser", "\347\224\250\346\210\267\346\267\273\345\212\240\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("adduser", "\350\257\246\347\273\206\347\224\250\346\210\267\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("adduser", "    \345\221\230\345\267\245\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("adduser", "  \345\221\230\345\267\245\347\274\226\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("adduser", "  \345\221\230\345\267\245\347\272\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("adduser", "\350\257\267\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("adduser", "\344\270\200\347\272\247", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("adduser", "\344\272\214\347\272\247", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("adduser", "\344\270\211\347\272\247", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("adduser", "      \346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("adduser", "\350\257\267\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("adduser", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("adduser", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("adduser", "    \347\216\260\344\275\217\345\235\200\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("adduser", "      \347\261\215\350\264\257\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("adduser", "  \350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("adduser", "  \347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("adduser", "      \345\271\264\351\276\204\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("adduser", "\346\217\220\344\272\244\346\226\260\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("adduser", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("adduser", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("adduser", "\345\217\267\347\240\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class adduser: public Ui_adduser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
