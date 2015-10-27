#ifndef MANUALVIDEO_H
#define MANUALVIDEO_H

#include <QMetaType>
//#include <gst/gst.h>
#include <QToolButton>
#include "dynamicwidget.h"
//#include "lib/player.h"
#include <vlc/vlc.h>
#include <QPushButton>
namespace Ui {
class ManualVideo;
}

class ManualVideo : public DynamicWidget
{
    Q_OBJECT

public:
    //explicit FirstPage(QWidget *parent = 0);
    ManualVideo();
    ~ManualVideo();
    void setWidget(QWidget *parent);
    ManualVideo(const ManualVideo &t);


private slots:
        void Exit();
        void Play(QString id);


private:
    Ui::ManualVideo *ui;
    void CreateButton();
    void RemoveButton();


signals:
    void PlayVideo(QString idCam,QString method);


};
Q_DECLARE_METATYPE(ManualVideo)

#endif // VIDEOMANUALE_H
