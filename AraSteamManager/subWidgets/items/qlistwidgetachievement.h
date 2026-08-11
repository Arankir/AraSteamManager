#ifndef QLISTWIDGETACHIEVEMENT_H
#define QLISTWIDGETACHIEVEMENT_H

#include <QListWidgetItem>
#include "classes/steamApi/structures/sachievements.h"

class QListWidgetAchievement : public QListWidgetItem {
public:
    QListWidgetAchievement(const SAchievement &achievement);
    QListWidgetAchievement(): QListWidgetItem() {}
    ~QListWidgetAchievement();

    QListWidgetAchievement &operator=(const QListWidgetAchievement&);
    bool operator==(const QListWidgetAchievement&);

    SAchievement *achievement_ = nullptr;
};

#endif // QLISTWIDGETACHIEVEMENT_H
