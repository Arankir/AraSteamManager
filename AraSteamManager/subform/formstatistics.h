#ifndef FORMSTATISTICS_H
#define FORMSTATISTICS_H

#include <QWidget>
#include <class/steamapi/Sgames.h>
#include <class/settings.h>
#include <class/steamapi/Sachievements.h>
#include <class/steamapi/Sfriends.h>

namespace Ui {
class FormStatistics;
}

class FormStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit FormStatistics(QString key, QString id, SGames games, QWidget *parent = nullptr);
    ~FormStatistics();

public slots:
    void OnResultAchievements(SAchievementsPlayer ach);

private:
    Ui::FormStatistics *ui;
    QString key;
    QString id;
    SGames games;
    int times[24];
    int months[12];
    int *years;
    QString *yearsTitles;
};

#endif // FORMSTATISTICS_H
