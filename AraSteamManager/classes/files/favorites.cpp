#include "favorites.h"
//#include "classes/common/settings.h"

#define FavGame {
FavoriteGame::FavoriteGame(const ProfileID &aProfileId, const QString &aIcon, const GameID &aGameId, const QString &name) : profileId_(aProfileId), icon_(aIcon),
    appId_(aGameId), name_(name) {

}

FavoriteGame::FavoriteGame(const ProfileID &aProfileId, const SGame &aGame) : profileId_(aProfileId), icon_(aGame.imgIconUrl()), appId_(aGame.appId()), name_(aGame.name()) {

}

FavoriteGame::FavoriteGame(const QJsonObject &aObject) {
    fromJson(aObject);
}

FavoriteGame::FavoriteGame(const FavoriteGame &aGame) : profileId_(aGame.profileId_), icon_(aGame.icon_), appId_(aGame.appId_), name_(aGame.name_) {

}

QJsonObject FavoriteGame::toJson() const {
    QJsonObject obj;
    obj["icon"]     = icon_;
    obj["appid"]    = appId_;
    obj["userId"]   = profileId_;
    obj["name"]     = name_;
    return obj;
}

FavoriteGame &FavoriteGame::fromJson(const QJsonObject &aGame) {
    icon_   = aGame["icon"].toString();
    appId_  = aGame["appid"].toInt();
    profileId_ = aGame["userId"].toString();
    name_   = aGame["name"].toString();
    return *this;
}

FavoriteGame &FavoriteGame::setIcon(const QString &aIcon) {
    icon_ = aIcon;
    return *this;
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
#define FavGameEnd }

#define FavFriend {
FavoriteProfile::FavoriteProfile(const ProfileID &aProfileId): id_(aProfileId) {

}

FavoriteProfile::FavoriteProfile(const FavoriteProfile &aProfile): id_(aProfile.id_) {

}

FavoriteProfile::FavoriteProfile(const QJsonObject &aObject) {
    fromJson(aObject);
}

QJsonObject FavoriteProfile::toJson() const {
    QJsonObject obj;
    obj["id"]       = id_;
    return obj;
}

void FavoriteProfile::fromJson(const QJsonObject &aProfile) {
    id_ = aProfile["id"].toString();
}

ProfileID FavoriteProfile::profileId() const {
    return id_;
}
#define FavFriendEnd }

#define FavAchievementGame {
#define FavAchievement {
FavoriteAchievement::FavoriteAchievement(const AchievementID &aAchievementId, const QString &aTitle, const QString &aDescription, const QString &aIcon, const QString &aIconGray, int aAchieved):
    apiName_(aAchievementId), title_(aTitle), description_(aDescription), achieved_(aAchieved), icon_(aIcon), iconGray_(aIconGray) {

}

FavoriteAchievement::FavoriteAchievement(const SAchievement &aAchievement): apiName_(aAchievement.apiName()), title_(aAchievement.displayName()),
    description_(aAchievement.description()), achieved_(aAchievement.achieved()), icon_(aAchievement.iconPath()), iconGray_(aAchievement.iconGrayPath()) {

}

FavoriteAchievement::FavoriteAchievement(const FavoriteAchievement &aAchievement): apiName_(aAchievement.apiName_), title_(aAchievement.title_),
    description_(aAchievement.description_), achieved_(aAchievement.achieved_), icon_(aAchievement.icon_), iconGray_(aAchievement.iconGray_) {

}

FavoriteAchievement::FavoriteAchievement(const QJsonObject &aObject) {
    fromJson(aObject);
}

bool FavoriteAchievement::operator==(const SAchievement &aAchievement) const {
    return (apiName_ == aAchievement.apiName()) &&
            (title_ == aAchievement.displayName()) &&
            (description_ == aAchievement.description()) &&
            (achieved_ == aAchievement.achieved()) /*&& () && ()*/;
}

QJsonObject FavoriteAchievement::toJson() const {
    QJsonObject obj;
    obj["id"]           = apiName_;
    obj["title"]        = title_;
    obj["description"]  = description_;
    obj["achieved"]     = achieved_;
    obj["icon"]         = icon_;
    obj["icon_gray"]    = iconGray_;
    return obj;
}

void FavoriteAchievement::fromJson(const QJsonObject &aAchievement) {
    apiName_        = aAchievement["id"].toString();
    title_          = aAchievement["title"].toString();
    description_    = aAchievement["description"].toString();
    achieved_       = aAchievement["achieved"].toInt();
    icon_           = aAchievement["icon"].toString();
    iconGray_       = aAchievement["icon_gray"].toString();
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
#define FavAchievementEnd }

FavoriteAchievementsGame::FavoriteAchievementsGame(const ProfileID &aProfileId, const SGame &aGame) : userId_(aProfileId), appId_(aGame.appId()), name_(aGame.name()) {

}

FavoriteAchievementsGame::FavoriteAchievementsGame(const FavoriteAchievementsGame &aAchievementsGame) : QList<FavoriteAchievement>(aAchievementsGame), userId_(aAchievementsGame.userId_),
    appId_(aAchievementsGame.appId_), name_(aAchievementsGame.name_) {

}

FavoriteAchievementsGame::FavoriteAchievementsGame(const QJsonObject &aObject) {
    fromJson(aObject);
}

FavoriteAchievementsGame &FavoriteAchievementsGame::operator=(const FavoriteAchievementsGame &aAchievementsGame) {
    appId_          = aAchievementsGame.appId_;
    name_           = aAchievementsGame.name_;
    userId_         = aAchievementsGame.userId_;
    QList<FavoriteAchievement>::operator=(aAchievementsGame);
    return *this;
}

bool FavoriteAchievementsGame::operator==(const SGame &aGame) const {
    return (appId_ == aGame.appId());// && (_name == aGame.name());
}

void FavoriteAchievementsGame::remove(const AchievementID &aAchievement) {
    auto iterator = std::remove_if(begin(),
                                   end(),
                                   [=](const FavoriteAchievement &lAchievement) {
                                        return lAchievement.apiName() == aAchievement;
                                   });
    if (iterator != end()) {
        erase(iterator, end());
    }
}

bool FavoriteAchievementsGame::isInAchievements(const AchievementID &aAchievement) const {
    return std::any_of(cbegin(),
                       cend(),
                       [=](const FavoriteAchievement &achievement) {
                           return achievement.apiName() == aAchievement;
                       });
}

QJsonObject FavoriteAchievementsGame::toJson() const {
    QJsonObject obj;

    QJsonObject game;
    game["appid"]      = appId_;
    game["name"]    = name_;
    game["userId"]   = userId_;

    QJsonArray values;
    for (const auto &achievement: *this) {
        values.append(achievement.toJson());
    }

    obj["game"]     = game;
    obj["values"]   = values;
    return obj;
}

void FavoriteAchievementsGame::fromJson(const QJsonObject &aAchievements) {
    appId_  = aAchievements.value("game").toObject().value("appid").toInt();
    name_   = aAchievements.value("game").toObject().value("name").toString();
    userId_ = aAchievements.value("game").toObject().value("userId").toString();

    clear();
    for (auto &&achievement: aAchievements.value("values").toArray()) {
        append(FavoriteAchievement(achievement.toObject()));
    }
}
#define FavAchievementsGameEnd }

FavoriteGames::FavoriteGames(): FileSaveLoad(Paths::favorites("games")) {
    load(filePath_);
}

void FavoriteGames::append(const FavoriteGame &aGame) {
    QList<FavoriteGame>::append(aGame);
    save();
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
    object["type"] = "games";
    object["version"] = "1.0";

    QJsonArray values;
    for(const auto &game: *this) {
        values.append(game.toJson());
    }
    object["values"] = values;
    return object;
}

void FavoriteGames::update() {
    FileSaveLoad::load(filePath_);
}

void FavoriteGames::fromJson(const QJsonObject &aObject) {
    if (aObject.value("type").toString() == "games") {
        clear();
        for (auto &&value: aObject.value("values").toArray()) {
            append(FavoriteGame(value.toObject()));
        }
    } else {
        qWarning() << "favorites games file is corrupted";
    }
}

FavoriteProfiles::FavoriteProfiles(): FileSaveLoad(Paths::favorites("friends")) {
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
    object["type"] = "friends";
    object["version"] = "1.0";

    QJsonArray values;
    for(const auto &steamFriend: *this) {
        values.append(steamFriend.toJson());
    }
    object["values"] = values;
    return object;
}

void FavoriteProfiles::update() {
    FileSaveLoad::load(filePath_);
}

void FavoriteProfiles::fromJson(const QJsonObject &aObject) {
    if (aObject.value("type").toString() == "friends") {
        clear();
        for (auto &&value: aObject.value("values").toArray()) {
            append(FavoriteProfile(value.toObject()));
        }
    } else {
        qWarning() << "favorites friends file is corrupted";
    }
}

FavoriteAchievementsGames::FavoriteAchievementsGames(): FileSaveLoad(Paths::favorites("achievements")) {
    load(filePath_);
}

void FavoriteAchievementsGames::append(const FavoriteAchievementsGame &aFavoriteAchiementsGame) {
    QList<FavoriteAchievementsGame>::append(aFavoriteAchiementsGame);
    save();
}

void FavoriteAchievementsGames::append(const ProfileID &aProfileId, const SGame &aGame, const SAchievement &aAchievement) {
    auto iterator = std::find_if(begin(),
                                 end(),
                                 [=](const FavoriteAchievementsGame &lFavoriteAchievementsGame) {
                                    return lFavoriteAchievementsGame == aGame && lFavoriteAchievementsGame.steamId() == aProfileId;
                                 });
    if (iterator != end()) {
        (*iterator).append(aAchievement);
    } else {
        FavoriteAchievementsGame achievementGame(aProfileId, aGame);
        achievementGame.append(aAchievement);
        append(achievementGame);
    }
    save();
}

void FavoriteAchievementsGames::remove(const ProfileID &aProfileId, const GameID &aGame) {
    auto iterator = std::remove_if(begin(),
                                   end(),
                                   [=](const FavoriteAchievementsGame &lFavoriteAchievementsGame) {
                                      return lFavoriteAchievementsGame.appId() == aGame && lFavoriteAchievementsGame.steamId() == aProfileId;
                                   });
    if (iterator != end()) {
        erase(iterator, end());
        save();
    }
}

void FavoriteAchievementsGames::remove(const ProfileID &aProfileId, const GameID &aGame, const AchievementID &aAchievement) {
    auto iterator = std::find_if(begin(),
                                 end(),
                                 [=](const FavoriteAchievementsGame &lFavoriteAchievementsGame) {
                                    return lFavoriteAchievementsGame.appId() == aGame && lFavoriteAchievementsGame.steamId() == aProfileId;
                                 });
    if (iterator != end()) {
        iterator->remove(aAchievement);
        if (iterator->count() <= 0) {
            erase(iterator);
        }
    }
    save();
}

bool FavoriteAchievementsGames::isInFavorite(const GameID &aGameId, const ProfileID &aProfileId, const AchievementID &aAchievementId) {
    auto iteratorGame = std::find_if(begin(),
                                     end(),
                                     [=](const FavoriteAchievementsGame &lGame) {
                                        return lGame.appId() == aGameId && lGame.steamId() == aProfileId;
                                     });
    if (iteratorGame != end()) {
        return (*iteratorGame).isInAchievements(aAchievementId);
    }
    return false;
}

QJsonObject FavoriteAchievementsGames::toJson() const {
    QJsonObject object;
    object["type"] = "achievements";
    object["version"] = "1.0";

    QJsonArray values;
    for(const auto &achievement: *this) {
        values.append(achievement.toJson());
    }
    object["values"] = values;
    return object;
}

void FavoriteAchievementsGames::update() {
    load(filePath_);
}

void FavoriteAchievementsGames::fromJson(const QJsonObject &aObject) {
    if (aObject.value("type").toString() == "achievements") {
        clear();
        for (const auto &value: aObject.value("values").toArray()) {
            append(FavoriteAchievementsGame(value.toObject()));
        }
    } else {
        qWarning() << "favorites achievements file is corrupted";
    }
}
