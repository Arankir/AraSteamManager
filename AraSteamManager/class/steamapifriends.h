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
    SteamAPIFriend GetFriendInfo(int index) {return friends[index];}
    QString GetSteamid(int index) {return friends[index].GetSteamid();}
    QString GetRelationship(int index) {return friends[index].GetRelationship();}
    QDateTime GetFriend_since(int index) {return friends[index].GetFriend_since();}
    QString GetStatus() {return status;}
    int GetFriendsCount() {return count;}
    SteamAPIProfile GetProfileFriend(int index);
    QVector<SteamAPIProfile> GetProfiles();
    void Update();
    void Clear();
    SteamAPIFriends(const SteamAPIFriends &);
    SteamAPIFriends & operator=(const SteamAPIFriends & friends);

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
