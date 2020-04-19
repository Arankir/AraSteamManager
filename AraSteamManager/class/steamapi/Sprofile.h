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
#include <QObject>

enum class QueryType{
    url,
    vanity
};

class SProfile : public QObject
{

    Q_OBJECT
public:
    explicit SProfile(QString id, bool parallel, QueryType type, QObject *parent = nullptr);
    SProfile(QJsonObject ObjSummaries, QObject *parent = nullptr);
    SProfile(QObject *parent = nullptr);
    ~SProfile();
    void Set(QString id, bool parallel, QueryType type);
    void Set(QJsonObject ObjSummaries);
    QString GetSteamid() {return _profile.value("steamid").toString();}
    int GetCommunityvisibilitystate() {return _profile.value("communityvisibilitystate").toInt();}
    int GetProfilestate() {return _profile.value("profilestate").toInt();}
    QString GetPersonaname() const {return _profile.value("personaname").toString();}
    QDateTime GetLastlogoff() {return QDateTime::fromSecsSinceEpoch(_profile.value("lastlogoff").toInt(),Qt::LocalTime);}
    int GetCommentpermission() {return _profile.value("commentpermission").toInt();}
    QString GetProfileurl() {return _profile.value("profileurl").toString();}
    QString GetAvatar() {return _profile.value("avatar").toString();}
    QString GetAvatarmedium() {return _profile.value("avatarmedium").toString();}
    QString GetAvatarfull() {return _profile.value("avatarfull").toString();}
    int GetPersonastate() {return _profile.value("personastate").toInt();}
    QString GetPrimaryclanid() {return _profile.value("primaryclanid").toString();}
    QDateTime GetTimecreated() {return QDateTime::fromSecsSinceEpoch(_profile.value("timecreated").toInt(),Qt::LocalTime);}
    int GetPersonastateflags() {return _profile.value("personastateflags").toInt();}
    QString GetGameextrainfo() {return _profile.value("gameextrainfo").toString();}
    QString GetGameid() {return _profile.value("gameid").toString();}
    QString GetLoccountrycode() {return _profile.value("loccountrycode").toString();}
    QString GetLocstatecode() {return _profile.value("locstatecode").toString();}
    int GetLoccityid() {return _profile.value("loccityid").toInt();}
    QString GetRealname() {return _profile.value("realname").toString();}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    int GetCount() {return _profile.size();}
    void Update(bool parallel);
    void Clear();
    SProfile( const SProfile & a);
    SProfile & operator=(const SProfile & profile);
    const bool &operator<(const SProfile & profile);

    int _unicIndex=-1;

signals:
    void s_finished(SProfile*);
    void s_finished();

public slots:
    void LoadURL(QNetworkReply *Reply);
    void LoadVanity(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QJsonObject _profile;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _id="";
};

class SProfiles : public QObject
{

    Q_OBJECT
public:
    explicit SProfiles(QString id, bool parallel, QueryType type, QObject *parent = nullptr);
    SProfiles(QJsonDocument DocSummaries, QObject *parent = nullptr);
    SProfiles(QJsonArray ArrSummaries, QObject *parent = nullptr);
    SProfiles(QJsonObject ObjSummaries, QObject *parent = nullptr);
    SProfiles(QObject *parent = nullptr);
    ~SProfiles();
    void Set(QString id, bool parallel, QueryType type);
    void Set(QJsonDocument DocSummaries);
    void Set(QJsonArray ArrSummaries);
    void Set(QJsonObject ObjSummaries);
    void SetUnicIndex(int AUnicIndex) {_unicIndex=AUnicIndex;}
    QString GetSteamid(int index=0) {return _profile[index].GetSteamid();}
    int GetCommunityvisibilitystate(int index=0) {return _profile[index].GetCommunityvisibilitystate();}
    int GetProfilestate(int index=0) {return _profile[index].GetProfilestate();}
    QString GetPersonaname(int index=0) const {return _profile[index].GetPersonaname();}
    QDateTime GetLastlogoff(int index=0) {return _profile[index].GetLastlogoff();}
    int GetCommentpermission(int index=0) {return _profile[index].GetCommentpermission();}
    QString GetProfileurl(int index=0) {return _profile[index].GetProfileurl();}
    QString GetAvatar(int index=0) {return _profile[index].GetAvatar();}
    QString GetAvatarmedium(int index=0) {return _profile[index].GetAvatarmedium();}
    QString GetAvatarfull(int index=0) {return _profile[index].GetAvatarfull();}
    int GetPersonastate(int index=0) {return _profile[index].GetPersonastate();}
    QString GetPrimaryclanid(int index=0) {return _profile[index].GetPrimaryclanid();}
    QDateTime GetTimecreated(int index=0) {return _profile[index].GetTimecreated();}
    int GetPersonastateflags(int index=0) {return _profile[index].GetPersonastateflags();}
    QString GetGameextrainfo(int index=0) {return _profile[index].GetGameextrainfo();}
    QString GetGameid(int index=0) {return _profile[index].GetGameid();}
    QString GetLoccountrycode(int index=0) {return _profile[index].GetLoccountrycode();}
    QString GetLocstatecode(int index=0) {return _profile[index].GetLocstatecode();}
    int GetLoccityid(int index=0) {return _profile[index].GetLoccityid();}
    QString GetRealname(int index=0) {return _profile[index].GetRealname();}
    SProfile GetProfile(int index) {return _profile[index];}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    int GetUnicIndex() {return _unicIndex;}
    int GetCount() {return _profile.size();}
    void Update(bool parallel);
    void Sort();
    void Clear();
    SProfiles(const SProfiles & a);
    SProfiles &operator=(const SProfiles & profile);
    SProfile &operator[](const int &Aindex);

signals:
    void s_finished(SProfiles*);
    void s_finished();

public slots:
    void LoadURL(QNetworkReply *Reply);
    void LoadVanity(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QVector<SProfile> _profile;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _id="";
    int _unicIndex=-1;
};

#endif // SPROFILE_H
