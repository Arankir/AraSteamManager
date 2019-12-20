#include "Sachievementpercentage.h"

SAchievementPercentage::SAchievementPercentage(QJsonObject Aachievement, QObject *parent) : QObject(parent){
    _apiName=Aachievement.value("name").toString();
    _percent=Aachievement.value("percent").toDouble();
}
SAchievementPercentage::SAchievementPercentage(){

}

void SAchievementPercentage::Set(QJsonObject Aachievement){
    _apiName=Aachievement.value("name").toString();
    _percent=Aachievement.value("percent").toDouble();
}

SAchievementPercentage::SAchievementPercentage(const SAchievementPercentage & AnewAchievement){
    _apiName=AnewAchievement._apiName;
    _percent=AnewAchievement._percent;
}
SAchievementPercentage & SAchievementPercentage::operator=(const SAchievementPercentage & AnewAchievement){
    _apiName=AnewAchievement._apiName;
    _percent=AnewAchievement._percent;
    return *this;
}
