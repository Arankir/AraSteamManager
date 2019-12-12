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

namespace Ui {
class FormFriends;
}

class FormFriends : public QWidget
{
    Q_OBJECT

public:
    explicit FormFriends(QString id, QString key, SFriends Friends, QWidget *parent = nullptr);
    ~FormFriends();

signals:
    void return_to_profile();
    void go_to_profile(QString id, QString type, bool UpdateBuffer);

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
    QString id;
    QString key;
    int windowchildcount=0;
    SFriends friends;
    QVector<SProfile> profiless;
    Settings setting;
    QString theme="white";
    Favorites favorites;

    QVector<ImageRequest*> request;
    int numrequests=0;
    int numnow=0;

    Filter filter;
};

#endif // FORMFRIENDS_H
