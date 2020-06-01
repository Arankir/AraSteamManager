#ifndef THREADFRIENDS_H
#define THREADFRIENDS_H

#include <QObject>
#include <QTableWidget>
#include <QStandardItemModel>
#include <class/steamapi/Sfriends.h>
#include <class/Network/requestdata.h>
#include <class/settings.h>
#include <QFontDatabase>

class ThreadFriends : public QObject {
    Q_OBJECT
public slots:
    int fill();

public:
    explicit ThreadFriends(const int a_columnID, const int a_columnName, const int a_columnAdded, const int a_columnStatus, const int a_columnisPublic,
                           QTableWidget *a_TableWidgetFriends, SProfiles a_profiles,SFriends a_friends, QObject *a_parent = nullptr);

signals:
    void s_finished();
    void s_progress(int p, int row);

private slots:
    QTableWidgetItem *getState(QString gameExtraInfo, int personaState);
    QTableWidgetItem *getPrivacy(int communityVisibilityState);

private:
    const int c_tableColumnID;
    const int c_tableColumnName;
    const int c_tableColumnAdded;
    const int c_tableColumnStatus;
    const int c_tableColumnisPublic;
    SFriends _friends;
    SProfiles _profiles;
    Settings _setting;
    QTableWidget *_tableWidgetFriends;
};

#endif // THREADFRIENDS_H
