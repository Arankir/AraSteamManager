#include "formgames.h"
#include "ui_formgames.h"

#define Init {
FormGames::FormGames(QWidget *aParent): Form(aParent), ui(new Ui::FormGames) {
    ui->setupUi(this);
    init();
}

void FormGames::init() {
    initingTable(ui->tableGames);
    auto games = new GamesModel(this);
    connect(games, &GamesModel::s_progress, this, &Form::setStatus);
    connect(&_filterGames, &FilterModelGames::s_modelFinished, this, [&]() {
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
        emit s_finish(getWidthTableColumns(ui->tableGames));
    });
    _filterGames.setSourceModel(games);
    ui->tableGames->setModel(&_filterGames);
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
    connect(&_filterGames, &FilterModel::s_rowsUpdated, this, [&]() {
        ui->tableGames->resizeRowsToContents();
    });
    connect(this, &Form::s_settingsUpdated, ui->lineEditGame, &MyLineEdit::updateSettings);
#define ConnectsEnd }
}

void FormGames::setGames(const ProfileID &aProfileId) {
    clear();
    _steamId = aProfileId;
    _filterGames.sourceModel()->setGames(SGame::load(_steamId, true, true), _steamId);
}
#define InitEnd }

#define FindDataInTable {
int FormGames::currentIndex() {
    return ui->tableGames->model()->data(ui->tableGames->currentIndex().siblingAtColumn(gamesModel::Index)).toInt();
}

SGame FormGames::currentGame() {
    return _filterGames.getGame(currentIndex());
}

QStringList FormGames::currentComment() {
    return _filterGames.getGameComment(currentIndex());
}

QList<SAchievementPlayer> FormGames::currentAchievements() {
    return _filterGames.getGameAchievements(currentIndex());
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
    if (aSettings.testFlag(changedSettings::visibleHiddenGame)) {
        updateHiddenGames();
    }
}

void FormGames::updateIcons() {
    ui->buttonFind->setIcon(QIcon(Images::find()));
}

void FormGames::setEnable(bool isEnable) {
    ui->groupBoxFilter->setEnabled(isEnable);
    ui->tableGames->setEnabled(isEnable);
}

bool FormGames::isInit() {
    return ((_steamId != "") && (_filterGames.sourceModel()->rowCount() > 0));
}

void FormGames::updateGroups() {
    ui->comboBoxGroups->clear();
    GroupsGames groups(_steamId);
    for(const auto &group: groups) {
        ui->comboBoxGroups->addItem(group.title());
    }
}

void FormGames::updateHiddenGames() {
    HiddenGames hiddenGames(_steamId, true);
    QSet<GameID> hiddens;
    for (const auto &hide: hiddenGames) {
        hiddens.insert(hide.id());
    }
    _filterGames.setHide(hiddens);
}

void FormGames::clear() {
    _filterGames.clear();
    _steamId = "";
}
#define SystemEnd }

#define Filter {
void FormGames::lineEditGame_TextChanged(const QString &aFindText) {
    _filterGames.setName(aFindText);
}

void FormGames::buttonFind_Clicked() {
    lineEditGame_TextChanged(ui->lineEditGame->text());
}

void FormGames::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        _filterGames.clearFavorites();
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
        _filterGames.setFavorites(favorites);
        break;
    }
    }
}

void FormGames::updateGroupsFilter() {
    QStringList selectedGroups = ui->comboBoxGroups->currentText();
    if (selectedGroups.count() > 0 &&
        selectedGroups != QStringList{""}) {
        GroupsGames groups(_steamId);
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
        _filterGames.setGroup(gameInGroup);
    } else {
        _filterGames.clearGroup();
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
                                                curGame.steamId() == _steamId;
                                    });
    if(isGameFavorite) {
        actionFavorites = new QAction(QIcon(Images::isFavorites()), tr("Удалить из избранного"), this);
        actionFavorites->setObjectName("RemoveFavorite");
        connect (actionFavorites,       &QAction::triggered,    this,   [&](){
            FavoriteGames().remove(_steamId, currentGame());
        });
    } else {
        actionFavorites = new QAction(QIcon(Images::isNotFavorites()), tr("Добавить в избранное"), this);
        actionFavorites->setObjectName("AddFavorite");
        connect (actionFavorites,       &QAction::triggered,    this,   [&](){
            FavoriteGames().append(FavoriteGame(_steamId, currentGame()));
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
        HiddenGames profile(_steamId);
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

    updateHiddenGames();

    delete btnProfile;
    delete btnAll;
}

void FormGames::showGroupsEdit() {
    FormGroups *groups = new FormGroups(this);
    groups->setObjectName(QString("Groups%1").arg(_steamId));
    groups->setProfileGame(_steamId, currentGame());
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
    comments->setObjectName(QString("Comments%1").arg(_steamId));
    comments->setData(_steamId, currentGame());
    comments->setAttribute( Qt::WA_DeleteOnClose );
    QFrame *frame = createSubForm<FormComments>(comments, this);

    connect(comments, &FormComments::s_updateComments,  _filterGames.sourceModel(), &GamesModel::updateComments);
    connect(comments, &FormComments::s_closed,          this,                       [this, frame](){
        setEnable(true);
        delete frame->layout();
        delete frame;
    });
    setEnable(false);
}
#define FunctionsEnd }
