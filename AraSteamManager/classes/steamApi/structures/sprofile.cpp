#include "sprofile.h"

#define SProfileStart {
SProfile::SProfile(const QJsonObject &aProfile, QObject *aParent): Sapi(aParent) {
    fromJson(aProfile);
}

SProfile &SProfile::operator=(const SProfile &aProfile) {
    _steamID                    = aProfile._steamID;//!
    _timeCreated                = aProfile._timeCreated;//!
    _communityVisibilityState   = aProfile._communityVisibilityState;
    _profileState               = aProfile._profileState;
    _personaName                = aProfile._personaName;
    _lastLogoff                 = aProfile._lastLogoff;
    _commentPermission          = aProfile._commentPermission;
    _profileUrl                 = aProfile._profileUrl;
    _avatar                     = aProfile._avatar;
    _avatarMedium               = aProfile._avatarMedium;
    _avatarFull                 = aProfile._avatarFull;
//    _pixmapAvatar               = aProfile._pixmapAvatar;
//    _pixmapAvatarMedium         = aProfile._pixmapAvatarMedium;
//    _pixmapAvatarFull           = aProfile._pixmapAvatarFull;
    _personaState               = aProfile._personaState;
    _primaryClanID              = aProfile._primaryClanID;
    _personaStateFlags          = aProfile._personaStateFlags;
    _gameExtraInfo              = aProfile._gameExtraInfo;
    _gameID                     = aProfile._gameID;
    _locCountryCode             = aProfile._locCountryCode;
    _locStateCode               = aProfile._locStateCode;
    _locCityID                  = aProfile._locCityID;
    _realName                   = aProfile._realName;
    return *this;
}

bool SProfile::operator<(const SProfile &aProfile) const {
    return _personaName.toLower() < aProfile._personaName.toLower();
}

bool SProfile::operator>(const SProfile &aProfile) const {
    return _personaName.toLower() > aProfile._personaName.toLower();
}

bool SProfile::operator==(const SProfile &aProfile) const {
    return (_steamID == aProfile._steamID &&
            _timeCreated                == aProfile._timeCreated &&
            _communityVisibilityState   == aProfile._communityVisibilityState &&
            _profileState               == aProfile._profileState &&
            _personaName                == aProfile._personaName &&
            _lastLogoff                 == aProfile._lastLogoff &&
            _commentPermission          == aProfile._commentPermission &&
            _profileUrl                 == aProfile._profileUrl &&
            _avatar                     == aProfile._avatar &&
            _avatarMedium               == aProfile._avatarMedium &&
            _avatarFull                 == aProfile._avatarFull &&
//            _pixmapAvatar               == aProfile._pixmapAvatar &&
//            _pixmapAvatarMedium         == aProfile._pixmapAvatarMedium &&
//            _pixmapAvatarFull           == aProfile._pixmapAvatarFull &&
            _personaState               == aProfile._personaState &&
            _primaryClanID              == aProfile._primaryClanID &&
            _personaStateFlags          == aProfile._personaStateFlags &&
            _gameExtraInfo              == aProfile._gameExtraInfo &&
            _gameID                     == aProfile._gameID &&
            _locCountryCode             == aProfile._locCountryCode &&
            _locStateCode               == aProfile._locStateCode &&
            _locCityID                  == aProfile._locCityID &&
            _realName                   == aProfile._realName);
}

bool SProfile::operator!=(const SProfile &aProfile) const {
    return !operator==(aProfile);
}

void SProfile::fromJson(const QJsonValue &aValue) {
    _steamID                    =   aValue.toObject().value("steamid").toString();//!
    _timeCreated                =   QDateTime::fromSecsSinceEpoch(aValue.toObject().value("timecreated").toInt(),Qt::LocalTime);//!
    _communityVisibilityState   =   aValue.toObject().value("communityvisibilitystate").toInt();
    _profileState               =   aValue.toObject().value("profilestate").toInt();
    _personaName                =   aValue.toObject().value("personaname").toString();
    _lastLogoff                 =   QDateTime::fromSecsSinceEpoch(aValue.toObject().value("lastlogoff").toInt(),Qt::LocalTime);
    _commentPermission          =   aValue.toObject().value("commentpermission").toInt();
    _profileUrl                 =   aValue.toObject().value("profileurl").toString();
    _avatar                     =   aValue.toObject().value("avatar").toString();
    _avatarMedium               =   aValue.toObject().value("avatarmedium").toString();
    _avatarFull                 =   aValue.toObject().value("avatarfull").toString();
    _personaState               =   aValue.toObject().value("personastate").toInt();
    _primaryClanID              =   aValue.toObject().value("primaryclanid").toString();
    _personaStateFlags          =   aValue.toObject().value("personastateflags").toInt();
    _gameExtraInfo              =   aValue.toObject().value("gameextrainfo").toString();
    _gameID                     =   aValue.toObject().value("gameid").toString();
    _locCountryCode             =   aValue.toObject().value("loccountrycode").toString();
    _locStateCode               =   aValue.toObject().value("locstatecode").toString();
    _locCityID                  =   aValue.toObject().value("loccityid").toInt();
    _realName                   =   aValue.toObject().value("realname").toString();
}

SProfile &SProfile::update() {
    return SProfile::operator=(SProfile::load(_steamID, SProfileRequestType::id));
}

QJsonObject SProfile::toJson() const {
    QJsonObject obj;
    obj["type"]                     = className();
    obj["steamid"]                  = _steamID;
    obj["timecreated"]              = _timeCreated.toSecsSinceEpoch();
    obj["communityvisibilitystate"] = _communityVisibilityState;
    obj["profilestate"]             = _profileState;
    obj["personaname"]              = _personaName;
    obj["lastlogoff"]               = _lastLogoff.toSecsSinceEpoch();
    obj["commentpermission"]        = _commentPermission;
    obj["profileurl"]               = _profileUrl;
    obj["avatar"]                   = _avatar;
    obj["avatarmedium"]             = _avatarMedium;
    obj["avatarfull"]               = _avatarFull;
    obj["personastate"]             = _personaState;
    obj["primaryclanid"]            = _primaryClanID;
    obj["personastateflags"]        = _personaStateFlags;
    obj["gameextrainfo"]            = _gameExtraInfo;
    obj["gameid"]                   = _gameID;
    obj["loccountrycode"]           = _locCountryCode;
    obj["locstatecode"]             = _locStateCode;
    obj["loccityid"]                = _locCityID;
    obj["realname"]                 = _realName;
    return obj;
}

QString getIdFromVanity(RequestData *aRequest) {
    return QJsonDocument::fromJson(aRequest->reply()).object().value("response").toObject().value("steamid").toString();
}

SProfile SProfile::loadVanity(const QString &aId, std::function<void (SProfile)> aCallback) {
    RequestData *request = new RequestData();
    request->get(Sapi::profilefromVanityUrl(aId), aCallback != nullptr);
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

SProfile SProfile::loadId(const QString &aId, std::function<void (SProfile)> aCallback) {
    RequestData *request = new RequestData();
    request->get(Sapi::profileUrl(aId), aCallback != nullptr);
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

SProfile SProfile::load(const QString &aId, const SProfileRequestType &aType, std::function<void (SProfile)> aCallback) {
    switch (aType) {
    case SProfileRequestType::id: {
        return SProfile::loadId(aId, nullptr);
        break;
    }
    case SProfileRequestType::vanity: {
        return SProfile::loadVanity(aId, aCallback);
        break;
    }
    }
    return SProfile();
}

QList<SProfile> SProfile::load(QStringList aIds, std::function<void (QList<SProfile>)> aCallback) {
    RequestData *request = new RequestData();
    QList<SProfile> profiles;
    while (aIds.count() > 0) {
        QStringList localId;
        for (int i = 0; i < 100; ++i) {
            if (aIds.isEmpty()) {
                break;
            }
            localId << aIds.takeFirst();
        }
        request->get(Sapi::profileUrl(localId), false);
        for(auto &&profile: QJsonDocument::fromJson(request->reply()).object().value("response").toObject().value("players").toArray()) {
            profiles.append(std::move(SProfile(profile.toObject())));
        }
    }
    delete request;
    if (aCallback != nullptr) {
        aCallback(profiles);
    }
    return profiles;
}

int SProfile::getLevel(const QString &aSteamId) {
    RequestData request;
    request.get(Sapi::lvlUrl(aSteamId), false);
    return (QJsonDocument::fromJson(request.reply()).object()).value("response").toObject().value("player_level").toInt();
}

QPixmap SProfile::pixmapAvatar() const {
    return cLoadPixmap(_avatar, Paths::imagesProfiles(_avatar), QSize(32, 32));
//    return loadPixmap(_pixmapAvatar, _avatar, Paths::imagesProfiles(_avatar), QSize(32, 32));
}

QPixmap SProfile::pixmapAvatarMedium() const {
    return cLoadPixmap(_avatarMedium, Paths::imagesProfiles(_avatarMedium), QSize(64, 64));
//    return loadPixmap(_pixmapAvatarMedium, _avatarMedium, Paths::imagesProfiles(_avatarMedium), QSize(64, 64));
}

QPixmap SProfile::pixmapAvatarFull() const {
    return cLoadPixmap(_avatarFull, Paths::imagesProfiles(_avatarFull), QSize(128, 128));
//    return loadPixmap(_pixmapAvatarFull, _avatarFull, Paths::imagesProfiles(_avatarFull), QSize(128, 128));
}

QColor SProfile::stateColor() const {
    if (!_gameExtraInfo.isEmpty()) {
        return QColor(137,183,83);
    } else
        switch (_personaState) {
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

QString SProfile::stateText() const {
    if (!_gameExtraInfo.isEmpty()) {
        return tr("В игре");
    } else
        switch (_personaState) {
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
#define SProfileEnd }
