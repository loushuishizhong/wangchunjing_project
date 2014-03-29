#ifndef FINDSTAFF_H
#define FINDSTAFF_H

#include <QMainWindow>
#include "myindex.h"

namespace Ui {
class findStaff;
}

class findStaff : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit findStaff(QWidget *parent = 0);
    ~findStaff();
    
private slots:
    void on_pushButton_find_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::findStaff *ui;
};

#endif // FINDSTAFF_H
