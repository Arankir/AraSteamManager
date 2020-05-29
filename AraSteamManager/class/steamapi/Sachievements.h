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

class SAchievementGlobal : public QObject{
    Q_OBJECT
public:
    explicit SAchievementGlobal(QJsonObject a_achievement, QObject *a_parent = nullptr) : QObject(a_parent),_apiName(a_achievement.value("name").toString()),
        _defaultValue(a_achievement.value("defaultvalue").toInt()),_displayName(a_achievement.value("displayName").toString()),
        _hidden(a_achievement.value("hidden").toInt()),_description(a_achievement.value("description").toString()),
        _icon(a_achievement.value("icon").toString()),_iconGray(a_achievement.value("icongray").toString()){};
    const QString _apiName;
    const int _defaultValue;
    const QString _displayName;
    const int _hidden;
    const QString _description;
    const QString _icon;
    const QString _iconGray;
    SAchievementGlobal(const SAchievementGlobal &a_achievement): QObject(a_achievement.parent()), _apiName(a_achievement._apiName), _defaultValue(a_achievement._defaultValue),
        _displayName(a_achievement._displayName), _hidden(a_achievement._hidden), _description(a_achievement._description), _icon(a_achievement._icon), _iconGray(a_achievement._iconGray){};
    SAchievementGlobal &operator=(const SAchievementGlobal &) {return *this;}

};
class SAchievementPercentage : public QObject{
    Q_OBJECT
public:
    explicit SAchievementPercentage(QJsonObject a_achievement, QObject *parent = nullptr) : QObject(parent),_apiName(a_achievement.value("name").toString()),_percent(a_achievement.value("percent").toDouble()){};
    const QString _apiName;
    const double _percent;
    SAchievementPercentage(const SAchievementPercentage &a_achievement): QObject(a_achievement.parent()),_apiName(a_achievement._apiName), _percent(a_achievement._percent){};
    SAchievementPercentage &operator=(const SAchievementPercentage &) {return *this;}

};
class SAchievementPlayer : public QObject{
    Q_OBJECT
public:
    explicit SAchievementPlayer(QJsonObject a_achievement, QObject *parent = nullptr): QObject(parent),_apiName(a_achievement.value("apiname").toString()),
        _achieved(a_achievement.value("achieved").toInt()),_unlockTime(QDateTime::fromSecsSinceEpoch(a_achievement.value("unlocktime").toInt(),Qt::LocalTime)){};
    const QString _apiName;
    const int _achieved;
    const QDateTime _unlockTime;
    SAchievementPlayer(const SAchievementPlayer &a_achievement): QObject(a_achievement.parent()),_apiName(a_achievement._apiName),_achieved(a_achievement._achieved),
        _unlockTime(a_achievement._unlockTime){};
    SAchievementPlayer &operator=(const SAchievementPlayer &) {return *this;}

};
class SAchievement : public QObject{
    Q_OBJECT
public:
    explicit SAchievement(SAchievementGlobal a_global, SAchievementPlayer a_player, SAchievementPercentage a_percent, QObject *parent = nullptr): QObject(parent),
        _apiName(a_global._apiName), _defaultValue(a_global._defaultValue), _displayName(a_global._displayName), _hidden(a_global._hidden),
        _description(a_global._description), _icon(a_global._icon), _iconGray(a_global._iconGray), _achieved(a_player._achieved),
        _unlockTime(a_player._unlockTime), _percent(a_percent._percent){};
    const QString _apiName;
    const int _defaultValue;
    const QString _displayName;
    const int _hidden;
    const QString _description;
    const QString _icon;
    const QString _iconGray;
    const int _achieved;
    const QDateTime _unlockTime;
    const double _percent;
    SAchievement(const SAchievement & a_achievement): QObject(a_achievement.parent()),
        _apiName(a_achievement._apiName), _defaultValue(a_achievement._defaultValue), _displayName(a_achievement._displayName), _hidden(a_achievement._hidden),
        _description(a_achievement._description), _icon(a_achievement._icon), _iconGray(a_achievement._iconGray), _achieved(a_achievement._achieved),
        _unlockTime(a_achievement._unlockTime), _percent(a_achievement._percent){};
    SAchievement &operator=(const SAchievement &) {return *this;}
    const bool &operator<(const SAchievement & achievement);

};

class SAchievementsGlobal : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementsGlobal(QString appid, bool parallel = true, QObject *parent = nullptr);
    SAchievementsGlobal(QJsonDocument DocAchievements, QObject *parent = nullptr);
    SAchievementsGlobal(QObject *parent = nullptr): QObject(parent),_manager(new QNetworkAccessManager()){};
    ~SAchievementsGlobal();
    void Set(QString appid);
    void Set(QJsonDocument DocAchievements);
    void Delete(int index) { _achievements.removeAt(index);}
    QString GetAppid() {return _appid;}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    QString GetGamename() {return _gameName;}
    QString GetGameversion() {return _gameVersion;}
    int GetCount() {return _achievements.size();}
    QList<SAchievementGlobal>::iterator begin() {return _achievements.begin();}
    QList<SAchievementGlobal>::iterator end() {return _achievements.end();}
    void Update();
    void Clear();
    SAchievementsGlobal(const SAchievementsGlobal &achievements):QObject(achievements.parent()), _manager(new QNetworkAccessManager), _achievements(achievements._achievements),
        _status(achievements._status), _error(achievements._error), _appid(achievements._appid), _gameName(achievements._gameName), _gameVersion(achievements._gameVersion){};
    SAchievementsGlobal &operator=(const SAchievementsGlobal & friends);
    SAchievementGlobal &operator[](const int &a_index) {return _achievements[a_index];}

signals:
    void s_finished(SAchievementsGlobal);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QList<SAchievementGlobal> _achievements;
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
    SAchievementsPercentage(QJsonDocument DocAchievements, QObject *parent = nullptr);
    SAchievementsPercentage(QObject *parent = nullptr): QObject(parent),_manager(new QNetworkAccessManager()){};
    ~SAchievementsPercentage();
    void Set(QString appid);
    void Set(QJsonDocument DocAchievements);
    void Delete(int index) { _achievements.removeAt(index);}
    QString GetAppid() {return _appid;}
    int GetCount() {return _achievements.size();}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    QList<SAchievementPercentage>::iterator begin() {return _achievements.begin();}
    QList<SAchievementPercentage>::iterator end() {return _achievements.end();}
    void Update();
    void Clear();
    SAchievementsPercentage(const SAchievementsPercentage &achievements): QObject(achievements.parent()),_manager(new QNetworkAccessManager()), _achievements(achievements._achievements),
        _error(achievements._error), _status(achievements._status), _appid(achievements._appid){};
    SAchievementsPercentage &operator=(const SAchievementsPercentage & friends);
    SAchievementPercentage &operator[](const int &a_index) {return _achievements[a_index];}

signals:
    void s_finished(SAchievementsPercentage);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QList<SAchievementPercentage> _achievements;
    QString _error="";
    StatusValue _status=StatusValue::none;
    QString _appid="";
};
class SAchievementsPlayer : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementsPlayer(QString appid, QString id, bool parallel = true, QObject *parent = nullptr);
    SAchievementsPlayer(QJsonDocument DocAchievements, QObject *parent = nullptr);
    SAchievementsPlayer(QObject *parent = nullptr): QObject(parent),_manager(new QNetworkAccessManager()){};
    ~SAchievementsPlayer();
    void Set(QString appid, QString id);
    void Set(QJsonDocument DocAchievements);
    void Delete(int AIndex) { _achievements.removeAt(AIndex);}
    QString GetAppid() {return _appid;}
    StatusValue GetStatus() {return _status;}
    QString GetError() {return _error;}
    QString GetGamename() {return _gameName;}
    int GetCount() {return _achievements.size();}
    QList<SAchievementPlayer>::iterator begin() {return _achievements.begin();}
    QList<SAchievementPlayer>::iterator end() {return _achievements.end();}
    void Update();
    void Clear();
    SAchievementsPlayer(const SAchievementsPlayer &achievements): QObject(achievements.parent()), _index(achievements._index), _manager(new QNetworkAccessManager()),
        _achievements(achievements._achievements), _status(achievements._status), _error(achievements._error), _id(achievements._id), _appid(achievements._appid),
        _gameName(achievements._gameName){};
    SAchievementsPlayer &operator=(const SAchievementsPlayer & friends);
    SAchievementPlayer &operator[](const int &a_index) {return _achievements[a_index];}

    int _index=0;

signals:
    void s_finished(SAchievementsPlayer);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    Settings _setting;
    QList<SAchievementPlayer> _achievements;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _id="";
    QString _appid="";
    QString _gameName="";
};

class SAchievements : public QObject
{
    Q_OBJECT
public:
    explicit SAchievements(QString appid, QString id, QObject *parent = nullptr);
    SAchievements(SAchievementsGlobal &a_global, SAchievementsPlayer &Player, SAchievementsPercentage &Percent, QObject *parent = nullptr);
    SAchievements(SAchievementsGlobal &a_global, QObject *parent = nullptr): QObject(parent),_global(a_global),_statusGlobal(StatusValue::success){};
    SAchievements(SAchievementsPlayer &a_player, QObject *parent = nullptr): QObject(parent),_player(a_player),_statusPlayer(StatusValue::success){};
    SAchievements(SAchievementsPercentage a_percent, QObject *parent = nullptr): QObject(parent),_percent(a_percent),_statusPercent(StatusValue::success){};
    SAchievements(QObject *parent = nullptr): QObject(parent){};
    ~SAchievements() {};
    void Set(QString appid, QString id);
    void Set(SAchievementsGlobal &Global, SAchievementsPlayer &Player, SAchievementsPercentage &Percent);
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
    QList<SAchievement>::iterator begin() {return _finish.begin();}
    QList<SAchievement>::iterator end() {return _finish.end();}
    void Update();
    void Clear();
    void Sort();
    SAchievements(const SAchievements &achievements): QObject(achievements.parent()), _id(achievements._id), _appid(achievements._appid), _global(achievements._global),
        _player(achievements._player), _percent(achievements._percent), _finish(achievements._finish), _statusGlobal(achievements._statusGlobal), _statusPlayer(achievements._statusPlayer),
        _statusPercent(achievements._statusPercent), _statusFinish(achievements._statusFinish), _errorGlobal(achievements._errorGlobal), _errorPlayer(achievements._errorPlayer),
        _errorPercent(achievements._errorPercent), _errorFinish(achievements._errorFinish), _gameName(achievements._gameName), _gameVersion(achievements._gameVersion){};
    SAchievements &operator=(const SAchievements & friends);
    SAchievement &operator[](const int &a_index) {return _finish[a_index];}

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
    QList<SAchievement> _finish;
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
