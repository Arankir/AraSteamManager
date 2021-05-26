#ifndef CATEGORIESGAME_H
#define CATEGORIESGAME_H

#include "classes/steamApi/structures/sgames.h"

class Category {
public:
    explicit Category(const SGame &game);
    explicit Category(const int &gameId);
    explicit Category(const QJsonObject &category = QJsonObject());
    explicit Category(const QString &title, const QList<QString> &achievements, const QList<Category*> &categories = QList<Category*>()):
        _title(title), _achievements(achievements), _categories(categories) {}
    Category(const Category &category):
        _parent(category._parent), _title(category._title), _achievements(category._achievements), _categories(category._categories) {}

    //operators
    Category &operator=(const Category &category);
    bool      operator==(Category &category);
    bool      operator!=(Category &category);
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
    Category &setAchievements(const QList<QString> &achievements);
    Category &setGame(const SGame &game);

    //parents
    Category &updateParents();
    Category &removeFromParent();
    Category &changeParent(Category *newParent);

    //categories
    Category &addCategory(Category *category);
    bool      removeCategory(Category *category, const bool &isRemoveRecursively = false);
    Category &clearCategories();
    Category *findCategory(Category*) const;

    Category &fromJson(const QJsonObject &category);
    QJsonObject toJson() const;  //Потом заменить на другой вид хранения данных
    Category *root();
    Category *findCategory(const int &order) const;
    int countCategories() const;

    bool save() const;
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
