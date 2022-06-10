#ifndef SFRIENDS_H
#define SFRIENDS_H

#include "./sprofile.h"
#include "../sapi.h"

class SFriend : public Sapi {
    Q_OBJECT
public:
    SFriend(const QJsonObject &aFriend = QJsonObject(), QObject *parent = nullptr);
    SFriend(const SFriend &aFriend);

    QJsonObject toJson() const;
    virtual QString className() const {return "SFriend";}
    static QList<SFriend> load(const ProfileID &aId, std::function<void (QList<SFriend>)> aCallback = nullptr);
    SFriend &operator=(const SFriend&);
    bool operator<(const SFriend&) const;
    bool operator>(const SFriend&) const;
    bool operator==(const SFriend&) const;
    bool operator!=(const SFriend&) const;

    ProfileID steamId()     const;
    QString relationship()  const;
    QDateTime friendSince() const;

    static QStringList getFriendsSteamId(const ProfileID &id);

private:
    ProfileID steamId_;
    QString relationship_;
    QDateTime friend_since_;

};

using SFriends = QList<SFriend>;

struct SFriendProfile {
    SFriendProfile(const SFriend &aFriend, const SProfile &aProfile);
    SFriendProfile(const SProfile &aProfile, const SFriend &aFriend);
    SFriend steamFriend;
    SProfile steamProfile;
};

#endif // SFRIENDS_H
