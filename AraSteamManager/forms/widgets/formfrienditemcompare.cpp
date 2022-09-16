#include "formfrienditemcompare.h"
#include "ui_formfrienditemcompare.h"
#include "classes/common/images.h"

FormFriendItemCompare::FormFriendItemCompare(const SProfile &steamFriend, QListWidgetItem *parent) :
                        ui(new Ui::FormFriendItemCompare),
                        item_(parent),
                        profile_(new SProfile(steamFriend)) {
    ui->setupUi(this);
    ui->LabelName->setText(profile_->personaName());
    ui->LabelPercent->setText("0%");
    setIcons();

    connect(ui->ButtonDelete, &QPushButton::clicked, this, [&](){
        emit s_delete();
    });
    connect(ui->Filter, &ButtonReachedType::s_radioButtonChange, this ,[&](ReachedType type) {
        emit s_filterChanged(profile_, type);
    });
}

FormFriendItemCompare::~FormFriendItemCompare() {
    delete profile_;
    delete ui;
}

void FormFriendItemCompare::setIcons() {
    ui->ButtonDelete->setIcon(QIcon(Images::deleteIcon()));
}

QListWidgetItem *FormFriendItemCompare::item() {
    return item_;
}

SProfile *FormFriendItemCompare::steamProfile() {
    return profile_;
}

void FormFriendItemCompare::setHiddenFilter(const bool &aHidden) {
    ui->Filter->setVisible(!aHidden);
}

bool FormFriendItemCompare::isFilterHidden() {
    return ui->Filter->isHidden();
}

void FormFriendItemCompare::setFilterValue(const ReachedType &type) {
    ui->Filter->setType(type);
}

void FormFriendItemCompare::setPercent(const double &aPercent) {
    ui->LabelPercent->setText(QString::number(aPercent, 'f', 2) + "%");
}
