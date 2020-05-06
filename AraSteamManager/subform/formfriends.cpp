#include "formfriends.h"
#include "ui_formfriends.h"

#define Constants {
const int c_tableColumnID=0;
const int c_tableColumnIcon=1;
const int c_tableColumnName=2;
const int c_tableColumnAdded=3;
const int c_tableColumnStatus=4;
const int c_tableColumnisPublic=5;
const int c_tableColumnGoTo=6;
const int c_tableColumnFavorite=7;
const int c_tableColumnCount=6;

const int c_filterName=0;
const int c_filterStatus=1;
const int c_filterPublic=2;
const int c_filterFavorites=3;
const int c_filterCount=4;
#define ConstantsEnd }

#define Init {
FormFriends::FormFriends(QString a_id, SFriends a_friends, QWidget *parent) : QWidget(parent), ui(new Ui::FormFriends),_id(a_id),_friends(a_friends),_profiles(_friends.GetProfiles()){
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    switch(_setting.GetTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
    }
    InitComponents();
    ui->LineEditName->setFocus();
}
void FormFriends::InitComponents(){
    _favorites.SetType("friends");
    ui->TableWidgetFriends->setColumnCount(c_tableColumnCount);
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnID,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnIcon,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnName,new QTableWidgetItem(tr("Ник")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnAdded,new QTableWidgetItem(tr("Добавлен")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnStatus,new QTableWidgetItem(tr("Статус")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnisPublic,new QTableWidgetItem(tr("Профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnGoTo,new QTableWidgetItem(tr("На профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnFavorite,new QTableWidgetItem(tr("Избранное")));
    ui->ComboBoxStatus->addItems(QStringList()<<tr("Статус")<<tr("В игре")<<tr("Не в сети")<<tr("В сети")<<tr("Не беспокоить")<<tr("Нет на месте")<<tr("Спит")<<tr("Ожидает обмена")<<tr("Хочет поиграть"));
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->TableWidgetFriends->setAlternatingRowColors(true);
    //ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setRowCount(_friends.GetCount());
    ui->TableWidgetFriends->setColumnHidden(c_tableColumnID,true);
    ui->TableWidgetFriends->setColumnWidth(c_tableColumnIcon,33);
    _profiles.Sort();
    _filter.SetRow(_friends.GetCount());
    _filter.SetCol(c_filterCount);
    ui->ButtonFriendGoTo->setMinimumSize(QSize(25,25));
    ui->ButtonFriendFavorite->setMinimumSize(QSize(25,25));
#define Connects {
    connect(ui->TableWidgetFriends,&QTableWidget::cellClicked,this,&FormFriends::TableWidgetFriends_CellClicked);
    connect(ui->ButtonFriendGoTo,&QPushButton::clicked,this,&FormFriends::ButtonFriendGoTo_Clicked);
    connect(ui->ButtonFriendFavorite,&QPushButton::clicked,this,&FormFriends::ButtonFriendFavorite_Clicked);
#define ConnectsEnd }
#define Icons {
    ui->ButtonFind->setIcon(QIcon("://"+_theme+"/find_profile.png"));
    ui->ButtonFriendGoTo->setIcon(QIcon("://"+_theme+"/go_to.png"));
    ui->ButtonFriendFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
    ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(://"+_theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
#define IconsEnd }
    Threading loadTable(this);
    loadTable.AddThreadFriends(ui->TableWidgetFriends,_profiles,_friends);
}
void FormFriends::ProgressLoading(int a_progress,int a_row){
//    QButtonWithData *button1 = new QButtonWithData(tr(" На профиль"));
//    button1->setIcon(QIcon("://"+_theme+"/go_to.png"));
//    button1->setMinimumSize(QSize(25,25));
//    button1->setObjectName("ButtonGoToProfile"+_profiles[a_progress].GetSteamid());
//    button1->AddData("ProfileID",_profiles[a_progress].GetSteamid());
//    connect(button1,&QButtonWithData::pressed,this,&FormFriends::GoToProfileClicked);
//    ui->TableWidgetFriends->setCellWidget(a_row,c_tableColumnGoTo,button1);

//    QButtonWithData *button2 = new QButtonWithData("");
//    button2->setIcon(QIcon("://"+_theme+"/favorites.png"));
//    button2->setObjectName("ButtonFavorites"+QString::number(a_progress));
//    button2->AddData("NumberFriend",QString::number(a_row));
//    connect(button2,&QButtonWithData::pressed,this,&FormFriends::FavoritesClicked);
//    ui->TableWidgetFriends->setCellWidget(a_row,c_tableColumnFavorite,button2);
    ui->TableWidgetFriends->setRowHeight(a_row,33);
}
void FormFriends::OnFinish(){
    ui->TableWidgetFriends->resizeColumnsToContents();
    for (int i=0;i<_friends.GetCount();i++) {
        QString path = _setting._pathImagesProfiles+_profiles[i].GetAvatar().mid(72,20)+".jpg";
        QLabel *avatarFriend = new QLabel;
        ui->TableWidgetFriends->setCellWidget(i,c_tableColumnIcon,avatarFriend);
        if(!QFile::exists(path)){
                avatarFriend->setBaseSize(QSize(32,32));
                if(i==0)//не работает
                    connect(new RequestImage(avatarFriend,_profiles[i].GetAvatar(),path,true,this),&RequestImage::s_loadComplete,ui->TableWidgetFriends,[=](){TableWidgetFriends_CellClicked(0,0);});
                else
                    new RequestImage(avatarFriend,_profiles[i].GetAvatar(),path,true,this);
            } else {
                avatarFriend->setPixmap(QPixmap(path));
                if(i==0)
                    TableWidgetFriends_CellClicked(0,0);
            }
        }
}
#define InitEnd }

#define System {
FormFriends::~FormFriends(){
//    for (int i=0;i<=_numRequests;i++) {
//        //request[numrequests];
//    }
    delete ui;
}
void FormFriends::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        Retranslate();
    }
}
void FormFriends::Retranslate(){
    ui->retranslateUi(this);
    ui->ComboBoxStatus->clear();
    ui->ComboBoxStatus->addItems(QStringList()<<tr("Статус")<<tr("В игре")<<tr("Не в сети")<<tr("В сети")<<tr("Не беспокоить")<<tr("Нет на месте")<<tr("Спит")<<tr("Ожидает обмена")<<tr("Хочет поиграть"));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnID,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnIcon,new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnName,new QTableWidgetItem(tr("Ник")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnAdded,new QTableWidgetItem(tr("Добавлен")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnStatus,new QTableWidgetItem(tr("Статус")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnisPublic,new QTableWidgetItem(tr("Профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnGoTo,new QTableWidgetItem(tr("На профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnFavorite,new QTableWidgetItem(tr("Избранное")));
    FriendToUi();
    Threading loadTable(this);
    loadTable.AddThreadFriends(ui->TableWidgetFriends,_profiles,_friends);
}
void FormFriends::closeEvent(QCloseEvent*){
    emit s_return_to_profile(this);
    //delete this;
}
void FormFriends::on_ButtonReturn_clicked(){
    emit s_return_to_profile(this);
    //delete this;
}
#define SystemEnd }

#define Filter {
void FormFriends::on_CheckBoxOpenProfile_stateChanged(int arg1){
    if(arg1==2){
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            _filter.SetData(i,c_filterPublic,ui->TableWidgetFriends->item(i,c_tableColumnisPublic)->text().indexOf(tr("Публичный"))>-1);
        } else {
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            _filter.SetData(i,c_filterPublic,true);
        }
    UpdateHiddenRows();
}
void FormFriends::on_ComboBoxStatus_activated(int a_index){
    if(a_index!=0){
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            _filter.SetData(i,c_filterStatus,ui->ComboBoxStatus->currentText()==ui->TableWidgetFriends->item(i,c_tableColumnStatus)->text());
        } else {
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            _filter.SetData(i,c_filterStatus,true);
        }
    UpdateHiddenRows();
}
void FormFriends::on_LineEditName_textChanged(const QString & a_newText){
    for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
        _filter.SetData(i,c_filterName,ui->TableWidgetFriends->item(i,c_tableColumnName)->text().toLower().indexOf(a_newText.toLower())>-1);
    UpdateHiddenRows();
}
void FormFriends::on_ButtonFind_clicked(){
    on_LineEditName_textChanged(ui->LineEditName->text());
}
void FormFriends::UpdateHiddenRows(){
    for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
        ui->TableWidgetFriends->setRowHidden(i,!_filter.GetData(i));
}
void FormFriends::on_CheckBoxFavorites_stateChanged(int arg1){
    switch (arg1) {
        case 0:
            for (int i=0;i<ui->TableWidgetFriends->rowCount();
                 _filter.SetData(i++,c_filterFavorites,true));
            break;
        case 2:
            QJsonArray values=_favorites.GetValues();
            for (int i=0;i<ui->TableWidgetFriends->rowCount();i++){
                bool isFavorite=false;
                foreach (QJsonValue value, values) {
                    if(value.toObject().value("id").toString()==_profiles[i].GetSteamid()){
                        isFavorite=true;
                        break;
                    }
                }
                _filter.SetData(i,c_filterFavorites,isFavorite);
            }
            break;
    }
    UpdateHiddenRows();
}
#define FilterEnd }

#define Functions {
void FormFriends::ButtonFriendGoTo_Clicked(){
    if((_windowChildCount==0)&&(_currentFriend!="")){
        //disconnect(sender(),SIGNAL(pressed()),this,SLOT(GoToProfileClicked()));
        _windowChildCount++;
        emit s_go_to_profile(_currentFriend,QueryType::url);
        emit s_return_to_profile(this);
    }
}
void FormFriends::ButtonFriendFavorite_Clicked(){
    QJsonObject newValue;
    newValue["id"]=_profiles[_currentFriendIndex].GetSteamid();
    newValue["name"]=_profiles[_currentFriendIndex].GetPersonaname();
    newValue["added"]=_friends[_currentFriendIndex].GetFriend_since().toString("yyyy.MM.dd hh:mm:ss");
    if(_favorites.AddValue(newValue,true)){
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}
void FormFriends::on_TableWidgetFriends_cellDoubleClicked(int a_row, int){
    _currentFriend=ui->TableWidgetFriends->item(a_row,c_tableColumnID)->text();
    ButtonFriendGoTo_Clicked();
}

void FormFriends::TableWidgetFriends_CellClicked(int a_row, int){
    if(_currentFriend!=ui->TableWidgetFriends->item(a_row,c_tableColumnID)->text()){
        _currentFriend=ui->TableWidgetFriends->item(a_row,c_tableColumnID)->text();
        FriendToUi();
    }
}

void FormFriends::FriendToUi(){
    int row=-1;
    for (int i=0;i<ui->TableWidgetFriends->rowCount();i++) {
        if(ui->TableWidgetFriends->item(i,c_tableColumnID)->text()==_currentFriend){
            row=i;
            break;
        }
    }
    if(row>-1){
        ui->LabelFriendIcon->setPixmap(*static_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(row,c_tableColumnIcon))->pixmap());
        int index=-1;
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++) {
            if(_profiles[i].GetSteamid()==_currentFriend){
                index=i;
                break;
            }
        }
        if(index>-1){
            _currentFriendIndex=index;
            ui->LabelFriendName->setText(_profiles[index].GetPersonaname());
            if(!_profiles[index].GetGameextrainfo().isEmpty()){
                ui->LabelFriendStatus->setText(tr("В игре"));
                ui->LabelFriendStatus->setStyleSheet("color: #89b753");
            } else
                switch (_profiles[index].GetPersonastate()){
                case 0:{
                        ui->LabelFriendStatus->setText(tr("Не в сети"));
                        ui->LabelFriendStatus->setStyleSheet("color: #4c4d4f");
                        break;
                }
                case 1:{
                        ui->LabelFriendStatus->setText(tr("В сети"));
                        ui->LabelFriendStatus->setStyleSheet("color: #57cbde");
                        break;
                }
                case 2:{
                        ui->LabelFriendStatus->setText(tr("Не беспокоить"));
                        ui->LabelFriendStatus->setStyleSheet("color: #815560");
                        break;
                }
                case 3:{
                        ui->LabelFriendStatus->setText(tr("Нет на месте"));
                        ui->LabelFriendStatus->setStyleSheet("color: #46788e");
                        break;
                }
                case 4:{
                        ui->LabelFriendStatus->setText(tr("Спит"));
                        ui->LabelFriendStatus->setStyleSheet("color: #46788e");
                        break;
                }
                case 5:{
                        ui->LabelFriendStatus->setText(tr("Ожидает обмена"));
                        ui->LabelFriendStatus->setStyleSheet("color: #761e87");
                        break;
                }
                case 6:{
                        ui->LabelFriendStatus->setText(tr("Хочет поиграть"));
                        ui->LabelFriendStatus->setStyleSheet("color: #761e87");
                        break;
                }
                }
            switch(_profiles[index].GetCommunityvisibilitystate()){
            case 1:{
                ui->LabelFriendPublic->setText(tr("Скрытый"));
                ui->LabelFriendPublic->setStyleSheet("color: #6e0e0e");
                break;
            }
            case 2:{
                ui->LabelFriendPublic->setText(tr("Скрытый"));
                ui->LabelFriendPublic->setStyleSheet("color: #6e0e0e");
                break;
            }
            case 3:{
                ui->LabelFriendPublic->setText(tr("Публичный"));
                ui->LabelFriendPublic->setStyleSheet("color: #0e6e11");
                break;
            }
            case 8:{
                ui->LabelFriendPublic->setText(tr("Скрытый"));
                ui->LabelFriendPublic->setStyleSheet("color: #6e0e0e");
                break;
            }
            }
        } else {
            _currentFriendIndex=-1;
        }
    }
}
#define FunctionsEnd }
