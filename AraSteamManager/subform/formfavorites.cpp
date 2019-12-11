#include "formfavorites.h"
#include "ui_formfavorites.h"

FormFavorites::FormFavorites(QString key, QWidget *parent): QWidget(parent), ui(new Ui::FormFavorites){
    ui->setupUi(this);
    this->key=key;
    numrequests=0;
    numnow=0;
    InitComponents();
}

FormFavorites::~FormFavorites(){
    delete ui;
}

void FormFavorites::InitComponents(){
    games.SetPath("Files/Favorites/Games.json","Games");
    friends.SetPath("Files/Favorites/Friends.json","Friends");
    achievements.SetPath("Files/Favorites/Achievements.json","Achievements");
    QJsonArray gamesJ=games.GetValues();
    QJsonArray friendsJ=friends.GetValues();
    QJsonArray achievementsJ=achievements.GetValues();
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
    for (int i=0;i<friendsJ.size();i++) {
        SProfile *Profiles = new SProfile(key,friendsJ[i].toObject().value("id").toString(),true,"url");
        connect(Profiles,SIGNAL(finished(SProfile*)),this,SLOT(FriendLoad(SProfile*)));
    }
    for (int i=0;i<achievementsJ.size();i++) {
        //
    }
}

void FormFavorites::FriendLoad(SProfile *pro){
    QString path = "images/profiles/"+pro->GetAvatar().mid(72,20)+".jpg";
    if(!QFile::exists(path)){
        if(numrequests<500){
            ImageRequest *image = new ImageRequest(pro->GetAvatar(),numrequests,path,true);
            connect(image,&ImageRequest::onReady,this,&FormFavorites::OnResultImage);
            request.append(image);
            //numrequests++;
            numnow++;
            }
        } else {
            QPixmap pixmap;
            pixmap.load(path);
            QLabel *label = new QLabel;
            label->setPixmap(pixmap);
            ui->TableWidgetFriends->setCellWidget(numrequests,0,label);
        }
    QTableWidgetItem *item4 = new QTableWidgetItem;
    if(!pro->GetGameextrainfo().isEmpty()){
        item4->setText(tr("В игре"));
        item4->setTextColor(QColor("#89b753"));
    } else
        switch (pro->GetPersonastate()){
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
    switch(pro->GetCommunityvisibilitystate()){
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
    ui->TableWidgetFriends->setItem(numrequests,1,new QTableWidgetItem(pro->GetPersonaname()));
    ui->TableWidgetFriends->setItem(numrequests,2,item4);
    ui->TableWidgetFriends->setItem(numrequests,3,item5);
    ui->TableWidgetFriends->setItem(numrequests,4,new QTableWidgetItem(pro->GetSteamid()));
    numrequests++;
}

void FormFavorites::OnResultImage(ImageRequest* imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetFriends->setCellWidget(imgr->GetRow(),0,label);
    disconnect(imgr,&ImageRequest::onReady,this,&FormFavorites::OnResultImage);
    imgr->deleteLater();
}

void FormFavorites::on_pushButton_clicked(){
    ui->label->setStyleSheet("color: rgb("+ui->lineEdit->text()+");");
    ui->label_2->setStyleSheet("color: rgb("+ui->lineEdit->text()+");");
}
