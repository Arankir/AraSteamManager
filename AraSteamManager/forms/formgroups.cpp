#include "formgroups.h"
#include "ui_formgroups.h"
#include "classes/common/images.h"

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
//            int row = ui->listWidgetGroups->row(lItem);
//            ui->listWidgetGroups->item(row);
            groups_.find(lItem->text())->changeTitle(lItem->text());
        }
    });
}

void FormGroups::setProfileGames(const ProfileID &aProfileId, const SGames &aGame) {
    groups_.update(aProfileId);
    games_ = aGame;
    initUi();
    QStringList names;
    for (const SGame &game: games_) {
        names << game.name();
    }
    QString name = names.join(",");
    if (name.length() > 33) {
        name = name.first(30) + "...";
    }
    ui->LabelTitle->setText(name);
    if (games_.count() > 0) {
        ui->labelIcon->setPixmap(games_[0].pixmapIcon());
    }
}

void FormGroups::initUi() {
    for(const GroupGames &group: groups_) {
        QListWidgetItem *item = new QListWidgetItem(group.title());
        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
        QSet<GameID> games = group;
        bool isAllInGroup = true;
        bool isAnyoneInGroup = false;
        for (const SGame &game: games_) {
            bool isInGroup = games.find(game.appId()) != games.end();
            if (isInGroup) {
                isAnyoneInGroup = true;
            } else {
                isAllInGroup = false;
            }
        }
        if (isAllInGroup) {
            item->setCheckState(Qt::CheckState::Checked);
        } else if (isAnyoneInGroup) {
            item->setCheckState(Qt::CheckState::PartiallyChecked);
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
    qDebug() << ui->listWidgetGroups->count() << groups_.count();
}

void FormGroups::cancel() {
    close();
}

void FormGroups::apply() {
    for(int row = 0; row < ui->listWidgetGroups->count() - 1; ++row) {
        QListWidgetItem *item = ui->listWidgetGroups->item(row);
        if (item->flags().testFlag(Qt::ItemIsUserCheckable)) {
            if (item->checkState() == Qt::CheckState::Checked) {
                for (const SGame &game: games_) {
                    groups_.find(item->text())->addGame(game);
                }
            } else {
                for (const SGame &game: games_) {
                    groups_.find(item->text())->removeGame(game.appId());
                }
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
    QListWidgetItem *item = ui->listWidgetGroups->item(ui->listWidgetGroups->count() - 1);
    item->setIcon(QIcon(Images::create()));
}

//void FormGroups::updateSettings(QFlags<changedSettings> aSettings) {
//    if (aSettings.testFlag(changedSettings::theme)) {
//        updateIcons();
//    }
//}
