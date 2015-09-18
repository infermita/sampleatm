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
#include <stdint.h>



//#include <QGst/Init>

VideoManuale* VideoManuale::instance = 0;


VideoManuale* VideoManuale::getInstance(){
    if(instance==0){
        instance = new VideoManuale;
    }
    return instance;
}

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
    instance = this;
    ui->setupUi(parent);
    QObject::connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
    QObject::connect(ui->play, SIGNAL (clicked()),this, SLOT (Play()),Qt::DirectConnection);
    QObject::connect(ui->stop, SIGNAL (clicked()),this, SLOT (Stop()),Qt::DirectConnection);

    const char * const argv[] = {
            "-I", "dummy",    // Don't use any interface
            "--ignore-config",    // Don't use VLC's config
            "--no-xlib", "--no-audio"

        };

    //"--demux=h264"

    inst = libvlc_new(sizeof(argv) / sizeof(argv[0]), argv);


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
    Stop();
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObCondotta(),MainWindow::getInstance()->condotta());

}

void VideoManuale::Play()
{
    libvlc_event_manager_t *p_e;
    libvlc_media_t *m_media;
    unsigned int idWin;
    for(i = 0 ; i < num;i++){

        m_media = libvlc_media_new_location(inst, "rtsp://192.168.2.5:2000");
        //m_media = libvlc_media_new_path(inst, "/home/alberto/test.mp4");
        media_players[i] = libvlc_media_player_new_from_media(m_media);
        libvlc_media_release(m_media);

        if(i==0){
            idWin = ui->video->winId() ;
        }else{
            idWin = ui->video2->winId() ;
        }

        p_e = libvlc_media_player_event_manager(media_players[i]);
        libvlc_event_attach(p_e,libvlc_MediaPlayerBuffering,(libvlc_callback_t)callbacks, (void *)idWin );
        libvlc_media_player_set_xwindow(media_players[i], idWin);

        if(libvlc_media_player_play(media_players[i]) != 0)
            qDebug() << "libvlc_media_player_play error!!!";


    }


}
void VideoManuale::Stop()
{
     for(i = 0 ; i < num;i++){
         libvlc_media_player_stop(media_players[i]);
     }
}
void VideoManuale::callbacks(const libvlc_event_t *event, void *self){


    int idWin = reinterpret_cast<intptr_t>(self);

    qDebug() << "Cache: " << event->u.media_player_buffering.new_cache;
    /*
    float f_val = event->u.media_player_buffering.new_cache;

    int i_val = (int) f_val;
    int winid = idWin;

    if(winid==VideoManuale::getInstance()->ui->video->winId()){

        VideoManuale::getInstance()->ui->pr->setValue(i_val-1);
    }else{
        VideoManuale::getInstance()->ui->pr2->setValue(i_val-1);
    }
    */

}




