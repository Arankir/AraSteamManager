#include "formfriendscompare.h"
#include "ui_formfriendscompare.h"
#include "./widgets/formfrienditemcompare.h"
#include <QMenu>

constexpr int c_columnAppid             = 0;
constexpr int c_columnIndex             = 1;
constexpr int c_columnIcon              = 2;
constexpr int c_columnTitle             = 3;
constexpr int c_columnDescription       = 4;
constexpr int c_columnComment           = 5;
constexpr int c_columnWorld             = 6;
constexpr int c_columnReachedMy         = 7;
constexpr int c_columnCount             = 8;

constexpr int c_friendColumnWidth       = 50;
constexpr int c_staticRows              = 1;

FormFriendsCompare::FormFriendsCompare(QWidget *parent): QWidget(parent), ui(new Ui::FormFriendsCompare),
_fCompare(0, 0) {
    ui->setupUi(this);

    initTableCompare();
    setIcons();
    #define Connects {
    connect(ui->CheckBoxCompareIcon,
            &QCheckBox::stateChanged,
            ui->TableViewCompare,
            [=](int arg1) {
                ui->TableViewCompare->setColumnHidden(c_columnIcon, arg1 == 0);
            });
    connect(ui->CheckBoxCompareTitle,
            &QCheckBox::stateChanged,
            ui->TableViewCompare,
            [=](int arg1) {
                ui->TableViewCompare->setColumnHidden(c_columnTitle, arg1 == 0);
            });
    connect(ui->CheckBoxCompareDescription,
            &QCheckBox::stateChanged,
            ui->TableViewCompare,
            [=](int arg1) {
                ui->TableViewCompare->setColumnHidden(c_columnDescription, arg1 == 0);
            });
    connect(ui->CheckBoxCompareTotalPercent,
            &QCheckBox::stateChanged,
            ui->TableViewCompare,
            [=](int arg1) {
                ui->TableViewCompare->setColumnHidden(c_columnWorld, arg1 == 0);
            });
    connect(ui->ButtonFriendsAll,
            &QPushButton::clicked,
            this,
            &FormFriendsCompare::setFriendsAll);
    connect(ui->ButtonFriendsReached,
            &QPushButton::clicked,
            this,
            &FormFriendsCompare::setFriendsReached);
    connect(ui->ButtonFriendsNotReached,
            &QPushButton::clicked,
            this,
            &FormFriendsCompare::setFriendsNotReached);
    connect(ui->ComboBoxFriend,
            &ComboBoxFriends::s_friendClicked,
            this,
            &FormFriendsCompare::addFriendToList);
    #define ConnectsEnd }
}

void FormFriendsCompare::setAchievedColors(QColor aAchieved, QColor aNotAchieved) {
    _achievedColor = aAchieved;
    _notAchievedColor = aNotAchieved;
}

FormFriendsCompare::~FormFriendsCompare() {
    qInfo() << "Форма сравнения с друзьями удалилась";
    delete ui;
}

void FormFriendsCompare::changeEvent(QEvent *event) {
    if (event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormFriendsCompare::retranslate() {
    ui->retranslateUi(this);
////    ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars, 1)->setToolTip(tr("Достижения друзей"));
//    if (ui->TableViewMyAchievements->model() != nullptr) {
//        ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars, 1)->setToolTip(tr("Достижения друзей"));
//    }
}

void FormFriendsCompare::setInitData(SProfile &profile, SGame &game, SAchievements &achievements, QStandardItemModel *model, MyFilter *aFAchievements) {
    _profile = profile;
    _game = game;
    _achievements = achievements;
    _fCompare.setRow(model->rowCount());
    _fAchievements = aFAchievements;
    ui->TableViewCompare->setModel(model);
    //ui->TableViewCompare->setSortingEnabled(true);
    ui->TableViewCompare->setColumnHidden(c_columnAppid, true);
    ui->TableViewCompare->setColumnHidden(c_columnIndex, true);
    ui->TableViewCompare->setColumnHidden(c_columnComment, true);
    ui->TableViewCompare->resizeColumnsToContents();
    ui->TableViewCompare->setColumnWidth(c_columnTitle, 220);
    ui->TableViewCompare->setColumnWidth(c_columnDescription, 450);
    ui->TableViewCompare->resizeRowsToContents();
    loadingCompare();
}

void FormFriendsCompare::setIcons() {
    ui->ButtonFriendsReached    ->setIcon(QIcon(Images::reached()));
    ui->ButtonFriendsAll        ->setIcon(QIcon(Images::allAchievements()));
    ui->ButtonFriendsNotReached ->setIcon(QIcon(Images::notReached()));
}

void FormFriendsCompare::initTableCompare() {
    ui->TableViewCompare->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
    ui->TableViewCompare->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

    ui->TableViewCompare->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TableViewCompare->setShowGrid(false);
//TODO потом разрешить сортировку
    ui->TableViewCompare->setSortingEnabled(false);
    ui->TableViewCompare->horizontalHeader()->setStretchLastSection(true);
    ui->TableViewCompare->verticalHeader()->setVisible(false);
    ui->TableViewCompare->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->TableViewCompare->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->TableViewCompare, &QTableView::doubleClicked, this, [=](QModelIndex) {
        updateCurrentAchievement();
    });
}

void FormFriendsCompare::updateCurrentAchievement() {
    QModelIndex index = ui->TableViewCompare->currentIndex();
    _currentAchievementIndex = ui->TableViewCompare->model()->index(index.row(), c_columnIndex).data().toString().toInt();
    QString appId = ui->TableViewCompare->model()->index(index.row(), c_columnAppid).data().toString();

    auto iterator = std::find_if(_achievements.begin(),
                                 _achievements.end(),
                                 [=](const SAchievement &achievement) {
                                     return achievement.apiName() == appId;
                                 });
    if (iterator != _achievements.end()) {
        _currentAchievement = &*iterator;
    }
}

void FormFriendsCompare::setFriendsAll() {
    for(int i = 0; i < ui->ListWidgetFriends->count(); ++i) {
        auto item = ui->ListWidgetFriends->item(i);
        auto itemWidget = dynamic_cast<FormFriendItemCompare*>(ui->ListWidgetFriends->itemWidget(item));
        if (itemWidget != nullptr) {
            if (!itemWidget->isFilterHidden()) {
                itemWidget->setFilterValue(ReachedType::all);
            }
        }
    }
}

void FormFriendsCompare::setFriendsReached() {
    for(int i = 0; i < ui->ListWidgetFriends->count(); ++i) {
        auto item = ui->ListWidgetFriends->item(i);
        auto itemWidget = dynamic_cast<FormFriendItemCompare*>(ui->ListWidgetFriends->itemWidget(item));
        if (itemWidget != nullptr) {
            if (!itemWidget->isFilterHidden()) {
                itemWidget->setFilterValue(ReachedType::reached);
            }
        }
    }
}

void FormFriendsCompare::setFriendsNotReached() {
    for(int i = 0; i < ui->ListWidgetFriends->count(); ++i) {
        auto item = ui->ListWidgetFriends->item(i);
        auto itemWidget = dynamic_cast<FormFriendItemCompare*>(ui->ListWidgetFriends->itemWidget(item));
        if (itemWidget != nullptr) {
            if (!itemWidget->isFilterHidden()) {
                itemWidget->setFilterValue(ReachedType::notReached);
            }
        }
    }
}

void FormFriendsCompare::updateFilterFriend(SProfile *aSteamId, ReachedType aType) {
    auto model = dynamic_cast<QStandardItemModel*>(ui->TableViewCompare->model());
    if (model == nullptr) {
        return;
    }
    int columnFriend = 0;
    auto iterator = std::find_if(_friendColumns.begin(),
                                 _friendColumns.end(),
                                 [=](SProfile profile) {
                                    return profile.steamID() == aSteamId->steamID();
                                });
    if (iterator == _friendColumns.end()) {
        return;
    }
    int filterColumn = iterator - _friendColumns.begin();
    columnFriend = c_columnCount + filterColumn;
    switch (aType) {
    case ReachedType::all: {
        for (int i = c_staticRows; i < ui->TableViewCompare->model()->rowCount(); ++i) {
            _fCompare.setData(i, filterColumn, true);
        }
        break;
    }
    case ReachedType::reached: {
        for (int i = c_staticRows; i < ui->TableViewCompare->model()->rowCount(); ++i) {
            _fCompare.setData(i, filterColumn, model->item(i, columnFriend)->text().indexOf(".") > -1);
        }
        break;
    }
    case ReachedType::notReached: {
        for (int i = c_staticRows; i < ui->TableViewCompare->model()->rowCount(); ++i) {
            _fCompare.setData(i, filterColumn, model->item(i, columnFriend)->text().indexOf(".") == -1);
        }
        break;
    }
    default: {
        break;
    }
    }
    updateHiddenRows();
}

void FormFriendsCompare::updateHiddenRows() {
//TODO не учитывает пересортировку
    if (ui->TableViewCompare->model() == nullptr) {
        return;
    }
    if (_fAchievements != nullptr) {
        for (int i = c_staticRows; i < ui->TableViewCompare->model()->rowCount(); ++i) {
            ui->TableViewCompare->setRowHidden(i, !(_fCompare.getData(i) && _fAchievements->getData(i - 1)));
        }
    } else {
        for (int i = c_staticRows; i < ui->TableViewCompare->model()->rowCount(); ++i) {
            ui->TableViewCompare->setRowHidden(i, !_fCompare.getData(i));
        }
    }
}

void FormFriendsCompare::loadingCompare() {
    ++_loadCompare;
    _profilesFriends = SFriends(_profile.steamID(), false).profiles();

    for(auto &profileFriend: _profilesFriends) {
        SGames *gamesFriend = new SGames(this);
        gamesFriend->load(profileFriend.steamID(), true, true, true);
        connect(gamesFriend, SIGNAL(s_finished(SGames*)), this, SLOT(loadFriendGames(SGames*)));
    }
}

void FormFriendsCompare::loadFriendGames(SGames *aGames) {
    disconnect(aGames, SIGNAL(s_finished(SGames*)), this, SLOT(loadFriendGames(SGames*)));

    auto iterator = std::find_if(_profilesFriends.begin(),
                                 _profilesFriends.end(),
                                 [=](const SProfile &profile) {
                                     return aGames->gameId() == profile.steamID();
                                 });
    if (iterator != _profilesFriends.end()) {
        bool isGameExist = std::any_of(aGames->begin(),
                                       aGames->end(),
                                       [=](const SGame &game) {
                                           return game.appId() == _game.appId();
                                       });
        if (isGameExist) {
            ui->ComboBoxFriend->addItem(*iterator, FriendType::haveGame);
            ++_type1;
        } else {
            ui->ComboBoxFriend->addItem(*iterator, FriendType::haventGame);
            ++_type2;
        }
        emit s_progressLoad(_type1 + _type2, _profilesFriends.getCount());
    //    ui->ProgressBarLoad->setValue(ui->ProgressBarLoad->value() + 1);
    }
    if(_type1 + _type2 == _profilesFriends.getCount()) {
        ++_loadCompare;
        emit s_finishLoad();
    }
}

void FormFriendsCompare::addFriendToList(SProfile *aSteamFriend) {
    QListWidgetItem *item = new QListWidgetItem();
    item->setIcon(aSteamFriend->pixmapAvatar());

    auto friendItem = new FormFriendItemCompare(aSteamFriend, item);
    connect(friendItem, &FormFriendItemCompare::s_delete, this, &FormFriendsCompare::removeFriendFromCompare);
    connect(friendItem, &FormFriendItemCompare::s_filterChanged, this, &FormFriendsCompare::updateFilterFriend);

    ui->ListWidgetFriends->addItem(item);
    ui->ListWidgetFriends->setItemWidget(item, friendItem);
    float percent = addFriendColumn(*aSteamFriend);
    if (percent == -1.0f) {
        friendItem->setPercent(0.0f);
        friendItem->setHiddenFilter(true);
    } else {
        friendItem->setPercent(percent);
    }
}

void FormFriendsCompare::removeFriendFromCompare() {
    auto sndr = dynamic_cast<FormFriendItemCompare*>(sender());
    if (sndr == nullptr) {
        return;
    }
    ui->ComboBoxFriend->addItem(*sndr->steamProfile(), sndr->isFilterHidden() ? FriendType::haventGame : FriendType::haveGame);
    removeFriendColumn(*sndr->steamProfile());
    delete sndr->item();
}

int FormFriendsCompare::rowFromId(QString aId) {
    for(int i = c_staticRows; i < ui->TableViewCompare->model()->rowCount(); ++i) {
        if (aId == ui->TableViewCompare->model()->index(i, c_columnAppid).data(Qt::DisplayRole)) {
            return i;
        }
    }
    return -1;
}

float FormFriendsCompare::addFriendColumn(SProfile &aSteamFriend) {
    auto model = dynamic_cast<QStandardItemModel*>(ui->TableViewCompare->model());
    if (model == nullptr) {
        return -1.0f;
    }
    int column = model->columnCount();
    model->insertColumn(column);
    model->setHeaderData(column, Qt::Horizontal, aSteamFriend.personaName(), Qt::DisplayRole);
    QStandardItem *itemAvatar = new QStandardItem();
    itemAvatar->setData(aSteamFriend.pixmapAvatar(), Qt::DecorationRole);
    itemAvatar->setData(aSteamFriend.personaName(), Qt::ToolTipRole);
//    itemAvatar->setTextAlignment(Qt::AlignCenter);
    model->setItem(0, column, itemAvatar);
    SAchievements achievementsFriends(_achievements);
    achievementsFriends.set(SAchievementsPlayer(_game.sAppId(), aSteamFriend.steamID(), false));
//    Threading LoadFriendTable(this);
//    LoadFriendTable.AddThreadFriendAchievements(ui->TableWidgetAchievements,ach,col,c_tableCompareColumnAppid);
    _fCompare.setCol(_fCompare.getCol() + 1);

    _friendColumns.push_back(aSteamFriend);
    int totalReach = 0;
    int totalNotReach = 0;
    if (achievementsFriends.status() == StatusValue::success) {
        for(auto &achievement: achievementsFriends) {
            int row = rowFromId(achievement.apiName());
            if (row > -1) {
                QStandardItem *itemAchieved = new QStandardItem();
                if (achievement.achieved() == 1) {
                    itemAchieved->setText(achievement.unlockTime().toString("yyyy.MM.dd hh:mm"));
                    itemAchieved->setForeground(_achievedColor);
                    ++totalReach;
                } else {
                    itemAchieved->setText(tr("Не получено"));
                    itemAchieved->setForeground(_notAchievedColor);
                    ++totalNotReach;
                }
                itemAchieved->setTextAlignment(Qt::AlignCenter);
                model->setItem(row, column, itemAchieved);
            }
        }
    }
    ui->TableViewCompare->setColumnWidth(column, c_friendColumnWidth);
    emit s_addedFriend();
    if((totalReach == 0) && (totalNotReach == 0)) {
        QStandardItem *item = new QStandardItem(tr("Профиль не публичный"));
        item->setForeground(_notAchievedColor);
        model->setItem(c_staticRows, column, item);
        return -1.0f;
    } else {
        return 100.0f * totalReach / (totalReach + totalNotReach);
    }
}

bool FormFriendsCompare::removeFriendColumn(SProfile &aSteamFriend) {
    auto iterator = std::find_if(_friendColumns.begin(),
                                 _friendColumns.end(),
                                 [=](SProfile profile) {
                                    return profile.steamID() == aSteamFriend.steamID();
                                });
    if (iterator != _friendColumns.end()) {
        _fCompare.removeCol(iterator - _friendColumns.begin());
        ui->TableViewCompare->model()->removeColumn(c_columnCount + (iterator - _friendColumns.begin()));
        _friendColumns.removeAt(iterator - _friendColumns.begin());
        updateHiddenRows();
        return true;
    }
    return false;
}
