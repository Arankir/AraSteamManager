#ifndef SAPI_H
#define SAPI_H

#include "classes/network/requestimage.h"
#include "classes/common/settings.h"

QPixmap loadPixmap(QPixmap &aPixmap, const QString &aUrl, const QString &aSavePath, const QSize &aSize);
QPixmap cLoadPixmap(const QString &aUrl, const QString &aSavePath, const QSize &aSize);

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

signals:

protected:
    static QString gameImageUrl(const QString &game, const QString &img_id);

    static QUrl achievementsSchemaUrl(const QString &appId);
    static QUrl achievementsPlayerUrl(const QString &appId, const QString &steamId);
    static QUrl achievementsPercentUrl(const QString &appId);
    static QUrl bansUrl(const QString &steamIds);
    static QUrl friendsUrl(const QString &steamId);
    static QUrl profileUrl(const QString &steamId);
    static QUrl profileUrl(const QStringList &steamIds);
    static QUrl profilefromVanityUrl(const QString &steamId);
    static QUrl gameUrl(const int &freeGames, const int &gameInfo, const QString &steamId);
    static QUrl numberPlayersUrl(const QString &appId);
    static QUrl lvlUrl(const QString &steamId);
    template <typename T>
    static QList<T> load(const QUrl &url, std::function<QList<T>(QByteArray)> onLoad, std::function<void(QList<T>)> callback = nullptr) {
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
    static const QString _key;
};


#endif // SAPI_H
