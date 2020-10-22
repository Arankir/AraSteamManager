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

SAchievement &SAchievement::operator=(const SAchievement &aAchievement) {
    //qDebug()<<"SAchievement equality"<<_apiName;
    _pixmapIcon = aAchievement._pixmapIcon;
    _pixmapIconGray = aAchievement._pixmapIconGray;
    return *this;
}

const bool &SAchievement::operator<(const SAchievement &aAchievement){
    static const bool b = _displayName.toLower() < aAchievement._displayName.toLower();
    return b;
}

QPixmap SAchievement::getIcon(int aGameId) {
    return getPixmap(_pixmapIcon, _icon, QSize(64, 64), aGameId);
}

QPixmap SAchievement::getIconGray(int aGameId) {
    return getPixmap(_pixmapIconGray, _iconGray, QSize(64, 64), aGameId);
}

QPixmap SAchievement::getPixmap(QPixmap &pixmap, const QString &url, QSize size, int aGameId) {
    if (pixmap.isNull()) {
        if ((url != "") && (url.lastIndexOf("/") != url.length() - 1)) {
            QString savePath = Paths::imagesAchievements(QString::number(aGameId), _icon);
            if (!QFile::exists(savePath)) {
                RequestImage *img = new RequestImage(url, savePath, true, this);
                QEventLoop loop;
                connect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
                loop.exec();
                disconnect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
                pixmap = img->getPixmap();
                delete img;
            } else {
                pixmap = QPixmap(savePath);
            }
        } else {
            pixmap = QPixmap(Images::missingImage()).scaled(size);
        }
    }
    return pixmap;
}
#define SAchievementEnd }

#define MultipleAchievements {
#define SAchievementsGlobalStart {
SAchievementsGlobal::SAchievementsGlobal(const QString &aAppid, bool aParallel, QObject *aParent): Sapi(aParent), _appid(aAppid) {
    update(aParallel);
}

SAchievementsGlobal &SAchievementsGlobal::operator=(const SAchievementsGlobal &aAchievements) {
    _status = _status;
    _error = _error;

    _achievements = aAchievements._achievements;
    _appid = aAchievements._appid;
    _gameName = aAchievements._gameName;
    _gameVersion = aAchievements._gameVersion;
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
    parse(QJsonDocument::fromJson(_request.getReply()));
    emit s_finished();
}

void SAchievementsGlobal::parse(const QJsonDocument &aAchievements) {
    clear();
    QJsonArray gameAchievements = aAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray();
    if(gameAchievements.size() > 0) {
        _gameName = aAchievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion = aAchievements.object().value("game").toObject().value("gameVersion").toString();
        for(auto achievement: gameAchievements) {
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
    _status = aAchievements._status;
    _error = aAchievements._error;

    _achievements = aAchievements._achievements;
    _appid = aAchievements._appid;
    //qDebug() << "equality" << _appid;
    return *this;
}

SAchievementsPercentage &SAchievementsPercentage::load(const QString &aAppid, bool aParalell) {
    _appid = aAppid;
    _request.get(achievementsPercentUrl(_appid), aParalell);
    return *this;
}

void SAchievementsPercentage::onLoad() {
    parse(QJsonDocument::fromJson(_request.getReply()));
    emit s_finished();
}

void SAchievementsPercentage::parse(const QJsonDocument &aAchievements) {
    clear();
    QJsonArray achievementsArray = aAchievements.object().value("achievementpercentages").toObject().value("achievements").toArray();
    if (achievementsArray.size() > 0) {
        for (auto achievement: achievementsArray) {
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
    //qDebug()<<"SAchievementsPlayer constructor 1"<<_id<<_appid;
    load(_appid, _id, aParallel);
}

SAchievementsPlayer &SAchievementsPlayer::operator=(const SAchievementsPlayer &aAchievements) {
    _status         = aAchievements._status;
    _error          = aAchievements._error;

    _achievements   = aAchievements._achievements;
    _appid          = aAchievements._appid;
    _id             = aAchievements._id;
    _gameName       = aAchievements._gameName;
    _index          = aAchievements._index;
    //qDebug()<<"SAchievementsPlayer equality"<<_appid<<_id;
    return *this;
}

SAchievementsPlayer &SAchievementsPlayer::load(const QString &aAppid, const QString &aId, bool aParalell) {
    _appid  = aAppid;
    _id     = aId;
    _request.get(achievementsPlayerUrl(_appid, _id), aParalell);
    return *this;
}

void SAchievementsPlayer::onLoad() {
    parse(QJsonDocument::fromJson(_request.getReply()));
    emit s_finished(this);
}

void SAchievementsPlayer::parse(const QJsonDocument &aAchievements) {
    clear();
    QJsonArray achievementsArray = aAchievements.object().value("playerstats").toObject().value("achievements").toArray();
    if (achievementsArray.size() > 0) {
        //_appid = aAchievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName = aAchievements.object().value("playerstats").toObject().value("gameName").toString();
        for (auto achievement: achievementsArray) {
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
    switch (aStatus) {
    case StatusValue::none: {
        _status = StatusValue::none;
        _error = "none";
        break;
    }
    case StatusValue::error: {
        _status = StatusValue::error;
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
        _status = StatusValue::success;
        _error = "none";
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
