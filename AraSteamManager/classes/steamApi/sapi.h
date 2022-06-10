#ifndef SAPI_H
#define SAPI_H

#include "classes/network/requestimage.h"

QImage loadImage(QImage &image, const QString &url, const QString &savePath, const QSize &size);
QImage loadImage(const QString &url, const QString &savePath, const QSize &size);

typedef QString ProfileID;
typedef QStringList ProfileIDs;
typedef QString AchievementID;
typedef int GameID;

class Sapi : public QObject {
    Q_OBJECT
public:
    explicit Sapi(QObject *parent = nullptr);
    Sapi(const Sapi &api);
    ~Sapi();

    virtual QJsonObject toJson() const = 0;
    virtual QString className() const = 0;
    QString toString() const;

    friend QDebug operator<<(QDebug dbg, const Sapi &a) {
        dbg.nospace() << a.className() << "(" << a.toString() << ")\n";
        return dbg.space();
    }
    static QString gameImageUrl(const GameID &aAppId, const QString &img_id);

signals:

protected:
    static QString frameProfileUrl(const QString &aАFrameId);

    static QUrl achievementsSchemaUrl(const GameID &appId);
    static QUrl achievementsPlayerUrl(const GameID &appId, const ProfileID &steamId);
    static QUrl achievementsPercentUrl(const GameID &appId);
    static QUrl bansUrl(const QString &steamIds);
    static QUrl friendsUrl(const ProfileID &steamId);
    static QUrl profileUrl(const ProfileID &steamId);
    static QUrl profileUrl(const ProfileIDs &steamIds);
    static QUrl profilefromVanityUrl(const ProfileID &steamId);
    static QUrl avatarFrameUrl(const ProfileID &aSteamId);
    static QUrl avatarAnimationUrl(const ProfileID &aSteamId);
    static QUrl gameUrl(const int &freeGames, const int &gameInfo, const ProfileID &steamId);
    static QUrl numberPlayersUrl(const GameID &appId);
    static QUrl lvlUrl(const ProfileID &steamId);
    static QUrl profileCustomizationsUrl(const ProfileID &aSteamId);
    static QUrl profileEquippedItemUrl(const ProfileID &aSteamId);
    static QUrl badgesUrl(const ProfileID &aSteamId);
    template <typename T>
    static QList<T> load(const QUrl &url, std::function<QList<T>(const QByteArray&)> onLoad, std::function<void(QList<T>)> callback = nullptr) {
        RequestData *request = new RequestData();
        request->get(url, callback != nullptr);

        if (callback == nullptr) {
            QByteArray ba = request->reply();
            delete request;
            return onLoad(ba);
        } else {
            connect(request,
                    &RequestData::s_finished,
                    [=](RequestData *requestL) {
                        QByteArray ba = requestL->reply();
                        requestL->deleteLater();
                        callback(onLoad(ba));
                    });
        }
        return QList<T>();
    }

private:
    static const QString key_;
};


#endif // SAPI_H
