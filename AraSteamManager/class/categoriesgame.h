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
    CategoriesGame & operator=(const CategoriesGame &);
    CategoriesGame(const CategoriesGame&);

signals:

public slots:
    QList<QString> GetTitles();
    QString GetTitle(int index);
    int GetIsNoValues(int index);
    QList<QString> GetValues(int category, int value);
    QJsonArray GetValues(int value);
    QList<QString> GetNoValues(int category);
    QString GetGame();
    int GetCounts() {return categories.value("Categories").toArray().size();}
    int GetGameID();
    void DeleteCategory(int index);
    void DeleteAll();
    void ChangeCategory(int category, QJsonObject newCategory);
    void Set(SGame game);
    void Save();

private:
    QJsonObject categories;
    SGame game;
};

#endif // CATEGORIESGAME_H
