/********************************************************************************
** Form generated from reading UI file 'choice.ui'
**
** Created: Thu Jul 25 14:26:56 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOICE_H
#define UI_CHOICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Choice
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *Choice)
    {
        if (Choice->objectName().isEmpty())
            Choice->setObjectName(QString::fromUtf8("Choice"));
        Choice->resize(248, 232);
        pushButton = new QPushButton(Choice);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 170, 75, 23));
        pushButton_2 = new QPushButton(Choice);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 170, 75, 23));
        label = new QLabel(Choice);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        comboBox = new QComboBox(Choice);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 110, 131, 21));
        layoutWidget = new QWidget(Choice);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 0, 91, 20));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        layoutWidget1 = new QWidget(Choice);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(150, 20, 91, 21));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);


        retranslateUi(Choice);

        QMetaObject::connectSlotsByName(Choice);
    } // setupUi

    void retranslateUi(QDialog *Choice)
    {
        Choice->setWindowTitle(QApplication::translate("Choice", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Choice", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Choice", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Choice", "\345\217\260\344\275\215\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Choice", "\345\274\200\345\217\260/\347\202\271\350\217\234", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Choice", "\347\273\223\350\264\246", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Choice", "\351\242\204\350\256\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Choice", "\345\217\226\346\266\210\351\242\204\350\256\242", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Choice", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("Choice", "\345\217\260\344\275\215\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Choice: public Ui_Choice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOICE_H
