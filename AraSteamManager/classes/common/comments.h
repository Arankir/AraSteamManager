#ifndef COMMENTS_H
#define COMMENTS_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/common/generalfunctions.h"

class Comment {
public:
    virtual QJsonObject toJson()    const = 0;
    ProfileID profileId()           const {return _profileId;}
    QStringList comment()           const {return _comment;}

    void changeComment(const QStringList &comment);

protected:
    Comment() {};
    explicit Comment(const ProfileID &profileId, const QStringList &comment): _profileId(profileId), _comment(comment) {};
    virtual ~Comment() {};

    virtual void fromJson(const QJsonObject &object) = 0;

    ProfileID _profileId;
    QStringList _comment;
};

class AchievementComment: public Comment {
public:
    explicit AchievementComment(const ProfileID &profileId, const GameID &gameId, const QString &achievementId, const QStringList &comment):
        Comment(profileId, comment), _gameId(gameId), _achievementId(achievementId) {};
    explicit AchievementComment(const QJsonObject &object);
    ~AchievementComment() {};

    bool operator==(const AchievementComment &comment) const;

    QJsonObject toJson()            const;
    GameID gameId()                 const {return _gameId;}
    AchievementID achievementId()   const {return _achievementId;}

    static QList<QPair<GameID, QList<AchievementComment> > > load(const ProfileID &profileId);
    static QList<AchievementComment> load(const ProfileID &profileId, const GameID &gameId);
    static bool save(const ProfileID &profileId, const GameID &gameId, const AchievementComment &comments);
    static bool save(const ProfileID &profileId, const GameID &gameId, const QList<AchievementComment> &comments);
    static bool save(const ProfileID &profileId, QList<QPair<GameID, QList<AchievementComment> > > &comments);

private:
    void fromJson(const QJsonObject &object);

    GameID _gameId;
    AchievementID _achievementId;

};

using AchievementGameComments = QPair<GameID, QList<AchievementComment>>;
using AchievementGamesComments = QList<AchievementGameComments>;

class GameComment: public Comment {
public:
    explicit GameComment(const GameID &gameId, const ProfileID &profileId, const QStringList &comment): Comment(profileId, comment), _gameId(gameId) {};
    explicit GameComment(const QJsonObject &object);
    ~GameComment() {};

    QJsonObject toJson()    const;
    GameID gameId()        const {return _gameId;}

    static QList<GameComment> load(const ProfileID &profileId);
    static bool save(const ProfileID &profileId, const QList<GameComment> &comments);
    static bool save(const ProfileID &profileId, const GameComment &comments);

private:
    void fromJson(const QJsonObject &object);

    GameID _gameId;
};

class Comments {
public:
    explicit Comments(const ProfileID &profileId = "");

    Comments &setProfileId(const ProfileID &profileId);
    Comments &setGameComment(const GameID &gameId, const ProfileID &profileId, const QStringList &comment);
    Comments &setAchievementComment(const ProfileID &profileId, const GameID &gameId, const AchievementID &achievementId, const QStringList &comment);
    Comments &removeGameComment(const GameID &gameId, const ProfileID &profileId);
    Comments &removeAchievementComment(const ProfileID &profileId, const GameID &gameId, const AchievementID &achievementId);
    const GameComment getGameComment(const GameID &gameId) const;
    const AchievementComment getAchievementComment(const ProfileID &profileId, const GameID &gameId, const AchievementID &achievementId) const;
    bool saveGames() const;
    bool saveAchievements() const;
    bool save() const;
    Comments &load();

private:
    QString _profileId;
    QList<GameComment> _games;
    AchievementGamesComments _achievements;

    AchievementGamesComments::iterator findAchievementComment(const GameID &aGameId);
    AchievementGamesComments::const_iterator findAchievementComment(const GameID &aGameId) const;
    QList<GameComment>::iterator findGameComment(const GameID &aGameId, const ProfileID &aProfileId);
    QList<GameComment>::const_iterator findGameComment(const GameID &aGameId, const ProfileID &aProfileId) const;
};

#endif // COMMENTS_H
