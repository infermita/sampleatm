#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dynamicwidget.h"
#include "firstpage.h"
#include "condotta.h"
#include "password.h"
#include "strumenti.h"
#include "stati.h"
#include "impostazioni.h"
#include "tram.h"
#include "data.h"
#include "videomanuale.h"
#include "lib/dao.h"
#include "lib/bean/beantram.h"
#include <QTime>
#include <QDateTime>
#include <stdio.h>
#include <QObject>
#include <QDebug>
#include <QRect>

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

    setWidget(ObFirstPage(),abilitazione());

    //QRect rec = QApplication::desktop()->screenGeometry();
    //qDebug() << "width: " << rec.width() << " height: " << rec.height();

    //setWidget(ObStrumenti,strumenti);


    Dao *d = new Dao();

    BeanDaoGen *bg;
    bg = d->singleRow("tram");
    BeanTram *bt = static_cast<BeanTram*>(bg);
    //if(bt!=0)
        ui->matricola->setText(bt->numeroTram);



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
void MainWindow::setWidget(QString widgetName,QString contesto)
{

    qRegisterMetaType<FirstPage>("FirstPage");
    qRegisterMetaType<Condotta>("Condotta");
    qRegisterMetaType<Password>("Password");
    qRegisterMetaType<Strumenti>("Strumenti");
    qRegisterMetaType<Stati>("Stati");
    qRegisterMetaType<Impostazioni>("Impostazioni");
    qRegisterMetaType<Tram>("Tram");
    qRegisterMetaType<Data>("Data");
    qRegisterMetaType<VideoManuale>("VideoManuale");


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
    ui->contesto->setText(contesto);


    //QMetaType::destroy(id, ptr1);


}
void MainWindow::setTram(QString tram){

    ui->matricola->setText(tram);

}

