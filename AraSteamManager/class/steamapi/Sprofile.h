#ifndef SPROFILE_H
#define SPROFILE_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QTcpSocket>
#include <QEventLoop>
#include <class/settings.h>
#include <class/statusvalue.h>
#include <class/Network/requestdata.h>
#include <QObject>

enum class QueryType{
    url,
    vanity
};

class SProfile : public QObject
{

    Q_OBJECT
public:
    SProfile(QJsonObject profile=QJsonObject(), QObject *parent = nullptr): QObject(parent), _steamID(profile.value("steamid").toString()), _communityVisibilityState(profile.value("communityvisibilitystate").toInt()),
        _profileState(profile.value("profilestate").toInt()), _personaName(profile.value("personaname").toString()), _lastLogoff(QDateTime::fromSecsSinceEpoch(profile.value("lastlogoff").toInt(),Qt::LocalTime)),
        _commentPermission(profile.value("commentpermission").toInt()), _profileUrl(profile.value("profileurl").toString()), _avatar(profile.value("avatar").toString()),
        _avatarMedium(profile.value("avatarmedium").toString()), _avatarFull(profile.value("avatarfull").toString()), _personaState(profile.value("personastate").toInt()),
        _primaryClanID(profile.value("primaryclanid").toString()), _timeCreated(QDateTime::fromSecsSinceEpoch(profile.value("timecreated").toInt(),Qt::LocalTime)),
        _personaStateFlags(profile.value("personastateflags").toInt()), _gameExtraInfo(profile.value("gameextrainfo").toString()), _gameID(profile.value("gameid").toString()),
        _locCountryCode(profile.value("loccountrycode").toString()), _locStateCode(profile.value("locstatecode").toString()), _locCityID(profile.value("loccityid").toInt()),
        _realName(profile.value("realname").toString()){};
    ~SProfile(){};

    /*const*/ QString _steamID;
    int _communityVisibilityState;
    int _profileState;
    QString _personaName;
    QDateTime _lastLogoff;
    int _commentPermission;
    QString _profileUrl;
    QString _avatar;
    QString _avatarMedium;
    QString _avatarFull;
    int _personaState;
    QString _primaryClanID;
    /*const*/ QDateTime _timeCreated;
    int _personaStateFlags;
    QString _gameExtraInfo;
    QString _gameID;
    QString _locCountryCode;
    QString _locStateCode;
    int _locCityID;
    QString _realName;

    int _unicIndex=-1;

    void Update(bool parallel);
    SProfile( const SProfile & a_profile): QObject(a_profile.parent()), _steamID(a_profile._steamID), _communityVisibilityState(a_profile._communityVisibilityState),
        _profileState(a_profile._profileState), _personaName(a_profile._personaName), _lastLogoff(a_profile._lastLogoff), _commentPermission(a_profile._commentPermission),
        _profileUrl(a_profile._profileUrl), _avatar(a_profile._avatar), _avatarMedium(a_profile._avatarMedium), _avatarFull(a_profile._avatarFull), _personaState(a_profile._personaState),
        _primaryClanID(a_profile._primaryClanID), _timeCreated(a_profile._timeCreated), _personaStateFlags(a_profile._personaStateFlags), _gameExtraInfo(a_profile._gameExtraInfo),
        _gameID(a_profile._gameID), _locCountryCode(a_profile._locCountryCode), _locStateCode(a_profile._locStateCode), _locCityID(a_profile._locCityID), _realName(a_profile._realName){};
    SProfile & operator=(const SProfile & profile);
    const bool &operator<(const SProfile & profile);

signals:
    void s_finished(SProfile*);
    void s_finished();

public slots:
    void LoadURL(RequestData *request);

private:
    void Loading(bool parallel);
    void Set(QJsonObject ObjSummaries);

    Settings _setting;
};

class SProfiles : public QObject
{

    Q_OBJECT
public:
    explicit SProfiles(QString id, bool parallel, QueryType type, QObject *parent = nullptr);
    SProfiles(QJsonDocument DocSummaries, QObject *parent = nullptr);
    SProfiles(QJsonArray ArrSummaries, QObject *parent = nullptr);
    SProfiles(QJsonObject ObjSummaries, QObject *parent = nullptr);
    SProfiles(QObject *parent = nullptr): QObject(parent), _request(new RequestData()){};
    ~SProfiles();
    void Set(QString id, bool parallel, QueryType type);
    void Set(QJsonDocument DocSummaries);
    void Set(QJsonArray ArrSummaries);
    void Set(QJsonObject ObjSummaries);
    void SetUnicIndex(int AUnicIndex) {_unicIndex=AUnicIndex;}
    QString GetSteamid(int index=0) {return _profile[index]._steamID;}
    int GetCommunityvisibilitystate(int index=0) {return _profile[index]._communityVisibilityState;}
    int GetProfilestate(int index=0) {return _profile[index]._profileState;}
    QString GetPersonaname(int index=0) const {return _profile[index]._personaName;}
    QDateTime GetLastlogoff(int index=0) {return _profile[index]._lastLogoff;}
    int GetCommentpermission(int index=0) {return _profile[index]._commentPermission;}
    QString GetProfileurl(int index=0) {return _profile[index]._profileUrl;}
    QString GetAvatar(int index=0) {return _profile[index]._avatar;}
    QString GetAvatarmedium(int index=0) {return _profile[index]._avatarMedium;}
    QString GetAvatarfull(int index=0) {return _profile[index]._avatarFull;}
    int GetPersonastate(int index=0) {return _profile[index]._personaState;}
    QString GetPrimaryclanid(int index=0) {return _profile[index]._primaryClanID;}
    QDateTime GetTimecreated(int index=0) {return _profile[index]._timeCreated;}
    int GetPersonastateflags(int index=0) {return _profile[index]._personaStateFlags;}
    QString GetGameextrainfo(int index=0) {return _profile[index]._gameExtraInfo;}
    QString GetGameid(int index=0) {return _profile[index]._gameID;}
    QString GetLoccountrycode(int index=0) {return _profile[index]._locCountryCode;}
    QString GetLocstatecode(int index=0) {return _profile[index]._locStateCode;}
    int GetLoccityid(int index=0) {return _profile[index]._locCityID;}
    QString GetRealname(int index=0) {return _profile[index]._realName;}
    SProfile GetProfile(int index) {return _profile[index];}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    int GetUnicIndex() {return _unicIndex;}
    int GetCount() {return _profile.size();}
    QList<SProfile>::iterator begin() {return _profile.begin();}
    QList<SProfile>::iterator end() {return _profile.end();}
    void Update(bool parallel);
    void Sort();
    void Clear();
    SProfiles(const SProfiles & a_profile): QObject(a_profile.parent()), _request(new RequestData), _profile(a_profile._profile), _status(a_profile._status), _error(a_profile._error), _id(a_profile._id){};
    SProfiles &operator=(const SProfiles & profile);
    SProfile &operator[](const int &Aindex);

signals:
    void s_finished(SProfiles*);
    void s_finished();

public slots:
    void LoadURL(RequestData *a_request);
    void LoadVanity(RequestData *a_request);

private:
    void Load(bool a_parallel, QueryType a_type);

    RequestData *_request;
    Settings _setting;
    QList<SProfile> _profile;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _id="";
    int _unicIndex=-1;
};

#endif // SPROFILE_H
