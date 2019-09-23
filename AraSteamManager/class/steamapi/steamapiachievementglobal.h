#ifndef STEAMAPIACHIEVEMENTGLOBAL_H
#define STEAMAPIACHIEVEMENTGLOBAL_H

#include <QMainWindow>
#include <QObject>
#include <QJsonObject>
#include <QTextCodec>
#include <QDebug>

class SteamAPIAchievementGlobal : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievementGlobal(QJsonObject ObjAchievement, QObject *parent = nullptr);
    SteamAPIAchievementGlobal();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname() {return apiname;}
    int GetDefaultvalue() {return defaultvalue;}
    QString GetDisplayname() {return displayname;}
    int GetHidden() {return hidden;}
    QString GetDescription() {return description;}
    QString GetIcon() {return icon;}
    QString GetIcongray() {return icongray;}
    SteamAPIAchievementGlobal(const SteamAPIAchievementGlobal &);
    SteamAPIAchievementGlobal & operator=(const SteamAPIAchievementGlobal & achievement);

signals:

public slots:

private:
    QString apiname="";
    int defaultvalue=0;
    QString displayname="";
    int hidden=0;
    QString description="";
    QString icon="";
    QString icongray="";
};

#endif // STEAMAPIACHIEVEMENTGLOBAL_H
