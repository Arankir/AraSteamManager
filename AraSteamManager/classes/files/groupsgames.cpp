#include "groupsgames.h"

GroupGames::GroupGames(const QString &aTitle, const ProfileID &aProfileId): title_(aTitle), profileId_(aProfileId) {

}

GroupGames::GroupGames(const QJsonObject &aObject) {
    fromJson(aObject);
}

GroupGames &GroupGames::addGame(const SGame &aGame) {
//    bool isAlreadyInclude = std::any_of(games_.begin(),
//                                        games_.end(),
//                                        [=](const GameID &lGame) {
//                                            return lGame == aGame.appId();
//                                        });
//    if (!isAlreadyInclude) {
//        games_.insert(aGame.appId());
//    }
    games_.insert(aGame.appId());
    return *this;
}

GroupGames &GroupGames::removeGame(const GameID &aGameId) {
//    games_.erase(std::remove_if(games_.begin(),
//                                games_.end(),
//                                [=](const GameID &lGame) {
//                                    return lGame == aGame;
//                                }),
//               games_.end());
    games_.remove(aGameId);
    return *this;
}

GroupGames &GroupGames::changeTitle(const QString &aTitle) {
    title_ = aTitle;
    return *this;
}

QJsonObject GroupGames::toJson() const {
    QJsonObject object;
    object["title"] = title_;
    object["profileId"] = profileId_;
    QJsonArray array;
    for(const auto &game: games_) {
        array.append(game);
    }
    object["games"] = array;
    return object;
}

QString GroupGames::title() const {
    return title_;
}

ProfileID GroupGames::profileId() const {
    return profileId_;
}

QList<GameID> GroupGames::games() const {
    QList<GameID> games;
    for (const auto &game: games_) {
        games << game;
    }
    return games;
}

GroupGames &GroupGames::fromJson(const QJsonObject &aObject) {
    title_      = aObject.value("title").toString();
    profileId_  = aObject.value("profileId").toString();
    for(const auto &game: aObject.value("games").toArray()) {
        games_.insert(game.toInt());
    }
    return *this;
}

GroupsGames::GroupsGames(const ProfileID &aProfileId) : QList<GroupGames>(), FileSaveLoad(Paths::groupGames(aProfileId)), profileId_(aProfileId) {
    init();
}

void GroupsGames::addGroup(const QString &aTitle) {
    append(GroupGames(aTitle, profileId_));
}

void GroupsGames::removeGroup(const QString &aTitle) {
    auto iterator = std::find_if(begin(),
                                 end(),
                                 [=](const GroupGames &lGroup) {
                                    return lGroup.title() == aTitle;
                                 });
    if (iterator != end()) {
        removeAt(iterator - begin());
    }
}

void GroupsGames::init() {
    if (profileId_ != "") {
        load(filePath_);
    }
}

void GroupsGames::update(const ProfileID &aProfileId) {
    profileId_ = aProfileId;
    filePath_ = Paths::groupGames(profileId_);
    init();
}

void GroupsGames::fromJson(const QJsonObject &aObject) {
    profileId_ = aObject.value("profileId").toString();
    clear();
    for(auto &&group: aObject.value("groups").toArray()) {
        append(GroupGames(group.toObject()));
    }
}

QJsonObject GroupsGames::toJson() const {
    QJsonObject object;
    object["profileId"] = profileId_;
    QJsonArray array;
    for(auto &group: *this) {
        array.append(std::move(group.toJson()));
    }
    object["groups"] = array;
    return object;
}
