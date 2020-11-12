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
    explicit ThreadGames(const int columnAppid, const int columnIndex, const int columnIcon, const int columnName, const int columnComment, const int columnProgress,
                         const int columnCount, SGames &games, QObject *parent = nullptr): QObject(parent), c_columnAppid(columnAppid), c_columnIcon(columnIcon),
        c_columnIndex(columnIndex), c_columnName(columnName), c_columnComment(columnComment), c_columnProgress(columnProgress), c_columnCount(columnCount), _games(games) {}

    ~ThreadGames() {qInfo() << "Thread games deleted";}

signals:
    void s_finishedModel(QStandardItemModel *model);
    void s_finished();
    void s_progress(int p, int row);

private:
    const int c_columnAppid;
    const int c_columnIcon;
    const int c_columnIndex;
    const int c_columnName;
    const int c_columnComment;
    const int c_columnProgress;
    const int c_columnCount;
    SGames _games;
};

#endif // THREADGAMES_H
