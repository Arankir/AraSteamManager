#include "formstatistics.h"
#include "ui_formstatistics.h"

FormStatistics::FormStatistics(QString Aid, SGames Agames, QString Aname, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStatistics){
    ui->setupUi(this);
    _games=Agames;
    _id=Aid;
    _name=Aname;
    Threading LoadData(this);
    LoadData.AddThreadStatistics(_games,_id);
}

void FormStatistics::OnFinish(QVector<int> Anumof, QVector<QPair<QString,QString> > Acomplete,
                              QVector<QPair<QString,QString>> Astarted, QVector<QPair<QString,QString>> AnotStarted,
                              QVector<double> AaveragePercent, int Asummcolumn, QVector<int> Atimes,
                              QVector<int> Amonths, QVector<QPair<QString,int>> Ayears){
    _numof=Anumof;
    _complete=Acomplete;
    _started=Astarted;
    _notStarted=AnotStarted;
    _averagePercent=AaveragePercent;
    _averagePercent.resize(_averagePercent.size());
    _summcolumn=Asummcolumn;
    _times=Atimes;
    _months=Amonths;
    _years=Ayears;
    double totalAverage=0.0;
    foreach (double averageForGame, _averagePercent) {
        totalAverage+=averageForGame;
    }
    ui->LabelAveragePercent->setText(QString("%1\n-%2: %3%\n-%4: %5%").arg(tr("Средний процент")).arg(tr("по всем играм")).arg(QString::number(totalAverage/(_numof[0]+_numof[1]+_numof[2]))).arg(tr("по начатым играм")).arg(QString::number(totalAverage/(_numof[1]+_numof[2]))));
    ui->LabelSummColumn->setText(tr("Всего достижений: %1").arg(_summcolumn));

    #define SetChartDonut {
    QPieSeries *series1 = new QPieSeries();
    series1->append(tr("Не начато (%1)").arg(_numof[0]), _numof[0]);
    QPieSeries *series2 = new QPieSeries();
    series2->append(tr("Начато (%1)").arg(_numof[1]), _numof[1]);
    QPieSeries *series3 = new QPieSeries();
    series3->append(tr("Закончено (%1)").arg(_numof[2]), _numof[2]);

    DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
    donutBreakdown->setBackgroundVisible(false);
    donutBreakdown->setAnimationOptions(QChart::SeriesAnimations);
    donutBreakdown->legend()->setAlignment(Qt::AlignRight);
    donutBreakdown->setMargins(QMargins(1,1,1,1));
    switch(_setting.GetTheme()){
        case 1:
            donutBreakdown->setTheme(QChart::ChartThemeDark);
            break;
        case 2:
            break;
    }
    donutBreakdown->addBreakdownSeries(series1, QColor("#b23232"));
    donutBreakdown->addBreakdownSeries(series2, QColor("#cdcb1f"));
    donutBreakdown->addBreakdownSeries(series3, QColor("#55b53e"));
    //donutBreakdown->legend()->setVisible(false);
    ui->ChartViewPercentages->setChart(donutBreakdown);
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

    QChart *chartT = new QChart;
    chartT->addAxis(axisXT, Qt::AlignBottom);
    chartT->addAxis(axisYT, Qt::AlignLeft);
    chartT->legend()->setAlignment(Qt::AlignBottom);
    chartT->setAnimationOptions(QChart::SeriesAnimations);
    chartT->setTitle(tr("Достижения по часам"));
    chartT->setBackgroundVisible(false);
    switch(_setting.GetTheme()){
        case 1:
            chartT->setTheme(QChart::ChartThemeDark);
            break;
        case 2:
            barSetT->setLabelColor(Qt::black);
            break;
    }

    QBarSeries *barSeriesT = new QBarSeries;
    barSeriesT->append(barSetT);
    chartT->addSeries(barSeriesT);
    barSeriesT->attachAxis(axisXT);
    barSeriesT->attachAxis(axisYT);
    barSeriesT->setLabelsVisible(true);
    barSeriesT->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    barSeriesT->setLabelsAngle(4);

    ui->ChartsViewTimes->setChart(chartT);
    ui->ChartsViewTimes->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewTimes->setMinimumSize(480, 480);
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

    QChart *chartM = new QChart;
    chartM->addAxis(axisXM, Qt::AlignBottom);
    chartM->addAxis(axisYM, Qt::AlignLeft);
    chartM->legend()->setAlignment(Qt::AlignBottom);
    chartM->setAnimationOptions(QChart::SeriesAnimations);
    chartM->setTitle(tr("Достижения по месяцам"));
    chartM->setBackgroundVisible(false);
    switch(_setting.GetTheme()){
        case 1:
            chartM->setTheme(QChart::ChartThemeDark);
            break;
        case 2:
            barSetM->setLabelColor(Qt::black);
            break;
    }

    QBarSeries *barSeriesM = new QBarSeries;
    barSeriesM->append(barSetM);
    chartM->addSeries(barSeriesM);
    barSeriesM->attachAxis(axisXM);
    barSeriesM->attachAxis(axisYM);
    barSeriesM->setLabelsVisible(true);
    barSeriesM->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    barSeriesM->setLabelsAngle(4);

    ui->ChartsViewMonths->setChart(chartM);
    ui->ChartsViewMonths->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewMonths->setMinimumSize(480, 480);
    #define SetChartMonthsEnd }
    #define SetChartYears {
    max=0;
    QBarCategoryAxis *axisXY = new QBarCategoryAxis();
    QBarSet *barSetY = new QBarSet(_id);
    for(int i=0;i<_years.size();i++){
        axisXY->append(_years[i].first);
        *barSetY<<_years[i].second;
        if(max<_years[i].second)
            max=_years[i].second;
        }
    max+=(10000-max%10000);

    QValueAxis *axisYY = new QValueAxis();
    axisYY->setMax(max);
    axisYY->setLabelFormat("%i");

    QChart *chartY = new QChart;
    chartY->addAxis(axisXY, Qt::AlignBottom);
    chartY->addAxis(axisYY, Qt::AlignLeft);
    chartY->legend()->setAlignment(Qt::AlignBottom);
    chartY->setAnimationOptions(QChart::SeriesAnimations);
    chartY->setTitle(tr("Достижения по годам"));
    chartY->setBackgroundVisible(false);
    switch(_setting.GetTheme()){
        case 1:
            chartY->setTheme(QChart::ChartThemeDark);
            break;
        case 2:
            barSetY->setLabelColor(Qt::black);
            break;
    }

    QBarSeries *barSeriesY = new QBarSeries;
    barSeriesY->append(barSetY);
    chartY->addSeries(barSeriesY);
    barSeriesY->attachAxis(axisXY);
    barSeriesY->attachAxis(axisYY);
    barSeriesY->setLabelsVisible(true);
    barSeriesY->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    barSeriesY->setLabelsAngle(4);

    ui->ChartsViewYears->setChart(chartY);
    ui->ChartsViewYears->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewYears->setMinimumSize(480, 480);
    #define SetChartYearsEnd }
}

FormStatistics::~FormStatistics(){
    delete ui;
}
