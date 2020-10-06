#include "Sprofile.h"

#define SProfileStart {
void SProfile::set(QJsonObject &aProfile) {
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

void SProfile::loading(bool aParallel) {
    QString url = "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+Settings::getKey()+"&steamids="+_steamID;
    if (aParallel) {
        RequestData *request = new RequestData(url, true);
        connect(request, &RequestData::s_finished, this, &SProfile::loadURL);
    } else {
        RequestData request(url, false);
        QJsonObject doc = QJsonDocument::fromJson(request.getAnswer()).object().value("response").toObject().value("players").toArray().at(0).toObject();
        set(doc);
        emit s_finished(this);
        emit s_finished();
    }
}

void SProfile::loadURL(RequestData *aRequest){
    QJsonDocument localSummaries = QJsonDocument::fromJson(aRequest->getAnswer());
    QJsonObject obj = localSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject();
    set(obj);
    disconnect(aRequest, &RequestData::s_finished, this, &SProfile::loadURL);
    aRequest->deleteLater();
    emit s_finished(this);
    emit s_finished();
}

SProfile::SProfile(QJsonObject &aProfile, QObject *aParent): QObject(aParent), _steamID(aProfile.value("steamid").toString()),
_communityVisibilityState(aProfile.value("communityvisibilitystate").toInt()), _profileState(aProfile.value("profilestate").toInt()),
_personaName(aProfile.value("personaname").toString()), _lastLogoff(QDateTime::fromSecsSinceEpoch(aProfile.value("lastlogoff").toInt(),Qt::LocalTime)),
_commentPermission(aProfile.value("commentpermission").toInt()), _profileUrl(aProfile.value("profileurl").toString()), _personaState(aProfile.value("personastate").toInt()),
_primaryClanID(aProfile.value("primaryclanid").toString()), _timeCreated(QDateTime::fromSecsSinceEpoch(aProfile.value("timecreated").toInt(),Qt::LocalTime)),
_personaStateFlags(aProfile.value("personastateflags").toInt()), _gameExtraInfo(aProfile.value("gameextrainfo").toString()), _gameID(aProfile.value("gameid").toString()),
_locCountryCode(aProfile.value("loccountrycode").toString()), _locStateCode(aProfile.value("locstatecode").toString()), _locCityID(aProfile.value("loccityid").toInt()),
_realName(aProfile.value("realname").toString()), _avatar(aProfile.value("avatar").toString()), _avatarMedium(aProfile.value("avatarmedium").toString()),
_avatarFull(aProfile.value("avatarfull").toString()) {

}

SProfile::SProfile(QObject *aParent): QObject(aParent), _steamID(""),
    _communityVisibilityState(0), _profileState(0),
    _personaName(""), _lastLogoff(QDateTime::fromSecsSinceEpoch(0, Qt::LocalTime)),
    _commentPermission(0), _profileUrl(""), _personaState(0),
    _primaryClanID(""), _timeCreated(QDateTime::fromSecsSinceEpoch(0, Qt::LocalTime)),
    _personaStateFlags(0), _gameExtraInfo(""), _gameID(""),
    _locCountryCode(""), _locStateCode(""), _locCityID(0),
    _realName(""), _avatar(""), _avatarMedium(""),
    _avatarFull("") {
}

SProfile::~SProfile() {

}

void SProfile::update(bool aParallel) {
    loading(aParallel);
}

QPixmap SProfile::getPixmapAvatar() {
    if (_pixmapAvatar.isNull()) {
        QString savePath = _setting.getPathForImagesProfiles(_avatar);
        if(!QFile::exists(savePath)) {
            RequestImage *img = new RequestImage(_avatar, savePath, true, this);
            QEventLoop loop;
            connect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
            loop.exec();
            disconnect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
            _pixmapAvatar = img->getPixmap();
            delete img;
        } else {
            _pixmapAvatar = QPixmap(savePath);
        }
    }
    return _pixmapAvatar;
}

QPixmap SProfile::getPixmapAvatarMedium() {
    if (_pixmapAvatarMedium.isNull()) {
        QString savePath = _setting.getPathForImagesProfiles(_avatarMedium);
        if(!QFile::exists(savePath)) {
            RequestImage *img = new RequestImage(_avatarMedium, savePath, true, this);
            QEventLoop loop;
            connect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
            loop.exec();
            disconnect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
            _pixmapAvatarMedium = img->getPixmap();
            delete img;
        } else {
            _pixmapAvatarMedium = QPixmap(savePath);
        }
    }
    return _pixmapAvatarMedium;
}

QPixmap SProfile::getPixmapAvatarFull() {
    if (_pixmapAvatarFull.isNull()) {
        QString savePath = _setting.getPathForImagesProfiles(_avatarFull);
        if(!QFile::exists(savePath)) {
            RequestImage *img = new RequestImage(_avatarFull, savePath, true, this);
            QEventLoop loop;
            connect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
            loop.exec();
            disconnect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
            _pixmapAvatarFull = img->getPixmap();
            delete img;
        } else {
            _pixmapAvatarFull = QPixmap(savePath);
        }
    }
    return _pixmapAvatarFull;
}

SProfile::SProfile(const SProfile &aProfile): QObject(aProfile.parent()), _steamID(aProfile._steamID), _communityVisibilityState(aProfile._communityVisibilityState),
_profileState(aProfile._profileState), _personaName(aProfile._personaName), _lastLogoff(aProfile._lastLogoff), _commentPermission(aProfile._commentPermission),
_profileUrl(aProfile._profileUrl), _personaState(aProfile._personaState), _primaryClanID(aProfile._primaryClanID), _timeCreated(aProfile._timeCreated),
_personaStateFlags(aProfile._personaStateFlags), _gameExtraInfo(aProfile._gameExtraInfo), _gameID(aProfile._gameID), _locCountryCode(aProfile._locCountryCode),
_locStateCode(aProfile._locStateCode), _locCityID(aProfile._locCityID), _realName(aProfile._realName), _avatar(aProfile._avatar), _avatarMedium(aProfile._avatarMedium),
_avatarFull(aProfile._avatarFull), _pixmapAvatar(aProfile._pixmapAvatar), _pixmapAvatarMedium(aProfile._pixmapAvatarMedium), _pixmapAvatarFull(aProfile._pixmapAvatarFull) {

}

SProfile &SProfile::operator=(const SProfile &aProfile){
    _steamID = aProfile._steamID;//!
    _timeCreated = aProfile._timeCreated;//!
    _communityVisibilityState = aProfile._communityVisibilityState;
    _profileState = aProfile._profileState;
    _personaName = aProfile._personaName;
    _lastLogoff = aProfile._lastLogoff;
    _commentPermission = aProfile._commentPermission;
    _profileUrl = aProfile._profileUrl;
    _avatar = aProfile._avatar;
    _avatarMedium = aProfile._avatarMedium;
    _avatarFull = aProfile._avatarFull;
    _pixmapAvatar = aProfile._pixmapAvatar;
    _pixmapAvatarMedium = aProfile._pixmapAvatarMedium;
    _pixmapAvatarFull = aProfile._pixmapAvatarFull;
    _personaState = aProfile._personaState;
    _primaryClanID = aProfile._primaryClanID;
    _personaStateFlags = aProfile._personaStateFlags;
    _gameExtraInfo = aProfile._gameExtraInfo;
    _gameID = aProfile._gameID;
    _locCountryCode = aProfile._locCountryCode;
    _locStateCode = aProfile._locStateCode;
    _locCityID = aProfile._locCityID;
    _realName = aProfile._realName;
    return *this;
}

const bool &SProfile::operator<(const SProfile &aProfile){
    static const bool b = _personaName.toLower() < aProfile._personaName.toLower();
    return b;
}
#define SProfileEnd }
#define SProfilesStart {
SProfiles::SProfiles(const QString &aId, bool aParallel, ProfileUrlType aType, QObject *aParent): QObject(aParent), _request(new RequestData()), _id(aId) {
    load(aParallel, aType);
}

SProfiles::SProfiles(QJsonDocument &aDocprofiles, QObject *aParent): QObject(aParent), _request(new RequestData()) {
    set(aDocprofiles);
}

SProfiles::SProfiles(QJsonArray &aProfiles, QObject *aParent): QObject(aParent), _request(new RequestData()) {
    set(aProfiles);
}

SProfiles::SProfiles(QJsonObject &aProfile, QObject *aParent): QObject(aParent), _request(new RequestData()) {
    set(aProfile);
}

SProfiles::SProfiles(QObject *aParent): QObject(aParent), _request(new RequestData()) {

}

SProfiles::~SProfiles(){
    delete _request;
}

void SProfiles::set(const QString &aId, bool aParallel, ProfileUrlType aType) {
    _id = std::move(aId);
    load(aParallel, aType);
}

void SProfiles::set(QJsonDocument &aProfiles) {
    QJsonArray arr = aProfiles.object().value("response").toObject().value("players").toArray();
    set(arr);
}

void SProfiles::set(QJsonArray &aProfiles) {
    clear();
    if(aProfiles.size() > 0) {
        for (auto profile: aProfiles) {
            QJsonObject obj = profile.toObject();
            _profile.append(std::move(SProfile(obj)));
        }
        _status = StatusValue::success;
    }
    else {
        _status = StatusValue::error;
        _error = "profile is not exist";
    }
}

void SProfiles::set(QJsonObject &aPlayer) {
    clear();
    _profile.append(aPlayer);
    _status = StatusValue::success;
}

QString SProfiles::getSteamid(int aIndex) {
    return _profile[aIndex]._steamID;
}

int SProfiles::getCommunityvisibilitystate(int aIndex) {
    return _profile[aIndex]._communityVisibilityState;
}

int SProfiles::getProfilestate(int aIndex) {
    return _profile[aIndex]._profileState;
}

QString SProfiles::getPersonaname(int aIndex) const {
    return _profile[aIndex]._personaName;
}

QDateTime SProfiles::getLastlogoff(int aIndex) {
    return _profile[aIndex]._lastLogoff;
}

int SProfiles::getCommentpermission(int aIndex) {
    return _profile[aIndex]._commentPermission;
}

QString SProfiles::getProfileurl(int aIndex) {
    return _profile[aIndex]._profileUrl;
}

QPixmap SProfiles::getAvatar(int aIndex) {
    return _profile[aIndex].getPixmapAvatar();
}

QPixmap SProfiles::getAvatarmedium(int aIndex) {
    return _profile[aIndex].getPixmapAvatarMedium();
}

QPixmap SProfiles::getAvatarfull(int aIndex) {
    return _profile[aIndex].getPixmapAvatarFull();
}

int SProfiles::getPersonastate(int aIndex) {
    return _profile[aIndex]._personaState;
}

QString SProfiles::getPrimaryclanid(int aIndex) {
    return _profile[aIndex]._primaryClanID;
}

QDateTime SProfiles::getTimecreated(int aIndex) {
    return _profile[aIndex]._timeCreated;
}

int SProfiles::getPersonastateflags(int aIndex) {
    return _profile[aIndex]._personaStateFlags;
}

QString SProfiles::getGameextrainfo(int aIndex) {
    return _profile[aIndex]._gameExtraInfo;
}

QString SProfiles::getGameid(int aIndex) {
    return _profile[aIndex]._gameID;
}

QString SProfiles::getLoccountrycode(int aIndex) {
    return _profile[aIndex]._locCountryCode;
}

QString SProfiles::getLocstatecode(int aIndex) {
    return _profile[aIndex]._locStateCode;
}

int SProfiles::getLoccityid(int aIndex) {
    return _profile[aIndex]._locCityID;
}

QString SProfiles::getRealname(int aIndex) {
    return _profile[aIndex]._realName;
}

SProfile SProfiles::getProfile(int aIndex) {
    return _profile[aIndex];
}

StatusValue SProfiles::getStatus() {
    return _status;
}

QString SProfiles::getError() {
    return _error;
}

int SProfiles::getCount() {
    return _profile.size();
}

void SProfiles::loadVanity(RequestData *aRequest) {
    disconnect(_request, &RequestData::s_finished, this, &SProfiles::loadVanity);
    connect(_request, &RequestData::s_finished, this, &SProfiles::loadURL);
    _id = QJsonDocument::fromJson(aRequest->getAnswer()).object().value("response").toObject().value("steamid").toString();
    _request->get("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+Settings::getKey()+"&steamids="+_id);
}

void SProfiles::loadURL(RequestData *aRequest){
    disconnect(_request, &RequestData::s_finished, this, &SProfiles::loadURL);
    QJsonDocument doc = QJsonDocument::fromJson(aRequest->getAnswer());
    set(doc);
    aRequest->deleteLater();
    emit s_finished(this);
    emit s_finished();
}

void SProfiles::load(bool aParallel, ProfileUrlType aType) {
    if (aParallel) {
        if (aType == ProfileUrlType::vanity) {
            connect(_request, &RequestData::s_finished, this, &SProfiles::loadVanity);
            _request->get("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+Settings::getKey()+"&vanityurl="+_id+"&url_type=1", true);
        } else if(aType == ProfileUrlType::id) {
            connect(_request,&RequestData::s_finished,this,&SProfiles::loadURL);
            _request->get("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+Settings::getKey()+"&steamids="+_id, true);
        }
    } else {
        if(aType == ProfileUrlType::vanity){
            _request->get("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+Settings::getKey()+"&vanityurl="+_id+"&url_type=1", false);
            _id = QJsonDocument::fromJson(_request->getAnswer()).object().value("response").toObject().value("steamid").toString();
        }
        _request->get("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+Settings::getKey()+"&steamids="+_id, false);
        QJsonArray arr = QJsonDocument::fromJson(_request->getAnswer()).object().value("response").toObject().value("players").toArray();
        set(arr);
    }
}

void SProfiles::update(bool aParallel) {
    load(aParallel, ProfileUrlType::id);
}

void SProfiles::sort() {
    //Переделать нормально
    //std::list<SProfile> list = _profile.toList().toStdList();
    std::sort(_profile.begin(), _profile.end(), [](const SProfile &s1, const SProfile &s2)-> const bool {
        return QString::compare(s1._personaName.toLower(), s2._personaName.toLower()) < 0;
    });
//    std::list<SProfile> list(_profile.begin(), _profile.end());
//    list.sort([](const SProfile &s1, const SProfile &s2)-> const bool {
//        return QString::compare(s1._personaName.toLower(), s2._personaName.toLower()) < 0;
//    });
//    //_profile=QVector<SProfile>::fromList(QList<SProfile>::fromStdList(list));
//    _profile = QList<SProfile>(list.begin(), list.end());

}

void SProfiles::clear() {
    _profile.clear();
    _status = StatusValue::none;
}

SProfiles::SProfiles(const SProfiles &aProfile): QObject(aProfile.parent()), _request(new RequestData), _profile(aProfile._profile),
_status(aProfile._status), _error(aProfile._error), _id(aProfile._id) {

}

SProfiles &SProfiles::operator=(const SProfiles &aProfile) {
    delete _request;
    _profile = aProfile._profile;
    _id = aProfile._id;
    _status = aProfile._status;
    _error = aProfile._error;
    _request = new RequestData();
    return *this;
}

SProfile &SProfiles::operator[](const int &aIndex) {
    return _profile[aIndex];
}
#define SProfilesEnd }
