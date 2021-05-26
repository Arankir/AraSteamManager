#ifndef THREADGAMES_H
#define THREADGAMES_H

#include <QObject>
#include <QTableWidget>
#include <QEventLoop>
#include <QFontDatabase>
#include <QStandardItemModel>
#include "classes/steamApi/structures/sgames.h"
#include "classes/network/requestdata.h"
#include "classes/common/settings.h"
#include "../threadloading.h"
#include "forms/subForms/main/formgames.h"

class ThreadGames : public ThreadLoading {
    Q_OBJECT
private slots:
    int fill();

public:
    explicit ThreadGames(const SGames &games): _games(games) {}

    ~ThreadGames() {qInfo() << "Thread games deleted";}

signals:
    void s_finishedModel(QStandardItemModel *model);
//    void s_finished();
    void s_progress(const int &p);

private:
    SGames _games;
};

#endif // THREADGAMES_H
