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

FormFriends::FormFriends(QString Aid, SFriends Afriends, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormFriends){
    ui->setupUi(this);
    _id=Aid;
    _friends=Afriends;
    SProfile profiles = _friends.GetProfiles();
    for(int i=0;i<profiles.GetCount();_profiles.push_back(profiles.GetProfile(i++)));
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

#define Init {
void FormFriends::InitComponents(){
    _favorites.SetPath("Files/Favorites/Friends.json","Friends");
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
    ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setRowCount(_friends.GetCount());
    ui->ButtonFind->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/find.png"));
    ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(:/"+_theme+"/program/"+_theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->TableWidgetFriends->setColumnHidden(c_tableColumnID,true);
    ui->TableWidgetFriends->setColumnWidth(c_tableColumnIcon,33);
    for (int i=0; i < _profiles.size()-1; i++) {
        for (int j=0; j < _profiles.size()-i-1; j++) {
            if (_profiles[j].GetPersonaname() > _profiles[j+1].GetPersonaname()) {
                SProfile temp = _profiles[j];
                _profiles[j] = _profiles[j+1];
                _profiles[j+1] = temp;
            }
        }
    }
    _filter.SetRow(_friends.GetCount());
    _filter.SetCol(c_filterCount);
    Threading LoadTable(this);
    LoadTable.AddThreadFriends(ui->TableWidgetFriends,_profiles,_friends);
}
void FormFriends::ProgressLoading(int Aprogress,int Arow){
    QButtonWithData *button1 = new QButtonWithData(tr("На профиль"));
    button1->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/go_to.png"));
    button1->setMinimumSize(QSize(25,25));
    button1->setObjectName("ButtonGoToProfile"+_profiles[Aprogress].GetSteamid());
    button1->AddData("ProfileID",_profiles[Aprogress].GetSteamid());
    connect(button1,&QButtonWithData::pressed,this,&FormFriends::GoToProfileClicked);
    ui->TableWidgetFriends->setCellWidget(Arow,c_tableColumnGoTo,button1);

    QButtonWithData *button2 = new QButtonWithData("");
    button2->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/favorites.png"));
    button2->setObjectName("ButtonFavorites"+QString::number(Aprogress));
    button2->AddData("NumberFriend",QString::number(Arow));
    connect(button2,&QButtonWithData::pressed,this,&FormFriends::FavoritesClicked);
    ui->TableWidgetFriends->setCellWidget(Arow,c_tableColumnFavorite,button2);
    ui->TableWidgetFriends->setRowHeight(Arow,33);
}
void FormFriends::OnFinish(){
    ui->TableWidgetFriends->resizeColumnsToContents();
    for (int i=0;i<_friends.GetCount();i++) {
        QString path = "images/profiles/"+_profiles[i].GetAvatar().mid(72,20)+".jpg";
        if(!QFile::exists(path)){
            if(_numRequests<500){
                ImageRequest *image = new ImageRequest(_profiles[i].GetAvatar(),i,path,true);
                connect(image,&ImageRequest::s_finished,this,&FormFriends::OnResultImage);
                _request.append(image);
                _numRequests++;
                _numNow++;
                }
            } else {
                QPixmap pixmap;
                pixmap.load(path);
                QLabel *label = new QLabel;
                label->setPixmap(pixmap);
                ui->TableWidgetFriends->setCellWidget(i,c_tableColumnIcon,label);
            }
        }
}
void FormFriends::OnResultImage(ImageRequest *Aimage){
    QPixmap pixmap;
    pixmap.loadFromData(Aimage->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetFriends->setCellWidget(Aimage->GetRow(),c_tableColumnIcon,label);
    if(_numRequests==500&&_numNow<_friends.GetCount()){
        Aimage->LoadImage(_profiles[_numNow].GetAvatar(),_numNow,"images/profiles/"+_profiles[_numNow].GetAvatar().mid(72,20)+".jpg",true);
        _numNow++;
    } else {
        disconnect(Aimage,&ImageRequest::s_finished,this,&FormFriends::OnResultImage);
        Aimage->deleteLater();
    }
}
#define InitEnd }

#define System {
FormFriends::~FormFriends(){
    for (int i=0;i<=_numRequests;i++) {
        //request[numrequests];
    }
    delete ui;
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
void FormFriends::on_ComboBoxStatus_activated(int AIndex){
    if(AIndex!=0){
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            _filter.SetData(i,c_filterStatus,ui->ComboBoxStatus->currentText()==ui->TableWidgetFriends->item(i,c_tableColumnStatus)->text());
        } else {
        for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
            _filter.SetData(i,c_filterStatus,true);
        }
    UpdateHiddenRows();
}
void FormFriends::on_LineEditName_textChanged(const QString & AnewText){
    for (int i=0;i<ui->TableWidgetFriends->rowCount();i++)
        _filter.SetData(i,c_filterName,ui->TableWidgetFriends->item(i,c_tableColumnName)->text().toLower().indexOf(AnewText.toLower())>-1);
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
            QJsonArray val=_favorites.GetValues();
            for (int i=0;i<ui->TableWidgetFriends->rowCount();i++){
                bool accept=false;
                foreach (QJsonValue value, val) {
                    if(value.toObject().value("id").toString()==_profiles[i].GetSteamid()){
                        accept=true;
                        break;
                    }
                }
                _filter.SetData(i,c_filterFavorites,accept);
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
        QButtonWithData *btn = static_cast<QButtonWithData*>(sender());
        emit s_go_to_profile(btn->GetData(0),QueryType::url);
        emit s_return_to_profile(this);
    }
}
void FormFriends::FavoritesClicked(){
    QButtonWithData *btn = static_cast<QButtonWithData*>(sender());
    int index=btn->GetData(0).toInt();
    QJsonObject newValue;
    newValue["id"]=_profiles[index].GetSteamid();
    newValue["name"]=_profiles[index].GetPersonaname();
    newValue["added"]=_friends.GetFriend_since(index).toString("yyyy.MM.dd hh:mm:ss");
    if(_favorites.AddValue(newValue,true)){
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}
#define FunctionsEnd }

void FormFriends::on_TableWidgetFriends_cellDoubleClicked(int row, int){
    this->findChild<QButtonWithData*>("ButtonGoToProfile"+ui->TableWidgetFriends->item(row,0)->text())->click();
}
