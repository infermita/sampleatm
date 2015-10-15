#include "videomanuale.h"
#include "ui_videomanuale.h"
#include "mainwindow.h"
#include "lib/bean/videobean.h"
#include "lib/dao.h"
#include "lib/constant.h"
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
    QObject::connect(this, SIGNAL (SignalBuffer(int,int)),this, SLOT (SlotBuffer(int,int)),Qt::DirectConnection);

    timerId = 0;

    CreateButton();

    inst = 0;

}

void VideoManuale::CreateButton(){

    QString tmpButName;
    QSignalMapper *mapper = new QSignalMapper( this );

    Dao *d = new Dao();
    listCam = d->listRow(Constant::tableCamera());

    QPushButton *button;

    int y = 10;
    int x = 10;
    int k = 0;



    for(int i = 0; i < listCam.length(); i++){

        button = new QPushButton(ui->framebuttons);

        QString desc = listCam[i].value("desc");
        button->setStyleSheet("font-size:20pt");

        button->setText(desc.replace(" ","\n"));

        if(i>0 && i%4==0){
            y += 136;
            x = 10;
            k = 0;
        }

        button->move(x+(x*k)+(296*k),y);
        button->resize(296,126);
        tmpButName = QString("buttonvideo%1").arg(i);
        button->setObjectName(tmpButName);

        mapper->setMapping( button, listCam[i].value("id") );
        QObject::connect(button, SIGNAL (clicked()),mapper, SLOT (map()),Qt::DirectConnection);
        k++;
        button->show();


    }
    QObject::connect( mapper, SIGNAL(mapped(QString)), this, SLOT(Play(QString)));

    delete d;


}

void VideoManuale::Exit()
{
    if(inst){
        Stop();

        for(int i = 0 ; i < num;i++){
            QString tmpWidName = QString("video%1").arg(i);
            QWidget *tmpWid = MainWindow::getInstance()->findChild<QWidget *>(tmpWidName);

            if(tmpWid){
                tmpWid->hide();
                delete tmpWid;
            }


        }

        CreateButton();
    }else{

        MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObCondotta(),MainWindow::getInstance()->condotta());
    }

}
void VideoManuale::Play(QString id){

    libvlc_media_t *m_media;
    QString url;
    QPushButton *tmpWid;
    QString tmpWidName;
    QHash<QString,QString> myVideo;


    const char * const argv[] = {
            "-I", "dummy",    // Don't use any interface
            "--ignore-config",    // Don't use VLC's config
        "--no-xlib","--no-audio","--sub-filter=marq","--sub-source=marq"



        };

    //"--demux=h264"
    //"--no-video-title-show",                // <- this option disables the filename marquee
    //"--sub-filter=marq"

    for(int i = 0; i < listCam.length(); i++){

        tmpWidName = QString("buttonvideo%1").arg(i);
        tmpWid = ui->framebuttons->findChild<QPushButton *>(tmpWidName);

        if(tmpWid){
            tmpWid->hide();
            delete tmpWid;
        }

        if(listCam[i].value("id")==id){

            myVideo = listCam[i];

        }


    }

    inst = libvlc_new(sizeof(argv) / sizeof(argv[0]), argv);

    if(myVideo.value("type_camera")=="FULLSCREEN"|| myVideo.value("type_camera")=="ROTATION"){

        //video = new QWidget(ui->framebuttons);
        video = new QPushButton(MainWindow::getInstance());

        //video->resize(ui->framebuttons->width()-20,ui->framebuttons->height()-20);
        //video->move(10,10);
        video->resize(1280,768);
        video->move(0,0);
        video->setObjectName("video0");
        video->setStyleSheet("border:0px solid #39bcde;background-color : #000000");
        video->show();

        QObject::connect(video, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);

        url = "rtsp://"+myVideo.value("ip");

        m_media = libvlc_media_new_location(inst,  url.toStdString().c_str());
        //m_media = libvlc_media_new_path(inst, "/home/alberto/test.mp4");
        num = 1;
        media_players[0] = libvlc_media_player_new_from_media(m_media);
        libvlc_media_release(m_media);
        /*
        VideoBean *vb = new VideoBean();
        vb->video = this;
        vb->widWin = video->winId();
        vb->idPlay = 0;

        p_e[0] = libvlc_media_player_event_manager(media_players[0]);
        libvlc_event_attach(p_e[0],libvlc_MediaPlayerBuffering,(libvlc_callback_t)callbacks, (void *)vb );
        */

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

            QObject::connect(video, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);

            //Da aggiungere telecamera id
            url = "rtsp://"+myVideo.value("ip");

            m_media = libvlc_media_new_location(inst,  url.toStdString().c_str());
            media_players[i] = libvlc_media_player_new_from_media(m_media);
            libvlc_media_release(m_media);
            /*
            VideoBean *vb = new VideoBean();
            vb->video = this;
            vb->widWin = video->winId();
            vb->idPlay = 0;

            p_e[i] = libvlc_media_player_event_manager(media_players[0]);
            libvlc_event_attach(p_e[i],libvlc_MediaPlayerBuffering,(libvlc_callback_t)callbacks, (void *)vb );
            */
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
    //tmpWid->hide();

}

void VideoManuale::Stop()
{
    QString tmpPr;
    //QLabel *tmpLabel;

    if(timerId){

        killTimer(timerId);

    }

    if(inst!=0){

        for(i = 0 ; i < num;i++){

            if(libvlc_media_player_is_playing(media_players[i])){

                libvlc_media_player_stop(media_players[i]);
                libvlc_media_player_release (media_players[i]);

                tmpPr = QString("pr%1").arg(i);
                //tmpLabel = MainWindow::getInstance()->findChild<QLabel *>(tmpPr);
                //tmpLabel->setText("");
            }


        }
        libvlc_release (inst);
        inst = 0;


    }
}
void VideoManuale::callbacks(const libvlc_event_t *event, void *self){


    //int idWin = reinterpret_cast<intptr_t>(self);

    qDebug() << "Tipo evento: " << event->type;

    VideoBean* p = (VideoBean*)self;

    switch(event->type){

        case libvlc_MediaPlayerBuffering:

            qDebug() << "Cache: " << event->u.media_player_buffering.new_cache << p->widWin;
            //int i_val = (int) event->u.media_player_buffering.new_cache;
            //emit pp->video->SignalBuffer(pp->widWin,i_val);


            break;
        case libvlc_MediaPlayerPlaying:
            qDebug() << "setto " << libvlc_video_set_subtitle_file(p->video->media_players[p->idPlay], "cazzo");
            break;

    }




}
void VideoManuale::SlotBuffer(int idWin, int val){

    QString valText = QString("Buffer: %1%").arg(val);
    QWidget *tmpWid = MainWindow::getInstance()->find(idWin);
    QString tmpWidName = "pr"+tmpWid->objectName().replace("video","");

    qDebug() << "Pr" << tmpWidName;

    //QLabel *tmpLabel = MainWindow::getInstance()->findChild<QLabel *>(tmpWidName);

    //tmpLabel->setText(valText);
    /*
    if(idWin==ui->video->winId()){

        ui->pr->setText(valText);

    }else{

        ui->pr2->setText(valText);

    }
    */

}

void VideoManuale::timerEvent(QTimerEvent *event)
{
    //QDateTime dateTime = QDateTime::currentDateTime();
    //QString dateTimeString = dateTime.toString("dd-MM-yy\nhh:mm:ss");

    libvlc_media_player_stop(media_players[0]);

    //libvlc_video_set_marquee_string(media_players[0], libvlc_marquee_Text, dateTimeString.toUtf8().data());
    libvlc_media_player_play(media_players[0]);
}
void VideoManuale::mousePressEvent(QMouseEvent *qevent)
{

    qDebug() << "qua";

}
void VideoManuale::mouseReleaseEvent(QMouseEvent *){

    qDebug() << "qua 2";

}
