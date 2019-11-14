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
    explicit Profile(QJsonObject info, QObject* parent = nullptr);
    Profile();
    ~Profile();
    void Set(QJsonObject info);
    QString GetSteamid() {return steamid;}
    QPixmap GetAvatar() {return Avatar;}
    int GetVisibility() {return visibility;}
    QString GetName() {return Name;}
    int GetTimeCreated() {return timecreated;}
    QString GetInGame() {return inGame;}
    QString GetGameId() {return Gameid;}
    Profile & operator=(const Profile &);
    Profile(const Profile&);

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
