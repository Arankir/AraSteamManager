#ifndef QLISTWIDGETACHIEVEMENT_H
#define QLISTWIDGETACHIEVEMENT_H

#include <QListWidgetItem>
#include "classes/steamApi/structures/sachievements.h"

class QListWidgetFriend : public QListWidgetItem {
public:
    QListWidgetFriend(SAchievement *achievement);
    QListWidgetFriend(): QListWidgetItem() {}
    ~QListWidgetFriend();

    QListWidgetFriend &operator=(const QListWidgetFriend&);
    bool operator==(const QListWidgetFriend&);

    SAchievement *_achievement = nullptr;
};

#endif // QLISTWIDGETACHIEVEMENT_H
