#include "formfavorites.h"
#include "ui_formfavorites.h"

FormFavorites::FormFavorites(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFavorites)
{
    ui->setupUi(this);
}

FormFavorites::~FormFavorites()
{
    delete ui;
}
