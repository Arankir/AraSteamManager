#ifndef CATEGORIESGAME_H
#define CATEGORIESGAME_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
//#include "class/settings.h"
#include "class/steamapi/Sgames.h"

struct CategoryValue {
    QString title;
    QList<QString> achievements;

    CategoryValue &fromJson(QJsonObject);
    QJsonObject toJson(); //Потом заменить на другой вид хранения данных
};

class CategoryGame {
public:
    CategoryGame(const QJsonObject category);
    CategoryGame(const QString &title, int isNoValue, QList<CategoryValue> &values, QList<QString> &noValues): _isNoValue(isNoValue), _noValues(noValues), _title(title), _values(values) {}
    CategoryGame(const CategoryGame &category): _isNoValue(category._isNoValue), _noValues(category._noValues), _title(category._title), _values(category._values) {}
    CategoryGame &operator=(const CategoryGame category);

    CategoryGame &updateCategory(const QString &title, int isNoValue, QList<CategoryValue> &values, QList<QString> &noValues);

    CategoryGame &fromJson(QJsonObject categoryGame);
    QJsonObject toJson() const; //Потом заменить на другой вид хранения данных
    QList<QString> getNoValues() const {return _noValues;}
    QString getTitle() const {return _title;}
    int getIsNoValue() const {return _isNoValue;}
    int getIndex() const {return _index;}
    QList<CategoryValue> getValues() const {return _values;}
    friend QDebug operator<<(QDebug dbg, const CategoryGame &category) {
        dbg.nospace() << "Category(" << category.toJson() << ")";
        return dbg.space();
    }

private:
    int _isNoValue;
    QList<QString> _noValues;
    QString _title;
    QList<CategoryValue> _values;
    int _index;
};

class CategoriesGame : public QObject {
    Q_OBJECT
public:
    explicit CategoriesGame(SGame &game, QObject *parent = nullptr);
    CategoriesGame(const CategoriesGame &categories): QObject(categories.parent()), _categories(categories._categories), _game(categories._game) {}
    CategoryGame &operator[](const int index) {return _categories[index];}

    CategoriesGame &deleteCategory(int index);
    CategoriesGame &deleteAll();
    CategoriesGame &changeCategory(int category, const QString &title, int isNoValue, QList<CategoryValue> &values, QList<QString> &noValues);
    CategoriesGame &update();
    void save(QJsonObject aCategories);

    QList<CategoryGame>::iterator begin() {return _categories.begin();}
    QList<CategoryGame>::iterator end() {return _categories.end();}
    QString getGame()   const {return _gameName;}
    int getCount()      const {return _categories.count();}
    int getGameID()     const {return _gameId;}

    QList<QString> getCategoriesTitles() const;

private slots:
    void fromJson(QJsonObject _categories);
    QFileInfoList getFiles(const QString &path);
    void convertOldCategories();
    void load();
    QJsonObject toJson(); //Потом заменить на другой вид хранения данных

private:
    QList<CategoryGame> _categories;
    SGame _game;

    QString _gameName;
    int _gameId;
};

#endif // CATEGORIESGAME_H
