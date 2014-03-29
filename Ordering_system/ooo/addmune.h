#ifndef ADDMUNE_H
#define ADDMUNE_H

#include <QDialog>
#include <QWidget>
#include <QStringList>
#include <QDir>
#include "qdishesmanagement.h"

namespace Ui {
    class addmune;
}

class addmune : public QDialog {
    Q_OBJECT
public:
    addmune(QWidget *parent = 0,QString id="");
    ~addmune();
     QString user_id;
    void browse();
    QDishesManagement *a;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::addmune *ui;

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_comboBox_activated(QString );
    //void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};

#endif // ADDMUNE_H
