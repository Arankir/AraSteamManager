#ifndef FORMCATEGORIESTREE_H
#define FORMCATEGORIESTREE_H

#include <QTreeWidget>
#include <QObject>
#include <QWidget>
#include <QCheckBox>
#include <QMenu>
#include <QAction>
#include "classes/achievements/categoriesgame.h"

class FormCategoriesTree : public QTreeWidget {
    Q_OBJECT
public:
    FormCategoriesTree(QWidget *parent);
    void setGame(const SGame &gameId);
    QList<Category*> getCheckedCategories();
    Category *getCurrentCategory();
    const Category &getCategories() {return _categories;}
    int getCategoriesCount() {return _categories.countCategories();}

public slots:
    void updateUi();

signals:
    void s_stateChanged(Category *category, const bool &state);
    void s_categoryChange(Category *category);
    void s_categoryAdd(Category *category);
    void s_categoryDelete(Category *category);

private:
    SGame _game;
    Category _categories;
    Category *_currentCategory = nullptr;

    void updateCurrentCategory();
    QMenu *createMenu(Category *aCategory);
    void checkBoxCategory_StateChanged(const int &aIndex);
    void recursAddCategoryToTree(Category *aCategory, QTreeWidgetItem *aRoot = nullptr);
    QString getText(QTreeWidgetItem *item);
};

#endif // FORMCATEGORIESTREE_H
