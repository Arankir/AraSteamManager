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

QList<SGame> onLoad(QByteArray byteArray) {
    QList<SGame> list;
    for (const auto &game: QJsonDocument::fromJson(byteArray).object().value("response").toObject().value("games").toArray()) {
        list.append(std::move(SGame(game.toObject())));
    }
    return list;
}

QList<SGame> SGame::load(const QString &aId, int aFreeGames, int aGameInfo, std::function<void(QList<SGame>)> aCallback) {
    return Sapi::load<SGame>(gameUrl(aFreeGames, aGameInfo, aId), onLoad, aCallback);
}

int SGame::playerCount(const int aAppId) {
    RequestData request;
    request.get(Sapi::numberPlayersUrl(QString::number(aAppId)), false);
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
