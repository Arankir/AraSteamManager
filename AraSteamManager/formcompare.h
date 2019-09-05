#ifndef FORMCOMPARE_H
#define FORMCOMPARE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDir>
#include <QComboBox>
#include <QMessageBox>
#include <QFormLayout>
#include <class\imagerequest.h>
#include <class\profile.h>
#include <QTableWidgetItem>
#include <QRadioButton>
#include <class/settings.h>

namespace Ui {
class FormCompare;
}

class FormCompare : public QWidget
{
    Q_OBJECT

public:
    explicit FormCompare(QString keys, QString ids, QString appids, QPixmap GameLogo, QJsonArray JsonArrayGlobalAchievement, QWidget *parent = nullptr);
    ~FormCompare();

signals:
    void return_to_achievements(FormCompare*);

private slots:
    void closeEvent(QCloseEvent *);
    void OnResultImage(int i, QString Save, ImageRequest *imgr);
    void UpdateHiddenRows();

    void on_RadioButtonMyAll_clicked();
    void on_RadioButtonMyReached_clicked();
    void on_RadioButtonMyNotReached_clicked();

    void on_ComboBoxCategory_Change(int index);
    void on_CheckBoxCategory_Change(int ind);

    void on_CheckBoxSCIcons_stateChanged(int arg1);

    void on_CheckBoxSCTitle_stateChanged(int arg1);

    void on_CheckBoxSCDescription_stateChanged(int arg1);

    void on_CheckBoxSCTotalPercent_stateChanged(int arg1);

    void on_CheckBoxFriend_Click(int,int);

    void on_ButtonReturn_clicked();

    void on_CheckBoxShowFilter_stateChanged(int arg1);

    void on_RadioButtonFriendAll_Click();
    void on_RadioButtonFriendReached_Click();
    void on_RadioButtonFriendNotReached_Click();

    void on_CheckBoxAllFriends_stateChanged(int arg1);

    void on_RadioButtonFriendsAll_clicked();
    void on_RadioButtonFriendsReached_clicked();
    void on_RadioButtonFriendsNotReached_clicked();

    void on_ButtonFind_clicked();

    void on_LineEditFind_textChanged(const QString &arg1);

    void on_ButtonUpdate_clicked();

private:
    Ui::FormCompare *ui;
    QString key;
    QString id;
    int windowchildcount=0;
    QString appid;
    QJsonDocument JsonDocNumberOfCurrentPlayers;
    QJsonArray JsonArrayGlobalAchievements;
    QJsonDocument JsonDocPlayerAchievements;
    QJsonArray JsonArraySchemaForGame;
    bool **filter;
    int colfilter=3;
    QFormLayout *newcategoryvalueslayout;
    QFormLayout *changecategoryvalueslayout;
    QStringList Words;
    QPair <QVector<Profile>,QVector<Profile>> Friends;
    Settings Setting;
    QString theme="white";
};

#endif // FORMCOMPARE_H
