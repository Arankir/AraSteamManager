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

namespace Ui {
class FormStatistics;
}

class FormStatistics : public QWidget {
    Q_OBJECT

public slots:
    void onFinish();
    void createThread();

    void updateSettings();
    void setIcons();
public:
    explicit FormStatistics(const SProfile &profile, QList<SGame> &games, const QString &name, QWidget *parent = nullptr);
    ~FormStatistics();

signals:
    void s_statisticsLoaded(int progress);
    void s_finish();
    void s_return_to_profile(QWidget*);

private slots:
    void changeEvent(QEvent *event);
    void retranslate();

private:
    Ui::FormStatistics *ui;
    SProfile _profile;
    QList<SGame> _games;
    QString _name;
    double _totalAverage;
    int _summColumn = 0;

    QVector<SGame> _complete;
    QVector<QPair<SGame, double>> _started;
    QVector<SGame> _notStarted;
    QVector<SGame> _noAchievements;

    QVector<int> _times = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QVector<int> _months = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QVector<QPair<QString,int>> _years;

    QChart *_gamePercent;
    QChart *_chartT;
    QChart *_chartM;
    QChart *_chartY;
};

#endif // FORMSTATISTICS_H
