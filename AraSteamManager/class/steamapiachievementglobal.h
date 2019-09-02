#ifndef STEAMAPIACHIEVEMENTGLOBAL_H
#define STEAMAPIACHIEVEMENTGLOBAL_H

#include <QMainWindow>
#include <QObject>
#include <QJsonObject>
#include <QTextCodec>

class SteamAPIAchievementGlobal : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievementGlobal(QJsonObject ObjAchievement, QObject *parent = nullptr);
    SteamAPIAchievementGlobal();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname();
    int GetDefaultvalue();
    QString GetDisplayname();
    int GetHidden();
    QString GetDescription();
    QString GetIcon();
    QString GetIcongray();
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
