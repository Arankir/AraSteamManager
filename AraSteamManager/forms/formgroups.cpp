#include "formgroups.h"
#include "ui_formgroups.h"

FormGroups::FormGroups(SProfile &aProfile, SGame &aGame, QWidget *parent) :
    QWidget(parent), ui(new Ui::FormGroups), _groups(aProfile), _game(aGame) {
    ui->setupUi(this);
    init();
}

FormGroups::~FormGroups() {
    delete ui;
}

void FormGroups::init() {
    initUi();
    ui->LabelTitle->setText(_game.name());

    connect(ui->ButtonAdd,          &QPushButton::clicked, this, &FormGroups::add_clicked);
    connect(ui->ButtonChangeTitle,  &QPushButton::clicked, this, &FormGroups::changeTitle_clicked);
    connect(ui->ButtonCancel,       &QPushButton::clicked, this, &FormGroups::cancel_clicked);
    connect(ui->ButtonApply,        &QPushButton::clicked, this, &FormGroups::apply_clicked);
}

void FormGroups::initUi() {
    QVBoxLayout *layout = new QVBoxLayout(ui->ScrollAreaGroups);
    for(const auto &group: _groups) {
        ui->ComboBoxGroups->addItem(group.getTitle());
        QCheckBox *chb = new QCheckBox(group.getTitle());
        auto games = group.getGames();
        bool isInGroup = std::any_of(games.begin(), games.end(), [=](QString game) {
                                                                    return game == _game.sAppId();
                                                                });
        if (isInGroup) {
            chb->setChecked(true);
        }
        layout->addWidget(chb);
    }
}

void FormGroups::clear() {
    ui->ComboBoxGroups->clear();
    if (ui->ScrollAreaGroups->layout() != nullptr) {
        QLayoutItem *wItem;
        while ((wItem = ui->ScrollAreaGroups->layout()->takeAt(0)) != NULL) {
            delete wItem->widget();
            delete wItem;
        }
        delete ui->ScrollAreaGroups->layout();
    }
}

void FormGroups::updateUi() {
    clear();
    initUi();
}

void FormGroups::add(const QString &aTitle) {
    _groups.addGroup(aTitle);
    updateUi();
}

void FormGroups::changeTitle(const int &aIndex, const QString &aTitle) {
    _groups[aIndex].changeTitle(aTitle);
    updateUi();
}

void FormGroups::cancel() {
    emit s_updateGroups(false);
    close();
}

void FormGroups::apply() {
    for (int i = 0; i < ui->ScrollAreaGroups->layout()->count(); ++i) {
        QCheckBox *chb = dynamic_cast<QCheckBox*>(ui->ScrollAreaGroups->layout()->itemAt(i)->widget());
        if (chb) {
            if (chb->isChecked()) {
                _groups[i].addGame(_game);
            } else {
                _groups[i].removeGame(_game);
            }
        }
    }

    _groups.save();
    emit s_updateGroups(true);
    close();
}

void FormGroups::add_clicked() {
    add(ui->LineEditAddTitle->text());
}

void FormGroups::changeTitle_clicked() {
    changeTitle(ui->ComboBoxGroups->currentIndex(), ui->LineEditChangeTitle->text());
}

void FormGroups::cancel_clicked() {
    cancel();
}

void FormGroups::apply_clicked() {
    apply();
}
