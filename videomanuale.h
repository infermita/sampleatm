#ifndef VIDEOMANUALE_H
#define VIDEOMANUALE_H

#include <QMetaType>
//#include <gst/gst.h>
#include <QToolButton>
#include "dynamicwidget.h"
//#include "lib/player.h"
#include <vlc/vlc.h>
#include <QPushButton>
namespace Ui {
class VideoManuale;
}

class VideoManuale : public DynamicWidget
{
    Q_OBJECT

public:
    //explicit FirstPage(QWidget *parent = 0);
    VideoManuale();
    ~VideoManuale();
    void setWidget(QWidget *parent);
    VideoManuale(const VideoManuale &t);


private slots:
        void Exit();
        void Play(QString id);
        void Stop();
        void SlotBuffer(int idWin,int val);


private:
    Ui::VideoManuale *ui;
    QToolButton *m_playButton;
    int num;
    int i;
    libvlc_media_player_t *media_players[4];
    libvlc_instance_t *inst;
    libvlc_event_manager_t *p_e[4];
    static void callbacks( const libvlc_event_t* event, void* self );
    void CreateButton();
    void RemoveButton();
    QList< QHash<QString,QString> > listCam;
    QWidget *video;
    int timerId;


signals:
    void SignalBuffer(int idWin,int val);

protected:
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *qevent);
    void mouseReleaseEvent(QMouseEvent *);


};
Q_DECLARE_METATYPE(VideoManuale)

#endif // VIDEOMANUALE_H
