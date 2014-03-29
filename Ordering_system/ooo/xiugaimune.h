#ifndef XIUGAIMUNE_H
#define XIUGAIMUNE_H

#include <QDialog>
#include <QDir>
#include "qdishesmanagement.h"


namespace Ui {
    class xiugaimune;
}

class xiugaimune : public QDialog {
    Q_OBJECT
public:
    xiugaimune(QWidget *parent = 0,QString id="",QString a="",QString b="",QString c="",QString d="",QString e="");
    ~xiugaimune();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::xiugaimune *ui;
    QString user_id;
    QString aa,bb,cc,dd,ee;
    QDishesManagement dish_man;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // XIUGAIMUNE_H
