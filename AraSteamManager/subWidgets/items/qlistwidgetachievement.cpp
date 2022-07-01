#include "qlistwidgetachievement.h"

QListWidgetAchievement::QListWidgetAchievement(const SAchievement &aAchievement): QListWidgetItem() {
    _achievement = new SAchievement(aAchievement);
}

QListWidgetAchievement::~QListWidgetAchievement() {
    delete _achievement;
}

QListWidgetAchievement &QListWidgetAchievement::operator=(const QListWidgetAchievement &aItem) {
    QListWidgetItem::operator=(aItem);
    _achievement = aItem._achievement;
    return *this;
}

bool QListWidgetAchievement::operator==(const QListWidgetAchievement &aItem) {
    return (_achievement == aItem._achievement);
}
