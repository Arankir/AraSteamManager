#include "favorites.h"
#include "classes/common/images.h"
//#include "classes/common/settings.h"

#define FavGame {
FavoriteGame::FavoriteGame(const ProfileID &aProfileId, const QString &aIcon, const GameID &aGameId, const QString &name):
Favorite(game), profileId_(aProfileId), icon_(aIcon), appId_(aGameId), name_(name) {

}

FavoriteGame::FavoriteGame(const ProfileID &aProfileId, const SGame &aGame):
Favorite(game), profileId_(aProfileId), icon_(aGame.imgIconUrl()), appId_(aGame.appId()), name_(aGame.name()) {

}

FavoriteGame::FavoriteGame(const QJsonObject &aObject):
Favorite(game) {
    fromJson(aObject);
}

FavoriteGame::FavoriteGame(const FavoriteGame &aGame):
Favorite(game), profileId_(aGame.profileId_), icon_(aGame.icon_), appId_(aGame.appId_), name_(aGame.name_) {

}

QJsonObject FavoriteGame::toJson() const {
    QJsonObject obj = Favorite::toJson();
    obj["icon"]     = icon_;
    obj["appid"]    = appId_;
    obj["userId"]   = profileId_;
    obj["name"]     = name_;
    return obj;
}

void FavoriteGame::fromJson(const QJsonObject &aGame) {
    icon_   = aGame["icon"].toString();
    appId_  = aGame["appid"].toInt();
    profileId_ = aGame["userId"].toString();
    name_   = aGame["name"].toString();
    Favorite::fromJson(aGame);
}

ProfileID FavoriteGame::steamId() const {
    return profileId_;
}

GameID FavoriteGame::appId() const {
    return appId_;
}

QString FavoriteGame::name() const {
    return name_;
}

QString FavoriteGame::icon() const {
    return icon_;
}

QPixmap FavoriteGame::iconPixmap() const {
    if (icon_.isEmpty()) {
        gameIconPixmap_ = QPixmap(Images::missingImage()).scaled(QSize(32, 32)).toImage();
    }
    return QPixmap::fromImage(loadImage(gameIconPixmap_, Sapi::gameImageUrl(appId_, icon_), Paths::imagesGames(icon_), QSize(32, 32)));
}
#define FavGameEnd }

#define FavFriend {
FavoriteProfile::FavoriteProfile(const ProfileID &aProfileId):
Favorite(profile), id_(aProfileId) {

}

FavoriteProfile::FavoriteProfile(const FavoriteProfile &aProfile):
Favorite(profile), id_(aProfile.id_) {

}

FavoriteProfile::FavoriteProfile(const QJsonObject &aObject):
Favorite(profile) {
    fromJson(aObject);
}

QJsonObject FavoriteProfile::toJson() const {
    QJsonObject obj = Favorite::toJson();
    obj["id"]       = id_;
    return obj;
}

void FavoriteProfile::fromJson(const QJsonObject &aProfile) {
    id_ = aProfile["id"].toString();
    Favorite::fromJson(aProfile);
}

ProfileID FavoriteProfile::profileId() const {
    return id_;
}
#define FavFriendEnd }

#define FavAchievementGame {
#define FavAchievement {
FavoriteAchievement::FavoriteAchievement(const AchievementID &aAchievementId, const QString &aTitle, const QString &aDescription,
                                         const QString &aIcon, const QString &aIconGray, int aAchieved, const GameID &aAppId,
                                         const QString &aGameName, const QString &aGameIcon, const ProfileID &aProfileId):
    Favorite(achievement), apiName_(aAchievementId), title_(aTitle), description_(aDescription), achieved_(aAchieved), icon_(aIcon), iconGray_(aIconGray), profileId_(aProfileId) {
    game_.appId = aAppId;
    game_.name = aGameName;
    game_.icon = aGameIcon;
}

FavoriteAchievement::FavoriteAchievement(const SAchievement &aAchievement, const SGame &aGame, const ProfileID &aProfileId): Favorite(achievement), apiName_(aAchievement.apiName()), title_(aAchievement.displayName()),
    description_(aAchievement.description()), achieved_(aAchievement.achieved()), icon_(aAchievement.iconPath()), iconGray_(aAchievement.iconGrayPath()),
    game_(aGame), profileId_(aProfileId) {

}

FavoriteAchievement::FavoriteAchievement(const FavoriteAchievement &aAchievement): Favorite(achievement), apiName_(aAchievement.apiName_), title_(aAchievement.title_),
    description_(aAchievement.description_), achieved_(aAchievement.achieved_), icon_(aAchievement.icon_), iconGray_(aAchievement.iconGray_), game_(aAchievement.game_),
    profileId_(aAchievement.profileId_) {

}

FavoriteAchievement::FavoriteAchievement(const QJsonObject &aObject): Favorite(achievement) {
    fromJson(aObject);
}

bool FavoriteAchievement::operator==(const SAchievement &aAchievement) const {
    return (apiName_ == aAchievement.apiName()) &&
            (title_ == aAchievement.displayName()) &&
            (description_ == aAchievement.description()) &&
            (achieved_ == aAchievement.achieved())/* && ()*/;
}

QJsonObject FavoriteAchievement::toJson() const {
    QJsonObject obj = Favorite::toJson();

    QJsonObject objAchievement;
    objAchievement["id"]           = apiName_;
    objAchievement["title"]        = title_;
    objAchievement["description"]  = description_;
    objAchievement["achieved"]     = achieved_;
    objAchievement["icon"]         = icon_;
    objAchievement["icon_gray"]    = iconGray_;

    obj["game"] = game_.toJson();
    obj["achievement"] = objAchievement;
    obj["profile"] = profileId_;
    return obj;
}

void FavoriteAchievement::fromJson(const QJsonObject &aObject) {
    QJsonObject achievement = aObject["achievement"].toObject();

    apiName_        = achievement["id"].toString();
    title_          = achievement["title"].toString();
    description_    = achievement["description"].toString();
    achieved_       = achievement["achieved"].toInt();
    icon_           = achievement["icon"].toString();
    iconGray_       = achievement["icon_gray"].toString();

    game_.fromJson(aObject["game"].toObject());

    profileId_ = aObject["profile"].toString();
}

AchievementID FavoriteAchievement::apiName() const {
    return apiName_;
}

QString FavoriteAchievement::title() const {
    return title_;
}

QString FavoriteAchievement::description() const {
    return description_;
}

int FavoriteAchievement::achieved() const {
    return achieved_;
}

QString FavoriteAchievement::icon() const {
    return icon_;
}

QString FavoriteAchievement::iconGray() const {
    return iconGray_;
}

FavoriteAchievement::Game FavoriteAchievement::game() const {
    return game_;
}
#define FavAchievementEnd }

//FavoriteAchievementsGame::FavoriteAchievementsGame(const ProfileID &aProfileId, const SGame &aGame) : userId_(aProfileId), appId_(aGame.appId()), name_(aGame.name()) {

//}

//FavoriteAchievementsGame::FavoriteAchievementsGame(const FavoriteAchievementsGame &aAchievementsGame) : QList<FavoriteAchievement>(aAchievementsGame), userId_(aAchievementsGame.userId_),
//    appId_(aAchievementsGame.appId_), name_(aAchievementsGame.name_) {

//}

//FavoriteAchievementsGame::FavoriteAchievementsGame(const QJsonObject &aObject) {
//    fromJson(aObject);
//}

//FavoriteAchievementsGame &FavoriteAchievementsGame::operator=(const FavoriteAchievementsGame &aAchievementsGame) {
//    appId_          = aAchievementsGame.appId_;
//    name_           = aAchievementsGame.name_;
//    userId_         = aAchievementsGame.userId_;
//    QList<FavoriteAchievement>::operator=(aAchievementsGame);
//    return *this;
//}

//bool FavoriteAchievementsGame::operator==(const SGame &aGame) const {
//    return (appId_ == aGame.appId());// && (_name == aGame.name());
//}

//void FavoriteAchievementsGame::remove(const AchievementID &aAchievement) {
//    auto iterator = std::remove_if(begin(),
//                                   end(),
//                                   [=](const FavoriteAchievement &lAchievement) {
//                                        return lAchievement.apiName() == aAchievement;
//                                   });
//    if (iterator != end()) {
//        erase(iterator, end());
//    }
//}

//bool FavoriteAchievementsGame::isInAchievements(const AchievementID &aAchievement) const {
//    return std::any_of(cbegin(),
//                       cend(),
//                       [=](const FavoriteAchievement &achievement) {
//                           return achievement.apiName() == aAchievement;
//                       });
//}

//QJsonObject FavoriteAchievementsGame::toJson() const {
//    QJsonObject obj;

//    QJsonObject game;
//    game["appid"]      = appId_;
//    game["name"]    = name_;
//    game["userId"]   = userId_;

//    QJsonArray values;
//    for (const FavoriteAchievement &achievement: *this) {
//        values.append(achievement.toJson());
//    }

//    obj["game"]     = game;
//    obj["values"]   = values;
//    return obj;
//}

//void FavoriteAchievementsGame::fromJson(const QJsonObject &aAchievements) {
//    appId_  = aAchievements.value("game").toObject().value("appid").toInt();
//    name_   = aAchievements.value("game").toObject().value("name").toString();
//    userId_ = aAchievements.value("game").toObject().value("userId").toString();

//    clear();
//    for (QJsonValue &&achievement: aAchievements.value("values").toArray()) {
//        append(FavoriteAchievement(achievement.toObject()));
//    }
//}
#define FavAchievementsGameEnd }

FavoriteGames::FavoriteGames(): FileSaveLoad(Paths::favorites("games")) {
    load(filePath_);
}

void FavoriteGames::append(const FavoriteGame &aGame) {
    QList<FavoriteGame>::append(aGame);
    save();
}

void FavoriteGames::remove(const ProfileID &aProfileId) {
    auto iterator = std::remove_if(begin(),
                                   end(),
                                   [=](const FavoriteGame &game) {
                                        return (aProfileId == game.steamId());
                                   });
    if (iterator != end()) {
        erase(iterator, end());
        save();
    }
}

void FavoriteGames::remove(const ProfileID &aProfileId, const GameID &aGame) {
    auto iterator = std::remove_if(begin(),
                                   end(),
                                   [=](const FavoriteGame &game) {
                                        return (aProfileId == game.steamId())
                                                && (aGame == game.appId());
                                   });
    if (iterator != end()) {
        erase(iterator, end());
        save();
    }
}

QJsonObject FavoriteGames::toJson() const {
    QJsonObject object;
    object["type"] = "favorite games";
    object["version"] = "1.0";

    QJsonArray values;
    for(const FavoriteGame &game: *this) {
        values.append(game.toJson());
    }
    object["values"] = values;
    return object;
}

void FavoriteGames::update() {
    FileSaveLoad::load(filePath_);
}

void FavoriteGames::fromJson(const QJsonObject &aObject) {
    if (aObject.value("type").toString() == "favorite games") {
        clear();
        for (QJsonValue &&value: aObject.value("values").toArray()) {
            append(FavoriteGame(value.toObject()));
        }
    } else {
        qWarning() << "favorites games file is corrupted";
    }
}

FavoriteProfiles::FavoriteProfiles(): FileSaveLoad(Paths::favorites("profiles")) {
    load(filePath_);
}

void FavoriteProfiles::append(const FavoriteProfile &aFriend) {
    QList<FavoriteProfile>::append(aFriend);
    save();
}

void FavoriteProfiles::remove(const ProfileID &aProfileId) {
    auto iterator = std::remove_if(begin(),
                                   end(),
                                   [=](const FavoriteProfile &lProfile) {
                                        return (aProfileId == lProfile.profileId());
                                   });
    if (iterator != end()) {
        erase(iterator, end());
        save();
    }
}

QJsonObject FavoriteProfiles::toJson() const {
    QJsonObject object;
    object["type"] = "favorite profiles";
    object["version"] = "1.0";

    QJsonArray values;
    for(const FavoriteProfile &steamFriend: *this) {
        values.append(steamFriend.toJson());
    }
    object["values"] = values;
    return object;
}

void FavoriteProfiles::update() {
    FileSaveLoad::load(filePath_);
}

void FavoriteProfiles::fromJson(const QJsonObject &aObject) {
    if (aObject.value("type").toString() == "favorite profiles") {
        clear();
        for (QJsonValue &&value: aObject.value("values").toArray()) {
            append(FavoriteProfile(value.toObject()));
        }
    } else {
        qWarning() << "favorites friends file is corrupted";
    }
}

//FavoriteAchievementsGames::FavoriteAchievementsGames(): FileSaveLoad(Paths::favorites("achievements")) {
//    load(filePath_);
//}

//void FavoriteAchievementsGames::append(const FavoriteAchievementsGame &aFavoriteAchiementsGame) {
//    QList<FavoriteAchievementsGame>::append(aFavoriteAchiementsGame);
//    save();
//}

//void FavoriteAchievementsGames::append(const ProfileID &aProfileId, const SGame &aGame, const SAchievement &aAchievement) {
//    auto iterator = std::find_if(begin(),
//                                 end(),
//                                 [=](const FavoriteAchievementsGame &lFavoriteAchievementsGame) {
//                                    return lFavoriteAchievementsGame == aGame && lFavoriteAchievementsGame.steamId() == aProfileId;
//                                 });
//    if (iterator != end()) {
//        (*iterator).append(aAchievement);
//    } else {
//        FavoriteAchievementsGame achievementGame(aProfileId, aGame);
//        achievementGame.append(aAchievement);
//        append(achievementGame);
//    }
//    save();
//}

//void FavoriteAchievementsGames::remove(const ProfileID &aProfileId, const GameID &aGame) {
//    auto iterator = std::remove_if(begin(),
//                                   end(),
//                                   [=](const FavoriteAchievementsGame &lFavoriteAchievementsGame) {
//                                      return lFavoriteAchievementsGame.appId() == aGame && lFavoriteAchievementsGame.steamId() == aProfileId;
//                                   });
//    if (iterator != end()) {
//        erase(iterator, end());
//        save();
//    }
//}

//void FavoriteAchievementsGames::remove(const ProfileID &aProfileId, const GameID &aGame, const AchievementID &aAchievement) {
//    auto iterator = std::find_if(begin(),
//                                 end(),
//                                 [=](const FavoriteAchievementsGame &lFavoriteAchievementsGame) {
//                                    return lFavoriteAchievementsGame.appId() == aGame && lFavoriteAchievementsGame.steamId() == aProfileId;
//                                 });
//    if (iterator != end()) {
//        iterator->remove(aAchievement);
//        if (iterator->count() <= 0) {
//            erase(iterator);
//        }
//    }
//    save();
//}

//bool FavoriteAchievementsGames::isInFavorite(const GameID &aGameId, const ProfileID &aProfileId, const AchievementID &aAchievementId) {
//    auto iteratorGame = std::find_if(begin(),
//                                     end(),
//                                     [=](const FavoriteAchievementsGame &lGame) {
//                                        return lGame.appId() == aGameId && lGame.steamId() == aProfileId;
//                                     });
//    if (iteratorGame != end()) {
//        return (*iteratorGame).isInAchievements(aAchievementId);
//    }
//    return false;
//}

//QJsonObject FavoriteAchievementsGames::toJson() const {
//    QJsonObject object;
//    object["type"] = "favorite achievements";
//    object["version"] = "1.0";

//    QJsonArray values;
//    for(const FavoriteAchievementsGame &achievement: *this) {
//        values.append(achievement.toJson());
//    }
//    object["values"] = values;
//    return object;
//}

//void FavoriteAchievementsGames::update() {
//    load(filePath_);
//}

//void FavoriteAchievementsGames::fromJson(const QJsonObject &aObject) {
//    if (aObject.value("type").toString() == "favorite achievements") {
//        clear();
//        for (const QJsonValue &value: aObject.value("values").toArray()) {
//            append(FavoriteAchievementsGame(value.toObject()));
//        }
//    } else {
//        qWarning() << "favorites achievements file is corrupted";
//    }
//}

Favorite::Favorite(FavoriteType initType): type_(initType) {

}

QJsonObject Favorite::toJson() const {
    QJsonObject obj;
    obj["type"]     = static_cast<int>(type_);
    return obj;
}

void Favorite::fromJson(const QJsonObject &aObject) {
    type_ = static_cast<FavoriteType>(aObject["type"].toInt());
}

Favorite::FavoriteType Favorite::type() {
    return type_;
}

FavoriteAchievement::Game::Game() {

}

FavoriteAchievement::Game::Game(const SGame &aGame): appId(aGame.appId()), name(aGame.name()), icon(aGame.imgIconUrl()) {

}

QPixmap FavoriteAchievement::Game::iconPixmap() {
    if (icon.isEmpty()) {
        gameIconPixmap_ = QPixmap(Images::missingImage()).scaled(QSize(32, 32)).toImage();
    }
    return QPixmap::fromImage(loadImage(gameIconPixmap_, Sapi::gameImageUrl(appId, icon), Paths::imagesGames(icon), QSize(32, 32)));
}

QJsonObject FavoriteAchievement::Game::toJson() const {
    QJsonObject objGame;
    objGame["appid"] = appId;
    objGame["name"] = name;
    objGame["icon"] = icon;
    return objGame;
}

void FavoriteAchievement::Game::fromJson(const QJsonObject &aObject) {
    appId = aObject.value("appid").toInt();
    name = aObject.value("name").toString();
    icon = aObject.value("icon").toString();
}

bool FavoriteAchievement::Game::operator<(const Game &aGame) const {
    return name < aGame.name;
}

bool FavoriteAchievement::Game::operator==(const Game &aGame) const {
    return appId == aGame.appId && name == aGame.name && icon == aGame.icon;
}

FavoriteAchievements::FavoriteAchievements(): FileSaveLoad(Paths::favorites("achievements")) {
    load(filePath_);
}

void FavoriteAchievements::append(const FavoriteAchievements &aFavorites) {
    fromJson(aFavorites.toJson());
}

void FavoriteAchievements::append(const FavoriteAchievement &aFavorite, const ProfileID &aProfileId) {
    if (favorites_.find(aProfileId) == favorites_.end()) {
        favorites_.insert(aProfileId, QMap<FavoriteAchievement::Game, QList<FavoriteAchievement> >());
    }
    auto iteratorProfile = favorites_.find(aProfileId);
    FavoriteAchievement::Game game = aFavorite.game();
    if (iteratorProfile->find(game) == iteratorProfile->end()) {
        iteratorProfile->insert(game, QList<FavoriteAchievement>());
    }
    auto iteratorGame = iteratorProfile->find(game);
    iteratorGame.value().append(aFavorite);
}

void FavoriteAchievements::append(const ProfileID &aProfileId, const SGame &aGame, const SAchievement &aAchievement) {
    if (favorites_.find(aProfileId) == favorites_.end()) {
        favorites_.insert(aProfileId, QMap<FavoriteAchievement::Game, QList<FavoriteAchievement> >());
    }
    auto iteratorProfile = favorites_.find(aProfileId);
    FavoriteAchievement::Game game(aGame);
    if (iteratorProfile->find(game) == iteratorProfile->end()) {
        iteratorProfile->insert(game, QList<FavoriteAchievement>());
    }
    auto iteratorGame = iteratorProfile->find(game);
    iteratorGame.value().append(FavoriteAchievement(aAchievement, aGame, aProfileId));
}

void FavoriteAchievements::remove(const ProfileID &aProfileId, const GameID &aGame) {
    if (favorites_.find(aProfileId) == favorites_.end()) {
        favorites_.insert(aProfileId, QMap<FavoriteAchievement::Game, QList<FavoriteAchievement> >());
    }
    auto iteratorProfile = favorites_.find(aProfileId);
    for (auto it = iteratorProfile->begin(); it != iteratorProfile->end(); ++it) {
        if (it.key().appId == aGame) {
            iteratorProfile->erase(it);
            break;
        }
    }
}

void FavoriteAchievements::remove(const ProfileID &aProfileId, const GameID &aGame, const AchievementID &aAchievement) {
    if (favorites_.find(aProfileId) == favorites_.end()) {
        favorites_.insert(aProfileId, QMap<FavoriteAchievement::Game, QList<FavoriteAchievement> >());
    }
    auto iteratorProfile = favorites_.find(aProfileId);
    for (auto it = iteratorProfile->begin(); it != iteratorProfile->end(); ++it) {
        if (it.key().appId == aGame) {
            it.value().erase(
                        std::remove_if(it.value().begin(),
                                       it.value().end(),
                                       [=](const FavoriteAchievement &lFavorite) {
                                            return lFavorite.apiName() == aAchievement;
                                        }),
                        it.value().end());
            break;
        }
    }
}

bool FavoriteAchievements::isInFavorite(const GameID &aGameId, const ProfileID &aProfileId, const AchievementID &aAchievementId) {
    auto iteratorProfile = favorites_.find(aProfileId);
    if (iteratorProfile != favorites_.end()) {
        for (auto it = iteratorProfile->begin(); it != iteratorProfile->end(); ++it) {
            if (it.key().appId == aGameId) {
                return std::any_of(it.value().begin(),
                                    it.value().end(),
                                    [=](const FavoriteAchievement &lFavorite) {
                                        return lFavorite.apiName() == aAchievementId;
                                    });
            }
        }
    }
    return false;
}

QList<ProfileID> FavoriteAchievements::profiles() const {
    QList<ProfileID> list;
    for (auto it = favorites_.begin(); it != favorites_.end(); ++it) {
        list << it.key();
    }
    return list;
}

QList<FavoriteAchievement::Game> FavoriteAchievements::games(const ProfileID &aProfile) const {
    QList<FavoriteAchievement::Game> list;
    if (favorites_.find(aProfile) != favorites_.end()) {
        auto games = favorites_.find(aProfile);
        for (auto it = games->begin(); it != games->end(); ++it) {
            list << it.key();
        }
    }
    return list;
}

QList<FavoriteAchievement> FavoriteAchievements::achievements(const ProfileID &aProfile, const FavoriteAchievement::Game &aGame) const {
    if (favorites_.find(aProfile) != favorites_.end()) {
        auto games = favorites_.find(aProfile);
        if (games->find(aGame) != games->end()) {
            return *(games->find(aGame));
        }
    }
    return QList<FavoriteAchievement>();
}

QJsonObject FavoriteAchievements::toJson() const {
    QJsonObject object;
    object["type"] = "favorite achievements";
    object["version"] = "1.0";
    QJsonArray array;
    for (auto profile: favorites_) {
        for (auto game: profile) {
            for (auto achievement: game) {
                array << achievement.toJson();
            }
        }
    }
    object["values"] = array;
    return object;
}

void FavoriteAchievements::update() {
    favorites_.clear();
    load(filePath_);
}

void FavoriteAchievements::fromJson(const QJsonObject &aObject) {
    QString version = aObject.value("version").toString();
    for (auto jFavorite: aObject.value("values").toArray()) {
        ProfileID profile = jFavorite.toObject().value("profile").toString();
        if (favorites_.find(profile) == favorites_.end()) {
            favorites_.insert(profile, QMap<FavoriteAchievement::Game, QList<FavoriteAchievement> >());
        }
        auto iteratorProfile = favorites_.find(profile);
        FavoriteAchievement::Game game;
        game.fromJson(jFavorite.toObject().value("game").toObject());
        if (iteratorProfile->find(game) == iteratorProfile->end()) {
            iteratorProfile->insert(game, QList<FavoriteAchievement>());
        }
        auto iteratorGame = iteratorProfile->find(game);
        iteratorGame.value().append(FavoriteAchievement(jFavorite.toObject()));
    }
}
