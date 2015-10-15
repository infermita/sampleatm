#include "language.h"
#include "lib/constant.h"

Language::Language()
{


}
QString Language::Gettranslation(QString type,QString key){

    QSettings settings(Constant::pathConf()+"language.ini", QSettings::IniFormat);
    settings.beginGroup("Language");
    QString language = settings.value("say").toString();
    settings.endGroup();

    settings.beginGroup(language+"-"+type);

    return settings.value(key).toString();

}
