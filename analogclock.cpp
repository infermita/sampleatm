#include <QtGui>

 #include "analogclock.h"

 AnalogClock::AnalogClock(QWidget *parent)
     : QWidget(parent)
 {
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(update()));
     //timer->start(1000);

     setWindowTitle(tr("Analog Clock"));
     resize(200, 200);
 }

 void AnalogClock::paintEvent(QPaintEvent *)
 {
     static const QPoint hourHand[3] = {
         QPoint(7, 8),
         QPoint(-7, 8),
         QPoint(0, -40)
     };
     static const QPoint minuteHand[3] = {
         QPoint(7, 8),
         QPoint(-7, 8),
         QPoint(0, -70)
     };

     static const QPoint secondHand[3] = {
         QPoint(2, 3),
         QPoint(-2, 3),
         QPoint(0, -90)
     };

     QColor hourColor(1, 0, 120);
     QColor minuteColor(255, 255, 255, 191);
     QColor secondColor(0, 0, 0);

     int side = qMin(width(), height());
     QTime time = QTime::currentTime();

     QPainter painter(this);
     painter.setRenderHint(QPainter::Antialiasing);
     painter.translate(width() / 2, height() / 2);
     painter.scale(side / 200.0, side / 200.0);

     painter.setPen(Qt::NoPen);
     painter.setBrush(hourColor);

     painter.save();
     //painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
     painter.rotate(30.0 * ((ore + min / 60.0)));
     painter.drawConvexPolygon(hourHand, 3);
     painter.restore();

     painter.setPen(hourColor);
     /*
     for (int i = 0; i < 12; ++i) {
         painter.drawLine(88, 0, 96, 0);
         painter.rotate(30.0);

     }
     */
     painter.drawText(-8,-88,"12");
     painter.drawText(42,-76,"1");
     painter.drawText(77,-43,"2");
     painter.drawText(88,4,"3");
     painter.drawText(77,51,"4");
     painter.drawText(42,85,"5");
     painter.drawText(-4,98,"6");

     painter.drawText(-52,85,"7");
     painter.drawText(-86,51,"8");
     painter.drawText(-98,4,"9");
     painter.drawText(-92,-43,"10");
     painter.drawText(-54,-76,"11");
     /*
     for (int i = 0; i < 12; ++i) {
         //painter.drawLine(88, 0, 96, 0);
         painter.drawText(-4,-88,QString::number(i));
         //painter.rotate(30.0);
         break;
     }
     */
     painter.setPen(Qt::NoPen);
     painter.setBrush(minuteColor);

     painter.save();
     painter.rotate(6.0 * (min + sec / 60.0));
     //painter.rotate(6.0 * (time.second()));
     painter.drawConvexPolygon(minuteHand, 3);
     painter.restore();

     painter.setPen(minuteColor);

     for (int j = 0; j < 60; ++j) {
         if ((j % 5) != 0)
             painter.drawLine(92, 0, 96, 0);
         painter.rotate(6.0);
     }

     painter.setPen(Qt::NoPen);
     painter.setBrush(secondColor);

     painter.save();
     painter.rotate(6.0 * (sec));
     painter.drawConvexPolygon(secondHand, 3);
     painter.restore();

     painter.setPen(secondColor);

     for (int j = 0; j < 60; ++j) {
         //if ((j % 5) != 0)
         //    painter.drawLine(92, 0, 96, 0);
         painter.rotate(6.0);
     }

 }
 void AnalogClock::SetClock(int oreP, int minP, int secP){

     ore = oreP;
     min = minP;
     sec = secP;
     update();

 }

