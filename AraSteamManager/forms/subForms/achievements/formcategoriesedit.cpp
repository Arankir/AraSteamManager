#include "formcategoriesedit.h"
#include "ui_formcategoriesedit.h"
#include "subWidgets/actions/actioncategory.h"

FormCategoriesEdit::FormCategoriesEdit(const SGame &aGame, QWidget *aParent) : QWidget(aParent), ui(new Ui::FormCategoriesEdit),
    _game(aGame), _categories(_game) {
    ui->setupUi(this);
    init();
}

FormCategoriesEdit::FormCategoriesEdit(QWidget *aParent) : FormCategoriesEdit(SGame(), aParent) {

}

FormCategoriesEdit::~FormCategoriesEdit() {
    qInfo() << "Форма редактирования категорий удалилась";
    delete ui;
}

void FormCategoriesEdit::setGame(SGame &aGame) {
    _game = aGame;
    _categories.setGame(_game);
    ui->ListWidgetAll->setGame(_game);
    ui->ListWidgetCategory->setGame(_game);
    ui->ButtonChangeParent->setMenu(createParentMenu());
    changeEditType(_typeEdit);
}

void FormCategoriesEdit::setAchievements(QList<SAchievement> &aAchievements) {
    _achievements = aAchievements;
    achievementsToUi();
}

void FormCategoriesEdit::setFilter(MyFilter *aFilter) {
    _fAchievements = aFilter;
    updateHiddenItems();
}

void FormCategoriesEdit::achievementsToUi() {
    ui->ListWidgetAll->clear();
    ui->ListWidgetCategory->clear();
//    QFont font(Settings::getFontDefaultName(), 11);
    for (auto &achievement: _achievements) {
        ui->ListWidgetAll->addAchievementItem(achievement);
//        QListWidgetAchievement *item = new QListWidgetAchievement(&achievement);
//        item->setIcon(achievement.getIcon(_game.appId()));
//        item->setText(achievement._displayName);
//        item->setToolTip(achievement._description);
//        item->setFont(font);
//        ui->ListWidgetAll->addItem(item);
    }
}

void FormCategoriesEdit::init() {
    ui->ListWidgetAll->setDropIndicatorShown(true);
    ui->ListWidgetAll->setDragEnabled(true);
    ui->ListWidgetAll->setDragDropMode(QAbstractItemView::DragDrop);
    ui->ListWidgetAll->setDefaultDropAction(Qt::DropAction::MoveAction);
    ui->ListWidgetAll->setWordWrap(true);

    ui->ListWidgetCategory->setDropIndicatorShown(true);
    ui->ListWidgetCategory->setDragEnabled(true);
    ui->ListWidgetCategory->setDragDropMode(QAbstractItemView::DragDrop);
    ui->ListWidgetCategory->setDefaultDropAction(Qt::DropAction::MoveAction);
    ui->ListWidgetCategory->setWordWrap(true);

    ui->ListWidgetSubCategories->setDropIndicatorShown(true);
    ui->ListWidgetSubCategories->setDragEnabled(true);
    ui->ListWidgetSubCategories->setDragDropMode(QAbstractItemView::DragDropMode::InternalMove);
    ui->ListWidgetSubCategories->setDefaultDropAction(Qt::DropAction::MoveAction);
    ui->ListWidgetSubCategories->setWordWrap(true);

    changeEditType(EditType::none);
    ui->ButtonChangeParent->setMenu(createParentMenu());

    setIcons();
#define Connects {
    connect(ui->ButtonAddCategory,          &QPushButton::clicked,  this, &FormCategoriesEdit::buttonAdd_Clicked);
    connect(ui->ButtonCancelCategory,       &QPushButton::clicked,  this, &FormCategoriesEdit::buttonCancel_Clicked);
    connect(ui->ButtonAcceptCategory,       &QPushButton::clicked,  this, &FormCategoriesEdit::buttonAccept_Clicked);
    connect(ui->ButtonDeleteCategory,       &QPushButton::clicked,  this, &FormCategoriesEdit::buttonDelete_Clicked);
    connect(ui->ButtonDeleteAllCategories,  &QPushButton::clicked,  this, &FormCategoriesEdit::buttonDeleteAll_Clicked);
#define ConnectsEnd }
}

void FormCategoriesEdit::setIcons() {
    ui->ButtonAddCategory           ->setIcon(QIcon(Images::create()));
    ui->ButtonDeleteCategory        ->setIcon(QIcon(Images::deleteCategory()));
    ui->ButtonDeleteAllCategories   ->setIcon(QIcon(Images::deleteAllCategories()));
    ui->ButtonChangeParent          ->setIcon(QIcon(Images::moveInTree()));
    ui->ButtonAcceptCategory        ->setIcon(QIcon(Images::apply()));
    ui->ButtonCancelCategory        ->setIcon(QIcon(Images::cancel()));
}

int FormCategoriesEdit::indexFromRow(QListWidget *aListWidget, int aRow) {
    QListWidgetAchievement *achievement = dynamic_cast<QListWidgetAchievement*>(aListWidget->item(aRow));
    if (achievement) {
        QString apiName = achievement->_achievement->apiName();
        int index = 0;
        for(const auto &ach: _achievements) {
            if (ach.apiName() == apiName) {
                return index;
            }
            ++index;
        }
    }
    return -1;
}

void FormCategoriesEdit::updateHiddenItems() {
    if (_fAchievements == nullptr) {
        return;
    }
    for(int row = 0; row < ui->ListWidgetAll->count(); ++row) {
        ui->ListWidgetAll->setRowHidden(row, !_fAchievements->getData(indexFromRow(ui->ListWidgetAll, row)));
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
        ui->ButtonDeleteAllCategories->setEnabled(_categories.countCategories() != 0);

        ui->LineEditTitleCategory->setText("");
        ui->LineEditTitleCategory->setEnabled(false);
        ui->ListWidgetCategory->setEnabled(false);
        ui->FrameSubCategories->setEnabled(false);
        ui->FrameSubCategories->setVisible(false);
        ui->ListWidgetSubCategories->clear();

        ui->ButtonAcceptCategory->setEnabled(false);
        ui->ButtonCancelCategory->setEnabled(false);

        ui->LabelCategoryParent->setText("");
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
        ui->FrameSubCategories->setEnabled(false);
        ui->FrameSubCategories->setVisible(false);
        ui->ListWidgetSubCategories->clear();

        ui->ButtonAcceptCategory->setEnabled(true);
        ui->ButtonCancelCategory->setEnabled(true);

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
        ui->FrameSubCategories->setEnabled(true);
        ui->FrameSubCategories->setVisible(_currentCategory->categories().count() > 0);

        ui->ButtonAcceptCategory->setEnabled(true);
        ui->ButtonCancelCategory->setEnabled(true);

        break;
    }
    }
    _typeEdit = aType;
}

void FormCategoriesEdit::changeCategory(Category *aCategory) {
    _currentCategory = aCategory;
    _currentCategoryParent = aCategory->parent();
    changeNewParent(_currentCategoryParent);
    changeEditType(EditType::change);
    ui->LineEditTitleCategory->setText(aCategory->title());

//    QFont font(Settings::defaultFont(), 11);
    ui->ListWidgetAll->clear();
    ui->ListWidgetCategory->clear();
    auto achievementList = aCategory->achievementsApiName();
    for(auto &achievement: _achievements) {
        bool isInCategory = std::any_of(achievementList.begin(),
                                        achievementList.end(),
                                        [=](QString &aAchievement) {
                                            return aAchievement == achievement.apiName();
                                        });
        QListWidgetAchievement *item = new QListWidgetAchievement(&achievement);
        item->setIcon(achievement.icon(_game.appId()));
        item->setText(achievement.displayName());
        item->setToolTip(achievement.description());
//        item->setFont(font);
        if (isInCategory) {
            ui->ListWidgetCategory->addItem(item);
        } else {
            ui->ListWidgetAll->addItem(item);
        }
    }
    auto subCategoriesList = aCategory->categories();
    ui->ListWidgetSubCategories->clear();
    int row = 0;
    for(auto &subCategory: subCategoriesList) {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(subCategory->title());
        item->setWhatsThis(QString::number(row));
//        item->setFont(font);
        item->setFlags(Qt::ItemFlag::ItemIsEditable | item->flags());
        ui->ListWidgetSubCategories->addItem(item);
        ++row;
    }
}

void FormCategoriesEdit::addSubCategory(Category *aParent) {
    _currentCategory = nullptr;
    _currentCategoryParent = nullptr;
    changeEditType(EditType::add);
    changeNewParent(aParent);
}

void FormCategoriesEdit::deleteCategory(Category *aCategory) {
    _currentCategory = _categories.findCategory(aCategory);
    _currentCategoryParent = _currentCategory->parent();
    changeEditType(EditType::change);
    buttonDelete_Clicked();
}

void FormCategoriesEdit::buttonAdd_Clicked() {
    _currentCategory = nullptr;
    _currentCategoryParent = nullptr;
    changeEditType(EditType::add);
    changeNewParent(nullptr);
}

//void FormCategoriesEdit::changeParentButton_Clicked() {
//    QPushButton *senderButton = dynamic_cast<QPushButton*>(sender());
//    if (senderButton) {
//        Category *parent = _categories.categoryAtDirect(senderButton->accessibleName().toInt());
//        if (parent) {
//            if (parent != _currentCategory) {
//                changeNewParent(parent);
//            } else {
//                qWarning() << "changed parent to itself";
//                QMessageBox::warning(this, tr("Ошибка"), tr("Нельзя выбрать основной категорией самого себя!"));
//            }
//        }
//    }

//}

void FormCategoriesEdit::changeNewParent(Category *aParent) {
    if (aParent != nullptr) {
        ui->LabelCategoryParent->setText(tr("Подкатегория %1").arg(aParent->title()));
    } else {
        ui->LabelCategoryParent->setText(tr("Основная категория"));
    }
    _currentCategoryNewParent = aParent;
}

void FormCategoriesEdit::changeNewParentFromAction() {
    ActionCategory *action = dynamic_cast<ActionCategory*>(sender());
    if (action) {
        _currentCategoryNewParent = action->category();
        ui->LabelCategoryParent->setText(action->text());
    }
}

QMenu *FormCategoriesEdit::createParentMenu() {
    _categories.update();

    QMenu *menu = new QMenu(this);

    ActionCategory *root = new ActionCategory(nullptr, QIcon(Images::moveItem()), tr("Основная категория"), this);
    connect (root, &QAction::triggered, this, &FormCategoriesEdit::changeNewParentFromAction);

    menu->addAction(root);

    for(auto &category: _categories) {
        menu->addMenu(createParentSubMenu(category));
    }

    return menu;
}

QMenu *FormCategoriesEdit::createParentSubMenu(Category *aCategory) {
    QMenu *menu = new QMenu(aCategory->title());
    //menu->setIcon(QIcon(Images::goTo()));

    ActionCategory *action = new ActionCategory(aCategory, QIcon(Images::moveItem()), tr("Подкатегория для %1").arg(aCategory->title()), this);
    connect (action, &QAction::triggered, this, &FormCategoriesEdit::changeNewParentFromAction);

    menu->addAction(action);

    for(auto category: *aCategory) {
        menu->addMenu(createParentSubMenu(category));
    }

    return menu;
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

    _categories.clearCategories();
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
                            [=](Category *sCategory) {
                                return (sCategory->title() == aName);
                            });
    } else {
        return std::any_of( _categories.begin(),
                            _categories.end(),
                            [=](Category *sCategory) {
                                return (sCategory->title() == aName);
                            });
    }
}

void FormCategoriesEdit::buttonAccept_Clicked() {
    QString newTitle = ui->LineEditTitleCategory->text();
    if (newTitle == "") {
        QMessageBox::warning(this, tr("Ошибка"), tr("Название категории пустое!"));
        return;
    }
    if (_currentCategory != nullptr && _currentCategoryNewParent != nullptr) {
        if ((_currentCategory->findCategory(_currentCategoryNewParent) != nullptr) || (*_currentCategory == *_currentCategoryNewParent)) {
            QMessageBox::warning(this, tr("Ошибка"), tr("Нельзя переместить категорию в саму себя!"));
            return;
        }
    }

    QList<QString> categoryAchievements;
    for(int i = 0; i < ui->ListWidgetCategory->count(); ++i) {
        if (auto item = dynamic_cast<QListWidgetAchievement*>(ui->ListWidgetCategory->item(i))) {
            categoryAchievements.append(item->_achievement->apiName());
        }
    }

    switch (_typeEdit) {
    case EditType::add: {
        if (_currentCategory == nullptr || _currentCategory->title() != newTitle) {
            if (isCategoryNameExist(newTitle)) {
                QMessageBox::warning(this, tr("Ошибка"), tr("Такая категория уже есть!"));
                return;
            }
        }
        if (_currentCategory != nullptr) {
            qWarning() << "on EditType:add current category is exist";
            break;
        }
        _currentCategory = new Category(newTitle, categoryAchievements);
        if (_currentCategoryNewParent != nullptr) {
            qDebug() << 1;
            _categories.findCategory(_currentCategoryNewParent)->addCategory(_currentCategory);
            qDebug() << 2;
        } else {
            qDebug() << 3;
            _categories.addCategory(_currentCategory);
        }
        break;
    }
    case EditType::change: {
        if (_currentCategory != nullptr) {
            _currentCategory = _categories.findCategory(_currentCategory);
        }
        if (_currentCategory == nullptr) {
            qWarning() << "on apply category does not exist";
            QMessageBox::warning(this, tr("Ошибка"), tr("Невозможно найти категорию!"));
            return;
        }
        if (_currentCategory->title() != newTitle) {
            if (isCategoryNameExist(newTitle)) {
                QMessageBox::warning(this, tr("Ошибка"), tr("Такая категория уже есть!"));
                return;
            }
        }
        if (_currentCategoryNewParent != _currentCategoryParent) {
            if (_currentCategoryParent == nullptr) {
                _categories.removeCategory(_currentCategory);
            }
            _currentCategory->changeParent(_currentCategoryNewParent);
            if (_currentCategoryNewParent == nullptr) {
                _categories.addCategory(_currentCategory);
            }
        }
        _currentCategory->setTitle(newTitle);
        _currentCategory->setAchievements(categoryAchievements);

        QList<Category*> subCategoryList;
        for (int i = 0; i < ui->ListWidgetSubCategories->count(); ++i) {
            auto item = ui->ListWidgetSubCategories->item(i);
            Category *sub = _currentCategory->categories().at(item->whatsThis().toInt());
            sub->setTitle(item->text());
            subCategoryList.append(sub);
        }
        _currentCategory->clearCategories();
        for(auto category: subCategoryList) {
            _currentCategory->addCategory(category);
        }
        break;
    }
    default: {
        qWarning() << "on save category unknown type";
        return;
    }
    }

    _categories.save();
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
        qWarning() << "save category with unknown edit type";
    }
    }
    ui->ButtonChangeParent->setMenu(createParentMenu());
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

    if (_categories.removeCategory(_currentCategory, true)) {
        emit s_categoriesIsUpdated(true);
        QMessageBox::information(this, tr("Успешно"), tr("Категория была удалена!"));
    } else {
        qWarning() << "global category index not found";
        emit s_categoriesIsUpdated(false);
        QMessageBox::information(this, tr("Ошибка"), tr("Категория не найдена!"));
    }
    ui->ButtonChangeParent->setMenu(createParentMenu());

    buttonCancel_Clicked();
}
#define CategoryEnd }
