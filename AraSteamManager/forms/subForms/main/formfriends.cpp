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
    updateIcons();
#define Connects {
    connect(ui->ButtonFind,           &QPushButton::clicked,    this, &FormFriends::buttonFind_Clicked);
    connect(ui->ComboBoxStatus,       SIGNAL(activated(int)),   this, SLOT(comboBoxStatus_Activated(int)));
    connect(ui->LineEditName,         &QLineEdit::textChanged,  this, &FormFriends::lineEditName_TextChanged);
    connect(ui->CheckBoxOpenProfile,  &QCheckBox::stateChanged, this, &FormFriends::checkBoxOpenProfile_StateChanged);
    connect(ui->CheckBoxFavorites,    &QCheckBox::stateChanged, this, &FormFriends::checkBoxFavorites_StateChanged);
    connect(ui->TableFriends,         &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
        currentFriend();
        QMenu *menu = createMenu(currentFriend());
        menu->popup(ui->TableFriends->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableFriends,         &QTableView::doubleClicked, this, [=](QModelIndex) {
        goToCurrentProfile();
    });
#define ConnectsEnd }
#define InitFilter {
    _filterStatus.setSourceModel(&_filterName);
    _filterPublic.setSourceModel(&_filterStatus);
    _filterFavorite.setSourceModel(&_filterPublic);
    ui->TableFriends->setModel(&_filterFavorite);
    _filterName.setFilterKeyColumn(FriendsName);
    _filterStatus.setFilterKeyColumn(FriendsStatus);
    _filterPublic.setFilterKeyColumn(FriendsIsPublic);
    _filterFavorite.setFilterKeyColumn(FriendsID);
    _filterName.setFilterCaseSensitivity(Qt::CaseInsensitive);
    _filterStatus.setFilterCaseSensitivity(Qt::CaseInsensitive);
    _filterPublic.setFilterCaseSensitivity(Qt::CaseInsensitive);
    _filterFavorite.setFilterCaseSensitivity(Qt::CaseInsensitive);
#define InitFilterEnd }
}

QList<QPair<SFriend, SProfile>> loadProfiles(QList<SFriend> &aFriends) {
    QList<QPair<SFriend, SProfile>> resultList;
    QStringList listIds;
    for (const SFriend &sFriend: aFriends) {
        listIds.append(sFriend.steamId());
    }
    QList<SProfile> profiles = SProfile::load(listIds);
    mySort(profiles);
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
    if (_friendsModel) {
        delete _friendsModel;
    }
    _friendsModel = new FriendsModel(loadProfiles(aFriends), ui->TableFriends);
//    connect (ui->TableFriends->horizontalHeader(), &QHeaderView::sortIndicatorChanged, _friendsModel, &FriendsModel::sort);
    _filterName.setSourceModel(_friendsModel);
    ui->TableFriends->setColumnHidden(FriendsID,    true);
    ui->TableFriends->setColumnHidden(FriendsIndex, true);

    retranslate();

    ui->TableFriends->resizeColumnsToContents();
    ui->TableFriends->resizeRowsToContents();

    emit s_finish();
}

void FormFriends::clear() {
    _blockedLoad = false;
    _loaded = false;
    _id = "";
    _filterName.setFilterRegExp("");
    _filterStatus.setFilterRegExp("");
    _filterPublic.setFilterRegExp("");
    _filterFavorite.setFilterRegExp("");
    ui->ComboBoxStatus->setCurrentIndex(0);
    comboBoxStatus_Activated(0);
}

bool FormFriends::isInit() {
    return ((_id != "") && (ui->TableFriends->model()->rowCount() > 0) && (_loaded == true));
}

bool FormFriends::isLoaded() {
    return _loaded;
}

void FormFriends::initComboBoxStatus() {
    int index = ui->ComboBoxStatus->currentIndex();
    if (index < 0) {
        index = 0;
    }
    ui->ComboBoxStatus->clear();
    ui->ComboBoxStatus->addItems(QStringList() << tr("Статус") << tr("В игре") << tr("Не в сети") << tr("В сети") << tr("Не беспокоить")
                                               << tr("Нет на месте") << tr("Спит") << tr("Ожидает обмена") << tr("Хочет поиграть"));
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
    QVariant fIndex = _filterFavorite.data(index2);
    return _friendsModel->getFriend(fIndex.toInt());
}

void FormFriends::updateIcons() {
    ui->ButtonFind->setIcon(QIcon(Images::findProfile()));
}

bool FormFriends::isProfileFavorite(const QPair<SFriend, SProfile> &aProfile) {
    QList<FavoriteFriend> favoriteFriends = _favorites.friends();
    return std::any_of(favoriteFriends.begin(), favoriteFriends.end(), [=](const FavoriteFriend value) {
                                                                             return (value.friendId() == aProfile.second.steamID()) && (value.steamId() == _id);
                                                                         });
}
#define SystemEnd }

#define Filter {
void FormFriends::checkBoxOpenProfile_StateChanged(int aState) {
    _filterPublic.setFilterRegExp(aState == 2 ? "^" + tr("Публичный") + "$" : "");
    ui->TableFriends->resizeRowsToContents();
}

void FormFriends::comboBoxStatus_Activated(int aIndex) {
    _filterStatus.setFilterRegExp(aIndex == 0 ? "" : "^" + ui->ComboBoxStatus->currentText() + "$");
    ui->TableFriends->resizeRowsToContents();
}

void FormFriends::lineEditName_TextChanged(const QString &aNewText) {
    _filterName.setFilterRegExp(aNewText);
    ui->TableFriends->resizeRowsToContents();
}

void FormFriends::buttonFind_Clicked() {
    lineEditName_TextChanged(ui->LineEditName->text());
}

void FormFriends::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        _filterFavorite.setFilterRegExp("");
        break;
    }
    case 2: {
        QList<FavoriteFriend> favoriteFriends = _favorites.friends();
        QStringList list;
        for (const auto &favorite: qAsConst(favoriteFriends)) {
            list.append(favorite.friendId());
        }
        _filterFavorite.setFilterRegExp("(" + list.join(")|(") + ")");
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
    updateActionFavoriteData(actionFavorites, isProfileFavorite(aProfile));

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
    auto cFriend = currentFriend();
    QAction *action = dynamic_cast<QAction*>(sender());
    bool isFavorite = _favorites.addFriend(_id, cFriend.second, cFriend.first, true);
    if (action) {
        updateActionFavoriteData(action, isFavorite);
    }
}
#define TableActionEnd }
