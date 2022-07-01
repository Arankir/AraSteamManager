#ifndef SPROFILE_H
#define SPROFILE_H

#include "../sapi.h"
#include "./sgames.h"

struct SProfileEquippedItem {
    SProfileEquippedItem();
    SProfileEquippedItem(const QJsonObject &aObject);

    QString communityitemid;
    QString image_large;
    QString name;
    QString item_title;
    QString item_description;
    GameID appid;
    int item_type;
    int item_class;

    QJsonObject toJson() const;
    void fromJson(const QJsonObject &aObject);
};

const double c_frameLargerBy = 1.22;

class SProfile : public Sapi {
    Q_OBJECT
public:
    enum class LoadType {
        id,
        vanity,
        unknown
    };

    SProfile(const QJsonObject &profile = QJsonObject(), QObject *parent = nullptr);
    SProfile(const SProfile &profile);

    SProfile &operator=(const SProfile &profile);
    bool operator<(const SProfile &profile) const;
    bool operator>(const SProfile &profile) const;
    bool operator==(const SProfile &profile) const;
    bool operator!=(const SProfile &profile) const;

    SProfile &update();
    QJsonObject toJson() const;
    virtual QString className() const {return "SProfile";}
    static SProfile load(const ProfileID &aId, const LoadType &aType = LoadType::id, std::function<void (const SProfile &)> aCallback = nullptr);
    static QList<SProfile> load(ProfileIDs ids, std::function< void(QList<SProfile>) > callback = nullptr);
    static int getLevel(const ProfileID &aSteamId);
    static QPixmap getFrameProfile(const ProfileID &aSteamId);
    static QMap<QString, SProfileEquippedItem> getEquippedItems(const ProfileID &aSteamId);

    QPixmap pixmapAvatar() const;
    QPixmap pixmapAvatarMedium() const;
    QPixmap pixmapAvatarFull() const;

    QPixmap getAvatarWithFrame(const QSize &aSize) const;

    bool isNull() const;

    QColor stateColor() const;
    QString stateText() const;
    QString stateFullText() const;

    QString avatarUrl()             const;
    QString avatarMediumUrl()       const;
    QString avatarFullUrl()         const;

    ProfileID steamID()             const;
    int communityVisibilityState()  const;
    int profileState()              const;
    QString personaName()           const;
    QDateTime lastLogoff()          const;
    int commentPermission()         const;
    QString profileUrl()            const;
    int personaState()              const;
    QString primaryClanID()         const;
    QDateTime timeCreated()         const;
    int personaStateFlags()         const;
    QString gameExtraInfo()         const;
    GameID gameID()                 const;
    QString locCountryCode()        const;
    QString locStateCode()          const;
    int locCityID()                 const;
    QString realName()              const;

    static QStringList statesList();
private slots:
    void fromJson(const QJsonValue &value);
    static SProfile loadVanity(const ProfileID &aId, std::function<void (SProfile)> aCallback = nullptr);
    static SProfile loadId(const ProfileID &aId, std::function<void (SProfile)> aCallback = nullptr);

private:
    ProfileID steamId_ = "";
    int communityVisibilityState_ = 0;
    int profileState_ = 0;
    QString personaName_;
    QDateTime lastLogoff_;
    int commentPermission_ = 0;
    QString profileUrl_;
    int personaState_ = 0;
    QString primaryClanId_;
    QDateTime timeCreated_;
    int personaStateFlags_ = 0;
    QString gameExtraInfo_;
    QString gameId_;
    QString locCountryCode_;
    QString locStateCode_;
    int locCityId_ = 0;
    QString realName_;

    QString avatar_;
    QString avatarMedium_;
    QString avatarFull_;

    mutable QImage _pixmapAvatar;
    mutable QImage _pixmapAvatarMedium;
    mutable QImage _pixmapAvatarFull;

};

using SProfiles = QList<SProfile>;

#endif // SPROFILE_H
