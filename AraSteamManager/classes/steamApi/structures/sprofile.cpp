#include "sprofile.h"
#include "classes/steamApi/sapi.h"
#include <QPainter>
#include <QJsonDocument>
#include <QJsonArray>

#define SProfileStart {
SProfile::SProfile(const QJsonObject &aProfile, QObject *aParent): Sapi(aParent) {
    fromJson(aProfile);
}

SProfile::SProfile(const SProfile &aProfile): Sapi(aProfile.parent()), steamId_(aProfile.steamId_), communityVisibilityState_(aProfile.communityVisibilityState_),
    profileState_(aProfile.profileState_), personaName_(aProfile.personaName_), lastLogoff_(aProfile.lastLogoff_), commentPermission_(aProfile.commentPermission_),
    profileUrl_(aProfile.profileUrl_), personaState_(aProfile.personaState_), primaryClanId_(aProfile.primaryClanId_), timeCreated_(aProfile.timeCreated_),
    personaStateFlags_(aProfile.personaStateFlags_), gameExtraInfo_(aProfile.gameExtraInfo_), gameId_(aProfile.gameId_), locCountryCode_(aProfile.locCountryCode_),
    locStateCode_(aProfile.locStateCode_), locCityId_(aProfile.locCityId_), realName_(aProfile.realName_), avatar_(aProfile.avatar_), avatarMedium_(aProfile.avatarMedium_),
    avatarFull_(aProfile.avatarFull_) {

}

SProfile &SProfile::operator=(const SProfile &aProfile) {
    steamId_                    = aProfile.steamId_;//!
    timeCreated_                = aProfile.timeCreated_;//!
    communityVisibilityState_   = aProfile.communityVisibilityState_;
    profileState_               = aProfile.profileState_;
    personaName_                = aProfile.personaName_;
    lastLogoff_                 = aProfile.lastLogoff_;
    commentPermission_          = aProfile.commentPermission_;
    profileUrl_                 = aProfile.profileUrl_;
    avatar_                     = aProfile.avatar_;
    avatarMedium_               = aProfile.avatarMedium_;
    avatarFull_                 = aProfile.avatarFull_;
    _pixmapAvatar               = aProfile._pixmapAvatar;
    _pixmapAvatarMedium         = aProfile._pixmapAvatarMedium;
    _pixmapAvatarFull           = aProfile._pixmapAvatarFull;
    personaState_               = aProfile.personaState_;
    primaryClanId_              = aProfile.primaryClanId_;
    personaStateFlags_          = aProfile.personaStateFlags_;
    gameExtraInfo_              = aProfile.gameExtraInfo_;
    gameId_                     = aProfile.gameId_;
    locCountryCode_             = aProfile.locCountryCode_;
    locStateCode_               = aProfile.locStateCode_;
    locCityId_                  = aProfile.locCityId_;
    realName_                   = aProfile.realName_;
    return *this;
}

bool SProfile::operator<(const SProfile &aProfile) const {
    return personaName_.toLower() < aProfile.personaName_.toLower();
}

bool SProfile::operator>(const SProfile &aProfile) const {
    return personaName_.toLower() > aProfile.personaName_.toLower();
}

bool SProfile::operator==(const SProfile &aProfile) const {
    return (steamId_ == aProfile.steamId_ &&
            timeCreated_                == aProfile.timeCreated_ &&
            communityVisibilityState_   == aProfile.communityVisibilityState_ &&
            profileState_               == aProfile.profileState_ &&
            personaName_                == aProfile.personaName_ &&
            lastLogoff_                 == aProfile.lastLogoff_ &&
            commentPermission_          == aProfile.commentPermission_ &&
            profileUrl_                 == aProfile.profileUrl_ &&
            avatar_                     == aProfile.avatar_ &&
            avatarMedium_               == aProfile.avatarMedium_ &&
            avatarFull_                 == aProfile.avatarFull_ &&
            _pixmapAvatar               == aProfile._pixmapAvatar &&
            _pixmapAvatarMedium         == aProfile._pixmapAvatarMedium &&
            _pixmapAvatarFull           == aProfile._pixmapAvatarFull &&
            personaState_               == aProfile.personaState_ &&
            primaryClanId_              == aProfile.primaryClanId_ &&
            personaStateFlags_          == aProfile.personaStateFlags_ &&
            gameExtraInfo_              == aProfile.gameExtraInfo_ &&
            gameId_                     == aProfile.gameId_ &&
            locCountryCode_             == aProfile.locCountryCode_ &&
            locStateCode_               == aProfile.locStateCode_ &&
            locCityId_                  == aProfile.locCityId_ &&
            realName_                   == aProfile.realName_);
}

bool SProfile::operator!=(const SProfile &aProfile) const {
    return !operator==(aProfile);
}

void SProfile::fromJson(const QJsonValue &aValue) {
    steamId_                    =   aValue.toObject().value("steamid").toString();
    timeCreated_                =   QDateTime::fromSecsSinceEpoch(aValue.toObject().value("timecreated").toInt(),Qt::LocalTime);
    communityVisibilityState_   =   aValue.toObject().value("communityvisibilitystate").toInt();
    profileState_               =   aValue.toObject().value("profilestate").toInt();
    personaName_                =   aValue.toObject().value("personaname").toString();
    lastLogoff_                 =   QDateTime::fromSecsSinceEpoch(aValue.toObject().value("lastlogoff").toInt(),Qt::LocalTime);
    commentPermission_          =   aValue.toObject().value("commentpermission").toInt();
    profileUrl_                 =   aValue.toObject().value("profileurl").toString();
    avatar_                     =   aValue.toObject().value("avatar").toString();
    avatarMedium_               =   aValue.toObject().value("avatarmedium").toString();
    avatarFull_                 =   aValue.toObject().value("avatarfull").toString();
    personaState_               =   aValue.toObject().value("personastate").toInt();
    primaryClanId_              =   aValue.toObject().value("primaryclanid").toString();
    personaStateFlags_          =   aValue.toObject().value("personastateflags").toInt();
    gameExtraInfo_              =   aValue.toObject().value("gameextrainfo").toString();
    gameId_                     =   aValue.toObject().value("gameid").toString();
    locCountryCode_             =   aValue.toObject().value("loccountrycode").toString();
    locStateCode_               =   aValue.toObject().value("locstatecode").toString();
    locCityId_                  =   aValue.toObject().value("loccityid").toInt();
    realName_                   =   aValue.toObject().value("realname").toString();
}

SProfile &SProfile::update() {
    return SProfile::operator=(SProfile::load(steamId_, LoadType::id));
}

QJsonObject SProfile::toJson() const {
    QJsonObject obj;
    obj["type"]                     = className();
    obj["steamid"]                  = steamId_;
    obj["timecreated"]              = timeCreated_.toSecsSinceEpoch();
    obj["communityvisibilitystate"] = communityVisibilityState_;
    obj["profilestate"]             = profileState_;
    obj["personaname"]              = personaName_;
    obj["lastlogoff"]               = lastLogoff_.toSecsSinceEpoch();
    obj["commentpermission"]        = commentPermission_;
    obj["profileurl"]               = profileUrl_;
    obj["avatar"]                   = avatar_;
    obj["avatarmedium"]             = avatarMedium_;
    obj["avatarfull"]               = avatarFull_;
    obj["personastate"]             = personaState_;
    obj["primaryclanid"]            = primaryClanId_;
    obj["personastateflags"]        = personaStateFlags_;
    obj["gameextrainfo"]            = gameExtraInfo_;
    obj["gameid"]                   = gameId_;
    obj["loccountrycode"]           = locCountryCode_;
    obj["locstatecode"]             = locStateCode_;
    obj["loccityid"]                = locCityId_;
    obj["realname"]                 = realName_;
    return obj;
}

QString getIdFromVanity(RequestData *aRequest) {
    return QJsonDocument::fromJson(aRequest->reply()).object().value("response").toObject().value("steamid").toString();
}

SProfile SProfile::loadVanity(const ProfileID &aProfileId, std::function<void (SProfile)> aCallback) {
    RequestData *request = new RequestData();
    request->get(Sapi::profilefromVanityUrl(aProfileId), aCallback != nullptr);
    if (aCallback == nullptr) {
        QString id = getIdFromVanity(request);
        delete request;
        return SProfile::loadId(id, nullptr);
    } else {
        connect(request,
                &RequestData::s_finished,
                request,
                [=](RequestData *requestL) {
                    QString id = getIdFromVanity(requestL);
                    requestL->deleteLater();
                    if (id != "") {
                        return SProfile::loadId(id, aCallback);
                    } else {
                        qWarning() << "error load profile id from vanity";
                        return SProfile();
                    }
                });
    }
    return SProfile();
}

SProfile SProfile::loadId(const ProfileID &aProfileId, std::function<void (SProfile)> aCallback) {
    RequestData *request = new RequestData();
    request->get(Sapi::profileUrl(aProfileId), aCallback != nullptr);
    if (aCallback == nullptr) {
        QJsonObject profile = QJsonDocument::fromJson(request->reply()).object().value("response").toObject().value("players").toArray().at(0).toObject();
        delete request;
        return SProfile(profile);
    } else {
        connect(request,
                &RequestData::s_finished,
                request,
                [=](RequestData *requestL) {
                    QJsonObject profile = QJsonDocument::fromJson(requestL->reply()).object().value("response").toObject().value("players").toArray().at(0).toObject();
                    requestL->deleteLater();
                    aCallback(std::move(SProfile(profile)));
                });
    }
    return SProfile();
}

SProfile SProfile::load(const ProfileID &aProfileId, const LoadType &aType, std::function<void (SProfile)> aCallback) {
    switch (aType) {
    case LoadType::id: {
        return SProfile::loadId(aProfileId, nullptr);
        break;
    }
    case LoadType::vanity: {
        return SProfile::loadVanity(aProfileId, aCallback);
        break;
    }
    default: {
        return SProfile();
    }
    }
}

SProfiles SProfile::load(ProfileIDs aProfileIds, std::function<void (SProfiles)> aCallback) {
    RequestData *request = new RequestData();
    SProfiles profiles;
    while (aProfileIds.count() > 0) {
        QStringList localId;
        for (int i = 0; i < 100; ++i) {
            if (aProfileIds.isEmpty()) {
                break;
            }
            localId << aProfileIds.takeFirst();
        }
        request->get(Sapi::profileUrl(localId), false);
        for(auto &&profile: QJsonDocument::fromJson(request->reply()).object().value("response").toObject().value("players").toArray()) {
            profiles.append(SProfile(profile.toObject()));
        }
    }
    delete request;
    if (aCallback != nullptr) {
        aCallback(profiles);
    }
    return profiles;
}

int SProfile::getLevel(const ProfileID &aProfileId) {
    RequestData request;
    request.get(Sapi::lvlUrl(aProfileId), false);
    return (QJsonDocument::fromJson(request.reply()).object()).value("response").toObject().value("player_level").toInt();
}

QPixmap SProfile::getFrameProfile(const ProfileID &aProfileId) {
    RequestData request;
    request.get(Sapi::avatarFrameUrl(aProfileId), false);
    QString frameUrl = (QJsonDocument::fromJson(request.reply()).object()).value("response").toObject().value("avatar_frame").toObject().value("image_small").toString();
    QPixmap pix = QPixmap::fromImage(loadImage(Sapi::frameProfileUrl(frameUrl), Paths::imagesProfiles(frameUrl + ".frame", "png"), QSize(64, 64)));
    return pix;
}

QMap<QString, SProfileEquippedItem> SProfile::getEquippedItems(const ProfileID &aProfileId) {
    QMap<QString, SProfileEquippedItem> map;
    RequestData request;
    request.get(Sapi::profileEquippedItemUrl(aProfileId));
    for (auto item: QJsonDocument::fromJson(request.reply()).object().value("response").toObject().keys()) {
        map.insert(item, SProfileEquippedItem(QJsonDocument::fromJson(request.reply()).object().value("response").toObject().value(item).toObject()));
    }
    return map;
}

QPixmap SProfile::getAvatarWithFrame(const QSize &aSize) const {
    QPixmap pixFrame = SProfile::getFrameProfile(steamId_);
    if (pixFrame.isNull()) {
        return pixmapAvatarMedium().scaled(aSize);
    }
    QPixmap avatarWithFrame(aSize);
    avatarWithFrame.fill(QColor(0,0,0,0));
    QPainter painter(&avatarWithFrame);
    painter.drawPixmap(QPoint((aSize.width() * ((c_frameLargerBy - 1) / 2)),
                              (aSize.height() * ((c_frameLargerBy - 1) / 2))),
                       pixmapAvatarMedium().scaled(aSize / c_frameLargerBy));
    painter.drawPixmap(QPoint(0, 0), pixFrame.scaled(aSize));
    painter.end();
    return avatarWithFrame;
}

QPixmap SProfile::pixmapAvatar() const {
    return QPixmap::fromImage(loadImage(_pixmapAvatar, avatar_, Paths::imagesProfiles(avatar_), QSize(32, 32)));
}

QPixmap SProfile::pixmapAvatarMedium() const {
    return QPixmap::fromImage(loadImage(_pixmapAvatarMedium, avatarMedium_, Paths::imagesProfiles(avatarMedium_), QSize(64, 64)));
}

QPixmap SProfile::pixmapAvatarFull() const {
    return QPixmap::fromImage(loadImage(_pixmapAvatarFull, avatarFull_, Paths::imagesProfiles(avatarFull_), QSize(128, 128)));
}

bool SProfile::isNull() const {
    return steamId_.isEmpty() && communityVisibilityState_ == 0 && profileState_ == 0 && personaName_.isEmpty() &&
            lastLogoff_.isNull() && commentPermission_ == 0 && profileUrl_.isEmpty() && personaState_ == 0 &&
            primaryClanId_.isEmpty() && timeCreated_.isNull() && personaStateFlags_ == 0 && gameExtraInfo_.isEmpty() &&
            gameId_.isEmpty() && locCountryCode_.isEmpty() && locStateCode_.isEmpty() && locCityId_ == 0 && realName_.isEmpty();
}

QColor SProfile::stateColor() const {
    if (!gameExtraInfo_.isEmpty()) {
        return QColor(137,183,83);
    } else
        switch (personaState_) {
        case 0:{
            return QColor(76,77,79);
        }
        case 1:{
            return QColor(87,203,222);
        }
        case 2:{
            return QColor(129,85,96);
        }
        case 3:{
            return QColor(70,120,142);
        }
        case 4:{
            return QColor(70,120,142);
        }
        case 5:{
            return Qt::darkMagenta;
        }
        case 6:{
            return Qt::darkMagenta;
        }
        }
    return Qt::red;
}

QStringList SProfile::statesList() {
    return QStringList {tr("В игре"),
                        tr("Не в сети"),
                        tr("В сети"),
                        tr("Не беспокоить"),
                        tr("Нет на месте"),
                        tr("Спит"),
                        tr("Ожидает обмена"),
                        tr("Хочет поиграть")};
}

QString SProfile::stateText() const {
    if (!gameExtraInfo_.isEmpty()) {
        return tr("В игре");
    } else
        switch (personaState_) {
        case 0:{
            return tr("Не в сети");
        }
        case 1:{
            return tr("В сети");
        }
        case 2:{
            return tr("Не беспокоить");
        }
        case 3:{
            return tr("Нет на месте");
        }
        case 4:{
            return tr("Спит");
        }
        case 5:{
            return tr("Ожидает обмена");
        }
        case 6:{
            return tr("Хочет поиграть");
        }
        }
    return tr("Ошибка");
}

QString SProfile::stateFullText() const {
    if (!gameExtraInfo_.isEmpty()) {
        return tr("В игре %1").arg(gameExtraInfo());
    } else
        switch (personaState_) {
        case 0:{
            if (lastLogoff() == QDateTime::fromSecsSinceEpoch(0, Qt::LocalTime)) {
                return tr("Не в сети");
            } else {
                return tr("Был в сети %1").arg(lastLogoff().toString(Settings::dateTimeFormat()));
            }
            return tr("Не в сети");
        }
        case 1:{
            return tr("В сети");
        }
        case 2:{
            return tr("Не беспокоить");
        }
        case 3:{
            return tr("Нет на месте");
        }
        case 4:{
            return tr("Спит");
        }
        case 5:{
            return tr("Ожидает обмена");
        }
        case 6:{
            return tr("Хочет поиграть");
        }
        }
    return tr("Ошибка");
}

QString SProfile::avatarUrl() const {
    return avatar_;
}

QString SProfile::avatarMediumUrl() const {
    return avatarMedium_;
}

QString SProfile::avatarFullUrl() const {
    return avatarFull_;
}

ProfileID SProfile::steamID() const {
    return steamId_;
}

int SProfile::communityVisibilityState() const {
    return communityVisibilityState_;
}

int SProfile::profileState() const {
    return profileState_;
}

QString SProfile::personaName() const {
    return personaName_;
}

QDateTime SProfile::lastLogoff() const {
    return lastLogoff_;
}

int SProfile::commentPermission() const {
    return commentPermission_;
}

QString SProfile::profileUrl() const {
    return profileUrl_;
}

int SProfile::personaState() const {
    return personaState_;
}

QString SProfile::primaryClanID() const {
    return primaryClanId_;
}

QDateTime SProfile::timeCreated() const {
    return timeCreated_;
}

int SProfile::personaStateFlags() const {
    return personaStateFlags_;
}

QString SProfile::gameExtraInfo() const {
    return gameExtraInfo_;
}

GameID SProfile::gameID() const {
    return gameId_.toInt();
}

QString SProfile::locCountryCode() const {
    return locCountryCode_;
}

QString SProfile::locStateCode() const {
    return locStateCode_;
}

int SProfile::locCityID() const {
    return locCityId_;
}

QString SProfile::realName() const {
    return realName_;
}
#define SProfileEnd }

SProfileEquippedItem::SProfileEquippedItem() {

}

SProfileEquippedItem::SProfileEquippedItem(const QJsonObject &aObject) {
    fromJson(aObject);
}

QJsonObject SProfileEquippedItem::toJson() const {
    QJsonObject object;
    object["communityitemid"] = communityitemid;
    object["image_large"] = image_large;
    object["name"] = name;
    object["item_title"] = item_title;
    object["item_description"] = item_description;
    object["appid"] = appid;
    object["item_type"] = item_type;
    object["item_class"] = item_class;
    return object;
}

void SProfileEquippedItem::fromJson(const QJsonObject &aObject) {
    communityitemid = aObject.value("communityitemid").toString();
    image_large = aObject.value("image_large").toString();
    name = aObject.value("name").toString();
    item_title = aObject.value("item_title").toString();
    item_description = aObject.value("item_description").toString();
    appid = aObject.value("appid").toInt();
    item_type = aObject.value("item_type").toInt();
    item_class = aObject.value("item_class").toInt();
}
