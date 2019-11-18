#ifndef THREADACHIEVEMENTS_H
#define THREADACHIEVEMENTS_H

#include <QObject>
#include <QTableWidget>
#include <QLabel>
#include <class/imagerequest.h>
#include <class/steamapi/Sachievements.h>

class ThreadAchievements : public QObject
{
    Q_OBJECT
public:
    explicit ThreadAchievements(QObject* parent = nullptr);

signals:
    void finished();
    void progress(int p, int row);
    void setimage(QPixmap, int row);

public slots:
    int Fill();
    void Set(QString GameAppID, SAchievements achievements, QStringList Words, QLabel* LabelTotalPersent, QTableWidget* TableWidgetAchievements);
    void OnResultImage(ImageRequest* imgr);

private:
    int numrequests;
    int numnow;
    QVector<ImageRequest*> request;

    QString GameAppID;
    SAchievements achievements;
    QStringList Words;
    QLabel* LabelTotalPersent;
    QTableWidget* TableWidgetAchievements;
};

#endif // THREADACHIEVEMENTS_H
