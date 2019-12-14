#include "Sachievements.h"

SAchievements::SAchievements(QString AKey, QString AAppid, QString AID, QObject *parent) : QObject(parent){
    _key=AKey;
    _appid=AAppid;
    _id=AID;
    SAchievementsGlobal *Global = new SAchievementsGlobal(AKey,AAppid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *Player = new SAchievementsPlayer(AKey,AAppid,AID);
    connect(Player,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(AKey,AAppid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
SAchievements::SAchievements(SAchievementsGlobal AGlobal, SAchievementsPlayer APlayer, SAchievementsPercentage APercent){
    qDebug()<<"Set All Achievements data";
    _percent=APercent;
    _statusPercent="success";
    _global=AGlobal;
    _statusGlobal="success";
    _player=APlayer;
    _statusPlayer="success";
    SAchievementsGlobal localGlobal = _global;
    SAchievementsPlayer localPlayer = _player;
    SAchievementsPercentage localPercent = _percent;
    for(int i=0;i<localPercent.GetCount();i++){
        for(int j=0;j<localPlayer.GetCount();j++){
            if(localPercent.GetApiname(i)==localPlayer.GetApiname(j)){
                SAchievement achievement;
                achievement.SetPercent(localPercent.GetAchievement(i));
                achievement.SetPlayer(localPlayer.GetAchievement(j));
                achievement.SetGlobal(localGlobal.GetAchievement(j));
                localPlayer.Delete(j);
                localGlobal.Delete(j);
                _finish.push_back(achievement);
                break;
            }
        }
    }
    _count=_finish.size();
    _statusFinish="success";
    emit s_finished();
}
SAchievements::SAchievements(){

}
SAchievements::~SAchievements(){

}

void SAchievements::Set(QString AKey, QString AAppid, QString AID){
    _key=AKey;
    _appid=AAppid;
    _id=AID;
    SAchievementsGlobal *Global = new SAchievementsGlobal(AKey,AAppid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *Player = new SAchievementsPlayer(AKey,AAppid,AID);
    connect(Player,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(AKey,AAppid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
void SAchievements::DoSet(QString AKey, QString AAppid, QString AID){
    _key=AKey;
    _appid=AAppid;
    _id=AID;
    SAchievementsGlobal *Global = new SAchievementsGlobal(AKey,AAppid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(AKey,AAppid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
void SAchievements::Set(SAchievementsGlobal AGlobal, SAchievementsPlayer APlayer, SAchievementsPercentage APercent){
    Set(APercent);
    Set(AGlobal);
    Set(APlayer);
}
void SAchievements::Set(SAchievementsPlayer APlayer){
    qDebug()<<"Player set";
    _player=APlayer;
    _statusPlayer="success";
    if(_statusGlobal=="success"&&_statusPlayer=="success"&&_statusPercent=="success"){
        SetFinish();
    }
}
void SAchievements::Set(SAchievementsGlobal AGlobal){
    qDebug()<<"Global set";
    _global=AGlobal;
    _statusGlobal="success";
    if(_statusGlobal=="success"&&_statusPlayer=="success"&&_statusPercent=="success"){
        SetFinish();
    }
}
void SAchievements::Set(SAchievementsPercentage APercent){
    qDebug()<<"Percent set";
    _percent=APercent;
    _statusPercent="success";
    if(_statusGlobal=="success"&&_statusPlayer=="success"&&_statusPercent=="success"){
        SetFinish();
    }
}
void SAchievements::SetFinish(){
    Clear();
    SAchievementsGlobal localGlobal = _global;
    SAchievementsPlayer localPlayer = _player;
    SAchievementsPercentage localPercent = _percent;
    for(int i=0;i<localPercent.GetCount();i++){
        for(int j=0;j<localPlayer.GetCount();j++){
            if(localPercent.GetApiname(i)==localPlayer.GetApiname(j)){
                SAchievement achievement;
                achievement.SetPercent(localPercent.GetAchievement(i));
                achievement.SetPlayer(localPlayer.GetAchievement(j));
                achievement.SetGlobal(localGlobal.GetAchievement(j));
                localPlayer.Delete(j);
                localGlobal.Delete(j);
                _finish.push_back(achievement);
                break;
            }
        }
    }
    _count=_finish.size();
    _statusFinish="success";
    emit s_finished();
}

void SAchievements::Update(){
    Set(_key,_appid,_id);
}
void SAchievements::Clear(){
    _finish.clear();
    _count=0;
}
void SAchievements::Sort(){
    for (int i=0; i < _count-1; i++) {
        for (int j=0; j < _count-i-1; j++) {
            if (_finish[j].GetPercent() < _finish[j+1].GetPercent()){
                SAchievement temp = _finish[j];
                _finish[j] = _finish[j+1];
                _finish[j+1] = temp;
            }
        }
    }
}

SAchievements::SAchievements(const SAchievements & ANewAchievements){
    _finish=ANewAchievements._finish;
    _global=ANewAchievements._global;
    _player=ANewAchievements._player;
    _percent=ANewAchievements._percent;
    _statusGlobal=ANewAchievements._statusGlobal;
    _statusPlayer=ANewAchievements._statusPlayer;
    _statusPercent=ANewAchievements._statusPercent;
    _statusFinish=ANewAchievements._statusFinish;
    _id=ANewAchievements._id;
    _appid=ANewAchievements._appid;
    _key=ANewAchievements._key;
    _gameName=ANewAchievements._gameName;
    _gameVersion=ANewAchievements._gameVersion;
    _count=ANewAchievements._count;
}
SAchievements & SAchievements::operator=(const SAchievements & ANewAchievements){
    _finish=ANewAchievements._finish;
    _global=ANewAchievements._global;
    _player=ANewAchievements._player;
    _percent=ANewAchievements._percent;
    _statusGlobal=ANewAchievements._statusGlobal;
    _statusPlayer=ANewAchievements._statusPlayer;
    _statusPercent=ANewAchievements._statusPercent;
    _statusFinish=ANewAchievements._statusFinish;
    _id=ANewAchievements._id;
    _appid=ANewAchievements._appid;
    _key=ANewAchievements._key;
    _gameName=ANewAchievements._gameName;
    _gameVersion=ANewAchievements._gameVersion;
    _count=ANewAchievements._count;
    return *this;
}
