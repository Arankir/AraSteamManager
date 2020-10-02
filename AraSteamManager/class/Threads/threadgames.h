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
    explicit ThreadGames(const int a_tableColumnAppid, const int a_tableColumnIndex, const int a_tableColumnName, QTableWidget *a_tableWidgetGames,
                         SGames &a_games, QObject *a_parent = nullptr);

    ~ThreadGames();
signals:
    void s_finished();
    void s_progress(int p, int row);

private:
    const int c_tableColumnAppid;
    const int c_tableColumnIndex;
    const int c_tableColumnName;
    SGames _games;
    Settings _setting;
    QTableWidget *_TableWidgetGames;
};

#endif // THREADGAMES_H
