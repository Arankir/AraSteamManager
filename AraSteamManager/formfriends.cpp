#include "formfriends.h"
#include "ui_formfriends.h"

FormFriends::FormFriends(QString ids, QString keys, SteamAPIFriends Friendss, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormFriends){
    ui->setupUi(this);
    id=ids;
    key=keys;
    Friends=Friendss;
    ui->FormFriendsTWFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(Setting.GetStatus()=="success"){
        Language lan;
        Words=lan.GetLanguage("friends",Setting.GetLanguage());
    }
    QIcon favorites;
    switch(Setting.GetTheme()){
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
    ui->FormFriendsGBFilter->setTitle("      "+Words[0]);
    ui->FormFriendsBReturn->setText(" "+Words[1]);
    ui->FormFriendsBFind->setText("  "+Words[2]);
    ui->FormFriendsChBOpenProfile->setText(Words[3]);
    ui->FormFriendsChBFavorites->setText(Words[20]);
    ui->FormFriendsLineEditName->setPlaceholderText(Words[21]);
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(1,new QTableWidgetItem(Words[5]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[4]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[6]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(4,new QTableWidgetItem(Words[18]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(5,new QTableWidgetItem(""));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(6,new QTableWidgetItem(Words[7]));
    ui->FormFriendsTWFriends->setHorizontalHeaderItem(7,new QTableWidgetItem(Words[19]));
    ui->FormFriendsCBStatus->addItem(Words[6]);
    ui->FormFriendsCBStatus->addItem(Words[8]);
    ui->FormFriendsCBStatus->addItem(Words[9]);
    ui->FormFriendsCBStatus->addItem(Words[10]);
    ui->FormFriendsCBStatus->addItem(Words[11]);
    ui->FormFriendsCBStatus->addItem(Words[12]);
    ui->FormFriendsCBStatus->addItem(Words[13]);
    ui->FormFriendsCBStatus->addItem(Words[14]);
    ui->FormFriendsCBStatus->addItem(Words[15]);
    QVector<SteamAPIProfile> Profiles = Friends.GetProfiles();
    for (int i=0; i < Profiles.size()-1; i++) {
        for (int j=0; j < Profiles.size()-i-1; j++) {
            if (Profiles[j].GetPersonaname() > Profiles[j+1].GetPersonaname()) {
                SteamAPIProfile temp = Profiles[j];
                Profiles[j] = Profiles[j+1];
                Profiles[j+1] = temp;
            }
        }
    }
    for (int i=0;i<Friends.GetFriendsCount();i++) {
        ui->FormFriendsTWFriends->insertRow(i);
        if(!QFile::exists("images/profiles/"+Profiles[i].GetAvatar().mid(72,Profiles[i].GetAvatar().indexOf(".jpg",0)-72)+".png")){
            ImageRequest *image;
            switch (Setting.GetSaveimages()) {
                case 0:{
                    image = new ImageRequest(i,"");
                    break;
                    }
                case 1:{
                    image = new ImageRequest(i,Profiles[i].GetAvatar().mid(72,Profiles[i].GetAvatar().indexOf(".jpg",0)-72));
                    break;
                    }
                default:{
                    image = new ImageRequest(i,"");
                    break;
                    }
            }
            connect(image,SIGNAL(onReady(int, QString, ImageRequest *)),this,SLOT(OnResultImage(int, QString, ImageRequest *)));
            image->Get(Profiles[i].GetAvatar());
            } else {
            QPixmap pixmap;
            pixmap.load("images/profiles/"+Profiles[i].GetAvatar().mid(72,Profiles[i].GetAvatar().indexOf(".jpg",0)-72)+".png", "PNG");
            QLabel *lb = new QLabel();
            lb->setPixmap(pixmap);
            ui->FormFriendsTWFriends->setCellWidget(i,0,lb);
            }
        QTableWidgetItem *item2 = new QTableWidgetItem(Profiles[i].GetPersonaname());
        ui->FormFriendsTWFriends->setItem(i,1,item2);
        QDateTime date;
        for (int j=0;;j++) {
            if(Profiles[i].GetSteamid()==Friends.GetSteamid(j)){
                date=Friends.GetFriend_since(j);
                break;
            }
        }
        QTableWidgetItem *item3 = new QTableWidgetItem(date.toString("yyyy.MM.dd hh:mm:ss"));
        ui->FormFriendsTWFriends->setItem(i,2,item3);
        QTableWidgetItem *item4 = new QTableWidgetItem;
        if(!Profiles[i].GetGameextrainfo().isEmpty()){
            item4->setText(Words[8]);
            item4->setTextColor(QColor("#89b753"));
        } else
            switch (Profiles[i].GetPersonastate()){
            case 0:{
                    item4->setText(Words[9]);
                    item4->setTextColor(QColor("#4c4d4f"));
                    break;
            }
            case 1:{
                    item4->setText(Words[10]);
                    item4->setTextColor(QColor("#57cbde"));
                    break;
            }
            case 2:{
                    item4->setText(Words[11]);
                    item4->setTextColor(QColor("#815560"));
                    break;
            }
            case 3:{
                    item4->setText(Words[12]);
                    item4->setTextColor(QColor("#46788e"));
                    break;
            }
            case 4:{
                    item4->setText(Words[13]);
                    item4->setTextColor(QColor("#46788e"));
                    break;
            }
            case 5:{
                    item4->setText(Words[14]);
                    item4->setTextColor(Qt::darkMagenta);
                    break;
            }
            case 6:{
                    item4->setText(Words[15]);
                    item4->setTextColor(Qt::darkMagenta);
                    break;
            }
            }
        ui->FormFriendsTWFriends->setItem(i,3,item4);
        QTableWidgetItem *item5 = new QTableWidgetItem;
        switch(Profiles[i].GetCommunityvisibilitystate()){
        case 1:{
            item5->setText(Words[17]);
            item5->setTextColor(Qt::red);
            break;
        }
        case 2:{
            item5->setText(Words[17]);
            item5->setTextColor(Qt::red);
            break;
        }
        case 3:{
            item5->setText(Words[16]);
            item5->setTextColor(Qt::green);
            break;
        }
        case 8:{
            item5->setText(Words[17]);
            item5->setTextColor(Qt::red);
            break;
        }
        }
        ui->FormFriendsTWFriends->setItem(i,4,item5);
        QTableWidgetItem *item6 = new QTableWidgetItem(Profiles[i].GetSteamid());
        ui->FormFriendsTWFriends->setItem(i,5,item6);
        QPushButton *button1 = new QPushButton;
        button1->setText(Words[7]);
        switch (Setting.GetTheme()) {
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
        button1->setObjectName("btn"+Profiles[i].GetSteamid());
        connect(button1,SIGNAL(pressed()),this,SLOT(GoToProfileClicked()));
        ui->FormFriendsTWFriends->setCellWidget(i,6,button1);
        QPushButton *button2 = new QPushButton;
        button2->setIcon(favorites);
        connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
        button2->setObjectName("btnf"+Profiles[i].GetSteamid());
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
            if(ui->FormFriendsTWFriends->item(i,4)->text().indexOf(Words[16])>-1)
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
