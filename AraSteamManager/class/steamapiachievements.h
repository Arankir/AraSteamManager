#ifndef STEAMAPIACHIEVEMENTS_H
#define STEAMAPIACHIEVEMENTS_H

#include <QMainWindow>
#include <QObject>

class SteamAPIAchievements : public QObject
{
    Q_OBJECT
public:
    explicit SteamAPIAchievements(QObject *parent = nullptr);

signals:

public slots:
};

#endif // STEAMAPIACHIEVEMENTS_H
