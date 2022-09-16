#include "formgames.h"
#include "ui_formgames.h"
#include "forms/formgroups.h"
#include "forms/formcomments.h"
#include "classes/common/generalfunctions.h"
#include "classes/files/favorites.h"
#include "classes/files/hiddengames.h"
#include "classes/common/images.h"

#include <QMessageBox>
#include <QMenu>

#define Init {
FormGames::FormGames(QWidget *aParent): Form(aParent), ui(new Ui::FormGames) {
    ui->setupUi(this);
    init();
}

void FormGames::init() {
    initingTable(ui->tableGames);
    auto games = new GamesModel(this);
    connect(games, &GamesModel::s_progress, this, &Form::setStatus);
    connect(&filterGames_, &FilterModelGames::s_modelFinished, this, [&]() {
        ui->tableGames->sortByColumn(gamesModel::Name, Qt::SortOrder::AscendingOrder);
        ui->tableGames->resizeColumnsToContents();
        if (ui->tableGames->columnWidth(gamesModel::Name) > 200) {
            ui->tableGames->setColumnWidth(gamesModel::Name, 200);
        }
        if (ui->tableGames->columnWidth(gamesModel::Comment) > 100) {
            ui->tableGames->setColumnWidth(gamesModel::Comment, 100);
        }
        ui->tableGames->resizeRowsToContents();
        updateGroups();
        updateHiddenGames();
        clearStatus();
        emit s_finish(getWidthTableColumns(ui->tableGames));
    });
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 10);
    filterGames_.setDynamicSortFilter(true);
    filterGames_.setSourceModel(games);
    ui->tableGames->setModel(&filterGames_);
    ui->tableGames->setColumnHidden(gamesModel::Appid, true);
    ui->tableGames->setColumnHidden(gamesModel::Index, true);
    updateIcons();
#define Connects {
    connect(ui->lineEditGame,       &QLineEdit::textChanged,                this, &FormGames::lineEditGame_TextChanged);
    connect(ui->buttonFind,         &QPushButton::clicked,                  this, &FormGames::buttonFind_Clicked);
    connect(ui->checkBoxFavorites,  &QCheckBox::stateChanged,               this, &FormGames::checkBoxFavorites_StateChanged);
    connect(ui->comboBoxGroups,     &MultiSelectComboBox::selectionChanged, this, &FormGames::updateGroupsFilter);
    connect(ui->tableGames,         &QTableView::customContextMenuRequested,this, [&](QPoint pos) {
        createMenu(currentGame())->popup(ui->tableGames->viewport()->mapToGlobal(pos));
    });
    connect(ui->tableGames,         &QTableView::doubleClicked,             this, [&](QModelIndex aIndex) {
        if (aIndex.column() == gamesModel::Comment) {
            showCommentsEdit();
        } else {
            buttonAchievements_Clicked();
        }
    });
    connect(&filterGames_, &FilterModel::s_rowsUpdated, this, [&]() {
        ui->tableGames->resizeRowsToContents();
    });
#define ConnectsEnd }
}

void FormGames::setGames(const ProfileID &aProfileId) {
    clear();
    profileId_ = aProfileId;
    filterGames_.sourceModel()->setGames(SGame::load(profileId_, true, true), profileId_);
}

void FormGames::setGames(const ProfileID &aProfileId, const SGames &aGames) {
    clear();
    profileId_ = aProfileId;
    filterGames_.sourceModel()->setGames(aGames, profileId_);
}
#define InitEnd }

#define FindDataInTable {
int FormGames::currentIndex() {
    return ui->tableGames->model()->data(ui->tableGames->currentIndex().siblingAtColumn(gamesModel::Index)).toInt();
}

SGame FormGames::currentGame() {
    return filterGames_.getGame(currentIndex());
}

SGames FormGames::currentGames() {
    auto selected = ui->tableGames->selectionModel()->selectedRows();
    SGames games;
    for (const auto &select: selected) {
        games << filterGames_.getGame(ui->tableGames->model()->data(select.siblingAtColumn(gamesModel::Index)).toInt());
    }
    return games;
}

QStringList FormGames::currentComment() {
    return filterGames_.getGameComment(currentIndex());
}

QList<SAchievementPlayer> FormGames::currentAchievements() {
    return filterGames_.getGameAchievements(currentIndex());
}
#define FindDataInTableEnd }

#define System {
FormGames::~FormGames() {
    delete ui;
}

void FormGames::retranslate() {
    ui->retranslateUi(this);
}

void FormGames::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::visibleHiddenGame)) {
        updateHiddenGames();
    }
    if (aSettings.testFlag(changedSettings::hiddenGame)) {
        updateHiddenGames();
    }
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}

void FormGames::updateIcons() {
    ui->buttonFind->setIcon(QIcon(Images::find()));
}

void FormGames::setEnable(const bool &isEnable) {
    ui->frameFilter->setEnabled(isEnable);
    ui->tableGames->setEnabled(isEnable);
}

bool FormGames::isInit() {
    return ((profileId_ != "") && (filterGames_.sourceModel()->rowCount() > 0));
}

void FormGames::updateGroups() {
    ui->comboBoxGroups->clear();
    GroupsGames groups(profileId_);
    for(const auto &group: groups) {
        ui->comboBoxGroups->addItem(group.title());
    }
}

void FormGames::updateHiddenGames() {
    HiddenGames hiddenGames(profileId_, true);
    QSet<GameID> hiddens;
    for (const auto &hide: hiddenGames) {
        hiddens.insert(hide.id());
    }
    qDebug() << 1 << hiddens;
    filterGames_.setHide(hiddens);
}

void FormGames::clear() {
    filterGames_.clear();
    profileId_ = "";
}
#define SystemEnd }

#define Filter {
void FormGames::lineEditGame_TextChanged(const QString &aFindText) {
    filterGames_.setName(aFindText);
}

void FormGames::buttonFind_Clicked() {
    lineEditGame_TextChanged(ui->lineEditGame->text());
}

void FormGames::checkBoxFavorites_StateChanged(const int &state) {
    switch (state) {
    case 0: {
        filterGames_.clearFavorites();
        break;
    }
    case 2: {
        FavoriteGames fileFavorites;
        QSet<GameID> favorites = std::accumulate(fileFavorites.begin(),
                                                 fileFavorites.end(),
                                                 QSet<GameID>(),
                                                 [&](QSet<GameID> lSet, const FavoriteGame &lGame) {
                                                     lSet.insert(lGame.appId());
                                                     return lSet;
                                                 });
        filterGames_.setFavorites(favorites);
        break;
    }
    }
}

void FormGames::updateGroupsFilter() {
    QStringList selectedGroups = ui->comboBoxGroups->currentText();
    if (selectedGroups.count() > 0 &&
        selectedGroups != QStringList{""}) {
        GroupsGames groups(profileId_);
        QSet<GameID> gameInGroup = std::accumulate(selectedGroups.begin(),
                                                   selectedGroups.end(),
                                                   QSet<GameID>(),
                                                   [&](QSet<GameID> lSet, const QString &lGroupTitle) {
                                                        auto iterator = std::find_if(groups.begin(),
                                                                                     groups.end(),
                                                                                     [&](const GroupGames &lGame) {
                                                                                        return lGame.title() == lGroupTitle;
                                                                                     });
                                                        if (iterator != groups.end()) {
                                                            auto games = (*iterator).games();
                                                            lSet = std::accumulate(games.begin(),
                                                                                   games.end(),
                                                                                   lSet,
                                                                                   [&](QSet<GameID> lSet, const int &lGameId) {
                                                                                        lSet.insert(lGameId);
                                                                                        return lSet;
                                                                                   });
                                                            }
                                                        return lSet;
                                                    });
        filterGames_.setGroup(gameInGroup);
    } else {
        filterGames_.clearGroup();
    }
}
#define FilterEnd }

#define Functions {
QMenu *FormGames::createMenu(const SGame &aGame) {
    //Добавление перехода на достижения
    QAction *actionAchievements = new QAction(QIcon(Images::achievement()), tr("Достижения"), this);

    //Добавление кнопки избранного
    QAction *actionFavorites;
    auto favorites = FavoriteGames();
    auto isGameFavorite = std::any_of(favorites.cbegin(),
                                    favorites.cend(),
                                    [&](FavoriteGame curGame) {
                                        return curGame.appId() == aGame.appId() &&
                                                curGame.steamId() == profileId_;
                                    });
    if(isGameFavorite) {
        actionFavorites = new QAction(QIcon(Images::isFavorites()), tr("Удалить из избранного"), this);
        actionFavorites->setObjectName("RemoveFavorite");
        connect (actionFavorites,       &QAction::triggered,    this,   [&](){
            FavoriteGames().remove(profileId_, currentGame().appId());
            emit s_settingsUpdated(changedSettings::favorites);
        });
    } else {
        actionFavorites = new QAction(QIcon(Images::isNotFavorites()), tr("Добавить в избранное"), this);
        actionFavorites->setObjectName("AddFavorite");
        connect (actionFavorites,       &QAction::triggered,    this,   [&](){
            FavoriteGames().append(FavoriteGame(profileId_, currentGame()));
            emit s_settingsUpdated(changedSettings::favorites);
        });
    }

    //Добавление кнопки сокрытия
    QAction *actionHide;
    actionHide = new QAction(QIcon(Images::hide()), tr("Скрыть игру"), this);

    //Добавление кнопки комментариев
    QAction *actionComment = new QAction(QIcon(Images::isComment()), tr("Редактировать комментарий...     "), this);

    //Добавление кнопки взаимодействия с группами
    QAction *actionGroup = new QAction(QIcon(Images::group1()), tr("Добавить/Удалить из группы...     "), this);

    QMenu *menu = new QMenu(this);
    menu->addAction (actionAchievements);
    menu->addAction (actionFavorites);
    menu->addAction (actionHide);
    menu->addAction (actionComment);
    menu->addAction (actionGroup);

    connect (actionAchievements,    &QAction::triggered,    this,   &FormGames::buttonAchievements_Clicked);
    connect (actionHide,            &QAction::triggered,    this,   &FormGames::buttonHide_Clicked);
    connect (actionComment,         &QAction::triggered,    this,   &FormGames::showCommentsEdit);
    connect (actionGroup,           &QAction::triggered,    this,   &FormGames::showGroupsEdit);

    return menu;
}

void FormGames::buttonAchievements_Clicked() {
    emit s_showAchievements(currentGame());
}

void FormGames::buttonHide_Clicked() {
    QMessageBox question(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите скрыть эту игру?"));
    QAbstractButton *btnProfile = question.addButton(tr("Для этого аккаунта"), QMessageBox::YesRole);
    QAbstractButton *btnAll = question.addButton(tr("Для всех"), QMessageBox::YesRole);
    question.addButton(tr("Отмена"), QMessageBox::NoRole);
    question.exec();

    auto curGame = currentGame();
    if(question.clickedButton() == btnProfile) {
        HiddenGames profile(profileId_);
        if (profile.isGameExist(curGame.appId())) {
            profile.removeIf([=](const HiddenGame &lGame) {
                return lGame.id() == curGame.appId();
            });
        } else {
            profile.append(HiddenGame(curGame));
        }
        profile.save();
    } else if(question.clickedButton() == btnAll) {
        HiddenGames all;
        auto iterator = std::find_if(all.begin(),
                                     all.end(),
                                     [=](const HiddenGame &lGame) {
                                         return curGame.appId() == lGame.id();
                                     });
        if (iterator == all.end()) {
            all.append(HiddenGame(curGame));
        } else {
            all.removeAt(iterator - all.begin());
        }
        all.save();
    }

    emit s_settingsUpdated(changedSettings::hiddenGame);
    updateHiddenGames();

    delete btnProfile;
    delete btnAll;
}

void FormGames::showGroupsEdit() {
    FormGroups *groups = new FormGroups(this);
    groups->setObjectName(QString("Groups%1").arg(profileId_));
    groups->setProfileGames(profileId_, currentGames());
    groups->setAttribute( Qt::WA_DeleteOnClose );
    QFrame *frame = createSubForm<FormGroups>(groups, this);
    connect(groups, &FormGroups::s_updateGroups,    this, &FormGames::updateGroups);
    connect(groups, &FormGroups::s_closed,          this, [this, frame]() {
        setEnable(true);
        delete frame->layout();
        delete frame;
    });
    setEnable(false);
}

void FormGames::showCommentsEdit() {
    FormComments *comments = new FormComments(this);
    comments->setObjectName(QString("Comments%1").arg(profileId_));
    comments->setData(profileId_, currentGame());
    comments->setAttribute( Qt::WA_DeleteOnClose );
    QFrame *frame = createSubForm<FormComments>(comments, this);

    connect(comments, &FormComments::s_updateComments,  filterGames_.sourceModel(), &GamesModel::updateComments);
    connect(comments, &FormComments::s_closed,          this,                       [this, frame](){
        setEnable(true);
        delete frame->layout();
        delete frame;
    });
    setEnable(false);
}
#define FunctionsEnd }
