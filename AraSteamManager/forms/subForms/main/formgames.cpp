#include "formgames.h"
#include "ui_formgames.h"

#define Constants {
constexpr int c_tableColumnAppid    = 0;
constexpr int c_tableColumnIndex    = 1;
constexpr int c_tableColumnIcon     = 2;
constexpr int c_tableColumnName     = 3;
constexpr int c_tableColumnComment  = 4;
constexpr int c_tableColumnProgress = 5;
constexpr int c_tableColumnCount    = 6;

constexpr int c_filterName          = 0;
constexpr int c_filterHide          = 1;
constexpr int c_filterGroup         = 2;
constexpr int c_filterFavorites     = 3;
constexpr int c_filterCount         = 4;
#define ConstantsEnd }

#define Init {
FormGames::FormGames(SProfile &aProfile, SGames &aGames, QWidget *aParent): QWidget(aParent), ui(new Ui::FormGames), _profile(aProfile),  _games(aGames),
    _filter(aGames.getCount(), c_filterCount), _groups(_profile), _comments(_profile._steamID) {
    ui->setupUi(this);
    init();
    setGames(aProfile, aGames);
}

FormGames::FormGames(QWidget *aParent): QWidget(aParent), ui(new Ui::FormGames), _filter(0, c_filterCount) {
    ui->setupUi(this);
    init();
}

void FormGames::setGames(SProfile &aProfile, SGames &aGames) {
    _profile = aProfile;
    _games = aGames;
    _filter.setRow(aGames.getCount());
    _groups.setProfile(_profile);
    _comments.setProfileId(_profile._steamID);
    _games.sort();
    initGroups();
    initTable();
    createThread();
}

void FormGames::init() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->ProgressBarLoading->setVisible(false);
    setIcons();

#define Connects {
    connect(ui->LineEditGame,       &QLineEdit::textChanged,                this, &FormGames::lineEditGame_TextChanged);
    connect(ui->ButtonFind,         &QPushButton::clicked,                  this, &FormGames::buttonFind_Clicked);
    connect(ui->CheckBoxFavorites,  &QCheckBox::stateChanged,               this, &FormGames::checkBoxFavorites_StateChanged);
    connect(ui->ComboBoxGroups,     &MultiSelectComboBox::selectionChanged, this, &FormGames::updateGroupsFilter);
#define ConnectsEnd }
}

bool FormGames::isInit() {
    return ((_games.getCount() > 0) && (_filter.getRow() > 0) && (_loaded));
}

bool FormGames::isLoaded() {
    return _loaded;
}

void FormGames::clear() {
    _games.clear();
    _filter.setRow(0);
    _loaded = false;
}

void FormGames::initComponents() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->ProgressBarLoading->setVisible(false);
    _games.sort();
    setIcons();
    initGroups();
    initTable();

#define Connects {
    connect(ui->LineEditGame,       &QLineEdit::textChanged,                this, &FormGames::lineEditGame_TextChanged);
    connect(ui->ButtonFind,         &QPushButton::clicked,                  this, &FormGames::buttonFind_Clicked);
    connect(ui->CheckBoxFavorites,  &QCheckBox::stateChanged,               this, &FormGames::checkBoxFavorites_StateChanged);
    connect(ui->ComboBoxGroups,     &MultiSelectComboBox::selectionChanged, this, &FormGames::updateGroupsFilter);
#define ConnectsEnd }
    createThread();
}

void FormGames::initGroups() {
    ui->ComboBoxGroups->clear();
    _groups.update();
    for(auto group: _groups) {
        ui->ComboBoxGroups->addItem(group.getTitle());
    }
}

void FormGames::initComments() {
    _comments.load();
    for(const auto &game: _games) {
        QStringList comment = _comments.getGameComment(game.sAppId(), _profile._steamID).getComment();
        QVariant icon;
        QModelIndex index = ui->TableGames->model()->index(rowFromId(game.sAppId()), c_tableColumnComment);

        if ((comment != QStringList()) && (comment != QStringList() << "")) {
            icon = QVariant(QPixmap(Images::isComment()).scaled(32, 32));
        } else {
            icon = QVariant(QPixmap(Images::isNotComment()).scaled(32, 32));
        }
        ui->TableGames->model()->setData(index, icon, Qt::DecorationRole);
    }
}

void FormGames::initTable() {
    ui->TableGames->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
    ui->TableGames->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

    ui->TableGames->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TableGames->setShowGrid(false);
    ui->TableGames->setSortingEnabled(true);
    ui->TableGames->horizontalHeader()->setStretchLastSection(true);
    ui->TableGames->verticalHeader()->setVisible(false);
    ui->TableGames->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->TableGames->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->TableGames, &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
        updateCurrentGame();
        if (_currentGame != nullptr) {
            QMenu *menu = createMenu(*_currentGame);
            menu->popup(ui->TableGames->viewport()->mapToGlobal(pos));
        }
    });

    connect(ui->TableGames, &QTableView::doubleClicked, this, [=](QModelIndex aIndex) {
        updateCurrentGame();
        if (aIndex.column() == c_tableColumnComment) {
            showCommentsInteractive();
        } else {
            buttonAchievements_Clicked();
        }
    });
}

void FormGames::createThread() {
    Threading *loadTable = new Threading(this);
    loadTable->AddThreadGames(c_tableColumnAppid, c_tableColumnIndex, c_tableColumnIcon, c_tableColumnName, c_tableColumnComment, c_tableColumnProgress, c_tableColumnCount, _games);
    connect (loadTable, &Threading::s_games_progress, this, [=](int progress, int row) {
                                                                ui->ProgressBarLoading->setValue(progress);
                                                                emit s_achievementsLoaded(progress, row);
                                                            });
    connect (loadTable, &Threading::s_games_finished_model, this, &FormGames::setTableModel);
}

void FormGames::setTableModel(QStandardItemModel *aModel) {
    ui->TableGames->setModel(aModel);
    ui->TableGames->setSortingEnabled(true);
    ui->TableGames->setColumnHidden(c_tableColumnAppid, true);
    ui->TableGames->setColumnHidden(c_tableColumnIndex, true);
    initComments();
    ui->TableGames->resizeColumnsToContents();

    _achievements.resize(_games.getCount());
    int column = 0;
    for (auto &game: _games) {
        //Загрузка достижений игрока
        _achievements[column] = new SAchievementsPlayer(game.sAppId(), _profile._steamID);
        connect(_achievements[column], &SAchievementsPlayer::s_finished, this, &FormGames::onResultAchievements);
        ++column;
    }

    retranslate();
    updateHiddenGames();
    ui->LineEditGame->setFocus();
}

void FormGames::onResultAchievements(SAchievementsPlayer *aAchievements) {
    disconnect(aAchievements, &SAchievementsPlayer::s_finished, this, &FormGames::onResultAchievements);

    int row = rowFromId(aAchievements->getAppid());

    if (row > -1) {
        QProgressBar *pb;

        //Проверка на игру без достижений
        if (aAchievements->getCount() == 0) {
            pb = dynamic_cast<QProgressBar*>(new ProgressBarBad());
            pb->setFormat("");
        } else {
            pb = dynamic_cast<QProgressBar*>(new ProgressBarGood());
        }
        pb->setMaximum(aAchievements->getCount());
        pb->setValue(aAchievements->getReached());
        pb->setMinimumSize(QSize(25, 25));

        //Прогрессбар устанавливается в таблицу
        QModelIndex index = ui->TableGames->model()->index(row, c_tableColumnProgress);
        ui->TableGames->model()->setData(index, pb->text().rightJustified(5, '0'));
        ui->TableGames->setIndexWidget(index, pb);
    } else {
        qWarning() << "game" << aAchievements->getAppid() << "coudn't find";
    }
    ui->TableGames->resizeRowToContents(row);

    static int loaded = 0;
    emit s_achievementsLoaded(loaded, 0);
    //Проверка всё ли загрузилось
    if(++loaded == _games.getCount()) {
        _loaded = true;
        emit s_finish(ui->TableGames->viewport()->width() + 22);
    }
}

void FormGames::setIcons() {
    ui->ButtonFind->setIcon(QIcon(Images::find()));
}
#define InitEnd }

#define FindGameInTable {
int FormGames::indexFromRow(int aRow) {
    QModelIndex IdIndex = ui->TableGames->model()->index(aRow, c_tableColumnIndex);
    return ui->TableGames->model()->data(IdIndex).toInt();
}

int FormGames::rowFromIndex(int aIndex) {
    for (int i = 0; i < ui->TableGames->model()->rowCount(); ++i) {
        QModelIndex IdIndex = ui->TableGames->model()->index(i, c_tableColumnIndex);
        if (ui->TableGames->model()->data(IdIndex).toInt() == aIndex) {
            return i;
        }
    }
    return -1;
}

int FormGames::indexFromId(QString aId) {
    return std::find_if(_games.begin(), _games.end(), [=](const SGame &game) {
                                                            return game.sAppId() == aId;
                                                        }) - _games.begin();
}

int FormGames::rowFromId(QString aId) {
    QStandardItemModel *model = dynamic_cast<QStandardItemModel *>(ui->TableGames->model());
    if (model) {
        QList<QStandardItem*> items = model->findItems(aId, Qt::MatchExactly, c_tableColumnAppid);
        if (items.count() == 1) {
            return items[0]->row();
        } else {
            qWarning() << "duplicates game" << aId << ", " << items.count() << " count";
        }
    } else {
        qWarning() << "error model cast";
    }
    return -1;
}

void FormGames::updateCurrentGame() {
    QModelIndex index = ui->TableGames->currentIndex();
    _currentIndex = ui->TableGames->model()->index(index.row(), c_tableColumnIndex).data().toString().toInt();
    int appId = ui->TableGames->model()->index(index.row(), c_tableColumnAppid).data().toString().toInt();

    auto iterator = std::find_if(_games.begin(), _games.end(), [=](const SGame &game) {
                                                                    return game.appId() == appId;
                                                                });
    if (iterator != _games.end()) {
        _currentGame = &*iterator;
    }
}
#define FindGameInTableEnd }

#define System {
FormGames::~FormGames() {
    qInfo() << "Форма игр удалилась";
    delete ui;
}

#define EventsStart {
void FormGames::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormGames::closeEvent(QCloseEvent*) {
    emit s_return_to_profile(this);
    //delete this;
}

#define EventsEnd }

void FormGames::retranslate() {
    ui->retranslateUi(this);
    ui->TableGames->model()->setHeaderData(c_tableColumnIcon,        Qt::Horizontal, tr(""));
    ui->TableGames->model()->setHeaderData(c_tableColumnName,        Qt::Horizontal, tr("Название игры"));
    ui->TableGames->model()->setHeaderData(c_tableColumnComment,     Qt::Horizontal, tr(""));
    ui->TableGames->model()->setHeaderData(c_tableColumnProgress,    Qt::Horizontal, tr("Прогресс"));
}

void FormGames::updateSettings() {
    Settings::syncronizeSettings();
    setIcons();
    updateHiddenGames();
}

bool FormGames::isInFavorites(const int &aAppId) {
    auto favorites = _favorites.getGames();
    for(const auto &game: favorites) {
        if (game.getAppid() == aAppId) {
            return true;
        }
    }
    return false;
}
#define SystemEnd }

#define Filter {
void FormGames::lineEditGame_TextChanged(const QString &aFindText) {
    QString findText = aFindText.toLower();
    for (int i = 0; i < ui->TableGames->model()->rowCount(); ++i) {
        _filter.setData(indexFromRow(i), c_filterName, ui->TableGames->model()->index(i, c_tableColumnName).data().toString().toLower().indexOf(findText, 0) != -1);
    }
    updateHiddenRows();
}

void FormGames::buttonFind_Clicked() {
    lineEditGame_TextChanged(ui->LineEditGame->text());
}

void FormGames::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        for (int i = 0; i < _games.getCount(); ++i) {
            _filter.setData(i, c_filterFavorites, true);
        }
        break;
    }
    case 2: {
        for (int i = 0; i < _games.getCount(); ++i) {
            _filter.setData(i, c_filterFavorites, isInFavorites(_games[i].appId()));
        }
        break;
    }
    }
    updateHiddenRows();
}

void FormGames::updateHiddenGames() {
    for (int i = 0; i < _games.getCount(); ++i) {
        _filter.setData(i, c_filterHide, true);
        ui->TableGames->model()->setData(ui->TableGames->model()->index(i, c_tableColumnName), QVariant(), Qt::ForegroundRole);
    }

    _hide.clear();

    HiddenGames all;
    HiddenGames profile(_profile);
    auto listAll = all.getGames();
    auto listProfile = profile.getGames();
    _hide.append(listAll);
    _hide.append(listProfile);

    if (ui->TableGames->model()) {
        for(const auto &game: _hide) {
            _filter.setData(indexFromId(game.id), c_filterHide, false);
            ui->TableGames->model()->setData(ui->TableGames->model()->index(rowFromId(game.id), c_tableColumnName), QVariant(QColor(255 * 0.7, 0, 0)), Qt::ForegroundRole);
        }
    }

    updateHiddenRows();
}

void FormGames::updateGroupsFilter() {
    QStringList groups = ui->ComboBoxGroups->currentText();
    if ((groups.count() == 0) || (groups.count() == 1 && groups[0] == "")) {
        for (int i = 0; i < ui->TableGames->model()->rowCount(); ++i) {
            _filter.setData(i, c_filterGroup, true);
        }
        updateHiddenRows();
        return;
    }
    for (int i = 0; i < ui->TableGames->model()->rowCount(); ++i) {
        _filter.setData(i, c_filterGroup, false);
    }
    for(auto &group: _groups) {
        for(auto &selectedGroup: groups) {
            if (group.getTitle() == selectedGroup) {
                for(auto &game: group.getGames()) {
                    _filter.setData(indexFromId(game), c_filterGroup, true);
                }
                break;
            }
        }
    }
    updateHiddenRows();
}

void FormGames::updateHiddenRows() {
//TODO при поиске игр не отображает скрытые
    if (ui->TableGames->model()) {
        for (int i = 0; i < ui->TableGames->model()->rowCount(); ++i) {
            ui->TableGames->setRowHidden(rowFromIndex(i), !_filter.getData(i));
        }
    }
}
#define FilterEnd }

#define Functions {
QMenu *FormGames::createMenu(SGame &aGame) {
    QString appId = aGame.sAppId();

    //Добавление перехода на достижения
    QAction *actionAchievements = new QAction(tr("Достижения"), this);
    actionAchievements->setIcon(QIcon(Images::achievement()));

    //Добавление кнопки избранного
    QAction *actionFavorites;
    QList<FavoriteGame> favorites = _favorites.getGames();
    bool isFavorite = std::any_of(favorites.cbegin(), favorites.cend(), [=](FavoriteGame curFavorite) {
                                                                            return curFavorite.getAppid() == aGame.appId()
                                                                            && curFavorite.getUserId() == _profile._steamID;
                                                                        });
    if(isFavorite) {
        actionFavorites = new QAction(tr("Удалить из избранного"), this);
        actionFavorites->setIcon(QIcon(Images::isFavorites()));
    } else {
        actionFavorites = new QAction(tr("Добавить в избранное"), this);
        actionFavorites->setIcon(QIcon(Images::isNotFavorites()));
    }

    //Добавление кнопки сокрытия
    QAction *actionHide;
    auto hiddenGame = std::find_if(_hide.cbegin(), _hide.cend(), [=](gameData curGame) {
                                                                     return curGame.id == appId;
                                                                 });
    if (hiddenGame != _hide.cend()) {
        actionHide = new QAction(tr("Показать игру"), this);
        actionHide->setIcon(QIcon(Images::visible()));
    } else {
        actionHide = new QAction(tr("Скрыть игру"), this);
        actionHide->setIcon(QIcon(Images::hide()));
    }

    //Добавление кнопки комментариев
    QAction *actionComment = new QAction(tr("Редактировать комментарий...     "), this);
    actionComment->setIcon(QIcon(Images::isComment()));

    //Добавление кнопки взаимодействия с группами
    QAction *actionGroup = new QAction(tr("Добавить/Удалить из группы...     "), this);
    actionGroup->setIcon(QIcon(Images::group1()));

    QMenu *menu = new QMenu(this);
    menu->addAction (actionAchievements);
    menu->addAction (actionFavorites);
    menu->addAction (actionHide);
    menu->addAction (actionComment);
    menu->addAction (actionGroup);

    connect (actionAchievements,    &QAction::triggered,    this,   &FormGames::buttonAchievements_Clicked);
    connect (actionFavorites,       &QAction::triggered,    this,   &FormGames::buttonFavorite_Clicked);
    connect (actionHide,            &QAction::triggered,    this,   &FormGames::buttonHide_Clicked);
    connect (actionComment,         &QAction::triggered,    this,   &FormGames::showCommentsInteractive);
    connect (actionGroup,           &QAction::triggered,    this,   &FormGames::showGroupsInteractive);

    return menu;
}

void FormGames::buttonAchievements_Clicked() {
    SAchievementsPercentage Percentage(_currentGame->sAppId(), false);
    if (Percentage.getCount() == 0) {
        QMessageBox::warning(this, tr("Ошибка"), tr("В этой игре нет достижений"));
    } else {
        //ui->ProgressBarLoading->setMaximum(ui->ProgressBarSelectedGame->maximum());
        emit s_showAchievements(*_achievements[_currentIndex], *_currentGame);
    }
}

void FormGames::buttonFavorite_Clicked() {
    _favorites.addGame(_profile._steamID, _games[_currentIndex], true);
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
        profile.addGame(*_currentGame, true);
    } else if(question.clickedButton() == btnAll) {
        HiddenGames all;
        all.addGame(*_currentGame, true);
    } else {
        return;
    }

    updateHiddenGames();

    delete btnProfile;
    delete btnAll;
}

void FormGames::showGroupsInteractive() {
    FramelessWindow *f = new FramelessWindow;
    FormGroups *ggi = new FormGroups(_profile, *_currentGame, f);
    f->setWidget(ggi);
    connect(ggi, &FormGroups::s_updateGroups, this, [=](bool isUpdate) {
        if (isUpdate) {
            initGroups();
        }
        delete ggi;
    });
    f->show();
}

void FormGames::showCommentsInteractive() {
    FramelessWindow *f = new FramelessWindow;
    FormComments *ci = new FormComments(_profile, *_currentGame, nullptr, f);
    f->setWidget(ci);
    connect(ci, &FormComments::s_updateComments, this, [=](bool isUpdate) {
        if (isUpdate) {
            initComments();
        }
        delete ci;
    });
    f->show();
}
#define FunctionsEnd }
