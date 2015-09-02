#include "stati.h"
#include "ui_stati.h"

Stati::Stati()
{

}

Stati::~Stati()
{
    delete ui;
}

Stati::Stati(const Stati &t){

}
void Stati::setWidget(QWidget *parent)
{
    ui = new Ui::Stati;
    ui->setupUi(parent);

}
