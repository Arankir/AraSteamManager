#ifndef SAPI_H
#define SAPI_H

#include <QObject>
#include "class/settings.h"
#include "class/Network/requestdata.h"

enum class StatusValue {
    none,
    success,
    error
};

class Sapi : public QObject {
    Q_OBJECT
public:
    StatusValue getStatus() const;
    QString getError() const;

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
    static QString gameImageUrl(QString game, QString img_id);
    static QString numberPlayersUrl(QString appId);
    static QString lvlUrl(QString steamId);

signals:

protected:
    virtual void onLoad() = 0;
    RequestData _request;
    StatusValue _status;
    QString _error;
};

#endif // SAPI_H
