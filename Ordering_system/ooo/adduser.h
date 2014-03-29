#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include "qstaffmanagement.h"
//#include <QSqlQuery>
//#include <QtSql>

namespace Ui {
    class adduser;
}

class adduser : public QDialog {
    Q_OBJECT
public:
    adduser(QWidget *parent = 0,QString id="");
    ~adduser();
     QString user_id;
     QStaffManagement *a;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::adduser *ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // ADDUSER_H
