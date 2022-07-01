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
    ExportCategory() {;}
    ExportCategory(int aGameId, const QString &aGameName, const Category &aCategory);
    ExportCategory(const QJsonObject &object);
    ExportCategory(const QString &pathFile);

    int gameId;
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

private slots:
    void initExport();

    void radioButtonHiddenGames_Clicked();

    void achievementsClicked();
    void hideClicked();
    void retranslate() override;
    void updateSettings(QFlags<changedSettings>) override {};
    void updateIcons() override {};

    void checkBoxVisibleHiddenGames_StateChanged(int arg1);
    void checkBoxSaveImage_StateChanged(int arg1);

    void slideProfileSize_ValueChanged(int value);

    void comboBoxMaxTableRows(int index);
    int recursAddCategoryToTree(Category *aCategory, QTreeWidgetItem *aRoot, const int &aGameId);
    void buttonExportCategories_Clicked();
    void buttonImportCategories_Clicked();
    ExportFileData createExportCategoriesJson();

    void comboBoxThemeIndexChanged(int aIndex);
    void comboBoxLanguageIndexChanged(int aIndex);
    ExportFileData *getFileFromPath(QLineEdit *aLineEdit);
private:
    Ui::FormSettings *ui;
    void initCommonSettings();

    Settings _setting;
    QVector<QPair<QString,QList<QString>>> _hiddenGames;
    bool isInit_ = false;
};


#endif // FORMSETTINGS_H
