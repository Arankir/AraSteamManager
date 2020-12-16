#include "formachievements.h"
#include "ui_formachievements.h"
#define Constants {
constexpr int c_columnAppid             = 0;
constexpr int c_columnIndex             = 1;
constexpr int c_columnIcon              = 2;
constexpr int c_columnTitle             = 3;
constexpr int c_columnDescription       = 4;
constexpr int c_columnComment           = 5;
constexpr int c_columnWorld             = 6;
constexpr int c_columnReachedMy         = 7;
constexpr int c_columnCount             = 8;

constexpr int c_tableFriendsRowAvatars  = 0;
constexpr int c_tableFriendsRowCheckBox = 1;
constexpr int c_tableFriendsRowFilters  = 2;
constexpr int c_tableFriendsRowID       = 3;
constexpr int c_tableFriendsRowCount    = 4;

constexpr int c_filterName              = 0;
constexpr int c_filterReached           = 1;
constexpr int c_filterFavorite          = 2;
constexpr int c_filterColumnCount       = 3;
constexpr int c_filterEndConstValues    = 3;

constexpr int c_tabStandartAchievements = 0;
constexpr int c_tabCategories           = 1;
constexpr int c_tabCompareAchievements  = 2;
#define ConstantsEnd }

#define Init {
FormAchievements::FormAchievements(SAchievementsPlayer &aPlayer, SProfile &aProfile, SGame &aGame,
                                   QWidget *aParent): QWidget(aParent), ui(new Ui::FormAchievements),
                                   _achievements(aPlayer), _profile(aProfile), _game(aGame),
                                   _categoriesGame(_game), _comments(_profile._steamID) {
    ui->setupUi(this);
    initComponents();
    ui->LineEditNameAchievements->setFocus();
}

void FormAchievements::initComponents() {
    #define LoadData {
    this->setAttribute(Qt::WA_TranslucentBackground);

    //Временно
    _achievements.set(SAchievementsPercentage(_game.sAppId())).set(SAchievementsGlobal(_game.sAppId())).update(false);

    _fCategories.setCol(_categoriesGame.countAll());
    _fAchievements.setCol(c_filterColumnCount);
    _fCompare.setCol(c_filterColumnCount);
    //FormCompareFriends *Compare = new FormCompareFriends(ui->FrameCompare);

    ui->TreeWidgetCategories->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->TreeWidgetCategories, &QTreeWidget::customContextMenuRequested, this, [=](QPoint pos) {
        updateCurrentCategory();
        QMenu *menu = createMenuCategory(*_currentCategory);
        menu->popup(ui->TreeWidgetCategories->viewport()->mapToGlobal(pos));
    });


//    QLabel *allFriends = new QLabel("All", this);
//    allFriends->setToolTip(tr("Достижения друзей"));
//    allFriends->setScaledContents(true);
//    allFriends->setFixedSize(32, 32);

//    QLabel *avatarFriendsCompare = new QLabel(this);
//    avatarFriendsCompare->setAlignment(Qt::AlignCenter);
//    avatarFriendsCompare->setToolTip(_profile._personaName);
//    avatarFriendsCompare->setPixmap(_profile.getPixmapAvatar());

    createDir(Paths::imagesAchievements(QString::number(_game.appId()), ""));
    ui->ProgressBarLoad->setVisible(false);
    ui->LabelGameOnlineValue->setText(_game.getNumberPlayers(false));
    ui->FrameFilter->setEnabled(false);
    ui->tabWidget->setCurrentIndex(0);
    #define LoadDataEnd }

    initTableStandart();
    initTableCompare();

//    #define ConnectTables {
////    _tableAchievements = new FormTablesHeaders(_game, _profile._steamID, aPlayer);
////    connect(_tableAchievements, &FormTablesHeaders::s_tablePulled, this, &FormAchievements::onTablePulled);
////    _tableAchievements->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
//    #define ConnectTablesEnd }
//    #define SetTableWidgetCompareFriendsSettings {
//    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->TableWidgetFriends->setMinimumSize(0, 210);
//    ui->TableWidgetFriends->setColumnCount(2);
//    ui->TableWidgetFriends->setRowCount(c_tableFriendsRowCount);
//    ui->TableWidgetFriends->setRowHidden(c_tableFriendsRowID, true);
//    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars, 0, avatarFriendsCompare);
//    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars, 1, allFriends);

//    FormCompareProfileFilter *myFilter = new FormCompareProfileFilter(this);
//    myFilter->setObjectName("FormCompareProfileFilterMy");
//    connect(myFilter, &FormCompareProfileFilter::s_radioButtonChange, this, [=](QString, ReachedType aType) {
//        updateFilterWithMyProfile(aType, false, true);
//    });

//    QWidget *widgetFriendsAchievementsFilter = new QWidget(this);
//    QHBoxLayout *lFriendsAchievementsFilter = new QHBoxLayout(widgetFriendsAchievementsFilter);
//    lFriendsAchievementsFilter->setMargin(1);
//    lFriendsAchievementsFilter->setAlignment(Qt::AlignCenter);
//    lFriendsAchievementsFilter->addWidget(createButtonWithData("PBFriendsAll",        "Friends", "All",        true));
//    lFriendsAchievementsFilter->addWidget(createButtonWithData("PBFriendsReached",    "Friends", "Reached",    false));
//    lFriendsAchievementsFilter->addWidget(createButtonWithData("PBFriendsNotReached", "Friends", "NotReached", false));
//    //widgetFriendsAchievementsFilter->setLayout(layoutFriendsAchievementsFilter);

//    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, 0, myFilter);
//    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, 1, widgetFriendsAchievementsFilter);
//    ui->TableWidgetFriends->resizeRowsToContents();
//    for (int i = 0; i < ui->TableWidgetFriends->rowCount(); ++i) {
//        ui->TableWidgetFriends->setRowHeight(i, ui->TableWidgetFriends->rowHeight(i) + 18);
//    }
//    ui->TableWidgetFriends->setRowHeight(c_tableFriendsRowCheckBox, 30);
//    ui->TableWidgetFriends->resizeColumnsToContents();
//    #define SetTableWidgetCompareFriendsSettingsEnd }
    setIcons();
    #define Connects {
    connect(ui->ButtonUpdate,               &QPushButton::clicked,          this,                   &FormAchievements::buttonUpdate_Clicked);
    connect(ui->CheckBoxCompareAllFriends,  &QCheckBox::stateChanged,       this,                   &FormAchievements::checkBoxCompareAllFriends_StateChanged);
    connect(ui->CheckBoxFavorites,          &QCheckBox::stateChanged,       this,                   &FormAchievements::checkBoxFavorites_StateChanged);
    connect(ui->ButtonGuides,               &QPushButton::clicked,          this,                   &FormAchievements::buttonManual_Clicked);
    connect(ui->tabWidget,                  &QTabWidget::currentChanged,    this,                   &FormAchievements::tabWidget_CurrentChanged);
    connect(ui->LineEditNameAchievements,   &QLineEdit::textChanged,        this,                   [=](const QString &newText) {
                                                                                                        updateFilterTextAchievement(newText, true, true);
                                                                                                    });
    connect(ui->ButtonFindAchievement,      &QPushButton::clicked,          this,                   [=]() {
                                                                                                        ui->LineEditNameAchievements->setText(ui->LineEditNameAchievements->text());
                                                                                                    });
    connect(ui->FilterMyProfile,            &FormCompareProfileFilter::s_radioButtonChange, this,   [=](QString, ReachedType aType) {
                                                                                                        updateFilterWithMyProfile(aType, true, false);
                                                                                                    });
//    connect(ui->CheckBoxCompareIcon,            &QCheckBox::stateChanged,       ui->TableViewCompare,   [=](int arg1) {
//        ui->TableViewCompare->setColumnHidden(c_columnIcon, arg1 == 0);
//    });
//    connect(ui->CheckBoxCompareTitle,           &QCheckBox::stateChanged,       ui->TableViewCompare,   [=](int arg1) {
//        ui->TableViewCompare->setColumnHidden(c_columnTitle, arg1 == 0);
//    });
//    connect(ui->CheckBoxCompareDescription,     &QCheckBox::stateChanged,       ui->TableViewCompare,   [=](int arg1) {
//        ui->TableViewCompare->setColumnHidden(c_columnDescription, arg1 == 0);
//    });
//    connect(ui->CheckBoxCompareTotalPercent,    &QCheckBox::stateChanged,       ui->TableViewCompare,   [=](int arg1) {
//        ui->TableViewCompare->setColumnHidden(c_columnWorld, arg1 == 0);
//    });
    #define ConnectsEnd }
//    setFormMode(FormMode::standart);
    createThread();
    retranslate();
}

void FormAchievements::retranslate() {
    ui->retranslateUi(this);
//    ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars, 1)->setToolTip(tr("Достижения друзей"));
    if (ui->TableViewMyAchievements->model() != nullptr) {
        ui->TableViewMyAchievements->model()->setHeaderData(c_columnIcon,           Qt::Horizontal, tr(""));
        ui->TableViewMyAchievements->model()->setHeaderData(c_columnTitle,          Qt::Horizontal, tr("Название"));
        ui->TableViewMyAchievements->model()->setHeaderData(c_columnDescription,    Qt::Horizontal, tr("Описание"));
        ui->TableViewMyAchievements->model()->setHeaderData(c_columnComment,        Qt::Horizontal, tr(""));
        ui->TableViewMyAchievements->model()->setHeaderData(c_columnWorld,          Qt::Horizontal, tr("По миру"));
    }
}

void FormAchievements::updateHiddenRows(bool aStandart, bool aCompare) {
    if (aStandart) {
        if (_isEditCategoryLoaded) {
            ui->CategoriesEdit->updateFilter(_fAchievements);
        }
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            ui->TableViewMyAchievements->setRowHidden(i + 1, !_fAchievements.getData(i));
        }
    }
    if (aCompare) {
        for (int i = 0; i < ui->TableViewCompare->model()->rowCount() - 1; ++i) {
            ui->TableViewCompare->setRowHidden(i + 1, !_fCompare.getData(i));
        }
    }
}

void FormAchievements::updateSettings() {
    Settings::syncronizeSettings();
    setIcons();
    emit s_updateSettings();
}

void FormAchievements::setIcons() {
    ui->ButtonFindAchievement   ->setIcon(QIcon(Images::find()));
    ui->ButtonUpdate            ->setIcon(QIcon(Images::update()));
    ui->ButtonGuides            ->setIcon(QIcon(Images::guide()));

//    QLabel *friendsIcon = dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars, 1));
//    if (friendsIcon) {
//        friendsIcon->setPixmap(QPixmap(Images::friends()));
//    }
//    QWidget *wFriendsFilter = dynamic_cast<QWidget*>(ui->TableWidgetFriends->cellWidget(c_tableFriendsRowFilters, 1));
//    if (wFriendsFilter) {
//        QButtonWithData *bFriendsAll = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(0)->widget());
//        if (bFriendsAll) {
//            bFriendsAll->setIcon(QIcon(Images::allAchievements()));
//        } else {
//            qWarning() << "not init bFriendsAll";
//        }
//        QButtonWithData *bFriendsReached = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(1)->widget());
//        if (bFriendsReached) {
//            bFriendsReached->setIcon(QIcon(Images::reached()));
//        } else {
//            qWarning() << "not init bFriendsReached";
//        }
//        QButtonWithData *bFriendsNotReached = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(2)->widget());
//        if (bFriendsNotReached) {
//            bFriendsNotReached->setIcon(QIcon(Images::notReached()));
//        } else {
//            qWarning() << "not init bFriendsNotReached";
//        }
//    } else {
//        qWarning() << "not init wFriendsFilter";
//    }
}

QButtonWithData *FormAchievements::createButtonWithData(const QString &aObjectName, const QString &aAppertain, const QString &aType, bool aChecked) {
//    QButtonWithData *button = new QButtonWithData("", this);
//    button->setObjectName(aObjectName);
//    button->addData("Appertain", aAppertain);
//    button->addData("Type", aType);
//    button->setChecked(aChecked);
//    connect(button, &QPushButton::clicked, this, &FormAchievements::buttonCompareAllFriendsReach_Clicked);
//    return button;
}

void FormAchievements::progressLoading(int aProgress, int aRow) {
    Q_UNUSED(aProgress);
    Q_UNUSED(aRow);
    //qDebug()<<"Loading..."<<a_progress;
}

void FormAchievements::onTablePulled(int reached, int notReached) {
    ui->ProgressBarLoad->setVisible(false);
    if ((reached > 0) || (notReached > 0)) {
        ui->FrameFilter->setEnabled(true);
        ui->LabelTotalPersent->setText(QString("%1/%2 (%3%)").arg(
                                           QString::number(reached),
                                           QString::number(reached + notReached),
                                           QString::number(100.0 * reached / (reached + notReached))));
        ui->FilterMyProfile->update();
    }
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
        if (aIndex.column() == c_columnComment) {
            buttonComment_Clicked();
        } else {
//            buttonAchievements_Clicked();
        }
    });
}

void FormAchievements::initTableCompare() {
    ui->TableViewCompare->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
    ui->TableViewCompare->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

    ui->TableViewCompare->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TableViewCompare->setShowGrid(false);
    ui->TableViewCompare->setSortingEnabled(true);
    ui->TableViewCompare->horizontalHeader()->setStretchLastSection(true);
    ui->TableViewCompare->verticalHeader()->setVisible(false);
    ui->TableViewCompare->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->TableViewCompare->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->TableViewCompare, &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
        updateCurrentAchievement();
        if (_currentAchievement != nullptr) {
            QMenu *menu = createMenu(*_currentAchievement);
            menu->popup(ui->TableViewCompare->viewport()->mapToGlobal(pos));
        }
    });

    connect(ui->TableViewCompare, &QTableView::doubleClicked, this, [=](QModelIndex aIndex) {
        updateCurrentAchievement();
        if (aIndex.column() == c_columnComment) {
            buttonComment_Clicked();
        } else {
//            buttonAchievements_Clicked();
        }
    });
}

void FormAchievements::updateCurrentAchievement() {
    QTableView *table = dynamic_cast<QTableView*>(QApplication::focusWidget());
    if ((table != ui->TableViewMyAchievements) && (table != ui->TableViewCompare)) {
        return;
    }
    QModelIndex index = table->currentIndex();
    _currentAchievementIndex = table->model()->index(index.row(), c_columnIndex).data().toString().toInt();
    QString appId = table->model()->index(index.row(), c_columnAppid).data().toString();

    auto iterator = std::find_if(_achievements.begin(),
                                 _achievements.end(),
                                 [=](const SAchievement &achievement) {
                                     return achievement._apiName == appId;
                                 });
    if (iterator != _achievements.end()) {
        _currentAchievement = &*iterator;
    }
}

void FormAchievements::updateCurrentCategory() {
    auto currentItem = ui->TreeWidgetCategories->currentItem();
    QCheckBox *checkBox = dynamic_cast<QCheckBox*>(ui->TreeWidgetCategories->itemWidget(currentItem, 0));
    if (checkBox) {
        _currentCategoryIndex = checkBox->accessibleName().toInt();
    } else {
        QLabel *label = dynamic_cast<QLabel*>(ui->TreeWidgetCategories->itemWidget(currentItem, 0));
        if (label) {
            _currentCategoryIndex = label->accessibleName().toInt();
        }
    }
    _currentCategory = _categoriesGame.categoryAtDirect(_currentCategoryIndex);
}

QMenu *FormAchievements::createMenu(const SAchievement &aAchievement) {
    QString appId = aAchievement._apiName;

    //Добавление кнопки избранного
    QAction *actionFavorites;
    QList<FavoriteAchievement> favorites = Favorites::getAchievementsGame(_profile._steamID, _game).getAchievements();
    bool isFavorite = std::any_of(favorites.cbegin(), favorites.cend(), [=](FavoriteAchievement curFavorite) {
                                                                            return curFavorite.getId() == appId;
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
    //actionGroup->setIcon(QIcon(Images::group1()));

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

    connect (actionAchievements,    &QAction::triggered,    this,   &FormAchievements::categoryChangeAchievements);
    connect (actionSubCategory,     &QAction::triggered,    this,   &FormAchievements::categoryAddSubCategory);
    connect (actionDelete,          &QAction::triggered,    this,   &FormAchievements::categoryDelete);

    return menu;
}

void FormAchievements::categoryChangeAchievements() {
    ui->tabWidget->setCurrentIndex(c_tabCategories);
    updateCurrentCategory();
    ui->CategoriesEdit->changeCategory(_currentCategory, _currentCategoryIndex);
}

void FormAchievements::categoryAddSubCategory() {
    ui->tabWidget->setCurrentIndex(c_tabCategories);
    ui->CategoriesEdit->addSubCategory(_currentCategory);
}

void FormAchievements::categoryDelete() {
    ui->tabWidget->setCurrentIndex(c_tabCategories);
    ui->CategoriesEdit->deleteCategory(_currentCategory, _currentCategoryIndex);
}

void FormAchievements::buttonComment_Clicked() {
    FramelessWindow *f = new FramelessWindow;
    FormComments *ci = new FormComments(_profile, _game, _currentAchievement, f);
    f->setWidget(ci);
    connect(ci, &FormComments::s_updateComments, this, [=](bool isUpdate) {
        if (isUpdate) {
            initComments();
        }
        delete ci;
    });
    f->show();
}

void FormAchievements::initComments() {
    _comments.load();
    for(const auto &achievement: _achievements) {
        QStringList comment = _comments.getAchievementComment(_profile._steamID, _game.sAppId(), achievement._apiName).getComment();
        QVariant icon;
        QModelIndex index = ui->TableViewMyAchievements->model()->index(rowFromId(achievement._apiName), c_columnComment);

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

int FormAchievements::rowFromId(QString aId) {
    QStandardItemModel *model = dynamic_cast<QStandardItemModel *>(ui->TableViewMyAchievements->model());
    if (model) {
        QList<QStandardItem*> items = model->findItems(aId, Qt::MatchExactly, c_columnAppid);
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

void FormAchievements::setTableModels(QStandardItemModel *aModel) {
    QStandardItem *name = new QStandardItem(_profile._personaName);
    name->setFont(QFont(Settings::getFontDefaultName()));
    aModel->setHorizontalHeaderItem(c_columnReachedMy, name);

    QStandardItem *avatar = new QStandardItem();
    avatar->setData(QVariant(_profile.getPixmapAvatar()), Qt::DecorationRole);
    avatar->setFlags(Qt::ItemFlag::ItemIsEnabled);
    aModel->setItem(0, c_columnReachedMy, avatar);

    ui->TableViewMyAchievements->setModel(aModel);
    _fCategories.setRow(aModel->rowCount());
    _fAchievements.setRow(aModel->rowCount());
    _fCompare.setRow(aModel->rowCount());
    //ui->TableViewMyAchievements->setSortingEnabled(true);
    ui->TableViewMyAchievements->setRowHidden(0, true);
    ui->TableViewMyAchievements->setColumnHidden(c_columnAppid, true);
    ui->TableViewMyAchievements->setColumnHidden(c_columnIndex, true);
    initComments();

    ui->TableViewCompare->setModel(aModel);
    //ui->TableViewCompare->setSortingEnabled(true);
    ui->TableViewCompare->setColumnHidden(c_columnAppid, true);
    ui->TableViewCompare->setColumnHidden(c_columnIndex, true);
    ui->TableViewCompare->resizeColumnsToContents();
    ui->TableViewCompare->resizeRowsToContents();

    retranslate();
    showCategories();
    ui->TableViewMyAchievements->resizeColumnsToContents();
    ui->TableViewMyAchievements->setColumnWidth(c_columnTitle, 220);
    ui->TableViewMyAchievements->setColumnWidth(c_columnDescription, 450);
    ui->TableViewMyAchievements->resizeRowsToContents();
    ui->LineEditNameAchievements->setFocus();
}

void FormAchievements::createThread() {
    Threading *loadTable = new Threading(this);
    ui->ProgressBarLoad->setMaximum(_achievements.getCount());
    ui->ProgressBarLoad->setValue(0);
    ui->ProgressBarLoad->setVisible(true);
    loadTable->AddThreadAchievements(c_columnAppid,
                                     c_columnIndex,
                                     c_columnIcon,
                                     c_columnTitle,
                                     c_columnDescription,
                                     c_columnComment,
                                     c_columnWorld,
                                     c_columnReachedMy,
                                     c_columnCount,
                                     _achievements,
                                     _game.appId());
    connect (loadTable, &Threading::s_achievements_progress, this, [=](int progress, int row) {
        Q_UNUSED(row);
        //emit s_achievementsLoaded(progress, row);
        ui->ProgressBarLoad->setValue(progress);
    });
    connect (loadTable, &Threading::s_achievements_finished_model, this, [=](QStandardItemModel *model, int reached, int notReached) {
        setTableModels(model);
        onTablePulled(reached, notReached);
    });
}
#define InitEnd }

void FormAchievements::updateFilterWithMyProfile(ReachedType aType, bool aStandart, bool aCompare) {
    switch (aType) {
    case ReachedType::all: {
        if (aStandart) {
            for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
                _fAchievements.setData(i, c_filterReached, true);
            }
        }
        if (aCompare) {
            for (int i = 0; i < ui->TableViewCompare->model()->rowCount() - 1; ++i) {
                _fCompare.setData(i, c_filterReached, true);
            }
        }
        break;
    }
    case ReachedType::reached: {
        if (aStandart) {
            for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
                _fAchievements.setData(i, c_filterReached, ui->TableViewMyAchievements->model()->index(i + 1, c_columnReachedMy).data().toString().indexOf(".") > -1);
            }
        }
        if (aCompare) {
            for (int i = 0; i < ui->TableViewCompare->model()->rowCount() - 1; ++i) {
                _fCompare.setData(i, c_filterReached, ui->TableViewCompare->model()->index(i + 1, c_columnReachedMy).data().toString().indexOf(".") > -1);
            }
        }
        break;
    }
    case ReachedType::notReached: {
        if (aStandart) {
            for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
                _fAchievements.setData(i, c_filterReached, ui->TableViewMyAchievements->model()->index(i + 1, c_columnReachedMy).data().toString().indexOf(".") == -1);
            }
        }
        if (aCompare) {
            for (int i = 0; i < ui->TableViewCompare->model()->rowCount() - 1; ++i) {
                _fCompare.setData(i, c_filterReached, ui->TableViewCompare->model()->index(i + 1, c_columnReachedMy).data().toString().indexOf(".") == -1);
            }
        }
        break;
    }
    default: {
        break;
    }
    }
    updateHiddenRows(aStandart, aCompare);
}

void FormAchievements::updateFilterTextAchievement(const QString &aNewText, bool aStandart, bool aCompare) {
    if (aStandart) {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            _fAchievements.setData(i, c_filterName, ((ui->TableViewMyAchievements->model()->index(i + 1, c_columnTitle).data().toString().toLower().indexOf(aNewText.toLower()) > -1)
                                                   ||(ui->TableViewMyAchievements->model()->index(i + 1, c_columnDescription).data().toString().toLower().indexOf(aNewText.toLower()) > -1)));
        }
    }
    if (aCompare) {
        for (int i = 0; i < ui->TableViewCompare->model()->rowCount() - 1; ++i) {
            _fCompare.setData(i, c_filterName, ((ui->TableViewCompare->model()->index(i + 1, c_columnTitle).data().toString().toLower().indexOf(aNewText.toLower()) > -1)
                                                ||(ui->TableViewCompare->model()->index(i + 1, c_columnDescription).data().toString().toLower().indexOf(aNewText.toLower()) > -1)));
        }
    }
    updateHiddenRows(aStandart, aCompare);
}

#define SimpleCompare {
void FormAchievements::setFormMode(FormMode aMode) {
//    switch (aMode) {
//    case FormMode::standart: {
//        ui->FilterMyProfile             ->setVisible(true);
//        ui->CheckBoxCompareAllFriends   ->setVisible(false);
//        ui->TableWidgetFriends          ->setVisible(false);

////        ui->ButtonAddCategory           ->setEnabled(true);
////        ui->ButtonChangeCategory        ->setEnabled(true);

////        ui->ButtonDeleteAllCategories   ->setEnabled(true);
////        ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
//        break;
//    }
//    case FormMode::compare: {
//        ui->FilterMyProfile             ->setVisible(false);
//        ui->CheckBoxCompareAllFriends   ->setVisible(true);
//        ui->TableWidgetFriends          ->setVisible(true);

////        ui->ButtonAddCategory           ->setEnabled(false);
////        ui->ButtonChangeCategory        ->setEnabled(false);

////        ui->ButtonDeleteAllCategories   ->setEnabled(false);
////        ui->ButtonCompare->setText(tr("Обратно"));
//        switch (_loadCompare) {
//        case 0: {
//            ui->TableWidgetFriends      ->setVisible(false);
//            loadingCompare();
//            break;
//        }
//        case 1: {
//            ui->TableWidgetFriends      ->setVisible(true);
//            break;
//        }
//        default: {
//            ui->TableWidgetFriends      ->setVisible(true);
//        }
//        }
//        break;
//    }
//    }
}

void FormAchievements::loadingCompare() {
//    ++_loadCompare;

//    _profilesFriends = SFriends(_profile._steamID, false).getProfiles();
//    ui->TableWidgetFriends->setColumnCount(_profilesFriends.getCount() + 2);
//    for (int i = 0; i < _profilesFriends.getCount() + 2; ++i) {
//        ui->TableWidgetFriends->setColumnWidth(i, 33 + 8);
//    }
//    _profilesFriends.sort();
//    ui->ProgressBarLoad->setMaximum(_profilesFriends.getCount());
//    ui->ProgressBarLoad->setValue(0);
//    ui->ProgressBarLoad->setVisible(true);

//    int index = -1;
//    for(auto &profileFriend: _profilesFriends) {
//        SGames *gamesFriend = new SGames(this);
//        gamesFriend->_index = ++index;
//        gamesFriend->load(profileFriend._steamID, true, true, true);
//        connect(gamesFriend, SIGNAL(s_finished(SGames*)), this, SLOT(loadFriendGames(SGames*)));
//    }
}

void FormAchievements::loadFriendGames(SGames *aGames) {
    disconnect(aGames, SIGNAL(s_finished(SGames*)), this, SLOT(loadFriendGames(SGames*)));
    bool isGameExist = std::any_of(aGames->begin(), aGames->end(), [=](const SGame &game) {
                                                                        return game.appId() == _game.appId();
                                                                    });
    QPair<SProfile, FriendType> friendState;
    friendState.first = _profilesFriends[aGames->_index];
    if (isGameExist) {
        friendState.second = FriendType::haveGame;
        ++_type1;
    } else {
        friendState.second = FriendType::haventGame;
        ++_type2;
    }
    _friends.push_back(std::move(friendState));
    ui->ProgressBarLoad->setValue(ui->ProgressBarLoad->value() + 1);
    if(ui->ProgressBarLoad->value() == _profilesFriends.getCount()) {
        finishLoadFriends();
    }
}

void FormAchievements::finishLoadFriends() {
    ui->ProgressBarLoad->setVisible(false);
    int row = 2;
    for(auto &friendP: _friends) {
        QLabel *avatarFriend = new QLabel(this);
        avatarFriend->setToolTip(friendP.first._personaName);
        avatarFriend->setAlignment(Qt::AlignCenter);
        avatarFriend->setPixmap(friendP.first.getPixmapAvatar());
        ui->TableWidgetFriends->setCellWidget(0, row, avatarFriend);

        QTableWidgetItem *itemCheck(new QTableWidgetItem(""));
        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
        itemCheck->setCheckState(Qt::Unchecked);
        itemCheck->setTextAlignment(Qt::AlignCenter);

        ui->TableWidgetFriends->setItem(c_tableFriendsRowCheckBox, row, itemCheck);
        ui->TableWidgetFriends->setItem(c_tableFriendsRowID, row, new QTableWidgetItem(friendP.first._steamID));

        ui->TableWidgetFriends->setColumnHidden(row, friendP.second == FriendType::haventGame);
        ++row;
    }
    connect(ui->TableWidgetFriends, &QTableWidget::cellChanged, this, &FormAchievements::tableWidgetCompareFriends_CellChanged);
    ++_loadCompare;
    ui->TableWidgetFriends->setVisible(_currentMode == FormMode::compare);
}

void FormAchievements::compareProfileFilterClickFriends(const QString &aName, ReachedType aType) {
    QLabel *friendAvatar = dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(0, aName.toInt()));
    if (friendAvatar) {
        QString name = friendAvatar->toolTip();
//        _tableAchievements->updateFilterWithFriend(name, aType);
    } else {
        qWarning() << "not init friendAvatar";
    }
}

void FormAchievements::buttonCompareAllFriendsReach_Clicked() {
    QButtonWithData *senderButton = dynamic_cast<QButtonWithData*>(sender());
    if (senderButton) {
        ReachedType setType = ReachedType::none;
        if(senderButton->getData(1) == "All") {
            setType = ReachedType::all;
        } else if (senderButton->getData(1) == "Reached") {
            setType = ReachedType::reached;
        } else if (senderButton->getData(1) == "NotReached") {
            setType = ReachedType::notReached;
        }
        for (int i = 2; i < ui->TableWidgetFriends->columnCount(); ++i) {
            FormCompareProfileFilter *friendFilter = findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend" + QString::number(i));
            if (friendFilter) {
                friendFilter->setType(setType);
            } else {
                //qDebug()<<"error FormAchievements::buttonCompareAllFriendsReach_Clicked() filterFriend";
            }
        }
    } else {
        qWarning() << "not init senderButton";
    }
}

void FormAchievements::tableWidgetCompareFriends_CellChanged(int aRow, int aColumn) {
    if ((aRow == 1) && (aColumn > 1)) {
        SProfile profileFriend = _friends[aColumn - 2].first;
        if (ui->TableWidgetFriends->item(aRow, aColumn)->checkState() == Qt::Checked) {
//            if (_tableAchievements->addFriendColumn(profileFriend)) {
//                createCompareProfileFilter(true, aColumn);
//            }
        } else {
//            _tableAchievements->removeFriendColumn(profileFriend._personaName);
            FormCompareProfileFilter *friendFilter = findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend" + QString::number(aColumn));
            if (friendFilter) {
                disconnect(friendFilter, &FormCompareProfileFilter::s_radioButtonChange, this, &FormAchievements::compareProfileFilterClickFriends);
                ui->TableWidgetFriends->removeCellWidget(c_tableFriendsRowFilters, aColumn);
                delete friendFilter;
                //ui->TableWidgetFriends->resizeColumnsToContents();
            } else {
                qWarning() << "not init friendFilter";
            }
        }
    }
}

void FormAchievements::createCompareProfileFilter(bool aAccept, int aColumn) {
    if (aAccept) {
        FormCompareProfileFilter *friendFilter = new FormCompareProfileFilter(this);
        friendFilter->setObjectName("FormCompareProfileFilterFriend" + QString::number(aColumn));
        friendFilter->setName(QString::number(aColumn));
        connect(friendFilter, &FormCompareProfileFilter::s_radioButtonChange, this,         &FormAchievements::compareProfileFilterClickFriends);
        connect(this,         &FormAchievements::s_updateSettings,            friendFilter, &FormCompareProfileFilter::updateSettings);
        ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, aColumn, friendFilter);
        //ui->TableWidgetFriends->resizeRowsToContents();
        //ui->TableWidgetFriends->resizeColumnsToContents();
    }
}

void FormAchievements::checkBoxCompareAllFriends_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        for (int i = 0; i < _friends.size(); ++i) {
            if(_friends[i].second == FriendType::haventGame) {
                ui->TableWidgetFriends->setColumnHidden(i + 2, true);
            }
        }
        break;
    }
    case 2: {
        for (int i = 0; i < _friends.size(); ++i) {
            if (_friends[i].second == FriendType::haventGame) {
                ui->TableWidgetFriends->setColumnHidden(i + 2, false);
            }
        }
        //ui->TableWidgetFriends->resizeColumnsToContents();
        break;
    }
    }
}
#define SimpleCompareEnd }

#define System {
FormAchievements::~FormAchievements() {
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

void FormAchievements::checkBoxCategory_StateChanged(int aIndex) {
    updateCurrentCategory();
    if (_currentCategory != nullptr) {
        switch (aIndex) {
        case 0: {
            updateFilterCategory(_currentCategoryIndex, true);
            break;
        }
        case 2: {
            QList<QString> achievementsName = _currentCategory->achievements();
            updateFilterCategory(_currentCategoryIndex, false, achievementsName);
            break;
        }
        }
    }
}

int FormAchievements::recursAddCategoryToTree(Category &aCategory, int aCount, QTreeWidgetItem *aRoot) {
    QTreeWidgetItem *subItem;
    if (aRoot == nullptr) {
        subItem = new QTreeWidgetItem(ui->TreeWidgetCategories);
    } else {
        subItem = new QTreeWidgetItem(aRoot);
    }
    QSize sizeHint;
    QWidget *widget;
    if (aCategory.achievements().isEmpty()) {
        widget = new QLabel(aCategory.title());
    } else {
        widget = new QCheckBox(aCategory.title());
        connect(dynamic_cast<QCheckBox*>(widget), &QCheckBox::stateChanged, this, &FormAchievements::checkBoxCategory_StateChanged);
    }
    widget->setAccessibleName(QString::number(aCount++));
    sizeHint = widget->sizeHint();
    sizeHint.rwidth() += 10;
    subItem->setSizeHint(0, sizeHint);
    ui->TreeWidgetCategories->setItemWidget(subItem, 0, widget);
    for(auto &subCategory: aCategory) {
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

    _fCategories.setCol(_categoriesGame.countAll());
    _fAchievements.setCol(_categoriesGame.countAll() + c_filterColumnCount);
    if (ui->TableViewCompare->model() != nullptr) {
        _fCompare.setCol(_categoriesGame.countAll() + c_filterColumnCount + ui->TableViewCompare->model()->columnCount() - c_columnCount);
    } else {
        _fCompare.setCol(_categoriesGame.countAll() + c_filterColumnCount - c_columnCount);
    }
    updateHiddenRows(true, true);
}
#define SystemEnd }

#define Filter {
void FormAchievements::buttonUpdate_Clicked() {
//    _tableAchievements->update();
    _achievements.update(false);
    createThread();
}

void FormAchievements::updateFilterCategory(int aCategoryIndex, bool aClear, QList<QString> aAchievementNames) {
    if (aClear) {
        for (int i = 0; i < _fAchievements.getRow(); ++i) {
            _fAchievements.setData(i, c_filterEndConstValues + aCategoryIndex, true);
        }
        for (int i = 0; i < _fCompare.getRow(); ++i) {
            _fCompare.setData(i, c_filterEndConstValues + aCategoryIndex, true);
        }
    } else {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            _fAchievements.setData(i, c_filterEndConstValues + aCategoryIndex, false);
            auto text = ui->TableViewMyAchievements->model()->index(i + 1, c_columnAppid).data().toString();
            bool isAchievementExist = std::any_of(aAchievementNames.begin(),
                                                  aAchievementNames.end(),
                                                  [=](QString &achievementName) {
                                                        return text == achievementName;
                                                    });
            if (isAchievementExist) {
                _fAchievements.setData(i, c_filterEndConstValues + aCategoryIndex, true);
            }
        }
        for (int i = 0; i < ui->TableViewCompare->model()->rowCount() - 1; ++i) {
            _fCompare.setData(i, c_filterEndConstValues + aCategoryIndex, false);
            auto text = ui->TableViewCompare->model()->index(i + 1, c_columnAppid).data().toString();
            bool isAchievementExist = std::any_of(aAchievementNames.begin(),
                                                  aAchievementNames.end(),
                                                  [=](QString &achievementName) {
                                                        return text == achievementName;
                                                    });
            if (isAchievementExist) {
                _fCompare.setData(i, c_filterEndConstValues + aCategoryIndex, true);
            }
        }
    }
    updateHiddenRows(true, true);
}

void FormAchievements::comboBoxCategory_IndexChange(int aIndex) {
    if (_categoriesGame.countTopCategories() > 0) {
        QComboBoxWithData *comboBox = dynamic_cast<QComboBoxWithData*>(sender());
        if (comboBox) {
            int categoryIndex = comboBox->getData(0).toInt();
            if (aIndex != 0) {
//                QList<QString> achievementsName = _categoriesGame[categoryIndex].values().at(aIndex - 1).achievements;
//                updateFilterCategory(categoryIndex, false, achievementsName);
            } else {
                updateFilterCategory(categoryIndex, true);
            }
        } else {
            qWarning() << "not init comboBox";
        }
    }
}

//void FormAchievements::checkBoxCategory_StateChanged(int aIndex) {
//    if (_categoriesGame.getCount() > 0) {
//        QCheckBoxWithData *checkBox = dynamic_cast<QCheckBoxWithData*>(sender());
//        if (checkBox) {
//            int categoryIndex = checkBox->getData(0).toInt();
//            if (aIndex != 0) {
////                QList<QString> achievementsName = _categoriesGame[categoryIndex].getNoValues();
////                updateFilterCategory(categoryIndex, false, achievementsName);
//            } else {
//                updateFilterCategory(categoryIndex, true);
//            }
//        } else {
//            qWarning() << "not init checkBox";
//        }
//    }
//}
#define FilterEnd }

#define Function {

void FormAchievements::updateFilterFavorite(const QList<FavoriteAchievement> &aFavorites) {
    if (aFavorites.count() == 0) {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            _fAchievements.setData(i, c_filterFavorite, true);
        }
        for (int i = 0; i < ui->TableViewCompare->model()->rowCount() - 1; ++i) {
            _fCompare.setData(i, c_filterFavorite, true);
        }
    } else {
        for (int i = 0; i < ui->TableViewMyAchievements->model()->rowCount() - 1; ++i) {
            QString apiName = _achievements[i]._apiName;
            bool accept = std::any_of(aFavorites.begin(), aFavorites.end(), [=](const FavoriteAchievement &achievement) {
                                                                                return (achievement.getId() == apiName);
                                                                            });
            _fAchievements.setData(i, c_filterFavorite, accept);
        }
        for (int i = 0; i < ui->TableViewCompare->model()->rowCount() - 1; ++i) {
            QString apiName = _achievements[i]._apiName;
            bool accept = std::any_of(aFavorites.begin(), aFavorites.end(), [=](const FavoriteAchievement &achievement) {
                                                                                return (achievement.getId() == apiName);
                                                                            });
            _fCompare.setData(i, c_filterFavorite, accept);
        }
    }
    updateHiddenRows(true, true);
}

void FormAchievements::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        updateFilterFavorite(QList<FavoriteAchievement>());
        break;
    }
    case 2: {
        updateFilterFavorite(_favorites.getAchievementsGame(_profile._steamID, _game).getAchievements());
        break;
    }
    }
}

void FormAchievements::buttonFavorite_Clicked() {
    if (_currentAchievementIndex > -1) {
        if (_favorites.addAchievement(_profile._steamID, _game,  *_currentAchievement, true)) {
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

}

void FormAchievements::tabWidget_CurrentChanged(int index) {
    switch(index) {
    case 0: {//standart
        updateHiddenColumnsStandart();
        break;
    }
    case 1: {//editCategory
        if (!_isEditCategoryLoaded) {
            loadEditCategory();
        }
        break;
    }
    case 2: {//compare
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
    ui->CategoriesEdit->updateFilter(_fAchievements);
    connect(ui->CategoriesEdit, &FormCategoriesEdit::s_categoriesIsUpdated, this, [=](bool isUpdated) {
        if (isUpdated) {
            showCategories();
        }
    });
    _isEditCategoryLoaded = true;
}

void FormAchievements::loadCompare() {
    //блаблаs
    ui->FriendsCompare->setInitData(_profile, _game);
    _isCompareLoaded = true;
}
