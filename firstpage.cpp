#include <QMessageBox>
#include <QDebug>
#include <typeinfo>

#include "firstpage.h"
#include "ui_firstpage.h"
#include "mainwindow.h"
#include "lib/constant.h"

FirstPage::FirstPage()
{

}
FirstPage::~FirstPage()
{
    delete ui;
}
FirstPage::FirstPage(const FirstPage &t){

}

void FirstPage::Conduct()
{
    MainWindow::getInstance()->setWidget(Constant::ObConduct());

}
void FirstPage::Manutenzione()
{
    MainWindow::getInstance()->setWidget(Constant::ObPassword());
}

void FirstPage::setWidget(QWidget *parent)
{
    ui = new Ui::FirstPage;
    ui->setupUi(parent);

    QObject::connect(ui->conduct, SIGNAL (clicked()),this, SLOT (Conduct()),Qt::DirectConnection);
    QObject::connect(ui->maintenance, SIGNAL (clicked()),this, SLOT (Manutenzione()),Qt::DirectConnection);

    //ui->retranslateUi(this);

}

