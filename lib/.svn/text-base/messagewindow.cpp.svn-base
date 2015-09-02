#include "messagewindow.h"
#include <QMessageBox>

MessageWindow::MessageWindow()
{
}
void MessageWindow::message(QString title, QString mess){

    QMessageBox *msgBox  = new QMessageBox();
    msgBox->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    msgBox->setWindowTitle(title);
    msgBox->setText(mess);
    msgBox->setStyleSheet("color : #000000;font: 20pt \"DejaVu Sans\";font: bold; ");
    msgBox->show();

}
