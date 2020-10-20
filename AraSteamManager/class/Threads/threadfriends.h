#ifndef THREADFRIENDS_H
#define THREADFRIENDS_H

#include <QObject>
#include <QTableWidget>
#include <QStandardItemModel>
#include "class/steamapi/Sfriends.h"
#include "class/Network/requestdata.h"
#include "class/settings.h"
#include <QFontDatabase>

class ThreadFriends : public QObject {
    Q_OBJECT
public slots:
    int fill();

public:
    explicit ThreadFriends(const int columnID, const int columnName, const int columnAdded, const int columnStatus, const int columnisPublic,
                           QTableWidget *TableWidgetFriends, QList<QPair<SFriend, SProfile>> friends, QObject *parent = nullptr):
        QObject(parent), c_tableColumnID(columnID), c_tableColumnName(columnName), c_tableColumnAdded(columnAdded), c_tableColumnStatus(columnStatus),
        c_tableColumnisPublic(columnisPublic), _friends(friends), _tableWidgetFriends(TableWidgetFriends) {}

signals:
    void s_finished();
    void s_progress(int p, int row);

private slots:
    QTableWidgetItem *getState(const QString &gameExtraInfo, int personaState);
    QTableWidgetItem *getPrivacy(int communityVisibilityState);

private:
    const int c_tableColumnID;
    const int c_tableColumnName;
    const int c_tableColumnAdded;
    const int c_tableColumnStatus;
    const int c_tableColumnisPublic;
    QList<QPair<SFriend, SProfile>> _friends;
    SProfiles _profiles;
    QTableWidget *_tableWidgetFriends;
};

#endif // THREADFRIENDS_H
