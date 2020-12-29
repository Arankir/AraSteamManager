#include "slevels.h"

SLevels::SLevels(const QString &aId, QObject *aParent): Sapi(aParent) {
    load(aId);
}

SLevels &SLevels::load(const QString &aSteamId) {
    _steamId = aSteamId;
    _request.get(lvlUrl(_steamId), false);
    return *this;
}

void SLevels::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.reply()).object().value("response"));
    emit s_finished(this);
    emit s_finished();
}

void SLevels::fromJson(const QJsonValue &aValue) {
    int lvl = aValue.toObject().value("player_level").toInt();
    if (lvl > 0) {
        _playerLevel = std::move(lvl);
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = tr("profile is not exist");
    }
}

SLevels &SLevels::update() {
    load(_steamId);
    return *this;
}
