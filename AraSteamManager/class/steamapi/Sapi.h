#ifndef SAPI_H
#define SAPI_H

#include "class/Network/requestimage.h"

enum class StatusValue {
    none,
    success,
    error
};

QPixmap loadPixmap(QPixmap &aPixmap, const QString &aUrl, const QString &aSavePath, QSize aSize);

class Sapi : public QObject {
    Q_OBJECT
public:
    StatusValue getStatus() const {return _status;}
    QString getError() const {return _error;}

    static QString gameImageUrl(QString game, QString img_id);

protected:
    explicit Sapi(QObject *parent = nullptr);
    Sapi(const Sapi &api);
    ~Sapi();
    Sapi &operator=(const Sapi &api);

    static QString achievementsGlobalUrl(QString appId);
    static QString achievementsPlayerUrl(QString appId, QString steamId);
    static QString achievementsPercentUrl(QString appId);
    static QString bansUrl(QString steamIds);
    static QString friendsUrl(QString steamId);
    static QString profileUrl(QString steamId);
    static QString profileUrl(QStringList steamIds);
    static QString profilefromVanityUrl(QString steamId);
    static QString gameUrl(int freeGames, int gameInfo, QString steamId);
    static QString numberPlayersUrl(QString appId);
    static QString lvlUrl(QString steamId);

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
