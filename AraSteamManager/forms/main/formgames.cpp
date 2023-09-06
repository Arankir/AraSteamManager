#include "formgames.h"
#include "ui_formgames.h"
#include "forms/formgroups.h"
#include "forms/formcomments.h"
#include "classes/common/generalfunctions.h"
#include "classes/files/favorites.h"
#include "classes/common/images.h"

#include <QMessageBox>
#include <QMenu>

#define Init {
FormGames::FormGames(QWidget *aParent): Form(aParent), ui(new Ui::FormGames) {
    ui->setupUi(this);
    init();
}

void FormGames::init() {
    GamesModel *games = new GamesModel(ui->tableGames);
    FilterModelGames *filter = new FilterModelGames(ui->tableGames);
    ui->tableGames->setModel(games);
    ui->tableGames->setFilter(filter);
    connect(games, &GamesModel::s_progress, this, &Form::setStatus);
    connect(filter, &FilterModelGames::s_modelFinished, this, [&]() {
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
        clearStatus();
        emit s_finish(ui->tableGames->widthColumns());
    });
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 10);
    filter->setDynamicSortFilter(true);
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
    connect(filter, &FilterModel::s_rowsUpdated, this, [&]() {
        ui->tableGames->resizeRowsToContents();
    });
#define ConnectsEnd }
}

void FormGames::setGames(const ProfileID &aProfileId) {
    clear();
    profileId_ = aProfileId;
    if (auto model = dynamic_cast<GamesModel*>(ui->tableGames->originalModel())) {
        model->setGames(SGame::load(profileId_, true, true), profileId_);
    }
}

void FormGames::setGames(const ProfileID &aProfileId, const SGames &aGames) {
    clear();
    profileId_ = aProfileId;
    if (auto model = dynamic_cast<GamesModel*>(ui->tableGames->originalModel())) {
        model->setGames(aGames, profileId_);
    }
}
#define InitEnd }

#define FindDataInTable {
int FormGames::currentIndex() {
    return ui->tableGames->model()->data(ui->tableGames->currentIndex().siblingAtColumn(gamesModel::Index)).toInt();
}

SGame FormGames::currentGame() {
    if (auto model = dynamic_cast<GamesModel*>(ui->tableGames->originalModel())) {
        return model->getGame(currentIndex());
    }
    return SGame();
}

SGames FormGames::currentGames() {
    QModelIndexList selected = ui->tableGames->selectionModel()->selectedRows();
    SGames games;
    if (auto filter = dynamic_cast<FilterModelGames*>(ui->tableGames->filter())) {
        for (const QModelIndex &select: selected) {
            games << filter->getGame(ui->tableGames->model()->data(select.siblingAtColumn(gamesModel::Index)).toInt());
        }
    }
    return games;
}

QStringList FormGames::currentComment() {
    if (auto filter = dynamic_cast<FilterModelGames*>(ui->tableGames->filter())) {
        filter->getGameComment(currentIndex());
    }
    return QStringList();
}

QList<SAchievementPlayer> FormGames::currentAchievements() {
    if (auto filter = dynamic_cast<FilterModelGames*>(ui->tableGames->filter())) {
        filter->getGameAchievements(currentIndex());
    }
    return QList<SAchievementPlayer>();
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
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}

void FormGames::updateIcons() {
    ui->buttonFind->setIcon(QIcon(Images::find()));
}

void FormGames::setEnable(bool isEnable) {
    ui->frameFilter->setEnabled(isEnable);
    ui->comboBoxGroups->setEnabled(isEnable);
    ui->splitter->setEnabled(isEnable);
    ui->tableGames->setEnabled(isEnable);
}

bool FormGames::isInit() {
    if (auto model = dynamic_cast<GamesModel*>(ui->tableGames->originalModel())) {
        return ((profileId_ != "") && (model->rowCount() > 0));
    }
    return false;
}

void FormGames::updateGroups() {
    ui->comboBoxGroups->clear();
    GroupsGames groups(profileId_);
    for(const GroupGames &group: groups) {
        ui->comboBoxGroups->addItem(group.title());
    }
}

void FormGames::clear() {
    if (auto filter = dynamic_cast<FilterModelGames*>(ui->tableGames->filter())) {
        filter->clear();
    }
    profileId_ = "";
}
#define SystemEnd }

#define Filter {
void FormGames::lineEditGame_TextChanged(const QString &aFindText) {
    if (auto filter = dynamic_cast<FilterModelGames*>(ui->tableGames->filter())) {
        filter->setName(aFindText);
    }
}

void FormGames::buttonFind_Clicked() {
    lineEditGame_TextChanged(ui->lineEditGame->text());
}

void FormGames::checkBoxFavorites_StateChanged(int state) {
    auto filter = dynamic_cast<FilterModelGames*>(ui->tableGames->filter());
    if (!filter) {
        return;
    }
    switch (state) {
    case Qt::Unchecked: {
        filter->clearFavorites();
        break;
    }
    case Qt::Checked: {
        FavoriteGames fileFavorites;
        QSet<GameID> favorites = std::accumulate(fileFavorites.begin(),
                                                 fileFavorites.end(),
                                                 QSet<GameID>(),
                                                 [&](QSet<GameID> lSet, const FavoriteGame &lGame) {
                                                     lSet.insert(lGame.appId());
                                                     return lSet;
                                                 });
        filter->setFavorites(favorites);
        break;
    }
    }
}

void FormGames::updateGroupsFilter() {
    auto filter = dynamic_cast<FilterModelGames*>(ui->tableGames->filter());
    if (!filter) {
        return;
    }
    QStringList selectedGroups = ui->comboBoxGroups->currentText();
    if (selectedGroups.count() > 0 &&
        selectedGroups != QStringList{""}) {
        GroupsGames groups(profileId_);
        QSet<GameID> gameInGroup = std::accumulate(selectedGroups.begin(),
                                                   selectedGroups.end(),
                                                   QSet<GameID>(),
                                                   [&](QSet<GameID> lSet, const QString &lGroupTitle) {
                                                        auto it = groups.find(lGroupTitle);
                                                        if (it != groups.end()) {
                                                            lSet += (*it);
                                                        }
                                                        return lSet;
                                                   });
        filter->setGroup(gameInGroup);
    } else {
        filter->clearGroup();
    }
}
#define FilterEnd }

#define Functions {
QMenu *FormGames::createMenu(const SGame &aGame) {
    //Добавление перехода на достижения
    QAction *actionAchievements = new QAction(QIcon(Images::achievement()), tr("Достижения"), this);

    //Добавление кнопки избранного
    QAction *actionFavorites;
    FavoriteGames favorites = FavoriteGames();
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

    //Добавление кнопки комментариев
    QAction *actionComment = new QAction(QIcon(Images::isComment()), tr("Редактировать комментарий...     "), this);

    //Добавление кнопки взаимодействия с группами
    QAction *actionGroup = new QAction(QIcon(Images::group1()), tr("Добавить/Удалить из группы...     "), this);

    QMenu *menu = new QMenu(this);
    menu->addAction (actionAchievements);
    menu->addAction (actionFavorites);
    menu->addAction (actionComment);
    menu->addAction (actionGroup);

    connect (actionAchievements,    &QAction::triggered,    this,   &FormGames::buttonAchievements_Clicked);
    connect (actionComment,         &QAction::triggered,    this,   &FormGames::showCommentsEdit);
    connect (actionGroup,           &QAction::triggered,    this,   &FormGames::showGroupsEdit);

    return menu;
}

void FormGames::buttonAchievements_Clicked() {
    emit s_showAchievements(currentGame());
}

void FormGames::showGroupsEdit() {
    FormGroups *groups = new FormGroups(this);
    groups->setObjectName(QString("Groups%1").arg(profileId_));
    groups->setProfileGames(profileId_, currentGames());
    groups->setAttribute( Qt::WA_DeleteOnClose );

    SubForm *form = new SubForm(groups, this);
    form->show();

    connect(groups, &FormGroups::s_updateGroups,    this, &FormGames::updateGroups);
    connect(groups, &FormGroups::s_closed,          this, [this, form]() {
        setEnable(true);
        delete form;
    });
    setEnable(false);
}

void FormGames::showCommentsEdit() {
    FormComments *comments = new FormComments(this);
    comments->setObjectName(QString("Comments%1").arg(profileId_));
    comments->setData(profileId_, currentGame());
    comments->setAttribute( Qt::WA_DeleteOnClose );

    SubForm *form = new SubForm(comments, this);
    form->show();

    if (auto model = dynamic_cast<GamesModel*>(ui->tableGames->originalModel())) {
        connect(comments, &FormComments::s_updateComments,  model, &GamesModel::updateComments);
    }

    connect(comments, &FormComments::s_closed, this, [this, form]() {
        setEnable(true);
        delete form;
    });
    setEnable(false);
}
#define FunctionsEnd }
