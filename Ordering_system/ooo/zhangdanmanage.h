#ifndef ZHANGDANMANAGE_H
#define ZHANGDANMANAGE_H

#include <QMainWindow>
#include "qbillmanagement.h"

namespace Ui {
class Zhangdanmanage;
}

class Zhangdanmanage : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Zhangdanmanage(QWidget *parent = 0,QString id="");
    ~Zhangdanmanage();
    QString user_id;
    QString table_num;
    QBillManagement *a;
    
private slots:

    void on_pushButton_2_clicked();

private:
    Ui::Zhangdanmanage *ui;
};

#endif // ZHANGDANMANAGE_H
