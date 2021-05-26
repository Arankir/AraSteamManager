#ifndef THREADFRIENDS_H
#define THREADFRIENDS_H

#include <QObject>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QFontDatabase>
#include "classes/steamApi/structures/sfriends.h"
#include "classes/network/requestdata.h"
#include "classes/common/settings.h"
#include "../threadloading.h"
#include "forms/subForms/main/formfriends.h"

class ThreadFriends : public ThreadLoading {
    Q_OBJECT
private slots:
    int fill();

public:
    explicit ThreadFriends(const QList<QPair<SFriend, SProfile>> &friends): _friends(friends) {}

    ~ThreadFriends() {qInfo() << "Thread friends deleted";}

signals:
    void s_finishedModel(QStandardItemModel *model);
    void s_progress(const int &p);
//    void s_finished();

private:
    QList<QPair<SFriend, SProfile>> _friends;
};

#endif // THREADFRIENDS_H
