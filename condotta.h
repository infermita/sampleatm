#ifndef CONDOTTA_H
#define CONDOTTA_H

#include <QMetaType>
#include "dynamicwidget.h"


namespace Ui {
class Condotta;
}

class Condotta : public DynamicWidget
{
    Q_OBJECT
    
public:
    Condotta();
    ~Condotta();
    void setWidget(QWidget *parent);
    Condotta(const Condotta &t);
    
private:
    Ui::Condotta *ui;
private slots:
    void Exit();
    void MoreBrightness();
    void LessBrightness();
    void SetBrightness(int val);
    void GoToStrumenti();
    void GoToVideo();
    void SetVideo(int val);
};
Q_DECLARE_METATYPE(Condotta)
#endif // CONDOTTA_H
