#include "formfavorites.h"
#include "ui_formfavorites.h"
#define Constants {
const int c_tableFriendsColumnID=0;
const int c_tableFriendsColumnIcon=1;
const int c_tableFriendsColumnName=2;
const int c_tableFriendsColumnStatus=3;
const int c_tableFriendsColumnisPublic=4;
const int c_tableFriendsColumnGoTo=5;
const int c_tableFriendsColumnFavorite=6;
const int c_tableFriendsColumnCount=7;

//const int c_filterName=0;
//const int c_filterStatus=1;
//const int c_filterPublic=2;
//const int c_filterFavorites=3;
//const int c_filterCount=4;
#define ConstantsEnd }

FormFavorites::FormFavorites(QWidget *parent): QWidget(parent), ui(new Ui::FormFavorites){
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    InitComponents();
}

FormFavorites::~FormFavorites(){
    delete ui;
}
void FormFavorites::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        ui->retranslateUi(this);
    }
}

void FormFavorites::InitComponents(){
    _games.SetPath("games");
    _friends.SetPath("friends");
    _achievements.SetPath("achievements");
    QJsonArray gamesJ=_games.GetValues();
    QJsonArray friendsJ=_friends.GetValues();
    QJsonArray achievementsJ=_achievements.GetValues();
    //сделать отдельным потоком
    for (int i=0;i<gamesJ.size();i++) {
        //
    }
    ui->TableWidgetFriends->setColumnCount(c_tableFriendsColumnCount);
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnID,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnIcon,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnName,new QTableWidgetItem(tr("Ник")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnStatus,new QTableWidgetItem(tr("Статус")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnisPublic,new QTableWidgetItem(tr("Профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnGoTo,new QTableWidgetItem(tr("На профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnFavorite,new QTableWidgetItem(tr("Избранное")));
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setColumnHidden(c_tableFriendsColumnID,true);
    ui->TableWidgetFriends->setColumnWidth(c_tableFriendsColumnIcon,33);
    ui->TableWidgetFriends->setRowCount(friendsJ.size());
    foreach (QJsonValue frien, friendsJ) {
        SProfile *Profiles = new SProfile(frien.toObject().value("id").toString(),true,QueryType::url);
        connect(Profiles,SIGNAL(s_finished(SProfile*)),this,SLOT(FriendLoad(SProfile*)));
    }
    for (int i=0;i<achievementsJ.size();i++) {
        //
    }
}

void FormFavorites::FriendLoad(SProfile *a_profile){
    QString path = _setting._pathImagesProfiles+a_profile->GetAvatar().mid(72,20)+".jpg";
    if(!QFile::exists(path)){
        if(_numRequests<500){
            RequestData *image = new RequestData(a_profile->GetAvatar(),_numRequests,path,true);
            connect(image,&RequestData::s_finished,this,&FormFavorites::OnImageLoad);
            _request.append(image);
            //numrequests++;
            _numNow++;
            }
        } else {
            QLabel *avatarFriend = new QLabel;
            avatarFriend->setPixmap(QPixmap(path));
            ui->TableWidgetFriends->setCellWidget(_numRequests,c_tableFriendsColumnIcon,avatarFriend);
        }
    QTableWidgetItem *item4 = new QTableWidgetItem;
    if(!a_profile->GetGameextrainfo().isEmpty()){
        item4->setText(tr("В игре"));
        item4->setTextColor(QColor("#89b753"));
    } else
        switch (a_profile->GetPersonastate()){
            case 0:
                    item4->setText(tr("Не в сети"));
                    item4->setTextColor(QColor("#4c4d4f"));
                    break;
            case 1:
                    item4->setText(tr("В сети"));
                    item4->setTextColor(QColor("#57cbde"));
                    break;
            case 2:
                    item4->setText(tr("Не беспокоить"));
                    item4->setTextColor(QColor("#815560"));
                    break;
            case 3:
                    item4->setText(tr("Нет на месте"));
                    item4->setTextColor(QColor("#46788e"));
                    break;
            case 4:
                    item4->setText(tr("Спит"));
                    item4->setTextColor(QColor("#46788e"));
                    break;
            case 5:
                    item4->setText(tr("Ожидает обмена"));
                    item4->setTextColor(Qt::darkMagenta);
                    break;
            case 6:
                    item4->setText(tr("Хочет поиграть"));
                    item4->setTextColor(Qt::darkMagenta);
                    break;
        }
    QTableWidgetItem *item5 = new QTableWidgetItem;
    switch(a_profile->GetCommunityvisibilitystate()){
        case 1:
            item5->setText(tr("Скрытый"));
            item5->setTextColor(QColor("#6e0e0e"));
            break;
        case 2:
            item5->setText(tr("Скрытый"));
            item5->setTextColor(QColor("#6e0e0e"));
            break;
        case 3:
            item5->setText(tr("Публичный"));
            item5->setTextColor(QColor("#0e6e11"));
            break;
        case 8:
            item5->setText(tr("Скрытый"));
            item5->setTextColor(QColor("#6e0e0e"));
            break;
    }
    ui->TableWidgetFriends->setItem(_numRequests,c_tableFriendsColumnID,new QTableWidgetItem(a_profile->GetSteamid()));
    ui->TableWidgetFriends->setItem(_numRequests,c_tableFriendsColumnName,new QTableWidgetItem(a_profile->GetPersonaname()));
    ui->TableWidgetFriends->setItem(_numRequests,c_tableFriendsColumnStatus,item4);
    ui->TableWidgetFriends->setItem(_numRequests,c_tableFriendsColumnisPublic,item5);
    _numRequests++;
}

void FormFavorites::OnImageLoad(RequestData* a_image){
    QPixmap pixmap;
    pixmap.loadFromData(a_image->GetAnswer());
    QLabel *avatarFriend = new QLabel;
    avatarFriend->setPixmap(pixmap);
    ui->TableWidgetFriends->setCellWidget(a_image->GetRow(),c_tableFriendsColumnIcon,avatarFriend);
    disconnect(a_image,&RequestData::s_finished,this,&FormFavorites::OnImageLoad);
    a_image->deleteLater();
}

void FormFavorites::on_pushButton_clicked(){
    ui->label->setStyleSheet("color: rgb("+ui->lineEdit->text()+");");
    ui->label_2->setStyleSheet("color: rgb("+ui->lineEdit->text()+");");
}
