#include "data.h"
#include "ui_data.h"
#include "mainwindow.h"
#include "lib/functions.h"
#include "lib/constant.h"
#include <QDateTime>

Data::Data()
{

}

Data::~Data()
{
    delete ui;
}

Data::Data(const Data &t){

}
void Data::setWidget(QWidget *parent)
{
    int i;
    ui = new Ui::Data;
    ui->setupUi(parent);
    connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
    connect(ui->accept, SIGNAL (clicked()),this, SLOT (SaveData()),Qt::DirectConnection);

    //QDateTime dateTime = QDateTime::currentDateTime();
    //QString dateTimeString = dateTime.toString("dd-MM-yy\nhh:mm:ss");

    SetSpinBox(ui->day,1,31,"d");
    SetSpinBox(ui->month,1,12,"M");
    SetSpinBox(ui->year,2015,2030,"y");

    SetSpinBox(ui->hour,0,23,"h");
    SetSpinBox(ui->minute,0,59,"m");
    SetSpinBox(ui->second,0,59,"s");

    ui->analogClock->SetClock(ui->hour->value(),ui->minute->value(),ui->second->value());

    connect(ui->hour, SIGNAL(valueChanged(int)),this, SLOT(SetValue(int)));
    connect(ui->minute, SIGNAL(valueChanged(int)),this, SLOT(SetValue(int)));
    connect(ui->second, SIGNAL(valueChanged(int)),this, SLOT(SetValue(int)));



}
void Data::Exit()
{
    MainWindow::getInstance()->setWidget(Constant::ObSettings());

}
void Data::SaveData()
{
    char myCmd[40];
    memset(myCmd,0,sizeof(myCmd));
    sprintf(myCmd, "/bin/date -s '%04d-%02d-%02d %02d:%02d:%02d'", ui->year->value(), ui->month->value(), +ui->day->value(),ui->hour->value(), ui->minute->value(), ui->second->value());
    printf("data %s\n",myCmd);
    Functions *f = new Functions();
    f->Syscall(myCmd, "w");
    delete f;
    Exit();
}

void Data::SetSpinBox(QSpinBox *c, int min,int max, QString dFormat){

    QString number;
    QDateTime dateTime = QDateTime::currentDateTime();
    int index = 0,i;
    c->setRange(min,max);
    c->setValue(dateTime.toString(dFormat).toInt());


}
void Data::SetValue(int val){

    ui->analogClock->SetClock(ui->hour->value(),ui->minute->value(),ui->second->value());

}
