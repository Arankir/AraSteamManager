#ifndef PROFILE2_H
#define PROFILE2_H

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

class Profile : public QObject
{
    Q_OBJECT
public:
    explicit Profile(QJsonObject info, QObject *parent = nullptr);
    Profile();
    Profile(const Profile&);
    Profile& operator=(const Profile&);
    ~Profile();
    void PostData(QJsonObject info);
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


public slots:

};

#endif // PROFILE2_H
