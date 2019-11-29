#include "Sachievementplayer.h"

SAchievementPlayer::SAchievementPlayer(QJsonObject ObjAchievement, QObject *parent) : QObject(parent){
    Set(ObjAchievement);
}
SAchievementPlayer::SAchievementPlayer(){

}

void SAchievementPlayer::Set(QJsonObject ObjAchievement){
    apiname=ObjAchievement.value("apiname").toString();
    achieved=ObjAchievement.value("achieved").toInt();
    unlocktime=QDateTime::fromSecsSinceEpoch(ObjAchievement.value("unlocktime").toInt(),Qt::LocalTime);
}


SAchievementPlayer::SAchievementPlayer( const SAchievementPlayer & a){
    apiname=a.apiname;
    achieved=a.achieved;
    unlocktime=a.unlocktime;
}
SAchievementPlayer & SAchievementPlayer::operator=(const SAchievementPlayer & Achievements) {
    apiname=Achievements.apiname;
    achieved=Achievements.achieved;
    unlocktime=Achievements.unlocktime;
    return *this;
}
