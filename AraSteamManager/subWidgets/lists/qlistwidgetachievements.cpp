#include "qlistwidgetachievements.h"

const QString c_whatsThis = "QListWidgetAchievements";

QListWidgetAchievements::QListWidgetAchievements(QWidget *aParent) : QListWidget(aParent) {
    setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
    setWhatsThis(c_whatsThis);
}

void QListWidgetAchievements::setGame(SGame &aGame) {
    _game = aGame;
}

void QListWidgetAchievements::insertAchievement(const SAchievement &aAchievement, int aRow) {
    QListWidgetAchievement *item = new QListWidgetAchievement(aAchievement);
    if (_game.appId() > 0) {
        item->setIcon(aAchievement.icon(_game.appId()));
    }
    item->setText(aAchievement.displayName());
    item->setToolTip(textToToolTip(aAchievement.description()));
    if (aRow == -1) {
        addItem(item);
    } else {
        insertItem(aRow, item);
    }
}

void QListWidgetAchievements::startDrag(Qt::DropActions aSupportedActions) {
    auto items = selectedItems();
    //Формирование MimeData для всех выделенных item'ов
    auto mimeData = new QMimeData ();
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    for(auto &item: items) {
        QListWidgetAchievement *achievementItem = dynamic_cast<QListWidgetAchievement*>(item);
        if (achievementItem != nullptr) {
            QMap<int,  QVariant> map = model()->itemData(model()->index(row(achievementItem), 0));
            QVariant var = QVariant::fromValue(*(achievementItem->_achievement));
            stream << var << row(achievementItem) << 0 << map;
        }
    }
    mimeData->setData("application/x-qabstractitemmodeldatalist", data);

    //Вызов перетаскивания со сформированными данными
    auto drag = new QDrag(this);
    drag->setMimeData(mimeData);
    if (drag->exec(aSupportedActions, defaultDropAction()) == Qt::MoveAction) {
        //Удаление перемещенных item'ов
        for (auto &item: items) {
            if (auto achievementItem = dynamic_cast<QListWidgetAchievement*>(item)) {
                auto itemWithAchievement = takeItem(row(achievementItem));
//                delete achievementItem->_achievement;
                removeItemWidget(itemWithAchievement);
            } else {
                auto itemWithAchievement = takeItem(row(item));
                removeItemWidget(itemWithAchievement);
            }
        }
    }
}

void QListWidgetAchievements::dropEvent(QDropEvent *aEvent) {
    QByteArray encoded = aEvent->mimeData()->data("application/x-qabstractitemmodeldatalist");
    QDataStream stream(&encoded, QIODevice::ReadOnly);

    while (!stream.atEnd()) {
        int row, col;
        QVariant achievementText;
        QMap<int,  QVariant> roleDataMap;
        stream >> achievementText >> row >> col >> roleDataMap;

        if (achievementText.canConvert<SAchievement>()) {
            QModelIndex dropIndex = indexAt(aEvent->position().toPoint());
            switch(dropIndicatorPosition()) {
            case DropIndicatorPosition::BelowItem: {
                dropInsert(achievementText.value<SAchievement>(), dropIndex.row() + 1, roleDataMap);
                break;
            }
            default: {
                dropInsert(achievementText.value<SAchievement>(), dropIndex.row(), roleDataMap);
                break;
            }
            }
        }
    }
    aEvent->accept();
}

void QListWidgetAchievements::dropInsert(const SAchievement &aAchievement, int aRow, const QMap<int,  QVariant> &aRoleData) {
    QListWidgetAchievement *item = new QListWidgetAchievement(aAchievement);
    for (auto iterator = aRoleData.begin(); iterator != aRoleData.end(); ++iterator) {
        item->setData(iterator.key(), iterator.value());
    }
    if (aRow == -1) {
        addItem(item);
    } else {
        insertItem(aRow, item);
    }
}

void QListWidgetAchievements::dragEnterEvent(QDragEnterEvent *aEvent) {
    auto widget = dynamic_cast<QWidget*>(aEvent->source());
    if (widget) {
        if (dynamic_cast<QWidget*>(aEvent->source())->whatsThis() == c_whatsThis) {
            if (aEvent->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {
                aEvent->accept();
                return;
            }
        }
    }
    aEvent->ignore();
}

void QListWidgetAchievements::dragLeaveEvent(QDragLeaveEvent *aEvent) {
    aEvent->accept();
}
