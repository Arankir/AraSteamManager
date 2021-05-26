#include "categoriesgame.h"
#include "classes/common/settings.h"

Category::Category(const SGame &aGame): _gameName(aGame.name()), _gameId(aGame.appId()) {
    update();
}

Category::Category(const int &aGameId): _gameId(aGameId) {
    update();
}

Category::Category(const QJsonObject &aCategory) {
    fromJson(aCategory);
    int order = 0;
    updateOrders(order);
}

Category &Category::operator=(const Category &aCategory) {
    _title          = aCategory._title;
    _achievements   = aCategory._achievements;
    _categories     = aCategory._categories;
    _parent         = aCategory._parent;
    return *this;
}

bool isListsEqual(const QList<Category*> &aList1, const QList<Category*> &aList2) {
    if (aList1.count() != aList2.count()) {
        return false;
    }
    for(auto iterList1 = aList1.begin(), iterList2 = aList2.begin();
             iterList1 != aList1.end() || iterList2 != aList2.end();
             ++iterList1, ++iterList2) {
        if ((*iterList1)->title() != (*iterList2)->title() ||
            (*iterList1)->achievementsApiName() != (*iterList2)->achievementsApiName()) {
            return false;
        }
    }
    return true;
}

bool Category::operator==(Category &aCategory) {
    bool isRootEqually = (root()->_title == aCategory.root()->_title) && (root()->_achievements == aCategory.root()->_achievements);
    bool isItemEqually = (_title == aCategory._title) && (_achievements == aCategory._achievements);
    bool isListsEqually = isListsEqual(root()->_categories, aCategory.root()->_categories);
    return (isRootEqually && isItemEqually && isListsEqually);
}

bool Category::operator!=(Category &aCategory) {
    bool isRootEqually = (root()->_title == aCategory.root()->_title) && (root()->_achievements == aCategory.root()->_achievements);
    bool isItemEqually = (_title == aCategory._title) && (_achievements == aCategory._achievements);
    bool isListsEqually = isListsEqual(root()->_categories, aCategory.root()->_categories);
    return (!isRootEqually || !isItemEqually || !isListsEqually);
}

Category &Category::setParent(Category *aParent) {
    _parent = aParent;
    return *this;
}

Category &Category::setTitle(const QString &aTitle) {
    _title = aTitle;
    return *this;
}

Category &Category::setAchievements(const QList<QString> &aAchievements) {
    _achievements = aAchievements;
    return *this;
}

Category &Category::setGame(const SGame &aGame) {
    _gameName = aGame.name();
    _gameId = aGame.appId();
    update();
    return *this;
}

Category *Category::findCategory(Category *aFindCategory) const {
    auto iterator = std::find_if(   _categories.begin(),
                                    _categories.end(),
                                    [=](Category *aCategory) { return *aCategory == *aFindCategory; });
    if (iterator != _categories.end()) {
        return *iterator;
    } else {
        for (auto &category: _categories) {
            Category *find = category->findCategory(aFindCategory);
            if (find != nullptr) {
                return find;
            }
        }
    }
    return nullptr;
}

Category *Category::findCategory(const int &aOrder) const {
    auto iterator = std::find_if(   _categories.begin(),
                                    _categories.end(),
                                    [=](Category *aCategory) { return aCategory->order() == aOrder; });
    if (iterator != _categories.end()) {
        return *iterator;
    } else {
        for (auto &category: _categories) {
            Category *find = category->findCategory(aOrder);
            if (find != nullptr) {
                return find;
            }
        }
    }
    return nullptr;
}

Category &Category::addCategory(Category *aCategory) {
    _categories.append(aCategory);
    aCategory->setParent(this);
    int order = 0;
    root()->updateOrders(order);
//    updateParents();
    return *this;
}

Category &Category::clearCategories() {
    _categories.clear();
    return *this;
}

bool Category::removeCategory(Category *aCategory, const bool &isRemoveRecursively) {
    auto iterator = std::find_if(_categories.begin(),
                                 _categories.end(),
                                 [=](const Category *subCategory) {
                                    return subCategory == aCategory;
                                 });
    if (iterator != _categories.end()) {
        aCategory->setParent(nullptr);
        _categories.removeAt(iterator - _categories.begin());
        int order = 0;
        root()->updateOrders(order);
        root()->save();
        return true;
    } else {
        if (isRemoveRecursively) {
            for (auto &category: _categories) {
                if (category->removeCategory(aCategory, true)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int Category::countCategories() const {
    int count = std::accumulate(_categories.begin(),
                                _categories.end(),
                                _categories.count(),
                                [](int i, Category *c) {return i += c->countCategories();});
    return count;
}

bool Category::save() const {
    if (_gameId > 0) {
        saveFile(Paths::categories(QString::number(_gameId)), QJsonDocument(toJson()).toJson());
        return true;
    }
    return false;
}

Category &Category::update() {
    load();
    return *this;
}

bool Category::load() {
    QByteArray bytes;
    if (!readFile(Paths::categories(QString::number(_gameId)), bytes)) {
        return false;
    }

    clearCategories();
    fromJson(QJsonDocument().fromJson(bytes).object());

    int order = 0;
    for (auto &category: _categories) {
        category->updateParents().updateOrders(order);
    }
    return true;
}

Category &Category::updateParents() {
    for (auto &category: _categories) {
        category->setParent(this);
        category->updateParents();
    }
    return *this;
}

Category &Category::updateOrders(int &aOrder) {
    _order = aOrder++;
    for (auto &category: _categories) {
        category->updateOrders(aOrder);
    }
    return *this;
}

Category *Category::root() {
    return _parent == nullptr ? this : _parent->root();
}

Category &Category::removeFromParent() {
    changeParent(nullptr);
    return *this;
}

Category &Category::changeParent(Category *newParent) {
    if (_parent != nullptr) {
        _parent->removeCategory(this);
    }
    if (newParent != nullptr) {
        newParent->addCategory(this);
    } else {
        setParent(nullptr);
    }
    return *this;
}

Category &Category::fromJson(const QJsonObject &aCategory) {
    _gameName = aCategory.value("game").toString();
    _gameId   = aCategory.value("gameID").toInt();
    _order    = aCategory.value("order").toInt();
    _title  = aCategory.value("title").toString();
    for(auto &&valueAchievement: aCategory.value("achievements").toArray()) {
        _achievements.append(valueAchievement.toString());
    }
    for(auto &&valueCategory: aCategory.value("categories").toArray()) {
        addCategory(new Category (valueCategory.toObject()));
    }
    return *this;
}

QJsonObject Category::toJson() const {
    QJsonObject result;
    result["title"] = _title;
    result["order"] = _order;

    if (!_gameName.isEmpty()) {
        result["game"] = _gameName;
    }

    if (_gameId > 0) {
        result["gameID"] = _gameId;
    }

    QJsonArray valuesAchievements;
    for(const QString &valueAchievement: _achievements) {
        valuesAchievements.append(valueAchievement);
    }
    result["achievements"] = valuesAchievements;

    QJsonArray valuesCategories;
//    int order = -1;
    for(const auto &valueCategory: _categories) {
        auto category = valueCategory->toJson();
//        category["order"] = ++order;
        valuesCategories.append(category);
    }
    result["categories"] = valuesCategories;

    if (isRoot()) {
        result["version"] = "2.0";
    }

    return result;
}
