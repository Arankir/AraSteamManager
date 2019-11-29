#ifndef SACHIEVEMENTGLOBAL_H
#define SACHIEVEMENTGLOBAL_H

#include <QMainWindow>
#include <QObject>
#include <QJsonObject>
#include <QTextCodec>
#include <QDebug>

class SAchievementGlobal : public QObject
{
    Q_OBJECT
public:
    explicit SAchievementGlobal(QJsonObject ObjAchievement, QObject *parent = nullptr);
    SAchievementGlobal();
    void Set(QJsonObject ObjAchievement);
    QString GetApiname() {return apiname;}
    int GetDefaultvalue() {return defaultvalue;}
    QString GetDisplayname() {return displayname;}
    int GetHidden() {return hidden;}
    QString GetDescription() {return description;}
    QString GetIcon() {return icon;}
    QString GetIcongray() {return icongray;}
    SAchievementGlobal(const SAchievementGlobal &);
    SAchievementGlobal & operator=(const SAchievementGlobal & achievement);

signals:

public slots:

private:
    QString apiname="";
    int defaultvalue=0;
    QString displayname="";
    int hidden=0;
    QString description="";
    QString icon="";
    QString icongray="";
};

#endif // SACHIEVEMENTGLOBAL_H
