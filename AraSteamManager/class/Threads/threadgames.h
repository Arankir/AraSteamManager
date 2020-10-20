#ifndef THREADGAMES_H
#define THREADGAMES_H

#include <QObject>
#include <QTableWidget>
#include "class/steamapi/Sgames.h"
#include "class/Network/requestdata.h"
#include "class/settings.h"
#include <QEventLoop>
#include <QFontDatabase>

class ThreadGames : public QObject {
    Q_OBJECT
public slots:
    int fill();

public:
    explicit ThreadGames(const int tableColumnAppid, const int tableColumnIndex, const int tableColumnName, QTableWidget *tableWidgetGames,
        SGames &games, QObject *parent = nullptr): QObject(parent), c_tableColumnAppid(tableColumnAppid), c_tableColumnIndex(tableColumnIndex),
        c_tableColumnName(tableColumnName), _games(games), _TableWidgetGames(tableWidgetGames) {}

    ~ThreadGames() {qInfo() << "Thread games deleted";}

signals:
    void s_finished();
    void s_progress(int p, int row);

private:
    const int c_tableColumnAppid;
    const int c_tableColumnIndex;
    const int c_tableColumnName;
    SGames _games;
    QTableWidget *_TableWidgetGames;
};

#endif // THREADGAMES_H
