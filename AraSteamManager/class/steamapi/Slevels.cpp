#include "Slevels.h"

SLevels::SLevels(QString a_id, QObject *parent) : QObject(parent),_steamid(a_id){
    _manager = new QNetworkAccessManager();
    QEventLoop loop;
    connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    QNetworkReply& Reply = *_manager->get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key="+_setting.GetKey()+"&steamid="+a_id));
    loop.exec();
    QJsonDocument DocLvls = QJsonDocument::fromJson(Reply.readAll());
    Set(DocLvls);
    emit s_finished(this);
    emit s_finished();
}
SLevels::SLevels(QJsonDocument a_lvls, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    if(a_lvls.object().value("response").toObject().value("player_level").toInt()>0){
        _player_level=a_lvls.object().value("response").toObject().value("player_level").toInt();
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
SLevels::SLevels(QObject *parent) : QObject(parent),_status(StatusValue::none){
    _manager = new QNetworkAccessManager();
}
SLevels::~SLevels(){
    delete _manager;
}

void SLevels::Set(QString a_id){
    QEventLoop loop;
    connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    _steamid=a_id;
    QNetworkReply& Reply = *_manager->get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key="+_setting.GetKey()+"&steamid="+a_id));
    loop.exec();
    QJsonDocument DocLvls = QJsonDocument::fromJson(Reply.readAll());
    Set(DocLvls);
    emit s_finished(this);
    emit s_finished();
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

void SLevels::Update(){
    Set(_steamid);
}
