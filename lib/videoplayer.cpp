#include "videoplayer.h"
#include "dao.h"
#include "constant.h"
#include "mainwindow.h"
#include <vlc.h>
#include <QHash>
#include <QPushButton>

VideoPlayer::VideoPlayer(QObject *parent) :
    QObject(parent)

{

}

VideoPlayer::~VideoPlayer()
{

}
void VideoPlayer::Play(QString idCam,QString method){

    QString url;
    libvlc_media_t *m_media;

    Dao *d = new Dao();
    QHash<QString,QString> myVideo = d->singleRow(Constant::TableCamera(),"id="+idCam);
    delete d;

    if(myVideo.value("type_camera")=="FULLSCREEN"|| myVideo.value("type_camera")=="ROTATION"){

        video = new QPushButton(MainWindow::getInstance());

        video->resize(1280,768);
        video->move(0,0);
        video->setObjectName("video0");
        video->setStyleSheet("border:0px solid #39bcde;background-color : #000000");
        video->show();

        if(method=="manual")
            QObject::connect(video, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);

        url = "rtsp://"+myVideo.value("ip");

        m_media = libvlc_media_new_location(MainWindow::getInstance()->inst,  url.toStdString().c_str());
        //m_media = libvlc_media_new_path(inst, "/home/alberto/test.mp4");
        num = 1;
        media_players[0] = libvlc_media_player_new_from_media(m_media);
        libvlc_media_release(m_media);

        libvlc_video_set_marquee_int(media_players[0], libvlc_marquee_Enable, 1);
        libvlc_video_set_marquee_int(media_players[0], libvlc_marquee_X, 10);
        libvlc_video_set_marquee_int(media_players[0], libvlc_marquee_Y, 10);
        libvlc_video_set_marquee_string(media_players[0], libvlc_marquee_Text, myVideo.value("desc").toUtf8().data());

        libvlc_media_player_set_xwindow(media_players[0], video->winId());

        if(libvlc_media_player_play(media_players[0]) != 0)
            qDebug() << "libvlc_media_player_play error!!!";

        if(myVideo.value("type_camera")=="ROTATION")
            timerId = startTimer(5000);

    }

    if(myVideo.value("type_camera")=="ALL"){

        int x = 0;
        int y = 0;
        int i = 0;

        QStringList litsCamSel = myVideo.value("id_camera").split(",");

        foreach (QString cam, litsCamSel) {

            if(i>0 && i%2==0){
                x = 0;
                y = 384;
            }else if(i>0 && (i%1==0 || i%3==0)){

                x = 640;

            }
            video = new QPushButton(MainWindow::getInstance());
            video->resize(640,384);
            video->move(x,y);
            video->setObjectName(QString("video%1").arg(i));
            video->setStyleSheet("border:0px solid #39bcde;background-color : #000000");
            video->show();

            if(method=="manual")
                QObject::connect(video, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);

            //Da aggiungere telecamera id
            url = "rtsp://"+myVideo.value("ip");

            m_media = libvlc_media_new_location(MainWindow::getInstance()->inst,  url.toStdString().c_str());
            media_players[i] = libvlc_media_player_new_from_media(m_media);
            libvlc_media_release(m_media);

            libvlc_video_set_marquee_int(media_players[i], libvlc_marquee_Enable, 1);
            libvlc_video_set_marquee_int(media_players[i], libvlc_marquee_X, 10);
            libvlc_video_set_marquee_int(media_players[i], libvlc_marquee_Y, 10);

            QString desc = myVideo.value("desc") +" "+cam;

            libvlc_video_set_marquee_string(media_players[i], libvlc_marquee_Text, desc.toUtf8().data());

            libvlc_media_player_set_xwindow(media_players[i], video->winId());

            if(libvlc_media_player_play(media_players[i]) != 0)
                qDebug() << "libvlc_media_player_play error!!!";

            i++;
        }
        num = i;

    }

}
void VideoPlayer::Exit()
{

    for(int i = 0 ; i < num;i++){

        QString tmpWidName = QString("video%1").arg(i);
        if(libvlc_media_player_is_playing(media_players[i])){

            libvlc_media_player_stop(media_players[i]);
            libvlc_media_player_release (media_players[i]);

        }

        QWidget *tmpWid = MainWindow::getInstance()->findChild<QWidget *>(tmpWidName);
        if(tmpWid){
            tmpWid->close();
            delete tmpWid;
        }


    }


}
void VideoPlayer::Stop()
{
    Exit();
}
