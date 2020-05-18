#include "categoriesgame.h"

CategoriesGame::CategoriesGame(SGame a_game, QObject *parent) : QObject(parent),_game(a_game){
    ConvertOldCategories();
    LoadCategories();
}

void CategoriesGame::Update(){
    ConvertOldCategories();
    LoadCategories();
}

QList<QString> CategoriesGame::GetTitles(){
    QList<QString> list;
    for(auto title: _categories.value("Categories").toArray()){
        list.append(std::move(title.toObject().value("Title").toString()));
    }
    return list;
}
QList<QString> CategoriesGame::GetValues(int a_category, int a_value){
    QList<QString> list;
    for(auto achievement: _categories.value("Categories").toArray().at(a_category).toObject().value("Values").toArray().at(a_value).toObject().value("Achievements").toArray()){
        list.append(std::move(achievement.toString()));
    }
    return list;
}
QList<QString> CategoriesGame::GetNoValues(int a_category){
    QList<QString> list;
    for(auto noValue: _categories.value("Categories").toArray().at(a_category).toObject().value("NoValues").toArray()){
        list.append(std::move(noValue.toString()));
    }
    return list;
}

QFileInfoList CategoriesGame::GetFiles(QString a_path){
    Settings::CreateDir(a_path);
    QDir categoriesOld(a_path);
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    return categoriesOld.entryInfoList();
}
void CategoriesGame::ConvertOldCategories(){
    QFileInfoList listFiles = GetFiles(_setting._pathCategories+QString::number(_game._appID));
    if(!listFiles.isEmpty()){
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"]=_game._name;
        finalNew["GameID"]=_game._appID;
        for(auto &listFile: listFiles){
            QFile fileCategoryOld(_setting._pathCategories+QString::number(_game._appID)+"/"+listFile.fileName());
            fileCategoryOld.open(QFile::ReadOnly);
            QJsonDocument categoryOld=QJsonDocument().fromJson(fileCategoryOld.readAll());
            fileCategoryOld.close();

            QJsonObject categoryNew;
            categoryNew["Title"] = categoryOld.object().value("name").toString();
            QJsonArray ValuesNew;
            QJsonArray NoValuesNew;

            if(categoryOld.object().value("values").toArray().size() == 1){
                categoryNew["IsNoValues"] = 1;
                for(auto name: categoryOld.object().value(categoryOld.object().value("name").toString()).toArray()){
                    NoValuesNew.append(std::move(name.toString()));
                }
            } else {
                categoryNew["IsNoValues"]=0;
                for(auto value: categoryOld.object().value("values").toArray()){
                    QJsonObject valueNew;
                    valueNew["Title"]=value.toString();
                    QJsonArray achievementsNew;
                    for(auto newValue: categoryOld.object().value(value.toString()).toArray()){
                        achievementsNew.append(std::move(newValue.toString()));
                    }
                    valueNew["Achievements"]=achievementsNew;
                    ValuesNew.append(std::move(valueNew));
                }
            }
            categoryNew["Values"] = ValuesNew;
            categoryNew["NoValues"] = NoValuesNew;
            categoriesNew.append(std::move(categoryNew));
        }
        finalNew["Categories"]=categoriesNew;
        _categories=std::move(finalNew);
        Save();
        QDir categoriesOld(_setting._pathCategories+QString::number(_game._appID));
        categoriesOld.removeRecursively();
    }
}
void CategoriesGame::Save(){
    Settings::CreateDir(_setting._pathCategories);
    QFile fileCategory(_setting._pathCategories+QString::number(_game._appID)+".json");
    fileCategory.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(_categories);
    fileCategory.write(doc.toJson());
    fileCategory.close();
    LoadCategories();
}
void CategoriesGame::LoadCategories(){
    QFile fileCategory(_setting._pathCategories+QString::number(_game._appID)+".json");
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
    if(a_category>=_categories.value("Categories").toArray().size()){
        for(auto category: _categories.value("Categories").toArray()){
            arr.append(std::move(category));
        }
        arr.append(std::move(a_newCategory));
    } else {
        for(int i=0;i<_categories.value("Categories").toArray().size();i++)
            if(i!=a_category)
                arr.append(std::move(_categories.value("Categories").toArray().at(i)));
            else
                arr.append(std::move(a_newCategory));
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
            arr.append(std::move(_categories.value("Categories").toArray().at(i)));
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

//CategoriesGame& CategoriesGame::operator=(const CategoriesGame& a_newCategoriesGame){
//    _categories=a_newCategoriesGame._categories;
//    _game=a_newCategoriesGame._game;
//    return *this;
//}
