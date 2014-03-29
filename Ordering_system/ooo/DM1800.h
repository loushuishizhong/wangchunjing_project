#ifndef DM1800_H
#define DM1800_H
#include <QMainWindow>
#include "win_qextserialport.h"
#include <QDebug>
#include <QString>
#include <QObject>
class DM1800:QObject
{
    Q_OBJECT
private:

public:
    DM1800();
    int sendData(QString);
    Win_QextSerialPort *myCom;//声明串口对象
    QString str;
public slots:
    void receiveData();
};

#endif // DM1800_H
