#include "formcategoriestree.h"

FormCategoriesTree::FormCategoriesTree(QWidget *parent): QTreeWidget(parent) {
    this->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this, &QTreeWidget::customContextMenuRequested, this, [=](QPoint pos) {
        updateCurrentCategory();
        QMenu *menu = createMenu(_currentCategory);
        menu->popup(this->viewport()->mapToGlobal(pos));
    });
}

void FormCategoriesTree::setGame(const SGame &aGame) {
    _game = aGame;
    _categories.setGame(_game);
    updateUi();
}

QMenu *FormCategoriesTree::createMenu(Category *aCategory) {
    //Кнопка изменения достижений
    QAction *actionAchievements = new QAction(QIcon(Images::change()), tr("Изменить категорию"), this);

    //Кнопка добавления подкатегории
    QAction *actionSubCategory = new QAction(QIcon(Images::create()), tr("Добавить подкатегорию"), this);

    //Кнопка удаления категории
    QAction *actionDelete = new QAction(QIcon(Images::deleteIcon()), tr("Удалить категорию"), this);

    QMenu *menu = new QMenu(this);
    menu->addAction (actionAchievements);
    menu->addAction (actionSubCategory);
    menu->addAction (actionDelete);

    connect (actionAchievements,    &QAction::triggered,    this,   [=](){emit s_categoryChange(aCategory);});
    connect (actionSubCategory,     &QAction::triggered,    this,   [=](){emit s_categoryAdd(aCategory);});
    connect (actionDelete,          &QAction::triggered,    this,   [=](){emit s_categoryDelete(aCategory);});

    return menu;
}

QString FormCategoriesTree::getText(QTreeWidgetItem *item) {
    QWidget *widget = this->itemWidget(item, 0);
    if (QCheckBox *checkBox = dynamic_cast<QCheckBox*>(widget)) {
        return checkBox->text();
    }
    if (QLabel *label = dynamic_cast<QLabel*>(widget)) {
        return label->text();
    }
    return QString();
}

void FormCategoriesTree::updateCurrentCategory() {
    //_currentCategoryIndex
    auto currentItem = this->currentItem();
    if (currentItem == nullptr) {
        _currentCategory = nullptr;
        return;
    }
    QStringList names {getText(currentItem)};
    while (currentItem->parent() != nullptr) {
        currentItem = currentItem->parent();
        names << getText(currentItem);
    }
    _currentCategory = &_categories;
    while (!names.isEmpty()) {
        for (auto &category: *_currentCategory) {
            if (category->title() == names.last()) {
                _currentCategory = category;
                names.removeLast();
                break;
            }
        }
    }
}

void FormCategoriesTree::recursAddCategoryToTree(Category *aCategory, QTreeWidgetItem *aRoot) {
    //create widget
    QWidget *widget;
    if (aCategory->achievementsApiName().isEmpty()) {
        widget = new QLabel(aCategory->title());
    } else {
        widget = new QCheckBox(aCategory->title());
        connect(dynamic_cast<QCheckBox*>(widget), &QCheckBox::stateChanged, this, &FormCategoriesTree::checkBoxCategory_StateChanged);
    }
    widget->setAccessibleName(QString::number(aCategory->order() + 1));

    //calculate sizeHint
    QSize sizeHint;
    sizeHint = widget->sizeHint();
    sizeHint.rwidth() += 10;

    //create treeItem
    QTreeWidgetItem *treeItem;
    if (aRoot == nullptr) {
        treeItem = new QTreeWidgetItem(this);
    } else {
        treeItem = new QTreeWidgetItem(aRoot);
    }
    treeItem->setSizeHint(0, sizeHint);

    this->setItemWidget(treeItem, 0, widget);
    for(auto subCategory: *aCategory) {
        recursAddCategoryToTree(subCategory, treeItem);
    }
}

void FormCategoriesTree::checkBoxCategory_StateChanged(const int &aIndex) {
    updateCurrentCategory();
    if (_currentCategory != nullptr) {
        emit s_stateChanged(_currentCategory, aIndex == 2);
    }
}

void FormCategoriesTree::updateUi() {
    _categories.update();

    this->clear();
    for(auto &category: _categories) {
        recursAddCategoryToTree(category);
    }
}
