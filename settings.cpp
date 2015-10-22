#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include "lib/constant.h"

Settings::Settings()
{

}

Settings::~Settings()
{
    delete ui;
}

Settings::Settings(const Settings &t){

}
void Settings::setWidget(QWidget *parent)
{
    ui = new Ui::Settings;
    ui->setupUi(parent);
    connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
    connect(ui->setting_n_tram, SIGNAL (clicked()),this, SLOT (Tram()),Qt::DirectConnection);
    connect(ui->date_setting, SIGNAL (clicked()),this, SLOT (Data()),Qt::DirectConnection);
}
void Settings::Exit()
{
    MainWindow::getInstance()->setWidget(Constant::ObFirstPage());

}
void Settings::Tram()
{
    MainWindow::getInstance()->setWidget(Constant::ObTram());

}
void Settings::Data()
{
    MainWindow::getInstance()->setWidget(Constant::ObData());

}
