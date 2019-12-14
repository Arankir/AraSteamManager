#ifndef SACHIEVEMENTGLOBAL_H
#define SACHIEVEMENTGLOBAL_H

#include <QMainWindow>
#include <QObject>
#include <QJsonObject>
#include <QTextCodec>
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

#endif // SACHIEVEMENTGLOBAL_H
