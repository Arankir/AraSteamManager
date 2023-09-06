#ifndef SACHIEVEMENTS_H
#define SACHIEVEMENTS_H

#include "../sapi.h"
#include "./sgames.h"

class SAchievementSchema : public Sapi {
    Q_OBJECT
public:
    SAchievementSchema(QObject *parent  = nullptr);
    SAchievementSchema(const QJsonObject &object, QObject *parent  = nullptr);
    SAchievementSchema(const SAchievementSchema&);
    SAchievementSchema &operator=(const SAchievementSchema&);
    bool  operator<(const SAchievementSchema&) const;
    bool  operator>(const SAchievementSchema&) const;
    bool  operator==(const SAchievementSchema&) const;
    bool  operator!=(const SAchievementSchema&) const;
     
    QJsonObject toJson() const;
    static QList<SAchievementSchema> load(const GameID &gameId, std::function<void (QList<SAchievementSchema>)> callback = nullptr);

    QPixmap icon     (GameID gameId)const;
    QPixmap iconGray (GameID gameId)const;
    AchievementID  apiName()        const;
    int            defaultValue()   const;
    QString        displayName()    const;
    int            hidden()         const;
    QString        description()    const;
    QString        icon()           const;
    QString        iconGray()       const;

    void fromJson(const QJsonObject &aObject);
    static QPixmap icon(const GameID &gameId, const QString &iconPath, const QSize &aSize = QSize(64, 64));
private:
    AchievementID   apiName_;
    int             defaultValue_;
    QString         displayName_;
    int             hidden_;
    QString         description_;
    QString         icon_;
    QString         iconGray_;

    mutable QImage  pixmapIcon_;
    mutable QImage  pixmapIconGray_;

};
class SAchievementPercentage : public Sapi {
    Q_OBJECT
public:
    SAchievementPercentage(QObject *parent = nullptr);
    SAchievementPercentage(const QJsonObject &achievement, QObject *parent = nullptr);
    SAchievementPercentage(const SAchievementPercentage&);
    SAchievementPercentage &operator=(const SAchievementPercentage&);
    bool  operator<(const SAchievementPercentage&) const;
    bool  operator>(const SAchievementPercentage&) const;
    bool  operator==(const SAchievementPercentage&) const;
    bool  operator!=(const SAchievementPercentage&) const;

    QJsonObject toJson() const;
    static QList<SAchievementPercentage> load(const GameID &gameId, std::function<void (QList<SAchievementPercentage>)> callback = nullptr);

    AchievementID apiName() const;
    double percent() const;

    void fromJson(const QJsonObject &object);
private:
    AchievementID   apiName_;
    double          percent_;

};
class SAchievementPlayer : public Sapi {
    Q_OBJECT
public:
    SAchievementPlayer(QObject *parent = nullptr);
    SAchievementPlayer(const QJsonObject &achievement, QObject *parent = nullptr);
    SAchievementPlayer(const QString &error, QObject *parent = nullptr);
    SAchievementPlayer(const SAchievementPlayer&);
    SAchievementPlayer &operator=(const SAchievementPlayer&);
    bool  operator<(const SAchievementPlayer&) const;
    bool  operator>(const SAchievementPlayer&) const;
    bool  operator==(const SAchievementPlayer&) const;
    bool  operator!=(const SAchievementPlayer&) const;

    QJsonObject toJson() const;
    static int countAchieved(const QList<SAchievementPlayer>&);

    AchievementID apiName() const;
    int achieved() const;
    QDateTime unlockTime() const;

    const QString &error() const;

    void fromJson(const QJsonObject &object);
private:
    AchievementID   apiName_ = "";
    int             achieved_ = -1;
    QDateTime       unlockTime_;
    QString         error_;

};

class SAchievementsPlayer : public Sapi, public QList<SAchievementPlayer> {
    Q_OBJECT
public:
    SAchievementsPlayer(const GameID &gameid, const ProfileID &profileId, QObject *parent = nullptr);
    SAchievementsPlayer(const QJsonObject &achievement = QJsonObject(), QObject *parent = nullptr);
    SAchievementsPlayer(const SAchievementsPlayer&);
    SAchievementsPlayer &operator=(const SAchievementsPlayer&);
    bool  operator<(const SAchievementsPlayer&) const;
    bool  operator>(const SAchievementsPlayer&) const;
    bool  operator==(const SAchievementsPlayer&) const;
    bool  operator!=(const SAchievementsPlayer&) const;

    QJsonObject toJson() const;
    void update(const ProfileID &profileId);

    const QString &error() const;
    bool success() const;

    static SAchievementsPlayer load(const GameID &gameId, const ProfileID &profileId, std::function<void (SAchievementsPlayer)> callback = nullptr);

private:
    void fromJson(const QJsonObject &object);

    GameID gameId_;
    ProfileID profileId_;

    bool success_;
    QString error_;
};

using SAchievementsSchema = QList<SAchievementSchema>;
using SAchievementsPercentage = QList<SAchievementPercentage>;

class SAchievement : public Sapi {
    Q_OBJECT
public:
    SAchievement(const SAchievementSchema &aSchema, const SAchievementPlayer &aPlayer, const SAchievementPercentage &aPercent, QObject *aParent = nullptr):
        Sapi(aParent), schema_(aSchema), percentage_(aPercent), player_(aPlayer) {
        //    qDebug() << "SAchievement constructor" << apiName();
    }
    SAchievement(const SAchievement&);
    SAchievement(const QJsonObject &object = QJsonObject(), QObject *parent = nullptr);
    SAchievement(const QVariant &text, QObject *parent = nullptr);
    ~SAchievement();
    SAchievement &operator=(const SAchievement&);
    bool          operator<(const SAchievement&) const;
    bool          operator>(const SAchievement&) const;
    bool          operator==(const SAchievement&) const;
    bool          operator!=(const SAchievement&) const;
    friend QDataStream &operator<<(QDataStream &stream, const SAchievement &achievement) {
        stream << achievement.toJson();
        return stream;
    }

    friend QDataStream &operator>>(QDataStream &stream, SAchievement &achievement) {
        QJsonObject obj;
        stream >> obj;
        achievement.fromJson(obj);
        return stream;
    }

    bool isValid() const;
    QJsonObject toJson() const;

    QPixmap         icon     (GameID gameId)const;
    QPixmap         iconGray (GameID gameId)const;
    AchievementID   apiName()               const;
    int             defaultValue()          const;
    QString         displayName()           const;
    int             hidden()                const;
    QString         description()           const;
    int             achieved()              const;
    QDateTime       unlockTime()            const;
    double          percent()               const;
    QString         iconPath()              const;
    QString         iconGrayPath()          const;

    void fromJson(const QJsonObject &object);
private:
    SAchievementSchema schema_;
    SAchievementPercentage percentage_;
    SAchievementPlayer player_;
};
Q_DECLARE_METATYPE(SAchievement);
typedef SAchievement *SAchievementRef;
Q_DECLARE_METATYPE(SAchievementRef);

using SAchievements = QList<SAchievement>;

#endif // SACHIEVEMENTS_H
