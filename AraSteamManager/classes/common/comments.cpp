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

QList<QPair<QString, QList<AchievementComment>>> AchievementComment::load(const QString &aProfileId) {
    QList<QPair<QString, QList<AchievementComment>>> list;
    QByteArray bytes;
    if (readFile(Paths::commentsAchievements(aProfileId), bytes)) {
        QJsonObject achievements = QJsonDocument::fromJson(bytes).object();
        foreach(auto &&game, achievements.value("games").toArray()) {
            QPair<QString, QList<AchievementComment>> pair;
            pair.first = game.toObject().value("gameId").toString();
            foreach(auto &&achievement, game.toObject().value("achievements").toArray()) {
                pair.second.append(std::move(AchievementComment(achievement.toObject())));
            }
            list.append(pair);
        }
    }
    return list;
}

QList<AchievementComment> AchievementComment::load(const QString &aProfileId, const QString &aGameId) {
    QList<AchievementComment> list;
    QByteArray bytes;
    if (readFile(Paths::commentsAchievements(aProfileId), bytes)) {
        QJsonObject achievements = QJsonDocument::fromJson(bytes).object();
        foreach(auto &&game, achievements.value("games").toArray()) {
            if (game.toObject().value("gameId").toString() != aGameId) {
                continue;
            }
            foreach(auto &&achievement, game.toObject().value("achievements").toArray()) {
                list.append(std::move(AchievementComment(achievement.toObject())));
            }
        }
    }
    return list;
}

bool AchievementComment::save(const QString &aProfileId, const QString &aGameId, const AchievementComment &aComments) {
    auto list = load(aProfileId);
    auto iterator = std::find_if(list.begin(),
                                 list.end(),
                                 [=](const QPair<QString, QList<AchievementComment>> &comment) {
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
        list.append(QPair<QString, QList<AchievementComment>>(aGameId, QList<AchievementComment>() << aComments));
    }
    return save(aProfileId, list);
}

bool AchievementComment::save(const QString &aProfileId, const QString &aGameId, const QList<AchievementComment> &aComments) {
    auto list = load(aProfileId);
    auto iterator = std::find_if(list.begin(),
                                 list.end(),
                                 [=](const QPair<QString, QList<AchievementComment>> &comment) {
                                    return comment.first == aGameId;
                                });
    if (iterator != list.end()) {
        list.removeAt(iterator - list.begin());
    }
    if (aComments.count() > 0) {
        list.append(QPair<QString, QList<AchievementComment>>(aGameId, aComments));
    }
    return save(aProfileId, list);
}

bool AchievementComment::save(const QString &aProfileId, QList<QPair<QString, QList<AchievementComment> > > &aComments) {
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
    _gameId = aObject.value("game").toString();
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

QList<GameComment> GameComment::load(const QString &aProfileId) {
    QList<GameComment> list;

    QByteArray bytes;
    if (readFile(Paths::commentsGames(aProfileId), bytes)) {
        QJsonObject games = QJsonDocument::fromJson(bytes).object();
        foreach(const auto &game, games.value("games").toArray()) {
            list.append(std::move(GameComment(game.toObject())));
        }
    }
    return list;
}

bool GameComment::save(const QString &aProfileId, const GameComment &aComments) {
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

bool GameComment::save(const QString &aProfileId, const QList<GameComment> &aComments) {
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
    _gameId = aObject.value("game").toString();

    _comment.clear();
    for(auto &&line: aObject.value("comment").toArray()) {
        _comment.append(line.toString());
    }
}
#define GameCEnd }

#define CStart {
Comments::Comments(const QString &aProfileId) : _profileId(aProfileId) {
    if (_profileId != "") {
        load();
    }
}

Comments &Comments::setProfileId(const QString &aProfileId) {
    _profileId = aProfileId;
    if (_profileId != "") {
        load();
    }
    return *this;
}

Comments &Comments::setGameComment(const QString &aGameId, const QString &aProfileId, const QStringList &aComment) {
    auto iterator = findGameComment(aGameId, aProfileId);
    if (iterator != _games.end()) {
        (*iterator).changeComment(aComment);
    } else {
        _games.append(std::move(GameComment(aGameId, aProfileId, aComment)));
    }
    save();
    return *this;
}

QList<GameComment>::iterator Comments::findGameComment(const QString &aGameId, const QString &aProfileId) {
    return std::find_if(_games.begin(),
                        _games.end(),
                        [=](GameComment comment) {
                           return comment.gameId() == aGameId &&
                                  comment.profileId() == aProfileId;
    });
}

QList<GameComment>::const_iterator Comments::findGameComment(const QString &aGameId, const QString &aProfileId) const {
    return std::find_if(_games.cbegin(),
                        _games.cend(),
                        [=](GameComment comment) {
                           return comment.gameId() == aGameId &&
                                  comment.profileId() == aProfileId;
    });
}

QList<QPair<QString, QList<AchievementComment>>>::iterator Comments::findAchievementComment(const QString &aGameId) {
    return std::find_if(_achievements.begin(),
                        _achievements.end(),
                        [=](QPair<QString, QList<AchievementComment>> AchievementGameComment) {
                            return AchievementGameComment.first == aGameId;
    });
}

QList<QPair<QString, QList<AchievementComment>>>::const_iterator Comments::findAchievementComment(const QString &aGameId) const {
    return std::find_if(_achievements.cbegin(),
                        _achievements.cend(),
                        [=](QPair<QString, QList<AchievementComment>> AchievementGameComment) {
                            return AchievementGameComment.first == aGameId;
    });
}

Comments &Comments::setAchievementComment(const QString &aProfileId, const QString &aGameId, const QString &aAchievementId, const QStringList &aComment) {
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
            (*iteratorGameAchievements).second.append(std::move(AchievementComment(aProfileId, aGameId, aAchievementId, aComment)));
        }
    } else {
        _achievements.append(std::move(QPair<QString, QList<AchievementComment>>
                             (aGameId, QList<AchievementComment> {AchievementComment(aProfileId, aGameId, aAchievementId, aComment)})));
    }
    saveAchievements();
    return *this;
}

Comments &Comments::removeGameComment(const QString &aGameId, const QString &aProfileId) {
    _games.erase(std::remove_if(_games.begin(),
                                _games.end(),
                                [=](GameComment comment) {
                                    return ((comment.gameId() == aGameId) &&
                                            (comment.profileId() == aProfileId));
                                }), _games.end());
    save();
    return *this;
}

Comments &Comments::removeAchievementComment(const QString &aProfileId, const QString &aGameId, const QString &aAchievementId) {
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

const GameComment Comments::getGameComment(const QString &aGameId) const {
    auto iterator = findGameComment(aGameId, _profileId);
    if (iterator != _games.end()) {
        return *iterator;
    } else {
        return GameComment(aGameId, _profileId, QStringList());
    }
}

const AchievementComment Comments::getAchievementComment(const QString &aProfileId, const QString &aGameId, const QString &aAchievementId) const {
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
        foreach(const auto &game, games.value("games").toArray()) {
            _games.append(std::move(GameComment(game.toObject())));
        }
    }

    if (readFile(Paths::commentsAchievements(_profileId), bytes)) {
        QJsonObject achievements = QJsonDocument::fromJson(bytes).object();
        foreach(auto &&game, achievements.value("games").toArray()) {
            QPair<QString, QList<AchievementComment>> pair;
            pair.first = game.toObject().value("gameId").toString();
            foreach(auto &&achievement, game.toObject().value("achievements").toArray()) {
                pair.second.append(std::move(AchievementComment(achievement.toObject())));
            }
            _achievements.append(pair);
        }
    }
    return *this;
}
#define CEnd }
