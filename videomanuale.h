#ifndef VIDEOMANUALE_H
#define VIDEOMANUALE_H

#include <QMetaType>
//#include <gst/gst.h>
#include <QToolButton>
#include "dynamicwidget.h"
//#include "lib/player.h"
#include <vlc/vlc.h>
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
    static VideoManuale* getInstance();

private slots:
        void Exit();
        void Play();
        void Stop();


private:
    Ui::VideoManuale *ui;
    QToolButton *m_playButton;
    //Player *m_play;
    //libvlc_media_player_t *media_player;
    const static int num = 2;
    int i;
    libvlc_media_player_t *media_players[num];
    libvlc_instance_t *inst;
    static void callbacks( const libvlc_event_t* event, void* self );
    static VideoManuale* instance;


};
Q_DECLARE_METATYPE(VideoManuale)

#endif // VIDEOMANUALE_H
