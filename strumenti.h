#ifndef STRUMENTI_H
#define STRUMENTI_H

#include <QWidget>
#include "dynamicwidget.h"
#include "lib/qcgaugewidget.h"

namespace Ui {
class Strumenti;
}

class Strumenti : public DynamicWidget
{
    Q_OBJECT
    
public:
    Strumenti();
    ~Strumenti();
    void setWidget(QWidget *parent);
    Strumenti(const Strumenti &t);

protected:
    void timerEvent(QTimerEvent *event);

private:
    Ui::Strumenti *ui;
    QcNeedleItem *tensioneLineaAgo, *correnteLineaAgo, *velocitaAgo, *tensioneBatteriaAgo,*correnteBatteriaAgo;
    void SetGauge(QString type,QString label,float min,float max,float step);
    int myrand( unsigned int n, unsigned int m );
    int timerId;
private slots:
    void Exit();
};
Q_DECLARE_METATYPE(Strumenti)
#endif // STRUMENTI_H
