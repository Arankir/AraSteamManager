#ifndef THREADGAMES_H
#define THREADGAMES_H

#include <QObject>
#include <QTableWidget>
#include <class/steamapi/Sgames.h>
#include <class/Network/requestdata.h>
#include <QEventLoop>

class ThreadGames : public QObject
{
    Q_OBJECT
public:
    explicit ThreadGames(QObject *parent = nullptr);

signals:
    void s_finished();
    void s_progress(int p, int row);

public slots:
    int Fill();
    void Set(QTableWidget *TableWidgetGames, SGames games);

private:
    SGames _games;
    QTableWidget *_TableWidgetGames;
};

#endif // THREADGAMES_H
