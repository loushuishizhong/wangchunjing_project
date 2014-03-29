#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    


private slots:
    void on_comboBox_currentIndexChanged( );
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    QString user_id;
};

#endif // MAINWINDOW_H
