#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QMessageBox>
#include <QDebug>
#include <QFormLayout>
#include <QPair>
#include <QTranslator>
#include <QTreeWidgetItem>
#include <QFileDialog>
#include "classes/network/requestimage.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/files/category.h"
#include "subWidgets/withData/qbuttonwithdata.h"
#include "subWidgets/withData/qradiobuttonwithdata.h"
#include "classes/files/favorites.h"

enum class ExportType {
    unknown,
    categories,
    favorites,
    comments,
    groups,
    multiple
};

QString exportTypeToString(ExportType type);
ExportType stringToExportType(QString type);

struct ExportFileData {
    QJsonValue data;
    ExportType type;
    double version;
    QDateTime date;

    static ExportFileData fromJson(QJsonObject object);
    QJsonObject toJson();
};

struct ExportCategory {
    ExportCategory();
    ExportCategory(GameID gameId, const QString &gameName, const Category &category);
    ExportCategory(const QJsonObject &object);
    ExportCategory(const QString &pathFile);

    GameID gameId;
    QString gameName;
    Category category;

    void fromJson(const QJsonObject &object);
    QJsonObject toJson();
};

namespace Ui {
class FormSettings;
}

class FormSettings : public Form {
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = nullptr);
    ~FormSettings();
    void init();
    bool isInit();
    bool isLoaded();

signals:
    void s_return_to_profile(QWidget*);
    void s_showAchievements(const SGame &);

private slots:
    void initExport();

    void radioButtonHiddenGames_Clicked();

    void achievementsClicked();
    void hideClicked();
    void retranslate() override;
    void updateSettings(QFlags<changedSettings>) override;;
    void updateIcons() override;;

    void checkBoxVisibleHiddenGames_StateChanged(int arg1);
    void checkBoxSaveImage_StateChanged(int arg1);

    void slideProfileSize_ValueChanged(int value);

    void comboBoxMaxTableRows(int index);
    int recursAddCategoryToTree(Category *category, QTreeWidgetItem *root, const GameID &gameId);
    void buttonExportCategories_Clicked();
    void buttonImportCategories_Clicked();
    ExportFileData createExportCategoriesJson();

    void comboBoxThemeIndexChanged(const int &index);
    void comboBoxLanguageIndexChanged(const int &index);
    ExportFileData *getFileFromPath(QLineEdit *lineEdit);
    void initHiddenGames();
    void itemModelHiddenGames_Clicked(const QModelIndex &index);
    QMenu *createMenuHiddenGame(const QModelIndex &aIndex);
    void updateHiddenGames();
    void initCommonSettings();

    void updateExportCategories();
    void updateExportFavoriteGames();
    void updateExportFavoriteFriends();
    void updateExportFavoriteAchievements();
    void updateExportCommentsGames();
    void updateExportCommentsAchievements();
    void updateExportGroups();
    SProfiles getProfilesFavoriteAchievements();
private:
    Ui::FormSettings *ui;

    QVector<QPair<QString,QList<QString>>> hiddenGames_;
    QStringList listProfiles_;
    bool isInit_ = false;

    FavoriteProfiles friendsFavorites_;
    FavoriteGames gamesFavorites_;
    FavoriteAchievementsGames achievementsFavorites_;
};


#endif // FORMSETTINGS_H
