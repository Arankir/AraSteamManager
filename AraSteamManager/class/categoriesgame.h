#ifndef CATEGORIESGAME_H
#define CATEGORIESGAME_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <class/settings.h>
#include <class/steamapi/Sgames.h>

class CategoriesGame : public QObject
{
    Q_OBJECT
public:
    explicit CategoriesGame(SGame game, QObject *parent = nullptr);
    //CategoriesGame & operator=(const CategoriesGame &);
    CategoriesGame(const CategoriesGame &categories): QObject(categories.parent()), _categories(categories._categories), _game(categories._game){};

signals:

public slots:
    QString GetTitle(int a_index) {return _categories.value("Categories").toArray().at(a_index).toObject().value("Title").toString();}
    int GetIsNoValues(int a_index) {return _categories.value("Categories").toArray().at(a_index).toObject().value("IsNoValues").toInt();}
    QJsonArray GetValues(int a_value) {return _categories.value("Categories").toArray().at(a_value).toObject().value("Values").toArray();}
    QString GetGame() {return _categories.value("Game").toString();}
    int GetCount() {return _categories.value("Categories").toArray().size();}
    int GetGameID() {return _categories.value("GameID").toInt();}
    QList<QString> GetTitles();
    QList<QString> GetValues(int category, int value);
    QList<QString> GetNoValues(int category);
    void DeleteCategory(int index);
    void DeleteAll();
    void ChangeCategory(int category, QJsonObject newCategory);
    void Update();
    void Save();

private:
    QFileInfoList GetFiles(QString path);
    void ConvertOldCategories();
    void LoadCategories();

    QJsonObject _categories;
    Settings _setting;
    SGame _game;
};

#endif // CATEGORIESGAME_H
