#include "categoriesgame.h"

CategoriesGame::CategoriesGame(const CategoriesGame &aCategories): QObject(aCategories.parent()), _categories(aCategories._categories), _game(aCategories._game) {

}

QString CategoriesGame::getTitle(int aIndex) {
    return _categories.value("Categories").toArray().at(aIndex).toObject().value("Title").toString();
}

int CategoriesGame::getIsNoValues(int aIndex) {
    return _categories.value("Categories").toArray().at(aIndex).toObject().value("IsNoValues").toInt();
}

QJsonArray CategoriesGame::getValues(int aValue) {
    return _categories.value("Categories").toArray().at(aValue).toObject().value("Values").toArray();
}

QString CategoriesGame::getGame() {
    return _categories.value("Game").toString();
}

int CategoriesGame::getCount() {
    return _categories.value("Categories").toArray().size();
}

int CategoriesGame::getGameID() {
    return _categories.value("GameID").toInt();
}

CategoriesGame::CategoriesGame(SGame &aGame, QObject *aParent): QObject(aParent), _game(aGame) {
    update();
}

void CategoriesGame::update() {
    convertOldCategories();
    loadCategories();
}

QList<QString> CategoriesGame::getTitles() {
    QList<QString> list;
    for(auto title: _categories.value("Categories").toArray()) {
        list.append(std::move(title.toObject().value("Title").toString()));
    }
    return list;
}

QList<QString> CategoriesGame::getValues(int aCategory, int aValue) {
    QList<QString> list;
    for(auto achievement: _categories.value("Categories").toArray().at(aCategory).toObject().value("Values").toArray().at(aValue).toObject().value("Achievements").toArray()) {
        list.append(std::move(achievement.toString()));
    }
    return list;
}

QList<QString> CategoriesGame::getNoValues(int aCategory) {
    QList<QString> list;
    for(auto noValue: _categories.value("Categories").toArray().at(aCategory).toObject().value("NoValues").toArray()) {
        list.append(std::move(noValue.toString()));
    }
    return list;
}

QFileInfoList CategoriesGame::getFiles(const QString &aPath) {
    Settings::createDir(aPath);
    QDir categoriesOld(aPath);
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    return categoriesOld.entryInfoList();
}

void CategoriesGame::convertOldCategories() {
    QFileInfoList listFiles = getFiles(_setting._pathCategories+QString::number(_game._appID));
    if (!listFiles.isEmpty()) {
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"] = _game._name;
        finalNew["GameID"] = _game._appID;
        for (auto &listFile: listFiles) {
            QFile fileCategoryOld(_setting._pathCategories+QString::number(_game._appID)+"/"+listFile.fileName());
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
        _categories = std::move(finalNew);
        save();
        QDir categoriesOld(_setting._pathCategories + QString::number(_game._appID));
        categoriesOld.removeRecursively();
    }
}

void CategoriesGame::save() {
    Settings::createDir(_setting._pathCategories);
    QFile fileCategory(_setting._pathCategories + QString::number(_game._appID) + ".json");
    fileCategory.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(_categories);
    fileCategory.write(doc.toJson());
    fileCategory.close();
    loadCategories();
}

void CategoriesGame::loadCategories() {
    QFile fileCategory(_setting._pathCategories + QString::number(_game._appID) + ".json");
    if (fileCategory.exists()) {
        if (fileCategory.open(QFile::ReadOnly)) {
            _categories = QJsonDocument().fromJson(fileCategory.readAll()).object();
            fileCategory.close();
        }
    }
}

void CategoriesGame::changeCategory(int aCategory, QJsonObject &aNewCategory) {
    QJsonObject obj;
    obj["Game"] = _categories["Game"];
    obj["GameID"] = _categories["GameID"];
    QJsonArray arr;
    if(aCategory >= _categories.value("Categories").toArray().size()) {
        for(auto category: _categories.value("Categories").toArray()) {
            arr.append(std::move(category));
        }
        arr.append(std::move(aNewCategory));
    } else {
        for(int i = 0; i < _categories.value("Categories").toArray().size(); i++) {
            if(i != aCategory) {
                arr.append(std::move(_categories.value("Categories").toArray().at(i)));
            } else {
                arr.append(std::move(aNewCategory));
            }
        }
    }
    obj["Categories"] = arr;
    _categories = obj;
//    if(category==categories.value("Categories").toArray().size())
//        categories.value("Categories").toArray().append(newCategory);
//    else
//        categories.value("Categories").toArray().at(category).toObject()=newCategory;
    save();
}

void CategoriesGame::deleteCategory(int aIndex) {
    QJsonObject obj;
    obj["Game"] = _categories["Game"];
    obj["GameID"] = _categories["GameID"];
    QJsonArray arr;
    for(int i = 0; i < _categories.value("Categories").toArray().size(); i++)
        if(i != aIndex)
            arr.append(std::move(_categories.value("Categories").toArray().at(i)));
    obj["Categories"] = arr;
    _categories = obj;
    save();
}

void CategoriesGame::deleteAll(){
    QJsonObject obj;
    obj["Game"] = _categories["Game"];
    obj["GameID"] = _categories["GameID"];
    QJsonArray arr;
    obj["Categories"] = arr;
    _categories = obj;
    save();
}

//CategoriesGame& CategoriesGame::operator=(const CategoriesGame& a_newCategoriesGame){
//    _categories=a_newCategoriesGame._categories;
//    _game=a_newCategoriesGame._game;
//    return *this;
//}
