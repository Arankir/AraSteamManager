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
#define ConstantsEnd }

#define Init {
FormGames::FormGames(SProfile &aProfile, SGames &aGames, QWidget *aParent): QWidget(aParent), ui(new Ui::FormGames), _profile(aProfile),  _games(aGames) {
    ui->setupUi(this);
    initComponents();
}

void FormGames::initComponents() {
    this->setAttribute(Qt::WA_TranslucentBackground);
    _games.sort();
//    updateSettings();
//    retranslate();
    ui->ProgressBarLoading->setVisible(false);
//TODO загрузить группы
    //Загрузка номеров скрываемых игр
    loadHiddenGames();

#define Connects {
    connect(ui->LineEditGame,       &QLineEdit::textChanged,          this, &FormGames::lineEditGame_TextChanged);
    connect(ui->ButtonFind,         &QPushButton::clicked,            this, &FormGames::buttonFind_Clicked);
#define ConnectsEnd }
    createThread();
}

void FormGames::enableMouseTracking(const QObjectList &aChildren) {
    Q_UNUSED(aChildren);
//    for(QObject *child: aChildren) {
//        QWidget *childWidget = qobject_cast<QWidget*>(child);

//        if(childWidget) {
//            childWidget->setMouseTracking(true);
//            enableMouseTracking(childWidget->children());
//        }
//    }
}

void FormGames::updateSettings() {
    Settings::syncronizeSettings();
    setIcons();
    loadHiddenGames();
    hideHiddenGames();
}

void FormGames::setIcons() {
    ui->ButtonFind->setIcon(QIcon(Images::find()));
    //ui->ButtonFavorite->setIcon(QIcon(Images::isNotFavorites()));
    //ui->ButtonHide->setIcon(QIcon(Images::hide()));
    //ui->ButtonCreateGroup->setIcon(QIcon(Images::create()));
    //ui->ButtonChangeGroup->setIcon(QIcon(Images::change()));
}

void FormGames::updateCurrentGame() {
    QModelIndex index = ui->tableView->currentIndex();
    _currentIndex = ui->tableView->model()->index(index.row(), c_tableColumnIndex).data().toString().toInt();
    int appId = ui->tableView->model()->index(index.row(), c_tableColumnAppid).data().toString().toInt();

    auto iterator = std::find_if(_games.begin(), _games.end(), [=](const SGame &game) {
                                                                    return game._appID == appId;
                                                                });
    if (iterator != _games.end()) {
        _currentGame = &*iterator;
    }
}

void FormGames::loadHiddenGames() {
    _hide.clear();
    QFile fileHide;
    fileHide.setFileName(Paths::hiddenGames(_profile._steamID));
    if(fileHide.open(QIODevice::ReadOnly)) {
        while(!fileHide.atEnd()) {
            _hide << QString::fromLocal8Bit(fileHide.readLine()).remove("\r\n").remove("\n");
        }
        fileHide.close();
    }
    fileHide.setFileName(Paths::hiddenGames("All"));
    if(fileHide.open(QIODevice::ReadOnly)) {
        while(!fileHide.atEnd()) {
            _hide << QString::fromLocal8Bit(fileHide.readLine()).remove("\r\n").remove("\n").split("%%").at(0);
        }
        fileHide.close();
    }
}

void FormGames::onTablePushed() {
//    ui->TableWidgetGames->setColumnHidden(c_tableColumnAppid, true);
//    ui->TableWidgetGames->setColumnHidden(c_tableColumnIndex, true);
//    ui->TableWidgetGames->resizeColumnsToContents();
//    ui->TableWidgetGames->setColumnWidth(c_tableColumnIcon, 33 + 8);
//    ui->TableWidgetGames->setColumnWidth(c_tableColumnProgress, 150 + 8);

//    _achievements.resize(_games.getCount());
//    int row = 0;
//    for (auto &game: _games) {
//        //Загрузка картинок
//        QLabel *iconGame = new QLabel();
//        iconGame->setPixmap(game.getPixmapIcon());
//        ui->TableWidgetGames->setCellWidget(row, c_tableColumnIcon, iconGame);
//        ui->TableWidgetGames->setRowHeight(row, 32 + 18);

//        //Загрузка достижений игрока
//        SAchievementsPlayer *achievementsGame = new SAchievementsPlayer(QString::number(game._appID), _profile._steamID);
//        achievementsGame->_index = row;
//        connect(achievementsGame, &SAchievementsPlayer::s_finished, this, &FormGames::onResultAchievements);

////        //Добавление кнопки с настройками
////        QPushButton *tools = new QPushButton("...");
////        tools->setFont(QFont("Times New Roman", 16));
////        tools->setFlat(true);
////        tools->setMaximumSize(QSize(46, 32));
////        tools->setObjectName("TBtn" + QString::number(row));
////        tools->setMenu(createMenu(game, row));
////        connect (tools, &QPushButton::clicked, tools, &QPushButton::showMenu);
////        ui->TableWidgetGames->setCellWidget(row, c_tableColumnTools, tools);

//        ++row;
//    }
//    hideHiddenGames();
////    enableMouseTracking(ui->TableWidgetGames->children());
////    ui->TableWidgetGames->viewport()->setMouseTracking(true);
////    enableMouseTracking(ui->TableWidgetGames->viewport()->children());
////    ui->TableWidgetGames->installEventFilter(this);
////    ui->TableWidgetGames->viewport()->installEventFilter(this);
//    ui->LineEditGame->setFocus();
}

QMenu *FormGames::createMenu(SGame &aGame, int aIndex) {
    QString appId = QString::number(aGame._appID);

    //Добавление перехода на достижения
    QAction *actionAchievements = new QAction(tr("Достижения"), this);
    actionAchievements->setData(aIndex);
    actionAchievements->setWhatsThis(appId);
    //actionAchievements->setIcon(QIcon(_setting.getIconGoTo()));

    //Добавление кнопки избранного
    QAction *actionFavorites;
    QList<FavoriteGame> favorites = _favorites.getGames();
    bool isFavorite = std::any_of(favorites.cbegin(), favorites.cend(), [=](FavoriteGame curFavorite) {
                                                                            return curFavorite.getName() == aGame._name
                                                                            && curFavorite.getAppid() == aGame._appID
                                                                            && curFavorite.getUserId() == _profile._steamID;
                                                                        });
    if(isFavorite) {
        actionFavorites = new QAction(tr("Удалить из избранного"), this);
        actionFavorites->setIcon(QIcon(Images::isFavorites()));
    } else {
        actionFavorites = new QAction(tr("Добавить в избранное"), this);
        actionFavorites->setIcon(QIcon(Images::isNotFavorites()));
    }
    actionFavorites->setData(aIndex);
    actionFavorites->setWhatsThis(appId);

    //Добавление кнопки сокрытия
    QAction *actionHide;
    auto hiddenGame = std::find_if(_hide.cbegin(), _hide.cend(),
                                   [=](QString curGame) {return curGame == appId;});
    if (hiddenGame != _hide.cend()) {
        actionHide = new QAction(tr("Показать игру"), this);
        actionHide->setIcon(QIcon(Images::unhide()));
    } else {
        actionHide = new QAction(tr("Скрыть игру"), this);
        actionHide->setIcon(QIcon(Images::hide()));
    }
    actionHide->setData(aIndex);
    actionHide->setWhatsThis(appId);

    //Добавление кнопки комментов
    QAction *actionComment = new QAction(tr("Комменты (WIP)"), this);
    actionComment->setData(aIndex);
    actionComment->setWhatsThis(appId);

    QMenu* menu = new QMenu(this);
    menu->addAction (actionAchievements);
    menu->addAction (actionFavorites);
    menu->addAction (actionHide);
    menu->addAction (actionComment);

    connect (actionAchievements,    &QAction::triggered,    this,   &FormGames::buttonAchievements_Clicked);
    connect (actionFavorites,       &QAction::triggered,    this,   &FormGames::buttonFavorite_Clicked);
    connect (actionHide,            &QAction::triggered,    this,   &FormGames::buttonHide_Clicked);
    //connect (actionComment,         &QAction::triggered,    this,   &FormGames::buttonFriendFavorite_Clicked);

    return menu;
}

void FormGames::onResultAchievements(SAchievementsPlayer *aAchievements) {
    disconnect(aAchievements, &SAchievementsPlayer::s_finished, this, &FormGames::onResultAchievements);
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
    QModelIndex index = ui->tableView->model()->index(aAchievements->_index, c_tableColumnProgress);
    ui->tableView->model()->setData(index, pb->text().rightJustified(5, '0'));
    ui->tableView->setIndexWidget(index, pb);
    ui->tableView->resizeRowToContents(aAchievements->_index);

    _achievements[aAchievements->_index] = aAchievements;
    emit s_achievementsLoaded(_load, 0);

    //Проверка всё ли загрузилось
    if(++_load == _games.getCount()) {
        int width = 22;
//        for(int i = 0; i < ui->TableWidgetGames->columnCount(); ++i) {
//            width += ui->TableWidgetGames->columnWidth(i);
//        }
        emit s_finish(width);
    }
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

void FormGames::resizeEvent(QResizeEvent*) {
//    ui->TableWidgetGames->setGeometry(c_widthVisibleGroup, 0, ui->FrameGames->width() - c_widthVisibleGroup, ui->FrameGames->height());

//    QRect invisibleRect(c_invisibleGroupPos, QPoint(c_invisibleGroupPos.x() + c_widthGroup, ui->FrameGames->height()));
//    QRect visibleRect(c_visibleGroupPos, QPoint(c_visibleGroupPos.x() + c_widthGroup, ui->FrameGames->height()));

    //ui->FrameGroup->setGeometry(_isGroupShow ? visibleRect : invisibleRect);
    //ui->FrameGroup->raise();
}
#define EventsEnd }

void FormGames::hideHiddenGames() {
    QStringList hideList = _hide;
    for (int i = 0; i < ui->tableView->model()->rowCount(); ++i) {
        auto hiddenGame = std::find_if(hideList.cbegin(), hideList.cend(), [=](QString curGame) {
                                                                                return curGame == ui->tableView->model()->index(i, c_tableColumnAppid).data().toString();
                                                                            });
        if (hiddenGame != hideList.cend()) {
            //Найти аналог
            //ui->TableWidgetGames->item(i, c_tableColumnName)->setForeground(QColor(255 * 0.7, 0, 0));
            ui->tableView->hideRow(i);
            hideList.removeOne(*hiddenGame);
        }
    }
}

void FormGames::retranslate() {
    ui->retranslateUi(this);
    ui->tableView->model()->setHeaderData(c_tableColumnIcon,        Qt::Horizontal, tr(""));
    ui->tableView->model()->setHeaderData(c_tableColumnName,        Qt::Horizontal, tr("Название игры"));
    ui->tableView->model()->setHeaderData(c_tableColumnProgress,    Qt::Horizontal, tr("Прогресс"));
//    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnIcon, new QTableWidgetItem(tr("")));
//    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnName, new QTableWidgetItem(tr("Название игры")));
//    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnProgress, new QTableWidgetItem(tr("Прогресс")));
    //ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnTools, new QTableWidgetItem(tr("")));
    //ui->ButtonAchievements->setText(tr("Достижения"));
    //ui->ButtonFavorite->setText("");
    //ui->ButtonHide->setText("");
}

void FormGames::showHideSlideWidget(bool aShowing) {
    QRect invisibleRect(c_invisibleGroupPos, QPoint(c_invisibleGroupPos.x() + c_widthGroup, height()));
    QRect visibleRect(c_visibleGroupPos, QPoint(c_visibleGroupPos.x() + c_widthGroup, height()));

    if (aShowing) {
        _animate->setStartValue(invisibleRect);
        _animate->setEndValue(visibleRect);
    } else {
        _animate->setStartValue(visibleRect);
        _animate->setEndValue(invisibleRect);
    }
    _animate->start();

    _isGroupShow = aShowing;
}

void FormGames::mouseMoveEvent(QMouseEvent *aEvent) {
    Q_UNUSED(aEvent);
//    qDebug()<< "pos"<< aEvent->x()<< aEvent->y();
//    if (aEvent->pos().x() < c_widthVisibleGroup) {
//        if (!_isGroupShow) {
//            showHideSlideWidget(true);
//        }
//    } else {
//        if ((_isGroupShow) && (aEvent->pos().x() > (c_visibleGroupPos.x() + c_widthGroup))) {
//            showHideSlideWidget(false);
//        }
//    }
}

void FormGames::createThread() {
    Threading *loadTable = new Threading(this);
    loadTable->AddThreadGames(c_tableColumnAppid, c_tableColumnIndex, c_tableColumnIcon, c_tableColumnName, c_tableColumnComment, c_tableColumnProgress, _games);
    connect (loadTable, &Threading::s_games_progress, this, [=](int progress, int row) {
                                                                ui->ProgressBarLoading->setValue(progress);
                                                                emit s_achievementsLoaded(progress, row);
                                                            });
    connect (loadTable, &Threading::s_games_finished_model, this, [=](QStandardItemModel *model) {
        ui->tableView->setModel(model);
        ui->tableView->setSortingEnabled(true);
        ui->tableView->resizeColumnsToContents();

        ui->tableView->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
        ui->tableView->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setShowGrid(false);
        ui->tableView->setSortingEnabled(true);
        ui->tableView->horizontalHeader()->setStretchLastSection(true);
        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
//        ui->tableView->setColumnHidden(c_tableColumnAppid, true);
//        ui->tableView->setColumnHidden(c_tableColumnIndex, true);
//        ui->tableView->resizeColumnsToContents();
//        ui->tableView->setColumnWidth(c_tableColumnIcon, 33 + 8);
//        ui->tableView->setColumnWidth(c_tableColumnProgress, 150 + 8);

        _achievements.resize(_games.getCount());
        int row = 0;
        for (auto &game: _games) {
            //Загрузка достижений игрока
            SAchievementsPlayer *achievementsGame = new SAchievementsPlayer(QString::number(game._appID), _profile._steamID);
            achievementsGame->_index = row;
            connect(achievementsGame, &SAchievementsPlayer::s_finished, this, &FormGames::onResultAchievements);
            ++row;
        }
        hideHiddenGames();

        connect(ui->tableView, &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
            updateCurrentGame();
            if (_currentGame != nullptr) {
                QMenu *menu = createMenu(*_currentGame, _currentIndex);
                menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
            }
        });

        connect(ui->tableView, &QTableView::doubleClicked, this, [=](QModelIndex) {
            updateCurrentGame();
            buttonAchievements_Clicked();
        });
//    //    enableMouseTracking(ui->TableWidgetGames->children());
//    //    ui->TableWidgetGames->viewport()->setMouseTracking(true);
//    //    enableMouseTracking(ui->TableWidgetGames->viewport()->children());
//    //    ui->TableWidgetGames->installEventFilter(this);
//    //    ui->TableWidgetGames->viewport()->installEventFilter(this);
        ui->LineEditGame->setFocus();
    });
}
#define SystemEnd }

#define Filter {
void FormGames::lineEditGame_TextChanged(const QString &aFindText) {
    QString findText = aFindText.toLower();
    for (int i = 0; i < ui->tableView->model()->rowCount(); ++i) {
        ui->tableView->setRowHidden(i, ui->tableView->model()->index(i, c_tableColumnName).data().toString().toLower().indexOf(findText, 0) == -1);
    }
    if (Settings::getVisibleHiddenGames() != 1 || findText == "") {
        hideHiddenGames();
    }
}

void FormGames::buttonFind_Clicked() {
    lineEditGame_TextChanged(ui->LineEditGame->text());
}
#define FilterEnd }

#define Functions {
void FormGames::tableWidgetGames_CellClicked(int aRow, int) {
//    _selectedGame = ui->tableView->model()->index(aRow, c_tableColumnAppid).data().toString();
//    _selectedIndex = ui->tableView->model()->index(aRow, c_tableColumnIndex).data().toString();
    //Постановка иконки
//    QLabel *lGameIcon = dynamic_cast<QLabel*>(ui->tableView->cellWidget(aRow, c_tableColumnIcon));
//    if(lGameIcon) {
//        ui->LabelIconGame->setPixmap(*lGameIcon->pixmap());
//    } else {
//        ui->LabelIconGame->setPixmap(QPixmap());
//    }
//    ui->LabelTitleGame->setText(ui->TableWidgetGames->item(aRow, c_tableColumnName)->text());
    //Постановка прогрессбар
//    QProgressBar *progressBarSelectedGame = dynamic_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(aRow, c_tableColumnProgress));
//    if (progressBarSelectedGame) {
////        ui->ProgressBarSelectedGame->setMaximum(progressBarSelectedGame->maximum());
////        ui->ProgressBarSelectedGame->setValue(progressBarSelectedGame->value());
//    }
//    //Проверка является ли игра избранной
//    QJsonArray favorites = _favorites.getValues();
//    bool isFavorite = std::any_of(favorites.cbegin(), favorites.cend(),
//                                  [=](QJsonValue curFavorite) {return curFavorite.toObject().value("id").toString() == _selectedGame;});
//    if(isFavorite) {
//        ui->ButtonFavorite->setIcon(QIcon(Images::isFavorites()));
//    } else {
//        ui->ButtonFavorite->setIcon(QIcon(Images::isNotFavorites()));
//    }
//    //Проверка является ли игра скрытой
//    if(ui->TableWidgetGames->item(aRow, c_tableColumnName)->foreground() == QColor(255 * 0.7, 0, 0)) {
//        ui->ButtonHide->setIcon(QIcon(Images::unhide()));
//    }
}

void FormGames::tableWidgetGames_CellDoubleClicked(int aRow, int) {
    Q_UNUSED(aRow);
    buttonAchievements_Clicked();
}

void FormGames::buttonAchievements_Clicked() {
    SAchievementsPercentage Percentage(QString::number(_currentGame->_appID), false);
    if (Percentage.getCount() == 0) {
        QMessageBox::warning(this, tr("Ошибка"), tr("В этой игре нет достижений"));
    } else {
        //ui->ProgressBarLoading->setMaximum(ui->ProgressBarSelectedGame->maximum());
        emit s_showAchievements(*_achievements[_currentIndex], _games[_currentIndex]);
    }
}

void FormGames::buttonFavorite_Clicked() {
    QAction *action = dynamic_cast<QAction*>(sender());
    if (action) {
//        _selectedIndex = action->data().toString();
//        _selectedGame = action->whatsThis();
    }
    if(_favorites.addGame(_profile._steamID, _games[_currentIndex], true)) {
        //Категория добавилась
        action->setText(tr("Удалить из избранного"));
        action->setIcon(QIcon(Images::isFavorites()));
    } else {
        //Категория уже есть (удалилась)
        action->setText(tr("Добавить в избранное"));
        action->setIcon(QIcon(Images::isNotFavorites()));
    }
}

void FormGames::buttonHide_Clicked() {
    QAction *action = dynamic_cast<QAction*>(sender());
    if (action) {
//        _selectedIndex = action->data().toString();
//        _selectedGame = action->whatsThis();
    }
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
        writeStream <<_games[_currentIndex]._appID <<"%%" + _games[_currentIndex]._img_icon_url + "%%" + _games[_currentIndex]._name <<"\n";
    } else {
        writeStream <<_games[_currentIndex]._appID <<"\n";
    }

    fileHide.close();
    for (int i = 0; i < _games.getCount(); ++i) {
        if(_games[_currentIndex]._name == ui->tableView->model()->index(i, c_tableColumnName).data().toString()) {
            //Найти аналог
            //ui->tableView->item(i, c_tableColumnName)->setForeground(QColor(255 * 0.7, 0, 0));
            ui->tableView->setRowHidden(i, true);
            break;
        }
    }
    //ui->ButtonHide->setFixedSize(ui->ButtonHide->size());
    //ui->ButtonHide->setIcon(QIcon(Images::unhide()));
    delete btnProfile;
    delete btnAll;
}
#define FunctionsEnd }
