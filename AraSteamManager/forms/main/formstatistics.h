#ifndef FORMSTATISTICS_H
#define FORMSTATISTICS_H

#include <QWidget>
#include <QPair>
#include <QtCharts>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QVXYModelMapper>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QVBarModelMapper>
#include <QtWidgets/QHeaderView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QStandardItemModel>
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/common/generalfunctions.h"
#include "classes/threads/thread/threadstatistics.h"
#include "subWidgets/items/friendlistitem.h"

//QT_CHARTS_USE_NAMESPACE

enum FormStatisticTableGamesColumns {
    StaticticGamesAppId = 0,
    StaticticGamesIndex = 1,
    StaticticGamesIcon = 2,
    StaticticGamesTitle = 3,
    StaticticGamesPercent = 4
};

namespace Ui {
class FormStatistics;
}

class FormStatistics : public Form {
    Q_OBJECT

enum class GamesType {
    none,
    complete,
    started,
    notStarted,
    noAchievements
};

public slots:
    void onFinish(Statistics &aStatistic);
    void createThread();
    void createThreadFriend(Statistics &aStatistics);
    void updateSettings(QFlags<changedSettings> aSettings) override;

public:
    explicit FormStatistics(QWidget *parent = nullptr);
    ~FormStatistics();

    void setProfile(const SProfile &aProfile);
    bool isInit();
    void clear();
signals:
    void s_finish();
    void s_return_to_profile(QWidget*);
    void s_showAchievements(const SGame &game);

protected slots:
    void init();
    void initPie();
    void initLastAchievements();
    void initGraphs();

    void setEnable(bool isEnable);
    void showTableGames(QList<GameWithPercentModelItem> aGames);
private slots:
    void resizeEvent(QResizeEvent *aEvent) override;
    bool eventFilter(QObject* pObj, QEvent* pEvent) override;
    void retranslate() override;
    void updateIcons() override;

    void setInfo(Statistics &aStatistic);
    void setLastAchievements(Statistics &aStatistic);
    void setPie(const Statistics &aStatistic);
    void setGraphs(Statistics &aStatistic);

    void movePixmapLastAchievement();
    QMenu *createMenuChartTimes(QGraphicsItem *aItem);
    QMenu *createMenuChartYears(QGraphicsItem *aItem);
    void removeFriendBar(const QString &aName, const QString &barObjectName);
    void addFriendBar(Statistics &aStatistic);
    void loadFriends();
    void addFriendToList(const SProfile &aSteamFriend, FriendListItemData::ProfileType aType);
    void addFriendToGraphs(const QModelIndex &index);
private:
    Ui::FormStatistics *ui;

    SProfile profile_;
    Statistics statistics_;

    const QList<QColor> _colors = {QColor(150, 0, 0), QColor(0, 0, 150), QColor(150, 0, 150), QColor(0, 150, 150), QColor(0, 150, 0),
                                   QColor(150, 150, 0), QColor(1, 1, 1), QColor(150, 150, 150)};
    const int c_colorCount = 8;

    QGraphicsScene *scene_ = nullptr;
    QMap<QGraphicsPixmapItem*, QPixmap> pixmapsLastAchievements_;

    bool isUserResizing_ = false;

    void getParametersForLastAchievements(int &aSize, int &aRows, int &aColumns, int &aCount);
};

#endif // FORMSTATISTICS_H
