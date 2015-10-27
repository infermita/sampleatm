#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H
#include <QPushButton>
#include <vlc.h>

class VideoPlayer : public QObject
{
    Q_OBJECT
public:
    VideoPlayer(QObject *parent = 0);
    ~VideoPlayer();


public slots:

    void Exit();
    void Play(QString idCam,QString method);
    void Stop();

private:
    QPushButton *video;
    int num;
    libvlc_media_player_t *media_players[4];
    int timerId;
    QWidget *mainW;

protected:
    //void timerEvent(QTimerEvent *event);
};

#endif // VIDEOPLAYER_H
