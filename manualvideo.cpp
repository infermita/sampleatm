#include "manualvideo.h"
#include "ui_manualvideo.h"
#include "mainwindow.h"
#include "lib/bean/videobean.h"
#include "lib/dao.h"
#include "lib/constant.h"
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QVBoxLayout>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

ManualVideo::ManualVideo()
{

}
ManualVideo::~ManualVideo()
{
    delete ui;
}
ManualVideo::ManualVideo(const ManualVideo &t){

}

void ManualVideo::setWidget(QWidget *parent)
{
    ui = new Ui::ManualVideo;
    ui->setupUi(parent);

    QObject::connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);

    QObject::connect(this, SIGNAL(PlayVideo(QString,QString)),MainWindow::getInstance()->vd, SLOT(Play(QString,QString)),Qt::DirectConnection);

    CreateButton();


}

void ManualVideo::CreateButton(){

    QString tmpButName;
    QSignalMapper *mapper = new QSignalMapper( this );

    Dao *d = new Dao();
    QList< QHash<QString, QString> > listCam = d->listRow(Constant::TableCamera());

    QPushButton *button;

    int y = 10;
    int x = 10;
    int k = 0;



    for(int i = 0; i < listCam.length(); i++){

        button = new QPushButton(ui->framebuttons);

        QString desc = listCam[i].value("desc");
        button->setStyleSheet("font-size:20pt");

        button->setText(desc.replace(" ","\n"));

        if(i>0 && i%4==0){
            y += 136;
            x = 10;
            k = 0;
        }

        button->move(x+(x*k)+(296*k),y);
        button->resize(296,126);
        tmpButName = QString("buttonvideo%1").arg(i);
        button->setObjectName(tmpButName);

        mapper->setMapping( button, listCam[i].value("id")+",manual" );
        QObject::connect(button, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
        k++;
        button->show();


    }
    QObject::connect( mapper, SIGNAL(mapped(QString)), this, SLOT(Play(QString)));

    delete d;


}

void ManualVideo::Exit()
{
    MainWindow::getInstance()->setWidget(Constant::ObConduct());


}
void ManualVideo::Play(QString idCam){

    QStringList idSplit = idCam.split(",");

    emit PlayVideo(idSplit.at(0),idSplit.at(1));

}
