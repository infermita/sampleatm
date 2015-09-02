#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>

class AnalogClock : public QWidget
{
 Q_OBJECT

public:
 AnalogClock(QWidget *parent = 0);
 void SetClock(int oreP,int minP, int secP);
private:
 int ore,min,sec;


protected:
 void paintEvent(QPaintEvent *event);
};

#endif
