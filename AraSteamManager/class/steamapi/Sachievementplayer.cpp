#include "Sachievementplayer.h"

SAchievementPlayer::SAchievementPlayer(QJsonObject AAchievement, QObject *parent) : QObject(parent){
    _apiName=AAchievement.value("apiname").toString();
    _achieved=AAchievement.value("achieved").toInt();
    _unlockTime=QDateTime::fromSecsSinceEpoch(AAchievement.value("unlocktime").toInt(),Qt::LocalTime);
}
SAchievementPlayer::SAchievementPlayer(){

}

void SAchievementPlayer::Set(QJsonObject AAchievement){
    _apiName=AAchievement.value("apiname").toString();
    _achieved=AAchievement.value("achieved").toInt();
    _unlockTime=QDateTime::fromSecsSinceEpoch(AAchievement.value("unlocktime").toInt(),Qt::LocalTime);
}


SAchievementPlayer::SAchievementPlayer( const SAchievementPlayer & ANewAchievement){
    _apiName=ANewAchievement._apiName;
    _achieved=ANewAchievement._achieved;
    _unlockTime=ANewAchievement._unlockTime;
}
SAchievementPlayer & SAchievementPlayer::operator=(const SAchievementPlayer & ANewAchievement) {
    _apiName=ANewAchievement._apiName;
    _achieved=ANewAchievement._achieved;
    _unlockTime=ANewAchievement._unlockTime;
    return *this;
}
