#ifndef DYNAMICWIDGET_H
#define DYNAMICWIDGET_H

#include <QWidget>
#include <QMetaType>

class DynamicWidget  : public QWidget
{
    Q_OBJECT
public:
    DynamicWidget();
    ~DynamicWidget();
    DynamicWidget(const DynamicWidget &t);
    virtual void setWidget(QWidget *w);

};
Q_DECLARE_METATYPE(DynamicWidget)
#endif // DYNAMICWIDGET_H
