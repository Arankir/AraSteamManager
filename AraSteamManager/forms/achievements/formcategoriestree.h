#ifndef FORMCATEGORIESTREE_H
#define FORMCATEGORIESTREE_H

#include <QTreeWidget>
#include <QObject>
#include <QWidget>
#include <QCheckBox>
#include <QMenu>
#include <QAction>
#include "classes/files/achievementscategory.h"

class FormCategoriesTree : public QTreeWidget {
    Q_OBJECT
public:
    FormCategoriesTree(QWidget *parent = nullptr);
    ~FormCategoriesTree();
    void setGame(const SGame &gameId);
    QList<Category2*> getCheckedCategories();
    Category2 *getCurrentCategory();
    const Category2 &getCategories() {return *_categories;}
    int getCategoriesCount() {return _categories->countCategories();}

public slots:
    void updateUi();

signals:
    void s_stateChanged(Category2 *category, const bool &state);
    void s_categoryChange(Category2 *category);
    void s_categoryAdd(Category2 *category);
    void s_categoryDelete(Category2 *category);

private:
    SGame _game;
    Category2 *_categories;
    Category2 *_currentCategory = nullptr;

    void updateCurrentCategory();
    QMenu *createMenu(Category2 *aCategory);
    void checkBoxCategory_StateChanged(const int &aIndex);
    void recursAddCategoryToTree(Category2 *aCategory, QTreeWidgetItem *aRoot = nullptr);
    QString getText(QTreeWidgetItem *item);
};

#endif // FORMCATEGORIESTREE_H
