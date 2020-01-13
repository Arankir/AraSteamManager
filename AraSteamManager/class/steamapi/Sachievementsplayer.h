#ifndef SACHIEVEMENTSPLAYER_H
#define SACHIEVEMENTSPLAYER_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapi/Sachievementplayer.h>
#include <class/settings.h>
#include <class/statusvalue.h>
#include <QObject>

class SAchievementsPlayer : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementsPlayer(QString appid, QString id, QObject *parent = nullptr);
    SAchievementsPlayer(QJsonDocument DocAchievements);
    SAchievementsPlayer();
    ~SAchievementsPlayer();
    void Set(QString appid, QString id);
    void Set(QJsonDocument DocAchievements);
    void SetIndex(int ANewIndex) {_index=ANewIndex;}
    void Delete(int AIndex) { _achievements.remove(AIndex); _count--;}
    SAchievementPlayer GetAchievement(int index) {return _achievements[index];}
    QString GetApiname(int index) {return _achievements[index].GetApiname();}
    int GetAchieved(int index) {return _achievements[index].GetAchieved();}
    QDateTime GetUnlocktime(int index) {return _achievements[index].GetUnlocktime();}
    QString GetAppid() {return _appid;}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    QString GetGamename() {return _gameName;}
    int GetCount() {return _count;}
    int GetIndex() {return _index;}
    void Update();
    void Clear();
    SAchievementsPlayer(const SAchievementsPlayer &);
    SAchievementsPlayer & operator=(const SAchievementsPlayer & friends);

signals:
    void s_finished(SAchievementsPlayer);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QVector<SAchievementPlayer> _achievements;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _id="";
    QString _appid="";
    QString _gameName="";
    int _count=0;
    int _index=0;
};

#endif // SACHIEVEMENTSPLAYER_H
