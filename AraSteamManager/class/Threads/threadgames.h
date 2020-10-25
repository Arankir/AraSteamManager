#ifndef THREADGAMES_H
#define THREADGAMES_H

#include <QObject>
#include <QTableWidget>
#include "class/steamapi/Sgames.h"
#include "class/Network/requestdata.h"
#include "class/settings.h"
#include <QEventLoop>
#include <QFontDatabase>
#include <QStandardItemModel>

class ThreadGames : public QObject {
    Q_OBJECT
public slots:
    int fill();

public:
    explicit ThreadGames(const int tableColumnAppid, const int tableColumnIndex, const int tableColumnIcon, const int tableColumnName, const int tableColumnComment, const int tableColumnProgress,
        SGames &games, QObject *parent = nullptr): QObject(parent), c_tableColumnAppid(tableColumnAppid), c_tableColumnIcon(tableColumnIcon), c_tableColumnIndex(tableColumnIndex),
        c_tableColumnName(tableColumnName), c_tableColumnComment(tableColumnComment), c_tableColumnProgress(tableColumnProgress), _games(games) {}

    ~ThreadGames() {qInfo() << "Thread games deleted";}

signals:
    void s_finishedModel(QStandardItemModel *model);
    void s_finished();
    void s_progress(int p, int row);

private:
    const int c_tableColumnAppid;
    const int c_tableColumnIcon;
    const int c_tableColumnIndex;
    const int c_tableColumnName;
    const int c_tableColumnComment;
    const int c_tableColumnProgress;
    SGames _games;
};

#endif // THREADGAMES_H
