#include "Sbans.h"

SBans::SBans(const QString &aId, bool aParallel, QObject *aParent): Sapi(aParent) {
    load(aId, aParallel);
}

SBans &SBans::load(const QString &aId, bool aParallel) {
    _id = aId;
    _request.get(bansUrl(aId), aParallel);
    return *this;
}

void SBans::onLoad() {
    parse(QJsonDocument::fromJson(_request.getReply()));
    emit s_finished();
}

void SBans::parse(const QJsonDocument &doc) {
    if(doc.object().value("players").toArray().size() > 0) {
        _bans = doc.object().value("players").toArray();
        _status = StatusValue::success;
    }
    else {
        _status = StatusValue::error;
        _error = tr("profile is not exist");
    }
}

QString SBans::getSteamid(int aIndex) const {
    return _bans[aIndex].toObject().value("steamid").toString();
}

bool SBans::getCommunityBanned(int aIndex) const {
    return _bans[aIndex].toObject().value("CommunityBanned").toBool();
}

bool SBans::getVacBanned(int aIndex) const {
    return _bans[aIndex].toObject().value("VACBanned").toBool();
}

int SBans::getNumberOfVacBans(int aIndex) const {
    return _bans[aIndex].toObject().value("NumberOfVACBans").toInt();
}

int SBans::getDaysSinceLastBan(int aIndex) const {
    return _bans[aIndex].toObject().value("DaysSinceLastBan").toInt();
}

int SBans::getNumberOfGameBans(int aIndex) const {
    return _bans[aIndex].toObject().value("NumberOfGameBans").toInt();
}

QString SBans::getEconomyBan(int aIndex) const {
    return _bans[aIndex].toObject().value("EconomyBan").toString();
}

SBans &SBans::update(bool aParallel) {
    load(_id, aParallel);
    return *this;
}
