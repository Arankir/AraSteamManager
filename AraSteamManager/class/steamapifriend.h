#ifndef STEAMAPIFRIEND_H
#define STEAMAPIFRIEND_H

#include <QMainWindow>
#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QTextCodec>

class SteamAPIFriend : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIFriend(QJsonObject ObjFriend, QObject *parent = nullptr);
    SteamAPIFriend();
    void Set(QJsonObject ObjFriend);
    QString GetSteamid() {return friendd.value("steamid").toString();}
    QString GetRelationship() {return friendd.value("relationship").toString();}
    QDateTime GetFriend_since() {return QDateTime::fromSecsSinceEpoch(friendd.value("friend_since").toInt(),Qt::LocalTime);}
    SteamAPIFriend(const SteamAPIFriend &);
    SteamAPIFriend & operator=(const SteamAPIFriend & friends);

signals:

public slots:

private:
    QJsonObject friendd;
};

#endif // STEAMAPIFRIEND_H
