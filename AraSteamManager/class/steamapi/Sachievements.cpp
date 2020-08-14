#include "Sachievements.h"

#define SingleAchievements {
#define SAchievementGlobalStart {
SAchievementGlobal::SAchievementGlobal(QJsonObject aAchievement, QObject *aParent): QObject(aParent),
_apiName(aAchievement.value("name").toString()), _defaultValue(aAchievement.value("defaultvalue").toInt()),
_displayName(aAchievement.value("displayName").toString()), _hidden(aAchievement.value("hidden").toInt()),
_description(aAchievement.value("description").toString()), _icon(aAchievement.value("icon").toString()),
_iconGray(aAchievement.value("icongray").toString()) {

}

SAchievementGlobal::SAchievementGlobal(const SAchievementGlobal &aAchievement): QObject(aAchievement.parent()),
_apiName(aAchievement._apiName), _defaultValue(aAchievement._defaultValue), _displayName(aAchievement._displayName),
_hidden(aAchievement._hidden), _description(aAchievement._description), _icon(aAchievement._icon), _iconGray(aAchievement._iconGray) {

}

SAchievementGlobal &SAchievementGlobal::operator=(const SAchievementGlobal&) {
    return *this;
}
#define SAchievementGlobalEnd }
#define SAchievementPercentageStart {
SAchievementPercentage::SAchievementPercentage(QJsonObject aAchievement, QObject *aParent): QObject(aParent),
_apiName(aAchievement.value("name").toString()), _percent(aAchievement.value("percent").toDouble()) {

}

SAchievementPercentage::SAchievementPercentage(const SAchievementPercentage &aAchievement): QObject(aAchievement.parent()),
_apiName(aAchievement._apiName), _percent(aAchievement._percent) {

}

SAchievementPercentage &SAchievementPercentage::operator=(const SAchievementPercentage &) {
    return *this;
}
#define SAchievementPercentageEnd }
#define SAchievementPlayerStart {
SAchievementPlayer::SAchievementPlayer(QJsonObject aAchievement, QObject *aParent): QObject(aParent),
_apiName(aAchievement.value("apiname").toString()), _achieved(aAchievement.value("achieved").toInt()),
_unlockTime(QDateTime::fromSecsSinceEpoch(aAchievement.value("unlocktime").toInt(), Qt::LocalTime)) {

}

SAchievementPlayer::SAchievementPlayer(const SAchievementPlayer &aAchievement): QObject(aAchievement.parent()),
_apiName(aAchievement._apiName), _achieved(aAchievement._achieved), _unlockTime(aAchievement._unlockTime) {

}

SAchievementPlayer &SAchievementPlayer::operator=(const SAchievementPlayer &) {
    return *this;
}
#define SAchievementPlayerEnd }
#define SAchievementStart {
SAchievement::SAchievement(SAchievementGlobal aGlobal, SAchievementPlayer aPlayer, SAchievementPercentage aPercent, QObject *aParent):
QObject(aParent), _apiName(aGlobal._apiName), _defaultValue(aGlobal._defaultValue), _displayName(aGlobal._displayName), _hidden(aGlobal._hidden),
_description(aGlobal._description), _icon(aGlobal._icon), _iconGray(aGlobal._iconGray), _achieved(aPlayer._achieved), _unlockTime(aPlayer._unlockTime),
_percent(aPercent._percent) {

}

QPixmap SAchievement::getIcon(QString aSavePath) {
    if (_pixmapIcon == QPixmap()) {
        RequestImage *img = new RequestImage(_icon, aSavePath, true, this);
        QEventLoop loop;
        connect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
        _pixmapIcon = img->getPixmap();
        delete img;
    }
    return _pixmapIcon;
}

QPixmap SAchievement::getIconGray(QString aSavePath) {
    if (_pixmapIconGray == QPixmap()) {
        RequestImage *img = new RequestImage(_iconGray, aSavePath, true, this);
        QEventLoop loop;
        connect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
        _pixmapIconGray = img->getPixmap();
        delete img;
    }
    return _pixmapIconGray;
}

SAchievement::SAchievement(const SAchievement &aAchievement): QObject(aAchievement.parent()), _apiName(aAchievement._apiName),
_defaultValue(aAchievement._defaultValue), _displayName(aAchievement._displayName), _hidden(aAchievement._hidden),
_description(aAchievement._description), _icon(aAchievement._icon), _iconGray(aAchievement._iconGray), _achieved(aAchievement._achieved),
_unlockTime(aAchievement._unlockTime), _percent(aAchievement._percent) {

}

SAchievement &SAchievement::operator=(const SAchievement &) {
    return *this;
}

const bool &SAchievement::operator<(const SAchievement &aAchievement){
    static const bool b = _displayName.toLower() < aAchievement._displayName.toLower();
    return b;
}
#define SAchievementEnd }
#define SingleAchievementsEnd }
#define MultipleAchievements {
#define SAchievementsGlobalStart {
SAchievementsGlobal::SAchievementsGlobal(QString aAppid, bool aParallel, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()), _appid(aAppid) {
    connect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsGlobal::onLoad);
    Load(aAppid);
    if (!aParallel) {
        QEventLoop loop;
        connect(_manager,    &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
     }
}

SAchievementsGlobal::SAchievementsGlobal(QJsonDocument aAchievements, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    connect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsGlobal::onLoad);
    set(aAchievements);
}

SAchievementsGlobal::SAchievementsGlobal(QObject *parent): QObject(parent), _manager(new QNetworkAccessManager()) {
    connect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsGlobal::onLoad);
}

SAchievementsGlobal::~SAchievementsGlobal() {
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::onLoad);
    delete _manager;
    qDebug()<< "Achievements global deleted";
}

void SAchievementsGlobal::Load(QString aAppid) {
    _appid = std::move(aAppid);
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key=" + Settings::getKey() +
                                                                                                  "&appid=" + _appid +
                                                                                                  "&l=" + tr("russian")));
}

void SAchievementsGlobal::onLoad(QNetworkReply *aReply) {
    set(QJsonDocument::fromJson(aReply->readAll()));
    aReply->deleteLater();
    emit s_finished(this);
}

void SAchievementsGlobal::set(QJsonDocument aAchievements) {
    clear();
    QJsonArray gameAchievements = aAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray();
    if(gameAchievements.size() > 0) {
        _gameName = aAchievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion = aAchievements.object().value("game").toObject().value("gameVersion").toString();
        for(int i = 0; i < gameAchievements.size(); i++) {
            _achievements.append(SAchievementGlobal(gameAchievements.at(i).toObject()));
        }
        _status = StatusValue::success;
    }
    else {
        _status = StatusValue::error;
        _error = "game is not exist";
    }
}

void SAchievementsGlobal::remove(int aIndex) {
    _achievements.removeAt(aIndex);
}

QString SAchievementsGlobal::getAppid() {
    return _appid;
}

StatusValue SAchievementsGlobal::getStatus() {
    return _status;
}

QString SAchievementsGlobal::getError() {
    return _error;
}

QString SAchievementsGlobal::getGamename() {
    return _gameName;
}

QString SAchievementsGlobal::getGameversion() {
    return _gameVersion;
}

int SAchievementsGlobal::getCount() {
    return _achievements.size();
}

void SAchievementsGlobal::update() {
    Load(_appid);
}

void SAchievementsGlobal::clear() {
    _achievements.clear();
    _status = StatusValue::none;
}

SAchievementsGlobal::SAchievementsGlobal(const SAchievementsGlobal &aAchievements): QObject(aAchievements.parent()),
_manager(new QNetworkAccessManager), _achievements(aAchievements._achievements), _status(aAchievements._status),
_error(aAchievements._error), _appid(aAchievements._appid), _gameName(aAchievements._gameName), _gameVersion(aAchievements._gameVersion) {

}

SAchievementsGlobal &SAchievementsGlobal::operator=(const SAchievementsGlobal &aAchievements){
    delete _manager;
    _achievements = aAchievements._achievements;
    _appid = aAchievements._appid;
    _gameName = aAchievements._gameName;
    _gameVersion = aAchievements._gameVersion;
    _status = aAchievements._status;
    _error = aAchievements._error;
    _manager = new QNetworkAccessManager;
    return *this;
}

SAchievementGlobal &SAchievementsGlobal::operator[](const int &aIndex) {
    return _achievements[aIndex];
}
#define SAchievementsGlobalEnd }
#define SAchievementsPercentageStart {
SAchievementsPercentage::SAchievementsPercentage(QString aAppid, bool aParallel, QObject *aParent): QObject(aParent),
_manager(new QNetworkAccessManager()) {
    connect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsPercentage::onLoad);
    Load(aAppid);
    if (!aParallel) {
        QEventLoop loop;
        connect(_manager,    &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
     }
}

SAchievementsPercentage::SAchievementsPercentage(QJsonDocument aAchievements, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    connect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsPercentage::onLoad);
    set(aAchievements);
}

SAchievementsPercentage::SAchievementsPercentage(QObject *parent): QObject(parent), _manager(new QNetworkAccessManager()) {
    connect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsPercentage::onLoad);
}

SAchievementsPercentage::~SAchievementsPercentage() {
    disconnect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsPercentage::onLoad);
    delete _manager;
    qDebug()<< "Achievements percentage deleted"<<_appid;
}

void SAchievementsPercentage::Load(QString aAppid) {
    _appid = std::move(aAppid);
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v2/?key=" + Settings::getKey() +
                                                                                                                        "&gameid=" + _appid));
}

void SAchievementsPercentage::onLoad(QNetworkReply *aReply) {
    set(QJsonDocument::fromJson(aReply->readAll()));
    aReply->deleteLater();
    emit s_finished(this);
}

void SAchievementsPercentage::set(QJsonDocument aAchievements) {
    clear();
    QJsonArray achievementsArray = aAchievements.object().value("achievementpercentages").toObject().value("achievements").toArray();
    if (achievementsArray.size() > 0) {
        for (auto achievement: achievementsArray) {
            _achievements.append(SAchievementPercentage(achievement.toObject()));
        }
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = "game is not exist";
    }
}

void SAchievementsPercentage::remove(int index) {
    _achievements.removeAt(index);
}

QString SAchievementsPercentage::getAppid() {
    return _appid;
}

int SAchievementsPercentage::getCount() {
    return _achievements.size();
}

StatusValue SAchievementsPercentage::getStatus() {
    return _status;
}

QString SAchievementsPercentage::getError() {
    return _error;
}

void SAchievementsPercentage::update() {
    Load(_appid);
}

void SAchievementsPercentage::clear() {
    _achievements.clear();
    _status = StatusValue::none;
}

SAchievementsPercentage::SAchievementsPercentage(const SAchievementsPercentage &aAchievements): QObject(aAchievements.parent()),
_manager(new QNetworkAccessManager()), _achievements(aAchievements._achievements), _error(aAchievements._error),
_status(aAchievements._status), _appid(aAchievements._appid) {

}

SAchievementsPercentage &SAchievementsPercentage::operator=(const SAchievementsPercentage &aAchievements) {
    delete _manager;
    _achievements = aAchievements._achievements;
    _appid = aAchievements._appid;
    _status = aAchievements._status;
    _error = aAchievements._error;
    _manager = new QNetworkAccessManager;
    return *this;
}

SAchievementPercentage &SAchievementsPercentage::operator[](const int &aIndex) {
    return _achievements[aIndex];
}
#define SAchievementsPercentageEnd }
#define SAchievementsPlayerStart {
SAchievementsPlayer::SAchievementsPlayer(QString aAppid, QString aId, bool aParallel, QObject *aParent): QObject(aParent),
_manager(new QNetworkAccessManager()) {
    connect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsPlayer::onLoaded);
    Load(aAppid, aId);
    if (!aParallel) {
        QEventLoop loop;
        connect(_manager,    &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
     }
}

SAchievementsPlayer::SAchievementsPlayer(QJsonDocument aAchievements, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    connect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsPlayer::onLoaded);
    set(aAchievements);
}

SAchievementsPlayer::SAchievementsPlayer(QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    connect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsPlayer::onLoaded);
}

SAchievementsPlayer::~SAchievementsPlayer() {
    disconnect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsPlayer::onLoaded);
    delete _manager;
    qDebug()<<"Achievements player deleted"<<_appid<<_id;
}

void SAchievementsPlayer::Load(QString aAppid, QString aId) {
    _appid = std::move(aAppid);
    _id = std::move(aId);
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key=" + Settings::getKey() +
                                                                                                          "&appid=" + _appid +
                                                                                                          "&steamid=" + _id));
}

void SAchievementsPlayer::onLoaded(QNetworkReply *aReply) {
    set(QJsonDocument::fromJson(aReply->readAll()));
    aReply->deleteLater();
    emit s_finished(this);
}

void SAchievementsPlayer::set(QJsonDocument aAchievements) {
    clear();
    QJsonArray achievementsArray = aAchievements.object().value("playerstats").toObject().value("achievements").toArray();
    if (achievementsArray.size() > 0) {
        //_appid = aAchievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName = aAchievements.object().value("playerstats").toObject().value("gameName").toString();
        for (auto achievement: achievementsArray) {
            if (achievement.toObject().value("achieved").toInt() == 0) {
                _notReached++;
            } else {
                _reached++;
            }
            _achievements.append(SAchievementPlayer(achievement.toObject()));
        }
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = "profile is not exist";
    }
}

int SAchievementsPlayer::getReached() {
    return _reached;
}

int SAchievementsPlayer::getNotReached() {
    return _notReached;
}

void SAchievementsPlayer::remove(int aIndex) {
    _achievements.removeAt(aIndex);
}

QString SAchievementsPlayer::getAppid() {
    return _appid;
}

StatusValue SAchievementsPlayer::getStatus() {
    return _status;
}

QString SAchievementsPlayer::getError() {
    return _error;
}

QString SAchievementsPlayer::getGameName() {
    return _gameName;
}

int SAchievementsPlayer::getCount() {
    return _achievements.size();
}

void SAchievementsPlayer::update() {
    clear();
    Load(_appid, _id);
}

void SAchievementsPlayer::clear() {
    _achievements.clear();
    _reached = 0;
    _notReached = 0;
    _status = StatusValue::none;
}

SAchievementPlayer SAchievementsPlayer::at(const int &aIndex) {
    return _achievements[aIndex];
}

SAchievementsPlayer::SAchievementsPlayer(const SAchievementsPlayer &aAchievements): QObject(aAchievements.parent()),
_index(aAchievements._index), _manager(new QNetworkAccessManager()), _achievements(aAchievements._achievements),
_status(aAchievements._status), _error(aAchievements._error), _id(aAchievements._id), _appid(aAchievements._appid),
_gameName(aAchievements._gameName) {

}

SAchievementsPlayer &SAchievementsPlayer::operator=(const SAchievementsPlayer &aAchievements) {
    delete _manager;
    _achievements = aAchievements._achievements;
    _appid = aAchievements._appid;
    _id = aAchievements._id;
    _gameName = aAchievements._gameName;
    _status = aAchievements._status;
    _error = aAchievements._error;
    _index = aAchievements._index;
    _manager = new QNetworkAccessManager;
    return *this;
}

SAchievementPlayer &SAchievementsPlayer::operator[](const int &aIndex) {
    return _achievements[aIndex];
}
#define SAchievementsPlayerEnd }
#define SAchievementsStart {
SAchievements::SAchievements(QString aAppid, QString aId, QObject *aParent): QObject(aParent) {
    Load(aAppid, aId);
}

SAchievements::SAchievements(SAchievementsGlobal &aGlobal, SAchievementsPlayer &aPlayer, SAchievementsPercentage &aPercent, QObject *aParent): QObject(aParent),
_global(aGlobal), _player(aPlayer), _percent(aPercent), _statusGlobal(StatusValue::success), _statusPlayer(StatusValue::success), _statusPercent(StatusValue::success) {
    qDebug()<<"Set All Achievements data in constructor";
    setFinish();
}

SAchievements::SAchievements(SAchievementsGlobal &aGlobal, QObject *aParent): QObject(aParent), _global(aGlobal), _statusGlobal(StatusValue::success) {

}

SAchievements::SAchievements(SAchievementsPlayer &aPlayer, QObject *aParent): QObject(aParent), _player(aPlayer), _statusPlayer(StatusValue::success) {

}

SAchievements::SAchievements(SAchievementsPercentage aPercent, QObject *aParent): QObject(aParent), _percent(aPercent), _statusPercent(StatusValue::success) {

}

SAchievements::SAchievements(QObject *aParent): QObject(aParent) {

}

SAchievements::~SAchievements() {
    qDebug()<<"Achievements deleted"<<_appid<<_id;
}

void SAchievements::Load(QString aAppid, QString aId) {
    _appid = std::move(aAppid);
    _id = std::move(aId);
    clear();
    SAchievementsGlobal *global      = new SAchievementsGlobal(aAppid);
    SAchievementsPlayer *player      = new SAchievementsPlayer(aAppid, aId);
    SAchievementsPercentage *percent = new SAchievementsPercentage(aAppid);
    connect(global,  SIGNAL(s_finished(SAchievementsGlobal*)),     this, SLOT(set(SAchievementsGlobal*)));
    connect(player,  SIGNAL(s_finished(SAchievementsPlayer*)),     this, SLOT(set(SAchievementsPlayer*)));
    connect(percent, SIGNAL(s_finished(SAchievementsPercentage*)), this, SLOT(set(SAchievementsPercentage*)));
}

void SAchievements::set(SAchievementsGlobal &aGlobal, SAchievementsPlayer &aPlayer, SAchievementsPercentage &aPercent) {
    set(&aPercent);
    set(&aGlobal);
    set(&aPlayer);
}

void SAchievements::set(SAchievementsPlayer *aPlayer) {
    if (aPlayer->getCount() > 0) {
        qDebug()<<"Player set"<< aPlayer->getCount();
        _player = std::move(*aPlayer);
        aPlayer->deleteLater();
        //_appid = _player.getAppid();
        _statusPlayer = StatusValue::success;
        setFinish();
    } else {
        qDebug()<<"Player error"<< aPlayer->getCount();
        _statusPlayer = StatusValue::error;
    }
}

void SAchievements::set(SAchievementsGlobal *aGlobal) {
    if (aGlobal->getCount() > 0) {
        qDebug()<<"Global set"<< aGlobal->getCount();
        _global = std::move(*aGlobal);
        aGlobal->deleteLater();
        //_appid = _global.getAppid();
        _statusGlobal = StatusValue::success;
        setFinish();
    } else {
        qDebug()<<"Global error"<< aGlobal->getCount();
        _statusGlobal = StatusValue::error;
    }
}

void SAchievements::set(SAchievementsPercentage *aPercent) {
    if (aPercent->getCount() > 0) {
        qDebug()<<"Percent set"<< aPercent->getCount();
        _percent = std::move(*aPercent);
        aPercent->deleteLater();
        //_appid = _percent.getAppid();
        _statusPercent = StatusValue::success;
        setFinish();
    } else {
        qDebug()<<"Percent error"<< aPercent->getCount();
        _statusPercent = StatusValue::error;
    }
}

void SAchievements::setFinish() {
    if(_statusGlobal == StatusValue::success && _statusPlayer == StatusValue::success && _statusPercent == StatusValue::success) {
        qDebug()<<"Finish set";
        clear();
        for (const auto &percent: _percent) {
            int globalIndex = 0;
            for (const auto &player: _player) {
                const auto &global = std::move(_global[globalIndex++]);
                if (percent._apiName == player._apiName) {
                    _finish.push_back(SAchievement(global, player, percent));
                    break;
                }
            }
        }
        _statusFinish = StatusValue::success;
        emit s_finished();
    } else {
        qDebug()<<"Finish error";
        _statusFinish = StatusValue::error;
    }
}

StatusValue SAchievements::getStatus() {
    return _statusFinish;
}

QString SAchievements::getError() {
    return _errorFinish;
}

QString SAchievements::getAppid() {
    return _appid;
}

QString SAchievements::getGameName() {
    return _gameName;
}

QString SAchievements::getGameVersion() {
    return _gameVersion;
}

int SAchievements::getCount() {
    return _finish.size();
}

void SAchievements::update() {
    //_finish.clear();
    _statusGlobal = StatusValue::none;
    _statusPlayer = StatusValue::none;
    _statusPercent = StatusValue::none;
    _statusFinish = StatusValue::none;
    Load(_appid, _id);
}

void SAchievements::clear(){
    _finish.clear();
    _statusFinish = StatusValue::none;
}

void SAchievements::sort(){
    //Переделать нормально
    //std::list<SAchievement> list = _finish.toList().toStdList();
    std::list<SAchievement> list(_finish.begin(), _finish.end());
    list.sort();
    _finish = QList<SAchievement>(list.begin(), list.end());
    //_finish=QVector<SAchievement>::fromList(QList<SAchievement>::fromStdList(list));
}

SAchievements::SAchievements(const SAchievements &aAchievements): QObject(aAchievements.parent()), _id(aAchievements._id),
_appid(aAchievements._appid), _global(aAchievements._global), _player(aAchievements._player), _percent(aAchievements._percent),
_finish(aAchievements._finish), _statusGlobal(aAchievements._statusGlobal), _statusPlayer(aAchievements._statusPlayer),
_statusPercent(aAchievements._statusPercent), _statusFinish(aAchievements._statusFinish), _errorGlobal(aAchievements._errorGlobal),
_errorPlayer(aAchievements._errorPlayer), _errorPercent(aAchievements._errorPercent), _errorFinish(aAchievements._errorFinish),
_gameName(aAchievements._gameName), _gameVersion(aAchievements._gameVersion) {

}

SAchievements &SAchievements::operator=(const SAchievements &aAchievements){
    _finish = aAchievements._finish;
    _global = aAchievements._global;
    _player = aAchievements._player;
    _percent = aAchievements._percent;
    _statusGlobal = aAchievements._statusGlobal;
    _statusPlayer = aAchievements._statusPlayer;
    _statusPercent = aAchievements._statusPercent;
    _statusFinish = aAchievements._statusFinish;
    _errorGlobal = aAchievements._errorGlobal;
    _errorPlayer = aAchievements._errorPlayer;
    _errorPercent = aAchievements._errorPercent;
    _errorFinish = aAchievements._errorFinish;
    _id = aAchievements._id;
    _appid = aAchievements._appid;
    _gameName = aAchievements._gameName;
    _gameVersion = aAchievements._gameVersion;
    return *this;
}

SAchievement &SAchievements::operator[](const int &aIndex) {
    return _finish[aIndex];
}
#define SAchievementsEnd }
#define MultipleAchievementsEnd }
