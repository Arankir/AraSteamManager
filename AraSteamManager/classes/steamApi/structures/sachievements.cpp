#include "sachievements.h"
#include <QJsonDocument>
#include <QJsonArray>

#define SAchievementStart {
SAchievement::SAchievement(const SAchievementSchema &aSchema, const SAchievementPlayer &aPlayer, const SAchievementPercentage &aPercent, QObject *aParent):
    Sapi(aParent), schema_(aSchema), percentage_(aPercent), player_(aPlayer) {
    //qDebug()<<"SAchievement constructor"<<_apiName;
}

SAchievement::SAchievement(const SAchievement &aAchievement): Sapi(aAchievement.parent()), schema_(aAchievement.schema_),
    percentage_(aAchievement.percentage_), player_(aAchievement.player_) {
    //qDebug()<<"SAchievement copy"<<_apiName;
}

SAchievement::SAchievement(const QJsonObject &aObject, QObject *aParent): Sapi{aParent}, schema_(aObject.value("schema").toObject()),
    percentage_(aObject.value("percent").toObject()), player_(aObject.value("player").toObject()) {
    //qDebug() << "SAchievement constructor 1" << aObject;
}

SAchievement::SAchievement(const QString &aText, QObject *aParent): SAchievement(QJsonDocument::fromJson(aText.toUtf8()).object(), aParent) {
    //qDebug() << "SAchievement constructor 2" << aText;
}

SAchievement &SAchievement::operator=(const SAchievement &aAchievement) {
    //qDebug()<<"SAchievement equality"<<_apiName;
    schema_         = aAchievement.schema_;
    percentage_     = aAchievement.percentage_;
    player_         = aAchievement.player_;
    return *this;
}

bool SAchievement::operator<(const SAchievement &aAchievement) const {
    return displayName().compare(aAchievement.displayName(), Qt::CaseInsensitive) < 0;
}

bool SAchievement::operator>(const SAchievement &aAchievement) const {
    return displayName().compare(aAchievement.displayName(), Qt::CaseInsensitive) > 0;
}

bool SAchievement::operator==(const SAchievement &aAchievement) const {
    return (schema_ == aAchievement.schema_ &&
            percentage_ == aAchievement.percentage_ &&
            player_ == aAchievement.player_);
}

bool SAchievement::operator!=(const SAchievement &aAchievement) const {
    return (schema_ != aAchievement.schema_ ||
            percentage_ != aAchievement.percentage_ ||
            player_ != aAchievement.player_);
}

bool SAchievement::isValid() const {
    return (schema_.apiName() == percentage_.apiName()) && (percentage_.apiName() == player_.apiName());
}

QJsonObject SAchievement::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["schema"] = schema_.toJson();
    obj["percent"] = percentage_.toJson();
    obj["player"] = player_.toJson();
    return obj;
}

QPixmap SAchievement::icon(GameID aGameId) const {
    return schema_.icon(aGameId);
}

QPixmap SAchievement::iconGray(GameID aGameId) const {
    return schema_.iconGray(aGameId);
}

AchievementID SAchievement::apiName() const {
    return schema_.apiName();
}

int SAchievement::defaultValue() const {
    return schema_.defaultValue();
}

QString SAchievement::displayName() const {
    return schema_.displayName();
}

int SAchievement::hidden() const {
    return schema_.hidden();
}

QString SAchievement::description() const {
    return schema_.description();
}

int SAchievement::achieved() const {
    return player_.achieved();
}

QDateTime SAchievement::unlockTime() const {
    return player_.unlockTime();
}

double SAchievement::percent() const {
    return percentage_.percent();
}

QString SAchievement::iconPath() const {
    return schema_.icon();
}

QString SAchievement::iconGrayPath() const {
    return schema_.iconGray();
}
#define SAchievementEnd }

SAchievementSchema::SAchievementSchema(QObject *aParent): Sapi(aParent) {

};

SAchievementSchema::SAchievementSchema(const QJsonObject &aObject, QObject *aParent): Sapi(aParent),
apiName_(aObject.value("name").toString()), defaultValue_(aObject.value("defaultvalue").toInt()),
displayName_(aObject.value("displayName").toString()), hidden_(aObject.value("hidden").toInt()),
description_(aObject.value("description").toString()), icon_(aObject.value("icon").toString()),
iconGray_(aObject.value("icongray").toString()) {
    //qDebug()<<"SAchievementGlobal constructor"<<_apiName;
}

SAchievementSchema::SAchievementSchema(const SAchievementSchema &aSchema): Sapi(aSchema.parent()),
apiName_(aSchema.apiName_), defaultValue_(aSchema.defaultValue_), displayName_(aSchema.displayName_),
hidden_(aSchema.hidden_), description_(aSchema.description_), icon_(aSchema.icon_), iconGray_(aSchema.iconGray_),
pixmapIcon_(aSchema.pixmapIcon_), pixmapIconGray_(aSchema.pixmapIconGray_) {
    //qDebug()<<"SAchievementGlobal copy"<<_apiName;
}

SAchievementSchema &SAchievementSchema::operator=(const SAchievementSchema &aSchema) {
    //qDebug()<<"SAchievementGlobal equality"<<_apiName;
    apiName_ = aSchema.apiName_;
    defaultValue_ = aSchema.defaultValue_;
    displayName_ = aSchema.displayName_;
    hidden_ = aSchema.hidden_;
    description_ = aSchema.description_;
    icon_ = aSchema.icon_;
    iconGray_ = aSchema.iconGray_;
    pixmapIcon_ = aSchema.pixmapIcon_;
    pixmapIconGray_ = aSchema.pixmapIconGray_;
    return *this;
}

bool SAchievementSchema::operator<(const SAchievementSchema &aSchema) const {
    return apiName_ < aSchema.apiName_;
}

bool SAchievementSchema::operator>(const SAchievementSchema &aSchema) const {
    return apiName_ > aSchema.apiName_;
}

bool SAchievementSchema::operator==(const SAchievementSchema &aSchema) const {
    return (apiName_ == aSchema.apiName_ &&
            defaultValue_ == aSchema.defaultValue_ &&
            displayName_ == aSchema.displayName_ &&
            hidden_ == aSchema.hidden_ &&
            description_ == aSchema.description_ &&
            icon_ == aSchema.icon_ &&
            iconGray_ == aSchema.iconGray_);
}

bool SAchievementSchema::operator!=(const SAchievementSchema &aSchema) const {
    return (apiName_ != aSchema.apiName_ ||
        defaultValue_ != aSchema.defaultValue_ ||
        displayName_ != aSchema.displayName_ ||
        hidden_ != aSchema.hidden_ ||
    description_ != aSchema.description_ ||
    icon_ != aSchema.icon_ ||
    iconGray_ != aSchema.iconGray_);
}

QJsonObject SAchievementSchema::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["name"] = apiName_;
    obj["defaultvalue"] = defaultValue_;
    obj["displayName"] = displayName_;
    obj["hidden"] = hidden_;
    obj["description"] = description_;
    obj["icon"] = icon_;
    obj["icongray"] = iconGray_;
    return obj;
}

QList<SAchievementSchema> onLoadSchema(const QByteArray &aByteArray) {
    QList<SAchievementSchema> list;
    for(auto &&schema: QJsonDocument::fromJson(aByteArray).object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray()) {
        list.append(SAchievementSchema(schema.toObject()));
    }
    return list;
}

SAchievementsSchema SAchievementSchema::load(const GameID &aAppId, std::function<void (SAchievementsSchema)> aCallback) {
    return Sapi::load<SAchievementSchema>(achievementsSchemaUrl(aAppId), onLoadSchema, aCallback);
}

QPixmap SAchievementSchema::icon(GameID aGameId) const {
    return QPixmap::fromImage(loadImage(pixmapIcon_, icon(), Paths::imagesAchievements(QString::number(aGameId), icon()), QSize(64, 64)));
}

QPixmap SAchievementSchema::iconGray(GameID aGameId) const {
    return QPixmap::fromImage(loadImage(pixmapIconGray_, iconGray(), Paths::imagesAchievements(QString::number(aGameId), iconGray()), QSize(64, 64)));
}

AchievementID SAchievementSchema::apiName() const {
    return apiName_;
}

int SAchievementSchema::defaultValue() const {
    return defaultValue_;
}

QString SAchievementSchema::displayName() const {
    return displayName_;
}

int SAchievementSchema::hidden() const {
    return hidden_;
}

QString SAchievementSchema::description() const {
    return description_;
}

QString SAchievementSchema::icon() const {
    return icon_;
}

QString SAchievementSchema::iconGray() const {
    return iconGray_;
}

SAchievementPercentage::SAchievementPercentage(QObject *aParent): Sapi{aParent} {

}

SAchievementPercentage::SAchievementPercentage(const QJsonObject &aAchievement, QObject *aParent): Sapi(aParent),
    apiName_(aAchievement.value("name").toString()), percent_(aAchievement.value("percent").toDouble()) {
    //qDebug()<<"SAchievementPercentage constructor"<<_apiName;
}

SAchievementPercentage::SAchievementPercentage(const SAchievementPercentage &aAchievement): Sapi(aAchievement.parent()),
    apiName_(aAchievement.apiName_), percent_(aAchievement.percent_) {
    //qDebug()<<"SAchievementPercentage copy"<<_apiName;
}

SAchievementPercentage &SAchievementPercentage::operator=(const SAchievementPercentage &aAchievement) {
    //qDebug()<<"SAchievementPercentage equality"<<_apiName;
    apiName_ = aAchievement.apiName_;
    percent_ = aAchievement.percent_;
    return *this;
}

bool SAchievementPercentage::operator<(const SAchievementPercentage &aAchievement) const {
    return apiName_ < aAchievement.apiName_;
}

bool SAchievementPercentage::operator>(const SAchievementPercentage &aAchievement) const {
    return apiName_ > aAchievement.apiName_;
}

bool SAchievementPercentage::operator==(const SAchievementPercentage &aAchievement) const {
    return (apiName_ == aAchievement.apiName_ &&
            percent_ == aAchievement.percent_);
}

bool SAchievementPercentage::operator!=(const SAchievementPercentage &aAchievement) const {
    return (apiName_ != aAchievement.apiName_ ||
            percent_ != aAchievement.percent_);
}

QJsonObject SAchievementPercentage::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["name"] = apiName_;
    obj["percent"] = percent_;
    return obj;
}

QList<SAchievementPercentage> onLoadPercentage(QByteArray aByteArray) {
    QList<SAchievementPercentage> list;
    for(auto &&percentage: QJsonDocument::fromJson(aByteArray).object().value("achievementpercentages").toObject().value("achievements").toArray()) {
        list.append(SAchievementPercentage(percentage.toObject()));
    }
    return list;
}

SAchievementsPercentage SAchievementPercentage::load(const GameID &aAppId, std::function<void (SAchievementsPercentage)> aCallback) {
    return Sapi::load<SAchievementPercentage>(achievementsPercentUrl(aAppId), onLoadPercentage, aCallback);
}

AchievementID SAchievementPercentage::apiName() const {
    return apiName_;
}

double SAchievementPercentage::percent() const {
    return percent_;
}

SAchievementPlayer::SAchievementPlayer(QObject *aParent): Sapi{aParent} {

}

SAchievementPlayer::SAchievementPlayer(const QJsonObject &aAchievement, QObject *aParent): Sapi(aParent),
    apiName_(aAchievement.value("apiname").toString()), achieved_(aAchievement.value("achieved").toInt()),
    unlockTime_(QDateTime::fromSecsSinceEpoch(aAchievement.value("unlocktime").toInt(), Qt::LocalTime)) {
    //qDebug()<<"SAchievementPlayer constructor"<<_apiName;
}

SAchievementPlayer::SAchievementPlayer(const SAchievementPlayer &aAchievement): Sapi(aAchievement.parent()),
    apiName_(aAchievement.apiName_), achieved_(aAchievement.achieved_), unlockTime_(aAchievement.unlockTime_) {
    //qDebug()<<"SAchievementPlayer copy"<<_apiName;
}

SAchievementPlayer &SAchievementPlayer::operator=(const SAchievementPlayer &aAchievement) {
    //qDebug()<<"SAchievementPlayer equality"<<_apiName;
    apiName_ = aAchievement.apiName_;
    achieved_ = aAchievement.achieved_;
    unlockTime_ = aAchievement.unlockTime_;
    return *this;
}

bool SAchievementPlayer::operator<(const SAchievementPlayer &aAchievement) const {
    return apiName_ < aAchievement.apiName_;
}

bool SAchievementPlayer::operator>(const SAchievementPlayer &aAchievement) const {
    return apiName_ > aAchievement.apiName_;
}

bool SAchievementPlayer::operator==(const SAchievementPlayer &aAchievement) const {
    return (apiName_ == aAchievement.apiName_ &&
            achieved_ == aAchievement.achieved_ &&
            unlockTime_ == aAchievement.unlockTime_);
}

bool SAchievementPlayer::operator!=(const SAchievementPlayer &aAchievement) const {
    return (apiName_ != aAchievement.apiName_ ||
            achieved_ != aAchievement.achieved_ ||
            unlockTime_ != aAchievement.unlockTime_);
}

QJsonObject SAchievementPlayer::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["apiname"] = apiName_;
    obj["achieved"] = achieved_;
    obj["unlocktime"] = unlockTime_.toSecsSinceEpoch();
    return obj;
}

QList<SAchievementPlayer> onLoadPlayer(const QByteArray &aByteArray) {
    QList<SAchievementPlayer> list;
    for(auto &&player: QJsonDocument::fromJson(aByteArray).object().value("playerstats").toObject().value("achievements").toArray()) {
        list.append(SAchievementPlayer(player.toObject()));
    }
    return list;
}

SAchievementsPlayer SAchievementPlayer::load(const GameID &aAppId, const ProfileID &aProfileId, std::function<void (SAchievementsPlayer)> aCallback) {
    return Sapi::load<SAchievementPlayer>(achievementsPlayerUrl(aAppId, aProfileId), onLoadPlayer, aCallback);
}

int SAchievementPlayer::countAchieved(const QList<SAchievementPlayer> &aAchievements) {
    return std::accumulate(aAchievements.begin(),
                           aAchievements.end(),
                           0,
                           [&](int lCount, const SAchievementPlayer &lAchievement) {
                                if (lAchievement.achieved() > 0) {
                                    return lCount + 1;
                                }
                                return lCount;
                           });
}

AchievementID SAchievementPlayer::apiName() const {
    return apiName_;
}

int SAchievementPlayer::achieved() const {
    return achieved_;
}

QDateTime SAchievementPlayer::unlockTime() const {
    return unlockTime_;
}
