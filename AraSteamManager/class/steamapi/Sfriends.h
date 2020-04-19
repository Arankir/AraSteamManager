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
#include <class/steamapi/Sprofile.h>
#include <class/settings.h>
#include <class/statusvalue.h>
#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QTextCodec>

class SFriend : public QObject
{
    Q_OBJECT
public:
    explicit SFriend(QJsonObject ObjFriend, QObject *parent = nullptr);
    SFriend(QObject *parent = nullptr);
    void Set(QJsonObject ObjFriend);
    QString GetSteamid() {return _friend.value("steamid").toString();}
    QString GetRelationship() {return _friend.value("relationship").toString();}
    QDateTime GetFriend_since() {return QDateTime::fromSecsSinceEpoch(_friend.value("friend_since").toInt(),Qt::LocalTime);}
    SFriend(const SFriend &);
    SFriend & operator=(const SFriend &Afriend);
    const bool &operator<(const SFriend &Afriend);

signals:

public slots:

private:
    QJsonObject _friend;
};

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
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    int GetCount() {return _friends.size();}
    SProfiles GetProfiles();
    void Update(bool parallel);
    void Clear();
    void Sort();
    SFriends(const SFriends &);
    SFriends & operator=(const SFriends & friends);
    SFriend &operator[](const int &index);

signals:
    void s_finished(SFriends*);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _id;
    QVector<SFriend> _friends;
};

#endif // SFRIENDS_H
