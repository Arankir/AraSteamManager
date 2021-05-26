#include "threadachievements.h"
#include "classes/common/generalfunctions.h"

int ThreadAchievements::fill() {
    //QFont font(Settings::defaultFont(), 10);
    int totalReached = 0;
    int totalNotReached = 0;
    int row = 1;
    createDir(Paths::imagesAchievements(QString::number(_gameAppId)));
    QStandardItemModel *model = new QStandardItemModel;
    model->setColumnCount(AchievementCount);
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
            itemAchieved->setText(achievement.unlockTime().toString(Settings::dateTimeFormatShort()));
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

        itemTitle->setToolTip(textToToolTip(achievement.displayName()));
        itemDescription->setToolTip(textToToolTip(achievement.description()));

        itemPercent->setTextAlignment(Qt::AlignCenter);
        itemAchieved->setTextAlignment(Qt::AlignCenter);

        model->setItem(row, AchievementAppid, itemId);
        model->setItem(row, AchievementIndex, itemIndex);
        model->setItem(row, AchievementIcon, itemIcon);
        model->setItem(row, AchievementTitle, itemTitle);
        model->setItem(row, AchievementDescription, itemDescription);
        //model->setItem(row, FormAchievementsData::ColumnComment, itemComment);
        model->setItem(row, AchievementWorld, itemPercent);
        model->setItem(row, AchievementReachedMy, itemAchieved);
        emit s_progress(row, _achievements.count());
        ++row;
    }
    emit s_finishedModel(model, totalReached, totalNotReached);
    emit s_finished();
    return 1;
}
