#ifndef FORMACHIEVEMENTSCATEGORIESEDIT_H
#define FORMACHIEVEMENTSCATEGORIESEDIT_H

#include <QWidget>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QDrag>
#include <QMimeData>
#include <QTreeWidgetItem>
#include "class/settings.h"
#include "class/myfilter.h"
#include "class/categoriesgame.h"
#include "class/steamapi/Sgames.h"
#include "subwidget/qlistwidgetachievement.h"

enum class EditType {
    none,
    add,
    change
};

namespace Ui {
    class FormAchievementsCategoriesEdit;
}

class FormCategoriesEdit : public QWidget {
    Q_OBJECT

public:
    explicit FormCategoriesEdit(const SGame &game, QWidget *parent = nullptr);
    explicit FormCategoriesEdit(QWidget *parent = nullptr);
    ~FormCategoriesEdit();
    void setGame(SGame game);
    void setAchievements(SAchievements &aAchievements);
    void updateFilter(const MyFilter &aFilter);
    void changeCategory(Category *aCategory, int aGlobalIndex);
    void addSubCategory(Category *aParent);

signals:
    void s_categoriesIsUpdated(bool isUpdated);
    void s_updateSettings();

private slots:
    void init();
    void setIcons();
    void achievementsToUi();
    int indexFromRow(QListWidget *listWidget, int row);
    void changeEditType(EditType type);
    void buttonAdd_Clicked();
    void buttonCancel_Clicked();
    void buttonAccept_Clicked();
    void buttonDelete_Clicked();
    void buttonDeleteAll_Clicked();
    bool isCategoryNameExist(const QString &name);
    void updateParentTree();
    int recursAddToParentTree(Category &category, int count, QTreeWidgetItem *root = nullptr);
    void changeParentButton_Clicked();
    void changeNewParent(Category *aParent);
private:
    Ui::FormAchievementsCategoriesEdit *ui;
    SGame _game;
    SAchievements _achievements;
    Categories _categories;
    EditType _typeEdit = EditType::none;

    Category *_currentCategory = nullptr;
    Category *_currentCategoryParent = nullptr;
    Category *_currentCategoryNewParent = nullptr;
    int _currentCategoryGlobalIndex = -1;
};

#endif // FORMACHIEVEMENTSCATEGORIESEDIT_H
