#include "sachievements.h"

#define SAchievementStart {
SAchievement &SAchievement::operator=(const SAchievement &aAchievement) {
    //qDebug()<<"SAchievement equality"<<_apiName;
    _schema         = aAchievement._schema;
    _percentage     = aAchievement._percentage;
    _player         = aAchievement._player;
    _pixmapIcon     = aAchievement._pixmapIcon;
    _pixmapIconGray = aAchievement._pixmapIconGray;
    return *this;
}

bool SAchievement::operator<(const SAchievement &aAchievement) const {
    return displayName().compare(aAchievement.displayName(), Qt::CaseInsensitive) < 0;
}

QJsonObject SAchievement::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["schema"] = _schema.toJson();
    obj["percent"] = _percentage.toJson();
    obj["player"] = _player.toJson();
    return obj;
}

QPixmap SAchievement::icon(int aGameId) {
    return loadPixmap(_pixmapIcon, iconPath(), Paths::imagesAchievements(QString::number(aGameId), iconPath()), QSize(64, 64));
}

QPixmap SAchievement::iconGray(int aGameId) {
    return loadPixmap(_pixmapIconGray, iconGrayPath(), Paths::imagesAchievements(QString::number(aGameId), iconGrayPath()), QSize(64, 64));
}
#define SAchievementEnd }

QJsonObject SAchievementSchema::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["name"] = _apiName;
    obj["defaultvalue"] = _defaultValue;
    obj["displayName"] = _displayName;
    obj["hidden"] = _hidden;
    obj["description"] = _description;
    obj["icon"] = _icon;
    obj["icongray"] = _iconGray;
    return obj;
}

QList<SAchievementSchema> onLoadSchema(QByteArray byteArray) {
    QList<SAchievementSchema> list;
    for (const auto &schema: QJsonDocument::fromJson(byteArray).object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray()) {
        list.append(std::move(SAchievementSchema(schema.toObject())));
    }
    return list;
}

QList<SAchievementSchema> SAchievementSchema::load(const QString &appid, std::function<void (QList<SAchievementSchema>)> aCallback) {
    return Sapi::load<SAchievementSchema>(achievementsSchemaUrl(appid), onLoadSchema, aCallback);
}

QJsonObject SAchievementPercentage::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["name"] = _apiName;
    obj["percent"] = _percent;
    return obj;
}

QList<SAchievementPercentage> onLoadPercentage(QByteArray byteArray) {
    QList<SAchievementPercentage> list;
    for (const auto &percentage: QJsonDocument::fromJson(byteArray).object().value("achievementpercentages").toObject().value("achievements").toArray()) {
        list.append(std::move(SAchievementPercentage(percentage.toObject())));
    }
    return list;
}

QList<SAchievementPercentage> SAchievementPercentage::load(const QString &appid, std::function<void (QList<SAchievementPercentage>)> aCallback) {
    return Sapi::load<SAchievementPercentage>(achievementsPercentUrl(appid), onLoadPercentage, aCallback);
}

QJsonObject SAchievementPlayer::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["apiname"] = _apiName;
    obj["achieved"] = _achieved;
    obj["unlocktime"] = _unlockTime.toSecsSinceEpoch();
    return obj;
}

QList<SAchievementPlayer> onLoadPlayer(QByteArray byteArray) {
    QList<SAchievementPlayer> list;
    for (const auto &player: QJsonDocument::fromJson(byteArray).object().value("playerstats").toObject().value("achievements").toArray()) {
        list.append(std::move(SAchievementPlayer(player.toObject())));
    }
    return list;
}

QList<SAchievementPlayer> SAchievementPlayer::load(const QString &appid, const QString &id, std::function<void (QList<SAchievementPlayer>)> aCallback) {
    return Sapi::load<SAchievementPlayer>(achievementsPlayerUrl(appid, id), onLoadPlayer, aCallback);
}

QList<SAchievement> UniteAchievement(const QList<SAchievementSchema> &global, const QList<SAchievementPercentage> &percent, const QList<SAchievementPlayer> &player) {
    QList<SAchievement> list;
    for (const auto &percent: percent) {
        int globalIndex = -1;
        for (const auto &player: player) {
            SAchievementSchema localGlobal = global[++globalIndex];
            if (percent.apiName() == player.apiName()) {
                list.push_back(SAchievement(localGlobal, player, percent));
                break;
            }
        }
    }
    return list;
}
