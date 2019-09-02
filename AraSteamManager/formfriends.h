#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include <QWidget>
#include <QFile>
#include <QStandardItem>
#include <class/imagerequest.h>
#include <class/steamapifriends.h>

namespace Ui {
class FormFriends;
}

class FormFriends : public QWidget
{
    Q_OBJECT

public:
    explicit FormFriends(QString ids, QString keys, int languages, int Theme, SteamAPIFriends Friends, int SaveImagess, QWidget *parent = nullptr);
    ~FormFriends();

signals:
    void return_to_profile(FormFriends*);
    void go_to_profile(QString id);

private slots:
    void closeEvent(QCloseEvent *event);
    void on_FormFriendsBReturn_clicked();

    void OnResultImage(int i, QString Save, ImageRequest *imgr);

    void GoToProfileClicked();
    void FavoritesClicked();

    void UpdateHiddenRows();
    void on_FormFriendsChBOpenProfile_stateChanged(int arg1);
    void on_FormFriendsLineEditName_textChanged(const QString &arg1);
    void on_FormFriendsBFind_clicked();
    void on_FormFriendsCBStatus_activated(int index);

private:
    Ui::FormFriends *ui;
    QString id;
    QString key;
    int language;
    int Theme;
    int windowchildcount=0;
    SteamAPIFriends Friends;
    QJsonDocument DocFriends;
    QStringList SLLanguage;
    int SaveImages;
    bool **filter;
};

#endif // FORMFRIENDS_H
