#ifndef SACHIEVEMENTS_H
#define SACHIEVEMENTS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <class/steamapi/Sachievement.h>
#include <class/steamapi/Sachievementsglobal.h>
#include <class/steamapi/Sachievementsplayer.h>
#include <class/steamapi/Sachievementspercentage.h>
#include <QObject>

class SAchievements : public QObject
{
    Q_OBJECT
public:
    explicit SAchievements(QString appid, QString id, QObject *parent = nullptr);
    SAchievements(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent);
    SAchievements();
    ~SAchievements();
    void DoSet(QString appid, QString id);
    void Set(QString appid, QString id);
    void Set(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent);
    void SetFinish();
    SAchievement GetAchievement(int index) {return _finish[index];}
    QString GetApiname(int index) {return _finish[index].GetApiname();}
    int GetDefaultvalue(int index) {return _finish[index].GetDefaultvalue();}
    QString GetDisplayname(int index) {return _finish[index].GetDisplayname();}
    int GetHidden(int index) {return _finish[index].GetHidden();}
    QString GetDescription(int index) {return _finish[index].GetDescription();}
    QString GetIcon(int index) {return _finish[index].GetIcon();}
    QString GetIcongray(int index) {return _finish[index].GetIcongray();}
    int GetAchieved(int index) {return _finish[index].GetAchieved();}
    QDateTime GetUnlocktime(int index) {return _finish[index].GetUnlocktime();}
    double GetPercent(int index) {return _finish[index].GetPercent();}
    QString GetStatusGlobal() {return _statusGlobal;}
    QString GetStatusPlayer() {return _statusPlayer;}
    QString GetStatusPercent() {return _statusPercent;}
    QString GetStatusFinish() {return _statusFinish;}
    QString GetAppid() {return _appid;}
    QString GetGamename() {return _gameName;}
    QString GetGameversion() {return _gameVersion;}
    int GetCount() {return _count;}
    void Update();
    void Clear();
    void Sort();
    SAchievements(const SAchievements &);
    SAchievements & operator=(const SAchievements & friends);

signals:
    void s_finished(SAchievements*);
    void s_finished();

public slots:
    void Set(SAchievementsPlayer Player);
    void Set(SAchievementsGlobal Global);
    void Set(SAchievementsPercentage Percent);

private:
    SAchievementsGlobal _global;
    SAchievementsPlayer _player;
    SAchievementsPercentage _percent;
    QVector<SAchievement> _finish;
    QString _statusGlobal="none";
    QString _statusPlayer="none";
    QString _statusPercent="none";
    QString _statusFinish="none";
    QString _id="";
    QString _appid="";
    QString _gameName="";
    QString _gameVersion="";
    int _count=0;
};

#endif // SACHIEVEMENTS_H
