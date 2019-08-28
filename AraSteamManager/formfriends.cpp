#include "formfriends.h"
#include "ui_formfriends.h"

FormFriends::FormFriends(QString ids, QString keys, int languages, int Themes, QJsonDocument DocFriendss, int SaveImagess, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormFriends){
    ui->setupUi(this);
    id=ids;
    key=keys;
    language=languages;
    DocFriends=DocFriendss;
    SaveImages=SaveImagess;
    Theme=Themes;
    ui->FormFriendsTWFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QFile FileLanguage;
    switch(language){
    case 1:{
        FileLanguage.setFileName("Files/Languages/ENG/friends.txt");
        break;
        }
    case 5:{
        FileLanguage.setFileName("Files/Languages/RU/friends.txt");
        }
    }
    if(FileLanguage.open(QIODevice::ReadOnly)){
        while(!FileLanguage.atEnd()){
            SLLanguage << QString::fromLocal8Bit(FileLanguage.readLine()).remove("\r\n").remove("\n");
        }
    }
    QIcon favorites;
    switch(Theme){
    case 1:{
        ui->FormFriendsBReturn->setIcon(QIcon("images/program/back_white.png"));
        ui->FormFriendsBFind->setIcon(QIcon("images/program/find_white.png"));
        ui->FormFriendsGBFilter->setStyleSheet("QGroupBox::title {image:url(images/program/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
        favorites.addFile("images/program/favorites_white.png");
        break;
        }
    case 2:{
        ui->FormFriendsBReturn->setIcon(QIcon("images/program/back_black.png"));
        ui->FormFriendsBFind->setIcon(QIcon("images/program/find_black.png"));
        ui->FormFriendsGBFilter->setStyleSheet("QGroupBox::title {image:url(images/program/filter_black.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
        favorites.addFile("images/program/favorites_black.png");
        break;
        }
    }
    ui->FormFriendsLLogo->setText("(WIP)");
    ui->FormFriendsGBFilter->setTitle("      "+SLLanguage[0]);
    ui->FormFriendsBReturn->setText(" "+SLLanguage[1]);
    ui->FormFriendsBFind->setText("  "+SLLanguage[2]);
    ui->FormFriendsChBOpenProfile->setText(SLLanguage[3]);
    ui->FormFriendsChBFavorites->setText(SLLanguage[20]);
    ui->FormFriendsLineEditName->setPlaceholderText(SLLanguage[21]);
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(1,new QTableWidgetItem(SLLanguage[5]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(2,new QTableWidgetItem(SLLanguage[4]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(3,new QTableWidgetItem(SLLanguage[6]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(4,new QTableWidgetItem(SLLanguage[18]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(5,new QTableWidgetItem(""));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(6,new QTableWidgetItem(SLLanguage[7]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(7,new QTableWidgetItem(SLLanguage[19]));
    ui->FormFriendsCBStatus->addItem(SLLanguage[6]);
    ui->FormFriendsCBStatus->addItem(SLLanguage[8]);
    ui->FormFriendsCBStatus->addItem(SLLanguage[9]);
    ui->FormFriendsCBStatus->addItem(SLLanguage[10]);
    ui->FormFriendsCBStatus->addItem(SLLanguage[11]);
    ui->FormFriendsCBStatus->addItem(SLLanguage[12]);
    ui->FormFriendsCBStatus->addItem(SLLanguage[13]);
    ui->FormFriendsCBStatus->addItem(SLLanguage[14]);
    ui->FormFriendsCBStatus->addItem(SLLanguage[15]);
    QString Querry="http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+key+"&steamids="+DocFriends.object().value("friendslist").toObject().value("friends").toArray().at(0).toObject().value("steamid").toString();
    for (int i=1;i<DocFriends.object().value("friendslist").toObject().value("friends").toArray().size();i++) {
        Querry+=","+DocFriends.object().value("friendslist").toObject().value("friends").toArray().at(i).toObject().value("steamid").toString();
    }
    QNetworkAccessManager manager;
    QEventLoop loop;  //Ждем ответ от сервера.
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &ReplyPlayerSummaries = *manager.get(QNetworkRequest(Querry));
    loop.exec();
    QJsonArray Accounts = QJsonDocument::fromJson(ReplyPlayerSummaries.readAll()).object().value("response").toObject().value("players").toArray();
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
    for (int i=0;i<DocFriends.object().value("friendslist").toObject().value("friends").toArray().size();i++) {
        QJsonObject Account = abc[i];
        //{"steamid":"76561198065018572",
        //"communityvisibilitystate":3, (1 - the profile is not visible to you, 3 - the profile is "Public")
        //"profilestate":1,
        //"personaname":"Yuno",
        //"lastlogoff":1555174765,
        //"commentpermission":1,
        //"profileurl":"https://steamcommunity.com/id/Arankir/",
        //"avatar":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/avatars/ce/ce1d088d99e7244b9e5297430b9af304d2c5f93c.jpg",
        //"avatarmedium":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/avatars/ce/ce1d088d99e7244b9e5297430b9af304d2c5f93c_medium.jpg",
        //"avatarfull":"https://steamcdn-a.akamaihd.net/steamcommunity/public/images/avatars/ce/ce1d088d99e7244b9e5297430b9af304d2c5f93c_full.jpg",
        //"personastate":1,
        //"primaryclanid":"103582791434380590",
        //"timecreated":1339187696,
        //"personastateflags":0,
        //"gameextrainfo":"Realm of the Mad God",
        //"gameid":"200210",
        //"loccountrycode":"JP",
        //"locstatecode":"40",
        //"loccityid":26111}
        ui->FormFriendsTWFriends->insertRow(i);
        if(!QFile::exists("images/profiles/"+Account.value("avatar").toString().mid(72,Account.value("avatar").toString().indexOf(".jpg",0)-72)+".png")){
            ImageRequest *image;
            switch (SaveImages) {
                case 0:{
                    image = new ImageRequest(i,"");
                    break;
                    }
                case 1:{
                    image = new ImageRequest(i,Account.value("avatar").toString().mid(72,Account.value("avatar").toString().indexOf(".jpg",0)-72));
                    break;
                    }
                default:{
                    image = new ImageRequest(i,"");
                    break;
                    }
            }
            connect(image,SIGNAL(onReady(int, QString, ImageRequest *)),this,SLOT(OnResultImage(int, QString, ImageRequest *)));
            image->Get(Account.value("avatar").toString());
            } else {
            QPixmap pixmap;
            pixmap.load("images/profiles/"+Account.value("avatar").toString().mid(72,Account.value("avatar").toString().indexOf(".jpg",0)-72)+".png", "PNG");
            QLabel *lb = new QLabel();
            lb->setPixmap(pixmap);
            ui->FormFriendsTWFriends->setCellWidget(i,0,lb);
            }
        QTableWidgetItem *item2 = new QTableWidgetItem(Account.value("personaname").toString());
        ui->FormFriendsTWFriends->setItem(i,1,item2);
        QDateTime date;
        for (int j=0;;j++) {
            if(Account.value("steamid").toString()==DocFriends.object().value("friendslist").toObject().value("friends").toArray().at(j).toObject().value("steamid").toString()){
                date=QDateTime::fromSecsSinceEpoch(DocFriends.object().value("friendslist").toObject().value("friends").toArray().at(j).toObject().value("friend_since").toInt(),Qt::LocalTime);
                break;
            }
        }
        QTableWidgetItem *item3 = new QTableWidgetItem(date.toString("yyyy.MM.dd hh:mm:ss"));
        ui->FormFriendsTWFriends->setItem(i,2,item3);
        QTableWidgetItem *item4 = new QTableWidgetItem;
        if(!Account.value("gameextrainfo").toString().isEmpty()){
            item4->setText(SLLanguage[8]);
            item4->setTextColor(QColor("#89b753"));
        } else
            switch (Account.value("personastate").toInt()) {
            case 0:{
                    item4->setText(SLLanguage[9]);
                    item4->setTextColor(QColor("#4c4d4f"));
                    break;
            }
            case 1:{
                    item4->setText(SLLanguage[10]);
                    item4->setTextColor(QColor("#57cbde"));
                    break;
            }
            case 2:{
                    item4->setText(SLLanguage[11]);
                    item4->setTextColor(QColor("#815560"));
                    break;
            }
            case 3:{
                    item4->setText(SLLanguage[12]);
                    item4->setTextColor(QColor("#46788e"));
                    break;
            }
            case 4:{
                    item4->setText(SLLanguage[13]);
                    item4->setTextColor(QColor("#46788e"));
                    break;
            }
            case 5:{
                    item4->setText(SLLanguage[14]);
                    item4->setTextColor(Qt::darkMagenta);
                    break;
            }
            case 6:{
                    item4->setText(SLLanguage[15]);
                    item4->setTextColor(Qt::darkMagenta);
                    break;
            }
            }
        ui->FormFriendsTWFriends->setItem(i,3,item4);
        QTableWidgetItem *item5 = new QTableWidgetItem;
        switch(Account.value("communityvisibilitystate").toInt()){
        case 1:{
            item5->setText(SLLanguage[17]);
            item5->setTextColor(Qt::red);
            break;
        }
        case 2:{
            item5->setText(SLLanguage[17]);
            item5->setTextColor(Qt::red);
            break;
        }
        case 3:{
            item5->setText(SLLanguage[16]);
            item5->setTextColor(Qt::green);
            break;
        }
        }
        ui->FormFriendsTWFriends->setItem(i,4,item5);
        QTableWidgetItem *item6 = new QTableWidgetItem(Account.value("steamid").toString());
        ui->FormFriendsTWFriends->setItem(i,5,item6);
        QPushButton *button1 = new QPushButton;
        button1->setText(SLLanguage[7]);
        switch (Theme) {
        case 1:{
            button1->setIcon(QIcon("images/program/go_to_white.png"));
            break;
        }
        case 2:{
            button1->setIcon(QIcon("images/program/go_to_black.png"));
            break;
        }
        }
        button1->setMinimumSize(QSize(25,25));
        button1->setObjectName("btn"+Account.value("steamid").toString());
        connect(button1,SIGNAL(pressed()),this,SLOT(GoToProfileClicked()));
        ui->FormFriendsTWFriends->setCellWidget(i,6,button1);
        QPushButton *button2 = new QPushButton;
        button2->setIcon(favorites);
        connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
        button2->setObjectName("btnf"+Account.value("steamid").toString());
        ui->FormFriendsTWFriends->setCellWidget(i,7,button2);
    }
    ui->FormFriendsTWFriends->setColumnHidden(5,true);
    ui->FormFriendsTWFriends->resizeColumnsToContents();
    ui->FormFriendsTWFriends->setColumnWidth(0,33);

    filter = new bool*[ui->FormFriendsTWFriends->rowCount()];
    for (int i=0;i<ui->FormFriendsTWFriends->rowCount();i++) {
        filter[i]=new bool[4];
        for (int j=0;j<4;j++) {
            filter[i][j]=true;
            }
        }
    ui->FormFriendsLineEditName->setFocus();
}

FormFriends::~FormFriends()
{
    delete ui;
}
void FormFriends::closeEvent(QCloseEvent *){
    emit return_to_profile(this);
    //delete this;
}
void FormFriends::on_FormFriendsBReturn_clicked(){
    emit return_to_profile(this);
    //delete this;
}

void FormFriends::OnResultImage(int i, QString Save, ImageRequest *imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    if(!Save.isEmpty()){
        pixmap.save("images/profiles/"+Save+".png", "PNG");
    }
    ui->FormFriendsTWFriends->setCellWidget(i,0,label);
    ui->FormFriendsTWFriends->resizeRowToContents(i);
    imgr->deleteLater();
}

void FormFriends::GoToProfileClicked(){
    if(windowchildcount==0){
        windowchildcount++;
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        emit go_to_profile(btn->objectName().mid(3,btn->objectName().length()));
        on_FormFriendsBReturn_clicked();
    }
}
void FormFriends::FavoritesClicked(){

}

void FormFriends::on_FormFriendsChBOpenProfile_stateChanged(int arg1){
    if(arg1==2){
        for (int i=0;i<ui->FormFriendsTWFriends->rowCount();i++)
            if(ui->FormFriendsTWFriends->item(i,4)->text().indexOf(SLLanguage[16])>-1)
                filter[i][2]=true; else
                filter[i][2]=false;
        UpdateHiddenRows();
        } else {
        for (int i=0;i<ui->FormFriendsTWFriends->rowCount();i++)
            filter[i][2]=true;
        UpdateHiddenRows();
        }
}
void FormFriends::on_FormFriendsCBStatus_activated(int index){
    if(index!=0){
        for (int i=0;i<ui->FormFriendsTWFriends->rowCount();i++)
            if(ui->FormFriendsCBStatus->currentText()==ui->FormFriendsTWFriends->item(i,3)->text())
                filter[i][1]=true; else
                filter[i][1]=false;
        UpdateHiddenRows();
        } else {
        for (int i=0;i<ui->FormFriendsTWFriends->rowCount();i++)
            filter[i][1]=true;
        UpdateHiddenRows();
        }
}
void FormFriends::on_FormFriendsLineEditName_textChanged(const QString &){
    for (int i=0;i<ui->FormFriendsTWFriends->rowCount();i++)
        if(ui->FormFriendsTWFriends->item(i,1)->text().toLower().indexOf(ui->FormFriendsLineEditName->text().toLower())>-1)
            filter[i][0]=true; else
            filter[i][0]=false;
    UpdateHiddenRows();
}
void FormFriends::on_FormFriendsBFind_clicked(){
    on_FormFriendsLineEditName_textChanged(ui->FormFriendsLineEditName->text());
}
void FormFriends::UpdateHiddenRows(){
    for (int i=0;i<ui->FormFriendsTWFriends->rowCount();i++) {
        bool accept=true;
        for (int j=0;j<4;j++) {
            if(filter[i][j]==false){
                accept=false;
                break;
                }
            }
        if(accept){
            ui->FormFriendsTWFriends->setRowHidden(i,false);
            } else
            ui->FormFriendsTWFriends->setRowHidden(i,true);
        }
}
