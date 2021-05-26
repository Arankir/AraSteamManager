#ifndef SFRIENDS_H
#define SFRIENDS_H

#include "./sprofile.h"
#include "../sapi.h"

class SFriend : public Sapi {
    Q_OBJECT
public:
    explicit SFriend(const QJsonObject &aFriend = QJsonObject(), QObject *parent = nullptr): Sapi(parent), _steamID(aFriend.value("steamid").toString()),
        _relationship(aFriend.value("relationship").toString()), _friendSince(QDateTime::fromSecsSinceEpoch(aFriend.value("friend_since").toInt(), Qt::LocalTime)) {}
    SFriend(const SFriend &aFriend): Sapi(aFriend.parent()), _steamID(aFriend._steamID),
        _relationship(aFriend._relationship), _friendSince(aFriend._friendSince) {}

    QJsonObject toJson() const;
    virtual QString className() const {return "SFriend";}
    static QList<SFriend> load(const QString &aId, std::function<void (QList<SFriend>)> aCallback = nullptr);
    SFriend &operator=(const SFriend&);
    bool operator<(const SFriend&) const;
    bool operator>(const SFriend&) const;
    bool operator==(const SFriend&) const;
    bool operator!=(const SFriend&) const;

    QString steamId()       const {return _steamID;}
    QString relationship()  const {return _relationship;}
    QDateTime friendSince() const {return _friendSince;}

private:
    const QString _steamID;
    const QString _relationship;
    const QDateTime _friendSince;

};

#endif // SFRIENDS_H
