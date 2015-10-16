#ifndef CONSTANT_H
#define CONSTANT_H

#include <QString>

class Constant
{
public:
    Constant();

    //Section widgetClassName
    static QString ObFirstPage()       { return "FirstPage";}
    static QString ObConduct()         { return  "Conduct";}
    static QString ObPassword()        { return  "Password";}
    static QString ObInstruments()     { return  "Instruments";}
    static QString ObSettings()        { return  "Settings";}
    static QString ObTram()            { return  "Tram";}
    static QString ObData()            { return  "Data";}
    static QString ObManualVideo()     { return  "ManualVideo";}

    //Path oh con DB e language conf file
    static QString PathConf()           { return "/etc/atm/";}
    //Language file
    static QString FileLanguage()       { return "language.ini";}

    //Db Name
    static QString DbName()             { return "db";}
    //Section tables name
    static QString TableCamera()        { return "camera";}
    static QString TableTram()          { return "tram";}
};

#endif // CONSTANT_H
