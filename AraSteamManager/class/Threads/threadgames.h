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
    explicit ThreadGames(const int a_tableColumnAppid, const int a_tableColumnIndex, const int a_tableColumnName,
                         QTableWidget *a_tableWidgetGames, SGames a_games, QObject *a_parent = nullptr)
    :QObject(a_parent),c_tableColumnAppid(a_tableColumnAppid),c_tableColumnIndex(a_tableColumnIndex),c_tableColumnName(a_tableColumnName),
    _games(a_games),_TableWidgetGames(a_tableWidgetGames){};

signals:
    void s_finished();
    void s_progress(int p, int row);

public slots:
    int Fill();

private:
    const int c_tableColumnAppid;
    const int c_tableColumnIndex;
    const int c_tableColumnName;
    SGames _games;
    QTableWidget *_TableWidgetGames;
};

#endif // THREADGAMES_H
