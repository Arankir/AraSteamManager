#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QKeyEvent>
#include <QTranslator>
#include <QLibraryInfo>
#include <QPropertyAnimation>
#include <QFontDatabase>
#include <QScreen>
#include <QSizeGrip>
#include <QGraphicsDropShadowEffect>
#include "forms/subForms/main/formgames.h"
#include "forms/subForms/main/formfriends.h"
#include "forms/subForms/main/formfavorites.h"
#include "forms/subForms/main/formstatistics.h"
#include "forms/subForms/main/formsettings.h"
#include "forms/subForms/main/formprofile.h"
#include "formcontainerachievements.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sbans.h"
#include "classes/steamApi/structures/slevels.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sfriends.h"

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT

enum class WindowChildType {
     none,
     games,
     friends,
     favorites,
     statistics,
     settings
  };

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    FormGames *_gamesForm = nullptr;
    FormFriends *_friendsForm = nullptr;
    FormFavorites *_favoritesForm = nullptr;
    FormStatistics *_statisticsForm = nullptr;
    FormSettings *_settingsForm = nullptr;
    FormContainerAchievements *_containerAchievementsForm = nullptr;
    //QVector<FormAchievements*> _achievementsForms;

public slots:
    void progressLoading(int, int);
    void addAchievements(SAchievementsPlayer &achievements, SGame &games);
    void removeAchievements(int index);
    void containerAchievementsClose();
    void returnFromAchievements(int num);

    void goToGames(SProfile &profileSteamid, SGames &games);
    void goToFriends(const QString &profileSteamid, SFriends &friends);
    void goToFavorites();
    void goToStatistics(const QString &profileSteamid, SGames &games, const QString &profileName);

    void updateSettings();

    FormProfile *createFormProfile(SProfile &aProfile);
    FormGames *createFormGames(SProfile &aProfile, SGames &aGames);
    FormFriends *createFormFriends(const QString &aId, SFriends &aFriends);
    FormFavorites *createFormFavorites();
    FormStatistics *createFormStatistics(const QString &aId, SGames &aGames, const QString &aName);
    FormSettings *createFormSettings();
    FormContainerAchievements *createFormContainerAchievements();
signals:
    void s_updateSettings();

private slots:
    //events
    void keyPressEvent(QKeyEvent*) override;
    void changeEvent(QEvent*) override;
    void closeEvent(QCloseEvent*) override;
    //Forms
    void showForm(int widgetIndex, int widthWindow = 300);
    void returnFromForms();
    //Systems
    void initComponents();
    QString getTheme();
    void setIcons();
    void resizeScrollArea(int width = 300);
    void updateEnabledButtonsBackNext();
    void buttonMaximize_Clicked();
    void buttonMinimize_Clicked();
    //Functions
    void buttonFindProfile_Clicked();
    void goToProfile(const QString &id, ProfileUrlType type);
    void buttonSettings_Clicked();
    void buttonExit_Clicked();
    //Profile
    void buttonGoToMyProfile_Clicked();
    void buttonBack_Clicked();
    void buttonNext_Clicked();
    void buttonUpdate_Clicked();

private:
    Ui::MainWindow *ui;
    int _windowChildCount = 0;
    SProfiles _profile;
    SGames _games;
    SFriends _friends;
    Settings _setting;
    int _achievementsCount = 0;

    bool _blockedLoad = false;

    int test = 0;

};

#endif // MAINWINDOW_H
