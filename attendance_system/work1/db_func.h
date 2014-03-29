#ifndef DB_FUNC_H
#define DB_FUNC_H

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QTextStream>

struct Staff
{

    QString card_ID;
    QString staff_name;
    QString staff_sex;
    QString staff_photo;
    QString staff_ID;
    QString staff_birth;
    QString staff_phone;
    QString staff_address;
    QString staff_department;
    QString staff_position;
    QString staff_login_pass;
};


class db_func
{
public:
    QSqlDatabase db;

public slots:

    int db_open();
    int db_close();

    int addStaff(struct Staff staff);
    int deleteStaff(struct Staff satff);
    QString findPhotoDir(QString);
    int updateStaff(struct Staff satff);
};

#endif // DB_FUNC_H
