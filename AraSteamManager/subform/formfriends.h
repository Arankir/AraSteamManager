#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include <QWidget>
#include <QFile>
#include <QStandardItem>
#include <class/imagerequest.h>
#include <class/steamapi/Sfriends.h>
#include <class/Threads/threading.h>
#include <class/settings.h>
#include <class/favorites.h>
#include <class/filter.h>
#include <subwidget/qbuttonwithdata.h>

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
    void s_return_to_profile();
    void s_go_to_profile(QString id, QString type);

public slots:
    void ProgressLoading(int p,int row);
    void OnFinish();

private slots:
    void InitComponents();
    void closeEvent(QCloseEvent *event);

    void on_ButtonReturn_clicked();

    void OnResultImage(ImageRequest *imgr);

    void GoToProfileClicked();
    void FavoritesClicked();

    void UpdateHiddenRows();
    void on_CheckBoxOpenProfile_stateChanged(int arg1);
    void on_LineEditName_textChanged(const QString &arg1);
    void on_ButtonFind_clicked();
    void on_ComboBoxStatus_activated(int index);

    void on_CheckBoxFavorites_stateChanged(int arg1);

private:
    Ui::FormFriends *ui;
    QString _id;
    int _windowChildCount=0;
    SFriends _friends;
    QVector<SProfile> _profiles;
    Settings _setting;
    QString _theme="white";
    Favorites _favorites;
    Filter _filter;

    QVector<ImageRequest*> _request;
    int _numRequests=0;
    int _numNow=0;

    const int c_filterName=0;
    const int c_filterStatus=1;
    const int c_filterPublic=2;
    const int c_filterFavorites=3;
};

#endif // FORMFRIENDS_H
