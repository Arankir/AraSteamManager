#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QPixmap>
#include <formgames.h>
#include <formfriends.h>
#include <QFile>
#include <QKeyEvent>
#include <class/steamapiprofile.h>
#include <class/steamapibans.h>
#include <class/steamapilevels.h>
#include <class/steamapigames.h>
#include <class/steamapifriends.h>
#include <class/settings.h>
#include <class/language.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    FormGames *gamesform;
    FormFriends *friendsform;

private slots:
    void on_return(FormGames *);
    void on_return(FormFriends *);
    void on_go_to_profile(QString id);

    void keyPressEvent(QKeyEvent *event);

    void GoToProfile(QString id, QString type);
    void on_ButtonFindProfile_clicked();
    void on_ButtonGames_clicked();
    void on_ButtonFriends_clicked();
    void on_ButtonSetProfile_clicked();
    void on_ButtonExit_clicked();

    void on_ButtonGoToMyProfile_clicked();

private:
    Ui::MainWindow *ui;
    QString key="3826BF60403D15613B4B0381DAB7A7BD";
    int windowchildcount=0;
    QStringList Words;
    SteamAPIProfile Profile;
    SteamAPIGames Games;
    SteamAPIFriends Friends;
    Settings Setting;
};

#endif // MAINWINDOW_H
