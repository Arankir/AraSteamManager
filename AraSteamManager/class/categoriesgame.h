#ifndef CATEGORIESGAME_H
#define CATEGORIESGAME_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <class/steamapi/Sgame.h>

class CategoriesGame : public QObject
{
    Q_OBJECT
public:
    explicit CategoriesGame(SGame game, QObject *parent = nullptr);
    CategoriesGame() {}

signals:

public slots:
    QList<QString> GetTitles();
    int GetCountValues() {return countValues;}
    int GetCountNoValues() {return countNoValues;}
    QString GetTitle(int index);
    int GetIsNoValues(int index);
    QJsonArray GetValues(int index);
    QJsonArray GetNoValues(int index);
    QList<QString> GetAchievementsName(int category, int value);
    QString GetGame();
    int GetGameID();
    void DeleteCategory(int index);
    void Set(SGame game);
    void Save();

private:
    QJsonDocument categories;
    SGame game;
    int countValues;
    int countNoValues;
};

#endif // CATEGORIESGAME_H
