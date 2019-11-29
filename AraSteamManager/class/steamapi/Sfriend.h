#ifndef SFRIEND_H
#define SFRIEND_H

#include <QMainWindow>
#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QTextCodec>

class SFriend : public QObject
{
    Q_OBJECT
public:
    explicit SFriend(QJsonObject ObjFriend, QObject *parent = nullptr);
    SFriend();
    void Set(QJsonObject ObjFriend);
    QString GetSteamid() {return friendd.value("steamid").toString();}
    QString GetRelationship() {return friendd.value("relationship").toString();}
    QDateTime GetFriend_since() {return QDateTime::fromSecsSinceEpoch(friendd.value("friend_since").toInt(),Qt::LocalTime);}
    SFriend(const SFriend &);
    SFriend & operator=(const SFriend & friends);

signals:

public slots:

private:
    QJsonObject friendd;
};

#endif // SFRIEND_H
