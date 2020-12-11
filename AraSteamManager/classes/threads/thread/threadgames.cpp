#include "threadgames.h"

int ThreadGames::fill() {
    QFont font(Settings::getFontDefaultName(), 10);
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;
    model->setColumnCount(c_columnCount);
    for (auto game: _games) {
        QStandardItem *itemId = new QStandardItem(game.sAppId());

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(game.pixmapIcon()), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemName = new QStandardItem(game.name());

//        QStandardItem *itemComment = new QStandardItem();
//        itemComment->setData(QVariant(game.pixmapIcon()), Qt::DecorationRole);
//        itemComment->setFlags(Qt::ItemFlag::ItemIsEnabled);

        itemName->setFont(font);

        model->setItem(row, c_columnAppid,     itemId);
        model->setItem(row, c_columnIndex,     itemIndex);
        model->setItem(row, c_columnIcon,      itemIcon);
        model->setItem(row, c_columnName,      itemName);
        //model->setItem(row, c_tableColumnComment,   itemComment);
        emit s_progress(row, row);
        ++row;
    }
    emit s_finishedModel(model);
    return 1;
}

