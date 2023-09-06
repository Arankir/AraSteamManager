#include "formhiddengames.h"
#include "ui_formhiddengames.h"
#include "classes/files/hiddengames.h"
#include "classes/common/images.h"
#include <QDir>
#include <QMessageBox>

FormHiddenGames::FormHiddenGames(QWidget *aParent): Form(aParent), ui(new Ui::FormHiddenGames) {
    ui->setupUi(this);
    init();
}

FormHiddenGames::~FormHiddenGames() {
    delete ui;
}

void FormHiddenGames::retranslate() {
    ui->retranslateUi(this);
}

void FormHiddenGames::updateIcons() {

}

void FormHiddenGames::init() {
    ui->treeWidgetHiddenGames->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->treeWidgetHiddenGames->setWordWrap(true);
    connect(ui->treeWidgetHiddenGames, &QTableView::customContextMenuRequested,this, [&](QPoint pos) {
        GameID gameId = ui->treeWidgetHiddenGames->model()->data(ui->treeWidgetHiddenGames->currentIndex().siblingAtColumn(HiddenGamesData::Columns::id)).toString().toInt();
        QModelIndex profile = ui->treeWidgetHiddenGames->currentIndex().parent();
        if (profile.isValid()) {
            ProfileID profileId = ui->treeWidgetHiddenGames->model()->data(profile.siblingAtColumn(HiddenGamesData::Columns::id)).toString();
            if (gameId > 0) {
                QMenu *menu = createMenu(ui->treeWidgetHiddenGames->currentIndex());
                menu->popup(ui->treeWidgetHiddenGames->viewport()->mapToGlobal(pos));
            }
        }
    });
    connect(ui->treeWidgetHiddenGames, &QTableView::doubleClicked, this, [&](QModelIndex aIndex) {
        Q_UNUSED(aIndex);
        achievementsClicked();
    });

    update();
    ui->treeWidgetHiddenGames->setColumnCount(2);
    ui->treeWidgetHiddenGames->setColumnHidden(HiddenGamesData::Columns::id, true);
}

void FormHiddenGames::update() {
    ui->treeWidgetHiddenGames->clear();

    QDir dirHiddenGames(Paths::hiddenGames().remove("All.txt"));
    dirHiddenGames.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dirHiddenGames.setSorting(QDir::Name);
    if(dirHiddenGames.exists()) {
        QFileInfoList list = dirHiddenGames.entryInfoList();
        for(const QFileInfo &file: list) {
            QString fileName = file.fileName();
            HiddenGames hGames(fileName == "All.txt" ? "" : fileName.remove(".txt"));
            if (hGames.count() > 0) {
                QTreeWidgetItem *itemProfile = new QTreeWidgetItem();
                if(fileName == "All.txt") {
                    itemProfile->setData(HiddenGamesData::Columns::text, Qt::ItemDataRole::DisplayRole, tr("Скрыто у всех"));
                } else {
                    SProfile profile = SProfile::load(fileName.remove(".txt"), SProfile::LoadType::id);
                    itemProfile->setData(HiddenGamesData::Columns::icon, Qt::ItemDataRole::DecorationRole, profile.pixmapAvatar());
                    itemProfile->setData(HiddenGamesData::Columns::text, Qt::ItemDataRole::DisplayRole, profile.personaName());
                    itemProfile->setData(HiddenGamesData::Columns::id, Qt::ItemDataRole::DisplayRole, profile.steamId());
                }
                itemProfile->setData(HiddenGamesData::Columns::text, Qt::ItemDataRole::ToolTipRole, textToToolTip(itemProfile->data(HiddenGamesData::Columns::text, Qt::ItemDataRole::DisplayRole).toString()));

                for(const HiddenGame &game: hGames) {
                    QTreeWidgetItem *itemGame = new QTreeWidgetItem(itemProfile);
                    itemGame->setData(HiddenGamesData::Columns::icon, Qt::ItemDataRole::DecorationRole, SGame::pixmapIcon(game.id(), game.iconUrl()));
                    itemGame->setText(HiddenGamesData::Columns::text, game.name());
                    itemGame->setData(HiddenGamesData::Columns::id, Qt::ItemDataRole::DisplayRole, QString::number(game.id()));
                }
                ui->treeWidgetHiddenGames->addTopLevelItem(itemProfile);
            }
        }
    }

    ui->treeWidgetHiddenGames->expandAll();
    ui->treeWidgetHiddenGames->resizeColumnToContents(HiddenGamesData::Columns::id);
    ui->treeWidgetHiddenGames->resizeColumnToContents(HiddenGamesData::Columns::icon);
    ui->treeWidgetHiddenGames->resizeColumnToContents(HiddenGamesData::Columns::text);
    ui->treeWidgetHiddenGames->setColumnWidth(HiddenGamesData::Columns::text, std::min(150, ui->treeWidgetHiddenGames->columnWidth(HiddenGamesData::Columns::text)));
    ui->treeWidgetHiddenGames->collapseAll();
}

QMenu *FormHiddenGames::createMenu(const QModelIndex &aIndex) {
    Q_UNUSED(aIndex);
    QMenu *menu = new QMenu();

    QAction *actionAchievements = new QAction(QIcon(Images::achievement()), tr("Достижения"),         menu);
    connect(actionAchievements, &QAction::triggered, this, &FormHiddenGames::achievementsClicked);
    menu->addAction(actionAchievements);

    return menu;
}

void FormHiddenGames::achievementsClicked() {
    QModelIndex currentIdIndex = ui->treeWidgetHiddenGames->currentIndex();
    GameID gameId = ui->treeWidgetHiddenGames->model()->data(currentIdIndex.siblingAtColumn(HiddenGamesData::Columns::id)).toInt();
    QModelIndex parentIdIndex = currentIdIndex.parent();
    ProfileID profileId = ui->treeWidgetHiddenGames->model()->data(parentIdIndex.siblingAtColumn(HiddenGamesData::Columns::id)).toString();

    SGames games = SGame::load(profileId, true, true);
    auto iterator = std::find_if(games.begin(),
                                 games.end(),
                                 [=](const SGame &lGame) {
                                    return lGame.appId() == gameId;
                                 });
    if (iterator != games.end()) {
        emit s_showAchievements(*iterator);
    }
}
