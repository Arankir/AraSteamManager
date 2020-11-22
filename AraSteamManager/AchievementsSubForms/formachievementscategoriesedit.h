#ifndef FORMACHIEVEMENTSCATEGORIESEDIT_H
#define FORMACHIEVEMENTSCATEGORIESEDIT_H

#include <QWidget>
#include <QMessageBox>
#include <QStandardItemModel>
#include "class/settings.h"
#include "class/myfilter.h"
#include "class/categoriesgame.h"
#include "class/steamapi/Sgames.h"
#include "AchievementsSubForms/formcategoryvalue.h"
#include "AchievementsSubForms/formcategoryvalue.h"
#include "AchievementsSubForms/formachievementwidget.h"

enum class CategoryType {
    none,
    add,
    changeNotSelected,
    changeSelected
};

namespace Ui {
class FormAchievementsCategoriesEdit;
}

class FormAchievementsCategoriesEdit : public QWidget
{
    Q_OBJECT

public:
    explicit FormAchievementsCategoriesEdit(const SGame &game, QWidget *parent = nullptr);
    explicit FormAchievementsCategoriesEdit(QWidget *parent = nullptr);
    ~FormAchievementsCategoriesEdit();
    void setGame(SGame game);
    void setAchievements(SAchievements &aAchievements);
    void updateFilter(const MyFilter &aFilter);

signals:
    void s_categoriesIsUpdated(bool isUpdated);
    void s_updateSettings();

private slots:
    void changeCategoryType(CategoryType type);
    void buttonAddCategory_Clicked();
    void buttonChangeCategory_Clicked();
    void buttonDeleteAllCategories_Clicked();
    void buttonAddValueCategory_Clicked();
    void buttonCancelCategory_Clicked();
    void buttonAcceptCategory_Clicked();
    void buttonDeleteCategory_Clicked();
    void checkBoxCategoryOneValue_StateChanged(int arg1);
    void lineEditTitleCategory_TextChanged(const QString &arg1);
    void comboBoxCategories_Activated(int aIndex);
    void updateValuesOrder();
    void formCategoryValueReverse();
    void formCategoryValueFirst();
    void formCategoryValueBack();
    void formCategoryValueNext();
    void formCategoryValueLast();
    void formCategoryValueSelectVisible();
    void formCategoryValueUnselectVisible();
    void formCategoryValueDelete();
    void formCategoryDelete(int aPos);
    void setIcons();
    FormCategoryValue *createValueCategory();
    void updateUniqueAchievements();
    void init();
    void setUniqueMode(bool aIsUnique);
    void createCategoryNoValue(int aCategoryIndex, const QString &aTitle);
    bool createCategoryValue(int aCategoryIndex, const QString &aTitle);
private:
    Ui::FormAchievementsCategoriesEdit *ui;
    SGame _game;
    CategoriesGame _categoriesGame;
    CategoryType _typeCategory = CategoryType::none;
    bool _isNoValue = true;
    QList<FormCategoryValue*> _values;
    bool _isUnique = false;
};

#endif // FORMACHIEVEMENTSCATEGORIESEDIT_H
