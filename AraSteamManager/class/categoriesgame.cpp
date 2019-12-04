#include "categoriesgame.h"

CategoriesGame::CategoriesGame(SGame game, QObject *parent) : QObject(parent){
    Set(game);
}

QList<QString> CategoriesGame::GetTitles(){
    QList<QString> list;
    for(int i=0;i<categories.object().value("Categories").toArray().size();i++){
        list.append(GetTitle(i));
    }
    return list;
}
QString CategoriesGame::GetTitle(int index){
    return categories.object().value("Categories").toArray().at(index).toObject().value("Title").toString();
}
int CategoriesGame::GetIsNoValues(int index){
    return categories.object().value("Categories").toArray().at(index).toObject().value("IsNoValues").toInt();
}
QJsonArray CategoriesGame::GetValues(int index){
    return categories.object().value("Categories").toArray().at(index).toObject().value("Values").toArray();
}
QJsonArray CategoriesGame::GetNoValues(int index){
    return categories.object().value("Categories").toArray().at(index).toObject().value("NoValues").toArray();
}
QString CategoriesGame::GetGame(){
    return categories.object().value("Game").toString();
}
int CategoriesGame::GetGameID(){
    return categories.object().value("GameID").toInt();
}
void CategoriesGame::Set(SGame game){
    this->game=game;
    QDir categoriesOld("Files/Categories/"+QString::number(game.GetAppid()));
    categoriesOld.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categoriesOld.setSorting(QDir::Name);
    if(categoriesOld.exists()){
        QJsonDocument categoriesGameNew;
        QJsonObject finalNew;
        QJsonArray categoriesNew;
        finalNew["Game"]=game.GetName();
        finalNew["GameID"]=game.GetAppid();
        QFileInfoList list = categoriesOld.entryInfoList();
        for (int i=0;i<list.size();++i){
            QFile fileCategoryOld("Files/Categories/"+QString::number(game.GetAppid())+"/"+list.at(i).fileName());
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
        QFile fileCategoryNew("Files/Categories/"+QString::number(game.GetAppid())+".json");
        fileCategoryNew.open(QFile::WriteOnly);
        fileCategoryNew.write(categoriesGameNew.toJson());
        fileCategoryNew.close();
        categoriesOld.removeRecursively();
    }

    QFile fileCategory("Files/Categories/"+QString::number(game.GetAppid())+".json");
    if(fileCategory.exists()){
        if(fileCategory.open(QFile::ReadOnly)){
            categories=QJsonDocument().fromJson(fileCategory.readAll());
            fileCategory.close();
        }
    }
    for(int i=0;i<categories.object().value("Categories").toArray().size();i++){
        if(categories.object().value("Categories").toArray().at(i).toObject().value("IsNoValues").toInt()==1){
            countNoValues++;
        } else {
            countValues++;
        }
    }
}

QList<QString> CategoriesGame::GetAchievementsName(int category, int value){
    QList<QString> list;
    for(int i=0;i<categories.object().value("Categories").toArray().at(category).toObject().value("Values").toArray().at(value).toObject().value("Achievements").toArray().size();i++){
        list.append(categories.object().value("Categories").toArray().at(category).toObject().value("Values").toArray().at(value).toObject().value("Achievements").toArray().at(i).toString());
    }
    return list;
}

void CategoriesGame::Save(){
    QFile fileCategoryNew("Files/Categories/"+QString::number(game.GetAppid())+".json");
    fileCategoryNew.open(QFile::WriteOnly);
    fileCategoryNew.write(categories.toJson());
    fileCategoryNew.close();
}

void CategoriesGame::DeleteCategory(int index){
    QJsonObject obj=categories.object();
    obj.value("Categories").toArray().removeAt(index);
    categories.setObject(obj);
    qDebug()<<categories;
    Save();
}
