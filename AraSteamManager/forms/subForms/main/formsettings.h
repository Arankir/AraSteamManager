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
#include "classes/achievements/categoriesgame.h"
#include "subWidgets/withData/qbuttonwithdata.h"
#include "subWidgets/withData/qradiobuttonwithdata.h"

enum class ExportType {
    unknown,
    categories,
    favorites,
    comments,
    groups,
    multiple
};

QString exportTypeToString(ExportType aType);
ExportType stringToExportType(QString aType);

struct ExportFileData {
    QJsonValue data;
    ExportType type;
    double version;
    QDateTime date;

    static ExportFileData fromJson(QJsonObject object);
    QJsonObject toJson();
};

struct ExportCategory {
    int gameId;
    QString gameName;
    Category category;

    static ExportCategory fromJson(QJsonObject object);
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
    bool isInit();
    bool isLoaded();

signals:
    void s_return_to_profile(QWidget*);
    void s_updateSettings();

private slots:
    void initComponents();
    void initExport();

    void radioButtonLanguageEnglish_Clicked();
    void radioButtonLanguageRussian_Clicked();

    void radioButtonDarkTheme_Clicked();
    void radioButtonLightTheme_Clicked();
    void radioButtonBlueTheme_Clicked();

    void radioButtonHiddenGames_Clicked();

    void achievementsClicked();
    void hideClicked();
    void retranslate() override;
    void updateSettings() override {};
    void updateIcons() override {};

    void checkBoxVisibleHiddenGames_StateChanged(int arg1);
    void checkBoxSaveImage_StateChanged(int arg1);

    void slideProfileSize_ValueChanged(int value);

    void comboBoxMaxTableRows(int index);
    int recursAddCategoryToTree(Category *aCategory, QTreeWidgetItem *aRoot, const int &aGameId);
    void buttonExportCategories_Clicked();
    void buttonImportCategories_Clicked();
    ExportFileData createExportCategoriesJson();
    QStringList getColors(const QColor &aNewColor);
    void createIcons(const QString &aPath, const QColor &aNewColor);
private:
    Ui::FormSettings *ui;
    Settings _setting;
    QVector<QPair<QString,QList<QString>>> _hiddenGames;
};


#endif // FORMSETTINGS_H
