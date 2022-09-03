#ifndef FORMACHIEVEMENTSCATEGORIESEDIT_H
#define FORMACHIEVEMENTSCATEGORIESEDIT_H

#include "classes/files/category.h"
#include "classes/steamApi/structures/sgames.h"
#include "subWidgets/items/qlistwidgetachievement.h"

namespace Ui {
    class FormCategoriesEdit;
}

class FormCategoriesEdit : public Form {
    Q_OBJECT
public slots:
//    void updateSettings(QFlags<changedSettings> aSettings) override;

public:
    explicit FormCategoriesEdit(QWidget *parent = nullptr);
    ~FormCategoriesEdit();
    void setAchievements(const SAchievements &aAchievements, const GameID &aGameId);
    void setVisibleItems(const QList<AchievementID> &items);
    void updateHiddenItems();
    void changeCategory(Category *aCategory);

signals:
    void s_categoriesIsUpdated(const bool &isUpdated);

private slots:
    void init();
    void updateIcons() override;
    void retranslate() override;
    void achievementsToUi();
    int indexFromRow(QListWidget *listWidget, const int &row);
    void buttonCancel_Clicked();
    void buttonAccept_Clicked();
private:
    Ui::FormCategoriesEdit *ui;
    GameID gameId_;
    SAchievements _achievements;
    QList<AchievementID> _visibleAchievements;

    Category *_currentCategory = nullptr;
};

#endif // FORMACHIEVEMENTSCATEGORIESEDIT_H
