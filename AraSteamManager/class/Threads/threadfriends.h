#ifndef THREADFRIENDS_H
#define THREADFRIENDS_H

#include <QObject>
#include <QTableWidget>
#include <class/steamapi/Sfriends.h>
#include <class/imagerequest.h>

class ThreadFriends : public QObject
{
    Q_OBJECT
public:
    explicit ThreadFriends(QObject* parent = nullptr);

signals:
    void finished();
    void progress(int p, int row);
    void setimage(QPixmap, int row);

public slots:
    int Fill();
    void Set(QTableWidget* TableWidgetFriends,QVector<SProfile> Profiles,SFriends Friends,QStringList Words);
    void OnResultImage(ImageRequest* imgr);

private:
    int numrequests;
    int numnow;
    QVector<ImageRequest*> request;

    SFriends Friends;
    QVector<SProfile> Profiles;
    QStringList Words;
    QTableWidget* TableWidgetFriends;
};

#endif // THREADFRIENDS_H
