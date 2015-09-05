#include "videomanuale.h"
#include "ui_videomanuale.h"
#include "mainwindow.h"
#include "lib/player.h"
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QVBoxLayout>
#include <QGst/Init>

VideoManuale::VideoManuale()
{

}
VideoManuale::~VideoManuale()
{
    delete ui;
}
VideoManuale::VideoManuale(const VideoManuale &t){

}

void VideoManuale::setWidget(QWidget *parent)
{
    ui = new Ui::VideoManuale;
    ui->setupUi(parent);
    QObject::connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
    QObject::connect(ui->play, SIGNAL (clicked()),this, SLOT (Play()),Qt::DirectConnection);

    QGst::init(0, 0);
    m_play = new Player(ui->video);
    m_play->setFixedSize(640,480);

}

void VideoManuale::Exit()
{
    m_play->stop();
    delete m_play;
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObCondotta(),MainWindow::getInstance()->condotta());

}

void VideoManuale::Play()
{
    m_play->setUri("/etc/atm/test.mp4");
    m_play->play();


}



