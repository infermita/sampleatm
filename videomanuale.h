#ifndef VIDEOMANUALE_H
#define VIDEOMANUALE_H

#include <QMetaType>
#include <gst/gst.h>
#include <QToolButton>
#include "dynamicwidget.h"
//#include "lib/player.h"
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
        void Play();


private:
    Ui::VideoManuale *ui;
    QToolButton *m_playButton;
    //Player *m_play;




};
Q_DECLARE_METATYPE(VideoManuale)

#endif // VIDEOMANUALE_H
