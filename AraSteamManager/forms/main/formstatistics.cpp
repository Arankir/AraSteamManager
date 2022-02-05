#include "formstatistics.h"
#include "ui_formstatistics.h"
#include <math.h>
#include "forms/widgets/formfrienditemgraph.h"

constexpr int c_steamReleaseYear = 2002;
constexpr int c_secsInDay = 60 * 60 * 24;

QChart *initChart(QChartView *chartView, const QStringList &aList) {
    QChart *chart = new QChart();
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::NoAnimation);
    chart->setBackgroundVisible(false);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(480, 480);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%i");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(aList);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    axisX->setLabelsColor(Theme::getCurrentTheme().text.color);
    axisY->setLabelsColor(Theme::getCurrentTheme().text.color);
    chart->setTitleBrush(Theme::getCurrentTheme().text.color);
    chart->legend()->setLabelColor(Theme::getCurrentTheme().text.color);
    chart->axes(Qt::Vertical).at(0)->setGridLineColor(Theme::getCurrentTheme().border.color);
    chart->axes(Qt::Horizontal).at(0)->setGridLineColor(Theme::getCurrentTheme().border.color);
    return chart;
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

int roundToDesimal(int data) {
    const double delta = 0.1;
    static const QVector<double> logs {0, log10(1), log10(2), log10(3), log10(4), log10(5), log10(6), log10(7), log10(8), log10(9), 1};
    int newData = data;
    double dDecimal = log10(data);
    int iDecimal = dDecimal;
    dDecimal -= iDecimal;
    for (int i = 1; i < 11; ++i) {
//        qDebug() << i;
        if (dDecimal < logs[i]) {
            newData = pow(10, logs[i - 1] + iDecimal);
            break;
        }
    }
    if (newData % 10 == 9) {
        ++newData;
    }
    for (int i = 0; i < 20; ++i) {
//        qDebug() << data << newData << abs((1.0 * data/newData) - 0.8) << (1.0 * data/newData);
        if (abs((1.0 * data/newData) - 0.8) < delta) {
            break;
        }
        newData += pow(10, iDecimal - 1);
    }
    return newData;
}

QChart *updateChartHeight(QChart *chart) {
    int max = 9;
    for (auto sery: chart->series()) {
        if (auto realSery = dynamic_cast<QLineSeries*>(sery)) {
            auto points = realSery->points();
            auto maxElement = std::max_element(points.begin(),
                                                points.end(),
                                                [=](const QPointF point1, const QPointF point2) {
                                                    return point1.y() < point2.y();
                                                });
            if (maxElement < points.end()) {
                if ((*maxElement).y() > max) {
                    max = (*maxElement).y();
                }
            }
        }
    }
    chart->axes(Qt::Vertical).at(0)->setRange(0, roundToDesimal(max));
    return chart;
}

QChart *updateChartWidth(QChart *chart) {
    QStringList categories;
    if (auto bar = dynamic_cast<QBarCategoryAxis*>(chart->axes(Qt::Horizontal).at(0))) {
        categories = bar->categories();
    } else {
        return chart;
    }
    int min = 4000;
    int max = 1;
    for (auto sery: chart->series()) {
        if (auto realSery = dynamic_cast<QLineSeries*>(sery)) {
            auto points = realSery->points();
            if (points.size() > 0) {
                auto minMax = std::minmax_element(points.begin(),
                                                    points.end(),
                                                    [=](const QPointF point1, const QPointF point2) {
                                                       return point1.x() < point2.x();
                                                    });
                if (categories.at((*(minMax.first)).x()).toInt() < min) {
                    min = categories.at((*(minMax.first)).x()).toInt();
                }
                if (categories.at((*(minMax.second)).x()).toInt() > max) {
                    max = categories.at((*(minMax.second)).x()).toInt();
                }
            }
        }
    }
    if (min == 4000) {
        min = 0;
    }
    for (auto axis: chart->axes(Qt::Horizontal)) {
        axis->setRange(min, max);
    }
    return chart;
}

QPieSlice *createPieChart(QColor aColor) {
    QPieSlice *slice = new QPieSlice();
    slice->setBrush(aColor);
    slice->setBorderColor(Theme::getCurrentTheme().border.color);
    slice->setLabelVisible(true);
    slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
    QObject::connect(slice, &QPieSlice::hovered, slice, &QPieSlice::setExploded);
    return slice;
}

FormStatistics::FormStatistics(const SProfile &aProfile, const SGames &aGames, QWidget *aParent):
Form(aParent), ui(new Ui::FormStatistics), _userProfile(aProfile), _games(aGames), _statisticProfile(_userProfile),
_statistics(aProfile, aGames), _gamePercent(new QChart()) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);

    ui->comboBoxCurrentProfile->clear();
    auto profiles = SProfile::load(SFriend::getFriendsSteamId(aProfile.steamID()));
    for(const auto &profileFriend: profiles) {
        ui->comboBoxCurrentProfile->addItem(profileFriend);
    }

    initingTable(ui->tableViewLastAchievements);
    ui->tableViewLastAchievements->horizontalHeader()->setVisible(false);
    ui->tableViewLastAchievements->verticalHeader()->setVisible(false);

    initPie();
    ui->horizontalLayoutPie->setStretch(0, 1);
    ui->horizontalLayoutPie->setStretch(1, 2);
    initingTable(ui->TableViewGames)->verticalHeader()->setVisible(true);
    ui->TableViewGames->setVisible(false);

    ui->stackedWidgetGraphs->setCurrentIndex(0);
    initChart(ui->ChartsViewTimes, getDaysMonthTitles(QDate::currentDate()));
    initChart(ui->ChartsViewYears, getYearsTitles());

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
            QList<SAchievementPlayer> player = SAchievementPlayer::load(game->appId(), _statistics.profile.steamID());
            if (player.count() == 0) {
                QMessageBox::warning(this, tr("Ошибка"), tr("В этой игре нет достижений"));
            } else {
                emit s_showAchievements(*game);
            }
        }
    });

    connect(ui->comboBoxGraph, &QComboBox::currentIndexChanged, ui->stackedWidgetGraphs, &QStackedWidget::setCurrentIndex);

    connect(ui->comboBoxCurrentProfile, &ComboBoxFriends::s_friendClicked, this, &FormStatistics::updateStatisticProfile);
    connect(ui->comboBoxGraphsFriends, &ComboBoxFriends::s_friendClicked, this, [&](const SProfile &lProfile) {
        Statistics *statistic = new Statistics(lProfile, SGame::load(lProfile.steamID(), true, true));
        createThreadFriend(*statistic);
    });

    retranslate();
    createThread();
}

void FormStatistics::initPie() {
    _gamePercent->setBackgroundVisible(false);
    _gamePercent->setAnimationOptions(QChart::SeriesAnimations);
    _gamePercent->legend()->setAlignment(Qt::AlignBottom);
    _gamePercent->setMargins(QMargins(1, 1, 1, 1));
    QPieSeries *series = new QPieSeries();
    QPieSlice *complete         = createPieChart(QColor(85,  181, 62));
    QPieSlice *started          = createPieChart(QColor(205, 203, 31));
    QPieSlice *notStarted       = createPieChart(QColor(178, 50,  50));
    QPieSlice *noAchievements   = createPieChart(QColor(20,  20,  20));
    connect(complete,       &QPieSlice::clicked, this, [&]() {
        _currentGamesType = GamesType::complete;
        setModelToTable(_statistics.complete, false);
    });
    connect(started,        &QPieSlice::clicked, this, [&]() {
        _currentGamesType = GamesType::started;
        setModelToTable(_statistics.started, true);
    });
    connect(notStarted,     &QPieSlice::clicked, this, [&]() {
        _currentGamesType = GamesType::notStarted;
        setModelToTable(_statistics.notStarted, false);
    });
    connect(noAchievements, &QPieSlice::clicked, this, [&]() {
        _currentGamesType = GamesType::noAchievements;
        setModelToTable(_statistics.noAchievements, false);
    });
    series->append(complete);
    series->append(started);
    series->append(notStarted);
    series->append(noAchievements);

    _gamePercent->removeAllSeries();
    _gamePercent->addSeries(series);
    _gamePercent->legend()->setLabelColor(Theme::getCurrentTheme().text.getColor());

    ui->ChartViewPercentages->setChart(_gamePercent);
}

SGame *FormStatistics::currentGame() {
    if (_currentGamesType == GamesType::none) {
        _currentIndex = -1;
        return nullptr;
    }
    int row = ui->TableViewGames->currentIndex().row();
    _currentIndex = ui->TableViewGames->model()->index(row, StaticticGamesIndex).data().toString().toInt();
    int appId     = ui->TableViewGames->model()->index(row, StaticticGamesAppId).data().toString().toInt();

    QList<GameWithPercent> *list;

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
                                     [=](const GameWithPercent &game) {
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
    QList<QAbstractSeries*> series = _gamePercent->series();
    if (series.count() > 0) {
        if (QPieSeries *pie = dynamic_cast<QPieSeries*>(series[0])) {
            auto legends = _gamePercent->legend()->markers(pie);
            switch (legends.count()) {
            default:
            case 4: {
                legends[3]->setLabel(tr("Нет достижений"));
                [[fallthrough]];
            }
            case 3: {
                legends[2]->setLabel(tr("Не начато"));
                [[fallthrough]];
            }
            case 2: {
                legends[1]->setLabel(tr("Начато"));
                [[fallthrough]];
            }
            case 1: {
                legends[0]->setLabel(tr("Закончено"));
                break;
            }
            case 0: {
                qWarning() << "on retranslate legends.count = 0";
            }
            }
        } else {
            qWarning() << "on retranslate pie = nullptr";
        }
    } else {
        qWarning() << "on retranslate series.count = 0";
    }
    if (auto chart = ui->ChartsViewTimes->chart()) {
        chart->setTitle(tr("Последний месяц"));
    }
    if (auto chart = ui->ChartsViewYears->chart()) {
        chart->setTitle(tr("Достижения по годам"));
    }
    ui->comboBoxGraph->clear();
    ui->comboBoxGraph->addItems(QStringList {tr("Последний месяц"), tr("По годам")});
}

void FormStatistics::createThread() {
    ThreadStatistics *statistics = new ThreadStatistics(_statistics);
    connect(statistics, &ThreadStatistics::s_progress,  this, &Form::setStatus);
    connect(statistics, &ThreadStatistics::s_finish,  this, &FormStatistics::onFinish);
    statistics->start();
}

void FormStatistics::createThreadFriend(Statistics &aStatistics) {
    ThreadStatistics *statistics = new ThreadStatistics(aStatistics);
    connect(statistics, &ThreadStatistics::s_progress,  this, &Form::setStatus);
    connect(statistics, &ThreadStatistics::s_finish,  this, &FormStatistics::addFriendLines);
    statistics->start();
}

QChart *addLineToChart(QChart *chart, QVector<QPointF> &datas, const QString &name, const QColor &color) {
    if (chart) {
        QLineSeries *lineSeries = new QLineSeries();
        for (auto data: datas) {
            lineSeries->append(data);
        }
        chart->addSeries(lineSeries);
        lineSeries->setName(name);
        lineSeries->attachAxis(chart->axes(Qt::Horizontal).at(0));
        lineSeries->attachAxis(chart->axes(Qt::Vertical).at(0));
        lineSeries->setPointLabelsVisible(true);
        lineSeries->setPointLabelsFont(QFont(Theme::defaultFont(), 14));
        lineSeries->setPointLabelsFormat("@yPoint");

        lineSeries->setColor(color);
        QColor label(color);
        label.setHsl(color.hue(), (int)(color.saturation() * 0.5), (int)(color.lightness() * 0.7));
        lineSeries->setPointLabelsColor(label);
        lineSeries->setPointsVisible(true);
        lineSeries->setPointLabelsClipping(false);
    }
    return updateChartHeight(updateChartWidth(chart));
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
            mapGames.insert(achievements.game.appId(), SAchievementSchema::load(achievements.game.appId()));
            iteratorGames = mapGames.find(achievements.game.appId());
        }
        auto schema = (*iteratorGames);
        auto iteratorSchema = std::find_if(schema.begin(),
                                          schema.end(),
                                          [&](const SAchievementSchema &aSchema) {
                                              return aSchema.apiName() == achievements.achievement.apiName();
                                          });
        if (iteratorSchema != schema.end()) {
            QStandardItem * item = new QStandardItem();
            QImage pix = loadImage((*iteratorSchema).icon(), Paths::imagesAchievements(QString::number(iteratorGames.key()), (*iteratorSchema).icon()), QSize(64, 64));
            item->setData(QPixmap::fromImage(pix), Qt::ItemDataRole::DecorationRole);
            QString toolTip = textToToolTip("<b>" + achievements.game.name() + "</b>\n" +
                                            (*iteratorSchema).description())
                                .replace("\n", "<br>");
            item->setData(toolTip, Qt::ItemDataRole::ToolTipRole);
            model->setItem(i / 5, i % 5, item);
        }
        setStatus(tr("Последние достижения"), ++i, lastAchievements);
    }

    ui->tableViewLastAchievements->setModel(model);
    ui->tableViewLastAchievements->resizeColumnsToContents();
    ui->tableViewLastAchievements->resizeRowsToContents();
}

void FormStatistics::setPie(const Statistics &aStatistic) {
    if (_gamePercent->series().size() > 0) {
        if (auto series = dynamic_cast<QPieSeries*>(_gamePercent->series().at(0))) {
            auto slices = series->slices();
            switch (series->count()) {
            default:
            case 4: {
                slices[3]->setLabel(QString("%1%").arg(100.0 * aStatistic.noAchievements.count() / aStatistic.games.count(), 0, 'f', 2));
                slices[3]->setValue(aStatistic.noAchievements.count());
                [[fallthrough]];
            }
            case 3: {
                slices[2]->setLabel(QString("%1%").arg(100.0 * aStatistic.notStarted.count() / aStatistic.games.count(), 0, 'f', 2));
                slices[2]->setValue(aStatistic.notStarted.count());
                [[fallthrough]];
            }
            case 2: {
                slices[1]->setLabel(QString("%1%").arg(100.0 * aStatistic.started.count() / aStatistic.games.count(), 0, 'f', 2));
                slices[1]->setValue(aStatistic.started.count());
                [[fallthrough]];
            }
            case 1: {
                slices[0]->setLabel(QString("%1%").arg(100.0 * aStatistic.complete.count() / aStatistic.games.count(), 0, 'f', 2));
                slices[0]->setValue(aStatistic.complete.count());
                break;
            }
            case 0: {
                qWarning() << "on set data to pie slices.count = 0";
            }
            }
        }
    }
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
}

void FormStatistics::addFriendLines(Statistics &aStatistic) {
    aStatistic.sortAllLists();
    QColor color = _colors[0];
    if (auto chart = ui->ChartsViewTimes->chart()) {
        color = _colors[chart->series().count()];
        if (color == QColor()) {
            ui->comboBoxCurrentProfile->addItem(aStatistic.profile);
            return;
        }

        QListWidgetItem *item = new QListWidgetItem(aStatistic.profile.pixmapAvatar(), "");

        auto friendItem = new FormFriendItemGraph(aStatistic.profile, color, item);
        connect(friendItem, &FormFriendItemGraph::s_delete, this, [&]() {
            auto sndr = dynamic_cast<FormFriendItemGraph*>(sender());
            if (sndr == nullptr) {
                return;
            }
            ui->comboBoxGraphsFriends->addItem(*sndr->steamProfile());
            delete sndr->item();
            removeFriendLines(*sndr->steamProfile());
        });
        ui->listWidgetFriendsGraph->addItem(item);
        ui->listWidgetFriendsGraph->setItemWidget(item, friendItem);

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
        addLineToChart(chart, datasT, aStatistic.profile.personaName(), color);
    }

    int x = 0;
    QVector<QPointF> datasY;
    for (const auto &data: aStatistic.years) {
        datasY << QPointF(data.year.toInt() - c_steamReleaseYear, data.count);
        ++x;
    }
    addLineToChart(ui->ChartsViewYears->chart(), datasY, aStatistic.profile.personaName(), color);
}

void FormStatistics::removeFriendLines(const SProfile &aProfile) {
    int index = 0;
    if (auto chart = ui->ChartsViewTimes->chart()) {
        for (auto series: chart->series()) {
            if (series->name() == aProfile.personaName()) {
                chart->removeSeries(series);
                break;
            }
            ++index;
        }
        for (int i = index; i < chart->series().size(); ++i) {
            if (auto sery = dynamic_cast<QLineSeries*>(chart->series().at(i))) {
                sery->setColor(_colors[i]);
            }
        }
        updateChartHeight(updateChartWidth(ui->ChartsViewTimes->chart()));
    }

    if (auto chart = ui->ChartsViewYears->chart()) {
        chart->removeSeries(chart->series().at(index));
        for (int i = index; i < chart->series().size(); ++i) {
            if (auto sery = dynamic_cast<QLineSeries*>(chart->series().at(i))) {
                sery->setColor(_colors[i]);
                QColor label(_colors[i]);
                label.setHsl(_colors[i].hue(), (int)(_colors[i].saturation() * 0.5), (int)(_colors[i].lightness() * 0.7));
                sery->setPointLabelsColor(label);
                for (int j = 0; j < ui->listWidgetFriendsGraph->count(); ++j) {
                    if (auto friendWidget = dynamic_cast<FormFriendItemGraph*>(ui->listWidgetFriendsGraph->itemWidget(ui->listWidgetFriendsGraph->item(j)))) {
                        if (friendWidget->steamProfile()->personaName() == sery->name()) {
                            dynamic_cast<FormFriendItemGraph*>(ui->listWidgetFriendsGraph->itemWidget(ui->listWidgetFriendsGraph->item(j)))->setColor(_colors[i]);
                            break;
                        }
                    }
                }
            }
        }
        updateChartHeight(updateChartWidth(ui->ChartsViewYears->chart()));
    }
}

void FormStatistics::updateStatisticProfile(const SProfile &aProfile) {
    ui->comboBoxCurrentProfile->addItem(_statisticProfile);

    _statisticProfile = aProfile;
    auto games = SGame::load(_statisticProfile.steamID(), true, true);
    _statistics.changeProfile(_statisticProfile, games);
    createThread();
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

void FormStatistics::setModelToTable(QList<GameWithPercent> aGames, bool aIsVisiblePercent) {
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;
    for (const auto &game: aGames) {
        QStandardItem *itemId = new QStandardItem(game.game.appId());

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(game.game.pixmapIcon()), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemName = new QStandardItem(game.game.name());

        QStandardItem *itemPercent = new QStandardItem(QString("%1%").arg(game.percent, 0, 'f', 2));

        model->setItem(row, StaticticGamesAppId,   itemId);
        model->setItem(row, StaticticGamesIndex,   itemIndex);
        model->setItem(row, StaticticGamesIcon,    itemIcon);
        model->setItem(row, StaticticGamesTitle,   itemName);
        model->setItem(row, StaticticGamesPercent, itemPercent);

        ++row;
    }
    model->setHorizontalHeaderItem(StaticticGamesAppId, new QStandardItem(tr("ID")));
    model->setHorizontalHeaderItem(StaticticGamesIndex, new QStandardItem(tr("Index")));
    model->setHorizontalHeaderItem(StaticticGamesIcon, new QStandardItem(tr("")));
    model->setHorizontalHeaderItem(StaticticGamesTitle, new QStandardItem(tr("Название")));
    model->setHorizontalHeaderItem(StaticticGamesPercent, new QStandardItem(tr("Выполнено")));
    if (_currentGamesType == GamesType::none) {
        ui->TableViewGames->setVisible(false);
        return;
    }
    if (ui->TableViewGames->model() != nullptr) {
        delete ui->TableViewGames->model();
    }
    ui->TableViewGames->setModel(model);
    ui->TableViewGames->setSortingEnabled(true);
    ui->TableViewGames->setColumnHidden(StaticticGamesAppId, true);
    ui->TableViewGames->setColumnHidden(StaticticGamesIndex, true);
    ui->TableViewGames->setColumnHidden(StaticticGamesPercent, !aIsVisiblePercent);
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

FormStatistics::~FormStatistics() {
    qInfo() << "Форма статистики удалилась";
    delete ui;
}
