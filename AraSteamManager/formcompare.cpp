#include "formcompare.h"
#include "ui_formcompare.h"

FormCompare::FormCompare(QString keys, QString ids, SteamAPIGame games, QPixmap GameLogo, SteamAPIAchievements achievementss, QWidget *parent) : QWidget(parent), ui(new Ui::FormCompare){
    ui->setupUi(this);
    Words=Setting.GetWords("compare");
    key=keys;
    id=ids;
    game=games;
    achievements=achievementss;
    ui->CheckBoxFavorites->setText(Words[6]);
    ui->CheckBoxAllFriends->setText(Words[7]);
    ui->ButtonFind->setText(" "+Words[8]);
    ui->GroupBoxFilter->setTitle("      "+Words[9]);
    ui->GroupBoxShowedColumns->setTitle(Words[10]);
    ui->CheckBoxSCIcons->setText(Words[11]);
    ui->CheckBoxSCTitle->setText(Words[12]);
    ui->CheckBoxSCDescription->setText(Words[13]);
    ui->CheckBoxSCTotalPercent->setText(Words[14]);
    ui->LabelPlayerCount->setText(Words[18]+": "+game.GetNumberPlayers(key,false));
    ui->ButtonUpdate->setText(Words[19]);
    ui->CheckBoxShowFilter->setText(Words[24]);
    ui->TableWidget->setColumnCount(6);
    ui->TableWidget->insertRow(0);
    ui->TableWidget->insertRow(1);
    ui->TableWidget->setVerticalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidget->setVerticalHeaderItem(1,new QTableWidgetItem("%"));
    ui->TableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
    ui->TableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[12]));
    ui->TableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[13]));
    ui->TableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem(Words[14]));
    ui->LabelLogo->setPixmap(GameLogo);
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
    ui->ButtonReturn->setText(" "+Words[0]);
    //ui->GroupBoxMyA->setTitle(Words[1]);
    //ui->GroupBoxFriendsA->setTitle(Words[2]);
    //ui->RadioButtonMyAll->setText(Words[3]);
    //ui->RadioButtonMyReached->setText(Words[4]);
    //ui->RadioButtonMyNotReached->setText(Words[5]);
    //ui->RadioButtonFriendsAll->setText(Words[3]);
    //ui->RadioButtonFriendsReached->setText(Words[4]);
    //ui->RadioButtonFriendsNotReached->setText(Words[5]);
    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    SteamAPIProfile Profile(key,id,"url");
    connect(&Profile, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    disconnect(&Profile, SIGNAL(finished()), &loop, SLOT(quit()));
    ui->TableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem(Profile.GetPersonaname()/*Words[15]*/));
    QNetworkReply &imagereply = *manager.get(QNetworkRequest(Profile.GetAvatar()));
    loop.exec();
    QPixmap pix;
    pix.loadFromData(imagereply.readAll());
    QLabel* myava = new QLabel;
    myava->setPixmap(pix);
    myava->setAlignment(Qt::AlignCenter);
    ui->TableWidget->setCellWidget(0,5,myava);
    int totalr=0;
    int totalnr=0;
    if(!QDir("images/achievements/"+QString::number(game.GetAppid())).exists()){
        QDir().mkdir("images/achievements/"+QString::number(game.GetAppid()));
    }
    for(int i=0;i<achievements.GetAchievementsCount();i++){
        qDebug()<<i;
            if(achievements.GetDisplayname(i)!=""){
                int row = ui->TableWidget->rowCount();
                ui->TableWidget->insertRow(row);
                ui->TableWidget->setItem(row,0,new QTableWidgetItem(achievements.GetApiname(i)));
                QString AchievementIcon=achievements.GetIcon(i).mid(66,achievements.GetIcon(i).length());
                if(!QFile::exists("images/achievements/"+QString::number(game.GetAppid())+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png")){
                    ImageRequest *image;
                    switch (Setting.GetSaveimages()) {
                        case 0:{
                            image = new ImageRequest(row,"");
                            break;
                            }
                        case 1:{
                            image = new ImageRequest(row,AchievementIcon);
                            break;
                            }
                        default:{
                            image = new ImageRequest(row,"");
                            break;
                            }
                        }
                    connect(image,SIGNAL(onReady(int, QString, ImageRequest *)),this,SLOT(OnResultImage(int, QString, ImageRequest *)));
                    image->Get(achievements.GetIcon(i));
                    } else {
                    QPixmap pixmap;
                    pixmap.load("images/achievements/"+QString::number(game.GetAppid())+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1).remove(".jpg")+".png", "PNG");
                    QLabel *label = new QLabel;
                    label->setPixmap(pixmap);
                    ui->TableWidget->setCellWidget(row,1,label);
                    }
                ui->TableWidget->setItem(row,2,new QTableWidgetItem(achievements.GetDisplayname(i)));
                ui->TableWidget->setItem(row,3,new QTableWidgetItem(achievements.GetDescription(i)));
                ui->TableWidget->setItem(row,4,new QTableWidgetItem(achievements.GetPercent(i)<10?"0"+QString::number(achievements.GetPercent(i))+"%":QString::number(achievements.GetPercent(i))+"%"));
                if(achievements.GetAchieved(i)==1){
                    ui->TableWidget->setItem(row,5,new QTableWidgetItem(Words[15]+" "+achievements.GetUnlocktime(i).toString("yyyy.MM.dd hh:mm")));
                    totalr++;
                    } else {
                    ui->TableWidget->setItem(row,5,new QTableWidgetItem(Words[16]));
                    totalnr++;
                    }
                ui->TableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
                ui->TableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
                ui->TableWidget->item(row,4)->setTextAlignment(Qt::AlignCenter);
                ui->TableWidget->item(row,5)->setTextAlignment(Qt::AlignCenter);
                ui->TableWidget->setVerticalHeaderItem(row,new QTableWidgetItem(QString::number(row-1)));
            }
        }
    ui->TableWidget->setColumnHidden(0,true);
    ui->TableWidget->setCellWidget(1,5, new QLabel(" "+QString::number(totalr)+"/"+QString::number(totalr+totalnr)+"\n "+QString::number(100.0*totalr/(totalr+totalnr))+"%"));
    ui->TableWidget->setColumnWidth(1,65);
    ui->TableWidget->setColumnWidth(2,100);
    ui->TableWidget->setColumnWidth(3,315);
    ui->TableWidget->resizeColumnToContents(4);
    ui->TableWidget->setColumnWidth(5,80);
    ui->TableWidget->resizeRowsToContents();

    QDir categories("Files/Categories/"+QString::number(game.GetAppid()));
    categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categories.setSorting(QDir::Name);
    QFileInfoList list = categories.entryInfoList();
    if(categories.exists()){
        QFormLayout *layout1 = new QFormLayout;
        QFormLayout *layout2 = new QFormLayout;
        QWidget *widget1 = new QWidget;
        QWidget *widget2 = new QWidget;
        for (int i = 0; i < list.size(); ++i){
            QFile category("Files/Categories/"+QString::number(game.GetAppid())+"/"+list.at(i).fileName());
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

        ui->ScrollAreaCategoriesComboBox->setHidden(layout1->rowCount()==0?true:false);
        ui->ScrollAreaCategoriesCheckBox->setHidden(layout2->rowCount()==0?true:false);
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
    SteamAPIFriends frien(key,id);
    connect(&frien, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    disconnect(&frien, SIGNAL(finished()), &loop, SLOT(quit()));
    QVector<SteamAPIProfile> Profiles = frien.GetProfiles();
    for (int i=0; i < Profiles.size()-1; i++) {
        for (int j=0; j < Profiles.size()-i-1; j++) {
            if (Profiles[j].GetPersonaname() > Profiles[j+1].GetPersonaname()) {
                SteamAPIProfile temp = Profiles[j];
                Profiles[j] = Profiles[j+1];
                Profiles[j+1] = temp;
            }
        }
    }
    for (int i=0;i<Profiles.size();i++) {
        SteamAPIGames Games;
        Games.Set(key,Profiles[i].GetSteamid(),true,true);
        connect(&Games, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        disconnect(&Games, SIGNAL(finished()), &loop, SLOT(quit()));
        bool apply=false;
        for (int i=0;i<Games.GetGamesCount();i++) {
            if(Games.GetAppid(i)==games.GetAppid()){
                apply=true;
                break;
            }
        }
        QPair<SteamAPIProfile,int> deb;
        deb.first=Profiles[i];
        if(apply){
            deb.second=1;
            type1++;
        } else {
            deb.second=2;
            type2++;
        }
        friends.push_back(deb);
    }
    ui->TableWidgetFriends->setRowCount(4);
    ui->TableWidgetFriends->setColumnCount(type1+type2+2);

    QLabel* Me = new QLabel;
    Me->setPixmap(pix);
    Me->setAlignment(Qt::AlignCenter);
    Me->setToolTip(Profile.GetPersonaname());
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
    for (int i=0;i<friends.size();i++) {
        QNetworkReply &imagereply = *manager.get(QNetworkRequest(friends[i].first.GetAvatar()));
        loop.exec();
        QPixmap pix;
        pix.loadFromData(imagereply.readAll());
        QLabel *ava = new QLabel;
        ava->setPixmap(pix);
        ava->setToolTip(friends[i].first.GetPersonaname());
        ava->setAlignment(Qt::AlignCenter);
        ui->TableWidgetFriends->setCellWidget(0,i+2,ava);
        QTableWidgetItem* pItem(new QTableWidgetItem(tr("")));
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        pItem->setCheckState(Qt::Unchecked);
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->TableWidgetFriends->setItem(1,i+2,pItem);
        ui->TableWidgetFriends->setItem(3,i+2,new QTableWidgetItem(friends[i].first.GetSteamid()));
        ui->TableWidgetFriends->setColumnHidden(i+2,friends[i].second==2?true:false);
    }
    disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    connect(ui->TableWidgetFriends,SIGNAL(cellChanged(int,int)),this,SLOT(on_CheckBoxFriend_Click(int,int)));
    ui->TableWidgetFriends->setRowHidden(3,true);
    ui->TableWidgetFriends->resizeColumnsToContents();
    ui->LineEditFind->setFocus();
}

void FormCompare::OnResultAvatar(int i, QString, ImageRequest* img){
//    qDebug()<<i;
//    QPixmap pixmap;
//    pixmap.loadFromData(img->GetAnswer());
//    QLabel *ava = new QLabel;
//    ava->setPixmap(pixmap);
//    if(i>=Friends.first.size()){
//        ava->setPixmap(Friends.first[i].GetAvatar());
//        ava->setToolTip(Friends.first[i].GetPersonaname());
//    } else {
//        ava->setPixmap(Friends.second[i].GetAvatar());
//        ava->setToolTip(Friends.second[i].GetPersonaname());
//    }
//    ava->setAlignment(Qt::AlignCenter);
//    ui->TableWidgetFriends->setCellWidget(0,i+2,ava);
}

void FormCompare::OnResultImage(int i, QString Save, ImageRequest *imgr){
    disconnect(imgr,SIGNAL(onReady(int, QString, ImageRequest *)),this,SLOT(OnResultImage(int, QString, ImageRequest *)));
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    if(!Save.isEmpty()){
        pixmap.save("images/achievements/"+QString::number(game.GetAppid())+"/"+Save.mid(Save.indexOf("/",1)+1,Save.length()-1).remove(".jpg")+".png", "PNG");
    }
    ui->TableWidget->setCellWidget(i,1,label);
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
        ui->TableWidget->setRowHidden(i,accept?false:true);
        }
}

FormCompare::~FormCompare(){
    delete ui;
}

void FormCompare::on_RadioButtonMyAll_clicked(){
    for (int i=2;i<ui->TableWidget->rowCount();i++)
        filter[i][1]=true;
    UpdateHiddenRows();
}
void FormCompare::on_RadioButtonMyReached_clicked(){
    for (int i=2;i<ui->TableWidget->rowCount();i++)
        filter[i][1]=ui->TableWidget->item(i,5)->text().indexOf(".")>-1?true:false;
    UpdateHiddenRows();
}
void FormCompare::on_RadioButtonMyNotReached_clicked(){
    for (int i=2;i<ui->TableWidget->rowCount();i++)
        filter[i][1]=ui->TableWidget->item(i,5)->text().indexOf(".")>-1?false:true;
    UpdateHiddenRows();
}

void FormCompare::on_ComboBoxCategory_Change(int index){
    QComboBox *cb = qobject_cast<QComboBox*>(sender());
    QDir categories("Files/Categories/"+QString::number(game.GetAppid()));
    if(categories.exists()){
        categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        categories.setSorting(QDir::Name);
        QFileInfoList list = categories.entryInfoList();
        QFile category("Files/Categories/"+QString::number(game.GetAppid())+"/"+list.at(cb->objectName().mid(8,cb->objectName().length()).toInt()).fileName());
        category.open(QFile::ReadOnly);
        QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
        QJsonArray selecteditem = cat.object().value(cb->itemText(index)).toArray();
        if(index!=0)
            for (int i=2;i<ui->TableWidget->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->TableWidget->item(i,0)->text()==selecteditem[j].toString()){
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
    QDir categories("Files/Categories/"+QString::number(game.GetAppid()));
    if(categories.exists()){
        categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        categories.setSorting(QDir::Name);
        QFileInfoList list = categories.entryInfoList();
        QFile category("Files/Categories/"+QString::number(game.GetAppid())+"/"+list.at(cb->objectName().mid(8,cb->objectName().length()).toInt()).fileName());
        category.open(QFile::ReadOnly);
        QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
        QJsonArray selecteditem = cat.object().value(cat.object().value("values").toArray().at(0).toString()).toArray();
        if(ind!=0)
            for (int i=2;i<ui->TableWidget->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->TableWidget->item(i,0)->text()==selecteditem[j].toString()){
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
    ui->TableWidget->setColumnHidden(1,arg1==0?true:false);
}
void FormCompare::on_CheckBoxSCTitle_stateChanged(int arg1){
    ui->TableWidget->setColumnHidden(2,arg1==0?true:false);
}
void FormCompare::on_CheckBoxSCDescription_stateChanged(int arg1){
    ui->TableWidget->setColumnHidden(3,arg1==0?true:false);
}
void FormCompare::on_CheckBoxSCTotalPercent_stateChanged(int arg1){
    ui->TableWidget->setColumnHidden(4,arg1==0?true:false);
}

void FormCompare::on_CheckBoxFriend_Click(int row, int column){
    if((row==1)&&(column>1)){
        int col=ui->TableWidget->columnCount();
        SteamAPIProfile sProfile=friends[column-2].first;
        qDebug()<<sProfile.GetPersonaname();
        if(ui->TableWidgetFriends->item(row,column)->checkState()==Qt::Checked){
            ui->TableWidget->insertColumn(col);
            ui->TableWidget->setHorizontalHeaderItem(col,new QTableWidgetItem(sProfile.GetPersonaname()));
            QNetworkAccessManager manager;
            QEventLoop loop;
            connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
            QNetworkReply &imagereply = *manager.get(QNetworkRequest(friends[column-2].first.GetAvatar()));
            loop.exec();
            disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
            QPixmap pix;
            pix.loadFromData(imagereply.readAll());
            QLabel *ava = new QLabel;
            ava->setPixmap(pix);
            ava->setToolTip(friends[column-2].first.GetPersonaname());
            ava->setAlignment(Qt::AlignCenter);
            ui->TableWidget->setCellWidget(0,col,ava);
            SteamAPIAchievementsPlayer Pla(key,QString::number(game.GetAppid()),sProfile.GetSteamid());
            connect(&Pla,SIGNAL(finished()), &loop, SLOT(quit()));
            loop.exec();
            disconnect(&Pla,SIGNAL(finished()), &loop, SLOT(quit()));
            SteamAPIAchievements Ach;
            Ach.Set(Pla);
            if(ProfileIsPublic(Ach,col)){
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
                for (int j=0;j<colfilter;j++)
                    New[i][j]=j!=colfilter-1?filter[i][j]:true;
                }
            delete filter;
            filter = new bool*[ui->TableWidget->rowCount()];
            filter = New;

            ui->TableWidget->setColumnWidth(col,80);
        } else {
            int coll=0;
            for (int i=6;i<ui->TableWidget->columnCount();i++) {
                if(ui->TableWidget->horizontalHeaderItem(i)->text()==sProfile.GetPersonaname()){
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
        filter[i][filtercol]=ui->TableWidget->item(i,coll)->text().indexOf(".")>-1?true:false;
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
        filter[i][filtercol]=ui->TableWidget->item(i,coll)->text().indexOf(".")>-1?false:true;
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
    emit return_to_achievements();
    //delete this;
}

void FormCompare::closeEvent(QCloseEvent *){
    on_ButtonReturn_clicked();
}

void FormCompare::on_CheckBoxShowFilter_stateChanged(int arg1){
    ui->GroupBoxFilter->setHidden(arg1==0?true:false);
}

void FormCompare::on_CheckBoxAllFriends_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        for (int i=0;i<friends.size();i++) {
            if(friends[i].second==2){
                ui->TableWidgetFriends->setColumnHidden(i+2,true);
            }
        }
        break;
    }
//                if(ui->TableWidgetFriends->item(1,2+i)->checkState()==Qt::Checked){
//                    int coll=0;
//                    ui->TableWidgetFriends->item(1,2+i)->setCheckState(Qt::Unchecked);
//                    for (int j=6;j<ui->TableWidget->columnCount();j++) {
//                        if(ui->TableWidget->horizontalHeaderItem(j)->text()==friends[i].first.GetPersonaname()&&friends[i].second==2){
//                            coll=i;
//                            ui->TableWidget->removeColumn(j);
//                            break;
//                        }
//                    }
//                    if(findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"All")){
//                        disconnect(findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"All"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendAll_Click()));
//                        disconnect(findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"Reached"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendReached_Click()));
//                        disconnect(findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"NotReached"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendNotReached_Click()));
//                        delete findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"All");
//                        delete findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"Reached");
//                        delete findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"NotReached");
//                        delete findChild<QVBoxLayout*>("Lay"+QString::number(type1+2+i));
//                        ui->TableWidgetFriends->removeCellWidget(2,type1+2+i);
//                        delete findChild<QWidget*>("WD"+QString::number(type1+2+i));
//                        ui->TableWidgetFriends->resizeRowsToContents();
//                        ui->TableWidgetFriends->resizeColumnsToContents();
//                    }
//                    int filtercol=colfilter-(ui->TableWidget->columnCount()-coll);
//                    bool **New = new bool*[ui->TableWidget->rowCount()];
//                    colfilter--;
//                    for (int i=0;i<ui->TableWidget->rowCount();i++) {
//                        New[i]=new bool[colfilter];
//                        int jt=0;
//                        for (int j=0;j<colfilter;j++,jt++) {
//                            if(j==filtercol)
//                                jt++;
//                            New[i][j]=filter[i][jt];
//                        }
//                    }
//                    delete filter;
//                    filter = new bool*[ui->TableWidget->rowCount()];
//                    filter = New;
//                    UpdateHiddenRows();
//                }
//                ui->TableWidgetFriends->setColumnHidden(type1+2+i,true);
    case 2:{
        for (int i=0;i<friends.size();i++) {
            if(friends[i].second==2){
                ui->TableWidgetFriends->setColumnHidden(i+2,false);
            }
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
        filter[i][0]=(ui->TableWidget->item(i,2)->text().toLower().indexOf(ui->LineEditFind->text().toLower())>-1)||(ui->TableWidget->item(i,3)->text().toLower().indexOf(ui->LineEditFind->text().toLower())>-1)?true:false;
    UpdateHiddenRows();
}

bool FormCompare::ProfileIsPublic(SteamAPIAchievements achievement, int col){
    int totalr=0;
    int totalnr=0;
    for(int i=2;i<ui->TableWidget->rowCount();i++){
        int j=0;
        bool accept=false;
        for(;j<achievement.GetAchievementsCount();j++){
            if(achievement.GetApiname(j)==ui->TableWidget->item(i,0)->text()){
                accept=true;
                break;
                }
        }
        if(accept){
            QTableWidgetItem *item5;
            if(achievement.GetAchieved(j)==1){
                item5 = new QTableWidgetItem(Words[15]+" "+achievement.GetUnlocktime(j).toString("yyyy.MM.dd hh:mm"));
                totalr++;
                } else {
                item5 = new QTableWidgetItem(Words[16]);
                totalnr++;
                }
            item5->setTextAlignment(Qt::AlignCenter);
            ui->TableWidget->setItem(i,col,item5);
        }
        }
    if((totalr==0)&&(totalnr==0)){
        ui->TableWidget->setCellWidget(1,col, new QLabel("profile is \nnot public"));
        return false;
        } else {
        ui->TableWidget->setCellWidget(1,col, new QLabel(" "+QString::number(totalr)+"/"+QString::number(totalr+totalnr)+"\n "+QString::number(100.0*totalr/(totalr+totalnr))+"%"));
        return true;
    }
}

SteamAPIProfile FormCompare::FindProfile(int ii){
    for (int i=0;i<friends.size();i++)
        if(friends[i].first.GetSteamid()==ui->TableWidgetFriends->item(3,ii)->text())
            return friends[i].first;
}

void FormCompare::on_ButtonUpdate_clicked(){
    achievements.Update();
    if(achievements.GetAchievementsCount()>1){
        ProfileIsPublic(achievements,5);
    }
    for (int ii=2;ii<ui->TableWidgetFriends->columnCount();ii++){
        if(ui->TableWidgetFriends->item(1,ii)->checkState()==Qt::Checked){
            SteamAPIProfile sProfile=friends[ii-2].first;
            int col=0;
            for (int j=5;j<ui->TableWidget->columnCount();j++) {
                if(ui->TableWidget->horizontalHeaderItem(j)->text()==sProfile.GetPersonaname()){
                    col=j;
                    break;
                }
            }
            SteamAPIAchievementsPlayer Pla(key,QString::number(game.GetAppid()),sProfile.GetSteamid());
            SteamAPIAchievements Ach;
            Ach.Set(Pla);
            ProfileIsPublic(Ach,col);
        }
    }
}
