#ifndef SAPI_H
#define SAPI_H

#include "classes/network/requestimage.h"
#include <QUrlQuery>

enum class StatusValue {
    none,
    success,
    error
};

QPixmap loadPixmap(QPixmap &aPixmap, const QString &aUrl, const QString &aSavePath, QSize aSize);

class Sapi : public QObject {
    Q_OBJECT
public:
    StatusValue status() const {return _status;}
    QString error() const {return _error;}
    bool isLoad() const {return _status == StatusValue::success;}

    static QString gameImageUrl(QString game, QString img_id);

protected:
    explicit Sapi(QObject *parent = nullptr);
    Sapi(const Sapi &api);
    ~Sapi();
    Sapi &operator=(const Sapi &api);

    static QUrl achievementsGlobalUrl(QString appId);
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

    virtual void onLoad() = 0;
    virtual void fromJson(const QJsonValue&) = 0;

signals:

protected:
    RequestData _request;
    StatusValue _status;
    QString _error;

private:
    static const QString _key;
};

#endif // SAPI_H
