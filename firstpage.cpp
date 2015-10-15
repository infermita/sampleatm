#include <QMessageBox>
#include <QDebug>

#include "firstpage.h"
#include "ui_firstpage.h"
#include "mainwindow.h"
#include "lib/language.h"

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

    ui->conduct->setText(Language::Gettranslation("button","conduct"));
    ui->maintenance->setText(Language::Gettranslation("button","maintenance"));

    QObject::connect(ui->conduct, SIGNAL (clicked()),this, SLOT (Condotta()),Qt::DirectConnection);
    QObject::connect(ui->maintenance, SIGNAL (clicked()),this, SLOT (Manutenzione()),Qt::DirectConnection);

}

