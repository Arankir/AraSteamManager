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
    QString GetSteamid() {return _friend.value("steamid").toString();}
    QString GetRelationship() {return _friend.value("relationship").toString();}
    QDateTime GetFriend_since() {return QDateTime::fromSecsSinceEpoch(_friend.value("friend_since").toInt(),Qt::LocalTime);}
    SFriend(const SFriend &);
    SFriend & operator=(const SFriend & friends);

signals:

public slots:

private:
    QJsonObject _friend;
};

#endif // SFRIEND_H
