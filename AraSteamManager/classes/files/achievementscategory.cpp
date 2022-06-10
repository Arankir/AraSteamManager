#include "achievementscategory.h"

//TODO удалить, когда отнаследуюсь от FileSaveLoad
//#include <QJsonDocument>
//#include <QJsonObject>
//#include <QJsonArray>

//Category::Category(const SGame &aGame): _gameName(aGame.name()), _gameId(aGame.appId()) {
//    update();
//}

//Category::Category(const int &aGameId): _gameId(aGameId) {
//    update();
//}

//Category::Category(const QJsonObject &aCategory) {
//    fromJson(aCategory);
//    int order = 0;
//    updateOrders(order);
//}

//Category &Category::operator=(const Category &aCategory) {
//    _title          = aCategory._title;
//    _achievements   = aCategory._achievements;
//    _categories     = aCategory._categories;
//    _parent         = aCategory._parent;
//    return *this;
//}

//bool isListsEqual(const QList<Category*> &aList1, const QList<Category*> &aList2) {
//    if (aList1.count() != aList2.count()) {
//        return false;
//    }
//    for(auto iterList1 = aList1.begin(), iterList2 = aList2.begin();
//             iterList1 != aList1.end() || iterList2 != aList2.end();
//             ++iterList1, ++iterList2) {
//        if ((*iterList1)->title() != (*iterList2)->title() ||
//            (*iterList1)->achievementsApiName() != (*iterList2)->achievementsApiName()) {
//            return false;
//        }
//    }
//    return true;
//}

//bool Category::operator==(Category &aCategory) {
//    bool isRootEqually = (root()->_title == aCategory.root()->_title) && (root()->_achievements == aCategory.root()->_achievements);
//    bool isItemEqually = (_title == aCategory._title) && (_achievements == aCategory._achievements);
//    bool isListsEqually = isListsEqual(root()->_categories, aCategory.root()->_categories);
//    return (isRootEqually && isItemEqually && isListsEqually);
//}

//bool Category::operator!=(Category &aCategory) {
//    bool isRootEqually = (root()->_title == aCategory.root()->_title) && (root()->_achievements == aCategory.root()->_achievements);
//    bool isItemEqually = (_title == aCategory._title) && (_achievements == aCategory._achievements);
//    bool isListsEqually = isListsEqual(root()->_categories, aCategory.root()->_categories);
//    return (!isRootEqually || !isItemEqually || !isListsEqually);
//}

//Category &Category::setParent(Category *aParent) {
//    _parent = aParent;
//    return *this;
//}

//Category &Category::setTitle(const QString &aTitle) {
//    _title = aTitle;
//    return *this;
//}

//Category &Category::setAchievements(const QList<AchievementID> &aAchievements) {
//    _achievements = aAchievements;
//    return *this;
//}

//Category &Category::setGame(const SGame &aGame) {
//    _gameName = aGame.name();
//    _gameId = aGame.appId();
//    update();
//    return *this;
//}

//Category *Category::findCategory(Category *aFindCategory) const {
//    auto iterator = std::find_if(   _categories.begin(),
//                                    _categories.end(),
//                                    [=](Category *aCategory) { return *aCategory == *aFindCategory; });
//    if (iterator != _categories.end()) {
//        return *iterator;
//    } else {
//        for (auto &category: _categories) {
//            Category *find = category->findCategory(aFindCategory);
//            if (find != nullptr) {
//                return find;
//            }
//        }
//    }
//    return nullptr;
//}

//Category *Category::findCategory(const int &aOrder) const {
//    auto iterator = std::find_if(   _categories.begin(),
//                                    _categories.end(),
//                                    [=](Category *aCategory) { return aCategory->order() == aOrder; });
//    if (iterator != _categories.end()) {
//        return *iterator;
//    } else {
//        for (auto &category: _categories) {
//            Category *find = category->findCategory(aOrder);
//            if (find != nullptr) {
//                return find;
//            }
//        }
//    }
//    return nullptr;
//}

//Category &Category::addCategory(Category *aCategory) {
//    _categories.append(aCategory);
//    aCategory->setParent(this);
//    int order = 0;
//    root()->updateOrders(order);
////    updateParents();
//    return *this;
//}

//Category &Category::clearCategories() {
//    _categories.clear();
//    return *this;
//}

//bool Category::removeCategory(Category *aCategory, const bool &isRemoveRecursively) {
//    auto iterator = std::find_if(_categories.begin(),
//                                 _categories.end(),
//                                 [=](const Category *subCategory) {
//                                    return subCategory == aCategory;
//                                 });
//    if (iterator != _categories.end()) {
//        aCategory->setParent(nullptr);
//        _categories.removeAt(iterator - _categories.begin());
//        int order = 0;
//        root()->updateOrders(order);
//        root()->save();
//        return true;
//    } else {
//        if (isRemoveRecursively) {
//            for (auto &category: _categories) {
//                if (category->removeCategory(aCategory, true)) {
//                    return true;
//                }
//            }
//        }
//    }
//    return false;
//}

//int Category::countCategories() const {
//    int count = std::accumulate(_categories.begin(),
//                                _categories.end(),
//                                _categories.count(),
//                                [](int i, Category *c) {return i += c->countCategories();});
//    return count;
//}

//bool Category::save() const {
//    if (_gameId > 0) {
//        saveFile(Paths::categories(QString::number(_gameId)), QJsonDocument(toJson()).toJson());
//        return true;
//    }
//    return false;
//}

//Category &Category::update() {
//    load();
//    return *this;
//}

//bool Category::load() {
//    QByteArray bytes;
//    if (!readFile(Paths::categories(QString::number(_gameId)), bytes)) {
//        return false;
//    }

//    clearCategories();
//    fromJson(QJsonDocument().fromJson(bytes).object());

//    int order = 0;
//    for (auto &category: _categories) {
//        category->updateParents().updateOrders(order);
//    }
//    return true;
//}

//Category &Category::updateParents() {
//    for (auto &category: _categories) {
//        category->setParent(this);
//        category->updateParents();
//    }
//    return *this;
//}

//Category &Category::updateOrders(int &aOrder) {
//    _order = aOrder++;
//    for (auto &category: _categories) {
//        category->updateOrders(aOrder);
//    }
//    return *this;
//}

//Category *Category::root() {
//    return _parent == nullptr ? this : _parent->root();
//}

//Category &Category::removeFromParent() {
//    changeParent(nullptr);
//    return *this;
//}

//Category &Category::changeParent(Category *newParent) {
//    if (_parent != nullptr) {
//        _parent->removeCategory(this);
//    }
//    if (newParent != nullptr) {
//        newParent->addCategory(this);
//    } else {
//        setParent(nullptr);
//    }
//    return *this;
//}

//void Category::fromJson(const QJsonObject &aCategory) {
//    _gameName = aCategory.value("game").toString();
//    _gameId   = aCategory.value("gameID").toInt();
//    _order    = aCategory.value("order").toInt();
//    _title  = aCategory.value("title").toString();
//    for(auto &&valueAchievement: aCategory.value("achievements").toArray()) {
//        _achievements.append(valueAchievement.toString());
//    }
//    for(auto &&valueCategory: aCategory.value("categories").toArray()) {
//        addCategory(new Category (valueCategory.toObject()));
//    }
//}

//QJsonObject Category::toJson() const {
//    QJsonObject result;
//    result["title"] = _title;
//    result["order"] = _order;

//    if (!_gameName.isEmpty()) {
//        result["game"] = _gameName;
//    }

//    if (_gameId > 0) {
//        result["gameID"] = _gameId;
//    }

//    QJsonArray valuesAchievements;
//    for(const QString &valueAchievement: _achievements) {
//        valuesAchievements.append(valueAchievement);
//    }
//    result["achievements"] = valuesAchievements;

//    QJsonArray valuesCategories;
////    int order = -1;
//    for(const auto &valueCategory: _categories) {
//        auto category = valueCategory->toJson();
////        category["order"] = ++order;
//        valuesCategories.append(category);
//    }
//    result["categories"] = valuesCategories;

//    if (isRoot()) {
//        result["version"] = "2.0";
//    }

//    return result;
//}

Category2::Category2(const SGame &aGame): Category2(aGame.appId(), aGame.name()) {
}

Category2::Category2(const Category2 &aCategory): QSet<AchievementID>(aCategory), FileSaveLoad(aCategory.filePath_), parent_(aCategory.parent_), title_(aCategory.title_), gameId_(aCategory.gameId_), gameName_(aCategory.gameName_) {
    auto categories = aCategory.categories_;
    for (auto category: categories) {
        categories_.append(new Category2(*category));
    }
}

Category2::Category2(const GameID &aGameId, const QString &aGameName):  QSet<AchievementID>(), FileSaveLoad(Paths::categories(QString::number(aGameId))), gameId_(aGameId), gameName_(aGameName) {
    load(filePath_);
    qDebug() << 1 << title_ << categories_;
}

Category2::Category2(const GameID &aGameId, const QString &aTitle, const QSet<AchievementID> &aAchievements, const QList<Category2 *> &aCategories):  QSet<AchievementID>(aAchievements), FileSaveLoad(Paths::categories(QString::number(aGameId))), title_(aTitle), categories_(aCategories) {
    load(filePath_);
    qDebug() << 2 << title_ << categories_;
}

Category2::Category2(const QJsonObject &aCategory): QSet<AchievementID>(), FileSaveLoad("") {
    fromJson(aCategory);
    filePath_ = Paths::categories(QString::number(gameId_));
}

Category2::~Category2() {
//    deleteAllChilds();
}

bool Category2::operator==(const Category2 &aCategory) const {
    return parent_ == aCategory.parent_ &&
            title_ == aCategory.title_ &&
            gameId_ == aCategory.gameId_ &&
            gameName_ == aCategory.gameName_ &&
            categories_ == aCategory.categories_ &&
            filePath_ == aCategory.filePath_ &&
            QSet<AchievementID>::operator==(aCategory);
}

bool Category2::operator!=(const Category2 &aCategory) const {
    return parent_ != aCategory.parent_ ||
            title_ != aCategory.title_ ||
            gameId_ != aCategory.gameId_ ||
            gameName_ != aCategory.gameName_ ||
            categories_ != aCategory.categories_ ||
            filePath_ != aCategory.filePath_ ||
            QSet<AchievementID>::operator!=(aCategory);
}

bool Category2::isRoot() const   {
    return parent_ == nullptr;
}

QString Category2::title() const   {
    return title_;
}

QString Category2::gameName() const   {
    return gameName_;
}

GameID Category2::gameID() const   {
    return gameId_;
}

QList<Category2 *> Category2::categories() const   {
    return categories_;
}

Category2 *Category2::parent() const   {
    return parent_;
}

void Category2::setTitle(const QString &aTitle) {
    title_ = aTitle;
}

void Category2::setGame(const SGame &aGame) {
    setGame(aGame.appId(), aGame.name());
}

void Category2::setGame(const GameID &aGameId, const QString &aGameName) {
    gameId_ = aGameId;
    gameName_ = aGameName;
    filePath_ = Paths::categories(QString::number(aGameId));
}

void Category2::setParent(Category2 *aNewParent) {
    if (parent_ != nullptr) {
        parent_->removeCategory(title_);
    }
    aNewParent->addCategory(this);
}

bool Category2::addCategory(const QStringList &aTitles, Category2 *aCategory) {
    if (aTitles.count() == 0) {
        categories_.append(aCategory);
        aCategory->parent_ = this;
        return true;
    } else {
        QStringList localTitles = aTitles;
        QString nextTitle = localTitles.first();
        localTitles.pop_front();
        auto iterator = std::find_if(categories_.begin(),
                                     categories_.end(),
                                     [=](Category2 *lCategory) {
            return lCategory->title_ == nextTitle;
        });
        if (iterator != categories_.end()) {
            return (*iterator)->addCategory(localTitles, aCategory);
        }
        return false;
    }
}

bool Category2::addCategory(Category2 *aCategory) {
    return addCategory(QStringList(), aCategory);
}

bool Category2::removeCategory(const QStringList &aTitles) {
    if (aTitles.count() == 0) {
        return false;
    }
    QStringList localTitles = aTitles;
    QString nextTitle = localTitles.first();
    localTitles.pop_front();
    auto iterator = std::find_if(categories_.begin(),
                                 categories_.end(),
                                 [=](Category2 *lCategory) {
        return lCategory->title_ == nextTitle;
    });
    if (iterator != categories_.end()) {
        if (aTitles.count() == 1) {
            categories_.remove(iterator - categories_.begin());
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

bool Category2::removeCategory(const QString &aTitle) {
    return removeCategory(QStringList{aTitle});
}

Category2 *Category2::find(const QStringList &aTitles) {
    if (aTitles.count() == 0) {
        return nullptr;
    }
    QStringList localTitles = aTitles;
    QString nextTitle = localTitles.first();
    localTitles.pop_front();
    auto iterator = std::find_if(categories_.begin(),
                                 categories_.end(),
                                 [=](Category2 *lCategory) {
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

Category2 *Category2::find(const QString &aTitle) {
    return find(QStringList{aTitle});
}

void Category2::clearCategories() {
    categories_.clear();
}

void Category2::fromJson(const QJsonObject &aCategory) {
    gameName_ = aCategory.value("game").toString();
    gameId_   = aCategory.value("gameID").toInt();
    title_  = aCategory.value("title").toString();
    QSet<AchievementID>::clear();
    for(const auto &valueAchievement: aCategory.value("achievements").toArray()) {
        insert(valueAchievement.toString());
    }
    auto oldCategories = categories_;
//    if () {

//    }
//    categories_.clear();
    auto categoriesArray = aCategory.value("categories").toArray();
    for(const auto &valueCategory: categoriesArray) {
        auto iterator = std::find_if(categories_.begin(),
                                     categories_.end(),
                                     [&](Category2 *lCategory) {
                                        return lCategory->title() == valueCategory.toObject().value("title").toString();
                                     });
        if (iterator != categories_.end()) {
            (*iterator)->fromJson(valueCategory.toObject());
        } else {
            addCategory(new Category2(valueCategory.toObject()));
        }
//        if (categories_.find(valueCategory.toObject().value("title").toString()) != categories_.end()) {

//        }
//        addCategory(new Category2(valueCategory.toObject()));
    }
}

QJsonObject Category2::toJson() const {
    QJsonObject result;
    result["title"] = title_;

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
    for(const auto &valueCategory: categories_) {
        auto category = valueCategory->toJson();
        valuesCategories.append(category);
    }
    result["categories"] = valuesCategories;

    if (isRoot()) {
        result["version"] = "2.0";
    }

    return result;
}

Category2 *Category2::root() {
    return parent_ == nullptr ? this : parent_->root();
}

void Category2::getPathFromRoot(QStringList &aList) {
    aList.push_back(title_);
    if (parent_ != nullptr) {
        parent_->getPathFromRoot(aList);
    }
}

int Category2::countCategories() const {
    int count = std::accumulate(categories_.begin(),
                                categories_.end(),
                                categories_.count(),
                                [](int i, Category2 *c) {return i += c->countCategories();});
    return count;
}

void Category2::update() {
    load(filePath_);
    qDebug() << 3 << title_ << categories_;
}

void Category2::deleteAllChilds() {
    auto childs = categories_;
    for (auto child: childs) {
        child->deleteAllChilds();
        delete child;
    }
}
