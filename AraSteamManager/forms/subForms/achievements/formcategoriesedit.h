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
    class FormCategoriesEdit;
}

class FormCategoriesEdit : public QWidget {
    Q_OBJECT

public:
    explicit FormCategoriesEdit(const SGame &game, QWidget *parent = nullptr);
    explicit FormCategoriesEdit(QWidget *parent = nullptr);
    ~FormCategoriesEdit();
    void setGame(const SGame &game);
    void setAchievements(const SAchievements &aAchievements);
    void setFilter(MyFilter *aFilter);
    Category *categories() {return &_categories;}
    void updateHiddenItems();
    void changeCategory(Category *aCategory);
    void addSubCategory(Category *aParent);
    void deleteCategory(Category *aCategory);

signals:
    void s_categoriesIsUpdated(const bool &isUpdated);
    void s_updateSettings();

private slots:
    void init();
    void setIcons();
    void achievementsToUi();
    int indexFromRow(QListWidget *listWidget, const int &row);
    void changeEditType(const EditType &type);
    void buttonAdd_Clicked();
    void buttonCancel_Clicked();
    void buttonAccept_Clicked();
    void buttonDelete_Clicked();
    void buttonDeleteAll_Clicked();
    bool isCategoryNameExist(const QString &name);
//    void changeParentButton_Clicked();
    void changeNewParent(Category *parent);
    QMenu *createParentMenu(Category *category = nullptr);
    void changeNewParentFromAction();
    void changeCategoryParent(Category *category);
private:
    Ui::FormCategoriesEdit *ui;
    SGame _game;
    SAchievements _achievements;
    Category _categories;
    EditType _typeEdit = EditType::none;
    MyFilter *_fAchievements = nullptr;

    Category *_currentCategory = nullptr;
    Category *_currentCategoryNewParent = nullptr;
};

#endif // FORMACHIEVEMENTSCATEGORIESEDIT_H
