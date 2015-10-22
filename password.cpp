#include "mainwindow.h"
#include "password.h"
#include "ui_password.h"
#include "lib/messagewindow.h"
#include "lib/constant.h"
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

    ui->password->setEchoMode(QLineEdit::Password);
    //ui->uno->connect()

}
void Password::Exit()
{
    MainWindow::getInstance()->setWidget(Constant::ObFirstPage());

}
void Password::SelNumB( const QString &b)
{

    ui->password->setText(ui->password->text()+b);
}
void Password::Reset(){
    ui->password->setText("");
}
void Password::Confirm(){

    if(QString::compare(Constant::Password(),ui->password->text())==0){

        MainWindow::getInstance()->setWidget(Constant::ObSettings());

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
        msg->message(tr("Error"),tr("Wrong password"));
        delete msg;

    }

}

