#include "formfrienditemgraph.h"
#include "ui_formfrienditemgraph.h"

FormFriendItemGraph::FormFriendItemGraph(const SProfile &steamFriend, const QColor &color, QListWidgetItem *parent) :
                        ui(new Ui::FormFriendItemGraph),
                        _item(parent),
                        _steamProfile(new SProfile(steamFriend)),
                        _color(color) {
    ui->setupUi(this);
    ui->LabelName->setText(_steamProfile->personaName());
    QPixmap pix(16, 16);
    pix.fill(_color);
    ui->LabelColor->setPixmap(pix);
    setIcons();

    connect(ui->ButtonDelete, &QPushButton::clicked, this, [&]() {
        emit s_delete();
    });
}

FormFriendItemGraph::~FormFriendItemGraph() {
    delete _steamProfile;
    delete ui;
}

void FormFriendItemGraph::setColor(const QColor &aColor) {
    _color = aColor;
    QPixmap pix(16, 16);
    pix.fill(_color);
    ui->LabelColor->setPixmap(pix);
}

void FormFriendItemGraph::setIcons() {
    ui->ButtonDelete->setIcon(QIcon(Images::deleteIcon()));
}
