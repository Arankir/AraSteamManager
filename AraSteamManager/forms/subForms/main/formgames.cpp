#include "formgames.h"
#include "ui_formgames.h"

#define Init {
FormGames::FormGames(QWidget *aParent): Form(aParent), ui(new Ui::FormGames) {
    ui->setupUi(this);
    init();
}

void FormGames::init() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->ProgressBarLoading->setVisible(false);
    initingTable(ui->TableGames);
    updateIcons();

#define InitFilters {
    _gamesModel = new GamesModel();
    _filterHide.setSourceModel(&_filterName);
    _filterGroup.setSourceModel(&_filterHide);
    _filterFavorite.setSourceModel(&_filterGroup);
    ui->TableGames->setModel(&_filterFavorite);
    _filterName.setFilterKeyColumn(GamesName);
    _filterHide.setFilterKeyColumn(GamesAppid);
    _filterGroup.setFilterKeyColumn(GamesAppid);
    _filterFavorite.setFilterKeyColumn(GamesAppid);
    _filterName.setFilterCaseSensitivity(Qt::CaseInsensitive);
    _filterHide.setFilterCaseSensitivity(Qt::CaseInsensitive);
    _filterGroup.setFilterCaseSensitivity(Qt::CaseInsensitive);
    _filterFavorite.setFilterCaseSensitivity(Qt::CaseInsensitive);
//    _filterName.setSortRole(Qt::ForegroundRole);
//    _filterHide.setSortRole(Qt::ForegroundRole);
//    _filterGroup.setSortRole(Qt::ForegroundRole);
//    _filterFavorite.setSortRole(Qt::ForegroundRole);
#define InitFiltersEnd }
#define Connects {
    connect(ui->LineEditGame,       &QLineEdit::textChanged,                this, &FormGames::lineEditGame_TextChanged);
    connect(ui->ButtonFind,         &QPushButton::clicked,                  this, &FormGames::buttonFind_Clicked);
    connect(ui->CheckBoxFavorites,  &QCheckBox::stateChanged,               this, &FormGames::checkBoxFavorites_StateChanged);
    connect(ui->ComboBoxGroups,     &MultiSelectComboBox::selectionChanged, this, &FormGames::updateGroupsFilter);
    connect(ui->TableGames,         &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
        createMenu(currentGame())->popup(ui->TableGames->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableGames,         &QTableView::doubleClicked,             this, [=](QModelIndex aIndex) {
        if (aIndex.column() == ColumnGamesComment) {
            showCommentsEdit();
        } else {
            buttonAchievements_Clicked();
        }
    });
    connect(_gamesModel,            &GamesModel::s_progress,                this, [=](const int &stage, const int &progress) {
//        qDebug() << stage << progress;
        Q_UNUSED(stage);
        ui->ProgressBarLoading->setValue(progress);
        emit s_achievementsLoaded(progress);
    });
    connect(_gamesModel,            &GamesModel::s_finished,                this, [=]() {
        ui->TableGames->resizeColumnsToContents();
        ui->TableGames->resizeRowsToContents();
        _loaded = true;
        emit s_finish(ui->TableGames->viewport()->width() + 22);
    });
#define ConnectsEnd }
}

void FormGames::updateIcons() {
    ui->ButtonFind->setIcon(QIcon(Images::find()));
}

void FormGames::setGames(SProfile &aProfile, SGames &aGames) {
    clear();
    _profile = aProfile;
    updateGroups(_profile);
    updateHiddenGames();

    _gamesModel->setGames(mySort(aGames), _profile.steamID());
    _filterName.setSourceModel(_gamesModel);

    ui->TableGames->setColumnHidden(ColumnGamesAppid, true);
    ui->TableGames->setColumnHidden(ColumnGamesIndex, true);
}

void FormGames::updateGroups(const SProfile &aProfile) {
    ui->ComboBoxGroups->clear();
    _groups.setProfile(aProfile);
    _groups.update();
    for(const auto &group: _groups) {
        ui->ComboBoxGroups->addItem(group.title());
    }
}

void FormGames::updateHiddenGames() {
    _hide.clear();

    HiddenGames all;
    HiddenGames profile(_profile);
    _hide.append(all.games());
    _hide.append(profile.games());

    QStringList list;
    for (const auto &hide: qAsConst(_hide)) {
        list.append(std::move(hide.id()));
    }
    _filterHide.setFilterRegExp("(" + list.join(")|(") + ")");
    ui->TableGames->resizeRowsToContents();
}

void FormGames::clear() {
    _loaded = false;
    _filterName.setFilterRegExp("");
    _filterHide.setFilterRegExp("()");
    _filterGroup.setFilterRegExp("");
    _filterFavorite.setFilterRegExp("");
}
#define InitEnd }

#define FindGameInTable {
SGame FormGames::currentGame() {
    QModelIndex index = ui->TableGames->currentIndex();
    QModelIndex index2 = index.siblingAtColumn(GamesIndex);
    QVariant fIndex = ui->TableGames->model()->data(index2);
    return _gamesModel->getGame(fIndex.toInt());
}

QStringList FormGames::currentComment() {
    QModelIndex index = ui->TableGames->currentIndex();
    QModelIndex index2 = index.siblingAtColumn(GamesIndex);
    QVariant fIndex = _filterFavorite.data(index2);
    return _gamesModel->getComment(fIndex.toInt());
}

QList<SAchievementPlayer> FormGames::currentAchievements() {
    QModelIndex index = ui->TableGames->currentIndex();
    QModelIndex index2 = index.siblingAtColumn(GamesIndex);
    QVariant fIndex = _filterFavorite.data(index2);
    return _gamesModel->getAchievements(fIndex.toInt());
}
#define FindGameInTableEnd }

#define System {
FormGames::~FormGames() {
    qInfo() << "Форма игр удалилась";
    delete ui;
}

#define EventsStart {
void FormGames::closeEvent(QCloseEvent*) {
    emit s_return_to_profile(this);
    //delete this;
}

#define EventsEnd }

void FormGames::retranslate() {
    ui->retranslateUi(this);
//    if (ui->TableGames->model() != nullptr) {
//        ui->TableGames->model()->setHeaderData(ColumnGamesIcon,        Qt::Horizontal, tr(""));
//        ui->TableGames->model()->setHeaderData(ColumnGamesName,        Qt::Horizontal, tr("Название игры"));
//        ui->TableGames->model()->setHeaderData(ColumnGamesComment,     Qt::Horizontal, tr(""));
//        ui->TableGames->model()->setHeaderData(ColumnGamesProgress,    Qt::Horizontal, tr("Прогресс"));
//    }
}

void FormGames::updateSettings() {
    Settings::syncronizeSettings();
    updateIcons();
    updateHiddenGames();
}

bool FormGames::isInFavorites(const int &aAppId) {
    auto favorites = _favorites.games();
    return std::any_of(favorites.begin(),
                       favorites.end(),
                       [=](const FavoriteGame &game) {
                            return game.appId() == aAppId &&
                                   game.steamId() == _profile.steamID();
                       });
}
#define SystemEnd }

#define Filter {
void FormGames::lineEditGame_TextChanged(const QString &aFindText) {
    _filterName.setFilterRegExp(aFindText);
    ui->TableGames->resizeRowsToContents();
}

void FormGames::buttonFind_Clicked() {
    lineEditGame_TextChanged(ui->LineEditGame->text());
}

void FormGames::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        _filterFavorite.setFilterRegExp("");
        break;
    }
    case 2: {
        QList<FavoriteGame> favoriteFriends = _favorites.games();
        QStringList list;
        for (const auto &favorite: qAsConst(favoriteFriends)) {
            list.append(QString::number(favorite.appId()));
        }
        _filterFavorite.setFilterRegExp("(" + list.join(")|(") + ")");
        break;
    }
    }
    ui->TableGames->resizeRowsToContents();
}

void FormGames::updateGroupsFilter() {
    QStringList list;
    QStringList selectedGroups = ui->ComboBoxGroups->currentText();

    for(auto &selectedGroup: selectedGroups) {
        for(auto &group: _groups) {
            if (group.title() == selectedGroup) {
                list.append(std::move(group.games()));
            }
        }
    }

    _filterGroup.setFilterRegExp("(" + list.join(")|(") + ")");
    ui->TableGames->resizeRowsToContents();
}
#define FilterEnd }

#define Functions {
QMenu *FormGames::createMenu(const SGame &aGame) {
    QString appId = aGame.sAppId();

    //Добавление перехода на достижения
    QAction *actionAchievements = new QAction(QIcon(Images::achievement()), tr("Достижения"), this);

    //Добавление кнопки избранного
    QAction *actionFavorites;
    if(isInFavorites(aGame.appId())) {
        actionFavorites = new QAction(QIcon(Images::isFavorites()), tr("Удалить из избранного"), this);
    } else {
        actionFavorites = new QAction(QIcon(Images::isNotFavorites()), tr("Добавить в избранное"), this);
    }

    //Добавление кнопки сокрытия
    QAction *actionHide;
    auto hiddenGame = std::find_if(_hide.cbegin(), _hide.cend(), [=](HiddenGame curGame) {
                                                                     return curGame.id() == appId;
                                                                 });
    if (hiddenGame != _hide.cend()) {
        actionHide = new QAction(QIcon(Images::visible()), tr("Показать игру"), this);
    } else {
        actionHide = new QAction(QIcon(Images::hide()), tr("Скрыть игру"), this);
    }

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
    connect (actionFavorites,       &QAction::triggered,    this,   &FormGames::buttonFavorite_Clicked);
    connect (actionHide,            &QAction::triggered,    this,   &FormGames::buttonHide_Clicked);
    connect (actionComment,         &QAction::triggered,    this,   &FormGames::showCommentsEdit);
    connect (actionGroup,           &QAction::triggered,    this,   &FormGames::showGroupsEdit);

    return menu;
}

void FormGames::buttonAchievements_Clicked() {
    QList<SAchievementSchema> global = SAchievementSchema::load(currentGame().sAppId());
    if (global.count() > 0) {
        emit s_showAchievements(currentGame());
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("В этой игре нет достижений"));
    }
}

void FormGames::buttonFavorite_Clicked() {
    _favorites.addGame(_profile.steamID(), currentGame(), true);
}

void FormGames::buttonHide_Clicked() {
    QMessageBox question(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите скрыть эту игру?"));
    QAbstractButton *btnProfile = question.addButton(tr("Да, но только для этого аккаунта"), QMessageBox::YesRole);
    QAbstractButton *btnAll = question.addButton(tr("Да, для всех аккаунтов"), QMessageBox::YesRole);
    question.addButton(tr("Отмена"), QMessageBox::NoRole);
    question.exec();

    if(question.clickedButton() == btnProfile) {
        HiddenGames profile(_profile);
        profile.addGame(currentGame(), true);
    } else if(question.clickedButton() == btnAll) {
        HiddenGames all;
        all.addGame(currentGame(), true);
    }

    updateHiddenGames();

    delete btnProfile;
    delete btnAll;
}

void FormGames::showGroupsEdit() {
    FramelessWindow *f = new FramelessWindow;
    FormGroups *ggi = new FormGroups(_profile, currentGame(), f);
    f->setWidget(ggi);
    connect(ggi, &FormGroups::s_updateGroups, this, [=]() {
        updateGroups(_profile);
    });
    f->show();
}

void FormGames::showCommentsEdit() {
    auto form = createFramelessForm<FormComments>();
    form->setData(_profile, currentGame(), SAchievement());
    connect(form, &FormComments::s_updateComments, _gamesModel, &GamesModel::updateComments);
    form->window()->show();
}
#define FunctionsEnd }
