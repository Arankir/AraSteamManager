#include "threadgames.h"

int ThreadGames::fill() {
    QFont font(Settings::getFontDefaultName(), 10);
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;
    for (auto game: _games) {
        QStandardItem *itemId = new QStandardItem(QString::number(game._appID));

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(game.getPixmapIcon()), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemName = new QStandardItem(game._name);

        QStandardItem *itemComment = new QStandardItem();
        itemComment->setData(QVariant(game.getPixmapIcon()), Qt::DecorationRole);
        itemComment->setFlags(Qt::ItemFlag::ItemIsEnabled);

        itemName->setFont(font);

        model->setItem(row, c_tableColumnAppid,     itemId);
        model->setItem(row, c_tableColumnIndex,     itemIndex);
        model->setItem(row, c_tableColumnIcon,      itemIcon);
        model->setItem(row, c_tableColumnName,      itemName);
        model->setItem(row, c_tableColumnComment,   itemComment);
        emit s_progress(row, row);
        ++row;
    }
    model->insertColumn(c_tableColumnProgress);
    emit s_finishedModel(model);
    return 1;
}

