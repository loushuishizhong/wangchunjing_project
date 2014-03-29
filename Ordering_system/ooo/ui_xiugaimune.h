/********************************************************************************
** Form generated from reading UI file 'xiugaimune.ui'
**
** Created: Thu Jul 25 12:59:02 2013
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XIUGAIMUNE_H
#define UI_XIUGAIMUNE_H

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

class Ui_xiugaimune
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *xiugaimune)
    {
        if (xiugaimune->objectName().isEmpty())
            xiugaimune->setObjectName(QString::fromUtf8("xiugaimune"));
        xiugaimune->resize(320, 400);
        label = new QLabel(xiugaimune);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(15);
        label->setFont(font);
        layoutWidget = new QWidget(xiugaimune);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 0, 80, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        pushButton_4 = new QPushButton(xiugaimune);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 270, 41, 21));
        widget = new QWidget(xiugaimune);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 330, 239, 31));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        label_6 = new QLabel(xiugaimune);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 99, 60, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(11);
        label_6->setFont(font1);
        label_4 = new QLabel(xiugaimune);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 61, 60, 16));
        label_4->setFont(font1);
        label_9 = new QLabel(xiugaimune);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 270, 60, 21));
        label_9->setFont(font1);
        label_5 = new QLabel(xiugaimune);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 140, 60, 21));
        label_5->setFont(font1);
        label_7 = new QLabel(xiugaimune);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 180, 62, 21));
        label_7->setFont(font1);
        label_8 = new QLabel(xiugaimune);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 220, 60, 21));
        label_8->setFont(font1);
        lineEdit = new QLineEdit(xiugaimune);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 60, 141, 20));
        lineEdit_4 = new QLineEdit(xiugaimune);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(130, 180, 141, 20));
        lineEdit_5 = new QLineEdit(xiugaimune);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(130, 220, 141, 20));
        lineEdit_6 = new QLineEdit(xiugaimune);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(130, 270, 101, 20));
        lineEdit_3 = new QLineEdit(xiugaimune);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 100, 141, 20));
        lineEdit_2 = new QLineEdit(xiugaimune);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 140, 141, 20));

        retranslateUi(xiugaimune);

        QMetaObject::connectSlotsByName(xiugaimune);
    } // setupUi

    void retranslateUi(QDialog *xiugaimune)
    {
        xiugaimune->setWindowTitle(QApplication::translate("xiugaimune", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("xiugaimune", "\344\277\256\346\224\271\346\226\260\350\217\234\345\223\201", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("xiugaimune", "\346\223\215\344\275\234\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("xiugaimune", "\345\217\267\347\240\201", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("xiugaimune", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("xiugaimune", "\344\277\256\346\224\271\350\217\234\345\223\201", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("xiugaimune", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("xiugaimune", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("xiugaimune", "\350\217\234\345\223\201\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("xiugaimune", "\350\217\234\345\223\201\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("xiugaimune", "\350\217\234\345\223\201\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("xiugaimune", "\350\217\234\345\223\201\347\256\200\347\247\260", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("xiugaimune", "\350\217\234\345\223\201\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("xiugaimune", "\350\217\234\345\223\201\344\273\267\346\240\274", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class xiugaimune: public Ui_xiugaimune {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XIUGAIMUNE_H
