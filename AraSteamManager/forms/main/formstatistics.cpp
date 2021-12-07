#include "formstatistics.h"
#include "ui_formstatistics.h"
#include <math.h>

constexpr int c_steamReleaseYear = 2002;
constexpr int c_secsInDay = 60 * 60 * 24;
//TODO добавить имена в легенде, добавить друзей для сравнения
QChartView *initAndSetChart(QChart *&chart, const QString &chartTitle, QChartView *chartView) {
    chart = new QChart();
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::NoAnimation);
    chart->setTitle(chartTitle);
    chart->setBackgroundVisible(false);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(480, 480);
    return chartView;
}

QChart *initChart(QChart *chart, QBarCategoryAxis *axisX) {
    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%i");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    switch(Settings::theme()) {
    case 1: {
        //chart->setTheme(QChart::ChartThemeDark);
        axisX->setLabelsColor(Qt::white);
        axisY->setLabelsColor(Qt::white);
        chart->setTitleBrush(QBrush(Qt::white));
        chart->legend()->setLabelColor(Qt::white);
//        barSet->setLabelColor(Qt::white);
        chart->axes(Qt::Vertical).at(0)->setGridLineColor(QColor(255, 255, 255, 100));
        chart->axes(Qt::Horizontal).at(0)->setGridLineColor(QColor(255, 255, 255, 100));
        break;
    }
    case 2: {
        axisX->setLabelsColor(Qt::black);
        axisY->setLabelsColor(Qt::black);
        chart->setTitleBrush(QBrush(Qt::black));
        chart->legend()->setLabelColor(Qt::black);
//        barSet->setLabelColor(Qt::black);
        chart->axes(Qt::Vertical).at(0)->setGridLineColor(QColor(255, 255, 255, 100));
        chart->axes(Qt::Horizontal).at(0)->setGridLineColor(QColor(255, 255, 255, 100));
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
    return chart;
}

QStringList getHoursTitles() {
    QStringList list;
    for (int i = 0; i < 24; ++i) {
        list << QString::number(i);
    }
    return list;
}

//QStringList getMonthTitles() {
//    QStringList list;
//    QLocale locale;
//    switch(Settings::language()) {
//    case 1: {
//        locale = QLocale(QLocale::English);
//        break;
//    }
//    case 5: {
//        locale = QLocale(QLocale::Russian);
//        break;
//    }
//    }
//    for (int i = 1; i < 13; ++i) {
//        list << locale.toString(QDate(1900, i, 1), "MMM");
//    }
////#define tr QObject::tr
//    return list;//QStringList {tr("Январь"), tr("Февраль"), tr("Март"), tr("Апрель"), tr("Май"), tr("Июнь"), tr("Июль"), tr("Август"), tr("Сентябрь"), tr("Октябрь"), tr("Ноябрь"), tr("Декабрь")};
////#undef tr
//}

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
    data *= 1.1;
    QVector<double> logs {log10(0), log10(1), log10(2), log10(3), log10(4), log10(5), log10(6), log10(7), log10(8), log10(9)};
    double dDecimal = log10(data);
    int iDecimal = dDecimal;
    data = pow(10, iDecimal + 1);
    for (int i = 1; i < 10; ++i) {
        if ((dDecimal - iDecimal) < logs[i]) {
            data = pow(10, logs[i] + iDecimal);
            break;
        }
    }
    return data;
}

int roundToDesimal2(int data) {
    const double five = log10(5);
    double dDecimal = log10(data);
    int iDecimal = dDecimal;
    data = (dDecimal - iDecimal) > five ? pow(10, iDecimal + 1) : pow(10, five + iDecimal) + 1;
    return data;
}

QPieSlice *getPieChart(QString aTitle, int aValue, int aAllValue, QColor aColor) {
    QPieSlice *slice = new QPieSlice(aTitle + QString(" - %1%").arg(100.0 * aValue / aAllValue, 0, 'f', 2), aValue);
    slice->setBrush(aColor);
    slice->setLabelVisible(false);
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
    switch(Settings::theme()) {
    case 1: {
        //_gamePercent->setTheme(QChart::ChartThemeDark);
        break;
    }
    case 2: {
        break;
    }
    }

    ui->comboBoxGraph->addItems(QStringList {tr("Последний месяц"), tr("По годам")});

    initAndSetChart(_chartT, tr("Последний месяц"),     ui->ChartsViewTimes);
    QBarCategoryAxis *axisXT = new QBarCategoryAxis();
    QDate date = QDate::currentDate().addDays(-QDate::currentDate().day() + 1);
    QStringList monthsTitles;
    while (date.month() == QDate::currentDate().month()) {
        monthsTitles << date.toString("dd");
        date = date.addDays(1);
    }
    axisXT->append(monthsTitles);
    initChart(_chartT, axisXT);
    initAndSetChart(_chartY, tr("Достижения по годам"),     ui->ChartsViewYears);
    QBarCategoryAxis *axisXY = new QBarCategoryAxis();
    axisXY->append(getYearsTitles());
    initChart(_chartY, axisXY);

    initingTable(ui->tableViewLastAchievements);
    ui->tableViewLastAchievements->horizontalHeader()->setVisible(false);
    ui->tableViewLastAchievements->verticalHeader()->setVisible(false);

    ui->horizontalLayoutDonut->setStretch(0, 1);
    ui->horizontalLayoutDonut->setStretch(1, 2);

    ui->TableViewGames->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
    ui->TableViewGames->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

    ui->TableViewGames->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TableViewGames->setShowGrid(false);
    ui->TableViewGames->setSortingEnabled(true);
    ui->TableViewGames->horizontalHeader()->setStretchLastSection(true);
//    ui->TableViewGames->verticalHeader()->setVisible(false);
    ui->TableViewGames->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->TableViewGames->setEditTriggers(QAbstractItemView::NoEditTriggers);


    QStringList list;
    for(const SFriend &sFriend: SFriend::load(aProfile.steamID())) {
        list.append(sFriend.steamId());
    }
    ui->comboBoxCurrentProfile->clear();
    auto profiles = SProfile::load(list);
    for(const auto &profileFriend: profiles) {
        ui->comboBoxCurrentProfile->addItem(profileFriend);
    }

    connect(ui->TableViewGames, &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
        SGame *game = currentGame();
        if (game != nullptr) {
            createMenu(*game)->popup(ui->TableViewGames->viewport()->mapToGlobal(pos));
        }
    });

    connect(ui->TableViewGames, &QTableView::doubleClicked, this, [=](QModelIndex aIndex) {
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
    connect (actionAchievements, &QAction::triggered, this, [=]() {
        emit s_showAchievements(aGame);
    });

    return menu;
}

void FormStatistics::retranslate() {
    ui->retranslateUi(this);
    QList<QAbstractSeries*> series = _gamePercent->series();
    if (series.count() > 0) {
        QPieSeries *pie = dynamic_cast<QPieSeries*>(series[0]);
        if (pie != nullptr) {
            QList<QPieSlice*> slices = pie->slices();
            switch (slices.count()) {
            default: {

            }
            case 4: {
                slices[3]->setLabel(tr("Нет достижений (%1) - %2%").arg(QString::number(_statistics.noAchievements.count())).arg(100.0 * _statistics.noAchievements.count() / _statistics.games.count(), 0, 'f', 2));
                [[fallthrough]];
            }
            case 3: {
                slices[2]->setLabel(tr("Не начато (%1) - %2%").arg(QString::number(_statistics.notStarted.count())).arg(100.0 * _statistics.notStarted.count() / _statistics.games.count(), 0, 'f', 2));
                [[fallthrough]];
            }
            case 2: {
                slices[1]->setLabel(tr("Начато (%1) - %2%").arg(QString::number(_statistics.started.count())).arg(100.0 * _statistics.started.count() / _statistics.games.count(), 0, 'f', 2));
                [[fallthrough]];
            }
            case 1: {
                slices[0]->setLabel(tr("Закончено (%1) - %2%").arg(QString::number(_statistics.complete.count())).arg(100.0 * _statistics.complete.count() / _statistics.games.count(), 0, 'f', 2));
                break;
            }
            case 0: {
                qWarning() << "on retranslate slices.count = 0";
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
//    if((_chartM->series().size() > 0) && (_chartM->axes(Qt::Horizontal, _chartM->series().at(0)).size() > 0)) {
//        if (QBarCategoryAxis *bar = dynamic_cast<QBarCategoryAxis*>(_chartM->axes(Qt::Horizontal, _chartM->series().at(0)).at(0))) {
//            bar->setCategories(getMonthTitles());
//        }
//    }
}

void FormStatistics::createThread() {
    ThreadStatistics *statistics = new ThreadStatistics(_statistics);
    connect(statistics, &ThreadStatistics::s_progress,  this, &Form::setStatus);
    connect(statistics, &ThreadStatistics::s_finish,  this, &FormStatistics::onFinish);
    statistics->start();
}

QChart *updateChartHeight(QChart *chart) {
    int max = 0;
    for (auto sery: chart->series()) {
        if (auto realSery = dynamic_cast<QLineSeries*>(sery)) {
            for (auto point: realSery->points()) {
                if (point.y() > max) {
                    max = point.y();
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
    int max = 0;
    int min = 2147483647;
    for (auto sery: chart->series()) {
        if (auto realSery = dynamic_cast<QLineSeries*>(sery)) {
            for (auto point: realSery->points()) {
                if (point.x() > max) {
                    max = point.x();
                }
                if (point.x() < min) {
                    min = point.x();
                }
            }
        }
    }
    if (max != 0 && min != 2147483647) {
        //qDebug() << min << max << chart->title() << categories.at(min) << categories.at(max);
        for (auto axis: chart->axes(Qt::Horizontal)) {
    //        axis->setRange(min, max);
            axis->setMin(categories.at(min));
            axis->setMax(categories.at(max));
        }
    }
    return chart;
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
    constexpr int lastAchievements = 50;
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

    if (aStatistic.completedAchievements.size() > 50) {
        QStandardItemModel *model = new QStandardItemModel();
        auto tempLast50 = aStatistic.completedAchievements.last(lastAchievements);
        QList<CompletedAchievement> last50(reverseList<CompletedAchievement>(tempLast50));
        QMap<GameID, QList<SAchievementSchema>> mapGames;

        int i = 0;
        for (const auto &achievements: last50) {
            QStandardItem * item = new QStandardItem();
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
}

void FormStatistics::setPie(Statistics &aStatistic) {
    QPieSeries *series = new QPieSeries();

    QPieSlice *complete =       getPieChart(tr("Закончено (%1)")     .arg(aStatistic.complete.count())         , aStatistic.complete.count()      , aStatistic.games.count(), QColor(85, 181, 62));
    QPieSlice *started =        getPieChart(tr("Начато (%1)")        .arg(aStatistic.started.count())          , aStatistic.started.count()       , aStatistic.games.count(), QColor(205, 203, 31));
    QPieSlice *notStarted =     getPieChart(tr("Не начато (%1)")     .arg(aStatistic.notStarted.count())       , aStatistic.notStarted.count()    , aStatistic.games.count(), QColor(178, 50, 50));
    QPieSlice *noAchievements = getPieChart(tr("Нет достижений (%1)").arg(aStatistic.noAchievements.count())   , aStatistic.noAchievements.count(), aStatistic.games.count(), QColor(41, 41, 41));
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

    ui->ChartViewPercentages->setChart(_gamePercent);
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
    const int startMonthSecs = QDateTime(QDate::currentDate(), QTime()).addDays(-QDate::currentDate().day() + 1).toSecsSinceEpoch();
    for (auto achievement: aStatistic.completedAchievements) {
        int secsFromStartMonth = achievement.achievement.unlockTime().toSecsSinceEpoch() - startMonthSecs;
        if (secsFromStartMonth > 0) {
            int index = secsFromStartMonth / c_secsInDay;
            datasT[index].setY(datasT[index].y() + 1);
        }
    }
    setDataToLineChart(_chartT, datasT, aStatistic.profile.personaName(), color);

    x = 0;
    QVector<QPointF> datasY;
    for (auto data: aStatistic.years) {
        datasY << QPointF(data.year.toInt() - c_steamReleaseYear, data.count);
        ++x;
    }
    setDataToLineChart(_chartY, datasY, aStatistic.profile.personaName(), color);
//    for (auto &year: datasY) {
//        static int a = -10000;
//        year.setY(100000 + a);
//        if (a > 0) {
//            a += 5000;
//        } else {
//            a -= 5000;
//        }
//        a *= -1;
//    }
//    setDataToLineChart(_chartY, datasY, "кто-то1", nextColor(dynamic_cast<QLineSeries *>(_chartY->series().last())->color()));
//    for (auto &year: datasY) {
//        static int a = -5000;
//        year.setY(50000 + a);
//        if (a > 0) {
//            a += 2000;
//        } else {
//            a -= 2000;
//        }
//        a *= -1;
//    }
//    setDataToLineChart(_chartY, datasY, "кто-то2", nextColor(dynamic_cast<QLineSeries *>(_chartY->series().last())->color()));
//    for (auto &year: datasY) {
//        static int a = -7000;
//        year.setY(70000 + a);
//        if (a > 0) {
//            a += 3000;
//        } else {
//            a -= 3000;
//        }
//        a *= -1;
//    }
//    setDataToLineChart(_chartY, datasY, "кто-то3", nextColor(dynamic_cast<QLineSeries *>(_chartY->series().last())->color()));
//    for (auto &year: datasY) {
//        static int a = -10000;
//        year.setY(200000 + a);
//        a -= 5000;
//    }
//    setDataToLineChart(_chartY, datasY, "кто-то4", nextColor(dynamic_cast<QLineSeries *>(_chartY->series().last())->color()));
//    for (auto &year: datasY) {
//        static int a = 0;
//        year.setY(100000 + a);
//        a += 5000;
//    }
//    setDataToLineChart(_chartY, datasY, "кто-то5", nextColor(dynamic_cast<QLineSeries *>(_chartY->series().last())->color()));

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

void FormStatistics::updateStatisticProfile(const SProfile &aProfile) {
    ui->comboBoxCurrentProfile->addItem(_statisticProfile);

    _statisticProfile = aProfile;
    _statistics.changeProfile(_statisticProfile, SGame::load(_statisticProfile.steamID()));
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
