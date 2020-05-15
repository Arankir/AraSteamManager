#include "Sprofile.h"

#define SProfileStart {
void SProfile::Set(QJsonObject profile){
    _steamID=profile.value("steamid").toInt();//!
    _timeCreated=QDateTime::fromSecsSinceEpoch(profile.value("timecreated").toInt(),Qt::LocalTime);//!
    _communityVisibilityState=profile.value("communityvisibilitystate").toInt();
    _profileState=profile.value("profilestate").toInt();
    _personaName=profile.value("personaname").toString();
    _lastLogoff=QDateTime::fromSecsSinceEpoch(profile.value("lastlogoff").toInt(),Qt::LocalTime);
    _commentPermission=profile.value("commentpermission").toInt();
    _profileUrl=profile.value("profileurl").toString();
    _avatar=profile.value("avatar").toString();
    _avatarMedium=profile.value("avatarmedium").toString();
    _avatarFull=profile.value("avatarfull").toString();
    _personaState=profile.value("personastate").toInt();
    _primaryClanID=profile.value("primaryclanid").toString();
    _personaStateFlags=profile.value("personastateflags").toInt();
    _gameExtraInfo=profile.value("gameextrainfo").toString();
    _gameID=profile.value("gameid").toString();
    _locCountryCode=profile.value("loccountrycode").toString();
    _locStateCode=profile.value("locstatecode").toString();
    _locCityID=profile.value("loccityid").toInt();
    _realName=profile.value("realname").toString();
}
void SProfile::Loading(bool a_parallel){
    QString url="http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_steamID;
    if(a_parallel){
        RequestData *request = new RequestData(url,true);
        connect(request,&RequestData::s_finished,this,&SProfile::LoadURL);
    } else {
        RequestData *request = new RequestData(url,false);
        Set(QJsonDocument::fromJson(request->GetAnswer()).object().value("response").toObject().value("players").toArray().at(0).toObject());
        delete request;
        emit s_finished(this);
        emit s_finished();
    }
}
void SProfile::LoadURL(RequestData *a_request){
    QJsonDocument localSummaries = QJsonDocument::fromJson(a_request->GetAnswer());
    disconnect(a_request,&RequestData::s_finished,this,&SProfile::LoadURL);
    a_request->deleteLater();
    Set(localSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject());
    emit s_finished(this);
    emit s_finished();
}
void SProfile::Update(bool a_parallel){
    Loading(a_parallel);
}
SProfile & SProfile::operator=(const SProfile & a_profile){
    _steamID=a_profile._steamID;//!
    _timeCreated=a_profile._timeCreated;//!
    _communityVisibilityState=a_profile._communityVisibilityState;
    _profileState=a_profile._profileState;
    _personaName=a_profile._personaName;
    _lastLogoff=a_profile._lastLogoff;
    _commentPermission=a_profile._commentPermission;
    _profileUrl=a_profile._profileUrl;
    _avatar=a_profile._avatar;
    _avatarMedium=a_profile._avatarMedium;
    _avatarFull=a_profile._avatarFull;
    _personaState=a_profile._personaState;
    _primaryClanID=a_profile._primaryClanID;
    _personaStateFlags=a_profile._personaStateFlags;
    _gameExtraInfo=a_profile._gameExtraInfo;
    _gameID=a_profile._gameID;
    _locCountryCode=a_profile._locCountryCode;
    _locStateCode=a_profile._locStateCode;
    _locCityID=a_profile._locCityID;
    _realName=a_profile._realName;
    return *this;
}
const bool &SProfile::operator<(const SProfile &a_profile){
    static const bool b=_personaName.toLower()<a_profile._personaName.toLower();
    return b;
}
#define SProfileEnd }
#define SProfilesStart {
SProfiles::SProfiles(QString a_id, bool a_parallel, QueryType a_type, QObject *parent): QObject(parent), _request(new RequestData()), _id(a_id){
    Load(a_parallel, a_type);
}
SProfiles::SProfiles(QJsonDocument a_docProfiles, QObject *parent): QObject(parent), _request(new RequestData()){
    Set(a_docProfiles);
}
SProfiles::SProfiles(QJsonArray a_profiles, QObject *parent): QObject(parent), _request(new RequestData()){
    Set(a_profiles);
}
SProfiles::SProfiles(QJsonObject a_profile, QObject *parent): QObject(parent), _request(new RequestData()){
    Set(a_profile);
}
SProfiles::~SProfiles(){
    delete _request;
}
void SProfiles::Set(QString a_id, bool a_parallel, QueryType a_type){
    _id=a_id;
    Load(a_parallel, a_type);
}
void SProfiles::Set(QJsonDocument a_docProfiles){
    Set(a_docProfiles.object().value("response").toObject().value("players").toArray());
}
void SProfiles::Set(QJsonArray a_profiles){
    Clear();
    if(a_profiles.size()>0){
        for(int i=0;i<a_profiles.size();i++)
            _profile.append(std::move(SProfile(a_profiles.at(i).toObject())));
        _status=StatusValue::success;
    }
    else {
        _status=StatusValue::error;
        _error="profile is not exist";
    }
}
void SProfiles::Set(QJsonObject a_player){
    Clear();
    _profile.append(std::move(a_player));
    _status=StatusValue::success;
}
void SProfiles::LoadVanity(RequestData *a_request){
    QJsonDocument localDoc = QJsonDocument::fromJson(a_request->GetAnswer());
    disconnect(_request,&RequestData::s_finished,this,&SProfiles::LoadVanity);
    connect(_request,&RequestData::s_finished,this,&SProfiles::LoadURL);
    _id=localDoc.object().value("response").toObject().value("steamid").toString();
    _request->Get("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id);
}
void SProfiles::LoadURL(RequestData *a_request){
    QJsonDocument localDoc = QJsonDocument::fromJson(a_request->GetAnswer());
    disconnect(_request,&RequestData::s_finished,this,&SProfiles::LoadURL);
    Set(localDoc);
    emit s_finished(this);
    emit s_finished();
}
void SProfiles::Load(bool a_parallel, QueryType a_type){
    if(a_parallel){
        if(a_type==QueryType::vanity){
            connect(_request,&RequestData::s_finished,this,&SProfiles::LoadVanity);
            _request->Get("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+_id+"&url_type=1", true);
        } else if(a_type==QueryType::url){
            connect(_request,&RequestData::s_finished,this,&SProfiles::LoadURL);
            _request->Get("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id, true);
        }
    } else {
        if(a_type==QueryType::vanity){
            _request->Get("https://api.steampowered.com/ISteamUser/ResolveVanityURL/v1/?key="+_setting.GetKey()+"&vanityurl="+_id+"&url_type=1", false);
            _id=QJsonDocument::fromJson(_request->GetAnswer()).object().value("response").toObject().value("steamid").toString();
        }
        _request->Get("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+_setting.GetKey()+"&steamids="+_id, false);
        Set(QJsonDocument::fromJson(_request->GetAnswer()).object().value("response").toObject().value("players").toArray());
    }
}
void SProfiles::Update(bool a_parallel){
    Load(a_parallel, QueryType::url);
}
void SProfiles::Sort(){
    //Переделать нормально
    //std::list<SProfile> list = _profile.toList().toStdList();
    std::list<SProfile> list(_profile.begin(),_profile.end());
    list.sort([](const SProfile &s1, const SProfile &s2)-> const bool {
        if(QString::compare(s1._personaName.toLower(),s2._personaName.toLower())<0)
            return true;
        else
            return false;
    });
    //_profile=QVector<SProfile>::fromList(QList<SProfile>::fromStdList(list));
    _profile=QList<SProfile>(list.begin(),list.end());

}
void SProfiles::Clear(){
    _profile.clear();
    _status=StatusValue::none;
}
SProfiles & SProfiles::operator=(const SProfiles &a_profile){
    delete _request;
    _profile=a_profile._profile;
    _id=a_profile._id;
    _status=a_profile._status;
    _error=a_profile._error;
    _request = new RequestData();
    return *this;
}
SProfile &SProfiles::operator[](const int &a_index){
    return _profile[a_index];
}
#define SProfilesEnd }
