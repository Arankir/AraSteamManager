#include "hiddengames.h"
#include "classes/common/settings.h"

HiddenGames::HiddenGames(SProfile profile) : _profile(profile.steamID()) {
    load();
}

HiddenGames &HiddenGames::addGame(const SGame &aGame, const bool &aRemoveIfExist) {
    auto iterator = std::find_if(_games.begin(),
                                 _games.end(),
                                 [=](HiddenGame game) {
                                    return game.id() == aGame.sAppId();
                                 });
    if (iterator != _games.end()) {
        if (aRemoveIfExist) {
            removeGame(aGame);
        }
    } else {
        _games.append(std::move(HiddenGame(aGame)));
    }
    save();
    return *this;
}

HiddenGames &HiddenGames::removeGame(const SGame &aGame, const bool &aAddIfExist) {
    auto iterator = std::remove_if(_games.begin(),
                                   _games.end(),
                                   [=](HiddenGame game) {
                                        return game.id() == aGame.sAppId();
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
    saveFile(Paths::hiddenGames(_profile), QJsonDocument(toJson()).toJson());
    return *this;
}

void HiddenGames::load() {
    _games.clear();

    QByteArray bytes;
    if (readFile(Paths::hiddenGames(_profile == "" ? "All" : _profile), bytes)) {
        QJsonObject games = QJsonDocument::fromJson(bytes).object();
        for(auto &&game: games.value("games").toArray()) {
            _games.append(std::move(HiddenGame(game.toObject())));
        }
        _profile = games.value("profile").toString();
    }
}

QJsonObject HiddenGames::toJson() {
    QJsonObject object;
    object["profile"] = _profile;
    QJsonArray games;
    for(auto &&game: _games) {
        games.append(std::move(game.toJson()));
    }
    object["games"] = games;
    object["version"] = "1.0";
    return object;
}

HiddenGame::HiddenGame(const SGame &aGame): _id(aGame.sAppId()), _name(aGame.name()), _iconUrl(aGame.imgIconUrl()) {

}

HiddenGame::HiddenGame(const QJsonObject &aGame) {
    fromJson(aGame);
}

HiddenGame &HiddenGame::fromJson(const QJsonObject &aObject) {
    _id         = aObject.value("id").toString();
    _name       = aObject.value("name").toString();
    _iconUrl    = aObject.value("icon").toString();
    return *this;
}

QJsonObject HiddenGame::toJson() const {
    QJsonObject jGame;
    jGame["id"] = _id;
    jGame["name"] = _name;
    jGame["icon"] = _iconUrl;
    return jGame;
}
