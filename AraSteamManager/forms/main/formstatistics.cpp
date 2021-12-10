#include "formstatistics.h"
#include "ui_formstatistics.h"
#include <math.h>

constexpr int c_steamReleaseYear = 2002;
constexpr int c_secsInDay = 60 * 60 * 24;

QChart *initChart(QChart *&chart, QChartView *chartView, const QString &chartTitle, const QStringList &aList) {
    chart = new QChart();
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::NoAnimation);
    chart->setTitle(chartTitle);
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
    int min = 3000;
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
    if (min == 3000) {
        min = 0;
    }
    for (auto axis: chart->axes(Qt::Horizontal)) {
        axis->setRange(min, max);
    }
    return chart;
}

QPieSlice *getPieChart(QColor aColor) {
    QPieSlice *slice = new QPieSlice();
    slice->setBrush(aColor);
    slice->setBorderColor(Theme::getCurrentTheme().border.color);
    slice->setLabelVisible(true);
    slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
    QObject::connect(slice, &QPieSlice::hovered, slice, &QPieSlice::setExploded);
    return slice;
}

FormStatistics::FormStatistics(const SProfile &aProfile, const SGames &aGames, QWidget *aParent):
Form(aParent), ui(new Ui::FormStatistics), _userProfile(aProfile), _games(aGames), _statisticProfile(_userProfile), _statistics(aProfile, aGames) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->TableViewGames->setVisible(false);
    _gamePercent = new QChart();
    _gamePercent->setBackgroundVisible(false);
    _gamePercent->setAnimationOptions(QChart::SeriesAnimations);
//    _gamePercent->legend()->setAlignment(Qt::AlignRight);
    _gamePercent->legend()->setAlignment(Qt::AlignBottom);
    _gamePercent->setMargins(QMargins(1, 1, 1, 1));

    ui->comboBoxGraph->addItems(QStringList {tr("Последний месяц"), tr("По годам")});
    ui->stackedWidgetGraphs->setCurrentIndex(0);

    initChart(_chartT, ui->ChartsViewTimes, tr("Последний месяц"), getDaysMonthTitles(QDate::currentDate()));
    initChart(_chartY, ui->ChartsViewYears, tr("Достижения по годам"), getYearsTitles());

    initingTable(ui->tableViewLastAchievements);
    ui->tableViewLastAchievements->horizontalHeader()->setVisible(false);
    ui->tableViewLastAchievements->verticalHeader()->setVisible(false);

    ui->horizontalLayoutDonut->setStretch(0, 1);
    ui->horizontalLayoutDonut->setStretch(1, 2);

    initingTable(ui->TableViewGames)->verticalHeader()->setVisible(true);
//    ui->TableViewGames->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
//    ui->TableViewGames->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

//    ui->TableViewGames->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->TableViewGames->setShowGrid(false);
//    ui->TableViewGames->setSortingEnabled(true);
//    ui->TableViewGames->horizontalHeader()->setStretchLastSection(true);
//    ui->TableViewGames->setContextMenuPolicy(Qt::CustomContextMenu);
//    ui->TableViewGames->setEditTriggers(QAbstractItemView::NoEditTriggers);


    QPieSeries *series = new QPieSeries();
    QPieSlice *complete =       getPieChart(QColor(85, 181, 62));
    QPieSlice *started =        getPieChart(QColor(205, 203, 31));
    QPieSlice *notStarted =     getPieChart(QColor(178, 50, 50));
    QPieSlice *noAchievements = getPieChart(QColor(20, 20, 20));
    connect(complete,       &QPieSlice::clicked, this, &FormStatistics::showCompleteGames);
    connect(started,        &QPieSlice::clicked, this, &FormStatistics::showStartedGames);
    connect(notStarted,     &QPieSlice::clicked, this, &FormStatistics::showNotStartedGames);
    connect(noAchievements, &QPieSlice::clicked, this, &FormStatistics::showNoAchievementsGames);
    series->append(complete);
    series->append(started);
    series->append(notStarted);
    series->append(noAchievements);

    _gamePercent->removeAllSeries();
    _gamePercent->addSeries(series);
    _gamePercent->legend()->setLabelColor(Theme::getCurrentTheme().text.getColor());

    _gamePercent->legend()->markers(series).at(0)->setLabel(tr("Закончено"));
    _gamePercent->legend()->markers(series).at(1)->setLabel(tr("Начато"));
    _gamePercent->legend()->markers(series).at(2)->setLabel(tr("Не начато"));
    _gamePercent->legend()->markers(series).at(3)->setLabel(tr("Нет достижений"));

    ui->ChartViewPercentages->setChart(_gamePercent);

    QStringList list;
    for(const SFriend &sFriend: SFriend::load(aProfile.steamID())) {
        list.append(sFriend.steamId());
    }
    ui->comboBoxCurrentProfile->clear();
    auto profiles = SProfile::load(list);
    for(const auto &profileFriend: profiles) {
        ui->comboBoxCurrentProfile->addItem(profileFriend);
    }

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

    connect(ui->comboBoxGraph, &QComboBox::currentIndexChanged, this, [&](int aIndex) {
        switch (aIndex) {
        case 0: {
            ui->stackedWidgetGraphs->setCurrentIndex(0);
            break;
        }
        case 1: {
            ui->stackedWidgetGraphs->setCurrentIndex(2);
            break;
        }
        }
    });

    connect(ui->comboBoxCurrentProfile, &ComboBoxFriends::s_friendClicked, this, &FormStatistics::updateStatisticProfile);
    connect(ui->comboBoxGraphsFriends, &ComboBoxFriends::s_friendClicked, this, [&](const SProfile &lProfile) {
        //TODO Добавить его в правый виджет
        Statistics *statistic = new Statistics(lProfile, SGame::load(lProfile.steamID(), true, true));
        createThreadFriend(*statistic);
    });

    createThread();
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
    _chartT->setTitle(tr("Последний месяц"));
    _chartY->setTitle(tr("Достижения по годам"));
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

QChart *setDataToChart(QChart *chart, QBarCategoryAxis *axisX, int maxY, QBarSet *barSet) {
    QValueAxis *axisY = new QValueAxis();
    axisY->setMax(maxY);
    axisY->setLabelFormat("%i");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    switch(Settings::theme()) {
    case 1: {
        //chart->setTheme(QChart::ChartThemeDark);
        axisX->setLabelsBrush(QBrush(Qt::white));
        axisY->setLabelsBrush(QBrush(Qt::white));
        chart->setTitleBrush(QBrush(Qt::white));
        chart->legend()->setLabelColor(Qt::white);
        barSet->setLabelColor(Qt::white);
        break;
    }
    case 2: {
        axisX->setLabelsColor(Qt::black);
        axisY->setLabelsColor(Qt::black);
        chart->setTitleBrush(QBrush(Qt::black));
        chart->legend()->setLabelColor(Qt::black);
        barSet->setLabelColor(Qt::black);
        break;
    }
    default: {
//        if (Settings::iconsColor() == "white") {
//            barSet->setLabelColor(Qt::white);
//        } else {
//            barSet->setLabelColor(Qt::black);
//        }
    }
    }


    QBarSeries *barSeriesT = new QBarSeries;
    barSeriesT->append(barSet);
    chart->addSeries(barSeriesT);
    barSeriesT->attachAxis(axisX);
    barSeriesT->attachAxis(axisY);
    barSeriesT->setLabelsVisible(true);
    barSeriesT->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    barSeriesT->setLabelsAngle(4);
    return chart;
}

QChart *setDataToLineChart(QChart *chart, QVector<QPointF> &datas, const QString &name, const QColor &color) {
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

    return updateChartHeight(updateChartWidth(chart));
}

QColor nextColor(const QColor &aColor) {
    QColor newColor;
    newColor.setHsl((aColor.hue() + 45) % 255, aColor.saturation(), aColor.lightness());
//    newColor.setRgb((aColor.red() + 140) % 255, (aColor.green() + 140) % 255, (aColor.blue() + 140) % 255);
    return newColor;
}

void FormStatistics::setInfo(Statistics &aStatistic) {
    constexpr long long lastAchievements = 50;
    ui->labelAverageAllGamesValue->setText(QString::number(aStatistic.summAverages / (aStatistic.complete.count() + aStatistic.started.count() + aStatistic.notStarted.count())) + "%");
    ui->labelAverageStartedGamesValue->setText(QString::number(aStatistic.summAverages / (aStatistic.complete.count() + aStatistic.started.count())) + "%");
    ui->LabelSumAchievementsValue->setText(QString::number(aStatistic.achievementCount));
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
    for(auto series: _chartT->series()) {
        delete series;
    }
    for(auto series: _chartY->series()) {
        delete series;
    }
}

void FormStatistics::setGraphs(Statistics &aStatistic) {
    QColor color(200,100,200);

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
    setDataToLineChart(_chartT, datasT, aStatistic.profile.personaName(), color);

    x = 0;
    QVector<QPointF> datasY;
    for (const auto &data: aStatistic.years) {
        datasY << QPointF(data.year.toInt() - c_steamReleaseYear, data.count);
        ++x;
    }
    setDataToLineChart(_chartY, datasY, aStatistic.profile.personaName(), color);
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
    QColor color(200, 100, 200);
    if (auto lastSeries = dynamic_cast<QLineSeries*>(_chartT->series().last())) {
        color = nextColor(lastSeries->color());
    }

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
    setDataToLineChart(_chartT, datasT, aStatistic.profile.personaName(), color);

    x = 0;
    QVector<QPointF> datasY;
    for (const auto &data: aStatistic.years) {
        datasY << QPointF(data.year.toInt() - c_steamReleaseYear, data.count);
        ++x;
    }
    setDataToLineChart(_chartY, datasY, aStatistic.profile.personaName(), color);
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

void FormStatistics::showCompleteGames() {
    _currentGamesType = GamesType::complete;
    setModelToTable(_statistics.complete, false);
}

void FormStatistics::showStartedGames() {
    _currentGamesType = GamesType::started;
    setModelToTable(_statistics.started, true);
}

void FormStatistics::showNotStartedGames() {
    _currentGamesType = GamesType::notStarted;
    setModelToTable(_statistics.notStarted, false);
}

void FormStatistics::showNoAchievementsGames() {
    _currentGamesType = GamesType::noAchievements;
    setModelToTable(_statistics.noAchievements, false);
}

void FormStatistics::setModelToTable(QList<GameWithPercent> aGames, bool aIsVisiblePercent) {
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;
    for (auto game: aGames) {
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
