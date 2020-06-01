#ifndef SBANS_H
#define SBANS_H

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
#include <QObject>

class SBans : public QObject
{
    Q_OBJECT
public:
    explicit SBans(QString id, bool parallel, QObject *parent = nullptr);
    SBans(QJsonDocument docBans, QObject *parent = nullptr);
    SBans(QObject *parent = nullptr);
    ~SBans();
    void set(QString id, bool parallel);
    void set(QJsonDocument docBans);
    QString getSteamid(int index=0);
    bool getCommunityBanned(int index=0);
    bool getVacBanned(int index=0);
    int getNumberOfVacBans(int index=0);
    int getDaysSinceLastBan(int index=0);
    int getNumberOfGameBans(int index=0);
    QString getEconomyBan(int index=0);
    StatusValue getStatus();
    QString getError();
    void update(bool parallel);

signals:
    void s_finished(SBans*);
    void s_finished();

private slots:
    void onLoad(QNetworkReply *reply);

private:
    QNetworkAccessManager *_manager;
    QJsonArray _bans;
    StatusValue _status;
    QString _error="";
    QString _id;
};
#endif // SBANS_H
