#ifndef SPROFILE_H
#define SPROFILE_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QTcpSocket>
#include <QEventLoop>
#include <class/settings.h>
#include <class/statusvalue.h>
#include <class/Network/requestimage.h>
#include <QObject>

enum class ProfileUrlType {
    id,
    vanity
};

class SProfile : public QObject {
    Q_OBJECT
public:
    SProfile(QJsonObject profile = QJsonObject(), QObject *parent = nullptr);
    ~SProfile();

    /*const*/ QString _steamID;
    int _communityVisibilityState;
    int _profileState;
    QString _personaName;
    QDateTime _lastLogoff;
    int _commentPermission;
    QString _profileUrl;
    QString _avatar;
    QString _avatarMedium;
    QString _avatarFull;
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

    int _unicIndex = -1;

    void update(bool parallel);

    QPixmap getPixmapAvatar(QString savePath);
    QPixmap getPixmapAvatarMedium(QString savePath);
    QPixmap getPixmapAvatarFull(QString savePath);

    SProfile(const SProfile &profile);
    SProfile &operator=(const SProfile &profile);
    const bool &operator<(const SProfile &profile);

signals:
    void s_finished(SProfile*);
    void s_finished();

private slots:
    void loadURL(RequestData *request);
    void loading(bool parallel);
    void set(QJsonObject ObjSummaries);

private:
    QPixmap _pixmapAvatar;
    QPixmap _pixmapAvatarMedium;
    QPixmap _pixmapAvatarFull;

};

class SProfiles : public QObject {
    Q_OBJECT
public slots:
    void loadURL(RequestData *request);
    void loadVanity(RequestData *request);

public:
    explicit SProfiles(QString id, bool parallel, ProfileUrlType type, QObject *parent = nullptr);
    SProfiles(QJsonDocument docSummaries, QObject *parent = nullptr);
    SProfiles(QJsonArray arrSummaries, QObject *parent = nullptr);
    SProfiles(QJsonObject objSummaries, QObject *parent = nullptr);
    SProfiles(QObject *parent = nullptr);
    ~SProfiles();
    void set(QString id, bool parallel, ProfileUrlType type);
    void set(QJsonDocument docSummaries);
    void set(QJsonArray arrSummaries);
    void set(QJsonObject objSummaries);
    QString getSteamid(int index = 0);
    int getCommunityvisibilitystate(int index = 0);
    int getProfilestate(int index = 0);
    QString getPersonaname(int index = 0) const;
    QDateTime getLastlogoff(int index = 0);
    int getCommentpermission(int index = 0);
    QString getProfileurl(int index = 0);
    QString getAvatar(int index = 0);
    QString getAvatarmedium(int index = 0);
    QString getAvatarfull(int index = 0);
    int getPersonastate(int index = 0);
    QString getPrimaryclanid(int index = 0);
    QDateTime getTimecreated(int index = 0);
    int getPersonastateflags(int index = 0);
    QString getGameextrainfo(int index = 0);
    QString getGameid(int index = 0);
    QString getLoccountrycode(int index = 0);
    QString getLocstatecode(int index = 0);
    int getLoccityid(int index = 0);
    QString getRealname(int index = 0);
    SProfile getProfile(int index);
    StatusValue getStatus();
    QString getError();
    int getCount();
    void update(bool parallel);
    void sort();
    void clear();
    SProfiles(const SProfiles &profile);;
    SProfiles &operator=(const SProfiles &profile);
    SProfile &operator[](const int &index);
    QList<SProfile>::iterator begin() {return _profile.begin();}
    QList<SProfile>::iterator end() {return _profile.end();}

    int _unicIndex=-1;

signals:
    void s_finished(SProfiles*);
    void s_finished();

private slots:
    void load(bool parallel, ProfileUrlType type);

private:
    RequestData *_request;
    QList<SProfile> _profile;
    StatusValue _status = StatusValue::none;
    QString _error = "";
    QString _id = "";
};

#endif // SPROFILE_H
