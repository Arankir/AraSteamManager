#include "categoriesgame.h"

CategoriesGame::CategoriesGame(SGame a_game, QObject *parent) : QObject(parent){
    _game=a_game;
    _setting.CreateFile(_setting._pathCategories+QString::number(a_game.GetAppid()));
    QDir categoriesOld(_setting._pathCategories+QString::number(a_game.GetAppid()));
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    if(categoriesOld.exists()){
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"]=a_game.GetName();
        finalNew["GameID"]=a_game.GetAppid();
        QFileInfoList list = categoriesOld.entryInfoList();
        for (int i=0;i<list.size();++i){
            QFile fileCategoryOld(_setting._pathCategories+QString::number(a_game.GetAppid())+"/"+list.at(i).fileName());
            fileCategoryOld.open(QFile::ReadOnly);
            QJsonDocument categoryOld=QJsonDocument().fromJson(fileCategoryOld.readAll());

            QJsonObject categoryNew;
            categoryNew["Title"]=categoryOld.object().value("name").toString();
            QJsonArray ValuesNew;
            QJsonArray NoValuesNew;

            if(categoryOld.object().value("values").toArray().size()==1){
                categoryNew["IsNoValues"]=1;
                for (int j=0;j<categoryOld.object().value(categoryOld.object().value("name").toString()).toArray().size();j++) {
                    NoValuesNew.append(categoryOld.object().value(categoryOld.object().value("name").toString()).toArray().at(j).toString());
                }
            } else {
                categoryNew["IsNoValues"]=0;
                for (int i=0;i<categoryOld.object().value("values").toArray().size();i++) {
                    QJsonObject valueNew;
                    valueNew["Title"]=categoryOld.object().value("values").toArray().at(i).toString();
                    QJsonArray achievementsNew;
                    for (int j=0;j<categoryOld.object().value(categoryOld.object().value("values").toArray().at(i).toString()).toArray().size();j++) {
                        achievementsNew.append(categoryOld.object().value(categoryOld.object().value("values").toArray().at(i).toString()).toArray().at(j).toString());
                    }
                    valueNew["Achievements"]=achievementsNew;
                    ValuesNew.append(valueNew);
                }
            }
            fileCategoryOld.close();
            categoryNew["Values"]=ValuesNew;
            categoryNew["NoValues"]=NoValuesNew;
            categoriesNew.append(categoryNew);
            }
        finalNew["Categories"]=categoriesNew;
        categoriesGameNew.setObject(finalNew);
        QFile fileCategoryNew(_setting._pathCategories+QString::number(a_game.GetAppid())+".json");
        fileCategoryNew.open(QFile::WriteOnly);
        fileCategoryNew.write(categoriesGameNew.toJson());
        fileCategoryNew.close();
        categoriesOld.removeRecursively();
    }

    QFile fileCategory(_setting._pathCategories+QString::number(a_game.GetAppid())+".json");
    if(fileCategory.exists()){
        if(fileCategory.open(QFile::ReadOnly)){
            _categories=QJsonDocument().fromJson(fileCategory.readAll()).object();
            fileCategory.close();
        }
    }
}

QList<QString> CategoriesGame::GetTitles(){
    QList<QString> list;
    for(int i=0;i<_categories.value("Categories").toArray().size();i++){
        list.append(GetTitle(i));
    }
    return list;
}
QString CategoriesGame::GetTitle(int a_index){
    return _categories.value("Categories").toArray().at(a_index).toObject().value("Title").toString();
}
int CategoriesGame::GetIsNoValues(int a_index){
    return _categories.value("Categories").toArray().at(a_index).toObject().value("IsNoValues").toInt();
}
QJsonArray CategoriesGame::GetValues(int a_value){
    return _categories.value("Categories").toArray().at(a_value).toObject().value("Values").toArray();
}
QList<QString> CategoriesGame::GetValues(int a_category, int a_value){
    QList<QString> list;
    for(int i=0;i<_categories.value("Categories").toArray().at(a_category).toObject().value("Values").toArray().at(a_value).toObject().value("Achievements").toArray().size();i++){
        list.append(_categories.value("Categories").toArray().at(a_category).toObject().value("Values").toArray().at(a_value).toObject().value("Achievements").toArray().at(i).toString());
    }
    return list;
}
QList<QString> CategoriesGame::GetNoValues(int a_category){
    QList<QString> list;
    for(int i=0;i<_categories.value("Categories").toArray().at(a_category).toObject().value("NoValues").toArray().size();i++){
        list.append(_categories.value("Categories").toArray().at(a_category).toObject().value("NoValues").toArray().at(i).toString());
    }
    return list;
}
QString CategoriesGame::GetGame(){
    return _categories.value("Game").toString();
}
int CategoriesGame::GetGameID(){
    return _categories.value("GameID").toInt();
}
void CategoriesGame::Set(SGame a_game){
    _game=a_game;
    QDir categoriesOld(_setting._pathCategories+QString::number(a_game.GetAppid()));
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    if(categoriesOld.exists()){
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"]=a_game.GetName();
        finalNew["GameID"]=a_game.GetAppid();
        QFileInfoList list = categoriesOld.entryInfoList();
        for (int i=0;i<list.size();++i){
            QFile fileCategoryOld(_setting._pathCategories+QString::number(a_game.GetAppid())+"/"+list.at(i).fileName());
            fileCategoryOld.open(QFile::ReadOnly);
            QJsonDocument categoryOld=QJsonDocument().fromJson(fileCategoryOld.readAll());

            QJsonObject categoryNew;
            categoryNew["Title"]=categoryOld.object().value("name").toString();
            QJsonArray ValuesNew;
            QJsonArray NoValuesNew;

            if(categoryOld.object().value("values").toArray().size()==1){
                categoryNew["IsNoValues"]=1;
                for (int j=0;j<categoryOld.object().value(categoryOld.object().value("name").toString()).toArray().size();j++) {
                    NoValuesNew.append(categoryOld.object().value(categoryOld.object().value("name").toString()).toArray().at(j).toString());
                }
            } else {
                categoryNew["IsNoValues"]=0;
                for (int i=0;i<categoryOld.object().value("values").toArray().size();i++) {
                    QJsonObject valueNew;
                    valueNew["Title"]=categoryOld.object().value("values").toArray().at(i).toString();
                    QJsonArray achievementsNew;
                    for (int j=0;j<categoryOld.object().value(categoryOld.object().value("values").toArray().at(i).toString()).toArray().size();j++) {
                        achievementsNew.append(categoryOld.object().value(categoryOld.object().value("values").toArray().at(i).toString()).toArray().at(j).toString());
                    }
                    valueNew["Achievements"]=achievementsNew;
                    ValuesNew.append(valueNew);
                }
            }
            fileCategoryOld.close();
            categoryNew["Values"]=ValuesNew;
            categoryNew["NoValues"]=NoValuesNew;
            categoriesNew.append(categoryNew);
            }
        finalNew["Categories"]=categoriesNew;
        categoriesGameNew.setObject(finalNew);
        QFile fileCategoryNew(_setting._pathCategories+QString::number(a_game.GetAppid())+".json");
        fileCategoryNew.open(QFile::WriteOnly);
        fileCategoryNew.write(categoriesGameNew.toJson());
        fileCategoryNew.close();
        categoriesOld.removeRecursively();
    }

    QFile fileCategory(_setting._pathCategories+QString::number(a_game.GetAppid())+".json");
    if(fileCategory.exists()){
        if(fileCategory.open(QFile::ReadOnly)){
            _categories=QJsonDocument().fromJson(fileCategory.readAll()).object();
            fileCategory.close();
        }
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
    Set(_game);
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

CategoriesGame::CategoriesGame(const CategoriesGame& a_newCategoriesGame){
    _categories=a_newCategoriesGame._categories;
    _game=a_newCategoriesGame._game;
}
CategoriesGame& CategoriesGame::operator=(const CategoriesGame& a_newCategoriesGame){
    _categories=a_newCategoriesGame._categories;
    _game=a_newCategoriesGame._game;
    return *this;
}
