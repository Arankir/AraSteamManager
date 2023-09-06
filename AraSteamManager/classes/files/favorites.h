#ifndef FAVORITES_H
#define FAVORITES_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/common/filesaveload.h"

class Favorite {
public:
    enum FavoriteType {
        unknown,
        game,
        achievement,
        profile
    };

    Favorite(FavoriteType);
    virtual QJsonObject toJson() const;
    virtual void fromJson(const QJsonObject&);
    FavoriteType type();

protected:
    FavoriteType type_ = unknown;
};

class FavoriteGame: public Favorite {
public:
    FavoriteGame(const ProfileID &profileId, const QString &icon, const GameID &appId, const QString &name);
    FavoriteGame(const ProfileID &profileId, const SGame &game);
    FavoriteGame(const FavoriteGame &game);
    FavoriteGame(const QJsonObject &object = QJsonObject());

    FavoriteGame &operator=(const FavoriteGame &game) = default;

    QJsonObject toJson() const;
    void fromJson(const QJsonObject &game);

    ProfileID steamId() const;
    GameID appId()      const;
    QString name()      const;
    QString icon()      const;
    QPixmap iconPixmap()const;

private:
    ProfileID profileId_;
    QString icon_;
    GameID appId_;
    QString name_;

    mutable QImage gameIconPixmap_;
};

class FavoriteGames: public QList<FavoriteGame>, public FileSaveLoad {
public:
    FavoriteGames();

    void append(const FavoriteGame &);
    void remove(const ProfileID &profileId);
    void remove(const ProfileID &profileId, const GameID &);

    QJsonObject toJson() const override;
    void update();

private:
    void fromJson(const QJsonObject &object) override;
};

class FavoriteProfile: public Favorite {
public:
    FavoriteProfile(const ProfileID &profileId);
    FavoriteProfile(const FavoriteProfile &profile);
    FavoriteProfile(const QJsonObject &object = QJsonObject());

    FavoriteProfile &operator=(const FavoriteProfile &steamProfile) = default;

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

class FavoriteAchievement: public Favorite {
public:
    FavoriteAchievement(const AchievementID &achievementId, const QString &title, const QString &description,
                        const QString &icon, const QString &icon_gray, int achieved, const GameID &appId,
                        const QString &gameName, const QString &gameIcon, const ProfileID &profileId);
    FavoriteAchievement(const SAchievement &achievement, const SGame &game, const ProfileID &profileId);
    FavoriteAchievement(const FavoriteAchievement &favoriteAchievement);
    FavoriteAchievement(const QJsonObject &object = QJsonObject());

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

    struct Game {
        Game();
        Game(const SGame &game);
        GameID appId;
        QString name;
        QString icon;

        QPixmap iconPixmap();

        QJsonObject toJson() const;
        void fromJson(const QJsonObject &);

        bool operator<(const Game &game) const;
        bool operator==(const Game &game) const;

    private:
        mutable QImage gameIconPixmap_;
    };

    Game game()             const;

private:
    AchievementID apiName_;
    QString title_;
    QString description_;
    int achieved_;
    QString icon_;
    QString iconGray_;

    Game game_;

    ProfileID profileId_;
};

//class FavoriteAchievementsGame: public QList<FavoriteAchievement> {
//public:
//    FavoriteAchievementsGame(const ProfileID &profileId, const SGame &game);
//    FavoriteAchievementsGame(const FavoriteAchievementsGame &steamFriend);
//    FavoriteAchievementsGame(const QJsonObject &object);

//    FavoriteAchievementsGame &operator=(const FavoriteAchievementsGame &achievement);
//    bool operator==(const SGame &game) const;

//    void remove(const AchievementID &achievement);
//    bool isInAchievements(const AchievementID &achievement) const;
//    QJsonObject toJson() const;
//    void fromJson(const QJsonObject &);

//    ProfileID steamId() const {return userId_;}
//    GameID appId()      const {return appId_;}
//    QString name()      const {return name_;}

//private:
//    ProfileID userId_;
//    GameID appId_;
//    QString name_;
//};

//class FavoriteAchievementsGames: public QList<FavoriteAchievementsGame>, public FileSaveLoad {
//public:
//    FavoriteAchievementsGames();

//    void append(const FavoriteAchievementsGame &);
//    void append(const ProfileID &profileId, const SGame &game, const SAchievement &);
//    void remove(const ProfileID &profileId, const GameID &game);
//    void remove(const ProfileID &profileId, const GameID &game, const AchievementID &);
//    bool isInFavorite(const GameID &gameId, const ProfileID &profileId, const AchievementID &achievementId);

//    QJsonObject toJson() const override;
//    void update();

//private:
//    void fromJson(const QJsonObject &object) override;
//};

class FavoriteAchievements: public FileSaveLoad {
public:
    FavoriteAchievements();

    void append(const FavoriteAchievements &);
    void append(const FavoriteAchievement &, const ProfileID &profileId);
    void append(const ProfileID &profileId, const SGame &game, const SAchievement &);
    void remove(const ProfileID &profileId, const GameID &game);
    void remove(const ProfileID &profileId, const GameID &game, const AchievementID &);

    bool isInFavorite(const GameID &gameId, const ProfileID &profileId, const AchievementID &achievementId);
    QList<ProfileID> profiles() const;
    QList<FavoriteAchievement::Game> games(const ProfileID &profile) const;
    QList<FavoriteAchievement> achievements(const ProfileID &profile, const FavoriteAchievement::Game &game) const;

    QJsonObject toJson() const override;
    void update();

private:
    void fromJson(const QJsonObject &object) override;
    QMap<ProfileID, QMap<FavoriteAchievement::Game, QList<FavoriteAchievement> > > favorites_;
};

#endif // FAVORITES_H
