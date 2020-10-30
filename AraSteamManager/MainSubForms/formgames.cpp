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

constexpr int c_filterName     = 0;
constexpr int c_filterHide     = 1;
constexpr int c_filterGroup    = 2;
constexpr int c_filterCount    = 3;
#define ConstantsEnd }

#define Init {
FormGames::FormGames(SProfile &aProfile, SGames &aGames, QWidget *aParent): QWidget(aParent), ui(new Ui::FormGames), _profile(aProfile),  _games(aGames),
    _filter(aGames.getCount(), c_filterCount), _groups(_profile) {
    ui->setupUi(this);
    initComponents();
}

void FormGames::initComponents() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->ProgressBarLoading->setVisible(false);
    _games.sort();
    setIcons();
    initGroups();
    initTable();

#define Connects {
    connect(ui->LineEditGame,       &QLineEdit::textChanged,          this, &FormGames::lineEditGame_TextChanged);
    connect(ui->ButtonFind,         &QPushButton::clicked,            this, &FormGames::buttonFind_Clicked);
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

    connect(ui->TableGames, &QTableView::doubleClicked, this, [=](QModelIndex) {
        updateCurrentGame();
        buttonAchievements_Clicked();
    });
}

void FormGames::createThread() {
    Threading *loadTable = new Threading(this);
    loadTable->AddThreadGames(c_tableColumnAppid, c_tableColumnIndex, c_tableColumnIcon, c_tableColumnName, c_tableColumnComment, c_tableColumnProgress, _games);
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
    ui->TableGames->resizeColumnsToContents();

    _achievements.resize(_games.getCount());
    int column = 0;
    for (auto &game: _games) {
        //Загрузка достижений игрока
        _achievements[column] = new SAchievementsPlayer(QString::number(game._appID), _profile._steamID);
        connect(_achievements[column], &SAchievementsPlayer::s_finished, this, &FormGames::onResultAchievements);
        ++column;
    }

    retranslate();
    updateHiddenGames();
    ui->LineEditGame->setFocus();
}

void FormGames::onResultAchievements(SAchievementsPlayer *aAchievements) {
    disconnect(aAchievements, &SAchievementsPlayer::s_finished, this, &FormGames::onResultAchievements);

    static int loaded = 0;

    QString appId = aAchievements->getAppid();

    int row = getRowFromIdGame(appId);


//    for(int i = 0; i < ui->TableGames->model()->rowCount(); ++i) {
//        if (ui->TableGames->model()->index(i, c_tableColumnAppid).data().toString() == appId) {
//            row = i;
//            break;
//        }
//    }

    //Устанавливается значение програссбара игры
    QProgressBar *pb = new QProgressBar();
    pb->setMaximum(aAchievements->getCount());
    pb->setValue(aAchievements->getReached());
    pb->setMinimumSize(QSize(25, 25));

    //Создаётся свечение для прогрессбаров
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setColor(QColor(93, 170, 224, 255 * 0.7));
    shadowEffect->setOffset(0);
    shadowEffect->setBlurRadius(50);
    pb->setGraphicsEffect(shadowEffect);

    //Проверка на игру без достижений
    if (aAchievements->getCount() == 0) {
        pb->setAccessibleName("BadAchievements");
        shadowEffect->setColor(QColor(255, 0, 0, 255 * 0.7));
        pb->setFormat("");
    }

    if (row > -1) {
        QModelIndex index = ui->TableGames->model()->index(row, c_tableColumnProgress);
        ui->TableGames->model()->setData(index, pb->text().rightJustified(5, '0'));
        ui->TableGames->setIndexWidget(index, pb);
        ui->TableGames->resizeRowToContents(row);
    } else {
        qWarning() << "game" << appId << "coudn't find";
    }
    emit s_achievementsLoaded(loaded, 0);

    //Проверка всё ли загрузилось
    if(++loaded == _games.getCount()) {
        emit s_finish(ui->TableGames->viewport()->width() + 22);
    }
}

void FormGames::updateSettings() {
    Settings::syncronizeSettings();
    setIcons();
    updateHiddenGames();
}

void FormGames::setIcons() {
    ui->ButtonFind->setIcon(QIcon(Images::find()));
}

void FormGames::updateCurrentGame() {
    QModelIndex index = ui->TableGames->currentIndex();
    _currentIndex = ui->TableGames->model()->index(index.row(), c_tableColumnIndex).data().toString().toInt();
    int appId = ui->TableGames->model()->index(index.row(), c_tableColumnAppid).data().toString().toInt();

    auto iterator = std::find_if(_games.begin(), _games.end(), [=](const SGame &game) {
                                                                    return game._appID == appId;
                                                                });
    if (iterator != _games.end()) {
        _currentGame = &*iterator;
    }
}

int FormGames::getIndexGameFromRow(int aRow) {
    QModelIndex IdIndex = ui->TableGames->model()->index(aRow, c_tableColumnIndex);
    return ui->TableGames->model()->data(IdIndex).toInt();
}

int FormGames::getRowFromIndexGame(int aIndex) {
    for (int i = 0; i < ui->TableGames->model()->rowCount(); ++i) {
        QModelIndex IdIndex = ui->TableGames->model()->index(i, c_tableColumnIndex);
        if (ui->TableGames->model()->data(IdIndex).toInt() == aIndex) {
            return i;
        }
    }
    return -1;
}

int FormGames::getIndexGameFromIdGame(QString aId) {
    return std::find_if(_games.begin(), _games.end(), [=](const SGame &game) {
                                                            return QString::number(game._appID) == aId;
                                                        }) - _games.begin();
}

int FormGames::getRowFromIdGame(QString aId) {
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

void FormGames::updateHiddenGames() {
    for (int i = 0; i < _games.getCount(); ++i) {
        _filter.setData(i, c_filterHide, true);
        ui->TableGames->model()->setData(ui->TableGames->model()->index(i, c_tableColumnName), QVariant(), Qt::ForegroundRole);
    }

    updateHideFromFile(_profile._steamID);
    updateHideFromFile("All");

    updateHiddenRows();
}

void FormGames::updateHideFromFile(const QString &aFile) {
    QFile fileHide(Paths::hiddenGames(aFile));
    if(fileHide.open(QIODevice::ReadOnly)) {
        while(!fileHide.atEnd()) {
            QString gameId = QString::fromLocal8Bit(fileHide.readLine()).remove("\r\n").remove("\n");
            gameId = aFile == "All" ? gameId.split("%%").at(0) : gameId;
            int index = getIndexGameFromIdGame(gameId);
            _filter.setData(index, c_filterHide, false);
            ui->TableGames->model()->setData(ui->TableGames->model()->index(getRowFromIdGame(gameId), c_tableColumnName), QVariant(QColor(255 * 0.7, 0, 0)), Qt::ForegroundRole);
        }
        fileHide.close();
    } else {
        qWarning() << "file" << fileHide.fileName() << "coudn't open";
    }
}

void FormGames::updateGroupsFilter() {
    QStringList groups = ui->ComboBoxGroups->currentText();
    //TODO Обновить фильтр
    updateHiddenRows();
}

void FormGames::updateHiddenRows() {
    for (int i = 0; i < ui->TableGames->model()->rowCount(); ++i) {
        ui->TableGames->setRowHidden(getRowFromIndexGame(i), !_filter.getData(i));
    }
}

QMenu *FormGames::createMenu(SGame &aGame) {
    QString appId = QString::number(aGame._appID);

    //Добавление перехода на достижения
    QAction *actionAchievements = new QAction(tr("Достижения"), this);
    actionAchievements->setIcon(QIcon(Images::achievement()));

    //Добавление кнопки избранного
    QAction *actionFavorites;
    QList<FavoriteGame> favorites = _favorites.getGames();
    bool isFavorite = std::any_of(favorites.cbegin(), favorites.cend(), [=](FavoriteGame curFavorite) {
                                                                            return curFavorite.getAppid() == aGame._appID
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
    auto hiddenGame = std::find_if(_hide.cbegin(), _hide.cend(), [=](QString curGame) {
                                                                     return curGame == appId;
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

    QMenu* menu = new QMenu(this);
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
#define InitEnd }

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
#define SystemEnd }

#define Filter {
void FormGames::lineEditGame_TextChanged(const QString &aFindText) {
    QString findText = aFindText.toLower();
    for (int i = 0; i < ui->TableGames->model()->rowCount(); ++i) {
        int index = getIndexGameFromRow(i);
        _filter.setData(index, c_filterName, ui->TableGames->model()->index(i, c_tableColumnName).data().toString().toLower().indexOf(findText, 0) != -1);
    }
    updateHiddenRows();
}

void FormGames::buttonFind_Clicked() {
    lineEditGame_TextChanged(ui->LineEditGame->text());
}
#define FilterEnd }

#define Functions {
void FormGames::buttonAchievements_Clicked() {
    SAchievementsPercentage Percentage(QString::number(_currentGame->_appID), false);
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
    QString savePath = "";

    QMessageBox question(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите скрыть эту игру?"));
    QAbstractButton *btnProfile = question.addButton(tr("Да, но только для этого аккаунта"), QMessageBox::YesRole);
    QAbstractButton *btnAll = question.addButton(tr("Да, для всех аккаунтов"), QMessageBox::YesRole);
    question.addButton(tr("Отмена"), QMessageBox::NoRole);
    question.exec();

    if(question.clickedButton() == btnProfile) {
         savePath = Paths::hiddenGames(_profile._steamID);
    } else if(question.clickedButton() == btnAll) {
         savePath = Paths::hiddenGames("All");
    } else {
        return;
    }

    Settings::createDir(savePath);

    QFile fileHide(savePath);
    fileHide.open(QIODevice::Append | QIODevice::Text);
    QTextStream writeStream(&fileHide);
    if (savePath == Paths::hiddenGames("All")) {
        writeStream <<_currentGame->_appID <<"%%" + _currentGame->_img_icon_url + "%%" + _currentGame->_name <<"\n";
    } else {
        writeStream <<_currentGame->_appID <<"\n";
    }
    fileHide.close();

    updateHiddenGames();

    delete btnProfile;
    delete btnAll;
}

void FormGames::showGroupsInteractive() {
    FormGroupsGamesInteractions *ggi = new FormGroupsGamesInteractions(_profile, *_currentGame);
    connect(ggi, &FormGroupsGamesInteractions::s_updateGroups, this, [=](bool isUpdate) {
        if (isUpdate) {
            initGroups();
        }
        delete ggi;
    });
    ggi->show();
}

void FormGames::showCommentsInteractive() {
    FormCommentsInteractions *ci = new FormCommentsInteractions(_profile, *_currentGame);
    connect(ci, &FormCommentsInteractions::s_updateComments, this, [=](bool isUpdate) {
        if (isUpdate) {
            //initComments();
        }
        delete ci;
    });
    ci->show();
}
#define FunctionsEnd }
