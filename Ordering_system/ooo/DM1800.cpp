#include "DM1800.h"
#include <QDebug>
DM1800::DM1800()
{
    struct PortSettings myComSetting = {BAUD115200,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,500};//定义一个结构体，用来存放串口各个参数

    myCom = new Win_QextSerialPort("com1",myComSetting,QextSerialBase::EventDriven);//定义串口对象，并传递参数，在构造函数里对其进行初始化

    bool bl =  myCom ->open(QIODevice::ReadWrite);
    qDebug()<<bl;
    connect(myCom,SIGNAL(readyRead()),this,SLOT(receiveData()));
    str="T";

}
/*void DM1800::readMyCom()
{
    QByteArray temp = myCom->readAll();//读取串口缓冲区的所有数据给临时变量temp

}*/
int DM1800::sendData(QString string)
{

    qDebug()<<"发送数据！";
    myCom->write(string.toAscii());
}


void DM1800::receiveData()
{
    QByteArray temp = myCom->readAll();//读取串口缓冲区的所有数据给临时变量temp
     str = QString(temp);
}

