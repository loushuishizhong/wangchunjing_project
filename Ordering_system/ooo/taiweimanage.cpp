#include "taiweimanage.h"
#include "ui_taiweimanage.h"
#include "function.h"
#include "choice.h"


Taiweimanage::Taiweimanage(QWidget *parent,QString id) :
        QMainWindow(parent),user_id(id),
        ui(new Ui::Taiweimanage)
{
    a=new QTableManagement();
    a->initTables();//��ʼ��̨λ

    //���ݽ�����
    bool i=false;

    ui->setupUi(this);
    ui->label_2->setText(user_id);

    ui->label_3->setVisible(i);
    ui->label_4->setVisible(i);
    ui->label_5->setVisible(i);
    ui->label_6->setVisible(i);
    ui->label_7->setVisible(i);
    ui->label_8->setVisible(i);
    ui->label_9->setVisible(i);
    ui->label_10->setVisible(i);
    ui->label_11->setVisible(i);
    ui->label_12->setVisible(i);
    ui->label_13->setVisible(i);
    ui->label_14->setVisible(i);

    DM1800 *dm=new DM1800();
    while(dm->str!="T")
    {   if(dm->str=="F")break;
        if(dm->str!=NULL)
        {
            int i=0;

            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_3->setVisible(true);
                    ui->label_3->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_3->setVisible(true);
                    ui->label_3->setText("��ռ��");
                }
                i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_4->setVisible(true);
                    ui->label_4->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_4->setVisible(true);
                    ui->label_4->setText("��ռ��");
                }
                i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_4->setVisible(true);
                    ui->label_4->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_4->setVisible(true);
                    ui->label_4->setText("��ռ��");
                }
                i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_5->setVisible(true);
                    ui->label_5->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_5->setVisible(true);
                    ui->label_5->setText("��ռ��");
                }
                i++;
            }
            i++;
            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_6->setVisible(true);
                    ui->label_6->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_6->setVisible(true);
                    ui->label_6->setText("��ռ��");
                }
            }
            i++;


            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_7->setVisible(true);
                    ui->label_7->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_7->setVisible(true);
                    ui->label_7->setText("��ռ��");
                }
            }
            i++;

            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_8->setVisible(true);
                    ui->label_8->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_8->setVisible(true);
                    ui->label_8->setText("��ռ��");
                }
            }
            i++;
            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_9->setVisible(true);
                    ui->label_9->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_9->setVisible(true);
                    ui->label_9->setText("��ռ��");
                }
            }
            i++;
            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_10->setVisible(true);
                    ui->label_10->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_10->setVisible(true);
                    ui->label_10->setText("��ռ��");
                }
            }
            i++;
            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_11->setVisible(true);
                    ui->label_11->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_11->setVisible(true);
                    ui->label_11->setText("��ռ��");
                }
            }
            i++;

            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_12->setVisible(true);
                    ui->label_12->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_12->setVisible(true);
                    ui->label_12->setText("��ռ��");
                }
            }
            i++;


            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_13->setVisible(true);
                    ui->label_13->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_13->setVisible(true);
                    ui->label_13->setText("��ռ��");
                }
            }
            i++;

            while(dm->str.at(i)!='+')
            {

                if(dm->str.at(i)=='1')
                {
                    ui->label_14->setVisible(true);
                    ui->label_14->setText("��Ԥ��");
                }
                if(dm->str.at(i)=='2')
                {
                    ui->label_14->setVisible(true);
                    ui->label_14->setText("��ռ��");
                }
            }
            i++;

        }
        dm->str.clear(); 
    }
    dm->myCom->close();
}

Taiweimanage::~Taiweimanage()
{
    delete ui;
}

void Taiweimanage::on_pushButton_13_clicked()
{
    this->close();
    Function *fu=new Function(0,user_id);
    fu->show();
}

void Taiweimanage::on_pushButton_clicked()
{
    this->close();
    table_num="01";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();

}

void Taiweimanage::on_pushButton_2_clicked()
{
    this->close();
    table_num="02";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}

void Taiweimanage::on_pushButton_3_clicked()
{
    this->close();
    table_num="03";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}

void Taiweimanage::on_pushButton_4_clicked()
{
    this->close();
    table_num="04";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}

void Taiweimanage::on_pushButton_5_clicked()
{
    this->close();
    table_num="05";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}

void Taiweimanage::on_pushButton_6_clicked()
{
    this->close();
    table_num="06";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}

void Taiweimanage::on_pushButton_7_clicked()
{
    this->close();
    table_num="07";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}

void Taiweimanage::on_pushButton_8_clicked()
{
    this->close();
    table_num="08";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}

void Taiweimanage::on_pushButton_9_clicked()
{
    this->close();
    table_num="09";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}

void Taiweimanage::on_pushButton_10_clicked()
{
    this->close();
    table_num="10";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}

void Taiweimanage::on_pushButton_11_clicked()
{
    this->close();
    table_num="11";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}

void Taiweimanage::on_pushButton_12_clicked()
{
    this->close();
    table_num="12";
    Choice *c=new Choice(0,user_id,table_num);
    c->show();
}
