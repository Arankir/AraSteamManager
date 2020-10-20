#ifndef FORMPROFILE_H
#define FORMPROFILE_H

#include <QWidget>
#include "class/steamapi/Sprofile.h"
#include "class/steamapi/Sbans.h"
#include "class/steamapi/Slevels.h"
#include "class/steamapi/Sgames.h"
#include "class/steamapi/Sfriends.h"
//#include "class/settings.h"
#include "class/Network/requestimage.h"
#include <QGraphicsDropShadowEffect>

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
    void profileToUi(SProfile &profile);
    void setProfile(SProfile &profile);
    SProfile getProfile();
    SGames getGames();
    SFriends getFriends();
    void updateVisibleInfo();
    void updateInfo();
    void retranslate();

    void setIcons();
    void updateSettings();
    void updateMyProfile();
signals:
    void s_goToGames(SProfile &profileSteamid, SGames &games);
    void s_goToFriends(const QString &profileSteamid, SFriends &friends);
    void s_goToStatistic(const QString &profileSteamid, SGames &games, const QString &profileName);
    void s_goToFavorites();
    void s_myProfileChange();

private slots:
    void changeEvent(QEvent *event);
    void buttonSetProfile_Clicked();
    void buttonGames_Clicked();
    void buttonFriends_Clicked();
    void buttonStatistics_Clicked();
    void buttonFavorites_Clicked();

    void setLvl(const QString &aSteamId);
    void setColorStatus(int aRed, int aGreen, int aBlue, double aAlpha);
    void setStatus();
    void setGames(const QString &aSteamId);
    void setFriends(const QString &aSteamId);
    void setBans(const QString &aSteamId);
    void setName();
    QGraphicsDropShadowEffect *createLightning();
    void setCommentPermission();
    void setProfileState();
private:
    Ui::FormProfile *ui;
    SProfile _profile;
    SGames _games;
    SFriends _friends;
    //Settings _setting;
    int _visibleInfo;
};

#endif // FORMPROFILE_H
