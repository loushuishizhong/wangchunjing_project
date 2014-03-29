#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "db_func.h"
#include "myindex.h"
#include <QTimer>
#include "posix_qextserialport.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit login(QWidget *parent = 0);
    ~login();
    
private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_cancle_clicked();

    void readMyCom();

private:
    Ui::login *ui;
    QString user_ID,user_pass;
    Posix_QextSerialPort *myCom;
    QTimer *readTimer;
};

#endif // LOGIN_H
