#include "Sbans.h"

SBans::SBans(const QString &aId, bool aParallel, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    set(aId, aParallel);
}

SBans::SBans(QJsonDocument &aBans, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    set(aBans);
}

SBans::SBans(QObject *parent): QObject(parent), _manager(new QNetworkAccessManager()), _status(StatusValue::none) {

}

SBans::~SBans() {
    delete _manager;
}

void SBans::set(const QString &aId, bool aParallel) {
    _id = std::move(aId);
    if (aParallel) {
        connect(_manager, &QNetworkAccessManager::finished, this, &SBans::onLoad);
        _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key=" + Settings::getKey() + "&steamids=" + aId));
    } else {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        QNetworkReply *reply = _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key=" + Settings::getKey() + "&steamids=" + aId));
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        set(doc);
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}

void SBans::set(QJsonDocument &aBans) {
    if(aBans.object().value("players").toArray().size() > 0) {
        _bans = aBans.object().value("players").toArray();
        _status = StatusValue::success;
    }
    else {
        _status = StatusValue::error;
        _error = "profile is not exist";
    }
}

QString SBans::getSteamid(int aIndex) {
    return _bans[aIndex].toObject().value("steamid").toString();
}

bool SBans::getCommunityBanned(int aIndex) {
    return _bans[aIndex].toObject().value("CommunityBanned").toBool();
}

bool SBans::getVacBanned(int aIndex) {
    return _bans[aIndex].toObject().value("VACBanned").toBool();
}

int SBans::getNumberOfVacBans(int aIndex) {
    return _bans[aIndex].toObject().value("NumberOfVACBans").toInt();
}

int SBans::getDaysSinceLastBan(int aIndex) {
    return _bans[aIndex].toObject().value("DaysSinceLastBan").toInt();
}

int SBans::getNumberOfGameBans(int aIndex) {
    return _bans[aIndex].toObject().value("NumberOfGameBans").toInt();
}

QString SBans::getEconomyBan(int aIndex) {
    return _bans[aIndex].toObject().value("EconomyBan").toString();
}

StatusValue SBans::getStatus() {
    return _status;
}

QString SBans::getError() {
    return _error;
}

void SBans::onLoad(QNetworkReply *aReply) {
    disconnect(_manager, &QNetworkAccessManager::finished, this, &SBans::onLoad);
    QJsonDocument doc = QJsonDocument::fromJson(aReply->readAll());
    set(doc);
    aReply->deleteLater();
    emit s_finished(this);
    emit s_finished();
}

void SBans::update(bool aParallel) {
    set(_id, aParallel);
}
