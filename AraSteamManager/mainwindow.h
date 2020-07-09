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
#include <MainSubForms/formgames.h>
#include <MainSubForms/formfriends.h>
#include <MainSubForms/formfavorites.h>
#include <MainSubForms/formstatistics.h>
#include <MainSubForms/formsettings.h>
#include <MainSubForms/formprofile.h>
#include <class/steamapi/Sprofile.h>
#include <class/steamapi/Sbans.h>
#include <class/steamapi/Slevels.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sfriends.h>
#include <class/settings.h>
#include <QPropertyAnimation>
#include <QFontDatabase>
#include <QScreen>
#include <QSizeGrip>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

enum class WindowChildType{
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
    FormGames *_gamesForm;
    FormFriends *_friendsForm;
    FormFavorites *_favoritesForm;
    FormStatistics *_statisticsForm;
    FormSettings *_settingsForm;
    FormContainerAchievements *_containerAchievementsForm;
    QVector<FormAchievements*> _achievementsForms;

public slots:
    void progressLoading(int,int);
    void AddAchievements(SAchievementsPlayer achievements,SGame games);
    void RemoveAchievements(int index);
    void ContainerAchievementsClose();
    void ReturnFromAchievements(int num);

    void GoToGames(QString prifileSteamid, SGames games);
    void GoToFriends(QString prifileSteamid, SFriends friends);
    void GoToFavorites();
    void GoToStatistics(QString prifileSteamid, SGames games, QString profileName);

    void UpdateMyProfile();
    void UpdateSettings();

signals:
    void s_updateSettings();

private slots:
    //events
    void keyPressEvent(QKeyEvent*) override;
    void changeEvent(QEvent*) override;
    void closeEvent(QCloseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    //Forms
    void showForm(bool &initForm, int widgetIndex, int widthWindow=300);
    void showGames(int width);
    void showFriends();
    void showStatistic();
    void returnFromForms();
    //Systems
    void InitComponents();
    void SetIcons();
    void ResizeScrollArea(int width=300);
    void UpdateButtonsBackNext();
    void ButtonMaximize_Clicked();
    void ButtonMinimize_Clicked();
    //Functions
    void ButtonFindProfile_Clicked();
    void GoToProfile(QString id, QueryType type);
    void ButtonSettings_Clicked();
    void ButtonExit_Clicked();
    //Profile
    void ButtonGoToMyProfile_Clicked();
    void ButtonBack_Clicked();
    void ButtonNext_Clicked();
    void ButtonUpdate_Clicked();

private:
    QString GetTheme();
    Ui::MainWindow *ui;
    int _windowChildCount=0;
    SProfiles _profile;
    SGames _games;
    SFriends _friends;
    Settings _setting;
    QString _iconColor="white";
    int _achievementsCount=0;

    bool _initGames=false;
    bool _initFriends=false;
    bool _initFavorites=false;
    bool _initStatistics=false;
    bool _initSettings=false;
    bool _blockedLoad=false;

};

#endif // MAINWINDOW_H
