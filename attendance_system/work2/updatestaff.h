#ifndef UPDATESTAFF_H
#define UPDATESTAFF_H

#include <QMainWindow>
#include "myindex.h"
#include <QUuid>
#include <QTime>
#include "videodevice.h"
#include <QMessageBox>
#include <QDebug>
#include <QImage>
#include <QTimer>
#include <QUuid>

namespace Ui {
class updateStaff;
}

class updateStaff : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit updateStaff(QWidget *parent = 0,struct Staff *staff=NULL);
    ~updateStaff();
    struct Staff *mystaff;
    
private slots:
    void on_pushButton_submit_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_look_clicked();

    void on_pushButton_local_clicked();

    int convert_yuv_to_rgb_pixel(int y, int u, int v);

    int convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);

    void updateShow();

    void on_pushButton_camera_clicked();

    void on_pushButton_takephoto_clicked();

    void on_pushButton_retake_clicked();

    void on_pushButton_OK_clicked();

    void on_pushButton_cancle_clicked();

private:
    Ui::updateStaff *ui;

    VideoDevice *vi;
    uchar *p,*pp;
    unsigned int len;
    int rs;
    QImage *frame;
    QTimer *timer;
};

#endif // UPDATESTAFF_H
