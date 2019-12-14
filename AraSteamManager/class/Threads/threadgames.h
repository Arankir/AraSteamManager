#ifndef THREADGAMES_H
#define THREADGAMES_H

#include <QObject>
#include <QTableWidget>
#include <class/steamapi/Sgame.h>
#include <class/imagerequest.h>
#include <QEventLoop>
#include <QPushButton>

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
    void Set(QTableWidget *TableWidgetGames, QVector<SGame> games);

private:
    QVector<SGame> _games;
    QTableWidget *_TableWidgetGames;
};

#endif // THREADGAMES_H
