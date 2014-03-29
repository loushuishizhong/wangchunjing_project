#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "myindex.h"
#include "db_func.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit login(QWidget *parent = 0);
    ~login();
    myindex i;
    
private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_cancle_clicked();

private:
    Ui::login *ui;
    QString user_name,user_pass;
    //db_func d;
};

#endif // LOGIN_H
