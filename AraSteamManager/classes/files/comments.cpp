#include "comments.h"

ProfileID Comment::profileId() const {
    return profileId_;
}

QStringList Comment::comment() const {
    return comment_;
}

void Comment::setComment(const QStringList &aComment) {
    comment_ = aComment;
}

Comment::Comment(const ProfileID &aProfileId, const QStringList &aComment): profileId_(aProfileId), comment_(aComment) {

}

Comment::~Comment() {

}

#define AchievementCStart {
AchievementComment::AchievementComment(const ProfileID &aProfileId, const GameID &aGameId, const AchievementID &aAchievementId, const QStringList &aComment):
    Comment(aProfileId, aComment), gameId_(aGameId), achievementId_(aAchievementId) {

}

AchievementComment::AchievementComment(const QJsonObject &aObject): Comment() {
    fromJson(aObject);
}

AchievementComment::~AchievementComment() {

}

bool AchievementComment::operator==(const AchievementComment &aComment) const {
    return aComment.profileId() == profileId_
            && aComment.gameId() == gameId_
            && aComment.achievementId() == achievementId_;
}

QJsonObject AchievementComment::toJson() const {
    QJsonObject object;
    object["profile"] = profileId_;
    object["game"] = gameId_;
    object["achievement"] = achievementId_;

    QJsonArray comment;
    for(const auto &line: comment_) {
        comment.append(line);
    }
    object["comment"] = comment;
    return object;
}

GameID AchievementComment::gameId() const {
    return gameId_;
}

AchievementID AchievementComment::achievementId() const {
    return achievementId_;
}

void AchievementComment::fromJson(const QJsonObject &aObject) {
    profileId_ = aObject.value("profile").toString();
    gameId_ = aObject.value("game").toInt();
    achievementId_ = aObject.value("achievement").toString();

    comment_.clear();
    for(const auto &line: aObject.value("comment").toArray()) {
        comment_.append(line.toString());
    }
}
#define AchievementCEnd }

#define GameCStart {
GameComment::GameComment(const GameID &aGameId, const ProfileID &aProfileId, const QStringList &aComment): Comment(aProfileId, aComment), gameId_(aGameId) {

}

GameComment::GameComment(const QJsonObject &aObject): Comment() {
    fromJson(aObject);
}

GameComment::~GameComment() {

}

QJsonObject GameComment::toJson() const {
    QJsonObject object;
    object["profile"] = profileId_;
    object["game"] = gameId_;

    QJsonArray comment;
    for(const auto &line: comment_) {
        comment.append(line);
    }
    object["comment"] = comment;
    return object;
}

GameID GameComment::gameId() const {
    return gameId_;
}

void GameComment::fromJson(const QJsonObject &aObject) {
    profileId_ = aObject.value("profile").toString();
    gameId_ = aObject.value("game").toInt();

    comment_.clear();
    auto array = aObject.value("comment").toArray();
    for(const auto &line: array) {
        comment_.append(line.toString());
    }
}
#define GameCEnd }

AchievementComments::AchievementComments(const ProfileID &aProfileId): FileSaveLoad(Paths::commentsAchievements(aProfileId)), profileId_(aProfileId) {
    load(filePath_);
}

QList<AchievementComment> AchievementComments::getCommentsFromGame(const ProfileID &aProfileId, const GameID &aGameId) {
    QList<AchievementComment> comments;
    for (const auto &comment: *this) {
        if (comment.profileId() == aProfileId && comment.gameId() == aGameId) {
            comments << comment;
        }
    }
    return comments;
}

void AchievementComments::append(const AchievementComment &aAchievementComment) {
//    qDebug() << "add" << aAchievementComment.profileId() << aAchievementComment.gameId() << aAchievementComment.achievementId() << aAchievementComment.comment();
    QList<AchievementComment>::append(aAchievementComment);
    save();
}

void AchievementComments::remove(const ProfileID &aProfileId, const GameID &aGameId, const AchievementID &aAchievementId) {
    auto iterator = std::find_if(begin(),
                                 end(),
                                 [=](const AchievementComment &lComment) {
                                    return lComment.profileId() == aProfileId && lComment.gameId() == aGameId && lComment.achievementId() == aAchievementId;
                                 });
    if (iterator != end()) {
        erase(iterator);
        save();
    }
}

void AchievementComments::setComment(const ProfileID &aProfileId, const GameID &aGameId, const QString &aAchievementId, const QStringList &aComment) {
    auto iterator = std::find_if(begin(),
                                 end(),
                                 [=](const AchievementComment &lComment) {
                                    return lComment.profileId() == aProfileId && lComment.gameId() == aGameId && lComment.achievementId() == aAchievementId;
                                 });
    if (iterator != end()) {
        iterator->setComment(aComment);
        save();
    }
}

QJsonObject AchievementComments::toJson() const {
    QJsonObject achievementsObject;
    achievementsObject["profileId"] = profileId_;

    QList<AchievementComment> comments(*this);
    std::sort(comments.begin(),
              comments.end(),
              [=](const AchievementComment &lComment1, const AchievementComment &lComment2) {
                return lComment1.gameId() < lComment2.gameId();
              });

    QJsonArray GamesArray;
    for(auto it = comments.begin(); it != comments.end();) {
        QJsonArray achievementsAchievementsArray;
        GameID gameId = it->gameId();
        while (it != comments.end() && gameId == it->gameId()) {
            achievementsAchievementsArray.append((*it).toJson());
            ++it;
        }
        QJsonObject GameObject;
        GameObject["gameId"] = gameId;
        GameObject["achievements"] = achievementsAchievementsArray;
        GamesArray.append(GameObject);
    }
    achievementsObject["games"] = GamesArray;
    return achievementsObject;
}

void AchievementComments::update() {
    load(filePath_);
}

void AchievementComments::fromJson(const QJsonObject &aObject) {
    for(const auto &game: aObject.value("games").toArray()) {
        for(const auto &achievement: game.toObject().value("achievements").toArray()) {
            QList<AchievementComment>::append(AchievementComment(achievement.toObject()));
        }
    }
    profileId_ = aObject.value("profileId").toString();
}

GameComments::GameComments(const ProfileID &aProfileId): FileSaveLoad(Paths::commentsGames(aProfileId)), profileId_(aProfileId) {
    load(filePath_);
}

void GameComments::append(const GameComment &aGame) {
    QList<GameComment>::append(aGame);
    save();
}

void GameComments::remove(const ProfileID &aProfileId, const GameID &aGameId) {
    auto iterator = std::find_if(begin(),
                                 end(),
                                 [=](const GameComment &lComment) {
                                    return lComment.profileId() == aProfileId && lComment.gameId() == aGameId;
                                 });
    if (iterator != end()) {
        erase(iterator);
        save();
    }
}

void GameComments::setComment(const ProfileID &aProfileId, const GameID &aGameId, const QStringList &aComment) {
    auto iterator = std::find_if(begin(),
                                 end(),
                                 [=](const GameComment &lComment) {
                                    return lComment.profileId() == aProfileId && lComment.gameId() == aGameId;
                                 });
    if (iterator != end()) {
        iterator->setComment(aComment);
        save();
    }
}

QJsonObject GameComments::toJson() const {
    QJsonObject gamesObject;
    gamesObject["profileId"] = profileId_;
    QJsonArray games;
    for(const auto &game: *this) {
        games.append(game.toJson());
    }
    gamesObject["games"] = games;
    return gamesObject;
}

void GameComments::update() {
    load(filePath_);
}

void GameComments::fromJson(const QJsonObject &aObject) {
    for(const auto &game: aObject.value("games").toArray()) {
        QList<GameComment>::append(GameComment(game.toObject()));
    }
}
