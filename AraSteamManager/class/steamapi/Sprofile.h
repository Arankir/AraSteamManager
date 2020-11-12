#ifndef SPROFILE_H
#define SPROFILE_H

#include "class/steamapi/Sapi.h"

enum class ProfileUrlType {
    id,
    vanity
};

class SProfile : public Sapi {
    Q_OBJECT
public:
    SProfile(const QJsonObject &profile, QObject *parent = nullptr);
    SProfile(QObject *parent = nullptr): SProfile(QJsonObject(), parent) {}
    SProfile(const SProfile &profile): Sapi(profile.parent()), _steamID(profile._steamID), _communityVisibilityState(profile._communityVisibilityState),
        _profileState(profile._profileState), _personaName(profile._personaName), _lastLogoff(profile._lastLogoff), _commentPermission(profile._commentPermission),
        _profileUrl(profile._profileUrl), _personaState(profile._personaState), _primaryClanID(profile._primaryClanID), _timeCreated(profile._timeCreated),
        _personaStateFlags(profile._personaStateFlags), _gameExtraInfo(profile._gameExtraInfo), _gameID(profile._gameID), _locCountryCode(profile._locCountryCode),
        _locStateCode(profile._locStateCode), _locCityID(profile._locCityID), _realName(profile._realName), _avatar(profile._avatar), _avatarMedium(profile._avatarMedium),
        _avatarFull(profile._avatarFull), _pixmapAvatar(profile._pixmapAvatar), _pixmapAvatarMedium(profile._pixmapAvatarMedium), _pixmapAvatarFull(profile._pixmapAvatarFull) {}
    ~SProfile() {}

    SProfile &  operator=(const SProfile &profile);
    bool        operator<(const SProfile &profile);

    SProfile &update(bool parallel);

    QPixmap getPixmapAvatar();
    QPixmap getPixmapAvatarMedium();
    QPixmap getPixmapAvatarFull();

    /*const*/ QString _steamID = "";
    int _communityVisibilityState;
    int _profileState;
    QString _personaName;
    QDateTime _lastLogoff;
    int _commentPermission;
    QString _profileUrl;
    int _personaState;
    QString _primaryClanID;
    /*const*/ QDateTime _timeCreated;
    int _personaStateFlags;
    QString _gameExtraInfo;
    QString _gameID;
    QString _locCountryCode;
    QString _locStateCode;
    int _locCityID;
    QString _realName;

signals:
    void s_finished(SProfile*);
    void s_finished();

private slots:
    void load(bool parallel);
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QString _avatar;
    QString _avatarMedium;
    QString _avatarFull;

    QPixmap _pixmapAvatar;
    QPixmap _pixmapAvatarMedium;
    QPixmap _pixmapAvatarFull;

};

class SProfiles : public Sapi {
    Q_OBJECT
public:
    explicit SProfiles(const QStringList &ids, bool parallel, ProfileUrlType type, QObject *parent = nullptr);
    explicit SProfiles(const QString &id, bool parallel, ProfileUrlType type, QObject *parent = nullptr): SProfiles(QStringList() << id, parallel, type, parent) {}
    SProfiles(const QJsonArray &arrSummaries, QObject *parent = nullptr);
    SProfiles(const QJsonObject &profile, QObject *parent = nullptr): SProfiles(QJsonArray() << profile, parent) {}
    SProfiles(const SProfiles &profile): Sapi(profile.parent()), _profile(profile._profile), _ids(profile._ids) {}
    SProfiles(QObject *parent = nullptr): Sapi(parent) {}
    ~SProfiles() {}

    SProfiles &operator=(const SProfiles &profile);
    SProfile &operator[](const int &index) {return _profile[index];}

    SProfiles &load(QStringList ids, bool parallel, ProfileUrlType type);
    SProfiles &add(const QJsonArray &arrSummaries);
    SProfiles &update(bool parallel);
    SProfiles &sort();
    SProfiles &clear();

    QList<SProfile>::iterator begin() {return _profile.begin();}
    QList<SProfile>::iterator end() {return _profile.end();}
    int getCount() const {return _profile.size();}

signals:
    void s_finished(SProfiles*);
    void s_finished();

private slots:
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QList<SProfile> _profile;
    ProfileUrlType _type;
    QStringList _ids;
};

#endif // SPROFILE_H
