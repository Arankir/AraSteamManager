#include "qlistwidgetachievements.h"

QListWidgetAchievements::QListWidgetAchievements(QWidget *parent) : QListWidget(parent) {

}

void QListWidgetAchievements::setGame(SGame &game) {
    _game = game;
}

void QListWidgetAchievements::addAchievementItem(SAchievement &aAchievement, int aRow) {
    QListWidgetAchievement *item = new QListWidgetAchievement(&aAchievement);
    if (_game.appId() > 0) {
        item->setIcon(aAchievement.getIcon(_game.appId()));
    }
    item->setText(aAchievement._displayName);
    item->setToolTip(aAchievement._description);
    item->setFont(QFont(Settings::getFontDefaultName(), 11));
    if (aRow == -1) {
        addItem(item);
    } else {
        insertItem(aRow, item);
    }
}

void QListWidgetAchievements::startDrag(Qt::DropActions supportedActions) {
    auto item = dynamic_cast<QListWidgetAchievement*>(currentItem());
    int lastItemRow = currentRow();
    if (item) {
        auto mimeData = new QMimeData ();
        mimeData->setData("application/x-qabstractitemmodeldatalist", item->_achievement->toString().toUtf8());

        auto drag = new QDrag(this);
        drag->setMimeData (mimeData);
        if (drag->exec(supportedActions, defaultDropAction()) == Qt::MoveAction) {
            if (lastItemRow > -1) {
                removeItemWidget(takeItem(lastItemRow));
            }
        }
    }
}

void QListWidgetAchievements::dropEvent(QDropEvent *event) {
    QString t = QString::fromUtf8(event->mimeData()->data("application/x-qabstractitemmodeldatalist"));
    if (!t.isEmpty()) {
        SAchievement *achievement = new SAchievement(t);
        QModelIndex dropIndex = indexAt(event->pos());
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
        event->accept();
    } else {
        event->ignore();
    }
}

void QListWidgetAchievements::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {
        event->accept();
    }
}

void QListWidgetAchievements::dragLeaveEvent(QDragLeaveEvent *event) {
    event->accept();
}
