#include "categoriesgame.h"

Category::Category(SGame &aGame): _gameName(aGame.name()), _gameId(aGame.appId()) {
    update();
}

Category::Category(int aGameId): _gameId(aGameId) {
    update();
}

Category::Category(const QJsonObject &aCategory) {
    fromJson(aCategory);
}

Category &Category::operator=(const Category &aCategory) {
    _title          = aCategory._title;
    _achievements   = aCategory._achievements;
    _categories     = aCategory._categories;
    _parent         = aCategory._parent;
    return *this;
}

bool isListsEqual(const QList<Category*> &list1, const QList<Category*> &list2) {
    if (list1.count() != list2.count()) {
        return false;
    }
    for(int i = 0; i < list1.count(); ++i) {
        if (*(list1[i]) != *(list2[i])) {
            return false;
        }
    }
    return true;
}

bool Category::operator==(const Category &aCategory) const {
    return ((_title == aCategory._title) && (_achievements == aCategory._achievements) && isListsEqual(_categories, aCategory._categories));
}

bool Category::operator!=(const Category &aCategory) const {
    return ((_title != aCategory._title) || (_achievements != aCategory._achievements) || !isListsEqual(_categories, aCategory._categories));
}

Category &Category::setParent(Category *aParent) {
    _parent = aParent;
    return *this;
}

Category &Category::setTitle(const QString &aTitle) {
    _title = aTitle;
    return *this;
}

Category &Category::setAchievements(QList<QString> &aAchievements) {
    _achievements = aAchievements;
    return *this;
}

Category &Category::setGame(SGame aGame) {
    _gameName = aGame.name();
    _gameId = aGame.appId();
    update();
    return *this;
}

Category *Category::findCategory(Category *aFindCategory) {
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

bool Category::removeCategory(Category *aCategory, bool isRemoveRecursively) {
    auto iterator = std::find_if(_categories.begin(), _categories.end(), [=](const Category *subCategory){
                                                                                    return subCategory == aCategory;
                                                                                });
    if (iterator != _categories.end()) {
        int index = iterator - _categories.begin();
        aCategory->setParent(nullptr);
        _categories.removeAt(index);
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

bool Category::save() {
    if (_gameId > 0) {
        auto aCategories = toJson();
        createDir(Paths::categories());
        QFile fileCategory(Paths::categories(QString::number(_gameId)));
        fileCategory.open(QFile::WriteOnly);
        fileCategory.write(QJsonDocument(aCategories).toJson());
        fileCategory.close();
        return true;
    }
    return false;
}

Category &Category::update() {
    load();
    return *this;
}

bool Category::load() {
    QFile fileCategory(Paths::categories(QString::number(_gameId)));
    if (!fileCategory.exists()) {
        return false;
    }
    if (!fileCategory.open(QFile::ReadOnly)) {
        return false;
    }

    clearCategories();
    fromJson(QJsonDocument().fromJson(fileCategory.readAll()).object());

    fileCategory.close();
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
    for(auto valueAchievement: aCategory.value("achievements").toArray()) {
        _achievements.append(valueAchievement.toString());
    }
    for(auto valueCategory: aCategory.value("categories").toArray()) {
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
    for(auto valueCategory: _categories) {
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

Category *Category::findCategory(int aOrder) {
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
