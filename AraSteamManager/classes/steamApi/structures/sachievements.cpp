#include "sachievements.h"
#include "classes/common/settings.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QVariant>

#define SAchievementStart {


SAchievement::SAchievement(const SAchievement &aAchievement): Sapi(aAchievement.parent()), schema_(aAchievement.schema_),
    percentage_(aAchievement.percentage_), player_(aAchievement.player_) {
//    qDebug() << "SAchievement copy" << apiName();
}

SAchievement::SAchievement(const QJsonObject &aObject, QObject *aParent): Sapi{aParent}, schema_(aObject.value("schema").toObject()),
    percentage_(aObject.value("percent").toObject()), player_(aObject.value("player").toObject()) {
//    qDebug() << "SAchievement constructor 1" << aObject;
}

SAchievement::SAchievement(const QVariant &aText, QObject *aParent): SAchievement(qvariant_cast<SAchievement>(aText)) {
//    qDebug() << "SAchievement constructor 2" << aText;
    Sapi::setParent(aParent);
}

SAchievement::~SAchievement() {
//    qDebug() << "SAchievement destructor" << apiName();
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

void SAchievement::fromJson(const QJsonObject &aObject) {
    schema_.fromJson(aObject.value("schema").toObject());
    percentage_.fromJson(aObject.value("percent").toObject());
    player_.fromJson(aObject.value("player").toObject());
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
    // qDebug() << "SAchievementGlobal constructor" << apiName_;
}

SAchievementSchema::SAchievementSchema(const SAchievementSchema &aSchema): Sapi(aSchema.parent()),
apiName_(aSchema.apiName_), defaultValue_(aSchema.defaultValue_), displayName_(aSchema.displayName_),
hidden_(aSchema.hidden_), description_(aSchema.description_), icon_(aSchema.icon_), iconGray_(aSchema.iconGray_),
pixmapIcon_(aSchema.pixmapIcon_), pixmapIconGray_(aSchema.pixmapIconGray_) {
    // qDebug() << "SAchievementGlobal copy" << apiName_;
}

SAchievementSchema &SAchievementSchema::operator=(const SAchievementSchema &aSchema)
{
    apiName_ = aSchema.apiName_;
    defaultValue_ = aSchema.defaultValue_;
    displayName_ = aSchema.displayName_;
    hidden_ = aSchema.hidden_;
    description_ = aSchema.description_;
    icon_ = aSchema.icon_;
    iconGray_ = aSchema.iconGray_;
    pixmapIcon_ = aSchema.pixmapIcon_;
    pixmapIconGray_ = aSchema.pixmapIconGray_;
    // qDebug() << "SAchievementGlobal equality" << apiName_;
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

void SAchievementSchema::fromJson(const QJsonObject &aObject) {
    apiName_ = aObject.value("name").toString();
    defaultValue_ = aObject.value("defaultvalue").toInt();
    displayName_ = aObject.value("displayName").toString();
    hidden_ = aObject.value("hidden").toInt();
    description_ = aObject.value("description").toString();
    icon_ = aObject.value("icon").toString();
    iconGray_ = aObject.value("icongray").toString();
}

QList<SAchievementSchema> onLoadSchema(const QByteArray &aByteArray) {
    QList<SAchievementSchema> list;
    for(QJsonValue &&schema: QJsonDocument::fromJson(aByteArray).object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray()) {
        list.append(SAchievementSchema(schema.toObject()));
    }
    return list;
}

SAchievementsSchema SAchievementSchema::load(const GameID &aAppId, std::function<void (SAchievementsSchema)> aCallback) {
    return Sapi::load<SAchievementSchema>(Sapi::Url::achievementsSchema(aAppId), onLoadSchema, aCallback);
}

QPixmap SAchievementSchema::icon(GameID aGameId) const {
    return QPixmap::fromImage(loadImage(pixmapIcon_, icon(), Paths::imagesAchievements(QString::number(aGameId), icon()), QSize(64, 64)));
}

QPixmap SAchievementSchema::icon(const GameID &aGameId, const QString &aIconPath, const QSize &aSize) {
    return QPixmap::fromImage(loadImage(aIconPath, Paths::imagesAchievements(QString::number(aGameId), aIconPath), aSize));
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

SAchievementPercentage::SAchievementPercentage(const QJsonObject &aAchievement, QObject *aParent):
    Sapi(aParent), apiName_(aAchievement.value("name").toString()), percent_(aAchievement.value("percent").toString().toDouble())
{
    // qDebug() << "SAchievementPercentage constructor" << apiName_ << percent_ << aAchievement.value("percent");
}

SAchievementPercentage::SAchievementPercentage(const SAchievementPercentage &aAchievement): Sapi(aAchievement.parent()),
    apiName_(aAchievement.apiName_), percent_(aAchievement.percent_) {
    // qDebug() << "SAchievementPercentage copy" << apiName_ << percent_;
}

SAchievementPercentage &SAchievementPercentage::operator=(const SAchievementPercentage &aAchievement)
{
    apiName_ = aAchievement.apiName_;
    percent_ = aAchievement.percent_;
    // qDebug() << "SAchievementPercentage equality" << apiName_ << percent_;
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

void SAchievementPercentage::fromJson(const QJsonObject &aObject) {
    apiName_ = aObject.value("name").toString();
    percent_ = aObject.value("percent").toDouble();
}

QList<SAchievementPercentage> onLoadPercentage(QByteArray aByteArray) {
    QList<SAchievementPercentage> list;
    for(QJsonValue &&percentage: QJsonDocument::fromJson(aByteArray).object().value("achievementpercentages").toObject().value("achievements").toArray()) {
        list.append(SAchievementPercentage(percentage.toObject()));
    }
    return list;
}

SAchievementsPercentage SAchievementPercentage::load(const GameID &aAppId, std::function<void (SAchievementsPercentage)> aCallback) {
    return Sapi::load<SAchievementPercentage>(Sapi::Url::achievementsPercent(aAppId), onLoadPercentage, aCallback);
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

SAchievementPlayer::SAchievementPlayer(const QString &aError, QObject *aParent): Sapi(aParent), achieved_(-1), error_(aError) {

}

SAchievementPlayer::SAchievementPlayer(const SAchievementPlayer &aAchievement): Sapi(aAchievement.parent()),
    apiName_(aAchievement.apiName_), achieved_(aAchievement.achieved_), unlockTime_(aAchievement.unlockTime_), error_(aAchievement.error_) {
    //qDebug()<<"SAchievementPlayer copy"<<_apiName;
}

SAchievementPlayer &SAchievementPlayer::operator=(const SAchievementPlayer &aAchievement) {
    //qDebug()<<"SAchievementPlayer equality"<<_apiName;
    apiName_ = aAchievement.apiName_;
    achieved_ = aAchievement.achieved_;
    unlockTime_ = aAchievement.unlockTime_;
    error_ = aAchievement.error_;
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
            unlockTime_ == aAchievement.unlockTime_ &&
            achieved_ == aAchievement.achieved_);
}

bool SAchievementPlayer::operator!=(const SAchievementPlayer &aAchievement) const {
    return (apiName_ != aAchievement.apiName_ ||
            achieved_ != aAchievement.achieved_ ||
            unlockTime_ != aAchievement.unlockTime_ ||
            achieved_ != aAchievement.achieved_);
}

QJsonObject SAchievementPlayer::toJson() const {
    QJsonObject obj;
    obj["type"] = className();
    obj["apiname"] = apiName_;
    obj["achieved"] = achieved_;
    obj["unlocktime"] = unlockTime_.toSecsSinceEpoch();
    obj["error"] = error_;
    return obj;
}

void SAchievementPlayer::fromJson(const QJsonObject &aObject) {
    QJsonObject obj;
    obj["type"] = className();
    apiName_ = aObject.value("apiname").toString();
    achieved_ = aObject.value("achieved").toInt();
    unlockTime_ = QDateTime::fromSecsSinceEpoch(aObject.value("unlocktime").toInt(), Qt::LocalTime);
    error_ = aObject.value("error").toString();
}

//SAchievementsPlayer SAchievementPlayer::load(const GameID &aAppId, const ProfileID &aProfileId, std::function<void (SAchievementsPlayer)> aCallback) {
//    return Sapi::load<SAchievementPlayer>(achievementsPlayerUrl(aAppId, aProfileId), onLoadPlayer, aCallback);
//}

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

const QString &SAchievementPlayer::error() const {
    return error_;
}

//QList<SAchievementPlayer> onLoadPlayer(const QByteArray &aByteArray) {
//    QList<SAchievementPlayer> list;
//    QJsonObject object = QJsonDocument::fromJson(aByteArray).object().value("playerstats").toObject();
//    if (object.value("success").toBool() == true) {
//        for(auto &&player: object.value("achievements").toArray()) {
//            list.append(SAchievementPlayer(player.toObject()));
//        }
//    } else {

//    }
//    return list;
//}

SAchievementsPlayer::SAchievementsPlayer(const GameID &aGameId, const ProfileID &aProfileId, QObject *aParent):
Sapi(aParent), gameId_(aGameId), profileId_(aProfileId) {
    RequestData *request = new RequestData();
    request->get(Sapi::Url::achievementsPlayer(gameId_, profileId_), false);
    QByteArray ba = request->reply();
    delete request;
    fromJson(QJsonDocument::fromJson(ba).object());
}

SAchievementsPlayer::SAchievementsPlayer(const QJsonObject &achievement, QObject *aParent): Sapi(aParent) {
    fromJson(achievement);
}

SAchievementsPlayer::SAchievementsPlayer(const SAchievementsPlayer &aPlayer): Sapi(aPlayer.parent()), QList<SAchievementPlayer>(aPlayer),
    gameId_(aPlayer.gameId_), profileId_(aPlayer.profileId_), success_(aPlayer.success_), error_(aPlayer.error_) {

}

SAchievementsPlayer &SAchievementsPlayer::operator=(const SAchievementsPlayer &aPlayer) {
    gameId_ = aPlayer.gameId_;
    profileId_ = aPlayer.profileId_;
    error_ = aPlayer.error_;
    success_ = aPlayer.success_;
    QList<SAchievementPlayer>::operator=(aPlayer);
    return *this;
}

bool SAchievementsPlayer::operator<(const SAchievementsPlayer &aPlayer) const {
    return gameId_ < aPlayer.gameId_;
}

bool SAchievementsPlayer::operator>(const SAchievementsPlayer &aPlayer) const {
    return gameId_ > aPlayer.gameId_;
}

bool SAchievementsPlayer::operator==(const SAchievementsPlayer &aPlayer) const {
    return gameId_ == aPlayer.gameId_ && profileId_ == aPlayer.profileId_ && error_ == aPlayer.error_ && success_ == aPlayer.success_ && QList<SAchievementPlayer>::operator==(aPlayer);
}

bool SAchievementsPlayer::operator!=(const SAchievementsPlayer &aPlayer) const {
    return gameId_ != aPlayer.gameId_ || profileId_ != aPlayer.profileId_ || error_ != aPlayer.error_ || success_ != aPlayer.success_ || QList<SAchievementPlayer>::operator!=(aPlayer);
}

QJsonObject SAchievementsPlayer::toJson() const {
    QJsonObject object;
    object["success"] = success_;
    object["error"] = error_;
    object["gameId"] = gameId_;
    object["profileId"] = profileId_;
    QJsonArray jAchievements;
    for(const SAchievementPlayer &achievement: *this) {
        jAchievements.append(achievement.toJson());
    }
    object["achievements"] = jAchievements;
    return object;
}

void SAchievementsPlayer::update(const ProfileID &aProfileId) {
    profileId_ = aProfileId;
    RequestData *request = new RequestData();
    request->get(Sapi::Url::achievementsPlayer(gameId_, profileId_), false);
    QByteArray ba = request->reply();
    delete request;
    fromJson(QJsonDocument::fromJson(ba).object());
}

void SAchievementsPlayer::fromJson(const QJsonObject &aObject) {
    success_ = aObject.value("playerstats").toObject().value("success").toBool();
    error_ = aObject.value("playerstats").toObject().value("error").toString();
    for(QJsonValue &&player: aObject.value("playerstats").toObject().value("achievements").toArray()) {
        append(SAchievementPlayer(player.toObject(), parent()));
    }
}

bool SAchievementsPlayer::success() const {
    return success_;
}

SAchievementsPlayer onLoadPlayer(QByteArray aByteArray)
{
    return SAchievementsPlayer(QJsonDocument::fromJson(aByteArray).object());
}

SAchievementsPlayer SAchievementsPlayer::load(const GameID &aGameId, const ProfileID &aProfileId, std::function<void(SAchievementsPlayer)> aCallback)
{
    return Sapi::loadOne<SAchievementsPlayer>(Sapi::Url::achievementsPlayer(aGameId, aProfileId), onLoadPlayer, aCallback);
    // RequestData *request = new RequestData();
    // request->get(Sapi::Url::achievementsPlayer(aGameId, aProfileId), aCallback != nullptr);

    // if (aCallback == nullptr) {
    //     QByteArray ba = request->reply();
    //     delete request;
    //     return SAchievementsPlayer(QJsonDocument::fromJson(ba).object());
    // } else {
    //     auto conn = std::make_shared<QMetaObject::Connection>();
    //     *conn = connect(request,
    //             &RequestData::s_finished,
    //             [aCallback, conn](RequestData *requestL) {
    //                 QObject::disconnect(*conn);
    //                 QByteArray ba = requestL->reply();
    //                 requestL->deleteLater();
    //                 aCallback(SAchievementsPlayer(QJsonDocument::fromJson(ba).object()));
    //             });

    // }
    // return SAchievementsPlayer();
}

const QString &SAchievementsPlayer::error() const {
    return error_;
}
