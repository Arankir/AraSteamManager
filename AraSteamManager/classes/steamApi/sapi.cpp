#include "sapi.h"

const QString    Sapi::_key = "3826BF60403D15613B4B0381DAB7A7BD";

Sapi::Sapi(QObject *parent) : QObject(parent) {
    connect(&_request, &RequestData::s_finished, this, &Sapi::onLoad);
}

Sapi::~Sapi() {
    disconnect(&_request, &RequestData::s_finished, this, &Sapi::onLoad);
}

QString Sapi::gameImageUrl(QString aGame, QString aImgId) {
    return "http://media.steampowered.com/steamcommunity/public/images/apps/" + aGame + "/" + aImgId + ".jpg";
}

QString Sapi::achievementsGlobalUrl(QString aAppId) {
    return "http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key=" + _key + "&appid=" + aAppId + "&l=" + tr("russian");
}

QString Sapi::achievementsPlayerUrl(QString aAppId, QString aSteamId) {
    return "http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key=" + _key + "&appid=" + aAppId + "&steamid=" + aSteamId;
}

QString Sapi::achievementsPercentUrl(QString aAppId) {
    return "https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v2/?key=" + _key + "&gameid=" + aAppId;
}

QString Sapi::bansUrl(QString aSteamIds) {
    return "http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key=" + _key + "&steamids=" + aSteamIds;
}

QString Sapi::friendsUrl(QString aSteamId) {
    return "http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key=" + _key + "&steamid=" + aSteamId + "&relationship=friend";
}

QString Sapi::profileUrl(QString aSteamId) {
    return "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=" + _key + "&steamids=" + aSteamId;
}

QString Sapi::profileUrl(QStringList aSteamIds) {
    return "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=" + _key + "&steamids=" + aSteamIds.join(", ");
}

QString Sapi::profilefromVanityUrl(QString aSteamId) {
    return "https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key=" + _key + "&vanityurl=" + aSteamId + "&url_type=1";
}

QString Sapi::gameUrl(int aFreeGames, int aGameInfo, QString aSteamId) {
    return "http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=" + _key + "&include_played_free_games=" + QString::number(aFreeGames) +
            "&include_appinfo=" + QString::number(aGameInfo) + "&format=json&steamid=" + aSteamId;
}

QString Sapi::numberPlayersUrl(QString aAppId) {
    return "https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key=" + _key + "&appid=" + aAppId;
}

QString Sapi::lvlUrl(QString aSteamId) {
    return "https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key=" + _key + "&steamid=" + aSteamId;
}

Sapi::Sapi(const Sapi &api) {
    _status = api._status;
    _error  = api._error;
}

Sapi &Sapi::operator=(const Sapi &api) {
    _status = api._status;
    _error  = api._error;
    return *this;
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
                if (!img.getPixmap().isNull()) {
                    aPixmap = img.getPixmap().scaled(aSize);
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
