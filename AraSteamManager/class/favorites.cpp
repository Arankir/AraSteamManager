#include "favorites.h"

Favorites::Favorites(QString path, QString type, QObject *parent) : QObject(parent){
    SetPath(path,type);
}
Favorites::Favorites(){

}

void Favorites::SetPath(QString path, QString type){
    this->path=path;
    Setting.CreateFile(path);
    if(!QFile::exists(path)){
        QJsonObject obj;
        obj["Type"]=type;
        QJsonArray arr;
        obj["Values"]=arr;
        favorites=obj;
        Save();
    }
    QFile file(path);
    if(file.exists()){
        if(file.open(QFile::ReadOnly)){
            favorites=QJsonDocument().fromJson(file.readAll()).object();
            file.close();
        }
    }
}
void Favorites::SetType(QString type){
    Setting.CreateFile(path);
    QJsonObject obj;
    obj["Type"]=type;
    obj["Values"]=favorites.value("Values");
    favorites=obj;
    Save();
}

bool Favorites::AddValue(QJsonObject newValue, bool deleteIfExist){
    Setting.CreateFile(path);
    QJsonObject obj;
    obj["Type"]=favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<favorites.value("Values").toArray().size();i++){
        if(favorites.value("Values").toArray().at(i).toObject()==newValue)
            if(deleteIfExist){
                RemoveValue(newValue);
                return false;
            } else
                return false;
        else
            arr.append(favorites.value("Values").toArray().at(i));
    }
    arr.append(newValue);
    obj["Values"]=arr;
    favorites=obj;
    Save();
    return true;
}
void Favorites::RemoveValue(QJsonObject newValue){
    Setting.CreateFile(path);
    QJsonObject obj;
    obj["Type"]=favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<favorites.value("Values").toArray().size();i++){
        if(favorites.value("Values").toArray().at(i).toObject()!=newValue)
            arr.append(favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    favorites=obj;
    Save();
}
bool Favorites::AddValue(QJsonArray newValue, bool deleteIfExist){
    Setting.CreateFile(path);
    QJsonObject obj;
    obj["Type"]=favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<favorites.value("Values").toArray().size();i++){
        if(favorites.value("Values").toArray().at(i).toArray()==newValue)
            if(deleteIfExist){
                RemoveValue(newValue);
                return false;
            } else
                return false;
        else
            arr.append(favorites.value("Values").toArray().at(i));
    }
    arr.append(newValue);
    obj["Values"]=arr;
    favorites=obj;
    Save();
    return true;
}
void Favorites::RemoveValue(QJsonArray newValue){
    Setting.CreateFile(path);
    QJsonObject obj;
    obj["Type"]=favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<favorites.value("Values").toArray().size();i++){
        if(favorites.value("Values").toArray().at(i).toArray()!=newValue)
            arr.append(favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    favorites=obj;
    Save();
}
bool Favorites::AddValue(QString game, QJsonObject newValue, bool deleteIfExist){
    Setting.CreateFile(path);
    QJsonObject obj;
    obj["Type"]=favorites["Type"];
    QJsonArray arr;
    int indGame=-1;
    //Узнаем индекс нужной игры
    for(int i=0;i<favorites.value("Values").toArray().size();i++){
        if(favorites.value("Values").toArray().at(i).toObject().value("game").toString()==game){
            indGame=i;
            break;
        }
    }
    //если её нет, создаем
    if(indGame==-1){
        indGame=AddGame(game);
    }
    //формируем массив избранных ачивок по этой игре
    QJsonObject obj2;
    obj2["game"]=game;
    QJsonArray arr2;
    for(int i=0;i<favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().size();i++){
        if(favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i).toObject()==newValue)
            if(deleteIfExist){
                RemoveValue(game, newValue);
                return false;
            } else
                return false;
        else
            arr2.append(favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i));
        }
    arr2.append(newValue);
    obj2["Values"]=arr2;
    //копируем все игры, заменив старую версию игры на новую
    for(int i=0;i<favorites.value("Values").toArray().size();i++){
        if(i==indGame)
            arr.append(obj2);
        else
            arr.append(favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    favorites=obj;
    Save();
    return true;
}
bool Favorites::RemoveValue(QString game, QJsonObject newValue){
    Setting.CreateFile(path);
    QJsonObject obj;
    obj["Type"]=favorites["Type"];
    QJsonArray arr;
    int indGame=-1;
    for(int i=0;i<favorites.value("Values").toArray().size();i++){
        if(favorites.value("Values").toArray().at(i).toObject().value("game").toString()==game){
            indGame=i;
            break;
        }
    }
    if(indGame==-1){
        return true;
    }
    QJsonObject obj2;
    obj2["game"]=game;
    QJsonArray arr2;
    for(int i=0;i<favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().size();i++){
        if(favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i).toObject()!=newValue)
            arr2.append(favorites.value("Values").toArray().at(indGame).toObject().value("Values").toArray().at(i));
        }
    arr2.append(newValue);
    obj2["Values"]=arr2;
    //копируем все игры, заменив старую версию игры на новую
    for(int i=0;i<favorites.value("Values").toArray().size();i++){
        if(i==indGame)
            arr.append(obj2);
        else
            arr.append(favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    favorites=obj;
    Save();
    return true;
}
void Favorites::RemoveGame(QString game){
    Setting.CreateFile(path);
    QJsonObject obj;
    obj["Type"]=favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<favorites.value("Values").toArray().size();i++){
        if(favorites.value("Values").toArray().at(i).toObject().value("game")!=game)
            arr.append(favorites.value("Values").toArray().at(i));
    }
    obj["Values"]=arr;
    favorites=obj;
    Save();
}
int Favorites::AddGame(QString game){
    Setting.CreateFile(path);
    QJsonObject obj;
    obj["Type"]=favorites["Type"];
    QJsonArray arr;
    for(int i=0;i<favorites.value("Values").toArray().size();i++){
        if(favorites.value("Values").toArray().at(i).toObject().value("game")!=game)
            arr.append(favorites.value("Values").toArray().at(i));
        else
            return i;
    }
    QJsonObject newObj;
    newObj["game"]=game;
    newObj["Value"]=QJsonArray();
    arr.append(newObj);
    obj["Values"]=arr;
    favorites=obj;
    Save();
    return arr.size()-1;
}

QString Favorites::GetType(){
    return favorites.value("Type").toString();
}
QJsonArray Favorites::GetValues(){
    return favorites.value("Values").toArray();
}

void Favorites::Save(){
    Setting.CreateFile(path);
    QFile file(path);
    file.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(favorites);
    file.write(doc.toJson());
    file.close();
}
