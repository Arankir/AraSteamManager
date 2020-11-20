#include "Sachievements.h"

#define SAchievementStart {
SAchievement::SAchievement(SAchievementGlobal &aGlobal, SAchievementPlayer &aPlayer, SAchievementPercentage &aPercent, QObject *aParent):
QObject(aParent), _apiName(aGlobal._apiName), _defaultValue(aGlobal._defaultValue), _displayName(aGlobal._displayName), _hidden(aGlobal._hidden),
_description(aGlobal._description), _achieved(aPlayer._achieved), _unlockTime(aPlayer._unlockTime),
_percent(aPercent._percent), _icon(aGlobal._icon), _iconGray(aGlobal._iconGray) {
    //qDebug()<<"SAchievement constructor"<<_apiName;
}

SAchievement::SAchievement(const SAchievement &aAchievement): QObject(aAchievement.parent()), _apiName(aAchievement._apiName),
_defaultValue(aAchievement._defaultValue), _displayName(aAchievement._displayName), _hidden(aAchievement._hidden),
_description(aAchievement._description), _achieved(aAchievement._achieved), _unlockTime(aAchievement._unlockTime), _percent(aAchievement._percent),
_icon(aAchievement._icon), _iconGray(aAchievement._iconGray), _pixmapIcon(aAchievement._pixmapIcon), _pixmapIconGray(aAchievement._pixmapIconGray) {
    //qDebug()<<"SAchievement copy"<<_apiName;
}

SAchievement::SAchievement(const QJsonObject &aObject): _apiName(aObject.value("apiName").toString()),
                           _defaultValue(aObject.value("defaultValue").toInt()),
                           _displayName(aObject.value("displayName").toString()),
                           _hidden(aObject.value("hidden").toInt()),
                           _description(aObject.value("description").toString()),
                           _achieved(aObject.value("achieved").toInt()),
                           _unlockTime(QDateTime::fromString(aObject.value("unlockTime").toString())),
                           _percent(aObject.value("percent").toDouble()), _icon(aObject.value("icon").toString()),
                           _iconGray(aObject.value("iconGray").toString()) {
    //qDebug()<<"SAchievement copy"<<_apiName;
}

SAchievement::SAchievement(const QString &aText): SAchievement(QJsonValue(aText).toObject()) {
    //qDebug()<<"SAchievement copy"<<_apiName;
}

SAchievement &SAchievement::operator=(const SAchievement &aAchievement) {
    //qDebug()<<"SAchievement equality"<<_apiName;
    _pixmapIcon     = aAchievement._pixmapIcon;
    _pixmapIconGray = aAchievement._pixmapIconGray;
    return *this;
}

bool SAchievement::operator<(const SAchievement &aAchievement) {
    return _displayName.compare(aAchievement._displayName, Qt::CaseInsensitive) < 0;
}

QString SAchievement::toString() const {
    QJsonObject object;
    object["apiName"] = _apiName;
    object["defaultValue"] = _defaultValue;
    object["displayName"] = _displayName;
    object["hidden"] = _hidden;
    object["description"] = _description;
    object["achieved"] = _achieved;
    object["unlockTime"] = _unlockTime.toString();
    object["percent"] = _percent;
    object["icon"] = _icon;
    object["iconGray"] = _iconGray;
    return QJsonDocument(object).toJson(QJsonDocument::Compact);
}

QPixmap SAchievement::getIcon(int aGameId) {
    return loadPixmap(_pixmapIcon, _icon, Paths::imagesAchievements(QString::number(aGameId), _icon), QSize(64, 64));
}

QPixmap SAchievement::getIconGray(int aGameId) {
    return loadPixmap(_pixmapIconGray, _iconGray, Paths::imagesAchievements(QString::number(aGameId), _iconGray), QSize(64, 64));
}
#define SAchievementEnd }

#define MultipleAchievements {
#define SAchievementsGlobalStart {
SAchievementsGlobal::SAchievementsGlobal(const QString &aAppid, bool aParallel, QObject *aParent): Sapi(aParent), _appid(aAppid) {
    update(aParallel);
}

SAchievementsGlobal &SAchievementsGlobal::operator=(const SAchievementsGlobal &aAchievements) {
    Sapi::operator=(aAchievements);
    _achievements   = aAchievements._achievements;
    _appid          = aAchievements._appid;
    _gameName       = aAchievements._gameName;
    _gameVersion    = aAchievements._gameVersion;
    //qDebug()<<"SAchievementsGlobal equality"<<_appid;
    return *this;
}

SAchievementsGlobal &SAchievementsGlobal::remove(int index) {
    _achievements.removeAt(index);
    return *this;
}

SAchievementsGlobal &SAchievementsGlobal::load(const QString &aAppid, bool aParalell) {
    _appid = aAppid;
    _request.get(achievementsGlobalUrl(_appid), aParalell);
    return *this;
}

void SAchievementsGlobal::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.getReply()).object().value("game"));
    emit s_finished();
}

void SAchievementsGlobal::fromJson(const QJsonValue &aValue) {
    clear();
    QJsonArray gameAchievements = aValue.toObject().value("availableGameStats").toObject().value("achievements").toArray();
    if(gameAchievements.size() > 0) {
        _gameName = aValue.toObject().value("gameName").toString();
        _gameVersion = aValue.toObject().value("gameVersion").toString();
        for(const auto &achievement: gameAchievements) {
            _achievements.append(std::move(SAchievementGlobal(achievement.toObject())));
        }
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = tr("achievements is not exist");
    }
}

SAchievementsGlobal &SAchievementsGlobal::update(bool aParalell) {
    load(_appid, aParalell);
    return *this;
}

SAchievementsGlobal &SAchievementsGlobal::clear() {
    _achievements.clear();
    _status = StatusValue::none;
    return *this;
}
#define SAchievementsGlobalEnd }
#define SAchievementsPercentageStart {
SAchievementsPercentage::SAchievementsPercentage(const QString &aAppid, bool aParallel, QObject *aParent): Sapi(aParent), _appid(aAppid) {
    //qDebug() << "constructor 1" << _appid;
    load(_appid, aParallel);
}

SAchievementsPercentage &SAchievementsPercentage::operator=(const SAchievementsPercentage &aAchievements) {
    Sapi::operator=(aAchievements);
    _achievements   = aAchievements._achievements;
    _appid          = aAchievements._appid;
    //qDebug() << "equality" << _appid;
    return *this;
}

SAchievementsPercentage &SAchievementsPercentage::load(const QString &aAppid, bool aParalell) {
    _appid = aAppid;
    _request.get(achievementsPercentUrl(_appid), aParalell);
    return *this;
}

void SAchievementsPercentage::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.getReply()).object().value("achievementpercentages").toObject().value("achievements"));
    emit s_finished();
}

void SAchievementsPercentage::fromJson(const QJsonValue &aValue) {
    clear();
    QJsonArray achievementsArray = aValue.toArray();
    if (achievementsArray.size() > 0) {
        for (const auto &achievement: achievementsArray) {
            _achievements.append(std::move(SAchievementPercentage(achievement.toObject())));
        }
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = tr("game is not exist");
    }
}

SAchievementsPercentage &SAchievementsPercentage::update(bool aParalell) {
    load(_appid, aParalell);
    return *this;
}

SAchievementsPercentage &SAchievementsPercentage::clear() {
    _achievements.clear();
    _status = StatusValue::none;
    return *this;
}

SAchievementsPercentage &SAchievementsPercentage::remove(int aIndex) {
    _achievements.removeAt(aIndex);
    return *this;
}
#define SAchievementsPercentageEnd }
#define SAchievementsPlayerStart {
SAchievementsPlayer::SAchievementsPlayer(const QString &aAppid, const QString &aId, bool aParallel, QObject *aParent): Sapi(aParent), _id(aId), _appid(aAppid) {
    //qDebug() << "SAchievementsPlayer constructor 1" << _id << _appid;
    load(_appid, _id, aParallel);
}

SAchievementsPlayer &SAchievementsPlayer::operator=(const SAchievementsPlayer &aAchievements) {
    Sapi::operator=(aAchievements);
    _achievements   = aAchievements._achievements;
    _appid          = aAchievements._appid;
    _id             = aAchievements._id;
    _gameName       = aAchievements._gameName;
    //qDebug() << "SAchievementsPlayer equality" << _appid << _id;
    return *this;
}

SAchievementsPlayer &SAchievementsPlayer::load(const QString &aAppid, const QString &aId, bool aParalell) {
    _appid  = aAppid;
    _id     = aId;
    _request.get(achievementsPlayerUrl(_appid, _id), aParalell);
    return *this;
}

void SAchievementsPlayer::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.getReply()).object().value("playerstats"));
    emit s_finished(this);
}

void SAchievementsPlayer::fromJson(const QJsonValue &aValue) {
    clear();
    QJsonArray achievementsArray = aValue.toObject().value("achievements").toArray();
    if (achievementsArray.size() > 0) {
        //_appid = aValue.toObject().value("steamID").toString();
        _gameName = aValue.toObject().value("gameName").toString();
        for (const auto &achievement: achievementsArray) {
            achievement.toObject().value("achieved").toInt() ? ++_reached : ++_notReached;
            _achievements.append(std::move(SAchievementPlayer(achievement.toObject())));
        }
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = tr("profile is not exist");
    }
}

SAchievementsPlayer &SAchievementsPlayer::update(bool aParalell) {
    clear();
    load(_appid, _id, aParalell);
    return *this;
}

SAchievementsPlayer &SAchievementsPlayer::clear() {
    _achievements.clear();
    _reached    = 0;
    _notReached = 0;
    _status     = StatusValue::none;
    return *this;
}

SAchievementsPlayer &SAchievementsPlayer::remove(int aIndex) {
    _achievements.removeAt(aIndex);
    return *this;
}
#define SAchievementsPlayerEnd }
#define SAchievementsStart {
SAchievements::SAchievements(const QString &aAppid, const QString &aId, bool aParalell, QObject *aParent): QObject(aParent)/*, _id(aId), _appid(aAppid)*/ {
    //qDebug()<<"constructor 1";
    initConnects();
    load(aAppid, aId, aParalell);
}

SAchievements::SAchievements(const SAchievementsGlobal &aGlobal, const SAchievementsPlayer &aPlayer, const SAchievementsPercentage &aPercent, QObject *aParent): QObject(aParent),
_global(aGlobal), _player(aPlayer), _percent(aPercent) {
    //qDebug()<<"Set All Achievements in constructor";
    initConnects();
}

SAchievements &SAchievements::operator=(const SAchievements &aAchievements) {
    _global         = aAchievements._global;
    _player         = aAchievements._player;
    _percent        = aAchievements._percent;
    _finish         = aAchievements._finish;
    _status         = aAchievements._status;
    _error          = aAchievements._error;
//    _id             = aAchievements._id;
//    _appid          = aAchievements._appid;
    _gameName       = aAchievements._gameName;
    _gameVersion    = aAchievements._gameVersion;
    //qDebug() << "equence";
    return *this;
}

void SAchievements::initConnects() {
    connect(&_global,  &SAchievementsGlobal::s_finished,     this, &SAchievements::setFinish);
    connect(&_player,  &SAchievementsPlayer::s_finished,     this, &SAchievements::setFinish);
    connect(&_percent, &SAchievementsPercentage::s_finished, this, &SAchievements::setFinish);
}

void SAchievements::setStatus(StatusValue aStatus) {
    _status = aStatus;
    switch (aStatus) {
    case StatusValue::none: {
        _error  = "none";
        break;
    }
    case StatusValue::error: {
        QStringList needList;
        if (_global.getStatus() != StatusValue::success) {
            needList.append(tr("global"));
        }
        if (_player.getStatus() != StatusValue::success) {
            needList.append(tr("player"));
        }
        if (_percent.getStatus() != StatusValue::success) {
            needList.append(tr("percent"));
        }
        _error = tr("Need data of (");
        _error += needList.join(", ");
        _error += tr(")");
        break;
    }
    case StatusValue::success: {
        _error  = "none";
    }
    }
}

SAchievements &SAchievements::load(const QString &aAppid, const QString &aId, bool aParalell) {
//    _appid = aAppid;
//    _id = aId;
    clear();
    _global .load(aAppid, aParalell);
    _player .load(aAppid, aId, aParalell);
    _percent.load(aAppid, aParalell);
    return *this;
}

SAchievements &SAchievements::set(SAchievementsGlobal &aGlobal, SAchievementsPlayer &aPlayer, SAchievementsPercentage &aPercent) {
    _global     = aGlobal;
    _player     = aPlayer;
    _percent    = aPercent;
    return setFinish();
}

SAchievements &SAchievements::set(const SAchievementsPlayer &aPlayer) {
    _player = aPlayer;
    return setFinish();
}

SAchievements &SAchievements::set(const SAchievementsGlobal &aGlobal) {
    _global = aGlobal;
    return setFinish();
}

SAchievements &SAchievements::set(const SAchievementsPercentage &aPercent) {
    _percent = aPercent;
    return setFinish();
}

SAchievements &SAchievements::setFinish() {
    if((_global.getStatus() == StatusValue::success) && (_player.getStatus() == StatusValue::success) && (_percent.getStatus() == StatusValue::success)) {
        //qDebug()<<"Finish set";
        clear();
        for (auto &percent: _percent) {
            int globalIndex = -1;
            for (auto &player: _player) {
                auto global = std::move(_global[++globalIndex]);
                if (percent._apiName == player._apiName) {
                    _finish.push_back(std::move(SAchievement(global, player, percent)));
                    break;
                }
            }
        }
        setStatus(StatusValue::success);
        emit s_finished();
    } else {
        setStatus(StatusValue::error);
    }
    //qDebug() << _error;
    return *this;
}

SAchievements &SAchievements::update(bool aParalell) {
    //_finish.clear();
    setStatus(StatusValue::none);
    _global.update(aParalell);
    _player.update(aParalell);
    _percent.update(aParalell);
    return *this;
//    load(_appid, _id, true);
}

SAchievements &SAchievements::clear() {
    _finish.clear();
    setStatus(StatusValue::none);
    return *this;
}

SAchievements &SAchievements::sort() {
    std::sort(_finish.begin(), _finish.end());
    return *this;
}
#define SAchievementsEnd }
#define MultipleAchievementsEnd }
