#ifndef THREADACHIEVEMENTS_H
#define THREADACHIEVEMENTS_H

#include <QObject>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QLabel>
#include "classes/network/requestdata.h"
#include "classes/steamApi/structures/sachievements.h"

class ThreadAchievements : public QObject {
    Q_OBJECT
public slots:
    int fill();
//    void set(SAchievements achievements, QTableWidget *TableWidgetAchievements);
//    bool addFriend();
//    void setFriend(QTableWidget *TableWidgetAchievements, SAchievements achievement, int col, int AcolumnAppid);

public:
    explicit ThreadAchievements(const SAchievements &achievements, int gameAppId, const int columnAppid, const int columnIndex, const int columnIcon, const int columnTitle,
                                const int columnDescription, const int columnComment, const int columnWorld, const int columnMy, const int columnCount, QObject *parent = nullptr):
        QObject(parent), c_columnAppid(columnAppid), c_columnIndex(columnIndex), c_columnIcon(columnIcon), c_columnTitle(columnTitle), c_columnDescription(columnDescription),
        c_columnComment(columnComment), c_columnWorld(columnWorld), c_columnMy(columnMy), c_columnCount(columnCount), _gameAppId(gameAppId), _achievements(achievements) {}
    explicit ThreadAchievements(QObject *parent = nullptr): ThreadAchievements(nullptr, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, parent) {}
    ~ThreadAchievements() {qInfo() << "Thread achievements deleted";}

signals:
    void s_finished(int reached, int notReached);
    void s_progress(int progress, int row);
    void s_finishedModel(QStandardItemModel *model, int reached, int notReached);
    void s_is_public(bool aPublic, int aColumn);

private:
    const int c_columnAppid;
    const int c_columnIndex;
    const int c_columnIcon;
    const int c_columnTitle;
    const int c_columnDescription;
    const int c_columnComment;
    const int c_columnWorld;
    const int c_columnMy;
    const int c_columnCount;
    int _gameAppId;
    SAchievements _achievements;

    int _col;
    int _columnAppid;
};

#endif // THREADACHIEVEMENTS_H
