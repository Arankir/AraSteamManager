#include "formcompare.h"
#include "ui_formcompare.h"

FormCompare::FormCompare(QString keys, QString ids, QString appids, QPixmap GameLogo, QJsonArray JsonArrayGlobalAchievement, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCompare){
    ui->setupUi(this);
    Words=Setting.GetWords("compare");
    key=keys;
    id=ids;
    appid=appids;
    ui->CheckBoxFavorites->setText(Words[6]);
    ui->CheckBoxAllFriends->setText(Words[7]);
    ui->ButtonFind->setText(" "+Words[8]);
    ui->GroupBoxFilter->setTitle("      "+Words[9]);
    ui->GroupBoxShowedColumns->setTitle(Words[10]);
    ui->CheckBoxSCIcons->setText(Words[11]);
    ui->CheckBoxSCTitle->setText(Words[12]);
    ui->CheckBoxSCDescription->setText(Words[13]);
    ui->CheckBoxSCTotalPercent->setText(Words[14]);
    ui->LabelPlayerCount->setText(Words[18]+": "+QString::number(JsonDocNumberOfCurrentPlayers.object().value("response").toObject().value("player_count").toDouble()));
    ui->ButtonUpdate->setText(Words[19]);
    ui->CheckBoxShowFilter->setText(Words[24]);
    ui->TableWidget->setColumnCount(6);
    ui->TableWidget->insertRow(0);
    ui->TableWidget->insertRow(1);
    ui->TableWidget->setVerticalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidget->setVerticalHeaderItem(1,new QTableWidgetItem("%"));
    ui->TableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem(Words[12]));
    ui->TableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[13]));
    ui->TableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[14]));
    ui->LabelLogo->setPixmap(GameLogo);
    JsonArrayGlobalAchievements = JsonArrayGlobalAchievement;
    //{"name": "no_one_cared_who_i_was",
    //"percent": 85}
    ui->TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    QIcon favorites;
//    switch(Theme){
//    case 1:{
//        ui->GroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(images/program/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
//        ui->ButtonFind->setIcon(QIcon("images/program/find_white.png"));
//        ui->ButtonReturn->setIcon(QIcon("images/program/back_white.png"));
//        ui->RadioButtonMyAll->setIcon(QIcon("images/program/all_white.png"));
//        ui->RadioButtonMyReached->setIcon(QIcon("images/program/reached_white.png"));
//        ui->RadioButtonMyNotReached->setIcon(QIcon("images/program/notreached_white.png"));
//        ui->RadioButtonFriendsAll->setIcon(QIcon("images/program/all_white.png"));
//        ui->RadioButtonFriendsReached->setIcon(QIcon("images/program/reached_white.png"));
//        ui->RadioButtonFriendsNotReached->setIcon(QIcon("images/program/notreached_white.png"));
////        favorites.addFile("images/program/favorites_white.png");
//        break;
//        }
//    case 2:{
//        ui->GroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(images/program/filter_black.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
//        ui->ButtonFind->setIcon(QIcon("images/program/find_black.png"));
//        ui->ButtonReturn->setIcon(QIcon("images/program/back_black.png"));
//        ui->RadioButtonMyAll->setIcon(QIcon("images/program/all_black.png"));
//        ui->RadioButtonMyReached->setIcon(QIcon("images/program/reached_black.png"));
//        ui->RadioButtonMyNotReached->setIcon(QIcon("images/program/notreached_black.png"));
//        ui->RadioButtonFriendsAll->setIcon(QIcon("images/program/all_black.png"));
//        ui->RadioButtonFriendsReached->setIcon(QIcon("images/program/reached_black.png"));
//        ui->RadioButtonFriendsNotReached->setIcon(QIcon("images/program/notreached_black.png"));
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
    ui->ButtonReturn->setText(" "+Words[0]);
    //ui->GroupBoxMyA->setTitle(Words[1]);
    //ui->GroupBoxFriendsA->setTitle(Words[2]);
    //ui->RadioButtonMyAll->setText(Words[3]);
    //ui->RadioButtonMyReached->setText(Words[4]);
    //ui->RadioButtonMyNotReached->setText(Words[5]);
    //ui->RadioButtonFriendsAll->setText(Words[3]);
    //ui->RadioButtonFriendsReached->setText(Words[4]);
    //ui->RadioButtonFriendsNotReached->setText(Words[5]);
    QNetworkReply &ReplyPlayerSummaries = *manager.get(QNetworkRequest("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+ids));
    loop.exec();
    QJsonDocument DocPlayerSummaries = QJsonDocument::fromJson(ReplyPlayerSummaries.readAll());
    ui->TableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("personaname").toString()/*Words[15]*/));
    ui->TableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem(/**/));
    QNetworkReply &imagereply = *manager.get(QNetworkRequest(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("avatar").toString()));
    loop.exec();
    QPixmap pix;
    pix.loadFromData(imagereply.readAll());
    QLabel* myava = new QLabel;
    myava->setPixmap(pix);
    myava->setAlignment(Qt::AlignCenter);
    ui->TableWidget->setCellWidget(0,4,myava);
    QNetworkReply &replySchemaForGame = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/v2/?key="+key+"&appid="+appid+"&l="+Words[17])));
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
                int row = ui->TableWidget->rowCount();
                ui->TableWidget->insertRow(row);
                QString AchievementIcon=JASFG[j].toObject().value("icon").toString().mid(66,JASFG[j].toObject().value("icon").toString().length());
                if(!QFile::exists("images/achievements/"+appid+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png")){
                    ImageRequest *image;
                    switch (Setting.GetSaveimages()) {
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
                    ui->TableWidget->setCellWidget(row,0,label);
                    }
                QTableWidgetItem *item2 = new QTableWidgetItem(JASFG[j].toObject().value("displayName").toString());
                item2->setTextAlignment(Qt::AlignCenter);
                ui->TableWidget->setItem(row,1,item2);
                QTableWidgetItem *item3 = new QTableWidgetItem(JASFG[j].toObject().value("description").toString());
                item3->setTextAlignment(Qt::AlignCenter);
                ui->TableWidget->setItem(row,2,item3);
                QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(JsonArrayGlobalAchievements[i].toObject().value("percent").toDouble())+"%");
                item4->setTextAlignment(Qt::AlignCenter);
                ui->TableWidget->setItem(row,3,item4);
                QTableWidgetItem *item5;
                if(JAPA[j].toObject().value("achieved").toInt()==1){
                    QDateTime date=QDateTime::fromSecsSinceEpoch(JAPA[j].toObject().value("unlocktime").toInt(),Qt::LocalTime);
                    item5 = new QTableWidgetItem(Words[15]+" "+date.toString("yyyy.MM.dd hh:mm"));
                    totalr++;
                    } else {
                    item5 = new QTableWidgetItem(Words[16]);
                    totalnr++;
                    }
                item5->setTextAlignment(Qt::AlignCenter);
                ui->TableWidget->setItem(row,4,item5);
                QTableWidgetItem *item6 = new QTableWidgetItem(JAPA[j].toObject().value("apiname").toString());
                ui->TableWidget->setItem(row,5,item6);
                JAPA.removeAt(j);
                JASFG.removeAt(j);
                ui->TableWidget->setVerticalHeaderItem(row,new QTableWidgetItem(QString::number(row-1)));
            }
        }
    double percent= 100.0*totalr/(totalr+totalnr);
    ui->TableWidget->setCellWidget(1,4, new QLabel(" "+QString::number(totalr)+"/"+QString::number(totalr+totalnr)+"\n "+QString::number(percent)+"%"));
    ui->TableWidget->setColumnWidth(0,65);
    ui->TableWidget->setColumnWidth(1,100);
    ui->TableWidget->setColumnWidth(2,315);
    ui->TableWidget->resizeColumnToContents(3);
    ui->TableWidget->setColumnWidth(4,80);
    ui->TableWidget->setColumnHidden(5,true);
    ui->TableWidget->resizeRowsToContents();

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
                cb->addItem(Words[20]);
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
        ui->ScrollAreaCategoriesComboBox->setWidget(widget1);
        ui->ScrollAreaCategoriesCheckBox->setWidget(widget2);

        if(layout1->rowCount()==0){
            ui->ScrollAreaCategoriesComboBox->hide();
        } else {
            ui->ScrollAreaCategoriesComboBox->show();
        }
        if(layout2->rowCount()==0){
            ui->ScrollAreaCategoriesCheckBox->hide();
        } else {
            ui->ScrollAreaCategoriesCheckBox->show();
        }
    }
    bool **New = new bool*[ui->TableWidget->rowCount()];
    for (int i=0;i<ui->TableWidget->rowCount();i++) {
        New[i]=new bool[list.size()+3];
        for (int j=0;j<list.size()+3;j++) {
            New[i][j]=true;
            }
        }
    colfilter=list.size()+3;
    filter = new bool*[ui->TableWidget->rowCount()];
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

    ui->TableWidgetFriends->setRowCount(4);
    ui->TableWidgetFriends->setColumnCount(Friends.first.size()+Friends.second.size()+2);

    QLabel* Me = new QLabel;
    Me->setPixmap(pix);
    Me->setAlignment(Qt::AlignCenter);
    Me->setToolTip(DocPlayerSummaries.object().value("response").toObject().value("players").toArray().at(0).toObject().value("personaname").toString());
    ui->TableWidgetFriends->setCellWidget(0,0,Me);
    QRadioButton *rbMyAll = new QRadioButton(/*Words[]*/);
    QRadioButton *rbMyReached = new QRadioButton(/*Words[]*/);
    QRadioButton *rbMyNotReached = new QRadioButton(/*Words[]*/);
    rbMyAll->setObjectName("RBMyAll");
    rbMyReached->setObjectName("RBMyReached");
    rbMyNotReached->setObjectName("RBMyNotReached");
    connect(rbMyAll,SIGNAL(clicked()),this,SLOT(on_RadioButtonMyAll_clicked()));
    connect(rbMyReached,SIGNAL(clicked()),this,SLOT(on_RadioButtonMyReached_clicked()));
    connect(rbMyNotReached,SIGNAL(clicked()),this,SLOT(on_RadioButtonMyNotReached_clicked()));
    rbMyAll->setChecked(true);
    QWidget* wd1 = new QWidget;
    QVBoxLayout* lay1 = new QVBoxLayout;
    wd1->setObjectName("WDMy");
    lay1->setObjectName("LayMy");
    lay1->addWidget(rbMyAll);
    lay1->addWidget(rbMyReached);
    lay1->addWidget(rbMyNotReached);
    lay1->setMargin(1);
    lay1->setAlignment(Qt::AlignCenter);
    wd1->setLayout(lay1);
    QLabel* All = new QLabel("All");
    All->setToolTip(Words[2]);
    ui->TableWidgetFriends->setCellWidget(0,1,All);
    QPushButton *pbFriendsAll = new QPushButton(/*Words[]*/);
    QPushButton *pbFriendsReached = new QPushButton(/*Words[]*/);
    QPushButton *pbFriendsNotReached = new QPushButton(/*Words[]*/);
    pbFriendsAll->setObjectName("PBFriendsAll");
    pbFriendsReached->setObjectName("PBFriendsReached");
    pbFriendsNotReached->setObjectName("PBFriendsNotReached");
    connect(pbFriendsAll,SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendsAll_clicked()));
    connect(pbFriendsReached,SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendsReached_clicked()));
    connect(pbFriendsNotReached,SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendsNotReached_clicked()));
    pbFriendsAll->setChecked(true);
    QWidget* wd2 = new QWidget;
    QVBoxLayout* lay2 = new QVBoxLayout;
    wd2->setObjectName("WDFriends");
    lay2->setObjectName("LayFriends");
    lay2->addWidget(pbFriendsAll);
    lay2->addWidget(pbFriendsReached);
    lay2->addWidget(pbFriendsNotReached);
    lay2->setMargin(1);
    wd2->setLayout(lay2);
    ui->GroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(:/"+theme+"/program/"+theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->ButtonFind->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    ui->ButtonReturn->setIcon(QIcon(":/"+theme+"/program/"+theme+"/back.png"));
    ui->ButtonUpdate->setIcon(QIcon(":/"+theme+"/program/"+theme+"/update.png"));
    All->setPixmap(QPixmap(":/"+theme+"/program/"+theme+"/friends.png"));
    rbMyAll->setIcon(QIcon(":/"+theme+"/program/"+theme+"/all.png"));
    rbMyReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/reached.png"));
    rbMyNotReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/notreached.png"));
    pbFriendsAll->setIcon(QIcon(":/"+theme+"/program/"+theme+"/all.png"));
    pbFriendsReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/reached.png"));
    pbFriendsNotReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/notreached.png"));
    All->setScaledContents(true);
    All->setFixedSize(32,32);
    ui->TableWidgetFriends->setCellWidget(2,0,wd1);
    ui->TableWidgetFriends->setCellWidget(2,1,wd2);
    ui->TableWidgetFriends->resizeRowsToContents();

    for (int i=0;i<Friends.first.size();i++) {
        QLabel *ava = new QLabel;
        ava->setPixmap(Friends.first[i].GetAvatar());
        ava->setToolTip(Friends.first[i].GetName());
        ava->setAlignment(Qt::AlignCenter);
        ui->TableWidgetFriends->setCellWidget(0,i+2,ava);
        QTableWidgetItem* pItem(new QTableWidgetItem(tr("")));
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        pItem->setCheckState(Qt::Unchecked);
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->TableWidgetFriends->setItem(1,i+2,pItem);
        QTableWidgetItem *item2 = new QTableWidgetItem(Friends.first[i].GetSteamid());
        ui->TableWidgetFriends->setItem(3,i+2,item2);
    }
    for (int i=0;i<Friends.second.size();i++) {
        QLabel *ava = new QLabel;
        ava->setPixmap(Friends.second[i].GetAvatar());
        ava->setToolTip(Friends.second[i].GetName());
        ava->setAlignment(Qt::AlignCenter);
        ui->TableWidgetFriends->setCellWidget(0,Friends.first.size()+i+2,ava);
        QTableWidgetItem* pItem(new QTableWidgetItem(tr("")));
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        pItem->setCheckState(Qt::Unchecked);
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->TableWidgetFriends->setItem(1,Friends.first.size()+i+2,pItem);
        QTableWidgetItem *item2 = new QTableWidgetItem(Friends.second[i].GetSteamid());
        ui->TableWidgetFriends->setItem(3,Friends.first.size()+i+2,item2);
        ui->TableWidgetFriends->resizeColumnToContents(Friends.first.size()+i+2);
        ui->TableWidgetFriends->setColumnHidden(Friends.first.size()+i+2,true);
    }
    connect(ui->TableWidgetFriends,SIGNAL(cellChanged(int,int)),this,SLOT(on_CheckBoxFriend_Click(int,int)));
    ui->TableWidgetFriends->setRowHidden(3,true);
    ui->TableWidgetFriends->resizeColumnsToContents();

    ui->LineEditFind->setFocus();
}

void FormCompare::OnResultImage(int i, QString Save, ImageRequest *imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    if(!Save.isEmpty()){
        pixmap.save("images/achievements/"+appid+"/"+Save.mid(Save.indexOf("/",1)+1,Save.length()-1).remove(".jpg")+".png", "PNG");
    }
    ui->TableWidget->setCellWidget(i,0,label);
    ui->TableWidget->resizeRowToContents(i);
    imgr->deleteLater();
}

void FormCompare::UpdateHiddenRows(){
    for (int i=2;i<ui->TableWidget->rowCount();i++) {
        bool accept=true;
        for (int j=0;j<colfilter;j++) {
            if(filter[i][j]==false){
                accept=false;
                break;
                }
            }
        if(accept){
            ui->TableWidget->setRowHidden(i,false);
            } else
            ui->TableWidget->setRowHidden(i,true);
        }
}

FormCompare::~FormCompare()
{
    delete ui;
}

void FormCompare::on_RadioButtonMyAll_clicked()
{
    for (int i=2;i<ui->TableWidget->rowCount();i++){
        filter[i][1]=true;}
    UpdateHiddenRows();
}
void FormCompare::on_RadioButtonMyReached_clicked()
{
    for (int i=2;i<ui->TableWidget->rowCount();i++)
        if(ui->TableWidget->item(i,4)->text().indexOf(".")>-1){
            filter[i][1]=true;} else{
            filter[i][1]=false;}
    UpdateHiddenRows();
}
void FormCompare::on_RadioButtonMyNotReached_clicked()
{
    for (int i=2;i<ui->TableWidget->rowCount();i++)
        if(ui->TableWidget->item(i,4)->text().indexOf(".")>-1){
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
            for (int i=2;i<ui->TableWidget->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->TableWidget->item(i,5)->text()==selecteditem[j].toString()){
                        filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        break;
                        };
                    }
            } else {
            for (int i=2;i<ui->TableWidget->rowCount();i++) {
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
            for (int i=2;i<ui->TableWidget->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->TableWidget->item(i,5)->text()==selecteditem[j].toString()){
                        filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        break;
                        };
                    }
            } else {
            for (int i=2;i<ui->TableWidget->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()]=true;
                }
            }
        category.close();
        UpdateHiddenRows();
    }
}

void FormCompare::on_CheckBoxSCIcons_stateChanged(int arg1){
    switch(arg1){
    case 0:{
        ui->TableWidget->setColumnHidden(0,true);
        break;
    }
    case 2:{
        ui->TableWidget->setColumnHidden(0,false);
        break;
    }
    }
}
void FormCompare::on_CheckBoxSCTitle_stateChanged(int arg1){
    switch(arg1){
    case 0:{
        ui->TableWidget->setColumnHidden(1,true);
        break;
    }
    case 2:{
        ui->TableWidget->setColumnHidden(1,false);
        break;
    }
    }
}
void FormCompare::on_CheckBoxSCDescription_stateChanged(int arg1){
    switch(arg1){
    case 0:{
        ui->TableWidget->setColumnHidden(2,true);
        break;
    }
    case 2:{
        ui->TableWidget->setColumnHidden(2,false);
        break;
    }
    }
}
void FormCompare::on_CheckBoxSCTotalPercent_stateChanged(int arg1){
    switch(arg1){
    case 0:{
        ui->TableWidget->setColumnHidden(3,true);
        break;
    }
    case 2:{
        ui->TableWidget->setColumnHidden(3,false);
        break;
    }
    }
}

void FormCompare::on_CheckBoxFriend_Click(int row, int column){
    if((row==1)&&(column>1)){
        Profile sProfile;
        int col=ui->TableWidget->columnCount();
        if(ui->CheckBoxAllFriends->isChecked()){
            bool accept=true;
            for (int i=0;i<Friends.first.size();i++) {
                if(Friends.first[i].GetSteamid()==ui->TableWidgetFriends->item(3,column)->text()){
                    accept=false;
                    sProfile=Friends.first[i];
                    break;
                }
            }
            if(accept){
                for (int i=0;i<Friends.second.size();i++) {
                    if(Friends.second[i].GetSteamid()==ui->TableWidgetFriends->item(3,column)->text()){
                        sProfile=Friends.second[i];
                        break;
                    }
                }
            }
        } else {
            for (int i=0;i<Friends.first.size();i++) {
                if(Friends.first[i].GetSteamid()==ui->TableWidgetFriends->item(3,column)->text()){
                    sProfile=Friends.first[i];
                    break;
                }
            }
        }
        if(ui->TableWidgetFriends->item(row,column)->checkState()==Qt::Checked){
            ui->TableWidget->insertColumn(col);
            ui->TableWidget->setHorizontalHeaderItem(col,new QTableWidgetItem(sProfile.GetName()));
            QLabel* ava = new QLabel;
            ava->setPixmap(sProfile.GetAvatar());
            ava->setAlignment(Qt::AlignCenter);
            ui->TableWidget->setCellWidget(0,col,ava);
            QNetworkAccessManager manager;
            QEventLoop loop;
            QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
            QNetworkReply &replyPlayerAchievements = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+sProfile.GetSteamid())));
            loop.exec();
            QJsonArray JAPA = QJsonDocument::fromJson(replyPlayerAchievements.readAll()).object().value("playerstats").toObject().value("achievements").toArray();
            int totalr=0;
            int totalnr=0;
            for(int i=2;i<ui->TableWidget->rowCount();i++){
                int j=0;
                bool accept=false;
                for(;j<JAPA.size();j++){
                    if(JAPA[j].toObject().value("apiname").toString()==ui->TableWidget->item(i,5)->text()){
                        accept=true;
                        break;
                        }
                }
                if(accept){
                    QTableWidgetItem *item5;
                    if(JAPA[j].toObject().value("achieved").toInt()==1){
                        QDateTime date=QDateTime::fromSecsSinceEpoch(JAPA[j].toObject().value("unlocktime").toInt(),Qt::LocalTime);
                        item5 = new QTableWidgetItem(Words[15]+" "+date.toString("yyyy.MM.dd hh:mm"));
                        totalr++;
                        } else {
                        item5 = new QTableWidgetItem(Words[16]);
                        totalnr++;
                        }
                    item5->setTextAlignment(Qt::AlignCenter);
                    ui->TableWidget->setItem(i,col,item5);
                    //JAPA.removeAt(j);
                }
                }
            double percent= 100.0*totalr/(totalr+totalnr);
            if((totalr==0)&&(totalnr==0))
                ui->TableWidget->setCellWidget(1,col, new QLabel("profile is \nnot public"));
            else {
                ui->TableWidget->setCellWidget(1,col, new QLabel(" "+QString::number(totalr)+"/"+QString::number(totalr+totalnr)+"\n "+QString::number(percent)+"%"));
                QRadioButton *rbAll = new QRadioButton(/*Words[]*/);
                QRadioButton *rbReached = new QRadioButton(/*Words[]*/);
                QRadioButton *rbNotReached = new QRadioButton(/*Words[]*/);
                rbAll->setObjectName("RB"+QString::number(column)+"All");
                rbReached->setObjectName("RB"+QString::number(column)+"Reached");
                rbNotReached->setObjectName("RB"+QString::number(column)+"NotReached");
                connect(rbAll,SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendAll_Click()));
                connect(rbReached,SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendReached_Click()));
                connect(rbNotReached,SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendNotReached_Click()));
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
                rbAll->setIcon(QIcon(":/"+theme+"/program/"+theme+"/all.png"));
                rbReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/reached.png"));
                rbNotReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/notreached.png"));
                ui->TableWidgetFriends->setCellWidget(2,column,wd);
                ui->TableWidgetFriends->resizeRowsToContents();
                ui->TableWidgetFriends->resizeColumnsToContents();
            }
            bool **New = new bool*[ui->TableWidget->rowCount()];
            colfilter++;
            for (int i=0;i<ui->TableWidget->rowCount();i++) {
                New[i]=new bool[colfilter];
                for (int j=0;j<colfilter;j++) {
                    if(j!=colfilter-1)
                        New[i][j]=filter[i][j];
                    else
                        New[i][j]=true;
                    }
                }
            delete filter;
            filter = new bool*[ui->TableWidget->rowCount()];
            filter = New;

            ui->TableWidget->setColumnWidth(col,80);
        } else {
            int coll=0;
            for (int i=6;i<ui->TableWidget->columnCount();i++) {
                if(ui->TableWidget->horizontalHeaderItem(i)->text()==sProfile.GetName()){
                    coll=i;
                    ui->TableWidget->removeColumn(i);
                    break;
                }
            }
            if(findChild<QRadioButton*>("RB"+QString::number(column)+"All")){
                disconnect(findChild<QRadioButton*>("RB"+QString::number(column)+"All"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendAll_Click()));
                disconnect(findChild<QRadioButton*>("RB"+QString::number(column)+"Reached"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendReached_Click()));
                disconnect(findChild<QRadioButton*>("RB"+QString::number(column)+"NotReached"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendNotReached_Click()));
                delete findChild<QRadioButton*>("RB"+QString::number(column)+"All");
                delete findChild<QRadioButton*>("RB"+QString::number(column)+"Reached");
                delete findChild<QRadioButton*>("RB"+QString::number(column)+"NotReached");
                delete findChild<QVBoxLayout*>("Lay"+QString::number(column));
                ui->TableWidgetFriends->removeCellWidget(2,column);
                delete findChild<QWidget*>("WD"+QString::number(column));
                ui->TableWidgetFriends->resizeRowsToContents();
                ui->TableWidgetFriends->resizeColumnsToContents();
            }
            int filtercol=colfilter-(ui->TableWidget->columnCount()-coll);
            bool **New = new bool*[ui->TableWidget->rowCount()];
            colfilter--;
            for (int i=0;i<ui->TableWidget->rowCount();i++) {
                New[i]=new bool[colfilter];
                int jt=0;
                for (int j=0;j<colfilter;j++,jt++) {
                    if(j==filtercol)
                        jt++;
                    New[i][j]=filter[i][jt];
                }
            }
            delete filter;
            filter = new bool*[ui->TableWidget->rowCount()];
            filter = New;
            UpdateHiddenRows();
        }
    }
}

void FormCompare::on_RadioButtonFriendAll_Click(){
    QRadioButton *rb = qobject_cast<QRadioButton*>(sender());
    int col=(rb->objectName().mid(2,rb->objectName().indexOf("All")-2)).toInt();
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(0,col))->toolTip();
    int coll=0;
    for (int i=6;i<ui->TableWidget->columnCount();i++) {
        if(ui->TableWidget->horizontalHeaderItem(i)->text()==Name){
            coll=i;
            break;
        }
    }
    int filtercol=colfilter-(ui->TableWidget->columnCount()-coll);
    for (int i=2;i<ui->TableWidget->rowCount();i++){
        filter[i][filtercol]=true;}
    UpdateHiddenRows();
}
void FormCompare::on_RadioButtonFriendReached_Click(){
    QRadioButton *rb = qobject_cast<QRadioButton*>(sender());
    int col=(rb->objectName().mid(2,rb->objectName().indexOf("Reached")-2)).toInt();
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(0,col))->toolTip();
    int coll=0;
    for (int i=6;i<ui->TableWidget->columnCount();i++) {
        if(ui->TableWidget->horizontalHeaderItem(i)->text()==Name){
            coll=i;
            break;
        }
    }
    int filtercol=colfilter-(ui->TableWidget->columnCount()-coll);
    for (int i=2;i<ui->TableWidget->rowCount();i++)
        if(ui->TableWidget->item(i,coll)->text().indexOf(".")>-1){
            filter[i][filtercol]=true;} else{
            filter[i][filtercol]=false;}
    UpdateHiddenRows();
}
void FormCompare::on_RadioButtonFriendNotReached_Click(){
    QRadioButton *rb = qobject_cast<QRadioButton*>(sender());
    int col=(rb->objectName().mid(2,rb->objectName().indexOf("NotReached")-2)).toInt();
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(0,col))->toolTip();
    int coll=0;
    for (int i=6;i<ui->TableWidget->columnCount();i++) {
        if(ui->TableWidget->horizontalHeaderItem(i)->text()==Name){
            coll=i;
            break;
        }
    }
    int filtercol=colfilter-(ui->TableWidget->columnCount()-coll);
    for (int i=2;i<ui->TableWidget->rowCount();i++)
        if(ui->TableWidget->item(i,coll)->text().indexOf(".")>-1){
            filter[i][filtercol]=false;} else{
            filter[i][filtercol]=true;}
    UpdateHiddenRows();
}

void FormCompare::on_RadioButtonFriendsAll_clicked(){
    for (int i=2;i<ui->TableWidgetFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"All";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormCompare::on_RadioButtonFriendsReached_clicked(){
    for (int i=2;i<ui->TableWidgetFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"Reached";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormCompare::on_RadioButtonFriendsNotReached_clicked(){
    for (int i=2;i<ui->TableWidgetFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"NotReached";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}

void FormCompare::on_ButtonReturn_clicked(){
    emit return_to_achievements(this);
    //delete this;
}

void FormCompare::closeEvent(QCloseEvent *){
    on_ButtonReturn_clicked();
}

void FormCompare::on_CheckBoxShowFilter_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        ui->GroupBoxFilter->setHidden(true);
        break;
    }
    case 2:{
        ui->GroupBoxFilter->setHidden(false);
        break;
    }
    }
}

void FormCompare::on_CheckBoxAllFriends_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        for (int i=0;i<Friends.second.size();i++) {
            if(ui->TableWidgetFriends->item(1,Friends.first.size()+2+i)->checkState()==Qt::Checked){
                int coll=0;
                ui->TableWidgetFriends->item(1,Friends.first.size()+2+i)->setCheckState(Qt::Unchecked);
                for (int j=6;j<ui->TableWidget->columnCount();j++) {
                    if(ui->TableWidget->horizontalHeaderItem(j)->text()==Friends.second[i].GetName()){
                        coll=i;
                        ui->TableWidget->removeColumn(j);
                        break;
                    }
                }
                if(findChild<QRadioButton*>("RB"+QString::number(Friends.first.size()+2+i)+"All")){
                    disconnect(findChild<QRadioButton*>("RB"+QString::number(Friends.first.size()+2+i)+"All"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendAll_Click()));
                    disconnect(findChild<QRadioButton*>("RB"+QString::number(Friends.first.size()+2+i)+"Reached"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendReached_Click()));
                    disconnect(findChild<QRadioButton*>("RB"+QString::number(Friends.first.size()+2+i)+"NotReached"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendNotReached_Click()));
                    delete findChild<QRadioButton*>("RB"+QString::number(Friends.first.size()+2+i)+"All");
                    delete findChild<QRadioButton*>("RB"+QString::number(Friends.first.size()+2+i)+"Reached");
                    delete findChild<QRadioButton*>("RB"+QString::number(Friends.first.size()+2+i)+"NotReached");
                    delete findChild<QVBoxLayout*>("Lay"+QString::number(Friends.first.size()+2+i));
                    ui->TableWidgetFriends->removeCellWidget(2,Friends.first.size()+2+i);
                    delete findChild<QWidget*>("WD"+QString::number(Friends.first.size()+2+i));
                    ui->TableWidgetFriends->resizeRowsToContents();
                    ui->TableWidgetFriends->resizeColumnsToContents();
                }
                int filtercol=colfilter-(ui->TableWidget->columnCount()-coll);
                bool **New = new bool*[ui->TableWidget->rowCount()];
                colfilter--;
                for (int i=0;i<ui->TableWidget->rowCount();i++) {
                    New[i]=new bool[colfilter];
                    int jt=0;
                    for (int j=0;j<colfilter;j++,jt++) {
                        if(j==filtercol)
                            jt++;
                        New[i][j]=filter[i][jt];
                    }
                }
                delete filter;
                filter = new bool*[ui->TableWidget->rowCount()];
                filter = New;
                UpdateHiddenRows();
            }
            ui->TableWidgetFriends->setColumnHidden(Friends.first.size()+2+i,true);
        }
        break;
    }
    case 2:{
        for (int i=0;i<Friends.second.size();i++) {
            ui->TableWidgetFriends->setColumnHidden(Friends.first.size()+2+i,false);
        }
        ui->TableWidgetFriends->resizeColumnsToContents();
        break;
    }
    }
}

void FormCompare::on_ButtonFind_clicked(){
    on_LineEditFind_textChanged(ui->LineEditFind->text());
}

void FormCompare::on_LineEditFind_textChanged(const QString&){
    for (int i=2;i<ui->TableWidget->rowCount();i++)
        if((ui->TableWidget->item(i,1)->text().toLower().indexOf(ui->LineEditFind->text().toLower())>-1)||(ui->TableWidget->item(i,2)->text().toLower().indexOf(ui->LineEditFind->text().toLower())>-1))
            filter[i][0]=true; else
            filter[i][0]=false;
    UpdateHiddenRows();
}

void FormCompare::on_ButtonUpdate_clicked(){
    QNetworkAccessManager manager;
    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &replyPlayerAchievements = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+id)));
    loop.exec();
    JsonDocPlayerAchievements = QJsonDocument::fromJson(replyPlayerAchievements.readAll());
    QJsonArray JsonArrayPlayerAchievements = JsonDocPlayerAchievements.object().value("playerstats").toObject().value("achievements").toArray();
    if(JsonArrayPlayerAchievements.size()>1){
        int totalr=0;
        int totalnr=0;
        for(int i=2;i<ui->TableWidget->rowCount();i++){
            int j=0;
            bool accept=false;
            for(;j<JsonArrayPlayerAchievements.size();j++){
                if(JsonArrayPlayerAchievements[j].toObject().value("apiname").toString()==ui->TableWidget->item(i,5)->text()){
                    accept=true;
                    break;
                    }
            }
            if(accept){
                QTableWidgetItem *item5;
                if(JsonArrayPlayerAchievements[j].toObject().value("achieved").toInt()==1){
                    QDateTime date=QDateTime::fromSecsSinceEpoch(JsonArrayPlayerAchievements[j].toObject().value("unlocktime").toInt(),Qt::LocalTime);
                    item5 = new QTableWidgetItem(Words[15]+" "+date.toString("yyyy.MM.dd hh:mm"));
                    totalr++;
                    } else {
                    item5 = new QTableWidgetItem(Words[16]);
                    totalnr++;
                    }
                item5->setTextAlignment(Qt::AlignCenter);
                delete ui->TableWidget->item(i,4);
                ui->TableWidget->setItem(i,4,item5);
                //JAPA.removeAt(j);
            }
            }
        double percent= 100.0*totalr/(totalr+totalnr);
        if((totalr==0)&&(totalnr==0))
            ui->TableWidget->setCellWidget(1,4, new QLabel("profile is \nnot public"));
        else {
            ui->TableWidget->setCellWidget(1,4, new QLabel(" "+QString::number(totalr)+"/"+QString::number(totalr+totalnr)+"\n "+QString::number(percent)+"%"));
        }
    }

    for (int ii=2;ii<ui->TableWidgetFriends->columnCount();ii++){
        if(ui->TableWidgetFriends->item(1,ii)->checkState()==Qt::Checked){
            Profile sProfile;
            if(ui->CheckBoxAllFriends->isChecked()){
                bool accept=true;
                for (int i=0;i<Friends.first.size();i++) {
                    if(Friends.first[i].GetSteamid()==ui->TableWidgetFriends->item(3,ii)->text()){
                        accept=false;
                        sProfile=Friends.first[i];
                        break;
                    }
                }
                if(accept){
                    for (int i=0;i<Friends.second.size();i++) {
                        if(Friends.second[i].GetSteamid()==ui->TableWidgetFriends->item(3,ii)->text()){
                            sProfile=Friends.second[i];
                            break;
                        }
                    }
                }
            } else {
                for (int i=0;i<Friends.first.size();i++) {
                    if(Friends.first[i].GetSteamid()==ui->TableWidgetFriends->item(3,ii)->text()){
                        sProfile=Friends.first[i];
                        break;
                    }
                }
            }
            int col=0;
            for (int j=5;j<ui->TableWidget->columnCount();j++) {
                if(ui->TableWidget->horizontalHeaderItem(j)->text()==sProfile.GetName()){
                    col=j;
                    break;
                }
            }
            QNetworkReply &replyPlayerAchievements = *manager.get(QNetworkRequest(QString("http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?key="+key+"&appid="+appid+"&steamid="+sProfile.GetSteamid())));
            loop.exec();
            QJsonArray JAPA = QJsonDocument::fromJson(replyPlayerAchievements.readAll()).object().value("playerstats").toObject().value("achievements").toArray();
            int totalr=0;
            int totalnr=0;
            for(int i=2;i<ui->TableWidget->rowCount();i++){
                int j=0;
                bool accept=false;
                for(;j<JAPA.size();j++){
                    if(JAPA[j].toObject().value("apiname").toString()==ui->TableWidget->item(i,5)->text()){
                        accept=true;
                        break;
                        }
                }
                if(accept){
                    QTableWidgetItem *item5;
                    if(JAPA[j].toObject().value("achieved").toInt()==1){
                        QDateTime date=QDateTime::fromSecsSinceEpoch(JAPA[j].toObject().value("unlocktime").toInt(),Qt::LocalTime);
                        item5 = new QTableWidgetItem(Words[15]+" "+date.toString("yyyy.MM.dd hh:mm"));
                        totalr++;
                        } else {
                        item5 = new QTableWidgetItem(Words[16]);
                        totalnr++;
                        }
                    item5->setTextAlignment(Qt::AlignCenter);
                    delete ui->TableWidget->item(i,col);
                    ui->TableWidget->setItem(i,col,item5);
                    //JAPA.removeAt(j);
                }
                }
            double percent= 100.0*totalr/(totalr+totalnr);
            if((totalr==0)&&(totalnr==0))
                ui->TableWidget->setCellWidget(1,col, new QLabel("profile is \nnot public"));
            else {
                ui->TableWidget->setCellWidget(1,col, new QLabel(" "+QString::number(totalr)+"/"+QString::number(totalr+totalnr)+"\n "+QString::number(percent)+"%"));
            }
        }
    }
}
