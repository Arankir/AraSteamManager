#include "hiddengames.h"

HiddenGames::HiddenGames(const ProfileID &aProfile, bool aIsIncludeAll): FileSaveLoad(Paths::hiddenGames(aProfile == "" ? "All" : aProfile)), profile_(aProfile) {
    load(aProfile);
    if (aIsIncludeAll) {
        load("");
    }
}

void HiddenGames::remove(const GameID &aGameId) {
    erase(std::remove_if(begin(),
                         end(),
                        [=](const HiddenGame &lGame) {
                            return aGameId == lGame.id();
                        }),
          end());
}

bool HiddenGames::isGameExist(const GameID &aGame) {
    auto iterator = std::find_if(begin(),
                                 end(),
                                 [=](const HiddenGame &lGame) {
                                     return aGame == lGame.id();
                                 });
    if (iterator == end()) {
        return false;
    } else {
        return true;
    }
}

void HiddenGames::load(const ProfileID &aProfileId) {
    filePath_ = Paths::hiddenGames(profile_ == "" ? "All" : aProfileId);
    FileSaveLoad::load(filePath_);
}

QJsonObject HiddenGames::toJson() const {
    QJsonObject object;
    object["profile"] = profile_;
    QJsonArray games;
    for(const HiddenGame &game: *this) {
        games.append(std::move(game.toJson()));
    }
    object["games"] = games;
    object["version"] = "1.0";
    return object;
}

void HiddenGames::fromJson(const QJsonObject &aObject) {
    for(QJsonValue &&game: aObject.value("games").toArray()) {
        append(HiddenGame(game.toObject()));
    }
}

HiddenGame::HiddenGame(const SGame &aGame): id_(aGame.appId()), name_(aGame.name()), iconUrl_(aGame.imgIconUrl()) {

}

HiddenGame::HiddenGame(const GameID &aGameId, const QString &aName, const QString &aIconUrl): id_{aGameId},
name_{aName}, iconUrl_{aIconUrl} {

}

HiddenGame::HiddenGame(const HiddenGame &aGame): id_(aGame.id_), name_(aGame.name_), iconUrl_(aGame.iconUrl_) {

}

HiddenGame::HiddenGame(const QJsonObject &aGame) {
    fromJson(aGame);
}

HiddenGame &HiddenGame::fromJson(const QJsonObject &aObject) {
    id_         = aObject.value("id").toInt();
    name_       = aObject.value("name").toString();
    iconUrl_    = aObject.value("icon").toString();
    return *this;
}

HiddenGame &HiddenGame::operator=(const HiddenGame &aObject) {
    id_ = aObject.id_;
    name_ = aObject.name_;
    iconUrl_ = aObject.iconUrl_;
    return *this;
}

QJsonObject HiddenGame::toJson() const {
    QJsonObject jGame;
    jGame["id"] = id_;
    jGame["name"] = name_;
    jGame["icon"] = iconUrl_;
    return jGame;
}

GameID HiddenGame::id() const {
    return id_;
}

QString HiddenGame::name() const {
    return name_;
}

QString HiddenGame::iconUrl() const {
    return iconUrl_;
}
