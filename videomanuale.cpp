#include "videomanuale.h"
#include "ui_videomanuale.h"
#include "mainwindow.h"
#include "lib/player.h"
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QVBoxLayout>
#include <QGst/Init>
/*
#if QT_VERSION > 0x50000
#include <QtWebKit>
#else
#include <QWebView>
#endif
*/
#include <gst/gst.h>
#include <gst/gstversion.h>
#include <gst/gstelementfactory.h>
#include <gst/gstbus.h>
#include <gst/gstinterface.h>


//#if (GST_CHECK_VERSION(1,0,0))
//#include <gst/video/videooverlay.h>
//#else
#include <gst/interfaces/xoverlay.h>
//#endif


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
    //QObject::connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);
    QObject::connect(ui->play, SIGNAL (clicked()),this, SLOT (Play()),Qt::DirectConnection);

    //QString path = QDir::currentPath()+"/movie.mp4";
    //QString path1 = QDir::currentPath()+"/movie.ogg";

    //qDebug() << "path " << path << " path 1" << path1;
    //ui->webView->setStyleSheet("border:2px solid #FFFFFF");
    //ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    //ui->webView->setHtml("<html><body><video width=\"320\" height=\"240\" controls autoplay loop><source src=\""+path+"\" type=\"video/mp4\"><source src=\""+path1+"\" type=\"video/ogg\">your browser does not support the video tag.</video></body></html>",QUrl::fromLocalFile(QDir::currentPath()));

    //ui->webView->load(QUrl("http://www.w3schools.com/html/tryit.asp?filename=tryhtml5_video_autoplay"));
    //ui->webView->load(QUrl("https://html5test.com/"));
    //Play();
    //QWidget *pp = new QWidget(ui->video);
    //pp->setFixedSize(640,480);

    //MediaApp *media = new MediaApp(pp);
    QGst::init(0, 0);
    m_play = new Player(ui->video);
    m_play->setFixedSize(640,480);
    //pl->setUri("/home/alberto/test.mp4");

    //pp->show();
    /*
    m_play = new Player();
    //m_play->setStyleSheet("");

    QVBoxLayout *appLayout = new QVBoxLayout(this);
    appLayout->setContentsMargins(0, 0, 0, 0);

    appLayout->addWidget(m_play);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addStretch();

    m_playButton = new QToolButton;
    m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    m_playButton->setIconSize(QSize(36, 36));
    m_playButton->setToolTip(tr("Play"));
    connect(m_playButton, SIGNAL(clicked()), m_play, SLOT(play()));
    btnLayout->addWidget(m_playButton);
    btnLayout->addStretch();

    appLayout->addLayout(btnLayout);

    setLayout(appLayout);

    QGst::State newState = m_play->state();
    m_playButton->setEnabled(newState != QGst::StatePlaying);

    m_play->show();
    */

}

void VideoManuale::Exit()
{
    g_source_remove(timer);
    gst_element_set_state (pipeline,GST_STATE_PAUSED);
    gst_element_set_state (pipeline,GST_STATE_NULL);
    gst_object_unref (pipeline);
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObCondotta(),MainWindow::getInstance()->condotta());

}

GstElement *VideoManuale::find_video_sink(void){

    GstStateChangeReturn sret;
    GstElement *sink;
    /*
    if ((sink = gst_element_factory_make ("autovideosink", NULL))) {
      sret = gst_element_set_state (sink, GST_STATE_READY);
      if (sret == GST_STATE_CHANGE_SUCCESS)
        return sink;

      gst_element_set_state (sink, GST_STATE_NULL);
    }
    gst_object_unref (sink);

    if ((sink = gst_element_factory_make ("imxipuvideosink", NULL))) {
      sret = gst_element_set_state (sink, GST_STATE_READY);
      if (sret == GST_STATE_CHANGE_SUCCESS)
        return sink;

      gst_element_set_state (sink, GST_STATE_NULL);
    }
    gst_object_unref (sink);

    if ((sink = gst_element_factory_make ("imxeglvivsink", NULL))) {
      sret = gst_element_set_state (sink, GST_STATE_READY);
      if (sret == GST_STATE_CHANGE_SUCCESS)
        return sink;

      gst_element_set_state (sink, GST_STATE_NULL);
    }
    gst_object_unref (sink);
    */

    if ((sink = gst_element_factory_make ("xvimagesink", NULL))) {
        sret = gst_element_set_state (sink, GST_STATE_READY);
        if (sret == GST_STATE_CHANGE_SUCCESS)
          return sink;

        gst_element_set_state (sink, GST_STATE_NULL);
        gst_object_unref (sink);
      }

    if ((sink = gst_element_factory_make ("ximagesink", NULL))) {
      sret = gst_element_set_state (sink, GST_STATE_READY);
      if (sret == GST_STATE_CHANGE_SUCCESS)
        return sink;

      gst_element_set_state (sink, GST_STATE_NULL);
    }
    gst_object_unref (sink);

    return NULL;

}
/*
static void VideoManuale::on_pad_added(GstElement *element, GstPad *pad, gpointer data){


    GstPad *sinkpad;
    GstElement *s = (GstElement *) data;

    g_print ("Dynamic pad created, linking decoder/sink\n");
    sinkpad = gst_element_get_static_pad (s, "sink");
    gst_pad_link (pad, sinkpad);
    gst_object_unref (sinkpad);

}
static gboolean VideoManuale::cb_print_position (GstElement *pipeline)
{


    GstFormat fmt = GST_FORMAT_TIME;
    gint64 pos, len;
    gboolean b;
    b=gst_element_query_duration (pipeline, &fmt, &len);
    g_print("%d",b);
    if (gst_element_query_position (pipeline, &fmt, &pos) && gst_element_query_duration (pipeline, &fmt, &len))
    {
        g_print ("Time: %" GST_TIME_FORMAT " / %" GST_TIME_FORMAT "\r",
        GST_TIME_ARGS (pos), GST_TIME_ARGS (len));
    }

    return TRUE;
}
*/
void VideoManuale::Play()
{
    m_play->setUri("/home/alberto/test.mp4");
    m_play->play();
    /*
    gst_init (0, 0);

    GstBus *bus;
    GstMessage *msg;

    pipeline = gst_pipeline_new ("xvoverlay");
    GstElement *src = gst_element_factory_make ("filesrc", NULL);

    GstElement *dec = gst_element_factory_make ("decodebin", NULL);
    GstElement *sink = find_video_sink ();

    g_object_set(G_OBJECT(src), "location", "/etc/atm/test.mp4", NULL);
    if (sink == NULL)
      g_error ("Couldn't find a working video sink.");

    gst_bin_add_many (GST_BIN (pipeline), src, dec,sink, NULL);


    if (!gst_element_link(src, dec)) {
    g_print ("Failed to link some elements!\n");
    //return -1;
    }
    //g_signal_connect (dec, "pad-added", G_CALLBACK (VideoManuale::on_pad_added), sink);

    WId xwinid = ui->video->winId();

    qDebug() << "Win id " << xwinid;

    gst_x_overlay_set_xwindow_id(GST_X_OVERLAY(sink), xwinid);

    GstStateChangeReturn sret = gst_element_set_state (pipeline,GST_STATE_PLAYING);

    /*
    if (sret == GST_STATE_CHANGE_FAILURE) {
      gst_element_set_state (pipeline, GST_STATE_NULL);
      gst_object_unref (pipeline);

      //QTimer::singleShot(0, QApplication::activeWindow(), SLOT(quit()));
    }else{

        bus = gst_element_get_bus (pipeline);
        msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

    }
    */
    //timer = g_timeout_add (1000, (GSourceFunc) cb_print_position, pipeline);


}



