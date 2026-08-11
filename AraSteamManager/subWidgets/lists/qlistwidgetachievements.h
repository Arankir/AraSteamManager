#ifndef QLISTWIDGETACHIEVEMENTS_H
#define QLISTWIDGETACHIEVEMENTS_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QDrag>
#include <QDropEvent>
#include <QMimeData>
#include "subWidgets/items/qlistwidgetachievement.h"
#include "classes/steamApi/structures/sgames.h"

class QListWidgetAchievements : public QListWidget {
    Q_OBJECT
public:
    QListWidgetAchievements(QWidget *parent = nullptr);
    void insertAchievement(const SAchievement &achievement, const GameID &gameId, int row = -1);

protected:
    void startDrag(Qt::DropActions supportedActions) override;
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;

private:
    void dropInsert(const SAchievement &achievement, int row, const QMap<int, QVariant> &roleData);
};

#endif // QLISTWIDGETACHIEVEMENTS_H
