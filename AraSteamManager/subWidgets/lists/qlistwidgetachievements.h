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
    void insertAchievement(const SAchievement &aAchievement, const GameID &aGameId, int aRow = -1);

protected:
    void startDrag(Qt::DropActions supportedActions) override;
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;

private:
    void dropInsert(const SAchievement &aAchievement, int aRow, const QMap<int, QVariant> &aRoleData);
};

#endif // QLISTWIDGETACHIEVEMENTS_H
