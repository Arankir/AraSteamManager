#include "threadachievements.h"

int ThreadAchievements::fill() {
    //QFont font(Settings::defaultFont(), 10);
    int totalReached = 0;
    int totalNotReached = 0;
    int row = 1;
    QStandardItemModel *model = new QStandardItemModel;
    model->setColumnCount(c_columnCount);
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

        model->setItem(row, c_columnAppid, itemId);
        model->setItem(row, c_columnIndex, itemIndex);
        model->setItem(row, c_columnIcon, itemIcon);
        model->setItem(row, c_columnTitle, itemTitle);
        model->setItem(row, c_columnDescription, itemDescription);
        //model->setItem(row, c_tableColumnComment, itemComment);
        model->setItem(row, c_columnWorld, itemPercent);
        model->setItem(row, c_columnMy, itemAchieved);
        emit s_progress(row, _achievements.count());
        ++row;
    }
    emit s_finishedModel(model, totalReached, totalNotReached);
    return 1;
}
