#include "favorites.h"
#include "classes/common/settings.h"

template<typename T>
QList<T> initFavorite(const QString &aPath, const QString &aType) {
    QList<T> list;
    QByteArray data;
    if (readFile(aPath, data)) {
        QJsonObject favorites = QJsonDocument().fromJson(data).object();
        if (favorites.value("type").toString() == aType) {
            for (auto &&value: favorites.value("values").toArray()) {
                list.append(std::move(T(value.toObject())));
            }
        } else {
            qWarning() << "favorites " + aType + " file is corrupted";
        }
    }
    return list;
}

QList<FavoriteGame>              Favorites::_fGame          = initFavorite<FavoriteGame>(Paths::favorites("games"), "games");
QList<FavoriteFriend>            Favorites::_fFriend        = initFavorite<FavoriteFriend>(Paths::favorites("friends"), "friends");
QList<FavoriteAchievementsGame>  Favorites::_fAchievement   = initFavorite<FavoriteAchievementsGame>(Paths::favorites("achievements"), "achievements");

QJsonObject Favorites::gamesToJson() {
    QJsonObject object;
    object["type"] = "games";
    object["version"] = "1.0";

    QJsonArray values;
    for(auto &game: _fGame) {
        values.append(std::move(game.toJson()));
    }
    object["values"] = values;
    return object;
}

QJsonObject Favorites::friendsToJson() {
    QJsonObject object;
    object["type"] = "friends";
    object["version"] = "1.0";

    QJsonArray values;
    for(auto &steamFriend: _fFriend) {
        values.append(std::move(steamFriend.toJson()));
    }
    object["values"] = values;
    return object;
}

QJsonObject Favorites::achievementsToJson() {
    QJsonObject object;
    object["type"] = "achievements";
    object["version"] = "1.0";

    QJsonArray values;
    for(auto &achievement: _fAchievement) {
        values.append(std::move(achievement.toJson()));
    }
    object["values"] = values;
    return object;
}

void Favorites::saveGames() {
    saveFile(Paths::favorites("games"), QJsonDocument(gamesToJson()).toJson());
}

void Favorites::saveFriends() {
    saveFile(Paths::favorites("friends"), QJsonDocument(friendsToJson()).toJson());
}

void Favorites::saveAchievements() {
    saveFile(Paths::favorites("achievements"), QJsonDocument(achievementsToJson()).toJson());
}

void Favorites::saveAll() {
    saveGames();
    saveFriends();
    saveAchievements();
}

bool Favorites::addGame(const QString &aIdUser, const SGame &aGame, const bool &aElseRemove) {
    auto iterator = std::find_if(_fGame.begin(),
                                 _fGame.end(),
                                 [=](const FavoriteGame &game) {
                                    return (aIdUser == game.steamId())
                                            && (aGame.appId() == game.appId())
                                            && (aGame.name() == game.name());
                                 });
    if (iterator == _fGame.end()) {
        _fGame.append(std::move(FavoriteGame(aIdUser, aGame)));
        saveGames();
        return true;
    } else {
        (*iterator).setIcon(aGame.imgIconUrl());
        if (aElseRemove) {
            removeGame(aIdUser, aGame);
        }
        return false;
    }
}

bool Favorites::addFriend(const QString &aIdUser, const SProfile &aFriendProfile, const SFriend &aFriendLink, const bool &aElseRemove) {
    auto iterator = std::find_if(_fFriend.begin(),
                                 _fFriend.end(),
                                 [=](const FavoriteFriend &steamFriend) {
                                    return (aIdUser == steamFriend.steamId())
                                            && (aFriendProfile.personaName() == steamFriend.name())
                                            && (aFriendProfile.steamID() == steamFriend.friendId());
                                 });
    if (iterator == _fFriend.end()) {
        _fFriend.append(std::move(FavoriteFriend(aIdUser, aFriendLink.friendSince(), aFriendProfile.steamID(), aFriendProfile.personaName())));
        saveFriends();
        return true;
    } else {
        (*iterator).setAdded(aFriendLink.friendSince());
        if (aElseRemove) {
            removeFriend(aIdUser, aFriendProfile, aFriendLink);
        }
        return false;
    }
}

bool Favorites::addAchievement(const QString &aIdUser, const SGame &aGame, const SAchievement &aAchievement, const bool &aElseRemove) {
    FavoriteAchievementsGame &achievementGame = achievementsGame(aIdUser, aGame);
    bool result = achievementGame.addAchievement(aAchievement);
    if (aElseRemove && !result) {
        achievementGame.removeAchievement(aAchievement);
    }
    saveAchievements();
    return result;
}

FavoriteAchievementsGame &Favorites::achievementsGame(const QString &aIdUser, const SGame &aGame) {
    auto iterator = std::find_if(_fAchievement.begin(),
                                 _fAchievement.end(),
                                 [=](FavoriteAchievementsGame &achievementsGame) {
                                    return (aIdUser == achievementsGame.steamId())
                                            && (achievementsGame.isThisGame(aGame));
                                 });
    if (iterator != _fAchievement.end()) {
        return *iterator;
    } else {
        FavoriteAchievementsGame game(aIdUser, aGame);
        _fAchievement.append(game);
        return _fAchievement.last();
    }
}

bool Favorites::removeGame(const QString &aIdUser, const SGame &aGame, const bool &aElseCreate) {
    auto iterator = std::remove_if(_fGame.begin(),
                                   _fGame.end(),
                                   [=](FavoriteGame &game) {
                                        return (aIdUser == game.steamId())
                                                && (aGame.appId() == game.appId())
                                                && (aGame.name() == game.name());
                                   });
    if (iterator == _fGame.end()) {
        if (aElseCreate) {
            addGame(aIdUser, aGame);
        }
        return false;
    } else {
        _fGame.erase(iterator, _fGame.end());
        saveGames();
        return true;
    }
}

bool Favorites::removeFriend(const QString &aIdUser, const SProfile &aProfileFriend, const SFriend &aFriendLink, const bool &aElseCreate) {
    auto iterator = std::remove_if(_fFriend.begin(),
                                   _fFriend.end(),
                                   [=](FavoriteFriend &steamFriend) {
                                        return (aIdUser == steamFriend.steamId())
                                                && (aProfileFriend.personaName() == steamFriend.name())
                                                && (aProfileFriend.steamID() == steamFriend.friendId());
                                   });
    if (iterator == _fFriend.end()) {
        if (aElseCreate) {
            addFriend(aIdUser, aProfileFriend, aFriendLink);
        }
        return false;
    } else {
        _fFriend.erase(iterator, _fFriend.end());
        saveFriends();
        return true;
    }
}

bool Favorites::removeAchievement(const QString &aIdUser, const SGame &aGame, const SAchievement &aAchievement, const bool &aElseCreate) {
    FavoriteAchievementsGame &achievementGame = achievementsGame(aIdUser, aGame);
    bool result = achievementGame.removeAchievement(aAchievement);
    if (aElseCreate && !result) {
        achievementGame.addAchievement(aAchievement);
    }
    saveAchievements();
    return result;
}

#define FavGame {
FavoriteGame::FavoriteGame(const QJsonObject &aObject) {
    fromJson(aObject);
}

FavoriteGame &FavoriteGame::operator=(const FavoriteGame &game) {
    _userId = game._userId;
    _appid  = game._appid;
    _name   = game._name;
    _icon   = game._icon;
    return *this;
}

QJsonObject FavoriteGame::toJson() {
    QJsonObject obj;
    obj["icon"]     = _icon;
    obj["appid"]    = _appid;
    obj["userId"]   = _userId;
    obj["name"]     = _name;
    return obj;
}

FavoriteGame &FavoriteGame::fromJson(const QJsonObject &aGame) {
    _icon   = aGame["icon"].toString();
    _appid  = aGame["appid"].toInt();
    _userId = aGame["userId"].toString();
    _name   = aGame["name"].toString();
    return *this;
}

FavoriteGame &FavoriteGame::setIcon(const QString &aIcon) {
    _icon = aIcon;
    return *this;
}
#define FavGameEnd }

#define FavFriend {
FavoriteFriend::FavoriteFriend(const QJsonObject &aObject) {
    fromJson(aObject);
}

FavoriteFriend &FavoriteFriend::operator=(const FavoriteFriend &aFriend) {
    _id     = aFriend._id;
    _added  = aFriend._added;
    _userId = aFriend._userId;
    _name   = aFriend._name;
    return *this;
}

QJsonObject FavoriteFriend::toJson() {
    QJsonObject obj;
    obj["id"]       = _id;
    obj["added"]    = _added.toString(Settings::dateTimeFormat());
    obj["userId"]   = _userId;
    obj["name"]     = _name;
    return obj;
}

FavoriteFriend &FavoriteFriend::fromJson(const QJsonObject &aFriend) {
    _id     = aFriend["id"].toString();
    _added  = QDateTime::fromString(aFriend["added"].toString(), Settings::dateTimeFormat());
    _userId = aFriend["userId"].toString();
    _name   = aFriend["name"].toString();
    return *this;
}

FavoriteFriend &FavoriteFriend::setAdded(const QDateTime &aDate) {
    _added = aDate;
    return *this;
}
#define FavFriendEnd }

#define FavAchievementGame {
#define FavAchievement {
FavoriteAchievement::FavoriteAchievement(const QJsonObject &fag) {
    fromJson(fag);
}

FavoriteAchievement &FavoriteAchievement::operator=(const FavoriteAchievement &fag) {
    _id             = fag._id;
    _title          = fag._title;
    _description    = fag._description;
    _achieved       = fag._achieved;
    _icon           = fag._icon;
    _iconGray      = fag._iconGray;
    return *this;
}

QJsonObject FavoriteAchievement::toJson() {
    QJsonObject obj;
    obj["id"]           = _id;
    obj["title"]        = _title;
    obj["description"]  = _description;
    obj["achieved"]     = _achieved;
    obj["icon"]         = _icon;
    obj["icon_gray"]    = _iconGray;
    return obj;
}

FavoriteAchievement &FavoriteAchievement::fromJson(const QJsonObject &fag) {
    _id             = fag["id"].toString();
    _title          = fag["title"].toString();
    _description    = fag["description"].toString();
    _achieved       = fag["achieved"].toInt();
    _icon           = fag["icon"].toString();
    _iconGray       = fag["icon_gray"].toString();
    return *this;
}

bool FavoriteAchievement::isThisAchievement(const SAchievement &aAchievement) const {
    return (_id == aAchievement.apiName()) &&
            (_title == aAchievement.displayName()) &&
            (_description == aAchievement.description()) &&
            (_achieved == aAchievement.achieved()) /*&& () && ()*/;
}
#define FavAchievementEnd }

FavoriteAchievementsGame::FavoriteAchievementsGame(const QJsonObject &aObject) {
    fromJson(aObject);
}

FavoriteAchievementsGame &FavoriteAchievementsGame::operator=(const FavoriteAchievementsGame &aAchievement) {
    _appid          = aAchievement._appid;
    _name           = aAchievement._name;
    _userId         = aAchievement._userId;
    _achievements   = aAchievement._achievements;
    return *this;
}

bool FavoriteAchievementsGame::addAchievement(const SAchievement &aAchievement, const bool &aElseRemove) {
    if (isInAchievements(aAchievement)) {
        if (aElseRemove) {
            removeAchievement(aAchievement);
        }
        return false;
    } else {
        _achievements.append(std::move(FavoriteAchievement(aAchievement)));
        return true;
    }
}

bool FavoriteAchievementsGame::removeAchievement(const SAchievement &aAchievement, const bool &aElseCreate) {
    auto iterator = std::remove_if(_achievements.begin(),
                                   _achievements.end(),
                                   [=](FavoriteAchievement &achievement) {
                                        return achievement.isThisAchievement(aAchievement);
                                   });
    if (iterator == _achievements.end()) {
        if (aElseCreate) {
            addAchievement(aAchievement);
        }
        return false;
    } else {
        _achievements.erase(iterator, _achievements.end());
        return true;
    }
}

bool FavoriteAchievementsGame::isInAchievements(const SAchievement &aAchievement) const {
    return std::find_if(_achievements.cbegin(),
                        _achievements.cend(),
                        [=](const FavoriteAchievement &achievement) {
                            return achievement.isThisAchievement(aAchievement);
                        })
            != _achievements.end();
}

QJsonObject FavoriteAchievementsGame::toJson() {
    QJsonObject obj;

    QJsonObject game;
    game["appid"]      = _appid;
    game["name"]    = _name;
    game["userId"]   = _userId;

    QJsonArray values;
    for (auto &&achievement: _achievements) {
        values.append(achievement.toJson());
    }

    obj["game"]     = game;
    obj["values"]   = values;
    return obj;
}

FavoriteAchievementsGame &FavoriteAchievementsGame::fromJson(const QJsonObject &achievements) {
    _appid  = achievements.value("game").toObject().value("appid").toInt();
    _name   = achievements.value("game").toObject().value("name").toString();
    _userId = achievements.value("game").toObject().value("userId").toString();

    for (auto &&achievement: achievements.value("values").toArray()) {
        _achievements.append(std::move(FavoriteAchievement(achievement.toObject())));
    }
    return *this;
}

bool FavoriteAchievementsGame::isThisGame(const SGame &aGame) const {
    return (_appid == aGame.appId());// && (_name == aGame.name());
}
#define FavAchievementsGameEnd }
