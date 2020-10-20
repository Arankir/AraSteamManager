#include "Slevels.h"

SLevels::SLevels(const QString &aId, QObject *aParent): Sapi(aParent) {
    load(aId);
}

SLevels &SLevels::load(const QString &aSteamId) {
    _steamid = aSteamId;
    _request.get(lvlUrl(_steamid), false);
    return *this;
}

void SLevels::onLoad() {
    parse(QJsonDocument::fromJson(_request.getReply()));
    emit s_finished(this);
    emit s_finished();
}

void SLevels::parse(const QJsonDocument &aLvls) {
    int lvl = aLvls.object().value("response").toObject().value("player_level").toInt();
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

int SLevels::getLevel() const {
    return _player_level;
}
