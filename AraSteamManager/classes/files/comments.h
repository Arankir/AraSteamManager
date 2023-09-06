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
    explicit AchievementComment(const ProfileID &profileId, const GameID &gameId, const QString &gameName, const QString &gameIcon, const AchievementID &achievementId, const QString &title, const QString &icon, const QStringList &comment);
    explicit AchievementComment(const QJsonObject &object = QJsonObject());
    ~AchievementComment();

    bool operator==(const AchievementComment &comment) const;

    void fromJson(const QJsonObject &object);
    QJsonObject toJson()            const;

    GameID gameId()                 const;
    QString gameName()              const;
    QPixmap gameIcon()              const;
    AchievementID achievementId()   const;
    QString title()                 const;
    QString icon()                  const;

private:
    GameID gameId_;
    QString gameName_;
    QString gameIcon_;
    AchievementID achievementId_;
    QString title_;
    QString icon_;

    mutable QImage gameIconPixmap_;
};

class AchievementComments: public QList<AchievementComment>, public FileSaveLoad {
public:
    AchievementComments(const ProfileID &profileId);
    explicit AchievementComments(const QJsonObject &object);

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
    explicit GameComment(const GameID &gameId, const QString &gameName, const QString &gameIcon, const ProfileID &profileId, const QStringList &comment);
    explicit GameComment(const QJsonObject &object = QJsonObject());
    ~GameComment();

    void fromJson(const QJsonObject &object);
    QJsonObject toJson()    const;

    GameID gameId()         const;
    QString gameName()      const;
    QPixmap gameIcon()      const;

private:

    GameID gameId_;
    QString gameName_;
    QString gameIcon_;

    mutable QImage gameIconPixmap_;
};

class GameComments: public QList<GameComment>, public FileSaveLoad {
public:
    GameComments(const ProfileID &profileId);
    explicit GameComments(const QJsonObject &object);

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
