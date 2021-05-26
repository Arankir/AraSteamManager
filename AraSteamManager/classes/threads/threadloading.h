#ifndef THREADLOADING_H
#define THREADLOADING_H

#include <QObject>
#include <QThread>
#include <QDebug>

class ThreadInfo: public QThread {
public:
    ~ThreadInfo() {qInfo() << "Thread deleted";}
};

class ThreadLoading : public QObject {
    Q_OBJECT
public slots:
    void start() {_thread->start();}

private slots:
    virtual int fill() = 0;

public:
    ThreadLoading();
    ~ThreadLoading();

signals:
    void s_finished();

private:
    ThreadInfo *_thread;

};

#endif // THREADLOADING_H
