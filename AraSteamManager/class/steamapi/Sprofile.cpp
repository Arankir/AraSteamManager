#include "Sprofile.h"

#define SProfileStart {
SProfile &SProfile::operator=(const SProfile &aProfile) {
    _status                     = aProfile._status;
    _error                      = aProfile._error;

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

const bool &SProfile::operator<(const SProfile &aProfile) {
    static const bool b = _personaName.toLower() < aProfile._personaName.toLower();
    return b;
}

void SProfile::load(bool aParallel) {
    _request.get(profileUrl(_steamID), aParallel);
}

void SProfile::onLoad() {
    parse(QJsonDocument::fromJson(_request.getReply()).object().value("response").toObject().value("players").toArray().at(0).toObject());
    emit s_finished(this);
    emit s_finished();
}

void SProfile::parse(const QJsonObject &aProfile) {
    _steamID =                                                    aProfile.value("steamid").toString();//!
    _timeCreated =                  QDateTime::fromSecsSinceEpoch(aProfile.value("timecreated").toInt(),Qt::LocalTime);//!
    _communityVisibilityState =                                   aProfile.value("communityvisibilitystate").toInt();
    _profileState =                                               aProfile.value("profilestate").toInt();
    _personaName =                                                aProfile.value("personaname").toString();
    _lastLogoff =                   QDateTime::fromSecsSinceEpoch(aProfile.value("lastlogoff").toInt(),Qt::LocalTime);
    _commentPermission =                                          aProfile.value("commentpermission").toInt();
    _profileUrl =                                                 aProfile.value("profileurl").toString();
    _avatar =                                                     aProfile.value("avatar").toString();
    _avatarMedium =                                               aProfile.value("avatarmedium").toString();
    _avatarFull =                                                 aProfile.value("avatarfull").toString();
    _personaState =                                               aProfile.value("personastate").toInt();
    _primaryClanID =                                              aProfile.value("primaryclanid").toString();
    _personaStateFlags =                                          aProfile.value("personastateflags").toInt();
    _gameExtraInfo =                                              aProfile.value("gameextrainfo").toString();
    _gameID =                                                     aProfile.value("gameid").toString();
    _locCountryCode =                                             aProfile.value("loccountrycode").toString();
    _locStateCode =                                               aProfile.value("locstatecode").toString();
    _locCityID =                                                  aProfile.value("loccityid").toInt();
    _realName =                                                   aProfile.value("realname").toString();
}

SProfile &SProfile::update(bool aParallel) {
    load(aParallel);
    return *this;
}

QPixmap SProfile::getPixmapAvatar() {
    return loadPixmap(_pixmapAvatar, _avatar, QSize(32, 32));
}

QPixmap SProfile::getPixmapAvatarMedium() {
    return loadPixmap(_pixmapAvatarMedium, _avatarMedium, QSize(64, 64));
}

QPixmap SProfile::getPixmapAvatarFull() {
    return loadPixmap(_pixmapAvatarFull, _avatarFull, QSize(128, 128));
}

QPixmap SProfile::loadPixmap(QPixmap &aPixmap, const QString &aUrl, QSize aSize) {
    if (aPixmap.isNull()) {
        if (!aUrl.isEmpty()) {
            QString savePath = Paths::imagesProfiles(aUrl);
            if(!QFile::exists(savePath)) {
                RequestImage *img = new RequestImage(aUrl, savePath, true, this);
                QEventLoop loop;
                connect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
                loop.exec();
                disconnect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
                aPixmap = img->getPixmap();
                delete img;
            } else {
                aPixmap = QPixmap(savePath);
            }
        } else {
            aPixmap = QPixmap(Images::missingImage()).scaled(aSize);
        }
    }
    return aPixmap;
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
    if (QJsonDocument::fromJson(_request.getReply()).object().value("response").toObject().value("steamid").toString() != "") {
        QString id = QJsonDocument::fromJson(_request.getReply()).object().value("response").toObject().value("steamid").toString();
        _request.get(profileUrl(id), false);
    }
    add(QJsonDocument::fromJson(_request.getReply()).object().value("response").toObject().value("players").toArray());
}

SProfiles &SProfiles::add(const QJsonArray &aProfiles) {
    if(aProfiles.size() > 0) {
        for (auto profile: aProfiles) {
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
    _status = aProfile._status;
    _error = aProfile._error;

    _profile = aProfile._profile;
    _ids = aProfile._ids;
    return *this;
}
#define SProfilesEnd }
