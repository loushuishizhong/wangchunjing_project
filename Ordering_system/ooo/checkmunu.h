#ifndef CHECKMUNU_H
#define CHECKMUNU_H

#include <QDialog>
//#include "qbillmanagement.h"
#include "qtablemanagement.h"


namespace Ui {
    class checkmunu;
}

class checkmunu : public QDialog {
    Q_OBJECT
public:
    QTableManagement *b;
    //QBillManagement *a;
    checkmunu(QWidget *parent = 0,QString id="",QString num="");
    ~checkmunu();
     QString user_id;
     QString table_num;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::checkmunu *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
};

#endif // CHECKMUNU_H
