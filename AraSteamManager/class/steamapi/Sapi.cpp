#include "Sapi.h"

Sapi::Sapi(QObject *parent) : QObject(parent) {
    connect(&_request, &RequestData::s_finished, this, &Sapi::onLoad);
}

Sapi::~Sapi() {
    disconnect(&_request, &RequestData::s_finished, this, &Sapi::onLoad);
}

QString Sapi::achievementsGlobalUrl(QString aAppId) {
    return "http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key=" + Settings::getKey() + "&appid=" + aAppId + "&l=" + tr("russian");
}

QString Sapi::achievementsPlayerUrl(QString aAppId, QString aSteamId) {
    return "http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key=" + Settings::getKey() + "&appid=" + aAppId + "&steamid=" + aSteamId;
}

QString Sapi::achievementsPercentUrl(QString aAppId) {
    return "https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v2/?key=" + Settings::getKey() + "&gameid=" + aAppId;
}

QString Sapi::bansUrl(QString aSteamIds) {
    return "http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key=" + Settings::getKey() + "&steamids=" + aSteamIds;
}

QString Sapi::friendsUrl(QString aSteamId) {
    return "http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key=" + Settings::getKey() + "&steamid=" + aSteamId + "&relationship=friend";
}

QString Sapi::profileUrl(QString aSteamId) {
    return "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=" + Settings::getKey() + "&steamids=" + aSteamId;
}

QString Sapi::profileUrl(QStringList steamIds) {
    return "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=" + Settings::getKey() + "&steamids=" + steamIds.join(", ");
}

QString Sapi::profilefromVanityUrl(QString aSteamId) {
    return "https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key=" + Settings::getKey() + "&vanityurl=" + aSteamId + "&url_type=1";
}

QString Sapi::gameUrl(int aFreeGames, int aGameInfo, QString aSteamId) {
    return "http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=" + Settings::getKey() + "&include_played_free_games=" + QString::number(aFreeGames) +
            "&include_appinfo=" + QString::number(aGameInfo) + "&format=json&steamid=" + aSteamId;
}

QString Sapi::gameImageUrl(QString aGame, QString aImg_id) {
    return "http://media.steampowered.com/steamcommunity/public/images/apps/" + aGame + "/" + aImg_id + ".jpg";
}

QString Sapi::numberPlayersUrl(QString aAppId) {
    return "https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key=" + Settings::getKey() + "&appid=" + aAppId;
}

QString Sapi::lvlUrl(QString aSteamId) {
    return "https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key=" + Settings::getKey() + "&steamid=" + aSteamId;
}

Sapi::Sapi(const Sapi &api) {
    _status = api._status;
    _error = api._error;
}

Sapi &Sapi::operator=(const Sapi &api) {
    _status = api._status;
    _error = api._error;
    return *this;
}

StatusValue Sapi::getStatus() const {
    return _status;
}

QString Sapi::getError() const {
    return _error;
}
