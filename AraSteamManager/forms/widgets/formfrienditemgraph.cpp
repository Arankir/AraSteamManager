#include "formfrienditemgraph.h"
#include "ui_formfrienditemgraph.h"
#include "classes/common/images.h"

FormFriendItemGraph::FormFriendItemGraph(const SProfile &steamFriend, const QColor &color, QListWidgetItem *parent) :
                        ui(new Ui::FormFriendItemGraph),
                        item_(parent),
                        profile_(new SProfile(steamFriend)),
                        color_(color) {
    ui->setupUi(this);
    ui->LabelName->setText(profile_->personaName());
    QPixmap pix(16, 16);
    pix.fill(color_);
    ui->LabelColor->setPixmap(pix);
    setIcons();

    connect(ui->ButtonDelete, &QPushButton::clicked, this, [&]() {
        emit s_delete();
    });
}

FormFriendItemGraph::~FormFriendItemGraph() {
    delete profile_;
    delete ui;
}

void FormFriendItemGraph::setColor(const QColor &aColor) {
    color_ = aColor;
    QPixmap pix(16, 16);
    pix.fill(color_);
    ui->LabelColor->setPixmap(pix);
}

void FormFriendItemGraph::setIcons() {
    ui->ButtonDelete->setIcon(QIcon(Images::deleteIcon()));
}

QListWidgetItem *FormFriendItemGraph::item() {
    return item_;
}

SProfile *FormFriendItemGraph::profile() {
    return profile_;
}
