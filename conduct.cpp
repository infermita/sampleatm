#include "conduct.h"
#include "ui_conduct.h"
#include "mainwindow.h"
#include "lib/functions.h"
#include "lib/constant.h"
#include "QDebug"
#include <QSignalMapper>

Conduct::Conduct()
{

}

Conduct::~Conduct()
{
    delete ui;
}

Conduct::Conduct(const Conduct &t){

}
void Conduct::setWidget(QWidget *parent)
{
    ui = new Ui::Conduct;
    ui->setupUi(parent);
    connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
    connect(ui->more, SIGNAL(clicked()), this, SLOT(MoreBrightness()));
    connect(ui->less, SIGNAL(clicked()), this, SLOT(LessBrightness()));
    connect(ui->slider, SIGNAL(valueChanged(int)),this, SLOT(SetBrightness(int)));
    connect(ui->strumenti, SIGNAL(clicked()), this, SLOT(GoToStrumenti()));
    connect(ui->vaivideosorveglianza, SIGNAL(clicked()), this, SLOT(GoToVideo()));

    QSignalMapper *mapper = new QSignalMapper( this );

    mapper->setMapping( ui->videomanuale, 0 );
    mapper->setMapping( ui->videoautomatico, 1 );

    connect(ui->videomanuale, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->videoautomatico, SIGNAL(clicked()), mapper, SLOT(map()));
    connect( mapper, SIGNAL(mapped(int)), this, SLOT(SetVideo(int)));

    ui->videoautomatico->setDown(true);

    Functions *f = new Functions();
    //QString screen = f->Syscall("cat /sys/class/backlight/acpi_video0/brightness", "r");
    QString screen = f->Syscall("cat /sys/class/backlight/backlight_lvds.23/brightness", "r");
    ui->slider->setValue(screen.toInt());
    delete f;

}
void Conduct::Exit()
{
    MainWindow::getInstance()->setWidget(Constant::ObFirstPage());

}
void Conduct::MoreBrightness()
{
    int val = ui->slider->value()+1;
    if(val>8)
        val = 7;

    Functions *f = new Functions();
    QString command = "echo " + QString::number(val) + " > /sys/class/backlight/backlight_lvds.23/brightness";
    f->Syscall(command.toAscii().data(), "w");
    delete f;
    ui->slider->setValue(val);

}
void Conduct::LessBrightness()
{
    int val = ui->slider->value()-1;
    if(val<=0)
        val = 1;

    Functions *f = new Functions();
    QString command = "echo " + QString::number(val) + " > /sys/class/backlight/backlight_lvds.23/brightness";
    f->Syscall(command.toAscii().data(), "w");
    delete f;
    ui->slider->setValue(val);

}
void Conduct::SetBrightness(int val)
{
    Functions *f = new Functions();
    QString command = "echo " + QString::number(val) + " > /sys/class/backlight/backlight_lvds.23/brightness";
    f->Syscall(command.toAscii().data(), "w");
    delete f;
    ui->slider->setValue(val);
}
void Conduct::GoToStrumenti()
{

    MainWindow::getInstance()->setWidget(Constant::ObInstruments());


}
void Conduct::GoToVideo(){

    MainWindow::getInstance()->setWidget(Constant::ObManualVideo());

}
void Conduct::SetVideo(int val){

    if(val==0){

        ui->videomanuale->setDown(true);
        ui->videoautomatico->setDown(false);

    }else{

        ui->videomanuale->setDown(false);
        ui->videoautomatico->setDown(true);


    }

}
