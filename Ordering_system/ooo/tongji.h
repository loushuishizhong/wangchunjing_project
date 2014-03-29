#ifndef TONGJI_H
#define TONGJI_H

#include <QMainWindow>
#include "QAbstractItemModel"
#include "QAbstractItemView"
#include "QSplitter"
#include "QFileDialog"
#include "QTableView"
#include "QStandardItemModel"
#include "QVBoxLayout"
#include "QGroupBox"
#include "qstatisticsmanagement.h"
#include  "DM1800.h"

namespace Ui {
    class tongji;
}

class tongji : public QMainWindow {
    Q_OBJECT
public:
    tongji(QWidget *parent = 0,QString id="");
    ~tongji();
     QString user_id;
     QStatisticsManagement *aa;

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_toolBox_currentChanged(int index);
    void on_pushButton_3_clicked();

private:
    Ui::tongji *ui;

    void setupModelForSale();
    void setupModelForStaff();
    void setupModelForDishes();
    void setupViews(const QString &path);


     QAbstractItemModel *model;
     QAbstractItemView *pieChart;
     QVBoxLayout * layout;

private slots:
    void setdate();
private slots:
    void setdate1();
};

#endif // TONGJI_H
