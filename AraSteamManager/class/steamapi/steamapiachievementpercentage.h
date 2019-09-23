#ifndef STEAMAPIACHIEVEMENTPERCENTAGE_H
#define STEAMAPIACHIEVEMENTPERCENTAGE_H

#include <QMainWindow>
#include <QObject>
#include <QJsonObject>
#include <QTextCodec>

class SteamAPIAchievementPercentage : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievementPercentage(QJsonObject ObjAchievement, QObject *parent = nullptr);
    SteamAPIAchievementPercentage();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname() {return apiname;}
    double GetPercent() {return percent;}
    SteamAPIAchievementPercentage(const SteamAPIAchievementPercentage & achievement);
    SteamAPIAchievementPercentage & operator=(const SteamAPIAchievementPercentage & achievement);

signals:

public slots:

private:
    QString apiname="";
    double percent=0.0;
};

#endif // STEAMAPIACHIEVEMENTPERCENTAGE_H
