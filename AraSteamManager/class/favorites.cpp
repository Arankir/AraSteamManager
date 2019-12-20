#include "favorites.h"

Favorites::Favorites(QString Apath, QString Atype, QObject *parent) : QObject(parent){
    _path=Apath;
    _setting.CreateFile(Apath);
    if(!QFile::exists(Apath)){
        QJsonObject obj;
        obj["Type"]=Atype;
        QJsonArray arr;
        obj["Values"]=arr;
        _favorites=obj;
        Save();
    }
    QFile file(Apath);
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
QJsonArray Favorites::GetValues(QJsonObject Agame){
    for(int i=0;i<_favorites.value("Values").toArray().size();i++)
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()==Agame)
            return _favorites.value("Values").toArray().at(i).toObject().value("Values").toArray();
    return QJsonArray();
}
void Favorites::SetPath(QString Apath, QString Atype){
    _path=Apath;
    _setting.CreateFile(Apath);
    if(!QFile::exists(Apath)){
        QJsonObject obj;
        obj["Type"]=Atype;
        QJsonArray arr;
        obj["Values"]=arr;
        _favorites=obj;
        Save();
    }
    QFile file(Apath);
    if(file.exists()){
        if(file.open(QFile::ReadOnly)){
            _favorites=QJsonDocument().fromJson(file.readAll()).object();
            file.close();
        }
    }
}
void Favorites::SetType(QString Atype){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=Atype;
    obj["Values"]=_favorites.value("Values");
    _favorites=obj;
    Save();
}

bool Favorites::AddValue(QJsonObject AnewValue, bool AdeleteIfExist){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject()==AnewValue){
            if(AdeleteIfExist)
                RemoveValue(AnewValue);
            return false;
        } else
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    arr.append(AnewValue);
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}
bool Favorites::AddValue(QJsonArray AnewValue, bool AdeleteIfExist){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toArray()==AnewValue){
            if(AdeleteIfExist)
                RemoveValue(AnewValue);
            return false;
        } else
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    arr.append(AnewValue);
    obj["Values"]=arr;
    _favorites=obj;
    Save();
    return true;
}
bool Favorites::AddValue(QJsonObject Agame, QJsonObject AnewValue, bool AdeleteIfExist){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    int indGame=-1;
    //Узнаем индекс нужной игры
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()==Agame){
            indGame=i;
            break;
        }
    }
    //если её нет, создаем
    if(indGame==-1){
        indGame=AddGame(Agame);
    }
    //формируем массив избранных ачивок по этой игре
    QJsonObject obj2;
    obj2["game"]=Agame;
    QJsonArray arr2;
    for(int i=0;i<_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i).toObject()==AnewValue)
            if(AdeleteIfExist){
                RemoveValue(Agame, AnewValue);
                return false;
            } else
                return false;
        else
            arr2.append(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i));
        }
    arr2.append(AnewValue);
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

void Favorites::RemoveValue(QJsonObject AnewValue){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject()!=AnewValue)
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}
void Favorites::RemoveValue(QJsonArray AnewValue){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toArray()!=AnewValue)
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}
bool Favorites::RemoveValue(QJsonObject Agame, QJsonObject AnewValue){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    int indGame=-1;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()==Agame){
            indGame=i;
            break;
        }
    }
    if(indGame==-1){
        return true;
    }
    QJsonObject obj2;
    obj2["game"]=Agame;
    QJsonArray arr2;
    for(int i=0;i<_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i).toObject()!=AnewValue)
            arr2.append(_favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i));
        }
    if(arr2.size()==0){
        RemoveGame(Agame);
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

void Favorites::RemoveGame(QJsonObject Agame){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()!=Agame)
            arr.append(_favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    _favorites=obj;
    Save();
}
int Favorites::AddGame(QJsonObject Agame){
    _setting.CreateFile(_path);
    QJsonObject obj;
    obj["Type"]=_favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<_favorites.value("Values").toArray().size();i++){
        if(_favorites.value("Values").toArray().at(i).toObject().value("game").toObject()!=Agame)
            arr.append(_favorites.value("Values").toArray().at(i));
        else
            return i;
    }
    QJsonObject newObj;
    newObj["game"]=Agame;
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
