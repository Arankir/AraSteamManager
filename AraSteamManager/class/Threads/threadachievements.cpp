#include "threadachievements.h"

ThreadAchievements::ThreadAchievements(SAchievements aAchievements, QTableWidget *aTableWidgetAchievements, const int aTableColumnAppid,
const int aTableColumnTitle, const int aTableColumnDescription, const int aTableColumnWorld, const int aTableColumnMy, QObject *aParent):
QObject(aParent), c_tableColumnAppid(aTableColumnAppid), c_tableColumnTitle(aTableColumnTitle), c_tableColumnDescription(aTableColumnDescription),
c_tableColumnWorld(aTableColumnWorld), c_tableColumnMy(aTableColumnMy), _achievements(aAchievements), _tableWidgetAchievements(aTableWidgetAchievements) {

}

ThreadAchievements::ThreadAchievements(QObject *aParent): QObject(aParent), c_tableColumnAppid(0), c_tableColumnTitle(0), c_tableColumnDescription(0),
c_tableColumnWorld(0), c_tableColumnMy(0) {

}

ThreadAchievements::~ThreadAchievements() {
    qDebug()<<"Thread deleted";
}

int ThreadAchievements::fill() {
    int totalReached = std::move(0);
    int totalNotReached = std::move(0);
    int row = std::move(0);
    for (auto &achievement: _achievements) {
        if (achievement._displayName != "") {
            _tableWidgetAchievements->setItem(row, c_tableColumnAppid, new QTableWidgetItem(achievement._apiName));
            _tableWidgetAchievements->setItem(row, c_tableColumnTitle, new QTableWidgetItem(achievement._displayName));
            _tableWidgetAchievements->setItem(row, c_tableColumnDescription, new QTableWidgetItem(achievement._description));
            _tableWidgetAchievements->setItem(row, c_tableColumnWorld, new QTableWidgetItem((achievement._percent < 10 ? "0" : "")+QString::number(achievement._percent)+"%"));
            if(achievement._achieved == 1) {
                _tableWidgetAchievements->setItem(row, c_tableColumnMy, new QTableWidgetItem(tr("Получено %1").arg(achievement._unlockTime.toString("yyyy.MM.dd hh:mm"))));
                totalReached++;
            } else {
                _tableWidgetAchievements->setItem(row, c_tableColumnMy, new QTableWidgetItem(tr("Не получено")));
                totalNotReached++;
            }
            _tableWidgetAchievements->item(row, c_tableColumnTitle)->setTextAlignment(Qt::AlignCenter);
            _tableWidgetAchievements->item(row, c_tableColumnDescription)->setTextAlignment(Qt::AlignCenter);
            _tableWidgetAchievements->item(row, c_tableColumnWorld)->setTextAlignment(Qt::AlignCenter);
            _tableWidgetAchievements->item(row, c_tableColumnMy)->setTextAlignment(Qt::AlignCenter);
            emit s_progress(row, row);
            row++;
        }
    }
    emit s_finished(totalReached, totalNotReached);
    return 1;
}

void ThreadAchievements::set(SAchievements aAchievements, QTableWidget *aTableWidgetAchievements){
    _achievements = std::move(aAchievements);
    _tableWidgetAchievements = std::move(aTableWidgetAchievements);
}

void ThreadAchievements::setFriend(QTableWidget *aTableWidgetAchievements, SAchievements aAchievement, int aCol, int aColumnAppid) {
    _achievement = std::move(aAchievement);
    _col = std::move(aCol);
    _columnAppid = std::move(aColumnAppid);
    _tableWidgetAchievements = std::move(aTableWidgetAchievements);
}

bool ThreadAchievements::addFriend(){
//TODO Переписать полностью
    int totalReach=0;
    int totalNotReach=0;
    for(int i=0;i<_tableWidgetAchievements->rowCount();i++){
        int j=0;
        bool accept=false;
        for(;j<_achievement.getCount();j++){
            if(_achievement[j]._apiName==_tableWidgetAchievements->item(i,_columnAppid)->text()){
                accept=true;
                break;
                }
        }
        if(accept){
            QTableWidgetItem *item5;
            if(_achievement[j]._achieved==1){
                item5 = new QTableWidgetItem(tr("Получено %1").arg(_achievement[j]._unlockTime.toString("yyyy.MM.dd hh:mm")));
                item5->setToolTip(_achievement[j]._unlockTime.toString("yyyy.MM.dd hh:mm"));
                totalReach++;
                } else {
                item5 = new QTableWidgetItem(tr("Не получено"));
                totalNotReach++;
                }
            item5->setTextAlignment(Qt::AlignCenter);
            _tableWidgetAchievements->setItem(i,_col,item5);
        }
        }
    if((totalReach==0)&&(totalNotReach==0)){
        _tableWidgetAchievements->setItem(1,_col, new QTableWidgetItem(QString("%1\n%2").arg(tr("Профиль не"),tr("публичный"))));
        emit s_is_public(false,_col);
        } else {
        _tableWidgetAchievements->setItem(1,_col, new QTableWidgetItem(QString("%1/%2\n%3%").arg(QString::number(totalReach),QString::number(totalReach+totalNotReach),
                                                                                                 QString::number(100.0*totalReach/(totalReach+totalNotReach)))));
        emit s_is_public(true,_col);
    }
    emit s_finished(totalReach,totalNotReach);
    return true;
}
