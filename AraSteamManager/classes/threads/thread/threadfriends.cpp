#include "threadfriends.h"

QStandardItem *getState(const QString &aGameExtraInfo, int aPersonaState) {
    QStandardItem *item = new QStandardItem;
    if (!aGameExtraInfo.isEmpty()) {
        item->setText(QObject::tr("В игре"));
        item->setForeground(QColor(137,183,83));
    } else
        switch (aPersonaState) {
        case 0:{
                item->setText(QObject::tr("Не в сети"));
                item->setForeground(QColor(76,77,79));
                break;
        }
        case 1:{
                item->setText(QObject::tr("В сети"));
                item->setForeground(QColor(87,203,222));
                break;
        }
        case 2:{
                item->setText(QObject::tr("Не беспокоить"));
                item->setForeground(QColor(129,85,96));
                break;
        }
        case 3:{
                item->setText(QObject::tr("Нет на месте"));
                item->setForeground(QColor(70,120,142));
                break;
        }
        case 4:{
                item->setText(QObject::tr("Спит"));
                item->setForeground(QColor(70,120,142));
                break;
        }
        case 5:{
                item->setText(QObject::tr("Ожидает обмена"));
                item->setForeground(Qt::darkMagenta);
                break;
        }
        case 6:{
                item->setText(QObject::tr("Хочет поиграть"));
                item->setForeground(Qt::darkMagenta);
                break;
        }
        }
    return item;
}

QStandardItem *getPrivacy(int aCommunityVisibilityState) {
    QStandardItem *item = new QStandardItem;
    switch (aCommunityVisibilityState) {
    case 1:{
        item->setText(QObject::tr("Скрытый"));
        item->setForeground(QColor(155,44,44));
        break;
    }
    case 2:{
        item->setText(QObject::tr("Скрытый"));
        item->setForeground(QColor(155,44,44));
        break;
    }
    case 3:{
        item->setText(QObject::tr("Публичный"));
        item->setForeground(QColor(105,155,44));
        break;
    }
    case 8:{
        item->setText(QObject::tr("Скрытый"));
        item->setForeground(QColor(155,44,44));
        break;
    }
    }
    return item;
}

int ThreadFriends::fill() {
//    QFont font(Settings::defaultFont(), 9);
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;

    for (auto friendP: _friends) {
        QStandardItem *itemId = new QStandardItem(friendP.second.steamID());

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(friendP.second.pixmapAvatar()), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemNickName = new QStandardItem(friendP.second.personaName());

        QStandardItem *itemAdded = new QStandardItem(friendP.first.friendSince().toString("yyyy.MM.dd hh:mm"));

        QStandardItem *itemState = getState(friendP.second.gameExtraInfo(), friendP.second.personaState());

        QStandardItem *itemPrivacy = getPrivacy(friendP.second.communityVisibilityState());

//        itemNickName->setFont(font);
//        itemAdded   ->setFont(font);
//        itemState   ->setFont(font);
//        itemPrivacy ->setFont(font);

        model->setItem(row, c_tableColumnID, itemId);
        model->setItem(row, c_tableColumnIndex, itemIndex);
        model->setItem(row, c_tableColumnIcon, itemIcon);
        model->setItem(row, c_tableColumnName, itemNickName);
        model->setItem(row, c_tableColumnAdded, itemAdded);
        model->setItem(row, c_tableColumnStatus, itemState);
        model->setItem(row, c_tableColumnisPublic, itemPrivacy);
        emit s_progress(row, row);
        ++row;
    }
    emit s_finishedModel(model);
    return 1;
}
