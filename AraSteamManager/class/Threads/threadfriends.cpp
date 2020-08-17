#include "threadfriends.h"

ThreadFriends::ThreadFriends(const int columnID, const int columnName, const int columnAdded, const int columnStatus, const int columnisPublic,
QTableWidget *TableWidgetFriends, QList<QPair<SFriend, SProfile>> aFriends, QObject *parent):
QObject(parent), c_tableColumnID(columnID), c_tableColumnName(columnName), c_tableColumnAdded(columnAdded), c_tableColumnStatus(columnStatus),
c_tableColumnisPublic(columnisPublic), _friends(aFriends), _tableWidgetFriends(TableWidgetFriends) {

}

int ThreadFriends::fill() {
    int id = std::move(QFontDatabase::addApplicationFont(_setting.c_defaultFont));
    QString family = std::move(QFontDatabase::applicationFontFamilies(id).at(0));
    QFont font(family, 9);
    int row = 0;
    for (auto friendP: _friends) {
        QTableWidgetItem *itemName = new QTableWidgetItem(friendP.second._personaName);
        QTableWidgetItem *itemAdded = new QTableWidgetItem(friendP.first._friend_since.toString("yyyy.MM.dd hh:mm"));
        QTableWidgetItem *itemState = getState(friendP.second._gameExtraInfo, friendP.second._personaState);
        QTableWidgetItem *itemPrivacy = getPrivacy(friendP.second._communityVisibilityState);
        itemName->setFont(font);
        itemAdded->setFont(font);
        itemState->setFont(font);
        itemPrivacy->setFont(font);
        _tableWidgetFriends->setItem(row, c_tableColumnID, new QTableWidgetItem(friendP.second._steamID));
        _tableWidgetFriends->setItem(row, c_tableColumnName, itemName);
        _tableWidgetFriends->setItem(row, c_tableColumnAdded, itemAdded);
        _tableWidgetFriends->setItem(row, c_tableColumnStatus, itemState);
        _tableWidgetFriends->setItem(row, c_tableColumnisPublic, itemPrivacy);
        emit s_progress(row, row);
        row++;
    }
    emit s_finished();
    return 1;
}

QTableWidgetItem *ThreadFriends::getState(QString aGameExtraInfo, int aPersonaState) {
    QTableWidgetItem *item = new QTableWidgetItem;
    if (!aGameExtraInfo.isEmpty()) {
        item->setText(tr("В игре"));
        item->setForeground(QColor(137,183,83));
    } else
        switch (aPersonaState) {
        case 0:{
                item->setText(tr("Не в сети"));
                item->setForeground(QColor(76,77,79));
                break;
        }
        case 1:{
                item->setText(tr("В сети"));
                item->setForeground(QColor(87,203,222));
                break;
        }
        case 2:{
                item->setText(tr("Не беспокоить"));
                item->setForeground(QColor(129,85,96));
                break;
        }
        case 3:{
                item->setText(tr("Нет на месте"));
                item->setForeground(QColor(70,120,142));
                break;
        }
        case 4:{
                item->setText(tr("Спит"));
                item->setForeground(QColor(70,120,142));
                break;
        }
        case 5:{
                item->setText(tr("Ожидает обмена"));
                item->setForeground(Qt::darkMagenta);
                break;
        }
        case 6:{
                item->setText(tr("Хочет поиграть"));
                item->setForeground(Qt::darkMagenta);
                break;
        }
        }
    return item;
}

QTableWidgetItem *ThreadFriends::getPrivacy(int aCommunityVisibilityState) {
    QTableWidgetItem *item = new QTableWidgetItem;
    switch (aCommunityVisibilityState) {
    case 1:{
        item->setText(tr("Скрытый"));
        item->setForeground(QColor(155,44,44));
        break;
    }
    case 2:{
        item->setText(tr("Скрытый"));
        item->setForeground(QColor(155,44,44));
        break;
    }
    case 3:{
        item->setText(tr("Публичный"));
        item->setForeground(QColor(105,155,44));
        break;
    }
    case 8:{
        item->setText(tr("Скрытый"));
        item->setForeground(QColor(155,44,44));
        break;
    }
    }
    return item;
}

