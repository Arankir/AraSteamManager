#include "Sprofile.h"

#define SProfileStart {
void SProfile::set(QJsonObject aProfile) {
    _steamID = aProfile.value("steamid").toInt();//!
    _timeCreated = QDateTime::fromSecsSinceEpoch(aProfile.value("timecreated").toInt(),Qt::LocalTime);//!
    _communityVisibilityState = aProfile.value("communityvisibilitystate").toInt();
    _profileState = aProfile.value("profilestate").toInt();
    _personaName = aProfile.value("personaname").toString();
    _lastLogoff = QDateTime::fromSecsSinceEpoch(aProfile.value("lastlogoff").toInt(),Qt::LocalTime);
    _commentPermission = aProfile.value("commentpermission").toInt();
    _profileUrl = aProfile.value("profileurl").toString();
    _avatar = aProfile.value("avatar").toString();
    _avatarMedium = aProfile.value("avatarmedium").toString();
    _avatarFull = aProfile.value("avatarfull").toString();
    _personaState = aProfile.value("personastate").toInt();
    _primaryClanID = aProfile.value("primaryclanid").toString();
    _personaStateFlags = aProfile.value("personastateflags").toInt();
    _gameExtraInfo = aProfile.value("gameextrainfo").toString();
    _gameID = aProfile.value("gameid").toString();
    _locCountryCode = aProfile.value("loccountrycode").toString();
    _locStateCode = aProfile.value("locstatecode").toString();
    _locCityID = aProfile.value("loccityid").toInt();
    _realName = aProfile.value("realname").toString();
}

void SProfile::loading(bool aParallel){
    QString url = "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+Settings::getKey()+"&steamids="+_steamID;
    if (aParallel) {
        RequestData *request = new RequestData(url, true);
        connect(request, &RequestData::s_finished, this, &SProfile::loadURL);
    } else {
        RequestData request(url, false);
        set(QJsonDocument::fromJson(request.getAnswer()).object().value("response").toObject().value("players").toArray().at(0).toObject());
        emit s_finished(this);
        emit s_finished();
    }
}

void SProfile::loadURL(RequestData *aRequest){
    QJsonDocument localSummaries = QJsonDocument::fromJson(aRequest->getAnswer());
    set(localSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject());
    disconnect(aRequest,&RequestData::s_finished,this,&SProfile::loadURL);
    aRequest->deleteLater();
    emit s_finished(this);
    emit s_finished();
}

SProfile::SProfile(QJsonObject aProfile, QObject *aParent): QObject(aParent), _steamID(aProfile.value("steamid").toString()),
_communityVisibilityState(aProfile.value("communityvisibilitystate").toInt()), _profileState(aProfile.value("profilestate").toInt()),
_personaName(aProfile.value("personaname").toString()), _lastLogoff(QDateTime::fromSecsSinceEpoch(aProfile.value("lastlogoff").toInt(),Qt::LocalTime)),
_commentPermission(aProfile.value("commentpermission").toInt()), _profileUrl(aProfile.value("profileurl").toString()), _avatar(aProfile.value("avatar").toString()),
_avatarMedium(aProfile.value("avatarmedium").toString()), _avatarFull(aProfile.value("avatarfull").toString()), _personaState(aProfile.value("personastate").toInt()),
_primaryClanID(aProfile.value("primaryclanid").toString()), _timeCreated(QDateTime::fromSecsSinceEpoch(aProfile.value("timecreated").toInt(),Qt::LocalTime)),
_personaStateFlags(aProfile.value("personastateflags").toInt()), _gameExtraInfo(aProfile.value("gameextrainfo").toString()), _gameID(aProfile.value("gameid").toString()),
_locCountryCode(aProfile.value("loccountrycode").toString()), _locStateCode(aProfile.value("locstatecode").toString()), _locCityID(aProfile.value("loccityid").toInt()),
_realName(aProfile.value("realname").toString()) {

}

SProfile::~SProfile() {

}

void SProfile::update(bool aParallel) {
    loading(aParallel);
}

QPixmap SProfile::getPixmapAvatar(QString aPath) {
    if (_pixmapAvatar == QPixmap()) {
        RequestImage *img = new RequestImage(_avatar, aPath, true, this);
        QEventLoop loop;
        connect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
        _pixmapAvatar = img->getPixmap();
        delete img;
    }
    return _pixmapAvatar;
}

QPixmap SProfile::getPixmapAvatarMedium(QString aPath) {
    if (_pixmapAvatarMedium == QPixmap()) {
        RequestImage *img = new RequestImage(_avatarMedium, aPath, true, this);
        QEventLoop loop;
        connect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
        _pixmapAvatarMedium = img->getPixmap();
        delete img;
    }
    return _pixmapAvatarMedium;
}

QPixmap SProfile::getPixmapAvatarFull(QString aPath) {
    if (_pixmapAvatarFull == QPixmap()) {
        RequestImage *img = new RequestImage(_avatarFull, aPath, true, this);
        QEventLoop loop;
        connect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(img, &RequestImage::s_loadComplete, &loop, &QEventLoop::quit);
        _pixmapAvatarFull = img->getPixmap();
        delete img;
    }
    return _pixmapAvatarFull;
}

SProfile::SProfile(const SProfile &aProfile): QObject(aProfile.parent()), _steamID(aProfile._steamID), _communityVisibilityState(aProfile._communityVisibilityState),
_profileState(aProfile._profileState), _personaName(aProfile._personaName), _lastLogoff(aProfile._lastLogoff), _commentPermission(aProfile._commentPermission),
_profileUrl(aProfile._profileUrl), _avatar(aProfile._avatar), _avatarMedium(aProfile._avatarMedium), _avatarFull(aProfile._avatarFull), _personaState(aProfile._personaState),
_primaryClanID(aProfile._primaryClanID), _timeCreated(aProfile._timeCreated), _personaStateFlags(aProfile._personaStateFlags), _gameExtraInfo(aProfile._gameExtraInfo),
_gameID(aProfile._gameID), _locCountryCode(aProfile._locCountryCode), _locStateCode(aProfile._locStateCode), _locCityID(aProfile._locCityID), _realName(aProfile._realName) {

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
SProfiles::SProfiles(QString aId, bool aParallel, ProfileUrlType aType, QObject *aParent): QObject(aParent), _request(new RequestData()), _id(aId) {
    load(aParallel, aType);
}

SProfiles::SProfiles(QJsonDocument aDocprofiles, QObject *aParent): QObject(aParent), _request(new RequestData()) {
    set(aDocprofiles);
}

SProfiles::SProfiles(QJsonArray aProfiles, QObject *aParent): QObject(aParent), _request(new RequestData()) {
    set(aProfiles);
}

SProfiles::SProfiles(QJsonObject aProfile, QObject *aParent): QObject(aParent), _request(new RequestData()) {
    set(aProfile);
}

SProfiles::SProfiles(QObject *aParent): QObject(aParent), _request(new RequestData()) {

}

SProfiles::~SProfiles(){
    delete _request;
}

void SProfiles::set(QString aId, bool aParallel, ProfileUrlType aType) {
    _id = std::move(aId);
    load(aParallel, aType);
}

void SProfiles::set(QJsonDocument aProfiles) {
    set(aProfiles.object().value("response").toObject().value("players").toArray());
}

void SProfiles::set(QJsonArray aProfiles){
    clear();
    if(aProfiles.size() > 0) {
        for (auto profile: aProfiles) {
            _profile.append(std::move(SProfile(profile.toObject())));
        }
        _status = std::move(StatusValue::success);
    }
    else {
        _status = std::move(StatusValue::error);
        _error = std::move("profile is not exist");
    }
}

void SProfiles::set(QJsonObject aPlayer) {
    clear();
    _profile.append(std::move(aPlayer));
    _status = std::move(StatusValue::success);
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

QString SProfiles::getAvatar(int aIndex) {
    return _profile[aIndex]._avatar;
}

QString SProfiles::getAvatarmedium(int aIndex) {
    return _profile[aIndex]._avatarMedium;
}

QString SProfiles::getAvatarfull(int aIndex) {
    return _profile[aIndex]._avatarFull;
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
    set(QJsonDocument::fromJson(aRequest->getAnswer()));
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
        set(QJsonDocument::fromJson(_request->getAnswer()).object().value("response").toObject().value("players").toArray());
    }
}

void SProfiles::update(bool aParallel) {
    load(aParallel, ProfileUrlType::id);
}

void SProfiles::sort() {
    //Переделать нормально
    //std::list<SProfile> list = _profile.toList().toStdList();
    std::list<SProfile> list(_profile.begin(), _profile.end());
    list.sort([](const SProfile &s1, const SProfile &s2)-> const bool {
        return QString::compare(s1._personaName.toLower(), s2._personaName.toLower()) < 0;
    });
    //_profile=QVector<SProfile>::fromList(QList<SProfile>::fromStdList(list));
    _profile = QList<SProfile>(list.begin(), list.end());

}

void SProfiles::clear() {
    _profile.clear();
    _status = std::move(StatusValue::none);
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
