#include "formgroups.h"
#include "ui_formgroups.h"

FormGroups::FormGroups(SProfile &aProfile, const SGame &aGame, QWidget *parent) :
    Form(parent), ui(new Ui::FormGroups), _groups(aProfile), _game(aGame) {
    ui->setupUi(this);
    setProfileGame();
    connect(ui->ButtonAdd,          &QPushButton::clicked, this, &FormGroups::add_clicked);
    connect(ui->ButtonChangeTitle,  &QPushButton::clicked, this, &FormGroups::changeTitle_clicked);
    connect(ui->ButtonCancel,       &QPushButton::clicked, this, &FormGroups::cancel_clicked);
    connect(ui->ButtonApply,        &QPushButton::clicked, this, &FormGroups::apply_clicked);
}

FormGroups::~FormGroups() {
    qInfo() << "Форма групп удалилась";
    delete ui;
}

void FormGroups::setProfileGame() {//TODO потом сделать это публичной функцией для передачи в нее данных, а конструктор сделать пустым
    initUi();
    ui->LabelTitle->setText(_game.name());
}

void FormGroups::initUi() {
    QVBoxLayout *layout = new QVBoxLayout();
    for(const auto &group: _groups) {
        ui->ComboBoxGroups->addItem(group.title());
        QCheckBox *chb = new QCheckBox(group.title());
        auto games = group.games();
        bool isInGroup = std::any_of(games.begin(),
                                     games.end(),
                                     [=](QString game) {
                                        return game == _game.sAppId();
                                     });
        if (isInGroup) {
            chb->setChecked(true);
        }
        layout->addWidget(chb);
    }
    if (QLayout *lay = ui->ScrollAreaGroups->layout()) {
        delete lay;
    }
    ui->ScrollAreaGroups->setLayout(layout);
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
    parentWidget()->parentWidget()->close();
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
    emit s_updateGroups();
    parentWidget()->parentWidget()->close();
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

void FormGroups::retranslate() {
    ui->retranslateUi(this);
}

void FormGroups::updateIcons() {

}

void FormGroups::updateSettings() {

}
