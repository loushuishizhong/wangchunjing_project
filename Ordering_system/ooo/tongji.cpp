#include "tongji.h"
#include "ui_tongji.h"
#include "function.h"
#include <QtGui>
#include "pieview.h"


tongji::tongji(QWidget *parent, QString id) :
        QMainWindow(parent),user_id(id),
        ui(new Ui::tongji)
{
    ui->setupUi(this);
    ui->label_3->setText(user_id);

    ui->calendarWidget->hide();
    connect(ui->beginButton,SIGNAL(clicked()),ui->calendarWidget,SLOT(show()));
    ui->calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
    connect(ui->calendarWidget,SIGNAL(clicked(const QDate &)),this,SLOT(setdate()));
    ui->calendarWidget_2->hide();
    connect(ui->stopButton,SIGNAL(clicked()),ui->calendarWidget_2,SLOT(show()));
    ui->calendarWidget_2->setSelectionMode(QCalendarWidget::SingleSelection);
    connect(ui->calendarWidget_2,SIGNAL(clicked(const QDate &)),this,SLOT(setdate1()));

    aa=new QStatisticsManagement();

    //setupModelForStaff();
    //setupViews(":/qtdata_staff.cht");
}

tongji::~tongji()
{
    delete ui;
}

void tongji::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void tongji::on_pushButton_3_clicked()
{
    this->close();
    Function *fu=new Function(0,user_id);
    fu->show();
}
void tongji::setdate()
{
    ui->beginEdit->clear();//无效果？？
    ui->beginEdit->setDate(ui->calendarWidget->selectedDate());
    ui->calendarWidget->hide();
    if(ui->calendarWidget_2->selectedDate()<=ui->calendarWidget->selectedDate())
    {
        QMessageBox::warning(this,tr("Error!"),tr("时间选择有误，请重新选择！"),QMessageBox::Yes);
    }
}
void tongji::setdate1()
{
    ui->stopEdit->clear();
    ui->stopEdit->setDate(ui->calendarWidget_2->selectedDate());
    ui->calendarWidget_2->hide();
    if(ui->calendarWidget_2->selectedDate()<=ui->calendarWidget->selectedDate())
    {
        QMessageBox::warning(this,tr("Error!"),tr("时间选择有误，请重新选择！"),QMessageBox::Yes);
    }
}

void tongji::setupModelForSale()
{

    if(model != NULL){
        model=NULL;
    }

    model = new QStandardItemModel(8, 2, this);

    model->setHeaderData(0, Qt::Horizontal, tr("月份"));
    model->setHeaderData(1, Qt::Horizontal, tr("销售额"));
}

void tongji::setupModelForStaff(){


    if(model != NULL){
        model=NULL;
    }
    model = new QStandardItemModel(8, 2, this);

    model->setHeaderData(0, Qt::Horizontal, tr("员工姓名"));
    model->setHeaderData(1, Qt::Horizontal, tr("出勤率"));
}
void tongji::setupModelForDishes(){

    if(model != NULL){
        model=NULL;
    }
    model = new QStandardItemModel(8, 2, this);

    model->setHeaderData(0, Qt::Horizontal, tr("菜品"));
    model->setHeaderData(1, Qt::Horizontal, tr("点菜率"));
}
#if 1
void tongji::setupViews(const QString &path)
{
    QSplitter *splitter = new QSplitter(Qt::Vertical);
    QTableView *table = new QTableView;
    pieChart = new PieView;
    splitter->addWidget(table);
    splitter->addWidget(pieChart);
    splitter->setStretchFactor(0, 0);
    splitter->setStretchFactor(1, 1);
    table->setModel(model);
    pieChart->setModel(model);

    QItemSelectionModel *selectionModel = new QItemSelectionModel(model);
    table->setSelectionModel(selectionModel);
    pieChart->setSelectionModel(selectionModel);

    QHeaderView *headerView = table->horizontalHeader();
    headerView->setStretchLastSection(true);
    layout = new QVBoxLayout;
    layout->addWidget(splitter);

    // 获取数据
    QString fileName;
    if (path.isNull())
        fileName = QFileDialog::getOpenFileName(this, tr("Choose a data file"),
                                                "", "*.cht");
    else
        fileName = path;

    if (!fileName.isEmpty()) {
        QFile file(fileName);

        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream stream(&file);
            QString line;

            model->removeRows(0, model->rowCount(QModelIndex()), QModelIndex());

            int row = 0;
            do {
                line = stream.readLine();
                if (!line.isEmpty()) {

                    model->insertRows(row, 1, QModelIndex());
                    int a,b,c;
                    a=qrand()%256;
                    b=qrand()%256;
                    c=qrand()%256;

                    QStringList pieces = line.split(",", QString::SkipEmptyParts);
                    //获取统计数据

                    model->setData(model->index(row, 0, QModelIndex()),
                                   pieces.value(0));
                    model->setData(model->index(row, 1, QModelIndex()),
                                   pieces.value(1));
                    model->setData(model->index(row, 0, QModelIndex()),
                                   QColor(a,b,c), Qt::DecorationRole);
                    row++;
                }
            } while (!line.isEmpty());

            file.close();
            statusBar()->showMessage(tr("Loaded %1").arg(fileName), 2000);
        }
    }

    //ui->toolBox->currentWidget()->setLayout(layout);
    ui->toolBox->currentWidget()->setGeometry(20,80,281,331);

}
#endif



void tongji::on_toolBox_currentChanged(int index)
{
    delete layout;
    if(index == 0 ){
        qDebug()<<"staff";

        QString begin_time=ui->beginEdit->text();
        QString end_time=ui->stopEdit->text();


        aa->staffStatistics(begin_time,end_time);


        QFile file("qtdata_staff.cht");

        DM1800 *dm=new DM1800();
        if (file.open(QIODevice::WriteOnly )) {
            qDebug()<<"打开成功！";
            QTextStream stream(&file);



            while(dm->str!="T")
            {
                if(dm->str=="F")break;
                if(dm->str!=NULL)
                {
                    model->insertRow(0);
                    int i=0;
                    QString xxx;
                    //xxx为接受到的数据222222222222222
                    QString aaa;

                    while(dm->str.at(i)!='+')
                    {
                        xxx.append(dm->str.at(i)) ;
                        i++;
                    }
                    i++;
                    QString sss=xxx+",";
                    while(dm->str.at(i)!='+')
                    {
                        aaa.append(dm->str.at(i));
                        i++;
                    }

                    stream.operator <<(sss);
                    stream.operator <<(aaa);
                    stream.operator <<("\r\n");

                    dm->str.clear();
                }
            }
        }
        file.close();

        dm->myCom->close();
        setupModelForStaff();
        setupViews("qtdata_staff.cht");
        ui->toolBox->currentWidget()->setLayout(layout);

    }
    else if(index == 2)
    {
        qDebug()<<"sale";

        QString begin_time=ui->beginEdit->text();
        QString end_time=ui->stopEdit->text();
        aa->moneyStatistics(begin_time,end_time);
        DM1800 *dm=new DM1800();
        QFile file("qtdata_sale.cht");
        if (file.open(QIODevice::WriteOnly ))
        {
            qDebug()<<"打开成功！";
            QTextStream stream(&file);


            while(dm->str!="T")
            {
                if(dm->str=="F")break;
                if(dm->str!=NULL)
                {
                    model->insertRow(0);
                    int i=0;
                    QString xxx;
                    //xxx为接受到的数据
                    QString aaa;

                    while(dm->str.at(i)!='+')
                    {
                        xxx.append(dm->str.at(i)) ;
                        i++;
                    }
                    i++;
                    QString sss=xxx+",";
                    while(dm->str.at(i)!='+')
                    {
                        aaa.append(dm->str.at(i));
                        i++;
                    }

                    stream.operator <<(sss);
                    stream.operator <<(aaa);
                    stream.operator <<("\r\n");

                    dm->str.clear();
                }
            }
        }
        file.close();
        setupModelForSale();
        setupViews("qtdata_sale.cht");
        ui->toolBox->currentWidget()->setLayout(layout);
        dm->myCom->close();

    }
    else if(index == 1){
        qDebug()<<"dishes";


        QString begin_time=ui->beginEdit->text();
        QString end_time=ui->stopEdit->text();
        aa->dishesStatistics(begin_time,end_time);
        DM1800 *dm=new DM1800();
        QFile file("qtdata_dishes.cht");
        if (file.open(QIODevice::WriteOnly )) {
            qDebug()<<"打开成功！";
            QTextStream stream(&file);


            while(dm->str!="T")
            {
                if(dm->str=="F")break;
                if(dm->str!=NULL)
                {
                    model->insertRow(0);
                    int i=0;
                    QString xxx;      //xxx为接受到的数据
                    QString aaa;

                    while(dm->str.at(i)!='+')
                    {
                        xxx.append(dm->str.at(i)) ;
                        i++;
                    }
                    i++;
                    QString sss=xxx+",";
                    while(dm->str.at(i)!='+')
                    {
                        aaa.append(dm->str.at(i));
                        i++;
                    }

                    stream.operator <<(sss);
                    stream.operator <<(aaa);
                    stream.operator <<("\r\n");

                    dm->str.clear();
                }
            }
        }
        file.close();
        dm->myCom->close();

        setupModelForDishes();
        setupViews("qtdata_dishes.cht");
        ui->toolBox->currentWidget()->setLayout(layout);
    }
}
