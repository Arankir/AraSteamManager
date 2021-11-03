#ifndef SPROFILE_H
#define SPROFILE_H

#include "../sapi.h"

class SProfile : public Sapi {
    Q_OBJECT
public:
    enum class LoadType {
        id,
        vanity
    };

    SProfile(const QJsonObject &profile, QObject *parent = nullptr);
    SProfile(QObject *parent = nullptr): SProfile(QJsonObject(), parent) {}
    SProfile(const SProfile &profile): Sapi(profile.parent()), _steamID(profile._steamID), _communityVisibilityState(profile._communityVisibilityState),
        _profileState(profile._profileState), _personaName(profile._personaName), _lastLogoff(profile._lastLogoff), _commentPermission(profile._commentPermission),
        _profileUrl(profile._profileUrl), _personaState(profile._personaState), _primaryClanID(profile._primaryClanID), _timeCreated(profile._timeCreated),
        _personaStateFlags(profile._personaStateFlags), _gameExtraInfo(profile._gameExtraInfo), _gameID(profile._gameID), _locCountryCode(profile._locCountryCode),
        _locStateCode(profile._locStateCode), _locCityID(profile._locCityID), _realName(profile._realName), _avatar(profile._avatar), _avatarMedium(profile._avatarMedium),
        _avatarFull(profile._avatarFull)/*, _pixmapAvatar(profile._pixmapAvatar), _pixmapAvatarMedium(profile._pixmapAvatarMedium), _pixmapAvatarFull(profile._pixmapAvatarFull)*/ {}
    ~SProfile() {}

    SProfile &operator=(const SProfile &profile);
    bool operator<(const SProfile &profile) const;
    bool operator>(const SProfile &profile) const;
    bool operator==(const SProfile &profile) const;
    bool operator!=(const SProfile &profile) const;

    SProfile &update();
    QJsonObject toJson() const;
    virtual QString className() const {return "SProfile";}
    static SProfile load(const ProfileID &aId, const LoadType &aType, std::function<void (SProfile)> aCallback = nullptr);
    static QList<SProfile> load(ProfileIDs ids, std::function< void(QList<SProfile>) > callback = nullptr);
    static int getLevel(const ProfileID &aSteamId);

    QPixmap pixmapAvatar() const;
    QPixmap pixmapAvatarMedium() const;
    QPixmap pixmapAvatarFull() const;

    bool isNull() const;

    QColor stateColor() const;
    QString stateText() const;
    QString stateFullText() const;

    ProfileID steamID()             const {return _steamID;}
    int communityVisibilityState()  const {return _communityVisibilityState;}
    int profileState()              const {return _profileState;}
    QString personaName()           const {return _personaName;}
    QDateTime lastLogoff()          const {return _lastLogoff;}
    int commentPermission()         const {return _commentPermission;}
    QString profileUrl()            const {return _profileUrl;}
    int personaState()              const {return _personaState;}
    QString primaryClanID()         const {return _primaryClanID;}
    QDateTime timeCreated()         const {return _timeCreated;}
    int personaStateFlags()         const {return _personaStateFlags;}
    QString gameExtraInfo()         const {return _gameExtraInfo;}
    GameID gameID()                 const {return _gameID.toInt();}
    QString locCountryCode()        const {return _locCountryCode;}
    QString locStateCode()          const {return _locStateCode;}
    int locCityID()                 const {return _locCityID;}
    QString realName()              const {return _realName;}

private slots:
    void fromJson(const QJsonValue &value);
    static SProfile loadVanity(const ProfileID &aId, std::function<void (SProfile)> aCallback = nullptr);
    static SProfile loadId(const ProfileID &aId, std::function<void (SProfile)> aCallback = nullptr);

private:
    ProfileID _steamID = "";
    int _communityVisibilityState = 0;
    int _profileState = 0;
    QString _personaName;
    QDateTime _lastLogoff;
    int _commentPermission = 0;
    QString _profileUrl;
    int _personaState = 0;
    QString _primaryClanID;
    QDateTime _timeCreated;
    int _personaStateFlags = 0;
    QString _gameExtraInfo;
    QString _gameID;
    QString _locCountryCode;
    QString _locStateCode;
    int _locCityID = 0;
    QString _realName;

    QString _avatar;
    QString _avatarMedium;
    QString _avatarFull;

    mutable QImage _pixmapAvatar;
    mutable QImage _pixmapAvatarMedium;
    mutable QImage _pixmapAvatarFull;

};

using SProfiles = QList<SProfile>;

#endif // SPROFILE_H
