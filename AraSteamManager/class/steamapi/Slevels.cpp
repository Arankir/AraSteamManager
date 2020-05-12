#include "Slevels.h"

SLevels::SLevels(QString a_id, QObject *parent): QObject(parent), _manager(new QNetworkAccessManager()), _steamid(a_id){
    Load();
}
SLevels::SLevels(QJsonDocument a_lvls, QObject *parent): QObject(parent), _manager(new QNetworkAccessManager()){
    Set(a_lvls);
}
SLevels::~SLevels(){
    delete _manager;
}

void SLevels::Set(QString a_id){
    _steamid=a_id;
    Load();
    emit s_finished(this);
    emit s_finished();
}
void SLevels::Update(){
    Load();
}

void SLevels::Load(){
    QEventLoop loop;
    connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    QNetworkReply& Reply = *_manager->get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key="+_setting.GetKey()+"&steamid="+_steamid));
    loop.exec();
    QJsonDocument DocLvls = QJsonDocument::fromJson(Reply.readAll());
    Set(DocLvls);
}
void SLevels::Set(QJsonDocument a_lvls){
    if(a_lvls.object().value("response").toObject().value("player_level").toInt()>0){
        _player_level=a_lvls.object().value("response").toObject().value("player_level").toInt();
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
