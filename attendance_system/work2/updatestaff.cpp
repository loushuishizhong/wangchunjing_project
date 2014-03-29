#include "updatestaff.h"
#include "ui_updatestaff.h"

updateStaff::updateStaff(QWidget *parent,struct Staff *staff) :
    QMainWindow(parent),mystaff(staff),
    ui(new Ui::updateStaff)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_cardID->setEnabled(false);
    ui->widget->hide();
    ui->widget_camera->hide();

    ui->lineEdit_cardID->setText(staff->card_ID);
    ui->lineEdit_name->setText(staff->staff_name);
    if(staff->staff_sex=="男")
        ui->comboBox_sex->setCurrentIndex(0);
    else if(staff->staff_sex=="女")
        ui->comboBox_sex->setCurrentIndex(1);
    int date=staff->staff_birth.toInt();
    int year=date/100-1970;
    int month=date%100-1;
    ui->comboBox_year->setCurrentIndex(year);
    ui->comboBox_month->setCurrentIndex(month);
    ui->lineEdit_ID->setText(staff->staff_ID);
    ui->lineEdit_phone->setText(staff->staff_phone);
    ui->lineEdit_address->setText(staff->staff_address);
    if(staff->staff_department=="董事会")
        ui->comboBox_department->setCurrentIndex(0);
    else if(staff->staff_department=="销售部")
        ui->comboBox_department->setCurrentIndex(1);
    else if(staff->staff_department=="技术部")
        ui->comboBox_department->setCurrentIndex(2);
    else if(staff->staff_department=="后勤部")
        ui->comboBox_department->setCurrentIndex(3);

    if(staff->staff_position=="董事长")
        ui->comboBox_position->setCurrentIndex(0);
    else if(staff->staff_position=="总经理")
        ui->comboBox_position->setCurrentIndex(1);
    else if(staff->staff_position=="经理")
        ui->comboBox_position->setCurrentIndex(2);
    else if(staff->staff_position=="副经理")
        ui->comboBox_position->setCurrentIndex(3);
    else if(staff->staff_position=="员工")
        ui->comboBox_position->setCurrentIndex(4);

    ui->lineEdit_photo->setText(staff->staff_photo);
}

updateStaff::~updateStaff()
{
    delete ui;
}

void updateStaff::on_pushButton_look_clicked()
{
    ui->widget->show();
}

void updateStaff::on_pushButton_submit_clicked()
{
    struct Staff staff;
    staff.card_ID=ui->lineEdit_cardID->text();
    staff.staff_name=ui->lineEdit_name->text();
    staff.staff_sex=ui->comboBox_sex->currentText();
    staff.staff_photo=ui->lineEdit_photo->text();
    staff.staff_birth=ui->comboBox_year->currentText()+ui->comboBox_month->currentText();
    staff.staff_ID=ui->lineEdit_ID->text();
    staff.staff_phone=ui->lineEdit_phone->text();
    staff.staff_address=ui->lineEdit_address->text();
    staff.staff_department=ui->comboBox_department->currentText();
    staff.staff_position=ui->comboBox_position->currentText();
    staff.staff_login_pass=ui->lineEdit_password->text();
    if(staff.card_ID==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("卡号不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_name==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("姓名不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_sex==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("性别不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_phone==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("电话不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_ID==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("身份证号不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_photo==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("照片不能为空!"),QMessageBox::Yes);
    }
    else if(staff.staff_address==NULL)
    {
        QMessageBox::information(this,tr("错误"),tr("住址不能为空!"),QMessageBox::Yes);
    }
    else
    {
        db_func d;
        d.db_open();
        if(d.updateStaff(staff))
        {
            //QMessageBox::information(this,tr("错误"),tr("更新失败!"),QMessageBox::Yes);
            on_pushButton_clear_clicked();
        }
        d.db_close();
    }
}

void updateStaff::on_pushButton_clear_clicked()
{
    //ui->lineEdit_cardID->clear();
    ui->lineEdit_name->clear();
    ui->comboBox_sex->setCurrentIndex(0);
    ui->lineEdit_ID->clear();
    ui->lineEdit_photo->clear();
    ui->comboBox_year->setCurrentIndex(0);
    ui->comboBox_month->setCurrentIndex(0);
    ui->lineEdit_phone->clear();
    ui->lineEdit_address->clear();
    ui->comboBox_department->setCurrentIndex(0);
    ui->comboBox_position->setCurrentIndex(0);
    ui->lineEdit_password->clear();

    ui->lineEdit_name->setFocus();
}

void updateStaff::on_pushButton_back_clicked()
{
    this->close();
    QString sql;
    myindex *i=new myindex(0,sql);
    i->show();
    i->on_action_staff_manage_triggered();
}

/******************************************************/

void updateStaff::on_pushButton_local_clicked()
{
    ui->widget->hide();
    QString old_photo_dir = QFileDialog::getOpenFileName(this);

    QUuid id = QUuid::createUuid();
    QString strId = id.toString();
    QTime theTime = QTime::currentTime();
    //QString new_photo_dir=ftppath+strId+theTime.hour()+theTime.minute()+theTime.second();
    QString new_photo_dir=strId+theTime.hour()+theTime.minute()+theTime.second();
    QFile::copy(old_photo_dir,new_photo_dir);

    if(!new_photo_dir.isEmpty())
    {
        //QPixmap *pixmap=new QPixmap(photo_dir);
        //ui->label_photo->setPixmap(*pixmap);
        ui->lineEdit_photo->setText(old_photo_dir);
    }
}

void updateStaff::updateShow()
{
    pp = (unsigned char *)malloc(640 * 480/*QWidget::width()*QWidget::height()*/* 3 * sizeof(char));

    rs=vi->get_frame((void **)&p,&len);
//    if(-1==rs)
//    {
//        QMessageBox::warning(this,tr("error"),QObject::tr("get frame failed"),QMessageBox::Yes);
//        vi->stop_capturing();
//    }

    convert_yuv_to_rgb_buffer(p,pp,640,480);

    frame = new QImage(pp,640,480,QImage::Format_RGB888);
    QImage image=frame->scaled(ui->label_photoview->width(),ui->label_photoview->height());
    ui->label_photoview->setPixmap(QPixmap::fromImage(image,Qt::AutoColor));

    vi->unget_frame();
}

int updateStaff::convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height)
{
    unsigned int in, out = 0;
    unsigned int pixel_16;
    unsigned char pixel_24[3];
    unsigned int pixel32;
    int y0, u, y1, v;
    for(in = 0; in < width * height * 2; in += 4) {
        pixel_16 =
                yuv[in + 3] << 24 |
                               yuv[in + 2] << 16 |
                                              yuv[in + 1] <<  8 |
                                                              yuv[in + 0];
        y0 = (pixel_16 & 0x000000ff);
        u  = (pixel_16 & 0x0000ff00) >>  8;
        y1 = (pixel_16 & 0x00ff0000) >> 16;
        v  = (pixel_16 & 0xff000000) >> 24;
        pixel32 = convert_yuv_to_rgb_pixel(y0, u, v);
        pixel_24[0] = (pixel32 & 0x000000ff);
        pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
        pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
        rgb[out++] = pixel_24[0];
        rgb[out++] = pixel_24[1];
        rgb[out++] = pixel_24[2];
        pixel32 = convert_yuv_to_rgb_pixel(y1, u, v);
        pixel_24[0] = (pixel32 & 0x000000ff);
        pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
        pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
        rgb[out++] = pixel_24[0];
        rgb[out++] = pixel_24[1];
        rgb[out++] = pixel_24[2];
    }
    return 0;
}

int updateStaff::convert_yuv_to_rgb_pixel(int y, int u, int v)
{
    unsigned int pixel32 = 0;
    unsigned char *pixel = (unsigned char *)&pixel32;
    int r, g, b;
    r = y + (1.370705 * (v-128));
    g = y - (0.698001 * (v-128)) - (0.337633 * (u-128));
    b = y + (1.732446 * (u-128));
    if(r > 255) r = 255;
    if(g > 255) g = 255;
    if(b > 255) b = 255;
    if(r < 0) r = 0;
    if(g < 0) g = 0;
    if(b < 0) b = 0;
    pixel[0] = r * 220 / 256;
    pixel[1] = g * 220 / 256;
    pixel[2] = b * 220 / 256;
    return pixel32;
}

void updateStaff::on_pushButton_camera_clicked()
{
    ui->widget->hide();
    ui->widget_camera->show();

    vi=new VideoDevice("/dev/video0");
    rs=vi->open_device();
    if(-1==rs)
    {
        QMessageBox::warning(this,tr("error"),QObject::tr("open /dev/dsp error"),QMessageBox::Yes);
        vi->close_device();
    }
    vi->init_device();
    if(-1==rs)
    {
        QMessageBox::warning(this,tr("error"),QObject::tr("init failed"),QMessageBox::Yes);
        vi->close_device();
    }

    vi->start_capturing();
    if(-1==rs)
    {
        QMessageBox::warning(this,tr("error"),QObject::tr("start capture failed"),QMessageBox::Yes);
        vi->close_device();
    }

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateShow()));
    timer->start(30);
}

void updateStaff::on_pushButton_takephoto_clicked()
{
    timer->stop();
}

void updateStaff::on_pushButton_retake_clicked()
{
    timer->start(30);
}

void updateStaff::on_pushButton_OK_clicked()
{
    //QString old_photo_dir=ui->lineEdit_photo->text();
    QUuid id = QUuid::createUuid();
    QString strId = id.toString();
    QTime theTime = QTime::currentTime();
    QString dir="/srv/ftp/org_images/"+strId+QString::number(theTime.hour(),10)+QString::number(theTime.minute(),10)+QString::number(theTime.second(),10)+".jpg";
    //QString old_photo_dir;
    frame->save(dir,"JPG");
    //QString new_photo_dir="/home/root";
    //QFile::copy(,new_photo_dir);

    ui->lineEdit_photo->setText(dir);
    vi->stop_capturing();
    vi->uninit_device();
    vi->close_device();
    ui->widget_camera->hide();
}

void updateStaff::on_pushButton_cancle_clicked()
{
    vi->stop_capturing();
    //vi->uninit_device();
    vi->close_device();
    ui->widget_camera->hide();
}
