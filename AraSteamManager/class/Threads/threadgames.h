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
    void finished();
    void progress(int p, int row);

public slots:
    int Fill();
    void Set(QTableWidget *TableWidgetGames, QVector<SGame> games);

private:
    QVector<SGame> games;
    QTableWidget *TableWidgetGames;
};

#endif // THREADGAMES_H
