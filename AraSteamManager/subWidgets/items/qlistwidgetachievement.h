#ifndef QLISTWIDGETACHIEVEMENT_H
#define QLISTWIDGETACHIEVEMENT_H

#include <QListWidgetItem>
#include "class/steamapi/Sachievements.h"

class QListWidgetAchievement : public QListWidgetItem {
public:
    QListWidgetAchievement(SAchievement *achievement);
    QListWidgetAchievement(): QListWidgetItem() {}
    ~QListWidgetAchievement();

    QListWidgetAchievement &operator=(const QListWidgetAchievement&);
    bool operator==(const QListWidgetAchievement&);

    SAchievement *_achievement = nullptr;
};

#endif // QLISTWIDGETACHIEVEMENT_H
