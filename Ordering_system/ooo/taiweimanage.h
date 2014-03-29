#ifndef TAIWEIMANAGE_H
#define TAIWEIMANAGE_H

#include <QMainWindow>
#include "qtablemanagement.h"
#include "DM1800.h"

namespace Ui {
class Taiweimanage;
}

class Taiweimanage : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Taiweimanage(QWidget *parent = 0,QString id="");
    ~Taiweimanage();
    QString user_id;
    QString table_num;
    QTableManagement *a;
    //DM1800 recv;

    
private slots:
    void on_pushButton_13_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::Taiweimanage *ui;
};

#endif // TAIWEIMANAGE_H
