#ifndef ARM_INDEX_H
#define ARM_INDEX_H

#include <QMainWindow>
#include "videodevice.h"
#include <QMessageBox>
#include <QDebug>
#include <QImage>

#include"posix_qextserialport.h"
#include <QTimer>
#include <QtNetwork>
#include <QFtp>
#include <QFile>
#include <QUuid>

namespace Ui {
class arm_index;
}

class arm_index : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit arm_index(QWidget *parent = 0);
    ~arm_index();

private slots:
    void readMyCom();
    
    void replyFinished(QNetworkReply *);
    void addFinished(QNetworkReply *);

    void ftpCommandStarted(int);
    void ftpCommandFinished(int,bool);

    void takePhoto();

    void clearAll();

private:
    Ui::arm_index *ui;
    Posix_QextSerialPort *myCom;
    QTimer *readTimer;

    QNetworkAccessManager *manager, *manager1;

    QFtp *ftp;
    QFile *file;

    videodevice *video;
    int fd;
    QImage *frame;
    QString dir;
};

#endif // ARM_INDEX_H
