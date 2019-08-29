#include "formstatistic.h"
#include "ui_formstatistic.h"

FormStatistic::FormStatistic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStatistic)
{
    ui->setupUi(this);
   /* int Theme=1;
    switch (Theme) {
    case 1:{
        ui->FormStatisticCustomPlotGames->setBackground(QBrush(QColor(53, 53, 53)));
        ui->FormStatisticCustomPlotGames->xAxis->setTickLabelColor(Qt::white);
        ui->FormStatisticCustomPlotGames->xAxis->setBasePen(QPen(Qt::white));
        ui->FormStatisticCustomPlotGames->xAxis->setLabelColor(Qt::white);
        ui->FormStatisticCustomPlotGames->xAxis->setTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotGames->xAxis->setSubTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotGames->yAxis->setTickLabelColor(Qt::white);
        ui->FormStatisticCustomPlotGames->yAxis->setBasePen(QPen(Qt::white));
        ui->FormStatisticCustomPlotGames->yAxis->setLabelColor(Qt::white);
        ui->FormStatisticCustomPlotGames->yAxis->setTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotGames->yAxis->setSubTickPen(QPen(Qt::white));

        ui->FormStatisticCustomPlotHours->setBackground(QBrush(QColor(53, 53, 53)));
        ui->FormStatisticCustomPlotHours->xAxis->setTickLabelColor(Qt::white);
        ui->FormStatisticCustomPlotHours->xAxis->setBasePen(QPen(Qt::white));
        ui->FormStatisticCustomPlotHours->xAxis->setLabelColor(Qt::white);
        ui->FormStatisticCustomPlotHours->xAxis->setTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotHours->xAxis->setSubTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotHours->yAxis->setTickLabelColor(Qt::white);
        ui->FormStatisticCustomPlotHours->yAxis->setBasePen(QPen(Qt::white));
        ui->FormStatisticCustomPlotHours->yAxis->setLabelColor(Qt::white);
        ui->FormStatisticCustomPlotHours->yAxis->setTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotHours->yAxis->setSubTickPen(QPen(Qt::white));

        ui->FormStatisticCustomPlotDays->setBackground(QBrush(QColor(53, 53, 53)));
        ui->FormStatisticCustomPlotDays->xAxis->setTickLabelColor(Qt::white);
        ui->FormStatisticCustomPlotDays->xAxis->setBasePen(QPen(Qt::white));
        ui->FormStatisticCustomPlotDays->xAxis->setLabelColor(Qt::white);
        ui->FormStatisticCustomPlotDays->xAxis->setTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotDays->xAxis->setSubTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotDays->yAxis->setTickLabelColor(Qt::white);
        ui->FormStatisticCustomPlotDays->yAxis->setBasePen(QPen(Qt::white));
        ui->FormStatisticCustomPlotDays->yAxis->setLabelColor(Qt::white);
        ui->FormStatisticCustomPlotDays->yAxis->setTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotDays->yAxis->setSubTickPen(QPen(Qt::white));

        ui->FormStatisticCustomPlotMonths->setBackground(QBrush(QColor(53, 53, 53)));
        ui->FormStatisticCustomPlotMonths->xAxis->setTickLabelColor(Qt::white);
        ui->FormStatisticCustomPlotMonths->xAxis->setBasePen(QPen(Qt::white));
        ui->FormStatisticCustomPlotMonths->xAxis->setLabelColor(Qt::white);
        ui->FormStatisticCustomPlotMonths->xAxis->setTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotMonths->xAxis->setSubTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotMonths->yAxis->setTickLabelColor(Qt::white);
        ui->FormStatisticCustomPlotMonths->yAxis->setBasePen(QPen(Qt::white));
        ui->FormStatisticCustomPlotMonths->yAxis->setLabelColor(Qt::white);
        ui->FormStatisticCustomPlotMonths->yAxis->setTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotMonths->yAxis->setSubTickPen(QPen(Qt::white));

        ui->FormStatisticCustomPlotYears->setBackground(QBrush(QColor(53, 53, 53)));
        ui->FormStatisticCustomPlotYears->xAxis->setTickLabelColor(Qt::white);
        ui->FormStatisticCustomPlotYears->xAxis->setBasePen(QPen(Qt::white));
        ui->FormStatisticCustomPlotYears->xAxis->setLabelColor(Qt::white);
        ui->FormStatisticCustomPlotYears->xAxis->setTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotYears->xAxis->setSubTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotYears->yAxis->setTickLabelColor(Qt::white);
        ui->FormStatisticCustomPlotYears->yAxis->setBasePen(QPen(Qt::white));
        ui->FormStatisticCustomPlotYears->yAxis->setLabelColor(Qt::white);
        ui->FormStatisticCustomPlotYears->yAxis->setTickPen(QPen(Qt::white));
        ui->FormStatisticCustomPlotYears->yAxis->setSubTickPen(QPen(Qt::white));
        break;
        }
    case 2:{

        break;
        }
    }

//    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
//    dateTicker->setDateTimeFormat("hh");
    QSharedPointer<QCPAxisTickerText> TickerHours(new QCPAxisTickerText);
    for (int i=1;i<=24;i++) {
        TickerHours->addTick(i, QString::number(i)+":00");
    }
    ui->FormStatisticCustomPlotHours->xAxis->setTicker(TickerHours);
    ui->FormStatisticCustomPlotHours->xAxis->setRange(0,25);
    ui->FormStatisticCustomPlotHours->xAxis->setTickLength(1);
    ui->FormStatisticCustomPlotHours->xAxis->setSubTicks(false);
    ui->FormStatisticCustomPlotHours->yAxis->setTickLength(1);
    ui->FormStatisticCustomPlotHours->yAxis->setSubTicks(false);
    //ui->FormStatisticCustomPlotHours->xAxis->setDateTimeFormat("hh");

    QSharedPointer<QCPAxisTickerText> TickerDays(new QCPAxisTickerText);
    for (int i=1;i<=31;i++) {
        TickerDays->addTick(i, QString::number(i));
    }
    ui->FormStatisticCustomPlotDays->xAxis->setTicker(TickerDays);
    ui->FormStatisticCustomPlotDays->xAxis->setRange(0,32);
    ui->FormStatisticCustomPlotDays->xAxis->setTickLength(1);
    ui->FormStatisticCustomPlotDays->xAxis->setSubTicks(false);
    ui->FormStatisticCustomPlotDays->yAxis->setTickLength(1);
    ui->FormStatisticCustomPlotDays->yAxis->setSubTicks(false);

    QSharedPointer<QCPAxisTickerText> TickerMonths(new QCPAxisTickerText);
    TickerMonths->addTick(1, "Январь");
    TickerMonths->addTick(2, "Февраль");
    TickerMonths->addTick(3, "Март");
    TickerMonths->addTick(4, "Апрель");
    TickerMonths->addTick(5, "Май");
    TickerMonths->addTick(6, "Июнь");
    TickerMonths->addTick(7, "Июль");
    TickerMonths->addTick(8, "Август");
    TickerMonths->addTick(9, "Сентябрь");
    TickerMonths->addTick(10, "Октябрь");
    TickerMonths->addTick(11, "Ноябрь");
    TickerMonths->addTick(12, "Декабрь");
    ui->FormStatisticCustomPlotMonths->xAxis->setTicker(TickerMonths);
    ui->FormStatisticCustomPlotMonths->xAxis->setRange(0,13);
    ui->FormStatisticCustomPlotMonths->xAxis->setTickLength(1);
    ui->FormStatisticCustomPlotMonths->xAxis->setSubTicks(false);
    ui->FormStatisticCustomPlotMonths->yAxis->setTickLength(1);
    ui->FormStatisticCustomPlotMonths->yAxis->setSubTicks(false);*/
}

FormStatistic::~FormStatistic()
{
    delete ui;
}

void FormStatistic::closeEvent(QCloseEvent *){
    emit return_to_profile(this);
    //delete this;
}
void FormStatistic::on_FormStatisticButtonReturn_clicked(){
    emit return_to_profile(this);
//delete this;
}
