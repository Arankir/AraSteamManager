#include "steamapiachievements.h"

SteamAPIAchievements::SteamAPIAchievements(QString key, QString appid, QString id, QString language, QObject *parent) : QObject(parent){
  Set(key, appid, id, language);
}
SteamAPIAchievements::SteamAPIAchievements(SteamAPIAchievementsGlobal Global, SteamAPIAchievementsPlayer Player, SteamAPIAchievementsPercentage Percent){
    Set(Global, Player, Percent);
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
    QEventLoop loop;
    SteamAPIAchievementsGlobal Global(key,appid,language);
    connect(&Global,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    SteamAPIAchievementsPlayer Player(key,appid,id);
    connect(&Player,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    SteamAPIAchievementsPercentage Percent(key,appid);
    connect(&Percent,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    qDebug()<<Global.GetStatus()<<Player.GetStatus()<<Percent.GetStatus();
    Set(Global,Player,Percent);
}
void SteamAPIAchievements::Set(SteamAPIAchievementsGlobal Global, SteamAPIAchievementsPlayer Player, SteamAPIAchievementsPercentage Percent){
    Set(Percent);
    Set(Global);
    Set(Player);
}
void SteamAPIAchievements::Set(SteamAPIAchievementsPlayer Player){
    if(count>0){
        for (int i=0;i<count;i++) {
            for (int j=Player.GetAchievementsCount();j++;) {
                if(achievements[i].GetApiname()==Player.GetApiname(j)){
                    achievements[i].SetPlayer(Player.GetAchievementInfo(j));
                    break;
                }
            }
        }
    } else {
        for (int i=0;i<Player.GetAchievementsCount();i++) {
            SteamAPIAchievement ach;
            ach.SetPlayer(Player.GetAchievementInfo(i));
            achievements.push_back(ach);
        }
        count=Player.GetAchievementsCount();
    }
    statusplayer="success";
}
void SteamAPIAchievements::Set(SteamAPIAchievementsGlobal Global){
    if(count>0){
        for (int i=0;i<count;i++) {
            for (int j=Global.GetAchievementsCount();j++;) {
                if(achievements[i].GetApiname()==Global.GetApiname(j)){
                    achievements[i].SetGlobal(Global.GetAchievementInfo(j));
                    break;
                }
            }
        }
    } else {
        for (int i=0;i<Global.GetAchievementsCount();i++) {
            SteamAPIAchievement ach;
            ach.SetGlobal(Global.GetAchievementInfo(i));
            achievements.push_back(ach);
        }
        count=Global.GetAchievementsCount();
    }
    statusglobal="success";
}
void SteamAPIAchievements::Set(SteamAPIAchievementsPercentage Percent){
    if(count>0){
        for (int i=0;i<count;i++) {
            for (int j=Percent.GetAchievementsCount();j++;) {
                if(achievements[i].GetApiname()==Percent.GetApiname(j)){
                    achievements[i].SetPercent(Percent.GetAchievementInfo(j));
                    break;
                }
            }
        }
    } else {
        for (int i=0;i<Percent.GetAchievementsCount();i++) {
            SteamAPIAchievement ach;
            ach.SetPercent(Percent.GetAchievementInfo(i));
            achievements.push_back(ach);
        }
        count=Percent.GetAchievementsCount();
        Sort();
    }
    statuspercent="success";
}

void SteamAPIAchievements::Update(){
    Set(key,appid,id,language);
}
void SteamAPIAchievements::Clear(){
    achievements.clear();
    count=0;
}
void SteamAPIAchievements::Sort(){
    for (int i=0; i < count-1; i++) {
        for (int j=0; j < count-i-1; j++) {
            if (achievements[j].GetPercent() > achievements[j+1].GetPercent()){
                SteamAPIAchievement temp = achievements[j];
                achievements[j] = achievements[j+1];
                achievements[j+1] = temp;
            }
        }
    }
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
