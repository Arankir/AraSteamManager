#include "groupsgames.h"
#include "classes/common/settings.h"

GroupGames::GroupGames(const QJsonObject &aObject) {
    fromJson(aObject);
}

GroupGames &GroupGames::addGame(const SGame &aGame) {
    _games.append(aGame.sAppId());
    return *this;
}

GroupGames &GroupGames::removeGame(const SGame &aGame) {
    auto iterator = std::find_if(_games.begin(),
                                 _games.end(),
                                 [=](const QString &game){return game == aGame.sAppId();});
    if (iterator != _games.end()) {
        _games.removeOne(*iterator);
    }
    return *this;
}

GroupGames &GroupGames::changeTitle(const QString &aTitle) {
    _title = aTitle;
    return *this;
}

QJsonObject GroupGames::toJson() const {
    QJsonObject object;
    object["title"] = _title;
    object["profileId"] = _profileId;
    QJsonArray array;
    for(const auto &game: _games) {
        array.append(game);
    }
    object["games"] = array;
    return object;
}

GroupGames &GroupGames::fromJson(const QJsonObject &aObject) {
    _title      = aObject.value("title").toString();
    _profileId  = aObject.value("profileId").toString();
    foreach(const auto &game, aObject.value("games").toArray()) {
        _games.append(game.toString());
    }
    return *this;
}

GroupsGames::GroupsGames(const SProfile &aProfile) : _profileId(aProfile.steamID()) {
    init();
}

void GroupsGames::setProfile(const SProfile &aProfile) {
    _profileId = aProfile.steamID();
    init();
}

GroupGames &GroupsGames::operator[](const int &aIndex) {
    return _groups[aIndex];
}

GroupsGames &GroupsGames::addGroup(const QString &aTitle) {
    _groups.append(std::move(GroupGames(aTitle, _profileId)));
    return *this;
}

void GroupsGames::init() {
    if (_profileId != "") {
        QByteArray bytes;
        if(readFile(Paths::groupGames(_profileId), bytes)) {
            fromJson(QJsonDocument::fromJson(bytes).object());
        } else {
            qWarning() << "file" << Paths::groupGames(_profileId) << "coudn't open";
        }
    }
}

void GroupsGames::update() {
    init();
}

GroupsGames &GroupsGames::fromJson(const QJsonObject &aObject) {
    _profileId = aObject.value("profileId").toString();
    _groups.clear();
    for(auto &&group: aObject.value("groups").toArray()) {
        _groups.append(std::move(GroupGames(group.toObject())));
    }
    return *this;
}

QJsonObject GroupsGames::toJson() const {
    QJsonObject object;
    object["profileId"] = _profileId;
    QJsonArray array;
    for(auto &group: _groups) {
        array.append(std::move(group.toJson()));
    }
    object["groups"] = array;
    return object;
}

const GroupsGames &GroupsGames::save() const {
    saveFile(Paths::groupGames(_profileId), QJsonDocument(toJson()).toJson());
    return *this;
}
