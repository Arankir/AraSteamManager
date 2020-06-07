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

SAchievementGlobal &SAchievementGlobal::operator=(const SAchievementGlobal &) {
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
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::onLoad);
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+Settings::getKey()+"&appid="+aAppid+"&l="+tr("russian")));
    if (!aParallel) {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
     }
}

SAchievementsGlobal::SAchievementsGlobal(QJsonDocument aAchievements, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    set(aAchievements);
}

SAchievementsGlobal::~SAchievementsGlobal() {
    delete _manager;
}

void SAchievementsGlobal::set(QString aAppid) {
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::onLoad);
    _appid = std::move(aAppid);
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+Settings::getKey()+"&appid="+aAppid+"&l="+tr("russian")));
}

void SAchievementsGlobal::set(QJsonDocument aAchievements) {
    clear();
    QJsonArray gameAchievements = aAchievements.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray();
    if(gameAchievements.size() > 0) {
        _gameName = aAchievements.object().value("game").toObject().value("gameName").toString();
        _gameVersion = aAchievements.object().value("game").toObject().value("gameVersion").toString();
        for(int i = 0; i < gameAchievements.size(); i++) {
            _achievements.append(std::move(SAchievementGlobal(gameAchievements.at(i).toObject())));
        }
        _status = std::move(StatusValue::success);
    }
    else {
        _status = std::move(StatusValue::error);
        _error = std::move("game is not exist");
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

void SAchievementsGlobal::onLoad(QNetworkReply *aReply) {
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsGlobal::onLoad);
    set(QJsonDocument::fromJson(aReply->readAll()));
    aReply->deleteLater();
    emit s_finished(*this);
    emit s_finished();
}

void SAchievementsGlobal::update() {
    set(_appid);
}

void SAchievementsGlobal::clear() {
    _achievements.clear();
    _status = std::move(StatusValue::none);
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
_manager(new QNetworkAccessManager()), _appid(aAppid) {
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::onLoad);
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+Settings::getKey()+"&gameid="+aAppid));
    if (!aParallel) {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
     }
}

SAchievementsPercentage::SAchievementsPercentage(QJsonDocument aAchievements, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    set(aAchievements);
}

SAchievementsPercentage::SAchievementsPercentage(QObject *parent): QObject(parent), _manager(new QNetworkAccessManager()) {

}

SAchievementsPercentage::~SAchievementsPercentage() {
    delete _manager;
}

void SAchievementsPercentage::set(QString aAppid) {
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::onLoad);
    _appid = std::move(aAppid);
    _manager->get(QNetworkRequest("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+Settings::getKey()+"&gameid="+aAppid));
}

void SAchievementsPercentage::set(QJsonDocument aAchievements){
    clear();
    QJsonArray achievementsArray = aAchievements.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray();
    if (achievementsArray.size() > 0) {
        for (auto achievement: achievementsArray) {
            _achievements.append(std::move(SAchievementPercentage(achievement.toObject())));
        }
        _status = std::move(StatusValue::success);
    } else {
        _status = std::move(StatusValue::error);
        _error = std::move("game is not exist");
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

void SAchievementsPercentage::onLoad(QNetworkReply *aReply){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPercentage::onLoad);
    set(QJsonDocument::fromJson(aReply->readAll()));
    aReply->deleteLater();
    emit s_finished(*this);
    emit s_finished();
}

void SAchievementsPercentage::update(){
    set(_appid);
}

void SAchievementsPercentage::clear(){
    _achievements.clear();
    _status = std::move(StatusValue::none);
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
_manager(new QNetworkAccessManager()), _id(aId), _appid(aAppid) {
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+Settings::getKey()+"&appid="+aAppid+"&steamid="+aId));
    if (!aParallel) {
        QEventLoop loop;
        connect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
        loop.exec();
        disconnect(_manager,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
     }
}

SAchievementsPlayer::SAchievementsPlayer(QJsonDocument aAchievements, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {
    set(aAchievements);
}

SAchievementsPlayer::SAchievementsPlayer(QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager()) {

}

SAchievementsPlayer::~SAchievementsPlayer() {
    delete _manager;
}

void SAchievementsPlayer::set(QString aAppid, QString aId) {
    connect(_manager,&QNetworkAccessManager::finished,this,&SAchievementsPlayer::Load);
    _appid = std::move(aAppid);
    _id = std::move(aId);
    _manager->get(QNetworkRequest("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+Settings::getKey()+"&appid="+aAppid+"&steamid="+aId));
}

void SAchievementsPlayer::set(QJsonDocument aAchievements) {
    clear();
    QJsonArray achievementsArray = aAchievements.object().value("playerstats").toObject().value("achievements").toArray();
    if (achievementsArray.size() > 0){
        _appid = aAchievements.object().value("playerstats").toObject().value("steamID").toString();
        _gameName = aAchievements.object().value("playerstats").toObject().value("gameName").toString();
        for (auto achievement: achievementsArray) {
            _achievements.append(std::move(SAchievementPlayer(achievement.toObject())));
        }
        _status = std::move(StatusValue::success);
    } else {
        _status = std::move(StatusValue::error);
        _error = std::move("profile is not exist");
    }
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

void SAchievementsPlayer::Load(QNetworkReply *aReply) {
    disconnect(_manager, &QNetworkAccessManager::finished, this, &SAchievementsPlayer::Load);
    set(QJsonDocument::fromJson(aReply->readAll()));
    aReply->deleteLater();
    emit s_finished(*this);
    emit s_finished();
}

void SAchievementsPlayer::update() {
    set(_appid, _id);
}

void SAchievementsPlayer::clear() {
    _achievements.clear();
    _status = std::move(StatusValue::none);
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
SAchievements::SAchievements(QString aAppid, QString aId, QObject *aParent): QObject(aParent), _id(aId), _appid(aAppid) {
    SAchievementsGlobal *global = new SAchievementsGlobal(aAppid);
    SAchievementsPlayer *player = new SAchievementsPlayer(aAppid, aId);
    SAchievementsPercentage *percent = new SAchievementsPercentage(aAppid);
    connect(global, SIGNAL(s_finished(SAchievementsGlobal)), this, SLOT(set(SAchievementsGlobal)));
    connect(player, SIGNAL(s_finished(SAchievementsPlayer)), this, SLOT(set(SAchievementsPlayer)));
    connect(percent, SIGNAL(s_finished(SAchievementsPercentage)), this, SLOT(set(SAchievementsPercentage)));
}

SAchievements::SAchievements(SAchievementsGlobal &aGlobal, SAchievementsPlayer &aPlayer, SAchievementsPercentage &aPercent, QObject *aParent): QObject(aParent),
_global(aGlobal), _player(aPlayer), _percent(aPercent), _statusGlobal(StatusValue::success), _statusPlayer(StatusValue::success), _statusPercent(StatusValue::success) {
    qDebug()<<"Set All Achievements data";
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

}

void SAchievements::set(QString aAppid, QString aId) {
    _appid = std::move(aAppid);
    _id = std::move(aId);
    SAchievementsGlobal *global = new SAchievementsGlobal(aAppid);
    SAchievementsPlayer *player = new SAchievementsPlayer(aAppid, aId);
    SAchievementsPercentage *percent = new SAchievementsPercentage(aAppid);
    connect(global, SIGNAL(s_finished(SAchievementsGlobal)), this, SLOT(set(SAchievementsGlobal)));
    connect(player, SIGNAL(s_finished(SAchievementsPlayer)), this, SLOT(set(SAchievementsPlayer)));
    connect(percent, SIGNAL(s_finished(SAchievementsPercentage)), this, SLOT(set(SAchievementsPercentage)));
}

void SAchievements::set(SAchievementsGlobal &aGlobal, SAchievementsPlayer &aPlayer, SAchievementsPercentage &aPercent) {
    set(aPercent);
    set(aGlobal);
    set(aPlayer);
}

void SAchievements::set(SAchievementsPlayer aPlayer) {
    qDebug()<<"Player set";
    _player = std::move(aPlayer);
    _statusPlayer = std::move(StatusValue::success);
    if(_statusGlobal == StatusValue::success && _statusPlayer == StatusValue::success && _statusPercent == StatusValue::success) {
        setFinish();
    }
}

void SAchievements::set(SAchievementsGlobal aGlobal) {
    qDebug()<<"Global set";
    _global = std::move(aGlobal);
    _statusGlobal = std::move(StatusValue::success);
    if(_statusGlobal == StatusValue::success && _statusPlayer == StatusValue::success && _statusPercent == StatusValue::success) {
        setFinish();
    }
}

void SAchievements::set(SAchievementsPercentage aPercent) {
    qDebug()<<"Percent set";
    _percent = std::move(aPercent);
    _statusPercent = std::move(StatusValue::success);
    if(_statusGlobal == StatusValue::success && _statusPlayer == StatusValue::success && _statusPercent == StatusValue::success) {
        setFinish();
    }
}

void SAchievements::setFinish() {
    qDebug()<<"Finish set";
    clear();
    for (const auto &percent: _percent) {
        int globalIndex = std::move(0);
        for (const auto &player: _player) {
            const auto &global = std::move(_global[globalIndex++]);
            if (percent._apiName == player._apiName) {
                _finish.push_back(std::move(SAchievement(global,player,percent)));
                break;
            }
        }
    }
    _statusFinish = std::move(StatusValue::success);
    emit s_finished();
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
    _statusGlobal = std::move(StatusValue::none);
    _statusPlayer = std::move(StatusValue::none);
    _statusPercent = std::move(StatusValue::none);
    _statusFinish = std::move(StatusValue::none);
    SAchievementsGlobal *global = new SAchievementsGlobal(_appid);
    SAchievementsPlayer *player = new SAchievementsPlayer(_appid, _id);
    SAchievementsPercentage *percent = new SAchievementsPercentage(_appid);
    connect(global, SIGNAL(s_finished(SAchievementsGlobal)), this, SLOT(set(SAchievementsGlobal)));
    connect(player, SIGNAL(s_finished(SAchievementsPlayer)), this, SLOT(set(SAchievementsPlayer)));
    connect(percent, SIGNAL(s_finished(SAchievementsPercentage)), this, SLOT(set(SAchievementsPercentage)));
}

void SAchievements::clear(){
    _finish.clear();
    _statusFinish = std::move(StatusValue::none);
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
