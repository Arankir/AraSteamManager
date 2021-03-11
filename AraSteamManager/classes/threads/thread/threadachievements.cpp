#include "threadachievements.h"

int ThreadAchievements::fill() {
    //QFont font(Settings::defaultFont(), 10);
    int totalReached = 0;
    int totalNotReached = 0;
    int row = 1;
    QStandardItemModel *model = new QStandardItemModel;
    model->setColumnCount(ColumnAchievementsCount);
    for (auto &achievement: _achievements) {
        QStandardItem *itemId = new QStandardItem(achievement.apiName());

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(achievement.icon(_gameAppId)), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemTitle = new QStandardItem(achievement.displayName());

        QStandardItem *itemDescription = new QStandardItem(achievement.description());

        QStandardItem *itemPercent = new QStandardItem((achievement.percent() < 10 ? "0" : "") + QString::number(achievement.percent()) + "%");

        QStandardItem *itemAchieved = new QStandardItem();
        if (achievement.achieved() == 1) {
            itemAchieved->setText(achievement.unlockTime().toString("yyyy.MM.dd hh:mm"));
            itemAchieved->setForeground(c_achievedColor);
            ++totalReached;
        } else {
            itemAchieved->setText(tr("Не получено"));
            itemAchieved->setForeground(c_notAchievedColor);
            ++totalNotReached;
        }

//        itemTitle       ->setFont(font);
//        itemDescription ->setFont(font);
//        itemPercent     ->setFont(font);
//        itemAchieved    ->setFont(font);

        itemTitle->setToolTip(achievement.displayName());
        itemDescription->setToolTip(achievement.description());

        itemPercent->setTextAlignment(Qt::AlignCenter);
        itemAchieved->setTextAlignment(Qt::AlignCenter);

        model->setItem(row, ColumnAchievementsAppid, itemId);
        model->setItem(row, ColumnAchievementsIndex, itemIndex);
        model->setItem(row, ColumnAchievementsIcon, itemIcon);
        model->setItem(row, ColumnAchievementsTitle, itemTitle);
        model->setItem(row, ColumnAchievementsDescription, itemDescription);
        //model->setItem(row, ColumnAchievementsComment, itemComment);
        model->setItem(row, ColumnAchievementsWorld, itemPercent);
        model->setItem(row, ColumnAchievementsReachedMy, itemAchieved);
        emit s_progress(row, _achievements.count());
        ++row;
    }
    emit s_finishedModel(model, totalReached, totalNotReached);
    return 1;
}
