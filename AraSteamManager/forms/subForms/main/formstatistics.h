#ifndef FORMSTATISTICS_H
#define FORMSTATISTICS_H

#include <QWidget>
#include <QPair>
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
#include "classes/threads/threading.h"

QT_CHARTS_USE_NAMESPACE

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

class FormStatistics : public QWidget {
    Q_OBJECT

enum class GamesType {
    none,
    complete,
    started,
    notStarted,
    noAchievements
};

public slots:
    void onFinish();
    void createThread();

    void updateSettings();
    void setIcons();
public:
    explicit FormStatistics(const SProfile &profile, QList<SGame> &games, QWidget *parent = nullptr);
    ~FormStatistics();

signals:
    void s_statisticsLoaded(int progress);
    void s_finish();
    void s_return_to_profile(QWidget*);
    void s_showAchievements(QList<SAchievementPlayer> achievements, SGame game);

private slots:
    void changeEvent(QEvent *event);
    void retranslate();

    void showCompleteGames();
    void showStartedGames();
    void showNotStartedGames();
    void showNoAchievementsGames();
    void setModelToTable(QStandardItemModel *aModel);
    SGame *currentGame();
    QMenu *createMenu(SGame &aGame);
private:
    Ui::FormStatistics *ui;
    GamesType _currentGamesType = GamesType::none;
    int _currentIndex = -1;
    SProfile _profile;
    QList<SGame> _games;
    double _summAverages;
    int _achievementCount = 0;

    QList<SGame> _complete;
    QList<QPair<SGame, double>> _started;
    QList<SGame> _notStarted;
    QList<SGame> _noAchievements;


    QVector<int> _times = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QVector<int> _months = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QVector<QPair<QString,int>> _years;

    QChart *_gamePercent;
    QChart *_chartT;
    QChart *_chartM;
    QChart *_chartY;
};

#endif // FORMSTATISTICS_H
