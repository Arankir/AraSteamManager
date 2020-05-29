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

class SFriend : public QObject{
    Q_OBJECT
public:
    explicit SFriend(QJsonObject a_friend, QObject *parent = nullptr): QObject(parent),_steamID(a_friend.value("steamid").toString()),
        _relationship(a_friend.value("relationship").toString()),_friend_since(QDateTime::fromSecsSinceEpoch(a_friend.value("friend_since").toInt(),Qt::LocalTime)){};
    const QString _steamID;
    const QString _relationship;
    const QDateTime _friend_since;
    SFriend(const SFriend &a_friend): QObject(a_friend.parent()), _steamID(a_friend._steamID), _relationship(a_friend._relationship), _friend_since(a_friend._friend_since){};
    SFriend &operator=(const SFriend &) {return *this;}
    const bool &operator<(const SFriend &Afriend);

};

class SFriends : public QObject
{
    Q_OBJECT
public:
    explicit SFriends(QString id, bool parallel, QObject *parent = nullptr);
    SFriends(QJsonDocument DocFriends, QObject *parent = nullptr);
    SFriends(QObject *parent = nullptr): QObject(parent),_manager(new QNetworkAccessManager()){};
    ~SFriends();
    void Set(QString id, bool parallel);
    void Set(QJsonDocument DocFriends);
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    int GetCount() {return _friends.size();}
    SProfiles GetProfiles();
    void Update(bool parallel);
    QList<SFriend>::iterator begin() {return _friends.begin();}
    QList<SFriend>::iterator end() {return _friends.end();}
    void Clear();
    void Sort();
    SFriends(const SFriends &);
    SFriends & operator=(const SFriends & friends);
    SFriend &operator[](const int &index) {return _friends[index];}

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
    QList<SFriend> _friends;
};

#endif // SFRIENDS_H
