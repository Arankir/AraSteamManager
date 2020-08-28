#include "formstatistics.h"
#include "ui_formstatistics.h"

//Можно подключить при изменении названия слайса изменить название мейн слайса, тогда будет переводиться легенда
FormStatistics::FormStatistics(QString aId, SGames aGames, QString aName, QWidget *aParent): QWidget(aParent), ui(new Ui::FormStatistics), _id(aId), _games(aGames), _name(aName) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    int id = QFontDatabase::addApplicationFont(_setting.c_defaultFont);
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    ui->ChartsViewTimes->setStyleSheet("background: rgba(0,0,0,0); ");
    ui->ChartsViewMonths->setStyleSheet("background: rgba(0,0,0,0); ");
    ui->ChartsViewYears->setStyleSheet("background: rgba(0,0,0,0); ");
    ui->ChartViewPercentages->setStyleSheet("background: rgba(0,0,0,0); ");
    _donutBreakdown = new DonutBreakdownChart();
    _chartT = new QChart;
    _chartM = new QChart;
    _chartY = new QChart;

    _donutBreakdown->setBackgroundVisible(false);
    _donutBreakdown->setAnimationOptions(QChart::SeriesAnimations);
    _donutBreakdown->legend()->setAlignment(Qt::AlignRight);
    _donutBreakdown->setMargins(QMargins(1, 1, 1, 1));
    switch(_setting.getTheme()) {
    case 1: {
        _donutBreakdown->setTheme(QChart::ChartThemeDark);
        break;
    }
    case 2: {
        break;
    }
    }

    _chartT->legend()->setAlignment(Qt::AlignBottom);
    _chartT->setAnimationOptions(QChart::SeriesAnimations);
    _chartT->setTitle(tr("Достижения по часам"));
    _chartT->setBackgroundVisible(false);
    ui->ChartsViewTimes->setChart(_chartT);
    ui->ChartsViewTimes->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewTimes->setMinimumSize(480, 480);

    _chartM->legend()->setAlignment(Qt::AlignBottom);
    _chartM->setAnimationOptions(QChart::SeriesAnimations);
    _chartM->setTitle(tr("Достижения по месяцам"));
    _chartM->setBackgroundVisible(false);
    ui->ChartsViewMonths->setChart(_chartM);
    ui->ChartsViewMonths->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewMonths->setMinimumSize(480, 480);

    _chartY->legend()->setAlignment(Qt::AlignBottom);
    _chartY->setAnimationOptions(QChart::SeriesAnimations);
    _chartY->setTitle(tr("Достижения по годам"));
    _chartY->setBackgroundVisible(false);
    ui->ChartsViewYears->setChart(_chartY);
    ui->ChartsViewYears->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewYears->setMinimumSize(480, 480);

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
                                        QString::number(_totalAverage / (_numof[0] + _numof[1] + _numof[2])),
                                        tr("по начатым играм"),
                                        QString::number(_totalAverage / (_numof[1] + _numof[2]))));
    QList<QAbstractSeries*> series = _donutBreakdown->series();
    //Using fall-through
    switch (series.size()) {
    default: {

    }
    case 3: {
        QPieSeries *pie = dynamic_cast<QPieSeries*>(series[2]);
        if (pie) {
            pie->slices()[0]->setLabel(tr("Закончено (%1)").arg(_numof[2]));
        }
    }
    case 2: {
        QPieSeries *pie = dynamic_cast<QPieSeries*>(series[1]);
        if (pie) {
            pie->slices()[0]->setLabel(tr("Начато (%1)").arg(_numof[1]));
        }
    }
    case 1: {
        QPieSeries *pie = dynamic_cast<QPieSeries*>(series[0]);
        if (pie) {
            pie->slices()[0]->setLabel(tr("Не начато (%1)").arg(_numof[0]));
        }
    }
    case 0: {

    }
    }
    _chartT->setTitle(tr("Достижения по часам"));
    _chartM->setTitle(tr("Достижения по месяцам"));
    QBarCategoryAxis *axisXM = new QBarCategoryAxis();
    QStringList titlesXM;
    titlesXM <<tr("Январь") <<tr("Февраль") <<tr("Март") <<tr("Апрель") <<tr("Май") <<tr("Июнь")
            <<tr("Июль") <<tr("Август") <<tr("Сентябрь") <<tr("Октябрь") <<tr("Ноябрь") <<tr("Декабрь");
    axisXM->append(titlesXM);
    if((_chartM->series().size() > 0) && (_chartM->axes(Qt::Horizontal, _chartM->series().at(0)).size() > 0)) {
        QBarCategoryAxis *bar = dynamic_cast<QBarCategoryAxis*>(_chartM->axes(Qt::Horizontal, _chartM->series().at(0)).at(0));
        if (bar) {
            bar->setCategories(titlesXM);
        }
    }
    _chartY->setTitle(tr("Достижения по годам"));
}

void FormStatistics::createThread() {
    Threading *loadData = new Threading(this);
    loadData->AddThreadStatistics(_games, _id, _numof, _complete, _started, _notStarted, _averagePercent, _summcolumn, _times, _months, _years);
    connect (loadData, &Threading::s_statistics_progress, this, [=](int progress, int row) {
        emit s_statisticsLoaded(progress, row);
    });
    connect (loadData, &Threading::s_statistics_finished, this, &FormStatistics::onFinish);
}

void FormStatistics::onFinish() {
    _totalAverage = 0.0;
    for(double averageForGame: _averagePercent) {
        _totalAverage += averageForGame;
    }
    ui->LabelAveragePercentValue->setText(QString("%1\n-%2: %3%\n-%4: %5%").arg(tr("Средний процент"),
                                                                                tr("по всем играм"),
                                                                                QString::number(_totalAverage / (_numof[0] + _numof[1] + _numof[2])),
                                                                                tr("по начатым играм"),
                                                                                QString::number(_totalAverage / (_numof[1] + _numof[2]))));
    ui->LabelSummColumnValue->setText(QString::number(_summcolumn));

    #define SetChartDonut {
    QPieSeries *series1 = new QPieSeries();
    series1->append(tr("Не начато (%1)").arg(_numof[0]), _numof[0]);
    QPieSeries *series2 = new QPieSeries();
    series2->append(tr("Начато (%1)").arg(_numof[1]), _numof[1]);
    QPieSeries *series3 = new QPieSeries();
    series3->append(tr("Закончено (%1)").arg(_numof[2]), _numof[2]);

    _donutBreakdown->addBreakdownSeries(series1, QColor(178, 50, 50));
    _donutBreakdown->addBreakdownSeries(series2, QColor(205, 203, 31));
    _donutBreakdown->addBreakdownSeries(series3, QColor(85, 181, 62));
    //donutBreakdown->legend()->setVisible(false);
    ui->ChartViewPercentages->setChart(_donutBreakdown);
    #define SetChartDonutEnd }
    #define SetChartTimes {
    int max = 0;
    QBarCategoryAxis *axisXT = new QBarCategoryAxis();
    QBarSet *barSetT = new QBarSet(_id);
    for(int i = 0; i < 24; i++) {
        axisXT->append(QString::number(i));
        *barSetT<<_times[i];
        if(max < _times[i]) {
            max = _times[i];
        }
    }
    max += (10000 - max % 10000);

    QValueAxis *axisYT = new QValueAxis();
    axisYT->setMax(max);
    axisYT->setLabelFormat("%i");

    _chartT->addAxis(axisXT, Qt::AlignBottom);
    _chartT->addAxis(axisYT, Qt::AlignLeft);
    switch(_setting.getTheme()) {
    case 1: {
        _chartT->setTheme(QChart::ChartThemeDark);
        break;
    }
    case 2: {
        barSetT->setLabelColor(Qt::black);
        break;
    }
    }

    QBarSeries *barSeriesT = new QBarSeries;
    barSeriesT->append(barSetT);
    _chartT->addSeries(barSeriesT);
    barSeriesT->attachAxis(axisXT);
    barSeriesT->attachAxis(axisYT);
    barSeriesT->setLabelsVisible(true);
    barSeriesT->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    barSeriesT->setLabelsAngle(4);
    #define SetChartTimesEnd }
    #define SetChartMonths {
    max = 0;
    QBarCategoryAxis *axisXM = new QBarCategoryAxis();
    QStringList titlesXM;
    titlesXM <<tr("Январь") <<tr("Февраль") <<tr("Март") <<tr("Апрель") <<tr("Май") <<tr("Июнь")
            <<tr("Июль") <<tr("Август") <<tr("Сентябрь") <<tr("Октябрь") <<tr("Ноябрь") <<tr("Декабрь");
    axisXM->append(titlesXM);
    QBarSet *barSetM = new QBarSet(_id);
    for(int i = 0; i < 12; i++) {
        *barSetM <<_months[i];
        if(max < _months[i]) {
            max = _months[i];
        }
    }
    max += (10000 - max % 10000);

    QValueAxis *axisYM = new QValueAxis();
    axisYM->setMax(max);
    axisYM->setLabelFormat("%i");

    _chartM->addAxis(axisXM, Qt::AlignBottom);
    _chartM->addAxis(axisYM, Qt::AlignLeft);
    switch(_setting.getTheme()){
    case 1: {
        _chartM->setTheme(QChart::ChartThemeDark);
        break;
    }
    case 2: {
        barSetM->setLabelColor(Qt::black);
        break;
    }
    }

    QBarSeries *barSeriesM = new QBarSeries;
    barSeriesM->append(barSetM);
    _chartM->addSeries(barSeriesM);
    barSeriesM->attachAxis(axisXM);
    barSeriesM->attachAxis(axisYM);
    barSeriesM->setLabelsVisible(true);
    barSeriesM->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    barSeriesM->setLabelsAngle(4);
    #define SetChartMonthsEnd }
    #define SetChartYears {
    max = 0;
    QBarCategoryAxis *axisXY = new QBarCategoryAxis();
    QBarSet *barSetY = new QBarSet(_id);
    for(auto &year: _years) {
        axisXY->append(year.first);
        *barSetY <<year.second;
        if(max < year.second) {
            max=year.second;
        }
    }
    max += (10000 - max % 10000);

    QValueAxis *axisYY = new QValueAxis();
    axisYY->setMax(max);
    axisYY->setLabelFormat("%i");

    _chartY->addAxis(axisXY, Qt::AlignBottom);
    _chartY->addAxis(axisYY, Qt::AlignLeft);
    switch(_setting.getTheme()) {
    case 1: {
        _chartY->setTheme(QChart::ChartThemeDark);
        break;
    }
    case 2: {
        barSetY->setLabelColor(Qt::black);
        break;
    }
    }

    QBarSeries *barSeriesY = new QBarSeries;
    barSeriesY->append(barSetY);
    _chartY->addSeries(barSeriesY);
    barSeriesY->attachAxis(axisXY);
    barSeriesY->attachAxis(axisYY);
    barSeriesY->setLabelsVisible(true);
    barSeriesY->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    barSeriesY->setLabelsAngle(4);
    #define SetChartYearsEnd }
    emit s_finish();
}

void FormStatistics::updateSettings() {
    _setting.syncronizeSettings();
    setIcons();
}

void FormStatistics::setIcons() {

}

FormStatistics::~FormStatistics() {
    delete ui;
}
