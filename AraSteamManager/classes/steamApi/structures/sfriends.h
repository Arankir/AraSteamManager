#ifndef SFRIENDS_H
#define SFRIENDS_H

#include "./sprofile.h"
#include "../sapi.h"

class SFriend : public QObject {
    Q_OBJECT
public:
    explicit SFriend(const QJsonObject &aFriend = QJsonObject(), QObject *parent = nullptr): QObject(parent), _steamID(aFriend.value("steamid").toString()),
        _relationship(aFriend.value("relationship").toString()), _friendSince(QDateTime::fromSecsSinceEpoch(aFriend.value("friend_since").toInt(), Qt::LocalTime)) {}
    SFriend(const SFriend &aFriend): QObject(aFriend.parent()), _steamID(aFriend._steamID),
        _relationship(aFriend._relationship), _friendSince(aFriend._friendSince) {}

    SFriend &operator=(const SFriend&);
    const bool &operator<(const SFriend&);

    QString steamId()       const {return _steamID;}
    QString relationship()  const {return _relationship;}
    QDateTime friendSince() const {return _friendSince;}

private:
    const QString _steamID;
    const QString _relationship;
    const QDateTime _friendSince;

};

class SFriends : public Sapi {
    Q_OBJECT
public:
    explicit SFriends(const QString &id, bool parallel, QObject *parent = nullptr);
    SFriends(const SFriends&);
    SFriends(QObject *parent = nullptr): Sapi(parent) {}
    ~SFriends() {}

    SFriends &operator=(const SFriends &friends);
    SFriend &operator[](const int &index) {return _friends[index];}

    SFriends &load(const QString &id, bool parallel);
    SFriends &update(bool parallel);
    SFriends &clear();
    SFriends &sort();

    QList<SFriend>::iterator begin() {return _friends.begin();}
    QList<SFriend>::iterator end() {return _friends.end();}
    int count()             const {return _friends.size();}
    SProfiles profiles()    const;

signals:
    void s_finished();

private slots:
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QString _id;
    QList<SFriend> _friends;
};

#endif // SFRIENDS_H
