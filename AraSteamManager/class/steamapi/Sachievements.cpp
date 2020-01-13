#include "Sachievements.h"

SAchievements::SAchievements(QString Aappid, QString Aid, QObject *parent) : QObject(parent){
    _appid=Aappid;
    _id=Aid;
    SAchievementsGlobal *Global = new SAchievementsGlobal(Aappid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *Player = new SAchievementsPlayer(Aappid,Aid);
    connect(Player,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(Aappid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
SAchievements::SAchievements(SAchievementsGlobal Aglobal, SAchievementsPlayer Aplayer, SAchievementsPercentage Apercent){
    qDebug()<<"Set All Achievements data";
    _percent=Apercent;
    _statusPercent=StatusValue::success;
    _global=Aglobal;
    _statusGlobal=StatusValue::success;
    _player=Aplayer;
    _statusPlayer=StatusValue::success;
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
    _statusFinish=StatusValue::success;
    emit s_finished();
}
SAchievements::SAchievements(){

}
SAchievements::~SAchievements(){

}

void SAchievements::Set(QString Aappid, QString Aid){
    _appid=Aappid;
    _id=Aid;
    SAchievementsGlobal *Global = new SAchievementsGlobal(Aappid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPlayer *Player = new SAchievementsPlayer(Aappid,Aid);
    connect(Player,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(Set(SAchievementsPlayer)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(Aappid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
void SAchievements::DoSet(QString Aappid, QString Aid){
    _appid=Aappid;
    _id=Aid;
    SAchievementsGlobal *Global = new SAchievementsGlobal(Aappid);
    connect(Global,SIGNAL(s_finished(SAchievementsGlobal)),this,SLOT(Set(SAchievementsGlobal)));
    SAchievementsPercentage *Percent = new SAchievementsPercentage(Aappid);
    connect(Percent,SIGNAL(s_finished(SAchievementsPercentage)),this,SLOT(Set(SAchievementsPercentage)));
}
void SAchievements::Set(SAchievementsGlobal Aglobal, SAchievementsPlayer Aplayer, SAchievementsPercentage Apercent){
    Set(Apercent);
    Set(Aglobal);
    Set(Aplayer);
}
void SAchievements::Set(SAchievementsPlayer Aplayer){
    qDebug()<<"Player set";
    _player=Aplayer;
    _statusPlayer=StatusValue::success;
    if(_statusGlobal==StatusValue::success&&_statusPlayer==StatusValue::success&&_statusPercent==StatusValue::success){
        SetFinish();
    }
}
void SAchievements::Set(SAchievementsGlobal Aglobal){
    qDebug()<<"Global set";
    _global=Aglobal;
    _statusGlobal=StatusValue::success;
    if(_statusGlobal==StatusValue::success&&_statusPlayer==StatusValue::success&&_statusPercent==StatusValue::success){
        SetFinish();
    }
}
void SAchievements::Set(SAchievementsPercentage Apercent){
    qDebug()<<"Percent set";
    _percent=Apercent;
    _statusPercent=StatusValue::success;
    if(_statusGlobal==StatusValue::success&&_statusPlayer==StatusValue::success&&_statusPercent==StatusValue::success){
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
    _statusFinish=StatusValue::success;
    emit s_finished();
}

void SAchievements::Update(){
    Set(_appid,_id);
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

SAchievements::SAchievements(const SAchievements & AnewAchievements){
    _finish=AnewAchievements._finish;
    _global=AnewAchievements._global;
    _player=AnewAchievements._player;
    _percent=AnewAchievements._percent;
    _statusGlobal=AnewAchievements._statusGlobal;
    _statusPlayer=AnewAchievements._statusPlayer;
    _statusPercent=AnewAchievements._statusPercent;
    _statusFinish=AnewAchievements._statusFinish;
    _errorGlobal=AnewAchievements._errorGlobal;
    _errorPlayer=AnewAchievements._errorPlayer;
    _errorPercent=AnewAchievements._errorPercent;
    _errorFinish=AnewAchievements._errorFinish;
    _id=AnewAchievements._id;
    _appid=AnewAchievements._appid;
    _gameName=AnewAchievements._gameName;
    _gameVersion=AnewAchievements._gameVersion;
    _count=AnewAchievements._count;
}
SAchievements & SAchievements::operator=(const SAchievements & AnewAchievements){
    _finish=AnewAchievements._finish;
    _global=AnewAchievements._global;
    _player=AnewAchievements._player;
    _percent=AnewAchievements._percent;
    _statusGlobal=AnewAchievements._statusGlobal;
    _statusPlayer=AnewAchievements._statusPlayer;
    _statusPercent=AnewAchievements._statusPercent;
    _statusFinish=AnewAchievements._statusFinish;
    _errorGlobal=AnewAchievements._errorGlobal;
    _errorPlayer=AnewAchievements._errorPlayer;
    _errorPercent=AnewAchievements._errorPercent;
    _errorFinish=AnewAchievements._errorFinish;
    _id=AnewAchievements._id;
    _appid=AnewAchievements._appid;
    _gameName=AnewAchievements._gameName;
    _gameVersion=AnewAchievements._gameVersion;
    _count=AnewAchievements._count;
    return *this;
}
