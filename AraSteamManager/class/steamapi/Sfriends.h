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
#include <class/settings.h>

class SFriends : public QObject
{
    Q_OBJECT
public:
    explicit SFriends(QString id, bool parallel, QObject *parent = nullptr);
    SFriends(QJsonDocument DocFriends);
    SFriends();
    ~SFriends();
    void Set(QString id, bool parallel);
    void Set(QJsonDocument DocFriends);
    SFriend GetFriend(int index) {return SFriend(_friends[index].toObject());}
    QString GetSteamid(int index) {return _friends[index].toObject().value("steamid").toString();}
    QString GetRelationship(int index) {return _friends[index].toObject().value("relationship").toString();}
    QDateTime GetFriend_since(int index) {return QDateTime::fromSecsSinceEpoch(_friends[index].toObject().value("friend_since").toInt(),Qt::LocalTime);}
    QString GetStatus() {return _status;}
    int GetCount() {return _friends.size();}
    SProfile GetProfiles();
    void Update(bool parallel);
    void Clear();
    SFriends(const SFriends &);
    SFriends & operator=(const SFriends & friends);

signals:
    void s_finished(SFriends*);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QString _status="none";
    QString _id;
    QJsonArray _friends;
};

#endif // SFRIENDS_H
