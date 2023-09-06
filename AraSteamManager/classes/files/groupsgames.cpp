#include "groupsgames.h"

GroupGames::GroupGames(const QString &aTitle, const ProfileID &aProfileId): title_(aTitle), profileId_(aProfileId) {

}

GroupGames::GroupGames(const QJsonObject &aObject) {
    fromJson(aObject);
}

GroupGames &GroupGames::addGame(const SGame &aGame) {
    insert(aGame.appId());
    return *this;
}

GroupGames &GroupGames::removeGame(const GameID &aGameId) {
    remove(aGameId);
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
    for(const GameID &game: *this) {
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

GroupGames &GroupGames::fromJson(const QJsonObject &aObject) {
    title_      = aObject.value("title").toString();
    profileId_  = aObject.value("profileId").toString();
    for(const QJsonValue &game: aObject.value("games").toArray()) {
        insert(game.toInt());
    }
    return *this;
}

GroupsGames::GroupsGames(const ProfileID &aProfileId) : QMap<QString, GroupGames>(), FileSaveLoad(Paths::groupGames(aProfileId)), profileId_(aProfileId) {
    init();
}

void GroupsGames::addGroup(const QString &aTitle) {
    insert(aTitle, GroupGames(aTitle, profileId_));
    //    append(GroupGames(aTitle, profileId_));
}

void GroupsGames::addGroup(const GroupGames &aGroup) {
    insert(aGroup.title(), aGroup);
}

void GroupsGames::removeGroup(const QString &aTitle) {
    auto it = find(aTitle);
    if (it != end()) {
        erase(it);
    }
//    auto iterator = std::find_if(begin(),
//                                 end(),
//                                 [=](const GroupGames &lGroup) {
//                                    return lGroup.title() == aTitle;
//                                 });
//    if (iterator != end()) {
//        removeAt(iterator - begin());
//    }
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
    for(QJsonValue &&group: aObject.value("groups").toArray()) {
        insert(group.toObject().value("title").toString(), GroupGames(group.toObject()));
    }
}

QJsonObject GroupsGames::toJson() const {
    QJsonObject object;
    object["profileId"] = profileId_;
    QJsonArray array;
    for(const GroupGames &group: *this) {
        array.append(std::move(group.toJson()));
    }
    object["groups"] = array;
    return object;
}
