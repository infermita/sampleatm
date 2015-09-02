#ifndef IMPOSTAZIONI_H
#define IMPOSTAZIONI_H

#include <QWidget>
#include "dynamicwidget.h"

namespace Ui {
class Impostazioni;
}

class Impostazioni : public DynamicWidget
{
    Q_OBJECT

public:
    Impostazioni();
    ~Impostazioni();
    void setWidget(QWidget *parent);
    Impostazioni(const Impostazioni &t);
private:
    Ui::Impostazioni *ui;

private slots:
    void Exit();
    void Tram();
    void Data();
};
Q_DECLARE_METATYPE(Impostazioni)

#endif // IMPOSTAZIONI_H
