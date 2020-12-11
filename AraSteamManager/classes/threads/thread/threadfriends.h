#ifndef THREADFRIENDS_H
#define THREADFRIENDS_H

#include <QObject>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QFontDatabase>
#include "classes/steamApi/structures/sfriends.h"
#include "classes/network/requestdata.h"
#include "classes/common/settings.h"

class ThreadFriends : public QObject {
    Q_OBJECT
public slots:
    int fill();

public:
    explicit ThreadFriends(const int columnID, const int columnIndex, const int columnIcon, const int columnName, const int columnAdded, const int columnStatus, const int columnisPublic,
        QList<QPair<SFriend, SProfile>> friends, QObject *parent = nullptr): QObject(parent), c_tableColumnID(columnID), c_tableColumnIndex(columnIndex), c_tableColumnIcon(columnIcon),
        c_tableColumnName(columnName), c_tableColumnAdded(columnAdded), c_tableColumnStatus(columnStatus), c_tableColumnisPublic(columnisPublic), _friends(friends) {}

signals:
    void s_finishedModel(QStandardItemModel *model);
    void s_progress(int p, int row);
    void s_finished();

private:
    const int c_tableColumnID;
    const int c_tableColumnIndex;
    const int c_tableColumnIcon;
    const int c_tableColumnName;
    const int c_tableColumnAdded;
    const int c_tableColumnStatus;
    const int c_tableColumnisPublic;
    QList<QPair<SFriend, SProfile>> _friends;
    SProfiles _profiles;
};

#endif // THREADFRIENDS_H
