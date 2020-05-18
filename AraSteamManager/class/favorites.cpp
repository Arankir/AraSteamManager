#include "favorites.h"

Favorites::Favorites(QString a_path, QString a_type, QObject *parent) : QObject(parent),_path(a_path){
    Init(a_type);
}
void Favorites::SetType(QString a_type){
    _path=_setting._pathFavorites+a_type+".json";
    Init(a_type);
}
void Favorites::Init(QString a_type){
    Settings::CreateDir(_path);
    if(!QFile::exists(_path)){
        QJsonObject obj;
        obj["Type"]=a_type;
        QJsonArray arr;
        obj["Values"]=arr;
        _favorites=obj;
        Save();
    }
    Load();
}

QJsonArray Favorites::GetValues(QJsonObject a_game){
    for(auto value: _favorites.value("Values").toArray()){
        if(value.toObject().value("game").toObject()==a_game)
            return value.toObject().value("Values").toArray();
    }
    return QJsonArray();
}

bool Favorites::AddValue(QJsonObject a_newValue, bool a_deleteIfExist){
    return AddValue(a_newValue, a_deleteIfExist, jsonType::object);
}
bool Favorites::AddValue(QJsonArray a_newValue, bool a_deleteIfExist){
    return AddValue(a_newValue, a_deleteIfExist, jsonType::array);
}
bool Favorites::AddValue(QJsonObject a_game, QJsonObject a_newValue, bool a_deleteIfExist){
    Settings::CreateDir(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    int indGame=-1;
    //Узнаем индекс нужной игры
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()==a_game){
            indGame=i;
            break;
        }
    }
    //если её нет, создаем
    if(indGame==-1){
        indGame=AddGame(a_game);
    }
    //формируем массив избранных ачивок по этой игре
    QJsonObject obj2;
    obj2["game"]=a_game;
    QJsonArray arr2;
    for(auto value: _favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray()){
        if(value.toObject()==a_newValue)
            if(a_deleteIfExist){
                RemoveValue(a_game, a_newValue);
                return false;
            } else
                return false;
        else
            arr2.append(std::move(value));
    }
    arr2.append(std::move(a_newValue));
    obj2["Values"]=arr2;
    //копируем все игры, заменив старую версию игры на новую
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(i==indGame)
            arr.append(std::move(obj2));
        else
            arr.append(std::move(_favorites.value("Values").toArray().at(i)));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}
bool Favorites::AddValue(QJsonValue a_newValue, bool a_deleteIfExist, jsonType a_type){
    Settings::CreateDir(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(auto value: _favorites.value("Values").toArray()){
        if(value==a_newValue){
            if(a_deleteIfExist)
                RemoveValue(a_newValue);
            return false;
        } else
            arr.append(std::move(value));
    }
    switch (a_type) {
    case jsonType::object:{
        arr.append(std::move(a_newValue.toObject()));
        break;
    }
    case jsonType::array:{
        arr.append(std::move(a_newValue.toArray()));
        break;
    }
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}

void Favorites::RemoveValue(QJsonObject a_newValue){
    return RemoveValue(QJsonValue(a_newValue));
}
void Favorites::RemoveValue(QJsonArray a_newValue){
    return RemoveValue(QJsonValue(a_newValue));
}
bool Favorites::RemoveValue(QJsonObject a_game, QJsonObject a_newValue){
    Settings::CreateDir(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    int indGame=-1;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()==a_game){
            indGame=i;
            break;
        }
    }
    if(indGame==-1){
        return true;
    }
    QJsonObject obj2;
    obj2["game"]=a_game;
    QJsonArray arr2;
    for(int i=0;i<_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i).toObject()!=a_newValue)
            arr2.append(std::move(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i)));
        }
    if(arr2.size()==0){
        RemoveGame(a_game);
        return false;
    }
    obj2["Values"]=arr2;
    //копируем все игры, заменив старую версию игры на новую
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(i==indGame)
            arr.append(std::move(obj2));
        else
            arr.append(std::move(_favorites.value("Values").toArray().at(i)));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}
void Favorites::RemoveValue(QJsonValue a_newValue){
    Settings::CreateDir(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(auto value: _favorites.value("Values").toArray()){
        if(value!=a_newValue)
            arr.append(std::move(value));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}

void Favorites::RemoveGame(QJsonObject a_game){
    Settings::CreateDir(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;

    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()!=a_game)
            arr.append(std::move(_favorites.value("Values").toArray().at(i)));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}
int Favorites::AddGame(QJsonObject a_game){
    Settings::CreateDir(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;

    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()!=a_game)
            arr.append(std::move(_favorites.value("Values").toArray().at(i)));
        else
            return i;
    }
    QJsonObject newObj;
    newObj["game"]=a_game;
    newObj["Value"]=QJsonArray();
    arr.append(std::move(newObj));
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return arr.size()-1;
}

void Favorites::Save(){
    Settings::CreateDir(_path);
    QFile file(_path);
    file.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(_favorites);
    file.write(doc.toJson());
    file.close();
}
void Favorites::Load(){
    QFile file(_path);
    if(file.exists()){
        if(file.open(QFile::ReadOnly)){
            _favorites=QJsonDocument().fromJson(file.readAll()).object();
            file.close();
        }
    }
}
