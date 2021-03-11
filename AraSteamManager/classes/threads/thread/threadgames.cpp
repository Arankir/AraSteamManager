#include "threadgames.h"

int ThreadGames::fill() {
//    QFont font(Settings::defaultFont(), 10);
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;
    model->setColumnCount(ColumnGamesCount);
    for (auto game: qAsConst(_games)) {
        QStandardItem *itemId = new QStandardItem(game.sAppId());

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(game.pixmapIcon()), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemName = new QStandardItem(game.name());

//        QStandardItem *itemComment = new QStandardItem();
//        itemComment->setData(QVariant(game.pixmapIcon()), Qt::DecorationRole);
//        itemComment->setFlags(Qt::ItemFlag::ItemIsEnabled);

//        itemName->setFont(font);

        model->setItem(row, ColumnGamesAppid,   itemId);
        model->setItem(row, ColumnGamesIndex,   itemIndex);
        model->setItem(row, ColumnGamesIcon,    itemIcon);
        model->setItem(row, ColumnGamesName,    itemName);
        //model->setItem(row, ColumnGamesComment,   itemComment);
        emit s_progress(row);
        ++row;
    }
    emit s_finishedModel(model);
    return 1;
}

