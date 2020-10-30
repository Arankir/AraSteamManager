#include "comments.h"

#define AchievementCStart {
AchievementComment::AchievementComment(const QJsonObject &aObject) {
    fromJson(aObject);
}

AchievementComment &AchievementComment::changeComment(const QStringList &aComment) {
    _comment = aComment;
    return *this;
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

void AchievementComment::fromJson(const QJsonObject &aObject) {
    _profileId = aObject.value("profile").toString();
    _gameId = aObject.value("game").toString();
    _achievementId = aObject.value("achievement").toString();

    _comment.clear();
    for(auto line: aObject.value("comment").toArray()) {
        _comment.append(line.toString());
    }
}
#define AchievementCEnd }

#define GameCStart {
GameComment::GameComment(const QJsonObject &aObject) {
    fromJson(aObject);
}

GameComment &GameComment::changeComment(const QStringList &aComment) {
    _comment = aComment;
    return *this;
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

void GameComment::fromJson(const QJsonObject &aObject) {
    _profileId = aObject.value("profile").toString();
    _gameId = aObject.value("game").toString();

    _comment.clear();
    for(auto line: aObject.value("comment").toArray()) {
        _comment.append(line.toString());
    }
}
#define GameCEnd }

#define CStart {
Comments::Comments(QString aProfileId) : _profileId(aProfileId) {
    load();
}

Comments &Comments::setGameComment(const QString &aGameId, const QString &aProfileId, const QStringList &aComment) {
    auto iterator = std::find_if(_games.begin(), _games.end(), [=](GameComment comment) {
                                                                    return comment.getGameId() == aGameId && comment.getProfileId() == aProfileId;
                                                                });
    if (iterator != _games.end()) {
        (*iterator).changeComment(aComment);
    } else {
        _games.append(GameComment(aGameId, aProfileId, aComment));
    }
    save();
    return *this;
}

Comments &Comments::setAchievementComment(const QString &aProfileId, const QString &aGameId, const QString &aAchievementId, const QStringList &aComment) {
    auto iterator = std::find_if(_achievements.begin(), _achievements.end(), [=](QPair<QString, QList<AchievementComment>> comment) {
                                                                                 return comment.first == aGameId;
                                                                             });
    if (iterator != _achievements.end()) {
        auto iteratorAchievement = std::find_if((*iterator).second.begin(), (*iterator).second.end(), [=](AchievementComment comment) {
                                                                                                            return comment.getProfileId() == aProfileId
                                                                                                                    && comment.getGameId() == aGameId
                                                                                                                    && comment.getAchievementId() == aAchievementId;
                                                                                                        });
        if (iteratorAchievement != (*iterator).second.end()) {
            (*iteratorAchievement).changeComment(aComment);
        } else {
            (*iterator).second.append(AchievementComment(aProfileId, aGameId, aAchievementId, aComment));
        }
    } else {
        _achievements.append(QPair<QString, QList<AchievementComment>>(aGameId, QList<AchievementComment>() << AchievementComment(aProfileId, aGameId, aAchievementId, aComment)));
    }
    save();
    return *this;
}

Comments &Comments::removeGameComment(const QString &aGameId, const QString &aProfileId) {
    _games.erase(std::remove_if(_games.begin(), _games.end(), [=](GameComment comment) {
                                                                    return ((comment.getGameId() == aGameId) && (comment.getProfileId() == aProfileId));
                                                                }), _games.end());
    save();
    return *this;
}

Comments &Comments::removeAchievementComment(const QString &aProfileId, const QString &aGameId, const QString &aAchievementId) {
    auto iterator = std::find_if(_achievements.begin(), _achievements.end(), [=](QPair<QString, QList<AchievementComment>> comment) {
                                                                                 return comment.first == aGameId;
                                                                             });
    if (iterator != _achievements.end()) {
        (*iterator).second.erase(std::remove_if((*iterator).second.begin(), (*iterator).second.end(), [=](AchievementComment comment) {
                                                                                                            return comment.getProfileId() == aProfileId
                                                                                                                    && comment.getGameId() == aGameId
                                                                                                                    && comment.getAchievementId() == aAchievementId;
                                                                                                        }), (*iterator).second.end());
    } else {

    }
    save();
    return *this;
}

const GameComment &Comments::getGameComment(const QString &aGameId, const QString &aProfileId) const {
    auto iterator = std::find_if(_games.begin(), _games.end(), [=](GameComment comment) {
                                                                    return ((comment.getGameId() == aGameId) && (comment.getProfileId() == aProfileId));
                                                                });
    if (iterator != _games.end()) {
        return *iterator;
    } else {
        return *(new GameComment(aGameId, aProfileId, QStringList()));
    }
}

const AchievementComment &Comments::getAchievementComment(const QString &aProfileId, const QString &aGameId, const QString &aAchievementId) const {
    auto iterator = std::find_if(_achievements.begin(), _achievements.end(), [=](QPair<QString, QList<AchievementComment>> comment) {
                                                                                 return comment.first == aGameId;
                                                                             });
    if (iterator != _achievements.end()) {
        auto iteratorAchievement = std::find_if((*iterator).second.begin(), (*iterator).second.end(), [=](AchievementComment comment) {
                                                                                                            return comment.getProfileId() == aProfileId
                                                                                                                    && comment.getGameId() == aGameId
                                                                                                                    && comment.getAchievementId() == aAchievementId;
                                                                                                        });
        if (iteratorAchievement != (*iterator).second.end()) {
            return *iteratorAchievement;
        } else {
            return *(new AchievementComment(aProfileId, aGameId, aAchievementId, QStringList()));
        }
    } else {
        return *(new AchievementComment(aProfileId, aGameId, aAchievementId, QStringList()));
    }
}

Comments &Comments::save() {
    QJsonObject gamesObject;
    gamesObject["profileId"] = _profileId;
    QJsonArray games;
    for(const auto &game: _games) {
        games.append(game.toJson());
    }
    gamesObject["games"] = games;

    saveFile(Paths::commentsGames(_profileId), gamesObject);

    QJsonObject achievementsObject;
    achievementsObject["profileId"] = _profileId;
    QJsonArray achievementsGamesArray;
    for(const auto &game: _achievements) {
        QJsonObject achievementsGameObject;
        QJsonArray achievementsAchievementsArray;
        for(const auto &achievement: game.second) {
            achievementsAchievementsArray.append(achievement.toJson());
        }
        achievementsGameObject["gameId"] = game.first;
        achievementsGameObject["achievements"] = achievementsAchievementsArray;
        achievementsGamesArray.append(achievementsGameObject);
    }
    achievementsObject["games"] = achievementsGamesArray;
    saveFile(Paths::commentsAchievements(_profileId), achievementsObject);

    return *this;
}

void Comments::saveFile(const QString &aProfileId, const QJsonObject &aObject) {
    Settings::createDir(aProfileId);
    QFile file(aProfileId);
    file.open(QFile::WriteOnly);
    file.write(QJsonDocument(aObject).toJson());
    file.close();
}

Comments &Comments::load() {
    _games.clear();
    _achievements.clear();

    QFile file1(Paths::commentsGames(_profileId));
    if (file1.open(QFile::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file1.readAll());
        QJsonObject games = doc.object();
        for(const auto &game: games.value("games").toArray()) {
            _games.append(GameComment(game.toObject()));
        }
        file1.close();
    }

    QFile file2(Paths::commentsAchievements(_profileId));
    if (file2.open(QFile::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file2.readAll());
        QJsonObject achievements = doc.object();
        for(const auto &game: achievements.value("games").toArray()) {
            QPair<QString, QList<AchievementComment>> pair;
            pair.first = game.toObject().value("gameId").toString();
            for(const auto &achievement: game.toObject().value("achievements").toArray()) {
                pair.second.append(AchievementComment(achievement.toObject()));
            }
            _achievements.append(pair);
        }
        file2.close();
    }
    return *this;
}
#define CEnd }
