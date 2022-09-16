#include "formfriends.h"
#include "ui_formfriends.h"
#include "classes/files/favorites.h"
#include "classes/common/images.h"

#include <QMenu>

#define Init {
FormFriends::FormFriends(QWidget *aParent): Form(aParent), ui(new Ui::FormFriends) {
    ui->setupUi(this);
    init();
}

void FormFriends::init() {
    initingTable(ui->tableFriends);
    initComboBoxStatus();
    ui->tableFriends->setModel(&filterFriends_);
    auto friendsModel = new FriendsModel(ui->tableFriends);
    connect(friendsModel, &FriendsModel::s_progress, this, &Form::setStatus);
    connect(&filterFriends_, &FilterModelFriends::s_modelFinished, this, [&]() {
        ui->tableFriends->resizeColumnsToContents();
        ui->tableFriends->resizeRowsToContents();
        clearStatus();
        emit s_finish(getWidthTableColumns(ui->tableFriends) + 23);//Почему-то при подсчёте длинна последнего 77, а как всё начинает ресайзиться, меняется на 100
    });
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 10);
    filterFriends_.setSourceModel(friendsModel);
    ui->tableFriends->setColumnHidden(friendsModel::ID,    true);
    ui->tableFriends->setColumnHidden(friendsModel::Index, true);
    updateIcons();
#define Connects {
    connect(ui->buttonFind,           &QPushButton::clicked,    this, &FormFriends::buttonFind_Clicked);
    connect(ui->comboBoxStatus,       SIGNAL(activated(int)),   this, SLOT(comboBoxStatus_Activated(int)));
    connect(ui->lineEditName,         &QLineEdit::textChanged,  this, &FormFriends::lineEditName_TextChanged);
    connect(ui->checkBoxOpenProfile,  &QCheckBox::stateChanged, this, [&](int lState) {
        filterFriends_.setIsPublic(lState);
        ui->tableFriends->resizeRowsToContents();
    });
    connect(ui->checkBoxFavorites,    &QCheckBox::stateChanged, this, &FormFriends::checkBoxFavorites_StateChanged);
    connect(ui->tableFriends,         &QTableView::customContextMenuRequested, this, [&](QPoint pos) {
        QMenu *menu = createMenu(currentFriend());
        menu->popup(ui->tableFriends->viewport()->mapToGlobal(pos));
    });
    connect(ui->tableFriends,         &QTableView::doubleClicked, this, [&](QModelIndex) {
        goToCurrentProfile();
    });
    connect(&filterFriends_, &FilterModel::s_rowsUpdated, this, [&]() {
        ui->tableFriends->resizeRowsToContents();
    });
#define ConnectsEnd }
}

void FormFriends::setFriends(const ProfileID &aProfileId) {
    clear();
    profileId_ = aProfileId;
    filterFriends_.sourceModel()->setFriends(SFriend::load(aProfileId));
}

void FormFriends::clear() {
    profileId_ = "";
    filterFriends_.clear();
    ui->comboBoxStatus->setCurrentIndex(0);
    isLoading_ = false;
}

bool FormFriends::isInit() {
    return ((profileId_ != "") && (ui->tableFriends->model()->rowCount() > 0));
}

void FormFriends::initComboBoxStatus() {
    int index = std::max(ui->comboBoxStatus->currentIndex(), 0);
    ui->comboBoxStatus->clear();
    ui->comboBoxStatus->addItems(QStringList{tr("Статус")} << SProfile::statesList());
    ui->comboBoxStatus->setCurrentIndex(index);
}

#define InitEnd }

#define System {
FormFriends::~FormFriends() {
    delete ui;
}

void FormFriends::retranslate() {
    ui->retranslateUi(this);
    initComboBoxStatus();
}

//void FormFriends::updateSettings(QFlags<changedSettings> aSettings) {
//    if (aSettings.testFlag(changedSettings::theme)) {
//        updateIcons();
//    }
//}

SFriendProfile FormFriends::currentFriend() {
    return filterFriends_.sourceModel()->getFriend(filterFriends_.data(ui->tableFriends->currentIndex().siblingAtColumn(friendsModel::Index)).toInt());
}

void FormFriends::updateIcons() {
    ui->buttonFind->setIcon(QIcon(Images::findProfile()));
}
#define SystemEnd }

#define Filter {
void FormFriends::comboBoxStatus_Activated(const int &aIndex) {
    filterFriends_.setStatus(aIndex == 0 ? "" : ui->comboBoxStatus->currentText());
}

void FormFriends::lineEditName_TextChanged(const QString &aNewText) {
    filterFriends_.setName(aNewText);
}

void FormFriends::buttonFind_Clicked() {
    lineEditName_TextChanged(ui->lineEditName->text());
}

void FormFriends::checkBoxFavorites_StateChanged(const int &arg1) {
    switch (arg1) {
    case 0: {
        filterFriends_.clearFavorites();
        break;
    }
    case 2: {
        QList<FavoriteProfile> favoriteProfile = FavoriteProfiles();
        QSet<ProfileID> profiles = std::accumulate(favoriteProfile.begin(),
                                                   favoriteProfile.end(),
                                                   QSet<ProfileID>(),
                                                   [&](QSet<ProfileID> lProfiles, const FavoriteProfile &lProfile) {
                                                        lProfiles.insert(lProfile.profileId());
                                                        return lProfiles;
                                                   });
        filterFriends_.setFavorites(profiles);
        break;
    }
    }
}
#define FilterEnd }

#define TableAction {
QMenu *FormFriends::createMenu(const SFriendProfile &aProfile) {
    QMenu *menu = new QMenu(this);

    QAction *actionGoToProfile = new QAction(tr("Перейти на профиль"), this);
    actionGoToProfile->setIcon(QIcon(Images::goTo()));
    connect (actionGoToProfile, &QAction::triggered, this, &FormFriends::goToCurrentProfile);

    QAction *actionFavorites = new QAction(this);

    QList<FavoriteProfile> favoriteFriends = FavoriteProfiles();
    bool isFavorite = std::any_of(favoriteFriends.begin(),
                                  favoriteFriends.end(),
                                  [&](const FavoriteProfile &lFriend) {
                                        return (lFriend.profileId() == aProfile.steamProfile.steamId());
                                    });
    if (isFavorite) {
        actionFavorites->setText(QObject::tr("Удалить из избранного"));
        actionFavorites->setIcon(QIcon(Images::isFavorites()));
        connect(actionFavorites, &QAction::triggered, this,  [=, this](){
                    auto curFriend = currentFriend();
                    FavoriteProfiles favoriteFriends;
                    favoriteFriends.remove(curFriend.steamProfile.steamId());
                    emit s_settingsUpdated(changedSettings::favorites);
                });
    } else {
        actionFavorites->setText(QObject::tr("Добавить в избранное"));
        actionFavorites->setIcon(QIcon(Images::isNotFavorites()));
        connect(actionFavorites, &QAction::triggered, this,  [=, this](){
                    auto curFriend = currentFriend();
                    FavoriteProfiles favoriteFriends;
                    favoriteFriends.append(FavoriteProfile(curFriend.steamProfile.steamId()));
                    emit s_settingsUpdated(changedSettings::favorites);
                });
    }

    menu -> addAction(actionGoToProfile);
    menu -> addAction(actionFavorites);
    return menu;
}

void FormFriends::goToCurrentProfile() {
    if(isLoading_) {
        return;
    }
    isLoading_ = true;
    emit s_goToProfile(currentFriend().steamProfile.steamId());
}
#define TableActionEnd }
