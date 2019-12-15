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
#include <class/steamapi/Sprofile.h>
#include <class/steamapi/Sbans.h>
#include <class/steamapi/Slevels.h>
#include <class/steamapi/Sgames.h>
#include <class/steamapi/Sfriends.h>
#include <class/settings.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    FormGames *_gamesForm;
    FormFriends *_friendsForm;
    FormFavorites *_favoritesForm;
    FormStatistics *_statisticsForm;
    FormSettings *_settingsForm;

public slots:
    void ProgressLoading(int,int);

private slots:
    void keyPressEvent(QKeyEvent *event) override;
    void changeEvent(QEvent *event) override;
    void ReturnFromForms();
    void ReturnFromGames();
    void ReturnFromFriends();
    void ReturnFromFavorites();
    void ReturnFromStatistics();
    void ReturnFromSettings();

    void InitComponents();
    void ShowGames();
    void ShowFriends();
    void GoToProfile(QString id, QString type);
    void ProfileToUi(SProfile AProfile);

    void on_ButtonFindProfile_clicked();
    void on_ButtonGames_clicked();
    void on_ButtonFriends_clicked();
    void on_ButtonSetProfile_clicked();
    void on_ButtonExit_clicked();

    void on_ButtonGoToMyProfile_clicked();

    void on_ButtonBack_clicked();

    void on_ButtonNext_clicked();

    void on_ButtonFavorites_clicked();

    void on_ButtonStatistics_clicked();

    void on_ButtonSettings_clicked();


private:
    Ui::MainWindow *ui;
    int _windowChildCount=0;
    int _windowChild=0;
    SProfile _profile;
    SGames _games;
    SFriends _friends;
    Settings _setting;
    QString _theme="white";

    QVector<SProfile> _bufferProfiles;
    int _currentBufferProfile=0;
};

#endif // MAINWINDOW_H
