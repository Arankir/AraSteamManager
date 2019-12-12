#include "formfriends.h"
#include "ui_formfriends.h"

FormFriends::FormFriends(QString ids, QString keys, SFriends friendss, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormFriends){
    ui->setupUi(this);
    id=ids;
    key=keys;
    friends=friendss;
    SProfile profiles = friends.GetProfiles();
    for(int i=0;i<profiles.GetCount();i++) {
        profiless.push_back(profiles.GetProfile(i));
    }
    switch(setting.GetTheme()){
    case 1:{
        theme="white";
        break;
        }
    case 2:{
        theme="black";
        break;
        }
    }
    InitComponents();
    ui->LineEditName->setFocus();
}

#define Init {
void FormFriends::InitComponents(){
    favorites.SetPath("Files/Favorites/Friends.json","Friends");
    ui->TableWidgetFriends->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("Ник")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("Добавлен")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(3,new QTableWidgetItem(tr("Статус")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(4,new QTableWidgetItem(tr("Профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(5,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(6,new QTableWidgetItem(tr("На профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(7,new QTableWidgetItem(tr("Избранное")));
    ui->ComboBoxStatus->addItems(QStringList()<<tr("Статус")<<tr("В игре")<<tr("Не в сети")<<tr("В сети")<<tr("Не беспокоить")<<tr("Нет на месте")<<tr("Спит")<<tr("Ожидает обмена")<<tr("Хочет поиграть"));
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setRowCount(friends.GetCount());
    ui->ButtonFind->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(:/"+theme+"/program/"+theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->TableWidgetFriends->setColumnHidden(5,true);
    ui->TableWidgetFriends->setColumnWidth(0,33);
    for (int i=0; i < profiless.size()-1; i++) {
        for (int j=0; j < profiless.size()-i-1; j++) {
            if (profiless[j].GetPersonaname() > profiless[j+1].GetPersonaname()) {
                SProfile temp = profiless[j];
                profiless[j] = profiless[j+1];
                profiless[j+1] = temp;
            }
        }
    }
    filter.SetRow(friends.GetCount());
    filter.SetCol(4);
    Threading LoadTable(this);
    LoadTable.AddThreadFriends(ui->TableWidgetFriends,profiless,friends);
}
void FormFriends::ProgressLoading(int p,int row){
    QPushButton *button1 = new QPushButton(tr("На профиль"));
    button1->setIcon(QIcon(":/"+theme+"/program/"+theme+"/go_to.png"));
    button1->setMinimumSize(QSize(25,25));
    button1->setObjectName("btn"+profiless[p].GetSteamid());
    connect(button1,&QPushButton::pressed,this,&FormFriends::GoToProfileClicked);
    ui->TableWidgetFriends->setCellWidget(row,6,button1);

    QPushButton *button2 = new QPushButton;
    button2->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
    connect(button2,&QPushButton::pressed,this,&FormFriends::FavoritesClicked);
    button2->setObjectName("btnf"+QString::number(row));
    ui->TableWidgetFriends->setCellWidget(row,7,button2);
    ui->TableWidgetFriends->setRowHeight(row,33);
}
void FormFriends::OnFinish(){
    ui->TableWidgetFriends->resizeColumnsToContents();
    for (int i=0;i<friends.GetCount();i++) {
        QString path = "images/profiles/"+profiless[i].GetAvatar().mid(72,20)+".jpg";
        if(!QFile::exists(path)){
            if(numrequests<500){
                ImageRequest *image = new ImageRequest(profiless[i].GetAvatar(),i,path,true);
                connect(image,&ImageRequest::onReady,this,&FormFriends::OnResultImage);
                request.append(image);
                numrequests++;
                numnow++;
                }
            } else {
                QPixmap pixmap;
                pixmap.load(path);
                QLabel *label = new QLabel;
                label->setPixmap(pixmap);
                ui->TableWidgetFriends->setCellWidget(i,0,label);
            }
        }
}
void FormFriends::OnResultImage(ImageRequest *imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetFriends->setCellWidget(imgr->GetRow(),0,label);
    if(numrequests==500&&numnow<friends.GetCount()){
        imgr->LoadImage(profiless[numnow].GetAvatar(),numnow,"images/profiles/"+profiless[numnow].GetAvatar().mid(72,20)+".jpg",true);
        numnow++;
    } else {
        disconnect(imgr,&ImageRequest::onReady,this,&FormFriends::OnResultImage);
        imgr->deleteLater();
    }
}
#define InitEnd }

#define System {
FormFriends::~FormFriends(){
    for (int i=0;i<=numrequests;i++) {
        //request[numrequests];
    }
    delete ui;
}
void FormFriends::closeEvent(QCloseEvent*){
    emit return_to_profile();
    //delete this;
}
void FormFriends::on_ButtonReturn_clicked(){
    emit return_to_profile();
    //delete this;
}
#define SystemEnd }

#define Filter {
void FormFriends::on_CheckBoxOpenProfile_stateChanged(int arg1){
    if(arg1==2){
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            filter.SetData(i,2,ui->TableWidgetFriends->item(i,4)->text().indexOf(tr("Публичный"))>-1);
        } else {
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            filter.SetData(i,2,true);
        }
    UpdateHiddenRows();
}
void FormFriends::on_ComboBoxStatus_activated(int index){
    if(index!=0){
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            filter.SetData(i,1,ui->ComboBoxStatus->currentText()==ui->TableWidgetFriends->item(i,3)->text());
        } else {
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            filter.SetData(i,1,true);
        }
    UpdateHiddenRows();
}
void FormFriends::on_LineEditName_textChanged(const QString &){
    for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
        filter.SetData(i,0,ui->TableWidgetFriends->item(i,1)->text().toLower().indexOf(ui->LineEditName->text().toLower())>-1);
    UpdateHiddenRows();
}
void FormFriends::on_ButtonFind_clicked(){
    on_LineEditName_textChanged(ui->LineEditName->text());
}
void FormFriends::UpdateHiddenRows(){
    for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
        ui->TableWidgetFriends->setRowHidden(i,!filter.GetData(i));
}
void FormFriends::on_CheckBoxFavorites_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            filter.SetData(i,3,true);
        break;
    }
    case 2:{
        QJsonArray val=favorites.GetValues();
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++){
            bool accept=false;
            for (int j=0;j<val.size();j++) {
                if(val[j].toObject().value("id").toString()==profiless[i].GetSteamid()){
                    accept=true;
                    break;
                }
            }
            filter.SetData(i,3,accept);
        }
        break;
    }
    }
    UpdateHiddenRows();
}
#define FilterEnd }

#define Functions {
void FormFriends::GoToProfileClicked(){
    if(windowchildcount==0){
        //disconnect(sender(),SIGNAL(pressed()),this,SLOT(GoToProfileClicked()));
        windowchildcount++;
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        emit go_to_profile(btn->objectName().mid(3,btn->objectName().length()),"url",true);
        emit return_to_profile();
    }
}
void FormFriends::FavoritesClicked(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    int index=btn->objectName().mid(4).toInt();
    QJsonObject newValue;
    newValue["id"]=profiless[index].GetSteamid();
    newValue["name"]=profiless[index].GetPersonaname();
    newValue["added"]=friends.GetFriend_since(index).toString("yyyy.MM.dd hh:mm:ss");
    if(favorites.AddValue(newValue,true)){
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}
#define FunctionsEnd }
