#include "sbans.h"

QList<SBan> onLoadBan(QByteArray byteArray) {
    QList<SBan> list;
    for (const auto &ban: QJsonDocument::fromJson(byteArray).object().value("players").toArray()) {
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

SBan &SBan::operator=(const SBan &ban) {
    _steamId = ban._steamId;
    _communityBanned = ban._communityBanned;
    _vacBanned = ban._vacBanned;
    _numberOfVacBan = ban._numberOfVacBan;
    _daysSinceLastBan = ban._daysSinceLastBan;
    _numberOfGameBans = ban._numberOfGameBans;
    _economyBan = ban._economyBan;
    return *this;
}
