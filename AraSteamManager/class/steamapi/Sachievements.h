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

class SAchievementGlobal : public QObject {
    Q_OBJECT
public:
    explicit SAchievementGlobal(QJsonObject achievement, QObject *parent = nullptr);
    const QString _apiName;
    const int _defaultValue;
    const QString _displayName;
    const int _hidden;
    const QString _description;
    const QString _icon;
    const QString _iconGray;
    SAchievementGlobal(const SAchievementGlobal &achievement);
    SAchievementGlobal &operator=(const SAchievementGlobal &);

};
class SAchievementPercentage : public QObject {
    Q_OBJECT
public:
    explicit SAchievementPercentage(QJsonObject achievement, QObject *parent = nullptr);
    const QString _apiName;
    const double _percent;
    SAchievementPercentage(const SAchievementPercentage &achievement);
    SAchievementPercentage &operator=(const SAchievementPercentage &);

};
class SAchievementPlayer : public QObject {
    Q_OBJECT
public:
    explicit SAchievementPlayer(QJsonObject a_achievement, QObject *parent = nullptr);
    const QString _apiName;
    const int _achieved;
    const QDateTime _unlockTime;
    SAchievementPlayer(const SAchievementPlayer &a_achievement);
    SAchievementPlayer &operator=(const SAchievementPlayer &);

};
class SAchievement : public QObject {
    Q_OBJECT
public:
    explicit SAchievement(SAchievementGlobal a_global, SAchievementPlayer a_player, SAchievementPercentage a_percent, QObject *parent = nullptr);
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
    SAchievement(const SAchievement & a_achievement);
    SAchievement &operator=(const SAchievement &);
    const bool &operator<(const SAchievement & achievement);

};

class SAchievementsGlobal : public QObject {
    Q_OBJECT
public:
    explicit SAchievementsGlobal(QString appid, bool parallel = true, QObject *parent = nullptr);
    SAchievementsGlobal(QJsonDocument DocAchievements, QObject *parent = nullptr);
    SAchievementsGlobal(QObject *parent = nullptr): QObject(parent),_manager(new QNetworkAccessManager()){};
    ~SAchievementsGlobal();
    void set(QString appid);
    void set(QJsonDocument DocAchievements);
    void remove(int index);
    QString getAppid();
    StatusValue getStatus();
    QString getError();
    QString getGamename();
    QString getGameversion();
    int getCount();
    void update();
    void clear();
    SAchievementsGlobal(const SAchievementsGlobal &achievements);;
    SAchievementsGlobal &operator=(const SAchievementsGlobal &friends);
    SAchievementGlobal &operator[](const int &a_index);
    QList<SAchievementGlobal>::iterator begin();
    QList<SAchievementGlobal>::iterator end() {return _achievements.end();}

signals:
    void s_finished(SAchievementsGlobal);
    void s_finished();

public slots:
    void onLoad(QNetworkReply *reply);

private:
    QNetworkAccessManager *_manager;
    QList<SAchievementGlobal> _achievements;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _appid="";
    QString _gameName="";
    QString _gameVersion="";
};
class SAchievementsPercentage : public QObject {
    Q_OBJECT
public:
    explicit SAchievementsPercentage(QString appid, bool parallel = true, QObject *parent = nullptr);
    SAchievementsPercentage(QJsonDocument docAchievements, QObject *parent = nullptr);
    SAchievementsPercentage(QObject *parent = nullptr);
    ~SAchievementsPercentage();
    void set(QString appid);
    void set(QJsonDocument docAchievements);
    void remove(int index);
    QString getAppid();
    int getCount();
    StatusValue getStatus();
    QString getError();
    void update();
    void clear();
    SAchievementsPercentage(const SAchievementsPercentage &achievements);;
    SAchievementsPercentage &operator=(const SAchievementsPercentage & friends);
    SAchievementPercentage &operator[](const int &index);
    QList<SAchievementPercentage>::iterator begin() {return _achievements.begin();}
    QList<SAchievementPercentage>::iterator end() {return _achievements.end();}

signals:
    void s_finished(SAchievementsPercentage);
    void s_finished();

public slots:
    void onLoad(QNetworkReply *reply);

private:
    QNetworkAccessManager *_manager;
    QList<SAchievementPercentage> _achievements;
    QString _error = "";
    StatusValue _status = StatusValue::none;
    QString _appid = "";
};
class SAchievementsPlayer : public QObject {
    Q_OBJECT
public:
    explicit SAchievementsPlayer(QString appid, QString id, bool parallel = true, QObject *parent = nullptr);
    SAchievementsPlayer(QJsonDocument docAchievements, QObject *parent = nullptr);
    SAchievementsPlayer(QObject *parent = nullptr);
    ~SAchievementsPlayer();
    void set(QString appid, QString id);
    void set(QJsonDocument docAchievements);
    void remove(int index);
    QString getAppid();
    StatusValue getStatus();
    QString getError();
    QString getGameName();
    int getCount();
    void update();
    void clear();
    SAchievementsPlayer(const SAchievementsPlayer &achievements);
    SAchievementsPlayer &operator=(const SAchievementsPlayer & friends);
    SAchievementPlayer &operator[](const int &index);
    QList<SAchievementPlayer>::iterator begin() {return _achievements.begin();}
    QList<SAchievementPlayer>::iterator end() {return _achievements.end();}

    int _index=0;

signals:
    void s_finished(SAchievementsPlayer);
    void s_finished();

public slots:
    void Load(QNetworkReply *Reply);

private:
    QNetworkAccessManager *_manager;
    QList<SAchievementPlayer> _achievements;
    StatusValue _status=StatusValue::none;
    QString _error="";
    QString _id="";
    QString _appid="";
    QString _gameName="";
};

class SAchievements : public QObject {
    Q_OBJECT
public slots:
    void set(SAchievementsPlayer player);
    void set(SAchievementsGlobal global);
    void set(SAchievementsPercentage percent);

public:
    explicit SAchievements(QString appid, QString id, QObject *parent = nullptr);
    SAchievements(SAchievementsGlobal &a_global, SAchievementsPlayer &Player, SAchievementsPercentage &Percent, QObject *parent = nullptr);
    SAchievements(SAchievementsGlobal &a_global, QObject *parent = nullptr);
    SAchievements(SAchievementsPlayer &a_player, QObject *parent = nullptr);
    SAchievements(SAchievementsPercentage a_percent, QObject *parent = nullptr);
    SAchievements(QObject *parent = nullptr);
    ~SAchievements();
    void set(QString appid, QString id);
    void set(SAchievementsGlobal &Global, SAchievementsPlayer &Player, SAchievementsPercentage &Percent);
    void setFinish();
    StatusValue getStatus();
    QString getError();
    QString getAppid();
    QString getGameName();
    QString getGameVersion();
    int getCount();
    void update();
    void clear();
    void sort();
    SAchievements(const SAchievements &achievements);
    SAchievements &operator=(const SAchievements &friends);
    SAchievement &operator[](const int &index);
    QList<SAchievement>::iterator begin() {return _finish.begin();}
    QList<SAchievement>::iterator end() {return _finish.end();}

    QString _id="";
    QString _appid="";

signals:
    void s_finished(SAchievements*);
    void s_finished();

private slots:
    StatusValue getStatusGlobal() {return _statusGlobal;}
    StatusValue getStatusPlayer() {return _statusPlayer;}
    StatusValue getStatusPercent() {return _statusPercent;}
    QString GetErrorGlobal() {return _errorGlobal;}
    QString GetErrorPlayer() {return _errorPlayer;}
    QString GetErrorPercent() {return _errorPercent;}

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
