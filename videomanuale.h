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
    GstElement *find_video_sink (void);
    //Player *m_play;
    //QToolButton *m_playButton;
    static void on_pad_added (GstElement *element,GstPad *pad,gpointer data);
    static gboolean cb_print_position (GstElement *pipeline);
    GstElement *pipeline;
    guint timer;




};
Q_DECLARE_METATYPE(VideoManuale)

#endif // VIDEOMANUALE_H
