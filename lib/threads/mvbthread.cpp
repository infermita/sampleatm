#include "mvbthread.h"
#include "mainwindow.h"
#include <QDebug>

MvbThread::MvbThread(QObject *parent) :
    QObject(parent)
{
    // create a QUDP socket
    socket = new QUdpSocket(this);


}

void MvbThread::Start()
{
    bool bind = socket->bind(QHostAddress::Any, 41000);

    if(bind){
        connect(socket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
        connect(this, SIGNAL(StartPlayVideo(QString,QString)), MainWindow::getInstance()->vd, SLOT(Play(QString,QString)));
        connect(this, SIGNAL(StopPlayVideo()), MainWindow::getInstance()->vd, SLOT(Stop()));
        isPlayVideo = 0;
    }else{
        qDebug() << "Not BIND";
    }
}

void MvbThread::readPendingDatagrams()
{
    int i;
    while (socket->hasPendingDatagrams()) {
        // when data comes in
        QByteArray buf;
        unsigned char mvb_size;
        unsigned short mvb_port;
        unsigned short mvb_freshness;

        buf.resize(socket->pendingDatagramSize());



        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(buf.data(), buf.size(),
                             &sender, &senderPort);

        qDebug() << "Message from: " << sender.toString();
        qDebug() << "Message port: " << senderPort;
        qDebug() << "Message: " << buf;

        mvb_size = buf[1]; 												// MVB size
        mvb_port = ((buf[2] << 8) & 0xFF00) | (buf[3] & 0xFF); 		// MVB port
        mvb_freshness = ((buf[36] << 8) & 0xFF00) | (buf[37] & 0xFF); // MVB freshness

        //printf("mvb port=%d, size=%d, freshness=%d, data=", mvb_port, mvb_size, mvb_freshness);
        /*
        for(i=0; i<mvb_size; i++) {
                if(i%16 == 0){
                        printf("\n    ");
                }
                printf("%d ", (unsigned char)buf[4 + i]);

        }
        */
        if(mvb_port==40106){

            int speed = ((buf[4] << 8) & 0xFF00) | (buf[5] & 0xFF);
            if(speed>0 && isPlayVideo == 0){
                emit StartPlayVideo("5","auto");
                isPlayVideo = 1;
            }else if(isPlayVideo && speed == 0){
                emit StopPlayVideo();
                isPlayVideo = 0;
            }
        }
        printf("\n");

    }
}
