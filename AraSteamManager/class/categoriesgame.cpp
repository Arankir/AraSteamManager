#include "categoriesgame.h"

CategoriesGame::CategoriesGame(SGame a_game, QObject *parent) : QObject(parent),_game(a_game){
    ConvertOldCategories();
    LoadCategories();
}

void CategoriesGame::SetGame(SGame a_game){
    _game=a_game;
    ConvertOldCategories();
    LoadCategories();
}

QList<QString> CategoriesGame::GetTitles(){
    QList<QString> list;
    for(auto title: _categories.value("Categories").toArray()){
        list.append(title.toObject().value("Title").toString());
    }
    return list;
}
QList<QString> CategoriesGame::GetValues(int a_category, int a_value){
    QList<QString> list;
    for(auto achievement: _categories.value("Categories").toArray().at(a_category).toObject().value("Values").toArray().at(a_value).toObject().value("Achievements").toArray()){
        list.append(achievement.toString());
    }
    return list;
}
QList<QString> CategoriesGame::GetNoValues(int a_category){
    QList<QString> list;
    for(auto noValue: _categories.value("Categories").toArray().at(a_category).toObject().value("NoValues").toArray()){
        list.append(noValue.toString());
    }
    return list;
}

QFileInfoList CategoriesGame::GetFiles(QString a_path){
    _setting.CreateFile(a_path);
    QDir categoriesOld(a_path);
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    return categoriesOld.entryInfoList();
}
void CategoriesGame::ConvertOldCategories(){
    QFileInfoList listFiles = GetFiles(_setting._pathCategories+QString::number(_game.GetAppid()));
    if(!listFiles.isEmpty()){
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"]=_game.GetName();
        finalNew["GameID"]=_game.GetAppid();
        for(auto &listFile: listFiles){
            QFile fileCategoryOld(_setting._pathCategories+QString::number(_game.GetAppid())+"/"+listFile.fileName());
            fileCategoryOld.open(QFile::ReadOnly);
            QJsonDocument categoryOld=QJsonDocument().fromJson(fileCategoryOld.readAll());

            QJsonObject categoryNew;
            categoryNew["Title"] = categoryOld.object().value("name").toString();
            QJsonArray ValuesNew;
            QJsonArray NoValuesNew;

            if(categoryOld.object().value("values").toArray().size() == 1){
                categoryNew["IsNoValues"] = 1;
                for(auto name: categoryOld.object().value(categoryOld.object().value("name").toString()).toArray()){
                    NoValuesNew.append(name.toString());
                }
            } else {
                categoryNew["IsNoValues"]=0;
                for(auto value: categoryOld.object().value("values").toArray()){
                    QJsonObject valueNew;
                    valueNew["Title"]=value.toString();
                    QJsonArray achievementsNew;
                    for(auto newValue: categoryOld.object().value(value.toString()).toArray()){
                        achievementsNew.append(newValue.toString());
                    }
                    valueNew["Achievements"]=achievementsNew;
                    ValuesNew.append(valueNew);
                }
            }
            fileCategoryOld.close();
            categoryNew["Values"] = ValuesNew;
            categoryNew["NoValues"] = NoValuesNew;
            categoriesNew.append(std::move(categoryNew));
        }
        finalNew["Categories"]=categoriesNew;
        categoriesGameNew.setObject(finalNew);
        QFile fileCategoryNew(_setting._pathCategories+QString::number(_game.GetAppid())+".json");
        fileCategoryNew.open(QFile::WriteOnly);
        fileCategoryNew.write(categoriesGameNew.toJson());
        fileCategoryNew.close();
        QDir categoriesOld(_setting._pathCategories+QString::number(_game.GetAppid()));
        categoriesOld.removeRecursively();
    }
}
void CategoriesGame::Save(){
    _setting.CreateFile(_setting._pathCategories);
    QFile fileCategoryNew(_setting._pathCategories+QString::number(_game.GetAppid())+".json");
    fileCategoryNew.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(_categories);
    fileCategoryNew.write(doc.toJson());
    fileCategoryNew.close();
    LoadCategories();
}
void CategoriesGame::LoadCategories(){
    QFile fileCategory(_setting._pathCategories+QString::number(_game.GetAppid())+".json");
    if(fileCategory.exists()){
        if(fileCategory.open(QFile::ReadOnly)){
            _categories=QJsonDocument().fromJson(fileCategory.readAll()).object();
            fileCategory.close();
        }
    }
}

void CategoriesGame::ChangeCategory(int a_category, QJsonObject a_newCategory){
    QJsonObject obj;
    obj["Game"]=_categories["Game"];
    obj["GameID"]=_categories["GameID"];
    QJsonArray arr;
    if(a_category==_categories.value("Categories").toArray().size()){
        for(int i=0;i<_categories.value("Categories").toArray().size();i++)
                arr.append(_categories.value("Categories").toArray().at(i));
        arr.append(a_newCategory);
    } else {
        for(int i=0;i<_categories.value("Categories").toArray().size();i++)
            if(i!=a_category)
                arr.append(_categories.value("Categories").toArray().at(i));
            else
                arr.append(a_newCategory);
    }
    obj["Categories"]=arr;
    _categories=obj;
//    if(category==categories.value("Categories").toArray().size())
//        categories.value("Categories").toArray().append(newCategory);
//    else
//        categories.value("Categories").toArray().at(category).toObject()=newCategory;
    Save();
}
void CategoriesGame::DeleteCategory(int a_index){
    QJsonObject obj;
    obj["Game"]=_categories["Game"];
    obj["GameID"]=_categories["GameID"];
    QJsonArray arr;
    for(int i=0;i<_categories.value("Categories").toArray().size();i++)
        if(i!=a_index)
            arr.append(_categories.value("Categories").toArray().at(i));
    obj["Categories"]=arr;
    _categories=obj;
    Save();
}
void CategoriesGame::DeleteAll(){
    QJsonObject obj;
    obj["Game"]=_categories["Game"];
    obj["GameID"]=_categories["GameID"];
    QJsonArray arr;
    obj["Categories"]=arr;
    _categories=obj;
    Save();
}

CategoriesGame::CategoriesGame(const CategoriesGame& a_newCategoriesGame){
    _categories=a_newCategoriesGame._categories;
    _game=a_newCategoriesGame._game;
}
CategoriesGame& CategoriesGame::operator=(const CategoriesGame& a_newCategoriesGame){
    _categories=a_newCategoriesGame._categories;
    _game=a_newCategoriesGame._game;
    return *this;
}
