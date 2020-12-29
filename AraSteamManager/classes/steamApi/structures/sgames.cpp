#include "sgames.h"

#define SGameStart {
SGame::SGame(const QJsonObject &game, QObject *parent): QObject(parent) {
    fromJson(game);
}

SGame &SGame::operator=(const SGame &aGame) {
    _appID                          = aGame._appID;
    _name                           = aGame._name;
    _playtime_2weeks                = aGame._playtime_2weeks;
    _playtime_forever               = aGame._playtime_forever;
    _has_community_visible_stats    = aGame._has_community_visible_stats;
    _img_icon_url                   = aGame._img_icon_url;
    _img_logo_url                   = aGame._img_logo_url;
    _pixmapIcon                     = aGame._pixmapIcon;
    _pixmapLogo                     = aGame._pixmapLogo;
    return *this;
}

bool SGame::operator<(const SGame &aGame) {
    //    qDebug() << _name.compare(aGame._name, Qt::CaseInsensitive);
    return (_name < aGame._name);
}

QPixmap SGame::pixmapIcon() {
    return loadPixmap(_pixmapIcon, Sapi::gameImageUrl(QString::number(_appID), _img_icon_url), Paths::imagesGames(_img_icon_url), QSize(32, 32));
}

QPixmap SGame::pixmapLogo() {
    return loadPixmap(_pixmapLogo, Sapi::gameImageUrl(QString::number(_appID), _img_logo_url), Paths::imagesGames(_img_logo_url), QSize(184, 69));
}

void SGame::fromJson(const QJsonValue &aValue) {
    _appID                          = aValue.toObject().value("appid").toInt();
    _name                           = aValue.toObject().value("name").toString();
    _playtime_2weeks                = aValue.toObject().value("playtime_2weeks").toInt();
    _playtime_forever               = aValue.toObject().value("playtime_forever").toInt();
    _has_community_visible_stats    = aValue.toObject().value("has_community_visible_stats").toBool();
    _img_icon_url                   = aValue.toObject().value("img_icon_url").toString();
    _img_logo_url                   = aValue.toObject().value("img_logo_url").toString();
}
#define SGameEnd }
#define SGamesStart {
SGames::SGames(const QString &aId, int aFreeGames, int aGameInfo, bool aParallel, QObject *aParent): Sapi(aParent) {
    load(aId, aFreeGames, aGameInfo, aParallel);
}

SGames &SGames::operator=(const SGames &aGames) {
    Sapi::operator=(aGames);
    _games      = aGames._games;
    _id         = aGames._id;
    _freeGames = aGames._freeGames;
    _gameInfo  = aGames._gameInfo;
    return *this;
}

SGames &SGames::load(const QString &aId, int aFreeGames, int aGameInfo, bool aParallel) {
    _id         = aId;
    _freeGames = aFreeGames;
    _gameInfo  = aGameInfo;
    _request.get(gameUrl(_freeGames, _gameInfo, _id), aParallel);
    return *this;
}

void SGames::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.reply()).object().value("response").toObject().value("games"));
    emit s_finished(this);
    emit s_finished();
}

void SGames::fromJson(const QJsonValue &aValue) {
    clear();
    QJsonArray gamesArray = aValue.toArray();
    if (gamesArray.size() > 0) {
        for (const auto &game: gamesArray) {
            _games.append(std::move(SGame(game.toObject())));
        }
        _status = StatusValue::success;
    } else {
        _status = StatusValue::error;
        _error = tr("game is not exist");
    }
}

SGames &SGames::update(bool aParallel) {
    load(_id, _freeGames, _gameInfo, aParallel);
    return *this;
}

SGames &SGames::clear() {
    _games.clear();
    return *this;
}

SGames &SGames::sort() {
    //Переделать нормально
//    std::sort(_games.begin(), _games.end(), [](const SGame &s1, const SGame &s2)-> const bool {
//                            return s1._name.compare(s2._name, Qt::CaseInsensitive) < 0;
//                        });
    std::list<SGame> list(_games.begin(), _games.end());
    list.sort(  [](const SGame &s1, const SGame &s2)-> const bool {
                    return s1.name().compare(s2.name(), Qt::CaseInsensitive) < 0;
                });
    _games = QList<SGame>(list.begin(), list.end());
    return *this;
}
#define SGamesEnd }

SGamePlayers::SGamePlayers(const QJsonObject &game, QObject *parent): Sapi(parent) {
    fromJson(game);
}

SGamePlayers::SGamePlayers(const int &appId, QObject *parent): Sapi(parent) {
    load(appId, false);
}

SGamePlayers &SGamePlayers::operator=(const SGamePlayers &game) {
    _appID = game._appID;
    _numberPlayers = game._numberPlayers;
    return *this;
}

SGamePlayers &SGamePlayers::load(int aAppId, bool aParalell) {
    _appID = aAppId;
    _request.get(numberPlayersUrl(QString::number(_appID)), aParalell);
    return *this;
}

void SGamePlayers::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.reply()).object());
}

void SGamePlayers::fromJson(const QJsonValue &aValue) {
    double playersCount = aValue.toObject().value("response").toObject().value("player_count").toDouble();
    _numberPlayers = playersCount;
}
