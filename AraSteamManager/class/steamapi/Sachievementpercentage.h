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
    explicit SAchievementPercentage(QJsonObject ObjAchievement, QObject *parent = nullptr);
    SAchievementPercentage();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname() {return _apiName;}
    double GetPercent() {return _percent;}
    SAchievementPercentage(const SAchievementPercentage & achievement);
    SAchievementPercentage & operator=(const SAchievementPercentage & achievement);

signals:

public slots:

private:
    QString _apiName="";
    double _percent=0.0;
};

#endif // SACHIEVEMENTPERCENTAGE_H
