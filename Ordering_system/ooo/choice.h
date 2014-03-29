#ifndef CHOICE_H
#define CHOICE_H

#include <QDialog>
#include "qtablemanagement.h"
namespace Ui {
class Choice;
}

class Choice : public QDialog
{
    Q_OBJECT
    
public:
    explicit Choice(QWidget *parent = 0,QString id="",QString num="");
    ~Choice();
     QString user_id;
     QString table_num;
    QTableManagement *a;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Choice *ui;
};

#endif // CHOICE_H
