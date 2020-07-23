#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include <QWidget>
#include <QFile>
#include <QStandardItem>
#include <class/Network/requestimage.h>
#include <class/steamapi/Sfriends.h>
#include <class/Threads/threading.h>
#include <class/settings.h>
#include <class/favorites.h>
#include <class/filter.h>
#include <subwidget/qbuttonwithdata.h>
#include <QtAlgorithms>

namespace Ui {
class FormFriends;
}

class FormFriends : public QWidget {
    Q_OBJECT

public slots:
    void changeEvent(QEvent *event);
    void progressLoading(int p,int row);
    void onTablePulled();
    void updateSettings();

public:
    explicit FormFriends(QString id, SFriends Friends, QWidget *parent = nullptr);
    ~FormFriends();

signals:
    void s_friendsLoaded(int progress, int row);
    void s_finish();
    void s_return_to_profile(QWidget*);
    void s_go_to_profile(QString id, ProfileUrlType type);

private slots:
    void initComponents();
    void closeEvent(QCloseEvent *event);
    void retranslate();
    void setIcons();
    void updateHiddenRows();
    void friendToUi();
    void createThread();

    void buttonFriendGoTo_Clicked();
    void buttonFriendFavorite_Clicked();

    void checkBoxOpenProfile_StateChanged(int arg1);
    void lineEditName_TextChanged(const QString &arg1);
    void buttonFind_Clicked();
    void comboBoxStatus_Activated(int index);
    void checkBoxFavorites_StateChanged(int arg1);

    void tableWidgetFriends_CellClicked(int row, int col);
    void tableWidgetFriends_CellDoubleClicked(int row, int column);

private:
    Ui::FormFriends *ui;
    QString _id;
    bool _blockedLoad = false;
    SFriends _friends;
    SProfiles _profiles;
    Settings _setting;
    Favorites _favorites;
    Filter _filter;
    QString _currentFriend;
    int _currentFriendIndex = -1;

    //QVector<RequestData*> _request;
    int _numRequests = 0;
    int _numNow = 0;


};

#endif // FORMFRIENDS_H
