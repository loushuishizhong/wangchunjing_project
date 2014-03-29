#ifndef MYINDEX_H
#define MYINDEX_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QDebug>
#include <QTextCodec>
#include <QFileDialog>
#include <QMessageBox>
#include "db_func.h"
#include "addstaff.h"
#include "updatestaff.h"
#include "findstaff.h"

namespace Ui {
class myindex;
}

class myindex : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit myindex(QWidget *parent = 0,QString mysql="");
    ~myindex();
    QString sql;
public slots:
    void on_action_staff_manage_triggered();

    void on_action_exit_triggered();

    void on_pushButton_add_clicked();

private slots:
    void on_pushButton_delete_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_find_clicked();

    void on_action_workinfo_triggered();

    void on_pushButton_OK_clicked();

    void setdate();

    void setdate1();

    void on_pushButton_find_2_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_cancle_clicked();

    void on_pushButton_all_clicked();

    void tableViewClicked();

    void on_pushButton_clicked();

private:
    Ui::myindex *ui;
    QSqlTableModel *model;
    QSqlQueryModel *model1;
};

#endif // MYINDEX_H
