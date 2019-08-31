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
    QString GetSteamid();
    QString GetRelationship();
    QDateTime GetFriend_since();
    SteamAPIFriend(const SteamAPIFriend &);
    SteamAPIFriend & operator=(const SteamAPIFriend & friends);

signals:

public slots:

private:
    QString steamid="";
    QString relationship="";
    QDateTime friend_since=QDateTime::fromSecsSinceEpoch(0,Qt::LocalTime);
};

#endif // STEAMAPIFRIEND_H
