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
#include <imagerequest.h>

namespace Ui {
class FormCompare;
}

class FormCompare : public QWidget
{
    Q_OBJECT

public:
    explicit FormCompare(QString keys, int languages, int Themes, QString ids, QString appids, QPixmap GameLogo, QJsonArray JsonArrayGlobalAchievement,int SaveImage, QWidget *parent = nullptr);
    ~FormCompare();

signals:
    void return_to_achievements();

private slots:
    void closeEvent(QCloseEvent *);
    void OnResultImage(int i, QString Save, ImageRequest *imgr);
    void UpdateHiddenRows();

    void on_FormCompareRadioButtonMyAll_clicked();
    void on_FormCompareRadioButtonMyReached_clicked();
    void on_FormCompareRadioButtonMyNotReached_clicked();

    void on_ComboBoxCategory_Change(int index);
    void on_CheckBoxCategory_Change(int ind);

    void on_FormCompareCheckBoxSCIcons_stateChanged(int arg1);

    void on_FormCompareCheckBoxSCTitle_stateChanged(int arg1);

    void on_FormCompareCheckBoxSCDescription_stateChanged(int arg1);

    void on_FormCompareCheckBoxSCTotalPercent_stateChanged(int arg1);

    void on_FormCompareButtonReturn_clicked();

private:
    Ui::FormCompare *ui;
    QString key;
    QString id;
    int language;
    int Theme;
    QString appid;
    QJsonDocument JsonDocNumberOfCurrentPlayers;
    QJsonArray JsonArrayGlobalAchievements;
    QJsonDocument JsonDocPlayerAchievements;
    QJsonArray JsonArraySchemaForGame;
    bool **filter;
    int colfilter=3;
    QFormLayout *newcategoryvalueslayout;
    QFormLayout *changecategoryvalueslayout;
    QStringList SLLanguage;
    int SaveImages;
};

#endif // FORMCOMPARE_H
