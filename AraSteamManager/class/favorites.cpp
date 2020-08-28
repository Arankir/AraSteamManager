#include "favorites.h"

Favorites::Favorites(QString aPath, QString aType, QObject *aParent): QObject(aParent), _path(aPath) {
    init(aType);
}

Favorites::Favorites(QString aType, QObject *aParent): QObject(aParent), _path(_setting._pathFavorites+aType+".json") {
    init(aType);
}

Favorites::Favorites(QObject *aParent): QObject(aParent) {

}

void Favorites::setType(QString aType) {
    _path = _setting._pathFavorites + aType + ".json";
    init(aType);
}

void Favorites::init(QString aType) {
    Settings::createDir(_path);
    if (!QFile::exists(_path)) {
        QJsonObject obj;
        obj["Type"] = aType;
        QJsonArray arr;
        obj["Values"] = arr;
        _favorites = obj;
        save();
    }
    load();
}

QJsonArray Favorites::getValues(QJsonObject aGame) {
    for(auto value: _favorites.value("Values").toArray()) {
        if(value.toObject().value("game").toObject() == aGame) {
            return value.toObject().value("Values").toArray();
        }
    }
    return QJsonArray();
}

bool Favorites::addValue(QJsonObject aNewValue, bool aDeleteIfExist) {
    return addValue(aNewValue, aDeleteIfExist, jsonType::object);
}

bool Favorites::addValue(QJsonArray aNewValue, bool aDeleteIfExist) {
    return addValue(aNewValue, aDeleteIfExist, jsonType::array);
}

bool Favorites::addValue(QJsonObject aGame, QJsonObject aNewValue, bool aDeleteIfExist) {
    Settings::createDir(_path);
    QJsonObject obj;
    obj["Type"] = _favorites["Type"];
    QJsonArray arr;
    int indGame = -1;
    //Узнаем индекс нужной игры
    for (int i = 0; i < _favorites.value("Values").toArray().size(); i++) {
        if (_favorites.value("Values").toArray().at(i).toObject().value("game").toObject() == aGame){
            indGame = i;
            break;
        }
    }
    //если её нет, создаем
    if (indGame == -1) {
        indGame = addGame(aGame);
    }
    //формируем массив избранных ачивок по этой игре
    QJsonObject obj2;
    obj2["game"] = aGame;
    QJsonArray arr2;
    for(auto value: _favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray()) {
        if (value.toObject() == aNewValue) {
            if(aDeleteIfExist) {
                removeValue(aGame, aNewValue);
            }
            return false;
        } else {
            arr2.append(std::move(value));
        }
    }
    arr2.append(std::move(aNewValue));
    obj2["Values"] = arr2;
    //копируем все игры, заменив старую версию игры на новую
    for(int i = 0; i < _favorites.value("Values").toArray().size(); i++) {
        if(i == indGame) {
            arr.append(std::move(obj2));
        } else {
            arr.append(std::move(_favorites.value("Values").toArray().at(i)));
        }
    }
    obj["Values"] = arr;
    _favorites = obj;
    save();
    return true;
}

bool Favorites::addValue(QJsonValue aNewValue, bool aDeleteIfExist, jsonType aType) {
    Settings::createDir(_path);
    QJsonObject obj;
    obj["Type"] = _favorites["Type"];
    QJsonArray arr;
    for (auto value: _favorites.value("Values").toArray()) {
        if (value == aNewValue) {
            if(aDeleteIfExist) {
                removeValue(aNewValue);
            }
            return false;
        } else {
            arr.append(std::move(value));
        }
    }
    switch (aType) {
    case jsonType::object:{
        arr.append(std::move(aNewValue.toObject()));
        break;
    }
    case jsonType::array:{
        arr.append(std::move(aNewValue.toArray()));
        break;
    }
    }
    obj["Values"] = arr;
    _favorites = obj;
    save();
    return true;
}

void Favorites::removeValue(QJsonObject aNewValue) {
    return removeValue(QJsonValue(aNewValue));
}

void Favorites::removeValue(QJsonArray aNewValue) {
    return removeValue(QJsonValue(aNewValue));
}

bool Favorites::removeValue(QJsonObject aGame, QJsonObject aNewValue) {
    Settings::createDir(_path);
    QJsonObject obj;
    obj["Type"] = _favorites["Type"];
    QJsonArray arr;
    int indGame = -1;
    for (int i = 0; i < _favorites.value("Values").toArray().size(); i++) {
        if (_favorites.value("Values").toArray().at(i).toObject().value("game").toObject() == aGame) {
            indGame = i;
            break;
        }
    }
    if (indGame == -1) {
        return true;
    }
    QJsonObject obj2;
    obj2["game"] = aGame;
    QJsonArray arr2;
    for (auto favorite: _favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray()) {
        if (favorite.toObject() != aNewValue) {
            arr2.append(std::move(favorite));
        }
    }
    if (arr2.size() == 0) {
        removeGame(aGame);
        return false;
    }
    obj2["Values"] = arr2;
    //копируем все игры, заменив старую версию игры на новую
    for (int i = 0; i < _favorites.value("Values").toArray().size(); i++) {
        if (i == indGame) {
            arr.append(std::move(obj2));
        } else {
            arr.append(std::move(_favorites.value("Values").toArray().at(i)));
        }
    }
    obj["Values"] = arr;
    _favorites = obj;
    save();
    return true;
}

void Favorites::removeValue(QJsonValue aNewValue) {
    Settings::createDir(_path);
    QJsonObject obj;
    obj["Type"] = _favorites["Type"];
    QJsonArray arr;
    for (auto value: _favorites.value("Values").toArray()) {
        if (value != aNewValue) {
            arr.append(std::move(value));
        }
    }
    obj["Values"] = arr;
    _favorites = obj;
    save();
}

void Favorites::removeGame(QJsonObject aGame) {
    Settings::createDir(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;

    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()!=aGame)
            arr.append(std::move(_favorites.value("Values").toArray().at(i)));
    }
    obj["Values"]=arr;
    _favorites=obj;
    save();
}

int Favorites::addGame(QJsonObject aGame) {
    Settings::createDir(_path);
    QJsonObject obj;
    obj["Type"] = _favorites["Type"];
    QJsonArray arr;

    for (int i = 0; i < _favorites.value("Values").toArray().size(); i++) {
        if (_favorites.value("Values").toArray().at(i).toObject().value("game").toObject() != aGame) {
            arr.append(std::move(_favorites.value("Values").toArray().at(i)));
        } else {
            return i;
        }
    }
    QJsonObject newObj;
    newObj["game"] = aGame;
    newObj["Value"] = QJsonArray();
    arr.append(std::move(newObj));
    obj["Values"] = arr;
    _favorites = obj;
    save();
    return arr.size()-1;
}

bool Favorites::isInFavorites(QJsonObject aGame, QString aId) {
    QJsonArray favorites = getValues(aGame);
    return std::any_of(favorites.cbegin(), favorites.cend(),
                                      [=](QJsonValue id) { return aId == id.toObject().value("id").toString(); } );
}

QString Favorites::getType() {
    return _favorites.value("Type").toString();
}

QJsonArray Favorites::getValues() {
    return _favorites.value("Values").toArray();
}

void Favorites::save() {
    Settings::createDir(_path);
    QFile file(_path);
    file.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(_favorites);
    file.write(doc.toJson());
    file.close();
}
void Favorites::load() {
    QFile file(_path);
    if (file.exists()) {
        if (file.open(QFile::ReadOnly)) {
            _favorites = QJsonDocument().fromJson(file.readAll()).object();
            file.close();
        }
    }
}
