#ifndef SFRIENDS_H
#define SFRIENDS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapi/Sfriend.h>
#include <class/steamapi/Sprofile.h>

class SFriends : public QObject
{
    Q_OBJECT
public:
    explicit SFriends(QString key, QString id, bool parallel, QObject* parent = nullptr);
    SFriends(QJsonDocument DocFriends);
    SFriends();
    ~SFriends();
    void Set(QString key, QString id, bool parallel);
    void Set(QJsonDocument DocFriends);
    SFriend GetFriend(int index) {return SFriend(friends[index].toObject());}
    QString GetSteamid(int index) {return friends[index].toObject().value("steamid").toString();}
    QString GetRelationship(int index) {return friends[index].toObject().value("relationship").toString();}
    QDateTime GetFriend_since(int index) {return QDateTime::fromSecsSinceEpoch(friends[index].toObject().value("friend_since").toInt(),Qt::LocalTime);}
    QString GetStatus() {return status;}
    int GetCount() {return friends.size();}
    SProfile GetProfiles();
    void Update(bool parallel);
    void Clear();
    SFriends(const SFriends &);
    SFriends & operator=(const SFriends & friends);

signals:
    void finished(SFriends*);
    void finished();

public slots:
    void Load(QNetworkReply* Reply);

private:
    QNetworkAccessManager* manager;
    QString status="none";
    QString id;
    QString key;
    QJsonArray friends;
};

#endif // SFRIENDS_H
