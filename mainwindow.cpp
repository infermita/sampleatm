#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dynamicwidget.h"
#include "firstpage.h"
#include "conduct.h"
#include "password.h"
#include "instruments.h"
#include "stati.h"
#include "settings.h"
#include "tram.h"
#include "data.h"
#include "manualvideo.h"
#include "lib/dao.h"
#include "lib/constant.h"
#include "lib/language.h"
#include <QTime>
#include <QDateTime>
#include <stdio.h>
#include <QObject>
#include <QDebug>
#include <QRect>
#include <libintl.h>
#include <locale.h>

MainWindow* MainWindow::instance = 0;

MainWindow* MainWindow::getInstance(){
    if(instance==0){
        instance = new MainWindow;
    }
    return instance;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerId = startTimer(1000);
    instance = this;
    ptr1 = 0;

    setWidget(Constant::ObFirstPage());

    Dao *d = new Dao();

    QHash<QString,QString> res = d->singleRow(Constant::TableTram(),"");

    ui->serialbus->setText(res.value("numero"));

    delete d;



}

MainWindow::~MainWindow()
{
    killTimer(timerId);
    delete ui;
}
void MainWindow::timerEvent(QTimerEvent *event)
{

    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString("dd-MM-yy\nhh:mm:ss");
    ui->mydata->setText(dateTimeString);

}
void MainWindow::setWidget(QString widgetName)
{


    qRegisterMetaType<FirstPage>("FirstPage");
    qRegisterMetaType<Conduct>("Conduct");
    qRegisterMetaType<Password>("Password");
    qRegisterMetaType<Instruments>("Instruments");
    qRegisterMetaType<Stati>("Stati");
    qRegisterMetaType<Settings>("Settings");
    qRegisterMetaType<Tram>("Tram");
    qRegisterMetaType<Data>("Data");
    qRegisterMetaType<ManualVideo>("ManualVideo");


    if(ptr1!=0){

        delete ptr1;
        delete ui->boxcentrale;
        ui->boxcentrale = new QWidget(ui->mainWidget);
        ui->boxcentrale->setObjectName(QString::fromUtf8("boxcentrale"));
        ui->boxcentrale->setGeometry(QRect(10, 80, 1261, 681));
        ui->boxcentrale->setStyleSheet(QString::fromUtf8("QWidget{ background-color : #020037; color : #fefe00 }"));

        ptr1 = 0;

    }

    char *widName = widgetName.toAscii().data();


    idWidget = QMetaType::type(widName);
    ptr1 = (DynamicWidget*)(QMetaType::construct(idWidget));
    ptr1->setWidget(ui->boxcentrale);
    ui->boxcentrale->show();
    /*
    ui->context->setText(QString::fromUtf8(
                             Language::Gettranslation(
                                ptr1->metaObject()->className(),
                                ui->context->metaObject()->className(),
                                ui->context->objectName()
                             ).toUpper().toStdString().c_str()
                          )
                         );
    */
    ui->context->tr(widgetName.toStdString().c_str());


    //QMetaType::destroy(id, ptr1);


}
void MainWindow::setTram(QString tram){

    ui->serialbus->setText(tram);

}




