#ifndef SACHIEVEMENTS_H
#define SACHIEVEMENTS_H

#include "../sapi.h"

class SAchievementGlobal : public QObject {
    Q_OBJECT
public:
    explicit SAchievementGlobal(const QJsonObject &achievement, QObject *parent  = nullptr): QObject(parent),
        _apiName(achievement.value("name").toString()), _defaultValue(achievement.value("defaultvalue").toInt()),
        _displayName(achievement.value("displayName").toString()), _hidden(achievement.value("hidden").toInt()),
        _description(achievement.value("description").toString()), _icon(achievement.value("icon").toString()),
        _iconGray(achievement.value("icongray").toString()) {
            //qDebug()<<"SAchievementGlobal constructor"<<_apiName;
        }
     SAchievementGlobal(const SAchievementGlobal &achievement): QObject(achievement.parent()),
         _apiName(achievement._apiName), _defaultValue(achievement._defaultValue), _displayName(achievement._displayName),
         _hidden(achievement._hidden), _description(achievement._description), _icon(achievement._icon), _iconGray(achievement._iconGray) {
             //qDebug()<<"SAchievementGlobal copy"<<_apiName;
         }
     SAchievementGlobal &operator=(const SAchievementGlobal&) {
             //qDebug()<<"SAchievementGlobal equality"<<_apiName;
             return *this;
         }

     QString   apiName()        {return _apiName;}
     int       defaultValue()   {return _defaultValue;}
     QString   displayName()    {return _displayName;}
     int       hidden()         {return _hidden;}
     QString   description()    {return _description;}
     QString   icon()           {return _icon;}
     QString   iconGray()       {return _iconGray;}

private:
    QString   _apiName;
    int       _defaultValue;
    QString   _displayName;
    int       _hidden;
    QString   _description;
    QString   _icon;
    QString   _iconGray;

};
class SAchievementPercentage : public QObject {
    Q_OBJECT
public:
    explicit SAchievementPercentage(const QJsonObject &achievement, QObject *parent = nullptr): QObject(parent),
        _apiName(achievement.value("name").toString()), _percent(achievement.value("percent").toDouble()) {
            //qDebug()<<"SAchievementPercentage constructor"<<_apiName;
        }
    SAchievementPercentage(const SAchievementPercentage &achievement): QObject(achievement.parent()),
        _apiName(achievement._apiName), _percent(achievement._percent) {
            //qDebug()<<"SAchievementPercentage copy"<<_apiName;
        }
    SAchievementPercentage &operator=(const SAchievementPercentage&) {
            //qDebug()<<"SAchievementPercentage equality"<<_apiName;
            return *this;
        }

    QString apiName() {return _apiName;}
    double percent() {return _percent;}

private:
    QString   _apiName;
    double    _percent;

};
class SAchievementPlayer : public QObject {
    Q_OBJECT
public:
    explicit SAchievementPlayer(const QJsonObject &achievement, QObject *parent = nullptr): QObject(parent),
        _apiName(achievement.value("apiname").toString()), _achieved(achievement.value("achieved").toInt()),
        _unlockTime(QDateTime::fromSecsSinceEpoch(achievement.value("unlocktime").toInt(), Qt::LocalTime)) {
            //qDebug()<<"SAchievementPlayer constructor"<<_apiName;
        }
    SAchievementPlayer(const SAchievementPlayer &achievement): QObject(achievement.parent()),
        _apiName(achievement._apiName), _achieved(achievement._achieved), _unlockTime(achievement._unlockTime) {
            //qDebug()<<"SAchievementPlayer copy"<<_apiName;
        }
    SAchievementPlayer &operator=(const SAchievementPlayer &) {
            //qDebug()<<"SAchievementPlayer equality"<<_apiName;
            return *this;
        }

    QString apiName() {return _apiName;}
    int achieved() {return _achieved;}
    QDateTime unlockTime() {return _unlockTime;}

private:
    QString   _apiName;
    int       _achieved;
    QDateTime _unlockTime;

};

class SAchievement : public QObject {
    Q_OBJECT
public:
    explicit SAchievement(SAchievementGlobal &global, SAchievementPlayer &player, SAchievementPercentage &percent, QObject *parent = nullptr);
             SAchievement(const SAchievement &achievement);
             SAchievement(const QJsonObject &object);
             SAchievement(const QString &text);
    SAchievement &  operator=(const SAchievement &achievement);
    bool            operator<(const SAchievement &achievement);

    QString toString() const;

    QPixmap icon     (int gameId);
    QPixmap iconGray (int gameId);

    QString   apiName()         const {return _apiName;}
    int       defaultValue()    const {return _defaultValue;}
    QString   displayName()     const {return _displayName;}
    int       hidden()          const {return _hidden;}
    QString   description()     const {return _description;}
    int       achieved()        const {return _achieved;}
    QDateTime unlockTime()      const {return _unlockTime;}
    double    percent()         const {return _percent;}
    QString   iconPath()        const {return _icon;}
    QString   iconGrayPath()    const {return _iconGray;}

    friend QDebug operator<<(QDebug dbg, const SAchievement &a) {
        dbg.nospace() << "Achievement(" << a.toString() << ")\n";
        return dbg.space();
    }

private:
    QString   _apiName;
    int       _defaultValue;
    QString   _displayName;
    int       _hidden;
    QString   _description;
    int       _achieved;
    QDateTime _unlockTime;
    double    _percent;
    QString _icon;
    QString _iconGray;

    QPixmap _pixmapIcon;
    QPixmap _pixmapIconGray;
};

class SAchievementsGlobal : public Sapi {
    Q_OBJECT
public:
    explicit SAchievementsGlobal(const QString &appid, bool parallel = true);
    SAchievementsGlobal(Sapi *parent = nullptr): Sapi(parent) {};
    SAchievementsGlobal(const SAchievementsGlobal &achievements): Sapi(achievements), _achievements(achievements._achievements),
        _appid(achievements._appid), _gameName(achievements._gameName), _gameVersion(achievements._gameVersion) {
            //qDebug()<<"SAchievementsGlobal copy"<<_appid;
        }
    ~SAchievementsGlobal() {};

    SAchievementsGlobal &operator=(const SAchievementsGlobal &friends);
    SAchievementGlobal &operator[](const int &index) {return _achievements[index];};

    SAchievementsGlobal &load(const QString &appid, bool paralell);
    SAchievementsGlobal &update(bool paralell = false);
    SAchievementsGlobal &clear();

    SAchievementsGlobal &remove(int index);
    QList<SAchievementGlobal>::iterator begin() {return _achievements.begin();}
    QList<SAchievementGlobal>::iterator end() {return _achievements.end();}
    QString appid()         const {return _appid;}
    QString gameName()      const {return _gameName;}
    QString gameVersion()   const {return _gameVersion;}
    int count()             const {return _achievements.size();}

signals:
    void s_finished();

private slots:
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QList<SAchievementGlobal> _achievements;
    QString _appid = "";
    QString _gameName = "";
    QString _gameVersion = "";
};
class SAchievementsPercentage : public Sapi {
    Q_OBJECT
public:
    explicit SAchievementsPercentage(const QString &appid, bool parallel = true);
    SAchievementsPercentage(Sapi *parent = nullptr): Sapi(parent) {/*qDebug() << "constructor 3";*/};
    SAchievementsPercentage(const SAchievementsPercentage &achievements): Sapi(achievements), _achievements(achievements._achievements),
        _appid(achievements._appid) {/*qDebug() << "copy" << _appid;*/};
    ~SAchievementsPercentage() {/*qDebug() << "deleted" << _appid;*/};

    SAchievementsPercentage &operator=(const SAchievementsPercentage &friends);
    SAchievementPercentage &operator[](const int &index) {return _achievements[index];};

    SAchievementsPercentage &load(const QString &appid, bool paralell);
    SAchievementsPercentage &update(bool paralell = false);
    SAchievementsPercentage &clear();

    SAchievementsPercentage &remove(int index);;
    QList<SAchievementPercentage>::iterator begin() {return _achievements.begin();}
    QList<SAchievementPercentage>::iterator end() {return _achievements.end();}
    QString appid() const {return _appid;};
    int count()     const {return _achievements.size();};

signals:
    void s_finished();

private slots:
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QList<SAchievementPercentage> _achievements;
    QString _appid = "";
};
class SAchievementsPlayer : public Sapi {
    Q_OBJECT
public:
    explicit SAchievementsPlayer(const QString &appid, const QString &id, bool parallel = true);
    SAchievementsPlayer(Sapi *parent = nullptr): Sapi(parent) {/*qDebug()<<"constructor 3";*/};
    SAchievementsPlayer(const SAchievementsPlayer &achievements): Sapi(achievements), _achievements(achievements._achievements),
        _id(achievements._id), _appid(achievements._appid), _gameName(achievements._gameName) {/*qDebug() << "copy" << _appid << _id;*/};
    ~SAchievementsPlayer() {/*qDebug() << "deleted" << _appid << _id;*/};

    SAchievementsPlayer &operator=(const SAchievementsPlayer &friends);
    SAchievementPlayer &operator[](const int &index) {return _achievements[index];}

    SAchievementsPlayer &load(const QString &appid, const QString &id, bool paralell);
    SAchievementsPlayer &update(bool paralell = false);
    SAchievementsPlayer &clear();

    SAchievementPlayer at(const int &index) {return _achievements[index];}
    SAchievementsPlayer &remove(int index);
    QList<SAchievementPlayer>::iterator begin() {return _achievements.begin();}
    QList<SAchievementPlayer>::iterator end() {return _achievements.end();}
    QString appid()      const {return _appid;}
    QString gameName()   const {return _gameName;}
    int reached()        const {return _reached;}
    int notReached()     const {return _notReached;}
    int count()          const {return _achievements.size();}

signals:
    void s_finished(SAchievementsPlayer*);

private slots:
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QList<SAchievementPlayer> _achievements;
    QString _id = "";
    QString _appid = "";
    QString _gameName = "";
    int _reached = 0;
    int _notReached = 0;
};

class SAchievements : public QObject {
    Q_OBJECT
public slots:
    SAchievements &set(const SAchievementsPlayer &player);
    SAchievements &set(const SAchievementsGlobal &global);
    SAchievements &set(const SAchievementsPercentage &percent);

public:
    explicit SAchievements(const QString &appid, const QString &id, bool paralell = true, QObject *parent = nullptr);
    SAchievements(const SAchievementsGlobal &global, const SAchievementsPlayer &player, const SAchievementsPercentage &percent, QObject *parent = nullptr);
    SAchievements(const SAchievementsGlobal &global, QObject *parent = nullptr): SAchievements(global, SAchievementsPlayer(), SAchievementsPercentage(), parent) {
        /*qDebug() << "constructor g";*/};
    SAchievements(const SAchievementsPlayer &player, QObject *parent = nullptr): SAchievements(SAchievementsGlobal(), player, SAchievementsPercentage(), parent) {
        /*qDebug() << "constructor pl";*/};
    SAchievements(const SAchievementsPercentage &percent, QObject *parent = nullptr): SAchievements(SAchievementsGlobal(), SAchievementsPlayer(), percent, parent) {
        /*qDebug() << "constructor per";*/};
    SAchievements(QObject *parent = nullptr): SAchievements(SAchievementsGlobal(), SAchievementsPlayer(), SAchievementsPercentage(), parent) {
        /*qDebug() << "constructor none";*/};
    SAchievements(const SAchievements &achievements): QObject(achievements.parent()),// _id(achievements._id), _appid(achievements._appid),
        _global(achievements._global), _player(achievements._player), _percent(achievements._percent), _finish(achievements._finish),
        _status(achievements._status), _error(achievements._error), _gameName(achievements._gameName), _gameVersion(achievements._gameVersion) {
            /*qDebug() << "copy" << achievements._global.isLoad() << achievements._player.isLoad() << achievements._percent.isLoad()*/;}
    ~SAchievements() {/*qDebug() << "deleted" << _appid << _id*/;}

    SAchievements &operator=(const SAchievements &friends);
    SAchievement &operator[](const int &index) {return _finish[index];}

    SAchievements &load(const QString &appid, const QString &id, bool paralell);
    SAchievements &set(SAchievementsGlobal &global, SAchievementsPlayer &player, SAchievementsPercentage &percent);
    SAchievements &update(bool paralell = true);
    SAchievements &clear();

    SAchievements &sort();
    QList<SAchievement>::iterator begin() {return _finish.begin();}
    QList<SAchievement>::iterator end() {return _finish.end();}
    StatusValue status()     const {return _status;}
    QString error()          const {return _error;}
    QString gameName()       const {return _gameName;}
    QString gameVersion()    const {return _gameVersion;}
    int count()              const {return _finish.size();}

signals:
    void s_finished();

private slots:
    SAchievements &setFinish();
    void initConnects();
    void setStatus(StatusValue status);

private:
    SAchievementsGlobal _global;
    SAchievementsPlayer _player;
    SAchievementsPercentage _percent;

    QList<SAchievement> _finish;
    StatusValue _status = StatusValue::none;
    QString _error = "";
    QString _gameName = "";
    QString _gameVersion = "";
};

#endif // SACHIEVEMENTS_H
