#ifndef FORMPROFILESBROWSER_H
#define FORMPROFILESBROWSER_H

#include "forms/main/formprofile.h"

namespace Ui {
class FormProfilesBrowser;
}

class FormProfilesBrowser : public Form {
    Q_OBJECT

public:
    explicit FormProfilesBrowser(QWidget *parent = nullptr);
    ~FormProfilesBrowser();

    SProfile currentProfile();

    void goToProfile(const ProfileID &profileId);

    void retranslate() override;
    void updateIcons() override;

    void goToGames(const ProfileID &profileId);
    void goToFriends(const ProfileID &profileId);
    void buttonFavorites_Clicked();
    void goToStatistics(const SProfile &profile);
    void updateSettings(QFlags<changedSettings>) override;

signals:
    void s_profileChanged(const ProfileID&);
    void s_gamesClicked(const ProfileID&);
    void s_friendsClicked(const ProfileID&);
    void s_statisticsClicked(const SProfile&);
    void s_favoritesClicked();
    void s_settingsClicked();

protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    FormProfile *createFormProfile(const SProfile &profile);
    void updateProfileNavigation();
    //Functions
    void buttonFindProfile_Clicked();
    void buttonSettings_Clicked();
    //Profile
    void buttonGoToMyProfile_Clicked();
    void buttonBack_Clicked();
    void buttonNext_Clicked();
    void buttonUpdate_Clicked();

    Ui::FormProfilesBrowser *ui;
};

#endif // FORMPROFILESBROWSER_H
