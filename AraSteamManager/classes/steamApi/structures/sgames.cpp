#include "sgames.h"


#define SGameStart {
SGame::SGame(const QJsonObject &game, const QString &userId, QObject *parent): Sapi(parent), _userId(userId) {
    fromJson(game);
}

QJsonObject SGame::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["appid"] = _appID;
    obj["name"] = _name;
    obj["playtime_2weeks"] = _playtime_2weeks;
    obj["playtime_forever"] = _playtime_forever;
    obj["has_community_visible_stats"] = _has_community_visible_stats;
    obj["img_icon_url"] = _img_icon_url;
    obj["img_logo_url"] = _img_logo_url;
    return obj;
}

SGames onLoad(const QByteArray &byteArray) {
    SGames list;
    for(const auto &game: QJsonDocument::fromJson(byteArray).object().value("response").toObject().value("games").toArray()) {
        list.append(SGame(game.toObject()));
    }
    return list;
}

SGames SGame::load(const ProfileID &aId, const int &aFreeGames, const int &aGameInfo, std::function<void(SGames)> aCallback) {
    return Sapi::load<SGame>(gameUrl(aFreeGames, aGameInfo, aId), onLoad, aCallback);
}

int SGame::playerCount(const GameID &aAppId) {
    RequestData request;
    request.get(Sapi::numberPlayersUrl(aAppId), false);
    return (QJsonDocument::fromJson(request.reply()).object()).value("response").toObject().value("player_count").toDouble();
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

bool SGame::operator<(const SGame &aGame) const {
    return _name < aGame._name;
}

bool SGame::operator>(const SGame &aGame) const {
    return _name > aGame._name;
}

bool SGame::operator==(const SGame &aGame) const {
    return (_appID                          == aGame._appID &&
            _name                           == aGame._name &&
            _playtime_2weeks                == aGame._playtime_2weeks &&
            _playtime_forever               == aGame._playtime_forever &&
            _has_community_visible_stats    == aGame._has_community_visible_stats &&
            _img_icon_url                   == aGame._img_icon_url &&
            _img_logo_url                   == aGame._img_logo_url &&
            _pixmapIcon                     == aGame._pixmapIcon &&
            _pixmapLogo                     == aGame._pixmapLogo);
}

bool SGame::operator!=(const SGame &aGame) const {
    return (_appID                          != aGame._appID ||
            _name                           != aGame._name ||
            _playtime_2weeks                != aGame._playtime_2weeks ||
            _playtime_forever               != aGame._playtime_forever ||
            _has_community_visible_stats    != aGame._has_community_visible_stats ||
            _img_icon_url                   != aGame._img_icon_url ||
            _img_logo_url                   != aGame._img_logo_url ||
            _pixmapIcon                     != aGame._pixmapIcon ||
            _pixmapLogo                     != aGame._pixmapLogo);
}

QPixmap SGame::pixmapIcon() const {
    return QPixmap::fromImage(loadPixmap(_pixmapIcon, Sapi::gameImageUrl(_appID, _img_icon_url), Paths::imagesGames(_img_icon_url), QSize(32, 32)));
}

QPixmap SGame::pixmapLogo() const {
    return QPixmap::fromImage(loadPixmap(_pixmapLogo, Sapi::gameImageUrl(_appID, _img_logo_url), Paths::imagesGames(_img_logo_url), QSize(184, 69)));
}

void SGame::fromJson(const QJsonObject &aValue) {
    _appID                          = aValue.value("appid").toInt();
    _name                           = aValue.value("name").toString();
    _playtime_2weeks                = aValue.value("playtime_2weeks").toInt();
    _playtime_forever               = aValue.value("playtime_forever").toInt();
    _has_community_visible_stats    = aValue.value("has_community_visible_stats").toBool();
    _img_icon_url                   = aValue.value("img_icon_url").toString();
    _img_logo_url                   = aValue.value("img_logo_url").toString();
}
#define SGameEnd }
