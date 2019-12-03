#include "formstatistics.h"
#include "ui_formstatistics.h"

FormStatistics::FormStatistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStatistics)
{
    ui->setupUi(this);
}

FormStatistics::~FormStatistics()
{
    delete ui;
}
