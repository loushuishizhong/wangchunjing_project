#include "usermanage.h"
#include "ui_usermanage.h"
#include "function.h"
#include "adduser.h"
#include <QSqlTableModel>
#include <QSqlQuery>
Usermanage::Usermanage(QWidget *parent,QString id) :
        QMainWindow(parent),user_id(id),
        ui(new Ui::Usermanage)
{
    ui->setupUi(this);
    ui->label_2->setText(user_id);
    a=new QStaffManagement();

    model=new QSqlTableModel();
    model->setTable("staff");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->removeColumn(2);
    // model->removeColumn(3);
    //model->removeColumn(4);
    // model->removeColumn(5);
    //model->removeColumn(6);
    // model->removeColumn(8);
    model->setHeaderData(0,Qt::Horizontal,tr("用户编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    //model->setHeaderData(2,Qt::Horizontal,tr("密码"));
    model->setHeaderData(2,Qt::Horizontal,tr("性别"));
    model->setHeaderData(3,Qt::Horizontal,tr("籍贯"));
    model->setHeaderData(4,Qt::Horizontal,tr("现住址"));
    model->setHeaderData(5,Qt::Horizontal,tr("年龄"));
    model->setHeaderData(6,Qt::Horizontal,tr("级别"));
    model->setHeaderData(7,Qt::Horizontal,tr("证件号"));

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QString str_level1(tr("一级"));
    QString str_level2(tr("二级"));
    QString str_level3(tr("三级"));


    levelMap.insert(str_level1,0);
    levelMap.insert(str_level2,1);
    levelMap.insert(str_level3,2);
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(tableViewClicked()));

}

Usermanage::~Usermanage()
{
    delete ui;
}

void Usermanage::on_pushButton_4_clicked()
{
    this->close();
    Function *fu=new Function(0,user_id);
    fu->show();
}

void Usermanage::on_pushButton_clicked()
{
    this->close();
    adduser *a=new adduser(0,user_id);
    a->show();
}

void Usermanage::tableViewClicked()
{
    int curRow = ui->tableView->currentIndex().row();

    ui->lineEdit->setText(model->index(curRow,0).data().toString());
    ui->lineEdit_2->setText(model->index(curRow,1).data().toString());

    QString str_level;
    QString char_level = model->index(curRow,6).data().toString();
    if(char_level == "0")
        str_level = "一级";
    else if(char_level == "1")
        str_level = "二级";
    else
        str_level = "三级";
    int index = levelMap.value(str_level);
    ui->comboBox->setCurrentIndex(index);

    if(model->index(curRow,2).data().toString() == "男")
        ui->comboBox_2->setCurrentIndex(0);
    else
        ui->comboBox_2->setCurrentIndex(1);

    ui->lineEdit_6->setText(model->index(curRow,5).data().toString());
    ui->lineEdit_3->setText(model->index(curRow,4).data().toString());
    ui->lineEdit_4->setText(model->index(curRow,3).data().toString());
    ui->lineEdit_5->setText(model->index(curRow,7).data().toString());
}

void Usermanage::on_pushButton_2_clicked()//删除员工
{
    QSqlQuery query;

    Staff staff;
    staff.staff_number=ui->lineEdit->text();
    query.exec("select * from staff where staff_number='"+staff.staff_number+"'");
    query.exec("delete from staff where staff_number='"+staff.staff_number+"'");
    staff.staff_name=query.value(1).toString();
    staff.staff_login_pass=query.value(2).toString();
    staff.staff_sex=query.value(3).toString();
    staff.staff_native=query.value(4).toString();
    staff.staff_address=query.value(5).toString();
    staff.staff_ID_card_number=query.value(8).toString();
    staff.staff_age=query.value(6).toString();
    staff.staff_level=query.value(7).toString();

    a->deleteStaff(staff);

    //判断是否处理成功
}

void Usermanage::on_pushButton_3_clicked()//修改员工信息
{
    QSqlQuery query;
    Staff staff;
    staff.staff_number=ui->lineEdit->text();
    staff.staff_name=ui->lineEdit_2->text();
    staff.staff_address=ui->lineEdit_3->text();
    staff.staff_native=ui->lineEdit_4->text();
    staff.staff_ID_card_number=ui->lineEdit_5->text();
    staff.staff_age=ui->lineEdit_6->text();
    QString str=ui->comboBox->currentText();
    if(str=="一级")
        staff.staff_level="0";
    if(str=="二级")
        staff.staff_level="1";
    if(str=="三级")
        staff.staff_level="2";
    staff.staff_sex=ui->comboBox_2->currentText();


    query.exec("update staff set staff_name='"+staff.staff_name+"',staff_age="+staff.staff_age+",staff_sex='"+staff.staff_sex+"',staff_address='"+staff.staff_address+"',staff_native='"+staff.staff_native+"',staff_ID_card_number='"+staff.staff_ID_card_number+"',staff_level='"+staff.staff_level+"' where staff_number='"+staff.staff_number+"'");
    qDebug()<<"update staff set staff_name='"+staff.staff_name+"',staff_age="+staff.staff_age+",staff_sex='"+staff.staff_sex+"',staff_address='"+staff.staff_address+"',staff_native='"+staff.staff_native+"',staff_ID_card_number='"+staff.staff_ID_card_number+"',staff_level='"+staff.staff_level+"' where staff_number='"+staff.staff_number+"'";
    a->updateStaff(staff);

    //判断是否成功


    model->select();
}
