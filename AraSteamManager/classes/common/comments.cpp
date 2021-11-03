#include "comments.h"
#include "classes/common/settings.h"

void Comment::changeComment(const QStringList &aComment) {
    _comment = aComment;
}

#define AchievementCStart {
AchievementComment::AchievementComment(const QJsonObject &aObject): Comment() {
    fromJson(aObject);
}

bool AchievementComment::operator==(const AchievementComment &comment) const {
    return comment.profileId() == _profileId
            && comment.gameId() == _gameId
            && comment.achievementId() == _achievementId;
}

QJsonObject AchievementComment::toJson() const {
    QJsonObject object;
    object["profile"] = _profileId;
    object["game"] = _gameId;
    object["achievement"] = _achievementId;

    QJsonArray comment;
    for(const auto &line: _comment) {
        comment.append(line);
    }
    object["comment"] = comment;
    return object;
}

AchievementGamesComments AchievementComment::load(const ProfileID &aProfileId) {
    AchievementGamesComments list;
    QByteArray bytes;
    if (readFile(Paths::commentsAchievements(aProfileId), bytes)) {
        QJsonObject achievements = QJsonDocument::fromJson(bytes).object();
        for(auto &&game: achievements.value("games").toArray()) {
            AchievementGameComments pair;
            pair.first = game.toObject().value("gameId").toInt();
            for(auto &&achievement: game.toObject().value("achievements").toArray()) {
                pair.second.append(AchievementComment(achievement.toObject()));
            }
            list.append(pair);
        }
    }
    return list;
}

QList<AchievementComment> AchievementComment::load(const ProfileID &aProfileId, const GameID &aGameId) {
    QList<AchievementComment> list;
    QByteArray bytes;
    if (readFile(Paths::commentsAchievements(aProfileId), bytes)) {
        QJsonObject achievements = QJsonDocument::fromJson(bytes).object();
        for(auto &&game: achievements.value("games").toArray()) {
            if (game.toObject().value("gameId").toInt() != aGameId) {
                continue;
            }
            for(auto &&achievement: game.toObject().value("achievements").toArray()) {
                list.append(AchievementComment(achievement.toObject()));
            }
        }
    }
    return list;
}

bool AchievementComment::save(const ProfileID &aProfileId, const GameID &aGameId, const AchievementComment &aComments) {
    auto list = load(aProfileId);
    auto iterator = std::find_if(list.begin(),
                                 list.end(),
                                 [=](const AchievementGameComments &comment) {
                                    return comment.first == aGameId;
                                });
    if (iterator != list.end()) {
        auto iterator2 = std::find_if((*iterator).second.begin(),
                                     (*iterator).second.end(),
                                     [=](const AchievementComment &comment) {
                                        return comment._achievementId == aComments._achievementId;
                                    });
        if (iterator2 != (*iterator).second.end()) {
            (*iterator).second.removeAt(iterator2 - (*iterator).second.begin());
        }
        (*iterator).second.append(aComments);
    } else {
        list.append(AchievementGameComments(aGameId, QList<AchievementComment>{aComments}));
    }
    return save(aProfileId, list);
}

bool AchievementComment::save(const ProfileID &aProfileId, const GameID &aGameId, const QList<AchievementComment> &aComments) {
    auto list = load(aProfileId);
    auto iterator = std::find_if(list.begin(),
                                 list.end(),
                                 [=](const AchievementGameComments &comment) {
                                    return comment.first == aGameId;
                                });
    if (iterator != list.end()) {
        list.removeAt(iterator - list.begin());
    }
    if (aComments.count() > 0) {
        list.append(AchievementGameComments(aGameId, aComments));
    }
    return save(aProfileId, list);
}

bool AchievementComment::save(const ProfileID &aProfileId, AchievementGamesComments &aComments) {
    QJsonObject achievementsObject;
    achievementsObject["profileId"] = aProfileId;
    QJsonArray achievementsGamesArray;
    for(auto &&achievement: aComments) {
        QJsonArray achievementsAchievementsArray;
        for(auto &&achievement: achievement.second) {
            achievementsAchievementsArray.append(achievement.toJson());
        }
        QJsonObject achievementsGameObject;
        achievementsGameObject["gameId"] = achievement.first;
        achievementsGameObject["achievements"] = achievementsAchievementsArray;
        achievementsGamesArray.append(achievementsGameObject);
    }
    achievementsObject["games"] = achievementsGamesArray;
    return saveFile(Paths::commentsAchievements(aProfileId), QJsonDocument(achievementsObject).toJson());
}

void AchievementComment::fromJson(const QJsonObject &aObject) {
    _profileId = aObject.value("profile").toString();
    _gameId = aObject.value("game").toInt();
    _achievementId = aObject.value("achievement").toString();

    _comment.clear();
    for(auto &&line: aObject.value("comment").toArray()) {
        _comment.append(line.toString());
    }
}
#define AchievementCEnd }

#define GameCStart {
GameComment::GameComment(const QJsonObject &aObject): Comment() {
    fromJson(aObject);
}

QJsonObject GameComment::toJson() const {
    QJsonObject object;
    object["profile"] = _profileId;
    object["game"] = _gameId;

    QJsonArray comment;
    for(const auto &line: _comment) {
        comment.append(line);
    }
    object["comment"] = comment;
    return object;
}

QList<GameComment> GameComment::load(const ProfileID &aProfileId) {
    QList<GameComment> list;

    QByteArray bytes;
    if (readFile(Paths::commentsGames(aProfileId), bytes)) {
        QJsonObject games = QJsonDocument::fromJson(bytes).object();
        for(const auto &game: games.value("games").toArray()) {
            list.append(GameComment(game.toObject()));
        }
    }
    return list;
}

bool GameComment::save(const ProfileID &aProfileId, const GameComment &aComments) {
    auto list = load(aProfileId);
    auto iterator = std::find_if(list.begin(),
                                 list.end(),
                                 [=](const GameComment &comment) {
                                    return comment.gameId() == aComments.gameId();
                                });
    if (iterator != list.end()) {
        list.removeAt(iterator - list.begin());
    }
    if (aComments.comment() != QStringList()) {
        list.append(aComments);
    }
    return save(aProfileId, list);
}

bool GameComment::save(const ProfileID &aProfileId, const QList<GameComment> &aComments) {
    QJsonObject gamesObject;
    gamesObject["profileId"] = aProfileId;
    QJsonArray games;
    for(auto &&game: aComments) {
        games.append(game.toJson());
    }
    gamesObject["games"] = games;

    return saveFile(Paths::commentsGames(aProfileId), QJsonDocument(gamesObject).toJson());
}

void GameComment::fromJson(const QJsonObject &aObject) {
    _profileId = aObject.value("profile").toString();
    _gameId = aObject.value("game").toInt();

    _comment.clear();
    for(auto &&line: aObject.value("comment").toArray()) {
        _comment.append(line.toString());
    }
}
#define GameCEnd }

#define CStart {
Comments::Comments(const ProfileID &aProfileId) : _profileId(aProfileId) {
    if (_profileId != "") {
        load();
    }
}

Comments &Comments::setProfileId(const ProfileID &aProfileId) {
    _profileId = aProfileId;
    if (_profileId != "") {
        load();
    }
    return *this;
}

Comments &Comments::setGameComment(const GameID &aGameId, const ProfileID &aProfileId, const QStringList &aComment) {
    auto iterator = findGameComment(aGameId, aProfileId);
    if (iterator != _games.end()) {
        (*iterator).changeComment(aComment);
    } else {
        _games.append(GameComment(aGameId, aProfileId, aComment));
    }
    save();
    return *this;
}

QList<GameComment>::iterator Comments::findGameComment(const GameID &aGameId, const ProfileID &aProfileId) {
    return std::find_if(_games.begin(),
                        _games.end(),
                        [=](GameComment comment) {
                           return comment.gameId() == aGameId &&
                                  comment.profileId() == aProfileId;
                        });
}

QList<GameComment>::const_iterator Comments::findGameComment(const GameID &aGameId, const ProfileID &aProfileId) const {
    return std::find_if(_games.cbegin(),
                        _games.cend(),
                        [=](GameComment comment) {
                           return comment.gameId() == aGameId &&
                                  comment.profileId() == aProfileId;
                            });
}

AchievementGamesComments::iterator Comments::findAchievementComment(const GameID &aGameId) {
    return std::find_if(_achievements.begin(),
                        _achievements.end(),
                        [=](AchievementGameComments AchievementGameComment) {
                            return AchievementGameComment.first == aGameId;
                        });
}

AchievementGamesComments::const_iterator Comments::findAchievementComment(const GameID &aGameId) const {
    return std::find_if(_achievements.cbegin(),
                        _achievements.cend(),
                        [=](AchievementGameComments AchievementGameComment) {
                            return AchievementGameComment.first == aGameId;
    });
}

Comments &Comments::setAchievementComment(const ProfileID &aProfileId, const GameID &aGameId, const AchievementID &aAchievementId, const QStringList &aComment) {
    auto iteratorGameAchievements = findAchievementComment(aGameId);
    if (iteratorGameAchievements != _achievements.end()) {
        auto iteratorAchievement = std::find_if((*iteratorGameAchievements).second.begin(),
                                                (*iteratorGameAchievements).second.end(),
                                                [=](const AchievementComment &comment) {
                                                    return comment == AchievementComment {aProfileId, aGameId, aAchievementId, QStringList()};
                                                });
        if (iteratorAchievement != (*iteratorGameAchievements).second.end()) {
            (*iteratorAchievement).changeComment(aComment);
        } else {
            (*iteratorGameAchievements).second.append(AchievementComment(aProfileId, aGameId, aAchievementId, aComment));
        }
    } else {
        _achievements.append(AchievementGameComments(aGameId, QList<AchievementComment> {AchievementComment(aProfileId, aGameId, aAchievementId, aComment)}));
    }
    saveAchievements();
    return *this;
}

Comments &Comments::removeGameComment(const GameID &aGameId, const ProfileID &aProfileId) {
    _games.erase(std::remove_if(_games.begin(),
                                _games.end(),
                                [=](GameComment comment) {
                                    return ((comment.gameId() == aGameId) &&
                                            (comment.profileId() == aProfileId));
                                }), _games.end());
    save();
    return *this;
}

Comments &Comments::removeAchievementComment(const ProfileID &aProfileId, const GameID &aGameId, const AchievementID &aAchievementId) {
    auto iteratorGameAchievements = findAchievementComment(aGameId);
    if (iteratorGameAchievements != _achievements.end()) {
        (*iteratorGameAchievements).second.erase(std::remove_if((*iteratorGameAchievements).second.begin(),
                                                                (*iteratorGameAchievements).second.end(),
                                                                [=](const AchievementComment &comment) {
                                                                    return comment == AchievementComment {aProfileId, aGameId, aAchievementId, QStringList()};
                                                                }), (*iteratorGameAchievements).second.end());
    }
    save();
    return *this;
}

const GameComment Comments::getGameComment(const GameID &aGameId) const {
    auto iterator = findGameComment(aGameId, _profileId);
    if (iterator != _games.end()) {
        return *iterator;
    } else {
        return GameComment(aGameId, _profileId, QStringList());
    }
}

const AchievementComment Comments::getAchievementComment(const ProfileID &aProfileId, const GameID &aGameId, const AchievementID &aAchievementId) const {
    auto iterator = findAchievementComment(aGameId);
    if (iterator != _achievements.end()) {
        auto iteratorAchievement = std::find_if((*iterator).second.begin(),
                                                (*iterator).second.end(),
                                                [=](const AchievementComment &comment) {
                                                    return comment == AchievementComment {aProfileId, aGameId, aAchievementId, QStringList()};
                                                });
        if (iteratorAchievement != (*iterator).second.end()) {
            return *iteratorAchievement;
        }
    }
    return AchievementComment(aProfileId, aGameId, aAchievementId, QStringList());
}

bool Comments::saveGames() const {
    QJsonObject gamesObject;
    gamesObject["profileId"] = _profileId;
    QJsonArray games;
    for(auto &&game: _games) {
        games.append(game.toJson());
    }
    gamesObject["games"] = games;

    return saveFile(Paths::commentsGames(_profileId), QJsonDocument(gamesObject).toJson());
}

bool Comments::saveAchievements() const {
    QJsonObject achievementsObject;
    achievementsObject["profileId"] = _profileId;
    QJsonArray achievementsGamesArray;
    for(auto &&achievement: _achievements) {
        QJsonArray achievementsAchievementsArray;
        for(auto &&achievement: achievement.second) {
            achievementsAchievementsArray.append(achievement.toJson());
        }
        QJsonObject achievementsGameObject;
        achievementsGameObject["gameId"] = achievement.first;
        achievementsGameObject["achievements"] = achievementsAchievementsArray;
        achievementsGamesArray.append(achievementsGameObject);
    }
    achievementsObject["games"] = achievementsGamesArray;
    return saveFile(Paths::commentsAchievements(_profileId), QJsonDocument(achievementsObject).toJson());
}

bool Comments::save() const {
    bool games = saveGames();
    bool achievements = saveAchievements();
    return games && achievements;
}

Comments &Comments::load() {
    _games.clear();
    _achievements.clear();

    QByteArray bytes;
    if (readFile(Paths::commentsGames(_profileId), bytes)) {
        QJsonObject games = QJsonDocument::fromJson(bytes).object();
        for(const auto &game: games.value("games").toArray()) {
            _games.append(GameComment(game.toObject()));
        }
    }

    if (readFile(Paths::commentsAchievements(_profileId), bytes)) {
        QJsonObject achievements = QJsonDocument::fromJson(bytes).object();
        for(auto &&game: achievements.value("games").toArray()) {
            AchievementGameComments pair;
            pair.first = game.toObject().value("gameId").toInt();
            for(auto &&achievement: game.toObject().value("achievements").toArray()) {
                pair.second.append(AchievementComment(achievement.toObject()));
            }
            _achievements.append(pair);
        }
    }
    return *this;
}
#define CEnd }
