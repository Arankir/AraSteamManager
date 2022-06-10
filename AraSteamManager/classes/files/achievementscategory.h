#ifndef CATEGORIESGAME_H
#define CATEGORIESGAME_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/common/filesaveload.h"

//class Category {
//public:
//    explicit Category(const SGame &game);
//    explicit Category(const int &gameId);
//    explicit Category(const QJsonObject &category = QJsonObject());
//    explicit Category(const QString &title, const QList<QString> &achievements, const QList<Category*> &categories = QList<Category*>()):
//        _title(title), _achievements(achievements), _categories(categories) {

//    }
//    Category(const Category &category):
//        _parent(category._parent), _title(category._title), _achievements(category._achievements), _categories(category._categories) {

//    }

//    //operators
//    Category &operator=(const Category &category);
//    bool      operator==(Category &category);
//    bool      operator!=(Category &category);
//    Category *operator[](const int index) {return _categories[index];}

//    //iterators
//    QList<Category*>::iterator begin()          {return _categories.begin();}
//    QList<Category*>::iterator end()            {return _categories.end();}

//    //gets
//    bool isRoot()                               const   {
//        return _parent == nullptr;
//    }
//    QString title()                             const   {
//        return _title;
//    }
//    QString game()                              const   {
//        return _gameName;
//    }
//    int gameID()                                const   {
//        return _gameId;
//    }
//    int order()                                 const   {
//        return _order;
//    }
//    QList<AchievementID> achievementsApiName()  const   {
//        return _achievements;
//    }
//    QList<Category*> categories()               const   {
//        return _categories;
//    }
//    Category *parent()                          const   {
//        return _parent;
//    }

//    //sets
//    Category &setTitle(const QString &title);
//    Category &setAchievements(const QList<AchievementID> &achievements);
//    Category &setGame(const SGame &game);

//    //parents
//    Category &updateParents();
//    Category &removeFromParent();
//    Category &changeParent(Category *newParent);

//    //categories
//    Category &addCategory(Category *category);
//    bool      removeCategory(Category *category, const bool &isRemoveRecursively = false);
//    Category &clearCategories();
//    Category *findCategory(Category*) const;

//    void fromJson(const QJsonObject &category);
//    QJsonObject toJson() const;
//    Category *root();
//    Category *findCategory(const int &order) const;
//    int countCategories() const;

//    bool save() const;
//    Category &update();

//    friend QDebug operator<<(QDebug dbg, const Category &category) {
//        dbg.nospace() << "Category(" << category.toJson() << category._parent << ")";
//        return dbg.space();
//    }

//private:
//    bool load();
//    Category &setParent(Category *parent);
//    Category &updateOrders(int &aOrder);

//    Category *_parent = nullptr;
//    QString _title;
//    int _order = -1;
//    QString _gameName;
//    GameID _gameId;
//    QList<AchievementID> _achievements;
//    QList<Category*> _categories;

//};

class Category2: public QSet<AchievementID>, public FileSaveLoad {
public:
    explicit Category2(const SGame &game);
    explicit Category2(const GameID &gameId, const QString &gameName);
    explicit Category2(const GameID &gameId, const QString &title, const QSet<AchievementID> &achievements, const QList<Category2 *> &categories = QList<Category2*>());
    explicit Category2(const QJsonObject &category = QJsonObject());
    Category2(const Category2 &category);
    virtual ~Category2();

    //operators
    Category2 &operator=(const Category2 &category) = default;
    bool      operator==(const Category2 &category) const;
    bool      operator!=(const Category2 &category) const;

    //gets
    bool isRoot()                   const;
    QString title()                 const;
    QString gameName()              const;
    GameID gameID()                 const;
    QList<Category2*> categories()  const;
    Category2 *parent()             const;

    //sets
    void setTitle(const QString &aTitle);
    void setGame(const SGame &game);
    void setGame(const GameID &gameId, const QString &gameName);

    //parents
    void setParent(Category2 *newParent);

    //categories
    bool addCategory(const QStringList &titles, Category2 *category);
    bool addCategory(Category2 *category);
    bool removeCategory(const QStringList &titles);
    bool removeCategory(const QString &title);
    Category2 *find(const QStringList &titles);
    Category2 *find(const QString &title);
    void clearCategories();

    void fromJson(const QJsonObject &aCategory);
    QJsonObject toJson() const;

    Category2 *root();
    void getPathFromRoot(QStringList &list);
    int countCategories() const;

    void update();

    friend QDebug operator<<(QDebug dbg, const Category2 &category) {
        dbg.nospace() << "Category(" << category.toJson() << "parent =" << (category.parent_ == nullptr ? "NULL" : category.parent_->title_) << ")";
        return dbg.space();
    }

private:
    //for destructor
    void deleteAllChilds();

    Category2 *parent_ = nullptr;
    QString title_;
    GameID gameId_;
    QString gameName_;
    QList<Category2*> categories_;

};

#endif // CATEGORIESGAME_H
