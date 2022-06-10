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
#include "classes/files/achievementscategory.h"
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

class FormCategoriesEdit : public Form {
    Q_OBJECT
public slots:
    void updateSettings(QFlags<changedSettings> aSettings) override;

public:
    explicit FormCategoriesEdit(const SGame &game, QWidget *parent = nullptr);
    explicit FormCategoriesEdit(QWidget *parent = nullptr);
    ~FormCategoriesEdit();
    void setGame(const SGame &game);
    void setAchievements(const SAchievements &aAchievements);
//    Category2 *categories() {return &_categories;}
    void setVisibleItems(const QList<QString> &items);
    void updateHiddenItems();
    void changeCategory(Category2 *aCategory);
    void addSubCategory(Category2 *aParent);
    void deleteCategory(Category2 *aCategory);

signals:
    void s_categoriesIsUpdated(const bool &isUpdated);

private slots:
    void init();
    void updateIcons() override;
    void retranslate() override;
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
    void changeNewParent(Category2 *parent);
    QMenu *createParentMenu(Category2 *category = nullptr);
    void changeNewParentFromAction();
    void changeCategoryParent(Category2 *category);
private:
    Ui::FormCategoriesEdit *ui;
    SGame _game;
    SAchievements _achievements;
//    Category2 _categories;
    EditType _typeEdit = EditType::none;
    QList<QString> _visibleAchievements;

    Category2 *_currentCategory = nullptr;
    Category2 *_currentCategoryNewParent = nullptr;
};

#endif // FORMACHIEVEMENTSCATEGORIESEDIT_H
