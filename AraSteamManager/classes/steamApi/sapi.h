#ifndef SAPI_H
#define SAPI_H

#include "classes/network/requestimage.h"

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include "classes/common/settings.h"

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
    virtual QString className() const;
    virtual QString toString() const;

    friend QDebug operator<<(QDebug dbg, const Sapi &steam) {
        dbg.nospace() << steam.className() << "(" << steam.toString() << ")\n";
        return dbg.space();
    }

    static QUrl gameImageUrl(const GameID &appId, const QString &imgId);
    static QUrl frameProfile(const QString &frameId);
protected:
    class Url {
    public:
        static QUrl achievementsSchema(const GameID &appId);
        static QUrl achievementsPlayer(const GameID &appId, const ProfileID &profileId);
        static QUrl achievementsPercent(const GameID &appId);
        static QUrl bans(const QString &profileIds);
        static QUrl friends(const ProfileID &profileId);
        static QUrl profile(const ProfileID &profileId);
        static QUrl profile(const ProfileIDs &profileIds);
        static QUrl profilefromVanity(const ProfileID &profileId);
        static QUrl avatarFrame(const ProfileID &profileId);
        static QUrl avatarAnimation(const ProfileID &profileId);
        static QUrl game(int freeGames, int gameInfo, const ProfileID &profileId);
        static QUrl numberPlayers(const GameID &appId);
        static QUrl lvl(const ProfileID &profileId);
        static QUrl profileCustomizations(const ProfileID &profileId);
        static QUrl profileEquippedItem(const ProfileID &profileId);
        static QUrl badges(const ProfileID &profileId);
    private:
        Url();
    };

    static QString pathToTempRawFile(const QUrl &aUrl);
    static bool saveRawLoadedData(const QUrl &aUrl, const QByteArray &aBytes);
    static bool checkRawLoadedData(const QUrl &aUrl);
    static QByteArray loadRawLoadedData(const QUrl &aUrl);

    template <typename T>
    static QList<T> load(const QUrl &url, std::function<QList<T>(const QByteArray&)> onLoad, std::function<void(QList<T>)> callback = nullptr) {
        if (checkRawLoadedData(url)) {
            QByteArray ba = loadRawLoadedData(url);
            if (callback == nullptr) {
                return onLoad(ba);
            } else {
                callback(onLoad(ba));
                return {};
            }
        }
        RequestData *request = new RequestData();
        request->get(url, callback != nullptr);

        if (callback == nullptr) {
            QByteArray ba = request->reply();
            delete request;
            saveRawLoadedData(url, ba);
            return onLoad(ba);
        } else {
            connect(request,
                    &RequestData::s_finished,
                    [callback, onLoad, url](RequestData *requestL) {
                        QByteArray ba = requestL->reply();
                        requestL->deleteLater();
                        saveRawLoadedData(url, ba);
                        callback(onLoad(ba));
                    });
        }
        return {};
    }

    template<typename T>
    static T loadOne(const QUrl &url, std::function<T(const QByteArray &)> onLoad, std::function<void(T)> callback = nullptr)
    {
        if (checkRawLoadedData(url)) {
            QByteArray ba = loadRawLoadedData(url);
            if (callback == nullptr) {
                return onLoad(ba);
            } else {
                callback(onLoad(ba));
                return {};
            }
        }
        RequestData *request = new RequestData();
        request->get(url, callback != nullptr);

        if (callback == nullptr) {
            QByteArray ba = request->reply();
            delete request;
            saveRawLoadedData(url, ba);
            return onLoad(ba);
        } else {
            connect(request, &RequestData::s_finished,
                    [callback, onLoad, url](RequestData *requestL)
                    {
                        QByteArray ba = requestL->reply();
                        requestL->deleteLater();
                        saveRawLoadedData(url, ba);
                        callback(onLoad(ba));
                    });
        }
        return {};
    }

private:
    static const QString key_;
};


#endif // SAPI_H
