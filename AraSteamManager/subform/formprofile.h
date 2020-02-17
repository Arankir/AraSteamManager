#ifndef FORMPROFILE_H
#define FORMPROFILE_H

#include <QWidget>
#include <class/steamapi/Sprofile.h>
#include <class/steamapi/Sbans.h>
#include <class/steamapi/Slevels.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sfriends.h>
#include <class/settings.h>
#include <class/requestdata.h>

namespace Ui {
class FormProfile;
}

class FormProfile : public QWidget
{
    Q_OBJECT

public:
    explicit FormProfile(SProfile profile, QWidget *parent = nullptr);
    ~FormProfile();

public slots:
    void ProfileToUi(SProfile profile);
    void SetProfile(SProfile profile);
    SProfile GetProfile() {return _profile;}
    SGames GetGames() {return _games;}
    SFriends GetFriends() {return _friends;}
    void UpdateTheme();
    void UpdateVisibleInfo();
    void UpdateInfo();

signals:
    void s_goToGames(QString prifileSteamid, SGames games);
    void s_goToFriends(QString prifileSteamid, SFriends friends);
    void s_goToStatistic(QString prifileSteamid, SGames games, QString profileName);
    void s_goToFavorites();
    void s_myProfileChange();

private slots:
    void changeEvent(QEvent *event);
    void on_ButtonSetProfile_clicked();
    void on_ButtonGames_clicked();
    void on_ButtonFriends_clicked();
    void on_ButtonStatistics_clicked();
    void on_ButtonFavorites_clicked();

private:
    Ui::FormProfile *ui;
    SProfile _profile;
    SGames _games;
    SFriends _friends;
    Settings _setting;
    QString _theme;
    bool _visibleInfo;
};

#endif // FORMPROFILE_H
