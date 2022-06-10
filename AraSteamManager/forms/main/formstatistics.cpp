#include "formstatistics.h"
#include "ui_formstatistics.h"
#include <math.h>
#include "forms/widgets/formfrienditemgraph.h"
#include "classes/common/theme.h"
#include "subWidgets/charts/achievementcountchart.h"
#include "subWidgets/charts/achievementcompletedpiechart.h"

constexpr int c_steamReleaseYear = 2002;
constexpr int c_secsInDay = 60 * 60 * 24;

FormStatistics::FormStatistics(QWidget *aParent): Form(aParent), ui(new Ui::FormStatistics)/*, _gamePercent(new QChart())*/ {
    ui->setupUi(this);
    init();
}

FormStatistics::~FormStatistics() {
    delete ui;
}

QStringList getDaysMonthTitles(const QDate &aDate) {
    QDate date(aDate.year(), aDate.month(), 1);
    QStringList monthsTitles;
    while (date.month() == aDate.month()) {
        monthsTitles << date.toString("dd");
        date = date.addDays(1);
    }
    return monthsTitles;
}

QStringList getYearsTitles() {
    QStringList list;
    QDate date(c_steamReleaseYear,1,1);
    while (date < QDate::currentDate()) {
        list << date.toString("yyyy");
        date = date.addYears(1);
    }
    return list;
}

void FormStatistics::init() {
    initingTable(ui->tableViewLastAchievements);
    ui->tableViewLastAchievements->horizontalHeader()->setVisible(false);
    ui->tableViewLastAchievements->verticalHeader()->setVisible(false);
    ui->tableViewLastAchievements->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableViewLastAchievements->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    initPie();
    ui->horizontalLayoutPie->setStretch(0, 1);
    ui->horizontalLayoutPie->setStretch(1, 2);
    initingTable(ui->TableViewGames)->verticalHeader()->setVisible(true);

    ui->stackedWidgetGraphs->setCurrentIndex(0);
    ui->ChartsViewTimes->setChart(new AchievementCountChart());
    ui->ChartsViewTimes->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewTimes->setMinimumSize(480, 480);
    dynamic_cast<AchievementCountChart*>(ui->ChartsViewTimes->chart())->addAxisX(getDaysMonthTitles(QDate::currentDate()));
    ui->ChartsViewYears->setChart(new AchievementCountChart());
    ui->ChartsViewYears->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewYears->setMinimumSize(480, 480);
    dynamic_cast<AchievementCountChart*>(ui->ChartsViewYears->chart())->addAxisX(getYearsTitles());

    connect(ui->TableViewGames, &QTableView::customContextMenuRequested, this, [&](QPoint pos) {
        SGame *game = currentGame();
        if (game != nullptr) {
            createMenu(*game)->popup(ui->TableViewGames->viewport()->mapToGlobal(pos));
        }
    });

    connect(ui->TableViewGames, &QTableView::doubleClicked, this, [&](QModelIndex aIndex) {
        Q_UNUSED(aIndex);
        SGame *game = currentGame();
        if (game != nullptr) {
            emit s_showAchievements(*game);
        }
    });

    connect(ui->comboBoxGraph, &QComboBox::currentIndexChanged, ui->stackedWidgetGraphs, &QStackedWidget::setCurrentIndex);

    connect(ui->comboBoxCurrentProfile, &ComboBoxFriends::s_friendClicked, this, &FormStatistics::updateStatisticProfile);
    connect(ui->comboBoxGraphsFriends, &ComboBoxFriends::s_friendClicked, this, [&](const SProfile &lProfile) {
        Statistics *statistic = new Statistics(lProfile);
        createThreadFriend(*statistic);
    });

    retranslate();

    GamesWithPercentModel *model2 = new GamesWithPercentModel();
    ui->TableViewGames->setModel(model2);
    ui->TableViewGames->setSortingEnabled(true);
    ui->TableViewGames->setColumnHidden(gamesWithPercentModel::Appid, true);
    ui->TableViewGames->setColumnHidden(gamesWithPercentModel::Index, true);
}

bool FormStatistics::isInit() {
    return (_userProfile.steamID() != "");
}

void FormStatistics::clear() {
    _userProfile = SProfile();
    _statisticProfile = SProfile();
}

void FormStatistics::setProfile(const SProfile &aProfile) {
    _userProfile = aProfile;
    _statisticProfile = _userProfile;
    _statistics = Statistics(_userProfile);

    createThread();

    ui->comboBoxCurrentProfile->clear();
    auto profiles = SProfile::load(SFriend::getFriendsSteamId(aProfile.steamID()));
    for(const auto &profileFriend: profiles) {
        ui->comboBoxCurrentProfile->addItem(profileFriend);
    }
}

void FormStatistics::createThread() {
    ThreadStatistics *statistics = new ThreadStatistics(_statistics);
    connect(statistics, &ThreadStatistics::s_progress, this, &Form::setStatus);
    connect(statistics, &ThreadStatistics::s_finish, this, &FormStatistics::onFinish);
    statistics->start();
}

QChart *addLineToChart(QChart *chart, QVector<QPointF> &datas, const QString &name, const QColor &color) {
    if (auto acChart = dynamic_cast<AchievementCountChart*>(chart)) {
        acChart->addLineToChart(datas, name, color);
    }
    return chart;
}

void FormStatistics::onFinish(Statistics &aStatistic) {
    ui->labelProfile->setPixmap(aStatistic.profile.pixmapAvatar());
    ui->labelProfile->setToolTip(aStatistic.profile.personaName());

    aStatistic.summAverages = 100.0 * aStatistic.complete.count();
    for (const auto &average: qAsConst(aStatistic.started)) {
        aStatistic.summAverages += average.percent;
    }
    aStatistic.sortAllLists();

    setInfo(aStatistic);
    setPie(aStatistic);
    clearGraphs();
    setGraphs(aStatistic);
    emit s_finish();
}

void FormStatistics::initPie() {
    auto pie = new AchievementCompletedPieChart();
    connect(pie, &AchievementCompletedPieChart::s_noAchievementsClicked, this, [&]() {
        _currentGamesType = GamesType::noAchievements;
        setModelToTable(_statistics.noAchievements, false);
    });
    connect(pie, &AchievementCompletedPieChart::s_notStartedClicked, this, [&]() {
        _currentGamesType = GamesType::notStarted;
        setModelToTable(_statistics.notStarted, true);
    });
    connect(pie, &AchievementCompletedPieChart::s_startedClicked, this, [&]() {
        _currentGamesType = GamesType::started;
        setModelToTable(_statistics.started, true);
    });
    connect(pie, &AchievementCompletedPieChart::s_completedClicked, this, [&]() {
        _currentGamesType = GamesType::complete;
        setModelToTable(_statistics.complete, true);
    });
    ui->ChartViewPercentages->setChart(pie);
}

SGame *FormStatistics::currentGame() {
    if (_currentGamesType == GamesType::none) {
        _currentIndex = -1;
        return nullptr;
    }
    int row = ui->TableViewGames->currentIndex().row();
    _currentIndex = ui->TableViewGames->model()->index(row, StaticticGamesIndex).data().toString().toInt();
    int appId     = ui->TableViewGames->model()->index(row, StaticticGamesAppId).data().toString().toInt();

    QList<GameWithPercentModelItem> *list;

    switch(_currentGamesType) {
    case GamesType::complete: {
        list = &_statistics.complete;
        break;
    }
    case GamesType::started: {
        list = &_statistics.started;
        break;
    }
    case GamesType::notStarted: {
        list = &_statistics.notStarted;
        break;
    }
    case GamesType::noAchievements: {
        list = &_statistics.noAchievements;
        break;
    }
    default: {
        return nullptr;
    }
    }

    if (list != nullptr) {
        auto iterator = std::find_if(list->begin(),
                                     list->end(),
                                     [=](const GameWithPercentModelItem &game) {
                                         return game.game.appId() == appId;
                                     });
        if (iterator != _statistics.complete.end()) {
            return &(*iterator).game;
        }
    }
    return nullptr;
}

QMenu *FormStatistics::createMenu(SGame &aGame) {
//    GameID appId = aGame.appId();

    //Добавление перехода на достижения
    QAction *actionAchievements = new QAction(tr("Достижения"), this);
    actionAchievements->setIcon(QIcon(Images::achievement()));

    QMenu *menu = new QMenu(this);
    menu->addAction (actionAchievements);
    connect (actionAchievements, &QAction::triggered, this, [&]() {
        emit s_showAchievements(aGame);
    });

    return menu;
}

void FormStatistics::retranslate() {
    ui->retranslateUi(this);
//    QList<QAbstractSeries*> series = _gamePercent->series();
//    if (series.count() > 0) {
//        if (QPieSeries *pie = dynamic_cast<QPieSeries*>(series[0])) {
//            auto legends = _gamePercent->legend()->markers(pie);
//            switch (legends.count()) {
//            default:
//            case 4: {
//                legends[3]->setLabel(tr("Нет достижений"));
//                [[fallthrough]];
//            }
//            case 3: {
//                legends[2]->setLabel(tr("Не начато"));
//                [[fallthrough]];
//            }
//            case 2: {
//                legends[1]->setLabel(tr("Начато"));
//                [[fallthrough]];
//            }
//            case 1: {
//                legends[0]->setLabel(tr("Закончено"));
//                break;
//            }
//            case 0: {
//                qWarning() << "on retranslate legends.count = 0";
//            }
//            }
//        } else {
//            qWarning() << "on retranslate pie = nullptr";
//        }
//    } else {
//        qWarning() << "on retranslate series.count = 0";
//    }
    if (auto chart = ui->ChartsViewTimes->chart()) {
        chart->setTitle(tr("Последний месяц"));
    }
    if (auto chart = ui->ChartsViewYears->chart()) {
        chart->setTitle(tr("Достижения по годам"));
    }
    ui->comboBoxGraph->clear();
    ui->comboBoxGraph->addItems(QStringList {tr("Последний месяц"), tr("По годам")});
}

void FormStatistics::createThreadFriend(Statistics &aStatistics) {
    ThreadStatistics *statistics = new ThreadStatistics(aStatistics);
    connect(statistics, &ThreadStatistics::s_progress,  this, &Form::setStatus);
    connect(statistics, &ThreadStatistics::s_finish,  this, &Form::clearStatus);
    connect(statistics, &ThreadStatistics::s_finish,  this, &FormStatistics::addFriendLines);
    statistics->start();
}

void FormStatistics::setInfo(Statistics &aStatistic) {
    constexpr long long lastAchievements = 50;
    ui->labelAverageAllGamesValue->setText(QString::number(aStatistic.summAverages / (aStatistic.complete.count() + aStatistic.started.count() + aStatistic.notStarted.count())) + "%");
    ui->labelAverageStartedGamesValue->setText(QString::number(aStatistic.summAverages / (aStatistic.complete.count() + aStatistic.started.count())) + "%");
    ui->labelSumAchievementsValue->setText(QString::number(aStatistic.achievementCount));
    ui->labelCompletedGamesValue->setText(QString::number(aStatistic.complete.count()));
    ui->labelStartedGamesValue->setText(QString::number(aStatistic.started.count()));
    ui->labelNotStartedGamesValue->setText(QString::number(aStatistic.notStarted.count()));
    ui->labelNoAchievementsGamesValue->setText(QString::number(aStatistic.noAchievements.count()));

    if (ui->tableViewLastAchievements->model() != nullptr) {
        delete ui->tableViewLastAchievements->model();
    }

    QStandardItemModel *model = new QStandardItemModel();
    auto tempLast50 = aStatistic.completedAchievements.last(std::min(lastAchievements, aStatistic.completedAchievements.size()));
    QList<CompletedAchievement> last50(reverseList<CompletedAchievement>(tempLast50));
    QMap<GameID, QList<SAchievementSchema>> mapGames;


    for (int i = 0; const auto &achievements: last50) {
        auto iteratorGames = mapGames.find(achievements.game.appId());
        if (iteratorGames == mapGames.end()) {
            iteratorGames = mapGames.insert(achievements.game.appId(), SAchievementSchema::load(achievements.game.appId()));
        }
        auto schema = (*iteratorGames);
        auto iteratorSchema = std::find_if(schema.begin(),
                                          schema.end(),
                                          [&](const SAchievementSchema &aSchema) {
                                              return aSchema.apiName() == achievements.achievement.apiName();
                                          });
        if (iteratorSchema != schema.end()) {
            QStandardItem * item = new QStandardItem();
            QImage pix = loadImage((*iteratorSchema).icon(), Paths::imagesAchievements(QString::number(iteratorGames.key()), (*iteratorSchema).icon()), QSize(32, 32));
            item->setData(QPixmap::fromImage(pix), Qt::ItemDataRole::DecorationRole);
            QString toolTip = textToToolTip("<b>" + achievements.game.name() + "</b>\n" +
                                            (*iteratorSchema).description())
                                .replace("\n", "<br>");
            item->setData(toolTip, Qt::ItemDataRole::ToolTipRole);
            model->setItem(i / 10, i % 10, item);
        }
        setStatus(tr("Последние достижения"), ++i, lastAchievements);
    }

    ui->tableViewLastAchievements->setModel(model);
    ui->tableViewLastAchievements->resizeColumnsToContents();
    ui->tableViewLastAchievements->resizeRowsToContents();
    ui->tableViewLastAchievements->setFixedSize(getWidthTableColumns(ui->tableViewLastAchievements, false), getHeightTableColumns(ui->tableViewLastAchievements, false));
}

void FormStatistics::setPie(const Statistics &aStatistic) {
    auto pie = dynamic_cast<AchievementCompletedPieChart*>(ui->ChartViewPercentages->chart());
    if (pie) {
        pie->setNoAchievements(aStatistic.noAchievements.count());
        pie->setNotStarted(aStatistic.notStarted.count());
        pie->setStarted(aStatistic.started.count());
        pie->setCompleted(aStatistic.complete.count());
    }
//    if (_gamePercent->series().size() > 0) {
//        if (auto series = dynamic_cast<QPieSeries*>(_gamePercent->series().at(0))) {
//            auto slices = series->slices();
//            switch (series->count()) {
//            default:
//            case 4: {
//                slices[3]->setLabel(QString("%1%").arg(100.0 * aStatistic.noAchievements.count() / aStatistic.games.count(), 0, 'f', 2));
//                slices[3]->setValue(aStatistic.noAchievements.count());
//                [[fallthrough]];
//            }
//            case 3: {
//                slices[2]->setLabel(QString("%1%").arg(100.0 * aStatistic.notStarted.count() / aStatistic.games.count(), 0, 'f', 2));
//                slices[2]->setValue(aStatistic.notStarted.count());
//                [[fallthrough]];
//            }
//            case 2: {
//                slices[1]->setLabel(QString("%1%").arg(100.0 * aStatistic.started.count() / aStatistic.games.count(), 0, 'f', 2));
//                slices[1]->setValue(aStatistic.started.count());
//                [[fallthrough]];
//            }
//            case 1: {
//                slices[0]->setLabel(QString("%1%").arg(100.0 * aStatistic.complete.count() / aStatistic.games.count(), 0, 'f', 2));
//                slices[0]->setValue(aStatistic.complete.count());
//                break;
//            }
//            case 0: {
//                qWarning() << "on set data to pie slices.count = 0";
//            }
//            }
//        }
//    }
}

void FormStatistics::clearGraphs() {
    for(auto series: ui->ChartsViewTimes->chart()->series()) {
        delete series;
    }
    for(auto series: ui->ChartsViewYears->chart()->series()) {
        delete series;
    }
}

void FormStatistics::setGraphs(Statistics &aStatistic) {
    QColor color = _colors[0];

    int x = 0;
    QVector<QPointF> datasT(daysInMonth(QDate::currentDate()));
    for (auto &point: datasT) {
        point.setX(x++);
    }
    const int startMonthSecs = QDateTime(QDate(QDate::currentDate().year(), QDate::currentDate().month(), 1), QTime()).toSecsSinceEpoch();
    for (const auto &achievement: aStatistic.completedAchievements) {
        int secsFromStartMonth = achievement.achievement.unlockTime().toSecsSinceEpoch() - startMonthSecs;
        if (secsFromStartMonth > 0) {
            int index = secsFromStartMonth / c_secsInDay;
            datasT[index].setY(datasT[index].y() + 1);
        }
    }
    addLineToChart(ui->ChartsViewTimes->chart(), datasT, aStatistic.profile.personaName(), color);

    x = 0;
    QVector<QPointF> datasY;
    for (const auto &data: aStatistic.years) {
        datasY << QPointF(data.year.toInt() - c_steamReleaseYear, data.count);
        ++x;
    }
    addLineToChart(ui->ChartsViewYears->chart(), datasY, aStatistic.profile.personaName(), color);
    QStringList list;
    for(const SFriend &sFriend: SFriend::load(aStatistic.profile.steamID())) {
        list.append(sFriend.steamId());
    }
    ui->comboBoxGraphsFriends->clear();
    auto profiles = SProfile::load(list);
    for(const auto &profileFriend: profiles) {
        ui->comboBoxGraphsFriends->addItem(profileFriend);
    }
    ui->comboBoxGraphsFriends->sort(Qt::SortOrder::AscendingOrder);
}

void FormStatistics::addFriendLines(Statistics &aStatistic) {
    aStatistic.sortAllLists();
    QColor color = _colors[0];
    int colorNumber = ui->listWidgetFriendsGraph->count() + 1;
    if (colorNumber >= c_colorCount) {
        ui->comboBoxGraphsFriends->addItem(aStatistic.profile);
        ui->comboBoxGraphsFriends->sort(Qt::SortOrder::AscendingOrder);
        return;
    } else {
        color = _colors[colorNumber];
    }

    QListWidgetItem *item = new QListWidgetItem(aStatistic.profile.pixmapAvatar(), "");

    auto friendItem = new FormFriendItemGraph(aStatistic.profile, color, item);
    connect(friendItem, &FormFriendItemGraph::s_delete, this, [=, this]() {
        auto profile = friendItem->steamProfile();
        delete friendItem->item();
        if (profile) {
            ui->comboBoxGraphsFriends->addItem(*profile);
            removeFriendLines(*profile);
        }
    });
    ui->listWidgetFriendsGraph->addItem(item);
    ui->listWidgetFriendsGraph->setItemWidget(item, friendItem);

    AchievementCountChart *chartTimes = dynamic_cast<AchievementCountChart*>(ui->ChartsViewTimes->chart());
    AchievementCountChart *chartYears = dynamic_cast<AchievementCountChart*>(ui->ChartsViewYears->chart());
    if (chartTimes) {
        int x = 0;
        QVector<QPointF> datasT(daysInMonth(QDate::currentDate()));
        for (auto &point: datasT) {
            point.setX(x++);
        }
        const int startMonthSecs = QDateTime(QDate(QDate::currentDate().year(), QDate::currentDate().month(), 1), QTime()).toSecsSinceEpoch();
        for (const auto &achievement: aStatistic.completedAchievements) {
            int secsFromStartMonth = achievement.achievement.unlockTime().toSecsSinceEpoch() - startMonthSecs;
            if (secsFromStartMonth > 0) {
                int index = secsFromStartMonth / c_secsInDay;
                datasT[index].setY(datasT[index].y() + 1);
            }
        }
        addLineToChart(chartTimes, datasT, aStatistic.profile.personaName(), color);
    }
    if (chartYears) {
        QVector<QPointF> datasY;
        for (const auto &data: aStatistic.years) {
            datasY << QPointF(data.year.toInt() - c_steamReleaseYear, data.count);
        }
        addLineToChart(chartYears, datasY, aStatistic.profile.personaName(), color);
    }
}

void FormStatistics::removeFriendLines(const SProfile &aProfile) {
    AchievementCountChart *chartTimes = dynamic_cast<AchievementCountChart*>(ui->ChartsViewTimes->chart());
    AchievementCountChart *chartYears = dynamic_cast<AchievementCountChart*>(ui->ChartsViewYears->chart());
    if (chartTimes) {
        chartTimes->removeSeries(chartTimes->getSeries(aProfile.personaName()));
    }
    if (chartYears) {
        chartYears->removeSeries(chartYears->getSeries(aProfile.personaName()));
    }
    for (int j = 0; j < ui->listWidgetFriendsGraph->count(); ++j) {
        if (auto friendWidget = dynamic_cast<FormFriendItemGraph*>(ui->listWidgetFriendsGraph->itemWidget(ui->listWidgetFriendsGraph->item(j)))) {
            if (chartTimes) {
                auto series = chartTimes->getSeries(friendWidget->steamProfile()->personaName());
                if (series) {
                    chartTimes->setSeriesColor(series, _colors[j + 1]);
                }
            }
            if (chartYears) {
                auto series = chartYears->getSeries(friendWidget->steamProfile()->personaName());
                if (series) {
                    chartYears->setSeriesColor(series, _colors[j + 1]);
                }
            }
            friendWidget->setColor(_colors[j + 1]);
        }
    }
}

void FormStatistics::updateStatisticProfile(const SProfile &aProfile) {
    ui->comboBoxCurrentProfile->addItem(_statisticProfile);

    _statisticProfile = aProfile;
    auto games = SGame::load(_statisticProfile.steamID(), true, true);
    _statistics.changeProfile(_statisticProfile);
    createThread();
}

void FormStatistics::setModelToTable(QList<GameWithPercentModelItem> aGames, bool aIsVisiblePercent) {
    if (_currentGamesType == GamesType::none) {
        ui->TableViewGames->setVisible(false);
        return;
    }
    if (auto model = dynamic_cast<GamesWithPercentModel*>(ui->TableViewGames->model())) {
        model->setGames(aGames, _statisticProfile.steamID());
        if (_currentGamesType == GamesType::started) {
            model->sort(gamesWithPercentModel::Percent, Qt::DescendingOrder);
        } else {
            model->sort(gamesWithPercentModel::Title, Qt::AscendingOrder);
        }
    } else {
        qWarning() << "error model in TableViewGames is not GamesWithPercentModel";
    }
    ui->TableViewGames->setColumnHidden(gamesWithPercentModel::Percent, !aIsVisiblePercent);
    ui->TableViewGames->resizeColumnsToContents();
    ui->TableViewGames->resizeRowsToContents();
    ui->TableViewGames->setVisible(true);
}

void FormStatistics::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}

void FormStatistics::updateIcons() {

}
