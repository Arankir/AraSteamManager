#ifndef STEAMAPILEVELS_H
#define STEAMAPILEVELS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QTcpSocket>
#include <QObject>

class SteamAPILevels : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPILevels(QString key, QString id, QObject *parent = nullptr);
    SteamAPILevels(QJsonDocument DocLevels);
    SteamAPILevels();
    ~SteamAPILevels();
    void Set(QString key, QString id);
    void Set(QJsonDocument DocLevel);
    int GetPlayer_level();
    QString GetStatus();
    void Update();

signals:
    void finished(SteamAPILevels*);
    void finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *manager;
    QString steamid;//"76561198065018572"
    int player_level=0;
    QString status;
    QString key;
};

#endif // STEAMAPILEVELS_H
