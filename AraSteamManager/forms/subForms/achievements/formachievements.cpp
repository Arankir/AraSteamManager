#include "formachievements.h"
#include "ui_formachievements.h"

#define Constants {
constexpr QColor c_achievedColor      = QColor (87, 220, 87, 255 * 1);
constexpr QColor c_notAchievedColor   = QColor (255, 48, 48, 255 * 1);
#define ConstantsEnd }

#define Init {
FormAchievements::FormAchievements(QList<SAchievementPlayer> &aPlayer, SProfile &aProfile, SGame &aGame,
                                   QWidget *aParent): QWidget(aParent), ui(new Ui::FormAchievements),
                                   _player(aPlayer), _profile(aProfile), _game(aGame),
                                   _categoriesGame(_game), _comments(_profile.steamID()),
                                   _fCategories(0, _categoriesGame.countCategories()), _fAchievements(0, FilterAchievementsColumnCount) {
    ui->setupUi(this);
    initComponents();
    ui->LineEditNameAchievements->setFocus();
}

void FormAchievements::initComponents() {
    this->setAttribute(Qt::WA_TranslucentBackground);

    _global = SAchievementSchema::load(_game.sAppId());
    _percent = SAchievementPercentage::load(_game.sAppId());
    _achievements = UniteAchievement(_global, _percent, _player);

//    _achievements.set(SAchievementsPercentage(_game.sAppId())).set(SAchievementsGlobal(_game.sAppId())).update(false);

    initTableStandart();
    initCategoriesTree();

    ui->LabelGameOnlineValue->setText(QString::number(SGame::playerCount(_game.appId())));
    ui->TabWidget->setCurrentIndex(0);

    setIcons();
    #define Connects {
    connect(ui->ButtonUpdate,               &QPushButton::clicked,                      this,   &FormAchievements::buttonUpdate_Clicked);
    connect(ui->CheckBoxFavorites,          &QCheckBox::stateChanged,                   this,   &FormAchievements::checkBoxFavorites_StateChanged);
    connect(ui->ButtonGuides,               &QPushButton::clicked,                      this,   &FormAchievements::buttonManual_Clicked);
    connect(ui->TabWidget,                  &QTabWidget::currentChanged,                this,   &FormAchievements::tabWidget_CurrentChanged);
    connect(ui->FilterMyProfile,            &FormReachedFilter::s_radioButtonChange,    this,   &FormAchievements::updateFilterWithMyProfile);
    connect(ui->LineEditNameAchievements,   &QLineEdit::textChanged,                    this,   &FormAchievements::updateFilterTextAchievement);
    connect(ui->ButtonFindAchievement,      &QPushButton::clicked,                      this,   [=]() {
                                                                                                    ui->LineEditNameAchievements->setText(ui->LineEditNameAchievements->text());
                                                                                                });
    #define ConnectsEnd }
    createThread();
}

void FormAchievements::initTableStandart() {
    ui->TableViewMyAchievements->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
    ui->TableViewMyAchievements->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

    ui->TableViewMyAchievements->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TableViewMyAchievements->setShowGrid(false);
    ui->TableViewMyAchievements->setSortingEnabled(true);
    ui->TableViewMyAchievements->horizontalHeader()->setStretchLastSection(true);
    ui->TableViewMyAchievements->verticalHeader()->setVisible(false);
    ui->TableViewMyAchievements->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->TableViewMyAchievements->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->TableViewMyAchievements, &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
        updateCurrentAchievement();
        if (_currentAchievement != nullptr) {
            QMenu *menu = createMenu(*_currentAchievement);
            menu->popup(ui->TableViewMyAchievements->viewport()->mapToGlobal(pos));
        }
    });

    connect(ui->TableViewMyAchievements, &QTableView::doubleClicked, this, [=](QModelIndex aIndex) {
        updateCurrentAchievement();
        if (aIndex.column() == ColumnAchievementsComment) {
            buttonComment_Clicked();
        } else {
//            buttonAchievements_Clicked();
        }
    });
}

void FormAchievements::initCategoriesTree() {
    ui->TreeWidgetCategories->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->TreeWidgetCategories, &QTreeWidget::customContextMenuRequested, this, [=](QPoint pos) {
        updateCurrentCategory();
        QMenu *menu = createMenuCategory(*_currentCategory);
        menu->popup(ui->TreeWidgetCategories->viewport()->mapToGlobal(pos));
    });

}

void FormAchievements::initComments() {
    _comments.load();
    for(const auto &achievement: _achievements) {
        QStringList comment = _comments.getAchievementComment(_profile.steamID(), _game.sAppId(), achievement.apiName()).comment();
        QVariant icon;
        QModelIndex index = ui->TableViewMyAchievements->model()->index(rowFromId(achievement.apiName()), ColumnAchievementsComment);

        if ((comment != QStringList()) && (comment != QStringList() << "")) {
            icon = QVariant(QPixmap(Images::isComment()).scaled(32, 32));
            ui->TableViewMyAchievements->model()->setData(index, comment, Qt::ToolTipRole);
            ui->TableViewMyAchievements->model()->setData(index, "1", Qt::ForegroundRole);
        } else {
            icon = QVariant(QPixmap(Images::isNotComment()).scaled(32, 32));
            ui->TableViewMyAchievements->model()->setData(index, "0", Qt::ForegroundRole);
        }
        ui->TableViewMyAchievements->model()->setData(index, icon, Qt::DecorationRole);
    }
}

void FormAchievements::createThread() {
    Threading *loadTable = new Threading(this);
    ui->ProgressBarLoad->setMaximum(_achievements.count());
    ui->ProgressBarLoad->setValue(0);
    loading(true);
    createDir(Paths::imagesAchievements(_game.sAppId()));
    loadTable->AddThreadAchievements(c_achievedColor, c_notAchievedColor, _achievements, _game.appId());
    connect (loadTable, &Threading::s_achievements_progress,        this, &FormAchievements::progressLoading);
    connect (loadTable, &Threading::s_achievements_finished_model,  this, &FormAchievements::onModelPulled);
}

void FormAchievements::onModelPulled(QStandardItemModel *aModel, int reached, int notReached) {
    if (aModel != nullptr) {
        QStandardItem *name = new QStandardItem(_profile.personaName());
//        name->setFont(QFont(Settings::defaultFont()));
        aModel->setHorizontalHeaderItem(ColumnAchievementsReachedMy, name);

        QStandardItem *avatar = new QStandardItem();
        avatar->setData(QVariant(_profile.pixmapAvatar()), Qt::DecorationRole);
        avatar->setFlags(Qt::ItemFlag::ItemIsEnabled);
        aModel->setItem(0, ColumnAchievementsReachedMy, avatar);

        ui->TableViewMyAchievements->setModel(aModel);
        _fCategories.setRow(aModel->rowCount());
        _fAchievements.setRow(aModel->rowCount());
        initComments();
//TODO потом разрешить сортировку
        ui->TableViewMyAchievements->setSortingEnabled(false);
        ui->TableViewMyAchievements->setRowHidden(0, true);
        ui->TableViewMyAchievements->setColumnHidden(ColumnAchievementsAppid, true);
        ui->TableViewMyAchievements->setColumnHidden(ColumnAchievementsIndex, true);
        ui->TableViewMyAchievements->resizeColumnsToContents();
        ui->TableViewMyAchievements->setColumnWidth(ColumnAchievementsTitle, 220);
        ui->TableViewMyAchievements->setColumnWidth(ColumnAchievementsDescription, 450);
        ui->TableViewMyAchievements->resizeRowsToContents();

        aModel->setHeaderData(ColumnAchievementsIcon,           Qt::Horizontal, tr(""));
        aModel->setHeaderData(ColumnAchievementsTitle,          Qt::Horizontal, tr("Название"));
        aModel->setHeaderData(ColumnAchievementsDescription,    Qt::Horizontal, tr("Описание"));
        aModel->setHeaderData(ColumnAchievementsComment,        Qt::Horizontal, tr(""));
        aModel->setHeaderData(ColumnAchievementsWorld,          Qt::Horizontal, tr("По миру"));
        showCategories();
    }

    if ((reached > 0) || (notReached > 0)) {
        ui->LabelTotalPersent->setText(QString("%1/%2 (%3%)").arg(
                                       QString::number(reached),
                                       QString::number(reached + notReached),
                                       QString::number(100.0 * reached / (reached + notReached))));
        ui->FilterMyProfile->update();
    }
    loading(false);
    ui->LineEditNameAchievements->setFocus();
}

void FormAchievements::setIcons() {
    ui->ButtonFindAchievement   ->setIcon(QIcon(Images::find()));
    ui->ButtonUpdate            ->setIcon(QIcon(Images::update()));
    ui->ButtonGuides            ->setIcon(QIcon(Images::guide()));
}

QMenu *FormAchievements::createMenu(const SAchievement &aAchievement) {
    QString appId = aAchievement.apiName();

    //Добавление кнопки избранного
    QAction *actionFavorites;
    QList<FavoriteAchievement> favorites = Favorites::achievementsGame(_profile.steamID(), _game).achievements();
    bool isFavorite = std::any_of(favorites.cbegin(), favorites.cend(), [=](FavoriteAchievement curFavorite) {
                                                                            return curFavorite.apiName() == appId;
                                                                        });
    if(isFavorite) {
        actionFavorites = new QAction(tr("Удалить из избранного"), this);
        actionFavorites->setIcon(QIcon(Images::isFavorites()));
    } else {
        actionFavorites = new QAction(tr("Добавить в избранное"), this);
        actionFavorites->setIcon(QIcon(Images::isNotFavorites()));
    }

    //Добавление кнопки комментариев
    QAction *actionComment = new QAction(tr("Редактировать комментарий...     "), this);
    actionComment->setIcon(QIcon(Images::isComment()));

    //Добавление кнопки руководств
    QAction *actionGuides = new QAction(tr("Перейти в руководства"), this);
    actionGuides->setIcon(QIcon(Images::guide()));

    //Добавление кнопки обновления
    QAction *actionUpdate = new QAction(tr("Обновить"), this);
    actionUpdate->setIcon(QIcon(Images::update()));

    QMenu *menu = new QMenu(this);
    menu->addAction (actionFavorites);
    menu->addAction (actionComment);
    menu->addAction (actionGuides);
    menu->addAction (actionUpdate);

    connect (actionFavorites,   &QAction::triggered,    this,   &FormAchievements::buttonFavorite_Clicked);
    connect (actionComment,     &QAction::triggered,    this,   &FormAchievements::buttonComment_Clicked);
    connect (actionGuides,      &QAction::triggered,    this,   &FormAchievements::buttonManual_Clicked);
    connect (actionUpdate,      &QAction::triggered,    this,   &FormAchievements::buttonUpdate_Clicked);

    return menu;
}

QMenu *FormAchievements::createMenuCategory(const Category &aCategory) {
    Q_UNUSED(aCategory);
    //Кнопка изменения достижений
    QAction *actionAchievements = new QAction(tr("Изменить категорию"), this);
    actionAchievements->setIcon(QIcon(Images::change()));

    //Кнопка добавления подкатегории
    QAction *actionSubCategory = new QAction(tr("Добавить подкатегорию"), this);
    actionSubCategory->setIcon(QIcon(Images::create()));

    //Кнопка удаления категории
    QAction *actionDelete = new QAction(tr("Удалить категорию"), this);
    actionDelete->setIcon(QIcon(Images::deleteIcon()));

    QMenu *menu = new QMenu(this);
    menu->addAction (actionAchievements);
    menu->addAction (actionSubCategory);
    menu->addAction (actionDelete);

    connect (actionAchievements,    &QAction::triggered,    this,   &FormAchievements::categoryChange);
    connect (actionSubCategory,     &QAction::triggered,    this,   &FormAchievements::categoryAdd);
    connect (actionDelete,          &QAction::triggered,    this,   &FormAchievements::categoryDelete);

    return menu;
}
#define InitEnd }

void FormAchievements::updateFilterWithMyProfile(ReachedType aType) {
    switch (aType) {
    case ReachedType::all: {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            _fAchievements.setData(i, FilterAchievementsReached, true);
        }
        break;
    }
    case ReachedType::reached: {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            _fAchievements.setData(i, FilterAchievementsReached, ui->TableViewMyAchievements->model()->index(i + 1, ColumnAchievementsReachedMy).data().toString().indexOf(".") > -1);
        }
        break;
    }
    case ReachedType::notReached: {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            _fAchievements.setData(i, FilterAchievementsReached, ui->TableViewMyAchievements->model()->index(i + 1, ColumnAchievementsReachedMy).data().toString().indexOf(".") == -1);
        }
        break;
    }
    default: {
        break;
    }
    }
    updateHiddenRows();
}

void FormAchievements::updateFilterTextAchievement(const QString &aNewText) {
    for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
        bool findInTitle        = ui->TableViewMyAchievements->model()->index(i + 1, ColumnAchievementsTitle      ).data().toString().toLower().indexOf(aNewText.toLower()) > -1;
        bool findInDescription  = ui->TableViewMyAchievements->model()->index(i + 1, ColumnAchievementsDescription).data().toString().toLower().indexOf(aNewText.toLower()) > -1;
        _fAchievements.setData(i, FilterAchievementsName, (findInTitle || findInDescription));
    }
    updateHiddenRows();
}

#define System {
FormAchievements::~FormAchievements() {
    qInfo() << "Форма достижений удалилась";
    delete ui;
}

void FormAchievements::closeEvent(QCloseEvent *event) {
    event->accept();
}

void FormAchievements::changeEvent(QEvent *event) {
    if (event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormAchievements::loading(bool aIsLoading) {
    ui->FrameFilter->setEnabled(!aIsLoading);
    ui->TreeWidgetCategories->setEnabled(!aIsLoading);
    ui->ButtonUpdate->setEnabled(!aIsLoading);
    ui->TabWidget->setEnabled(!aIsLoading);
    ui->ProgressBarLoad->setVisible(aIsLoading);
}

void FormAchievements::retranslate() {
    ui->retranslateUi(this);
    buttonUpdate_Clicked();
}

void FormAchievements::updateHiddenRows() {
    if (ui->TableViewMyAchievements->model() != nullptr) {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            ui->TableViewMyAchievements->setRowHidden(i + 1, !_fAchievements.getData(i));
        }
    } else {
        qWarning() << "table achievements isn't init model";
    }
    emit s_updatedHiddenRows();
}

void FormAchievements::updateSettings() {
    Settings::syncronizeSettings();
    setIcons();
    emit s_updateSettings();
}

int FormAchievements::rowFromId(QString aId) {
    QStandardItemModel *model = dynamic_cast<QStandardItemModel *>(ui->TableViewMyAchievements->model());
    if (model) {
        QList<QStandardItem*> items = model->findItems(aId, Qt::MatchExactly, ColumnAchievementsAppid);
        if (items.count() == 1) {
            return items[0]->row();
        } else {
            qWarning() << "duplicates achievement" << aId << ", " << items.count() << " count";
        }
    } else {
        qWarning() << "error model cast";
    }
    return -1;
}

void FormAchievements::progressLoading(int aValue, int aMax) {
    ui->ProgressBarLoad->setMaximum(aMax);
    ui->ProgressBarLoad->setValue(aValue);
}

void FormAchievements::updateCurrentAchievement() {
    QModelIndex index = ui->TableViewMyAchievements->currentIndex();
    _currentAchievementIndex = ui->TableViewMyAchievements->model()->index(index.row(), ColumnAchievementsIndex).data().toString().toInt();
    QString appId = ui->TableViewMyAchievements->model()->index(index.row(), ColumnAchievementsAppid).data().toString();

    auto iterator = std::find_if(_achievements.begin(),
                                 _achievements.end(),
                                 [=](const SAchievement &achievement) {
                                     return achievement.apiName() == appId;
                                 });
    if (iterator != _achievements.end()) {
        _currentAchievement = &*iterator;
    }
}

QString FormAchievements::getText(QTreeWidgetItem *item) {
    QWidget *widget = ui->TreeWidgetCategories->itemWidget(item, 0);
    QCheckBox *checkBox = dynamic_cast<QCheckBox*>(widget);
    if (checkBox) {
        return checkBox->text();
    } else {
        QLabel *label = dynamic_cast<QLabel*>(widget);
        if (label) {
            return label->text();
        }
    }
    return QString();
}

void FormAchievements::updateCurrentCategory() {
    //_currentCategoryIndex
    auto currentItem = ui->TreeWidgetCategories->currentItem();
    if (currentItem == nullptr) {
        _currentCategory = nullptr;
        return;
    }
    QStringList names {getText(currentItem)};
    while (currentItem->parent() != nullptr) {
        currentItem = currentItem->parent();
        names << getText(currentItem);
    }
    _currentCategory = &_categoriesGame;
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

void FormAchievements::checkBoxCategory_StateChanged(int aIndex) {
    updateCurrentCategory();
    if (_currentCategory != nullptr) {
        switch (aIndex) {
        case 0: {
            updateFilterCategory(_currentCategory->order(), true);
            break;
        }
        case 2: {
            QList<QString> achievementsName = _currentCategory->achievementsApiName();
            updateFilterCategory(_currentCategory->order(), false, achievementsName);
            break;
        }
        }
    }
}

int FormAchievements::recursAddCategoryToTree(Category *aCategory, int aCount, QTreeWidgetItem *aRoot) {
    QTreeWidgetItem *subItem;
    if (aRoot == nullptr) {
        subItem = new QTreeWidgetItem(ui->TreeWidgetCategories);
    } else {
        subItem = new QTreeWidgetItem(aRoot);
    }
    QSize sizeHint;
    QWidget *widget;
    if (aCategory->achievementsApiName().isEmpty()) {
        widget = new QLabel(aCategory->title());
    } else {
        widget = new QCheckBox(aCategory->title());
        connect(dynamic_cast<QCheckBox*>(widget), &QCheckBox::stateChanged, this, &FormAchievements::checkBoxCategory_StateChanged);
    }
    widget->setAccessibleName(QString::number(aCount++));
    sizeHint = widget->sizeHint();
    sizeHint.rwidth() += 10;
    subItem->setSizeHint(0, sizeHint);
    ui->TreeWidgetCategories->setItemWidget(subItem, 0, widget);
    for(auto subCategory: *aCategory) {
        aCount = recursAddCategoryToTree(subCategory, aCount, subItem);
    }
    return aCount;
}

void FormAchievements::showCategories() {
    _categoriesGame.update();

    ui->TreeWidgetCategories->clear();
    int count = 0;
    for(auto &category: _categoriesGame) {
        count = recursAddCategoryToTree(category, count);
    }

    _fCategories.setCol(_categoriesGame.countCategories());
    _fAchievements.setCol(_categoriesGame.countCategories() + FilterAchievementsColumnCount);
    updateHiddenRows();
}
#define SystemEnd }

#define Filter {
void FormAchievements::buttonUpdate_Clicked() {
    _player = SAchievementPlayer::load(_game.sAppId(), _profile.steamID());
    _achievements = UniteAchievement(_global, _percent, _player);
//    _achievements.update(false);
    createThread();
}

void FormAchievements::updateFilterCategory(int aCategoryIndex, bool aClear, QList<QString> aAchievementNames) {
    if (aClear) {
        for (int i = 0; i < _fAchievements.getRow(); ++i) {
            _fAchievements.setData(i, FilterAchievementsEndConstValues + aCategoryIndex, true);
        }
    } else {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            _fAchievements.setData(i, FilterAchievementsEndConstValues + aCategoryIndex, false);
            auto text = ui->TableViewMyAchievements->model()->index(i + 1, ColumnAchievementsAppid).data().toString();
            bool isAchievementExist = std::any_of(aAchievementNames.begin(),
                                                  aAchievementNames.end(),
                                                  [=](QString &achievementName) {
                                                        return text == achievementName;
                                                    });
            if (isAchievementExist) {
                _fAchievements.setData(i, FilterAchievementsEndConstValues + aCategoryIndex, true);
            }
        }
    }
    updateHiddenRows();
}
#define FilterEnd }

#define Function {

void FormAchievements::updateFilterFavorite(const QList<FavoriteAchievement> &aFavorites) {
    if (aFavorites.count() == 0) {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            _fAchievements.setData(i, FilterAchievementsFavorite, true);
        }
    } else {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            QString apiName = _achievements[i].apiName();
            bool accept = std::any_of(aFavorites.begin(), aFavorites.end(), [=](const FavoriteAchievement &achievement) {
                                                                                return (achievement.apiName() == apiName);
                                                                            });
            _fAchievements.setData(i, FilterAchievementsFavorite, accept);
        }
    }
    updateHiddenRows();
}

void FormAchievements::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        updateFilterFavorite(QList<FavoriteAchievement>());
        break;
    }
    case 2: {
        updateFilterFavorite(_favorites.achievementsGame(_profile.steamID(), _game).achievements());
        break;
    }
    }
}

void FormAchievements::buttonFavorite_Clicked() {
    if (_currentAchievementIndex > -1) {
        if (_favorites.addAchievement(_profile.steamID(), _game,  *_currentAchievement, true)) {
            //Категория добавилась
            //ui->ButtonFavorite->setIcon(QIcon(Images::isFavorites()));
        } else {
            //Категория уже есть (удалилась)
            //ui->ButtonFavorite->setIcon(QIcon(Images::isNotFavorites()));
        }
    }
}
#define FunctionEnd }

void FormAchievements::buttonManual_Clicked() {
    QDesktopServices::openUrl(QUrl("https://steamcommunity.com/app/" + QString::number(_game.appId()) + "/guides/"));
    //https://steamcommunity.com/app/218620/guides/
}

void FormAchievements::updateHiddenColumnsStandart() {
    for (int i = ColumnAchievementsCount; i < ui->TableViewMyAchievements->model()->columnCount(); ++i) {
        ui->TableViewMyAchievements->setColumnHidden(i, true);
    }
}

void FormAchievements::tabWidget_CurrentChanged(int index) {
    switch(index) {
    case TabAchievementsStandart: {
        updateHiddenColumnsStandart();
        break;
    }
    case TabAchievementsCategories: {
        if (!_isEditCategoryLoaded) {
            loadEditCategory();
        }
        break;
    }
    case TabAchievementsCompare: {
        if (!_isCompareLoaded) {
            loadCompare();
        }
        break;
    }
    }
}

void FormAchievements::loadEditCategory() {
    ui->CategoriesEdit->setGame(_game);
    ui->CategoriesEdit->setAchievements(_achievements);
    ui->CategoriesEdit->setFilter(&_fAchievements);
    connect(this, &FormAchievements::s_updatedHiddenRows, ui->CategoriesEdit, &FormCategoriesEdit::updateHiddenItems);
    connect(ui->CategoriesEdit, &FormCategoriesEdit::s_categoriesIsUpdated, this, [=](bool isUpdated) {
        if (isUpdated) {
            showCategories();
        }
    });
    _isEditCategoryLoaded = true;
}

void FormAchievements::loadCompare() {
    if (ui->TableViewMyAchievements->model()) {
        ui->ProgressBarLoad->setMaximum(0);
        ui->ProgressBarLoad->setValue(0);
        loading(true);
        ui->FriendsCompare->setAchievedColors(c_achievedColor, c_notAchievedColor);
        ui->FriendsCompare->setInitData(_profile, _game, _achievements, static_cast<QStandardItemModel*>(ui->TableViewMyAchievements->model()), &_fAchievements);
        connect(this, &FormAchievements::s_updatedHiddenRows, ui->FriendsCompare, &FormFriendsCompare::updateHiddenRows);
        connect(ui->FriendsCompare, &FormFriendsCompare::s_progressLoad,    this,   &FormAchievements::progressLoading);
        connect(ui->FriendsCompare, &FormFriendsCompare::s_addedFriend,     this,   &FormAchievements::updateHiddenColumnsStandart);
        connect(ui->FriendsCompare, &FormFriendsCompare::s_finishLoad,      this,   [=](){
                                                                                        loading(false);
                                                                                    });
        _isCompareLoaded = true;
    }
}

void FormAchievements::categoryChange() {
    ui->TabWidget->setCurrentIndex(TabAchievementsCategories);
//    updateCurrentCategory();
    ui->CategoriesEdit->changeCategory(_currentCategory);
}

void FormAchievements::categoryAdd() {
    ui->TabWidget->setCurrentIndex(TabAchievementsCategories);
//    updateCurrentCategory();
    ui->CategoriesEdit->addSubCategory(_currentCategory);
}

void FormAchievements::categoryDelete() {
    ui->TabWidget->setCurrentIndex(TabAchievementsCategories);
//    updateCurrentCategory();
    ui->CategoriesEdit->deleteCategory(_currentCategory);
}

void FormAchievements::buttonComment_Clicked() {
    FramelessWindow *f = new FramelessWindow;
    FormComments *ci = new FormComments(_profile, _game, _currentAchievement, f);
    f->setWidget(ci);
    connect(ci, &FormComments::s_updateComments, this, [=](bool isUpdate) {
        if (isUpdate) {
            initComments();
        }
    });
    f->show();
}
