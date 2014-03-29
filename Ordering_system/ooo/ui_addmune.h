/********************************************************************************
** Form generated from reading UI file 'addmune.ui'
**
** Created: Thu Jul 25 12:59:02 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMUNE_H
#define UI_ADDMUNE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addmune
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QLabel *label_7;
    QLineEdit *lineEdit_6;

    void setupUi(QDialog *addmune)
    {
        if (addmune->objectName().isEmpty())
            addmune->setObjectName(QString::fromUtf8("addmune"));
        addmune->resize(320, 400);
        label = new QLabel(addmune);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        layoutWidget = new QWidget(addmune);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 0, 80, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        pushButton_4 = new QPushButton(addmune);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 270, 31, 20));
        widget = new QWidget(addmune);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 310, 261, 51));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        label_2 = new QLabel(addmune);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 78, 64, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(12);
        label_2->setFont(font1);
        lineEdit = new QLineEdit(addmune);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 78, 151, 20));
        label_4 = new QLabel(addmune);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 116, 64, 17));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(12);
        font2.setItalic(false);
        label_4->setFont(font2);
        lineEdit_3 = new QLineEdit(addmune);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(120, 116, 151, 20));
        label_3 = new QLabel(addmune);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 154, 64, 17));
        label_3->setFont(font1);
        label_5 = new QLabel(addmune);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 192, 64, 17));
        label_5->setFont(font1);
        lineEdit_2 = new QLineEdit(addmune);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 154, 151, 20));
        lineEdit_4 = new QLineEdit(addmune);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(120, 192, 151, 20));
        label_6 = new QLabel(addmune);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 230, 64, 17));
        label_6->setFont(font1);
        lineEdit_5 = new QLineEdit(addmune);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 230, 151, 20));
        label_7 = new QLabel(addmune);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 268, 68, 17));
        label_7->setFont(font1);
        lineEdit_6 = new QLineEdit(addmune);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(120, 268, 121, 20));

        retranslateUi(addmune);

        QMetaObject::connectSlotsByName(addmune);
    } // setupUi

    void retranslateUi(QDialog *addmune)
    {
        addmune->setWindowTitle(QApplication::translate("addmune", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addmune", "\346\267\273\345\212\240\346\226\260\350\217\234\345\223\201", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("addmune", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("addmune", "\345\217\267\347\240\201", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("addmune", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("addmune", "\346\217\220\344\272\244\346\226\260\350\217\234\345\223\201", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("addmune", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("addmune", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("addmune", "\350\217\234\345\223\201\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("addmune", "\350\217\234\345\223\201\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("addmune", "\350\217\234\345\223\201\347\256\200\347\247\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("addmune", "\350\217\234\345\223\201\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("addmune", "\350\217\234\345\223\201\344\273\267\346\240\274", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("addmune", " \350\217\234\345\223\201\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addmune: public Ui_addmune {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMUNE_H
