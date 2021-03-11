#include "formstatistics.h"
#include "ui_formstatistics.h"

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
    QStringList titles;
    titles << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11"
             << "12" << "13" << "14" << "15" << "16" << "17" << "18" << "19" << "20" << "21" << "22" << "23";
    return titles;
}

QStringList getMonthTitles() {
    QStringList titles;
    titles << QObject::tr("Январь") << QObject::tr("Февраль") << QObject::tr("Март") << QObject::tr("Апрель") << QObject::tr("Май") << QObject::tr("Июнь")
            << QObject::tr("Июль") << QObject::tr("Август") << QObject::tr("Сентябрь") << QObject::tr("Октябрь") << QObject::tr("Ноябрь") << QObject::tr("Декабрь");
    return titles;
}

FormStatistics::FormStatistics(const SProfile &profile, QList<SGame> &aGames, const QString &aName, QWidget *aParent): QWidget(aParent), ui(new Ui::FormStatistics), _profile(profile), _games(aGames), _name(aName) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
//    QFont font(Settings::defaultFont());
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

    createThread();
}

void FormStatistics::changeEvent(QEvent *aEvent) {
    if(aEvent->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormStatistics::retranslate() {
    ui->retranslateUi(this);
    ui->LabelAveragePercentValue->setText(QString("%1\n-%2: %3%\n-%4: %5%").arg(
                                        tr("Средний процент"),
                                        tr("по всем играм"),
                                        QString::number(_totalAverage / (_complete.count() + _started.count() + _notStarted.count())),
                                        tr("по начатым играм"),
                                        QString::number(_totalAverage / (_complete.count() + _started.count()))));
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
    Threading *loadData = new Threading(this);
    loadData->AddThreadStatistics(_games, _profile.steamID(), _noAchievements, _complete, _started, _notStarted, _summColumn, _times, _months, _years);
    connect (loadData, &Threading::s_statistics_progress, this, [=](int progress) {
        emit s_statisticsLoaded(progress);
    });
    connect (loadData, &Threading::s_statistics_finished, this, &FormStatistics::onFinish);
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

QPieSlice *getPieChart(QString aTitle, int aValue, int aAllValue, QColor aColor) {
    QPieSlice *slice = new QPieSlice(aTitle + QString(" - %1%").arg(100.0 * aValue / aAllValue, 0, 'f', 2), aValue);
    slice->setBrush(aColor);
    slice->setLabelVisible(true);
    QObject::connect(slice, &QPieSlice::hovered, slice, &QPieSlice::setExploded);
    return slice;
}

void FormStatistics::onFinish() {
    _totalAverage = 100.0 * _complete.count();
    for (const auto &average: qAsConst(_started)) {
        _totalAverage += average.second;
    }
    ui->LabelAveragePercentValue->setText(QString("%1\n-%2: %3%\n-%4: %5%").arg(tr("Средний процент"),
                                                                                tr("по всем играм"),
                                                                                QString::number(_totalAverage / (_complete.count() + _started.count() + _notStarted.count())),
                                                                                tr("по начатым играм"),
                                                                                QString::number(_totalAverage / (_complete.count() + _started.count()))));
    ui->LabelSummColumnValue->setText(QString::number(_summColumn));

    #define SetChartDonut {
    QPieSeries *series = new QPieSeries();
    series->append(getPieChart(tr("Закончено (%1)")     .arg(_complete.count())         ,_complete.count()      , _games.count(), QColor(85, 181, 62)));
    series->append(getPieChart(tr("Начато (%1)")        .arg(_started.count())          ,_started.count()       , _games.count(), QColor(205, 203, 31)));
    series->append(getPieChart(tr("Не начато (%1)")     .arg(_notStarted.count())       ,_notStarted.count()    , _games.count(), QColor(178, 50, 50)));
    series->append(getPieChart(tr("Нет достижений (%1)").arg(_noAchievements.count())   ,_noAchievements.count(), _games.count(), QColor(41, 41, 41)));

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

void FormStatistics::updateSettings() {
    Settings::syncronizeSettings();
    setIcons();
}

void FormStatistics::setIcons() {

}

FormStatistics::~FormStatistics() {
    qInfo() << "Форма статистики удалилась";
    delete ui;
}
