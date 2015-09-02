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
    void setWidget(QString widgetName,QString contesto);
    void setTram(QString tram);
    Ui::MainWindow *ui;

    QString ObFirstPage()   { return "FirstPage";}
    QString ObCondotta()    { return  "Condotta";}
    QString ObPassword()    { return  "Password";}
    QString ObStrumenti()   { return  "Strumenti";}
    QString ObImpostazioni(){ return   "Impostazioni";}
    QString ObTram()        { return  "Tram";}
    QString ObData()        { return  "Data";}
    QString ObVideoManuale()        { return  "VideoManuale";}

    QString abilitazione()  { return  "ABILITAZIONE";}
    QString condotta()      { return  "MENU' CONDOTTA";}
    QString password()      { return  "INSERIMENTO PASSWORD";}
    QString strumenti()     { return  "STRUMENTI";}
    QString impostazioni()  { return  "MENU' MANUTENZIONE";}
    QString tram()          { return  "IMPOSTAZIONE NUMERO TRAM";}
    QString data()          { return  "IMPOSTAZIONE DATA E ORA";}
    QString videomanuale()  { return  "Video Manuale";}



private:

    int timerId;
    DynamicWidget *ptr1;
    static MainWindow* instance;
    int idWidget;

protected:
    void timerEvent(QTimerEvent *event);

};

#endif // MAINWINDOW_H
