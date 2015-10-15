#include <QApplication>
#include "mainwindow.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{

    setenv("QT_QPA_PLATFORM","eglfs",1);
    setenv("QT_QPA_GENERIC_PLUGINS","tslib:/dev/input/event0",1);
    setenv("QT_QPA_EVDEV_TOUCHSCREEN_PARAMETERS","/dev/input/event0",1);
    setenv("TSLIB_TSEVENTTYPE","'INPUT'",1);
    setenv("TSLIB_TSDEVICE","'/dev/input/event0'",1);

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
