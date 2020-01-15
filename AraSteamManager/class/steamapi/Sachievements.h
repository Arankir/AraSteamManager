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
#include <class/statusvalue.h>
#include <QObject>

class SAchievements : public QObject
{
    Q_OBJECT
public:
    explicit SAchievements(QString appid, QString id, QObject *parent = nullptr);
    SAchievements(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent);
    SAchievements();
    ~SAchievements();
    void Set(QString appid, QString id);
    void Set(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent);
    void SetID(QString Aid);
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
    StatusValue GetStatusGlobal() {return _statusGlobal;}
    StatusValue GetStatusPlayer() {return _statusPlayer;}
    StatusValue GetStatusPercent() {return _statusPercent;}
    StatusValue GetStatusFinish() {return _statusFinish;}
    QString GetErrorGlobal() {return _errorGlobal;}
    QString GetErrorPlayer() {return _errorPlayer;}
    QString GetErrorPercent() {return _errorPercent;}
    QString GetErrorFinish() {return _errorFinish;}
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
    StatusValue _statusGlobal=StatusValue::none;
    StatusValue _statusPlayer=StatusValue::none;
    StatusValue _statusPercent=StatusValue::none;
    StatusValue _statusFinish=StatusValue::none;
    QString _errorGlobal="";
    QString _errorPlayer="";
    QString _errorPercent="";
    QString _errorFinish="";
    QString _id="";
    QString _appid="";
    QString _gameName="";
    QString _gameVersion="";
    int _count=0;
};

#endif // SACHIEVEMENTS_H
