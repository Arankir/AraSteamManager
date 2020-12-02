#include "categoriesgame.h"

Categories::Categories(SGame &aGame, QObject *aParent): QObject(aParent), _game(aGame) {
    update();
}

Category *findCategory(int &aIndex, Category &aCategory) {
    for(auto &subCategory: aCategory) {
        if (aIndex == 0) {
            return &subCategory;
        }
        --aIndex;
        Category *category;
        category = findCategory(aIndex, subCategory);
        if(category != nullptr) {
            return category;
        }
    }
    return nullptr;
}

Category *Categories::getCategoryAtGlobalIndex(int aIndex) {
    Category *category;
    for(auto &subCategory: _categories) {
        if (aIndex == 0) {
            return &subCategory;
        }
        --aIndex;
        category = findCategory(aIndex, subCategory);
        if(category != nullptr) {
            return category;
        }
    }
    return nullptr;
}

void Categories::setGame(SGame aGame) {
    _game = aGame;
    _gameName = _game.name();
    _gameId = _game.appId();
    update();
}

Categories &Categories::update() {
    load();
    return *this;
}

Categories &Categories::addCategory(const QString &aTitle, QList<QString> aAchievements, const QList<Category> &aCategories) {
    _categories.append(Category(aTitle, aAchievements, aCategories));
    save(toJson());
    load();
    return *this;
}

Categories &Categories::addCategory(Category &aCategory) {
    _categories.append(aCategory);
    save(toJson());
    load();
    return *this;
}

bool Categories::addSubCategory(Category &aCategory) {
    for (auto &category: _categories) {
        if (category.addSubCategory(aCategory)) {
            save(toJson());
            load();
            return true;
        }
    }
    return false;
}

Categories &Categories::deleteCategoryAtGlobalIndex(int aIndex) {
    int localIndex = 0;
    for(auto &subCategory: _categories) {
        if (aIndex == 0) {
            _categories.removeAt(localIndex);
            break;
        }
        --aIndex;
        ++localIndex;
        if (subCategory.removeCategoryAtGlobalIndex(aIndex) == true) {
            break;
        }
    }
    save(toJson());
    return *this;
}

bool Categories::removeCategory(Category &aCategory) {
    if (_categories.removeOne(aCategory)) {
        save(toJson());
        return true;
    } else {
        for (auto &category: _categories) {
            if (category.removeCategory(aCategory)) {
                save(toJson());
                return true;
            }
        }
    }
    return false;
}

Categories &Categories::deleteAll() {
    _categories.clear();
    save(toJson());
    return *this;
}

void Categories::save(QJsonObject aCategories) {
    Settings::createDir(Paths::categories());
    QFile fileCategory(Paths::categories(_game.sAppId()));
    fileCategory.open(QFile::WriteOnly);
    fileCategory.write(QJsonDocument(aCategories).toJson());
    fileCategory.close();
}

int Categories::countAll() const {
    int count = 0;
    for(auto subCategory: _categories) {
        count += subCategory.countCategories();
        ++count;
    }
    return count;
}

void Categories::load() {
    _categories.clear();
    QFile fileCategory(Paths::categories(_game.sAppId()));
    if (fileCategory.exists()) {
        if (fileCategory.open(QFile::ReadOnly)) {
            fromJson(QJsonDocument().fromJson(fileCategory.readAll()).object());
            fileCategory.close();
        }
    }
    for (auto &category: _categories) {
        category.updateParents();
    }
}

void Categories::fromJson(QJsonObject aCategories) {
    _gameName = aCategories.value("Game").toString();
    _gameId   = aCategories.value("GameID").toInt();
    for(auto category: aCategories.value("Categories").toArray()) {
        _categories.append(Category(category.toObject()));
    }
}

QJsonObject Categories::toJson() const {
    QJsonObject obj;
    obj["Game"] = _gameName;
    obj["GameID"] = _gameId;
    obj["Version"] = "1.0";
    QJsonArray categoriesArr;
    for(auto category: _categories) {
        categoriesArr.append(category.toJson());
    }
    obj["Categories"] = categoriesArr;
    return obj;
}

#define CategoryStart {
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

bool Category::operator==(const Category &aCategory) {
//TODO Неправильно определяет равенство (если у родителя такое же имя и достижения определит как то)
    if (aCategory.parent() == nullptr || _parent == nullptr) {
        return ((_title == aCategory._title)
                && (_achievements == aCategory._achievements)
                && (_categories == aCategory._categories)
                && (_parent == aCategory._parent));
    }
    return ((_title == aCategory._title)
            && (_achievements == aCategory._achievements)
            && (_categories == aCategory._categories)
            && (_parent->title() == aCategory._parent->title())
            && (_parent->achievements() == aCategory._parent->achievements()));
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

Category &Category::addCategory(Category &aCategory) {
    aCategory.setParent(this);
    _categories.append(aCategory);
    updateParents();
    return *this;
}

bool Category::addSubCategory(Category &aCategory) {
    if (*this == *(aCategory.parent())) {
        addCategory(aCategory);
        updateParents();
        return true;
    } else {
        for(auto &category: _categories) {
            if (category.addSubCategory(aCategory)) {
                updateParents();
                return true;
            }
        }
    }
    return false;
}

Category &Category::removeCategoryAt(int aIndex) {
    _categories.removeAt(aIndex);
    updateParents();
    return *this;
}

bool Category::removeCategory(Category &aCategory) {
    if (_categories.removeOne(aCategory)) {
        updateParents();
        return true;
    } else {
        for (auto &cat: _categories) {
            if (cat.removeCategory(aCategory)) {
                updateParents();
                return true;
            }
        }
    }
    return false;
}

bool Category::removeCategoryAtGlobalIndex(int &aIndex) {
    int localIndex = 0;
    for(auto &subCategory: _categories) {
        if (aIndex == 0) {
            _categories.removeAt(localIndex);
            updateParents();
            return true;
        }
        --aIndex;
        ++localIndex;
        if (subCategory.removeCategoryAtGlobalIndex(aIndex) == true) {
            updateParents();
            return true;
        }
    }
    updateParents();
    return false;
}

Category Category::takeCategoryAtGlobalIndex(int aIndex) {
    int localIndex = 0;
    for(auto &subCategory: _categories) {
        if (aIndex == 0) {
            return _categories.takeAt(localIndex);
        }
        --aIndex;
        ++localIndex;
        Category sub = subCategory.takeCategoryAtGlobalIndex(aIndex);
        if (sub.title() != "") {
            return sub;
        }
    }
    return Category();
}

Category &Category::fromJson(const QJsonObject &aCategoryGame) {
    if (!aCategoryGame.value("title").toString().isNull()) {
        _title  = aCategoryGame.value("title").toString();
        for(auto valueAchievement: aCategoryGame.value("achievements").toArray()) {
            _achievements.append(valueAchievement.toString());
        }
        for(auto valueCategory: aCategoryGame.value("categories").toArray()) {
            Category sub(valueCategory.toObject());
            addCategory(sub);
        }
    }
    return *this;
}

QJsonObject Category::toJson() const {
    QJsonObject result;
    result["title"] = _title;

    QJsonArray valuesAchievements;
    for(auto valueAchievement: _achievements) {
        valuesAchievements.append(valueAchievement);
    }
    result["achievements"] = valuesAchievements;

    QJsonArray valuesCategories;
    int order = -1;
    for(auto valueCategory: _categories) {
        auto category = valueCategory.toJson();
        category["order"] = ++order;
        valuesCategories.append(category);
    }
    result["categories"] = valuesCategories;

    return result;
}

int Category::countCategories() const {
    int count = 0;
    for (auto &subCategory: _categories) {
        ++count;
        count += subCategory.countCategories();
    }
    return count;
}

Category &Category::updateParents() {
    for (auto &category: _categories) {
        category.setParent(this);
        category.updateParents();
    }
    return *this;
}

QList<Category*> Category::directTraversalList() {
    QList<Category*> list;
    for (auto &category: _categories) {
        list.append(&category);
        list.append(category.directTraversalList());
    }
    return list;
}
#define CategoryEnd }
