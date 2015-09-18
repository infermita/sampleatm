#include "videomanuale.h"
#include "ui_videomanuale.h"
#include "mainwindow.h"
#include "lib/bean/videobean.h"
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QVBoxLayout>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

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
    QObject::connect(ui->stop, SIGNAL (clicked()),this, SLOT (Stop()),Qt::DirectConnection);
    QObject::connect(this, SIGNAL (SignalBuffer(int,int)),this, SLOT (SlotBuffer(int,int)),Qt::DirectConnection);

}

void VideoManuale::Exit()
{
    Stop();
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObCondotta(),MainWindow::getInstance()->condotta());

}

void VideoManuale::Play()
{

    libvlc_media_t *m_media;
    unsigned int idWin;
    QWidget *tmpWid;
    QString tmpWidName;

    const char * const argv[] = {
            "-I", "dummy",    // Don't use any interface
            "--ignore-config",    // Don't use VLC's config
            "--no-xlib","--no-audio"

        };

    //"--demux=h264"
    //

    inst = libvlc_new(sizeof(argv) / sizeof(argv[0]), argv);

    for(i = 0 ; i < num;i++){

        m_media = libvlc_media_new_location(inst, "rtsp://192.168.2.5:2000");
        //m_media = libvlc_media_new_path(inst, "/home/alberto/test.mp4");
        media_players[i] = libvlc_media_player_new_from_media(m_media);
        libvlc_media_release(m_media);

        tmpWidName = QString("video%1").arg(i);
        tmpWid = MainWindow::getInstance()->findChild<QWidget *>(tmpWidName);

        idWin = tmpWid->winId();
        VideoBean *vb = new VideoBean();
        vb->video = this;
        vb->widWin = idWin;

        p_e[i] = libvlc_media_player_event_manager(media_players[i]);
        libvlc_event_attach(p_e[i],libvlc_MediaPlayerBuffering,(libvlc_callback_t)callbacks, (void *)vb );

        libvlc_media_player_set_xwindow(media_players[i], idWin);
        if(libvlc_media_player_play(media_players[i]) != 0)
            qDebug() << "libvlc_media_player_play error!!!";



    }


}
void VideoManuale::Stop()
{
    QString tmpPr;
    QLabel *tmpLabel;
    for(i = 0 ; i < num;i++){

        libvlc_media_player_stop(media_players[i]);
        libvlc_media_player_release (media_players[i]);

        tmpPr = QString("pr%1").arg(i);
        tmpLabel = MainWindow::getInstance()->findChild<QLabel *>(tmpPr);
        tmpLabel->setText("");


    }
    libvlc_release (inst);
}
void VideoManuale::callbacks(const libvlc_event_t *event, void *self){


    //int idWin = reinterpret_cast<intptr_t>(self);

    qDebug() << "Tipo evento: " << event->type;

    switch(event->type){

        case libvlc_MediaPlayerBuffering:
            VideoBean* pp = (VideoBean*)self;
            qDebug() << "Cache: " << event->u.media_player_buffering.new_cache << pp->widWin;
            int i_val = (int) event->u.media_player_buffering.new_cache;
            emit pp->video->SignalBuffer(pp->widWin,i_val);
            break;

    }




}
void VideoManuale::SlotBuffer(int idWin, int val){

    QString valText = QString("Buffer: %1%").arg(val);
    QWidget *tmpWid = MainWindow::getInstance()->find(idWin);
    QString tmpWidName = "pr"+tmpWid->objectName().replace("video","");

    qDebug() << "Pr" << tmpWidName;

    QLabel *tmpLabel = MainWindow::getInstance()->findChild<QLabel *>(tmpWidName);

    tmpLabel->setText(valText);
    /*
    if(idWin==ui->video->winId()){

        ui->pr->setText(valText);

    }else{

        ui->pr2->setText(valText);

    }
    */

}




