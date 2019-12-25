#include "formstatistics.h"
#include "ui_formstatistics.h"

FormStatistics::FormStatistics(QString Aid, SGames Agames, QString Aname, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStatistics){
    ui->setupUi(this);
    _games=Agames;
    _id=Aid;
    _name=Aname;
    for (int i=0;i<24;i++) {
        ui->tableWidget->setItem(0,i,new QTableWidgetItem(0));
        }
    for (int i=0;i<12;i++) {
        ui->tableWidget_2->setItem(0,i,new QTableWidgetItem(0));
        }
    Threading LoadData(this);
    LoadData.AddThreadStatistics(_games,_id);
}

void FormStatistics::OnFinish(QVector<int> Anumof, QVector<QPair<QString, QString> > Acomplete,
                              QVector<QPair<QString, QString> > Astarted, QVector<QPair<QString, QString> > AnotStarted,
                              QVector<double> AaveragePercent, int Asummcolumn, QVector<QPair<QString, int> > Atimes,
                              QVector<QPair<QString, int> > Amonths, QVector<QPair<QString, int> > Ayears){
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
    ui->tableWidget->setVerticalHeaderItem(0,new QTableWidgetItem(_name));
    for (int i=0;i<24;i++) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(_times[i].second)));
        }
    for (int i=0;i<12;i++) {
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::number(_months[i].second)));
        }
    ui->tableWidget_3->setRowCount(_years.size());
    for (int i=0;i<_years.size();i++) {
        ui->tableWidget_3->setVerticalHeaderItem(i,new QTableWidgetItem(_years[i].first));
        ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::number(_years[i].second)));
    }
    double totalAverage=0.0;
    foreach (double averageForGame, _averagePercent) {
        totalAverage+=0.0+averageForGame;
    }
    ui->LabelAveragePercent->setText(tr("Средний процент\n-по всем играм: %1%\n-по начатым играм: %2%").arg(QString::number(totalAverage/(_numof[0]+_numof[1]+_numof[2]))).arg(QString::number(totalAverage/(_numof[1]+_numof[2]))));
    ui->LabelSummColumn->setText(tr("Всего достижений: %1").arg(_summcolumn));
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget_2->resizeColumnsToContents();
    ui->tableWidget_3->resizeColumnsToContents();
    ui->tableWidget->setVisible(false);
    ui->tableWidget_2->setVisible(false);
    ui->tableWidget_3->setVisible(false);

    QPieSeries *series1 = new QPieSeries();
    series1->append(tr("Не начато (%1)").arg(_numof[0]), _numof[0]);
    QPieSeries *series2 = new QPieSeries();
    series2->append(tr("Начато (%1)").arg(_numof[1]), _numof[1]);
    QPieSeries *series3 = new QPieSeries();
    series3->append(tr("Закончено (%1)").arg(_numof[2]), _numof[2]);
    //![1]

    //![2]
    DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
    donutBreakdown->setBackgroundVisible(false);
    donutBreakdown->setAnimationOptions(QChart::SeriesAnimations);
    donutBreakdown->legend()->setAlignment(Qt::AlignRight);
    donutBreakdown->setMargins(QMargins(1,1,1,1));
    switch(_setting.GetTheme()){
    case 1:{
        donutBreakdown->setTheme(QChart::ChartThemeDark);
        break;
    }
    case 2:{

        break;
    }
    }
    donutBreakdown->addBreakdownSeries(series1, QColor("#b23232"));
    donutBreakdown->addBreakdownSeries(series2, QColor("#cdcb1f"));
    donutBreakdown->addBreakdownSeries(series3, QColor("#55b53e"));
    //donutBreakdown->legend()->setVisible(false);
    ui->ChartViewPercentages->setChart(donutBreakdown);

    #define SetChartTimes {
    QChart *chartTimes = new QChart;
    chartTimes->setAnimationOptions(QChart::SeriesAnimations);
    QBarSeries *seriesTimes = new QBarSeries;
    QVBarModelMapper *mapperTimes = new QVBarModelMapper(this);
    mapperTimes->setFirstBarSetColumn(0);
    mapperTimes->setLastBarSetColumn(24);
    mapperTimes->setFirstRow(0);
    mapperTimes->setRowCount(24);
    mapperTimes->setSeries(seriesTimes);
    mapperTimes->setModel(ui->tableWidget->model());
    chartTimes->addSeries(seriesTimes);
    QStringList titlesX1Times;
    QStringList titlesX2Times;
    for(int i=0;i<24;i++){
        titlesX1Times << _times[i].first;
        titlesX2Times << QString::number(_times[i].second)+tr("шт");
        }
    QBarCategoryAxis *axisX1Times = new QBarCategoryAxis();
    QBarCategoryAxis *axisX2Times = new QBarCategoryAxis();
    axisX1Times->append(titlesX1Times);
    axisX2Times->append(titlesX2Times);
    chartTimes->addAxis(axisX2Times, Qt::AlignTop);
    chartTimes->addAxis(axisX1Times, Qt::AlignBottom);
    seriesTimes->attachAxis(axisX1Times);
    QValueAxis *axisYTimes = new QValueAxis();
    axisYTimes->applyNiceNumbers();
    axisYTimes->setLabelFormat("%i");
    chartTimes->addAxis(axisYTimes, Qt::AlignLeft);
    chartTimes->setBackgroundVisible(false);
    switch(_setting.GetTheme()){
    case 1:{
        chartTimes->setTheme(QChart::ChartThemeDark);
        axisX1Times->setLabelsColor(Qt::white);
        axisX2Times->setLabelsColor(Qt::white);
        axisYTimes->setLabelsColor(Qt::white);
        chartTimes->setTitleBrush(QBrush(Qt::white));
        chartTimes->legend()->setColor(Qt::white);
        chartTimes->legend()->setBrush(QBrush(Qt::white));
        break;
    }
    case 2:{

        break;
    }
    }
    chartTimes->setTitle(tr("Достижения по часам"));
    seriesTimes->attachAxis(axisYTimes);
    ui->ChartsViewTimes->setChart(chartTimes);
    ui->ChartsViewTimes->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewTimes->setMinimumSize(480, 480);
    #define SetChartTimesEnd }
    #define SetChartMonths {
    QChart *chartMonths = new QChart;
    chartMonths->setAnimationOptions(QChart::SeriesAnimations);
    QBarSeries *seriesMonths = new QBarSeries;
    QVBarModelMapper *mapperMonths = new QVBarModelMapper(this);
    mapperMonths->setFirstBarSetColumn(0);
    mapperMonths->setLastBarSetColumn(12);
    mapperMonths->setFirstRow(0);
    mapperMonths->setRowCount(12);
    mapperMonths->setSeries(seriesMonths);
    mapperMonths->setModel(ui->tableWidget_2->model());
    chartMonths->addSeries(seriesMonths);
    QStringList titlesX1Months;
    QStringList titlesX2Months;
    for(int i=0;i<12;i++){
        titlesX1Months << _months[i].first;
        titlesX2Months << QString::number(_months[i].second)+tr("шт");
        }
    QBarCategoryAxis *axisX1Months = new QBarCategoryAxis();
    QBarCategoryAxis *axisX2Months = new QBarCategoryAxis();
    axisX1Months->append(titlesX1Months);
    axisX2Months->append(titlesX2Months);
    chartMonths->addAxis(axisX2Months, Qt::AlignTop);
    chartMonths->addAxis(axisX1Months, Qt::AlignBottom);
    seriesMonths->attachAxis(axisX1Months);
    QValueAxis *axisYMonths = new QValueAxis();
    axisYMonths->applyNiceNumbers();
    axisYMonths->setLabelFormat("%i");
    chartMonths->addAxis(axisYMonths, Qt::AlignLeft);
    chartMonths->setBackgroundVisible(false);
    switch(_setting.GetTheme()){
    case 1:{
        chartMonths->setTheme(QChart::ChartThemeDark);
        axisX1Months->setLabelsColor(Qt::white);
        axisX2Months->setLabelsColor(Qt::white);
        axisYMonths->setLabelsColor(Qt::white);
        chartMonths->setTitleBrush(QBrush(Qt::white));
        chartMonths->legend()->setColor(Qt::white);
        break;
    }
    case 2:{

        break;
    }
    }
    chartMonths->setTitle(tr("Достижения по месяцам"));
    seriesMonths->attachAxis(axisYMonths);
    ui->ChartsViewMonths->setChart(chartMonths);
    ui->ChartsViewMonths->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewMonths->setMinimumSize(480, 480);
    #define SetChartMonthsEnd }
    #define SetChartYears {
    QChart *chartYears = new QChart;
    chartYears->setAnimationOptions(QChart::SeriesAnimations);
    QBarSeries *seriesYears = new QBarSeries;
    QVBarModelMapper *mapperYears = new QVBarModelMapper(this);
    mapperYears->setFirstBarSetColumn(0);
    mapperYears->setLastBarSetColumn(ui->tableWidget_3->rowCount());
    mapperYears->setFirstRow(0);
    mapperYears->setRowCount(ui->tableWidget_3->rowCount());
    mapperYears->setSeries(seriesYears);
    mapperYears->setModel(ui->tableWidget_3->model());
    chartYears->addSeries(seriesYears);
    QStringList titlesX1Years;
    QStringList titlesX2Years;
    for(int i=0;i<ui->tableWidget_3->rowCount();i++){
        titlesX1Years << _years[i].first;
        titlesX2Years << QString::number(_years[i].second)+tr("шт");
        }
    QBarCategoryAxis *axisX1Years = new QBarCategoryAxis();
    QBarCategoryAxis *axisX2Years = new QBarCategoryAxis();
    axisX1Years->append(titlesX1Years);
    axisX2Years->append(titlesX2Years);
    chartYears->addAxis(axisX2Years, Qt::AlignTop);
    chartYears->addAxis(axisX1Years, Qt::AlignBottom);
    seriesYears->attachAxis(axisX1Years);
    QValueAxis *axisYYears = new QValueAxis();
    axisYYears->applyNiceNumbers();
    axisYYears->setLabelFormat("%i");
    chartYears->addAxis(axisYYears, Qt::AlignLeft);
    chartYears->setBackgroundVisible(false);
    switch(_setting.GetTheme()){
    case 1:{
        chartYears->setTheme(QChart::ChartThemeDark);
        axisX1Years->setLabelsColor(Qt::white);
        axisX2Years->setLabelsColor(Qt::white);
        axisYYears->setLabelsColor(Qt::white);
        chartYears->setTitleBrush(QBrush(Qt::white));
        chartYears->legend()->setColor(Qt::white);
        break;
    }
    case 2:{

        break;
    }
    }
    chartYears->setTitle(tr("Достижения по годам"));
    seriesYears->attachAxis(axisYYears);
    ui->ChartsViewYears->setChart(chartYears);
    ui->ChartsViewYears->setRenderHint(QPainter::Antialiasing);
    ui->ChartsViewYears->setMinimumSize(480, 480);
    #define SetChartYearsEnd }
}

FormStatistics::~FormStatistics(){
    delete ui;
}
