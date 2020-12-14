#ifndef FORMPROFILE_H
#define FORMPROFILE_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sbans.h"
#include "classes/steamApi/structures/slevels.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/network/requestimage.h"

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
    void profileToUi(const SProfile &profile);
    void setProfile(const SProfile &profile);
    void updateVisibleInfo();
    void updateInfo();
    void retranslate();
    void updateSettings();

    SProfile getProfile() const {return _profile;}
    SGames getGames() const {return _games;}
    SFriends getFriends() const {return _friends;}

signals:
    void s_goToGames(SProfile &profileSteamid, SGames &games);
    void s_goToFriends(const QString &profileSteamid, SFriends &friends);
    void s_goToStatistic(const QString &profileSteamid, SGames &games, const QString &profileName);
    void s_goToFavorites();
    void s_myProfileChange();

private slots:
    void changeEvent(QEvent *event);

    void setLvl(const QString &aSteamId);
    void setOnlineStatus();
    void setGames(const QString &aSteamId);
    void setFriends(const QString &aSteamId);
    void setBans(const QString &aSteamId);
    void setProfileStatus();
    void setCommentPermission();
    void setCommunityProfile();

    void buttonSetProfile_Clicked();
    void buttonGames_Clicked();
    void buttonFriends_Clicked();
    void buttonStatistics_Clicked();
    void buttonFavorites_Clicked();

    void setIcons();
    void updateMyProfile();
    QGraphicsDropShadowEffect *createLightning();
    void setColorStatus(int aRed, int aGreen, int aBlue, double aAlpha);

private:
    Ui::FormProfile *ui;
    SProfile _profile;
    SGames _games;
    SFriends _friends;
    //Settings _setting;
    int _visibleInfo;
};

#endif // FORMPROFILE_H
