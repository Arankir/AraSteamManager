#include "formfriends.h"
#include "ui_formfriends.h"

#define Constants {
constexpr int c_tableColumnID       = 0;
constexpr int c_tableColumnIndex    = 1;
constexpr int c_tableColumnIcon     = 2;
constexpr int c_tableColumnName     = 3;
constexpr int c_tableColumnAdded    = 4;
constexpr int c_tableColumnStatus   = 5;
constexpr int c_tableColumnisPublic = 6;
constexpr int c_tableColumnCount    = 7;

constexpr int c_filterName          = 0;
constexpr int c_filterStatus        = 1;
constexpr int c_filterPublic        = 2;
constexpr int c_filterFavorites     = 3;
constexpr int c_filterCount         = 4;
#define ConstantsEnd }

#define Init {
FormFriends::FormFriends(const QString &aId, SFriends &aFriends, QWidget *aParent): QWidget(aParent), ui(new Ui::FormFriends), _id(aId), _filter(aFriends.count(), c_filterCount) {
    ui->setupUi(this);
    init();
    setFriends(aId, aFriends);
}

FormFriends::FormFriends(QWidget *aParent): QWidget(aParent), ui(new Ui::FormFriends), _filter(0, c_filterCount) {
    ui->setupUi(this);
    init();
}

void FormFriends::init() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    initTable();
//    setFont(QFont(Settings::defaultFont()));
    setIcons();
#define Connects {
    connect(ui->ButtonFind,           &QPushButton::clicked,    this, &FormFriends::buttonFind_Clicked);
    connect(ui->ComboBoxStatus,       SIGNAL(activated(int)),   this, SLOT(comboBoxStatus_Activated(int)));
    connect(ui->LineEditName,         &QLineEdit::textChanged,  this, &FormFriends::lineEditName_TextChanged);
    connect(ui->CheckBoxOpenProfile,  &QCheckBox::stateChanged, this, &FormFriends::checkBoxOpenProfile_StateChanged);
    connect(ui->CheckBoxFavorites,    &QCheckBox::stateChanged, this, &FormFriends::checkBoxFavorites_StateChanged);
#define ConnectsEnd }
}

void FormFriends::setFriends(const QString &aId, SFriends &aFriends) {
    _blockedLoad = false;
    _loaded = false;
    _id = aId;
    _filter.setRow(aFriends.count());
    initFriends(aFriends);
    createThread();
}

void FormFriends::clear() {
    _blockedLoad = false;
    _loaded = false;
    _id = "";
    _filter.setRow(0);
    _friends.clear();
}

bool FormFriends::isInit() {
    return ((_id != "") && (_friends.count() > 0) && (_loaded == true));
}

bool FormFriends::isLoaded() {
    return _loaded;
}

void FormFriends::initFriends(SFriends &aFriends) {
    SFriends friends(aFriends);
    SProfiles profiles(friends.profiles());
    profiles.sort();
    for(auto &profile: profiles) {
        for (auto &currentFriend: friends) {
            if (currentFriend.steamId() == profile.steamID()) {
                _friends.append(QPair<SFriend, SProfile>(currentFriend, profile));
                break;
            }
        }
    }
}

void FormFriends::initTable() {
    ui->TableFriends->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
    ui->TableFriends->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

    ui->TableFriends->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TableFriends->setShowGrid(false);
    ui->TableFriends->setSortingEnabled(true);
    ui->TableFriends->horizontalHeader()->setStretchLastSection(true);
    ui->TableFriends->verticalHeader()->setVisible(false);
    ui->TableFriends->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->TableFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->TableFriends, &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
        updateCurrentFriend();
        QMenu *menu = createMenu(*_currentFriend);
        menu->popup(ui->TableFriends->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableFriends, &QTableView::doubleClicked, this, [=](QModelIndex) {
        updateCurrentFriend();
        goToProfile();
    });
}

void FormFriends::initComboBoxStatus() {
    ui->ComboBoxStatus->clear();
    ui->ComboBoxStatus->addItems(QStringList()<<tr("Статус") <<tr("В игре") <<tr("Не в сети") <<tr("В сети") <<tr("Не беспокоить")
                                              <<tr("Нет на месте") <<tr("Спит") <<tr("Ожидает обмена") <<tr("Хочет поиграть"));
}

void FormFriends::createThread() {
    Threading *threadLoadTable = new Threading(this);
    threadLoadTable->AddThreadFriends(c_tableColumnID, c_tableColumnIndex, c_tableColumnIcon, c_tableColumnName, c_tableColumnAdded, c_tableColumnStatus, c_tableColumnisPublic, _friends);
    connect (threadLoadTable, &Threading::s_friends_progress, this, [=](int progress, int row) {
                                                                        emit s_friendsLoaded(progress, row);
                                                                    });
    connect (threadLoadTable, &Threading::s_friends_finished_model, this, &FormFriends::setTableModel);
}

void FormFriends::setTableModel(QStandardItemModel *aModel) {
    ui->TableFriends->setModel(aModel);
    ui->TableFriends->setColumnHidden(c_tableColumnID,    true);
    ui->TableFriends->setColumnHidden(c_tableColumnIndex, true);

    retranslate();

    aModel->horizontalHeaderItem(c_tableColumnName)      ->setTextAlignment(Qt::AlignLeft);
    aModel->horizontalHeaderItem(c_tableColumnAdded)     ->setTextAlignment(Qt::AlignLeft);
    aModel->horizontalHeaderItem(c_tableColumnStatus)    ->setTextAlignment(Qt::AlignLeft);
    aModel->horizontalHeaderItem(c_tableColumnisPublic)  ->setTextAlignment(Qt::AlignLeft);

    aModel->horizontalHeaderItem(c_tableColumnName)      ->setTextAlignment(Qt::AlignVCenter);
    aModel->horizontalHeaderItem(c_tableColumnAdded)     ->setTextAlignment(Qt::AlignVCenter);
    aModel->horizontalHeaderItem(c_tableColumnStatus)    ->setTextAlignment(Qt::AlignVCenter);
    aModel->horizontalHeaderItem(c_tableColumnisPublic)  ->setTextAlignment(Qt::AlignVCenter);

    ui->TableFriends->resizeColumnsToContents();
    ui->TableFriends->resizeRowsToContents();

    _loaded = true;
    emit s_finish();
}
#define InitEnd }

#define System {
FormFriends::~FormFriends() {
    qInfo() << "Форма друзей удалилась";
    delete ui;
}

void FormFriends::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormFriends::closeEvent(QCloseEvent*) {
    emit s_returnToProfile(this);
    //delete this;
}

void FormFriends::retranslate() {
    ui->retranslateUi(this);
    initComboBoxStatus();

    if (ui->TableFriends->model() != nullptr) {
        ui->TableFriends->model()->setHeaderData(c_tableColumnIcon,        Qt::Horizontal, tr(""));
        ui->TableFriends->model()->setHeaderData(c_tableColumnName,        Qt::Horizontal, tr("   НИК"));
        ui->TableFriends->model()->setHeaderData(c_tableColumnAdded,       Qt::Horizontal, tr("   ДОБАВЛЕН"));
        ui->TableFriends->model()->setHeaderData(c_tableColumnStatus,      Qt::Horizontal, tr("   СТАТУС"));
        ui->TableFriends->model()->setHeaderData(c_tableColumnisPublic,    Qt::Horizontal, tr("   ПРОФИЛЬ"));
    }
}

void FormFriends::updateSettings() {
    Settings::syncronizeSettings();
    setIcons();
}

void FormFriends::updateCurrentFriend() {
    _currentFriend = getFriendFromRow(ui->TableFriends->currentIndex().row());
}

QPair<SFriend, SProfile> *FormFriends::getFriendFromRow(int aRow) {
    QModelIndex IdIndex = ui->TableFriends->model()->index(aRow, c_tableColumnID);
    QString id = ui->TableFriends->model()->data(IdIndex).toString();
    auto iterator = std::find_if(_friends.begin(), _friends.end(), [=](const QPair<SFriend, SProfile> &aProfile) {
                                                                        return aProfile.second.steamID() == id;
                                                                    });
    if (iterator != _friends.end()) {
        return &*iterator;
    } else {
        qWarning() << "didn't find friend" << id;
    }
    return nullptr;
}

int FormFriends::getCurrentFriendIndex() {
    return getIndexFriendFromRow(ui->TableFriends->currentIndex().row());
}

int FormFriends::getIndexFriendFromRow(int aRow) {
    QModelIndex IdIndex = ui->TableFriends->model()->index(aRow, c_tableColumnIndex);
    return ui->TableFriends->model()->data(IdIndex).toInt();
}

int FormFriends::getRowFromIndexFriend(int aIndex) {
    for (int i = 0; i < ui->TableFriends->model()->rowCount(); ++i) {
        QModelIndex IdIndex = ui->TableFriends->model()->index(i, c_tableColumnIndex);
        if (ui->TableFriends->model()->data(IdIndex).toInt() == aIndex) {
            return i;
        }
    }
    return -1;
}

void FormFriends::setIcons() {
    ui->ButtonFind->setIcon(QIcon(Images::findProfile()));
}

void FormFriends::updateHiddenRows() {
    for (int i = 0; i < ui->TableFriends->model()->rowCount(); ++i) {
        ui->TableFriends->setRowHidden(getRowFromIndexFriend(i), !_filter.getData(i));
    }
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
    switch (aState) {
    case 0: {
        for (int i = 0; i < _friends.count(); ++i) {
            _filter.setData(i, c_filterPublic, true);
        }
        break;
    }
    case 2: {
        for (int i = 0; i < _friends.count(); ++i) {
            int index = getIndexFriendFromRow(i);
            _filter.setData(index, c_filterPublic, _friends[index].second.communityVisibilityState() == 3);
        }
    }
    }
    updateHiddenRows();
}

void FormFriends::comboBoxStatus_Activated(int aIndex) {
    switch (aIndex) {
    case 0: {
        for (int i = 0; i < _friends.count(); ++i) {
            _filter.setData(i, c_filterStatus, true);
        }
        break;
    }
    case 1: {
        for (int i = 0; i < _friends.count(); ++i) {
            int index = getIndexFriendFromRow(i);
            _filter.setData(index, c_filterStatus, !_friends[index].second.gameExtraInfo().isEmpty());
        }
        break;
    }
    default: {
        for (int i = 0; i < _friends.count(); ++i) {
            int index = getIndexFriendFromRow(i);
            _filter.setData(index, c_filterStatus, (_friends[index].second.personaState() == ui->ComboBoxStatus->currentIndex() - 2) && (_friends[index].second.gameExtraInfo().isEmpty()));
        }
    }
    }
    updateHiddenRows();
}

void FormFriends::lineEditName_TextChanged(const QString &aNewText) {
    for (int i = 0; i < _friends.count(); ++i) {
        int index = getIndexFriendFromRow(i);
        _filter.setData(index, c_filterName, _friends[index].second.personaName().toLower().indexOf(aNewText.toLower()) > -1);
    }
    updateHiddenRows();
}

void FormFriends::buttonFind_Clicked() {
    lineEditName_TextChanged(ui->LineEditName->text());
}

void FormFriends::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        for (int i = 0; i < _friends.count(); ++i) {
            _filter.setData(i, c_filterFavorites, true);
        }
        break;
    }
    case 2: {
        for (int i = 0; i < _friends.count(); ++i) {
            int index = getIndexFriendFromRow(i);
            _filter.setData(index, c_filterFavorites, isProfileFavorite(_friends[index]));
        }
        break;
    }
    }
    updateHiddenRows();
}
#define FilterEnd }

#define TableAction {
QMenu *FormFriends::createMenu(const QPair<SFriend, SProfile> &aProfile) {
    QMenu *menu = new QMenu(this);

    QAction *actionGoToProfile = new QAction(tr("Перейти на профиль"), this);
    actionGoToProfile->setIcon(QIcon(Images::goTo()));

    QAction *actionFavorites = new QAction(this);
    updateActionFavoriteData(actionFavorites, isProfileFavorite(aProfile));

    connect (actionFavorites,   &QAction::triggered, this, &FormFriends::friendToFavorite);
    connect (actionGoToProfile, &QAction::triggered, this, &FormFriends::goToProfile);

    menu -> addAction (actionGoToProfile);
    menu -> addAction (actionFavorites);
    return menu;
}

void FormFriends::updateActionFavoriteData(QAction *aAction, bool aIsFavorite) {
    if (aIsFavorite) {
        aAction->setText(tr("Удалить из избранного"));
        aAction->setIcon(QIcon(Images::isFavorites()));
    } else {
        aAction->setText(tr("Добавить в избранное"));
        aAction->setIcon(QIcon(Images::isNotFavorites()));
    }
}

void FormFriends::goToProfile() {
    if(_blockedLoad) {
        return;
    }
    _blockedLoad = true;
    if (_currentFriend == nullptr) {
        updateCurrentFriend();
    }
    emit s_goToProfile(_currentFriend->second.steamID(), ProfileUrlType::id);
}

void FormFriends::friendToFavorite() {
    if (_currentFriend == nullptr) {
        updateCurrentFriend();
    }
    QAction *action = dynamic_cast<QAction*>(sender());
    bool isFavorite = _favorites.addFriend(_id, _currentFriend->second, _currentFriend->first, true);
    if (action) {
        updateActionFavoriteData(action, isFavorite);
    }
}
#define TableActionEnd }
