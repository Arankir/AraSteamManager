#include "threadachievements.h"

const QColor achievedColor      = QColor(0, 255, 0);
const QColor notAchievedColor   = QColor(255, 0, 0);

int ThreadAchievements::fill() {
    //icon
    //Title
    //Description
    //Comment
    //Percent
    //Achieved
    QFont font(Settings::getFontDefaultName(), 10);
    int totalReached = 0;
    int totalNotReached = 0;
    int row = 1;
    QStandardItemModel *model = new QStandardItemModel;
    model->setColumnCount(c_columnCount);
    for (auto &achievement: _achievements) {
        QStandardItem *itemId = new QStandardItem(achievement._apiName);

        QStandardItem *itemIndex = new QStandardItem(QString::number(row));

        QStandardItem *itemIcon = new QStandardItem();
        itemIcon->setData(QVariant(achievement.getIcon(_gameAppId)), Qt::DecorationRole);
        itemIcon->setFlags(Qt::ItemFlag::ItemIsEnabled);

        QStandardItem *itemTitle = new QStandardItem(achievement._displayName);

        QStandardItem *itemDescription = new QStandardItem(achievement._description);

        QStandardItem *itemPercent = new QStandardItem((achievement._percent < 10 ? "0" : "") + QString::number(achievement._percent) + "%");

        QStandardItem *itemAchieved = new QStandardItem();
        if (achievement._achieved == 1) {
            itemAchieved->setText(achievement._unlockTime.toString("yyyy.MM.dd hh:mm"));
            itemAchieved->setForeground(achievedColor);
            ++totalReached;
        } else {
            itemAchieved->setText(tr("Не получено"));
            itemAchieved->setForeground(notAchievedColor);
            ++totalNotReached;
        }

        itemTitle       ->setFont(font);
        itemDescription ->setFont(font);
        itemPercent     ->setFont(font);
        itemAchieved    ->setFont(font);

        model->setItem(row, c_columnAppid, itemId);
        model->setItem(row, c_columnIndex, itemIndex);
        model->setItem(row, c_columnIcon, itemIcon);
        model->setItem(row, c_columnTitle, itemTitle);
        model->setItem(row, c_columnDescription, itemDescription);
        //model->setItem(row, c_tableColumnComment, itemComment);
        model->setItem(row, c_columnWorld, itemPercent);
        model->setItem(row, c_columnMy, itemAchieved);
        emit s_progress(row, row);
        ++row;
    }
    emit s_finishedModel(model, totalReached, totalNotReached);
    return 1;

//    int totalReached = 0;
//    int totalNotReached = 0;
//    int row = 0;
//    for (auto &achievement: *_achievements) {
//        if (achievement._displayName != "") {
//            emit s_progress(row, row);
//            _tableWidgetAchievements->setItem(row, c_tableColumnAppid,          new QTableWidgetItem(achievement._apiName));
//            _tableWidgetAchievements->setItem(row, c_tableColumnTitle,          new QTableWidgetItem(achievement._displayName));
//            _tableWidgetAchievements->setItem(row, c_tableColumnDescription,    new QTableWidgetItem(achievement._description));
//            _tableWidgetAchievements->setItem(row, c_tableColumnWorld,          new QTableWidgetItem((achievement._percent < 10 ? "0" : "") + QString::number(achievement._percent) + "%"));
//            if(achievement._achieved == 1) {
//                _tableWidgetAchievements->setItem(row, c_tableColumnMy, new QTableWidgetItem(tr("Получено %1").arg(achievement._unlockTime.toString("yyyy.MM.dd hh:mm"))));
//                ++totalReached;
//            } else {
//                _tableWidgetAchievements->setItem(row, c_tableColumnMy, new QTableWidgetItem(tr("Не получено")));
//                ++totalNotReached;
//            }
//            _tableWidgetAchievements->item(row, c_tableColumnTitle)         ->setTextAlignment(Qt::AlignCenter);
//            _tableWidgetAchievements->item(row, c_tableColumnDescription)   ->setTextAlignment(Qt::AlignCenter);
//            _tableWidgetAchievements->item(row, c_tableColumnWorld)         ->setTextAlignment(Qt::AlignCenter);
//            _tableWidgetAchievements->item(row, c_tableColumnMy)            ->setTextAlignment(Qt::AlignCenter);
//            ++row;
//        }
//    }
//    emit s_finished(totalReached, totalNotReached);
//    return 1;
}

//void ThreadAchievements::set(SAchievements aAchievements, QTableWidget *aTableWidgetAchievements){
//    _achievements = std::move(aAchievements);
//    _tableWidgetAchievements = std::move(aTableWidgetAchievements);
//}

//void ThreadAchievements::setFriend(QTableWidget *aTableWidgetAchievements, SAchievements aAchievement, int aCol, int aColumnAppid) {
//    _achievement = std::move(aAchievement);
//    _col = std::move(aCol);
//    _columnAppid = std::move(aColumnAppid);
//    _tableWidgetAchievements = std::move(aTableWidgetAchievements);
//}

//bool ThreadAchievements::addFriend(){
////TODO Переписать полностью
//    int totalReach = 0;
//    int totalNotReach = 0;
//    for(int i = 0; i < _tableWidgetAchievements->rowCount(); i++) {
//        int j = 0;
//        bool accept = false;
//        for(; j < _achievement.getCount(); j++) {
//            if(_achievement[j]._apiName == _tableWidgetAchievements->item(i, _columnAppid)->text()) {
//                accept = true;
//                break;
//                }
//        }
//        if(accept) {
//            QTableWidgetItem *item5;
//            if(_achievement[j]._achieved==1) {
//                item5 = new QTableWidgetItem(tr("Получено %1").arg(_achievement[j]._unlockTime.toString("yyyy.MM.dd hh:mm")));
//                item5->setToolTip(_achievement[j]._unlockTime.toString("yyyy.MM.dd hh:mm"));
//                totalReach++;
//                } else {
//                item5 = new QTableWidgetItem(tr("Не получено"));
//                totalNotReach++;
//                }
//            item5->setTextAlignment(Qt::AlignCenter);
//            _tableWidgetAchievements->setItem(i, _col, item5);
//        }
//        }
//    if((totalReach == 0) && (totalNotReach == 0)) {
//        _tableWidgetAchievements->setItem(1, _col, new QTableWidgetItem(QString("%1\n%2").arg(tr("Профиль не"),tr("публичный"))));
//        emit s_is_public(false, _col);
//    } else {
//        _tableWidgetAchievements->setItem(1, _col, new QTableWidgetItem(QString("%1/%2\n%3%").arg(QString::number(totalReach),QString::number(totalReach+totalNotReach),
//                                                                                                 QString::number(100.0*totalReach/(totalReach+totalNotReach)))));
//        emit s_is_public(true, _col);
//    }
//    emit s_finished(totalReach,totalNotReach);
//    return true;
//}
