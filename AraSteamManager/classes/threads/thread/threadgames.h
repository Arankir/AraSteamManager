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
#include "forms/subForms/main/formgames.h"

class ThreadGames : public QObject {
    Q_OBJECT
public slots:
    int fill();

public:
    explicit ThreadGames(QList<SGame> &games, QObject *parent = nullptr): QObject(parent), _games(games) {}

    ~ThreadGames() {qInfo() << "Thread games deleted";}

signals:
    void s_finishedModel(QStandardItemModel *model);
    void s_finished();
    void s_progress(int p);

private:
    QList<SGame> _games;
};

#endif // THREADGAMES_H
