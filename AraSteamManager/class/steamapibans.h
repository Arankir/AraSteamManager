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
    explicit SteamAPIBans(QString key, QString id, QObject *parent = nullptr);
    SteamAPIBans(QJsonDocument DocBans);
    SteamAPIBans();
    ~SteamAPIBans();
    void Set(QString key, QString id);
    void Set(QJsonDocument DocBans);
    QString GetSteamid();
    bool GetCommunityBanned();
    bool GetVACBanned();
    int GetNumberOfVACBans();
    int GetDaysSinceLastBan();
    int GetNumberOfGameBans();
    QString GetEconomyBan();
    QString GetStatus();
    void Update();

signals:
    void finished(SteamAPIBans*);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QString steamid;//"76561198065018572"
    bool CommunityBanned=false;//false
    bool VACBanned=false;//false
    int NumberOfVACBans=0;//0
    int DaysSinceLastBan=0;//0
    int NumberOfGameBans=0;//0
    QString EconomyBan="none";//"none"
    QString status;
    QString key;
};
#endif // STEAMAPIBANS_H
