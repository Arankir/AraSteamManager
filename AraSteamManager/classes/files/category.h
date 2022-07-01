#ifndef CATEGORY_H
#define CATEGORY_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/common/filesaveload.h"

class Category: public QSet<AchievementID>, public FileSaveLoad {
public:
    explicit Category(const SGame &game);
    explicit Category(const GameID &gameId, const QString &gameName);
    explicit Category(const GameID &gameId, const QString &title, const QSet<AchievementID> &achievements, const QList<Category *> &categories = QList<Category*>());
    explicit Category(const QJsonObject &category = QJsonObject());
    Category(const Category &category);
    virtual ~Category();

    //operators
    Category &operator=(const Category &category) = default;
    bool      operator==(const Category &category) const;
    bool      operator!=(const Category &category) const;

    //gets
    bool isRoot()                   const;
    QString title()                 const;
    QString gameName()              const;
    GameID gameID()                 const;
    QList<Category*> categories()   const;
    Category *parent()              const;

    //sets
    void setTitle(const QString &aTitle);
    void setGame(const SGame &game);
    void setGame(const GameID &gameId, const QString &gameName);

    //parents
    void setParent(Category *newParent);
    void changeCategoryIndex(QString category, int index);

    //categories
    bool addCategory(const QStringList &titles, Category *category);
    bool addCategory(Category *category);
    bool removeCategory(const QStringList &titles);
    bool removeCategory(const QString &title);
    Category *find(const QStringList &titles);
    Category *find(const QString &title);
    void clearCategories();

    void fromJson(const QJsonObject &aCategory);
    QJsonObject toJson() const;

    Category *root();
    void getPathFromRoot(QStringList &list);
    QStringList getPathFromRoot();
    int countCategories() const;
    //for destructor
    void deleteAllCategories();

    void update();

    friend QDebug operator<<(QDebug dbg, const Category &category) {
        dbg.nospace() << "Category(" << category.toJson() << "parent =" << (category.parent_ == nullptr ? "NULL" : category.parent_->title_) << ")";
        return dbg.space();
    }
    friend QDataStream &operator<<(QDataStream &stream, Category *aCategory) {
        qulonglong ptrval(*reinterpret_cast<qulonglong *>(&aCategory));
        return stream << ptrval;
    }
    friend QDataStream &operator>>(QDataStream &stream, Category *&aCategory) {
        qulonglong ptrval;
        stream >> ptrval;
        aCategory = *reinterpret_cast<Category **>(&ptrval);
        return stream;
    }

    int getIndex(Category *aCategory);
private:

    Category *parent_ = nullptr;
    QString title_;
    GameID gameId_;
    QString gameName_;
    QList<Category*> categories_;

};

#endif // CATEGORY_H
