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

public slots:
    FormContainerAchievements *createFormContainerAchievements();
    void showAchievements(const SGame &games);
    void showAchievementsProfile(const ProfileID &profileId, const SGame &game);
    void containerAchievementsClose();

    void goToGames(const ProfileID &profileId);
    void goToFriends(const ProfileID &profileId);
    void goToFavorites();
    void goToStatistics(const SProfile &profile);
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
    void resizeScrollArea(int width = 300, int height = 400);
    //Functions
    void goToProfile(const ProfileID &profileId);
    void goToSettings();

private:
    Ui::FormMain *ui;
    FormContainerAchievements *achievements_ = nullptr;

    bool isLoading_ = false;

};

#endif // FORMMAIN_H
