#ifndef FORMMAIN_H
#define FORMMAIN_H

#include "form.h"
#include "formcontainerachievements.h"

namespace Ui {
    class FormMain;
}

class FormMain : public Form {
    Q_OBJECT

public:
    explicit FormMain(QWidget *parent = nullptr);
    ~FormMain() override;
    FormContainerAchievements *_containerAchievementsForm = nullptr;

public slots:
    FormContainerAchievements *createFormContainerAchievements();
    void showAchievements(const SGame &games);
    void containerAchievementsClose();

    void goToGames(const ProfileID &aSteamId);
    void goToFriends(const ProfileID &aSteamId);
    void goToFavorites();
    void goToStatistics(const SProfile &profileSteamid);
    void updateSettings(QFlags<changedSettings>) override;

private slots:
    //events
    void closeEvent(QCloseEvent*) override;
    //Forms
    void showForm(int widgetIndex, int widthWindow = 300, int windowHeight = 400);
    void returnFromForms();
    //Systems
    void retranslate() override;
    void updateIcons() override;
    void init();
    void resizeScrollArea(int width = 300, int aHeight = 400);
    //Functions
    void goToProfile(const ProfileID &id);
    void goToSettings();

private:
    Ui::FormMain *ui;

    bool isLoading_ = false;

};

#endif // FORMMAIN_H
