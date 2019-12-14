#include "Slevels.h"

SLevels::SLevels(QString AKey, QString AID, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    QEventLoop loop;
    connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    _key=AKey;
    _steamid=AID;
    QNetworkReply& Reply = *_manager->get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key="+AKey+"&steamid="+AID));
    loop.exec();
    QJsonDocument DocLvls = QJsonDocument::fromJson(Reply.readAll());
    Set(DocLvls);
    emit s_finished(this);
    emit s_finished();
}
SLevels::SLevels(QJsonDocument ALvls){
    _manager = new QNetworkAccessManager();
    if(ALvls.object().value("response").toObject().value("player_level").toInt()>0){
        _player_level=ALvls.object().value("response").toObject().value("player_level").toInt();
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}
SLevels::SLevels(){
    _manager = new QNetworkAccessManager();
    _status="null";
}
SLevels::~SLevels(){
    delete _manager;
}

void SLevels::Set(QString AKey, QString AID){
    QEventLoop loop;
    connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    _key=AKey;
    _steamid=AID;
    QNetworkReply& Reply = *_manager->get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key="+AKey+"&steamid="+AID));
    loop.exec();
    QJsonDocument DocLvls = QJsonDocument::fromJson(Reply.readAll());
    Set(DocLvls);
    emit s_finished(this);
    emit s_finished();
}
void SLevels::Set(QJsonDocument ALvls){
    if(ALvls.object().value("response").toObject().value("player_level").toInt()>0){
        _player_level=ALvls.object().value("response").toObject().value("player_level").toInt();
        _status="success";
    }
    else {
        _status="error: profile is not exist";
    }
}

void SLevels::Update(){
    Set(_key, _steamid);
}
