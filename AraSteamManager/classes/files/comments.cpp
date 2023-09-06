#include "comments.h"
#include "classes/common/images.h"
#include "classes/common/settings.h"

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
AchievementComment::AchievementComment(const ProfileID &aProfileId, const GameID &aGameId, const QString &aGameName, const QString &aGameIcon, const AchievementID &aAchievementId, const QString &aTitle, const QString &aIcon, const QStringList &aComment):
    Comment(aProfileId, aComment), gameId_(aGameId), gameName_(aGameName), gameIcon_(aGameIcon), achievementId_(aAchievementId), title_(aTitle), icon_(aIcon) {

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
    object["gameName"] = gameName_;
    object["gameIcon"] = gameIcon_;
    object["achievement"] = achievementId_;
    object["title"] = title_;
    object["icon"] = icon_;
    object["type"] = "AchievementComment";

    QJsonArray comment;
    for(const QString &line: comment_) {
        comment.append(line);
    }
    object["comment"] = comment;
    return object;
}

GameID AchievementComment::gameId() const {
    return gameId_;
}

QString AchievementComment::gameName() const {
    return gameName_;
}

QPixmap AchievementComment::gameIcon() const {
    if (gameIcon_.isEmpty()) {
        gameIconPixmap_ = QPixmap(Images::missingImage()).scaled(QSize(32, 32)).toImage();
    }
    return QPixmap::fromImage(loadImage(gameIconPixmap_, Sapi::gameImageUrl(gameId_, gameIcon_), Paths::imagesGames(gameIcon_), QSize(32, 32)));
}

AchievementID AchievementComment::achievementId() const {
    return achievementId_;
}

void AchievementComment::fromJson(const QJsonObject &aObject) {
    profileId_ = aObject.value("profile").toString();
    gameId_ = aObject.value("game").toInt();
    gameName_ = aObject.value("gameName").toString();
    gameIcon_ = aObject.value("gameIcon").toString();
    achievementId_ = aObject.value("achievement").toString();
    title_ = aObject.value("title").toString();
    icon_ = aObject.value("icon").toString();

    comment_.clear();
    for(const QJsonValue &line: aObject.value("comment").toArray()) {
        comment_.append(line.toString());
    }
}

QString AchievementComment::icon() const {
    return icon_;
}

QString AchievementComment::title() const {
    return title_;
}
#define AchievementCEnd }

#define GameCStart {
GameComment::GameComment(const GameID &aGameId, const QString &aGameName, const QString &aGameIcon, const ProfileID &aProfileId, const QStringList &aComment):
    Comment(aProfileId, aComment), gameId_(aGameId), gameName_(aGameName), gameIcon_(aGameIcon) {

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
    object["gameName"] = gameName_;
    object["gameIcon"] = gameIcon_;

    QJsonArray comment;
    for(const QString &line: comment_) {
        comment.append(line);
    }
    object["comment"] = comment;
    object["type"] = "GameComment";
    return object;
}

GameID GameComment::gameId() const {
    return gameId_;
}

QString GameComment::gameName() const {
    return gameName_;
}

QPixmap GameComment::gameIcon() const {
    if (gameIcon_.isEmpty()) {
        gameIconPixmap_ = QPixmap(Images::missingImage()).scaled(QSize(32, 32)).toImage();
    }
    return QPixmap::fromImage(loadImage(gameIconPixmap_, Sapi::gameImageUrl(gameId_, gameIcon_), Paths::imagesGames(gameIcon_), QSize(32, 32)));
}

void GameComment::fromJson(const QJsonObject &aObject) {
    profileId_ = aObject.value("profile").toString();
    gameId_ = aObject.value("game").toInt();
    gameName_ = aObject.value("gameName").toString();
    gameIcon_ = aObject.value("gameIcon").toString();

    comment_.clear();
    QJsonArray array = aObject.value("comment").toArray();
    for(const QJsonValue &line: array) {
        comment_.append(line.toString());
    }
}
#define GameCEnd }

AchievementComments::AchievementComments(const ProfileID &aProfileId): FileSaveLoad(Paths::commentsAchievements(aProfileId)), profileId_(aProfileId) {
    load(filePath_);
}

AchievementComments::AchievementComments(const QJsonObject &aObject): FileSaveLoad(Paths::commentsAchievements("")) {
    fromJson(aObject);
}

QList<AchievementComment> AchievementComments::getCommentsFromGame(const ProfileID &aProfileId, const GameID &aGameId) {
    QList<AchievementComment> comments;
    for (const AchievementComment &comment: *this) {
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
    achievementsObject["type"] = "AchievementComments";

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
    for(const QJsonValue &game: aObject.value("games").toArray()) {
        for(const QJsonValue &achievement: game.toObject().value("achievements").toArray()) {
            QList<AchievementComment>::append(AchievementComment(achievement.toObject()));
        }
    }
    profileId_ = aObject.value("profileId").toString();
}

GameComments::GameComments(const ProfileID &aProfileId): FileSaveLoad(Paths::commentsGames(aProfileId)), profileId_(aProfileId) {
    load(filePath_);
}

GameComments::GameComments(const QJsonObject &aObject): FileSaveLoad(Paths::commentsGames("")) {
    fromJson(aObject);
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
    gamesObject["type"] = "GameComments";
    QJsonArray games;
    for(const GameComment &game: *this) {
        games.append(game.toJson());
    }
    gamesObject["games"] = games;
    return gamesObject;
}

void GameComments::update() {
    load(filePath_);
}

void GameComments::fromJson(const QJsonObject &aObject) {
    for(const QJsonValue &game: aObject.value("games").toArray()) {
        QList<GameComment>::append(GameComment(game.toObject()));
    }
}
