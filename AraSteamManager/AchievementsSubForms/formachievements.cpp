#include "formachievements.h"
#include "ui_formachievements.h"
#define Constants {
constexpr int c_tableAchievementColumnAppid       = 0;
constexpr int c_tableAchievementColumnIcon        = 1;
constexpr int c_tableAchievementColumnTitle       = 2;
constexpr int c_tableAchievementColumnDescription = 3;
constexpr int c_tableAchievementColumnWorld       = 4;
constexpr int c_tableAchievementColumnReachedMy   = 5;
constexpr int c_tableAchievementColumnCount       = 6;

constexpr int c_tableCategoryColumnNoValue        = c_tableAchievementColumnCount;

constexpr int c_tableFriendsRowAvatars            = 0;
constexpr int c_tableFriendsRowCheckBox           = 1;
constexpr int c_tableFriendsRowFilters            = 2;
constexpr int c_tableFriendsRowID                 = 3;
constexpr int c_tableFriendsRowCount              = 4;

constexpr int c_categoriesWidth                   = 200;
constexpr int c_CategoriesEditWidth               = 400;
constexpr int c_CategoriesEditHeight              = 300;
#define ConstantsEnd }

#define Init {
FormAchievements::FormAchievements(SAchievementsPlayer aPlayer, SProfile aProfile, SGame aGame, int aUnicNum, QWidget *aParent): QWidget(aParent), ui(new Ui::FormAchievements),
_profile(aProfile), _game(aGame), _unicNum(aUnicNum), _categoriesGame(_game), _favorites("achievements") {
    ui->setupUi(this);
    initComponents(aPlayer);
    ui->LineEditNameAchievements->setFocus();
}

void FormAchievements::initComponents(SAchievementsPlayer aPlayer) {
    #define LoadData {
    this->setAttribute(Qt::WA_TranslucentBackground);

    //Временно
    ui->ListWidgetValuesCategory->setDragEnabled(false);

    QLabel *allFriends = new QLabel("All", this);
    allFriends->setToolTip(tr("Достижения друзей"));
    allFriends->setScaledContents(true);
    allFriends->setFixedSize(32, 32);

    QLabel *avatarAchievementsCompare = new QLabel(this);
    avatarAchievementsCompare->setAlignment(Qt::AlignCenter);
    avatarAchievementsCompare->setPixmap(_profile.getPixmapAvatar());

    QLabel *avatarFriendsCompare = new QLabel(this);
    avatarFriendsCompare->setAlignment(Qt::AlignCenter);
    avatarFriendsCompare->setToolTip(_profile._personaName);
    avatarFriendsCompare->setPixmap(_profile.getPixmapAvatar());

    ui->LabelGameLogo->setPixmap(_game.getPixmapLogo());
    Settings::createDir(_setting.getPathForImagesAchievements(QString::number(_game._appID),""));
    //ui->FrameEditCategory->setVisible(false);
    ui->ProgressBarFriendsLoad->setVisible(false);
    ui->LabelGameOnlineValue->setText(_game.getNumberPlayers(false));
    ui->LabelGameTitle->setText(_game._name);
    ui->FrameFilter->setEnabled(false);
    ui->ButtonCompare->setMinimumHeight(21);
    #define LoadDataEnd }
    #define ConnectTables {
    _tableAchievements = new FormTablesHeaders(_game, _profile._steamID, aPlayer, ui->FrameContainer);
    connect(_tableAchievements, &FormTablesHeaders::s_tablePulled, this, &FormAchievements::onTablePulled);
    _tableAchievements->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    _tableAchievements->changeHorizontalTitle(c_tableAchievementColumnReachedMy, _profile._personaName);
    _tableAchievements->setWidgetHorizontalHeader(0, c_tableAchievementColumnReachedMy, avatarAchievementsCompare);
    #define ConnectTablesEnd }
    #define SetTableWidgetCompareFriendsSettings {
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setMinimumSize(0, 210);
    ui->TableWidgetFriends->setColumnCount(2);
    ui->TableWidgetFriends->setRowCount(c_tableFriendsRowCount);
    ui->TableWidgetFriends->setRowHidden(c_tableFriendsRowID, true);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars, 0, avatarFriendsCompare);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars, 1, allFriends);

    QVBoxLayout *layoutReachedFilter = new QVBoxLayout(ui->FrameReachedFilter);
    _filterMyProfile = new FormCompareProfileFilter(tr("Все достижения"),
                                                    tr("Полученные достижения"),
                                                    tr("Не полученные достижения"),
                                                    this);
    connect(_filterMyProfile, &FormCompareProfileFilter::s_radioButtonChange, _tableAchievements, [=](QString, ReachedType aType) {
        _tableAchievements->updateFilterWithMyProfile(aType, true, false);
    });
    layoutReachedFilter->addWidget(_filterMyProfile);
    //ui->GroupBoxReachedFilter->setLayout(layoutReachedFilter);

    FormCompareProfileFilter *myFilter = new FormCompareProfileFilter(this);
    myFilter->setObjectName("FormCompareProfileFilterMy");
    connect(myFilter, &FormCompareProfileFilter::s_radioButtonChange, _tableAchievements, [=](QString, ReachedType aType) {
        _tableAchievements->updateFilterWithMyProfile(aType, false, true);
    });

    QWidget *widgetFriendsAchievementsFilter = new QWidget(this);
    QVBoxLayout *layoutFriendsAchievementsFilter = new QVBoxLayout(widgetFriendsAchievementsFilter);
    layoutFriendsAchievementsFilter->setMargin(1);
    layoutFriendsAchievementsFilter->setAlignment(Qt::AlignCenter);
    layoutFriendsAchievementsFilter->addWidget(createButtonWithData("PBFriendsAll",        "Friends", "All",        true));
    layoutFriendsAchievementsFilter->addWidget(createButtonWithData("PBFriendsReached",    "Friends", "Reached",    false));
    layoutFriendsAchievementsFilter->addWidget(createButtonWithData("PBFriendsNotReached", "Friends", "NotReached", false));
    //widgetFriendsAchievementsFilter->setLayout(layoutFriendsAchievementsFilter);

    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, 0, myFilter);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, 1, widgetFriendsAchievementsFilter);
    ui->TableWidgetFriends->resizeRowsToContents();
    for (int i = 0; i < ui->TableWidgetFriends->rowCount(); i++) {
        ui->TableWidgetFriends->setRowHeight(i, ui->TableWidgetFriends->rowHeight(i) + 18);
    }
    ui->TableWidgetFriends->setRowHeight(c_tableFriendsRowCheckBox, 30);
    ui->TableWidgetFriends->resizeColumnsToContents();
    #define SetTableWidgetCompareFriendsSettingsEnd }
    setIcons();
    #define Connects {
    connect(ui->ButtonUpdate,                       &QPushButton::clicked,                    this,                &FormAchievements::buttonUpdate_Clicked);
    connect(ui->CheckBoxCompareAllFriends,          &QCheckBox::stateChanged,                 this,                &FormAchievements::checkBoxCompareAllFriends_StateChanged);
    connect(ui->ButtonAddCategory,                  &QPushButton::clicked,                    this,                &FormAchievements::buttonAddCategory_Clicked);
    connect(ui->ButtonChangeCategory,               &QPushButton::clicked,                    this,                &FormAchievements::buttonChangeCategory_Clicked);
    connect(ui->ButtonCompare,                      &QPushButton::clicked,                    this,                &FormAchievements::buttonCompare_Clicked);
    connect(ui->ButtonDeleteAllCategories,          &QPushButton::clicked,                    this,                &FormAchievements::buttonDeleteAllCategories_Clicked);
    connect(ui->ButtonAddValueCategory,             &QPushButton::clicked,                    this,                &FormAchievements::buttonAddValueCategory_Clicked);
    connect(ui->ButtonAcceptCategory,               &QPushButton::clicked,                    this,                &FormAchievements::buttonAcceptCategory_Clicked);
    connect(ui->ButtonCancelCategory,               &QPushButton::clicked,                    this,                &FormAchievements::buttonCancelCategory_Clicked);
    connect(ui->ButtonDeleteCategory,               &QPushButton::clicked,                    this,                &FormAchievements::buttonDeleteCategory_Clicked);
    connect(ui->CheckBoxCategoryOneValue,           &QCheckBox::stateChanged,                 this,                &FormAchievements::checkBoxCategoryOneValue_StateChanged);
    connect(ui->LineEditTitleCategory,              &QLineEdit::textChanged,                  this,                &FormAchievements::lineEditTitleCategory_TextChanged);
    connect(ui->ComboBoxCategories,                 SIGNAL(activated(int)),                   this,                SLOT(comboBoxCategories_Activated(int)));
    connect(ui->CheckBoxCategoryVisibleAll,         &QCheckBox::clicked,                      this,                &FormAchievements::checkBoxCategoryVisibleAll_Clicked);
    connect(ui->CheckBoxFavorites,                  &QCheckBox::stateChanged,                 this,                &FormAchievements::checkBoxFavorites_StateChanged);
    connect(ui->ButtonFavorite,                     &QPushButton::clicked,                    this,                &FormAchievements::buttonFavorite_Clicked);
    connect(ui->ButtonGuides,                       &QPushButton::clicked,                    this,                &FormAchievements::buttonManual_Clicked);
    connect(_tableAchievements,                     &FormTablesHeaders::s_contentCellClicked, this,                &FormAchievements::tableAchievements_CellClicked);
    connect(ui->ListWidgetValuesCategory,           &QListWidget::currentRowChanged,          this,                &FormAchievements::formCategoryListWidget_CurrentRowChanged);
    connect(ui->ButtonCategoryValueReverse,         &QPushButton::clicked,                    this,                &FormAchievements::formCategoryValueReverse);
    connect(ui->ButtonCategoryValueTop,             &QPushButton::clicked,                    this,                &FormAchievements::formCategoryValueTop);
    connect(ui->ButtonCategoryValueUp,              &QPushButton::clicked,                    this,                &FormAchievements::formCategoryValueUp);
    connect(ui->ButtonCategoryValueDown,            &QPushButton::clicked,                    this,                &FormAchievements::formCategoryValueDown);
    connect(ui->ButtonCategoryValueBottom,          &QPushButton::clicked,                    this,                &FormAchievements::formCategoryValueBottom);
    connect(ui->ButtonCategoryValueCheckVisible,    &QPushButton::clicked,                    this,                &FormAchievements::formCategoryValueSelectVisible);
    connect(ui->ButtonCategoryValueUncheckVisible,  &QPushButton::clicked,                    this,                &FormAchievements::formCategoryValueUnselectVisible);
    connect(ui->ButtonCategoryValueDelete,          &QPushButton::clicked,                    this,                &FormAchievements::formCategoryValueDelete);
    connect(ui->CheckBoxCategoryUniqueValue,        &QCheckBox::stateChanged,                 this,                [=](int checkBoxState) {
        _tableAchievements->setUniqueMode(checkBoxState == 2);
    });
    connect(ui->CheckBoxShowCategories,                 &QCheckBox::stateChanged,                 this,                [=](int checkBoxState) {
        QPropertyAnimation *animation = new QPropertyAnimation(ui->FrameCategories, "geometry");
        connect(animation, &QPropertyAnimation::finished, animation, &QPropertyAnimation::deleteLater);
        animation->setDuration(500);
        if (checkBoxState == 0) {
            animation->setStartValue(QRect(0, 0, ui->FrameCategories->width(), ui->FrameCategories->height()));
            animation->setEndValue(QRect(-ui->FrameCategories->width(), 0, ui->FrameCategories->width(), ui->FrameCategories->height()));
        } else {
            animation->setStartValue(QRect(-ui->FrameCategories->width(), 0, ui->FrameCategories->width(), ui->FrameCategories->height()));
            animation->setEndValue(QRect(0, 0, ui->FrameCategories->width(), ui->FrameCategories->height()));
        }
        animation->start();
        //ui->FrameCategories->setVisible(checkBoxState == 2);
    });
    connect(ui->LineEditNameAchievements,           &QLineEdit::textChanged,                  this,                [=](const QString &newText) {
        _tableAchievements->updateFilterTextAchievement(newText, true, true);
    });
    connect(ui->ButtonFindAchievement,              &QPushButton::clicked,                    this,                [=]() {
        ui->LineEditNameAchievements->setText(ui->LineEditNameAchievements->text());
    });
    connect(ui->CheckBoxCompareIcon,                &QCheckBox::stateChanged,                 _tableAchievements,  [=](int arg1) {
        _tableAchievements->setVisibleColumn(c_tableAchievementColumnIcon, arg1 == 2);
    });
    connect(ui->CheckBoxCompareTitle,               &QCheckBox::stateChanged,                 _tableAchievements,  [=](int arg1) {
        _tableAchievements->setVisibleColumn(c_tableAchievementColumnTitle, arg1 == 2);
    });
    connect(ui->CheckBoxCompareDescription,         &QCheckBox::stateChanged,                 _tableAchievements,  [=](int arg1) {
        _tableAchievements->setVisibleColumn(c_tableAchievementColumnDescription, arg1 == 2);
    });
    connect(ui->CheckBoxCompareTotalPercent,        &QCheckBox::stateChanged,                 _tableAchievements,  [=](int arg1) {
        _tableAchievements->setVisibleColumn(c_tableAchievementColumnWorld, arg1 == 2);
    });
    #define ConnectsEnd }
    ui->FrameCategories->raise();
    ui->FrameEditCategory->raise();
    setFormMode(FormMode::standart);
    showCategories();
    retranslate();
}

void FormAchievements::retranslate() {
    ui->retranslateUi(this);
    _filterMyProfile->setTitles(tr("Все достижения"), tr("Полученные достижения"), tr("Не полученные достижения"));
    ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars, 1)->setToolTip(tr("Достижения друзей"));
    switch (_currentMode) {
    case FormMode::compare: {
        ui->ButtonCompare->setText(tr("Обратно"));
        break;
    }
    case FormMode::standart: {
        ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
        break;
    }
    }
    switch (_typeCategory) {
    case CategoryType::add: {
        //ui->GroupBoxCategories->setTitle(tr("Добавить категорию"));
        break;
    }
    case CategoryType::change: {
        //ui->GroupBoxCategories->setTitle(tr("Изменить категорию"));
        break;
    }
    default: {
        break;
    }
    }
}

void FormAchievements::updateSettings() {
    _setting.syncronizeSettings();
    setIcons();
    emit s_updateSettings();
}

void FormAchievements::setIcons() {
    QString iconsColor = _setting.getIconsColor();
    ui->ButtonCompare->setIcon(QIcon(_setting.getIconCompare()));
    ui->ButtonAddCategory->setIcon(QIcon(_setting.getIconCreate()));
    ui->ButtonChangeCategory->setIcon(QIcon(_setting.getIconChange()));
    ui->ButtonDeleteCategory->setIcon(QIcon(_setting.getIconDelete()));
    ui->ButtonDeleteAllCategories->setIcon(QIcon(_setting.getIconDeleteAll()));
    ui->ButtonFindAchievement->setIcon(QIcon(_setting.getIconFind()));
    ui->ButtonAddValueCategory->setIcon(QIcon(_setting.getIconCreate()));
    ui->ButtonAcceptCategory->setIcon(QIcon(_setting.getIconApply()));
    ui->ButtonCancelCategory->setIcon(QIcon(_setting.getIconCancel()));
    ui->ButtonUpdate->setIcon(QIcon(_setting.getIconUpdate()));
    ui->ButtonFavorite->setIcon(QIcon(_setting.getIconIsNotFavorites()));

    ui->ButtonCategoryValueReverse->setIcon(QIcon(_setting.getIconReverse()));
    ui->ButtonCategoryValueTop->setIcon(QIcon(_setting.getIconTop()));
    ui->ButtonCategoryValueUp->setIcon(QIcon(_setting.getIconUp()));
    ui->ButtonCategoryValueDown->setIcon(QIcon(_setting.getIconDown()));
    ui->ButtonCategoryValueBottom->setIcon(QIcon(_setting.getIconBottom()));
    ui->ButtonCategoryValueCheckVisible->setIcon(QIcon(_setting.getIconCheckVisible()));
    ui->ButtonCategoryValueUncheckVisible->setIcon(QIcon(_setting.getIconUncheckVisible()));
    ui->ButtonCategoryValueDelete->setIcon(QIcon(_setting.getIconDelete()));

    QJsonObject gameObject;
    gameObject["id"] = _game._appID;
    gameObject["name"] = _game._name;
    QJsonArray favorites = _favorites.getValues(gameObject);
    bool isFavorite = false;
    for (auto favorite: favorites) {
        if (favorite.toObject().value("id").toString() == _currentAchievement) {
            isFavorite = true;
            break;
        }
    }
    if (isFavorite) {
        ui->ButtonFavorite->setIcon(QIcon(_setting.getIconIsFavorites()));
    } else {
        ui->ButtonFavorite->setIcon(QIcon(_setting.getIconIsNotFavorites()));
    }
    QLabel *friendsIcon = dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars, 1));
    if (friendsIcon) {
        friendsIcon->setPixmap(QPixmap(_setting.getIconFriends()));
    }
    QWidget *wFriendsFilter = dynamic_cast<QWidget*>(ui->TableWidgetFriends->cellWidget(c_tableFriendsRowFilters, 1));
    if (wFriendsFilter) {
        QButtonWithData *bFriendsAll = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(0)->widget());
        if (bFriendsAll) {
            bFriendsAll->setIcon(QIcon(_setting.getIconAll()));
        } else {
            qDebug()<<"error FormAchievements::setIcons() bFriendsAll";
        }
        QButtonWithData *bFriendsReached = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(1)->widget());
        if (bFriendsReached) {
            bFriendsReached->setIcon(QIcon(_setting.getIconReached()));
        } else {
            qDebug()<<"error FormAchievements::setIcons() bFriendsReached";
        }
        QButtonWithData *bFriendsNotReached = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(2)->widget());
        if (bFriendsNotReached) {
            bFriendsNotReached->setIcon(QIcon(_setting.getIconNotReached()));
        } else {
            qDebug()<<"error FormAchievements::setIcons() bFriendsNotReached";
        }
    } else {
        qDebug()<<"error FormAchievements::setIcons() wFriendsFilter";
    }
}

QButtonWithData *FormAchievements::createButtonWithData(QString aObjectName, QString aAppertain, QString aType, bool aChecked) {
    QButtonWithData *button = new QButtonWithData("", this);
    button->setObjectName(aObjectName);
    button->AddData("Appertain", aAppertain);
    button->AddData("Type", aType);
    button->setChecked(aChecked);
    connect(button, &QPushButton::clicked, this, &FormAchievements::buttonCompareAllFriendsReach_Clicked);
    return button;
}

void FormAchievements::progressLoading(int aProgress, int aRow) {
    //qDebug()<<"Loading..."<<a_progress;
}

void FormAchievements::onTablePulled(int reached, int notReached) {
    showCategories();
    if ((reached > 0) || (notReached > 0)) {
        ui->FrameFilter->setEnabled(true);
        ui->LabelTotalPersent->setText(QString("%1/%2 (%3%)").arg(
                                           QString::number(reached),
                                           QString::number(reached + notReached),
                                           QString::number(100.0 * reached / (reached + notReached))));
        _filterMyProfile->update();
    }
}
#define InitEnd }

#define SimpleCompare {
void FormAchievements::setFormMode(FormMode aMode) {
    switch (aMode) {
    case FormMode::standart: {
        ui->FrameReachedFilter->setVisible(true);
        _tableAchievements->setType(TableType::standart);
        ui->CheckBoxCompareAllFriends->setVisible(false);
        ui->TableWidgetFriends->setVisible(false);
        ui->ButtonAddCategory->setEnabled(true);
        ui->ButtonChangeCategory->setEnabled(true);
        ui->ButtonDeleteAllCategories->setEnabled(true);
        ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
        _currentMode = FormMode::standart;
        resizeForm();
        break;
    }
    case FormMode::compare: {
        ui->FrameReachedFilter->setVisible(false);
        _tableAchievements->setType(TableType::compare);
        ui->CheckBoxCompareAllFriends->setVisible(true);
        ui->TableWidgetFriends->setVisible(true);
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(false);
        ui->ButtonCompare->setText(tr("Обратно"));
        switch (_loadCompare) {
        case 0: {
            ui->TableWidgetFriends->setVisible(false);
            loadingCompare();
            break;
        }
        case 1: {
            ui->TableWidgetFriends->setVisible(true);
            break;
        }
        default: {
            ui->TableWidgetFriends->setVisible(true);
        }
        }
        _currentMode = FormMode::compare;
        resizeForm();
        break;
    }
    }
}

void FormAchievements::loadingCompare() {
    _loadCompare++;

    _profilesFriends = SFriends(_profile._steamID, false).getProfiles();
    ui->TableWidgetFriends->setColumnCount(_profilesFriends.getCount() + 2);
    for (int i = 0; i < _profilesFriends.getCount() + 2; i++) {
        ui->TableWidgetFriends->setColumnWidth(i, 33 + 8);
    }
    _profilesFriends.sort();
    ui->ProgressBarFriendsLoad->setMaximum(_profilesFriends.getCount());
    ui->ProgressBarFriendsLoad->setValue(0);
    ui->ProgressBarFriendsLoad->setVisible(true);

    int index = 0;
    for(auto &profileFriend: _profilesFriends) {
        SGames *gamesFriend = new SGames(this);
        gamesFriend->_index = index++;
        gamesFriend->set(profileFriend._steamID, true, true, true);
        connect(gamesFriend, SIGNAL(s_finished(SGames*)), this, SLOT(loadFriendGames(SGames*)));
    }
}

void FormAchievements::loadFriendGames(SGames *aGames) {
    disconnect(aGames, SIGNAL(s_finished(SGames*)), this, SLOT(loadFriendGames(SGames*)));
    bool isGameExist = false;
    for (const auto &game: *aGames) {
        if (game._appID == _game._appID) {
            isGameExist = true;
            break;
        }
    }
    QPair<SProfile, FriendType> friendState;
    friendState.first = _profilesFriends[aGames->_index];
    if (isGameExist) {
        friendState.second = FriendType::haveGame;
        _type1++;
    } else {
        friendState.second = FriendType::haventGame;
        _type2++;
    }
    _friends.push_back(std::move(friendState));
    ui->ProgressBarFriendsLoad->setValue(ui->ProgressBarFriendsLoad->value() + 1);
    if(ui->ProgressBarFriendsLoad->value() == _profilesFriends.getCount()) {
        finishLoadFriends();
    }
}

void FormAchievements::finishLoadFriends() {
    ui->ProgressBarFriendsLoad->setVisible(false);
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
        row++;
    }
    connect(ui->TableWidgetFriends, &QTableWidget::cellChanged, this, &FormAchievements::tableWidgetCompareFriends_CellChanged);
    _loadCompare++;
    ui->TableWidgetFriends->setVisible(_currentMode == FormMode::compare);
}

void FormAchievements::compareProfileFilterClickFriends(QString aName, ReachedType aType) {
    QLabel *friendAvatar = dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(0, aName.toInt()));
    if (friendAvatar) {
        QString name = friendAvatar->toolTip();
        _tableAchievements->updateFilterWithFriend(name, aType);
    } else {
        qDebug()<<"error FormAchievements::compareProfileFilterClickFriends(" + aName + ", "/*+QVariant::fromValue(aType).toString()+*/")";
    }
}

void FormAchievements::buttonCompareAllFriendsReach_Clicked() {
    QButtonWithData *senderButton = dynamic_cast<QButtonWithData*>(sender());
    if (senderButton) {
        ReachedType setType = ReachedType::none;
        if(senderButton->GetData(1) == "All") {
            setType = ReachedType::all;
        } else if (senderButton->GetData(1) == "Reached") {
            setType = ReachedType::reached;
        } else if (senderButton->GetData(1) == "NotReached") {
            setType = ReachedType::notReached;
        }
        for (int i = 2; i < ui->TableWidgetFriends->columnCount(); i++) {
            FormCompareProfileFilter *friendFilter = findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend" + QString::number(i));
            if (friendFilter) {
                friendFilter->setType(setType);
            } else {
                //qDebug()<<"error FormAchievements::buttonCompareAllFriendsReach_Clicked() filterFriend";
            }
        }
    } else {
        qDebug()<<"error FormAchievements::buttonCompareAllFriendsReach_Clicked() sender";
    }
}

void FormAchievements::tableWidgetCompareFriends_CellChanged(int aRow, int aColumn) {
    if ((aRow == 1) && (aColumn > 1)) {
        SProfile profileFriend = _friends[aColumn - 2].first;
        if (ui->TableWidgetFriends->item(aRow, aColumn)->checkState() == Qt::Checked) {
            if (_tableAchievements->addFriendColumn(profileFriend)) {
                createCompareProfileFilter(true, aColumn);
            }
        } else {
            _tableAchievements->removeFriendColumn(profileFriend._personaName);
            FormCompareProfileFilter *friendFilter = findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend" + QString::number(aColumn));
            if (friendFilter) {
                disconnect(friendFilter, &FormCompareProfileFilter::s_radioButtonChange, this, &FormAchievements::compareProfileFilterClickFriends);
                ui->TableWidgetFriends->removeCellWidget(c_tableFriendsRowFilters, aColumn);
                delete friendFilter;
                //ui->TableWidgetFriends->resizeColumnsToContents();
            } else {
                qDebug()<<"error FormAchievements::tableWidgetCompareFriends_CellChanged(" + QString::number(aRow) + ", " + QString::number(aColumn) + ") friendFilter";
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
        for (int i = 0; i < _friends.size(); i++) {
            if(_friends[i].second == FriendType::haventGame) {
                ui->TableWidgetFriends->setColumnHidden(i + 2, true);
            }
        }
        break;
    }
    case 2: {
        for (int i = 0; i < _friends.size(); i++) {
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

void FormAchievements::closeEvent(QCloseEvent*) {
    emit s_returnToGames(_unicNum);
    this->deleteLater();
}

void FormAchievements::changeEvent(QEvent *event) {
    if (event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormAchievements::resizeEvent(QResizeEvent*) {
    resizeForm();
}

void FormAchievements::resizeForm() {
    int height = 0;
    switch(_currentMode) {
    case FormMode::standart: {
        break;
    }
    case FormMode::compare: {
        ui->TableWidgetFriends->setGeometry(0, height, ui->FrameContainer->width(), 210);
        height += 210;
        break;
    }
    }
    ui->FrameHideColumns->setGeometry(QRect(0, height, ui->FrameContainer->width(), 19 + 18));
    height += 19 + 18;
    _tableAchievements->setGeometry(0, height, ui->FrameContainer->width(), ui->FrameContainer->height() - height);

#define categories {
    int heighCategories = 0;
    for (auto item: ui->ScrollAreaCategories->findChildren<QComboBoxWithData*>()) {
        heighCategories += item->sizeHint().height() + 6;
    }
    ui->ScrollAreaCategories->setFixedHeight(9 + heighCategories + 9 + 14);

    heighCategories = 0;
    for (auto item: ui->ScrollAreaCheckCategories->findChildren<QCheckBoxWithData*>()) {
        heighCategories += item->sizeHint().height() + 6;
    }
    ui->ScrollAreaCheckCategories->setFixedHeight(9 + heighCategories + 9);

    heighCategories = 9 + ui->LayoutCategoriesSettings->sizeHint().height() + 6 + ui->ScrollAreaCheckCategories->height() + 6 + ui->ScrollAreaCategories->height() + 9;

    if (ui->CheckBoxShowCategories->isChecked()) {
        ui->FrameCategories->setGeometry(0, 0, c_categoriesWidth, heighCategories);
    } else {
        ui->FrameCategories->setGeometry(-c_categoriesWidth, 0, c_categoriesWidth, heighCategories);
    }
#define categoriesEnd }

#define editCategories {
    switch (_typeCategory) {
    case CategoryType::none: {
        ui->FrameEditCategory->setGeometry(ui->FrameContainer->width(), 0, c_CategoriesEditWidth, c_CategoriesEditHeight);
        break;
    }
    case CategoryType::add: {

    }
    case CategoryType::change: {
        ui->FrameEditCategory->setGeometry(ui->FrameContainer->width() - c_CategoriesEditWidth - 16, 0, c_CategoriesEditWidth, c_CategoriesEditHeight);
        break;
    }
    }
#define editCategoriesEnd }
}

QString FormAchievements::getProfileId() {
    return _profile._steamID;
}

int FormAchievements::getGameAppId() {
    return _game._appID;
}

void FormAchievements::showCategories() {
    _categoriesGame.update();
    QFormLayout *layoutComboBox = ui->layoutComboBoxCategories;
    QFormLayout *layoutCheckBox = ui->layoutCheckBoxCategories;
    while (ui->ComboBoxCategories->count() > 1) {
        ui->ComboBoxCategories->removeItem(1);
    }
    QList<QComboBoxWithData*> allComboBoxes = ui->ScrollAreaCategories->findChildren<QComboBoxWithData*>();
    QList<QCheckBoxWithData*> allCheckBoxes = ui->ScrollAreaCheckCategories->findChildren<QCheckBoxWithData*>();
    for (int i = 0; i < _categoriesGame.getCount(); i++) {
        if (_categoriesGame.getIsNoValues(i)) {
            bool accept = false;
            for (QCheckBoxWithData *currentCheckBox: allCheckBoxes) {
                if (currentCheckBox->text() == _categoriesGame.getTitle(i)) {
                    allCheckBoxes.removeOne(currentCheckBox);
                    accept = true;
                    break;
                }
            }
            if(!accept) {
                //Создать новый чекбокс
                QCheckBoxWithData *checkBoxCategoryNew = new QCheckBoxWithData(_categoriesGame.getTitle(i), this);
                checkBoxCategoryNew->setObjectName("CheckBoxCategory" + QString::number(i));
                checkBoxCategoryNew->AddData("NumberCategory", QString::number(i));
                connect(checkBoxCategoryNew, &QCheckBoxWithData::stateChanged, this, &FormAchievements::checkBoxCategory_StateChanged);
                layoutCheckBox->addRow(checkBoxCategoryNew);
            }
        } else {
            bool accept = false;
            for (QComboBoxWithData *currentComboBox: allComboBoxes) {
                if (currentComboBox->GetData("TitleCategory") == _categoriesGame.getTitle(i)) {
                    QList<QString> values;
                    for (int j = currentComboBox->count() - 1; j < _categoriesGame.getValues(i).size(); j++) {
                        values.push_back(std::move(_categoriesGame.getValues(i).at(j).toObject().value("Title").toString()));
                    }
                    for (int j = 1; j < currentComboBox->count(); j++) {
                        if(currentComboBox->itemText(j) != _categoriesGame.getValues(i).at(j - 1).toObject().value("Title").toString()) {
                            values.push_back(std::move(_categoriesGame.getValues(i).at(j - 1).toObject().value("Title").toString()));
                            currentComboBox->removeItem(j);
                        }
                    }
                    for(QString &item: values) {
                        currentComboBox->addItem(item);
                    }
                    allComboBoxes.removeOne(currentComboBox);
                    accept = true;
                    break;
                }
            }
            if (!accept) {
                //Создать новый комбобокс
                QComboBoxWithData *comboBoxCategoryNew = new QComboBoxWithData(this);
                comboBoxCategoryNew->addItem(tr("Не выбрано"));
                QJsonArray values = _categoriesGame.getValues(i);
                for (auto value: values) {
                    comboBoxCategoryNew->addItem(value.toObject().value("Title").toString());
                }
                comboBoxCategoryNew->setObjectName("ComboBoxCategory" + QString::number(i));
                comboBoxCategoryNew->AddData("NumberCategory", QString::number(i));
                comboBoxCategoryNew->AddData("TitleCategory", _categoriesGame.getTitle(i));
                connect(comboBoxCategoryNew, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxCategory_IndexChange(int)));
                layoutComboBox->addRow(new QLabel(_categoriesGame.getTitle(i), this), comboBoxCategoryNew);
            }
        }
        ui->ComboBoxCategories->addItem(_categoriesGame.getTitle(i));
    }

    for(QCheckBoxWithData *currentCheckBox: allCheckBoxes) {
        layoutCheckBox->removeRow(currentCheckBox);
    }
    for(QComboBoxWithData *currentComboBox: allComboBoxes) {
        layoutComboBox->removeRow(currentComboBox);
    }
    ui->ScrollAreaCategories->setHidden(layoutComboBox->rowCount() == 0);
    ui->ScrollAreaCheckCategories->setHidden(layoutCheckBox->rowCount() == 0);
    ui->ButtonChangeCategory->setEnabled(_categoriesGame.getCount() != 0);
    ui->ButtonDeleteAllCategories->setEnabled(_categoriesGame.getCount() != 0);

    _tableAchievements->updateFilterCategoriesColumns(_categoriesGame.getCount());
}

FormCategoryValue *FormAchievements::createValueCategory() {
    int rowValues = ui->ListWidgetValuesCategory->count();//->rowCount();
    FormCategoryValue *newValue = new FormCategoryValue(rowValues, ui->ListWidgetValuesCategory);
    connect(newValue, &FormCategoryValue::s_visiblechange,  this,     &FormAchievements::formCategoryValueVisibleChange);
//    connect(newValue, &FormCategoryValue::s_positionchange, this,     &FormAchievements::formCategoryPosition_Change);
//    connect(newValue, &FormCategoryValue::s_deleting,       this,     &FormAchievements::formCategoryDelete);
    connect(this    , &FormAchievements::s_updateSettings,  newValue, &FormCategoryValue::updateSettings);
    connect(newValue, &FormCategoryValue::s_valuechange,    this,     [=](int aPos, QString aValue) {
        _tableAchievements->changeHorizontalTitle((c_tableCategoryColumnNoValue + 1) + aPos, aValue);
        formCategoryListWidget_CurrentRowChanged();
    });
//    connect(newValue, &FormCategoryValue::s_selectchange,   this,     [=](int aPos, bool aSelect) {
//        _tableAchievements->setVisibleContentSelect(aPos, aSelect);
//    });
    _values.append(newValue);
    updateValueUpDown();
    QListWidgetItem *item = new QListWidgetItem(ui->ListWidgetValuesCategory);
    item->setSizeHint(newValue->sizeHint());
    ui->ListWidgetValuesCategory->setItemWidget(item, newValue);
    ui->ListWidgetValuesCategory->setCurrentRow(ui->ListWidgetValuesCategory->count() - 1);
    return newValue;
}

void FormAchievements::animateFrameEditCategories(bool toVisible) {
    QPropertyAnimation *animation = new QPropertyAnimation(ui->FrameEditCategory, "geometry");
    connect(animation, &QPropertyAnimation::finished, animation, &QPropertyAnimation::deleteLater);
    animation->setDuration(500);
    if (toVisible) {
        animation->setStartValue(QRect(ui->FrameContainer->width(), 0, ui->FrameEditCategory->width(), ui->FrameEditCategory->height()));
        animation->setEndValue(QRect(ui->FrameContainer->width() - ui->FrameEditCategory->width() - 16, 0, ui->FrameEditCategory->width(), ui->FrameEditCategory->height()));
    } else {
        animation->setStartValue(QRect(ui->FrameContainer->width() - ui->FrameEditCategory->width() - 16, 0, ui->FrameEditCategory->width(), ui->FrameEditCategory->height()));
        animation->setEndValue(QRect(ui->FrameContainer->width(), 0, ui->FrameEditCategory->width(), ui->FrameEditCategory->height()));
    }
    animation->start();
}
#define SystemEnd }

#define Filter {
void FormAchievements::buttonAddCategory_Clicked() {
    if ((_typeCategory == CategoryType::none) && (_currentMode == FormMode::standart)) {
        _typeCategory = CategoryType::add;
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
        ui->CheckBoxCategoryOneValue->setChecked(false);

        ui->ComboBoxCategories->setVisible(false);
        ui->ButtonDeleteCategory->setVisible(false);
        ui->LineEditTitleCategory->setEnabled(true);
        ui->ButtonAddValueCategory->setEnabled(true);

        //ui->GroupBoxCategories->setTitle(tr("Добавить категорию"));
        //ui->FrameEditCategory->setVisible(true);
        resizeForm();
        noSelectedValue();
        animateFrameEditCategories(true);
        _tableAchievements->addNoValueColumn();
        _tableAchievements->setVisibleColumn(_tableAchievements->getNoValueColumn(), false);
    }
}

void FormAchievements::buttonChangeCategory_Clicked() {
    if ((_typeCategory == CategoryType::none) && (_currentMode == FormMode::standart)) {
        _typeCategory = CategoryType::change;
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
        ui->CheckBoxCategoryOneValue->setChecked(false);

        ui->ComboBoxCategories->setVisible(true);
        ui->ButtonDeleteCategory->setVisible(true);
        ui->LineEditTitleCategory->setEnabled(false);
        ui->ButtonAddValueCategory->setEnabled(false);
        ui->CheckBoxCategoryOneValue->setEnabled(false);

        resizeForm();
        noSelectedValue();
        animateFrameEditCategories(true);
    }
}

void FormAchievements::buttonUpdate_Clicked() {
    _tableAchievements->update();
}

void FormAchievements::buttonCompare_Clicked() {
    switch (_currentMode) {
    case FormMode::standart: {
        setFormMode(FormMode::compare);
        break;
    }
    case FormMode::compare: {
        setFormMode(FormMode::standart);
        break;
    }
    }
}

void FormAchievements::comboBoxCategory_IndexChange(int aIndex) {
    if (_categoriesGame.getCount() > 0) {
        QComboBoxWithData *comboBox = dynamic_cast<QComboBoxWithData*>(sender());
        if (comboBox) {
            int categoryIndex = comboBox->GetData(0).toInt();
            if (aIndex != 0) {
                QList<QString> achievementsName = _categoriesGame.getValues(categoryIndex, aIndex - 1);
                _tableAchievements->updateFilterCategory(categoryIndex, false, achievementsName);
            } else {
                _tableAchievements->updateFilterCategory(categoryIndex, true);
            }
        } else {
            qDebug()<<"error FormAchievements::comboBoxCategory_IndexChange(" + QString::number(aIndex) + ") comboBox";
        }
    }
}

void FormAchievements::checkBoxCategory_StateChanged(int aIndex) {
    if (_categoriesGame.getCount() > 0) {
        QCheckBoxWithData *checkBox = dynamic_cast<QCheckBoxWithData*>(sender());
        if (checkBox) {
            int categoryIndex = checkBox->GetData(0).toInt();
            if (aIndex != 0) {
                QList<QString> achievementsName = _categoriesGame.getNoValues(categoryIndex);
                _tableAchievements->updateFilterCategory(categoryIndex, false, achievementsName);
            } else {
                _tableAchievements->updateFilterCategory(categoryIndex, true);
            }
        } else {
            qDebug()<<"error FormAchievements::checkBoxCategory_IndexChange(" + QString::number(aIndex) + ") checkBox";
        }
    }
}

void FormAchievements::buttonDeleteAllCategories_Clicked() {
    QMessageBox deleteQuestion(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите удалить все категории?"));
    QAbstractButton *btnYes = deleteQuestion.addButton(tr("Да"), QMessageBox::YesRole);
    deleteQuestion.addButton(tr("Отмена"), QMessageBox::NoRole);
    deleteQuestion.exec();
    if(deleteQuestion.clickedButton() == btnYes) {
        QMessageBox deleteSecondQuestion(QMessageBox::Question,
                               tr("Внимание!"),
                               tr("Данные о категориях будут утеряны навсегда, вы точно хотите удалить все категории?"));
        QAbstractButton *btnYess = deleteSecondQuestion.addButton(tr("Да"), QMessageBox::YesRole);
        deleteSecondQuestion.addButton(tr("Отмена"), QMessageBox::NoRole);
        deleteSecondQuestion.exec();
        if (deleteSecondQuestion.clickedButton() == btnYess) {
            _categoriesGame.deleteAll();
            showCategories();
        }
    }
}

#define Categorys {
void FormAchievements::buttonAddValueCategory_Clicked() {
    if ((_tableAchievements->getType() == TableType::standart) && ((_typeCategory == CategoryType::add) || (_typeCategory == CategoryType::change))) {
        _tableAchievements->addCategoryColumn();
        createValueCategory();
    }
}

void FormAchievements::buttonCancelCategory_Clicked() {
    if ((_typeCategory == CategoryType::add) || (_typeCategory == CategoryType::change)) {
        resizeForm();
        animateFrameEditCategories(false);
        ui->ButtonAddCategory->setEnabled(true);
        ui->ButtonCompare->setEnabled(true);
        ui->ButtonChangeCategory->setEnabled(_categoriesGame.getCount() != 0);
        ui->ButtonDeleteAllCategories->setEnabled(_categoriesGame.getCount() != 0);
        ui->ListWidgetValuesCategory->clear();
        ui->LineEditTitleCategory->setText("");
        ui->ComboBoxCategories->setCurrentIndex(0);
        _typeCategory = CategoryType::none;
        while(!_values.isEmpty()) {
            _values.removeAt(0);
        }
        _tableAchievements->cancelCategory();
        ui->CheckBoxCategoryOneValue->setChecked(false);
    }
}

void FormAchievements::buttonAcceptCategory_Clicked() {
    if (_typeCategory == CategoryType::add || _typeCategory == CategoryType::change) {
        if (ui->LineEditTitleCategory->text() != "") {
            int targetCategory = -1;
            if (_typeCategory == CategoryType::change) {
                targetCategory = ui->ComboBoxCategories->currentIndex() - 1;
            } else {
                targetCategory = _categoriesGame.getCount();
            }

            QList<QString> titles = _categoriesGame.getTitles();
            bool isUniqueTitle = true;
            for (int i = 0; i < titles.size(); i++) {
                if((titles[i] == ui->LineEditTitleCategory->text()) && (i != ui->ComboBoxCategories->currentIndex() - 1)) {
                    isUniqueTitle = false;
                    break;
                }
            }
            if (isUniqueTitle) {
                QJsonObject categoryNew;
                categoryNew["Title"] = ui->LineEditTitleCategory->text();
                QJsonArray valuesNew;
                QJsonArray noValuesNew;
                if (ui->CheckBoxCategoryOneValue->isChecked()) {
                    categoryNew["IsNoValues"] = 1;
                } else {
                    categoryNew["IsNoValues"] = 0;
                    for (int i = c_tableCategoryColumnNoValue + 1; i < _tableAchievements->getColumnCount(); i++) {
                        if (_tableAchievements->getHeaderText(i) == "") {
                            QMessageBox::warning(this, tr("Ошибка"), tr("Название значения пустое!"));
                            return;
                        }
                        for (int j = c_tableCategoryColumnNoValue + 1; j < i; j++) {
                            if (_tableAchievements->getHeaderText(i) == _tableAchievements->getHeaderText(j)) {
                                QMessageBox::warning(this, tr("Ошибка"), tr("Название значения повторяется!"));
                                return;
                            }
                        }
                    }
                }
                for (int j = 0; j < _tableAchievements->getRowCount(); j++) {
                    if (_tableAchievements->itemContent(j, c_tableCategoryColumnNoValue)->checkState()) {
                        noValuesNew.append(std::move(_tableAchievements->itemContent(j, c_tableAchievementColumnAppid)->text()));
                    }
                }
                for(int i = c_tableCategoryColumnNoValue + 1; i < _tableAchievements->getColumnCount(); i++) {
                    QJsonObject valueNew;
                    valueNew["Title"] = _tableAchievements->getHeaderText(i);
                    QJsonArray achievementsNew;
                    for (int j = 0; j < _tableAchievements->getRowCount(); j++) {
                        if(_tableAchievements->itemContent(j, i)->checkState() == Qt::Checked) {
                            achievementsNew.append(std::move(_tableAchievements->itemContent(j, c_tableAchievementColumnAppid)->text()));
                        }
                    }
                    valueNew["Achievements"] = achievementsNew;
                    valuesNew.append(std::move(valueNew));
                }
                categoryNew["Values"] = valuesNew;
                categoryNew["NoValues"] = noValuesNew;
                _categoriesGame.changeCategory(targetCategory, categoryNew);
                ui->LineEditTitleCategory->setText("");
                ui->LineEditTitleCategory->setEnabled(false);
                delete ui->ScrollAreaCategories->layout();
                delete ui->ScrollAreaCheckCategories->layout();
                showCategories();
                ui->LineEditNameAchievements->setText("");
                _filterMyProfile->setType(ReachedType::all);
                ui->CheckBoxFavorites->setChecked(false);
                QMessageBox::information(this, tr("Успешно"), tr("Категория была %1!").arg(_typeCategory == CategoryType::add ? tr("добавлена") : tr("изменена")));
                buttonCancelCategory_Clicked();
            } else {
                QMessageBox::warning(this, tr("Ошибка"), tr("Такая категория уже есть!"));
            }
        } else {
            QMessageBox::warning(this, tr("Ошибка"), tr("Название категории пустое!"));
        }
    }
}

void FormAchievements::buttonDeleteCategory_Clicked() {
    if (_typeCategory == CategoryType::change) {
        QMessageBox::StandardButton clickedButton = QMessageBox::question(this, tr("Внимание"), tr("Вы уверены, что хотите удалить категорию?"), QMessageBox::Yes | QMessageBox::No);
        if (clickedButton == QMessageBox::No) {
            return;
        }
        if (ui->ComboBoxCategories->currentIndex() != 0) {
            _categoriesGame.deleteCategory(ui->ComboBoxCategories->currentIndex() - 1);
            showCategories();
            ui->LineEditNameAchievements->setText("");
            _filterMyProfile->setType(ReachedType::all);
            ui->CheckBoxFavorites->setChecked(false);
            QMessageBox::information(this, tr("Успешно"), tr("Категория была удалена!"));
            buttonCancelCategory_Clicked();
        }
    }
}

void FormAchievements::checkBoxCategoryOneValue_StateChanged(int arg1) {
    if (_typeCategory == CategoryType::add || _typeCategory == CategoryType::change) {
        bool value = arg1 == 2;
        ui->ButtonAddValueCategory->setEnabled(!value);
        ui->ListWidgetValuesCategory->setEnabled(!value);
        _tableAchievements->setValuesMode(!value);
    }
}

void FormAchievements::lineEditTitleCategory_TextChanged(const QString &arg1) {
    if (_tableAchievements->getColumnCount() > c_tableCategoryColumnNoValue) {
        _tableAchievements->changeHorizontalTitle(c_tableCategoryColumnNoValue, arg1);
    }
}

void FormAchievements::comboBoxCategories_Activated(int aIndex) {
    if (_typeCategory == CategoryType::change) {
        if (_categoriesGame.getCount() > 0) {
            ui->LineEditTitleCategory->setText(ui->ComboBoxCategories->itemText(aIndex));
            ui->ListWidgetValuesCategory->clear();
            if (aIndex > 0) {
                ui->ButtonAddValueCategory->setEnabled(true);
                ui->CheckBoxCategoryOneValue->setEnabled(true);
                ui->LineEditTitleCategory->setEnabled(true);
                QList<QString> noValues = _categoriesGame.getNoValues(aIndex - 1);
                QJsonArray valuesTitles = _categoriesGame.getValues(aIndex - 1);
                _tableAchievements->categoryToTable(_categoriesGame.getTitle(aIndex - 1), noValues, valuesTitles, _categoriesGame.getIsNoValues(aIndex - 1));
                ui->CheckBoxCategoryOneValue->setChecked(_categoriesGame.getIsNoValues(aIndex - 1));

                while(!_values.isEmpty()) {
                    _values.removeAt(0);
                }
                for(auto title: valuesTitles) {
                    FormCategoryValue *value = createValueCategory();
                    value->setTitle(title.toObject().value("Title").toString());
                }
            } else {
                _tableAchievements->setType(TableType::compare);
                _tableAchievements->setType(TableType::standart);
                ui->ButtonAddValueCategory->setEnabled(false);
                ui->CheckBoxCategoryOneValue->setEnabled(false);
            }
        }
    }
}

void FormAchievements::checkBoxCategoryVisibleAll_Clicked() {
    bool check = ui->CheckBoxCategoryVisibleAll->isChecked();
    for (auto &value: _values) {
        value->setColumnVisible(check);
    }
}

void FormAchievements::updateValuesUpDown(int aValue) {
    if (aValue == -1) {
        for (int i = 0; i < _values.size(); i++) {
            switch (i) {
            case 0: {
                _values[i]->setEnabledUpDown(_values.size() == 0 ? EnabledUpDown::none : EnabledUpDown::down);
                break;
            }
            default: {
                _values[i]->setEnabledUpDown(_values.size() - 1 == i ? EnabledUpDown::up : EnabledUpDown::both);
            }
            }
        }
    } else {
        switch (aValue) {
        case 0: {
            _values[aValue]->setEnabledUpDown(_values.size() == 0 ? EnabledUpDown::none : EnabledUpDown::down);
            break;
        }
        default: {
            _values[aValue]->setEnabledUpDown(_values.size() - 1 == aValue ? EnabledUpDown::up : EnabledUpDown::both);
        }
        }
    }
}

#define CategorysValues {
void FormAchievements::noSelectedValue() {
    ui->LabelValueTitle->setText("");
    updateValueUpDown();
    ui->ButtonCategoryValueReverse->setEnabled(false);
    ui->ButtonCategoryValueCheckVisible->setEnabled(false);
    ui->ButtonCategoryValueUncheckVisible->setEnabled(false);
    ui->ButtonCategoryValueDelete->setEnabled(false);
}

void FormAchievements::updateValueUpDown() {
    ui->ButtonCategoryValueTop->setEnabled(false);
    ui->ButtonCategoryValueUp->setEnabled(false);
    ui->ButtonCategoryValueDown->setEnabled(false);
    ui->ButtonCategoryValueBottom->setEnabled(false);
}

void FormAchievements::formCategoryListWidget_CurrentRowChanged() {
    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
    //int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

    FormCategoryValue *value = dynamic_cast<FormCategoryValue*>(ui->ListWidgetValuesCategory->itemWidget(currentItem));
    if (value) {
        ui->LabelValueTitle->setText(value->getTitle());
        ui->ButtonCategoryValueReverse->setEnabled(true);
        ui->ButtonCategoryValueCheckVisible->setEnabled(true);
        ui->ButtonCategoryValueUncheckVisible->setEnabled(true);
        ui->ButtonCategoryValueDelete->setEnabled(true);
    }
}

void FormAchievements::formCategoryValueVisibleChange(int aPos, bool aVisible) {
    bool isAllVisible = true;
    int currentRow = ui->ListWidgetValuesCategory->currentRow();
    for (int i = 0; i < ui->ListWidgetValuesCategory->count(); i++) {
        FormCategoryValue *value = dynamic_cast<FormCategoryValue*>(ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(i)));
        if (value) {
            if (!value->getVisible()) {
                isAllVisible = false;
                break;
            }
        } else {
            qDebug()<<"FormAchievements::formCategoryValueVisibleChange error";
        }
    }
    ui->ListWidgetValuesCategory->setCurrentRow(currentRow);
    ui->CheckBoxCategoryVisibleAll->setChecked(isAllVisible);
    _tableAchievements->setVisibleColumn((c_tableCategoryColumnNoValue + 1) + aPos, aVisible);
}

void FormAchievements::formCategoryValueReverse() {
    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
    int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

    _tableAchievements->reverseCategoryColumn(currentIndex);
}

void FormAchievements::formCategoryValueTop() {
    if (ui->ListWidgetValuesCategory->count() > 0) {
        int currentIndex = ui->ListWidgetValuesCategory->currentRow();
        if(currentIndex == 0) {
            return;
        } else {
            if (_tableAchievements->swapCategoryColumns(currentIndex, 0)) {
                QWidget *widget = ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(currentIndex));
//TODO Сделать нормальное перемещение
                //widget->setParent(nullptr);
                ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(currentIndex), ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(0)));
                ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(currentIndex), widget);
//                ui->ListWidgetValuesCategory->removeItemWidget(ui->ListWidgetValuesCategory->item(currentIndex));
//                QWidget *widget2 = ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(0));
//                ui->ListWidgetValuesCategory->removeItemWidget(ui->ListWidgetValuesCategory->item(0));
//                ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(0), widget1);
//                ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(currentIndex), widget2);
                //ui->ListWidgetValuesCategory->removeItemWidget(ui->ListWidgetValuesCategory->item(currentIndex));
                //QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->takeItem(currentIndex);
                //ui->ListWidgetValuesCategory->insertItem(0, currentItem);
                //ui->ListWidgetValuesCategory->setItemWidget(currentItem, widget);
                ui->ListWidgetValuesCategory->setCurrentRow(0);

                FormCategoryValue *value = dynamic_cast<FormCategoryValue*>(ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(currentIndex)));
                if (value) {
                    value->setPosition(0);
                }
            }
        }
    }
}

void FormAchievements::formCategoryValueUp() {
    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
    int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

    if(currentIndex == 0) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("Невозможно переместить значение"));
    } else {
        QListWidgetItem *prev = ui->ListWidgetValuesCategory->item(ui->ListWidgetValuesCategory->row(currentItem) - 1);
        int prevIndex = ui->ListWidgetValuesCategory->row(prev);

        QListWidgetItem *temp = ui->ListWidgetValuesCategory->takeItem(prevIndex);
        ui->ListWidgetValuesCategory->insertItem(prevIndex, currentItem);
        ui->ListWidgetValuesCategory->insertItem(currentIndex, temp);
        ui->ListWidgetValuesCategory->setCurrentRow(currentIndex - 1);

        FormCategoryValue *value = dynamic_cast<FormCategoryValue*>(ui->ListWidgetValuesCategory->itemWidget(currentItem));
        if (value) {
            value->setPosition(currentIndex - 1);
        }
    }
}

void FormAchievements::formCategoryValueDown() {
    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
    int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

    if(currentIndex >= ui->ListWidgetValuesCategory->count() - 1) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("Невозможно переместить значение"));
    } else {
        QListWidgetItem *next = ui->ListWidgetValuesCategory->item(ui->ListWidgetValuesCategory->row(currentItem) + 1);
        int nextIndex = ui->ListWidgetValuesCategory->row(next);

        QListWidgetItem *temp = ui->ListWidgetValuesCategory->takeItem(nextIndex);
        ui->ListWidgetValuesCategory->insertItem(currentIndex, temp);
        ui->ListWidgetValuesCategory->insertItem(nextIndex, currentItem);
        ui->ListWidgetValuesCategory->setCurrentRow(currentIndex + 1);

        FormCategoryValue *value = dynamic_cast<FormCategoryValue*>(ui->ListWidgetValuesCategory->itemWidget(currentItem));
        if (value) {
            value->setPosition(currentIndex + 1);
        }
    }
}

void FormAchievements::formCategoryValueBottom() {
    if (ui->ListWidgetValuesCategory->count() > 0) {
        int currentIndex = ui->ListWidgetValuesCategory->currentRow();
        if(currentIndex == ui->ListWidgetValuesCategory->count() - 1) {
            return;
        } else {
            QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->takeItem(currentIndex);
            ui->ListWidgetValuesCategory->insertItem(ui->ListWidgetValuesCategory->count(), currentItem);
            ui->ListWidgetValuesCategory->setCurrentRow(ui->ListWidgetValuesCategory->count() - 1);

            FormCategoryValue *value = dynamic_cast<FormCategoryValue*>(ui->ListWidgetValuesCategory->itemWidget(currentItem));
            if (value) {
                value->setPosition(ui->ListWidgetValuesCategory->count() - 1);
            }
        }
    }
}

void FormAchievements::formCategoryValueSelectVisible() {
    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
    int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

    _tableAchievements->setVisibleContentSelect(currentIndex, true);
}

void FormAchievements::formCategoryValueUnselectVisible() {
    QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
    int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);

    _tableAchievements->setVisibleContentSelect(currentIndex, false);
}

void FormAchievements::formCategoryValueDelete() {
    if (ui->ListWidgetValuesCategory->count() > 0) {
        QListWidgetItem *currentItem = ui->ListWidgetValuesCategory->currentItem();
        int currentIndex = ui->ListWidgetValuesCategory->row(currentItem);
        _tableAchievements->removeCategoryColumn(currentIndex);

        if (ui->ListWidgetValuesCategory->count() == 1) {
            if (QListWidgetItem *item = ui->ListWidgetValuesCategory->takeItem(currentIndex)) {
                delete item;
            }
            noSelectedValue();
        } else {
            if (currentIndex == 0) {
                if (QListWidgetItem *item = ui->ListWidgetValuesCategory->takeItem(currentIndex)) {
                    delete item;
                }
                ui->ListWidgetValuesCategory->setCurrentRow(0);
            } else {
                if (QListWidgetItem *item = ui->ListWidgetValuesCategory->takeItem(currentIndex)) {
                    delete item;
                }
                ui->ListWidgetValuesCategory->setCurrentRow(currentIndex - 1);
            }
        }
    }
    updateValueUpDown();
}

void FormAchievements::formCategoryPosition_Change(int aPosOld, int aPosNew) {
    if(aPosNew < 0 || aPosNew > _tableAchievements->getColumnCount() - (c_tableCategoryColumnNoValue + 1)) {
        QMessageBox::warning(this, "Ошибка!", tr("Невозможно переместить значение"));
    } else {
        if (_tableAchievements->swapCategoryColumns(aPosOld, aPosNew)) {
            std::swap(_values[aPosOld], _values[aPosNew]);
            for (int i = 0; i < _values.size(); i++) {
                _values[i]->setPosition(i);
                updateValuesUpDown(i);
            }
//            ui->ListWidgetValuesCategory->blockSignals(true);
//            ui->ListWidgetValuesCategory->clear();
//            ui->ListWidgetValuesCategory->blockSignals(false);
            qDebug()<<aPosOld<<aPosNew;
            QListWidgetItem *oldPosItem = ui->ListWidgetValuesCategory->takeItem(aPosOld);
            ui->ListWidgetValuesCategory->insertItem(aPosNew, oldPosItem);
            qDebug()<<111;
            //QListWidgetItem *newPosItem = ui->ListWidgetValuesCategory->item(aPosNew);
            //int newIndex = ui->ListWidgetValuesCategory->row(newPosItem);
            //QListWidgetItem *temp = ui->ListWidgetValuesCategory->takeItem(newIndex);
            //ui->ListWidgetValuesCategory->insertItem(aPosOld, newPosItem);
            //ui->ListWidgetValuesCategory->insertItem(aPosNew, oldPosItem);
            //QWidget *item1 = ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(aPosOld));
            //QWidget *item2 = ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(aPosNew));
            //ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(aPosOld), item2);
            //ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(aPosNew), item1);
//исправить!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //обновить данные на ListWidget
        }
    }
}

void FormAchievements::formCategoryDelete(int aPos) {
    _tableAchievements->removeCategoryColumn(aPos);
    QListWidgetItem* item = ui->ListWidgetValuesCategory->item(aPos);
    ui->ListWidgetValuesCategory->removeItemWidget(item);
    delete item;
    _values.removeAt(aPos);
    int pos = 0;
    for (auto &value: _values) {
        value->setPosition(pos);
        if (_values.size() == 1) {
            value->setEnabledUpDown(EnabledUpDown::none);
        } else if(_values.size() - 1 == pos) {
            value->setEnabledUpDown(EnabledUpDown::up);
        } else if(pos == 0) {
            value->setEnabledUpDown(EnabledUpDown::down);
        } else {
            value->setEnabledUpDown(EnabledUpDown::both);
        }
        pos++;
    }
}
#define CategoryValuesEnd }
#define CategoryEnd }
#define FilterEnd }

#define Function {
void FormAchievements::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        _tableAchievements->updateFilterFavorite(QJsonArray());
        break;
    }
    case 2: {
        QJsonObject gameObject;
        gameObject["id"] = _game._appID;
        gameObject["name"] = _game._name;
        QJsonArray values = _favorites.getValues(gameObject);
        _tableAchievements->updateFilterFavorite(values);
        break;
    }
    }
}

void FormAchievements::buttonFavorite_Clicked() {
    if (_currentAchievementIndex > -1) {
        SAchievement achievement = _tableAchievements->getAchievement(_currentAchievementIndex);

        QJsonObject gameObject;
        QJsonObject newValue;
        gameObject["id"] = _game._appID;
        gameObject["name"] = _game._name;
        newValue["id"] = achievement._apiName;
        newValue["title"] = achievement._displayName;
        newValue["description"] = achievement._description;
        QString iconsColor = _setting.getIconsColor();
        if (_favorites.addValue(gameObject, newValue, true)) {
            //Категория добавилась
            ui->ButtonFavorite->setIcon(QIcon(_setting.getIconIsFavorites()));
        } else {
            //Категория уже есть (удалилась)
            ui->ButtonFavorite->setIcon(QIcon(_setting.getIconIsNotFavorites()));
        }
    }
}
#define FunctionEnd }

void FormAchievements::tableAchievements_CellClicked(int row, int) {
    _currentAchievement = _tableAchievements->itemContent(row, c_tableAchievementColumnAppid)->text();
    _currentAchievementIndex = row;
    QJsonObject gameObject;
    gameObject["id"] = _game._appID;
    gameObject["name"] = _game._name;
    QJsonArray favorites = _favorites.getValues(gameObject);
    bool isFavorite = false;
    for (auto favorite: favorites) {
        if (favorite.toObject().value("id").toString() == _currentAchievement) {
            isFavorite = true;
            break;
        }
    }
    QString iconsColor = _setting.getIconsColor();
    if (isFavorite) {
        ui->ButtonFavorite->setIcon(QIcon(_setting.getIconIsFavorites()));
    } else {
        ui->ButtonFavorite->setIcon(QIcon(_setting.getIconIsNotFavorites()));
    }
}

void FormAchievements::buttonManual_Clicked() {
    QDesktopServices::openUrl(QUrl("https://steamcommunity.com/app/" + QString::number(_game._appID) + "/guides/"));
    //https://steamcommunity.com/app/218620/guides/
}
