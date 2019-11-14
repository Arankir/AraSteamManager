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
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    FormGames* gamesform;
    FormFriends* friendsform;

public slots:
    void ProgressLoading(int,int);

private slots:
    void returnfromgames();
    void returnfromfriends();

    void keyPressEvent(QKeyEvent* event);

    void ShowGames();
    void ShowFriends();

    void GoToProfile(QString id, QString type, bool UpdateBuffer);
    void InitComponents();
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

private:
    Ui::MainWindow* ui;
    QString key="3826BF60403D15613B4B0381DAB7A7BD";
    int windowchildcount=0;
    QStringList Words;
    SProfile Profile;
    SGames Games;
    SFriends Friends;
    Settings Setting;
    QString theme="white";

    QVector<QString> BufferProfiles;
    int CurrentBufferProfile=0;
};

#endif // MAINWINDOW_H
