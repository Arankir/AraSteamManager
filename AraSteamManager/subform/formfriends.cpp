#include "formfriends.h"
#include "ui_formfriends.h"

#define Constants {
constexpr int c_tableColumnID=0;
constexpr int c_tableColumnIcon=1;
constexpr int c_tableColumnName=2;
constexpr int c_tableColumnAdded=3;
constexpr int c_tableColumnStatus=4;
constexpr int c_tableColumnisPublic=5;
constexpr int c_tableColumnGoTo=6;
constexpr int c_tableColumnFavorite=7;
constexpr int c_tableColumnCount=6;

constexpr int c_filterName=0;
constexpr int c_filterStatus=1;
constexpr int c_filterPublic=2;
constexpr int c_filterFavorites=3;
constexpr int c_filterCount=4;
#define ConstantsEnd }

#define Init {
FormFriends::FormFriends(QString a_id, SFriends a_friends, QWidget *parent): QWidget(parent), ui(new Ui::FormFriends), _id(a_id), _friends(a_friends), _profiles(_friends.GetProfiles()),
    _favorites("friends"), _filter(_friends.GetCount(),c_filterCount){
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    InitComponents();
    ui->LineEditName->setFocus();
}
void FormFriends::InitComponents(){
    ui->TableWidgetFriends->setColumnCount(c_tableColumnCount);
    Retranslate();
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setRowCount(_friends.GetCount());
    ui->TableWidgetFriends->setColumnHidden(c_tableColumnID,true);
    ui->TableWidgetFriends->setColumnWidth(c_tableColumnIcon,33);
    _profiles.Sort();
    ui->ButtonFriendGoTo->setFixedSize(QSize(25,25));
    ui->ButtonFriendFavorite->setFixedSize(QSize(25,25));
    SetIcons();
#define Connects {
    connect(ui->TableWidgetFriends,&QTableWidget::cellClicked,this,&FormFriends::TableWidgetFriends_CellClicked);
    connect(ui->ButtonFriendGoTo,&QPushButton::clicked,this,&FormFriends::ButtonFriendGoTo_Clicked);
    connect(ui->ButtonFriendFavorite,&QPushButton::clicked,this,&FormFriends::ButtonFriendFavorite_Clicked);
#define ConnectsEnd }
    Threading loadTable(this);
    loadTable.AddThreadFriends(c_tableColumnID, c_tableColumnName, c_tableColumnAdded, c_tableColumnStatus, c_tableColumnisPublic, ui->TableWidgetFriends, _profiles, _friends);
}
void FormFriends::ProgressLoading(int a_progress,int a_row){
    ui->TableWidgetFriends->setRowHeight(a_row,33);
}
void FormFriends::OnFinish(){
    ui->TableWidgetFriends->resizeColumnsToContents();
    int row=0;
    for(auto &profile: _profiles){
        QString path = _setting._pathImagesProfiles+profile._avatar.mid(72,20)+".jpg";
        QLabel *avatarFriend = new QLabel;
        ui->TableWidgetFriends->setCellWidget(row,c_tableColumnIcon,avatarFriend);
        if(!QFile::exists(path)){//Подумать над row==0
                avatarFriend->setBaseSize(QSize(32,32));
                RequestImage* image = new RequestImage(avatarFriend,profile._avatar,path,true,this);
//                if(row==0)//не работает
//                    connect(image,&RequestImage::s_loadComplete,ui->TableWidgetFriends,[=](){
//                        TableWidgetFriends_CellClicked(0,0);
//                    });
            } else {
                avatarFriend->setPixmap(QPixmap(path));
                if(row==0)
                    TableWidgetFriends_CellClicked(0,0);
            }
        row++;
    }
}
#define InitEnd }

#define System {
FormFriends::~FormFriends(){
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
    loadTable.AddThreadFriends(c_tableColumnID, c_tableColumnName, c_tableColumnAdded, c_tableColumnStatus, c_tableColumnisPublic, ui->TableWidgetFriends,_profiles,_friends);
}

void FormFriends::SetIcons(){
    switch(_setting.GetTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
    }
    ui->ButtonFind->setIcon(QIcon("://"+_theme+"/find_profile.png"));
    ui->ButtonFriendGoTo->setIcon(QIcon("://"+_theme+"/go_to.png"));
    ui->ButtonFriendFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
    ui->GroupBoxFilter->setStyleSheet("QGroupBox::title { "
                                        "image:url(://"+_theme+"/filter.png) 0 0 0 0 stretch stretch; "
                                        "image-position:left; "
                                        "margin-top:15px; "
                                      "}");
}
void FormFriends::closeEvent(QCloseEvent*){
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
                for(QJsonValue value: values) {
                    if(value.toObject().value("id").toString()==_profiles[i]._steamID){
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
        //emit s_return_to_profile(this);
    }
}
void FormFriends::ButtonFriendFavorite_Clicked(){
    QJsonObject newValue;
    newValue["id"]=_profiles[_currentFriendIndex]._steamID;
    newValue["name"]=_profiles[_currentFriendIndex]._personaName;
    newValue["added"]=_friends[_currentFriendIndex]._friend_since.toString("yyyy.MM.dd hh:mm:ss");
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
        int indexFriend=0;
        _currentFriendIndex=-1;
        for(auto &profile: _profiles){
            if(profile._steamID==_currentFriend){
                _currentFriendIndex=indexFriend;
                ui->LabelFriendName->setText(profile._personaName);
                if(!profile._gameExtraInfo.isEmpty()){
                    ui->LabelFriendStatus->setText(tr("В игре"));
                    ui->LabelFriendStatus->setStyleSheet("color: #89b753");
                } else
                    switch (profile._personaState){
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
                switch(profile._communityVisibilityState){
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
                break;
            }
            indexFriend++;
        }
    }
}
#define FunctionsEnd }
