#include "formfriends.h"
#include "ui_formfriends.h"

FormFriends::FormFriends(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFriends)
{
    ui->setupUi(this);
}

FormFriends::~FormFriends()
{
    delete ui;
}
