#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H

#include <QWidget>
#include "dynamicwidget.h"
#include "lib/qcgaugewidget.h"

namespace Ui {
class Instruments;
}

class Instruments : public DynamicWidget
{
    Q_OBJECT
    
public:
    Instruments();
    ~Instruments();
    void setWidget(QWidget *parent);
    Instruments(const Instruments &t);

protected:
    void timerEvent(QTimerEvent *event);

private:
    Ui::Instruments *ui;
    QcNeedleItem *tensioneLineaAgo, *correnteLineaAgo, *velocitaAgo, *tensioneBatteriaAgo,*correnteBatteriaAgo;
    void SetGauge(QString type,QString label,float min,float max,float step);
    int myrand( unsigned int n, unsigned int m );
    int timerId;
private slots:
    void Exit();
};
Q_DECLARE_METATYPE(Instruments)
#endif // STRUMENTI_H
