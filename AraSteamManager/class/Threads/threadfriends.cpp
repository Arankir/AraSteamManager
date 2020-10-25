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
    QFont font(Settings::getFontDefaultName(), 9);
    int row = 0;
    QStandardItemModel *model = new QStandardItemModel;
    for (auto friendP: _friends) {
        QStandardItem *itemId = new QStandardItem(friendP.second._steamID);

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon2 = new QStandardItem();
        itemIcon2->setData(QVariant(friendP.second.getPixmapAvatar()), Qt::DecorationRole);
        itemIcon2->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemNickName2 = new QStandardItem(friendP.second._personaName);

        QStandardItem *itemAdded2 = new QStandardItem(friendP.first._friend_since.toString("yyyy.MM.dd hh:mm"));

        QStandardItem *itemState2 = getState(friendP.second._gameExtraInfo, friendP.second._personaState);

        QStandardItem *itemPrivacy2 = getPrivacy(friendP.second._communityVisibilityState);

        itemNickName2->setFont(font);
        itemAdded2   ->setFont(font);
        itemState2   ->setFont(font);
        itemPrivacy2 ->setFont(font);

        model->setItem(row, c_tableColumnID, itemId);
        model->setItem(row, c_tableColumnIndex, itemIndex);
        model->setItem(row, c_tableColumnIcon, itemIcon2);
        model->setItem(row, c_tableColumnName, itemNickName2);
        model->setItem(row, c_tableColumnAdded, itemAdded2);
        model->setItem(row, c_tableColumnStatus, itemState2);
        model->setItem(row, c_tableColumnisPublic, itemPrivacy2);
        emit s_progress(row, row);
        ++row;
    }
    emit s_finishedModel(model);
    return 1;
}
