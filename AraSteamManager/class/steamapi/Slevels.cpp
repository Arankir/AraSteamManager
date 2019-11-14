#include "Slevels.h"

SLevels::SLevels(QString key, QString id, QObject* parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    Set(key, id);
}
SLevels::SLevels(QJsonDocument DocBans){
    manager = new QNetworkAccessManager();
    Set(DocBans);
}
SLevels::SLevels(){
    manager = new QNetworkAccessManager();
    status="null";
}
SLevels::~SLevels(){
    delete manager;
}

void SLevels::Set(QString key, QString id){
    QEventLoop loop;
    connect(manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    this->key=key;
    this->steamid=id;
    QNetworkReply& Reply = *manager->get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key="+key+"&steamid="+id));
    loop.exec();
    QJsonDocument DocLvls = QJsonDocument::fromJson(Reply.readAll());
    Set(DocLvls);
    emit finished(this);
    emit finished();
}
void SLevels::Set(QJsonDocument DocLvls){
    if(DocLvls.object().value("response").toObject().value("player_level").toInt()>0){
        player_level=DocLvls.object().value("response").toObject().value("player_level").toInt();
        status="success";
    }
    else {
        status="error: profile is not exist";
    }
}

void SLevels::Update(){
    Set(key, steamid);
}
