#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QFile>
#include <QMessageBox>
#include <QPixmap>
#include <formgames.h>
#include <formfriends.h>
#include <QFile>
#include <QKeyEvent>
#include <formstatistic.h>

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
    FormStatistic *statisticform;

private slots:
    void on_return(FormGames *);
    void on_return(FormFriends *);
    void on_return(FormStatistic *);
    void on_go_to_profile(QString id);

    void keyPressEvent(QKeyEvent *event);

    void on_FormProfileButtonFindProfile_clicked();
    void on_FormProfileButtonGames_clicked();
    void on_FormProfileButtonFriends_clicked();
    void on_FormProfileButtonSetProfile_clicked();
    void on_FormProfileButtonExit_clicked();

    void on_FormProfileButtonGoToMyProfile_clicked();

    void on_FormProfileButtonStatistics_clicked();

private:
    Ui::MainWindow *ui;
    QString key="3826BF60403D15613B4B0381DAB7A7BD";
    int language=1;
    int Theme=1;
    int SaveImages=0;
    int windowchildcount=0;
    QString id;
    QJsonDocument DocPlayerSummaries;
    QJsonDocument DocOwnedGames;
    QJsonDocument DocFriendList;
    QStringList SLLanguage;
};

#endif // MAINWINDOW_H
