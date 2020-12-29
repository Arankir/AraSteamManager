#ifndef FAVORITES_H
#define FAVORITES_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/steamApi/structures/sachievements.h"

class FavoriteGame {
public:
    FavoriteGame(const QString &idUser, const QString &icon, const int &appid, const QString &name) : _userId(idUser), _icon(icon),
    _appid(appid), _name(name) {}
    FavoriteGame(const QString &idUser, const SGame &game) : _userId(idUser), _icon(game.imgIconUrl()), _appid(game.appId()), _name(game.name()) {}
    FavoriteGame(const QJsonObject &object);
    FavoriteGame(const FavoriteGame &game) : _userId(game._userId), _icon(game._icon), _appid(game._appid), _name(game._name) {}

    FavoriteGame &operator=(const FavoriteGame &game);

    QJsonObject toJson();//Поменять на другой тип хранения данных
    FavoriteGame &fromJson(QJsonObject game);
    FavoriteGame &setIcon(QString icon);

    QString steamId()   const {return _userId;}
    QString icon()      const {return _icon;}
    int appId()         const {return _appid;}
    QString name()      const {return _name;}

private:
    QString _userId;
    QString _icon;
    int _appid;
    QString _name;
};

class FavoriteFriend {
public:
    FavoriteFriend(const QString &idUser, const QDateTime &added, const QString &id, const QString &name) : _userId(idUser), _added(added),
    _id(id), _name(name) {}
    FavoriteFriend(const QJsonObject &object);
    FavoriteFriend(const FavoriteFriend &steamFriend) : _userId(steamFriend._userId), _added(steamFriend._added), _id(steamFriend._id), _name(steamFriend._name) {}

    FavoriteFriend &operator=(const FavoriteFriend &steamFriend);

    QJsonObject toJson();//Поменять на другой тип хранения данных
    FavoriteFriend &fromJson(QJsonObject);
    FavoriteFriend &setAdded(const QDateTime &date);

    QString steamId()   const {return _userId;}
    QDateTime added()   const {return _added;}
    QString friendId()  const {return _id;}
    QString name()      const {return _name;}

private:
    QString _userId;
    QDateTime _added;
    QString _id;
    QString _name;
};

class FavoriteAchievement {
public:
    FavoriteAchievement(const QString &id, const QString &title, const QString &description, const QString &icon, const QString &icon_gray, int achieved) :
        _id(id), _title(title), _description(description), _achieved(achieved), _icon(icon), _iconGray(icon_gray) {}
    FavoriteAchievement(const SAchievement &achievement) : _id(achievement.apiName()), _title(achievement.displayName()), _description(achievement.description()),
        _achieved(achievement.achieved())/*, _icon(achievement._icon), _icon_gray(achievement.icon_gray)*/ {}
    FavoriteAchievement(const FavoriteAchievement &fag) : _id(fag._id), _title(fag._title), _description(fag._description), _achieved(fag._achieved),
    _icon(fag._icon), _iconGray(fag._iconGray) {}
    FavoriteAchievement(const QJsonObject &fag);

    FavoriteAchievement &operator=(const FavoriteAchievement &fag);

    QJsonObject toJson();//Поменять на другой тип хранения данных
    FavoriteAchievement &fromJson(QJsonObject);
    bool isThisAchievement(const SAchievement &achievement);

    QString apiName()       const {return _id;}
    QString title()         const {return _title;}
    QString description()   const {return _description;}
    int achieved()          const {return _achieved;}
    QString icon()          const {return _icon;}
    QString iconGray()      const {return _iconGray;}


private:
    QString _id;
    QString _title;
    QString _description;
    int _achieved;
    QString _icon;
    QString _iconGray;
};

class FavoriteAchievementsGame {
public:
    FavoriteAchievementsGame(const QString &idUser, const SGame &game) : _userId(idUser), _appid(game.appId()), _name(game.name()) {}
    FavoriteAchievementsGame(const QJsonObject &object);
    FavoriteAchievementsGame(const FavoriteAchievementsGame &steamFriend) : _userId(steamFriend._userId), _achievements(steamFriend._achievements),
    _appid(steamFriend._appid), _name(steamFriend._name) {}

    FavoriteAchievementsGame &operator=(const FavoriteAchievementsGame &achievement);
    FavoriteAchievement &operator[](const int index) {return _achievements[index];}

    bool addAchievement(const SAchievement &achievement, const bool elseRemove = false);
    bool removeAchievement(const SAchievement &achievement, const bool elseRemove = false);
    bool isInAchievements(const SAchievement &achievement);
    QJsonObject toJson();//Поменять на другой тип хранения данных
    FavoriteAchievementsGame &fromJson(QJsonObject);
    bool isEqual(const SGame &game) const;

    QList<FavoriteAchievement>::iterator begin() {return _achievements.begin();}
    QList<FavoriteAchievement>::iterator end() {return _achievements.end();}
    QString steamId()                           const {return _userId;}
    int appId()                                 const {return _appid;}
    QString name()                              const {return _name;}
    QList<FavoriteAchievement> achievements()   const {return _achievements;}

private:
    QString _userId;
    QList<FavoriteAchievement> _achievements;
    int _appid;
    QString _name;
};

class Favorites : public QObject {
    Q_OBJECT

public:
    Favorites(QObject *parent = nullptr): QObject(parent) {}

    bool addGame(const QString &idUser, const SGame &game, bool elseRemove = false);
    bool addFriend(const QString &idUser, const SProfile &profileFriend, const SFriend &friendLink, bool elseRemove = false);
    bool addAchievement(const QString &idUser, const SGame &game, const SAchievement &achievement, bool elseRemove = false);

    bool removeGame(const QString &idUser, const SGame &game, bool elseCreate = false);
    bool removeFriend(const QString &idUser, const SProfile &profileFriend, const SFriend &friendLink, bool elseCreate = false);
    bool removeAchievement(const QString &idUser, const SGame &game, const SAchievement &achievement, bool elseCreate = false);

    static QList<FavoriteGame>             games()                                               {return _fGame;}
    static QList<FavoriteFriend>           friends()                                             {return _fFriend;}
    static QList<FavoriteAchievementsGame> achievementsGames()                                   {return _fAchievement;}
    static FavoriteAchievementsGame&       achievementsGame(const QString &idUser, const SGame &game);

signals:

private slots:
    QJsonObject gamesToJson();
    QJsonObject friendsToJson();
    QJsonObject achievementsToJson();

    void saveGames();
    void saveFriends();
    void saveAchievements();
    void saveAll();

    static QList<FavoriteGame> initGames();
    static QList<FavoriteFriend> initFriends();
    static QList<FavoriteAchievementsGame> initAchievements();

private:
    static QList<FavoriteGame> _fGame;
    static QList<FavoriteFriend> _fFriend;
    static QList<FavoriteAchievementsGame> _fAchievement;

};

#endif // FAVORITES_H
