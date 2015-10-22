#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dynamicwidget.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static MainWindow* getInstance();
    void setWidget(QStringList widgetName);
    void setTram(QString tram);
    Ui::MainWindow *ui;

private:

    int timerId;
    DynamicWidget *ptr1;
    static MainWindow* instance;
    int idWidget;

protected:
    void timerEvent(QTimerEvent *event);



};

#endif // MAINWINDOW_H
