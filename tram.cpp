#include "tram.h"
#include "ui_tram.h"
#include "mainwindow.h"
#include "lib/constant.h"
#include "lib/dao.h"
#include "lib/constant.h"
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
    mapper->setMapping( ui->one, "1" );
    mapper->setMapping( ui->two, "2" );
    mapper->setMapping( ui->three, "3" );
    mapper->setMapping( ui->four, "4" );
    mapper->setMapping( ui->five, "5" );
    mapper->setMapping( ui->six, "6" );
    mapper->setMapping( ui->seven, "7" );
    mapper->setMapping( ui->eight, "8" );
    mapper->setMapping( ui->nine, "9" );

    QObject::connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
    QObject::connect(ui->one, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->two, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->three, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->four, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->five, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->six, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->seven, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->eight, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->nine, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
    QObject::connect(ui->zero, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);

    connect( mapper, SIGNAL(mapped(QString)), this, SLOT(SelNumB(QString)));

    QObject::connect(ui->ok, SIGNAL (clicked()),this, SLOT (Confirm()),Qt::DirectConnection);
    QObject::connect(ui->del, SIGNAL (clicked()),this, SLOT (Reset()),Qt::DirectConnection);

    connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
}
void Tram::Exit()
{
    MainWindow::getInstance()->setWidget(Constant::ObSettings());

}
void Tram::SelNumB( const QString &b)
{

    ui->tram_number->setText(ui->tram_number->text()+b);
}
void Tram::Reset(){
    ui->tram_number->setText("");
}
void Tram::Confirm(){

    QStringList values;
    values << "numero='"+ui->tram_number->text()+"'";
    Dao *d = new Dao();

    if(d->updateRow(Constant::TableTram(),values,"")){
        MainWindow::getInstance()->setTram(ui->tram_number->text());
        Exit();
    }
    delete d;

}
