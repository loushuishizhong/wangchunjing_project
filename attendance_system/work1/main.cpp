#include "login.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");//GB2312也可以
    QTextCodec::setCodecForCStrings(codec);// 1
    QTextCodec::setCodecForLocale(codec);// 2
    QTextCodec::setCodecForTr(codec);// 3

    login w;
    w.show();

    return a.exec();
}
