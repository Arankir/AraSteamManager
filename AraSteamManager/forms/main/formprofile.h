#ifndef FORMPROFILE_H
#define FORMPROFILE_H

#include "form.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sfriends.h"

namespace Ui {
class FormProfile;
}

class FormProfile : public Form {
    Q_OBJECT

public:
    explicit FormProfile(const SProfile &profile, QWidget *parent = nullptr);
    ~FormProfile() override;
    SProfile getProfile() const;
    SGames getGames() const;
    SFriends getFriends() const;

public slots:
    void profileToUi(const SProfile &profile);
    void setProfile(const SProfile &profile);
    void updateVisibleInfo();
    void updateInfo();
    void retranslate() override;
    void updateSettings(QFlags<changedSettings> settings) override;

signals:
    void s_goToGames(const ProfileID &profileId);
    void s_goToFriends(const ProfileID &profileId);
    void s_goToStatistic(const SProfile &profile);
    void s_goToFavorites();

protected slots:
    void setMinimizeInfo(const SProfile &profile);
    void setBaseInfo(const SProfile &profile);
    void setMaximizeInfo(const SProfile &profile);
private slots:
    void setLvl(const ProfileID &profileId);
    void setOnlineStatus();
    void setGames(const ProfileID &profileId);
    void setFriends(const ProfileID &profileId);
    void setProfileStatus();

    void setCommonInfo(const SProfile &profile);
    void setBans(const ProfileID &profileId);
    void setBadges(const ProfileID &profileId);
    void setTimePlayed(const SGames &games);
    void setCustomizations(const ProfileID &profileId);

    void buttonSetProfile_Clicked();
    void buttonGames_Clicked();
    void buttonFriends_Clicked();
    void buttonStatistics_Clicked();

    void updateIcons() override;
    void updateMyProfile();
    void setColorStatus(const QColor &color);

private:
    Ui::FormProfile *ui;
    SProfile profile_;
    SGames games_;
    SFriends friends_;
    int visibleInfo_;

    bool isMinimizeInit_ = false;
    bool isBaseInit_ = false;
    bool isMaximizeInit_ = false;

};

#endif // FORMPROFILE_H
