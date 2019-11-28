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
    SAchievementsGlobal *Global = new SAchievementsGlobal(key,appid,language);
    connect(Global,SIGNAL(finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *Player = new SAchievementsPlayer(key,appid,id);
    connect(Player,SIGNAL(finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(key,appid);
    connect(Percent,SIGNAL(finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
void SAchievements::Set(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent){
    Set(Percent);
    Set(Global);
    Set(Player);
}
void SAchievements::Set(SAchievementsPlayer Player){
    qDebug()<<"Player set";
    this->Player=Player;
    statusplayer="success";
    if(statusglobal=="success"&&statusplayer=="success"&&statuspercent=="success"){
        SetFinish();
    }
}
void SAchievements::Set(SAchievementsGlobal Global){
    qDebug()<<"Global set";
    this->Global=Global;
    statusglobal="success";
    if(statusglobal=="success"&&statusplayer=="success"&&statuspercent=="success"){
        SetFinish();
    }
}
void SAchievements::Set(SAchievementsPercentage Percent){
    qDebug()<<"Percent set";
    this->Percent=Percent;
    statuspercent="success";
    if(statusglobal=="success"&&statusplayer=="success"&&statuspercent=="success"){
        SetFinish();
    }
}
void SAchievements::SetFinish(){
    Clear();
    SAchievementsGlobal Glo = Global;
    SAchievementsPlayer Pla = Player;
    SAchievementsPercentage Per = Percent;
    for(int i=0;i<Per.GetAchievementsCount();i++){
        for(int j=0;j<Pla.GetAchievementsCount();j++){
            if(Per.GetApiname(i)==Pla.GetApiname(j)){
                SAchievement achievement;
                achievement.SetPercent(Per.GetAchievementInfo(i));
                achievement.SetPlayer(Pla.GetAchievementInfo(j));
                achievement.SetGlobal(Glo.GetAchievementInfo(j));
                Pla.Delete(j);
                Glo.Delete(j);
                Finish.push_back(achievement);
                break;
            }
        }
    }
    count=Finish.size();
    statusfinish="success";
    emit finished();
}

void SAchievements::Update(){
    Set(key,appid,id,language);
}
void SAchievements::Clear(){
    Finish.clear();
    count=0;
}
void SAchievements::Sort(){
    for (int i=0; i < count-1; i++) {
        for (int j=0; j < count-i-1; j++) {
            if (Finish[j].GetPercent() < Finish[j+1].GetPercent()){
                SAchievement temp = Finish[j];
                Finish[j] = Finish[j+1];
                Finish[j+1] = temp;
            }
        }
    }
}

SAchievements::SAchievements(const SAchievements & achievement){
    Finish=achievement.Finish;
    Global=achievement.Global;
    Player=achievement.Player;
    Percent=achievement.Percent;
    statusglobal=achievement.statusglobal;
    statusplayer=achievement.statusplayer;
    statuspercent=achievement.statuspercent;
    statusfinish=achievement.statusfinish;
    id=achievement.id;
    appid=achievement.appid;
    key=achievement.key;
    language=achievement.language;
    gamename=achievement.gamename;
    gameversion=achievement.gameversion;
    count=achievement.count;
}
SAchievements & SAchievements::operator=(const SAchievements & achievement){
    Finish=achievement.Finish;
    Global=achievement.Global;
    Player=achievement.Player;
    Percent=achievement.Percent;
    statusglobal=achievement.statusglobal;
    statusplayer=achievement.statusplayer;
    statuspercent=achievement.statuspercent;
    statusfinish=achievement.statusfinish;
    id=achievement.id;
    appid=achievement.appid;
    key=achievement.key;
    language=achievement.language;
    gamename=achievement.gamename;
    gameversion=achievement.gameversion;
    count=achievement.count;
    return* this;
}
