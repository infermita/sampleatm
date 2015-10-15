#-------------------------------------------------
#
# Project created by QtCreator 2015-07-22T15:55:08
#
#-------------------------------------------------

QT       += core gui
QT       += sql
#QT       += phonon


DEFINES  += QT_DISABLE_DEPRECATED_BEFORE=0x000000
#DEFINES  += QT_QPA_PLATFORM=eglfs
#DEFINES  += FB_MULTI_BUFFER=24

greaterThan(QT_MAJOR_VERSION, 4){
    QT += widgets
    #QT += webkitwidgets
    #INCLUDEPATH += /usr/include/gstreamer-1.0 /usr/include/glib-2.0 /usr/include/gstreamer-0.10 /usr/include/QtGStreamer
    #PKGCONFIG += gstreamer-1.0 gstreamer-base-1.0 glib-2.0 gstreamer-video-1.0 QtGStreamer-0.10 QtGStreamerUi-0.10
    INCLUDEPATH += /usr/include/gstreamer-1.0 /usr/include/glib-2.0 /usr/include/gstreamer-0.10
    PKGCONFIG += gstreamer-1.0 gstreamer-base-1.0 glib-2.0 gstreamer-video-1.0
}#else{
    #QT += webkit
    #INCLUDEPATH += /usr/include/gstreamer-0.10 /usr/include/glib-2.0 /usr/include/QtGStreamer
    #PKGCONFIG += gstreamer-0.10 gstreamer-base-0.10 glib-2.0 gstreamer-interfaces-0.10 QtGStreamer-0.10 QtGStreamerUi-0.10
    #INCLUDEPATH += /usr/include/gstreamer-0.10 /usr/include/glib-2.0 /usr/include/QtGStreamer
    #PKGCONFIG += gstreamer-0.10 gstreamer-base-0.10 glib-2.0 gstreamer-interfaces-0.10 QtGStreamer-0.10 QtGStreamerUi-0.10
    INCLUDEPATH += /usr/include/vlc
    PKGCONFIG += libvlc
#}

#QMAKE_CFLAGS += -std=c++11 -fpermissive
#QMAKE_CXXFLAGS += -std=c++11 -fpermissive
#QMAKE_LFLAGS += -std=c++11 -fpermissive

TARGET = atm
TEMPLATE = app

CONFIG+=debug
CONFIG += link_pkgconfig

SOURCES +=\
        mainwindow.cpp \
    firstpage.cpp \
    main.cpp \
    dynamicwidget.cpp \
    condotta.cpp \
    lib/functions.cpp \
    password.cpp \
    lib/qcgaugewidget.cpp \
    strumenti.cpp \
    stati.cpp \
    impostazioni.cpp \
    tram.cpp \
    data.cpp \
    analogclock.cpp \
    lib/dao.cpp \
    lib/messagewindow.cpp \
    videomanuale.cpp \
    #lib/player.cpp
    #lib/player.cpp
    lib/bean/videobean.cpp \
    lib/constant.cpp \
    lib/language.cpp

HEADERS  += mainwindow.h \
    firstpage.h \
    dynamicwidget.h \
    condotta.h \
    lib/functions.h \
    password.h \
    lib/qcgaugewidget.h \
    strumenti.h \
    stati.h \
    impostazioni.h \
    tram.h \
    data.h \
    analogclock.h \
    lib/dao.h \
    lib/messagewindow.h \
    videomanuale.h \
    #lib/player.h
    #lib/player.h
    lib/bean/videobean.h \
    lib/constant.h \
    lib/language.h

FORMS    += mainwindow.ui \
    firstpage.ui \
    condotta.ui \
    password.ui \
    strumenti.ui \
    stati.ui \
    impostazioni.ui \
    tram.ui \
    data.ui \
    videomanuale.ui

RESOURCES +=
