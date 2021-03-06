#-------------------------------------------------
#
# Project created by QtCreator 2015-07-22T15:55:08
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
#QT       += phonon


DEFINES  += QT_DISABLE_DEPRECATED_BEFORE=0x000000
#DEFINES  += QT_QPA_PLATFORM=eglfs
#DEFINES  += FB_MULTI_BUFFER=24

#greaterThan(QT_MAJOR_VERSION, 4){
#    QT += widgets
    #QT += webkitwidgets
    #INCLUDEPATH += /usr/include/gstreamer-1.0 /usr/include/glib-2.0 /usr/include/gstreamer-0.10 /usr/include/QtGStreamer
    #PKGCONFIG += gstreamer-1.0 gstreamer-base-1.0 glib-2.0 gstreamer-video-1.0 QtGStreamer-0.10 QtGStreamerUi-0.10
#    INCLUDEPATH += /usr/include/gstreamer-1.0 /usr/include/glib-2.0 /usr/include/gstreamer-0.10
#    PKGCONFIG += gstreamer-1.0 gstreamer-base-1.0 glib-2.0 gstreamer-video-1.0
#}#else{
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

TRANSLATIONS    = translate_en_EN.ts translate_it_IT.ts

SOURCES +=\
        mainwindow.cpp \
    firstpage.cpp \
    main.cpp \
    dynamicwidget.cpp \
    lib/functions.cpp \
    password.cpp \
    lib/qcgaugewidget.cpp \
    stati.cpp \
    tram.cpp \
    data.cpp \
    analogclock.cpp \
    lib/dao.cpp \
    lib/messagewindow.cpp \
    #lib/player.cpp
    #lib/player.cpp
    lib/bean/videobean.cpp \
    lib/constant.cpp \
    conduct.cpp \
    instruments.cpp \
    settings.cpp \
    manualvideo.cpp \
    lib/videoplayer.cpp \
    lib/threads/mvbthread.cpp

HEADERS  += mainwindow.h \
    firstpage.h \
    dynamicwidget.h \
    lib/functions.h \
    password.h \
    lib/qcgaugewidget.h \
    stati.h \
    tram.h \
    data.h \
    analogclock.h \
    lib/dao.h \
    lib/messagewindow.h \
    #lib/player.h
    #lib/player.h
    lib/bean/videobean.h \
    lib/constant.h \
    conduct.h \
    instruments.h \
    settings.h \
    manualvideo.h \
    lib/videoplayer.h \
    lib/threads/mvbthread.h

FORMS    += mainwindow.ui \
    firstpage.ui \
    password.ui \
    stati.ui \
    tram.ui \
    data.ui \
    conduct.ui \
    instruments.ui \
    settings.ui \
    manualvideo.ui

RESOURCES +=
