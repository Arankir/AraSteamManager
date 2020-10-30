#include "groupsgames.h"

GroupGames::GroupGames(const QJsonObject &aObject) {
    fromJson(aObject);
}

GroupGames &GroupGames::addGame(const SGame &aGame) {
    _games.append(QString::number(aGame._appID));
    return *this;
}

GroupGames &GroupGames::removeGame(const SGame &aGame) {
    for(int i = 0; i < _games.count(); ++i) {
        if (_games[i] == QString::number(aGame._appID)) {
            _games.removeAt(i);
            break;
        }
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
    _title = aObject.value("title").toString();
    _profileId = aObject.value("profileId").toString();
    for(const auto &game: aObject.value("games").toArray()) {
        _games.append(game.toString());
    }
    return *this;
}

GroupsGames::GroupsGames(const SProfile &profile) : _profileId(profile._steamID) {
    init();
}

GroupGames &GroupsGames::operator[](const int index) {
    return _groups[index];
}

GroupsGames &GroupsGames::addGroup(const QString &title) {
    _groups.append(GroupGames(title, _profileId));
    return *this;
}

void GroupsGames::init() {
    QFile fileGroups(Paths::groupGames(_profileId));
    if(fileGroups.open(QIODevice::ReadOnly)) {
        QJsonObject obj = QJsonDocument::fromJson(fileGroups.readAll()).object();
        fromJson(obj);
        fileGroups.close();
    } else {
        qWarning() << "file" << fileGroups.fileName() << "coudn't open";
    }
}

void GroupsGames::update() {
    init();
}

GroupsGames &GroupsGames::fromJson(const QJsonObject &object) {
    _profileId = object.value("profileId").toString();
    _groups.clear();
    for(auto group: object.value("groups").toArray()) {
        _groups.append(GroupGames(group.toObject()));
    }
    return *this;
}

QJsonObject GroupsGames::toJson() const {
    QJsonObject object;
    object["profileId"] = _profileId;
    QJsonArray array;
    for(auto &group: _groups) {
        array.append(group.toJson());
    }
    object["groups"] = array;
    return object;
}

const GroupsGames &GroupsGames::save() const {
    Settings::createDir(Paths::groupGames(_profileId));
    QFile file(Paths::groupGames(_profileId));
    file.open(QFile::WriteOnly);
    file.write(QJsonDocument(toJson()).toJson());
    file.close();
    return *this;
}
