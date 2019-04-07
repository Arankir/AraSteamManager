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

#include <QImage>

#include <formgames.h>

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

private slots:
    void on_FormProfileButtonFindProfile_clicked();
    void on_FindAccount_language(QString LabelRealName, QString RealName, QString LabelTimeCreated, QDateTime TimeCreated, QString ButtonGames, int Games, QString ButtonFriends, int Friends, int personastate, QString PS0, QString PS1, QString PS2, QString PS3, QString PS4, QString PS5, QString PS6, QString LabelLocCountryCode, QString LocCountryCode);

    void on_FormProfileButtonSetProfile_clicked();

    void on_FormProfileButtonGames_clicked();

    void on_return();

    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    QString key="3826BF60403D15613B4B0381DAB7A7BD";
    int language=1;
    int Theme=1;
    QString id;
    QJsonDocument DocPlayerSummaries;
    QJsonDocument DocOwnedGames;
    QJsonDocument DocFriendList;
};

#endif // MAINWINDOW_H
