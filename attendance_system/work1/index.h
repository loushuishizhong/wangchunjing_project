#ifndef INDEX_H
#define INDEX_H

#include <QMainWindow>

namespace Ui {
class index;
}

class index : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit index(QWidget *parent = 0);
    ~index();
    
private:
    Ui::index *ui;
};

#endif // INDEX_H
