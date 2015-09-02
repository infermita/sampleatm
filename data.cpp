#include "data.h"
#include "ui_data.h"
#include "mainwindow.h"
#include "lib/functions.h"
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
    connect(ui->exit_2, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
    connect(ui->accetta, SIGNAL (clicked()),this, SLOT (SaveData()),Qt::DirectConnection);

    //QDateTime dateTime = QDateTime::currentDateTime();
    //QString dateTimeString = dateTime.toString("dd-MM-yy\nhh:mm:ss");

    SetSpinBox(ui->giorno,1,31,"d");
    SetSpinBox(ui->mese,1,12,"M");
    SetSpinBox(ui->anno,2015,2030,"y");

    SetSpinBox(ui->ore,0,23,"h");
    SetSpinBox(ui->minuti,0,59,"m");
    SetSpinBox(ui->secondi,0,59,"s");

    ui->analogClock->SetClock(ui->ore->value(),ui->minuti->value(),ui->secondi->value());

    connect(ui->ore, SIGNAL(valueChanged(int)),this, SLOT(SetValue(int)));
    connect(ui->minuti, SIGNAL(valueChanged(int)),this, SLOT(SetValue(int)));
    connect(ui->secondi, SIGNAL(valueChanged(int)),this, SLOT(SetValue(int)));



}
void Data::Exit()
{
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObImpostazioni(),MainWindow::getInstance()->impostazioni());

}
void Data::SaveData()
{
    char myCmd[40];
    memset(myCmd,0,sizeof(myCmd));
    sprintf(myCmd, "/bin/date -s '%04d-%02d-%02d %02d:%02d:%02d'", ui->anno->value(), ui->mese->value(), +ui->giorno->value(),ui->ore->value(), ui->minuti->value(), ui->secondi->value());
    printf("data %s\n",myCmd);
    Functions *f = new Functions();
    f->Syscall(myCmd, "w");
    delete f;
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObImpostazioni(),MainWindow::getInstance()->impostazioni());

}

void Data::SetSpinBox(QSpinBox *c, int min,int max, QString dFormat){

    QString number;
    QDateTime dateTime = QDateTime::currentDateTime();
    int index = 0,i;
    c->setRange(min,max);
    c->setValue(dateTime.toString(dFormat).toInt());


}
void Data::SetValue(int val){

    ui->analogClock->SetClock(ui->ore->value(),ui->minuti->value(),ui->secondi->value());

}
