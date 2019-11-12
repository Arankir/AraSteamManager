#ifndef THREADFRIENDS_H
#define THREADFRIENDS_H

#include <QObject>
#include <class/imagerequest.h>

class ThreadFriends : public QObject
{
    Q_OBJECT
public:
    explicit ThreadFriends(QObject *parent = nullptr);

signals:

public slots:
    int Fill();
    void Set();
    void OnResultImage(ImageRequest *imgr);
};

#endif // THREADFRIENDS_H
