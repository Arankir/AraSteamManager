#include "qlistwidgetachievements.h"

const QString c_whatsThis = "QListWidgetAchievements";

QListWidgetAchievements::QListWidgetAchievements(QWidget *aParent) : QListWidget(aParent) {
    setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
    setWhatsThis(c_whatsThis);
}

void QListWidgetAchievements::setGame(SGame &aGame) {
    _game = aGame;
}

void QListWidgetAchievements::addAchievementItem(SAchievement &aAchievement, int aRow) {
    QListWidgetAchievement *item = new QListWidgetAchievement(&aAchievement);
    if (_game.appId() > 0) {
        item->setIcon(aAchievement.icon(_game.appId()));
    }
    item->setText(aAchievement.displayName());
    item->setToolTip(textToToolTip(aAchievement.description()));
//    item->setFont(QFont(Settings::defaultFont(), 11));
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
            stream << achievementItem->_achievement->toString() << row(achievementItem) << 0 << map;
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
                removeItemWidget(takeItem(row(achievementItem)));
            } else {
                removeItemWidget(takeItem(row(item)));
            }
        }
    }
}

void QListWidgetAchievements::dropEvent(QDropEvent *aEvent) {
    QByteArray encoded = aEvent->mimeData()->data("application/x-qabstractitemmodeldatalist");
    QDataStream stream(&encoded, QIODevice::ReadOnly);

    while (!stream.atEnd()) {
        int row, col;
        QString achievementText;
        QMap<int,  QVariant> roleDataMap;
        stream >> achievementText >> row >> col >> roleDataMap;

        if (!achievementText.isEmpty()) {
            SAchievement *achievement = new SAchievement(achievementText);
            QModelIndex dropIndex = indexAt(aEvent->pos());
            switch(dropIndicatorPosition()) {
            case DropIndicatorPosition::BelowItem: {
                addAchievementItem(*achievement, dropIndex.row() + 1);
                break;
            }
            default: {
                addAchievementItem(*achievement, dropIndex.row());
                break;
            }
            }
        }
    }
    aEvent->accept();
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
