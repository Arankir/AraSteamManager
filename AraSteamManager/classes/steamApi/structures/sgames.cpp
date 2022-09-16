#include "sgames.h"
#include "classes/common/images.h"
#include "classes/common/settings.h"

#include <QJsonDocument>
#include <QJsonArray>

#define SGameStart {
SGame::SGame(const QJsonObject &aGame, const ProfileID &aProfileId, QObject *aParent): Sapi(aParent), userId_(aProfileId) {
    fromJson(aGame);
}

SGame::SGame(const SGame &aGame): Sapi(aGame.parent()), userId_(aGame.userId()), appId_(aGame.appId_), name_(aGame.name_),
    playtime_2weeks_(aGame.playtime_2weeks_), playtime_forever_(aGame.playtime_forever_),
    playtime_windows_forever_(aGame.playtime_windows_forever_), playtime_mac_forever_(aGame.playtime_mac_forever_),
    playtime_linux_forever_(aGame.playtime_linux_forever_), has_community_visible_stats_(aGame.has_community_visible_stats_),
    img_icon_url_(aGame.img_icon_url_), img_logo_url_(aGame.img_logo_url_) {

}

QJsonObject SGame::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["appid"] = appId_;
    obj["name"] = name_;
    obj["playtime_2weeks"] = playtime_2weeks_;
    obj["playtime_forever"] = playtime_forever_;
    obj["playtime_windows_forever"] = playtime_windows_forever_;
    obj["playtime_mac_forever"] = playtime_mac_forever_;
    obj["playtime_linux_forever"] = playtime_linux_forever_;
    obj["has_community_visible_stats"] = has_community_visible_stats_;
    obj["img_icon_url"] = img_icon_url_;
    obj["img_logo_url"] = img_logo_url_;
    return obj;
}

SGames onLoad(const QByteArray &aByteArray) {
    SGames list;
    for(const auto &game: QJsonDocument::fromJson(aByteArray).object().value("response").toObject().value("games").toArray()) {
        list.append(SGame(game.toObject()));
    }
    return list;
}

SGames SGame::load(const ProfileID &aProfileId, const int &aFreeGames, const int &aGameInfo, std::function<void(SGames)> aCallback) {
    return Sapi::load<SGame>(gameUrl(aFreeGames, aGameInfo, aProfileId), onLoad, aCallback);
}

int SGame::playerCount(const GameID &aGameId) {
    RequestData request;
    request.get(Sapi::numberPlayersUrl(aGameId), false);
    return (QJsonDocument::fromJson(request.reply()).object()).value("response").toObject().value("player_count").toDouble();
}

SGame &SGame::operator=(const SGame &aGame) {
    appId_                          = aGame.appId_;
    name_                           = aGame.name_;
    playtime_2weeks_                = aGame.playtime_2weeks_;
    playtime_forever_               = aGame.playtime_forever_;
    playtime_windows_forever_       = aGame.playtime_windows_forever_;
    playtime_mac_forever_           = aGame.playtime_mac_forever_;
    playtime_linux_forever_         = aGame.playtime_linux_forever_;
    has_community_visible_stats_    = aGame.has_community_visible_stats_;
    img_icon_url_                   = aGame.img_icon_url_;
    img_logo_url_                   = aGame.img_logo_url_;
    pixmapIcon_                     = aGame.pixmapIcon_;
    pixmapLogo_                     = aGame.pixmapLogo_;
    return *this;
}

bool SGame::operator<(const SGame &aGame) const {
    return name_ < aGame.name_;
}

bool SGame::operator>(const SGame &aGame) const {
    return name_ > aGame.name_;
}

bool SGame::operator==(const SGame &aGame) const {
    return (appId_                          == aGame.appId_ &&
            name_                           == aGame.name_ &&
            playtime_2weeks_                == aGame.playtime_2weeks_ &&
            playtime_forever_               == aGame.playtime_forever_ &&
            has_community_visible_stats_    == aGame.has_community_visible_stats_ &&
            img_icon_url_                   == aGame.img_icon_url_ &&
            img_logo_url_                   == aGame.img_logo_url_ &&
            pixmapIcon_                     == aGame.pixmapIcon_ &&
            pixmapLogo_                     == aGame.pixmapLogo_);
}

bool SGame::operator!=(const SGame &aGame) const {
    return (appId_                          != aGame.appId_ ||
            name_                           != aGame.name_ ||
            playtime_2weeks_                != aGame.playtime_2weeks_ ||
            playtime_forever_               != aGame.playtime_forever_ ||
            has_community_visible_stats_    != aGame.has_community_visible_stats_ ||
            img_icon_url_                   != aGame.img_icon_url_ ||
            img_logo_url_                   != aGame.img_logo_url_ ||
            pixmapIcon_                     != aGame.pixmapIcon_ ||
            pixmapLogo_                     != aGame.pixmapLogo_);
}

QPixmap SGame::pixmapIcon() const {
    if (img_icon_url_.isEmpty()) {
        pixmapIcon_ = QPixmap(Images::missingImage()).scaled(QSize(32, 32)).toImage();
    }
    return QPixmap::fromImage(loadImage(pixmapIcon_, Sapi::gameImageUrl(appId_, img_icon_url_), Paths::imagesGames(img_icon_url_), QSize(32, 32)));
}

QPixmap SGame::pixmapIcon(const GameID &aGameId, const QString &aIconPath) {
    if (aIconPath.isEmpty()) {
        return QPixmap(Images::missingImage()).scaled(QSize(32, 32));
    }
    return QPixmap::fromImage(loadImage(Sapi::gameImageUrl(aGameId, aIconPath), Paths::imagesGames(aIconPath), QSize(32, 32)));
}

QPixmap SGame::pixmapLogo() const {
    if (img_icon_url_.isEmpty()) {
        pixmapLogo_ = QPixmap(Images::missingImage()).scaled(QSize(184, 69)).toImage();
    }
    return QPixmap::fromImage(loadImage(pixmapLogo_, Sapi::gameImageUrl(appId_, img_logo_url_), Paths::imagesGames(img_logo_url_), QSize(184, 69)));
}

ProfileID SGame::userId() const {
    return userId_;
}

GameID SGame::appId() const {
    return appId_;
}

QString SGame::name() const {
    return name_;
}

int SGame::playtime2Weeks() const {
    return playtime_2weeks_;
}

int SGame::playtimeForever() const {
    return playtime_forever_;
}

int SGame::playtimeWindowsForever() const {
    return playtime_windows_forever_;
}

int SGame::playtimeMacForever() const {
    return playtime_mac_forever_;
}

int SGame::playtimeLinuxForever() const {
    return playtime_linux_forever_;
}

bool SGame::hasCommunityVisibleStats() const {
    return has_community_visible_stats_;
}

QString SGame::imgIconUrl() const {
    return img_icon_url_;
}

QString SGame::imgLogoUrl() const {
    return img_logo_url_;
}

void SGame::fromJson(const QJsonObject &aValue) {
    appId_                          = aValue.value("appid").toInt();
    name_                           = aValue.value("name").toString();
    playtime_2weeks_                = aValue.value("playtime_2weeks").toInt();
    playtime_forever_               = aValue.value("playtime_forever").toInt();
    playtime_windows_forever_       = aValue.value("playtime_windows_forever").toInt();
    playtime_mac_forever_           = aValue.value("playtime_mac_forever").toInt();
    playtime_linux_forever_         = aValue.value("playtime_linux_forever").toInt();
    has_community_visible_stats_    = aValue.value("has_community_visible_stats").toBool();
    img_icon_url_                   = aValue.value("img_icon_url").toString();
    img_logo_url_                   = aValue.value("img_logo_url").toString();
}
#define SGameEnd }
