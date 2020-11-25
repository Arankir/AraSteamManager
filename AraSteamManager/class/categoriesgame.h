#ifndef CATEGORIESGAME_H
#define CATEGORIESGAME_H

#include "class/steamapi/Sgames.h"

enum class TypeCategory {
    NoValues,
    Values
};

enum class TypeCategoryValue {
    Value,
    Category
};

class CategoryGame;

struct CategoryValue {
    QString title;
    TypeCategoryValue type;
    int order;
    QList<QString> achievements;
    CategoryGame *category;

    CategoryValue &setSubCategory(CategoryGame *category);
    CategoryValue &fromJson(QJsonObject);
    QJsonObject toJson(); //Потом заменить на другой вид хранения данных
};

class CategoryGame {
public:
    CategoryGame(const QJsonObject category);
    CategoryGame(const QString &title, const QList<QString> &achievements, const QList<CategoryGame> &categories): _title(title),
        _achievements(achievements), _categories(categories) {}
    CategoryGame(const CategoryGame &category): _title(category._title), _achievements(category._achievements),
        _categories(category._categories) {}
    CategoryGame &operator=(const CategoryGame category);
    CategoryGame &operator[](const int index) {return _categories[index];}
    CategoryGame &categoryAt(const int index) {return _categories[index];}

    CategoryGame &setTitle(const QString &title);
    CategoryGame &setAchievements(const QList<QString> achievements);
    CategoryGame &addCategory(CategoryGame *category);
    CategoryGame &removeCategory(CategoryGame *category);
    CategoryGame &updateCategory(const QString &title, QList<QString> aAchievements, const QList<CategoryGame> &aCategories);

    CategoryGame &fromJson(QJsonObject categoryGame);

    QList<CategoryGame>::iterator begin()       {return _categories.begin();}
    QList<CategoryGame>::iterator end()         {return _categories.end();}
    QList<CategoryGame>::const_iterator cbegin()      {return _categories.cbegin();}
    QList<CategoryGame>::const_iterator cend()        {return _categories.cend();}
    QJsonObject toJson()                const; //Потом заменить на другой вид хранения данных
    QString title()                     const   {return _title;}
    QList<QString> achievements()       const   {return _achievements;}
    QList<CategoryGame> categories()    const   {return _categories;}
    friend QDebug operator<<(QDebug dbg, const CategoryGame &category) {
        dbg.nospace() << "Category(" << category.toJson() << ")";
        return dbg.space();
    }

private:
    QString _title;
    QList<QString> _achievements;
    QList<CategoryGame> _categories;
};

class CategoriesGame : public QObject {
    Q_OBJECT
public:
    explicit CategoriesGame(SGame &game, QObject *parent = nullptr);
    explicit CategoriesGame(QObject *parent = nullptr): QObject(parent) {}
    CategoriesGame(const CategoriesGame &categories): QObject(categories.parent()), _categories(categories._categories), _game(categories._game) {}
    CategoryGame &operator[](const int index) {return _categories[index];}
    CategoryGame *getCategoryAtAll(int index);

    void setGame(SGame game);

    CategoriesGame &deleteCategory(int index);
    CategoriesGame &deleteAll();
    CategoriesGame &addCategory(const QString &title, QList<QString> achievements, const QList<CategoryGame> &categories);
    CategoriesGame &changeCategory(CategoryGame *category, const QString &title, QList<QString> achievements, const QList<CategoryGame> &categories);
    CategoriesGame &update();
    void save(QJsonObject aCategories);

    QList<CategoryGame>::iterator begin() {return _categories.begin();}
    QList<CategoryGame>::iterator end() {return _categories.end();}
    QString getGame()   const {return _gameName;}
    int countTopCategories()      const {return _categories.count();}
    int countAll()      const;
    int getGameID()     const {return _gameId;}

    QList<QString> getCategoriesTitles() const;

private slots:
    void fromJson(QJsonObject _categories);
    QFileInfoList getFiles(const QString &path);
    void convertOldCategories();
    void load();
    QJsonObject toJson(); //Потом заменить на другой вид хранения данных
    int countRoot(CategoryGame &aCategory) const;

private:
    QList<CategoryGame> _categories;
    SGame _game;

    QString _gameName;
    int _gameId;
};

#endif // CATEGORIESGAME_H
