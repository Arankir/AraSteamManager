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
#include <subform/formgames.h>
#include <subform/formfriends.h>
#include <subform/formfavorites.h>
#include <subform/formstatistics.h>
#include <subform/formsettings.h>
#include <subform/formprofile.h>
#include <class/steamapi/Sprofile.h>
#include <class/steamapi/Sbans.h>
#include <class/steamapi/Slevels.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sfriends.h>
#include <class/settings.h>
#include <QPropertyAnimation>
#include <QFontDatabase>

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
    void ProgressLoading(int,int);
    void AddAchievements(SAchievementsPlayer achievements,SGame games);
    void RemoveAchievements(int index);
    void ContainerAchievementsClose();
    void ReturnFromAchievements(int num);

    void GoToGames(QString prifileSteamid, SGames games);
    void GoToFriends(QString prifileSteamid, SFriends friends);
    void GoToFavorites();
    void GoToStatistics(QString prifileSteamid, SGames games, QString profileName);
    void UpdateMyProfile();

private slots:
    void keyPressEvent(QKeyEvent *event) override;
    void changeEvent(QEvent *event) override;
    void ReturnFromForms();
    void Retranslate();
    void ResizeScrollArea();

    void InitComponents();
    void ShowGames();
    void ShowFriends();
    void ShowStatistic();
    void GoToProfile(QString id, QueryType type);
    void UpdateButtonsBackNext();

    void on_ButtonFindProfile_clicked();
    void on_ButtonExit_clicked();

    void on_ButtonGoToMyProfile_clicked();
    void on_ButtonBack_clicked();
    void on_ButtonNext_clicked();

    void on_ButtonSettings_clicked();

    void on_ButtonUpdate_clicked();

private:
    Ui::MainWindow *ui;
    int _windowChildCount=0;
    SProfile _profile;
    SGames _games;
    SFriends _friends;
    Settings _setting;
    QString _theme="white";
    int _achievementsCount=0;

    bool _initGames=false;
    bool _initFriends=false;
    bool _initFavorites=false;
    bool _initStatistics=false;
    bool _initSettings=false;
    bool _blockedLoad=false;

};

#endif // MAINWINDOW_H
