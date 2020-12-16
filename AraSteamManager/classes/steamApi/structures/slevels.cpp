#include "slevels.h"

SLevels::SLevels(const QString &aId, QObject *aParent): Sapi(aParent) {
    load(aId);
}

SLevels &SLevels::load(const QString &aSteamId) {
    _steamid = aSteamId;
    _request.get(lvlUrl(_steamid), false);
    return *this;
}

void SLevels::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.getReply()).object().value("response"));
    emit s_finished(this);
    emit s_finished();
}

void SLevels::fromJson(const QJsonValue &aValue) {
    int lvl = aValue.toObject().value("player_level").toInt();
    if (lvl > 0) {
        _player_level = std::move(lvl);
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = tr("profile is not exist");
    }
}

SLevels &SLevels::update() {
    load(_steamid);
    return *this;
}
