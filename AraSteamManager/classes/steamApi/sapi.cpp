#include "sapi.h"

const QString    Sapi::_key = "3826BF60403D15613B4B0381DAB7A7BD";

Sapi::Sapi(QObject *parent): QObject(parent) {

}

Sapi::Sapi(const Sapi &api): QObject(api.parent()) {

}

Sapi::~Sapi() {

}

QString Sapi::gameImageUrl(QString aGame, QString aImgId) {
    return "http://media.steampowered.com/steamcommunity/public/images/apps/" + aGame + "/" + aImgId + ".jpg";
}

QUrl Sapi::achievementsSchemaUrl(QString aAppId) {
    QUrl url("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("appid", aAppId);
    query.addQueryItem("l", tr("russian"));
    url.setQuery(query);
    return url;
    //return "http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key=" + _key + "&appid=" + aAppId + "&l=" + tr("russian");
}

QUrl Sapi::achievementsPlayerUrl(QString aAppId, QString aSteamId) {
    QUrl url("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("appid", aAppId);
    query.addQueryItem("steamid", aSteamId);
    url.setQuery(query);
    return url;
    //return "http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key=" + _key + "&appid=" + aAppId + "&steamid=" + aSteamId;
}

QUrl Sapi::achievementsPercentUrl(QString aAppId) {
    QUrl url("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v2/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("gameid", aAppId);
    url.setQuery(query);
    return url;
    //return "https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v2/?key=" + _key + "&gameid=" + aAppId;
}

QUrl Sapi::bansUrl(QString aSteamIds) {
    QUrl url("http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("steamids", aSteamIds);
    url.setQuery(query);
    return url;
    //return "http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key=" + _key + "&steamids=" + aSteamIds;
}

QUrl Sapi::friendsUrl(QString aSteamId) {
    QUrl url("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("steamid", aSteamId);
    query.addQueryItem("relationship", "friend");
    url.setQuery(query);
    return url;
    //return "http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key=" + _key + "&steamid=" + aSteamId + "&relationship=friend";
}

QUrl Sapi::profileUrl(QString aSteamId) {
    QUrl url("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("steamids", aSteamId);
    url.setQuery(query);
    return url;
    //return "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=" + _key + "&steamids=" + aSteamId;
}

QUrl Sapi::profileUrl(QStringList aSteamIds) {
    QUrl url("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("steamids", aSteamIds.join(","));
    url.setQuery(query);
    return url;
    //return "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=" + _key + "&steamids=" + aSteamIds.join(", ");
}

QUrl Sapi::profilefromVanityUrl(QString aSteamId) {
    QUrl url("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("vanityurl", aSteamId);
    query.addQueryItem("url_type", "1");
    url.setQuery(query);
    qDebug() << url;
    return url;
    //return "https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key=" + _key + "&vanityurl=" + aSteamId + "&url_type=1";
}

QUrl Sapi::gameUrl(int aFreeGames, int aGameInfo, QString aSteamId) {
    QUrl url("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("include_played_free_games", QString::number(aFreeGames));
    query.addQueryItem("include_appinfo", QString::number(aGameInfo));
    query.addQueryItem("format", "json");
    query.addQueryItem("steamid", aSteamId);
    url.setQuery(query);
    return url;
//    return "http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=" + _key + "&include_played_free_games=" + QString::number(aFreeGames) +
//            "&include_appinfo=" + QString::number(aGameInfo) + "&format=json&steamid=" + aSteamId;
}

QUrl Sapi::numberPlayersUrl(QString aAppId) {
    QUrl url("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("appid", aAppId);
    url.setQuery(query);
    return url;
    //return "https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key=" + _key + "&appid=" + aAppId;
}

QUrl Sapi::lvlUrl(QString aSteamId) {
    QUrl url("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/");
    QUrlQuery query;
    query.addQueryItem("key", _key);
    query.addQueryItem("steamid", aSteamId);
    url.setQuery(query);
    return url;
    //return "https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key=" + _key + "&steamid=" + aSteamId;
}

QPixmap loadPixmap(QPixmap &aPixmap, const QString &aUrl, const QString &aSavePath, QSize aSize) {
    if (aPixmap.isNull()) {
        if (!aUrl.isEmpty()) {
            if (!QFile::exists(aSavePath)) {
                RequestImage img(aUrl, aSavePath, true);
                QEventLoop loop;
                QObject::connect(&img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
                loop.exec();
                QObject::disconnect(&img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
                if (!img.pixmap().isNull()) {
                    aPixmap = img.pixmap().scaled(aSize);
                }
            } else {
                aPixmap = QPixmap(aSavePath).scaled(aSize);
            }
        } else {
            aPixmap = QPixmap(Images::missingImage()).scaled(aSize);
        }
    }
    return aPixmap;
}

QString Sapi::toString() const {
    return QJsonDocument(toJson()).toJson(QJsonDocument::Compact);
}
