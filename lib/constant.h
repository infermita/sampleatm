#ifndef CONSTANT_H
#define CONSTANT_H

#include <QString>

class Constant
{
public:
    Constant();
    static QString pathConf() { return "/etc/atm/";}
    static QString tableCamera() { return "camera";}
    static QString tableTram() { return "tram";}
};

#endif // CONSTANT_H