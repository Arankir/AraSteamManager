#include "categoriesgame.h"

CategoriesGame::CategoriesGame(SGame &aGame, QObject *aParent): QObject(aParent), _game(aGame) {
    convertOldCategories();
    update();
}

CategoryGame *findCategory(int &aIndex, CategoryGame &aCategory) {
    CategoryGame *category;
    for(auto &subCategory: aCategory) {
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

CategoryGame *CategoriesGame::getCategoryAtAll(int aIndex) {
    CategoryGame *category;
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

void CategoriesGame::setGame(SGame aGame) {
    _game = aGame;
    _gameName = _game.name();
    _gameId = _game.appId();
    convertOldCategories();
    update();
}

CategoriesGame &CategoriesGame::update() {
    load();
    return *this;
}

QList<QString> CategoriesGame::getCategoriesTitles() const {
    QList<QString> list;
    for(auto category: _categories) {
        list.append(category.title());
    }
    return list;
}

CategoriesGame &CategoriesGame::addCategory(const QString &aTitle, QList<QString> aAchievements, const QList<CategoryGame> &aCategories) {
    _categories.append(CategoryGame(aTitle, aAchievements, aCategories));
    save(toJson());
    return *this;
}

CategoriesGame &CategoriesGame::changeCategory(CategoryGame *aCategory, const QString &aTitle, QList<QString> aAchievements, const QList<CategoryGame> &aCategories) {
    aCategory->updateCategory(aTitle, aAchievements, aCategories);
    save(toJson());
    return *this;
}

CategoriesGame &CategoriesGame::deleteCategory(int aIndex) {
    _categories.removeAt(aIndex);
    save(toJson());
    return *this;
}

CategoriesGame &CategoriesGame::deleteAll() {
    _categories.clear();
    save(toJson());
    return *this;
}

QFileInfoList CategoriesGame::getFiles(const QString &aPath) {
    Settings::createDir(aPath);
    QDir categoriesOld(aPath);
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    return categoriesOld.entryInfoList();
}

void CategoriesGame::convertOldCategories() {
    QFileInfoList listFiles = getFiles(Paths::categories(_game.sAppId()));
    if (!listFiles.isEmpty()) {
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"] = _gameName;
        finalNew["GameID"] = _gameId;
        for (auto &listFile: listFiles) {
            QFile fileCategoryOld(Paths::categories(_game.sAppId() + "/" + listFile.fileName()));
            fileCategoryOld.open(QFile::ReadOnly);
            QJsonDocument categoryOld = QJsonDocument().fromJson(fileCategoryOld.readAll());
            fileCategoryOld.close();

            QJsonObject categoryNew;
            categoryNew["Title"] = categoryOld.object().value("name").toString();
            QJsonArray ValuesNew;
            QJsonArray NoValuesNew;

            if (categoryOld.object().value("values").toArray().size() == 1) {
                categoryNew["IsNoValues"] = 1;
                for (auto name: categoryOld.object().value(categoryOld.object().value("name").toString()).toArray()) {
                    NoValuesNew.append(std::move(name.toString()));
                }
            } else {
                categoryNew["IsNoValues"] = 0;
                for (auto value: categoryOld.object().value("values").toArray()) {
                    QJsonObject valueNew;
                    valueNew["Title"] = value.toString();
                    QJsonArray achievementsNew;
                    for(auto newValue: categoryOld.object().value(value.toString()).toArray()) {
                        achievementsNew.append(std::move(newValue.toString()));
                    }
                    valueNew["Achievements"] = achievementsNew;
                    ValuesNew.append(std::move(valueNew));
                }
            }
            categoryNew["Values"] = ValuesNew;
            categoryNew["NoValues"] = NoValuesNew;
            categoriesNew.append(std::move(categoryNew));
        }
        finalNew["Categories"] = categoriesNew;
        save(finalNew);
        QDir categoriesOld(Paths::categories(_game.sAppId()));
        categoriesOld.removeRecursively();
    }
}

void CategoriesGame::save(QJsonObject aCategories) {
    Settings::createDir(Paths::categories());
    QFile fileCategory(Paths::categories(_game.sAppId()));
    fileCategory.open(QFile::WriteOnly);
    fileCategory.write(QJsonDocument(aCategories).toJson());
    fileCategory.close();
}

int CategoriesGame::countRoot(CategoryGame &aCategory) const {
    int count = 0;
    for(auto &subCategory: aCategory) {
        count += countRoot(subCategory);
        ++count;
    }
    return count;
}

int CategoriesGame::countAll() const {
    int count = 0;
    for(auto subCategory: _categories) {
        count += countRoot(subCategory);
        ++count;
    }
    return count;
}

void CategoriesGame::load() {
    _categories.clear();
    QFile fileCategory(Paths::categories(_game.sAppId()));
    if (fileCategory.exists()) {
        if (fileCategory.open(QFile::ReadOnly)) {
            fromJson(QJsonDocument().fromJson(fileCategory.readAll()).object());
            fileCategory.close();
        }
    }
}

void CategoriesGame::fromJson(QJsonObject aCategories) {
    _gameName = aCategories.value("Game").toString();
    _gameId   = aCategories.value("GameID").toInt();
    for(auto category: aCategories.value("Categories").toArray()) {
        _categories.append(CategoryGame(category.toObject()));
    }
}

QJsonObject CategoriesGame::toJson() {
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

#define Category {
CategoryGame::CategoryGame(const QJsonObject aCategory) {
    fromJson(aCategory);
}

CategoryGame &CategoryGame::operator=(const CategoryGame aCategory) {
    _title          = aCategory._title;
    _achievements   = aCategory._achievements;
    _categories     = aCategory._categories;
    return *this;
}

CategoryGame &CategoryGame::updateCategory(const QString &aTitle, QList<QString> aAchievements, const QList<CategoryGame> &aCategories) {
    _title          = aTitle;
    _achievements   = aAchievements;
    _categories     = aCategories;
    return *this;
}

CategoryGame &CategoryGame::fromJson(QJsonObject aCategoryGame) {
    if (!aCategoryGame.value("title").toString().isNull()) {
        _title  = aCategoryGame.value("title").toString();
        for(auto valueAchievement: aCategoryGame.value("achievements").toArray()) {
            _achievements.append(valueAchievement.toString());
        }
        for(auto valueCategory: aCategoryGame.value("categories").toArray()) {
            _categories.append(CategoryGame(valueCategory.toObject()));
        }
    }
    return *this;
}

QJsonObject CategoryGame::toJson() const {
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

#define Value {
CategoryValue &CategoryValue::setSubCategory(CategoryGame *aCategory) {
    category = aCategory;
    return *this;
}

CategoryValue &CategoryValue::fromJson(QJsonObject aObject) {
    title = aObject.value("title").toString();
    type = static_cast<TypeCategoryValue>(aObject.value("type").toInt());
    order = aObject.value("order").toInt();
    for(auto achievement: aObject.value("achievements").toArray()) {
        achievements.append(achievement.toString());
    }
    if (!aObject.value("category").isNull()) {
        category = new CategoryGame(aObject.value("category").toObject());
    }
    return *this;
}

QJsonObject CategoryValue::toJson() {
    QJsonObject value;
    value["title"] = title;
    value["type"] = static_cast<int>(type);
    value["order"] = order;
    QJsonArray achievementsJ;
    for(auto achievement: achievements) {
        achievementsJ.append(achievement);
    }
    value["achievements"] = achievementsJ;
    if (category != nullptr) {
        value["category"] = category->toJson();
    }
    return value;
}
#define ValueEnd }
#define CategoryEnd }
