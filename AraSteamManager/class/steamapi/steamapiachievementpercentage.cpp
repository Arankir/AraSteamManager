#include "steamapiachievementpercentage.h"

SteamAPIAchievementPercentage::SteamAPIAchievementPercentage(QJsonObject ObjAchievement, QObject *parent) : QObject(parent){
    Set(ObjAchievement);
}
SteamAPIAchievementPercentage::SteamAPIAchievementPercentage(){

}

void SteamAPIAchievementPercentage::Set(QJsonObject ObjAchievement){
    apiname=ObjAchievement.value("name").toString();
    percent=ObjAchievement.value("percent").toDouble();
}

SteamAPIAchievementPercentage::SteamAPIAchievementPercentage(const SteamAPIAchievementPercentage & achievement){
    apiname=achievement.apiname;
    percent=achievement.percent;
}
SteamAPIAchievementPercentage & SteamAPIAchievementPercentage::operator=(const SteamAPIAchievementPercentage & achievement){
    apiname=achievement.apiname;
    percent=achievement.percent;
    return *this;
}
