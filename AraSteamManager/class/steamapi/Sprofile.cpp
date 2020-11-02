#include "Sprofile.h"

#define SProfileStart {
SProfile::SProfile(const QJsonObject &aProfile, QObject *aParent): Sapi(aParent) {
    fromJson(aProfile);
}

SProfile &SProfile::operator=(const SProfile &aProfile) {
    Sapi::operator=(aProfile);
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
    _pixmapAvatar               = aProfile._pixmapAvatar;
    _pixmapAvatarMedium         = aProfile._pixmapAvatarMedium;
    _pixmapAvatarFull           = aProfile._pixmapAvatarFull;
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

bool SProfile::operator<(const SProfile &aProfile) {
    return _personaName.toLower() < aProfile._personaName.toLower();
}

void SProfile::load(bool aParallel) {
    _request.get(profileUrl(_steamID), aParallel);
}

void SProfile::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.getReply()).object().value("response").toObject().value("players").toArray().at(0).toObject());
    emit s_finished(this);
    emit s_finished();
}

void SProfile::fromJson(const QJsonValue &aValue) {
    _steamID =                                                    aValue.toObject().value("steamid").toString();//!
    _timeCreated =                  QDateTime::fromSecsSinceEpoch(aValue.toObject().value("timecreated").toInt(),Qt::LocalTime);//!
    _communityVisibilityState =                                   aValue.toObject().value("communityvisibilitystate").toInt();
    _profileState =                                               aValue.toObject().value("profilestate").toInt();
    _personaName =                                                aValue.toObject().value("personaname").toString();
    _lastLogoff =                   QDateTime::fromSecsSinceEpoch(aValue.toObject().value("lastlogoff").toInt(),Qt::LocalTime);
    _commentPermission =                                          aValue.toObject().value("commentpermission").toInt();
    _profileUrl =                                                 aValue.toObject().value("profileurl").toString();
    _avatar =                                                     aValue.toObject().value("avatar").toString();
    _avatarMedium =                                               aValue.toObject().value("avatarmedium").toString();
    _avatarFull =                                                 aValue.toObject().value("avatarfull").toString();
    _personaState =                                               aValue.toObject().value("personastate").toInt();
    _primaryClanID =                                              aValue.toObject().value("primaryclanid").toString();
    _personaStateFlags =                                          aValue.toObject().value("personastateflags").toInt();
    _gameExtraInfo =                                              aValue.toObject().value("gameextrainfo").toString();
    _gameID =                                                     aValue.toObject().value("gameid").toString();
    _locCountryCode =                                             aValue.toObject().value("loccountrycode").toString();
    _locStateCode =                                               aValue.toObject().value("locstatecode").toString();
    _locCityID =                                                  aValue.toObject().value("loccityid").toInt();
    _realName =                                                   aValue.toObject().value("realname").toString();
}

SProfile &SProfile::update(bool aParallel) {
    load(aParallel);
    return *this;
}

QPixmap SProfile::getPixmapAvatar() {
    return loadPixmap(_pixmapAvatar, _avatar, Paths::imagesProfiles(_avatar), QSize(32, 32));
}

QPixmap SProfile::getPixmapAvatarMedium() {
    return loadPixmap(_pixmapAvatarMedium, _avatarMedium, Paths::imagesProfiles(_avatarMedium), QSize(64, 64));
}

QPixmap SProfile::getPixmapAvatarFull() {
    return loadPixmap(_pixmapAvatarFull, _avatarFull, Paths::imagesProfiles(_avatarFull), QSize(128, 128));
}
#define SProfileEnd }
#define SProfilesStart {
SProfiles::SProfiles(const QStringList &aIds, bool aParallel, ProfileUrlType aType, QObject *aParent): Sapi(aParent) {
    load(aIds, aParallel, aType);
}

SProfiles::SProfiles(const QJsonArray &aProfiles, QObject *aParent): Sapi(aParent) {
    add(aProfiles);
}

SProfiles &SProfiles::load(QStringList aIds, bool aParallel, ProfileUrlType aType) {
    _ids = aIds;
    _type = aType;
    clear();
    if (_type == ProfileUrlType::vanity) {
        for (auto id: _ids) {
            _request.get(profilefromVanityUrl(id), aParallel);
        }
    } else {
        QStringList ids = _ids;
        while (ids.count() > 0) {
            QStringList localId;
            for (int i = 0; i < 100; ++i) {
                if (ids.isEmpty()) {
                    break;
                }
                localId << ids.takeFirst();
            }
            _request.get(profileUrl(localId), aParallel);
        }
    }
    emit s_finished(this);
    emit s_finished();
    return *this;
}

void SProfiles::onLoad() {
    fromJson(QJsonDocument::fromJson(_request.getReply()).object().value("response"));
}

void SProfiles::fromJson(const QJsonValue &aValue) {
    if (aValue.toObject().value("steamid").toString() != "") {
        QString id = aValue.toObject().value("steamid").toString();
        _request.get(profileUrl(id), false);
    }
    add(aValue.toObject().value("players").toArray());
}

SProfiles &SProfiles::add(const QJsonArray &aProfiles) {
    if(aProfiles.size() > 0) {
        for (const auto &profile: aProfiles) {
            _profile.append(std::move(SProfile(profile.toObject())));
        }
        _status = StatusValue::success;
    }
    else {
        _status = StatusValue::error;
        _error = tr("profile is not exist");
    }
    return *this;
}

SProfiles &SProfiles::update(bool aParallel) {
    return load(_ids, aParallel, ProfileUrlType::id);
}

SProfiles &SProfiles::sort() {
    std::sort(_profile.begin(), _profile.end(), [](const SProfile &s1, const SProfile &s2)-> const bool {
                                                    return s1._personaName.compare(s2._personaName, Qt::CaseInsensitive) < 0;
                                                });
    return *this;
}

SProfiles &SProfiles::clear() {
    _profile.clear();
    _status = StatusValue::none;
    return *this;
}

SProfiles &SProfiles::operator=(const SProfiles &aProfile) {
    Sapi::operator=(aProfile);
    _profile = aProfile._profile;
    _ids = aProfile._ids;
    return *this;
}
#define SProfilesEnd }
