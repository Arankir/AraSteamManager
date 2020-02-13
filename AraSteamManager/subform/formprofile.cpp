#include "formprofile.h"
#include "ui_formprofile.h"

FormProfile::FormProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormProfile)
{
    ui->setupUi(this);
}

FormProfile::~FormProfile()
{
    delete ui;
}
