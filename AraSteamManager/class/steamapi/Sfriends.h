#ifndef SFRIENDS_H
#define SFRIENDS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapi/Sprofile.h>
#include <class/settings.h>
#include <class/statusvalue.h>
#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QTextCodec>

class SFriend : public QObject {
    Q_OBJECT
public:
    explicit SFriend(QJsonObject a_friend, QObject *parent = nullptr);
    const QString _steamID;
    const QString _relationship;
    const QDateTime _friend_since;
    SFriend(const SFriend &aFriend);
    SFriend &operator=(const SFriend &);
    const bool &operator<(const SFriend &aFriend);

};

class SFriends : public QObject {
    Q_OBJECT
public:
    explicit SFriends(QString id, bool parallel, QObject *parent = nullptr);
    SFriends(QJsonDocument DocFriends, QObject *parent = nullptr);
    SFriends(QObject *parent = nullptr);
    ~SFriends();
    void set(QString id, bool parallel);
    void set(QJsonDocument DocFriends);
    StatusValue getStatus();
    QString getError();
    int getCount();
    SProfiles getProfiles();
    void update(bool parallel);
    void clear();
    void sort();
    SFriends(const SFriends &);
    SFriends &operator=(const SFriends &friends);
    SFriend &operator[](const int &index);
    QList<SFriend>::iterator begin() {return _friends.begin();}
    QList<SFriend>::iterator end() {return _friends.end();}

signals:
    void s_finished(SFriends*);
    void s_finished();

private slots:
    void onLoad(QNetworkReply *reply);

private:
    QNetworkAccessManager *_manager;
    StatusValue _status = StatusValue::none;
    QString _error = "";
    QString _id;
    QList<SFriend> _friends;
};

#endif // SFRIENDS_H
