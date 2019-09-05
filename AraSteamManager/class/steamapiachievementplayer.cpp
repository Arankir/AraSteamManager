#include "SteamAPIAchievementPlayer.h"

SteamAPIAchievementPlayer::SteamAPIAchievementPlayer(QJsonObject ObjAchievement, QObject *parent) : QObject(parent){
    Set(ObjAchievement);
}
SteamAPIAchievementPlayer::SteamAPIAchievementPlayer(){

}

void SteamAPIAchievementPlayer::Set(QJsonObject ObjAchievement){
    apiname=ObjAchievement.value("apiname").toString();
    achieved=ObjAchievement.value("achieved").toInt();
    unlocktime=QDateTime::fromSecsSinceEpoch(ObjAchievement.value("unlocktime").toInt(),Qt::LocalTime);
}


SteamAPIAchievementPlayer::SteamAPIAchievementPlayer( const SteamAPIAchievementPlayer & a){
    apiname=a.apiname;
    achieved=a.achieved;
    unlocktime=a.unlocktime;
}
SteamAPIAchievementPlayer & SteamAPIAchievementPlayer::operator=(const SteamAPIAchievementPlayer & Achievements) {
    apiname=Achievements.apiname;
    achieved=Achievements.achieved;
    unlocktime=Achievements.unlocktime;
    return *this;
}
