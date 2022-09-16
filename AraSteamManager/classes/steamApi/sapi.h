#ifndef SAPI_H
#define SAPI_H

#include "classes/network/requestimage.h"

QImage loadImage(QImage &image, const QString &url, const QString &savePath, const QSize &size);
QImage loadImage(const QString &url, const QString &savePath, const QSize &size);

typedef QString ProfileID;
typedef QStringList ProfileIDs;
typedef QString AchievementID;
typedef int GameID;

static QString gameImageUrl(const GameID &appId, const QString &imgId);

class Sapi : public QObject {
    Q_OBJECT
public:
    explicit Sapi(QObject *parent = nullptr);
    Sapi(const Sapi &api);
    ~Sapi();

    virtual QJsonObject toJson() const = 0;
    virtual QString className() const {
        return typeid(this).name();
    }
    QString toString() const;

    friend QDebug operator<<(QDebug dbg, const Sapi &steam) {
        dbg.nospace() << steam.className() << "(" << steam.toString() << ")\n";
        return dbg.space();
    }
    static QString gameImageUrl(const GameID &appId, const QString &imgId);

signals:

protected:
    static QString frameProfileUrl(const QString &frameId);

    static QUrl achievementsSchemaUrl(const GameID &appId);
    static QUrl achievementsPlayerUrl(const GameID &appId, const ProfileID &profileId);
    static QUrl achievementsPercentUrl(const GameID &appId);
    static QUrl bansUrl(const QString &profileIds);
    static QUrl friendsUrl(const ProfileID &profileId);
    static QUrl profileUrl(const ProfileID &profileId);
    static QUrl profileUrl(const ProfileIDs &profileIds);
    static QUrl profilefromVanityUrl(const ProfileID &profileId);
    static QUrl avatarFrameUrl(const ProfileID &profileId);
    static QUrl avatarAnimationUrl(const ProfileID &profileId);
    static QUrl gameUrl(const int &freeGames, const int &gameInfo, const ProfileID &profileId);
    static QUrl numberPlayersUrl(const GameID &appId);
    static QUrl lvlUrl(const ProfileID &profileId);
    static QUrl profileCustomizationsUrl(const ProfileID &profileId);
    static QUrl profileEquippedItemUrl(const ProfileID &profileId);
    static QUrl badgesUrl(const ProfileID &profileId);
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
