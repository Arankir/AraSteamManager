#include "steamapiachievements.h"

SteamAPIAchievements::SteamAPIAchievements(QString key, QString appid, QString id, QString language, QObject *parent) : QObject(parent){
  Set(key, appid, id, language);
}
SteamAPIAchievements::SteamAPIAchievements(SteamAPIAchievementsGlobal Global, SteamAPIAchievementsPlayer Player){
    Set(Global, Player);
}
SteamAPIAchievements::SteamAPIAchievements(){
}
SteamAPIAchievements::~SteamAPIAchievements(){
}

void SteamAPIAchievements::Set(QString key, QString appid, QString id, QString language){
    this->key=key;
    this->appid=appid;
    this->id=id;
    this->language=language;
    SteamAPIAchievementsGlobal Global(key,appid,language);
    SteamAPIAchievementsPlayer Player(key,appid,id);
    Set(Global,Player);
}
void SteamAPIAchievements::Set(SteamAPIAchievementsGlobal Global, SteamAPIAchievementsPlayer Player){

}
void SteamAPIAchievements::Set(SteamAPIAchievementsPlayer Player){

}
void SteamAPIAchievements::Set(SteamAPIAchievementsGlobal Global){

}

void SteamAPIAchievements::Sort(){
    for (int i=0; i < count-1; i++) {
        for (int j=0; j < count-i-1; j++) {
            if (achievements[j].get() > achievements[j+1].GetName()) {
                SteamAPIAchievement temp = achievements[j];
                achievements[j] = achievements[j+1];
                achievements[j+1] = temp;
            }
        }
    }
}

SteamAPIAchievement SteamAPIAchievements::GetAchievementInfo(int index){
    return achievements[index];
}
QString SteamAPIAchievements::GetApiname(int index){
    return achievements[index].GetApiname();
}
int SteamAPIAchievements::GetDefaultvalue(int index){
    return achievements[index].GetDefaultvalue();
}
QString SteamAPIAchievements::GetDisplayname(int index){
    return achievements[index].GetDisplayname();
}
int SteamAPIAchievements::GetHidden(int index){
    return achievements[index].GetHidden();
}
QString SteamAPIAchievements::GetDescription(int index){
    return achievements[index].GetDescription();
}
QString SteamAPIAchievements::GetIcon(int index){
    return achievements[index].GetIcon();
}
QString SteamAPIAchievements::GetIcongray(int index){
    return achievements[index].GetIcongray();
}
int SteamAPIAchievements::GetAchieved(int index){
    return achievements[index].GetAchieved();
}
QDateTime SteamAPIAchievements::GetUnlocktime(int index){
    return achievements[index].GetUnlocktime();
}

QString SteamAPIAchievements::GetStatusGlobal(){
  return statusglobal;
}
QString SteamAPIAchievements::GetStatusPlayer(){
    return statusplayer;
}
QString SteamAPIAchievements::GetAppid(){
    return appid;
}
QString SteamAPIAchievements::GetGamename(){
    return gamename;
}
QString SteamAPIAchievements::GetGameversion(){
    return gameversion;
}
int SteamAPIAchievements::GetAchievementsCount(){
    return count;
}

SteamAPIAchievements::SteamAPIAchievements(const SteamAPIAchievements & achievement){
    achievements=achievement.achievements;
    statusglobal=achievement.statusglobal;
    statusplayer=achievement.statusplayer;
    id=achievement.id;
    appid=achievement.appid;
    key=achievement.key;
    language=achievement.language;
    gamename=achievement.gamename;
    gameversion=achievement.gameversion;
    count=achievement.count;
}
SteamAPIAchievements & SteamAPIAchievements::operator=(const SteamAPIAchievements & achievement){
    achievements=achievement.achievements;
    statusglobal=achievement.statusglobal;
    statusplayer=achievement.statusplayer;
    id=achievement.id;
    appid=achievement.appid;
    key=achievement.key;
    language=achievement.language;
    gamename=achievement.gamename;
    gameversion=achievement.gameversion;
    count=achievement.count;
    return *this;
}

void SteamAPIAchievements::Clear(){
    achievements.clear();
    count=0;
}
void SteamAPIAchievements::Update(){
    Set(key,appid,id,language);
}
