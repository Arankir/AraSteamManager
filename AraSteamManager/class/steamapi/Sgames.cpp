#include "Sgames.h"

#define SGameStart {
SGame::SGame(QJsonObject aGame, QObject *aParent): QObject(aParent), _appID(aGame.value("appid").toInt()), _name(aGame.value("name").toString()),
_playtime_2weeks(aGame.value("playtime_2weeks").toInt()), _playtime_forever(aGame.value("playtime_forever").toInt()), _img_icon_url(aGame.value("img_icon_url").toString()),
_img_logo_url(aGame.value("img_logo_url").toString()), _has_community_visible_stats(aGame.value("has_community_visible_stats").toBool()) {

}

const QString SGame::getNumberPlayers(bool aHardReload){
    if (_numberPlayers == "" || aHardReload) {
        QNetworkAccessManager manager;
        QEventLoop loop;
        QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        QNetworkReply &replyNumberOfPlayers = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key="+Settings::getKey()+"&appid="+QString::number(_appID))));
        loop.exec();
        double playersCount = QJsonDocument::fromJson(replyNumberOfPlayers.readAll()).object().value("response").toObject().value("player_count").toDouble();
        _numberPlayers = QString::number(playersCount);
    }
    return _numberPlayers;
}

SGame::SGame(const SGame &aGame): QObject(aGame.parent()), _appID(aGame._appID), _name(aGame._name), _playtime_2weeks(aGame._playtime_2weeks),
_playtime_forever(aGame._playtime_forever), _img_icon_url(aGame._img_icon_url), _img_logo_url(aGame._img_logo_url),
_has_community_visible_stats(aGame._has_community_visible_stats) {

}

SGame &SGame::operator=(const SGame &aGame) {
    _numberPlayers=aGame._numberPlayers;
    return *this;
}

const bool &SGame::operator<(const SGame &aGame) {
    static const bool b = _name.toLower() < aGame._name.toLower();
    return b;
}
#define SGameEnd }
#define SGamesStart {
SGames::SGames(QString aId, bool aFreeGames, bool aGameInfo, bool aParallel, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager), _id(aId) {
    set(aId, aFreeGames, aGameInfo, aParallel);
}
SGames::SGames(QJsonDocument aGames, QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager) {
    set(aGames);
}

SGames::SGames(QObject *aParent): QObject(aParent), _manager(new QNetworkAccessManager) {

}

SGames::~SGames() {
    delete _manager;
}

void SGames::set(QString aId, bool aFreeGames, bool aGameInfo, bool aParallel) {
    _id = std::move(aId);
    QString request = QString("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=%1%2%3&format=json&steamid=%4").arg(
                Settings::getKey(),
                aFreeGames ? "&include_played_free_games=1" : "",
                aGameInfo ? "&include_appinfo=1" : "",
                _id);
    if (aParallel) {
        connect(_manager, &QNetworkAccessManager::finished, this, &SGames::onLoad);
        _manager->get(QNetworkRequest(request));
    } else {
        QEventLoop loop;
        connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        QNetworkReply *reply = _manager->get(QNetworkRequest(request));
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        set(QJsonDocument::fromJson(reply->readAll()));
        delete reply;
        emit s_finished(this);
        emit s_finished();
    }
}

void SGames::set(QJsonDocument aGames){
    clear();
    QJsonArray gamesArray = aGames.object().value("response").toObject().value("games").toArray();
    if (gamesArray.size() > 0) {
        for (auto game: gamesArray) {
            _games.append(std::move(SGame(game.toObject())));
        }
        _status = std::move(StatusValue::success);
    } else {
        _status = std::move(StatusValue::error);
        _error = std::move("profile is not exist");
    }
}

int SGames::getAppid(int aIndex) {
    return _games[aIndex]._appID;
}

QString SGames::getID() {
    return _id;
}

StatusValue SGames::getStatus() {
    return _status;
}

QString SGames::getError() {
    return _error;
}

int SGames::getCount() {
    return _games.size();
}

void SGames::onLoad(QNetworkReply *aReply) {
    disconnect(_manager, &QNetworkAccessManager::finished, this, &SGames::onLoad);
    set(QJsonDocument::fromJson(aReply->readAll()));
    aReply->deleteLater();
    emit s_finished(this);
    emit s_finished();
}
void SGames::update(bool aParallel){
    set(_id, _free_games, _game_info, aParallel);
}
void SGames::clear() {
    _games.clear();
}
void SGames::sort() {
    //Переделать нормально
    std::list<SGame> list(_games.begin(), _games.end());
    list.sort([](const SGame &s1, const SGame &s2)-> const bool {
        return QString::compare(s1._name.toLower(), s2._name.toLower()) < 0;
    });
    _games = QList<SGame>(list.begin(), list.end());
    //_games=QVector<SGame>::fromList(QList<SGame>::fromStdList(list));
}

SGames::SGames(const SGames &aGames): QObject(aGames.parent()), _manager(new QNetworkAccessManager), _games(aGames._games),
_status(aGames._status), _error(aGames._error), _id(aGames._id), _free_games(aGames._free_games), _game_info(aGames._game_info) {

}

SGames & SGames::operator=(const SGames & aGames) {
    delete _manager;
    _games = aGames._games;
    _status = aGames._status;
    _error = aGames._error;
    _id = aGames._id;
    _free_games = aGames._free_games;
    _game_info = aGames._game_info;
    _manager = new QNetworkAccessManager;
    return *this;
}

SGame &SGames::operator[](const int &aIndex) {
    return _games[aIndex];
}
#define SGamesEnd }
