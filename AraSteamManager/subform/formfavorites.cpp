#include "formfavorites.h"
#include "ui_formfavorites.h"

FormFavorites::FormFavorites(QString AKey, QWidget *parent): QWidget(parent), ui(new Ui::FormFavorites){
    ui->setupUi(this);
    _key=AKey;
    InitComponents();
}

FormFavorites::~FormFavorites(){
    delete ui;
}

void FormFavorites::InitComponents(){
    _games.SetPath("Files/Favorites/Games.json","Games");
    _friends.SetPath("Files/Favorites/Friends.json","Friends");
    _achievements.SetPath("Files/Favorites/Achievements.json","Achievements");
    QJsonArray gamesJ=_games.GetValues();
    QJsonArray friendsJ=_friends.GetValues();
    QJsonArray achievementsJ=_achievements.GetValues();
    //сделать отдельным потоком
    for (int i=0;i<gamesJ.size();i++) {
        //
    }
    ui->TableWidgetFriends->setColumnCount(7);
    ui->TableWidgetFriends->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("Ник")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("Статус")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(3,new QTableWidgetItem(tr("Профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(4,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(5,new QTableWidgetItem(tr("На профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(6,new QTableWidgetItem(tr("Избранное")));
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setColumnHidden(4,true);
    ui->TableWidgetFriends->setColumnWidth(0,33);
    ui->TableWidgetFriends->setRowCount(friendsJ.size());
    foreach (QJsonValue frien, friendsJ) {
        SProfile *Profiles = new SProfile(_key,frien.toObject().value("id").toString(),true,"url");
        connect(Profiles,SIGNAL(s_finished(SProfile*)),this,SLOT(FriendLoad(SProfile*)));
    }
    for (int i=0;i<achievementsJ.size();i++) {
        //
    }
}

void FormFavorites::FriendLoad(SProfile *AProfile){
    QString path = "images/profiles/"+AProfile->GetAvatar().mid(72,20)+".jpg";
    if(!QFile::exists(path)){
        if(_numRequests<500){
            ImageRequest *image = new ImageRequest(AProfile->GetAvatar(),_numRequests,path,true);
            connect(image,&ImageRequest::s_finished,this,&FormFavorites::OnResultImage);
            _request.append(image);
            //numrequests++;
            _numNow++;
            }
        } else {
            QPixmap pixmap;
            pixmap.load(path);
            QLabel *label = new QLabel;
            label->setPixmap(pixmap);
            ui->TableWidgetFriends->setCellWidget(_numRequests,0,label);
        }
    QTableWidgetItem *item4 = new QTableWidgetItem;
    if(!AProfile->GetGameextrainfo().isEmpty()){
        item4->setText(tr("В игре"));
        item4->setTextColor(QColor("#89b753"));
    } else
        switch (AProfile->GetPersonastate()){
        case 0:{
                item4->setText(tr("Не в сети"));
                item4->setTextColor(QColor("#4c4d4f"));
                break;
        }
        case 1:{
                item4->setText(tr("В сети"));
                item4->setTextColor(QColor("#57cbde"));
                break;
        }
        case 2:{
                item4->setText(tr("Не беспокоить"));
                item4->setTextColor(QColor("#815560"));
                break;
        }
        case 3:{
                item4->setText(tr("Нет на месте"));
                item4->setTextColor(QColor("#46788e"));
                break;
        }
        case 4:{
                item4->setText(tr("Спит"));
                item4->setTextColor(QColor("#46788e"));
                break;
        }
        case 5:{
                item4->setText(tr("Ожидает обмена"));
                item4->setTextColor(Qt::darkMagenta);
                break;
        }
        case 6:{
                item4->setText(tr("Хочет поиграть"));
                item4->setTextColor(Qt::darkMagenta);
                break;
        }
        }
    QTableWidgetItem *item5 = new QTableWidgetItem;
    switch(AProfile->GetCommunityvisibilitystate()){
    case 1:{
        item5->setText(tr("Скрытый"));
        item5->setTextColor(Qt::red);
        break;
    }
    case 2:{
        item5->setText(tr("Скрытый"));
        item5->setTextColor(Qt::red);
        break;
    }
    case 3:{
        item5->setText(tr("Публичный"));
        item5->setTextColor(Qt::green);
        break;
    }
    case 8:{
        item5->setText(tr("Скрытый"));
        item5->setTextColor(Qt::red);
        break;
    }
    }
    ui->TableWidgetFriends->setItem(_numRequests,1,new QTableWidgetItem(AProfile->GetPersonaname()));
    ui->TableWidgetFriends->setItem(_numRequests,2,item4);
    ui->TableWidgetFriends->setItem(_numRequests,3,item5);
    ui->TableWidgetFriends->setItem(_numRequests,4,new QTableWidgetItem(AProfile->GetSteamid()));
    _numRequests++;
}

void FormFavorites::OnResultImage(ImageRequest* AImage){
    QPixmap pixmap;
    pixmap.loadFromData(AImage->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetFriends->setCellWidget(AImage->GetRow(),0,label);
    disconnect(AImage,&ImageRequest::s_finished,this,&FormFavorites::OnResultImage);
    AImage->deleteLater();
}

void FormFavorites::on_pushButton_clicked(){
    ui->label->setStyleSheet("color: rgb("+ui->lineEdit->text()+");");
    ui->label_2->setStyleSheet("color: rgb("+ui->lineEdit->text()+");");
}
