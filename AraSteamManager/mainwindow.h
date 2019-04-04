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

    void on_FormProfileButtonSetProfile_clicked();

    void on_FormProfileButtonGames_clicked();

    void on_return();

    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    QString key="3826BF60403D15613B4B0381DAB7A7BD";
    int language=5;
    QString id;
};

#endif // MAINWINDOW_H
