#ifndef PROFILE_H
#define PROFILE_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QTcpSocket>

class Profile : public QObject
{
    Q_OBJECT
public:
    explicit Profile(QString steamid, QPixmap Avatar, int visibility, QString Name, int timecreated, QString inGame, QString Gameid, QObject *parent = nullptr);
    explicit Profile(QJsonObject info, QObject *parent = nullptr);
    explicit Profile(QObject *parent = nullptr);
    ~Profile();
    QString GetSteamid();
    QPixmap GetAvatar();
    int GetVisibility();
    QString GetName();
    int GetTimeCreated();
    QString GetInGame();
    QString GetGameId();

signals:

private:
    QString steamid;
    QPixmap Avatar;
    int visibility;
    QString Name;
    int timecreated;
    QString inGame;
    QString Gameid;
    QNetworkAccessManager* manager;


public slots:
    void OnResultGet(QNetworkReply *reply);
};

#endif // PROFILE_H
