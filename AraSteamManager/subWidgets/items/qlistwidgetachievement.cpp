#include "qlistwidgetachievement.h"

QListWidgetAchievement::QListWidgetAchievement(const SAchievement &aAchievement): QListWidgetItem() {
    achievement_ = new SAchievement(aAchievement);
}

QListWidgetAchievement::~QListWidgetAchievement() {
    delete achievement_;
}

QListWidgetAchievement &QListWidgetAchievement::operator=(const QListWidgetAchievement &aItem) {
    QListWidgetItem::operator=(aItem);
    achievement_ = aItem.achievement_;
    return *this;
}

bool QListWidgetAchievement::operator==(const QListWidgetAchievement &aItem) {
    return (achievement_ == aItem.achievement_);
}
