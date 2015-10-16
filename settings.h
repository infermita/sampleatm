#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "dynamicwidget.h"

namespace Ui {
class Settings;
}

class Settings : public DynamicWidget
{
    Q_OBJECT

public:
    Settings();
    ~Settings();
    void setWidget(QWidget *parent);
    Settings(const Settings &t);
private:
    Ui::Settings *ui;

private slots:
    void Exit();
    void Tram();
    void Data();
};
Q_DECLARE_METATYPE(Settings)

#endif // IMPOSTAZIONI_H
