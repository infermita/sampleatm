#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QSettings>

class Language
{
public:
    Language();
    static QString Gettranslation(QString widgetName,QString widgetType,QString key);
private:

};

#endif // LANGUAGE_H
