#ifndef THREADFRIENDS_H
#define THREADFRIENDS_H

#include <QObject>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QFontDatabase>
#include "classes/steamApi/structures/sfriends.h"
#include "classes/network/requestdata.h"
#include "classes/common/settings.h"
#include "forms/subForms/main/formfriends.h"

class ThreadFriends : public QObject {
    Q_OBJECT
public slots:
    int fill();

public:
    explicit ThreadFriends(QList<QPair<SFriend, SProfile>> friends, QObject *parent = nullptr): QObject(parent), _friends(friends) {}

signals:
    void s_finishedModel(QStandardItemModel *model);
    void s_progress(int p);
    void s_finished();

private:
    QList<QPair<SFriend, SProfile>> _friends;
};

#endif // THREADFRIENDS_H
