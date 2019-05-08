#include "formfriends.h"
#include "ui_formfriends.h"

FormFriends::FormFriends(QString ids, QString keys, int languages, QJsonDocument DocFriendss, int SaveImagess, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFriends)
{
    ui->setupUi(this);
    id=ids;
    key=keys;
    language=languages;
    DocFriends=DocFriendss;
    SaveImages=SaveImagess;
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
            SLLanguage << QString::fromLocal8Bit(FileLanguage.readLine()).remove("\r\n");
        }
    }
    ui->FormFriendsLLogo->setText("");
    ui->FormFriendsGBFilter->setTitle(SLLanguage[0]);
    ui->FormFriendsBReturn->setText(SLLanguage[1]);
    ui->FormFriendsBFind->setText(SLLanguage[2]);
    ui->FormFriendsChBOpenProfile->setText(SLLanguage[3]);
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(1,new QTableWidgetItem(SLLanguage[5]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(2,new QTableWidgetItem(SLLanguage[4]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(3,new QTableWidgetItem(SLLanguage[6]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(4,new QTableWidgetItem(SLLanguage[18]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(5,new QTableWidgetItem(""));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(6,new QTableWidgetItem(SLLanguage[7]));
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
    for (int i=0;i<DocFriends.object().value("friendslist").toObject().value("friends").toArray().size();i++) {
        QJsonObject Account = Accounts[i].toObject();
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
        QPixmap pixmap;
        switch (SaveImages) {
        case 0:{
            QNetworkAccessManager imagemanager;
            QEventLoop imageloop;  //Ждем ответ от сервера.
            QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
            QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(Account.value("avatar").toString()));
            imageloop.exec();
            pixmap.loadFromData(imagereply.readAll());
            break;
        }
        case 1:{
            if(!QFile::exists("images/profiles/"+Account.value("avatar").toString().mid(72,Account.value("avatar").toString().indexOf(".jpg",0)-72)+".png")){
                QNetworkAccessManager imagemanager;
                QEventLoop imageloop;  //Ждем ответ от сервера.
                QObject::connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
                QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(Account.value("avatar").toString()));
                imageloop.exec();
                QImage img;
                img.loadFromData(imagereply.readAll());
                img.save("images/profiles/"+Account.value("avatar").toString().mid(72,Account.value("avatar").toString().indexOf(".jpg",0)-72)+".png", "PNG");
                pixmap=QPixmap::fromImage(img);
            } else {
                pixmap.load("images/profiles/"+Account.value("avatar").toString().mid(72,Account.value("avatar").toString().indexOf(".jpg",0)-72)+".png", "PNG");
                }
        }
        }
        QLabel *lb = new QLabel();
        lb->setPixmap(pixmap);
        ui->FormFriendsTWFriends->setCellWidget(i,0,lb);
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
        } else
            switch (Account.value("personastate").toInt()) {
            case 0:{
                    item4->setText(SLLanguage[9]);
                    break;
            }
            case 1:{
                    item4->setText(SLLanguage[10]);
                    break;
            }
            case 2:{
                    item4->setText(SLLanguage[11]);
                    break;
            }
            case 3:{
                    item4->setText(SLLanguage[12]);
                    break;
            }
            case 4:{
                    item4->setText(SLLanguage[13]);
                    break;
            }
            case 5:{
                    item4->setText(SLLanguage[14]);
                    break;
            }
            case 6:{
                    item4->setText(SLLanguage[15]);
                    break;
            }
            }
        ui->FormFriendsTWFriends->setItem(i,3,item4);
        QTableWidgetItem *item5 = new QTableWidgetItem;
        switch(Account.value("communityvisibilitystate").toInt()){
        case 1:{
            item5->setText(SLLanguage[17]);
            break;
        }
        case 3:{
            item5->setText(SLLanguage[16]);
        }
        }
        qDebug() <<Account.value("steamid")<<Account.value("communityvisibilitystate");
        ui->FormFriendsTWFriends->setItem(i,4,item5);
        QTableWidgetItem *item6 = new QTableWidgetItem(Account.value("steamid").toString());
        ui->FormFriendsTWFriends->setItem(i,5,item6);
        QPushButton *button1 = new QPushButton;
        button1->setText(SLLanguage[7]);
        button1->setMinimumSize(QSize(25,25));
        connect(button1,SIGNAL(pressed()),this,SLOT(GoToProfileClicked()));
        ui->FormFriendsTWFriends->setCellWidget(i,6,button1);
    }
    ui->FormFriendsTWFriends->setColumnHidden(5,true);
    ui->FormFriendsTWFriends->resizeColumnsToContents();
}

FormFriends::~FormFriends()
{
    delete ui;
}

void FormFriends::closeEvent(QCloseEvent *){
    on_FormFriendsBReturn_clicked();
}
void FormFriends::on_FormFriendsBReturn_clicked(){
    emit return_to_profile();
    delete this;
}

void FormFriends::GoToProfileClicked(){

}
