#include "formstatistics.h"
#include "ui_formstatistics.h"

//Можно подключить при изменении названия слайса изменить название мейн слайса, тогда будет переводиться легенда
FormStatistics::FormStatistics(QString a_id, SGames a_games, QString a_name, QWidget *parent) : QWidget(parent),ui(new Ui::FormStatistics),_id(a_id),_games(a_games),_name(a_name){
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
    _donutBreakdown->setMargins(QMargins(1,1,1,1));
    switch(_setting.GetTheme()){
        case 1:
            _donutBreakdown->setTheme(QChart::ChartThemeDark);
            break;
        case 2:
            break;
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

    Threading LoadData(this);
    LoadData.AddThreadStatistics(_games,_id);
}

void FormStatistics::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        Retranslate();
    }
}
void FormStatistics::Retranslate(){
    ui->retranslateUi(this);
    ui->LabelAveragePercentValue->setText(QString("%1\n-%2: %3%\n-%4: %5%").arg(tr("Средний процент"),tr("по всем играм"),QString::number(_totalAverage/(_numof[0]+_numof[1]+_numof[2])),tr("по начатым играм"),QString::number(_totalAverage/(_numof[1]+_numof[2]))));
    QList<QAbstractSeries*> series = _donutBreakdown->series();
    switch (series.size()) {
        default:

        case 3:
            dynamic_cast<QPieSeries*>(series[2])->slices()[0]->setLabel(tr("Закончено (%1)").arg(_numof[2]));
        case 2:
            dynamic_cast<QPieSeries*>(series[1])->slices()[0]->setLabel(tr("Начато (%1)").arg(_numof[1]));
        case 1:
            dynamic_cast<QPieSeries*>(series[0])->slices()[0]->setLabel(tr("Не начато (%1)").arg(_numof[0]));
        case 0:;

    }
    _chartT->setTitle(tr("Достижения по часам"));
    _chartM->setTitle(tr("Достижения по месяцам"));
    QBarCategoryAxis *axisXM = new QBarCategoryAxis();
    QStringList titlesXM;
    titlesXM <<tr("Январь")<<tr("Февраль")<<tr("Март")<<tr("Апрель")<<tr("Май")<<tr("Июнь")<<tr("Июль")<<tr("Август")<<tr("Сентябрь")<<tr("Октябрь")<<tr("Ноябрь")<<tr("Декабрь");
    axisXM->append(titlesXM);
    if((_chartM->series().size()>0)&&(_chartM->axes(Qt::Horizontal,_chartM->series().at(0)).size()>0))
            dynamic_cast<QBarCategoryAxis*>(_chartM->axes(Qt::Horizontal,_chartM->series().at(0)).at(0))->setCategories(titlesXM);
    _chartY->setTitle(tr("Достижения по годам"));
}
void FormStatistics::OnFinish(QVector<int> a_numof, QVector<QPair<QString,QString> > a_complete,
                              QVector<QPair<QString,QString>> a_started, QVector<QPair<QString,QString>> a_notStarted,
                              QVector<double> a_averagePercent, int a_summcolumn, QVector<int> a_times,
                              QVector<int> a_months, QVector<QPair<QString,int>> a_years){
    _numof=a_numof;
    _complete=a_complete;
    _started=a_started;
    _notStarted=a_notStarted;
    _averagePercent=a_averagePercent;
    _averagePercent.resize(_averagePercent.size());
    _summcolumn=a_summcolumn;
    _times=a_times;
    _months=a_months;
    _years=a_years;
    _totalAverage=0.0;
    for(double averageForGame: _averagePercent) {
        _totalAverage+=averageForGame;
    }
    ui->LabelAveragePercentValue->setText(QString("%1\n-%2: %3%\n-%4: %5%").arg(tr("Средний процент"),tr("по всем играм"),QString::number(_totalAverage/(_numof[0]+_numof[1]+_numof[2])),tr("по начатым играм"),QString::number(_totalAverage/(_numof[1]+_numof[2]))));
    ui->LabelSummColumnValue->setText(QString::number(_summcolumn));

    #define SetChartDonut {
    QPieSeries *series1 = new QPieSeries();
    series1->append(tr("Не начато (%1)").arg(_numof[0]), _numof[0]);
    QPieSeries *series2 = new QPieSeries();
    series2->append(tr("Начато (%1)").arg(_numof[1]), _numof[1]);
    QPieSeries *series3 = new QPieSeries();
    series3->append(tr("Закончено (%1)").arg(_numof[2]), _numof[2]);

    _donutBreakdown->addBreakdownSeries(series1, QColor(178,50,50));
    _donutBreakdown->addBreakdownSeries(series2, QColor(205,203,31));
    _donutBreakdown->addBreakdownSeries(series3, QColor(85,181,62));
    //donutBreakdown->legend()->setVisible(false);
    ui->ChartViewPercentages->setChart(_donutBreakdown);
    #define SetChartDonutEnd }
    #define SetChartTimes {
    int max=0;
    QBarCategoryAxis *axisXT = new QBarCategoryAxis();
    QBarSet *barSetT = new QBarSet(_id);
    for(int i=0;i<24;i++){
        axisXT->append(QString::number(i));
        *barSetT<<_times[i];
        if(max<_times[i])
            max=_times[i];
        }
    max+=(10000-max%10000);

    QValueAxis *axisYT = new QValueAxis();
    axisYT->setMax(max);
    axisYT->setLabelFormat("%i");

    _chartT->addAxis(axisXT, Qt::AlignBottom);
    _chartT->addAxis(axisYT, Qt::AlignLeft);
    switch(_setting.GetTheme()){
        case 1:
            _chartT->setTheme(QChart::ChartThemeDark);
            break;
        case 2:
            barSetT->setLabelColor(Qt::black);
            break;
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
    max=0;
    QBarCategoryAxis *axisXM = new QBarCategoryAxis();
    QStringList titlesXM;
    titlesXM <<tr("Январь")<<tr("Февраль")<<tr("Март")<<tr("Апрель")<<tr("Май")<<tr("Июнь")<<tr("Июль")<<tr("Август")<<tr("Сентябрь")<<tr("Октябрь")<<tr("Ноябрь")<<tr("Декабрь");
    axisXM->append(titlesXM);
    QBarSet *barSetM = new QBarSet(_id);
    for(int i=0;i<12;i++){
        *barSetM<<_months[i];
        if(max<_months[i])
            max=_months[i];
        }
    max+=(10000-max%10000);

    QValueAxis *axisYM = new QValueAxis();
    axisYM->setMax(max);
    axisYM->setLabelFormat("%i");

    _chartM->addAxis(axisXM, Qt::AlignBottom);
    _chartM->addAxis(axisYM, Qt::AlignLeft);
    switch(_setting.GetTheme()){
        case 1:
            _chartM->setTheme(QChart::ChartThemeDark);
            break;
        case 2:
            barSetM->setLabelColor(Qt::black);
            break;
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
    max=0;
    QBarCategoryAxis *axisXY = new QBarCategoryAxis();
    QBarSet *barSetY = new QBarSet(_id);
    for(auto &year: _years){
        axisXY->append(year.first);
        *barSetY<<year.second;
        if(max<year.second)
            max=year.second;
    }
    max+=(10000-max%10000);

    QValueAxis *axisYY = new QValueAxis();
    axisYY->setMax(max);
    axisYY->setLabelFormat("%i");

    _chartY->addAxis(axisXY, Qt::AlignBottom);
    _chartY->addAxis(axisYY, Qt::AlignLeft);
    switch(_setting.GetTheme()){
        case 1:
            _chartY->setTheme(QChart::ChartThemeDark);
            break;
        case 2:
            barSetY->setLabelColor(Qt::black);
            break;
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
}

FormStatistics::~FormStatistics(){
    delete ui;
}
