#ifndef STEAMAPIBANS_H
#define STEAMAPIBANS_H

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
#include <QObject>

class SteamAPIBans : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIBans(QString key, QString id, bool parallel, QObject *parent = nullptr);
    SteamAPIBans(QJsonDocument DocBans);
    SteamAPIBans();
    ~SteamAPIBans();
    void Set(QString key, QString id, bool parallel);
    void Set(QJsonDocument DocBans);
    QString GetSteamid(int index=0) {return bans[index].toObject().value("steamid").toString();}
    bool GetCommunityBanned(int index=0) {return bans[index].toObject().value("CommunityBanned").toBool();}
    bool GetVACBanned(int index=0) {return bans[index].toObject().value("VACBanned").toBool();}
    int GetNumberOfVACBans(int index=0) {return bans[index].toObject().value("NumberOfVACBans").toInt();}
    int GetDaysSinceLastBan(int index=0) {return bans[index].toObject().value("DaysSinceLastBan").toInt();}
    int GetNumberOfGameBans(int index=0) {return bans[index].toObject().value("NumberOfGameBans").toInt();}
    QString GetEconomyBan(int index=0) {return bans[index].toObject().value("EconomyBan").toString();}
    QString GetStatus() {return status;}
    void Update(bool parallel);

signals:
    void finished(SteamAPIBans*);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QJsonArray bans;
    QString status;
    QString key;
    QString id;
};
#endif // STEAMAPIBANS_H
