#ifndef SAPI_H
#define SAPI_H

#include "classes/network/requestimage.h"
#include "classes/common/settings.h"

QPixmap loadPixmap(QPixmap &aPixmap, const QString &aUrl, const QString &aSavePath, QSize aSize);

class Sapi : public QObject {
    Q_OBJECT
public:
    static QString gameImageUrl(QString game, QString img_id);

    explicit Sapi(QObject *parent = nullptr);
    Sapi(const Sapi &api);
    ~Sapi();
    static QUrl achievementsSchemaUrl(QString appId);
    static QUrl achievementsPlayerUrl(QString appId, QString steamId);
    static QUrl achievementsPercentUrl(QString appId);
    static QUrl bansUrl(QString steamIds);
    static QUrl friendsUrl(QString steamId);
    static QUrl profileUrl(QString steamId);
    static QUrl profileUrl(QStringList steamIds);
    static QUrl profilefromVanityUrl(QString steamId);
    static QUrl gameUrl(int freeGames, int gameInfo, QString steamId);
    static QUrl numberPlayersUrl(QString appId);
    static QUrl lvlUrl(QString steamId);

    virtual QJsonObject toJson() const = 0;
    virtual QString className() const = 0;
    QString toString() const;

    friend QDebug operator<<(QDebug dbg, const Sapi &a) {
        dbg.nospace() << a.className() << "(" << a.toString() << ")\n";
        return dbg.space();
    }

protected:

signals:

protected:
    template <typename T>
    static QList<T> load(QUrl url, std::function<QList<T>(QByteArray)> onLoad, std::function<void(QList<T>)> callback = nullptr) {
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
