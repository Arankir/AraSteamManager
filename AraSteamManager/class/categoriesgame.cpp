#include "categoriesgame.h"

CategoriesGame::CategoriesGame(SGame AGame, QObject *parent) : QObject(parent){
    _game=AGame;
    QDir categoriesOld("Files/Categories/"+QString::number(AGame.GetAppid()));
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    if(categoriesOld.exists()){
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"]=AGame.GetName();
        finalNew["GameID"]=AGame.GetAppid();
        QFileInfoList list = categoriesOld.entryInfoList();
        for (int i=0;i<list.size();++i){
            QFile fileCategoryOld("Files/Categories/"+QString::number(AGame.GetAppid())+"/"+list.at(i).fileName());
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
        QFile fileCategoryNew("Files/Categories/"+QString::number(AGame.GetAppid())+".json");
        fileCategoryNew.open(QFile::WriteOnly);
        fileCategoryNew.write(categoriesGameNew.toJson());
        fileCategoryNew.close();
        categoriesOld.removeRecursively();
    }

    QFile fileCategory("Files/Categories/"+QString::number(AGame.GetAppid())+".json");
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
QString CategoriesGame::GetTitle(int AIndex){
    return _categories.value("Categories").toArray().at(AIndex).toObject().value("Title").toString();
}
int CategoriesGame::GetIsNoValues(int AIndex){
    return _categories.value("Categories").toArray().at(AIndex).toObject().value("IsNoValues").toInt();
}
QJsonArray CategoriesGame::GetValues(int AValue){
    return _categories.value("Categories").toArray().at(AValue).toObject().value("Values").toArray();
}
QList<QString> CategoriesGame::GetValues(int ACategory, int AValue){
    QList<QString> list;
    for(int i=0;i<_categories.value("Categories").toArray().at(ACategory).toObject().value("Values").toArray().at(AValue).toObject().value("Achievements").toArray().size();i++){
        list.append(_categories.value("Categories").toArray().at(ACategory).toObject().value("Values").toArray().at(AValue).toObject().value("Achievements").toArray().at(i).toString());
    }
    return list;
}
QList<QString> CategoriesGame::GetNoValues(int ACategory){
    QList<QString> list;
    for(int i=0;i<_categories.value("Categories").toArray().at(ACategory).toObject().value("NoValues").toArray().size();i++){
        list.append(_categories.value("Categories").toArray().at(ACategory).toObject().value("NoValues").toArray().at(i).toString());
    }
    return list;
}
QString CategoriesGame::GetGame(){
    return _categories.value("Game").toString();
}
int CategoriesGame::GetGameID(){
    return _categories.value("GameID").toInt();
}
void CategoriesGame::Set(SGame AGame){
    _game=AGame;
    QDir categoriesOld("Files/Categories/"+QString::number(AGame.GetAppid()));
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    if(categoriesOld.exists()){
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"]=AGame.GetName();
        finalNew["GameID"]=AGame.GetAppid();
        QFileInfoList list = categoriesOld.entryInfoList();
        for (int i=0;i<list.size();++i){
            QFile fileCategoryOld("Files/Categories/"+QString::number(AGame.GetAppid())+"/"+list.at(i).fileName());
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
        QFile fileCategoryNew("Files/Categories/"+QString::number(AGame.GetAppid())+".json");
        fileCategoryNew.open(QFile::WriteOnly);
        fileCategoryNew.write(categoriesGameNew.toJson());
        fileCategoryNew.close();
        categoriesOld.removeRecursively();
    }

    QFile fileCategory("Files/Categories/"+QString::number(AGame.GetAppid())+".json");
    if(fileCategory.exists()){
        if(fileCategory.open(QFile::ReadOnly)){
            _categories=QJsonDocument().fromJson(fileCategory.readAll()).object();
            fileCategory.close();
        }
    }
}

void CategoriesGame::Save(){
    _setting.CreateFile("Files/Categories/");
    QFile fileCategoryNew("Files/Categories/"+QString::number(_game.GetAppid())+".json");
    fileCategoryNew.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(_categories);
    fileCategoryNew.write(doc.toJson());
    fileCategoryNew.close();
}

void CategoriesGame::DeleteCategory(int AIndex){
    QJsonObject obj;
    obj["Game"]=_categories["Game"];
    obj["GameID"]=_categories["GameID"];
    QJsonArray arr;
    for(int i=0;i<_categories.value("Categories").toArray().size();i++)
        if(i!=AIndex)
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

void CategoriesGame::ChangeCategory(int ACategory, QJsonObject ANewCategory){
    QJsonObject obj;
    obj["Game"]=_categories["Game"];
    obj["GameID"]=_categories["GameID"];
    QJsonArray arr;
    if(ACategory==_categories.value("Categories").toArray().size()){
        for(int i=0;i<_categories.value("Categories").toArray().size();i++)
                arr.append(_categories.value("Categories").toArray().at(i));
        arr.append(ANewCategory);
    } else {
        for(int i=0;i<_categories.value("Categories").toArray().size();i++)
            if(i!=ACategory)
                arr.append(_categories.value("Categories").toArray().at(i));
            else
                arr.append(ANewCategory);
    }
    obj["Categories"]=arr;
    _categories=obj;
//    if(category==categories.value("Categories").toArray().size())
//        categories.value("Categories").toArray().append(newCategory);
//    else
//        categories.value("Categories").toArray().at(category).toObject()=newCategory;
    Save();
}

CategoriesGame::CategoriesGame(const CategoriesGame& ANewCategoriesGame){
    _categories=ANewCategoriesGame._categories;
    _game=ANewCategoriesGame._game;
}
CategoriesGame& CategoriesGame::operator=(const CategoriesGame& ANewCategoriesGame){
    _categories=ANewCategoriesGame._categories;
    _game=ANewCategoriesGame._game;
    return *this;
}
