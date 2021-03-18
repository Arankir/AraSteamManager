#ifndef SACHIEVEMENTS_H
#define SACHIEVEMENTS_H

#include "../sapi.h"

class SAchievementSchema : public Sapi {
    Q_OBJECT
public:
    SAchievementSchema() {};
    explicit SAchievementSchema(const QJsonObject &object, QObject *parent  = nullptr): Sapi(parent),
        _apiName(object.value("name").toString()), _defaultValue(object.value("defaultvalue").toInt()),
        _displayName(object.value("displayName").toString()), _hidden(object.value("hidden").toInt()),
        _description(object.value("description").toString()), _icon(object.value("icon").toString()),
        _iconGray(object.value("icongray").toString()) {
            //qDebug()<<"SAchievementGlobal constructor"<<_apiName;
        }
     SAchievementSchema(const SAchievementSchema &global): Sapi(global.parent()),
         _apiName(global._apiName), _defaultValue(global._defaultValue), _displayName(global._displayName),
         _hidden(global._hidden), _description(global._description), _icon(global._icon), _iconGray(global._iconGray) {
             //qDebug()<<"SAchievementGlobal copy"<<_apiName;
         }
     SAchievementSchema &operator=(const SAchievementSchema&) {
             //qDebug()<<"SAchievementGlobal equality"<<_apiName;
             return *this;
         }
     
     QJsonObject toJson() const;
     virtual QString className() const {return "SAchievementSchema";}
     static QList<SAchievementSchema> load(const QString &appid, std::function<void (QList<SAchievementSchema>)> aCallback = nullptr);

     QString   apiName()       const {return _apiName;}
     int       defaultValue()  const {return _defaultValue;}
     QString   displayName()   const {return _displayName;}
     int       hidden()        const {return _hidden;}
     QString   description()   const {return _description;}
     QString   icon()          const {return _icon;}
     QString   iconGray()      const {return _iconGray;}

private:
    QString   _apiName;
    int       _defaultValue;
    QString   _displayName;
    int       _hidden;
    QString   _description;
    QString   _icon;
    QString   _iconGray;

};
class SAchievementPercentage : public Sapi {
    Q_OBJECT
public:
    SAchievementPercentage() {};
    explicit SAchievementPercentage(const QJsonObject &achievement, QObject *parent = nullptr): Sapi(parent),
        _apiName(achievement.value("name").toString()), _percent(achievement.value("percent").toDouble()) {
            //qDebug()<<"SAchievementPercentage constructor"<<_apiName;
        }
    SAchievementPercentage(const SAchievementPercentage &achievement): Sapi(achievement.parent()),
        _apiName(achievement._apiName), _percent(achievement._percent) {
            //qDebug()<<"SAchievementPercentage copy"<<_apiName;
        }
    SAchievementPercentage &operator=(const SAchievementPercentage&) {
            //qDebug()<<"SAchievementPercentage equality"<<_apiName;
            return *this;
        }

    QJsonObject toJson() const;
    virtual QString className() const {return "SAchievementPercentage";}
    static QList<SAchievementPercentage> load(const QString &appid, std::function<void (QList<SAchievementPercentage>)> aCallback = nullptr);

    QString apiName() const {return _apiName;}
    double percent() const {return _percent;}

private:
    QString   _apiName;
    double    _percent;

};
class SAchievementPlayer : public Sapi {
    Q_OBJECT
public:
    SAchievementPlayer() {};
    explicit SAchievementPlayer(const QJsonObject &achievement, QObject *parent = nullptr): Sapi(parent),
        _apiName(achievement.value("apiname").toString()), _achieved(achievement.value("achieved").toInt()),
        _unlockTime(QDateTime::fromSecsSinceEpoch(achievement.value("unlocktime").toInt(), Qt::LocalTime)) {
            //qDebug()<<"SAchievementPlayer constructor"<<_apiName;
        }
    SAchievementPlayer(const SAchievementPlayer &achievement): Sapi(achievement.parent()),
        _apiName(achievement._apiName), _achieved(achievement._achieved), _unlockTime(achievement._unlockTime) {
            //qDebug()<<"SAchievementPlayer copy"<<_apiName;
        }
    SAchievementPlayer &operator=(const SAchievementPlayer &) {
            //qDebug()<<"SAchievementPlayer equality"<<_apiName;
            return *this;
        }

    QJsonObject toJson() const;
    virtual QString className() const {return "SAchievementPlayer";}
    static QList<SAchievementPlayer> load(const QString &appid, const QString &id, std::function<void (QList<SAchievementPlayer>)> aCallback = nullptr);

    QString apiName() const {return _apiName;}
    int achieved() const {return _achieved;}
    QDateTime unlockTime() const {return _unlockTime;}

private:
    QString   _apiName;
    int       _achieved;
    QDateTime _unlockTime;

};

class SAchievement : public Sapi {
    Q_OBJECT
public:
    explicit SAchievement(const SAchievementSchema &global, const SAchievementPlayer &player, const SAchievementPercentage &percent, QObject *parent = nullptr):
        Sapi(parent), _schema(global), _percentage(percent), _player(player) {
        //qDebug()<<"SAchievement constructor"<<_apiName;
    }
    SAchievement(const SAchievement &achievement): Sapi(achievement.parent()), _schema(achievement._schema),
        _percentage(achievement._percentage), _player(achievement._player) {
        //qDebug()<<"SAchievement copy"<<_apiName;
    }
    SAchievement(const QJsonObject &object): _schema(object.value("schema").toObject()),
        _percentage(object.value("percent").toObject()),
        _player(object.value("player").toObject()) {
        //qDebug() << "SAchievement constructor 1" << aObject;
    }
    SAchievement(const QString &text): SAchievement(QJsonDocument::fromJson(text.toUtf8()).object()) {
        //qDebug() << "SAchievement constructor 2" << aText;
    }
    SAchievement &  operator=(const SAchievement &achievement);
    bool            operator<(const SAchievement &achievement) const;

    bool isValid() const {return (_schema.apiName() == _percentage.apiName()) && (_percentage.apiName() == _player.apiName());}
    QJsonObject toJson() const;
    virtual QString className() const {return "SAchievement";}

    QPixmap icon     (int gameId);
    QPixmap iconGray (int gameId);

    QString   apiName()         const {return _schema.apiName();}
    int       defaultValue()    const {return _schema.defaultValue();}
    QString   displayName()     const {return _schema.displayName();}
    int       hidden()          const {return _schema.hidden();}
    QString   description()     const {return _schema.description();}
    int       achieved()        const {return _player.achieved();}
    QDateTime unlockTime()      const {return _player.unlockTime();}
    double    percent()         const {return _percentage.percent();}
    QString   iconPath()        const {return _schema.icon();}
    QString   iconGrayPath()    const {return _schema.iconGray();}

private:
    SAchievementSchema _schema;
    SAchievementPercentage _percentage;
    SAchievementPlayer _player;

    QPixmap _pixmapIcon;
    QPixmap _pixmapIconGray;
};

QList<SAchievement> UniteAchievement(const QList<SAchievementSchema> &global, const QList<SAchievementPercentage> &percent, const QList<SAchievementPlayer> &player);

#endif // SACHIEVEMENTS_H
