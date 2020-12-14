#ifndef FORMACHIEVEMENTSCATEGORIESEDIT_H
#define FORMACHIEVEMENTSCATEGORIESEDIT_H

#include <QWidget>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QDrag>
#include <QMimeData>
#include <QTreeWidgetItem>
#include <QMenu>
#include <QAction>
#include "classes/common/settings.h"
#include "classes/common/myfilter.h"
#include "classes/achievements/categoriesgame.h"
#include "classes/steamApi/structures/sgames.h"
#include "subWidgets/items/qlistwidgetachievement.h"
#include "subWidgets/models/listachievementsmodel.h"

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
    void setGame(SGame &game);
    void setAchievements(SAchievements &aAchievements);
    void updateFilter(const MyFilter &aFilter);
    void changeCategory(Category *aCategory, int aGlobalIndex);
    void addSubCategory(Category *aParent);
    void deleteCategory(Category *aCategory, int aGlobalIndex);

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
    void changeParentButton_Clicked();
    void changeNewParent(Category *parent);
    QMenu *createParentMenu();
    QMenu *createParentSubMenu(Category &category, int &number);
    void changeNewParentFromAction();
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
