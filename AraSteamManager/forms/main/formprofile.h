#ifndef FORMPROFILE_H
#define FORMPROFILE_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sbans.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/steamApi/structures/sprofilecustomization.h"
#include "classes/steamApi/structures/sbadge.h"
#include "classes/network/requestimage.h"

namespace Ui {
class FormProfile;
}

class FormProfile : public Form {
    Q_OBJECT

public:
    explicit FormProfile(const SProfile &profile, QWidget *parent = nullptr);
    ~FormProfile() override;
    SProfile getProfile() const {return _profile;}
    SGames getGames() const {return _games;}
    QList<SFriend> getFriends() const {return _friends;}

public slots:
    void profileToUi(const SProfile &profile);
    void setProfile(const SProfile &profile);
    void updateVisibleInfo();
    void updateInfo();
    void retranslate() override;
    void updateSettings(QFlags<changedSettings> aSettings) override;

signals:
    void s_goToGames(const ProfileID &profileId);
    void s_goToFriends(const ProfileID &profileId);
    void s_goToStatistic(const SProfile &profile);
    void s_goToFavorites();

private slots:
    void setLvl(const ProfileID &aSteamId);
    void setOnlineStatus();
    void setGames(const ProfileID &aSteamId);
    void setFriends(const ProfileID &aSteamId);
    void setProfileStatus();
    void setCommentPermission();
    void setCommunityProfile();

    void setId(const ProfileID &aSteamId);
    void setBans(const ProfileID &aSteamId);
    void setBadges(const ProfileID &aSteamId);
    void setTimePlayed(const SGames &aGames);
    void setCustomizations(const ProfileID &aSteamId);

    void buttonSetProfile_Clicked();
    void buttonGames_Clicked();
    void buttonFriends_Clicked();
    void buttonStatistics_Clicked();

    void updateIcons() override;
    void updateMyProfile();
//    QGraphicsDropShadowEffect *createLightning();
    void setColorStatus(const QColor &aColor);

private:
    Ui::FormProfile *ui;
    SProfile _profile;
    SGames _games;
    QList<SFriend> _friends;
    //Settings _setting;
    int _visibleInfo;
};

#endif // FORMPROFILE_H
