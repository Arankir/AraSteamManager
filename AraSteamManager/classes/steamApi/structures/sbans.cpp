#include "sbans.h"

QList<SBan> onLoadBan(QByteArray byteArray) {
    QList<SBan> list;
    for(auto &&ban: QJsonDocument::fromJson(byteArray).object().value("players").toArray()) {
        list.append(std::move(SBan(ban.toObject())));
    }
    return list;
}

QJsonObject SBan::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["steamid"] = _steamId;
    obj["CommunityBanned"] = _communityBanned;
    obj["VACBanned"] = _vacBanned;
    obj["NumberOfVACBans"] = _numberOfVacBan;
    obj["DaysSinceLastBan"] = _daysSinceLastBan;
    obj["NumberOfGameBans"] = _numberOfGameBans;
    obj["EconomyBan"] = _economyBan;
    return obj;
}

QList<SBan> SBan::load(const QString &aId, std::function<void (QList<SBan>)> aCallback) {
    return Sapi::load<SBan>(bansUrl(aId), onLoadBan, aCallback);
}

SBan &SBan::operator=(const SBan &aBan) {
    _steamId = aBan._steamId;
    _communityBanned = aBan._communityBanned;
    _vacBanned = aBan._vacBanned;
    _numberOfVacBan = aBan._numberOfVacBan;
    _daysSinceLastBan = aBan._daysSinceLastBan;
    _numberOfGameBans = aBan._numberOfGameBans;
    _economyBan = aBan._economyBan;
    return *this;
}

bool SBan::operator<(const SBan &aBan) const {
    return _steamId < aBan._steamId;
}

bool SBan::operator>(const SBan &aBan) const {
    return _steamId > aBan._steamId;
}

bool SBan::operator==(const SBan &aBan) const {
    return (_steamId == aBan._steamId &&
            _communityBanned == aBan._communityBanned &&
            _vacBanned == aBan._vacBanned &&
            _numberOfVacBan == aBan._numberOfVacBan &&
            _daysSinceLastBan == aBan._daysSinceLastBan &&
            _numberOfGameBans == aBan._numberOfGameBans &&
            _economyBan == aBan._economyBan);
}

bool SBan::operator!=(const SBan &aBan) const {
    return (_steamId != aBan._steamId ||
            _communityBanned != aBan._communityBanned ||
            _vacBanned != aBan._vacBanned ||
            _numberOfVacBan != aBan._numberOfVacBan ||
            _daysSinceLastBan != aBan._daysSinceLastBan ||
            _numberOfGameBans != aBan._numberOfGameBans ||
            _economyBan != aBan._economyBan);
}
