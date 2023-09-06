#ifndef FORMSTATISTICS_H
#define FORMSTATISTICS_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QChartView>
#include "classes/threads/thread/threadstatistics.h"
#include "subWidgets/items/friendlistitem.h"
#include "form.h"

namespace Ui {
class FormStatistics;
}

class FormStatistics : public Form {
    Q_OBJECT

public slots:
    void onFinish(Statistics &statistic);
    void createThread();
    void createThreadFriend(Statistics &statistics);
    void updateSettings(QFlags<changedSettings> settings) override;

public:
    explicit FormStatistics(QWidget *parent = nullptr);
    ~FormStatistics();

    void setProfile(const SProfile &profile);
    bool isInit();
    void clear();
signals:
    void s_finish(int width);
    void s_showAchievements(const SGame &game);

protected slots:
    void init();
    void initPie();
    void initLastAchievements();
    void initGraphs();

    void setEnable(bool isEnable);
    void showTableGames(QList<GameWithPercentModelItem> games);
private slots:
    void resizeEvent(QResizeEvent *event) override;
    bool eventFilter(QObject *object, QEvent *event) override;
    void retranslate() override;
    void updateIcons() override;

    void setInfo(const Statistics &statistic);
    void setLastAchievements(const Statistics &statistic);
    void setPie(const Statistics &statistic);
    void setGraphs(const Statistics &statistic);

    void movePixmapLastAchievement();
    QMenu *createMenuChart(QChartView *view, QGraphicsItem *item);
    void removeFriendBar(const QString &name, const QString &barObjectName);
    void addFriendBar(const Statistics &statistic);
    void loadFriends();
    void addFriendToList(const SProfile &profile, const FriendListItemData::ProfileType &type);
    void addFriendToGraphs(const QModelIndex &index);
private:
    Ui::FormStatistics *ui;

    SProfile profile_;
    Statistics statistics_;

    QGraphicsScene *scene_ = nullptr;

    bool isUserResizing_ = false;
};

#endif // FORMSTATISTICS_H
