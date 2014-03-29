#include "DM1800.h"
#include <QDebug>
DM1800::DM1800()
{
    struct PortSettings myComSetting = {BAUD115200,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,500};//����һ���ṹ�壬������Ŵ��ڸ�������

    myCom = new Win_QextSerialPort("com1",myComSetting,QextSerialBase::EventDriven);//���崮�ڶ��󣬲����ݲ������ڹ��캯���������г�ʼ��

    bool bl =  myCom ->open(QIODevice::ReadWrite);
    qDebug()<<bl;
    connect(myCom,SIGNAL(readyRead()),this,SLOT(receiveData()));
    str="T";

}
/*void DM1800::readMyCom()
{
    QByteArray temp = myCom->readAll();//��ȡ���ڻ��������������ݸ���ʱ����temp

}*/
int DM1800::sendData(QString string)
{

    qDebug()<<"�������ݣ�";
    myCom->write(string.toAscii());
}


void DM1800::receiveData()
{
    QByteArray temp = myCom->readAll();//��ȡ���ڻ��������������ݸ���ʱ����temp
     str = QString(temp);
}

