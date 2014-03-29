/********************************************************************************
** Form generated from reading UI file 'selectfood.ui'
**
** Created: Thu Jul 25 12:59:02 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTFOOD_H
#define UI_SELECTFOOD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Selectfood
{
public:
    QGroupBox *groupBox_foodMenu;
    QGroupBox *groupBox_foodList;
    QLabel *label_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Selectfood)
    {
        if (Selectfood->objectName().isEmpty())
            Selectfood->setObjectName(QString::fromUtf8("Selectfood"));
        Selectfood->resize(320, 400);
        groupBox_foodMenu = new QGroupBox(Selectfood);
        groupBox_foodMenu->setObjectName(QString::fromUtf8("groupBox_foodMenu"));
        groupBox_foodMenu->setGeometry(QRect(10, 30, 301, 191));
        QFont font;
        font.setPointSize(11);
        groupBox_foodMenu->setFont(font);
        groupBox_foodList = new QGroupBox(Selectfood);
        groupBox_foodList->setObjectName(QString::fromUtf8("groupBox_foodList"));
        groupBox_foodList->setGeometry(QRect(10, 220, 231, 171));
        groupBox_foodList->setFont(font);
        label_5 = new QLabel(Selectfood);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 91, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(15);
        label_5->setFont(font1);
        layoutWidget = new QWidget(Selectfood);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 230, 77, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        layoutWidget1 = new QWidget(Selectfood);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(230, 0, 91, 16));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setPointSize(9);
        label_3->setFont(font2);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        horizontalLayout->addWidget(label_4);

        layoutWidget2 = new QWidget(Selectfood);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(230, 20, 91, 16));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        horizontalLayout_2->addWidget(label_2);


        retranslateUi(Selectfood);

        QMetaObject::connectSlotsByName(Selectfood);
    } // setupUi

    void retranslateUi(QDialog *Selectfood)
    {
        Selectfood->setWindowTitle(QApplication::translate("Selectfood", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_foodMenu->setTitle(QApplication::translate("Selectfood", "\350\217\234\345\215\225", 0, QApplication::UnicodeUTF8));
        groupBox_foodList->setTitle(QApplication::translate("Selectfood", "\345\267\262\347\202\271\350\217\234\351\241\271", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Selectfood", "\347\202\271\350\217\234\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Selectfood", "\345\210\240\351\231\244\350\217\234\345\223\201", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Selectfood", "\344\277\256\346\224\271\350\217\234\345\223\201", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Selectfood", "\344\274\240\351\200\201\345\210\260\345\220\216\345\216\250", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Selectfood", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Selectfood", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label->setText(QApplication::translate("Selectfood", "\345\217\260\344\275\215\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Selectfood: public Ui_Selectfood {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTFOOD_H
