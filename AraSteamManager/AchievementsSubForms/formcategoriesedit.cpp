#include "formcategoriesedit.h"
#include "ui_formachievementscategoriesedit.h"

FormCategoriesEdit::FormCategoriesEdit(const SGame &aGame, QWidget *aParent) : QWidget(aParent), ui(new Ui::FormAchievementsCategoriesEdit),
    _game(aGame), _categories(_game) {
    ui->setupUi(this);
    init();
}

FormCategoriesEdit::FormCategoriesEdit(QWidget *aParent) : FormCategoriesEdit(SGame(), aParent) {

}

FormCategoriesEdit::~FormCategoriesEdit() {
    delete ui;
}

void FormCategoriesEdit::setGame(SGame aGame) {
    _game = aGame;
    _categories.setGame(_game);
    updateParentTree();
    changeEditType(_typeEdit);
}

void FormCategoriesEdit::setAchievements(SAchievements &aAchievements) {
    _achievements = aAchievements;
    achievementsToUi();
}

void FormCategoriesEdit::achievementsToUi() {
    ui->ListWidgetAll->clear();
    ui->ListWidgetCategory->clear();
    QFont font(Settings::getFontDefaultName(), 11);
    for (auto &achievement: _achievements) {
        QListWidgetAchievement *item = new QListWidgetAchievement(&achievement);
        item->setIcon(achievement.getIcon(_game.appId()));
        item->setText(achievement._displayName);
        item->setToolTip(achievement._description);
        item->setFont(font);
        ui->ListWidgetAll->addItem(item);
    }
}

void FormCategoriesEdit::init() {
    ui->ListWidgetAll->setDropIndicatorShown(false);
    ui->ListWidgetAll->setDragEnabled(true);
    ui->ListWidgetAll->setDragDropMode(QAbstractItemView::DragDrop);
    ui->ListWidgetAll->setDefaultDropAction(Qt::DropAction::MoveAction);
    ui->ListWidgetAll->setWordWrap(true);

    ui->ListWidgetCategory->setDropIndicatorShown(false);
    ui->ListWidgetCategory->setDragEnabled(true);
    ui->ListWidgetCategory->setDragDropMode(QAbstractItemView::DragDrop);
    ui->ListWidgetCategory->setDefaultDropAction(Qt::DropAction::MoveAction);
    ui->ListWidgetCategory->setWordWrap(true);

    changeEditType(EditType::none);
    updateParentTree();

    setIcons();
#define Connects {
    connect(ui->ButtonAddCategory,              &QPushButton::clicked,      this, &FormCategoriesEdit::buttonAdd_Clicked);
    connect(ui->ButtonCancelCategory,           &QPushButton::clicked,      this, &FormCategoriesEdit::buttonCancel_Clicked);
    connect(ui->ButtonAcceptCategory,           &QPushButton::clicked,      this, &FormCategoriesEdit::buttonAccept_Clicked);
    connect(ui->ButtonDeleteCategory,           &QPushButton::clicked,      this, &FormCategoriesEdit::buttonDelete_Clicked);
    connect(ui->ButtonDeleteAllCategories,      &QPushButton::clicked,      this, &FormCategoriesEdit::buttonDeleteAll_Clicked);
#define ConnectsEnd }
}

void FormCategoriesEdit::setIcons() {
    ui->ButtonAddCategory           ->setIcon(QIcon(Images::create()));
    ui->ButtonDeleteCategory        ->setIcon(QIcon(Images::deleteIcon()));
    ui->ButtonDeleteAllCategories   ->setIcon(QIcon(Images::deleteAll()));
    ui->ButtonAcceptCategory        ->setIcon(QIcon(Images::apply()));
    ui->ButtonCancelCategory        ->setIcon(QIcon(Images::cancel()));
}

int FormCategoriesEdit::indexFromRow(QListWidget *aListWidget, int aRow) {
    QListWidgetAchievement *achievement = dynamic_cast<QListWidgetAchievement*>(aListWidget->item(aRow));
    if (achievement) {
        QString apiName = achievement->_achievement->_apiName;
        int index = 0;
        for(const auto &ach: _achievements) {
            if (ach._apiName == apiName) {
                return index;
            }
            ++index;
        }
    }
    return -1;
}

void FormCategoriesEdit::updateFilter(const MyFilter &aFilter) {
//Неправильно сортирует, не учитывает перестановку
    for(int row = 0; row < ui->ListWidgetAll->count(); ++row) {
        ui->ListWidgetAll->setRowHidden(row, !aFilter.getData(indexFromRow(ui->ListWidgetAll, row)));
    }
}

void FormCategoriesEdit::changeEditType(EditType aType) {
    switch (aType) {
    case EditType::none: {
        ui->ButtonAddCategory->setEnabled(true);
        ui->ButtonDeleteCategory->setVisible(false);
        ui->ButtonDeleteCategory->setEnabled(false);
        ui->ButtonChangeParent->setVisible(false);
        ui->ButtonChangeParent->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(_categories.countTopCategories() != 0);

        ui->LineEditTitleCategory->setText("");
        ui->LineEditTitleCategory->setEnabled(false);
        ui->ListWidgetCategory->setEnabled(false);

        ui->ButtonAcceptCategory->setEnabled(false);
        ui->ButtonCancelCategory->setEnabled(false);

        ui->LabelCategoryParent->setText("");
        ui->TreeWidgetChangeParent->setEnabled(false);
        break;
    }
    case EditType::add: {
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonDeleteCategory->setVisible(false);
        ui->ButtonDeleteCategory->setEnabled(false);
        ui->ButtonChangeParent->setVisible(true);
        ui->ButtonChangeParent->setEnabled(true);
        ui->ButtonDeleteAllCategories->setEnabled(false);

        ui->LineEditTitleCategory->setText("");
        ui->LineEditTitleCategory->setEnabled(true);
        ui->ListWidgetCategory->setEnabled(true);

        ui->ButtonAcceptCategory->setEnabled(true);
        ui->ButtonCancelCategory->setEnabled(true);

        ui->TreeWidgetChangeParent->setEnabled(true);
        break;
    }
    case EditType::change: {
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonDeleteCategory->setVisible(true);
        ui->ButtonDeleteCategory->setEnabled(true);
        ui->ButtonChangeParent->setVisible(true);
        ui->ButtonChangeParent->setEnabled(true);
        ui->ButtonDeleteAllCategories->setEnabled(false);

        ui->LineEditTitleCategory->setEnabled(true);
        ui->ListWidgetCategory->setEnabled(true);

        ui->ButtonAcceptCategory->setEnabled(true);
        ui->ButtonCancelCategory->setEnabled(true);

        ui->TreeWidgetChangeParent->setEnabled(true);
        break;
    }
    }
    _typeEdit = aType;
}

void FormCategoriesEdit::buttonAdd_Clicked() {
    _currentCategory = nullptr;
    _currentCategoryGlobalIndex = -1;
    _currentCategoryParent = nullptr;
    changeEditType(EditType::add);
    changeNewParent(nullptr);
}

void FormCategoriesEdit::changeCategory(Category *aCategory, int aGlobalIndex) {
    _currentCategory = aCategory;
    _currentCategoryGlobalIndex = aGlobalIndex;
    //Что-то не так с парентом
    _currentCategoryParent = aCategory->parent();
    changeNewParent(_currentCategoryParent);
    changeEditType(EditType::change);
    ui->LineEditTitleCategory->setText(aCategory->title());
    for(auto &achievement: aCategory->achievements()) {

    }
}

void FormCategoriesEdit::addSubCategory(Category *aParent) {
    _currentCategory = nullptr;
    _currentCategoryGlobalIndex = -1;
    //Что-то не так с парентом
    _currentCategoryParent = nullptr;
    changeEditType(EditType::add);
    changeNewParent(aParent);
}

void FormCategoriesEdit::changeParentButton_Clicked() {
    QPushButton *senderButton = dynamic_cast<QPushButton*>(sender());
    if (senderButton) {
        Category *parent = _categories.getCategoryAtGlobalIndex(senderButton->accessibleName().toInt());
        if (parent) {
            if (parent != _currentCategory) {
                changeNewParent(parent);
            } else {
                qWarning() << "changed parent to itself";
                QMessageBox::warning(this, tr("Ошибка"), tr("Нельзя выбрать основной категорией самого себя!"));
            }
        }
    }

}

void FormCategoriesEdit::changeNewParent(Category *aParent) {
    if (aParent != nullptr) {
        ui->LabelCategoryParent->setText(tr("Подкатегория %1").arg(aParent->title()));
    } else {
        ui->LabelCategoryParent->setText(tr("Основная категория"));
    }
    _currentCategoryNewParent = aParent;
}

int FormCategoriesEdit::recursAddToParentTree(Category &aCategory, int aCount, QTreeWidgetItem *aRoot) {
    QTreeWidgetItem *subItem;
    if (aRoot == nullptr) {
        subItem = new QTreeWidgetItem(ui->TreeWidgetChangeParent);
    } else {
        subItem = new QTreeWidgetItem(aRoot);
    }
    QSize sizeHint;
    QPushButton *button = new QPushButton(aCategory.title());
    connect(button, &QPushButton::clicked, this, &FormCategoriesEdit::changeParentButton_Clicked);
    button->setAccessibleName(QString::number(aCount++));
    sizeHint = button->sizeHint();
    sizeHint.rwidth() += 10;
    subItem->setSizeHint(0, sizeHint);
    ui->TreeWidgetChangeParent->setItemWidget(subItem, 0, button);
    for(auto &subCategory: aCategory) {
        aCount = recursAddToParentTree(subCategory, aCount, subItem);
    }
    return aCount;
}

void FormCategoriesEdit::updateParentTree() {
    _categories.update();

    ui->TreeWidgetChangeParent->clear();
    int count = 0;
    for(auto &category: _categories) {
        count = recursAddToParentTree(category, count);
    }
}

void FormCategoriesEdit::buttonDeleteAll_Clicked() {
    QMessageBox deleteQuestion(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите удалить все категории?"));
    QAbstractButton *btnYes = deleteQuestion.addButton(tr("Да"), QMessageBox::YesRole);
    deleteQuestion.addButton(tr("Отмена"), QMessageBox::NoRole);
    deleteQuestion.exec();
    if(deleteQuestion.clickedButton() != btnYes) {
        return;
    }

    deleteQuestion.setText(tr("Данные о категориях будут утеряны навсегда, вы точно хотите удалить все категории?"));
    deleteQuestion.exec();
    if (deleteQuestion.clickedButton() != btnYes) {
        return;
    }

    _categories.deleteAll();
    emit s_categoriesIsUpdated(true);
}

#define Categorys {
void FormCategoriesEdit::buttonCancel_Clicked() {
    changeEditType(EditType::none);
    achievementsToUi();
}

bool FormCategoriesEdit::isCategoryNameExist(const QString &aName) {
//TODO Если не менять название при изменении, то выводит, что такая категория есть
    if (_currentCategoryNewParent != nullptr) {
        return std::any_of( _currentCategoryNewParent->begin(),
                            _currentCategoryNewParent->end(),
                            [=](Category sCategory) {
                                return (sCategory.title() == aName);
                            });
    } else {
        return std::any_of( _categories.begin(),
                            _categories.end(),
                            [=](Category sCategory) {
                                return (sCategory.title() == aName);
                            });
    }
}

void FormCategoriesEdit::buttonAccept_Clicked() {
    if (_typeEdit != EditType::add && _typeEdit != EditType::change) {
        qWarning() << "on save category unknown type";
        return;
    }
    QString newTitle = ui->LineEditTitleCategory->text();
    if (newTitle == "") {
        QMessageBox::warning(this, tr("Ошибка"), tr("Название категории пустое!"));
        return;
    }
    if (isCategoryNameExist(newTitle)) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Такая категория уже есть!"));
        return;
    }

    QList<QString> achievements;
    for(int i = 0; i < ui->ListWidgetCategory->count(); ++i) {
        achievements.append(ui->ListWidgetCategory->item(i)->text());
    }

    if (_typeEdit == EditType::change) {
        if (_currentCategory != nullptr) {
            Category newCategory = *_currentCategory;
            if (_currentCategoryNewParent != _currentCategoryParent) {
                if(_categories.removeCategory(*_currentCategory)) {
                    _currentCategory = &newCategory;
                }
                _currentCategory->setTitle(newTitle);
                _currentCategory->setAchievements(achievements);

                if (_currentCategoryNewParent != nullptr) {
                    _currentCategoryNewParent->addCategory(newCategory);
                } else {
                    _categories.addCategory(newCategory);
                }
                _currentCategory = nullptr;
            } else {
                _currentCategory->setTitle(newTitle);
                _currentCategory->setAchievements(achievements);
            }
        } else {
            qWarning() << "on EditType:change current category doesn't exist";
        }
    }
    if (_typeEdit == EditType::add) {
        if (_currentCategory == nullptr) {
            _currentCategory = new Category(newTitle, achievements);
            if (_currentCategoryNewParent != nullptr) {
                _currentCategory->setParent(_currentCategoryNewParent);
                _categories.addSubCategory(*_currentCategory);
            } else {
                _categories.addCategory(*_currentCategory);
            }
        } else {
            qWarning() << "on EditType:add current category is exist";
        }
    }

    _categories.save(_categories.toJson());

    emit s_categoriesIsUpdated(true);
    switch (_typeEdit) {
    case EditType::add: {
        QMessageBox::information(this, tr("Успешно"), tr("Категория была добавлена!"));
        break;
    }
    case EditType::change: {
        QMessageBox::information(this, tr("Успешно"), tr("Категория была изменена!"));
        break;
    }
    default: {
        qWarning() << "save category with unknown type";
    }
    }
    updateParentTree();
    buttonCancel_Clicked();
}

void FormCategoriesEdit::buttonDelete_Clicked() {
    if (_typeEdit != EditType::change) {
        return;
    }
    QMessageBox::StandardButton clickedButton = QMessageBox::question(this,
                                                                      tr("Внимание"),
                                                                      tr("Вы уверены, что хотите удалить категорию?"),
                                                                      QMessageBox::Yes |
                                                                      QMessageBox::No);
    if (clickedButton == QMessageBox::No) {
        return;
    }

    if (_currentCategoryGlobalIndex > -1) {
        _categories.removeCategory(*_currentCategory);
        emit s_categoriesIsUpdated(true);
        QMessageBox::information(this, tr("Успешно"), tr("Категория была удалена!"));
    } else {
        qWarning() << "global category index not found";
        emit s_categoriesIsUpdated(false);
        QMessageBox::information(this, tr("Ошибка"), tr("Не найден номер категории!"));
    }

    buttonCancel_Clicked();
}
#define CategoryEnd }
