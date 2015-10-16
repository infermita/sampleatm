#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QMetaType>
#include "dynamicwidget.h"
namespace Ui {
class FirstPage;
}

class FirstPage : public DynamicWidget
{
    Q_OBJECT

public:
    //explicit FirstPage(QWidget *parent = 0);
    FirstPage();
    ~FirstPage();
    void setWidget(QWidget *parent);
    FirstPage(const FirstPage &t);

private slots:
        void Conduct();
        void Manutenzione();

private:
    Ui::FirstPage *ui;


};
Q_DECLARE_METATYPE(FirstPage)

#endif // FIRSTPAGE_H
