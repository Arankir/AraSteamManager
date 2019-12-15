#ifndef FORMSTATISTICS_H
#define FORMSTATISTICS_H

#include <QWidget>
#include <QPair>
#include <class/steamapi/Sgames.h>
#include <class/settings.h>
#include <class/steamapi/Sachievements.h>
#include <class/steamapi/Sfriends.h>
#include <class/settings.h>

namespace Ui {
class FormStatistics;
}

class FormStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit FormStatistics(QString id, SGames games, QWidget *parent = nullptr);
    ~FormStatistics();

public slots:
    void OnResultAchievements(SAchievementsPlayer ach);

private:
    //Переименовать потом
    Ui::FormStatistics *ui;
    Settings _setting;
    QString id;
    int numof[3];
    QVector<QPair<QString,QString>> complete;
    QVector<QPair<QString,QString>> started;
    QVector<QPair<QString,QString>> notStarted;
    double *averagePercent;
    int nownum;
    int summcolumn;
    int colgames;
    SGames games;
    int times[24];
    int months[12];
    int *years;
    QString *yearsTitles;
};

#endif // FORMSTATISTICS_H
