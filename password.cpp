#include "mainwindow.h"
#include "password.h"
#include "ui_password.h"
#include "lib/messagewindow.h"
#include <QSignalMapper>
#include <QMessageBox>

Password::Password()
{

}

Password::~Password()
{
    delete ui;
}

Password::Password(const Password &t){

}
void Password::setWidget(QWidget *parent)
{
    ui = new Ui::Password;
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
    //ui->uno->connect()

}
void Password::Exit()
{
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObFirstPage(),MainWindow::getInstance()->abilitazione());

}
void Password::SelNumB( const QString &b)
{

    ui->password->setText(ui->password->text()+b);
}
void Password::Reset(){
    ui->password->setText("");
}
void Password::Confirm(){

    if(QString::compare(secret(),ui->password->text())==0){

        MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObImpostazioni(),MainWindow::getInstance()->impostazioni());

    }else{

        ui->password->setText("");
        /*
        QMessageBox *msgBox  = new QMessageBox();
        msgBox->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
        msgBox->setWindowTitle("Errore");
        msgBox->setText("Password errata");
        msgBox->show();
        */
        MessageWindow *msg = new MessageWindow();
        msg->message("Errore","Password errata");
        delete msg;

    }

}

