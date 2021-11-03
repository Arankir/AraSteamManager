#include "formstatistics.h"
#include "ui_formstatistics.h"
#include <math.h>

const int c_steamReleaseYear = 2002;
constexpr int c_secsInDay = 60 * 60 * 24;
//TODO добавить график последних 30 дней, добавить последние (50) ачивок плитками, добавить имена в легенде, добавить друзей для сравнения
QChartView *initAndSetChart(QChart *&chart, const QString &chartTitle, QChartView *chartView) {
    chart = new QChart();
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::SeriesAnimations);
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
//#define tr QObject::tr
    return list;//QStringList {tr("Январь"), tr("Февраль"), tr("Март"), tr("Апрель"), tr("Май"), tr("Июнь"), tr("Июль"), tr("Август"), tr("Сентябрь"), tr("Октябрь"), tr("Ноябрь"), tr("Декабрь")};
//#undef tr
}

int roundToDesimal(int data) {
//    int decim = 1;
    data *= 1.1;
//    int copyData = data;
//    while (copyData > 10) {
//        decim *= 10;
//        copyData /= 10;
//    }
//    data += (decim - (data % decim));
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
Form(aParent), ui(new Ui::FormStatistics), _statistics(aProfile, aGames)/*_profile(aProfile), _games(aGames)*/ {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
//    QFont font(Settings::defaultFont());
    ui->TableViewGames->setVisible(false);
    _gamePercent = new QChart();
    _gamePercent->setBackgroundVisible(false);
    _gamePercent->setAnimationOptions(QChart::SeriesAnimations);
    _gamePercent->legend()->setAlignment(Qt::AlignRight);
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

    initAndSetChart(_chartT, tr("Последние 30 дней"),     ui->ChartsViewTimes);
//    initAndSetChart(_chartT, tr("Достижения по часам"),     ui->ChartsViewTimes);
//    initAndSetChart(_chartM, tr("Достижения по месяцам"),   ui->ChartsViewMonths);
    initAndSetChart(_chartY, tr("Достижения по годам"),     ui->ChartsViewYears);

    ui->TableViewGames->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
    ui->TableViewGames->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

    ui->TableViewGames->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TableViewGames->setShowGrid(false);
    ui->TableViewGames->setSortingEnabled(true);
    ui->TableViewGames->horizontalHeader()->setStretchLastSection(true);
//    ui->TableViewGames->verticalHeader()->setVisible(false);
    ui->TableViewGames->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->TableViewGames->setEditTriggers(QAbstractItemView::NoEditTriggers);

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

    switch(_currentGamesType) {
    case GamesType::complete: {
        auto iterator = std::find_if(_statistics.complete.begin(),
                                     _statistics.complete.end(),
                                     [=](const GameWithPercent &game) {
                                         return game.game.appId() == appId;
                                     });
        if (iterator != _statistics.complete.end()) {
            return &(*iterator).game;
        }
        return nullptr;
    }
    case GamesType::started: {
        auto iterator = std::find_if(_statistics.started.begin(),
                                     _statistics.started.end(),
                                     [=](const /*QPair<SGame, double>*/GameWithPercent &game) {
                                         return game.game.appId() == appId;
                                     });
        if (iterator != _statistics.started.end()) {
            return &(*iterator).game;
        }
        return nullptr;
    }
    case GamesType::notStarted: {
        auto iterator = std::find_if(_statistics.notStarted.begin(),
                                     _statistics.notStarted.end(),
                                     [=](const GameWithPercent &game) {
                                         return game.game.appId() == appId;
                                     });
        if (iterator != _statistics.notStarted.end()) {
            return &(*iterator).game;
        }
        return nullptr;
    }
    case GamesType::noAchievements: {
        auto iterator = std::find_if(_statistics.noAchievements.begin(),
                                     _statistics.noAchievements.end(),
                                     [=](const GameWithPercent &game) {
                                         return game.game.appId() == appId;
                                     });
        if (iterator != _statistics.noAchievements.end()) {
            return &(*iterator).game;
        }
        return nullptr;
    }
    default: {
        return nullptr;
    }
    }
}

QMenu *FormStatistics::createMenu(SGame &aGame) {
//    GameID appId = aGame.appId();

    //Добавление перехода на достижения
    QAction *actionAchievements = new QAction(tr("Достижения"), this);
    actionAchievements->setIcon(QIcon(Images::achievement()));

    QMenu *menu = new QMenu(this);
    menu->addAction (actionAchievements);
    connect (actionAchievements,    &QAction::triggered,    this,   [=](){
//        QList<SAchievementPlayer> player = SAchievementPlayer::load(appId, _profile.steamID());
//        if (player.count() == 0) {
//            QMessageBox::warning(this, tr("Ошибка"), tr("В этой игре нет достижений"));
//        } else {
            emit s_showAchievements(aGame);
//        }
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
//    _chartT->setTitle(tr("Достижения по часам"));
    _chartT->setTitle(tr("Последние 30 дней"));
//    _chartM->setTitle(tr("Достижения по месяцам"));
    _chartY->setTitle(tr("Достижения по годам"));
//    if((_chartM->series().size() > 0) && (_chartM->axes(Qt::Horizontal, _chartM->series().at(0)).size() > 0)) {
//        if (QBarCategoryAxis *bar = dynamic_cast<QBarCategoryAxis*>(_chartM->axes(Qt::Horizontal, _chartM->series().at(0)).at(0))) {
//            bar->setCategories(getMonthTitles());
//        }
//    }
}

void FormStatistics::createThread() {
//    ThreadStatistics *statistics = new ThreadStatistics(_games, _profile.steamID(), _achievementCount, _noAchievements, _complete, _started, _notStarted, _times, _months, _years);
    ThreadStatistics *statistics = new ThreadStatistics(_statistics);
    connect(statistics, &ThreadStatistics::s_progress,  this, &Form::setStatus);
    connect(statistics, &ThreadStatistics::s_finished,  this, &FormStatistics::onFinish);
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
    qDebug() << min << max << chart->title() << categories.at(min) << categories.at(max);
    for (auto axis: chart->axes(Qt::Horizontal)) {
//        axis->setRange(min, max);
        axis->setMin(categories.at(min));
        axis->setMax(categories.at(max));
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
    lineSeries->setPointLabelsFont(QFont(Settings::defaultFont(), 14));
    lineSeries->setPointLabelsFormat("@yPoint");

    lineSeries->setColor(color);
    QColor label(color);
    label.setHsl(color.hue(), (int)(color.saturation() * 0.8), (int)(color.lightness() * 0.8));
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

void FormStatistics::setInfo(Statistics aStatistic) {
    ui->labelAverageAllGamesValue->setText(QString::number(aStatistic.summAverages / (aStatistic.complete.count() + aStatistic.started.count() + aStatistic.notStarted.count())) + "%");
    ui->labelAverageStartedGamesValue->setText(QString::number(aStatistic.summAverages / (aStatistic.complete.count() + aStatistic.started.count())) + "%");
    ui->LabelSumAchievementsValue->setText(QString::number(aStatistic.achievementCount));
    ui->labelCompletedGamesValue->setText(QString::number(aStatistic.complete.count()));
    ui->labelStartedGamesValue->setText(QString::number(aStatistic.started.count()));
    ui->labelNotStartedGamesValue->setText(QString::number(aStatistic.notStarted.count()));
    ui->labelNoAchievementsGamesValue->setText(QString::number(aStatistic.noAchievements.count()));

    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(5);
    model->setRowCount(10);
    for (int i = aStatistic.completedAchievements.count() - 1; aStatistic.completedAchievements.count() - i  < 50 && i >= 0; --i) {
        QStandardItem * item = new QStandardItem();
        item->setData(aStatistic.completedAchievements[i].achievement.apiName());
        model->setItem(i / 5, i % 5, item);
        qDebug() << (i/5) << (i%5) << i << aStatistic.completedAchievements.count();
    }
    ui->tableViewLastAchievements->setModel(model);
}

void FormStatistics::onFinish() {
    ui->labelProfile->setPixmap(_statistics.profile.pixmapAvatar());
    ui->labelProfile->setToolTip(_statistics.profile.personaName());

    _statistics.summAverages = 100.0 * _statistics.complete.count();
    for (const auto &average: qAsConst(_statistics.started)) {
        _statistics.summAverages += average.percent;
    }

    mySort<GameWithPercent>(_statistics.complete, [](GameWithPercent &game1, GameWithPercent &game2) {return game1.game < game2.game;});
    mySort<GameWithPercent>(_statistics.started, [](GameWithPercent &game1, GameWithPercent &game2) {return game1.game < game2.game;});
    mySort<GameWithPercent>(_statistics.notStarted, [](GameWithPercent &game1, GameWithPercent &game2) {return game1.game < game2.game;});
    mySort<GameWithPercent>(_statistics.noAchievements, [](GameWithPercent &game1, GameWithPercent &game2) {return game1.game < game2.game;});
    mySort<CompletedAchievement>(_statistics.completedAchievements, [](CompletedAchievement &game1, CompletedAchievement &game2)
        {return game1.achievement.unlockTime() < game2.achievement.unlockTime();});

    setInfo(_statistics);

    #define SetChartDonut {
    QPieSeries *series = new QPieSeries();

    QPieSlice *complete =       getPieChart(tr("Закончено (%1)")     .arg(_statistics.complete.count())         , _statistics.complete.count()      , _statistics.games.count(), QColor(85, 181, 62));
    QPieSlice *started =        getPieChart(tr("Начато (%1)")        .arg(_statistics.started.count())          , _statistics.started.count()       , _statistics.games.count(), QColor(205, 203, 31));
    QPieSlice *notStarted =     getPieChart(tr("Не начато (%1)")     .arg(_statistics.notStarted.count())       , _statistics.notStarted.count()    , _statistics.games.count(), QColor(178, 50, 50));
    QPieSlice *noAchievements = getPieChart(tr("Нет достижений (%1)").arg(_statistics.noAchievements.count())   , _statistics.noAchievements.count(), _statistics.games.count(), QColor(41, 41, 41));
    connect(complete,       &QPieSlice::clicked, this, &FormStatistics::showCompleteGames);
    connect(started,        &QPieSlice::clicked, this, &FormStatistics::showStartedGames);
    connect(notStarted,     &QPieSlice::clicked, this, &FormStatistics::showNotStartedGames);
    connect(noAchievements, &QPieSlice::clicked, this, &FormStatistics::showNoAchievementsGames);
    series->append(complete);
    series->append(started);
    series->append(notStarted);
    series->append(noAchievements);

    _gamePercent->addSeries(series);
    _gamePercent->legend()->setLabelColor(Qt::white);

    ui->ChartViewPercentages->setChart(_gamePercent);
    QColor color(0,100,200);
    #define SetChartDonutEnd }
        #define SetChartTimes {
        QBarCategoryAxis *axisXT = new QBarCategoryAxis();
        QDate date = QDate::currentDate().addDays(-QDate::currentDate().day() + 1);
        QStringList categories;
        while (date.month() == QDate::currentDate().month()) {
            categories << date.toString("dd");
            date = date.addDays(1);
        }
        axisXT->append(categories);
//        axisXT->append(getHoursTitles());
        initChart(_chartT, axisXT);
        int x = 0;

        x = 0;
        QVector<QPointF> datasT(30);
        for (auto &point: datasT) {
            point.setX(x++);
        }

        for (auto achievement: _statistics.completedAchievements) {
            int secsFromThirtyDaysAgo = achievement.achievement.unlockTime().toSecsSinceEpoch() - QDateTime(QDate::currentDate(), QTime()).addDays(-QDate::currentDate().day() + 1).toSecsSinceEpoch();
            if (secsFromThirtyDaysAgo > 0) {
                datasT[secsFromThirtyDaysAgo / c_secsInDay].setY(datasT[secsFromThirtyDaysAgo / c_secsInDay].y() + 1);
            }
        }

//        for (auto data: _statistics.times) {
//            datasT << QPointF(x, data);
//            ++x;
//        }
        setDataToLineChart(_chartT, datasT, _statistics.profile.personaName(), color);
        #define SetChartTimesEnd }
    #define SetChartYears {
    std::sort(_statistics.years.begin(),
              _statistics.years.end(),
              [](const YearCount &p1, const YearCount &p2) {
                    return p1.year < p2.year;
                });
    QBarCategoryAxis *axisXY = new QBarCategoryAxis();
    axisXY->append(getYearsTitles());
    initChart(_chartY, axisXY);
    x = 0;
    QVector<QPointF> datasY;
    for (auto data: _statistics.years) {
        datasY << QPointF(data.year.toInt() - c_steamReleaseYear, data.count);
        ++x;
    }
    qDebug() << datasY;
    setDataToLineChart(_chartY, datasY, _statistics.profile.personaName(), color);
    for (auto &year: datasY) {
        static int a = -10000;
        year.setY(100000 + a);
        if (a > 0) {
            a += 5000;
        } else {
            a -= 5000;
        }
        a *= -1;
    }
    setDataToLineChart(_chartY, datasY, "кто-то1", nextColor(dynamic_cast<QLineSeries *>(_chartY->series().last())->color()));
    for (auto &year: datasY) {
        static int a = -5000;
        year.setY(50000 + a);
        if (a > 0) {
            a += 2000;
        } else {
            a -= 2000;
        }
        a *= -1;
    }
    setDataToLineChart(_chartY, datasY, "кто-то2", nextColor(dynamic_cast<QLineSeries *>(_chartY->series().last())->color()));
    for (auto &year: datasY) {
        static int a = -7000;
        year.setY(70000 + a);
        if (a > 0) {
            a += 3000;
        } else {
            a -= 3000;
        }
        a *= -1;
    }
    setDataToLineChart(_chartY, datasY, "кто-то3", nextColor(dynamic_cast<QLineSeries *>(_chartY->series().last())->color()));
    for (auto &year: datasY) {
        static int a = -10000;
        year.setY(200000 + a);
        a -= 5000;
    }
    setDataToLineChart(_chartY, datasY, "кто-то4", nextColor(dynamic_cast<QLineSeries *>(_chartY->series().last())->color()));
    for (auto &year: datasY) {
        static int a = 0;
        year.setY(100000 + a);
        a += 5000;
    }
    setDataToLineChart(_chartY, datasY, "кто-то5", nextColor(dynamic_cast<QLineSeries *>(_chartY->series().last())->color()));
    #define SetChartYearsEnd }
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
