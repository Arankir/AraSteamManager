#include "formcomparefriends.h"
#include "ui_formcomparefriends.h"

FormCompareFriends::FormCompareFriends(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCompareFriends)
{
    ui->setupUi(this);
}

FormCompareFriends::~FormCompareFriends()
{
    delete ui;
}
