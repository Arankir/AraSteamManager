#include "Slevels.h"

SLevels::SLevels(QString aId, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()), _steamid(aId) {
    Load();
}
SLevels::SLevels(QJsonDocument aLvls, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    Set(aLvls);
}

SLevels::SLevels(QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()), _status(StatusValue::none) {

}

SLevels::~SLevels() {
    delete _manager;
}

void SLevels::Set(QString aId) {
    _steamid = std::move(aId);
    Load();
    emit s_finished(this);
    emit s_finished();
}

void SLevels::Update() {
    Load();
}

void SLevels::Load() {
    QEventLoop loop;
    connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    QNetworkReply& reply = *_manager->get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key="+Settings::getKey()+"&steamid="+_steamid));
    loop.exec();
    Set(QJsonDocument::fromJson(reply.readAll()));
}

void SLevels::Set(QJsonDocument a_lvls){
    int lvl = a_lvls.object().value("response").toObject().value("player_level").toInt();
    if (lvl > 0) {
        _player_level = std::move(lvl);
        _status = std::move(StatusValue::success);
    } else {
        _status = std::move(StatusValue::error);
        _error = std::move("profile is not exist");
    }
}

int SLevels::GetLevel() {
    return _player_level;
}

StatusValue SLevels::GetStatus() {
    return _status;
}

QString SLevels::GetError() {
    return _error;
}
