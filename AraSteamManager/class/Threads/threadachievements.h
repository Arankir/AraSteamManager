#ifndef THREADACHIEVEMENTS_H
#define THREADACHIEVEMENTS_H

#include <QObject>
#include <QTableWidget>
#include <QLabel>
#include <class/Network/requestdata.h>
#include <class/steamapi/Sachievements.h>

class ThreadAchievements : public QObject {
    Q_OBJECT
public slots:
    int fill();
//    void set(SAchievements achievements, QTableWidget *TableWidgetAchievements);
//    bool addFriend();
//    void setFriend(QTableWidget *TableWidgetAchievements, SAchievements achievement, int col, int AcolumnAppid);

public:
    explicit ThreadAchievements(SAchievements achievements, QTableWidget *tableWidgetAchievements, const int tableColumnAppid, const int tableColumnTitle,
                                const int tableColumnDescription, const int tableColumnWorld, const int tableColumnMy, QObject *parent = nullptr);
    explicit ThreadAchievements(QObject *parent = nullptr);
    ~ThreadAchievements();

signals:
    void s_finished(int reached, int notReached);
    void s_progress(int progress, int row);
    void s_is_public(bool aPublic, int aColumn);

private:
    const int c_tableColumnAppid;
    const int c_tableColumnTitle;
    const int c_tableColumnDescription;
    const int c_tableColumnWorld;
    const int c_tableColumnMy;
    int num;
    SAchievements _achievements;
    QTableWidget *_tableWidgetAchievements;

    SAchievements _achievement;
    int _col;
    int _columnAppid;
};

#endif // THREADACHIEVEMENTS_H
