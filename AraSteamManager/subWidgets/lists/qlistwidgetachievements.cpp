#include "qlistwidgetachievements.h"
#include "classes/common/generalfunctions.h"

const QString c_whatsThis = "QListWidgetAchievements";

QListWidgetAchievements::QListWidgetAchievements(QWidget *aParent) : QListWidget(aParent) {
    setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
    setWhatsThis(c_whatsThis);
}

void QListWidgetAchievements::insertAchievement(const SAchievement &aAchievement, const GameID &gameId, int row) {
    QListWidgetAchievement *item = new QListWidgetAchievement(aAchievement);
    if (gameId > 0) {
        item->setIcon(aAchievement.icon(gameId));
    }
    item->setText(aAchievement.displayName());
    item->setToolTip(textToToolTip(aAchievement.description()));
    if (row == -1) {
        addItem(item);
    } else {
        insertItem(row, item);
    }
}

void QListWidgetAchievements::startDrag(Qt::DropActions aSupportedActions) {
    QList<QListWidgetItem*> items = selectedItems();
    //Формирование MimeData для всех выделенных item'ов
    QMimeData *mimeData = new QMimeData ();
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    for(QListWidgetItem *item: items) {
        QListWidgetAchievement *achievementItem = dynamic_cast<QListWidgetAchievement*>(item);
        if (achievementItem != nullptr) {
            QMap<int,  QVariant> map = model()->itemData(model()->index(row(achievementItem), 0));
            QVariant var = QVariant::fromValue(*(achievementItem->achievement_));
            stream << var << row(achievementItem) << 0 << map;
        }
    }
    mimeData->setData("application/x-qabstractitemmodeldatalist", data);

    //Вызов перетаскивания со сформированными данными
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    if (drag->exec(aSupportedActions, defaultDropAction()) == Qt::MoveAction) {
        //Удаление перемещенных item'ов
        for (QListWidgetItem *item: items) {
            if (QListWidgetAchievement *achievementItem = dynamic_cast<QListWidgetAchievement*>(item)) {
                QListWidgetItem *itemWithAchievement = takeItem(row(achievementItem));
//                delete achievementItem->_achievement;
                removeItemWidget(itemWithAchievement);
            } else {
                QListWidgetItem *itemWithAchievement = takeItem(row(item));
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

void QListWidgetAchievements::dropInsert(const SAchievement &achievement, int row, const QMap<int,  QVariant> &roleData) {
    QListWidgetAchievement *item = new QListWidgetAchievement(achievement);
    for (auto iterator = roleData.begin(); iterator != roleData.end(); ++iterator) {
        item->setData(iterator.key(), iterator.value());
    }
    if (row == -1) {
        addItem(item);
    } else {
        insertItem(row, item);
    }
}

void QListWidgetAchievements::dragEnterEvent(QDragEnterEvent *aEvent) {
    QWidget *widget = dynamic_cast<QWidget*>(aEvent->source());
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
