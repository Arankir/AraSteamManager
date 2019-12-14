#include "favorites.h"

Favorites::Favorites(QString APath, QString AType, QObject *parent) : QObject(parent){
    _path=APath;
    _setting.CreateFile(APath);
    if(!QFile::exists(APath)){
        QJsonObject obj;
        obj["Type"]=AType;
        QJsonArray arr;
        obj["Values"]=arr;
        _favorites=obj;
        Save();
    }
    QFile file(APath);
    if(file.exists()){
        if(file.open(QFile::ReadOnly)){
            _favorites=QJsonDocument().fromJson(file.readAll()).object();
            file.close();
        }
    }
}
Favorites::Favorites(){

}

QString Favorites::GetType(){
    return _favorites.value("Type").toString();
}
QJsonArray Favorites::GetValues(){
    return _favorites.value("Values").toArray();
}
QJsonArray Favorites::GetValues(QJsonObject AGame){
    for(int i=0;i<_favorites.value("Values").toArray().size();i++)
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()==AGame)
            return _favorites.value("Values").toArray().at(i).toObject().value("Values").toArray();
    return QJsonArray();
}
void Favorites::SetPath(QString APath, QString AType){
    _path=APath;
    _setting.CreateFile(APath);
    if(!QFile::exists(APath)){
        QJsonObject obj;
        obj["Type"]=AType;
        QJsonArray arr;
        obj["Values"]=arr;
        _favorites=obj;
        Save();
    }
    QFile file(APath);
    if(file.exists()){
        if(file.open(QFile::ReadOnly)){
            _favorites=QJsonDocument().fromJson(file.readAll()).object();
            file.close();
        }
    }
}
void Favorites::SetType(QString AType){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=AType;
    obj["Values"]=_favorites.value("Values");
    _favorites=obj;
    Save();
}

bool Favorites::AddValue(QJsonObject ANewValue, bool ADeleteIfExist){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject()==ANewValue){
            if(ADeleteIfExist)
                RemoveValue(ANewValue);
            return false;
        } else
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    arr.append(ANewValue);
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}
bool Favorites::AddValue(QJsonArray ANewValue, bool ADeleteIfExist){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toArray()==ANewValue){
            if(ADeleteIfExist)
                RemoveValue(ANewValue);
            return false;
        } else
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    arr.append(ANewValue);
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}
bool Favorites::AddValue(QJsonObject AGame, QJsonObject ANewValue, bool ADeleteIfExist){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    int indGame=-1;
    //Узнаем индекс нужной игры
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()==AGame){
            indGame=i;
            break;
        }
    }
    //если её нет, создаем
    if(indGame==-1){
        indGame=AddGame(AGame);
    }
    //формируем массив избранных ачивок по этой игре
    QJsonObject obj2;
    obj2["game"]=AGame;
    QJsonArray arr2;
    for(int i=0;i<_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i).toObject()==ANewValue)
            if(ADeleteIfExist){
                RemoveValue(AGame, ANewValue);
                return false;
            } else
                return false;
        else
            arr2.append(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i));
        }
    arr2.append(ANewValue);
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

void Favorites::RemoveValue(QJsonObject ANewValue){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject()!=ANewValue)
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}
void Favorites::RemoveValue(QJsonArray ANewValue){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toArray()!=ANewValue)
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}
bool Favorites::RemoveValue(QJsonObject AGame, QJsonObject ANewValue){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    int indGame=-1;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()==AGame){
            indGame=i;
            break;
        }
    }
    if(indGame==-1){
        return true;
    }
    QJsonObject obj2;
    obj2["game"]=AGame;
    QJsonArray arr2;
    for(int i=0;i<_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i).toObject()!=ANewValue)
            arr2.append(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i));
        }
    if(arr2.size()==0){
        RemoveGame(AGame);
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

void Favorites::RemoveGame(QJsonObject AGame){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()!=AGame)
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}
int Favorites::AddGame(QJsonObject AGame){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()!=AGame)
            arr.append(_favorites.value("Values").toArray().at(i));
        else
            return i;
    }
    QJsonObject newObj;
    newObj["game"]=AGame;
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
