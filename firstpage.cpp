#include <QMessageBox>
#include <QDebug>

#include "firstpage.h"
#include "ui_firstpage.h"
#include "mainwindow.h"

FirstPage::FirstPage()
{

}
FirstPage::~FirstPage()
{
    delete ui;
}
FirstPage::FirstPage(const FirstPage &t){

}

void FirstPage::Condotta()
{
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObCondotta(),MainWindow::getInstance()->condotta());

}
void FirstPage::Manutenzione()
{
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObPassword(),MainWindow::getInstance()->password());
}

void FirstPage::setWidget(QWidget *parent)
{
    ui = new Ui::FirstPage;
    ui->setupUi(parent);
    QObject::connect(ui->condotta, SIGNAL (clicked()),this, SLOT (Condotta()),Qt::DirectConnection);
    QObject::connect(ui->manutenzione, SIGNAL (clicked()),this, SLOT (Manutenzione()),Qt::DirectConnection);

}

