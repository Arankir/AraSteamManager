#include "Sachievementpercentage.h"

SAchievementPercentage::SAchievementPercentage(QJsonObject ObjAchievement, QObject *parent) : QObject(parent){
    Set(ObjAchievement);
}
SAchievementPercentage::SAchievementPercentage(){

}

void SAchievementPercentage::Set(QJsonObject ObjAchievement){
    apiname=ObjAchievement.value("name").toString();
    percent=ObjAchievement.value("percent").toDouble();
}

SAchievementPercentage::SAchievementPercentage(const SAchievementPercentage & achievement){
    apiname=achievement.apiname;
    percent=achievement.percent;
}
SAchievementPercentage & SAchievementPercentage::operator=(const SAchievementPercentage & achievement){
    apiname=achievement.apiname;
    percent=achievement.percent;
    return *this;
}
