#include "formgroupsgamesinteractions.h"
#include "ui_formgroupsgamesinteractions.h"

FormGroupsGamesInteractions::FormGroupsGamesInteractions(SProfile &aProfile, SGame &aGame, QWidget *parent) :
    QWidget(parent), ui(new Ui::FormGroupsGamesInteractions), _groups(aProfile), _game(aGame) {
    ui->setupUi(this);
    init();
}

FormGroupsGamesInteractions::~FormGroupsGamesInteractions() {
    delete ui;
}

void FormGroupsGamesInteractions::init() {
    initUi();
    ui->LabelTitle->setText(_game._name);

    connect(ui->ButtonAdd,          &QPushButton::clicked, this, &FormGroupsGamesInteractions::add_clicked);
    connect(ui->ButtonChangeTitle,  &QPushButton::clicked, this, &FormGroupsGamesInteractions::changeTitle_clicked);
    connect(ui->ButtonCancel,       &QPushButton::clicked, this, &FormGroupsGamesInteractions::cancel_clicked);
    connect(ui->ButtonApply,        &QPushButton::clicked, this, &FormGroupsGamesInteractions::apply_clicked);
}

void FormGroupsGamesInteractions::initUi() {
    QVBoxLayout *layout = new QVBoxLayout(ui->ScrollAreaGroups);
    for(const auto &group: _groups) {
        ui->ComboBoxGroups->addItem(group.getTitle());
        QCheckBox *chb = new QCheckBox(group.getTitle());
        auto games = group.getGames();
        bool isInGroup = std::any_of(games.begin(), games.end(), [=](QString game) {
                                                                    return game == QString::number(_game._appID);
                                                                });
        if (isInGroup) {
            chb->setChecked(true);
        }
        layout->addWidget(chb);
    }
}

void FormGroupsGamesInteractions::clear() {
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

void FormGroupsGamesInteractions::updateUi() {
    clear();
    initUi();
}

void FormGroupsGamesInteractions::add(const QString &aTitle) {
    _groups.addGroup(aTitle);
    updateUi();
}

void FormGroupsGamesInteractions::changeTitle(const int &aIndex, const QString &aTitle) {
    _groups[aIndex].changeTitle(aTitle);
    updateUi();
}

void FormGroupsGamesInteractions::cancel() {
    emit s_updateGroups(false);
    close();
}

void FormGroupsGamesInteractions::apply() {
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

void FormGroupsGamesInteractions::add_clicked() {
    add(ui->LineEditAddTitle->text());
}

void FormGroupsGamesInteractions::changeTitle_clicked() {
    changeTitle(ui->ComboBoxGroups->currentIndex(), ui->LineEditChangeTitle->text());
}

void FormGroupsGamesInteractions::cancel_clicked() {
    cancel();
}

void FormGroupsGamesInteractions::apply_clicked() {
    apply();
}
