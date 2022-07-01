#ifndef FAVORITES_H
#define FAVORITES_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/common/filesaveload.h"

class FavoriteGame {
public:
    FavoriteGame(const ProfileID &idUser, const QString &icon, const GameID &appid, const QString &name);
    FavoriteGame(const ProfileID &idUser, const SGame &game);
    FavoriteGame(const FavoriteGame &game);
    FavoriteGame(const QJsonObject &object);

    FavoriteGame &operator=(const FavoriteGame &game) = default;

    QJsonObject toJson() const;
    FavoriteGame &fromJson(const QJsonObject &game);
    FavoriteGame &setIcon(const QString &icon);

    ProfileID steamId() const;
    GameID appId()      const;
    QString name()      const;
    QString icon()      const;

private:
    ProfileID profileId_;
    QString icon_;
    GameID appId_;
    QString name_;
};

class FavoriteGames: public QList<FavoriteGame>, public FileSaveLoad {
public:
    FavoriteGames();

    void append(const FavoriteGame &);
    void remove(const QString &aIdUser, const SGame &);

    QJsonObject toJson() const override;
    void update();

private:
    void fromJson(const QJsonObject &object) override;
};

class FavoriteProfile {
public:
    FavoriteProfile(const ProfileID &profileId);
    FavoriteProfile(const FavoriteProfile &profile);
    FavoriteProfile(const QJsonObject &object);

    FavoriteProfile &operator=(const FavoriteProfile &steamFriend) = default;

    QJsonObject toJson() const;
    void fromJson(const QJsonObject &);
    void setAdded(const QDateTime &date);

    ProfileID profileId() const;

private:
    ProfileID id_;
};

class FavoriteProfiles: public QList<FavoriteProfile>, public FileSaveLoad {
public:
    FavoriteProfiles();

    void append(const FavoriteProfile &);
    void remove(const ProfileID &profileId);

    QJsonObject toJson() const override;
    void update();

private:
    void fromJson(const QJsonObject &object) override;
};

class FavoriteAchievement {
public:
    FavoriteAchievement(const AchievementID &id, const QString &title, const QString &description, const QString &icon, const QString &icon_gray, int achieved);
    FavoriteAchievement(const SAchievement &achievement);
    FavoriteAchievement(const FavoriteAchievement &favoriteAchievement);
    FavoriteAchievement(const QJsonObject &object);

    FavoriteAchievement &operator=(const FavoriteAchievement &favoriteAchievement) = default;
    bool operator==(const SAchievement &achievement) const;
//    bool operator==(const FavoriteAchievement &achievement) const = default;

    QJsonObject toJson() const;
    void fromJson(const QJsonObject &);

    AchievementID apiName() const;
    QString title()         const;
    QString description()   const;
    int achieved()          const;
    QString icon()          const;
    QString iconGray()      const;


private:
    AchievementID apiName_;
    QString title_;
    QString description_;
    int achieved_;
    QString icon_;
    QString iconGray_;
};

class FavoriteAchievementsGame: public QList<FavoriteAchievement> {
public:
    FavoriteAchievementsGame(const ProfileID &idUser, const SGame &game);
    FavoriteAchievementsGame(const FavoriteAchievementsGame &steamFriend);
    FavoriteAchievementsGame(const QJsonObject &object);

    FavoriteAchievementsGame &operator=(const FavoriteAchievementsGame &achievement);
    bool operator==(const SGame &game) const;
//    bool operator==(const FavoriteAchievementsGame &achievement) const = default;

    void remove(const SAchievement &achievement);
    bool isInAchievements(const SAchievement &achievement) const;
    QJsonObject toJson() const;
    void fromJson(const QJsonObject &);

    ProfileID steamId() const {return userId_;}
    GameID appId()      const {return appId_;}
    QString name()      const {return name_;}

private:
    ProfileID userId_;
    GameID appId_;
    QString name_;
};

class FavoriteAchievementsGames: public QList<FavoriteAchievementsGame>, public FileSaveLoad {
public:
    FavoriteAchievementsGames();

    void append(const FavoriteAchievementsGame &);
    void append(const ProfileID &idUser, const SGame &game, const SAchievement &);
    void remove(const ProfileID &idUser, const SGame &game);
    void remove(const ProfileID &idUser, const SGame &game, const SAchievement &);

    QJsonObject toJson() const override;
    void update();

private:
    void fromJson(const QJsonObject &object) override;
};

#endif // FAVORITES_H
