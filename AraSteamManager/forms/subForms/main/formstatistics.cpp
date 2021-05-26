#include "formstatistics.h"
#include "ui_formstatistics.h"
#include <math.h>

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

QStringList getHoursTitles() {
    return QStringList{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23"};
}

QStringList getMonthTitles() {
#define tr QObject::tr
    return QStringList{tr("Январь"), tr("Февраль"), tr("Март"), tr("Апрель"), tr("Май"), tr("Июнь"), tr("Июль"), tr("Август"), tr("Сентябрь"), tr("Октябрь"), tr("Ноябрь"), tr("Декабрь")};
#undef tr
}

FormStatistics::FormStatistics(const SProfile &aProfile, SGames &aGames, QWidget *aParent):
Form(aParent), ui(new Ui::FormStatistics), _profile(aProfile), _games(aGames) {
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
        _gamePercent->setTheme(QChart::ChartThemeDark);
        break;
    }
    case 2: {
        break;
    }
    }

    initAndSetChart(_chartT, tr("Достижения по часам"),     ui->ChartsViewTimes);
    initAndSetChart(_chartM, tr("Достижения по месяцам"),   ui->ChartsViewMonths);
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
            QList<SAchievementPlayer> player = SAchievementPlayer::load(game->sAppId(), _profile.steamID());
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
        auto iterator = std::find_if(_complete.begin(), _complete.end(), [=](const SGame &game) {
                                                                             return game.appId() == appId;
                                                                         });
        if (iterator != _complete.end()) {
            return &*iterator;
        }
        return nullptr;
    }
    case GamesType::started: {
        auto iterator = std::find_if(_started.begin(), _started.end(), [=](const QPair<SGame, double> &game) {
                                                                             return game.first.appId() == appId;
                                                                         });
        if (iterator != _started.end()) {
            return &(*iterator).first;
        }
        return nullptr;
    }
    case GamesType::notStarted: {
        auto iterator = std::find_if(_notStarted.begin(), _notStarted.end(), [=](const SGame &game) {
                                                                             return game.appId() == appId;
                                                                         });
        if (iterator != _notStarted.end()) {
            return &*iterator;
        }
        return nullptr;
    }
    case GamesType::noAchievements: {
        auto iterator = std::find_if(_noAchievements.begin(), _noAchievements.end(), [=](const SGame &game) {
                                                                             return game.appId() == appId;
                                                                         });
        if (iterator != _noAchievements.end()) {
            return &*iterator;
        }
        return nullptr;
    }
    default: {
        return nullptr;
    }
    }
}

QMenu *FormStatistics::createMenu(SGame &aGame) {
    QString appId = aGame.sAppId();

    //Добавление перехода на достижения
    QAction *actionAchievements = new QAction(tr("Достижения"), this);
    actionAchievements->setIcon(QIcon(Images::achievement()));

    QMenu *menu = new QMenu(this);
    menu->addAction (actionAchievements);
    connect (actionAchievements,    &QAction::triggered,    this,   [=](){
        QList<SAchievementPlayer> player = SAchievementPlayer::load(appId, _profile.steamID());
        if (player.count() == 0) {
            QMessageBox::warning(this, tr("Ошибка"), tr("В этой игре нет достижений"));
        } else {
            emit s_showAchievements(aGame);
        }});

    return menu;
}

void FormStatistics::retranslate() {
    ui->retranslateUi(this);
    ui->LabelAveragePercentValue->setText(QString("%1\n-%2: %3%\n-%4: %5%").arg(
                                        tr("Средний процент"),
                                        tr("по всем играм"),
                                        QString::number(_summAverages / (_complete.count() + _started.count() + _notStarted.count())),
                                        tr("по начатым играм"),
                                        QString::number(_summAverages / (_complete.count() + _started.count()))));
    QList<QAbstractSeries*> series = _gamePercent->series();
    if (series.count() > 0) {
        QPieSeries *pie = dynamic_cast<QPieSeries*>(series[0]);
        if (pie != nullptr) {
            QList<QPieSlice*> slices = pie->slices();
            //Using fall-through
            switch (slices.count()) {
            default: {

            }
            case 4: {
                slices[3]->setLabel(tr("Нет достижений (%1) - %2%").arg(QString::number(_noAchievements.count())).arg(100.0 * _noAchievements.count() / _games.count(), 0, 'f', 2));
                [[fallthrough]];
            }
            case 3: {
                slices[2]->setLabel(tr("Не начато (%1) - %2%").arg(QString::number(_notStarted.count())).arg(100.0 * _notStarted.count() / _games.count(), 0, 'f', 2));
                [[fallthrough]];
            }
            case 2: {
                slices[1]->setLabel(tr("Начато (%1) - %2%").arg(QString::number(_started.count())).arg(100.0 * _started.count() / _games.count(), 0, 'f', 2));
                [[fallthrough]];
            }
            case 1: {
                slices[0]->setLabel(tr("Закончено (%1) - %2%").arg(QString::number(_complete.count())).arg(100.0 * _complete.count() / _games.count(), 0, 'f', 2));
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
    _chartT->setTitle(tr("Достижения по часам"));
    _chartM->setTitle(tr("Достижения по месяцам"));
    _chartY->setTitle(tr("Достижения по годам"));
    if((_chartM->series().size() > 0) && (_chartM->axes(Qt::Horizontal, _chartM->series().at(0)).size() > 0)) {
        QBarCategoryAxis *bar = dynamic_cast<QBarCategoryAxis*>(_chartM->axes(Qt::Horizontal, _chartM->series().at(0)).at(0));
        if (bar) {
            bar->setCategories(getMonthTitles());
        }
    }
}

void FormStatistics::createThread() {
    ThreadStatistics *statistics = new ThreadStatistics(_games, _profile.steamID(), _achievementCount, _noAchievements, _complete, _started, _notStarted, _times, _months, _years);
    connect(statistics, &ThreadStatistics::s_progress,  this, [=](int progress) {
                                                                            emit s_statisticsLoaded(progress);
                                                                        });
    connect(statistics, &ThreadStatistics::s_finished,  this, &FormStatistics::onFinish);
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
        chart->setTheme(QChart::ChartThemeDark);
        break;
    }
    case 2: {
        barSet->setLabelColor(Qt::black);
        break;
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

int &roundToDesimal(int &data) {
    int decim = 1;
    data *= 1.1;
    int copyData = data;
    while (copyData > 10) {
        decim *= 10;
        copyData /= 10;
    }
    data += (decim - (data % decim));
    return data;
}

int &roundToDesimal2(int &data) {
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

void FormStatistics::onFinish() {
    _summAverages = 100.0 * _complete.count();
    for (const auto &average: qAsConst(_started)) {
        _summAverages += average.second;
    }
    ui->LabelAveragePercentValue->setText(QString("%1\n-%2: %3%\n-%4: %5%").arg(tr("Средний процент"),
                                                                                tr("по всем играм"),
                                                                                QString::number(_summAverages / (_complete.count() + _started.count() + _notStarted.count())),
                                                                                tr("по начатым играм"),
                                                                                QString::number(_summAverages / (_complete.count() + _started.count()))));
    ui->LabelSummColumnValue->setText(QString::number(_achievementCount));

    mySort<SGame>(_complete);
    mySort<QPair<SGame,double>>(_started, [](QPair<SGame,double> &game1, QPair<SGame,double> &game2) {return game1.first < game2.first;});
    mySort<SGame>(_notStarted);
    mySort<SGame>(_noAchievements);

    #define SetChartDonut {
    QPieSeries *series = new QPieSeries();

    QPieSlice *complete =       getPieChart(tr("Закончено (%1)")     .arg(_complete.count())         ,_complete.count()      , _games.count(), QColor(85, 181, 62));
    QPieSlice *started =        getPieChart(tr("Начато (%1)")        .arg(_started.count())          ,_started.count()       , _games.count(), QColor(205, 203, 31));
    QPieSlice *notStarted =     getPieChart(tr("Не начато (%1)")     .arg(_notStarted.count())       ,_notStarted.count()    , _games.count(), QColor(178, 50, 50));
    QPieSlice *noAchievements = getPieChart(tr("Нет достижений (%1)").arg(_noAchievements.count())   ,_noAchievements.count(), _games.count(), QColor(41, 41, 41));
    connect(complete,       &QPieSlice::clicked, this, &FormStatistics::showCompleteGames);
    connect(started,        &QPieSlice::clicked, this, &FormStatistics::showStartedGames);
    connect(notStarted,     &QPieSlice::clicked, this, &FormStatistics::showNotStartedGames);
    connect(noAchievements, &QPieSlice::clicked, this, &FormStatistics::showNoAchievementsGames);
    series->append(complete);
    series->append(started);
    series->append(notStarted);
    series->append(noAchievements);

    _gamePercent->addSeries(series);

    ui->ChartViewPercentages->setChart(_gamePercent);
    #define SetChartDonutEnd }
    #define SetChartTimes {
    QBarCategoryAxis *axisXT = new QBarCategoryAxis();
    axisXT->append(getHoursTitles());
    QBarSet *barSetT = new QBarSet(_profile.personaName());
    for(int i = 0; i < 24; ++i) {
        *barSetT << _times[i];
    }
    setDataToChart(_chartT, axisXT, roundToDesimal(*std::max_element(_times.begin(), _times.end())), barSetT);
    #define SetChartTimesEnd }
    #define SetChartMonths {
    QBarCategoryAxis *axisXM = new QBarCategoryAxis();
    axisXM->append(getMonthTitles());
    QBarSet *barSetM = new QBarSet(_profile.personaName());
    for(int i = 0; i < 12; ++i) {
        *barSetM << _months[i];
    }
    setDataToChart(_chartM, axisXM, roundToDesimal(*std::max_element(_months.begin(), _months.end())), barSetM);
    #define SetChartMonthsEnd }
    #define SetChartYears {
    std::sort(_years.begin(), _years.end(), [](const QPair<QString,int> &p1, const QPair<QString,int> &p2) {
                                                return p1.first < p2.first;
                                            });
    int max = 0;
    QBarCategoryAxis *axisXY = new QBarCategoryAxis();
    QBarSet *barSetY = new QBarSet(_profile.personaName());
    for(auto &year: _years) {
        axisXY->append(year.first);
        *barSetY << year.second;
        if(max < year.second) {
            max = year.second;
        }
    }
    setDataToChart(_chartY, axisXY, roundToDesimal(max), barSetY);
    #define SetChartYearsEnd }
    emit s_finish();
}

void FormStatistics::showCompleteGames() {
    _currentGamesType = GamesType::complete;
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;
    for (auto game: qAsConst(_complete)) {
        QStandardItem *itemId = new QStandardItem(game.sAppId());

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(game.pixmapIcon()), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemName = new QStandardItem(game.name());

        model->setItem(row, StaticticGamesAppId,   itemId);
        model->setItem(row, StaticticGamesIndex,   itemIndex);
        model->setItem(row, StaticticGamesIcon,    itemIcon);
        model->setItem(row, StaticticGamesTitle,   itemName);

        ++row;
    }
    model->setHorizontalHeaderItem(StaticticGamesAppId, new QStandardItem(tr("ID")));
    model->setHorizontalHeaderItem(StaticticGamesIndex, new QStandardItem(tr("Index")));
    model->setHorizontalHeaderItem(StaticticGamesIcon, new QStandardItem(tr("")));
    model->setHorizontalHeaderItem(StaticticGamesTitle, new QStandardItem(tr("Название")));
    setModelToTable(model);
}

void FormStatistics::showStartedGames() {
    _currentGamesType = GamesType::started;
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;
    for (auto &game: _started) {
        QStandardItem *itemId = new QStandardItem(game.first.sAppId());

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(game.first.pixmapIcon()), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemName = new QStandardItem(game.first.name());

        QStandardItem *itemPercent = new QStandardItem(QString("%1%").arg(game.second, 0, 'f', 2));

        model->setItem(row, StaticticGamesAppId,   itemId);
        model->setItem(row, StaticticGamesIndex,   itemIndex);
        model->setItem(row, StaticticGamesIcon,    itemIcon);
        model->setItem(row, StaticticGamesTitle,    itemName);
        model->setItem(row, StaticticGamesPercent,    itemPercent);

        ++row;
    }
    model->setHorizontalHeaderItem(StaticticGamesAppId, new QStandardItem(tr("ID")));
    model->setHorizontalHeaderItem(StaticticGamesIndex, new QStandardItem(tr("Index")));
    model->setHorizontalHeaderItem(StaticticGamesIcon, new QStandardItem(tr("")));
    model->setHorizontalHeaderItem(StaticticGamesTitle, new QStandardItem(tr("Название")));
    model->setHorizontalHeaderItem(StaticticGamesPercent, new QStandardItem(tr("Выполнено")));
    setModelToTable(model);
}

void FormStatistics::showNotStartedGames() {
    _currentGamesType = GamesType::notStarted;
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;
    for (auto game: qAsConst(_notStarted)) {
        QStandardItem *itemId = new QStandardItem(game.sAppId());

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(game.pixmapIcon()), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemName = new QStandardItem(game.name());

        model->setItem(row, StaticticGamesAppId,   itemId);
        model->setItem(row, StaticticGamesIndex,   itemIndex);
        model->setItem(row, StaticticGamesIcon,    itemIcon);
        model->setItem(row, StaticticGamesTitle,    itemName);

        ++row;
    }
    model->setHorizontalHeaderItem(StaticticGamesAppId, new QStandardItem(tr("ID")));
    model->setHorizontalHeaderItem(StaticticGamesIndex, new QStandardItem(tr("Index")));
    model->setHorizontalHeaderItem(StaticticGamesIcon, new QStandardItem(tr("")));
    model->setHorizontalHeaderItem(StaticticGamesTitle, new QStandardItem(tr("Название")));
    setModelToTable(model);
}

void FormStatistics::showNoAchievementsGames() {
    _currentGamesType = GamesType::noAchievements;
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;
    for (auto game: qAsConst(_noAchievements)) {
        QStandardItem *itemId = new QStandardItem(game.sAppId());

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(game.pixmapIcon()), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemName = new QStandardItem(game.name());

        model->setItem(row, StaticticGamesAppId,   itemId);
        model->setItem(row, StaticticGamesIndex,   itemIndex);
        model->setItem(row, StaticticGamesIcon,    itemIcon);
        model->setItem(row, StaticticGamesTitle,    itemName);

        ++row;
    }
    model->setHorizontalHeaderItem(StaticticGamesAppId, new QStandardItem(tr("ID")));
    model->setHorizontalHeaderItem(StaticticGamesIndex, new QStandardItem(tr("Index")));
    model->setHorizontalHeaderItem(StaticticGamesIcon, new QStandardItem(tr("")));
    model->setHorizontalHeaderItem(StaticticGamesTitle, new QStandardItem(tr("Название")));
    setModelToTable(model);
}

void FormStatistics::setModelToTable(QStandardItemModel *aModel) {
    if (_currentGamesType == GamesType::none) {
        ui->TableViewGames->setVisible(false);
        return;
    }
    if (ui->TableViewGames->model() != nullptr) {
        delete ui->TableViewGames->model();
    }
    ui->TableViewGames->setModel(aModel);
    ui->TableViewGames->setSortingEnabled(true);
    ui->TableViewGames->setColumnHidden(StaticticGamesAppId, true);
    ui->TableViewGames->setColumnHidden(StaticticGamesIndex, true);
    ui->TableViewGames->resizeColumnsToContents();
    ui->TableViewGames->resizeRowsToContents();
    ui->TableViewGames->setVisible(true);
}

void FormStatistics::updateSettings() {
    Settings::syncronizeSettings();
    updateIcons();
}

void FormStatistics::updateIcons() {

}

FormStatistics::~FormStatistics() {
    qInfo() << "Форма статистики удалилась";
    delete ui;
}
