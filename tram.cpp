#include "tram.h"
#include "ui_tram.h"
#include "mainwindow.h"
#include <QSignalMapper>

Tram::Tram()
{

}

Tram::~Tram()
{
    delete ui;
}

Tram::Tram(const Tram &t){

}
void Tram::setWidget(QWidget *parent)
{
    ui = new Ui::Tram;
    ui->setupUi(parent);

    QSignalMapper *mapper = new QSignalMapper( this );

    mapper->setMapping( ui->zero, "0" );
    mapper->setMapping( ui->uno, "1" );
    mapper->setMapping( ui->due, "2" );
    mapper->setMapping( ui->tre, "3" );
    mapper->setMapping( ui->quattro, "4" );
    mapper->setMapping( ui->cinque, "5" );
    mapper->setMapping( ui->sei, "6" );
    mapper->setMapping( ui->sette, "7" );
    mapper->setMapping( ui->otto, "8" );
    mapper->setMapping( ui->nove, "9" );

    QObject::connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
    QObject::connect(ui->uno, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->due, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->tre, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->quattro, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->cinque, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->sei, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->sette, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->otto, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->nove, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->zero, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);

    connect( mapper, SIGNAL(mapped(QString)), this, SLOT(SelNumB(QString)));

    QObject::connect(ui->ok, SIGNAL (clicked()),this, SLOT (Confirm()),Qt::DirectConnection);
    QObject::connect(ui->cancel, SIGNAL (clicked()),this, SLOT (Reset()),Qt::DirectConnection);

    connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
}
void Tram::Exit()
{
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObImpostazioni(),MainWindow::getInstance()->impostazioni());

}
void Tram::SelNumB( const QString &b)
{

    ui->tram->setText(ui->tram->text()+b);
}
void Tram::Reset(){
    ui->tram->setText("");
}
void Tram::Confirm(){

    MainWindow::getInstance()->setTram(ui->tram->text());
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObImpostazioni(),MainWindow::getInstance()->impostazioni());

}
