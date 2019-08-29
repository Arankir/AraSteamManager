#include "formachievements.h"
#include "ui_formachievements.h"

FormAchievements::FormAchievements(QString keys, int languages, int Themes, QString ids, QString appids, QString GameLogo, QJsonDocument JsonDocGlobalAchievement,int SaveImage, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormAchievements){
    ui->setupUi(this);
    key=keys;
    language=languages;
    id=ids;
    appid=appids;
    SaveImages=SaveImage;
    Theme=Themes;
    JsonArrayGlobalAchievements = JsonDocGlobalAchievement.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray();
    //{"name": "no_one_cared_who_i_was",
    //"percent": 85}
    ui->FormAchievementsTableWidgetAchievements->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QFile FileLanguage;
    switch(language){
    case 1:{
        FileLanguage.setFileName("Files/Languages/ENG/achievements.txt");
        break;
        }
    case 5:{
        FileLanguage.setFileName("Files/Languages/RU/achievements.txt");
        }
    }
    if(FileLanguage.open(QIODevice::ReadOnly)){
        while(!FileLanguage.atEnd()){
            SLLanguage << QString::fromLocal8Bit(FileLanguage.readLine()).remove("\r\n");
        }
    }
    QIcon favorites;
    switch(Theme){
    case 1:{
        ui->FormAchievementsButtonReturn->setIcon(QIcon("images/program/back_white.png"));
        ui->FormAchievementsButtonCompare->setIcon(QIcon("images/program/compare_white.png"));
        //ui->FormAchievementsGroupBoxFilter->setStyleSheet("QGroupBox::title {background-image:url(images/program/filter_white.png)}");
        //ui->FormAchievementsGroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(images/program/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
        ui->FormAchievementsGroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(images/program/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
        ui->FormAchievementsButtonAddCategory->setIcon(QIcon("images/program/create.png"));
        ui->FormAchievementsButtonChangeCategory->setIcon(QIcon("images/program/change_white.png"));
        ui->FormAchievementsButtonDeleteCategory->setIcon(QIcon("images/program/delete.png"));
        ui->FormAchievementsButtonFindAchievement->setIcon(QIcon("images/program/find_white.png"));
        ui->FormAchievementsButtonAcceptNewCategory->setIcon(QIcon("images/program/apply.png"));
        ui->FormAchievementsButtonCancelNewCategory->setIcon(QIcon("images/program/cancel.png"));
        ui->FormAchievementsButtonAddValueNewCategory->setIcon(QIcon("images/program/create.png"));
        ui->FormAchievementsButtonAcceptChangeCategory->setIcon(QIcon("images/program/apply.png"));
        ui->FormAchievementsButtonCancelChangeCategory->setIcon(QIcon("images/program/cancel.png"));
        ui->FormAchievementsButtonAddValueChangeCategory->setIcon(QIcon("images/program/create.png"));
        ui->FormAchievementsRadioButtonAll->setIcon(QIcon("images/program/all_white.png"));
        ui->FormAchievementsRadioButtonReached->setIcon(QIcon("images/program/reached_white.png"));
        ui->FormAchievementsRadioButtonNotReached->setIcon(QIcon("images/program/notreached_white.png"));
        favorites.addFile("images/program/favorites_white.png");
        break;
        }
    case 2:{
        ui->FormAchievementsButtonReturn->setIcon(QIcon("images/program/back_black.png"));
        ui->FormAchievementsButtonCompare->setIcon(QIcon("images/program/compare_black.png"));
        ui->FormAchievementsGroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(images/program/filter_black.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
        ui->FormAchievementsButtonAddCategory->setIcon(QIcon("images/program/create.png"));
        ui->FormAchievementsButtonChangeCategory->setIcon(QIcon("images/program/change_black.png"));
        ui->FormAchievementsButtonDeleteCategory->setIcon(QIcon("images/program/delete.png"));
        ui->FormAchievementsButtonFindAchievement->setIcon(QIcon("images/program/find_black.png"));
        ui->FormAchievementsButtonAcceptNewCategory->setIcon(QIcon("images/program/apply.png"));
        ui->FormAchievementsButtonCancelNewCategory->setIcon(QIcon("images/program/cancel.png"));
        ui->FormAchievementsButtonAddValueNewCategory->setIcon(QIcon("images/program/create.png"));
        ui->FormAchievementsButtonAcceptChangeCategory->setIcon(QIcon("images/program/apply.png"));
        ui->FormAchievementsButtonCancelChangeCategory->setIcon(QIcon("images/program/cancel.png"));
        ui->FormAchievementsButtonAddValueChangeCategory->setIcon(QIcon("images/program/create.png"));
        ui->FormAchievementsRadioButtonAll->setIcon(QIcon("images/program/all_black.png"));
        ui->FormAchievementsRadioButtonReached->setIcon(QIcon("images/program/reached_black.png"));
        ui->FormAchievementsRadioButtonNotReached->setIcon(QIcon("images/program/notreached_black.png"));
        favorites.addFile("images/program/favorites_black.png");
        break;
        }
    }
    QNetworkAccessManager manager;
    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &replyNumberOfCurrentPlayers = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key="+key+"&appid="+appid)));
    loop.exec();
    //{"player_count":9023,
    //"result":1}
    JsonDocNumberOfCurrentPlayers = QJsonDocument::fromJson(replyNumberOfCurrentPlayers.readAll());
    QNetworkReply &replyPlayerAchievements = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+id)));
    loop.exec();
    JsonDocPlayerAchievements = QJsonDocument::fromJson(replyPlayerAchievements.readAll());
    QJsonArray JsonArrayPlayerAchievements = JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray();
    //{"apiname":"hot_wheels",
    //"achieved":1,
    //"unlocktime":1445190378}
    ui->FormAchievementsTableWidgetAchievements->setColumnCount(7);
    ui->FormAchievementsButtonReturn->setText(" "+SLLanguage[0]);
    ui->FormAchievementsButtonCompare->setText(" "+SLLanguage[1]);
    ui->FormAchievementsLabelGameLogo->setText("");
    ui->FormAchievementsRadioButtonAll->setText(SLLanguage[2]);
    ui->FormAchievementsRadioButtonReached->setText(SLLanguage[3]);
    ui->FormAchievementsRadioButtonNotReached->setText(SLLanguage[4]);
    ui->FormAchievementsButtonAddCategory->setText(SLLanguage[5]);
    ui->FormAchievementsButtonChangeCategory->setText(SLLanguage[6]);
    ui->FormAchievementsCheckBoxFavorites->setText(SLLanguage[7]);
    ui->FormAchievementsButtonFindAchievement->setText(SLLanguage[8]);
    ui->FormAchievementsGroupBoxFilter->setTitle("      "+SLLanguage[9]);
    ui->FormAchievementsLineEditNameAchievements->setPlaceholderText(SLLanguage[10]);
    ui->FormAchievementsGroupBoxAddCategory->setTitle(SLLanguage[5]);
    ui->FormAchievementsButtonAddValueNewCategory->setText(SLLanguage[11]);
    ui->FormAchievementsButtonCancelNewCategory->setText(" "+SLLanguage[12]);
    ui->FormAchievementsButtonAcceptNewCategory->setText(SLLanguage[13]);
    ui->FormAchievementsLineEditTitleNewCategory->setPlaceholderText(SLLanguage[14]);
    //ui->FormAchievementsLineEditTitleValueNewCategory->setPlaceholderText(SLLanguage[15]);
    ui->FormAchievementsGroupBoxChangeCategory->setTitle(SLLanguage[16]);
    ui->FormAchievementsButtonAddValueChangeCategory->setText(SLLanguage[11]);
    ui->FormAchievementsButtonCancelChangeCategory->setText(" "+SLLanguage[12]);
    ui->FormAchievementsButtonAcceptChangeCategory->setText(SLLanguage[13]);
    ui->FormAchievementsButtonDeleteCategory->setText(SLLanguage[17]);
    ui->FormAchievementsComboBoxCategoriesChangeCategory->addItem(SLLanguage[18]);
    ui->FormAchievementsLineEditTitleCategoryChangeCategory->setPlaceholderText(SLLanguage[14]);
    //ui->FormAchievementsLineEditTitleValueChangeCategory->setPlaceholderText(SLLanguage[15]);
    ui->FormAchievementsButtonUpdate->setText(SLLanguage[36]);
    ui->FormAchievementsCheckBoxNewCategoryOneValue->setText(SLLanguage[38]);
    ui->FormAchievementsCheckBoxChangeCategoryOneValue->setText(SLLanguage[38]);
    ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem(SLLanguage[19]));
    ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem(SLLanguage[20]));
    ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem(SLLanguage[21]));
    ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem(SLLanguage[23]));
    ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem(SLLanguage[22]));
    QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l="+SLLanguage[26])));
    loop.exec();
    JsonArraySchemaForGame = QJsonDocument::fromJson(replySchemaForGame.readAll()).object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray();
    ui->FormAchievementsLabelGameOnline->setText(SLLanguage[27]+": "+QString::number(JsonDocNumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble()));
    QNetworkReply &logoreply = *manager.get(QNetworkRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+appid+"/"+GameLogo+".jpg"));
    loop.exec();
    QPixmap pixmap;
    pixmap.loadFromData(logoreply.readAll());
    ui->FormAchievementsLabelGameLogo->setPixmap(pixmap);
    int totalr=0;
    int totalnr=0;
    if(!QDir("images/achievements/"+appid).exists()){
        QDir().mkdir("images/achievements/"+appid);
    }
    QJsonArray JAPA = JsonArrayPlayerAchievements;
    QJsonArray JASFG = JsonArraySchemaForGame;
    if(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("success").toBool()==false){
        ui->FormAchievementsTableWidgetAchievements->insertRow(0);
        QTableWidgetItem *item1 = new QTableWidgetItem("Error");
        ui->FormAchievementsTableWidgetAchievements->setItem(0,1,item1);
        QTableWidgetItem *item2 = new QTableWidgetItem(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("error").toString());
        ui->FormAchievementsTableWidgetAchievements->setItem(0,2,item2);
        ui->FormAchievementsTableWidgetAchievements->setColumnHidden(3,true);
        ui->FormAchievementsTableWidgetAchievements->setColumnHidden(4,true);
        ui->FormAchievementsTableWidgetAchievements->setColumnHidden(5,true);
        ui->FormAchievementsTableWidgetAchievements->setColumnHidden(6,true);
        ui->FormAchievementsGroupBoxFilter->setEnabled(false);
        ui->FormAchievementsButtonCompare->setEnabled(false);
    } else
    for(int i=0;i<JsonArrayGlobalAchievements.size();i++){
        qDebug()<<i;
            int j=0;
            bool accept=false;
            for(;j<JAPA.size();j++){
                if(JAPA[j].toObject().value("apiname").toString()==JsonArrayGlobalAchievements[i].toObject().value("name").toString()){
                    accept=true;
                    break;
                    }
            }
            if(accept){
                int row = ui->FormAchievementsTableWidgetAchievements->rowCount();
                ui->FormAchievementsTableWidgetAchievements->insertRow(row);
                QString AchievementIcon=JASFG[j].toObject().value("icon").toString().mid(66,JASFG[j].toObject().value("icon").toString().length());
                if(!QFile::exists("images/achievements/"+appid+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png")){
                    ImageRequest *image;
                    switch (SaveImages) {
                        case 0:{
                            image = new ImageRequest(row,"");
                            break;
                            }
                        case 1:{
                            image = new ImageRequest(row,JASFG[j].toObject().value("icon").toString().mid(66,JASFG[j].toObject().value("icon").toString().length()));
                            break;
                            }
                        default:{
                            image = new ImageRequest(row,"");
                            break;
                            }
                        }
                    connect(image,SIGNAL(onReady(int, QString, ImageRequest *)),this,SLOT(OnResultImage(int, QString, ImageRequest *)));
                    image->Get(JASFG[j].toObject().value("icon").toString());
                    } else {
                    QPixmap pixmap;
                    pixmap.load("images/achievements/"+appid+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png", "PNG");
                    QLabel *label = new QLabel;
                    label->setPixmap(pixmap);
                    ui->FormAchievementsTableWidgetAchievements->setCellWidget(row,0,label);
                    }
                QTableWidgetItem *item2 = new QTableWidgetItem(JASFG[j].toObject().value("displayName").toString());
                item2->setTextAlignment(Qt::AlignCenter);
                ui->FormAchievementsTableWidgetAchievements->setItem(row,1,item2);
                QTableWidgetItem *item3 = new QTableWidgetItem(JASFG[j].toObject().value("description").toString());
                item3->setTextAlignment(Qt::AlignCenter);
                ui->FormAchievementsTableWidgetAchievements->setItem(row,2,item3);
                QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(JsonArrayGlobalAchievements[i].toObject().value("percent").toDouble())+"%");
                item4->setTextAlignment(Qt::AlignCenter);
                ui->FormAchievementsTableWidgetAchievements->setItem(row,3,item4);
                QTableWidgetItem *item5;
                if(JAPA[j].toObject().value("achieved").toInt()==1){
                    QDateTime date=QDateTime::fromSecsSinceEpoch(JAPA[j].toObject().value("unlocktime").toInt(),Qt::LocalTime);
                    item5 = new QTableWidgetItem(SLLanguage[23]+" "+date.toString("yyyy.MM.dd hh:mm"));
                    totalr++;
                    } else {
                    item5 = new QTableWidgetItem(SLLanguage[24]);
                    totalnr++;
                    }
                item5->setTextAlignment(Qt::AlignCenter);
                ui->FormAchievementsTableWidgetAchievements->setItem(row,4,item5);
                QPushButton *button1 = new QPushButton;
                button1->setIcon(favorites);
                connect(button1,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
                button1->setObjectName("FormGamesButtonFavorites"+appid+"&"+JAPA[j].toObject().value("apiname").toString());
                ui->FormAchievementsTableWidgetAchievements->setCellWidget(row,5,button1);
                QTableWidgetItem *item6 = new QTableWidgetItem(JAPA[j].toObject().value("apiname").toString());
                ui->FormAchievementsTableWidgetAchievements->setItem(row,6,item6);
                ui->FormAchievementsTableWidgetAchievements->setColumnHidden(6,true);
                JAPA.removeAt(j);
                JASFG.removeAt(j);
            }
        }
    double percent= 100.0*totalr/(totalr+totalnr);
    ui->FormAchievementsLabelTotalPersent->setText(QString::number(totalr)+"/"+QString::number(totalr+totalnr)+" = "+QString::number(percent)+"%");
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(0,65);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(1,100);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(2,315);
    ui->FormAchievementsTableWidgetAchievements->resizeColumnToContents(3);
    ui->FormAchievementsTableWidgetAchievements->setColumnWidth(4,80);
    ui->FormAchievementsTableWidgetAchievements->resizeColumnToContents(5);
    ui->FormAchievementsTableWidgetAchievements->resizeRowsToContents();

    filter = new bool*[ui->FormAchievementsTableWidgetAchievements->rowCount()];
    ShowCategories();
    ui->FormAchievementsGroupBoxAddCategory->setVisible(false);
    ui->FormAchievementsGroupBoxChangeCategory->setVisible(false);
    QWidget *widget1 = new QWidget;
    newcategoryvalueslayout = new QFormLayout;
    widget1->setLayout(newcategoryvalueslayout);
    ui->FormAchievementsScrollAreaValues->setWidget(widget1);
    QWidget *widget2 = new QWidget;
    changecategoryvalueslayout = new QFormLayout;
    widget2->setLayout(changecategoryvalueslayout);
    ui->FormAchievementsScrollAreaValuesChangeCategory->setWidget(widget2);
    ui->FormAchievementsLineEditTitleCategoryChangeCategory->setEnabled(false);
    ui->FormAchievementsLineEditNameAchievements->setFocus();
}

FormAchievements::~FormAchievements(){
    delete ui;
}
void FormAchievements::closeEvent(QCloseEvent *){
    emit return_to_games(this);
    //delete this;
}
void FormAchievements::on_return(FormCompare* a){
    windowchildcount--;
    this->setVisible(true);
    a->deleteLater();
}
void FormAchievements::on_FormAchievementsButtonReturn_clicked(){
    emit return_to_games(this);
    //delete this;
}

void FormAchievements::FavoritesClicked(){

}

void FormAchievements::on_FormAchievementsLineEditNameAchievements_textChanged(const QString&){
    for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++)
        if((ui->FormAchievementsTableWidgetAchievements->item(i,1)->text().toLower().indexOf(ui->FormAchievementsLineEditNameAchievements->text().toLower())>-1)||(ui->FormAchievementsTableWidgetAchievements->item(i,2)->text().toLower().indexOf(ui->FormAchievementsLineEditNameAchievements->text().toLower())>-1))
            filter[i][0]=true; else
            filter[i][0]=false;
    UpdateHiddenRows();
}
void FormAchievements::on_FormAchievementsButtonFindAchievement_clicked(){
    on_FormAchievementsLineEditNameAchievements_textChanged(ui->FormAchievementsLineEditNameAchievements->text());
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

void FormAchievements::OnResultImage(int i, QString Save, ImageRequest *imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    if(!Save.isEmpty()){
        pixmap.save("images/achievements/"+appid+"/"+Save.mid(Save.indexOf("/",1)+1,Save.length()-1).remove(".jpg")+".png", "PNG");
    }
    ui->FormAchievementsTableWidgetAchievements->setCellWidget(i,0,label);
    ui->FormAchievementsTableWidgetAchievements->resizeRowToContents(i);
    imgr->deleteLater();
}
void FormAchievements::ShowCategories(){
    QDir categories("Files/Categories/"+appid);
    categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categories.setSorting(QDir::Name);
    QFileInfoList list = categories.entryInfoList();
    if(categories.exists()){
        while(ui->FormAchievementsComboBoxCategoriesChangeCategory->count()>1){
            ui->FormAchievementsComboBoxCategoriesChangeCategory->removeItem(1);
        }
        QFormLayout *layout1 = new QFormLayout;
        QFormLayout *layout2 = new QFormLayout;
        QWidget *widget1 = new QWidget;
        QWidget *widget2 = new QWidget;
        for (int i = 0; i < list.size(); ++i){
            QFile category("Files/Categories/"+appid+"/"+list.at(i).fileName());
            category.open(QFile::ReadOnly);
            QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
            if(cat.object().value("values").toArray().size()==1){
                QCheckBox *chb = new QCheckBox;
                chb->setText(cat.object().value("name").toString());
                chb->setObjectName("Category"+QString::number(i));
                connect(chb,SIGNAL(stateChanged(int)),this,SLOT(on_CheckBoxCategory_Change(int)));
                layout2->addRow(chb);
            } else {
                QComboBox *cb = new QComboBox;
                cb->addItem(SLLanguage[37]);
                for (int j=0;j<cat.object().value("values").toArray().size();j++) {
                    cb->addItem(cat.object().value("values").toArray().at(j).toString());
                }
                cb->setObjectName("Category"+QString::number(i));
                connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(on_ComboBoxCategory_Change(int)));
                layout1->addRow(new QLabel(cat.object().value("name").toString()),cb);
            }
            ui->FormAchievementsComboBoxCategoriesChangeCategory->addItem(cat.object().value("name").toString());
            category.close();
            }
        widget1->setLayout(layout1);
        widget2->setLayout(layout2);
        ui->FormAchievementsScrollAreaCategories->setWidget(widget1);
        ui->FormAchievementsScrollAreaCheckCategories->setWidget(widget2);

        if(layout1->rowCount()==0){
            ui->FormAchievementsScrollAreaCategories->hide();
        } else {
            ui->FormAchievementsScrollAreaCategories->show();
        }
        if(layout2->rowCount()==0){
            ui->FormAchievementsScrollAreaCheckCategories->hide();
        } else {
            ui->FormAchievementsScrollAreaCheckCategories->show();
        }
    }
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

void FormAchievements::on_ComboBoxCategory_Change(int index){
    QComboBox *cb = qobject_cast<QComboBox*>(sender());
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
void FormAchievements::on_CheckBoxCategory_Change(int ind){
    QCheckBox *cb = qobject_cast<QCheckBox*>(sender());
    QDir categories("Files/Categories/"+appid);
    if(categories.exists()){
        categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        categories.setSorting(QDir::Name);
        QFileInfoList list = categories.entryInfoList();
        QFile category("Files/Categories/"+appid+"/"+list.at(cb->objectName().mid(8,cb->objectName().length()).toInt()).fileName());
        category.open(QFile::ReadOnly);
        QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
        QJsonArray selecteditem = cat.object().value(cat.object().value("values").toArray().at(0).toString()).toArray();
        if(ind!=0)
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
void FormAchievements::on_FormAchievementsButtonAddCategory_clicked(){
    ui->FormAchievementsButtonAddCategory->setEnabled(false);
    ui->FormAchievementsButtonChangeCategory->setEnabled(false);
    ui->FormAchievementsGroupBoxAddCategory->setVisible(true);
}
void FormAchievements::on_FormAchievementsButtonChangeCategory_clicked(){
    ui->FormAchievementsButtonAddCategory->setEnabled(false);
    ui->FormAchievementsButtonChangeCategory->setEnabled(false);
    ui->FormAchievementsGroupBoxChangeCategory->setVisible(true);
}
void FormAchievements::on_FormAchievementsButtonUpdate_clicked(){
    QNetworkAccessManager manager;
    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &replyPlayerAchievements = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+id)));
    loop.exec();
    JsonDocPlayerAchievements = QJsonDocument::fromJson(replyPlayerAchievements.readAll());
    QJsonArray JsonArrayPlayerAchievements = JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray();
    QNetworkReply &replyNumber = *manager.get(QNetworkRequest(QString("https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?key="+key+"&appid="+appid)));
    loop.exec();
    QJsonDocument DocNumber = QJsonDocument::fromJson(replyNumber.readAll());
    ui->FormAchievementsLabelGameOnline->setText(SLLanguage[27]+": "+QString::number(JsonDocNumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble()));
    int totalr=0;
    int totalnr=0;
    if(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("success").toBool()==false){
        ui->FormAchievementsTableWidgetAchievements->insertRow(0);
        QTableWidgetItem *item1 = new QTableWidgetItem("Error");
        ui->FormAchievementsTableWidgetAchievements->setItem(0,1,item1);
        QTableWidgetItem *item2 = new QTableWidgetItem(JsonDocPlayerAchievements.object().value("playerstats").toObject().value("error").toString());
        ui->FormAchievementsTableWidgetAchievements->setItem(0,2,item2);
        ui->FormAchievementsTableWidgetAchievements->setColumnHidden(3,true);
        ui->FormAchievementsTableWidgetAchievements->setColumnHidden(4,true);
        ui->FormAchievementsTableWidgetAchievements->setColumnHidden(5,true);
        ui->FormAchievementsTableWidgetAchievements->setColumnHidden(6,true);
        ui->FormAchievementsGroupBoxFilter->setEnabled(false);
    } else
    for(int i=0;i<JsonArrayGlobalAchievements.size();i++){
        if(JsonArrayGlobalAchievements[i].toObject().value("percent")!=0){
            int j=0;
            bool accept=false;
            for(;j<JsonArrayPlayerAchievements.size();j++){
                if(JsonArrayPlayerAchievements[j].toObject().value("apiname").toString()==JsonArrayGlobalAchievements[i].toObject().value("name").toString()){
                    accept=true;
                    break;
                    }
            }
            if(accept){
                QModelIndex api = ui->FormAchievementsTableWidgetAchievements->model()->index(i,6);
                QTableWidgetItem *itemd;
                if(JsonArrayPlayerAchievements[j].toObject().value("achieved").toInt()==1){
                    QDateTime date=QDateTime::fromSecsSinceEpoch(JsonArrayPlayerAchievements[j].toObject().value("unlocktime").toInt(),Qt::LocalTime);
                    itemd = new QTableWidgetItem(SLLanguage[23]+" "+date.toString("yyyy.MM.dd hh:mm"));
                    totalr++;
                    } else {
                    totalnr++;
                    itemd = new QTableWidgetItem(SLLanguage[24]);
                    }
                if((JsonArrayPlayerAchievements[j].toObject().value("apiname").toString()!=api.data())||(itemd->text()!=ui->FormAchievementsTableWidgetAchievements->item(i,4)->text())){
                    delete ui->FormAchievementsTableWidgetAchievements->item(i,4);
                    ui->FormAchievementsTableWidgetAchievements->setItem(i,4,itemd);
                    }
            } else {
                JsonArrayGlobalAchievements.removeAt(i);
                i--;
            }
        }
        }
    double percent= 100.0*totalr/(totalr+totalnr);
    ui->FormAchievementsLabelTotalPersent->setText(QString::number(totalr)+"/"+QString::number(totalr+totalnr)+" = "+QString::number(percent)+"%");
    if (ui->FormAchievementsRadioButtonReached->isChecked()){
        on_FormAchievementsRadioButtonReached_clicked();
    } else
        if (ui->FormAchievementsRadioButtonNotReached->isChecked()){
            on_FormAchievementsRadioButtonNotReached_clicked();
        }
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
void FormAchievements::on_FormAchievementsButtonAddValueNewCategory_clicked(){
//    bool accept=true;
//    if(ui->FormAchievementsTableWidgetAchievements->columnCount()>7)
//        for (int i=7;i<ui->FormAchievementsTableWidgetAchievements->columnCount();i++){
//            if(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->FormAchievementsLineEditTitleValueNewCategory->text()){
//               accept=false;
//            }
//        }
//    if((ui->FormAchievementsLineEditTitleValueNewCategory->text()!="")&&(accept)){
        ui->FormAchievementsTableWidgetAchievements->setColumnCount(ui->FormAchievementsTableWidgetAchievements->columnCount()+1);
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(ui->FormAchievementsTableWidgetAchievements->columnCount()-1,new QTableWidgetItem());
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
        QHBoxLayout *bl = new QHBoxLayout;
        QPushButton *btn = new QPushButton;
        QLineEdit *val = new QLineEdit();
        QPushButton *up = new QPushButton();
        QPushButton *down = new QPushButton();
        QPushButton *select = new QPushButton();
        QPushButton *unselect = new QPushButton();
        btn->setObjectName("btnNewCategoryDeleteValue"+QString::number(newcategoryvalueslayout->rowCount()));
        val->setObjectName("liedNewCategoryValue"+QString::number(newcategoryvalueslayout->rowCount()));
        up->setObjectName("btnNewCategoryUpValue"+QString::number(newcategoryvalueslayout->rowCount()));
        down->setObjectName("btnNewCategoryDownValue"+QString::number(newcategoryvalueslayout->rowCount()));
        select->setObjectName("btnNewCategorySelectValue"+QString::number(newcategoryvalueslayout->rowCount()));
        unselect->setObjectName("btnNewCategoryUnSelectValue"+QString::number(newcategoryvalueslayout->rowCount()));
        int row = newcategoryvalueslayout->rowCount();
        if(row==0){
            up->setEnabled(false);
        } else {
            findChild<QPushButton*>("btnNewCategoryDownValue"+QString::number(newcategoryvalueslayout->rowCount()-1))->setEnabled(true);
        }
        down->setEnabled(false);
        btn->setIcon(QIcon("images/program/delete.png"));
        //select->setIcon();
        //unselect->setIcon();
        switch (Theme) {
        case 1:{
            up->setIcon(QIcon("images/program/up_white.png"));
            down->setIcon(QIcon("images/program/down_white.png"));
            break;
        }
        case 2:{
            up->setIcon(QIcon("images/program/up_black.png"));
            down->setIcon(QIcon("images/program/down_black.png"));
            break;
        }
        }
        connect(btn,SIGNAL(clicked()),this,SLOT(on_buttonNewCategoryDeleteValues_clicked()));
        connect(val,SIGNAL(editingFinished()),this,SLOT(EditLineEditNewCategoryValue()));
        connect(up,SIGNAL(clicked()),this,SLOT(on_buttonNewCategoryUpValues_clicked()));
        connect(down,SIGNAL(clicked()),this,SLOT(on_buttonNewCategoryDownValues_clicked()));
        connect(select,SIGNAL(clicked()),this,SLOT(on_buttonNewCategorySelectValues_clicked()));
        connect(unselect,SIGNAL(clicked()),this,SLOT(on_buttonNewCategoryUnSelectValues_clicked()));
        bl->addWidget(val);
        bl->addWidget(up);
        bl->addWidget(down);
        bl->addWidget(select);
        bl->addWidget(unselect);
        bl->addWidget(btn);
        bl->setMargin(0);
        QWidget *Wbl = new QWidget;
        Wbl->setLayout(bl);
        newcategoryvalueslayout->addRow(Wbl);
//    } else
//        QMessageBox::warning(this,SLLanguage[28],SLLanguage[29]);
}
void FormAchievements::on_FormAchievementsButtonAcceptNewCategory_clicked(){
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
                if(ui->FormAchievementsCheckBoxNewCategoryOneValue->isChecked()){
                    if(newcategoryvalueslayout->rowCount()>0){
                        QMessageBox::StandardButton btn=QMessageBox::question(this,SLLanguage[39],SLLanguage[40].mid(0,SLLanguage[40].indexOf("\\n")-1)+"\n"+SLLanguage[40].mid(SLLanguage[40].indexOf("\\n")+2,SLLanguage[40].length()-SLLanguage[40].indexOf("\n")-2),QMessageBox::Yes|QMessageBox::No);
                        if(btn==QMessageBox::No){
                            qDebug()<<0;
                            return;
                        }
                    }
                    values.append(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(ui->FormAchievementsTableWidgetAchievements->columnCount()-1)->text());
                    QJsonArray valn;
                    for (int j=0;j<ui->FormAchievementsTableWidgetAchievements->rowCount();j++){
                        if(ui->FormAchievementsTableWidgetAchievements->item(j,ui->FormAchievementsTableWidgetAchievements->columnCount()-1)->checkState()){
                            valn.append(ui->FormAchievementsTableWidgetAchievements->item(j,6)->text());
                            }
                        group[ui->FormAchievementsLineEditTitleNewCategory->text()]=valn;
                        }
                    } else {
                    for (int i=7;i<ui->FormAchievementsTableWidgetAchievements->columnCount();i++){
                        if(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(i)->text()==""){
                            Category.close();
                            Category.remove();
                            QMessageBox::warning(this,SLLanguage[28],SLLanguage[29]);
                            qDebug()<<1<<i;
                            return;
                            }
                        for (int j=7;j<i;j++){
                            if(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(j)->text()){
                                Category.close();
                                Category.remove();
                                QMessageBox::warning(this,SLLanguage[28],SLLanguage[29]);
                                qDebug()<<2<<i<<j;
                                return;
                                }
                            }
                        }
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
                    }
                group["values"]=values;
                category.setObject(group);
                Category.write(category.toJson());
                Category.close();
                delete ui->FormAchievementsScrollAreaCategories->layout();
                delete ui->FormAchievementsScrollAreaCheckCategories->layout();
                ShowCategories();
                QMessageBox::information(this,SLLanguage[30],SLLanguage[31]);
                on_FormAchievementsButtonCancelNewCategory_clicked();
            } else
                QMessageBox::warning(this,SLLanguage[28],SLLanguage[32]);
        }
    } else
        QMessageBox::warning(this,SLLanguage[28],SLLanguage[33]);
}
void FormAchievements::on_FormAchievementsCheckBoxNewCategoryOneValue_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        ui->FormAchievementsButtonAddValueNewCategory->setEnabled(true);
        ui->FormAchievementsScrollAreaValues->setEnabled(true);
        for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->columnCount()-7;i++) {
            ui->FormAchievementsTableWidgetAchievements->setColumnHidden(7+i,false);
        }
        ui->FormAchievementsTableWidgetAchievements->setColumnCount(ui->FormAchievementsTableWidgetAchievements->columnCount()-1);
        disconnect(ui->FormAchievementsLineEditTitleNewCategory,SIGNAL(editingFinished()),this,SLOT(on_Change_Title_NewCategory_OneValue()));
        break;
        }
    case 2:{
        ui->FormAchievementsButtonAddValueNewCategory->setEnabled(false);
        ui->FormAchievementsScrollAreaValues->setEnabled(false);
        for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->columnCount()-7;i++) {
            ui->FormAchievementsTableWidgetAchievements->setColumnHidden(7+i,true);
        }
        ui->FormAchievementsTableWidgetAchievements->setColumnCount(ui->FormAchievementsTableWidgetAchievements->columnCount()+1);
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(ui->FormAchievementsTableWidgetAchievements->columnCount()-1,new QTableWidgetItem(ui->FormAchievementsLineEditTitleNewCategory->text()));
        for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++){
            QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->FormAchievementsTableWidgetAchievements->setItem(i,ui->FormAchievementsTableWidgetAchievements->columnCount()-1, pItem);
        }
        connect(ui->FormAchievementsLineEditTitleNewCategory,SIGNAL(editingFinished()),this,SLOT(on_Change_Title_NewCategory_OneValue()));
        break;
        }
    }
}
void FormAchievements::on_Change_Title_NewCategory_OneValue(){
    ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(ui->FormAchievementsTableWidgetAchievements->columnCount()-1)->setText(ui->FormAchievementsLineEditTitleNewCategory->text());
}

void FormAchievements::EditLineEditNewCategoryValue(){
    QLineEdit *lied =qobject_cast<QLineEdit*>(sender());
    int i=lied->objectName().mid(20,lied->objectName().length()-20).toInt();
    ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(7+i)->setText(lied->text());
}
void FormAchievements::on_buttonNewCategoryUpValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(21,btn->objectName().length()-21).toInt();
    if(i==0){
        QMessageBox::warning(this,"","Ашипка");
    } else {
        for (int j=0;j<ui->FormAchievementsTableWidgetAchievements->rowCount();j++) {
            Qt::CheckState pItem1 = ui->FormAchievementsTableWidgetAchievements->item(j,7+i)->checkState();
            Qt::CheckState pItem2 = ui->FormAchievementsTableWidgetAchievements->item(j,6+i)->checkState();
            ui->FormAchievementsTableWidgetAchievements->item(j,6+i)->setCheckState(pItem1);
            ui->FormAchievementsTableWidgetAchievements->item(j,7+i)->setCheckState(pItem2);
        }
        QString hh=ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(7+i)->text();
        ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(7+i)->setText(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(6+i)->text());
        ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(6+i)->setText(hh);
        QString text=findChild<QLineEdit*>("liedNewCategoryValue"+QString::number(i))->text();
        findChild<QLineEdit*>("liedNewCategoryValue"+QString::number(i))->setText(findChild<QLineEdit*>("liedNewCategoryValue"+QString::number(i-1))->text());
        findChild<QLineEdit*>("liedNewCategoryValue"+QString::number(i-1))->setText(text);
    }
}
void FormAchievements::on_buttonNewCategoryDownValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(23,btn->objectName().length()-23).toInt();
    if(i==newcategoryvalueslayout->rowCount()){
        QMessageBox::warning(this,"","Ашипка");
    } else {
        for (int j=0;j<ui->FormAchievementsTableWidgetAchievements->rowCount();j++) {
            Qt::CheckState pItem1 = ui->FormAchievementsTableWidgetAchievements->item(j,7+i)->checkState();
            Qt::CheckState pItem2 = ui->FormAchievementsTableWidgetAchievements->item(j,8+i)->checkState();
            ui->FormAchievementsTableWidgetAchievements->item(j,8+i)->setCheckState(pItem1);
            ui->FormAchievementsTableWidgetAchievements->item(j,7+i)->setCheckState(pItem2);
        }
        QString hh=ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(7+i)->text();
        ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(7+i)->setText(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(8+i)->text());
        ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(8+i)->setText(hh);
        QString text=findChild<QLineEdit*>("liedNewCategoryValue"+QString::number(i))->text();
        findChild<QLineEdit*>("liedNewCategoryValue"+QString::number(i))->setText(findChild<QLineEdit*>("liedNewCategoryValue"+QString::number(i+1))->text());
        findChild<QLineEdit*>("liedNewCategoryValue"+QString::number(i+1))->setText(text);
    }
}
void FormAchievements::on_buttonNewCategoryDeleteValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(25,btn->objectName().length()-25).toInt();
    ui->FormAchievementsTableWidgetAchievements->removeColumn(7+i);
    delete btn;
    newcategoryvalueslayout->removeRow(i);
    i++;
    while(i<newcategoryvalueslayout->rowCount()+1){
        QPushButton * butn = findChild<QPushButton*>("btnNewCategoryDeleteValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btnNewCategoryDeleteValue"+QString::number(i-1));
        QLineEdit* lied = findChild<QLineEdit*>("liedNewCategoryValue"+QString::number(i));
        if(lied)
            lied->setObjectName("liedNewCategoryValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btnNewCategoryUpValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btnNewCategoryUpValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btnNewCategoryDownValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btnNewCategoryDownValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btnNewCategorySelectValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btnNewCategorySelectValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btnNewCategoryUnSelectValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btnNewCategoryUnSelectValue"+QString::number(i-1));
        i++;
    }
}
void FormAchievements::on_buttonNewCategorySelectValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(25,btn->objectName().length()-25).toInt();
    ui->FormAchievementsTableWidgetAchievements->selectColumn(1);
    QList<QTableWidgetItem *> rows = ui->FormAchievementsTableWidgetAchievements->selectedItems();
    qDebug()<<rows.size();
    for (int i=0;i<rows.size();i++) {
        ui->FormAchievementsTableWidgetAchievements->item(rows.at(i)->row(),7+j)->setCheckState(Qt::Checked);
    }
    ui->FormAchievementsTableWidgetAchievements->selectColumn(0);
}
void FormAchievements::on_buttonNewCategoryUnSelectValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(27,btn->objectName().length()-27).toInt();
    ui->FormAchievementsTableWidgetAchievements->selectColumn(1);
    QList<QTableWidgetItem *> rows = ui->FormAchievementsTableWidgetAchievements->selectedItems();
    qDebug()<<rows.size();
    for (int i=0;i<rows.size();i++) {
        ui->FormAchievementsTableWidgetAchievements->item(rows.at(i)->row(),7+j)->setCheckState(Qt::Unchecked);
    }
    ui->FormAchievementsTableWidgetAchievements->selectColumn(0);
}

void FormAchievements::on_FormAchievementsComboBoxCategoriesChangeCategory_activated(int index){
    QDir categories("Files/Categories/"+appid);
    if(categories.exists()){
        ui->FormAchievementsTableWidgetAchievements->setColumnCount(7);
        ui->FormAchievementsLineEditTitleCategoryChangeCategory->setText(ui->FormAchievementsComboBoxCategoriesChangeCategory->itemText(index));
        while(!changecategoryvalueslayout->isEmpty()){
            changecategoryvalueslayout->removeRow(0);
        }
        categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        categories.setSorting(QDir::Name);
        QFileInfoList list = categories.entryInfoList();
        if(index!=0){
            QFile category("Files/Categories/"+appid+"/"+list.at(index-1).fileName());
            category.open(QFile::ReadOnly);
            QJsonDocument categor=QJsonDocument().fromJson(category.readAll());
            ui->FormAchievementsLineEditTitleCategoryChangeCategory->setEnabled(true);
            for (int i=0;i<categor.object().value("values").toArray().size();i++) {
                QHBoxLayout *bl = new QHBoxLayout;
                QPushButton *btn = new QPushButton;
                QLineEdit *val = new QLineEdit(categor.object().value("values").toArray().at(i).toString());
                QPushButton *up = new QPushButton();
                QPushButton *down = new QPushButton();
                QPushButton *select = new QPushButton();
                QPushButton *unselect = new QPushButton();
                btn->setObjectName("btnChangeCategoryDeleteValue"+QString::number(changecategoryvalueslayout->rowCount()));
                val->setObjectName("liedChangeCategoryValue"+QString::number(changecategoryvalueslayout->rowCount()));
                up->setObjectName("btnChangeCategoryUpValue"+QString::number(changecategoryvalueslayout->rowCount()));
                down->setObjectName("btnChangeCategoryDownValue"+QString::number(changecategoryvalueslayout->rowCount()));
                select->setObjectName("btnChangeCategorySelectValue"+QString::number(changecategoryvalueslayout->rowCount()));
                unselect->setObjectName("btnChangeCategoryUnSelectValue"+QString::number(changecategoryvalueslayout->rowCount()));
                if(i==0) up->setEnabled(false);
                if(i==categor.object().value("values").toArray().size()-1) down->setEnabled(false);
                btn->setIcon(QIcon("images/program/delete.png"));
                //select->setIcon();
                //unselect->setIcon();
                switch (Theme) {
                case 1:{
                    up->setIcon(QIcon("images/program/up_white.png"));
                    down->setIcon(QIcon("images/program/down_white.png"));
                    break;
                }
                case 2:{
                    up->setIcon(QIcon("images/program/up_black.png"));
                    down->setIcon(QIcon("images/program/down_black.png"));
                    break;
                }
                }
                connect(btn,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryDeleteValues_clicked()));
                connect(val,SIGNAL(editingFinished()),this,SLOT(EditLineEditChangeCategoryValue()));
                connect(up,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryUpValues_clicked()));
                connect(down,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryDownValues_clicked()));
                connect(select,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategorySelectValues_clicked()));
                connect(unselect,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryUnSelectValues_clicked()));
                //changecategoryvalueslayout->addRow(categor.object().value("values").toArray().at(i).toString(),btn);
                bl->addWidget(val);
                bl->addWidget(up);
                bl->addWidget(down);
                bl->addWidget(select);
                bl->addWidget(unselect);
                bl->addWidget(btn);
                bl->setMargin(0);
                QWidget *Wbl = new QWidget;
                Wbl->setLayout(bl);
//                changecategoryvalueslayout->addWidget(val,i,0);
//                changecategoryvalueslayout->addWidget(up,i,1);
//                changecategoryvalueslayout->addWidget(down,i,2);
//                changecategoryvalueslayout->addWidget(btn,i,3);
                changecategoryvalueslayout->addRow(Wbl);
                ui->FormAchievementsTableWidgetAchievements->insertColumn(ui->FormAchievementsTableWidgetAchievements->columnCount());
                ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(ui->FormAchievementsTableWidgetAchievements->columnCount()-1,new QTableWidgetItem(categor.object().value("values").toArray().at(i).toString()));
                for (int j=0;j<ui->FormAchievementsTableWidgetAchievements->rowCount();j++) {
                    QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
                    pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
                    bool accept=true;
                    for (int k=0;k<categor.object().value(categor.object().value("values").toArray().at(i).toString()).toArray().size();k++) {
                        if(ui->FormAchievementsTableWidgetAchievements->item(j,6)->text()==categor.object().value(categor.object().value("values").toArray().at(i).toString()).toArray().at(k).toString()){
                            accept=false;
                            break;
                        }
                    }
                    if(accept){
                        pItem->setCheckState(Qt::Unchecked);
                        } else {
                        pItem->setCheckState(Qt::Checked);
                        }
                    ui->FormAchievementsTableWidgetAchievements->setItem(j,ui->FormAchievementsTableWidgetAchievements->columnCount()-1, pItem);
                }
            }
            category.close();
        } else {
            ui->FormAchievementsLineEditTitleCategoryChangeCategory->setEnabled(false);
        }
    }
}
void FormAchievements::on_FormAchievementsButtonAddValueChangeCategory_clicked(){
//    bool accept=true;
//    if(ui->FormAchievementsTableWidgetAchievements->columnCount()>7)
//        for (int i=7;i<ui->FormAchievementsTableWidgetAchievements->columnCount();i++){
//            if(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->FormAchievementsLineEditTitleValueChangeCategory->text()){
//               accept=false;
//            }
//        }
//    if((ui->FormAchievementsLineEditTitleValueChangeCategory->text()!="")&&(accept)){
        ui->FormAchievementsTableWidgetAchievements->setColumnCount(ui->FormAchievementsTableWidgetAchievements->columnCount()+1);
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(ui->FormAchievementsTableWidgetAchievements->columnCount()-1,new QTableWidgetItem());
        for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++){
            QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->FormAchievementsTableWidgetAchievements->setItem(i,ui->FormAchievementsTableWidgetAchievements->columnCount()-1, pItem);
        }
        QHBoxLayout *bl = new QHBoxLayout;
        QPushButton *btn = new QPushButton;
        QLineEdit *val = new QLineEdit();
        QPushButton *up = new QPushButton();
        QPushButton *down = new QPushButton();
        QPushButton *select = new QPushButton();
        QPushButton *unselect = new QPushButton();
        btn->setObjectName("btnChangeCategoryDeleteValue"+QString::number(changecategoryvalueslayout->rowCount()));
        val->setObjectName("liedChangeCategoryValue"+QString::number(changecategoryvalueslayout->rowCount()));
        up->setObjectName("btnChangeCategoryUpValue"+QString::number(changecategoryvalueslayout->rowCount()));
        down->setObjectName("btnChangeCategoryDownValue"+QString::number(changecategoryvalueslayout->rowCount()));
        select->setObjectName("btnChangeCategorySelectValue"+QString::number(changecategoryvalueslayout->rowCount()));
        unselect->setObjectName("btnChangeCategoryUnSelectValue"+QString::number(changecategoryvalueslayout->rowCount()));
        int row = changecategoryvalueslayout->rowCount();
        if(row==0){
            up->setEnabled(false);
        } else {
            findChild<QPushButton*>("btnChangeCategoryDownValue"+QString::number(changecategoryvalueslayout->rowCount()-1))->setEnabled(true);
        }
        down->setEnabled(false);
        btn->setIcon(QIcon("images/program/delete.png"));
        //select->setIcon();
        //unselect->setIcon();
        switch (Theme) {
        case 1:{
            up->setIcon(QIcon("images/program/up_white.png"));
            down->setIcon(QIcon("images/program/down_white.png"));
            break;
        }
        case 2:{
            up->setIcon(QIcon("images/program/up_black.png"));
            down->setIcon(QIcon("images/program/down_black.png"));
            break;
        }
        }
        connect(btn,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryDeleteValues_clicked()));
        connect(val,SIGNAL(editingFinished()),this,SLOT(EditLineEditChangeCategoryValue()));
        connect(up,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryUpValues_clicked()));
        connect(down,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryDownValues_clicked()));
        connect(select,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategorySelectValues_clicked()));
        connect(unselect,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryUnSelectValues_clicked()));
        bl->addWidget(val);
        bl->addWidget(up);
        bl->addWidget(down);
        bl->addWidget(select);
        bl->addWidget(unselect);
        bl->addWidget(btn);
        bl->setMargin(0);
        QWidget *Wbl = new QWidget;
        Wbl->setLayout(bl);
        changecategoryvalueslayout->addRow(Wbl);
//    } else
//        QMessageBox::warning(this,SLLanguage[28],SLLanguage[29]);
}
void FormAchievements::on_FormAchievementsButtonCancelChangeCategory_clicked(){
    ui->FormAchievementsTableWidgetAchievements->setColumnCount(7);
    ui->FormAchievementsGroupBoxChangeCategory->setVisible(false);
    ui->FormAchievementsButtonAddCategory->setEnabled(true);
    ui->FormAchievementsButtonChangeCategory->setEnabled(true);
    ui->FormAchievementsComboBoxCategoriesChangeCategory->setCurrentIndex(0);
    ui->FormAchievementsLineEditTitleCategoryChangeCategory->setText("");
    ui->FormAchievementsLineEditTitleCategoryChangeCategory->setEnabled(false);
    while(!changecategoryvalueslayout->isEmpty()){
        changecategoryvalueslayout->removeRow(0);
    }
}
void FormAchievements::on_FormAchievementsButtonDeleteCategory_clicked(){
    QMessageBox::StandardButton btn=QMessageBox::question(this,SLLanguage[39],SLLanguage[41],QMessageBox::Yes|QMessageBox::No);
    if(btn==QMessageBox::No){
        return;
    }
    QDir categories("Files/Categories/"+appid);
    delete ui->FormAchievementsScrollAreaCategories->layout();
    delete ui->FormAchievementsScrollAreaCheckCategories->layout();
        if(categories.exists()){
            if(ui->FormAchievementsComboBoxCategoriesChangeCategory->currentIndex()!=0){
            if(QFile("Files/Categories/"+appid+"/"+ui->FormAchievementsComboBoxCategoriesChangeCategory->currentText()+".json").exists()){
                QFile("Files/Categories/"+appid+"/"+ui->FormAchievementsComboBoxCategoriesChangeCategory->currentText()+".json").remove();
                }
            ShowCategories();
            ui->FormAchievementsLineEditNameAchievements->setText("");
            ui->FormAchievementsRadioButtonAll->setChecked(true);
            ui->FormAchievementsCheckBoxFavorites->setChecked(false);
            QMessageBox::information(this,SLLanguage[30],SLLanguage[35]);
            on_FormAchievementsButtonCancelChangeCategory_clicked();
            }
        }
}
void FormAchievements::on_FormAchievementsButtonAcceptChangeCategory_clicked(){
    if(!QDir("Files/Categories/"+appid).exists()){
        QDir().mkdir("Files/Categories/"+appid);
    }
    if(ui->FormAchievementsLineEditTitleCategoryChangeCategory->text()!=""){
        if(ui->FormAchievementsLineEditTitleCategoryChangeCategory->text()!=ui->FormAchievementsComboBoxCategoriesChangeCategory->currentText()){
            if(QFile::exists("Files/Categories/"+appid+"/"+ui->FormAchievementsComboBoxCategoriesChangeCategory->currentText()+".json")){
                QFile("Files/Categories/"+appid+"/"+ui->FormAchievementsComboBoxCategoriesChangeCategory->currentText()+".json").remove();
            }
        }
        QFile Category("Files/Categories/"+appid+"/"+ui->FormAchievementsLineEditTitleCategoryChangeCategory->text()+".json");
        if((!QFile::exists("Files/Categories/"+appid+"/"+ui->FormAchievementsLineEditTitleCategoryChangeCategory->text()+".json"))||(ui->FormAchievementsLineEditTitleCategoryChangeCategory->text()==ui->FormAchievementsComboBoxCategoriesChangeCategory->currentText())){
            QJsonDocument category;
            QJsonArray groups;
            QJsonObject group;
            group["name"]=ui->FormAchievementsLineEditTitleCategoryChangeCategory->text();
            QJsonArray values;
            if(ui->FormAchievementsCheckBoxChangeCategoryOneValue->isChecked()){
                if(changecategoryvalueslayout->rowCount()>0){
                    QMessageBox::StandardButton btn=QMessageBox::question(this,SLLanguage[39],SLLanguage[40].mid(0,SLLanguage[40].indexOf("\\n")-1)+"\n"+SLLanguage[40].mid(SLLanguage[40].indexOf("\\n")+2,SLLanguage[40].length()-SLLanguage[40].indexOf("\n")-2),QMessageBox::Yes|QMessageBox::No);
                    if(btn==QMessageBox::No){
                        return;
                    }
                }
                Category.open(QIODevice::WriteOnly);
                values.append(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(ui->FormAchievementsTableWidgetAchievements->columnCount()-1)->text());
                QJsonArray valn;
                for (int j=0;j<ui->FormAchievementsTableWidgetAchievements->rowCount();j++){
                    if(ui->FormAchievementsTableWidgetAchievements->item(j,ui->FormAchievementsTableWidgetAchievements->columnCount()-1)->checkState()){
                        valn.append(ui->FormAchievementsTableWidgetAchievements->item(j,6)->text());
                        }
                    group[ui->FormAchievementsLineEditTitleCategoryChangeCategory->text()]=valn;
                    }
            } else {
                for (int i=7;i<ui->FormAchievementsTableWidgetAchievements->columnCount();i++){
                    if(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(i)->text()==""){
                        Category.close();
                        QMessageBox::warning(this,SLLanguage[28],SLLanguage[29]);
                        return;
                        }
                    for (int j=7;j<i;j++) {
                        if(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(j)->text()){
                            Category.close();
                            QMessageBox::warning(this,SLLanguage[28],SLLanguage[29]);
                            return;
                            }
                        }
                    }
                Category.open(QIODevice::WriteOnly);
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
                }
            group["values"]=values;
            category.setObject(group);
            Category.write(category.toJson());
            Category.close();
            ui->FormAchievementsLineEditTitleCategoryChangeCategory->setText("");
            ui->FormAchievementsLineEditTitleCategoryChangeCategory->setEnabled(false);
            delete ui->FormAchievementsScrollAreaCategories->layout();
            delete ui->FormAchievementsScrollAreaCheckCategories->layout();
            ShowCategories();
            ui->FormAchievementsLineEditNameAchievements->setText("");
            ui->FormAchievementsRadioButtonAll->setChecked(true);
            ui->FormAchievementsCheckBoxFavorites->setChecked(false);
            QMessageBox::information(this,SLLanguage[30],SLLanguage[34]);
            on_FormAchievementsButtonCancelChangeCategory_clicked();
            } else
                QMessageBox::warning(this,SLLanguage[28],SLLanguage[32]);
        } else
            QMessageBox::warning(this,SLLanguage[28],SLLanguage[33]);
}
void FormAchievements::on_FormAchievementsCheckBoxChangeCategoryOneValue_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        ui->FormAchievementsButtonAddValueChangeCategory->setEnabled(true);
        ui->FormAchievementsScrollAreaValuesChangeCategory->setEnabled(true);
        for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->columnCount()-7;i++) {
            ui->FormAchievementsTableWidgetAchievements->setColumnHidden(7+i,false);
        }
        ui->FormAchievementsTableWidgetAchievements->setColumnCount(ui->FormAchievementsTableWidgetAchievements->columnCount()-1);
        disconnect(ui->FormAchievementsLineEditTitleCategoryChangeCategory,SIGNAL(editingFinished()),this,SLOT(on_Change_Title_ChangeCategory_OneValue()));
        break;
        }
    case 2:{
        ui->FormAchievementsButtonAddValueChangeCategory->setEnabled(false);
        ui->FormAchievementsScrollAreaValuesChangeCategory->setEnabled(false);
        for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->columnCount()-7;i++) {
            ui->FormAchievementsTableWidgetAchievements->setColumnHidden(7+i,true);
        }
        ui->FormAchievementsTableWidgetAchievements->setColumnCount(ui->FormAchievementsTableWidgetAchievements->columnCount()+1);
        ui->FormAchievementsTableWidgetAchievements->setHorizontalHeaderItem(ui->FormAchievementsTableWidgetAchievements->columnCount()-1,new QTableWidgetItem(ui->FormAchievementsLineEditTitleCategoryChangeCategory->text()));
        for (int i=0;i<ui->FormAchievementsTableWidgetAchievements->rowCount();i++){
            QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->FormAchievementsTableWidgetAchievements->setItem(i,ui->FormAchievementsTableWidgetAchievements->columnCount()-1, pItem);
        }
        connect(ui->FormAchievementsLineEditTitleCategoryChangeCategory,SIGNAL(editingFinished()),this,SLOT(on_Change_Title_ChangeCategory_OneValue()));
        break;
        }
    }
}
void FormAchievements::on_Change_Title_ChangeCategory_OneValue(){
    ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(ui->FormAchievementsTableWidgetAchievements->columnCount()-1)->setText(ui->FormAchievementsLineEditTitleCategoryChangeCategory->text());
}

void FormAchievements::EditLineEditChangeCategoryValue(){
    QLineEdit *lied =qobject_cast<QLineEdit*>(sender());
    int i=lied->objectName().mid(23,lied->objectName().length()-23).toInt();
    ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(7+i)->setText(lied->text());
}
void FormAchievements::on_buttonChangeCategoryUpValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(24,btn->objectName().length()-24).toInt();
    if(i==0){
        QMessageBox::warning(this,"","Ашипка");
    } else {
        for (int j=0;j<ui->FormAchievementsTableWidgetAchievements->rowCount();j++) {
            Qt::CheckState pItem1 = ui->FormAchievementsTableWidgetAchievements->item(j,7+i)->checkState();
            Qt::CheckState pItem2 = ui->FormAchievementsTableWidgetAchievements->item(j,6+i)->checkState();
            ui->FormAchievementsTableWidgetAchievements->item(j,6+i)->setCheckState(pItem1);
            ui->FormAchievementsTableWidgetAchievements->item(j,7+i)->setCheckState(pItem2);
        }
        QString hh=ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(7+i)->text();
        ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(7+i)->setText(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(6+i)->text());
        ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(6+i)->setText(hh);
        QString text=findChild<QLineEdit*>("liedChangeCategoryValue"+QString::number(i))->text();
        findChild<QLineEdit*>("liedChangeCategoryValue"+QString::number(i))->setText(findChild<QLineEdit*>("liedChangeCategoryValue"+QString::number(i-1))->text());
        findChild<QLineEdit*>("liedChangeCategoryValue"+QString::number(i-1))->setText(text);
    }
}
void FormAchievements::on_buttonChangeCategoryDownValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(26,btn->objectName().length()-26).toInt();
    if(i==changecategoryvalueslayout->rowCount()){
        QMessageBox::warning(this,"","Ашипка");
    } else {
        for (int j=0;j<ui->FormAchievementsTableWidgetAchievements->rowCount();j++) {
            Qt::CheckState pItem1 = ui->FormAchievementsTableWidgetAchievements->item(j,7+i)->checkState();
            Qt::CheckState pItem2 = ui->FormAchievementsTableWidgetAchievements->item(j,8+i)->checkState();
            ui->FormAchievementsTableWidgetAchievements->item(j,8+i)->setCheckState(pItem1);
            ui->FormAchievementsTableWidgetAchievements->item(j,7+i)->setCheckState(pItem2);
        }
        QString hh=ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(7+i)->text();
        ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(7+i)->setText(ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(8+i)->text());
        ui->FormAchievementsTableWidgetAchievements->horizontalHeaderItem(8+i)->setText(hh);
        QString text=findChild<QLineEdit*>("liedChangeCategoryValue"+QString::number(i))->text();
        findChild<QLineEdit*>("liedChangeCategoryValue"+QString::number(i))->setText(findChild<QLineEdit*>("liedChangeCategoryValue"+QString::number(i+1))->text());
        findChild<QLineEdit*>("liedChangeCategoryValue"+QString::number(i+1))->setText(text);
    }
}
void FormAchievements::on_buttonChangeCategoryDeleteValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(28,btn->objectName().length()-28).toInt();
    ui->FormAchievementsTableWidgetAchievements->removeColumn(7+i);
    delete btn;
    //утечка данных (надо удалить еще 2 кнопки, лайнэдит, лейаут и виджет
    changecategoryvalueslayout->removeRow(i);
    i++;
    while(i<changecategoryvalueslayout->rowCount()+1){
        QPushButton * butn = findChild<QPushButton*>("btnChangeCategoryDeleteValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btnChangeCategoryDeleteValue"+QString::number(i-1));
        QLineEdit* lied = findChild<QLineEdit*>("liedChangeCategoryValue"+QString::number(i));
        if(lied)
            lied->setObjectName("liedChangeCategoryValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btnChangeCategoryUpValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btnChangeCategoryUpValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btnChangeCategoryDownValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btnChangeCategoryDownValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btnChangeCategorySelectValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btnChangeCategorySelectValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btnChangeCategoryUnSelectValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btnChangeCategoryUnSelectValue"+QString::number(i-1));
        i++;
    }
}
void FormAchievements::on_buttonChangeCategorySelectValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(28,btn->objectName().length()-28).toInt();
    ui->FormAchievementsTableWidgetAchievements->selectColumn(1);
    QList<QTableWidgetItem *> rows = ui->FormAchievementsTableWidgetAchievements->selectedItems();
    qDebug()<<rows.size();
    for (int i=0;i<rows.size();i++) {
        ui->FormAchievementsTableWidgetAchievements->item(rows.at(i)->row(),7+j)->setCheckState(Qt::Checked);
    }
    ui->FormAchievementsTableWidgetAchievements->selectColumn(0);
}
void FormAchievements::on_buttonChangeCategoryUnSelectValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(30,btn->objectName().length()-30).toInt();
    ui->FormAchievementsTableWidgetAchievements->selectColumn(1);
    QList<QTableWidgetItem *> rows = ui->FormAchievementsTableWidgetAchievements->selectedItems();
    qDebug()<<rows.size();
    for (int i=0;i<rows.size();i++) {
        ui->FormAchievementsTableWidgetAchievements->item(rows.at(i)->row(),7+j)->setCheckState(Qt::Unchecked);
    }
    ui->FormAchievementsTableWidgetAchievements->selectColumn(0);
}

void FormAchievements::on_FormAchievementsButtonCompare_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        compareform = new FormCompare(key,language,Theme,id,appid,*ui->FormAchievementsLabelGameLogo->pixmap(),JsonArrayGlobalAchievements,SaveImages);
        connect(compareform,SIGNAL(return_to_achievements(FormCompare*)),this,SLOT(on_return(FormCompare*)));
        compareform->show();
        this->setVisible(false);
    }
}
