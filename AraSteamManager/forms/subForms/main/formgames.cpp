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
#define Connects {
    connect(ui->LineEditGame,       &QLineEdit::textChanged,                this, &FormGames::lineEditGame_TextChanged);
    connect(ui->ButtonFind,         &QPushButton::clicked,                  this, &FormGames::buttonFind_Clicked);
    connect(ui->CheckBoxFavorites,  &QCheckBox::stateChanged,               this, &FormGames::checkBoxFavorites_StateChanged);
    connect(ui->ComboBoxGroups,     &MultiSelectComboBox::selectionChanged, this, &FormGames::updateGroupsFilter);
    connect(ui->TableGames,         &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
        createMenu(currentGame())->popup(ui->TableGames->viewport()->mapToGlobal(pos));
    });
    connect(ui->TableGames,         &QTableView::doubleClicked,             this, [=](QModelIndex aIndex) {
        if (aIndex.column() == GamesComment) {
            showCommentsEdit();
        } else {
            buttonAchievements_Clicked();
        }
    });
#define ConnectsEnd }
}

void FormGames::updateIcons() {
    ui->ButtonFind->setIcon(QIcon(Images::find()));
}

void FormGames::setGames(const SProfile &aProfile, SGames &aGames) {
    clear();
    _profile = aProfile;
    updateGroups(_profile);
    updateHiddenGames();

    if (_filterGames.sourceModel()) {
        delete _filterGames.sourceModel();
    }

    auto games = new GamesModel();
    connect(games, &GamesModel::s_progress, this, [=](const int &stage, const int &progress) {
        Q_UNUSED(stage);
        ui->ProgressBarLoading->setValue(progress);
        emit s_achievementsLoaded(progress);
    });
    connect(games, &GamesModel::s_finished, this, [=]() {
        ui->TableGames->resizeColumnsToContents();
        ui->TableGames->resizeRowsToContents();
        emit s_finish(ui->TableGames->viewport()->width() + 22);
    });
    games->setGames(mySort2(aGames), _profile.steamID());
    _filterGames.setSourceModel(games);
    ui->TableGames->setModel(&_filterGames);

    ui->TableGames->setColumnHidden(GamesAppid, true);
    ui->TableGames->setColumnHidden(GamesIndex, true);
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
    _filterGames.setHide(list);
    ui->TableGames->resizeRowsToContents();
}

void FormGames::clear() {
    _filterGames.clear();
}
#define InitEnd }

#define FindGameInTable {
int FormGames::currentIndex() {
    QModelIndex index = ui->TableGames->currentIndex();
    QModelIndex index2 = index.siblingAtColumn(GamesIndex);
    return ui->TableGames->model()->data(index2).toInt();
}

SGame FormGames::currentGame() {
    return _filterGames.sourceModel()->getGame(currentIndex());
}

QStringList FormGames::currentComment() {
    return _filterGames.sourceModel()->getComment(currentIndex());
}

QList<SAchievementPlayer> FormGames::currentAchievements() {
    return _filterGames.sourceModel()->getAchievements(currentIndex());
}
#define FindGameInTableEnd }

#define System {
FormGames::~FormGames() {
    qInfo() << "Форма игр удалилась";
    delete ui;
}

void FormGames::setEnable(bool isEnable) {
    ui->GroupBoxFilter->setEnabled(isEnable);
    ui->TableGames->setEnabled(isEnable);
}

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

bool isInFavorites(const int &aAppId, const QString &aProfileId) {
    auto favorites = Favorites::games();
    for (const auto &favorite: qAsConst(favorites)) {
        if (favorite.appId() == aAppId &&
            favorite.steamId() == aProfileId) {
            return true;
        }
    }
    return false;
}
#define SystemEnd }

#define Filter {
void FormGames::lineEditGame_TextChanged(const QString &aFindText) {
    _filterGames.setName(aFindText);
    ui->TableGames->resizeRowsToContents();
}

void FormGames::buttonFind_Clicked() {
    lineEditGame_TextChanged(ui->LineEditGame->text());
}

void FormGames::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        _filterGames.setFavorites(QStringList());
        break;
    }
    case 2: {
        QList<FavoriteGame> favoriteFriends = Favorites::games();
        QStringList list;
        for (const auto &favorite: qAsConst(favoriteFriends)) {
            list.append(QString::number(favorite.appId()));
        }
        _filterGames.setFavorites(list);
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
    _filterGames.setGroup(list);
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
    if(isInFavorites(aGame.appId(), _profile.steamID())) {
        actionFavorites = new QAction(QIcon(Images::isFavorites()), tr("Удалить из избранного"), this);
    } else {
        actionFavorites = new QAction(QIcon(Images::isNotFavorites()), tr("Добавить в избранное"), this);
    }

    //Добавление кнопки сокрытия
    QAction *actionHide;
    auto isGameHidden = std::any_of(_hide.cbegin(),
                                    _hide.cend(),
                                    [=](HiddenGame curGame) {
                                        return curGame.id() == appId;
                                    });
    if (isGameHidden) {
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
    if (SAchievementSchema::load(currentGame().sAppId()).count() > 0) {
        emit s_showAchievements(currentGame());
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("В этой игре нет достижений"));
    }
}

void FormGames::buttonFavorite_Clicked() {
    Favorites::addGame(_profile.steamID(), currentGame(), true);
}

void FormGames::buttonHide_Clicked() {
    QMessageBox question(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите скрыть эту игру?"));
    QAbstractButton *btnProfile = question.addButton(tr("Для этого аккаунта"), QMessageBox::YesRole);
    QAbstractButton *btnAll = question.addButton(tr("Для всех"), QMessageBox::YesRole);
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
    FormGroups *groups = new FormGroups(_profile, currentGame());
    QFrame *frame = createSubForm<FormGroups>(groups, this);
    connect(groups, &FormGroups::s_updateGroups,    this, [=]() {updateGroups(_profile);});
    connect(groups, &FormGroups::s_closed,          this, [=]() {
        setEnable(true);
        delete frame->layout();
        delete frame;
    });
    setEnable(false);
}

void FormGames::showCommentsEdit() {
    FormComments *comments = new FormComments();
    comments->setData(_profile, currentGame());
    QFrame *frame = createSubForm<FormComments>(comments, this);
    connect(comments, &FormComments::s_updateComments,  _filterGames.sourceModel(), &GamesModel::updateComments);
    connect(comments, &FormComments::s_closed,          this,                       [=](){
        setEnable(true);
        delete frame->layout();
        delete frame;
    });
    setEnable(false);
}
#define FunctionsEnd }
