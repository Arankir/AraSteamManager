#include "Sachievementglobal.h"

SAchievementGlobal::SAchievementGlobal(QJsonObject AAchievement, QObject *parent) : QObject(parent){
    _apiName=AAchievement.value("name").toString();
    _defaultValue=AAchievement.value("defaultvalue").toInt();
    _displayName=AAchievement.value("displayName").toString();
    _hidden=AAchievement.value("hidden").toInt();
    _description=AAchievement.value("description").toString();
    _icon=AAchievement.value("icon").toString();
    _iconGray=AAchievement.value("icongray").toString();
}
SAchievementGlobal::SAchievementGlobal(){

}

void SAchievementGlobal::Set(QJsonObject AAchievement){
    _apiName=AAchievement.value("name").toString();
    _defaultValue=AAchievement.value("defaultvalue").toInt();
    _displayName=AAchievement.value("displayName").toString();
    _hidden=AAchievement.value("hidden").toInt();
    _description=AAchievement.value("description").toString();
    _icon=AAchievement.value("icon").toString();
    _iconGray=AAchievement.value("icongray").toString();
}

SAchievementGlobal::SAchievementGlobal( const SAchievementGlobal & ANewAchievements){
    _apiName=ANewAchievements._apiName;
    _defaultValue=ANewAchievements._defaultValue;
    _displayName=ANewAchievements._displayName;
    _hidden=ANewAchievements._hidden;
    _description=ANewAchievements._description;
    _icon=ANewAchievements._icon;
    _iconGray=ANewAchievements._iconGray;
}
SAchievementGlobal & SAchievementGlobal::operator=(const SAchievementGlobal & ANewAchievements) {
    _apiName=ANewAchievements._apiName;
    _defaultValue=ANewAchievements._defaultValue;
    _displayName=ANewAchievements._displayName;
    _hidden=ANewAchievements._hidden;
    _description=ANewAchievements._description;
    _icon=ANewAchievements._icon;
    _iconGray=ANewAchievements._iconGray;
    return *this;
}
