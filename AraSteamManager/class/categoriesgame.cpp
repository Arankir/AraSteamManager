#include "categoriesgame.h"

CategoriesGame::CategoriesGame(SGame game, QObject *parent) : QObject(parent){
    Set(game);
}

QList<QString> CategoriesGame::GetTitles(){
    QList<QString> list;
    for(int i=0;i<categories.value("Categories").toArray().size();i++){
        list.append(GetTitle(i));
    }
    return list;
}
QString CategoriesGame::GetTitle(int index){
    return categories.value("Categories").toArray().at(index).toObject().value("Title").toString();
}
int CategoriesGame::GetIsNoValues(int index){
    return categories.value("Categories").toArray().at(index).toObject().value("IsNoValues").toInt();
}
QJsonArray CategoriesGame::GetValues(int value){
    return categories.value("Categories").toArray().at(value).toObject().value("Values").toArray();
}
QList<QString> CategoriesGame::GetValues(int category, int value){
    QList<QString> list;
    for(int i=0;i<categories.value("Categories").toArray().at(category).toObject().value("Values").toArray().at(value).toObject().value("Achievements").toArray().size();i++){
        list.append(categories.value("Categories").toArray().at(category).toObject().value("Values").toArray().at(value).toObject().value("Achievements").toArray().at(i).toString());
    }
    return list;
}
QList<QString> CategoriesGame::GetNoValues(int category){
    QList<QString> list;
    for(int i=0;i<categories.value("Categories").toArray().at(category).toObject().value("NoValues").toArray().size();i++){
        list.append(categories.value("Categories").toArray().at(category).toObject().value("Values").toArray().at(i).toString());
    }
    return list;
}
QString CategoriesGame::GetGame(){
    return categories.value("Game").toString();
}
int CategoriesGame::GetGameID(){
    return categories.value("GameID").toInt();
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
            categories=QJsonDocument().fromJson(fileCategory.readAll()).object();
            fileCategory.close();
        }
    }
}


void CategoriesGame::Save(){
    QFile fileCategoryNew("Files/Categories/"+QString::number(game.GetAppid())+".json");
    fileCategoryNew.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(categories);
    fileCategoryNew.write(doc.toJson());
    fileCategoryNew.close();
}

void CategoriesGame::DeleteCategory(int index){
    qDebug()<<categories;
    categories.value("Categories").toArray().removeAt(index);
    qDebug()<<categories;
    Save();
}

void CategoriesGame::ChangeCategory(int category, QJsonObject newCategory){
    qDebug()<<categories<<categories.size();
    if(category==categories.size())
        categories.value("Categories").toArray().append(newCategory);
    else
        categories.value("Categories").toArray().at(category).toObject()=newCategory;
    qDebug()<<categories<<categories.size();
}

CategoriesGame::CategoriesGame(const CategoriesGame& a){
    this->categories=a.categories;
    this->game=a.game;
}
CategoriesGame& CategoriesGame::operator=(const CategoriesGame& a){
    this->categories=a.categories;
    this->game=a.game;
    return *this;
}
