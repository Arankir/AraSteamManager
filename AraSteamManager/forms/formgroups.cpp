#include "formgroups.h"
#include "ui_formgroups.h"

#include <QInputDialog>
#include <QAction>
#include <QMenu>

FormGroups::FormGroups(QWidget *parent): Form(parent), ui(new Ui::FormGroups) {
    ui->setupUi(this);
    init();
}

FormGroups::~FormGroups() {
    delete ui;
}

void FormGroups::init() {
    ui->listWidgetGroups->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->ButtonCancel,       &QPushButton::clicked, this, &FormGroups::cancelClicked);
    connect(ui->ButtonApply,        &QPushButton::clicked, this, &FormGroups::applyClicked);
    connect(ui->listWidgetGroups,   &QListView::customContextMenuRequested, this, [&](QPoint lPos) {
        createMenu(ui->listWidgetGroups->currentItem())->popup(ui->listWidgetGroups->viewport()->mapToGlobal(lPos));
    });
    connect(ui->listWidgetGroups,   &QListWidget::itemClicked, this, [&]() {
        if (ui->listWidgetGroups->row(ui->listWidgetGroups->currentItem()) == ui->listWidgetGroups->count() - 1) {
            QString title = QInputDialog::getText(this, tr("Новая группа"), tr("Название:"), QLineEdit::Normal, "");
            if (!title.isEmpty()) {
                groups_.addGroup(title);
                updateUi();
            }
        }
    });
    connect(ui->listWidgetGroups, &QListWidget::itemChanged, this, [=, this](QListWidgetItem *lItem) {
        if (lItem->flags().testFlag(Qt::ItemIsUserCheckable)) {
            int row = ui->listWidgetGroups->row(lItem);
            ui->listWidgetGroups->item(row);
            groups_[row].changeTitle(lItem->text());
        }
    });
}

void FormGroups::setProfileGame(const ProfileID &aProfileId, const SGame &aGame) {
    groups_.update(aProfileId);
    game_ = aGame;
    initUi();
    ui->LabelTitle->setText(game_.name());
    ui->labelIcon->setPixmap(game_.pixmapIcon());
}

void FormGroups::initUi() {
    for(const auto &group: groups_) {
        QListWidgetItem *item = new QListWidgetItem(group.title());
        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
        auto games = group.games();
        bool isInGroup = std::any_of(games.begin(),
                                     games.end(),
                                     [this](GameID game) {
                                        return game == game_.appId();
                                     });
        if (isInGroup) {
            item->setCheckState(Qt::CheckState::Checked);
        } else {
            item->setCheckState(Qt::CheckState::Unchecked);
        }
        ui->listWidgetGroups->addItem(item);
    }
    QListWidgetItem *itemAdd = new QListWidgetItem(QIcon(Images::create()), tr("Добавить"));
    itemAdd->setFlags(itemAdd->flags() | Qt::ItemIsEnabled);
    ui->listWidgetGroups->addItem(itemAdd);
}

void FormGroups::clear() {
    int count = ui->listWidgetGroups->count();
    for(int row = 0; row < count; ++row) {
        delete ui->listWidgetGroups->takeItem(0);
    }
}

void FormGroups::updateUi() {
    clear();
    initUi();
}

QMenu *FormGroups::createMenu(QListWidgetItem *aItem) {
    QAction *actionAchievements = new QAction(QIcon(Images::deleteIcon()), tr("Удалить"), this);
    connect (actionAchievements, &QAction::triggered, this, [=, this]() {
        removeGroup(aItem);
    });

    QMenu *menu = new QMenu(this);
    menu->addAction (actionAchievements);
    return menu;
}

void FormGroups::removeGroup(QListWidgetItem *aItem) {
    groups_.removeGroup(aItem->text());
    updateUi();
}

void FormGroups::cancel() {
    close();
}

void FormGroups::apply() {
    for(int row = 0; row < ui->listWidgetGroups->count(); ++row) {
        auto item = ui->listWidgetGroups->item(row);
        if (item->flags().testFlag(Qt::ItemIsUserCheckable)) {
            if (item->checkState() == Qt::CheckState::Checked) {
                groups_[row].addGame(game_);
            } else {
                groups_[row].removeGame(game_.appId());
            }
        }
    }

    groups_.save();
    emit s_updateGroups();
    close();
}

void FormGroups::cancelClicked() {
    cancel();
}

void FormGroups::applyClicked() {
    apply();
}

void FormGroups::retranslate() {
    ui->retranslateUi(this);
}

void FormGroups::updateIcons() {
    auto item = ui->listWidgetGroups->item(ui->listWidgetGroups->count() - 1);
    item->setIcon(QIcon(Images::create()));
}

void FormGroups::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}
