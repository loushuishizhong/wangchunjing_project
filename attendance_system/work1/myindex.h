#ifndef MYINDEX_H
#define MYINDEX_H

#include <QMainWindow>
#include <QSqlTableModel>
#include"posix_qextserialport.h"
#include <QTimer>
#include <QDate>

namespace Ui {
class myindex;
}

class myindex : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit myindex(QWidget *parent = 0);
    ~myindex();

private slots:
    void tableViewClicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_baseinfo_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_upadate_clicked();

    void on_pushButton_selectphoto_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_clear_clicked();

    void readMyCom();

    void on_pushButton_workinfo_clicked();

    void tableViewClicked_2();

    void on_pushButton_find_2_clicked();

    void setdate();

    void setdate1();
    void on_pushButton_clear_2_clicked();

private:
    Ui::myindex *ui;
    QSqlTableModel *model;
    QSqlQueryModel *model1;
    Posix_QextSerialPort *myCom;
    QTimer *readTimer;
    QString sql;
    QString photo_dir;
    QDate system_date;
};

#endif // MYINDEX_H
