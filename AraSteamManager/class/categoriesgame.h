#ifndef CATEGORIESGAME_H
#define CATEGORIESGAME_H

#include "class/steamapi/Sgames.h"

class Category {
public:
    Category(const QJsonObject &category = QJsonObject());
    Category(const QString &title,
             const QList<QString> &achievements,
             const QList<Category> &categories = QList<Category>())
        : _title(title),
        _achievements(achievements),
        _categories(categories) {}
    Category(const Category &category):
        _parent(category._parent),
        _title(category._title),
        _achievements(category._achievements),
        _categories(category._categories) {}

    Category &operator=(const Category &category);
    bool      operator==(const Category &category);
    Category &operator[](const int index) {return _categories[index];}

    Category &setParent(Category *parent);
    Category &setTitle(const QString &title);
    Category &setAchievements(const QList<QString> &achievements);
    Category &updateParents();

    Category &addCategory(Category &category);
    bool addSubCategory(Category &aCategory);
    bool removeCategory(Category &category);
    bool removeCategoryAtDirect(int &aIndex);

    Category &fromJson(const QJsonObject &categoryGame);
    QList<Category*> directTraversalList();

    QList<Category>::iterator begin()           {return _categories.begin();}
    QList<Category>::iterator end()             {return _categories.end();}
    QString title()                     const   {return _title;}
    QList<QString> achievements()       const   {return _achievements;}
    QList<Category> categories()        const   {return _categories;}
    Category *parent()                  const   {return _parent;}
    QJsonObject toJson()                const;  //Потом заменить на другой вид хранения данных
    int countCategories()               const;

    friend QDebug operator<<(QDebug dbg, const Category &category) {
        dbg.nospace() << "Category(" << category.toJson() << category._parent << ")";
        return dbg.space();
    }

private:

    Category *_parent = nullptr;
    QString _title;
    QList<QString> _achievements;
    QList<Category> _categories;
};

class Categories : public QObject {
    Q_OBJECT
public:
    explicit Categories(SGame &game, QObject *parent = nullptr);
    explicit Categories(QObject *parent = nullptr): QObject(parent) {}
    Categories(const Categories &categories): QObject(categories.parent()), _categories(categories._categories), _game(categories._game) {}
    Category &operator[](const int index) {return _categories[index];}

    void setGame(SGame game);
    Category *categoryAtDirect(int index);

    Categories &addCategory(const QString &title, QList<QString> achievements, const QList<Category> &categories);
    Categories &addCategory(Category &category);
    bool addSubCategory(Category &aCategory);
    bool removeCategory(Category &category);
    Categories &deleteAll();

    void save(QJsonObject categories);
    Categories &update();

    QList<Category>::iterator begin()   {return _categories.begin();}
    QList<Category>::iterator end()     {return _categories.end();}
    QString getGame()           const   {return _gameName;}
    int getGameID()             const   {return _gameId;}
    int countTopCategories()    const   {return _categories.count();}
    int countAll()              const;
    QJsonObject toJson()        const;  //Потом заменить на другой вид хранения данных

    Category takeCategoryAtDirect(int aIndex);

    friend QDebug operator<<(QDebug dbg, const Categories &categories) {
        dbg.nospace() << "Categories(" << categories.toJson() << ")";
        return dbg.space();
    }

private slots:
    void fromJson(QJsonObject _categories);
    void load();

private:
    QList<Category> _categories;
    SGame _game;

    QString _gameName;
    int _gameId;
};

#endif // CATEGORIESGAME_H
