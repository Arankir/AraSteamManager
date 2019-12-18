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
#include <QObject>

class SProfile : public QObject
{
    Q_OBJECT
public:
    explicit SProfile(QString id, bool parallel, QString type, QObject *parent = nullptr);
    SProfile(QJsonDocument DocSummaries);
    SProfile(QJsonArray ArrSummaries);
    SProfile(QJsonObject ObjSummaries);
    SProfile();
    ~SProfile();
    void Set(QString id, bool parallel, QString type);
    void Set(QJsonDocument DocSummaries);
    void Set(QJsonArray ArrSummaries);
    void Set(QJsonObject ObjSummaries);
    void SetUnicIndex(int AUnicIndex) {_unicIndex=AUnicIndex;}
    QString GetSteamid(int index=0) {return _profile[index].toObject().value("steamid").toString();}
    int GetCommunityvisibilitystate(int index=0) {return _profile[index].toObject().value("communityvisibilitystate").toInt();}
    int GetProfilestate(int index=0) {return _profile[index].toObject().value("profilestate").toInt();}
    QString GetPersonaname(int index=0) {return _profile[index].toObject().value("personaname").toString();}
    QDateTime GetLastlogoff(int index=0) {return QDateTime::fromSecsSinceEpoch(_profile[index].toObject().value("lastlogoff").toInt(),Qt::LocalTime);}
    int GetCommentpermission(int index=0) {return _profile[index].toObject().value("commentpermission").toInt();}
    QString GetProfileurl(int index=0) {return _profile[index].toObject().value("profileurl").toString();}
    QString GetAvatar(int index=0) {return _profile[index].toObject().value("avatar").toString();}
    QString GetAvatarmedium(int index=0) {return _profile[index].toObject().value("avatarmedium").toString();}
    QString GetAvatarfull(int index=0) {return _profile[index].toObject().value("avatarfull").toString();}
    int GetPersonastate(int index=0) {return _profile[index].toObject().value("personastate").toInt();}
    QString GetPrimaryclanid(int index=0) {return _profile[index].toObject().value("primaryclanid").toString();}
    QDateTime GetTimecreated(int index=0) {return QDateTime::fromSecsSinceEpoch(_profile[index].toObject().value("timecreated").toInt(),Qt::LocalTime);}
    int GetPersonastateflags(int index=0) {return _profile[index].toObject().value("personastateflags").toInt();}
    QString GetGameextrainfo(int index=0) {return _profile[index].toObject().value("gameextrainfo").toString();}
    QString GetGameid(int index=0) {return _profile[index].toObject().value("gameid").toString();}
    QString GetLoccountrycode(int index=0) {return _profile[index].toObject().value("loccountrycode").toString();}
    QString GetLocstatecode(int index=0) {return _profile[index].toObject().value("locstatecode").toString();}
    int GetLoccityid(int index=0) {return _profile[index].toObject().value("loccityid").toInt();}
    QString GetRealname(int index=0) {return _profile[index].toObject().value("realname").toString();}
    SProfile GetProfile(int index) {return _profile[index].toObject();}
    QString GetStatus() {return _status;}
    int GetUnicIndex() {return _unicIndex;}
    int GetCount() {return _profile.size();}
    void Update(bool parallel);
    SProfile( const SProfile & a);
    SProfile & operator=(const SProfile & profile);
    void Clear();

signals:
    void s_finished(SProfile*);
    void s_finished();

public slots:
    void LoadURL(QNetworkReply *Reply);
    void LoadVanity(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QJsonArray _profile;
    QString _status="null";
    QString _id="";
    int _unicIndex=-1;
};

#endif // SPROFILE_H
