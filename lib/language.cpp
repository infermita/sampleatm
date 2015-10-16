#include "language.h"
#include "lib/constant.h"


Language::Language()
{


}
QString Language::Gettranslation(QString widgetName,QString widgetType,QString key){

    QSettings settings(Constant::PathConf()+Constant::FileLanguage(), QSettings::IniFormat);
    settings.beginGroup("Language");
    QString language = settings.value("say").toString();
    settings.endGroup();

    settings.beginGroup(language+"-"+widgetName+"-"+widgetType);

    return settings.value(key).toString();
}
