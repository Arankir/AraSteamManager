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
    initComboBoxStatus();
    FriendsModel *friendsModel = new FriendsModel(ui->tableFriends);
    FilterModelFriends *filter = new FilterModelFriends();
    connect(friendsModel, &FriendsModel::s_progress, this, &Form::setStatus);
    connect(filter, &FilterModelFriends::s_modelFinished, this, [&]() {
        ui->tableFriends->resizeColumnsToContents();
        ui->tableFriends->resizeRowsToContents();
        clearStatus();
        emit s_finish(ui->tableFriends->widthColumns() + 23);//Почему-то при подсчёте длинна последнего 77, а как всё начинает ресайзиться, меняется на 100
    });
    ui->tableFriends->setFilter(filter);
    ui->tableFriends->setModel(friendsModel);
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 10);
    ui->tableFriends->setColumnHidden(friendsModel::ID,    true);
    ui->tableFriends->setColumnHidden(friendsModel::Index, true);
    updateIcons();
#define Connects {
    connect(ui->buttonFind,           &QPushButton::clicked,    this, &FormFriends::buttonFind_Clicked);
    connect(ui->comboBoxStatus,       SIGNAL(activated(int)),   this, SLOT(comboBoxStatus_Activated(int)));
    connect(ui->lineEditName,         &QLineEdit::textChanged,  this, &FormFriends::lineEditName_TextChanged);
    connect(ui->checkBoxOpenProfile,  &QCheckBox::stateChanged, this, [&](int lState) {
        filter->setIsPublic(lState);
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
    connect(filter, &FilterModel::s_rowsUpdated, this, [&]() {
        ui->tableFriends->resizeRowsToContents();
    });
#define ConnectsEnd }
}

void FormFriends::setFriends(const ProfileID &aProfileId) {
    clear();
    qDebug() << __FUNCTION__ << " " << aProfileId;
    profileId_ = aProfileId;
    auto m = dynamic_cast<FriendsModel*>(ui->tableFriends->originalModel());
    if (m) {
        m->setFriends(SFriend::load(aProfileId));
    }
//    filterFriends_.sourceModel()->setFriends(SFriend::load(aProfileId));
}

void FormFriends::clear() {
    profileId_ = "";
    ui->tableFriends->filter()->clear();
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

FriendsModel::item FormFriends::currentFriend() {
    return dynamic_cast<FriendsModel*>(ui->tableFriends->originalModel())->getFriend(ui->tableFriends->filter()->data(ui->tableFriends->currentIndex().siblingAtColumn(friendsModel::Index)).toInt());
}

void FormFriends::updateIcons() {
    ui->buttonFind->setIcon(QIcon(Images::findProfile()));
}
#define SystemEnd }

#define Filter {
void FormFriends::comboBoxStatus_Activated(int aIndex) {
    dynamic_cast<FilterModelFriends*>(ui->tableFriends->filter())->setStatus(aIndex == 0 ? "" : ui->comboBoxStatus->currentText());
}

void FormFriends::lineEditName_TextChanged(const QString &aNewText) {
    dynamic_cast<FilterModelFriends*>(ui->tableFriends->filter())->setName(aNewText);
}

void FormFriends::buttonFind_Clicked() {
    lineEditName_TextChanged(ui->lineEditName->text());
}

void FormFriends::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case Qt::Unchecked: {
        dynamic_cast<FilterModelFriends*>(ui->tableFriends->filter())->clearFavorites();
        break;
    }
    case Qt::Checked: {
        QList<FavoriteProfile> favoriteProfile = FavoriteProfiles();
        QSet<ProfileID> profiles = std::accumulate(favoriteProfile.begin(),
                                                   favoriteProfile.end(),
                                                   QSet<ProfileID>(),
                                                   [&](QSet<ProfileID> lProfiles, const FavoriteProfile &lProfile) {
                                                        lProfiles.insert(lProfile.profileId());
                                                        return lProfiles;
                                                   });
        dynamic_cast<FilterModelFriends*>(ui->tableFriends->filter())->setFavorites(profiles);
        break;
    }
    }
}
#define FilterEnd }

#define TableAction {
QMenu *FormFriends::createMenu(const FriendsModel::item &aProfile) {
    QMenu *menu = new QMenu(this);

    QAction *actionGoToProfile = new QAction(tr("Перейти на профиль"), this);
    actionGoToProfile->setIcon(QIcon(Images::goTo()));
    connect (actionGoToProfile, &QAction::triggered, this, &FormFriends::goToCurrentProfile);

    QAction *actionFavorites = new QAction(this);

    QList<FavoriteProfile> favoriteFriends = FavoriteProfiles();
    bool isFavorite = std::any_of(favoriteFriends.begin(),
                                  favoriteFriends.end(),
                                  [&](const FavoriteProfile &lFriend) {
                                        return (lFriend.profileId() == aProfile.profile.steamId());
                                    });
    if (isFavorite) {
        actionFavorites->setText(QObject::tr("Удалить из избранного"));
        actionFavorites->setIcon(QIcon(Images::isFavorites()));
        connect(actionFavorites, &QAction::triggered, this,  [=, this](){
                    FavoriteProfiles favoriteFriends;
                    favoriteFriends.remove(currentFriend().profile.steamId());
                    emit s_settingsUpdated(changedSettings::favorites);
                });
    } else {
        actionFavorites->setText(QObject::tr("Добавить в избранное"));
        actionFavorites->setIcon(QIcon(Images::isNotFavorites()));
        connect(actionFavorites, &QAction::triggered, this,  [=, this](){
                    FavoriteProfiles favoriteFriends;
                    favoriteFriends.append(FavoriteProfile(currentFriend().profile.steamId()));
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
    emit s_goToProfile(currentFriend().profile.steamId());
}
#define TableActionEnd }
