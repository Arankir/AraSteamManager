#include "formachievements.h"
#include "ui_formachievements.h"

FormAchievements::FormAchievements(QString keys, int languages, QString ids, QString appids, QString GameLogo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAchievements)
{
    ui->setupUi(this);
    key=keys;
    language=languages;
    id=ids;
    appid=appids;
    QNetworkAccessManager manager;
    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &replyNumberOfCurrentPlayers = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key="+key+"&appid="+appid)));
    loop.exec();
    JsonDocNumberOfCurrentPlayers = QJsonDocument::fromJson(replyNumberOfCurrentPlayers.readAll());
    //{"player_count":9023,
    //"result":1}
    QNetworkReply &replyGlobalAchievementPercentagesForApp = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+"&gameid="+appid)));
    loop.exec();
    JsonDocGlobalAchievementPercentagesForApp = QJsonDocument::fromJson(replyGlobalAchievementPercentagesForApp.readAll());
    //{"name": "no_one_cared_who_i_was",
    //"percent": 85}
    QNetworkReply &replyPlayerAchievements = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+id)));
    loop.exec();
    JsonDocPlayerAchievements = QJsonDocument::fromJson(replyPlayerAchievements.readAll());
    //{"apiname":"hot_wheels",
    //"achieved":1,
    //"unlocktime":1445190378}
    ui->FormAchievementsTableWidgetAchievements->setColumnCount(7);
    QString Reached="";
    QString NotReached="";
    QString TotalPercent="";
    switch (language) {
    case 1:{
        ui->FormAchievementsButtonReturn->setText("Return");
        ui->FormAchievementsButtonCompare->setText("Compare with friends");
        ui->FormAchievementsLabelGameLogo->setText("");
        ui->FormAchievementsRadioButtonAll->setText("All achievements");
        ui->FormAchievementsRadioButtonReached->setText("Reached achievements");
        ui->FormAchievementsRadioButtonNotReached->setText("Not reached achievements");
        ui->FormAchievementsButtonAddCategory->setText("Add category");
        ui->FormAchievementsButtonChangeCategory->setText("Change categories");
        ui->FormAchievementsCheckBoxFavorites->setText("Only Favorites");
        ui->FormAchievementsButtonFindAchievement->setText("Find");
        ui->FormAchievementsGroupBoxFilter->setTitle("Filter");
        ui->FormAchievementsLineEditNameAchievements->setPlaceholderText("Achievement name");
        ui->FormAchievementsGroupBoxAddCategory->setTitle("Add category");
        ui->FormAchievementsButtonAddValueNewCategory->setText("Add value");
        ui->FormAchievementsButtonCancelNewCategory->setText("Cancel");
        ui->FormAchievementsButtonAccessNewCategory->setText("Access");
        ui->FormAchievementsLineEditTitleNewCategory->setPlaceholderText("Text of category");
        ui->FormAchievementsLineEditTitleValueNewCategory->setPlaceholderText("Text of value");
        ui->FormAchievementsGroupBoxChangeCategory->setTitle("Change category");
        ui->FormAchievementsButtonAddValueChangeCategory->setText("Add value");
        ui->FormAchievementsButtonCancelChangeCategory->setText("Cancel");
        ui->FormAchievementsButtonAccessChangeCategory->setText("Access");
        ui->FormAchievementsButtonDeleteCategory->setText("Delete");
        ui->FormAchievementsComboBoxCategoriesChangeCategory->addItem("Category not selected");
        ui->FormAchievementsLineEditTitleCategoryChangeCategory->setPlaceholderText("Text of category");
        ui->FormAchievementsLineEditTitleValueChangeCategory->setPlaceholderText("Text of value");
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem("Title"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem("Description"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem("In the world"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem("Received"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem("Favorites"));
        Reached="Reached";
        NotReached="Not reached";
        TotalPercent="Total percent";
        QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l=english")));
        loop.exec();
        JsonDocSchemaForGame = QJsonDocument::fromJson(replySchemaForGame.readAll());
        ui->FormAchievementsLabelGameOnline->setText("Now in game: "+QString::number(JsonDocNumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble()));
        break;
    }
    case 5:{
        ui->FormAchievementsButtonReturn->setText("Вернуться");
        ui->FormAchievementsButtonCompare->setText("Сравнить с друзьями");
        ui->FormAchievementsLabelGameLogo->setText("");
        ui->FormAchievementsRadioButtonAll->setText("Все достижения");
        ui->FormAchievementsRadioButtonReached->setText("Полученные достижения");
        ui->FormAchievementsRadioButtonNotReached->setText("Не полученные достижения");
        ui->FormAchievementsButtonAddCategory->setText("Добавить категорию");
        ui->FormAchievementsButtonChangeCategory->setText("Изменить категории");
        ui->FormAchievementsCheckBoxFavorites->setText("Только избранное");
        ui->FormAchievementsButtonFindAchievement->setText("Найти");
        ui->FormAchievementsGroupBoxFilter->setTitle("Фильтр");
        ui->FormAchievementsLineEditNameAchievements->setPlaceholderText("Название достижения");
        ui->FormAchievementsGroupBoxAddCategory->setTitle("Добавить категорию");
        ui->FormAchievementsButtonAddValueNewCategory->setText("Добавить значение");
        ui->FormAchievementsButtonCancelNewCategory->setText("Отмена");
        ui->FormAchievementsButtonAccessNewCategory->setText("Применить");
        ui->FormAchievementsLineEditTitleNewCategory->setPlaceholderText("Название категории");
        ui->FormAchievementsLineEditTitleValueNewCategory->setPlaceholderText("Название значения");
        ui->FormAchievementsGroupBoxChangeCategory->setTitle("Изменить категорию");
        ui->FormAchievementsButtonAddValueChangeCategory->setText("Добавить значение");
        ui->FormAchievementsButtonCancelChangeCategory->setText("Отмена");
        ui->FormAchievementsButtonAccessChangeCategory->setText("Применить");
        ui->FormAchievementsButtonDeleteCategory->setText("Удалить");
        ui->FormAchievementsComboBoxCategoriesChangeCategory->addItem("Категория не выбрана");
        ui->FormAchievementsLineEditTitleCategoryChangeCategory->setPlaceholderText("Название категории");
        ui->FormAchievementsLineEditTitleValueChangeCategory->setPlaceholderText("Название значения");
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem("Название"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem("Описание"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem("По миру"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem("Получено"));
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem("Избранное"));
        Reached="Получено";
        NotReached="Не получено";
        TotalPercent="Общий процент";
        QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l=russian")));
        loop.exec();
        JsonDocSchemaForGame = QJsonDocument::fromJson(replySchemaForGame.readAll());
        ui->FormAchievementsLabelGameOnline->setText("Сейчас в сети: "+QString::number(JsonDocNumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble()));
        //{"name":"hot_wheels",
        //"defaultvalue":0,
        //"displayName":"В полымя",
        //"hidden":0,
        //"description":"Выполняя первый день контракта \"Сторожевые псы\", не дайте полицейским убить водителя пикапа.",
        //"icon":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/apps/218620/f6ed9cd6ec9750bcd36193c74e6f16104f6c1267.jpg",
        //"icongray":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/apps/218620/c336adacd88a21a6010c9b5596192322aecaf265.jpg"}
        }
    }
    QNetworkReply &logoreply = *manager.get(QNetworkRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+appid+"/"+GameLogo+".jpg"));
    loop.exec();
    QPixmap pixmap;
    pixmap.loadFromData(logoreply.readAll());
    ui->FormAchievementsLabelGameLogo->setPixmap(pixmap);
    int total=0;
    int dectotal=0;
    if(!QDir("images/achievements/"+appid).exists()){
        QDir().mkdir("images/achievements/"+appid);
    }
    for(int i=0;i<JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().size();i++){
        if(JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("percent")!=0){
            int j=0;
            bool accept=false;
            for(;j<JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().size();j++){
                if(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("apiname")==JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("name")){
                    accept=true;
                    break;
                    }
            }
            if(accept){
                QPixmap pixmap;
                QString AchievementIcon=JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("icon").toString().mid(66,JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("icon").toString().length());
                if(!QFile::exists("images/achievements/"+appid+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png")){
                    QNetworkAccessManager imagemanager;
                    QEventLoop imageloop;  //Ждем ответ от сервера.
                    QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
                    QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("icon").toString()));
                    imageloop.exec();
                    QImage img;
                    img.loadFromData(imagereply.readAll());
                    img.save("images/achievements/"+appid+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png", "PNG");
                    pixmap=QPixmap::fromImage(img);
                } else {
                    pixmap.load("images/achievements/"+appid+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png", "PNG");
                    }
                QLabel *label = new QLabel;
                label->setPixmap(pixmap);
                int row = ui->FormAchievementsTableWidgetAchievements->rowCount();
                ui->FormAchievementsTableWidgetAchievements->insertRow(row);
                ui->FormAchievementsTableWidgetAchievements->setCellWidget(row,0,label);
                QTableWidgetItem *item2 = new QTableWidgetItem(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("displayName").toString());
                ui->FormAchievementsTableWidgetAchievements->setItem(row,1,item2);
                QTableWidgetItem *item3 = new QTableWidgetItem(JsonDocSchemaForGame.object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray().at(j).toObject().value("description").toString());
                ui->FormAchievementsTableWidgetAchievements->setItem(row,2,item3);
                QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(JsonDocGlobalAchievementPercentagesForApp.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(i).toObject().value("percent").toDouble())+"%");
                ui->FormAchievementsTableWidgetAchievements->setItem(row,3,item4);
                QTableWidgetItem *item5;
                if(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("achieved").toInt()==1){
                    QDateTime date;
                    date.setDate(QDate::fromString("1970.01.01","yyyy.MM.dd"));
                    date=date.addSecs(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("unlocktime").toInt());
                    item5 = new QTableWidgetItem(Reached+" "+date.toString("yyyy.MM.dd"));
                    total++;
                } else {
                    item5 = new QTableWidgetItem(NotReached);
                    }
                ui->FormAchievementsTableWidgetAchievements->setItem(row,4,item5);
                QPushButton *button1 = new QPushButton;
                button1->setText("«");
                QFont font("Wingdings",24);
                button1->setFont(font);
                connect(button1,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
                button1->setObjectName("FormGamesButtonFavorites"+appid+"&"+JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("apiname").toString());
                ui->FormAchievementsTableWidgetAchievements->setCellWidget(row,5,button1);
                QTableWidgetItem *item6 = new QTableWidgetItem(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().at(j).toObject().value("apiname").toString());
                ui->FormAchievementsTableWidgetAchievements->setItem(row,6,item6);
                ui->FormAchievementsTableWidgetAchievements->setColumnHidden(6,true);
            } else dectotal+=1;

        }
        }
    double percent= 1.0*total/(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray().size()-dectotal)*100;
    ui->FormAchievementsLabelTotalPersent->setText(TotalPercent+" = "+QString::number(percent)+"%");
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(0,65);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(1,100);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(2,315);
    ui->FormAchievementsTableWidgetAchievements->resizeColumnToContents(3);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(4,80);
    ui->FormAchievementsTableWidgetAchievements->resizeColumnToContents(5);
    ui->FormAchievementsTableWidgetAchievements->resizeRowsToContents();

    filter = new bool*[ui->FormAchievementsTableWidgetAchievements->rowCount()];
    QDir categories("Files/Categories/"+appid);
    if(categories.exists()){
        categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        categories.setSorting(QDir::Name);
        QFileInfoList list = categories.entryInfoList();
        QHBoxLayout *layout = new QHBoxLayout;
        QWidget *widget = new QWidget;
        for (int i = 0; i < list.size(); ++i){
            QFile category("Files/Categories/"+appid+"/"+list.at(i).fileName());
            category.open(QFile::ReadOnly);
            QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
            QComboBox *cb = new QComboBox;
            cb->addItem(cat.object().value("name").toString());
            for (int j=0;j<cat.object().value("values").toArray().size();j++) {
                cb->addItem(cat.object().value("values").toArray().at(j).toString());
            }
            cb->setObjectName("Category"+QString::number(i));
            connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(on_ComboBoxCategory_Change(int)));
            layout->addWidget(cb);
            ui->FormAchievementsComboBoxCategoriesChangeCategory->addItem(cat.object().value("name").toString());
            category.close();
            }
        widget->setLayout(layout);
        ui->FormAchievementsScrollAreaCategories->setWidget(widget);
        for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++) {
            filter[i]=new bool[list.size()+3];
            for (int j=0;j<list.size()+3;j++) {
                filter[i][j]=true;
                }
            }
        colfilter=list.size()+3;
        } else {
        for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++) {
            filter[i]=new bool[3];
            for (int j=0;j<3;j++) {
                filter[i][j]=true;
                }
            }
        colfilter=3;
        }
    ui->FormAchievementsGroupBoxAddCategory->setVisible(false);
    ui->FormAchievementsGroupBoxChangeCategory->setVisible(false);
    QWidget *widget = new QWidget;
    newcategoryvalueslayout = new QFormLayout;
    widget->setLayout(newcategoryvalueslayout);
    ui->FormAchievementsScrollAreaValues->setWidget(widget);
}

void FormAchievements::on_ComboBoxCategory_Change(int index){
    QComboBox *cb = (QComboBox*) sender();
    QDir categories("Files/Categories/"+appid);
    if(categories.exists()){
        categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        categories.setSorting(QDir::Name);
        QFileInfoList list = categories.entryInfoList();
        QFile category("Files/Categories/"+appid+"/"+list.at(cb->objectName().mid(8,cb->objectName().length()).toInt()).fileName());
        category.open(QFile::ReadOnly);
        QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
        QJsonArray selecteditem = cat.object().value(cb->itemText(index)).toArray();
        if(index!=0)
            for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->FormAchievementsTableWidgetAchievements->item(i,6)->text()==selecteditem[j].toString()){
                        filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        break;
                        };
                    }
            } else {
            for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()]=true;
                }
            }
        category.close();
        UpdateHiddenRows();
    }
}

FormAchievements::~FormAchievements(){
    delete ui;
}

void FormAchievements::closeEvent(QCloseEvent *){
    on_FormAchievementsButtonReturn_clicked();
}

void FormAchievements::on_FormAchievementsButtonReturn_clicked(){
    emit return_to_games();
    delete this;
}

void FormAchievements::FavoritesClicked(){

}

void FormAchievements::UpdateHiddenRows(){
    for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++) {
        bool accept=true;
        for (int j=0;j<colfilter;j++) {
            if(filter[i][j]==false){
                accept=false;
                break;
                }
            }
        if(accept){
            ui->FormAchievementsTableWidgetAchievements->setRowHidden(i,false);
            } else
            ui->FormAchievementsTableWidgetAchievements->setRowHidden(i,true);
        }
}

void FormAchievements::on_FormAchievementsButtonAddCategory_clicked(){
    ui->FormAchievementsButtonAddCategory->setEnabled(false);
    ui->FormAchievementsButtonChangeCategory->setEnabled(false);
    ui->FormAchievementsGroupBoxAddCategory->setVisible(true);
}

void FormAchievements::on_return(){
    this->setEnabled(true);
}

void FormAchievements::on_FormAchievementsRadioButtonAll_clicked(){
    for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++){
        filter[i][1]=true;}
    UpdateHiddenRows();
}

void FormAchievements::on_FormAchievementsRadioButtonReached_clicked(){
    for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++)
        if(ui->FormAchievementsTableWidgetAchievements->item(i,4)->text().indexOf(".")>-1){
            filter[i][1]=true;} else{
            filter[i][1]=false;}
    UpdateHiddenRows();
}

void FormAchievements::on_FormAchievementsRadioButtonNotReached_clicked(){
    for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++)
        if(ui->FormAchievementsTableWidgetAchievements->item(i,4)->text().indexOf(".")>-1){
            filter[i][1]=false;} else{
            filter[i][1]=true;}
    UpdateHiddenRows();
}

void FormAchievements::on_FormAchievementsLineEditNameAchievements_textChanged(const QString&){
    for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++)
        if((ui->FormAchievementsTableWidgetAchievements->item(i,1)->text().toLower().indexOf(ui->FormAchievementsLineEditNameAchievements->text().toLower())>-1)||(ui->FormAchievementsTableWidgetAchievements->item(i,2)->text().toLower().indexOf(ui->FormAchievementsLineEditNameAchievements->text().toLower())>-1))
            filter[i][0]=true; else
            filter[i][0]=false;
    UpdateHiddenRows();
}

void FormAchievements::on_FormAchievementsButtonChangeCategory_clicked(){
//    changecategoryform = new FormChangeCategory(id,key,language,appid);
//    connect(changecategoryform,SIGNAL(return_to_achievements()),this,SLOT(on_return()));
//    changecategoryform->show();
//    this->setEnabled(false);
    ui->FormAchievementsButtonAddCategory->setEnabled(false);
    ui->FormAchievementsButtonChangeCategory->setEnabled(false);
    ui->FormAchievementsGroupBoxChangeCategory->setVisible(true);
}

void FormAchievements::on_FormAchievementsButtonCancelNewCategory_clicked(){
    ui->FormAchievementsTableWidgetAchievements->setColumnCount(7);
    ui->FormAchievementsGroupBoxAddCategory->setVisible(false);
    ui->FormAchievementsButtonAddCategory->setEnabled(true);
    ui->FormAchievementsButtonChangeCategory->setEnabled(true);
    while (!newcategoryvalueslayout->isEmpty()) {
        newcategoryvalueslayout->removeRow(0);
    }
}

void FormAchievements::on_FormAchievementsButtonCancelChangeCategory_clicked(){
    ui->FormAchievementsTableWidgetAchievements->setColumnCount(7);
    ui->FormAchievementsGroupBoxChangeCategory->setVisible(false);
    ui->FormAchievementsButtonAddCategory->setEnabled(true);
    ui->FormAchievementsButtonChangeCategory->setEnabled(true);
}

void FormAchievements::on_FormAchievementsButtonAddValueNewCategory_clicked(){
    bool accept=true;
    if(ui->FormAchievementsTableWidgetAchievements->columnCount()>7)
        for (int i=7;i<ui->FormAchievementsTableWidgetAchievements->columnCount();i++){
            if(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->FormAchievementsLineEditTitleValueNewCategory->text()){
               accept=false;
            }
        }
    if((ui->FormAchievementsLineEditTitleValueNewCategory->text()!="")&&(accept)){
        ui->FormAchievementsTableWidgetAchievements->setColumnCount(ui->FormAchievementsTableWidgetAchievements->columnCount()+1);
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(ui->FormAchievementsTableWidgetAchievements->columnCount()-1,new QTableWidgetItem(ui->FormAchievementsLineEditTitleValueNewCategory->text()));
        for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++){
            QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->FormAchievementsTableWidgetAchievements->setItem(i,ui->FormAchievementsTableWidgetAchievements->columnCount()-1, pItem);
//            QCheckBox *chb = new QCheckBox("Add");
//            chb->setObjectName(ui->FormAddCategoryLineEditNameValue->text()+"_number_"+QString::number(i));
//            ui->FormAddCategoryTableWidgetAchievements->setCellWidget(i,ui->FormAddCategoryTableWidgetAchievements->columnCount()-1,chb);
            //connect(chb,SIGNAL(stateChanged(int)),this,SLOT(chbCook3Change(int)));
//            value.second[i]=chb;
        }
        QPushButton *btn = new QPushButton;
        btn->setObjectName("btnNewCategoryDeleteValue"+QString::number(newcategoryvalueslayout->rowCount()));
        btn->setText("x");
        connect(btn,SIGNAL(clicked()),this,SLOT(on_buttonNewCategoryDeleteValues_clicked()));
        newcategoryvalueslayout->addRow(ui->FormAchievementsLineEditTitleValueNewCategory->text(),btn);
        ui->FormAchievementsLineEditTitleValueNewCategory->setText("");
        ui->FormAchievementsLineEditTitleValueNewCategory->setFocus();
    } else
        switch(language){
        case 1:{
            QMessageBox::warning(this,"Warning","Title of value is empty or such value already exists!");
            break;
            }
        case 5:
            QMessageBox::warning(this,"Ошибка","Название значения пустое или такое значение уже существует!");
        }
}

void FormAchievements::on_buttonNewCategoryDeleteValues_clicked(){
    QPushButton *btn = (QPushButton*) sender();
    int i=btn->objectName().mid(25,btn->objectName().length()-25).toInt();
    ui->FormAchievementsTableWidgetAchievements->removeColumn(7+i);
    delete btn;
    newcategoryvalueslayout->removeRow(i);
    i++;
    while(i<newcategoryvalueslayout->rowCount()+1){
        findChild<QPushButton*>("btnNewCategoryDeleteValue"+QString::number(i))->setObjectName("btnNewCategoryDeleteValue"+QString::number(i-1));
        i++;
    }
}

void FormAchievements::on_FormAchievementsButtonAccessNewCategory_clicked(){
    if(!QDir("Files/Categories/"+appid).exists()){
        QDir().mkdir("Files/Categories/"+appid);
    }
    if(ui->FormAchievementsLineEditTitleNewCategory->text()!=""){
        QFile Category("Files/Categories/"+appid+"/"+ui->FormAchievementsLineEditTitleNewCategory->text()+".json");
        if(!QFile::exists("Files/Categories/"+appid+"/"+ui->FormAchievementsLineEditTitleNewCategory->text()+".json")){
            if(Category.open(QIODevice::WriteOnly)){
                QJsonDocument category;
                QJsonArray groups;
                QJsonObject group;
                group["name"]=ui->FormAchievementsLineEditTitleNewCategory->text();
                QJsonArray values;
                QJsonObject val;
                for (int i=7;i<ui->FormAchievementsTableWidgetAchievements->columnCount();i++){
                    values.append(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(i)->text());
                    QJsonArray valn;
                    for (int j=0;j<ui->FormAchievementsTableWidgetAchievements->rowCount();j++) {
                        if(ui->FormAchievementsTableWidgetAchievements->item(j,i)->checkState()){
                            valn.append(ui->FormAchievementsTableWidgetAchievements->item(j,6)->text());
                        }
                    group[ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(i)->text()]=valn;
                    }
                }
                group["values"]=values;
                category.setObject(group);
                Category.write(category.toJson());
                Category.close();

                delete ui->FormAchievementsScrollAreaCategories->layout();
                QDir categories("Files/Categories/"+appid);
                if(categories.exists()){
                    categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
                    categories.setSorting(QDir::Name);
                    QFileInfoList list = categories.entryInfoList();
                    QHBoxLayout *layout = new QHBoxLayout;
                    QWidget *widget = new QWidget;
                    for (int i = 0; i < list.size(); ++i){
                        QFile category("Files/Categories/"+appid+"/"+list.at(i).fileName());
                        category.open(QFile::ReadOnly);
                        QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
                        QComboBox *cb = new QComboBox;
                        cb->addItem(cat.object().value("name").toString());
                        for (int j=0;j<cat.object().value("values").toArray().size();j++) {
                            cb->addItem(cat.object().value("values").toArray().at(j).toString());
                        }
                        cb->setObjectName("Category"+QString::number(i));
                        connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(on_ComboBoxCategory_Change(int)));
                        layout->addWidget(cb);
                        ui->FormAchievementsComboBoxCategoriesChangeCategory->addItem(cat.object().value("name").toString());
                        category.close();
                        }
                    widget->setLayout(layout);
                    ui->FormAchievementsScrollAreaCategories->setWidget(widget);

                    bool **New = new bool*[ui->FormAchievementsTableWidgetAchievements->rowCount()];
                    for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++) {
                        New[i]=new bool[list.size()+3];
                        for (int j=0;j<list.size()+3;j++) {
                            New[i][j]=true;
                            }
                        }
                    colfilter=list.size()+3;
                    delete filter;
                    filter = new bool*[ui->FormAchievementsTableWidgetAchievements->rowCount()];
                    filter = New;
                    qDebug() << filter[ui->FormAchievementsTableWidgetAchievements->rowCount()-1][list.size()+2];
                    }
                switch(language){
                case 1:{
                    QMessageBox::information(this,"Successful","New Category has been added!");
                    break;
                    }
                case 5:
                    QMessageBox::information(this,"Успешно","Категория была добавлена!");
                }
                on_FormAchievementsButtonCancelNewCategory_clicked();
            }
        } else
            switch(language){
            case 1:{
                QMessageBox::warning(this,"Warning","Category with this name already exist!");
                break;
                }
            case 5:
                QMessageBox::warning(this,"Ошибка","Такая категория уже есть!");
            }
    } else
        switch(language){
        case 1:{
            QMessageBox::warning(this,"Warning","Category name is empty!");
            break;
            }
        case 5:
            QMessageBox::warning(this,"Ошибка","Название категории пустое!");
        }
}
