#ifndef SACHIEVEMENTS_H
#define SACHIEVEMENTS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTcpSocket>
#include <QObject>
#include <QEventLoop>
#include <QDateTime>
#include <QTextCodec>
#include <class/settings.h>
#include <class/statusvalue.h>
#include <QDebug>

class SAchievementGlobal : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementGlobal(QJsonObject ObjAchievement, QObject *parent = nullptr);
    SAchievementGlobal();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname() {return _apiName;}
    int GetDefaultvalue() {return _defaultValue;}
    QString GetDisplayname() {return _displayName;}
    int GetHidden() {return _hidden;}
    QString GetDescription() {return _description;}
    QString GetIcon() {return _icon;}
    QString GetIcongray() {return _iconGray;}
    SAchievementGlobal(const SAchievementGlobal &);
    SAchievementGlobal & operator=(const SAchievementGlobal & achievement);

signals:

public slots:

private:
    QString _apiName="";
    int _defaultValue=0;
    QString _displayName="";
    int _hidden=0;
    QString _description="";
    QString _icon="";
    QString _iconGray="";
};

class SAchievementPercentage : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementPercentage(QJsonObject ObjAchievement, QObject *parent = nullptr);
    SAchievementPercentage();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname() {return _apiName;}
    double GetPercent() {return _percent;}
    SAchievementPercentage(const SAchievementPercentage & achievement);
    SAchievementPercentage & operator=(const SAchievementPercentage & achievement);

signals:

public slots:

private:
    QString _apiName="";
    double _percent=0.0;
};

class SAchievementPlayer : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementPlayer(QJsonObject ObjAchievement, QObject *parent = nullptr);
    SAchievementPlayer();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname() {return _apiName;}
    int GetAchieved() {return _achieved;}
    QDateTime GetUnlocktime() {return _unlockTime;}
    SAchievementPlayer(const SAchievementPlayer &);
    SAchievementPlayer & operator=(const SAchievementPlayer & achievement);

signals:

public slots:

private:
    QString _apiName="";
    int _achieved=0;
    QDateTime _unlockTime=QDateTime::fromSecsSinceEpoch(0,Qt::LocalTime);
};

class SAchievementsGlobal : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementsGlobal(QString appid, bool parallel = true, QObject *parent = nullptr);
    SAchievementsGlobal(QJsonDocument DocAchievements);
    SAchievementsGlobal();
    ~SAchievementsGlobal();
    void Set(QString appid);
    void Set(QJsonDocument DocAchievements);
    void Delete(int index) { _achievements.remove(index);}
    QString GetAppid() {return _appid;}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    QString GetGamename() {return _gameName;}
    QString GetGameversion() {return _gameVersion;}
    int GetCount() {return _achievements.size();}
    void Update();
    void Clear();
    SAchievementsGlobal(const SAchievementsGlobal &);
    SAchievementsGlobal &operator=(const SAchievementsGlobal & friends);
    SAchievementGlobal &operator[](const int &Aindex);

signals:
    void s_finished(SAchievementsGlobal);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QVector<SAchievementGlobal> _achievements;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _appid="";
    QString _gameName="";
    QString _gameVersion="";
};

class SAchievementsPercentage : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementsPercentage(QString appid, bool parallel = true, QObject *parent = nullptr);
    SAchievementsPercentage(QJsonDocument DocAchievements);
    SAchievementsPercentage();
    ~SAchievementsPercentage();
    void Set(QString appid);
    void Set(QJsonDocument DocAchievements);
    void Delete(int index) { _achievements.remove(index);}
    QString GetAppid() {return _appid;}
    int GetCount() {return _achievements.size();}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    void Update();
    void Clear();
    SAchievementsPercentage(const SAchievementsPercentage &);
    SAchievementsPercentage &operator=(const SAchievementsPercentage & friends);
    SAchievementPercentage &operator[](const int &Aindex);

signals:
    void s_finished(SAchievementsPercentage);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QVector<SAchievementPercentage> _achievements;
    QString _error="";
    StatusValue _status=StatusValue::none;
    QString _appid="";
};

class SAchievementsPlayer : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementsPlayer(QString appid, QString id, bool parallel = true, QObject *parent = nullptr);
    SAchievementsPlayer(QJsonDocument DocAchievements);
    SAchievementsPlayer();
    ~SAchievementsPlayer();
    void Set(QString appid, QString id);
    void Set(QJsonDocument DocAchievements);
    void Delete(int AIndex) { _achievements.remove(AIndex);}
    QString GetAppid() {return _appid;}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    QString GetGamename() {return _gameName;}
    int GetCount() {return _achievements.size();}
    void Update();
    void Clear();
    SAchievementsPlayer(const SAchievementsPlayer &);
    SAchievementsPlayer &operator=(const SAchievementsPlayer & friends);
    SAchievementPlayer &operator[](const int &Aindex);

    int _index=0;

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
};

class SAchievement : public QObject
{
    Q_OBJECT
public:
    explicit SAchievement(SAchievementGlobal Global, SAchievementPlayer Player, SAchievementPercentage Percent, QObject *parent = nullptr);
    SAchievement();
    void Set(SAchievementGlobal Global, SAchievementPlayer Player, SAchievementPercentage Percent);
    void SetGlobal(SAchievementGlobal Global);
    void SetPlayer(SAchievementPlayer Player);
    void SetPercent(SAchievementPercentage Percent);
    QString GetApiname() {return _apiName;}
    int GetDefaultvalue() {return _defaultValue;}
    QString GetDisplayname() {return _displayName;}
    int GetHidden() {return _hidden;}
    QString GetDescription() {return _description;}
    QString GetIcon() {return _icon;}
    QString GetIcongray() {return _iconGray;}
    int GetAchieved() {return _achieved;}
    QDateTime GetUnlocktime() {return _unlockTime;}
    StatusValue GetStatusGlobal() {return _statusGlobal;}
    StatusValue GetStatusPlayer() {return _statusPlayer;}
    QString GetErrorGlobal() {return _errorGlobal;}
    QString GetErrorPlayer() {return _errorPlayer;}
    double GetPercent() {return _percent;}
    SAchievement(const SAchievement &);
    SAchievement &operator=(const SAchievement & achievement);
    const bool &operator<(const SAchievement & achievement);

signals:

public slots:

private:
    QString _apiName="";
    int _defaultValue=0;
    QString _displayName="";
    int _hidden=0;
    QString _description="";
    QString _icon="";
    QString _iconGray="";
    int _achieved=0;
    QDateTime _unlockTime=QDateTime::fromSecsSinceEpoch(0,Qt::LocalTime);
    double _percent=0.0;
    StatusValue _statusGlobal=StatusValue::none;
    StatusValue _statusPlayer=StatusValue::none;
    StatusValue _statusPercent=StatusValue::none;
    QString _errorGlobal="";
    QString _errorPlayer="";
    QString _errorPercent="";
};

class SAchievements : public QObject
{
    Q_OBJECT
public:
    explicit SAchievements(QString appid, QString id, QObject *parent = nullptr);
    SAchievements(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent);
    SAchievements() {};
    ~SAchievements() {};
    void Set(QString appid, QString id);
    void Set(SAchievementsGlobal Global, SAchievementsPlayer Player, SAchievementsPercentage Percent);
    void SetFinish();
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
    int GetCount() {return _finish.size();}
    void Update();
    void Clear();
    void Sort();
    SAchievements(const SAchievements &);
    SAchievements &operator=(const SAchievements & friends);
    SAchievement &operator[](const int &Aindex);

    QString _id="";
    QString _appid="";

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
    QString _gameName="";
    QString _gameVersion="";
};

#endif // SACHIEVEMENTS_H
