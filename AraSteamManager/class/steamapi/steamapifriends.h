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
#include <class/steamapi/steamapifriend.h>
#include <class/steamapi/steamapiprofile.h>

class SteamAPIFriends : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIFriends(QString key, QString id, bool parallel, QObject *parent = nullptr);
    SteamAPIFriends(QJsonDocument DocFriends);
    SteamAPIFriends();
    ~SteamAPIFriends();
    void Set(QString key, QString id, bool parallel);
    void Set(QJsonDocument DocFriends);
    SteamAPIFriend GetFriend(int index) {return SteamAPIFriend(friends[index].toObject());}
    QString GetSteamid(int index) {return friends[index].toObject().value("steamid").toString();}
    QString GetRelationship(int index) {return friends[index].toObject().value("relationship").toString();}
    QDateTime GetFriend_since(int index) {return QDateTime::fromSecsSinceEpoch(friends[index].toObject().value("friend_since").toInt(),Qt::LocalTime);}
    QString GetStatus() {return status;}
    int GetCount() {return friends.size();}
    SteamAPIProfile GetProfiles();
    void Update(bool parallel);
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
    QString status="none";
    QString id;
    QString key;
    QJsonArray friends;
};

#endif // STEAMAPIFRIENDS_H
