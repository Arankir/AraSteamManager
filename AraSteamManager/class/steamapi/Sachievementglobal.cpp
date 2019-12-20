#include "Sachievementglobal.h"

SAchievementGlobal::SAchievementGlobal(QJsonObject Aachievement, QObject *parent) : QObject(parent){
    _apiName=Aachievement.value("name").toString();
    _defaultValue=Aachievement.value("defaultvalue").toInt();
    _displayName=Aachievement.value("displayName").toString();
    _hidden=Aachievement.value("hidden").toInt();
    _description=Aachievement.value("description").toString();
    _icon=Aachievement.value("icon").toString();
    _iconGray=Aachievement.value("icongray").toString();
}
SAchievementGlobal::SAchievementGlobal(){

}

void SAchievementGlobal::Set(QJsonObject Aachievement){
    _apiName=Aachievement.value("name").toString();
    _defaultValue=Aachievement.value("defaultvalue").toInt();
    _displayName=Aachievement.value("displayName").toString();
    _hidden=Aachievement.value("hidden").toInt();
    _description=Aachievement.value("description").toString();
    _icon=Aachievement.value("icon").toString();
    _iconGray=Aachievement.value("icongray").toString();
}

SAchievementGlobal::SAchievementGlobal( const SAchievementGlobal & AnewAchievements){
    _apiName=AnewAchievements._apiName;
    _defaultValue=AnewAchievements._defaultValue;
    _displayName=AnewAchievements._displayName;
    _hidden=AnewAchievements._hidden;
    _description=AnewAchievements._description;
    _icon=AnewAchievements._icon;
    _iconGray=AnewAchievements._iconGray;
}
SAchievementGlobal & SAchievementGlobal::operator=(const SAchievementGlobal & AnewAchievements) {
    _apiName=AnewAchievements._apiName;
    _defaultValue=AnewAchievements._defaultValue;
    _displayName=AnewAchievements._displayName;
    _hidden=AnewAchievements._hidden;
    _description=AnewAchievements._description;
    _icon=AnewAchievements._icon;
    _iconGray=AnewAchievements._iconGray;
    return *this;
}
