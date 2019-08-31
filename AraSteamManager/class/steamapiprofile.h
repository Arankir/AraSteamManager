#ifndef STEAMAPIPROFILE_H
#define STEAMAPIPROFILE_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QTcpSocket>
#include <QObject>

class SteamAPIProfile : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIProfile(QString key, QString id, QString type, QObject *parent = nullptr);
    SteamAPIProfile(QJsonDocument DocSummaries);
    SteamAPIProfile();
    ~SteamAPIProfile();
    void Set(QString key, QString id, QString type);
    void Set(QJsonDocument DocSummaries);
    void Set(QJsonDocument DocSummaries,int index);
    QString GetSteamid();
    int GetCommunityvisibilitystate();
    int GetProfilestate();
    QString GetPersonaname();
    QDateTime GetLastlogoff();
    int GetCommentpermission();
    QString GetProfileurl();
    QString GetAvatar();
    QString GetAvatarmedium();
    QString GetAvatarfull();
    int GetPersonastate();
    QString GetPrimaryclanid();
    QDateTime GetTimecreated();
    int GetPersonastateflags();
    QString GetGameextrainfo();
    QString GetGameid();
    QString GetLoccountrycode();
    QString GetLocstatecode();
    int GetLoccityid();
    QString GetRealname();
    QString GetStatus();
    void Update();
    SteamAPIProfile( const SteamAPIProfile & a);
    SteamAPIProfile & operator=(const SteamAPIProfile & profile);

signals:
    void finished(SteamAPIProfile*);
    void finished();

public slots:
    void LoadURL(QNetworkReply *Reply);
    void LoadVanity(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QString steamid="";//"76561198065018572"
    int communityvisibilitystate=0;//3, (1 - the profile is not visible to you, 3 - the profile is "Public")
    int profilestate=0;//1
    QString personaname="";//"Yuno"
    QDateTime lastlogoff=QDateTime::fromSecsSinceEpoch(0);//1555174765
    int commentpermission=0;//1
    QString profileurl="";//"https://steamcommunity.com/id/Arankir/"
    QString avatar="";//"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/avatars/ce/ce1d088d99e7244b9e5297430b9af304d2c5f93c.jpg"
    QString avatarmedium="";//"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/avatars/ce/ce1d088d99e7244b9e5297430b9af304d2c5f93c_medium.jpg"
    QString avatarfull="";//"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/avatars/ce/ce1d088d99e7244b9e5297430b9af304d2c5f93c_full.jpg"
    int personastate=0;//1
    QString primaryclanid="";//"103582791434380590"
    QDateTime timecreated=QDateTime::fromSecsSinceEpoch(0);//1339187696
    int personastateflags=0;//0
    QString gameextrainfo="";//"Realm of the Mad God"
    QString gameid="";//"200210"
    QString loccountrycode="";//"JP"
    QString locstatecode="";//"40"
    int loccityid=0;//26111
    QString realname="";
    QString status="null";
    QString key="";
};

#endif // STEAMAPIPROFILE_H
