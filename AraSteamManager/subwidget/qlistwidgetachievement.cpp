#include "qlistwidgetachievement.h"

QListWidgetAchievement::QListWidgetAchievement(SAchievement *aAchievement): QListWidgetItem() {
    _achievement = aAchievement;
}

QListWidgetAchievement::~QListWidgetAchievement() {

}

QListWidgetAchievement &QListWidgetAchievement::operator=(const QListWidgetAchievement &aItem) {
    QListWidgetItem::operator=(aItem);
    _achievement = aItem._achievement;
    return *this;
}

bool QListWidgetAchievement::operator==(const QListWidgetAchievement &aItem) {
    return (_achievement == aItem._achievement);
}
