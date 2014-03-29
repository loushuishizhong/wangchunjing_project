#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "qstaffmanagement.h"
//#include <QSqlQuery>
//#include <QtSql>

namespace Ui {
class Usermanage;
}

class Usermanage : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Usermanage(QWidget *parent = 0,QString id="");
    ~Usermanage();
    QString user_id;
    QStaffManagement *a;

    
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void tableViewClicked();

private:
    Ui::Usermanage *ui;
    QSqlTableModel *model;
    QMap<QString,int> levelMap;

};

#endif // USERMANAGE_H
