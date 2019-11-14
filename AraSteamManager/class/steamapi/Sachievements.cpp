#include "Sachievements.h"

SAchievements::SAchievements(QString key, QString appid, QString id, QString language, QObject* parent) : QObject(parent){
  Set(key, appid, id, language);
}
SAchievements::SAchievements(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent){
    Set(Global, Player, Percent);
}
SAchievements::SAchievements(){

}
SAchievements::~SAchievements(){

}

void SAchievements::Set(QString key, QString appid, QString id, QString language){
    this->key=key;
    this->appid=appid;
    this->id=id;
    this->language=language;
    QEventLoop loop;
    SAchievementsGlobal Global(key,appid,language);
    connect(&Global,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    SAchievementsPlayer Player(key,appid,id);
    connect(&Player,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    SAchievementsPercentage Percent(key,appid);
    connect(&Percent,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    Set(Global,Player,Percent);
}
void SAchievements::Set(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent){
    Set(Percent);
    Set(Global);
    Set(Player);
}
void SAchievements::Set(SAchievementsPlayer Player){
    if(count>0){
        for (int i=0;i<count;i++) {
            for (int j=0;j<Player.GetAchievementsCount();j++) {
                if(achievements[i].GetApiname()==Player.GetApiname(j)){
                    achievements[i].SetPlayer(Player.GetAchievementInfo(j));
                    break;
                }
            }
        }
    } else {
        for (int i=0;i<Player.GetAchievementsCount();i++) {
            SAchievement ach;
            ach.SetPlayer(Player.GetAchievementInfo(i));
            achievements.push_back(ach);
        }
        count=Player.GetAchievementsCount();
    }
    statusplayer="success";
}
void SAchievements::Set(SAchievementsGlobal Global){
    if(count>0){
        for (int i=0;i<count;i++) {
            for (int j=0;j<Global.GetAchievementsCount();j++) {
                //qDebug()<<achievements[i].GetApiname()<<Global.GetApiname(j);
                if(achievements[i].GetApiname()==Global.GetApiname(j)){
                    achievements[i].SetGlobal(Global.GetAchievementInfo(j));
                    break;
                }
            }
        }
    } else {
        for (int i=0;i<Global.GetAchievementsCount();i++) {
            SAchievement ach;
            ach.SetGlobal(Global.GetAchievementInfo(i));
            achievements.push_back(ach);
        }
        count=Global.GetAchievementsCount();
    }
    gamename=Global.GetGamename();
    gameversion=Global.GetGameversion();
    statusglobal="success";
}
void SAchievements::Set(SAchievementsPercentage Percent){
    if(count>0){
        for (int i=0;i<count;i++) {
            for (int j=0;j<Percent.GetAchievementsCount();j++) {
                if(achievements[i].GetApiname()==Percent.GetApiname(j)){
                    achievements[i].SetPercent(Percent.GetAchievementInfo(j));
                    break;
                }
            }
        }
    } else {
        for (int i=0;i<Percent.GetAchievementsCount();i++) {
            SAchievement ach;
            ach.SetPercent(Percent.GetAchievementInfo(i));
            achievements.push_back(ach);
        }
        count=Percent.GetAchievementsCount();
        Sort();
    }
    statuspercent="success";
}

void SAchievements::Update(){
    Set(key,appid,id,language);
}
void SAchievements::Clear(){
    achievements.clear();
    count=0;
}
void SAchievements::Sort(){
    for (int i=0; i < count-1; i++) {
        for (int j=0; j < count-i-1; j++) {
            if (achievements[j].GetPercent() < achievements[j+1].GetPercent()){
                SAchievement temp = achievements[j];
                achievements[j] = achievements[j+1];
                achievements[j+1] = temp;
            }
        }
    }
}

SAchievements::SAchievements(const SAchievements & achievement){
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
SAchievements & SAchievements::operator=(const SAchievements & achievement){
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
    return* this;
}
