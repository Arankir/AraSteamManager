#ifndef THREADFRIENDS_H
#define THREADFRIENDS_H

#include <QObject>
#include <QTableWidget>
#include <QStandardItemModel>
#include <class/steamapi/Sfriends.h>
#include <class/Network/requestdata.h>
#include <class/settings.h>
#include <QFontDatabase>

class ThreadFriends : public QObject
{
    Q_OBJECT
public:
    explicit ThreadFriends(const int a_columnID, const int a_columnName, const int a_columnAdded, const int a_columnStatus, const int a_columnisPublic,
                           QTableWidget *a_TableWidgetFriends, SProfiles a_profiles,SFriends a_friends, QObject *a_parent = nullptr)
    :QObject(a_parent),c_tableColumnID(a_columnID),c_tableColumnName(a_columnName),c_tableColumnAdded(a_columnAdded),c_tableColumnStatus(a_columnStatus),c_tableColumnisPublic(a_columnisPublic),
    _friends(a_friends),_profiles(a_profiles),_TableWidgetFriends(a_TableWidgetFriends){};

signals:
    void s_finished();
    void s_progress(int p, int row);

public slots:
    int Fill();

private:
    const int c_tableColumnID;
    const int c_tableColumnName;
    const int c_tableColumnAdded;
    const int c_tableColumnStatus;
    const int c_tableColumnisPublic;
    QTableWidgetItem *GetState(QString gameExtraInfo, int personaState);
    QTableWidgetItem *GetPrivacy(int communityVisibilityState);
    SFriends _friends;
    SProfiles _profiles;
    Settings _setting;
    QTableWidget *_TableWidgetFriends;
};

#endif // THREADFRIENDS_H
