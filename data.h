#ifndef DATA_H
#define DATA_H

#include <QWidget>
#include <QSpinBox>
#include "dynamicwidget.h"

namespace Ui {
class Data;
}

class Data : public DynamicWidget
{
    Q_OBJECT

public:
    Data();
    ~Data();
    void setWidget(QWidget *parent);
    Data(const Data &t);
private:
    Ui::Data *ui;
    void SetSpinBox(QSpinBox *c, int min,int max, QString dFormat);

private slots:
    void Exit();
    void SaveData();
    void SetValue(int val);

};
Q_DECLARE_METATYPE(Data)

#endif // DATA_H
