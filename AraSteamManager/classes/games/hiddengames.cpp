#include "hiddengames.h"

HiddenGames::HiddenGames(SProfile profile) : _profile(profile.steamID()) {
    load();
}

HiddenGames &HiddenGames::addGame(const SGame &aGame, bool aRemoveIfExist) {
    auto iterator = std::find_if(_games.begin(), _games.end(), [=](gameData game) {
                                                                    return game.id == aGame.sAppId();
                                                                });
    if (iterator != _games.end()) {
        if (aRemoveIfExist) {
            removeGame(aGame);
        }
    } else {
        _games.append(gameData{aGame.sAppId(), aGame.name(), aGame.imgIconUrl()});
    }
    save();
    return *this;
}

HiddenGames &HiddenGames::removeGame(const SGame &aGame, bool aAddIfExist) {
    auto iterator = std::remove_if(_games.begin(), _games.end(), [=](gameData game) {
                                                                    return game.id == aGame.sAppId();
                                                                });
    if (iterator != _games.end()) {
        _games.erase(iterator, _games.end());
    } else {
        if (aAddIfExist) {
            addGame(aGame);
        }
    }
    save();
    return *this;
}

HiddenGames &HiddenGames::save() {
    createDir(Paths::hiddenGames(_profile));
    QFile file(Paths::hiddenGames(_profile));
    file.open(QFile::WriteOnly);
    file.write(QJsonDocument(toJson()).toJson());
    file.close();
    return *this;
}

void HiddenGames::load() {
    _games.clear();

    QFile file(Paths::hiddenGames(_profile == "" ? "All" : _profile));
    if (file.open(QFile::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject games = doc.object();
        for(const auto &game: games.value("games").toArray()) {
            _games.append(gameData{game.toObject().value("id").toString(), game.toObject().value("name").toString(), game.toObject().value("icon").toString()});
        }
        _profile = games.value("profile").toString();
        file.close();
    }
}

QJsonObject HiddenGames::toJson() {
    QJsonObject object;
    object["profile"] = _profile;
    QJsonArray games;
    for(const auto &game: _games) {
        QJsonObject jGame;
        jGame["id"] = game.id;
        jGame["name"] = game.name;
        jGame["icon"] = game.iconUrl;
        games.append(jGame);
    }
    object["games"] = games;
    object["version"] = "1.0";
    return object;
}
