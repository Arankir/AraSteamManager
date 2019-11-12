#ifndef THREADGAMES_H
#define THREADGAMES_H

#include <QObject>
#include <class/imagerequest.h>
#include <QLabel>
#include <QTableWidget>
#include <class/steamapi/Sgame.h>
#include <QPushButton>

class ThreadGames : public QObject
{
    Q_OBJECT
public:
    explicit ThreadGames(QObject *parent = nullptr);

signals:
    void finished();
    void progress(int p, int row);
    void setimage(QPixmap, int row);

public slots:
    int Fill();
    void Set(QTableWidget *TableWidgetGames, QVector<SGame> games, QString key, QIcon Favorite, QString AchievementsLocalisation);
    void OnResultImage(ImageRequest *imgr);
    void OnResultAchievements(ImageRequest *imgr);

public:
    int numrequests;
    int numnow;
    QIcon Favorite;
    QString AchievementsLocalisation;
    QString key;
    QVector<SGame> games;
    QTableWidget *TableWidgetGames;
    QVector<ImageRequest*> request;
};

#endif // THREADGAMES_H
