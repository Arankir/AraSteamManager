#include "formfriends.h"
#include "ui_formfriends.h"

#define Init {
FormFriends::FormFriends(const QString &aId, SFriends &aFriends, QWidget *aParent):
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

void FormFriends::setFriends(const QString &aId, const SFriends &aFriends) {
    clear();
    _id = aId;
    if (_filterFriends.sourceModel()) {
        delete _filterFriends.sourceModel();
    }
    auto friendsModel = new FriendsModel(ui->TableFriends);
    connect(friendsModel, &FriendsModel::s_progress, this, &Form::setStatus);
    connect(friendsModel, &FriendsModel::s_finished, this, [=]() {
        _filterFriends.setSourceModel(friendsModel);
        ui->TableFriends->setColumnHidden(FriendsID,    true);
        ui->TableFriends->setColumnHidden(FriendsIndex, true);
        ui->TableFriends->resizeColumnsToContents();
        ui->TableFriends->resizeRowsToContents();
        int width = 0;
        for (int i = 0; i < ui->TableFriends->model()->columnCount(); ++i) {
            if (!ui->TableFriends->isColumnHidden(i)) {
                width += ui->TableFriends->columnWidth(i);
            }
        }
        emit s_finish(width + 32);
    });
    friendsModel->setFriends(aFriends);

    retranslate();

}

void FormFriends::clear() {
    _id = "";
    _filterFriends.clear();
    ui->ComboBoxStatus->setCurrentIndex(0);
    _isLoading = false;
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
}

void FormFriends::updateSettings(QFlags<changedSettings> aSettings) {
    Settings::syncronizeSettings();
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}

SFriendProfile FormFriends::currentFriend() {
    return _filterFriends.sourceModel()->getFriend(_filterFriends.data(ui->TableFriends->currentIndex().siblingAtColumn(FriendsIndex)).toInt());
}

void FormFriends::updateIcons() {
    ui->ButtonFind->setIcon(QIcon(Images::findProfile()));
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
            list.append(favorite.friendId());
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

QMenu *FormFriends::createMenu(const SFriendProfile &aProfile) {
    QMenu *menu = new QMenu(this);

    QAction *actionGoToProfile = new QAction(tr("Перейти на профиль"), this);
    actionGoToProfile->setIcon(QIcon(Images::goTo()));

    QAction *actionFavorites = new QAction(this);

    QList<FavoriteFriend> favoriteFriends = Favorites::friends();
    bool isFavorite = std::any_of(favoriteFriends.begin(),
                                  favoriteFriends.end(),
                                  [&](const FavoriteFriend &lFriend) {
                                        return (lFriend.friendId() == aProfile.steamProfile.steamID()) &&
                                                (lFriend.steamId() == _id);
                                    });
    updateActionFavoriteData(actionFavorites, isFavorite);

    connect (actionFavorites,   &QAction::triggered, this, &FormFriends::friendToFavorite);
    connect (actionGoToProfile, &QAction::triggered, this, &FormFriends::goToCurrentProfile);

    menu -> addAction (actionGoToProfile);
    menu -> addAction (actionFavorites);
    return menu;
}

void FormFriends::goToCurrentProfile() {
    if(_isLoading) {
        return;
    }
    _isLoading = true;
    emit s_goToProfile(currentFriend().steamProfile.steamID(), SProfile::LoadType::id);
}

void FormFriends::friendToFavorite() {
    auto curFriend = currentFriend();
    bool isFavorite = Favorites::addFriend(_id, curFriend.steamProfile, curFriend.steamFriend, true);
    if (QAction *action = dynamic_cast<QAction*>(sender())) {
        updateActionFavoriteData(action, isFavorite);
    }
}
#define TableActionEnd }
