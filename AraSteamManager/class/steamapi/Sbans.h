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
    SBans(QJsonDocument DocBans, QObject *parent = nullptr);
    SBans(QObject *parent = nullptr);
    ~SBans();
    void Set(QString id, bool parallel);
    void Set(QJsonDocument DocBans);
    QString GetSteamid(int index=0) {return _bans[index].toObject().value("steamid").toString();}
    bool GetCommunityBanned(int index=0) {return _bans[index].toObject().value("CommunityBanned").toBool();}
    bool GetVACBanned(int index=0) {return _bans[index].toObject().value("VACBanned").toBool();}
    int GetNumberOfVACBans(int index=0) {return _bans[index].toObject().value("NumberOfVACBans").toInt();}
    int GetDaysSinceLastBan(int index=0) {return _bans[index].toObject().value("DaysSinceLastBan").toInt();}
    int GetNumberOfGameBans(int index=0) {return _bans[index].toObject().value("NumberOfGameBans").toInt();}
    QString GetEconomyBan(int index=0) {return _bans[index].toObject().value("EconomyBan").toString();}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    void Update(bool parallel);

signals:
    void s_finished(SBans*);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QJsonArray _bans;
    StatusValue _status;
    QString _error="";
    QString _id;
};
#endif // SBANS_H
