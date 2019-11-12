#ifndef THREADACHIEVEMENTS_H
#define THREADACHIEVEMENTS_H

#include <QObject>
#include <class/imagerequest.h>

class ThreadAchievements : public QObject
{
    Q_OBJECT
public:
    explicit ThreadAchievements(QObject *parent = nullptr);

signals:

public slots:
    int Fill();
    void Set();
    void OnResultImage(ImageRequest *imgr);
};

#endif // THREADACHIEVEMENTS_H
