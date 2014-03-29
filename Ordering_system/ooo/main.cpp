#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    if(!createConnection())
        return 0;
    MainWindow w;
    w.show();
    
    return a.exec();
}
