#include "Sachievementpercentage.h"

SAchievementPercentage::SAchievementPercentage(QJsonObject AAchievement, QObject *parent) : QObject(parent){
    _apiName=AAchievement.value("name").toString();
    _percent=AAchievement.value("percent").toDouble();
}
SAchievementPercentage::SAchievementPercentage(){

}

void SAchievementPercentage::Set(QJsonObject AAchievement){
    _apiName=AAchievement.value("name").toString();
    _percent=AAchievement.value("percent").toDouble();
}

SAchievementPercentage::SAchievementPercentage(const SAchievementPercentage & ANewAchievement){
    _apiName=ANewAchievement._apiName;
    _percent=ANewAchievement._percent;
}
SAchievementPercentage & SAchievementPercentage::operator=(const SAchievementPercentage & ANewAchievement){
    _apiName=ANewAchievement._apiName;
    _percent=ANewAchievement._percent;
    return *this;
}
