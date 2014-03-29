#ifndef ADDSTAFF_H
#define ADDSTAFF_H

#include <QMainWindow>
#include <QTimer>
#include "myindex.h"
#include "posix_qextserialport.h"

#include "videodevice.h"
#include <QMessageBox>
#include <QDebug>
#include <QImage>
#include <QUuid>
#include <QTime>

namespace Ui {
class addStaff;
}

class addStaff : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit addStaff(QWidget *parent = 0);
    ~addStaff();
    
private slots:
    void on_pushButton_submit_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_clear_clicked();

    void readMyCom();

    void on_pushButton_look_clicked();

    void on_pushButton_local_clicked();

    void on_pushButton_cameraca_clicked();

    void on_pushButton_cancle_clicked();

    int convert_yuv_to_rgb_pixel(int y, int u, int v);

    int convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);

    void updateShow();

    void on_pushButton_retake_clicked();

    void on_pushButton_takephoto_clicked();

    void on_pushButton_OK_clicked();

private:
    Ui::addStaff *ui;
    Posix_QextSerialPort *myCom;
    QTimer *readTimer;

    VideoDevice *vi;
    uchar *p,*pp;
    unsigned int len;
    int rs;
    QImage *frame;
    QTimer *timer;
};

#endif // ADDSTAFF_H


