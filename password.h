#ifndef PASSWORD_H
#define PASSWORD_H

#include <QMetaType>
#include <QPushButton>
#include "dynamicwidget.h"

namespace Ui {
class Password;
}

class Password : public DynamicWidget
{
    Q_OBJECT
    
public:
    Password();
    ~Password();
    void setWidget(QWidget *parent);
    Password(const Password &t);
    
private:
    Ui::Password *ui;
    QString secret() {return "12345";}
private slots:
    void Exit();
    void SelNumB(const QString &b);
    void Reset();
    void Confirm();
};
Q_DECLARE_METATYPE(Password)
#endif // PASSWORD_H
