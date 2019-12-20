#include "Sachievementplayer.h"

SAchievementPlayer::SAchievementPlayer(QJsonObject Aachievement, QObject *parent) : QObject(parent){
    _apiName=Aachievement.value("apiname").toString();
    _achieved=Aachievement.value("achieved").toInt();
    _unlockTime=QDateTime::fromSecsSinceEpoch(Aachievement.value("unlocktime").toInt(),Qt::LocalTime);
}
SAchievementPlayer::SAchievementPlayer(){

}

void SAchievementPlayer::Set(QJsonObject Aachievement){
    _apiName=Aachievement.value("apiname").toString();
    _achieved=Aachievement.value("achieved").toInt();
    _unlockTime=QDateTime::fromSecsSinceEpoch(Aachievement.value("unlocktime").toInt(),Qt::LocalTime);
}


SAchievementPlayer::SAchievementPlayer( const SAchievementPlayer & AnewAchievement){
    _apiName=AnewAchievement._apiName;
    _achieved=AnewAchievement._achieved;
    _unlockTime=AnewAchievement._unlockTime;
}
SAchievementPlayer & SAchievementPlayer::operator=(const SAchievementPlayer & AnewAchievement) {
    _apiName=AnewAchievement._apiName;
    _achieved=AnewAchievement._achieved;
    _unlockTime=AnewAchievement._unlockTime;
    return *this;
}
