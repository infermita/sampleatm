#ifndef MVBTHREAD_H
#define MVBTHREAD_H
#include <QObject>
#include <QThread>
#include <QUdpSocket>

class MvbThread : public QObject
{
    Q_OBJECT
    public:
        explicit MvbThread(QObject *parent = 0);
        void Start();

    public slots:
        void readPendingDatagrams();

    private:
        QUdpSocket *socket;
        int isPlayVideo;

signals:
    void StartPlayVideo(QString idCam,QString method);
    void StopPlayVideo();
};

#endif // MVBTHREAD_H
