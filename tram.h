#ifndef TRAM_H
#define TRAM_H

#include <QWidget>

#include "dynamicwidget.h"

namespace Ui {
class Tram;
}

class Tram : public DynamicWidget
{
    Q_OBJECT

public:
    Tram();
    ~Tram();
    void setWidget(QWidget *parent);
    Tram(const Tram &t);
private:
    Ui::Tram *ui;

private slots:
    void Exit();void SelNumB(const QString &b);
    void Reset();
    void Confirm();
};
Q_DECLARE_METATYPE(Tram)

#endif // TRAM_H
