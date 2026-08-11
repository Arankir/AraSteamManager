#include "category.h"
#include "classes/common/settings.h"

#include <QMutableListIterator>

Category::Category(const SGame &aGame): Category(aGame.appId(), aGame.name(), aGame.imgIconUrl()) {

}

Category::Category(const Category &aCategory):
QSet<AchievementID>(aCategory),
FileSaveLoad(aCategory.filePath_),
parent_(aCategory.parent_),
title_(aCategory.title_),
gameId_(aCategory.gameId_),
gameName_(aCategory.gameName_),
gameIcon_(aCategory.gameIcon_) {
    QList<Category*> categories = aCategory.categories_;
    for (Category *category: categories) {
        categories_.append(new Category(*category));
    }
}

Category::Category(const GameID &aGameId, const QString &aGameName, const QString &aGameIcon, bool aAutoLoad):
QSet<AchievementID>(),
FileSaveLoad(Paths::categories(QString::number(aGameId))),
gameId_(aGameId),
gameName_(aGameName),
gameIcon_(aGameIcon) {
    if (aAutoLoad) {
        load(filePath_);
    }
//    qDebug() << 1 << title_ << categories_;
}

Category::Category(const GameID &aGameId,
                   const QString &aTitle,
                   const QSet<AchievementID> &aAchievements,
                   const QList<Category *> &aCategories):
QSet<AchievementID>(aAchievements),
FileSaveLoad(Paths::categories(QString::number(aGameId))),
title_(aTitle),
categories_(aCategories) {
    load(filePath_);
//    qDebug() << 2 << title_ << categories_;
}

Category::Category(const QJsonObject &aCategory): QSet<AchievementID>(), FileSaveLoad("") {
    fromJson(aCategory);
    filePath_ = Paths::categories(QString::number(gameId_));
}

Category::~Category() {
//    deleteAllChilds();
}

bool Category::operator==(const Category &aCategory) const {
    return parent_ == aCategory.parent_ &&
            title_ == aCategory.title_ &&
            gameId_ == aCategory.gameId_ &&
            gameName_ == aCategory.gameName_ &&
            gameIcon_ == aCategory.gameIcon_ &&
            categories_ == aCategory.categories_ &&
            filePath_ == aCategory.filePath_ &&
            QSet<AchievementID>::operator==(aCategory);
}

bool Category::operator!=(const Category &aCategory) const {
    return parent_ != aCategory.parent_ ||
            title_ != aCategory.title_ ||
            gameId_ != aCategory.gameId_ ||
            gameName_ != aCategory.gameName_ ||
            gameIcon_ != aCategory.gameIcon_ ||
            categories_ != aCategory.categories_ ||
            filePath_ != aCategory.filePath_ ||
            QSet<AchievementID>::operator!=(aCategory);
}

bool Category::isRoot() const   {
    return parent_ == nullptr;
}

QString Category::title() const   {
    return title_;
}

QString Category::gameName() const   {
    return gameName_;
}

GameID Category::gameID() const   {
    return gameId_;
}

QList<Category *> Category::categories() const   {
    return categories_;
}

Category *Category::parent() const   {
    return parent_;
}

void Category::setTitle(const QString &aTitle) {
    title_ = aTitle;
}

void Category::setGame(const SGame &aGame) {
    setGame(aGame.appId(), aGame.name(), aGame.imgIconUrl());
}

void Category::setGame(const GameID &aGameId, const QString &aGameName, const QString &aGameIcon) {
    gameId_ = aGameId;
    gameName_ = aGameName;
    gameIcon_ = aGameIcon;
    filePath_ = Paths::categories(QString::number(aGameId));
}

void Category::setParent(Category *aNewParent) {
    if (parent_ != nullptr) {
        parent_->removeCategory(title_);
    }
    aNewParent->addCategory(this);
}

int Category::getIndex(Category *aCategory) {
    if (aCategory->parent()) {
        QList<Category*> categories = aCategory->parent()->categories();
        auto iterator = std::find_if(categories.begin(),
                                     categories.end(),
                                     [=](Category *lCategory) {
                                        return lCategory == aCategory;
                                     });
        if (iterator != categories.end()) {
            return iterator - categories.begin();
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

void Category::changeCategoryIndex(const QString &aCategory, int aIndex) {
    Category *category = find(aCategory);
    if (category == nullptr) {
        return;
    }
    int oldIndex = getIndex(category);
    if (aIndex > categories_.size() - 1) {
        aIndex = categories_.size() - 1;
    }
    categories_.move(oldIndex, aIndex);
}

bool Category::addCategory(const QStringList &aTitles, Category *aCategory) {
    QString nextTitle;
    QStringList localTitles = aTitles;
    if (!localTitles.isEmpty()) {
        nextTitle = localTitles.last();
        localTitles.pop_back();
    }
    auto iterator = std::find_if(categories_.begin(),
                                 categories_.end(),
                                 [=](Category *lCategory) {
                                    return lCategory->title_ == nextTitle;
                                });
    if (aTitles.count() == 0) {
        if (iterator != categories_.end()) {
            return false;
        }
        categories_.append(aCategory);
        aCategory->parent_ = this;
        return true;
    } else {
        if (iterator != categories_.end()) {
            return (*iterator)->addCategory(localTitles, aCategory);
        }
        return false;
    }
}

bool Category::addCategory(Category *aCategory) {
    return addCategory(QStringList(), aCategory);
}

bool Category::removeCategory(const QStringList &aTitles, bool aIsDelete) {
    if (aTitles.count() == 0) {
        return false;
    }
    QStringList localTitles = aTitles;
    QString nextTitle = localTitles.last();
    localTitles.pop_back();
    auto iterator = std::find_if(categories_.begin(),
                                 categories_.end(),
                                 [=](Category *lCategory) {
        return lCategory->title_ == nextTitle;
    });
    if (iterator != categories_.end()) {
        if (aTitles.count() == 1) {
            if (aIsDelete) {
                delete (*iterator);
            }
            categories_.removeAt(iterator - categories_.begin());
            return true;
        } else {
            if (iterator != categories_.end()) {
                return (*iterator)->removeCategory(localTitles);
            }
            return false;
        }
    } else {
        return false;
    }
}

bool Category::removeCategory(const QString &aTitle, bool aIsDelete) {
    return removeCategory(QStringList{aTitle}, aIsDelete);
}

Category *Category::find(const QStringList &aTitles) {
    if (aTitles.count() == 0) {
        return this;
    }
    QStringList localTitles = aTitles;
    QString nextTitle = localTitles.last();
    localTitles.pop_back();
    auto iterator = std::find_if(categories_.begin(),
                                 categories_.end(),
                                 [=](Category *lCategory) {
        return lCategory->title_ == nextTitle;
    });
    if (iterator != categories_.end()) {
        if (aTitles.count() == 1) {
            return (*iterator);
        } else {
            if (iterator != categories_.end()) {
                return (*iterator)->find(localTitles);
            }
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

Category *Category::find(const QString &aTitle) {
    return find(QStringList{aTitle});
}

void Category::clearCategories() {
    categories_.clear();
}

void Category::fromJson(const QJsonObject &aCategory) {
    gameName_ = aCategory.value("game").toString();
    gameId_   = aCategory.value("gameID").toInt();
    gameIcon_ = aCategory.value("gameIcon").toString();
    title_  = aCategory.value("title").toString();
    QSet<AchievementID>::clear();
    for(const QJsonValue &valueAchievement: aCategory.value("achievements").toArray()) {
        insert(valueAchievement.toString());
    }
//    auto oldCategories = categories_;
//    if () {

//    }
//    categories_.clear();
    QJsonArray categoriesArray = aCategory.value("categories").toArray();
    for(const QJsonValue &valueCategory: categoriesArray) {
        auto iterator = std::find_if(categories_.begin(),
                                     categories_.end(),
                                     [&](Category *lCategory) {
                                        return lCategory->title() == valueCategory.toObject().value("title").toString();
                                     });
        if (iterator != categories_.end()) {
            (*iterator)->fromJson(valueCategory.toObject());
        } else {
            Category *category = new Category(valueCategory.toObject());
            addCategory(category);
        }
//        if (categories_.find(valueCategory.toObject().value("title").toString()) != categories_.end()) {

//        }
//        addCategory(new Category2(valueCategory.toObject()));
    }
}

QJsonObject Category::toJson() const {
    QJsonObject result;
    result["title"] = title_;
    result["gameIcon"] = gameIcon_;

    if (!gameName_.isEmpty()) {
        result["game"] = gameName_;
    }

    if (gameId_ > 0) {
        result["gameID"] = gameId_;
    }

    QJsonArray valuesAchievements;
    for(const QString &valueAchievement: *this) {
        valuesAchievements.append(valueAchievement);
    }
    result["achievements"] = valuesAchievements;

    QJsonArray valuesCategories;
    for(Category *valueCategory: categories_) {
        QJsonObject category = valueCategory->toJson();
        valuesCategories.append(category);
    }
    result["categories"] = valuesCategories;

    if (isRoot()) {
        result["version"] = "2.0";
    }

    return result;
}

Category *Category::root() {
    return parent_ == nullptr ? this : parent_->root();
}

QStringList Category::getPathFromRoot() {
    QStringList list;
    getPathFromRoot(list);
    return list;
}

void Category::getPathFromRoot(QStringList &aList) {
    if (parent_ != nullptr) {
        aList.push_back(title_);
        parent_->getPathFromRoot(aList);
    }
}

const QString &Category::gameIcon() const {
    return gameIcon_;
}

void Category::setGameIcon(const QString &newGameIcon) {
    gameIcon_ = newGameIcon;
}

int Category::countCategories() const {
    int count = std::accumulate(categories_.begin(),
                                categories_.end(),
                                categories_.count(),
                                [](int i, Category *c) {return i += c->countCategories();});
    return count;
}

void Category::update() {
    load(filePath_);
}

void Category::deleteAllCategories() {
    QList<Category*> childs = categories_;
    QMutableListIterator<Category*> cats(childs);
    while (cats.hasNext()) {
        Category *child = cats.next();
        child->deleteAllCategories();
        delete child;
    }
}
