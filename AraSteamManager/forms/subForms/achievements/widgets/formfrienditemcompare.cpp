#include "formfrienditemcompare.h"
#include "ui_formfrienditemcompare.h"

FormFriendItemCompare::FormFriendItemCompare(SProfile *steamFriend, QListWidgetItem *parent) :
                        ui(new Ui::FormFriendItemCompare),
                        _item(parent),
                        _steamProfile(steamFriend) {
    ui->setupUi(this);
    ui->LabelName->setText(_steamProfile->personaName());
    ui->LabelPercent->setText("0%");
    setIcons();

    connect(ui->ButtonDelete, &QPushButton::clicked, this, [=](){
        emit s_delete();
    });
    connect(ui->Filter, &FormReachedFilter::s_radioButtonChange, this ,[=](ReachedType type) {
        emit s_filterChanged(_steamProfile, type);
    });
}

void FormFriendItemCompare::setIcons() {
    ui->ButtonDelete->setIcon(QIcon(Images::deleteIcon()));
}

QListWidgetItem *FormFriendItemCompare::item() {
    return _item;
}

SProfile *FormFriendItemCompare::steamProfile() {
    return _steamProfile;
}

void FormFriendItemCompare::setHiddenFilter(bool aHidden) {
    ui->Filter->setVisible(!aHidden);
}

bool FormFriendItemCompare::isFilterHidden() {
    return ui->Filter->isHidden();
}

void FormFriendItemCompare::setFilterValue(ReachedType type) {
    ui->Filter->setType(type);
}

void FormFriendItemCompare::setPercent(double aPercent) {
    QString per;
    per.setNum(aPercent, 'f', 2);
    ui->LabelPercent->setText(per + "%");
}

FormFriendItemCompare::~FormFriendItemCompare() {
    delete ui;
}
