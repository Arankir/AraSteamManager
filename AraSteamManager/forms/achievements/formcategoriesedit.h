#ifndef FORMACHIEVEMENTSCATEGORIESEDIT_H
#define FORMACHIEVEMENTSCATEGORIESEDIT_H

#include "form.h"
#include "classes/files/category.h"
#include "classes/steamApi/structures/sgames.h"
#include "subWidgets/items/qlistwidgetachievement.h"

namespace Ui {
    class FormCategoriesEdit;
}

class FormCategoriesEdit : public Form {
    Q_OBJECT
public slots:

public:
    explicit FormCategoriesEdit(QWidget *parent = nullptr);
    ~FormCategoriesEdit();
    void setAchievements(const SAchievements &achievements, const GameID &nameId);
    void setVisibleItems(const QList<AchievementID> &items);
    void updateHiddenItems();
    void changeCategory(Category *category);

signals:
    void s_categoriesIsUpdated(bool isUpdated);

private slots:
    void init();
    void updateIcons() override;
    void retranslate() override;
    void achievementsToUi();
    int indexFromRow(QListWidget *listWidget, int row);
    void buttonCancel_Clicked();
    void buttonAccept_Clicked();
private:
    Ui::FormCategoriesEdit *ui;
    GameID gameId_;
    SAchievements achievements_;
    QList<AchievementID> visibleAchievements_;

    Category *currentCategory_ = nullptr;
};

#endif // FORMACHIEVEMENTSCATEGORIESEDIT_H
