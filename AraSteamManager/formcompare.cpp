#include "formcompare.h"
#include "ui_formcompare.h"

FormCompare::FormCompare(QString keys, int languages, int Themes, QString ids, QString appids, QPixmap GameLogo, QJsonArray JsonArrayGlobalAchievement,int SaveImage, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCompare){
    ui->setupUi(this);
    key=keys;
    language=languages;
    id=ids;
    appid=appids;
    SaveImages=SaveImage;
    Theme=Themes;
    ui->FormCompareLabelLogo->setPixmap(GameLogo);
    JsonArrayGlobalAchievements = JsonArrayGlobalAchievement;
    //{"name": "no_one_cared_who_i_was",
    //"percent": 85}
    ui->FormCompareTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QFile FileLanguage;
    switch(language){
    case 1:{
        FileLanguage.setFileName("Files/Languages/ENG/compare.txt");
        break;
        }
    case 5:{
        FileLanguage.setFileName("Files/Languages/RU/compare.txt");
        }
    }
    if(FileLanguage.open(QIODevice::ReadOnly)){
        while(!FileLanguage.atEnd()){
            SLLanguage << QString::fromLocal8Bit(FileLanguage.readLine()).remove("\r\n");
        }
    }
//    QIcon favorites;
//    switch(Theme){
//    case 1:{
//        ui->FormCompareGroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(images/program/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
//        ui->FormCompareButtonFind->setIcon(QIcon("images/program/find_white.png"));
//        ui->FormCompareButtonReturn->setIcon(QIcon("images/program/back_white.png"));
//        ui->FormCompareRadioButtonMyAll->setIcon(QIcon("images/program/all_white.png"));
//        ui->FormCompareRadioButtonMyReached->setIcon(QIcon("images/program/reached_white.png"));
//        ui->FormCompareRadioButtonMyNotReached->setIcon(QIcon("images/program/notreached_white.png"));
//        ui->FormCompareRadioButtonFriendsAll->setIcon(QIcon("images/program/all_white.png"));
//        ui->FormCompareRadioButtonFriendsReached->setIcon(QIcon("images/program/reached_white.png"));
//        ui->FormCompareRadioButtonFriendsNotReached->setIcon(QIcon("images/program/notreached_white.png"));
////        favorites.addFile("images/program/favorites_white.png");
//        break;
//        }
//    case 2:{
//        ui->FormCompareGroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(images/program/filter_black.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
//        ui->FormCompareButtonFind->setIcon(QIcon("images/program/find_black.png"));
//        ui->FormCompareButtonReturn->setIcon(QIcon("images/program/back_black.png"));
//        ui->FormCompareRadioButtonMyAll->setIcon(QIcon("images/program/all_black.png"));
//        ui->FormCompareRadioButtonMyReached->setIcon(QIcon("images/program/reached_black.png"));
//        ui->FormCompareRadioButtonMyNotReached->setIcon(QIcon("images/program/notreached_black.png"));
//        ui->FormCompareRadioButtonFriendsAll->setIcon(QIcon("images/program/all_black.png"));
//        ui->FormCompareRadioButtonFriendsReached->setIcon(QIcon("images/program/reached_black.png"));
//        ui->FormCompareRadioButtonFriendsNotReached->setIcon(QIcon("images/program/notreached_black.png"));
////        favorites.addFile("images/program/favorites_black.png");
//        break;
//        }
//    }
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
    ui->FormCompareButtonReturn->setText(" "+SLLanguage[0]);
    //ui->FormCompareGroupBoxMyA->setTitle(SLLanguage[1]);
    //ui->FormCompareGroupBoxFriendsA->setTitle(SLLanguage[2]);
    //ui->FormCompareRadioButtonMyAll->setText(SLLanguage[3]);
    //ui->FormCompareRadioButtonMyReached->setText(SLLanguage[4]);
    //ui->FormCompareRadioButtonMyNotReached->setText(SLLanguage[5]);
    //ui->FormCompareRadioButtonFriendsAll->setText(SLLanguage[3]);
    //ui->FormCompareRadioButtonFriendsReached->setText(SLLanguage[4]);
    //ui->FormCompareRadioButtonFriendsNotReached->setText(SLLanguage[5]);
    ui->FormCompareCheckBoxFavorites->setText(SLLanguage[6]);
    ui->FormCompareCheckBoxAllFriends->setText(SLLanguage[7]);
    ui->FormCompareButtonFind->setText(" "+SLLanguage[8]);
    ui->FormCompareGroupBoxFilter->setTitle("      "+SLLanguage[9]);
    ui->FormCompareGroupBoxShowedColumns->setTitle(SLLanguage[10]);
    ui->FormCompareCheckBoxSCIcons->setText(SLLanguage[11]);
    ui->FormCompareCheckBoxSCTitle->setText(SLLanguage[12]);
    ui->FormCompareCheckBoxSCDescription->setText(SLLanguage[13]);
    ui->FormCompareCheckBoxSCTotalPercent->setText(SLLanguage[14]);
    ui->FormCompareLabelPlayerCount->setText(SLLanguage[18]+": "+QString::number(JsonDocNumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble()));
    ui->FormCompareButtonUpdate->setText(SLLanguage[19]);
    ui->FormCompareTableWidget->setColumnCount(6);
    ui->FormCompareTableWidget->insertRow(0);
    ui->FormCompareTableWidget->insertRow(1);
    ui->FormCompareTableWidget->setVerticalHeaderItem(0,new QTableWidgetItem(""));
    ui->FormCompareTableWidget->setVerticalHeaderItem(1,new QTableWidgetItem("%"));
    ui->FormCompareTableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->FormCompareTableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem(SLLanguage[12]));
    ui->FormCompareTableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem(SLLanguage[13]));
    ui->FormCompareTableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem(SLLanguage[14]));
    QNetworkReply &ReplyPlayerSummaries = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+ids));
    loop.exec();
    QJsonDocument DocPlayerSummaries = QJsonDocument::fromJson(ReplyPlayerSummaries.readAll());
    ui->FormCompareTableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("personaname").toString()/*SLLanguage[15]*/));
    ui->FormCompareTableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem(/**/));
    QNetworkReply &imagereply = *manager.get(QNetworkRequest(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("avatar").toString()));
    loop.exec();
    QPixmap pix;
    pix.loadFromData(imagereply.readAll());
    QLabel* myava = new QLabel;
    myava->setPixmap(pix);
    ui->FormCompareTableWidget->setCellWidget(0,4,myava);
    QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l=russian"+SLLanguage[17])));
    loop.exec();
    JsonArraySchemaForGame = QJsonDocument::fromJson(replySchemaForGame.readAll()).object().value("game").toObject().value("availableGameStats").toObject().value("achievements").toArray();
    int totalr=0;
    int totalnr=0;
    if(!QDir("images/achievements/"+appid).exists()){
        QDir().mkdir("images/achievements/"+appid);
    }
    QJsonArray JAPA = JsonArrayPlayerAchievements;
    QJsonArray JASFG = JsonArraySchemaForGame;
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
                int row = ui->FormCompareTableWidget->rowCount();
                ui->FormCompareTableWidget->insertRow(row);
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
                    ui->FormCompareTableWidget->setCellWidget(row,0,label);
                    }
                QTableWidgetItem *item2 = new QTableWidgetItem(JASFG[j].toObject().value("displayName").toString());
                ui->FormCompareTableWidget->setItem(row,1,item2);
                QTableWidgetItem *item3 = new QTableWidgetItem(JASFG[j].toObject().value("description").toString());
                ui->FormCompareTableWidget->setItem(row,2,item3);
                QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(JsonArrayGlobalAchievements[i].toObject().value("percent").toDouble())+"%");
                ui->FormCompareTableWidget->setItem(row,3,item4);
                QTableWidgetItem *item5;
                if(JAPA[j].toObject().value("achieved").toInt()==1){
                    QDateTime date=QDateTime::fromSecsSinceEpoch(JAPA[j].toObject().value("unlocktime").toInt(),Qt::LocalTime);
                    item5 = new QTableWidgetItem(SLLanguage[15]+" "+date.toString("yyyy.MM.dd hh:mm"));
                    totalr++;
                    } else {
                    item5 = new QTableWidgetItem(SLLanguage[16]);
                    totalnr++;
                    }
                ui->FormCompareTableWidget->setItem(row,4,item5);
                QTableWidgetItem *item6 = new QTableWidgetItem(JAPA[j].toObject().value("apiname").toString());
                ui->FormCompareTableWidget->setItem(row,5,item6);
                JAPA.removeAt(j);
                JASFG.removeAt(j);
                ui->FormCompareTableWidget->setVerticalHeaderItem(row,new QTableWidgetItem(QString::number(row-1)));
            }
        }
    double percent= 100.0*totalr/(totalr+totalnr);
    ui->FormCompareTableWidget->setCellWidget(1,4, new QLabel(" "+QString::number(totalr)+"/"+QString::number(totalr+totalnr)+"\n "+QString::number(percent)+"%"));
    ui->FormCompareTableWidget->setColumnWidth(0,65);
    ui->FormCompareTableWidget->setColumnWidth(1,100);
    ui->FormCompareTableWidget->setColumnWidth(2,315);
    ui->FormCompareTableWidget->resizeColumnToContents(3);
    ui->FormCompareTableWidget->setColumnWidth(4,80);
    ui->FormCompareTableWidget->setColumnHidden(5,true);
    ui->FormCompareTableWidget->resizeRowsToContents();

    QDir categories("Files/Categories/"+appid);
    categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categories.setSorting(QDir::Name);
    QFileInfoList list = categories.entryInfoList();
    if(categories.exists()){
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
                cb->addItem(SLLanguage[20]);
                for (int j=0;j<cat.object().value("values").toArray().size();j++) {
                    cb->addItem(cat.object().value("values").toArray().at(j).toString());
                }
                cb->setObjectName("Category"+QString::number(i));
                connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(on_ComboBoxCategory_Change(int)));
                layout1->addRow(new QLabel(cat.object().value("name").toString()),cb);
            }
            category.close();
            }
        widget1->setLayout(layout1);
        widget2->setLayout(layout2);
        ui->FormCompareScrollAreaCategoriesComboBox->setWidget(widget1);
        ui->FormCompareScrollAreaCategoriesCheckBox->setWidget(widget2);

        if(layout1->rowCount()==0){
            ui->FormCompareScrollAreaCategoriesComboBox->hide();
        } else {
            ui->FormCompareScrollAreaCategoriesComboBox->show();
        }
        if(layout2->rowCount()==0){
            ui->FormCompareScrollAreaCategoriesCheckBox->hide();
        } else {
            ui->FormCompareScrollAreaCategoriesCheckBox->show();
        }
    }
    bool **New = new bool*[ui->FormCompareTableWidget->rowCount()];
    for (int i=0;i<ui->FormCompareTableWidget->rowCount();i++) {
        New[i]=new bool[list.size()+3];
        for (int j=0;j<list.size()+3;j++) {
            New[i][j]=true;
            }
        }
    colfilter=list.size()+3;
    filter = new bool*[ui->FormCompareTableWidget->rowCount()];
    filter = New;

    QNetworkReply &ReplyFriendList = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetFriendList/v0001/?key="+key+"&steamid="+id+"&relationship=friend"));
    loop.exec();
    QJsonDocument DocFriendList = QJsonDocument::fromJson(ReplyFriendList.readAll());
    QString Querry="http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+DocFriendList.object().value("friendslist").toObject().value("friends").toArray().at(0).toObject().value("steamid").toString();
    for (int i=1;i<DocFriendList.object().value("friendslist").toObject().value("friends").toArray().size();i++) {
        Querry+=","+DocFriendList.object().value("friendslist").toObject().value("friends").toArray().at(i).toObject().value("steamid").toString();
    }
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &ReplyPlayersSummaries = *manager.get(QNetworkRequest(Querry));
    loop.exec();
    QJsonArray Accounts = QJsonDocument::fromJson(ReplyPlayersSummaries.readAll()).object().value("response").toObject().value("players").toArray();
    QVector<QJsonObject> abc;
    for (int i=0;i<Accounts.size();i++) {
        abc.append(Accounts[i].toObject());
    }
    for (int i=0; i < abc.size()-1; i++) {
        for (int j=0; j < abc.size()-i-1; j++) {
            if (abc[j].value("personaname").toString() > abc[j+1].value("personaname").toString()) {
                QJsonObject temp = abc[j];
                abc[j] = abc[j+1];
                abc[j+1] = temp;
            }
        }
    }
    for (int i=0;i<abc.size();i++) {
        Profile a(abc[i]);
        QNetworkReply &ReplyOwnedGames = *manager.get(QNetworkRequest("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key="+key+"&include_played_free_games=1&include_appinfo=1&format=json&steamid="+a.GetSteamid()));
        loop.exec();
        QJsonDocument DocOwnedGames = QJsonDocument::fromJson(ReplyOwnedGames.readAll());
        QJsonArray Games = DocOwnedGames.object().value("response").toObject().value("games").toArray();
        bool apply=false;
        for (int i=0;i<Games.size();i++) {
            if(Games[i].toObject().value("appid").toInt()==appid.toInt()){
                apply=true;
                break;
            }
        }
        if(apply)
            Friends.first.push_back(a);
        else
            Friends.second.push_back(a);
    }

    ui->FormCompareTableWidgetFriends->setRowCount(4);
    ui->FormCompareTableWidgetFriends->setColumnCount(Friends.first.size()+2);

    QLabel* Me = new QLabel;
    Me->setPixmap(pix);
    ui->FormCompareTableWidgetFriends->setCellWidget(0,0,Me);
    QRadioButton *rbMyAll = new QRadioButton(/*SLLanguage[]*/);
    QRadioButton *rbMyReached = new QRadioButton(/*SLLanguage[]*/);
    QRadioButton *rbMyNotReached = new QRadioButton(/*SLLanguage[]*/);
    rbMyAll->setObjectName("RBMyAll");
    rbMyReached->setObjectName("RBMyReached");
    rbMyNotReached->setObjectName("RBMyNotReached");
    connect(rbMyAll,SIGNAL(clicked()),this,SLOT(on_FormCompareRadioButtonMyAll_clicked()));
    connect(rbMyReached,SIGNAL(clicked()),this,SLOT(on_FormCompareRadioButtonMyReached_clicked()));
    connect(rbMyNotReached,SIGNAL(clicked()),this,SLOT(on_FormCompareRadioButtonMyNotReached_clicked()));
    rbMyAll->setChecked(true);
    QWidget* wd1 = new QWidget;
    QVBoxLayout* lay1 = new QVBoxLayout;
    wd1->setObjectName("WDMy");
    lay1->setObjectName("LayMy");
    lay1->addWidget(rbMyAll);
    lay1->addWidget(rbMyReached);
    lay1->addWidget(rbMyNotReached);
    lay1->setMargin(1);
    wd1->setLayout(lay1);
    QLabel* All = new QLabel("All");
    //Me->setPixmap(pix);
    ui->FormCompareTableWidgetFriends->setCellWidget(0,1,All);
    QRadioButton *rbFriendsAll = new QRadioButton(/*SLLanguage[]*/);
    QRadioButton *rbFriendsReached = new QRadioButton(/*SLLanguage[]*/);
    QRadioButton *rbFriendsNotReached = new QRadioButton(/*SLLanguage[]*/);
    rbFriendsAll->setObjectName("RBFriendsAll");
    rbFriendsReached->setObjectName("RBFriendsReached");
    rbFriendsNotReached->setObjectName("RBFriendsNotReached");
    connect(rbFriendsAll,SIGNAL(clicked()),this,SLOT(on_FormCompareRadioButtonFriendsAll_clicked()));
    connect(rbFriendsReached,SIGNAL(clicked()),this,SLOT(on_FormCompareRadioButtonFriendsReached_clicked()));
    connect(rbFriendsNotReached,SIGNAL(clicked()),this,SLOT(on_FormCompareRadioButtonFriendsNotReached_clicked()));
    rbFriendsAll->setChecked(true);
    QWidget* wd2 = new QWidget;
    QVBoxLayout* lay2 = new QVBoxLayout;
    wd2->setObjectName("WDFriends");
    lay2->setObjectName("LayFriends");
    lay2->addWidget(rbFriendsAll);
    lay2->addWidget(rbFriendsReached);
    lay2->addWidget(rbFriendsNotReached);
    lay2->setMargin(1);
    wd2->setLayout(lay2);
    switch (Theme) {
    case 1:{
        ui->FormCompareGroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(images/program/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
        ui->FormCompareButtonFind->setIcon(QIcon("images/program/find_white.png"));
        ui->FormCompareButtonReturn->setIcon(QIcon("images/program/back_white.png"));
        rbMyAll->setIcon(QIcon("images/program/all_white.png"));
        rbMyReached->setIcon(QIcon("images/program/reached_white.png"));
        rbMyNotReached->setIcon(QIcon("images/program/notreached_white.png"));
        rbFriendsAll->setIcon(QIcon("images/program/all_white.png"));
        rbFriendsReached->setIcon(QIcon("images/program/reached_white.png"));
        rbFriendsNotReached->setIcon(QIcon("images/program/notreached_white.png"));
        break;
        }
    case 2:{
        ui->FormCompareGroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(images/program/filter_black.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
        ui->FormCompareButtonFind->setIcon(QIcon("images/program/find_black.png"));
        ui->FormCompareButtonReturn->setIcon(QIcon("images/program/back_black.png"));
        rbMyAll->setIcon(QIcon("images/program/all_black.png"));
        rbMyReached->setIcon(QIcon("images/program/reached_black.png"));
        rbMyNotReached->setIcon(QIcon("images/program/notreached_black.png"));
        rbFriendsAll->setIcon(QIcon("images/program/all_black.png"));
        rbFriendsReached->setIcon(QIcon("images/program/reached_black.png"));
        rbFriendsNotReached->setIcon(QIcon("images/program/notreached_black.png"));
        break;
    }
    }
    ui->FormCompareTableWidgetFriends->setCellWidget(3,0,wd1);
    ui->FormCompareTableWidgetFriends->setCellWidget(3,1,wd2);
    ui->FormCompareTableWidgetFriends->resizeRowsToContents();

    for (int i=0;i<Friends.first.size();i++) {
        QLabel *ava = new QLabel;
        ava->setPixmap(Friends.first[i].GetAvatar());
        ui->FormCompareTableWidgetFriends->setCellWidget(0,i+2,ava);
        QTableWidgetItem* pItem(new QTableWidgetItem(tr("")));
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        pItem->setCheckState(Qt::Unchecked);
        ui->FormCompareTableWidgetFriends->setItem(1,i+2,pItem);
        QTableWidgetItem *item2 = new QTableWidgetItem(Friends.first[i].GetSteamid());
        ui->FormCompareTableWidgetFriends->setItem(2,i+2,item2);
    }
    connect(ui->FormCompareTableWidgetFriends,SIGNAL(cellChanged(int,int)),this,SLOT(on_CheckBoxFriend_Click(int,int)));
    ui->FormCompareTableWidgetFriends->setRowHidden(2,true);
    ui->FormCompareTableWidgetFriends->resizeColumnsToContents();

    ui->FormCompareLineEditFind->setFocus();
}

void FormCompare::OnResultImage(int i, QString Save, ImageRequest *imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    if(!Save.isEmpty()){
        pixmap.save("images/achievements/"+appid+"/"+Save.mid(Save.indexOf("/",1)+1,Save.length()-1).remove(".jpg")+".png", "PNG");
    }
    ui->FormCompareTableWidget->setCellWidget(i,0,label);
    ui->FormCompareTableWidget->resizeRowToContents(i);
    imgr->deleteLater();
}

void FormCompare::UpdateHiddenRows(){
    for (int i=2;i<ui->FormCompareTableWidget->rowCount();i++) {
        bool accept=true;
        for (int j=0;j<colfilter;j++) {
            if(filter[i][j]==false){
                accept=false;
                break;
                }
            }
        if(accept){
            ui->FormCompareTableWidget->setRowHidden(i,false);
            } else
            ui->FormCompareTableWidget->setRowHidden(i,true);
        }
}

FormCompare::~FormCompare()
{
    delete ui;
}

void FormCompare::on_FormCompareRadioButtonMyAll_clicked()
{
    for (int i=2;i<ui->FormCompareTableWidget->rowCount();i++){
        filter[i][1]=true;}
    UpdateHiddenRows();
}
void FormCompare::on_FormCompareRadioButtonMyReached_clicked()
{
    for (int i=2;i<ui->FormCompareTableWidget->rowCount();i++)
        if(ui->FormCompareTableWidget->item(i,4)->text().indexOf(".")>-1){
            filter[i][1]=true;} else{
            filter[i][1]=false;}
    UpdateHiddenRows();
}
void FormCompare::on_FormCompareRadioButtonMyNotReached_clicked()
{
    for (int i=2;i<ui->FormCompareTableWidget->rowCount();i++)
        if(ui->FormCompareTableWidget->item(i,4)->text().indexOf(".")>-1){
            filter[i][1]=false;} else{
            filter[i][1]=true;}
    UpdateHiddenRows();
}

void FormCompare::on_ComboBoxCategory_Change(int index){
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
            for (int i=2;i<ui->FormCompareTableWidget->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->FormCompareTableWidget->item(i,5)->text()==selecteditem[j].toString()){
                        filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        break;
                        };
                    }
            } else {
            for (int i=2;i<ui->FormCompareTableWidget->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()]=true;
                }
            }
        category.close();
        UpdateHiddenRows();
    }
}
void FormCompare::on_CheckBoxCategory_Change(int ind){
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
            for (int i=2;i<ui->FormCompareTableWidget->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->FormCompareTableWidget->item(i,5)->text()==selecteditem[j].toString()){
                        filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        break;
                        };
                    }
            } else {
            for (int i=2;i<ui->FormCompareTableWidget->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()]=true;
                }
            }
        category.close();
        UpdateHiddenRows();
    }
}

void FormCompare::on_FormCompareCheckBoxSCIcons_stateChanged(int arg1){
    switch(arg1){
    case 0:{
        ui->FormCompareTableWidget->setColumnHidden(0,true);
        break;
    }
    case 2:{
        ui->FormCompareTableWidget->setColumnHidden(0,false);
        break;
    }
    }
}
void FormCompare::on_FormCompareCheckBoxSCTitle_stateChanged(int arg1){
    switch(arg1){
    case 0:{
        ui->FormCompareTableWidget->setColumnHidden(1,true);
        break;
    }
    case 2:{
        ui->FormCompareTableWidget->setColumnHidden(1,false);
        break;
    }
    }
}
void FormCompare::on_FormCompareCheckBoxSCDescription_stateChanged(int arg1){
    switch(arg1){
    case 0:{
        ui->FormCompareTableWidget->setColumnHidden(2,true);
        break;
    }
    case 2:{
        ui->FormCompareTableWidget->setColumnHidden(2,false);
        break;
    }
    }
}
void FormCompare::on_FormCompareCheckBoxSCTotalPercent_stateChanged(int arg1){
    switch(arg1){
    case 0:{
        ui->FormCompareTableWidget->setColumnHidden(3,true);
        break;
    }
    case 2:{
        ui->FormCompareTableWidget->setColumnHidden(3,false);
        break;
    }
    }
}

void FormCompare::on_CheckBoxFriend_Click(int row, int column){
    if((row==1)&&(column>1)){
        Profile sProfile;
        int col=ui->FormCompareTableWidget->columnCount();
        if(ui->FormCompareCheckBoxAllFriends->isChecked()){
            bool accept=true;
            for (int i=0;i<Friends.first.size();i++) {
                if(Friends.first[i].GetSteamid()==ui->FormCompareTableWidgetFriends->item(2,column)->text()){
                    accept=false;
                    sProfile=Friends.first[i];
                    break;
                }
            }
            if(accept){
                for (int i=0;i<Friends.second.size();i++) {
                    if(Friends.second[i].GetSteamid()==ui->FormCompareTableWidgetFriends->item(2,column)->text()){
                        sProfile=Friends.second[i];
                        break;
                    }
                }
            }
        } else {
            for (int i=0;i<Friends.first.size();i++) {
                if(Friends.first[i].GetSteamid()==ui->FormCompareTableWidgetFriends->item(2,column)->text()){
                    sProfile=Friends.first[i];
                    break;
                }
            }
        }
        if(ui->FormCompareTableWidgetFriends->item(row,column)->checkState()==Qt::Checked){
            ui->FormCompareTableWidget->insertColumn(col);
            ui->FormCompareTableWidget->setHorizontalHeaderItem(col,new QTableWidgetItem(sProfile.GetName()));
            QLabel* ava = new QLabel;
            ava->setPixmap(sProfile.GetAvatar());
            ui->FormCompareTableWidget->setCellWidget(0,col,ava);
            QNetworkAccessManager manager;
            QEventLoop loop;
            QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
            QNetworkReply &replyPlayerAchievements = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+sProfile.GetSteamid())));
            loop.exec();
            QJsonArray JAPA = QJsonDocument::fromJson(replyPlayerAchievements.readAll()).object().value("playerstats").toObject().value("achievements").toArray();
            int totalr=0;
            int totalnr=0;
            for(int i=2;i<ui->FormCompareTableWidget->rowCount();i++){
                qDebug()<<i;
                int j=0;
                bool accept=false;
                for(;j<JAPA.size();j++){
                    if(JAPA[j].toObject().value("apiname").toString()==ui->FormCompareTableWidget->item(i,5)->text()){
                        accept=true;
                        break;
                        }
                }
                if(accept){
                    QTableWidgetItem *item5;
                    if(JAPA[j].toObject().value("achieved").toInt()==1){
                        QDateTime date=QDateTime::fromSecsSinceEpoch(JAPA[j].toObject().value("unlocktime").toInt(),Qt::LocalTime);
                        item5 = new QTableWidgetItem(SLLanguage[15]+" "+date.toString("yyyy.MM.dd hh:mm"));
                        totalr++;
                        } else {
                        item5 = new QTableWidgetItem(SLLanguage[16]);
                        totalnr++;
                        }
                    ui->FormCompareTableWidget->setItem(i,col,item5);
                    //JAPA.removeAt(j);
                }
                }
            double percent= 100.0*totalr/(totalr+totalnr);
            if((totalr==0)&&(totalnr==0))
                ui->FormCompareTableWidget->setCellWidget(1,col, new QLabel("profile is \nnot public"));
            else {
                ui->FormCompareTableWidget->setCellWidget(1,col, new QLabel(" "+QString::number(totalr)+"/"+QString::number(totalr+totalnr)+"\n "+QString::number(percent)+"%"));
                QRadioButton *rbAll = new QRadioButton(/*SLLanguage[]*/);
                QRadioButton *rbReached = new QRadioButton(/*SLLanguage[]*/);
                QRadioButton *rbNotReached = new QRadioButton(/*SLLanguage[]*/);
                rbAll->setObjectName("RB"+QString::number(column)+"All");
                rbReached->setObjectName("RB"+QString::number(column)+"Reached");
                rbNotReached->setObjectName("RB"+QString::number(column)+"NotReached");
                connect(rbAll,SIGNAL(clicked),this,SLOT(on_RadioButtonFriendAll_Click));
                connect(rbReached,SIGNAL(clicked),this,SLOT(on_RadioButtonFriendReached_Click));
                connect(rbNotReached,SIGNAL(clicked),this,SLOT(on_RadioButtonFriendNotReached_Click));
                rbAll->setChecked(true);
                QWidget* wd = new QWidget;
                QVBoxLayout* lay = new QVBoxLayout;
                wd->setObjectName("WD"+QString::number(column));
                lay->setObjectName("Lay"+QString::number(column));
                lay->addWidget(rbAll);
                lay->addWidget(rbReached);
                lay->addWidget(rbNotReached);
                lay->setMargin(1);
                wd->setLayout(lay);
                switch (Theme) {
                case 1:{
                    rbAll->setIcon(QIcon("images/program/all_white.png"));
                    rbReached->setIcon(QIcon("images/program/reached_white.png"));
                    rbNotReached->setIcon(QIcon("images/program/notreached_white.png"));
                    break;
                    }
                case 2:{
                    rbAll->setIcon(QIcon("images/program/all_black.png"));
                    rbReached->setIcon(QIcon("images/program/reached_black.png"));
                    rbNotReached->setIcon(QIcon("images/program/notreached_black.png"));
                    break;
                }
                }
                ui->FormCompareTableWidgetFriends->setCellWidget(3,column,wd);
                ui->FormCompareTableWidgetFriends->resizeRowsToContents();
                ui->FormCompareTableWidgetFriends->resizeColumnsToContents();
            }
            ui->FormCompareTableWidget->setColumnWidth(col,80);

        } else {
            for (int i=5;i<ui->FormCompareTableWidget->columnCount();i++) {
                if(ui->FormCompareTableWidget->horizontalHeaderItem(i)->text()==sProfile.GetName()){
                    ui->FormCompareTableWidget->removeColumn(i);
                    break;
                }
            }
            if(findChild<QRadioButton*>("RB"+QString::number(column)+"All")){
                disconnect(findChild<QRadioButton*>("RB"+QString::number(column)+"All"),SIGNAL(clicked),this,SLOT(on_RadioButtonFriendAll_Click));
                disconnect(findChild<QRadioButton*>("RB"+QString::number(column)+"Reached"),SIGNAL(clicked),this,SLOT(on_RadioButtonFriendReached_Click));
                disconnect(findChild<QRadioButton*>("RB"+QString::number(column)+"NotReached"),SIGNAL(clicked),this,SLOT(on_RadioButtonFriendNotReached_Click));
                delete findChild<QRadioButton*>("RB"+QString::number(column)+"All");
                delete findChild<QRadioButton*>("RB"+QString::number(column)+"Reached");
                delete findChild<QRadioButton*>("RB"+QString::number(column)+"NotReached");
                delete findChild<QVBoxLayout*>("Lay"+QString::number(column));
                ui->FormCompareTableWidgetFriends->removeCellWidget(3,column);
                delete findChild<QWidget*>("WD"+QString::number(row)+"&"+QString::number(column));
                ui->FormCompareTableWidgetFriends->resizeRowsToContents();
                ui->FormCompareTableWidgetFriends->resizeColumnsToContents();
            }
        }
    }
}

void FormCompare::on_RadioButtonFriendAll_Click(){

}

void FormCompare::on_RadioButtonFriendReached_Click(){

}

void FormCompare::on_RadioButtonFriendNotReached_Click(){

}

void FormCompare::on_FormCompareButtonReturn_clicked(){
    emit return_to_achievements();
    delete this;
}

void FormCompare::closeEvent(QCloseEvent *){
    on_FormCompareButtonReturn_clicked();
}

void FormCompare::on_FormComparCheckBoxShowFilter_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        ui->FormCompareGroupBoxFilter->setHidden(true);
        break;
    }
    case 2:{
        ui->FormCompareGroupBoxFilter->setHidden(false);
        break;
    }
    }
}

