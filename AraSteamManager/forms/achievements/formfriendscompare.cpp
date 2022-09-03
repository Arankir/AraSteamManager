#include "formfriendscompare.h"
#include "ui_formfriendscompare.h"
#include "forms/widgets/formfrienditemcompare.h"
#include <QMenu>

constexpr int c_friendColumnWidth = 100;

FormFriendsCompare::FormFriendsCompare(QWidget *parent): Form(parent), ui(new Ui::FormFriendsCompare) {
    ui->setupUi(this);

    initingTable(ui->TableViewCompare);
    updateIcons();
    #define Connects {
    connect(ui->CheckBoxCompareIcon, &QCheckBox::stateChanged, ui->TableViewCompare,
            [&](int arg1) {ui->TableViewCompare->setColumnHidden(achievementsModel::Icon, arg1 == 0);});
    connect(ui->CheckBoxCompareTitle, &QCheckBox::stateChanged, ui->TableViewCompare,
            [&](int arg1) {ui->TableViewCompare->setColumnHidden(achievementsModel::Title, arg1 == 0);});
    connect(ui->CheckBoxCompareDescription, &QCheckBox::stateChanged, ui->TableViewCompare,
            [&](int arg1) {ui->TableViewCompare->setColumnHidden(achievementsModel::Description, arg1 == 0);});
    connect(ui->CheckBoxCompareTotalPercent, &QCheckBox::stateChanged, ui->TableViewCompare,
            [&](int arg1) {ui->TableViewCompare->setColumnHidden(achievementsModel::World, arg1 == 0);});
    connect(ui->ButtonFriendsAll, &QPushButton::clicked, this, &FormFriendsCompare::setFriendsAll);
    connect(ui->ButtonFriendsReached, &QPushButton::clicked, this, &FormFriendsCompare::setFriendsReached);
    connect(ui->ButtonFriendsNotReached, &QPushButton::clicked, this, &FormFriendsCompare::setFriendsNotReached);
    connect(ui->ComboBoxFriend, &ComboBoxFriendsWithGame::s_friendClicked, this, &FormFriendsCompare::addFriendToList);
    #define ConnectsEnd }
}

//void FormFriendsCompare::updateSettings(QFlags<changedSettings> aSettings) {
//    if (aSettings.testFlag(changedSettings::theme)) {
//        updateIcons();
//    }
//}

void FormFriendsCompare::setInitData(const SProfile &profile, const SGame &game, AchievementsModel *achievementsModel/*, SAchievements &achievements*//*, QAbstractItemModel *model*//*, MyFilter *aFAchievements*/) {
    _achievementsModel = achievementsModel;
    _profile = profile;
    _game = game;

    ui->TableViewCompare->resizeColumnsToContents();
    ui->TableViewCompare->setColumnWidth(achievementsModel::Title, 220);
    ui->TableViewCompare->setColumnWidth(achievementsModel::Description, 450);
    loadingCompare();
}

void FormFriendsCompare::setModel(QAbstractItemModel *model) {
    _model = model;
    updateFiltersFriends();
    ui->TableViewCompare->model()->sort(achievementsModel::ReachedMy, Qt::SortOrder::DescendingOrder);
    ui->TableViewCompare->sortByColumn(achievementsModel::World, Qt::SortOrder::DescendingOrder);
    ui->TableViewCompare->setColumnHidden(achievementsModel::Appid, true);
    ui->TableViewCompare->setColumnHidden(achievementsModel::Index, true);
    ui->TableViewCompare->setColumnHidden(achievementsModel::Comments, true);
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
    for (auto filter: qAsConst(_filtersFriends)) {
        filter->setSourceModel(model);
        model = filter;
    }
    ui->TableViewCompare->setModel(model);
}

void FormFriendsCompare::updateFilterFriend(SProfile *aSteamId, const ReachedType &aType) {
    if (_achievementsModel == nullptr) {
        return;
    }
    for (int i = 0; i < _achievementsModel->columnCount() - achievementsModel::ReachedMy; ++i) {
        if (_achievementsModel->getProfile(i).steamId() == aSteamId->steamId()) {
            switch (aType) {
            case ReachedType::all: {
                _filtersFriends[i - 1]->setFilterRegularExpression("");
                break;
            }
            case ReachedType::reached: {
                _filtersFriends[i - 1]->setFilterRegularExpression("(:)|(^$)");
                break;
            }
            case ReachedType::notReached: {
                _filtersFriends[i - 1]->setFilterRegularExpression("(" + tr("Не получено") + ")|(^$)");
                break;
            }
            default: {
                _filtersFriends[i - 1]->setFilterRegularExpression("");
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
    auto friends = SFriend::load(_profile.steamId());
    emit s_startLoad();
    QStringList list;
    for(const SFriend &sFriend: qAsConst(friends)) {
        list.append(sFriend.steamId());
    }
    _profilesFriends = SProfile::load(list);

    for(const auto &profileFriend: qAsConst(_profilesFriends)) {
        QString steamId = profileFriend.steamId();
        SGame::load(steamId, true, true, std::bind(&FormFriendsCompare::loadFriendGames, this,  std::placeholders::_1, steamId));
    }
}

void FormFriendsCompare::loadFriendGames(const SGames &aGames, const QString &aUserId) {
    static int haveGame = 0;
    static int haventGame = 0;
    auto iterator = std::find_if(_profilesFriends.begin(),
                                 _profilesFriends.end(),
                                 [=](const SProfile &profile) {
                                     return aUserId == profile.steamId();
                                 });
    if (iterator != _profilesFriends.end()) {
        bool isGameExist = std::any_of(aGames.begin(),
                                       aGames.end(),
                                       [&](const SGame &game) {
                                           return game.appId() == _game.appId();
                                       });
        if (isGameExist) {
            ui->ComboBoxFriend->addItem(*iterator, FriendType::haveGame);
            ++haveGame;
        } else {
            ui->ComboBoxFriend->addItem(*iterator, FriendType::haventGame);
            ++haventGame;
        }
        emit s_progressLoad(tr("Загрузка друзей"), haveGame + haventGame, _profilesFriends.count());
    }
    if(haveGame + haventGame == _profilesFriends.count()) {
        ++_loadCompare;
        haveGame = 0;
        haventGame = 0;
        emit s_finishLoad();
    }
}

void FormFriendsCompare::addFriendToList(const SProfile &aSteamFriend) {
    QListWidgetItem *item = new QListWidgetItem(aSteamFriend.pixmapAvatar(), "");

    auto friendItem = new FormFriendItemCompare(aSteamFriend, item);
    connect(friendItem, &FormFriendItemCompare::s_filterChanged, this, &FormFriendsCompare::updateFilterFriend);
    connect(friendItem, &FormFriendItemCompare::s_delete, this, [&]() {
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
    filter->setFilterKeyColumn(index + achievementsModel::Count);
    filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
    _filtersFriends.append(filter);
    updateFiltersFriends();
    ui->TableViewCompare->setColumnWidth(index + achievementsModel::Count - 1, c_friendColumnWidth);
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
