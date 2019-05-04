#include "formfriends.h"
#include "ui_formfriends.h"

FormFriends::FormFriends(QString ids, QString keys, int languages, QJsonDocument QJsonDocFriendss, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFriends)
{
    ui->setupUi(this);
    id=ids;
    key=keys;
    language=languages;
    QJsonDocFriends=QJsonDocFriendss;
}

FormFriends::~FormFriends()
{
    delete ui;
}
