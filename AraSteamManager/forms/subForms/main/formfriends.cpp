#include "formfriends.h"
#include "ui_formfriends.h"

#define Init {
FormFriends::FormFriends(const QString &aId, QList<SFriend> &aFriends, QWidget *aParent):
Form(aParent), ui(new Ui::FormFriends), _id(aId) {
    ui->setupUi(this);
    init();
    setFriends(aId, aFriends);
}

FormFriends::FormFriends(QWidget *aParent): Form(aParent), ui(new Ui::FormFriends) {
    ui->setupUi(this);
    init();
}

void FormFriends::init() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    initingTable(ui->TableFriends);
//    setFont(QFont(Settings::defaultFont()));
    ui->TableFriends->setModel(&_filterFriends);
    updateIcons();
#define Connects {
    connect(ui->ButtonFind,           &QPushButton::clicked,    this, &FormFriends::buttonFind_Clicked);
    connect(ui->ComboBoxStatus,       SIGNAL(activated(int)),   this, SLOT(comboBoxStatus_Activated(int)));
    connect(ui->LineEditName,         &QLineEdit::textChanged,  this, &FormFriends::lineEditName_TextChanged);
    connect(ui->CheckBoxOpenProfile,  &QCheckBox::stateChanged, this, [&](int lState) {
        _filterFriends.setIsPublic(lState);
        ui->TableFriends->resizeRowsToContents();
    });
    connect(ui->CheckBoxFavorites,    &QCheckBox::stateChanged, this, &FormFriends::checkBoxFavorites_StateChanged);
    connect(ui->TableFriends,         &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
        QMenu *menu = createMenu(currentFriend());
        menu->popup(ui->TableFriends->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableFriends,         &QTableView::doubleClicked, this, [=](QModelIndex) {
        goToCurrentProfile();
    });
#define ConnectsEnd }
}

QList<QPair<SFriend, SProfile>> loadProfiles(QList<SFriend> &aFriends) {
    QList<QPair<SFriend, SProfile>> resultList;
    QStringList listIds;
    for (const SFriend &sFriend: aFriends) {
        listIds.append(sFriend.steamId());
    }
    QList<SProfile> profiles = SProfile::load(listIds);
    mySort2(profiles);
    for(auto &profile: profiles) {
        for (const auto &currentFriend: aFriends) {
            if (currentFriend.steamId() == profile.steamID()) {
                resultList.append(std::move(QPair<SFriend, SProfile>(currentFriend, profile)));
                break;
            }
        }
    }
    return resultList;
}

void FormFriends::setFriends(const QString &aId, QList<SFriend> &aFriends) {
    clear();
    _id = aId;
    if (_filterFriends.sourceModel()) {
        delete _filterFriends.sourceModel();
    }
//    connect (ui->TableFriends->horizontalHeader(), &QHeaderView::sortIndicatorChanged, _friendsModel, &FriendsModel::sort);
    _filterFriends.setSourceModel(new FriendsModel(loadProfiles(aFriends), ui->TableFriends));
    ui->TableFriends->setColumnHidden(FriendsID,    true);
    ui->TableFriends->setColumnHidden(FriendsIndex, true);

    retranslate();

    ui->TableFriends->resizeColumnsToContents();
    ui->TableFriends->resizeRowsToContents();

    emit s_finish();
}

void FormFriends::clear() {
    _blockedLoad = false;
    _id = "";
    _filterFriends.clear();
    ui->ComboBoxStatus->setCurrentIndex(0);
}

bool FormFriends::isInit() {
    return ((_id != "") && (ui->TableFriends->model()->rowCount() > 0));
}

void FormFriends::initComboBoxStatus() {
    int index = ui->ComboBoxStatus->currentIndex();
    if (index < 0) {
        index = 0;
    }
    ui->ComboBoxStatus->clear();
    ui->ComboBoxStatus->addItems(QStringList{tr("Статус"), tr("В игре"), tr("Не в сети"), tr("В сети"), tr("Не беспокоить"),
                                             tr("Нет на месте"), tr("Спит"), tr("Ожидает обмена"), tr("Хочет поиграть")});
    ui->ComboBoxStatus->setCurrentIndex(index);
}

#define InitEnd }

#define System {
FormFriends::~FormFriends() {
    qInfo() << "Форма друзей удалилась";
    delete ui;
}

void FormFriends::closeEvent(QCloseEvent*) {
    emit s_returnToProfile(this);
    //delete this;
}

void FormFriends::retranslate() {
    ui->retranslateUi(this);
    initComboBoxStatus();

//    if (ui->TableFriends->model() != nullptr) {
//        ui->TableFriends->model()->setHeaderData(ColumnFriendsIcon,        Qt::Horizontal, tr(""));
//        ui->TableFriends->model()->setHeaderData(ColumnFriendsName,        Qt::Horizontal, tr("   НИК"));
//        ui->TableFriends->model()->setHeaderData(ColumnFriendsAdded,       Qt::Horizontal, tr("   ДОБАВЛЕН"));
//        ui->TableFriends->model()->setHeaderData(ColumnFriendsStatus,      Qt::Horizontal, tr("   СТАТУС"));
//        ui->TableFriends->model()->setHeaderData(ColumnFriendsIsPublic,    Qt::Horizontal, tr("   ПРОФИЛЬ"));
//    }
}

void FormFriends::updateSettings() {
    Settings::syncronizeSettings();
    updateIcons();
}

QPair<SFriend, SProfile> FormFriends::currentFriend() {
    QModelIndex index = ui->TableFriends->currentIndex();
    QModelIndex index2 = index.siblingAtColumn(FriendsIndex);
    QVariant fIndex = _filterFriends.data(index2);
    return _filterFriends.sourceModel()->getFriend(fIndex.toInt());
}

void FormFriends::updateIcons() {
    ui->ButtonFind->setIcon(QIcon(Images::findProfile()));
}

bool isProfileFavorite(const QPair<SFriend, SProfile> &aProfile, const QString &aSteamId) {
    QList<FavoriteFriend> favoriteFriends = Favorites::friends();
    for (const auto &favorite: qAsConst(favoriteFriends)) {
        if ((favorite.friendId() == aProfile.second.steamID()) &&
            (favorite.steamId() == aSteamId)) {
            return true;
        }
    }
    return false;
}
#define SystemEnd }

#define Filter {
void FormFriends::comboBoxStatus_Activated(int aIndex) {
    _filterFriends.setStatus(aIndex == 0 ? "" : ui->ComboBoxStatus->currentText());
    ui->TableFriends->resizeRowsToContents();
}

void FormFriends::lineEditName_TextChanged(const QString &aNewText) {
    _filterFriends.setName(aNewText);
    ui->TableFriends->resizeRowsToContents();
}

void FormFriends::buttonFind_Clicked() {
    lineEditName_TextChanged(ui->LineEditName->text());
}

void FormFriends::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        _filterFriends.setFavorites(QStringList());
        break;
    }
    case 2: {
        QList<FavoriteFriend> favoriteFriends = Favorites::friends();
        QStringList list;
        for (const auto &favorite: qAsConst(favoriteFriends)) {
            list.append(std::move(favorite.friendId()));
        }
        _filterFriends.setFavorites(list);
        break;
    }
    }
    ui->TableFriends->resizeRowsToContents();
}
#define FilterEnd }

#define TableAction {
void updateActionFavoriteData(QAction *aAction, bool aIsFavorite) {
    if (aIsFavorite) {
        aAction->setText(QObject::tr("Удалить из избранного"));
        aAction->setIcon(QIcon(Images::isFavorites()));
    } else {
        aAction->setText(QObject::tr("Добавить в избранное"));
        aAction->setIcon(QIcon(Images::isNotFavorites()));
    }
}

QMenu *FormFriends::createMenu(const QPair<SFriend, SProfile> &aProfile) {
    QMenu *menu = new QMenu(this);

    QAction *actionGoToProfile = new QAction(tr("Перейти на профиль"), this);
    actionGoToProfile->setIcon(QIcon(Images::goTo()));

    QAction *actionFavorites = new QAction(this);
    updateActionFavoriteData(actionFavorites, isProfileFavorite(aProfile, _id));

    connect (actionFavorites,   &QAction::triggered, this, &FormFriends::friendToFavorite);
    connect (actionGoToProfile, &QAction::triggered, this, &FormFriends::goToCurrentProfile);

    menu -> addAction (actionGoToProfile);
    menu -> addAction (actionFavorites);
    return menu;
}

void FormFriends::goToCurrentProfile() {
    if(_blockedLoad) {
        return;
    }
    _blockedLoad = true;
    emit s_goToProfile(currentFriend().second.steamID(), SProfileRequestType::id);
}

void FormFriends::friendToFavorite() {
    auto curFriend = currentFriend();
    bool isFavorite = Favorites::addFriend(_id, curFriend.second, curFriend.first, true);
    if (QAction *action = dynamic_cast<QAction*>(sender())) {
        updateActionFavoriteData(action, isFavorite);
    }
}
#define TableActionEnd }
