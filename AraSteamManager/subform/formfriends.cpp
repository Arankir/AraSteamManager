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
const int c_tableColumnCount=8;

const int c_filterName=0;
const int c_filterStatus=1;
const int c_filterPublic=2;
const int c_filterFavorites=3;
const int c_filterCount=4;
#define ConstantsEnd }

#define Init {
FormFriends::FormFriends(QString a_id, SFriends a_friends, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormFriends){
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    _id=a_id;
    _friends=a_friends;
    _profiles = _friends.GetProfiles();
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
    _favorites.SetPath("friends");
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
    //ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->TableWidgetFriends->setAlternatingRowColors(true);
    //ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setRowCount(_friends.GetCount());
    ui->ButtonFind->setIcon(QIcon("://"+_theme+"/find_profile.png"));
    ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(://"+_theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->TableWidgetFriends->setColumnHidden(c_tableColumnID,true);
    ui->TableWidgetFriends->setColumnWidth(c_tableColumnIcon,33);
    _profiles.Sort();
    _filter.SetRow(_friends.GetCount());
    _filter.SetCol(c_filterCount);
    Threading loadTable(this);
    loadTable.AddThreadFriends(ui->TableWidgetFriends,_profiles,_friends);
}
void FormFriends::ProgressLoading(int a_progress,int a_row){
    QButtonWithData *button1 = new QButtonWithData(tr(" На профиль"));
    button1->setIcon(QIcon("://"+_theme+"/go_to.png"));
    button1->setMinimumSize(QSize(25,25));
    button1->setObjectName("ButtonGoToProfile"+_profiles[a_progress].GetSteamid());
    button1->AddData("ProfileID",_profiles[a_progress].GetSteamid());
    connect(button1,&QButtonWithData::pressed,this,&FormFriends::GoToProfileClicked);
    ui->TableWidgetFriends->setCellWidget(a_row,c_tableColumnGoTo,button1);

    QButtonWithData *button2 = new QButtonWithData("");
    button2->setIcon(QIcon("://"+_theme+"/favorites.png"));
    button2->setObjectName("ButtonFavorites"+QString::number(a_progress));
    button2->AddData("NumberFriend",QString::number(a_row));
    connect(button2,&QButtonWithData::pressed,this,&FormFriends::FavoritesClicked);
    ui->TableWidgetFriends->setCellWidget(a_row,c_tableColumnFavorite,button2);
    ui->TableWidgetFriends->setRowHeight(a_row,33);
}
void FormFriends::OnFinish(){
    ui->TableWidgetFriends->resizeColumnsToContents();
    for (int i=0;i<_friends.GetCount();i++) {
        QString path = _setting._pathImagesProfiles+_profiles[i].GetAvatar().mid(72,20)+".jpg";
        if(!QFile::exists(path)){
            if(_numRequests<500){
                RequestData *image = new RequestData(_profiles[i].GetAvatar(),i,path,true);
                connect(image,&RequestData::s_finished,this,&FormFriends::OnImageLoad);
                _request.append(image);
                _numRequests++;
                _numNow++;
                }
            } else {
                QLabel *avatarFriend = new QLabel;
                avatarFriend->setPixmap(QPixmap(path));
                ui->TableWidgetFriends->setCellWidget(i,c_tableColumnIcon,avatarFriend);
            }
        }
}
void FormFriends::OnImageLoad(RequestData *a_image){
    QPixmap pixmap;
    pixmap.loadFromData(a_image->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetFriends->setCellWidget(a_image->GetRow(),c_tableColumnIcon,label);
    if(_numRequests==500&&_numNow<_friends.GetCount()){
        a_image->LoadImage(_profiles[_numNow].GetAvatar(),_numNow,_setting._pathImagesProfiles+_profiles[_numNow].GetAvatar().mid(72,20)+".jpg",true);
        _numNow++;
    } else {
        disconnect(a_image,&RequestData::s_finished,this,&FormFriends::OnImageLoad);
        a_image->deleteLater();
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
        ui->retranslateUi(this);
    }
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
void FormFriends::GoToProfileClicked(){
    if(_windowChildCount==0){
        //disconnect(sender(),SIGNAL(pressed()),this,SLOT(GoToProfileClicked()));
        _windowChildCount++;
        emit s_go_to_profile(static_cast<QButtonWithData*>(sender())->GetData(0),QueryType::url);
        emit s_return_to_profile(this);
    }
}
void FormFriends::FavoritesClicked(){
    int indexProfile=static_cast<QButtonWithData*>(sender())->GetData(0).toInt();
    QJsonObject newValue;
    newValue["id"]=_profiles[indexProfile].GetSteamid();
    newValue["name"]=_profiles[indexProfile].GetPersonaname();
    newValue["added"]=_friends[indexProfile].GetFriend_since().toString("yyyy.MM.dd hh:mm:ss");
    if(_favorites.AddValue(newValue,true)){
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}
void FormFriends::on_TableWidgetFriends_cellDoubleClicked(int a_row, int){
    this->findChild<QButtonWithData*>("ButtonGoToProfile"+ui->TableWidgetFriends->item(a_row,0)->text())->click();
}
#define FunctionsEnd }
