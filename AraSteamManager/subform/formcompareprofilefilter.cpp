#include "formcompareprofilefilter.h"
#include "ui_formcompareprofilefilter.h"

FormCompareProfileFilter::FormCompareProfileFilter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCompareProfileFilter)
{
    ui->setupUi(this);
}

FormCompareProfileFilter::~FormCompareProfileFilter()
{
    delete ui;
}
