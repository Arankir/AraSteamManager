#include "steamapiachievementglobal.h"

SteamAPIAchievementGlobal::SteamAPIAchievementGlobal(QJsonObject ObjAchievement, QObject *parent) : QObject(parent){
    Set(ObjAchievement);
}
SteamAPIAchievementGlobal::SteamAPIAchievementGlobal(){

}

void SteamAPIAchievementGlobal::Set(QJsonObject ObjAchievement){
    apiname=ObjAchievement.value("name").toString();
    defaultvalue=ObjAchievement.value("defaultvalue").toInt();
    displayname=ObjAchievement.value("displayName").toString();
    hidden=ObjAchievement.value("hidden").toInt();
    description=ObjAchievement.value("description").toString();
    icon=ObjAchievement.value("icon").toString();
    icongray=ObjAchievement.value("icongray").toString();
}

SteamAPIAchievementGlobal::SteamAPIAchievementGlobal( const SteamAPIAchievementGlobal & achievementss){
    apiname=achievementss.apiname;
    defaultvalue=achievementss.defaultvalue;
    displayname=achievementss.displayname;
    hidden=achievementss.hidden;
    description=achievementss.description;
    icon=achievementss.icon;
    icongray=achievementss.icongray;
}
SteamAPIAchievementGlobal & SteamAPIAchievementGlobal::operator=(const SteamAPIAchievementGlobal & achievementss) {
    apiname=achievementss.apiname;
    defaultvalue=achievementss.defaultvalue;
    displayname=achievementss.displayname;
    hidden=achievementss.hidden;
    description=achievementss.description;
    icon=achievementss.icon;
    icongray=achievementss.icongray;
    return *this;
}
