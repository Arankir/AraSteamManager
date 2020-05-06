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

class FormFriends : public QWidget
{
    Q_OBJECT

public:
    explicit FormFriends(QString id, SFriends Friends, QWidget *parent = nullptr);
    ~FormFriends();

signals:
    void s_return_to_profile(QWidget*);
    void s_go_to_profile(QString id, QueryType type);

public slots:
    void changeEvent(QEvent *event);
    void ProgressLoading(int p,int row);
    void OnFinish();

private slots:
    void InitComponents();
    void closeEvent(QCloseEvent *event);
    void Retranslate();

    void on_ButtonReturn_clicked();

    void ButtonFriendGoTo_Clicked();
    void ButtonFriendFavorite_Clicked();

    void UpdateHiddenRows();
    void on_CheckBoxOpenProfile_stateChanged(int arg1);
    void on_LineEditName_textChanged(const QString &arg1);
    void on_ButtonFind_clicked();
    void on_ComboBoxStatus_activated(int index);

    void on_CheckBoxFavorites_stateChanged(int arg1);

    void on_TableWidgetFriends_cellDoubleClicked(int row, int column);
    void TableWidgetFriends_CellClicked(int row, int col);
    void FriendToUi();

private:
    Ui::FormFriends *ui;
    QString _id;
    int _windowChildCount=0;
    SFriends _friends;
    SProfiles _profiles;
    Settings _setting;
    QString _theme="white";
    Favorites _favorites;
    Filter _filter;
    QString _currentFriend;
    int _currentFriendIndex=-1;

    //QVector<RequestData*> _request;
    int _numRequests=0;
    int _numNow=0;


};

#endif // FORMFRIENDS_H
