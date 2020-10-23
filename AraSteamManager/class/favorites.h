#ifndef FAVORITES_H
#define FAVORITES_H

#include <QObject>
#include <QDateTime>
#include "class/steamapi/Sgames.h"
#include "class/steamapi/Sfriends.h"
#include "class/steamapi/Sachievements.h"
#include "class/settings.h"

class FavoriteGame {
public:
    FavoriteGame(const QString &idUser, const QString &icon, const int &appid, const QString &name) : _userId(idUser), _icon(icon),
    _appid(appid), _name(name) {}
    FavoriteGame(const QString &idUser, const SGame &game) : _userId(idUser), _icon(game._img_icon_url), _appid(game._appID), _name(game._name) {}
    FavoriteGame(const QJsonObject &object);
    FavoriteGame(const FavoriteGame &game) : _userId(game._userId), _icon(game._icon), _appid(game._appid), _name(game._name) {}

    FavoriteGame &operator=(const FavoriteGame &game);

    QJsonObject toJson();//Поменять на другой тип хранения данных
    FavoriteGame &fromJson(QJsonObject game);
    FavoriteGame &setIcon(QString icon);

    QString getUserId() const {return _userId;}
    QString getIcon()   const {return _icon;}
    int getAppid()  const {return _appid;}
    QString getName()   const {return _name;}

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

    QString getUserId()     const {return _userId;}
    QDateTime getAdded()    const {return _added;}
    QString getId()         const {return _id;}
    QString getName()       const {return _name;}

private:
    QString _userId;
    QDateTime _added;
    QString _id;
    QString _name;
};

class FavoriteAchievement {
public:
    FavoriteAchievement(const QString &id, const QString &title, const QString &description, const QString &icon, const QString &icon_gray, int achieved) :
        _id(id), _title(title), _description(description), _achieved(achieved), _icon(icon), _icon_gray(icon_gray) {}
    FavoriteAchievement(const SAchievement &achievement) : _id(achievement._apiName), _title(achievement._displayName), _description(achievement._description),
        _achieved(achievement._achieved)/*, _icon(achievement._icon), _icon_gray(achievement.icon_gray)*/ {}
    FavoriteAchievement(const FavoriteAchievement &fag) : _id(fag._id), _title(fag._title), _description(fag._description), _achieved(fag._achieved),
    _icon(fag._icon), _icon_gray(fag._icon_gray) {}
    FavoriteAchievement(const QJsonObject &fag);

    FavoriteAchievement &operator=(const FavoriteAchievement &fag);

    QJsonObject toJson();//Поменять на другой тип хранения данных
    FavoriteAchievement &fromJson(QJsonObject);
    bool isThisAchievement(const SAchievement &achievement);

    QString getId()             const {return _id;}
    QString getTitle()          const {return _title;}
    QString getDescription()    const {return _description;}
    int getAchieved()           const {return _achieved;}
    QString getIcon()           const {return _icon;}
    QString getIconGray()       const {return _icon_gray;}


private:
    QString _id;
    QString _title;
    QString _description;
    int _achieved;
    QString _icon;
    QString _icon_gray;
};

class FavoriteAchievementsGame {
public:
    FavoriteAchievementsGame(const QString &idUser, const SGame &game) : _userId(idUser), _appid(game._appID), _name(game._name) {}
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
    QString getUserId() const {return _userId;}
    int getAppid()  const {return _appid;}
    QString getName()   const {return _name;}
    QList<FavoriteAchievement> getAchievements() const {return _achievements;}

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

    QList<FavoriteGame>             getGames()                                                      const {return _fGame;}
    QList<FavoriteFriend>           getFriends()                                                    const {return _fFriend;}
    QList<FavoriteAchievementsGame> getAchievementsGames()                                          const {return _fAchievement;}
    FavoriteAchievementsGame&       getAchievementsGame(const QString &idUser, const SGame &game)   const;

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
