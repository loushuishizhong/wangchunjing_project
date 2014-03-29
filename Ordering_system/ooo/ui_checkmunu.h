/********************************************************************************
** Form generated from reading UI file 'checkmunu.ui'
**
** Created: Thu Jul 25 12:59:02 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKMUNU_H
#define UI_CHECKMUNU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_checkmunu
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *listWidget;
    QPushButton *pushButton_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;

    void setupUi(QDialog *checkmunu)
    {
        if (checkmunu->objectName().isEmpty())
            checkmunu->setObjectName(QString::fromUtf8("checkmunu"));
        checkmunu->resize(320, 400);
        label = new QLabel(checkmunu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(15);
        label->setFont(font);
        layoutWidget = new QWidget(checkmunu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 0, 101, 36));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        listWidget = new QListWidget(checkmunu);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 70, 261, 231));
        pushButton_4 = new QPushButton(checkmunu);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(70, 360, 171, 23));
        widget = new QWidget(checkmunu);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 320, 261, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(checkmunu);

        QMetaObject::connectSlotsByName(checkmunu);
    } // setupUi

    void retranslateUi(QDialog *checkmunu)
    {
        checkmunu->setWindowTitle(QApplication::translate("checkmunu", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("checkmunu", "\350\264\246\345\215\225\346\266\210\350\264\271\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("checkmunu", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("checkmunu", "\345\217\260  \344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        pushButton_4->setText(QApplication::translate("checkmunu", "\346\211\223\345\215\260\350\264\246\345\215\225", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("checkmunu", "\347\273\223\350\264\246", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("checkmunu", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("checkmunu", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class checkmunu: public Ui_checkmunu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKMUNU_H
