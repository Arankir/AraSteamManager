#include "formfriendscompare.h"
#include "ui_formfriendscompare.h"

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

//в ретранслейте
//ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars, 1)->setToolTip(tr("Достижения друзей"));

FormFriendsCompare::FormFriendsCompare(QWidget *parent): QWidget(parent), ui(new Ui::FormFriendsCompare) {
    ui->setupUi(this);

    QLabel *allFriends = new QLabel("All", this);
    allFriends->setToolTip(tr("Достижения друзей"));
    allFriends->setScaledContents(true);
    allFriends->setFixedSize(32, 32);

    QLabel *avatarFriendsCompare = new QLabel(this);
    avatarFriendsCompare->setAlignment(Qt::AlignCenter);
    avatarFriendsCompare->setToolTip(_profile._personaName);
    avatarFriendsCompare->setPixmap(_profile.getPixmapAvatar());

    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setMinimumSize(0, 210);
    ui->TableWidgetFriends->setColumnCount(2);
    ui->TableWidgetFriends->setRowCount(c_tableFriendsRowCount);
    ui->TableWidgetFriends->setRowHidden(c_tableFriendsRowID, true);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars, 0, avatarFriendsCompare);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars, 1, allFriends);

    FormCompareProfileFilter *myFilter = new FormCompareProfileFilter(this);
    myFilter->setObjectName("FormCompareProfileFilterMy");
    connect(myFilter, &FormCompareProfileFilter::s_radioButtonChange, this, [=](QString, ReachedType aType) {
//        updateFilterWithMyProfile(aType, false, true);
    });

    QWidget *widgetFriendsAchievementsFilter = new QWidget(this);
    QHBoxLayout *lFriendsAchievementsFilter = new QHBoxLayout(widgetFriendsAchievementsFilter);
    lFriendsAchievementsFilter->setMargin(1);
    lFriendsAchievementsFilter->setAlignment(Qt::AlignCenter);
    lFriendsAchievementsFilter->addWidget(createButtonWithData("PBFriendsAll",        "Friends", "All",        true));
    lFriendsAchievementsFilter->addWidget(createButtonWithData("PBFriendsReached",    "Friends", "Reached",    false));
    lFriendsAchievementsFilter->addWidget(createButtonWithData("PBFriendsNotReached", "Friends", "NotReached", false));
    //widgetFriendsAchievementsFilter->setLayout(layoutFriendsAchievementsFilter);

    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, 0, myFilter);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, 1, widgetFriendsAchievementsFilter);
    ui->TableWidgetFriends->resizeRowsToContents();
    for (int i = 0; i < ui->TableWidgetFriends->rowCount(); ++i) {
        ui->TableWidgetFriends->setRowHeight(i, ui->TableWidgetFriends->rowHeight(i) + 18);
    }
    ui->TableWidgetFriends->setRowHeight(c_tableFriendsRowCheckBox, 30);
    ui->TableWidgetFriends->resizeColumnsToContents();
//    setIcons();
    #define Connects {
    connect(ui->CheckBoxCompareIcon,                &QCheckBox::stateChanged,   ui->TableViewCompare,  [=](int arg1) {
        ui->TableViewCompare->setColumnHidden(c_columnIcon, arg1 == 0);
    });
    connect(ui->CheckBoxCompareTitle,               &QCheckBox::stateChanged,   ui->TableViewCompare,  [=](int arg1) {
        ui->TableViewCompare->setColumnHidden(c_columnTitle, arg1 == 0);
    });
    connect(ui->CheckBoxCompareDescription,         &QCheckBox::stateChanged,   ui->TableViewCompare,  [=](int arg1) {
        ui->TableViewCompare->setColumnHidden(c_columnDescription, arg1 == 0);
    });
    connect(ui->CheckBoxCompareTotalPercent,        &QCheckBox::stateChanged,   ui->TableViewCompare,  [=](int arg1) {
        ui->TableViewCompare->setColumnHidden(c_columnWorld, arg1 == 0);
    });
    #define ConnectsEnd }
}

FormFriendsCompare::~FormFriendsCompare() {
    delete ui;
}

void FormFriendsCompare::setFriends(const SFriends &steamFriends) {
    _profilesFriends = steamFriends.getProfiles();
    loadingCompare();
}

void FormFriendsCompare::setInitData(SProfile &profile, SGame &game) {
    _profile = profile;
    _game = game;
    loadingCompare();
}

QButtonWithData *FormFriendsCompare::createButtonWithData(const QString &aObjectName, const QString &aAppertain, const QString &aType, bool aChecked) {
    QButtonWithData *button = new QButtonWithData("", this);
    button->setObjectName(aObjectName);
    button->addData("Appertain", aAppertain);
    button->addData("Type", aType);
    button->setChecked(aChecked);
//    connect(button, &QPushButton::clicked, this, &FormAchievementsFriendsCompare::buttonCompareAllFriendsReach_Clicked);
    return button;
}

void FormFriendsCompare::setIcons() {
    QLabel *friendsIcon = dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars, 1));
    if (friendsIcon) {
        friendsIcon->setPixmap(QPixmap(Images::friends()));
    }
    QWidget *wFriendsFilter = dynamic_cast<QWidget*>(ui->TableWidgetFriends->cellWidget(c_tableFriendsRowFilters, 1));
    if (wFriendsFilter) {
        QButtonWithData *bFriendsAll = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(0)->widget());
        if (bFriendsAll) {
            bFriendsAll->setIcon(QIcon(Images::allAchievements()));
        } else {
            qWarning() << "not init bFriendsAll";
        }
        QButtonWithData *bFriendsReached = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(1)->widget());
        if (bFriendsReached) {
            bFriendsReached->setIcon(QIcon(Images::reached()));
        } else {
            qWarning() << "not init bFriendsReached";
        }
        QButtonWithData *bFriendsNotReached = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(2)->widget());
        if (bFriendsNotReached) {
            bFriendsNotReached->setIcon(QIcon(Images::notReached()));
        } else {
            qWarning() << "not init bFriendsNotReached";
        }
    } else {
        qWarning() << "not init wFriendsFilter";
    }
}

void FormFriendsCompare::initTableCompare() {
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
//        updateCurrentAchievement();
//        if (_currentAchievement != nullptr) {
//            QMenu *menu = createMenuCompare(*_currentAchievement);
//            menu->popup(ui->TableViewCompare->viewport()->mapToGlobal(pos));
//        }
    });

    connect(ui->TableViewCompare, &QTableView::doubleClicked, this, [=](QModelIndex aIndex) {
//        updateCurrentAchievement();
    });
}

void FormFriendsCompare::updateFilterWithFriend(const QString &aFriendName, ReachedType aType) {
    int columnFriend = 0;
//    for (auto &column: _friendsColumns) {
//        if (ui->TableWidgetHorizontalHeader->horizontalHeaderItem(column)->text() == aFriendName){
//            columnFriend = column;
//            break;
//        }
//    }
//    int filterColumn = _fCompare.getCol() - (getColumnCount() - columnFriend);
    switch (aType) {
    case ReachedType::all: {
//        for (int i = 0; i < getRowCount(); ++i) {
//            _fCompare.setData(i, filterColumn, true);
//        }
        break;
    }
    case ReachedType::reached: {
//        for (int i = 0; i < getRowCount(); ++i) {
//            _fCompare.setData(i, filterColumn, itemContent(i, columnFriend)->text().indexOf(".") > -1);
//        }
        break;
    }
    case ReachedType::notReached: {
//        for (int i = 0; i < getRowCount(); ++i) {
//            _fCompare.setData(i, filterColumn, itemContent(i, columnFriend)->text().indexOf(".") == -1);
//        }
        break;
    }
    default: {
        break;
    }
    }
//    updateHiddenRows();
}

void FormFriendsCompare::loadingCompare() {
    ++_loadCompare;
    _profilesFriends = SFriends(_profile._steamID, false).getProfiles();
    ui->TableWidgetFriends->setColumnCount(_profilesFriends.getCount() + 2);
    for (int i = 0; i < _profilesFriends.getCount() + 2; ++i) {
        ui->TableWidgetFriends->setColumnWidth(i, 33 + 8);
    }
    _profilesFriends.sort();
//    ui->ProgressBarLoad->setMaximum(_profilesFriends.getCount());
//    ui->ProgressBarLoad->setValue(0);
//    ui->ProgressBarLoad->setVisible(true);

    int index = -1;
    for(auto &profileFriend: _profilesFriends) {
        SGames *gamesFriend = new SGames(this);
        gamesFriend->_index = ++index;
        gamesFriend->load(profileFriend._steamID, true, true, true);
        connect(gamesFriend, SIGNAL(s_finished(SGames*)), this, SLOT(loadFriendGames(SGames*)));
    }
}

void FormFriendsCompare::loadFriendGames(SGames *aGames) {
    disconnect(aGames, SIGNAL(s_finished(SGames*)), this, SLOT(loadFriendGames(SGames*)));
    bool isGameExist = std::any_of(aGames->begin(), 
                                   aGames->end(), 
                                   [=](const SGame &game) {
                                        return game.appId() == _game.appId();
                                    });
    QPair<SProfile, FriendType> friendState;
    friendState.first = _profilesFriends[aGames->_index];
    if (isGameExist) {
        ui->ComboBoxFriend->addItem(_profilesFriends[aGames->_index], FriendType::haveGame);
        //friendState.second = FriendType::haveGame;
        ++_type1;
    } else {
        ui->ComboBoxFriend->addItem(_profilesFriends[aGames->_index], FriendType::haventGame);
        //friendState.second = FriendType::haventGame;
        ++_type2;
    }
    //_friends.push_back(std::move(friendState));
//    ui->ProgressBarLoad->setValue(ui->ProgressBarLoad->value() + 1);
//    if(ui->ProgressBarLoad->value() == _profilesFriends.getCount()) {
//        finishLoadFriends();
//    }
}

void FormFriendsCompare::finishLoadFriends() {
//    ui->ProgressBarLoad->setVisible(false);
    int row = 2;
    //for(auto &friendP: _friends) {
//        QLabel *avatarFriend = new QLabel(this);
//        avatarFriend->setToolTip(friendP.first._personaName);
//        avatarFriend->setAlignment(Qt::AlignCenter);
//        avatarFriend->setPixmap(friendP.first.getPixmapAvatar());
//        ui->TableWidgetFriends->setCellWidget(0, row, avatarFriend);

//        QTableWidgetItem *itemCheck(new QTableWidgetItem(""));
//        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
//        itemCheck->setCheckState(Qt::Unchecked);
//        itemCheck->setTextAlignment(Qt::AlignCenter);

//        ui->TableWidgetFriends->setItem(c_tableFriendsRowCheckBox, row, itemCheck);
//        ui->TableWidgetFriends->setItem(c_tableFriendsRowID, row, new QTableWidgetItem(friendP.first._steamID));

//        //ui->ComboBoxFriend->addItem();

//        ui->TableWidgetFriends->setColumnHidden(row, friendP.second == FriendType::haventGame);
//        ++row;
    //}
    connect(ui->TableWidgetFriends, &QTableWidget::cellChanged, this, &FormFriendsCompare::tableWidgetCompareFriends_CellChanged);
    ++_loadCompare;
//    ui->TableWidgetFriends->setVisible(_currentMode == FormMode::compare);
}

void FormFriendsCompare::compareProfileFilterClickFriends(const QString &aName, ReachedType aType) {
    QLabel *friendAvatar = dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(0, aName.toInt()));
    if (friendAvatar) {
        QString name = friendAvatar->toolTip();
//        _tableAchievements->updateFilterWithFriend(name, aType);
    } else {
        qWarning() << "not init friendAvatar";
    }
}

void FormFriendsCompare::buttonCompareAllFriendsReach_Clicked() {
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
                //qDebug() << "error FormAchievements::buttonCompareAllFriendsReach_Clicked() filterFriend";
            }
        }
    } else {
        qWarning() << "not init senderButton";
    }
}

void FormFriendsCompare::tableWidgetCompareFriends_CellChanged(int aRow, int aColumn) {
    if ((aRow == 1) && (aColumn > 1)) {
//        SProfile profileFriend = _friends[aColumn - 2].first;
        if (ui->TableWidgetFriends->item(aRow, aColumn)->checkState() == Qt::Checked) {
//            if (_tableAchievements->addFriendColumn(profileFriend)) {
//                createCompareProfileFilter(true, aColumn);
//            }
        } else {
//            _tableAchievements->removeFriendColumn(profileFriend._personaName);
            FormCompareProfileFilter *friendFilter = findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend" + QString::number(aColumn));
            if (friendFilter) {
                disconnect(friendFilter, &FormCompareProfileFilter::s_radioButtonChange, this, &FormFriendsCompare::compareProfileFilterClickFriends);
                ui->TableWidgetFriends->removeCellWidget(c_tableFriendsRowFilters, aColumn);
                delete friendFilter;
                //ui->TableWidgetFriends->resizeColumnsToContents();
            } else {
                qWarning() << "not init friendFilter";
            }
        }
    }
}

void FormFriendsCompare::createCompareProfileFilter(bool aAccept, int aColumn) {
    if (aAccept) {
        FormCompareProfileFilter *friendFilter = new FormCompareProfileFilter(this);
        friendFilter->setObjectName("FormCompareProfileFilterFriend" + QString::number(aColumn));
        friendFilter->setName(QString::number(aColumn));
        connect(friendFilter, &FormCompareProfileFilter::s_radioButtonChange, this,         &FormFriendsCompare::compareProfileFilterClickFriends);
        connect(this,         &FormFriendsCompare::s_updateSettings,            friendFilter, &FormCompareProfileFilter::updateSettings);
        ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, aColumn, friendFilter);
        //ui->TableWidgetFriends->resizeRowsToContents();
        //ui->TableWidgetFriends->resizeColumnsToContents();
    }
}

void FormFriendsCompare::checkBoxCompareAllFriends_StateChanged(int arg1) {
//    switch (arg1) {
//    case 0: {
//        for (int i = 0; i < _friends.size(); ++i) {
//            if(_friends[i].second == FriendType::haventGame) {
//                ui->TableWidgetFriends->setColumnHidden(i + 2, true);
//            }
//        }
//        break;
//    }
//    case 2: {
//        for (int i = 0; i < _friends.size(); ++i) {
//            if (_friends[i].second == FriendType::haventGame) {
//                ui->TableWidgetFriends->setColumnHidden(i + 2, false);
//            }
//        }
//        //ui->TableWidgetFriends->resizeColumnsToContents();
//        break;
//    }
//    }
}
