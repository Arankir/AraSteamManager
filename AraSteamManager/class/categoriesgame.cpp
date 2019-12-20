#include "categoriesgame.h"

CategoriesGame::CategoriesGame(SGame Agame, QObject *parent) : QObject(parent){
    _game=Agame;
    QDir categoriesOld("Files/Categories/"+QString::number(Agame.GetAppid()));
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    if(categoriesOld.exists()){
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"]=Agame.GetName();
        finalNew["GameID"]=Agame.GetAppid();
        QFileInfoList list = categoriesOld.entryInfoList();
        for (int i=0;i<list.size();++i){
            QFile fileCategoryOld("Files/Categories/"+QString::number(Agame.GetAppid())+"/"+list.at(i).fileName());
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
        QFile fileCategoryNew("Files/Categories/"+QString::number(Agame.GetAppid())+".json");
        fileCategoryNew.open(QFile::WriteOnly);
        fileCategoryNew.write(categoriesGameNew.toJson());
        fileCategoryNew.close();
        categoriesOld.removeRecursively();
    }

    QFile fileCategory("Files/Categories/"+QString::number(Agame.GetAppid())+".json");
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
QString CategoriesGame::GetTitle(int Aindex){
    return _categories.value("Categories").toArray().at(Aindex).toObject().value("Title").toString();
}
int CategoriesGame::GetIsNoValues(int Aindex){
    return _categories.value("Categories").toArray().at(Aindex).toObject().value("IsNoValues").toInt();
}
QJsonArray CategoriesGame::GetValues(int Avalue){
    return _categories.value("Categories").toArray().at(Avalue).toObject().value("Values").toArray();
}
QList<QString> CategoriesGame::GetValues(int Acategory, int Avalue){
    QList<QString> list;
    for(int i=0;i<_categories.value("Categories").toArray().at(Acategory).toObject().value("Values").toArray().at(Avalue).toObject().value("Achievements").toArray().size();i++){
        list.append(_categories.value("Categories").toArray().at(Acategory).toObject().value("Values").toArray().at(Avalue).toObject().value("Achievements").toArray().at(i).toString());
    }
    return list;
}
QList<QString> CategoriesGame::GetNoValues(int Acategory){
    QList<QString> list;
    for(int i=0;i<_categories.value("Categories").toArray().at(Acategory).toObject().value("NoValues").toArray().size();i++){
        list.append(_categories.value("Categories").toArray().at(Acategory).toObject().value("NoValues").toArray().at(i).toString());
    }
    return list;
}
QString CategoriesGame::GetGame(){
    return _categories.value("Game").toString();
}
int CategoriesGame::GetGameID(){
    return _categories.value("GameID").toInt();
}
void CategoriesGame::Set(SGame Agame){
    _game=Agame;
    QDir categoriesOld("Files/Categories/"+QString::number(Agame.GetAppid()));
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    if(categoriesOld.exists()){
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"]=Agame.GetName();
        finalNew["GameID"]=Agame.GetAppid();
        QFileInfoList list = categoriesOld.entryInfoList();
        for (int i=0;i<list.size();++i){
            QFile fileCategoryOld("Files/Categories/"+QString::number(Agame.GetAppid())+"/"+list.at(i).fileName());
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
        QFile fileCategoryNew("Files/Categories/"+QString::number(Agame.GetAppid())+".json");
        fileCategoryNew.open(QFile::WriteOnly);
        fileCategoryNew.write(categoriesGameNew.toJson());
        fileCategoryNew.close();
        categoriesOld.removeRecursively();
    }

    QFile fileCategory("Files/Categories/"+QString::number(Agame.GetAppid())+".json");
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

void CategoriesGame::DeleteCategory(int Aindex){
    QJsonObject obj;
    obj["Game"]=_categories["Game"];
    obj["GameID"]=_categories["GameID"];
    QJsonArray arr;
    for(int i=0;i<_categories.value("Categories").toArray().size();i++)
        if(i!=Aindex)
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

void CategoriesGame::ChangeCategory(int Acategory, QJsonObject AnewCategory){
    QJsonObject obj;
    obj["Game"]=_categories["Game"];
    obj["GameID"]=_categories["GameID"];
    QJsonArray arr;
    if(Acategory==_categories.value("Categories").toArray().size()){
        for(int i=0;i<_categories.value("Categories").toArray().size();i++)
                arr.append(_categories.value("Categories").toArray().at(i));
        arr.append(AnewCategory);
    } else {
        for(int i=0;i<_categories.value("Categories").toArray().size();i++)
            if(i!=Acategory)
                arr.append(_categories.value("Categories").toArray().at(i));
            else
                arr.append(AnewCategory);
    }
    obj["Categories"]=arr;
    _categories=obj;
//    if(category==categories.value("Categories").toArray().size())
//        categories.value("Categories").toArray().append(newCategory);
//    else
//        categories.value("Categories").toArray().at(category).toObject()=newCategory;
    Save();
}

CategoriesGame::CategoriesGame(const CategoriesGame& AnewCategoriesGame){
    _categories=AnewCategoriesGame._categories;
    _game=AnewCategoriesGame._game;
}
CategoriesGame& CategoriesGame::operator=(const CategoriesGame& AnewCategoriesGame){
    _categories=AnewCategoriesGame._categories;
    _game=AnewCategoriesGame._game;
    return *this;
}
