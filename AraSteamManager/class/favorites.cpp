#include "favorites.h"

Favorites::Favorites(QString a_path, QString a_type, QObject *parent) : QObject(parent),_path(a_path){
    _setting.CreateFile(a_path);
    if(!QFile::exists(a_path)){
        QJsonObject obj;
        obj["Type"]=a_type;
        QJsonArray arr;
        obj["Values"]=arr;
        _favorites=obj;
        Save();
    }
    QFile file(a_path);
    if(file.exists()){
        if(file.open(QFile::ReadOnly)){
            _favorites=QJsonDocument().fromJson(file.readAll()).object();
            file.close();
        }
    }
}
Favorites::Favorites(QObject *parent) : QObject(parent){}

QString Favorites::GetType(){
    return _favorites.value("Type").toString();
}
QJsonArray Favorites::GetValues(){
    return _favorites.value("Values").toArray();
}
QJsonArray Favorites::GetValues(QJsonObject a_game){
    for(int i=0;i<_favorites.value("Values").toArray().size();i++)
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()==a_game)
            return _favorites.value("Values").toArray().at(i).toObject().value("Values").toArray();
    return QJsonArray();
}
void Favorites::SetType(QString a_type){
    _path=_setting._pathFavorites+a_type+".json";
    _setting.CreateFile(_path);
    if(!QFile::exists(_path)){
        QJsonObject obj;
        obj["Type"]=a_type;
        QJsonArray arr;
        obj["Values"]=arr;
        _favorites=obj;
        Save();
    }
    QFile file(_path);
    if(file.exists()){
        if(file.open(QFile::ReadOnly)){
            _favorites=QJsonDocument().fromJson(file.readAll()).object();
            file.close();
        }
    }
}

bool Favorites::AddValue(QJsonObject a_newValue, bool a_deleteIfExist){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject()==a_newValue){
            if(a_deleteIfExist)
                RemoveValue(a_newValue);
            return false;
        } else
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    arr.append(a_newValue);
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}
bool Favorites::AddValue(QJsonArray a_newValue, bool a_deleteIfExist){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toArray()==a_newValue){
            if(a_deleteIfExist)
                RemoveValue(a_newValue);
            return false;
        } else
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    arr.append(a_newValue);
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}
bool Favorites::AddValue(QJsonObject a_game, QJsonObject a_newValue, bool a_deleteIfExist){
    _setting.CreateFile(_path);
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
    for(int i=0;i<_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i).toObject()==a_newValue)
            if(a_deleteIfExist){
                RemoveValue(a_game, a_newValue);
                return false;
            } else
                return false;
        else
            arr2.append(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i));
        }
    arr2.append(a_newValue);
    obj2["Values"]=arr2;
    //копируем все игры, заменив старую версию игры на новую
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(i==indGame)
            arr.append(obj2);
        else
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}

void Favorites::RemoveValue(QJsonObject a_newValue){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject()!=a_newValue)
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}
void Favorites::RemoveValue(QJsonArray a_newValue){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toArray()!=a_newValue)
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}
bool Favorites::RemoveValue(QJsonObject a_game, QJsonObject a_newValue){
    _setting.CreateFile(_path);
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
            arr2.append(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i));
        }
    if(arr2.size()==0){
        RemoveGame(a_game);
        return false;
    }
    obj2["Values"]=arr2;
    //копируем все игры, заменив старую версию игры на новую
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(i==indGame)
            arr.append(obj2);
        else
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}

void Favorites::RemoveGame(QJsonObject a_game){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()!=a_game)
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}
int Favorites::AddGame(QJsonObject a_game){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()!=a_game)
            arr.append(_favorites.value("Values").toArray().at(i));
        else
            return i;
    }
    QJsonObject newObj;
    newObj["game"]=a_game;
    newObj["Value"]=QJsonArray();
    arr.append(newObj);
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return arr.size()-1;
}

void Favorites::Save(){
    _setting.CreateFile(_path);
    QFile file(_path);
    file.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(_favorites);
    file.write(doc.toJson());
    file.close();
}
