#ifndef SACHIEVEMENTSGLOBAL_H
#define SACHIEVEMENTSGLOBAL_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapi/Sachievementglobal.h>
#include <class/settings.h>
#include <QObject>

class SAchievementsGlobal : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementsGlobal(QString appid, QObject *parent = nullptr);
    SAchievementsGlobal(QJsonDocument DocAchievements);
    SAchievementsGlobal();
    ~SAchievementsGlobal();
    void Set(QString appid);
    void Set(QJsonDocument DocAchievements);
    void Delete(int index) { _achievements.remove(index); _count--;}
    SAchievementGlobal GetAchievement(int index) {return _achievements[index];}
    QString GetApiname(int index) {return _achievements[index].GetApiname();}
    int GetDefaultvalue(int index) {return _achievements[index].GetDefaultvalue();}
    QString GetDisplayname(int index) {return _achievements[index].GetDisplayname();}
    int GetHidden(int index) {return _achievements[index].GetHidden();}
    QString GetDescription(int index) {return _achievements[index].GetDescription();}
    QString GetIcon(int index) {return _achievements[index].GetIcon();}
    QString GetIcongray(int index) {return _achievements[index].GetIcongray();}
    QString GetAppid() {return _appid;}
    QString GetStatus() {return _status;}
    QString GetGamename() {return _gameName;}
    QString GetGameversion() {return _gameVersion;}
    int GetCount() {return _count;}
    void Update();
    void Clear();
    SAchievementsGlobal(const SAchievementsGlobal &);
    SAchievementsGlobal & operator=(const SAchievementsGlobal & friends);

signals:
    void s_finished(SAchievementsGlobal);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QVector<SAchievementGlobal> _achievements;
    QString _status="none";
    QString _appid="";
    QString _gameName="";
    QString _gameVersion="";
    int _count=0;
};

#endif // SACHIEVEMENTSGLOBAL_H
