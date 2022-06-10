#ifndef COMMENTS_H
#define COMMENTS_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/common/filesaveload.h"

class Comment {
public:
    virtual QJsonObject toJson()    const = 0;
    ProfileID profileId()           const;
    QStringList comment()           const;

    void setComment(const QStringList &comment);

protected:
    explicit Comment(const ProfileID &profileId = ProfileID(), const QStringList &comment = QStringList());
    virtual ~Comment();

    virtual void fromJson(const QJsonObject &object) = 0;

    ProfileID profileId_;
    QStringList comment_;
};

class AchievementComment: public Comment {
public:
    explicit AchievementComment(const ProfileID &profileId, const GameID &gameId, const AchievementID &achievementId, const QStringList &comment);
    explicit AchievementComment(const QJsonObject &object);
    ~AchievementComment();

    bool operator==(const AchievementComment &comment) const;

    QJsonObject toJson()            const;
    GameID gameId()                 const;
    AchievementID achievementId()   const;

private:
    void fromJson(const QJsonObject &object);

    GameID gameId_;
    AchievementID achievementId_;

};

class AchievementComments: public QList<AchievementComment>, public FileSaveLoad {
public:
    AchievementComments(const ProfileID &profileId);

    QList<AchievementComment> getCommentsFromGame(const ProfileID &idUser, const GameID &gameId);
    void append(const AchievementComment&);
    void remove(const ProfileID &idUser, const GameID &gameId, const AchievementID &achievementId);
    void setComment(const ProfileID &idUser, const GameID &gameId, const QString &achievementId, const QStringList &comment);

    QJsonObject toJson() const override;
    void update();

private:
    void fromJson(const QJsonObject &object) override;
    ProfileID profileId_;
};

class GameComment: public Comment {
public:
    explicit GameComment(const GameID &gameId, const ProfileID &profileId, const QStringList &comment);
    explicit GameComment(const QJsonObject &object);
    ~GameComment();

    QJsonObject toJson()   const;
    GameID gameId()        const;

private:
    void fromJson(const QJsonObject &object);

    GameID gameId_;
};

class GameComments: public QList<GameComment>, public FileSaveLoad {
public:
    GameComments(const ProfileID &profileId);

    void append(const GameComment&);
    void remove(const ProfileID &idUser, const GameID &gameId);
    void setComment(const ProfileID &idUser, const GameID &gameId, const QStringList &comment);

    QJsonObject toJson() const override;
    void update();

private:
    void fromJson(const QJsonObject &object) override;
    ProfileID profileId_;
};

#endif // COMMENTS_H
