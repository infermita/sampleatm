#include "videomanuale.h"
#include "ui_videomanuale.h"
#include "mainwindow.h"
//#include "lib/player.h"
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QVBoxLayout>
#include <stdio.h>
#include <string.h>


//#include <QGst/Init>

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

    inst = libvlc_new(0, 0);

    //media_player = libvlc_media_player_new(inst);
    /*
    QGst::init(0, 0);
    m_play = new Player(ui->video);
    m_play->setFixedSize(640,480);
    */
}

void VideoManuale::Exit()
{
    //m_play->stop();
    //delete m_play;
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObCondotta(),MainWindow::getInstance()->condotta());

}

void VideoManuale::Play()
{
    libvlc_media_t *m;
    // = malloc(10*sizeof(libvlc_media_player_t));
    //ui->videoPlayer->
    //ui->videoPlayer->play(Phonon::MediaSource("/home/alberto/test.mp4"));
    /*
    libvlc_media_player_set_xwindow(media_player, ui->video->winId());
    m = libvlc_media_new_path(inst, "rtsp://184.72.239.149/vod/mp4:BigBuckBunny_115k.mov");
    libvlc_media_player_set_media(media_player, m);
    libvlc_media_release(m);
    libvlc_media_player_play(media_player);
    */
    for(i = 0 ; i < num;i++)
        media_players[i] = libvlc_media_player_new(inst);

    for(i = 0 ; i < num;i++){

        if(i==0){
            libvlc_media_player_set_xwindow(media_players[i], ui->video->winId());
        }else{
            libvlc_media_player_set_xwindow(media_players[i], ui->video2->winId());
        }
        m = libvlc_media_new_path(inst, "rtsp://184.72.239.149/vod/mp4:BigBuckBunny_115k.mov");
        libvlc_media_player_set_media(media_players[i], m);
        libvlc_media_release(m);
        libvlc_media_player_play(media_players[i]);

    }



}
void VideoManuale::Stop()
{
     for(i = 0 ; i < num;i++){
         libvlc_media_player_stop(media_players[i]);
     }
}



