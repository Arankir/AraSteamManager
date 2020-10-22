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
#include "class/steamapi/Sprofile.h"
#include "class/steamapi/Sapi.h"
#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QTextCodec>

class SFriend : public QObject {
    Q_OBJECT
public:
    explicit SFriend(const QJsonObject &aFriend = QJsonObject(), QObject *parent = nullptr): QObject(parent), _steamID(aFriend.value("steamid").toString()),
        _relationship(aFriend.value("relationship").toString()), _friend_since(QDateTime::fromSecsSinceEpoch(aFriend.value("friend_since").toInt(), Qt::LocalTime)) {}
    SFriend(const SFriend &aFriend): QObject(aFriend.parent()), _steamID(aFriend._steamID),
        _relationship(aFriend._relationship), _friend_since(aFriend._friend_since) {}

    SFriend &operator=(const SFriend&);
    const bool &operator<(const SFriend&);

    const QString _steamID;
    const QString _relationship;
    const QDateTime _friend_since;

};

class SFriends : public Sapi {
    Q_OBJECT
public:
    explicit SFriends(const QString &id, bool parallel, QObject *parent = nullptr);
    SFriends(const SFriends&);
    SFriends(QObject *parent = nullptr): Sapi(parent) {}
    ~SFriends() {}

    SFriends &operator=(const SFriends &friends);
    SFriend &operator[](const int &index) {return _friends[index];};

    SFriends &load(const QString &id, bool parallel);
    SFriends &update(bool parallel);
    SFriends &clear();
    SFriends &sort();

    QList<SFriend>::iterator begin() {return _friends.begin();}
    QList<SFriend>::iterator end() {return _friends.end();}
    int getCount() const {return _friends.size();}
    SProfiles getProfiles() const;

signals:
    void s_finished();

private slots:
    void onLoad() override;
    void parse(const QJsonDocument &doc);

private:
    QString _id;
    QList<SFriend> _friends;
};

#endif // SFRIENDS_H
