#ifndef THREADCOMPARE_H
#define THREADCOMPARE_H

#include <QObject>
#include <class/imagerequest.h>

class ThreadCompare : public QObject
{
    Q_OBJECT
public:
    explicit ThreadCompare(QObject* parent = nullptr);

signals:

public slots:
    int Fill();
    void Set();
    void OnResultImage(ImageRequest* imgr);
};

#endif // THREADCOMPARE_H
