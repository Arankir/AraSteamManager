#ifndef COMMENTS_H
#define COMMENTS_H

#include "classes/steamApi/structures/sgames.h"

class AchievementComment {
public:
    AchievementComment(QString profileId, QString gameId, QString achievementId, QStringList comment) : _profileId(profileId), _gameId(gameId), _achievementId(achievementId),
    _comment(comment) {};
    AchievementComment(const QJsonObject &object);

    AchievementComment &changeComment(const QStringList &comment);

    QJsonObject toJson()        const;
    QString getProfileId()      const {return _profileId;}
    QString getGameId()         const {return _gameId;}
    QString getAchievementId()  const {return _achievementId;}
    QStringList getComment()    const {return _comment;}

private:
    void fromJson(const QJsonObject &object);

    QString _profileId;
    QString _gameId;
    QString _achievementId;
    QStringList _comment;

};

class GameComment {
public:
    GameComment(QString gameId, QString profileId, QStringList comment) : _gameId(gameId), _profileId(profileId), _comment(comment) {};
    GameComment(const QJsonObject &object);

    GameComment &changeComment(const QStringList &comment);

    QJsonObject toJson()        const;
    QString getProfileId()      const {return _profileId;}
    QString getGameId()         const {return _gameId;}
    QStringList getComment()    const {return _comment;}

private:
    void fromJson(const QJsonObject &object);

    QString _gameId;
    QString _profileId;
    QStringList _comment;

};

class Comments {
public:
    Comments(const QString &profileId = "");

    Comments &setProfileId(const QString &profileId);
    Comments &setGameComment(const QString &gameId, const QString &profileId, const QStringList &comment);
    Comments &setAchievementComment(const QString &profileId, const QString &gameId, const QString &achievementId, const QStringList &comment);
    Comments &removeGameComment(const QString &gameId, const QString &profileId);
    Comments &removeAchievementComment(const QString &profileId, const QString &gameId, const QString &achievementId);
    const GameComment &getGameComment(const QString &gameId, const QString &profileId) const;
    const AchievementComment &getAchievementComment(const QString &profileId, const QString &gameId, const QString &achievementId) const;
    Comments &save();
    Comments &load();

private:
    void saveFile(const QString &aProfileId, const QJsonObject &aObject);

    QString _profileId;
    QList<GameComment> _games;
    QList<QPair<QString, QList<AchievementComment>>> _achievements;

};

#endif // COMMENTS_H
