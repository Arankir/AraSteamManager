#include "favorites.h"

QList<FavoriteGame>              Favorites::_fGame           = initGames();
QList<FavoriteFriend>            Favorites::_fFriend         = initFriends();
QList<FavoriteAchievementsGame>  Favorites::_fAchievement    = initAchievements();

QJsonObject Favorites::gamesToJson() {
    QJsonObject object;
    object["type"] = "games";
    object["version"] = "1.0";

    QJsonArray values;
    for(auto game: _fGame) {
        values.append(game.toJson());
    }
    object["values"] = values;
    return object;
}

QJsonObject Favorites::friendsToJson() {
    QJsonObject object;
    object["type"] = "friends";
    object["version"] = "1.0";

    QJsonArray values;
    for(auto steamFriend: _fFriend) {
        values.append(steamFriend.toJson());
    }
    object["values"] = values;
    return object;
}

QJsonObject Favorites::achievementsToJson() {
    QJsonObject object;
    object["type"] = "achievements";
    object["version"] = "1.0";

    QJsonArray values;
    for(auto achievement: _fAchievement) {
        values.append(achievement.toJson());
    }
    object["values"] = values;
    return object;
}

void Favorites::saveGames() {
    Settings::createDir(Paths::favorites("games"));
    QFile file(Paths::favorites("games"));
    file.open(QFile::WriteOnly);
    file.write(QJsonDocument(gamesToJson()).toJson());
    file.close();
}

void Favorites::saveFriends() {
    Settings::createDir(Paths::favorites("friends"));
    QFile file(Paths::favorites("friends"));
    file.open(QFile::WriteOnly);
    file.write(QJsonDocument(friendsToJson()).toJson());
    file.close();
}

void Favorites::saveAchievements() {
    Settings::createDir(Paths::favorites("achievements"));
    QFile file(Paths::favorites("achievements"));
    file.open(QFile::WriteOnly);
    QJsonDocument doc(achievementsToJson());
    file.write(doc.toJson());
    file.close();
}

void Favorites::saveAll() {
    saveGames();
    saveFriends();
    saveAchievements();
}

bool Favorites::addGame(const QString &aIdUser, const SGame &aGame, bool aElseRemove) {
    auto iterator = std::find_if(_fGame.begin(), _fGame.end(), [=](FavoriteGame &game) {
                                                                    return (aIdUser == game.getUserId())
                                                                            && (aGame._appID == game.getAppid())
                                                                            && (aGame._name == game.getName());
                                                                });
    if (iterator == _fGame.end()) {
        _fGame.append(FavoriteGame(aIdUser, aGame));
        saveGames();
        return true;
    } else {
        (*iterator).setIcon(aGame._img_icon_url);
        if (aElseRemove) {
            removeGame(aIdUser, aGame);
        }
        return false;
    }
}

bool Favorites::addFriend(const QString &aIdUser, const SProfile &aProfileFriend, const SFriend &aFriendLink, bool aElseRemove) {
    auto iterator = std::find_if(_fFriend.begin(), _fFriend.end(), [=](FavoriteFriend &steamFriend) {
                                                                        return (aIdUser == steamFriend.getUserId())
                                                                                && (aProfileFriend._personaName == steamFriend.getName())
                                                                                && (aProfileFriend._steamID == steamFriend.getId());
                                                                    });
    if (iterator == _fFriend.end()) {
        _fFriend.append(FavoriteFriend(aIdUser, aFriendLink._friend_since, aProfileFriend._steamID, aProfileFriend._personaName));
        saveFriends();
        return true;
    } else {
        (*iterator).setAdded(aFriendLink._friend_since);
        if (aElseRemove) {
            removeFriend(aIdUser, aProfileFriend, aFriendLink);
        }
        return false;
    }
}

bool Favorites::addAchievement(const QString &aIdUser, const SGame &aGame, const SAchievement &aAchievement, bool aElseRemove) {
    bool result = getAchievementsGame(aIdUser, aGame).addAchievement(aAchievement);
    if (aElseRemove && !result) {
        getAchievementsGame(aIdUser, aGame).removeAchievement(aAchievement);
    }
    saveAchievements();
    return result;
}

bool Favorites::removeGame(const QString &aIdUser, const SGame &aGame, bool aElseCreate) {
    auto iterator = std::remove_if(_fGame.begin(), _fGame.end(), [=](FavoriteGame &game) {
                                                                    return (aIdUser == game.getUserId())
                                                                            && (aGame._appID == game.getAppid())
                                                                            && (aGame._name == game.getName());
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

bool Favorites::removeFriend(const QString &aIdUser, const SProfile &aProfileFriend, const SFriend &aFriendLink, bool aElseCreate) {
    auto iterator = std::remove_if(_fFriend.begin(), _fFriend.end(), [=](FavoriteFriend &steamFriend) {
                                                                        return (aIdUser == steamFriend.getUserId())
                                                                                && (aProfileFriend._personaName == steamFriend.getName())
                                                                                && (aProfileFriend._steamID == steamFriend.getId());
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

bool Favorites::removeAchievement(const QString &aIdUser, const SGame &aGame, const SAchievement &aAchievement, bool aElseCreate) {
    bool result = getAchievementsGame(aIdUser, aGame).removeAchievement(aAchievement);
    if (aElseCreate && !result) {
        getAchievementsGame(aIdUser, aGame).addAchievement(aAchievement);
    }
    saveAchievements();
    return result;
}

FavoriteAchievementsGame &Favorites::getAchievementsGame(const QString &aIdUser, const SGame &aGame) const {
    auto iterator = std::find_if(_fAchievement.begin(), _fAchievement.end(), [=](FavoriteAchievementsGame &achievementsGame) {
                                                                        return (aIdUser == achievementsGame.getUserId())
                                                                                && (achievementsGame.isEqual(aGame));
                                                                    });
    if (iterator != _fAchievement.end()) {
        return *iterator;
    } else {
        FavoriteAchievementsGame game(aIdUser, aGame);
        _fAchievement.append(game);
        return _fAchievement.last();
    }
}

QList<FavoriteFriend> Favorites::initFriends() {
    QList<FavoriteFriend> list;
    Settings::createDir(Paths::favorites("friends"));
    QFile file(Paths::favorites("friends"));
    if (file.exists()) {
        if (file.open(QFile::ReadOnly)) {
            QJsonObject favorites = QJsonDocument().fromJson(file.readAll()).object();
            if (favorites.value("type").toString() == "friends") {
                for (auto steamFriend: favorites.value("values").toArray()) {
                    list.append(FavoriteFriend(steamFriend.toObject()));
                }
            } else {
                qWarning() << "favorites friends file is corrupted";
            }
            file.close();
        }
    }
    return list;
}

QList<FavoriteAchievementsGame> Favorites::initAchievements() {
    QList<FavoriteAchievementsGame> list;
    Settings::createDir(Paths::favorites("achievements"));
    QFile file(Paths::favorites("achievements"));
    if (file.exists()) {
        if (file.open(QFile::ReadOnly)) {
            QJsonObject favorites = QJsonDocument().fromJson(file.readAll()).object();
            if (favorites.value("type").toString() == "achievements") {
                for (auto game: favorites.value("values").toArray()) {
                    list.append(FavoriteAchievementsGame(game.toObject()));
                }
            } else {
                qWarning() << "favorites achievements file is corrupted";
            }
            file.close();
        }
    }
    return list;
}

QList<FavoriteGame> Favorites::initGames() {
    QList<FavoriteGame> list;
    Settings::createDir(Paths::favorites("games"));
    QFile file(Paths::favorites("games"));
    if (file.exists()) {
        if (file.open(QFile::ReadOnly)) {
            QJsonObject favorites = QJsonDocument().fromJson(file.readAll()).object();
            if (favorites.value("type").toString() == "games") {
                for (auto game: favorites.value("values").toArray()) {
                    list.append(FavoriteGame(game.toObject()));
                }
            } else {
                qWarning() << "favorites games file is corrupted";
            }
            file.close();
        }
    }
    return list;
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

FavoriteGame &FavoriteGame::fromJson(QJsonObject aGame) {
    _icon   = aGame["icon"].toString();
    _appid  = aGame["appid"].toInt();
    _userId = aGame["userId"].toString();
    _name   = aGame["name"].toString();
    return *this;
}

FavoriteGame &FavoriteGame::setIcon(QString aIcon) {
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
    obj["added"]    = _added.toString("yyyy.MM.dd hh:mm:ss");
    obj["userId"]   = _userId;
    obj["name"]     = _name;
    return obj;
}

FavoriteFriend &FavoriteFriend::fromJson(QJsonObject aFriend) {
    _id     = aFriend["id"].toString();
    _added  = QDateTime::fromString(aFriend["added"].toString(), "yyyy.MM.dd hh:mm:ss");
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
    _icon_gray      = fag._icon_gray;
    return *this;
}

QJsonObject FavoriteAchievement::toJson() {
    QJsonObject obj;
    obj["id"]           = _id;
    obj["title"]        = _title;
    obj["description"]  = _description;
    obj["achieved"]     = _achieved;
    obj["icon"]         = _icon;
    obj["icon_gray"]    = _icon_gray;
    return obj;
}

FavoriteAchievement &FavoriteAchievement::fromJson(QJsonObject fag) {
    _id             = fag["id"].toString();
    _title          = fag["title"].toString();
    _description    = fag["description"].toString();
    _achieved       = fag["achieved"].toInt();
    _icon           = fag["icon"].toString();
    _icon_gray      = fag["icon_gray"].toString();
    return *this;
}

bool FavoriteAchievement::isThisAchievement(const SAchievement &aAchievement) {
    return (_id == aAchievement._apiName) && (_title == aAchievement._displayName) && (_description == aAchievement._description) && (_achieved == aAchievement._achieved) /*&& () && ()*/;
}
#define FavAchievementEnd }

FavoriteAchievementsGame::FavoriteAchievementsGame(const QJsonObject &aObject) {
    fromJson(aObject);
}

FavoriteAchievementsGame &FavoriteAchievementsGame::operator=(const FavoriteAchievementsGame &aAchievement) {
    _appid = aAchievement._appid;
    _name = aAchievement._name;
    _userId = aAchievement._userId;
    _achievements = aAchievement._achievements;
    return *this;
}

bool FavoriteAchievementsGame::addAchievement(const SAchievement &aAchievement, const bool aElseRemove) {
    if (isInAchievements(aAchievement)) {
        if (aElseRemove) {
            removeAchievement(aAchievement);
        }
        return false;
    } else {
        _achievements.append(FavoriteAchievement(aAchievement));
        return true;
    }
}

bool FavoriteAchievementsGame::removeAchievement(const SAchievement &aAchievement, const bool aElseRemove) {
    auto iterator = std::remove_if(_achievements.begin(), _achievements.end(), [=](FavoriteAchievement &achievement) {
                                                            return achievement.isThisAchievement(aAchievement);
                                                        });
    if (iterator == _achievements.end()) {
        if (aElseRemove) {
            addAchievement(aAchievement);
        }
        return false;
    } else {
        _achievements.erase(iterator, _achievements.end());
        return true;
    }
}

bool FavoriteAchievementsGame::isInAchievements(const SAchievement &aAchievement) {
    auto iterator = std::find_if(_achievements.begin(), _achievements.end(), [=](FavoriteAchievement &achievement) {
                                                            return achievement.isThisAchievement(aAchievement);
                                                        });
    if (iterator != _achievements.end()) {
        return true;
    } else {
        return false;
    }
}

QJsonObject FavoriteAchievementsGame::toJson() {
    QJsonObject obj;

    QJsonObject game;
    game["appid"]      = _appid;
    game["name"]    = _name;
    game["userId"]   = _userId;

    QJsonArray values;
    for (auto achievement: _achievements) {
        values.append(achievement.toJson());
    }

    obj["game"]     = game;
    obj["values"]   = values;
    return obj;
}

FavoriteAchievementsGame &FavoriteAchievementsGame::fromJson(QJsonObject achievements) {
    _appid  = achievements.value("game").toObject().value("appid").toInt();
    _name   = achievements.value("game").toObject().value("name").toString();
    _userId = achievements.value("game").toObject().value("userId").toString();

    for (auto achievement: achievements.value("values").toArray()) {
        _achievements.append(FavoriteAchievement(achievement.toObject()));
    }
    return *this;
}

bool FavoriteAchievementsGame::isEqual(const SGame &aGame) const {
    return (_appid == aGame._appID) && (_name == aGame._name);
}
#define FavAchievementsGameEnd }
