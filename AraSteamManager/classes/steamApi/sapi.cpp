#include "sapi.h"

#include "secret_config.h"

#include <QFile>
#include <QIcon>
#include <QJsonDocument>
#include <QUrlQuery>

QString Sapi::apiKey()
{
    static const QString key = QString::fromUtf8(SECRET_KEY);
    return key;
}

Sapi::Sapi(QObject *aParent): QObject(aParent) {

}

Sapi::Sapi(const Sapi &aApi): QObject(aApi.parent()) {

}

Sapi::~Sapi() {

}

QString Sapi::className() const {
    return typeid(this).name();
}

QString Sapi::toString() const {
    return QJsonDocument(toJson()).toJson(QJsonDocument::Compact);
}

QUrl Sapi::gameImageUrl(const GameID &aAppId, const QString &aImgId) {
    if (aAppId <= 0 || aImgId.isEmpty()) {
        return {};
    }
    return "https://media.steampowered.com/steamcommunity/public/images/apps/" + QString::number(aAppId) + "/" + aImgId + ".jpg";
}

QUrl Sapi::frameProfile(const QString &aFrameId) {
    if (aFrameId.isEmpty()) {
        return {};
    }
    return "https://media.steampowered.com/steamcommunity/public/images/" + aFrameId;
}

QString Sapi::pathToTempRawFile(const QUrl &aUrl) {
    return Paths::temp() + "SapiRaw/"
        + aUrl.url().remove("https://").remove("https").remove("http://").remove("http").remove("?").remove(".").remove("key=" + apiKey())
        + ".sapiraw";
}

bool Sapi::saveRawLoadedData(const QUrl &aUrl, const QByteArray &aBytes) {
    if (aBytes.isEmpty() || aBytes.isNull()) {
        return false;
    }
    QString dr = pathToTempRawFile(aUrl);
    if (dr.lastIndexOf("/") < dr.length() - 1 && dr.lastIndexOf("\\") < dr.length() - 1) {
        dr = dr.first(std::max(dr.lastIndexOf("/"), dr.lastIndexOf("\\")) + 1);
    }
    QDir dir;
    dir.mkpath(dr);
    QFile file(pathToTempRawFile(aUrl));
    bool isSaved = false;
    if (file.open(QIODevice::WriteOnly)) {
        isSaved = file.write(aBytes);
        file.close();
    }
    return isSaved;
}

bool Sapi::checkRawLoadedData(const QUrl &aUrl) {
    QFileInfo fInfo(pathToTempRawFile(aUrl));
    if (fInfo.lastModified() < QDateTime::currentDateTime().addSecs(-60 * 10)) {
        return false;
    }
    return true;
}

QByteArray Sapi::loadRawLoadedData(const QUrl &aUrl) {
    QByteArray data;
    QFile file(pathToTempRawFile(aUrl));
    if (file.open(QIODevice::ReadOnly)) {
        data = file.readAll();
        file.close();
    }
    return data;
}

QUrl Sapi::Url::achievementsSchema(const GameID &aAppId) {
    QUrl url("https://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/");
    url.setQuery({{"key", apiKey()}, {"appid", QString::number(aAppId)}, {"l", tr("russian")}});
    return url;
    //return "http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key=" + _key + "&appid=" + aAppId + "&l=" + tr("russian");
}

QUrl Sapi::Url::achievementsPlayer(const GameID &aAppId, const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/");
    url.setQuery({{"key", apiKey()}, {"appid", QString::number(aAppId)}, {"steamid", aSteamId}});
    return url;
    //return "http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key=" + _key + "&appid=" + aAppId + "&steamid=" + aSteamId;
}

QUrl Sapi::Url::avatarFrame(const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/IPlayerService/GetAvatarFrame/v1/");
    url.setQuery({{"key", apiKey()}, {"steamid", aSteamId}, {"language", tr("russian")}});
    return url;
    //return "https://api.steampowered.com/IPlayerService/GetAvatarFrame/v1/?key=" + _key + "&steamid=" + aSteamId + "&language=" + tr("russian");
}

QUrl Sapi::Url::avatarAnimation(const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/IPlayerService/GetAnimatedAvatar/v1/");
    url.setQuery({{"key", apiKey()}, {"steamid", aSteamId}, {"language", tr("russian")}});
    return url;
    //return "https://api.steampowered.com/IPlayerService/GetAnimatedAvatar/v1/?key=" + _key + "&steamid=" + aSteamId + "&language=" + tr("russian");
}

QUrl Sapi::Url::achievementsPercent(const GameID &aAppId) {
    QUrl url("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v2/");
    url.setQuery({{"key", apiKey()}, {"gameid", QString::number(aAppId)}});
    return url;
    //return "https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v2/?key=" + _key + "&gameid=" + aAppId;
}

QUrl Sapi::Url::bans(const QString &aSteamIds) {
    QUrl url("https://api.steampowered.com/ISteamUser/GetPlayerBans/v1/");
    url.setQuery({{"key", apiKey()}, {"steamids", aSteamIds}});
    return url;
    //return "http://api.steampowered.com/ISteamUser/GetPlayerBans/v1/?key=" + _key + "&steamids=" + aSteamIds;
}

QUrl Sapi::Url::friends(const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/ISteamUser/GetFriendList/v0001/");
    url.setQuery({{"key", apiKey()}, {"steamid", aSteamId}, {"relationship", "friend"}});
    return url;
    //return "http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key=" + _key + "&steamid=" + aSteamId + "&relationship=friend";
}

QUrl Sapi::Url::profile(const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/");
    url.setQuery({{"key", apiKey()}, {"steamids", aSteamId}});
    return url;
    //return "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=" + _key + "&steamids=" + aSteamId;
}

QUrl Sapi::Url::profile(const ProfileIDs &aSteamIds) {
    QUrl url("https://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/");
    url.setQuery({{"key", apiKey()}, {"steamids", aSteamIds.join(",")}});
    return url;
    //return "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=" + _key + "&steamids=" + aSteamIds.join(", ");
}

QUrl Sapi::Url::profilefromVanity(const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/");
    url.setQuery({{"key", apiKey()}, {"vanityurl", aSteamId}, {"url_type", "1"}});
    return url;
    //return "https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key=" + _key + "&vanityurl=" + aSteamId + "&url_type=1";
}

QUrl Sapi::Url::game(int aFreeGames, int aGameInfo, const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/");
    url.setQuery({{"key", apiKey()},
                  {"include_played_free_games", QString::number(aFreeGames)},
                  {"include_appinfo", QString::number(aGameInfo)},
                  {"format", "json"},
                  {"steamid", aSteamId}});
    return url;
//    return "http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=" + _key + "&include_played_free_games=" + QString::number(aFreeGames) +
//            "&include_appinfo=" + QString::number(aGameInfo) + "&format=json&steamid=" + aSteamId;
}

QUrl Sapi::Url::numberPlayers(const GameID &aAppId) {
    QUrl url("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/");
    url.setQuery({{"key", apiKey()}, {"appid", QString::number(aAppId)}});
    return url;
    //return "https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key=" + _key + "&appid=" + aAppId;
}

QUrl Sapi::Url::lvl(const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/");
    url.setQuery({{"key", apiKey()}, {"steamid", aSteamId}});
    return url;
    //return "https://api.steampowered.com/IPlayerService/GetSteamLevel/v1/?key=" + _key + "&steamid=" + aSteamId;
}

QUrl Sapi::Url::profileCustomizations(const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/IPlayerService/GetPurchasedAndUpgradedProfileCustomizations/v1/");
    url.setQuery({{"key", apiKey()}, {"steamid", aSteamId}});
    return url;
    //return "https://api.steampowered.com/IPlayerService/GetPurchasedAndUpgradedProfileCustomizations/v1/?key=" + _key + "&steamid=" + aSteamId;
}

QUrl Sapi::Url::profileEquippedItem(const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/IPlayerService/GetProfileItemsEquipped/v1/");
    url.setQuery({{"key", apiKey()}, {"steamid", aSteamId}, {"language", tr("russian")}});
    return url;
    //return "https://api.steampowered.com/IPlayerService/GetProfileItemsEquipped/v1/?key=" + _key + "&steamid=" + aSteamId + "&language=" + tr("russian");
}

QUrl Sapi::Url::badges(const ProfileID &aSteamId) {
    QUrl url("https://api.steampowered.com/IPlayerService/GetBadges/v1/");
    url.setQuery({{"key", apiKey()}, {"steamid", aSteamId}});
    return url;
}
