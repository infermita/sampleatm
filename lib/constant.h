#ifndef CONSTANT_H
#define CONSTANT_H

#include <QString>
#include <QObject>
#include <QStringList>

class Constant
{
public:
    Constant();

    //Section widget Class Name and Title
    static QStringList ObFirstPage()        { QStringList title; title <<  "FirstPage"    << QObject::tr("ENABLE");              return title;}
    static QStringList ObConduct()          { QStringList title; title <<  "Conduct"      << QObject::tr("CONDUCT MENU");        return title;}
    static QStringList ObPassword()         { QStringList title; title <<  "Password"     << QObject::tr("PASSWORD ENTRY");      return title;}
    static QStringList ObInstruments()      { QStringList title; title <<  "Instruments"  << QObject::tr("INSTRUMENTS");         return title;}
    static QStringList ObSettings()         { QStringList title; title <<  "Settings"     << QObject::tr("MAINTENANCE MENU");    return title;}
    static QStringList ObTram()             { QStringList title; title <<  "Tram"         << QObject::tr("SETTING NUMBER TRAM"); return title;}
    static QStringList ObData()             { QStringList title; title <<  "Data"         << QObject::tr("DATE TIME SETTING");   return title;}
    static QStringList ObManualVideo()      { QStringList title; title <<  "ManualVideo"  << QObject::tr("MANUAL VIDEO");        return title;}

    //Path configuration files and DB
    static QString PathConf()           { return "/etc/atm/";}

    //Db Name
    static QString DbName()             { return "db";}
    //Section tables name
    static QString TableCamera()        { return "camera";}
    static QString TableTram()          { return "tram";}

    //Pasword maintenance
    static QString Password()           { return "12345"; }
};

#endif // CONSTANT_H
