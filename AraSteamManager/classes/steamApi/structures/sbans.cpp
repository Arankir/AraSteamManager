#include "sbans.h"

SBans::SBans(const QString &aId, bool aParallel, QObject *aParent): Sapi(aParent) {
    load(aId, aParallel);
}

SBans &SBans::load(const QString &aId, bool aParallel) {
    _id = aId;
    _request.get(bansUrl(aId), aParallel);
    return *this;
}

void SBans::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.reply()).object().value("players"));
    emit s_finished();
}

void SBans::fromJson(const QJsonValue &aValue) {
    clear();
    QJsonArray bansArray = aValue.toArray();
    if (bansArray.size() > 0) {
        for (const auto &ban: bansArray) {
            _bans.append(std::move(SBan(ban.toObject())));
        }
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = tr("profile is not exist");
    }
}

SBans &SBans::clear() {
    _bans.clear();
    return *this;
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
