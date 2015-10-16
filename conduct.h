#ifndef CONDUCT_H
#define CONDUCT_H

#include <QMetaType>
#include "dynamicwidget.h"


namespace Ui {
class Conduct;
}

class Conduct : public DynamicWidget
{
    Q_OBJECT
    
public:
    Conduct();
    ~Conduct();
    void setWidget(QWidget *parent);
    Conduct(const Conduct &t);
    
private:
    Ui::Conduct *ui;
private slots:
    void Exit();
    void MoreBrightness();
    void LessBrightness();
    void SetBrightness(int val);
    void GoToStrumenti();
    void GoToVideo();
    void SetVideo(int val);
};
Q_DECLARE_METATYPE(Conduct)
#endif // CONDOTTA_H
