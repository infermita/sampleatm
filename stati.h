#ifndef STATI_H
#define STATI_H

#include <QWidget>
#include "dynamicwidget.h"

namespace Ui {
class Stati;
}

class Stati : public DynamicWidget
{
    Q_OBJECT

public:
    Stati();
    ~Stati();
    void setWidget(QWidget *parent);
    Stati(const Stati &t);

private:
    Ui::Stati *ui;
};
Q_DECLARE_METATYPE(Stati)

#endif // STATI_H
