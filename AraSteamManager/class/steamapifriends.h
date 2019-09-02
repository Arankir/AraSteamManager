#ifndef STEAMAPIFRIENDS_H
#define STEAMAPIFRIENDS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapifriend.h>
#include <class/steamapiprofile.h>

class SteamAPIFriends : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIFriends(QString key, QString id, QObject *parent = nullptr);
    SteamAPIFriends(QJsonDocument DocFriends);
    SteamAPIFriends();
    ~SteamAPIFriends();
    void Set(QString key, QString id);
    void Set(QJsonDocument DocFriends);
    SteamAPIFriend GetFriendInfo(int index);
    QString GetSteamid(int index);
    QString GetRelationship(int index);
    QDateTime GetFriend_since(int index);
    QString GetStatus();
    int GetFriendsCount();
    SteamAPIProfile GetProfileFriend(int index);
    QVector<SteamAPIProfile> GetProfiles();
    void Update();
    SteamAPIFriends(const SteamAPIFriends &);
    SteamAPIFriends & operator=(const SteamAPIFriends & friends);
    void Clear();

signals:
    void finished(SteamAPIFriends*);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QVector<SteamAPIFriend> friends;
    QString status="none";
    QString id;
    QString key;
    int count;
};

#endif // STEAMAPIFRIENDS_H
