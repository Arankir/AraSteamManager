#ifndef FORMNEWCATEGORY_H
#define FORMNEWCATEGORY_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QCheckBox>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QComboBox>

namespace Ui {
class FormNewCategory;
}

class FormNewCategory : public QWidget
{
    Q_OBJECT

public:
    explicit FormNewCategory(QString id, QString key, int language, QString, QWidget *parent = nullptr);
    ~FormNewCategory();

signals:
    void return_to_achievements();

private slots:
    void closeEvent(QCloseEvent *);
    void on_FormAddCategoryButtonAddParameterValue_clicked();

    void on_FormAddCategoryButtonCancel_clicked();

    void on_FormAddCategoryButtonAddCategory_clicked();

    void on_FormAddCategoryLineEditFind_textChanged(const QString &arg1);

private:
    Ui::FormNewCategory *ui;
    QString id;
    QString key;
    int language;
    QString appid;
    QVector <QPair<QString, QVector<QCheckBox*>>> variants;
    QJsonDocument JsonDocNumberOfCurrentPlayers;
    QJsonDocument JsonDocGlobalAchievementPercentagesForApp;
    QJsonDocument JsonDocPlayerAchievements;
    QJsonDocument JsonDocSchemaForGame;
};

#endif // FORMNEWCATEGORY_H
