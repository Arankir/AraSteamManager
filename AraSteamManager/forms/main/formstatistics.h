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
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/common/generalfunctions.h"
#include "classes/threads/thread/threadstatistics.h"
#include <QStandardItemModel>

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
    explicit FormStatistics(const SProfile &profile, const SGames &games, QWidget *parent = nullptr);
    ~FormStatistics();

signals:
    void s_finish();
    void s_return_to_profile(QWidget*);
    void s_showAchievements(const SGame &game);

protected slots:
    void addFriendLines(Statistics &aStatistic);
private slots:
    void retranslate() override;
    void updateIcons() override;

    void setModelToTable(QList<GameWithPercent> aGames, bool aIsVisiblePercent);
    SGame *currentGame();
    QMenu *createMenu(SGame &aGame);
    void updateStatisticProfile(const SProfile &lProfile);
    void setInfo(Statistics &aStatistic);
    void setPie(const Statistics &aStatistic);
    void setGraphs(Statistics &aStatistic);
    void clearGraphs();

    void removeFriendLines(const SProfile &aProfile);
    void initPie();
private:
    Ui::FormStatistics *ui;
    GamesType _currentGamesType = GamesType::none;
    int _currentIndex = -1;

    SProfile _userProfile;
    SGames _games;

    SProfile _statisticProfile;
    Statistics _statistics;

    QChart *_gamePercent;

    const QList<QColor> _colors = {QColor(150, 0, 0), QColor(0, 0, 150), QColor(150, 0, 150), QColor(0, 150, 150), QColor(0, 150, 0),
                                   QColor(150, 150, 0), QColor(1, 1, 1), QColor(150, 150, 150)};

};

#endif // FORMSTATISTICS_H
