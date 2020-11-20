#include "formachievementscategoriesedit.h"
#include "ui_formachievementscategoriesedit.h"

FormAchievementsCategoriesEdit::FormAchievementsCategoriesEdit(const SGame &aGame, QWidget *aParent) : QWidget(aParent), ui(new Ui::FormAchievementsCategoriesEdit),
    _game(aGame), _categoriesGame(_game) {
    ui->setupUi(this);
    init();
}

FormAchievementsCategoriesEdit::FormAchievementsCategoriesEdit(QWidget *aParent) : FormAchievementsCategoriesEdit(SGame(), aParent) {

}

FormAchievementsCategoriesEdit::~FormAchievementsCategoriesEdit() {
    delete ui;
}

void FormAchievementsCategoriesEdit::setGame(SGame aGame) {
    _game = aGame;
    _categoriesGame.setGame(_game);
    changeCategoryType(_typeCategory);
}

void FormAchievementsCategoriesEdit::setAchievements(SAchievements &aAchievements) {
    int row = 0;
    QFont font(Settings::getFontDefaultName(), 9);
    QStandardItemModel *model = new QStandardItemModel();
    for (auto &achievement: aAchievements) {
        QStandardItem *item = new QStandardItem();
        item->setData(achievement.getIcon(_game.appId()).scaled(32, 32), Qt::DecorationRole);
        item->setText(achievement._displayName);
        item->setData(achievement._description, Qt::ToolTipRole);
        item->setData(achievement._apiName, Qt::WhatsThisRole);
        item->setFont(font);
        model->setItem(row, item);
        ++row;
    }
    ui->ListViewAll->setModel(model);
}

void FormAchievementsCategoriesEdit::init() {
    ui->ListViewAll->setDropIndicatorShown(false);
    ui->ListViewAll->setDragEnabled(true);
    ui->ListViewAll->setDragDropMode(QAbstractItemView::DragOnly);
    ui->ListViewAll->setWordWrap(true);

    changeCategoryType(CategoryType::none);

    setIcons();
#define Connects {
    connect(ui->ButtonAddCategory,              &QPushButton::clicked,      this, &FormAchievementsCategoriesEdit::buttonAddCategory_Clicked);
    connect(ui->ButtonChangeCategory,           &QPushButton::clicked,      this, &FormAchievementsCategoriesEdit::buttonChangeCategory_Clicked);
    connect(ui->ButtonDeleteAllCategories,      &QPushButton::clicked,      this, &FormAchievementsCategoriesEdit::buttonDeleteAllCategories_Clicked);
    connect(ui->ButtonAddValueCategory,         &QPushButton::clicked,      this, &FormAchievementsCategoriesEdit::buttonAddValueCategory_Clicked);
    connect(ui->ButtonAcceptCategory,           &QPushButton::clicked,      this, &FormAchievementsCategoriesEdit::buttonAcceptCategory_Clicked);
    connect(ui->ButtonCancelCategory,           &QPushButton::clicked,      this, &FormAchievementsCategoriesEdit::buttonCancelCategory_Clicked);
    connect(ui->ButtonDeleteCategory,           &QPushButton::clicked,      this, &FormAchievementsCategoriesEdit::buttonDeleteCategory_Clicked);
    connect(ui->LineEditTitleCategory,          &QLineEdit::textChanged,    this, &FormAchievementsCategoriesEdit::lineEditTitleCategory_TextChanged);
    connect(ui->ComboBoxCategories,             SIGNAL(activated(int)),     this, SLOT(comboBoxCategories_Activated(int)));
    connect(ui->CheckBoxCategoryUniqueValue,    &QCheckBox::stateChanged,   this, &FormAchievementsCategoriesEdit::setUniqueMode);
#define ConnectsEnd }
}

void FormAchievementsCategoriesEdit::setIcons() {
    ui->ButtonAddCategory           ->setIcon(QIcon(Images::create()));
    ui->ButtonChangeCategory        ->setIcon(QIcon(Images::change()));
    ui->ButtonDeleteCategory        ->setIcon(QIcon(Images::deleteIcon()));
    ui->ButtonDeleteAllCategories   ->setIcon(QIcon(Images::deleteAll()));
    ui->ButtonAddValueCategory      ->setIcon(QIcon(Images::create()));
    ui->ButtonAcceptCategory        ->setIcon(QIcon(Images::apply()));
    ui->ButtonCancelCategory        ->setIcon(QIcon(Images::cancel()));
}

void FormAchievementsCategoriesEdit::updateFilter(const MyFilter &aFilter) {
    for(int row = 0; row < ui->ListViewAll->model()->rowCount(); ++row) {
        ui->ListViewAll->setRowHidden(row, !aFilter.getData(row));
    }
}

void FormAchievementsCategoriesEdit::changeCategoryType(CategoryType aType) {
    switch (aType) {
    case CategoryType::none: {
        ui->ButtonAddCategory->setEnabled(true);
        ui->ButtonChangeCategory->setEnabled(_categoriesGame.getCount() != 0);
        ui->ButtonDeleteAllCategories->setEnabled(_categoriesGame.getCount() != 0);

        ui->ComboBoxCategories->setVisible(false);
        ui->ComboBoxCategories->setCurrentIndex(0);
        ui->LineEditTitleCategory->setText("");
        ui->LineEditTitleCategory->setEnabled(false);

        ui->ButtonAddValueCategory->setEnabled(false);
        ui->CheckBoxCategoryUniqueValue->setChecked(false);
        ui->CheckBoxCategoryUniqueValue->setEnabled(false);

        ui->ButtonAcceptCategory->setEnabled(false);
        ui->ButtonCancelCategory->setEnabled(false);

        ui->ButtonDeleteCategory->setVisible(false);
        ui->ButtonDeleteCategory->setEnabled(false);
        break;
    }
    case CategoryType::add: {
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(false);

        ui->ComboBoxCategories->setVisible(false);
        ui->ComboBoxCategories->setCurrentIndex(0);
        ui->LineEditTitleCategory->setText("");
        ui->LineEditTitleCategory->setEnabled(true);

        ui->ButtonAddValueCategory->setEnabled(true);
        ui->CheckBoxCategoryUniqueValue->setChecked(false);
        ui->CheckBoxCategoryUniqueValue->setEnabled(false);

        ui->ButtonAcceptCategory->setEnabled(true);
        ui->ButtonCancelCategory->setEnabled(true);

        ui->ButtonDeleteCategory->setVisible(false);
        ui->ButtonDeleteCategory->setEnabled(false);
        break;
    }
    case CategoryType::changeNotSelected: {
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(false);

        ui->ComboBoxCategories->setVisible(true);
        ui->ComboBoxCategories->setCurrentIndex(0);
        ui->LineEditTitleCategory->setText("");
        ui->LineEditTitleCategory->setEnabled(false);

        ui->ButtonAddValueCategory->setEnabled(false);
        ui->CheckBoxCategoryUniqueValue->setChecked(false);
        ui->CheckBoxCategoryUniqueValue->setEnabled(false);

        ui->ButtonAcceptCategory->setEnabled(false);
        ui->ButtonCancelCategory->setEnabled(true);

        ui->ButtonDeleteCategory->setVisible(true);
        ui->ButtonDeleteCategory->setEnabled(false);
        break;
    }
    case CategoryType::changeSelected: {
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(false);

        ui->ComboBoxCategories->setVisible(true);
        ui->LineEditTitleCategory->setEnabled(true);

        ui->ButtonAddValueCategory->setEnabled(true);
        ui->CheckBoxCategoryUniqueValue->setEnabled(false);

        ui->ButtonAcceptCategory->setEnabled(true);
        ui->ButtonCancelCategory->setEnabled(true);

        ui->ButtonDeleteCategory->setVisible(true);
        ui->ButtonDeleteCategory->setEnabled(true);
        break;
    }
    }
    _typeCategory = aType;
}

void FormAchievementsCategoriesEdit::buttonAddCategory_Clicked() {
    changeCategoryType(CategoryType::add);
}

void FormAchievementsCategoriesEdit::buttonChangeCategory_Clicked() {
    changeCategoryType(CategoryType::changeNotSelected);
}

void FormAchievementsCategoriesEdit::buttonDeleteAllCategories_Clicked() {
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

    _categoriesGame.deleteAll();
    emit s_categoriesIsUpdated(true);
}

FormCategoryValue_2 *FormAchievementsCategoriesEdit::createValueCategory() {
//    int rowValues = ui->ListWidgetValuesCategory->count();//->rowCount();
    FormCategoryValue_2 *newValue = new FormCategoryValue_2();
    connect(newValue, &FormCategoryValue_2::s_goFirst,              this,   &FormAchievementsCategoriesEdit::formCategoryValueFirst);
    connect(newValue, &FormCategoryValue_2::s_goBack,               this,   &FormAchievementsCategoriesEdit::formCategoryValueBack);
    connect(newValue, &FormCategoryValue_2::s_goNext,               this,   &FormAchievementsCategoriesEdit::formCategoryValueNext);
    connect(newValue, &FormCategoryValue_2::s_goLast,               this,   &FormAchievementsCategoriesEdit::formCategoryValueLast);
    connect(newValue, &FormCategoryValue_2::s_deleteValue,          this,   &FormAchievementsCategoriesEdit::formCategoryValueDelete);
    connect(newValue, &FormCategoryValue_2::s_deleteAchievement,    this,   &FormAchievementsCategoriesEdit::updateUniqueAchievements);
    _values.append(newValue);
    updateValuesOrder();
    newValue->setFixedWidth(newValue->sizeHint().width());
    ui->ScrollAreaValues->widget()->layout()->addWidget(newValue);
//    ui->ListWidgetValuesCategory->setCurrentRow(ui->ListWidgetValuesCategory->count() - 1);
    return newValue;
}

void FormAchievementsCategoriesEdit::updateUniqueAchievements() {

}

#define Categorys {
void FormAchievementsCategoriesEdit::buttonAddValueCategory_Clicked() {
    createValueCategory();
}

void FormAchievementsCategoriesEdit::buttonCancelCategory_Clicked() {
    while(!_values.isEmpty()) {
        delete _values.takeFirst();
    }
    changeCategoryType(CategoryType::none);
}

void FormAchievementsCategoriesEdit::createCategoryNoValue(int aCategoryIndex, const QString &aTitle) {
    QList<QString> resultNoValues;
    if (_values.size() > 0) {
        auto achievements = _values[0]->getAchievements();
        for (const auto &achievement: achievements) {
            resultNoValues.append(achievement);
        }
    } else {
        qWarning() << "on save noValue category value is not created";
    }
    _categoriesGame.changeCategory(aCategoryIndex, aTitle, 1, QList<CategoryValue>(), resultNoValues);
}

bool FormAchievementsCategoriesEdit::createCategoryValue(int aCategoryIndex, const QString &aTitle) {
    auto end = _values.end();
    for(auto valueIsEmpty = _values.begin(); valueIsEmpty < end; ++valueIsEmpty) {
        if ((*valueIsEmpty)->getTitle() == "") {
            QMessageBox::warning(this, tr("Ошибка"), tr("Название значения пустое!"));
            return false;
        }
        for(auto valueIsDoublicate = valueIsEmpty + 1; valueIsDoublicate < end; ++valueIsDoublicate) {
            if ((*valueIsEmpty)->getTitle() == (*valueIsDoublicate)->getTitle()) {
                QMessageBox::warning(this, tr("Ошибка"), tr("Название значения повторяется!"));
                return false;
            }
        }
    }
    QList<CategoryValue> resultValues;
    for (const auto &value: _values) {
        CategoryValue categoryValue;
        categoryValue.title = value->getTitle();
        auto achievements = value->getAchievements();
        for (const auto &achievement: achievements) {
            categoryValue.achievements.append(achievement);
        }
        resultValues.append(categoryValue);
    }
    _categoriesGame.changeCategory(aCategoryIndex, aTitle, 0, resultValues, QList<QString>());
    return true;
}

void FormAchievementsCategoriesEdit::buttonAcceptCategory_Clicked() {
    if (_typeCategory != CategoryType::add && _typeCategory != CategoryType::changeSelected) {
        qWarning() << "on save category unknown type";
        return;
    }

    QString newTitle = ui->LineEditTitleCategory->text();
    if (newTitle == "") {
        QMessageBox::warning(this, tr("Ошибка"), tr("Название категории пустое!"));
        return;
    }
    int targetCategory = _typeCategory == CategoryType::changeSelected ?
                        ui->ComboBoxCategories->currentIndex() - 1 :
                        _categoriesGame.getCount();

    bool isAlreadyExist = std::any_of(_categoriesGame.begin(),
                                      _categoriesGame.end(),
                                      [=](CategoryGame sCategory) {
                                          return ((sCategory.getTitle() == newTitle)
                                          && (sCategory.getIndex() != targetCategory));
                                      });
    if (isAlreadyExist) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Такая категория уже есть!"));
        return;
    }

    if (_isNoValue) {
        createCategoryNoValue(targetCategory, newTitle);
    } else {
        if (!createCategoryValue(targetCategory, newTitle)) {
            return;
        }
    }

    emit s_categoriesIsUpdated(true);
    switch (_typeCategory) {
    case CategoryType::add: {
        QMessageBox::information(this, tr("Успешно"), tr("Категория была добавлена!"));
        break;
    }
    case CategoryType::changeSelected: {
        QMessageBox::information(this, tr("Успешно"), tr("Категория была изменена!"));
        break;
    }
    default: {
        qWarning() << "save category with unknown type";
    }
    }
    buttonCancelCategory_Clicked();
}

void FormAchievementsCategoriesEdit::buttonDeleteCategory_Clicked() {
    if (_typeCategory != CategoryType::changeSelected) {
        return;
    }
    if (ui->ComboBoxCategories->currentIndex() == 0) {
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
    _categoriesGame.deleteCategory(ui->ComboBoxCategories->currentIndex() - 1);
    emit s_categoriesIsUpdated(true);
    QMessageBox::information(this, tr("Успешно"), tr("Категория была удалена!"));
    buttonCancelCategory_Clicked();
}

void FormAchievementsCategoriesEdit::checkBoxCategoryOneValue_StateChanged(int arg1) {
    if (_typeCategory != CategoryType::add &&
        _typeCategory != CategoryType::changeSelected) {
        return;
    }
    ui->ButtonAddValueCategory->setEnabled(arg1 == 0);
    //ui->ListWidgetValuesCategory->setEnabled(!value);
    //_tableAchievements->setValuesMode(!value);
}

void FormAchievementsCategoriesEdit::lineEditTitleCategory_TextChanged(const QString &arg1) {
//    if (_tableAchievements->getColumnCount() > c_tableCategoryColumnNoValue) {
//        _tableAchievements->changeHorizontalTitle(c_tableCategoryColumnNoValue, arg1);
//    }
}

void FormAchievementsCategoriesEdit::comboBoxCategories_Activated(int aIndex) {
    if (_typeCategory != CategoryType::changeNotSelected &&
        _typeCategory != CategoryType::changeSelected) {
        return;
    }
    if (_categoriesGame.getCount() <= 0) {
        return;
    }
    ui->LineEditTitleCategory->setText(ui->ComboBoxCategories->itemText(aIndex));
    if (aIndex > 0) {
        changeCategoryType(CategoryType::changeSelected);
//        ui->CheckBoxCategoryOneValue->setChecked(_categoriesGame[aIndex - 1].getIsNoValue());

        QList<QString> noValues = _categoriesGame[aIndex - 1].getNoValues();
        QList<CategoryValue> valuesTitles = _categoriesGame[aIndex - 1].getValues();
//      _tableAchievements->categoryToTable(_categoriesGame[aIndex - 1].getTitle(), noValues, valuesTitles, _categoriesGame[aIndex - 1].getIsNoValue());

        while(!_values.isEmpty()) {
            _values.removeAt(0);
        }
        for(auto &&title: valuesTitles) {
            FormCategoryValue_2 *value = createValueCategory();
            value->setTitle(title.title);
        }
    } else {
        changeCategoryType(CategoryType::changeNotSelected);
    }
}

#define CategorysValues {
void FormAchievementsCategoriesEdit::updateValuesOrder() {
//    ui->ButtonCategoryValueTop->setEnabled(false);
//    ui->ButtonCategoryValueUp->setEnabled(false);
//    ui->ButtonCategoryValueDown->setEnabled(false);
//    ui->ButtonCategoryValueBottom->setEnabled(false);
}

void FormAchievementsCategoriesEdit::formCategoryValueReverse() {
//    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
//    int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

////    _tableAchievements->reverseCategoryColumn(currentIndex);
}

void FormAchievementsCategoriesEdit::formCategoryValueFirst() {
//    if (ui->ListWidgetValuesCategory->count() > 0) {
//        int currentIndex = ui->ListWidgetValuesCategory->currentRow();
//        if(currentIndex == 0) {
//            return;
//        } else {
////            if (_tableAchievements->swapCategoryColumns(currentIndex, 0)) {
//                QWidget *widget = ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(currentIndex));
////TODO Сделать нормальное перемещение
//                //widget->setParent(nullptr);
//                ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(currentIndex), ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(0)));
//                ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(currentIndex), widget);
////                ui->ListWidgetValuesCategory->removeItemWidget(ui->ListWidgetValuesCategory->item(currentIndex));
////                QWidget *widget2 = ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(0));
////                ui->ListWidgetValuesCategory->removeItemWidget(ui->ListWidgetValuesCategory->item(0));
////                ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(0), widget1);
////                ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(currentIndex), widget2);
//                //ui->ListWidgetValuesCategory->removeItemWidget(ui->ListWidgetValuesCategory->item(currentIndex));
//                //QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->takeItem(currentIndex);
//                //ui->ListWidgetValuesCategory->insertItem(0, currentItem);
//                //ui->ListWidgetValuesCategory->setItemWidget(currentItem, widget);
//                ui->ListWidgetValuesCategory->setCurrentRow(0);

//                FormCategoryValue *value = dynamic_cast<FormCategoryValue*>(ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(currentIndex)));
//                if (value) {
//                    value->setPosition(0);
//                }
////            }
//        }
//    }
}

void FormAchievementsCategoriesEdit::formCategoryValueBack() {
//    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
//    int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

//    if(currentIndex == 0) {
//        QMessageBox::warning(this, tr("Ошибка!"), tr("Невозможно переместить значение"));
//    } else {
//        QListWidgetItem *prev = ui->ListWidgetValuesCategory->item(ui->ListWidgetValuesCategory->row(currentItem) - 1);
//        int prevIndex = ui->ListWidgetValuesCategory->row(prev);

//        QListWidgetItem *temp = ui->ListWidgetValuesCategory->takeItem(prevIndex);
//        ui->ListWidgetValuesCategory->insertItem(prevIndex, currentItem);
//        ui->ListWidgetValuesCategory->insertItem(currentIndex, temp);
//        ui->ListWidgetValuesCategory->setCurrentRow(currentIndex - 1);

//        FormCategoryValue *value = dynamic_cast<FormCategoryValue*>(ui->ListWidgetValuesCategory->itemWidget(currentItem));
//        if (value) {
//            value->setPosition(currentIndex - 1);
//        }
//    }
}

void FormAchievementsCategoriesEdit::formCategoryValueNext() {
//    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
//    int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

//    if(currentIndex >= ui->ListWidgetValuesCategory->count() - 1) {
//        QMessageBox::warning(this, tr("Ошибка!"), tr("Невозможно переместить значение"));
//    } else {
//        QListWidgetItem *next = ui->ListWidgetValuesCategory->item(ui->ListWidgetValuesCategory->row(currentItem) + 1);
//        int nextIndex = ui->ListWidgetValuesCategory->row(next);

//        QListWidgetItem *temp = ui->ListWidgetValuesCategory->takeItem(nextIndex);
//        ui->ListWidgetValuesCategory->insertItem(currentIndex, temp);
//        ui->ListWidgetValuesCategory->insertItem(nextIndex, currentItem);
//        ui->ListWidgetValuesCategory->setCurrentRow(currentIndex + 1);

//        FormCategoryValue *value = dynamic_cast<FormCategoryValue*>(ui->ListWidgetValuesCategory->itemWidget(currentItem));
//        if (value) {
//            value->setPosition(currentIndex + 1);
//        }
//    }
}

void FormAchievementsCategoriesEdit::formCategoryValueLast() {
//    if (ui->ListWidgetValuesCategory->count() > 0) {
//        int currentIndex = ui->ListWidgetValuesCategory->currentRow();
//        if(currentIndex == ui->ListWidgetValuesCategory->count() - 1) {
//            return;
//        } else {
//            QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->takeItem(currentIndex);
//            ui->ListWidgetValuesCategory->insertItem(ui->ListWidgetValuesCategory->count(), currentItem);
//            ui->ListWidgetValuesCategory->setCurrentRow(ui->ListWidgetValuesCategory->count() - 1);

//            FormCategoryValue *value = dynamic_cast<FormCategoryValue*>(ui->ListWidgetValuesCategory->itemWidget(currentItem));
//            if (value) {
//                value->setPosition(ui->ListWidgetValuesCategory->count() - 1);
//            }
//        }
//    }
}

void FormAchievementsCategoriesEdit::formCategoryValueSelectVisible() {
//    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
//    int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

//    _tableAchievements->setVisibleContentSelect(currentIndex, true);
}

void FormAchievementsCategoriesEdit::formCategoryValueUnselectVisible() {
//    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
//    int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

//    _tableAchievements->setVisibleContentSelect(currentIndex, false);
}

void FormAchievementsCategoriesEdit::formCategoryValueDelete() {
//    if (ui->ListWidgetValuesCategory->count() > 0) {
//        QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
//        int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);
////        _tableAchievements->removeCategoryColumn(currentIndex);

//        if (ui->ListWidgetValuesCategory->count() == 1) {
//            if (QListWidgetItem *item = ui->ListWidgetValuesCategory->takeItem(currentIndex)) {
//                delete item;
//            }
//            noSelectedValue();
//        } else {
//            if (currentIndex == 0) {
//                if (QListWidgetItem *item = ui->ListWidgetValuesCategory->takeItem(currentIndex)) {
//                    delete item;
//                }
//                ui->ListWidgetValuesCategory->setCurrentRow(0);
//            } else {
//                if (QListWidgetItem *item = ui->ListWidgetValuesCategory->takeItem(currentIndex)) {
//                    delete item;
//                }
//                ui->ListWidgetValuesCategory->setCurrentRow(currentIndex - 1);
//            }
//        }
//    }
//    updateValueUpDown();
}

void FormAchievementsCategoriesEdit::formCategoryDelete(int aPos) {
////    _tableAchievements->removeCategoryColumn(aPos);
//    QListWidgetItem* item = ui->ListWidgetValuesCategory->item(aPos);
//    ui->ListWidgetValuesCategory->removeItemWidget(item);
//    delete item;
//    _values.removeAt(aPos);
//    int pos = 0;
//    for (auto &value: _values) {
//        value->setPosition(pos);
//        if (_values.size() == 1) {
//            value->setEnabledUpDown(EnabledUpDown::none);
//        } else if(_values.size() - 1 == pos) {
//            value->setEnabledUpDown(EnabledUpDown::up);
//        } else if(pos == 0) {
//            value->setEnabledUpDown(EnabledUpDown::down);
//        } else {
//            value->setEnabledUpDown(EnabledUpDown::both);
//        }
//        ++pos;
//    }
}
#define CategoryValuesEnd }
#define CategoryEnd }

void FormAchievementsCategoriesEdit::setUniqueMode(bool aIsUnique) {
    _isUnique = aIsUnique;
//        _tableAchievements->setUniqueMode(checkBoxState == 2);
}