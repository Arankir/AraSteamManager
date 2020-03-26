#ifndef THREADFRIENDS_H
#define THREADFRIENDS_H

#include <QObject>
#include <QTableWidget>
#include <QStandardItemModel>
#include <class/steamapi/Sfriends.h>
#include <class/Network/requestdata.h>

class ThreadFriends : public QObject
{
    Q_OBJECT
public:
    explicit ThreadFriends(QObject *parent = nullptr);

signals:
    void s_finished();
    void s_progress(int p, int row);

public slots:
    int Fill();
    void Set(QTableWidget *TableWidgetFriends, SProfiles Profiles,SFriends Friends);

private:
    SFriends _friends;
    SProfiles _profiles;
    QTableWidget *_TableWidgetFriends;
};

#endif // THREADFRIENDS_H
