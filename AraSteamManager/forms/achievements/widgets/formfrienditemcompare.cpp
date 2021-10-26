#include "formfrienditemcompare.h"
#include "ui_formfrienditemcompare.h"

FormFriendItemCompare::FormFriendItemCompare(SProfile &steamFriend, QListWidgetItem *parent) :
                        ui(new Ui::FormFriendItemCompare),
                        _item(parent),
                        _steamProfile(new SProfile(steamFriend)) {
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

FormFriendItemCompare::~FormFriendItemCompare() {
    delete _steamProfile;
    delete ui;
}

void FormFriendItemCompare::setIcons() {
    ui->ButtonDelete->setIcon(QIcon(Images::deleteIcon()));
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
