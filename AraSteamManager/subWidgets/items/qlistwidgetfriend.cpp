#include "qlistwidgetfriend.h"

QListWidgetFriend::QListWidgetFriend(SAchievement *aAchievement): QListWidgetItem() {
    _achievement = aAchievement;
}

QListWidgetFriend::~QListWidgetFriend() {

}

QListWidgetFriend &QListWidgetFriend::operator=(const QListWidgetFriend &aItem) {
    QListWidgetItem::operator=(aItem);
    _achievement = aItem._achievement;
    return *this;
}

bool QListWidgetFriend::operator==(const QListWidgetFriend &aItem) {
    return (_achievement == aItem._achievement);
}
