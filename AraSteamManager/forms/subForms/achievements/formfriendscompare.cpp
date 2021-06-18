#include "formfriendscompare.h"
#include "ui_formfriendscompare.h"
#include "./widgets/formfrienditemcompare.h"
#include <QMenu>

constexpr int c_friendColumnWidth = 100;

FormFriendsCompare::FormFriendsCompare(QWidget *parent): Form(parent), ui(new Ui::FormFriendsCompare) {
    ui->setupUi(this);

    initingTable(ui->TableViewCompare);
    updateIcons();
    #define Connects {
    connect(ui->CheckBoxCompareIcon, &QCheckBox::stateChanged, ui->TableViewCompare,
            [=](int arg1) {ui->TableViewCompare->setColumnHidden(AchievementIcon, arg1 == 0);});
    connect(ui->CheckBoxCompareTitle, &QCheckBox::stateChanged, ui->TableViewCompare,
            [=](int arg1) {ui->TableViewCompare->setColumnHidden(AchievementTitle, arg1 == 0);});
    connect(ui->CheckBoxCompareDescription, &QCheckBox::stateChanged, ui->TableViewCompare,
            [=](int arg1) {ui->TableViewCompare->setColumnHidden(AchievementDescription, arg1 == 0);});
    connect(ui->CheckBoxCompareTotalPercent, &QCheckBox::stateChanged, ui->TableViewCompare,
            [=](int arg1) {ui->TableViewCompare->setColumnHidden(AchievementWorld, arg1 == 0);});
    connect(ui->ButtonFriendsAll, &QPushButton::clicked, this, &FormFriendsCompare::setFriendsAll);
    connect(ui->ButtonFriendsReached, &QPushButton::clicked, this, &FormFriendsCompare::setFriendsReached);
    connect(ui->ButtonFriendsNotReached, &QPushButton::clicked, this, &FormFriendsCompare::setFriendsNotReached);
    connect(ui->ComboBoxFriend, &ComboBoxFriends::s_friendClicked, this, &FormFriendsCompare::addFriendToList);
    #define ConnectsEnd }
}

void FormFriendsCompare::updateSettings() {
    updateIcons();
}

void FormFriendsCompare::setInitData(const SProfile &profile, const SGame &game, AchievementsModel *achievementsModel/*, SAchievements &achievements*//*, QAbstractItemModel *model*//*, MyFilter *aFAchievements*/) {
    _achievementsModel = achievementsModel;
    _profile = profile;
    _game = game;

    ui->TableViewCompare->resizeColumnsToContents();
    ui->TableViewCompare->setColumnWidth(AchievementTitle, 220);
    ui->TableViewCompare->setColumnWidth(AchievementDescription, 450);
    loadingCompare();
}

void FormFriendsCompare::setModel(QAbstractItemModel *model) {
    _model = model;
    updateFiltersFriends();
    ui->TableViewCompare->model()->sort(AchievementReachedMy, Qt::SortOrder::DescendingOrder);
    ui->TableViewCompare->sortByColumn(AchievementWorld, Qt::SortOrder::DescendingOrder);
    ui->TableViewCompare->setColumnHidden(AchievementAppid, true);
    ui->TableViewCompare->setColumnHidden(AchievementIndex, true);
    ui->TableViewCompare->setColumnHidden(AchievementComments, true);
    ui->TableViewCompare->resizeRowsToContents();
}

void FormFriendsCompare::updateIcons() {
    ui->ButtonFriendsReached    ->setIcon(QIcon(Images::reached()));
    ui->ButtonFriendsAll        ->setIcon(QIcon(Images::allAchievements()));
    ui->ButtonFriendsNotReached ->setIcon(QIcon(Images::notReached()));
}

FormFriendsCompare::~FormFriendsCompare() {
    qInfo() << "Форма сравнения с друзьями удалилась";
    delete ui;
}

void FormFriendsCompare::retranslate() {
    ui->retranslateUi(this);
}

void FormFriendsCompare::setAllFriendsValue(const ReachedType &aType) {
    for(int i = 0; i < ui->ListWidgetFriends->count(); ++i) {
        auto item = ui->ListWidgetFriends->item(i);
        if (auto itemWidget = dynamic_cast<FormFriendItemCompare*>(ui->ListWidgetFriends->itemWidget(item))) {
            if (!itemWidget->isFilterHidden()) {
                itemWidget->setFilterValue(aType);
            }
        }
    }
}

void FormFriendsCompare::setFriendsAll() {
    setAllFriendsValue(ReachedType::all);
}

void FormFriendsCompare::setFriendsReached() {
    setAllFriendsValue(ReachedType::reached);
}

void FormFriendsCompare::setFriendsNotReached() {
    setAllFriendsValue(ReachedType::notReached);
}

void FormFriendsCompare::updateFiltersFriends() {
    QAbstractItemModel *model = _model;
    for (auto filter: _filtersFriends) {
        filter->setSourceModel(model);
        model = filter;
    }
    ui->TableViewCompare->setModel(model);
}

void FormFriendsCompare::updateFilterFriend(SProfile *aSteamId, const ReachedType &aType) {
    if (_achievementsModel == nullptr) {
        return;
    }
    for (int i = 0; i < _achievementsModel->columnCount() - AchievementReachedMy; ++i) {
        if (_achievementsModel->getProfile(i).steamID() == aSteamId->steamID()) {
            switch (aType) {
            case ReachedType::all: {
                _filtersFriends[i - 1]->setFilterRegExp("");
                break;
            }
            case ReachedType::reached: {
                _filtersFriends[i - 1]->setFilterRegExp("(:)|(^$)");
                break;
            }
            case ReachedType::notReached: {
                _filtersFriends[i - 1]->setFilterRegExp("(" + tr("Не получено") + ")|(^$)");
                break;
            }
            default: {
                _filtersFriends[i - 1]->setFilterRegExp("");
                break;
            }
            }
            ui->TableViewCompare->resizeRowsToContents();
            return;
        }
    }
}

void FormFriendsCompare::loadingCompare() {
    ++_loadCompare;
    auto friends = SFriend::load(_profile.steamID());
    emit s_startLoad(friends.count());
    QStringList list;
    for(const SFriend &sFriend: qAsConst(friends)) {
        list.append(std::move(sFriend.steamId()));
    }
    _profilesFriends = SProfile::load(list);

    for(const auto &profileFriend: qAsConst(_profilesFriends)) {
        QString steamId = profileFriend.steamID();
        SGame::load(steamId, true, true, std::bind(&FormFriendsCompare::loadFriendGames, this,  std::placeholders::_1, steamId));
    }
}

void FormFriendsCompare::loadFriendGames(const SGames &aGames, const QString &aUserId) {
    static int haveGame = 0;
    static int haventGame = 0;
    auto iterator = std::find_if(_profilesFriends.begin(),
                                 _profilesFriends.end(),
                                 [=](const SProfile &profile) {
                                     return aUserId == profile.steamID();
                                 });
    if (iterator != _profilesFriends.end()) {
        bool isGameExist = std::any_of(aGames.begin(),
                                       aGames.end(),
                                       [=](const SGame &game) {
                                           return game.appId() == _game.appId();
                                       });
        if (isGameExist) {
            ui->ComboBoxFriend->addItem(*iterator, FriendType::haveGame);
            ++haveGame;
        } else {
            ui->ComboBoxFriend->addItem(*iterator, FriendType::haventGame);
            ++haventGame;
        }
        emit s_progressLoad(haveGame + haventGame, _profilesFriends.count());
    }
    if(haveGame + haventGame == _profilesFriends.count()) {
        ++_loadCompare;
        haveGame = 0;
        haventGame = 0;
        emit s_finishLoad();
    }
}

void FormFriendsCompare::addFriendToList(SProfile &aSteamFriend) {
    QListWidgetItem *item = new QListWidgetItem(aSteamFriend.pixmapAvatar(), "");

    auto friendItem = new FormFriendItemCompare(aSteamFriend, item);
    connect(friendItem, &FormFriendItemCompare::s_filterChanged, this, &FormFriendsCompare::updateFilterFriend);
    connect(friendItem, &FormFriendItemCompare::s_delete, this, [=]() {
        auto sndr = dynamic_cast<FormFriendItemCompare*>(sender());
        if (sndr == nullptr) {
            return;
        }
        ui->ComboBoxFriend->addItem(*sndr->steamProfile(), sndr->isFilterHidden() ? FriendType::haventGame : FriendType::haveGame);
        removeFriendColumn(*sndr->steamProfile());
        delete sndr->item();
    });
    ui->ListWidgetFriends->addItem(item);
    ui->ListWidgetFriends->setItemWidget(item, friendItem);

    int friendIndex = addFriendColumn(aSteamFriend);

    int reached = _achievementsModel->getReachedFromProfile(friendIndex);
    if(reached > -1) {
        friendItem->setPercent(100.0f * reached / _achievementsModel->getAchievementsCount());
    } else {
        friendItem->setPercent(0.0f);
        friendItem->setHiddenFilter(true);
    }
}

int FormFriendsCompare::addFriendColumn(const SProfile &aSteamFriend) {
    int index = _achievementsModel->addProfile(aSteamFriend);
    auto filter = new QSortFilterProxyModel();
    filter->setFilterKeyColumn(index + AchievementCount);
    filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
    _filtersFriends.append(filter);
    updateFiltersFriends();
    ui->TableViewCompare->setColumnWidth(index + AchievementCount - 1, c_friendColumnWidth);
//    emit s_addedFriend();
    return index;
}

bool FormFriendsCompare::removeFriendColumn(const SProfile &aSteamFriend) {
    _achievementsModel->removeProfile(aSteamFriend);
    return true;
}

void FormFriendsCompare::filtersValueUpdated() {
    ui->TableViewCompare->resizeRowsToContents();
}
