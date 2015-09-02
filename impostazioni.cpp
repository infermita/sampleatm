#include "impostazioni.h"
#include "ui_impostazioni.h"
#include "mainwindow.h"

Impostazioni::Impostazioni()
{

}

Impostazioni::~Impostazioni()
{
    delete ui;
}

Impostazioni::Impostazioni(const Impostazioni &t){

}
void Impostazioni::setWidget(QWidget *parent)
{
    ui = new Ui::Impostazioni;
    ui->setupUi(parent);
    connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
    connect(ui->tram, SIGNAL (clicked()),this, SLOT (Tram()),Qt::DirectConnection);
    connect(ui->data, SIGNAL (clicked()),this, SLOT (Data()),Qt::DirectConnection);
}
void Impostazioni::Exit()
{
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObFirstPage(),MainWindow::getInstance()->abilitazione());

}
void Impostazioni::Tram()
{
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObTram(),MainWindow::getInstance()->tram());

}
void Impostazioni::Data()
{
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObData(),MainWindow::getInstance()->data());

}
