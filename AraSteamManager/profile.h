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
#include <QEventLoop>

class Profile
{
public:
    Profile(QString steamid, QPixmap Avatar, int visibility, QString Name, int timecreated, QString inGame, QString Gameid);
    Profile(QJsonObject info);
    Profile();
    ~Profile();
    QString GetSteamid();
    QPixmap GetAvatar();
    int GetVisibility();
    QString GetName();
    int GetTimeCreated();
    QString GetInGame();
    QString GetGameId();

private:
    QString steamid;
    QPixmap Avatar;
    int visibility;
    QString Name;
    int timecreated;
    QString inGame;
    QString Gameid;
};

#endif // PROFILE_H
