#ifndef COMMENTS_H
#define COMMENTS_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/common/generalfunctions.h"

class Comment {
public:
    virtual QJsonObject toJson()    const = 0;
    QString profileId()             const {return _profileId;}
    QStringList comment()           const {return _comment;}

    void changeComment(const QStringList &comment);

protected:
    Comment() {};
    explicit Comment(const QString &profileId, const QStringList &comment): _profileId(profileId), _comment(comment) {};
    virtual ~Comment() {};

    virtual void fromJson(const QJsonObject &object) = 0;

    QString _profileId;
    QStringList _comment;
};

class AchievementComment: public Comment {
public:
    explicit AchievementComment(const QString &profileId, const QString &gameId, const QString &achievementId, const QStringList &comment):
        Comment(profileId, comment), _gameId(gameId), _achievementId(achievementId) {};
    explicit AchievementComment(const QJsonObject &object);
    ~AchievementComment() {};

    bool operator==(const AchievementComment &comment) const;

    QJsonObject toJson()    const;
    QString gameId()        const {return _gameId;}
    QString achievementId() const {return _achievementId;}

    static QList<QPair<QString, QList<AchievementComment> > > load(const QString &profileId);
    static QList<AchievementComment> load(const QString &profileId, const QString &gameId);
    static bool save(const QString &profileId, const QString &gameId, const AchievementComment &comments);
    static bool save(const QString &profileId, const QString &gameId, const QList<AchievementComment> &comments);
    static bool save(const QString &profileId, QList<QPair<QString, QList<AchievementComment> > > &comments);

private:
    void fromJson(const QJsonObject &object);

    QString _gameId;
    QString _achievementId;

};

class GameComment: public Comment {
public:
    explicit GameComment(const QString &gameId, const QString &profileId, const QStringList &comment): Comment(profileId, comment), _gameId(gameId) {};
    explicit GameComment(const QJsonObject &object);
    ~GameComment() {};

    QJsonObject toJson()    const;
    QString gameId()        const {return _gameId;}

    static QList<GameComment> load(const QString &profileId);
    static bool save(const QString &profileId, const QList<GameComment> &comments);
    static bool save(const QString &profileId, const GameComment &comments);

private:
    void fromJson(const QJsonObject &object);

    QString _gameId;
};

class Comments {
public:
    explicit Comments(const QString &profileId = "");

    Comments &setProfileId(const QString &profileId);
    Comments &setGameComment(const QString &gameId, const QString &profileId, const QStringList &comment);
    Comments &setAchievementComment(const QString &profileId, const QString &gameId, const QString &achievementId, const QStringList &comment);
    Comments &removeGameComment(const QString &gameId, const QString &profileId);
    Comments &removeAchievementComment(const QString &profileId, const QString &gameId, const QString &achievementId);
    const GameComment getGameComment(const QString &gameId) const;
    const AchievementComment getAchievementComment(const QString &profileId, const QString &gameId, const QString &achievementId) const;
    bool saveGames() const;
    bool saveAchievements() const;
    bool save() const;
    Comments &load();

private:
    QString _profileId;
    QList<GameComment> _games;
    QList<QPair<QString, QList<AchievementComment>>> _achievements;

    QList<QPair<QString, QList<AchievementComment> > >::iterator findAchievementComment(const QString &aGameId);
    QList<QPair<QString, QList<AchievementComment> > >::const_iterator findAchievementComment(const QString &aGameId) const;
    QList<GameComment>::iterator findGameComment(const QString &aGameId, const QString &aProfileId);
    QList<GameComment>::const_iterator findGameComment(const QString &aGameId, const QString &aProfileId) const;
};

#endif // COMMENTS_H
