#ifndef FORMPROFILE_H
#define FORMPROFILE_H

#include <QWidget>
#include <class/steamapi/Sprofile.h>
#include <class/steamapi/Sbans.h>
#include <class/steamapi/Slevels.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sfriends.h>
#include <class/settings.h>
#include <class/Network/requestdata.h>

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
    void profileToUi(SProfile profile);
    void setProfile(SProfile profile);
    SProfile getProfile();
    SGames getGames();
    SFriends getFriends();
    void updateTheme();
    void updateVisibleInfo();
    void updateInfo();
    void retranslate();

signals:
    void s_goToGames(SProfile profileSteamid, SGames games);
    void s_goToFriends(QString profileSteamid, SFriends friends);
    void s_goToStatistic(QString profileSteamid, SGames games, QString profileName);
    void s_goToFavorites();
    void s_myProfileChange();

private slots:
    void changeEvent(QEvent *event);
    void buttonSetProfile_Clicked();
    void buttonGames_Clicked();
    void buttonFriends_Clicked();
    void buttonStatistics_Clicked();
    void buttonFavorites_Clicked();

private:
    Ui::FormProfile *ui;
    SProfile _profile;
    SGames _games;
    SFriends _friends;
    Settings _setting;
    QString _theme;
    int _visibleInfo;
};

#endif // FORMPROFILE_H
