#ifndef FUNCTION_H
#define FUNCTION_H

#include <QMainWindow>
#include "qdishesmanagement.h"
#include "qstaffmanagement.h"

namespace Ui {
    class Function;
}

class Function : public QMainWindow {
    Q_OBJECT

public:
    QDishesManagement *a;
    QStaffManagement *b;
    Function(QWidget *parent = 0,QString id="");
    ~Function();
    QString user_id;

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButton_6_clicked();
    void on_taiweiButton_clicked();

    void on_muneButton_clicked();

    void on_zhangdanButton_clicked();

    void on_userButton_clicked();

    void on_tongjiButton_clicked();

private:
    Ui::Function *ui;

};

#endif // FUNCTION_H
