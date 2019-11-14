#ifndef SACHIEVEMENTPERCENTAGE_H
#define SACHIEVEMENTPERCENTAGE_H

#include <QMainWindow>
#include <QObject>
#include <QJsonObject>
#include <QTextCodec>

class SAchievementPercentage : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementPercentage(QJsonObject ObjAchievement, QObject* parent = nullptr);
    SAchievementPercentage();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname() {return apiname;}
    double GetPercent() {return percent;}
    SAchievementPercentage(const SAchievementPercentage & achievement);
    SAchievementPercentage & operator=(const SAchievementPercentage & achievement);

signals:

public slots:

private:
    QString apiname="";
    double percent=0.0;
};

#endif // SACHIEVEMENTPERCENTAGE_H
