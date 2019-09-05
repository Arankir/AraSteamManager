#include "formfriends.h"
#include "ui_formfriends.h"

FormFriends::FormFriends(QString ids, QString keys, SteamAPIFriends Friendss, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormFriends){
    ui->setupUi(this);
    Words=Setting.GetWords("friends");
    id=ids;
    key=keys;
    Friends=Friendss;
    ui->LabelLogo->setText("(WIP)");
    ui->GroupBoxFilter->setTitle("      "+Words[0]);
    ui->ButtonReturn->setText(" "+Words[1]);
    ui->ButtonFind->setText("  "+Words[2]);
    ui->CheckBoxOpenProfile->setText(Words[3]);
    ui->CheckBoxFavorites->setText(Words[20]);
    ui->LineEditName->setPlaceholderText(Words[21]);
    ui->TableWidgetFriends->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(1,new QTableWidgetItem(Words[5]));
    ui->TableWidgetFriends->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[4]));
    ui->TableWidgetFriends->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[6]));
    ui->TableWidgetFriends->setHorizontalHeaderItem(4,new QTableWidgetItem(Words[18]));
    ui->TableWidgetFriends->setHorizontalHeaderItem(5,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(6,new QTableWidgetItem(Words[7]));
    ui->TableWidgetFriends->setHorizontalHeaderItem(7,new QTableWidgetItem(Words[19]));
    ui->ComboBoxStatus->addItem(Words[6]);
    ui->ComboBoxStatus->addItem(Words[8]);
    ui->ComboBoxStatus->addItem(Words[9]);
    ui->ComboBoxStatus->addItem(Words[10]);
    ui->ComboBoxStatus->addItem(Words[11]);
    ui->ComboBoxStatus->addItem(Words[12]);
    ui->ComboBoxStatus->addItem(Words[13]);
    ui->ComboBoxStatus->addItem(Words[14]);
    ui->ComboBoxStatus->addItem(Words[15]);
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    switch(Setting.GetTheme()){
    case 1:{
        theme="white";
        break;
        }
    case 2:{
        theme="black";
        break;
        }
    }
    ui->ButtonReturn->setIcon(QIcon(":/"+theme+"/program/"+theme+"/back.png"));
    ui->ButtonFind->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(:/"+theme+"/program/"+theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
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
        ui->TableWidgetFriends->insertRow(i);
        if(!QFile::exists("images/profiles/"+Profiles[i].GetAvatar().mid(72,20).remove(".jpg")+".png")){
            ImageRequest *image;
            switch (Setting.GetSaveimages()) {
                case 0:{
                    image = new ImageRequest(i,"");
                    break;
                    }
                case 1:{
                    image = new ImageRequest(i,Profiles[i].GetAvatar().mid(72,20).remove(".jpg"));
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
            pixmap.load("images/profiles/"+Profiles[i].GetAvatar().mid(72,20).remove(".jpg")+".png", "PNG");
            QLabel *lb = new QLabel();
            lb->setPixmap(pixmap);
            ui->TableWidgetFriends->setCellWidget(i,0,lb);
            }
        QTableWidgetItem *item2 = new QTableWidgetItem(Profiles[i].GetPersonaname());
        ui->TableWidgetFriends->setItem(i,1,item2);
        QDateTime date;
        for (int j=0;;j++) {
            if(Profiles[i].GetSteamid()==Friends.GetSteamid(j)){
                date=Friends.GetFriend_since(j);
                break;
            }
        }
        QTableWidgetItem *item3 = new QTableWidgetItem(date.toString("yyyy.MM.dd hh:mm:ss"));
        ui->TableWidgetFriends->setItem(i,2,item3);
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
        ui->TableWidgetFriends->setItem(i,3,item4);
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
        ui->TableWidgetFriends->setItem(i,4,item5);
        QTableWidgetItem *item6 = new QTableWidgetItem(Profiles[i].GetSteamid());
        ui->TableWidgetFriends->setItem(i,5,item6);
        QPushButton *button1 = new QPushButton;
        button1->setText(Words[7]);
        button1->setIcon(QIcon(":/"+theme+"/program/"+theme+"/go_to.png"));
        button1->setMinimumSize(QSize(25,25));
        button1->setObjectName("btn"+Profiles[i].GetSteamid());
        connect(button1,SIGNAL(pressed()),this,SLOT(GoToProfileClicked()));
        ui->TableWidgetFriends->setCellWidget(i,6,button1);
        QPushButton *button2 = new QPushButton;
        button2->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
        connect(button2,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
        button2->setObjectName("btnf"+Profiles[i].GetSteamid());
        ui->TableWidgetFriends->setCellWidget(i,7,button2);
    }
    ui->TableWidgetFriends->setColumnHidden(5,true);
    ui->TableWidgetFriends->resizeColumnsToContents();
    ui->TableWidgetFriends->setColumnWidth(0,33);

    filter = new bool*[ui->TableWidgetFriends->rowCount()];
    for (int i=0;i<ui->TableWidgetFriends->rowCount();i++) {
        filter[i]=new bool[4];
        for (int j=0;j<4;j++) {
            filter[i][j]=true;
            }
        }
    ui->LineEditName->setFocus();
}

FormFriends::~FormFriends()
{
    delete ui;
}
void FormFriends::closeEvent(QCloseEvent *){
    emit return_to_profile(this);
    //delete this;
}
void FormFriends::on_ButtonReturn_clicked(){
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
    ui->TableWidgetFriends->setCellWidget(i,0,label);
    ui->TableWidgetFriends->resizeRowToContents(i);
    imgr->deleteLater();
}

void FormFriends::GoToProfileClicked(){
    if(windowchildcount==0){
        windowchildcount++;
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        emit go_to_profile(btn->objectName().mid(3,btn->objectName().length()));
        on_ButtonReturn_clicked();
    }
}
void FormFriends::FavoritesClicked(){

}

void FormFriends::on_CheckBoxOpenProfile_stateChanged(int arg1){
    if(arg1==2){
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            if(ui->TableWidgetFriends->item(i,4)->text().indexOf(Words[16])>-1)
                filter[i][2]=true; else
                filter[i][2]=false;
        UpdateHiddenRows();
        } else {
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            filter[i][2]=true;
        UpdateHiddenRows();
        }
}
void FormFriends::on_ComboBoxStatus_activated(int index){
    if(index!=0){
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            if(ui->ComboBoxStatus->currentText()==ui->TableWidgetFriends->item(i,3)->text())
                filter[i][1]=true; else
                filter[i][1]=false;
        UpdateHiddenRows();
        } else {
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            filter[i][1]=true;
        UpdateHiddenRows();
        }
}
void FormFriends::on_LineEditName_textChanged(const QString &){
    for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
        if(ui->TableWidgetFriends->item(i,1)->text().toLower().indexOf(ui->LineEditName->text().toLower())>-1)
            filter[i][0]=true; else
            filter[i][0]=false;
    UpdateHiddenRows();
}
void FormFriends::on_ButtonFind_clicked(){
    on_LineEditName_textChanged(ui->LineEditName->text());
}
void FormFriends::UpdateHiddenRows(){
    for (int i=0;i<ui->TableWidgetFriends->rowCount();i++) {
        bool accept=true;
        for (int j=0;j<4;j++) {
            if(filter[i][j]==false){
                accept=false;
                break;
                }
            }
        if(accept){
            ui->TableWidgetFriends->setRowHidden(i,false);
            } else
            ui->TableWidgetFriends->setRowHidden(i,true);
        }
}
