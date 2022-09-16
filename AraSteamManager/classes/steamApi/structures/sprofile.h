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
    static SProfile load(const ProfileID &profileId, const LoadType &type = LoadType::id, std::function<void (const SProfile &)> callback = nullptr);
    static QList<SProfile> load(ProfileIDs profileIds, std::function< void(QList<SProfile>) > callback = nullptr);
    static int getLevel(const ProfileID &profileId);
    static QPixmap getFrameProfile(const ProfileID &profileId);
    static QMap<QString, SProfileEquippedItem> getEquippedItems(const ProfileID &profileId);

    QPixmap pixmapAvatar() const;
    QPixmap pixmapAvatarMedium() const;
    QPixmap pixmapAvatarFull() const;

    QPixmap getAvatarWithFrame(const QSize &size) const;

    bool isNull() const;

    QColor stateColor() const;
    QString stateText() const;
    QString stateFullText() const;

    QString avatarUrl()             const;
    QString avatarMediumUrl()       const;
    QString avatarFullUrl()         const;

    ProfileID steamId()             const;
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
    static QPixmap pixmapAvatar(const QString &iconPath);
private slots:
    void fromJson(const QJsonValue &value);
    static SProfile loadVanity(const ProfileID &profileId, std::function<void (SProfile)> callback = nullptr);
    static SProfile loadId(const ProfileID &profileId, std::function<void (SProfile)> callback = nullptr);

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

    mutable QImage pixmapAvatar_;
    mutable QImage pixmapAvatarMedium_;
    mutable QImage pixmapAvatarFull_;

};

SProfile::LoadType identifyProfileType(QString &aId);

using SProfiles = QList<SProfile>;

#endif // SPROFILE_H
