#ifndef FORMFRIENDS_H
#define FORMFRIENDS_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QStandardItem>
#include <imagerequest.h>

namespace Ui {
class FormFriends;
}

class FormFriends : public QWidget
{
    Q_OBJECT

public:
    explicit FormFriends(QString ids, QString keys, int languages, QJsonDocument DocFriends, int SaveImagess, QWidget *parent = nullptr);
    ~FormFriends();

signals:
    void return_to_profile();

private slots:
    void closeEvent(QCloseEvent *event);

    void on_FormFriendsBReturn_clicked();
    void OnResultImage(int i, QString Save, ImageRequest *imgr);
    void GoToProfileClicked();

private:
    Ui::FormFriends *ui;
    QString id;
    QString key;
    int language=0;
    QJsonDocument DocFriends;
    QStringList SLLanguage;
    int SaveImages;
};

#endif // FORMFRIENDS_H
