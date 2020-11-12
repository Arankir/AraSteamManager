#include "categoriesgame.h"

CategoriesGame::CategoriesGame(SGame &aGame, QObject *aParent): QObject(aParent), _game(aGame) {
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
        list.append(category.getTitle());
    }
    return list;
}

CategoriesGame &CategoriesGame::changeCategory(int aCategory, const QString &aTitle, int aIsNoValue, QList<CategoryValue> &aValues, QList<QString> &aNoValues) {
    _categories[aCategory].updateCategory(aTitle, aIsNoValue, aValues, aNoValues);
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
        finalNew["Game"] = _game.name();
        finalNew["GameID"] = _game.appId();
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
    _isNoValue  = aCategory._isNoValue;
    _title      = aCategory._title;
    _values     = aCategory._values;
    _noValues   = aCategory._noValues;
    return *this;
}

CategoryGame &CategoryGame::updateCategory(const QString &aTitle, int aIsNoValue, QList<CategoryValue> &aValues, QList<QString> &aNoValues) {
    _title      = aTitle;
    _isNoValue  = aIsNoValue;
    _noValues   = aNoValues;
    _values     = aValues;
    return *this;
}

CategoryGame &CategoryGame::fromJson(QJsonObject aCategoryGame) {
    if (!aCategoryGame.value("Title").toString().isNull()) {
        _isNoValue  = aCategoryGame.value("IsNoValues").toInt();
        _title      = aCategoryGame.value("Title").toString();
        _index      = aCategoryGame.value("Index").toInt();
        for(auto noValueAchievement: aCategoryGame.value("NoValues").toArray()) {
            _noValues.append(noValueAchievement.toString());
        }
        for(auto valueAchievement: aCategoryGame.value("Values").toArray()) {
            CategoryValue value;
            _values.append(value.fromJson(valueAchievement.toObject()));
        }
    }
    return *this;
}

QJsonObject CategoryGame::toJson() const {
    QJsonObject result;
    result["IsNoValues"] = _isNoValue;
    result["Title"] = _title;
    result["Index"] = _index;

    QJsonArray noValues;
    for(auto noValueAchievement: _noValues) {
        noValues.append(noValueAchievement);
    }
    result["NoValues"] = noValues;

    QJsonArray values;
    for(auto valueAchievement: _values) {
        values.append(valueAchievement.toJson());
    }
    result["Values"] = values;

    return result;
}

#define Value {
CategoryValue &CategoryValue::fromJson(QJsonObject aObject) {
    title = aObject.value("Title").toString();
    for(auto achievement: aObject.value("Achievements").toArray()) {
        achievements.append(achievement.toString());
    }
    return *this;
}

QJsonObject CategoryValue::toJson() {
    QJsonObject value;
    value["Title"] = title;
    QJsonArray achievementsJ;
    for(auto achievement: achievements) {
        achievementsJ.append(achievement);
    }
    value["Achievements"] = achievementsJ;
    return value;
}
#define ValueEnd }
#define CategoryEnd }
