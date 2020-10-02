#include "Slevels.h"

SLevels::SLevels(const QString &aId, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()), _steamid(aId) {
    load();
}
SLevels::SLevels(QJsonDocument &aLvls, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    set(aLvls);
}

SLevels::SLevels(QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()), _status(StatusValue::none) {

}

SLevels::~SLevels() {
    delete _manager;
}

void SLevels::set(const QString &aId) {
    _steamid = std::move(aId);
    load();
    emit s_finished(this);
    emit s_finished();
}

void SLevels::update() {
    load();
}

void SLevels::load() {
    QEventLoop loop;
    connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
    QNetworkReply& reply = *_manager->get(QNetworkRequest("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key=" + Settings::getKey() + "&steamid=" + _steamid));
    loop.exec();
    QJsonDocument doc = QJsonDocument::fromJson(reply.readAll());
    set(doc);
}

void SLevels::set(QJsonDocument &aLvls) {
    int lvl = aLvls.object().value("response").toObject().value("player_level").toInt();
    if (lvl > 0) {
        _player_level = std::move(lvl);
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = "profile is not exist";
    }
}

int SLevels::getLevel() {
    return _player_level;
}

StatusValue SLevels::getStatus() {
    return _status;
}

QString SLevels::getError() {
    return _error;
}
