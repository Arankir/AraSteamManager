#ifndef CATEGORIESGAME_H
#define CATEGORIESGAME_H

#include "classes/steamApi/structures/sgames.h"

class Category {
public:
    explicit Category(SGame &game);
    explicit Category(int gameId);
    Category(const QJsonObject &category = QJsonObject());
    Category(const QString &title, const QList<QString> &achievements, const QList<Category*> &categories = QList<Category*>()):
        _title(title), _achievements(achievements), _categories(categories) {}
    Category(const Category &category):
        _parent(category._parent), _title(category._title), _achievements(category._achievements), _categories(category._categories) {}

    //operators
    Category &operator=(const Category &category);
    bool      operator==(const Category &category) const;
    bool      operator!=(const Category &category) const;
    Category *operator[](const int index) {return _categories[index];}

    //iterators
    QList<Category*>::iterator begin()          {return _categories.begin();}
    QList<Category*>::iterator end()            {return _categories.end();}

    //gets
    bool isRoot()                       const   {return _parent == nullptr;}
    QString title()                     const   {return _title;}
    QString game()                      const   {return _gameName;}
    int gameID()                        const   {return _gameId;}
    int order()                         const   {return _order;}
    QList<QString> achievementsApiName()const   {return _achievements;}
    QList<Category*> categories()       const   {return _categories;}
    Category *parent()                  const   {return _parent;}

    //sets
    Category &setTitle(const QString &title);
    Category &setAchievements(QList<QString> &achievements);
    Category &setGame(SGame game);

    //parents
    Category &updateParents();
    Category &removeFromParent();
    Category &changeParent(Category *newParent);

    //categories
    Category &addCategory(Category *category);
    bool      removeCategory(Category *category, bool isRemoveRecursively = false);
    Category &clearCategories();
    Category *findCategory(Category*);

    Category &fromJson(const QJsonObject &category);
    QJsonObject toJson()                const;  //Потом заменить на другой вид хранения данных
    Category *root();
    Category *findCategory(int order);
    int countCategories()               const;

    bool save();
    Category &update();

    friend QDebug operator<<(QDebug dbg, const Category &category) {
        dbg.nospace() << "Category(" << category.toJson() << category._parent << ")";
        return dbg.space();
    }

private:
    bool load();
    Category &setParent(Category *parent);
    Category &updateOrders(int &aOrder);

    Category *_parent = nullptr;
    QString _title;
    int _order = -1;
    QString _gameName;
    int _gameId;
    QList<QString> _achievements;
    QList<Category*> _categories;

};

#endif // CATEGORIESGAME_H
