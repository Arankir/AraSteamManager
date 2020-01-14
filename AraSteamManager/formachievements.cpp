#include "formachievements.h"
#include "ui_formachievements.h"
#define Constants {
const int c_filterName=0;
const int c_filterReached=1;
const int c_filterFavorite=2;
const int c_filterEndConstValues=3;

const int c_tableAchievementColumnAppid=0;
const int c_tableAchievementColumnIcon=1;
const int c_tableAchievementColumnTitle=2;
const int c_tableAchievementColumnDescription=3;
const int c_tableAchievementColumnWorld=4;
const int c_tableAchievementColumnReached=5;
const int c_tableAchievementColumnFavorite=6;
const int c_tableAchievementColumnCount=7;
const int c_tableAchievementColumnNoValue=7;

const int c_tableCompareColumnAppid=0;
const int c_tableCompareColumnIcon=1;
const int c_tableCompareColumnTitle=2;
const int c_tableCompareColumnDescription=3;
const int c_tableCompareColumnWorld=4;
const int c_tableCompareColumnMy=5;
const int c_tableCompareColumnFavorite=6;
const int c_tableCompareColumnCount=6;

const int c_tableFriendsRowAvatars=0;
const int c_tableFriendsRowCheckBox=1;
const int c_tableFriendsRowFilters=2;
const int c_tableFriendsRowID=3;
const int c_tableFriendsRowCount=4;
#define ConstantsEnd }

FormAchievements::FormAchievements(SAchievementsPlayer Aplayer, QString Aid, SGame Agame, int AunicNum, QWidget *parent): QWidget(parent), ui(new Ui::FormAchievements){
    ui->setupUi(this);
    _id=Aid;
    _game=Agame;
    _unicNum=AunicNum;
    _achievements.Set(Aplayer);
    switch(_setting.GetTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
    }
    InitComponents();
    ui->LineEditNameAchievements->setFocus();
}

#define Init {
void FormAchievements::InitComponents(){
    #define LoadData {
    SProfile profileData(_id,false,QueryType::url);
    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &logoreply = *manager.get(QNetworkRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                            QString::number(_game.GetAppid())+"/"+_game.GetImg_logo_url()+".jpg"));
    loop.exec();
    QPixmap pixLogo;
    pixLogo.loadFromData(logoreply.readAll());
    QNetworkReply &avatarReply = *manager.get(QNetworkRequest(profileData.GetAvatar()));
    loop.exec();
    disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QPixmap pixProfileAvatar;
    pixProfileAvatar.loadFromData(avatarReply.readAll());
    QLabel *profileAvatar = new QLabel;
    profileAvatar->setPixmap(pixProfileAvatar);
    profileAvatar->setAlignment(Qt::AlignCenter);
    QLabel *profileAvatar2 = new QLabel;
    profileAvatar2->setPixmap(pixProfileAvatar);
    profileAvatar2->setAlignment(Qt::AlignCenter);
    profileAvatar2->setToolTip(profileData.GetPersonaname());
    QLabel *allFriends = new QLabel("All");
    allFriends->setToolTip(tr("Достижения друзей"));
    allFriends->setScaledContents(true);
    allFriends->setFixedSize(32,32);
    #define LoadDataEnd }
    #define SetTableWidgetAchievementsSettings {
    ui->TableWidgetAchievements->setAlternatingRowColors(true);
    ui->TableWidgetAchievements->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetAchievements->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetAchievements->setColumnCount(c_tableAchievementColumnCount);
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnIcon,new QTableWidgetItem(""));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnTitle,new QTableWidgetItem(tr("Название")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnDescription,new QTableWidgetItem(tr("Описание")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnWorld,new QTableWidgetItem(tr("По миру")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnReached,new QTableWidgetItem(tr("Получено")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnFavorite,new QTableWidgetItem(tr("Избранное")));
    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnAppid,true);
    ui->TableWidgetAchievements->setColumnWidth(c_tableAchievementColumnTitle,65);
    ui->TableWidgetAchievements->setColumnWidth(c_tableAchievementColumnTitle,100);
    ui->TableWidgetAchievements->setColumnWidth(c_tableAchievementColumnDescription,315);
    ui->TableWidgetAchievements->setColumnWidth(c_tableAchievementColumnReached,80);
    ui->TableWidgetAchievements->setColumnWidth(c_tableAchievementColumnFavorite,50);
    #define SetTableWidgetAchievementsSettingsEnd }
    #define SetTableWidgetCompareAchievementsSettings {
    ui->TableWidgetCompareAchievements->setAlternatingRowColors(true);
    ui->TableWidgetCompareAchievements->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetCompareAchievements->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetCompareAchievements->setColumnCount(c_tableCompareColumnCount);
    ui->TableWidgetCompareAchievements->setCellWidget(0,c_tableCompareColumnMy,profileAvatar);
    ui->TableWidgetCompareAchievements->setRowHeight(0,33);
    ui->TableWidgetCompareAchievements->setVerticalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetCompareAchievements->setVerticalHeaderItem(1,new QTableWidgetItem("%"));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(c_tableCompareColumnIcon,new QTableWidgetItem(""));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(c_tableCompareColumnTitle,new QTableWidgetItem(tr("Название")));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(c_tableCompareColumnDescription,new QTableWidgetItem(tr("Описание")));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(c_tableCompareColumnWorld,new QTableWidgetItem(tr("По миру")));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(c_tableCompareColumnMy,new QTableWidgetItem(profileData.GetPersonaname()));
    ui->TableWidgetCompareAchievements->setColumnHidden(c_tableCompareColumnAppid,true);
    ui->TableWidgetCompareAchievements->setColumnWidth(c_tableCompareColumnIcon,65);
    ui->TableWidgetCompareAchievements->setColumnWidth(c_tableCompareColumnTitle,100);
    ui->TableWidgetCompareAchievements->setColumnWidth(c_tableCompareColumnDescription,315);
    ui->TableWidgetCompareAchievements->resizeColumnToContents(c_tableCompareColumnWorld);
    ui->TableWidgetCompareAchievements->setColumnWidth(c_tableCompareColumnMy,80);
    #define SetTableWidgetCompareAchievementsSettingsEnd }
    #define SetTableWidgetCompareFriendsSettings {
    ui->TableWidgetCompareFriends->setAlternatingRowColors(true);
    ui->TableWidgetCompareFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetCompareFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetCompareFriends->setMinimumSize(0,180);
    ui->TableWidgetCompareFriends->setColumnCount(2);
    ui->TableWidgetCompareFriends->setRowCount(c_tableFriendsRowCount);
    ui->TableWidgetCompareFriends->setRowHidden(c_tableFriendsRowID,true);
    ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowAvatars,0,profileAvatar2);
    ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowAvatars,1,allFriends);
    #define SetRadioButtonMyAchievementsSettings {
    QWidget *widgetMyAchievementsFilter = new QWidget;
    QVBoxLayout *layoutMyAchievementsFilter = new QVBoxLayout;
    layoutMyAchievementsFilter->setMargin(1);
    QRadioButtonWithData *rbMyAllAchievements = new QRadioButtonWithData();
    rbMyAllAchievements->setObjectName("RBMyAll");
    rbMyAllAchievements->AddData("Appertain","My");
    rbMyAllAchievements->AddData("Type","All");
    rbMyAllAchievements->setChecked(true);
    layoutMyAchievementsFilter->addWidget(rbMyAllAchievements);
    connect(rbMyAllAchievements,&QRadioButtonWithData::clicked,this,&FormAchievements::on_RadioButtonAll_clicked);
    QRadioButtonWithData *rbMyReachedAchievements = new QRadioButtonWithData();
    rbMyReachedAchievements->setObjectName("RBMyReached");
    rbMyReachedAchievements->AddData("Appertain","My");
    rbMyReachedAchievements->AddData("Type","Reached");
    layoutMyAchievementsFilter->addWidget(rbMyReachedAchievements);
    connect(rbMyReachedAchievements,&QRadioButtonWithData::clicked,this,&FormAchievements::on_RadioButtonReached_clicked);
    QRadioButtonWithData *rbMyNotReachedAchievements = new QRadioButtonWithData();
    rbMyNotReachedAchievements->setObjectName("RBMyNotReached");
    rbMyNotReachedAchievements->AddData("Appertain","My");
    rbMyNotReachedAchievements->AddData("Type","NotReached");
    layoutMyAchievementsFilter->addWidget(rbMyNotReachedAchievements);
    connect(rbMyNotReachedAchievements,&QRadioButtonWithData::clicked,this,&FormAchievements::on_RadioButtonNotReached_clicked);
    widgetMyAchievementsFilter->setLayout(layoutMyAchievementsFilter);
    #define SetRadioButtonMyAchievementsSettingsEnd }
    #define SetRadioButtonFriendsAchievementsSettings {
    QWidget *widgetFriendsAchievementsFilter = new QWidget;
    QVBoxLayout *layoutFriendsAchievementsFilter = new QVBoxLayout;
    layoutFriendsAchievementsFilter->setMargin(1);
    layoutFriendsAchievementsFilter->setAlignment(Qt::AlignCenter);
    QButtonWithData *pbFriendsAllAchievements = new QButtonWithData("");
    pbFriendsAllAchievements->setObjectName("PBFriendsAll");
    pbFriendsAllAchievements->AddData("Appertain","Friends");
    pbFriendsAllAchievements->AddData("Type","All");
    pbFriendsAllAchievements->setChecked(true);
    layoutFriendsAchievementsFilter->addWidget(pbFriendsAllAchievements);
    connect(pbFriendsAllAchievements,&QPushButton::clicked,this,&FormAchievements::on_RadioButtonCompareFriendsAll_clicked);
    QButtonWithData *pbFriendsReachedAchievements = new QButtonWithData("");
    pbFriendsReachedAchievements->setObjectName("PBFriendsReached");
    pbFriendsReachedAchievements->AddData("Appertain","Friends");
    pbFriendsReachedAchievements->AddData("Type","Reached");
    layoutFriendsAchievementsFilter->addWidget(pbFriendsReachedAchievements);
    connect(pbFriendsReachedAchievements,&QPushButton::clicked,this,&FormAchievements::on_RadioButtonCompareFriendsReached_clicked);
    QButtonWithData *pbFriendsNotReachedAchievements = new QButtonWithData("");
    pbFriendsNotReachedAchievements->setObjectName("PBFriendsNotReached");
    pbFriendsNotReachedAchievements->AddData("Appertain","Friends");
    pbFriendsNotReachedAchievements->AddData("Type","NotReached");
    connect(pbFriendsNotReachedAchievements,&QPushButton::clicked,this,&FormAchievements::on_RadioButtonCompareFriendsNotReached_clicked);
    layoutFriendsAchievementsFilter->addWidget(pbFriendsNotReachedAchievements);
    widgetFriendsAchievementsFilter->setLayout(layoutFriendsAchievementsFilter);
    #define SetRadioButtonFriendsAchievementsSettingsEnd }
    ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowFilters,0,widgetMyAchievementsFilter);
    ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowFilters,1,widgetFriendsAchievementsFilter);
    ui->TableWidgetCompareFriends->resizeRowsToContents();
    ui->TableWidgetCompareFriends->resizeColumnsToContents();
    #define SetTableWidgetCompareFriendsSettingsEnd }
    #define InitCategoryValuesLayout {
    QWidget *widget = new QWidget;
    _categoryValuesLayout = new QFormLayout;
    _categoryValuesLayout->setSpacing(0);
    _categoryValuesLayout->setContentsMargins(1,1,1,1);
    widget->setLayout(_categoryValuesLayout);
    ui->ScrollAreaValuesCategory->setWidget(widget);
    #define InitCategoryValuesLayoutEnd }
    #define SetIcon {
    ui->ButtonCompare->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/compare.png"));
    //ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {background-image:url(images/program/filter_white.png)}");
    //ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(images/program/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->GroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(:/"+_theme+"/program/"+_theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->ButtonAddCategory->setIcon(QIcon(":/program/program/create.png"));
    ui->ButtonChangeCategory->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/change.png"));
    ui->ButtonDeleteCategory->setIcon(QIcon(":/program/program/delete.png"));
    ui->ButtonFindAchievement->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/find.png"));
    ui->ButtonAddValueCategory->setIcon(QIcon(":/program/program/create.png"));
    ui->ButtonAcceptCategory->setIcon(QIcon(":/program/program/apply.png"));
    ui->ButtonCancelCategory->setIcon(QIcon(":/program/program/cancel.png"));
    ui->RadioButtonAll->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/all.png"));
    ui->RadioButtonReached->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/reached.png"));
    ui->RadioButtonNotReached->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/notreached.png"));
    ui->ButtonUpdate->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/update.png"));
    allFriends->setPixmap(QPixmap(":/"+_theme+"/program/"+_theme+"/friends.png"));
    rbMyAllAchievements->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/all.png"));
    rbMyReachedAchievements->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/reached.png"));
    rbMyNotReachedAchievements->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/notreached.png"));
    pbFriendsAllAchievements->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/all.png"));
    pbFriendsReachedAchievements->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/reached.png"));
    pbFriendsNotReachedAchievements->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/notreached.png"));
    #define SetIconEnd }
    _favorites.SetPath("Files/Favorites/Achievements.json","Achievements");
    if(!QDir("images/achievements/"+QString::number(_game.GetAppid())).exists())
        QDir().mkdir("images/achievements/"+QString::number(_game.GetAppid()));
    _categoriesGame.Set(_game);
    ui->LabelGameLogo->setPixmap(pixLogo);
    ui->GroupBoxCategories->setVisible(false);
    SwitchSimpleCompare(FormMode::compare);
    ui->ProgressBarFriendsLoad->setVisible(false);
    ui->LabelGameOnline->setText(tr("Сейчас в игре :%1").arg(_game.GetNumberPlayers(false)));
    ui->LabelGameTitle->setText(_game.GetName());
    ui->GroupBoxFilter->setEnabled(false);
    _achievements.DoSet(QString::number(_game.GetAppid()),_id);
    connect(&_achievements,SIGNAL(s_finished()),this,SLOT(PullTableWidget()));
}
void FormAchievements::PullTableWidget(){
    if(_achievements.GetStatusFinish()==StatusValue::success){
        ui->TableWidgetAchievements->setRowCount(_achievements.GetCount());
        for(int i=0;i<_achievements.GetCount();i++)
            ui->TableWidgetAchievements->setRowHeight(i,65);
        ui->TableWidgetCompareAchievements->setRowCount(_achievements.GetCount()+2);
        _fAchievements.SetRow(ui->TableWidgetAchievements->rowCount());
        _fCompare.SetRow(ui->TableWidgetCompareAchievements->rowCount());
        ShowCategories();
        Threading LoadTable(this);
        QLabel *lbl = new QLabel;
        ui->TableWidgetCompareAchievements->setCellWidget(1,c_tableCompareColumnMy,lbl);
        LoadTable.AddThreadAchievements(_achievements,ui->LabelTotalPersent,ui->TableWidgetAchievements,lbl,ui->TableWidgetCompareAchievements);
    } else {
        ui->TableWidgetAchievements->insertRow(0);
        ui->TableWidgetAchievements->setItem(c_tableAchievementColumnAppid,1,new QTableWidgetItem("Error"));
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnTitle,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnDescription,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnWorld,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnReached,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnFavorite,true);
        ui->GroupBoxFilter->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
    }
}
void FormAchievements::ProgressLoading(int Aprogress,int Arow){
    qDebug()<<"Loading..."<<Aprogress;
    QButtonWithData *button = new QButtonWithData("");
    button->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/favorites.png"));
    button->setObjectName("ButtonFavorites&"+QString::number(Arow));
    button->AddData("NumberGame",QString::number(Arow));
    connect(button,&QButtonWithData::pressed,this,&FormAchievements::FavoritesClicked);
    ui->TableWidgetAchievements->setCellWidget(Arow,c_tableCompareColumnFavorite,button);
}
void FormAchievements::OnFinish(){
    ui->GroupBoxFilter->setEnabled(true);
    ui->TableWidgetAchievements->resizeColumnToContents(c_tableCompareColumnWorld);
    ui->TableWidgetAchievements->resizeRowsToContents();
    int j=0;
    ui->TableWidgetCompareAchievements->resizeRowsToContents();
    for (int i=0;i<_achievements.GetCount();i++) {
            QString achievementIcon=_achievements.GetIcon(i).mid(66,_achievements.GetIcon(i).length());
            QString path="images/achievements/"+QString::number(_game.GetAppid())+"/"+achievementIcon.mid(achievementIcon.indexOf("/",1)+1,achievementIcon.length()-1);
            if(_achievements.GetDisplayname(i)!=""){
                if(!QFile::exists(path)){
                    if(_numRequests<500){
                            ImageRequest *image = new ImageRequest(_achievements.GetIcon(i),j,path,true);
                            connect(image,&ImageRequest::s_finished,this,&FormAchievements::OnResultImage);
                            _request.append(image);
                            _numRequests++;
                            }
                        _numNow++;
                    }  else {
                    QPixmap pixmap;
                    pixmap.load(path);
                    QLabel *label = new QLabel;
                    label->setPixmap(pixmap);
                    ui->TableWidgetAchievements->setCellWidget(j,c_tableCompareColumnIcon,label);
                    ui->TableWidgetAchievements->resizeRowToContents(j);
                    QLabel *label2 = new QLabel;
                    label2->setPixmap(pixmap);
                    ui->TableWidgetCompareAchievements->setCellWidget(j+2,c_tableCompareColumnIcon,label2);
                    ui->TableWidgetCompareAchievements->resizeRowToContents(j);
                }
                j++;
            } else {
                ui->TableWidgetAchievements->removeRow(ui->TableWidgetAchievements->rowCount()-1);
                ui->TableWidgetCompareAchievements->removeRow(ui->TableWidgetCompareAchievements->rowCount()-1);
            }
        }
}
void FormAchievements::OnResultImage(ImageRequest *Aimage){
    QPixmap pixmap;
    pixmap.loadFromData(Aimage->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    QLabel *label2 = new QLabel;
    label2->setPixmap(pixmap);
    ui->TableWidgetAchievements->setCellWidget(Aimage->GetRow(),c_tableAchievementColumnIcon,label);
    ui->TableWidgetCompareAchievements->setCellWidget(Aimage->GetRow()+2,c_tableCompareColumnIcon,label2);
    ui->TableWidgetAchievements->resizeRowToContents(Aimage->GetRow());
    ui->TableWidgetCompareAchievements->resizeRowToContents(Aimage->GetRow()+2);
    if(_numRequests==500&&_numNow<_achievements.GetCount()){
        QString achievementIcon=_achievements.GetIcon(_numNow).mid(66,_achievements.GetIcon(_numNow).length());
        QString path="images/achievements/"+QString::number(_game.GetAppid())+"/"+achievementIcon.mid(achievementIcon.indexOf("/",1)+1,achievementIcon.length()-1);
        while (QFile::exists(path))
            _numNow++;
        Aimage->LoadImage(_achievements.GetIcon(_numNow),_numNow,path,true);
        _numNow++;
    } else {
        disconnect(Aimage,&ImageRequest::s_finished,this,&FormAchievements::OnResultImage);
        Aimage->deleteLater();
    }
}
#define InitEnd }

#define SimpleCompare {
void FormAchievements::SwitchSimpleCompare(FormMode AsimpleCompare){
    switch (AsimpleCompare) {
        case FormMode::compare:{
            ui->RadioButtonAll->setVisible(true);
            ui->RadioButtonReached->setVisible(true);
            ui->RadioButtonNotReached->setVisible(true);
            ui->TableWidgetAchievements->setVisible(true);
            ui->CheckBoxCompareAllFriends->setVisible(false);
            ui->TableWidgetCompareFriends->setVisible(false);
            ui->TableWidgetCompareFriends->setVisible(false);
            ui->TableWidgetCompareAchievements->setVisible(false);
            _categoriesGame.Set(_game);
            QList<QString> list = _categoriesGame.GetTitles();
            ui->ButtonAddCategory->setEnabled(true);
            ui->ButtonChangeCategory->setEnabled(list.size()!=0);
            ui->ButtonDeleteAllCategories->setEnabled(list.size()!=0);
            ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
            _simpleCompare=FormMode::achievement;
            break;
        }
    case FormMode::achievement:
            ui->RadioButtonAll->setVisible(false);
            ui->RadioButtonReached->setVisible(false);
            ui->RadioButtonNotReached->setVisible(false);
            ui->TableWidgetAchievements->setVisible(false);
            ui->CheckBoxCompareAllFriends->setVisible(true);
            ui->TableWidgetCompareFriends->setVisible(true);
            ui->TableWidgetCompareFriends->setVisible(true);
            ui->TableWidgetCompareAchievements->setVisible(true);
            ui->ButtonAddCategory->setEnabled(false);
            ui->ButtonChangeCategory->setEnabled(false);
            ui->ButtonDeleteAllCategories->setEnabled(false);
            ui->ButtonCompare->setText(tr("Обратно"));
            if(!_loadCompare)
                LoadingCompare();
            _simpleCompare=FormMode::compare;
            break;
    }
}
void FormAchievements::LoadingCompare(){
    _loadCompare++;
    SProfile Profile(_id,false,QueryType::url);
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(c_tableCompareColumnMy,new QTableWidgetItem(Profile.GetPersonaname()));

    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &imagereply = *manager.get(QNetworkRequest(Profile.GetAvatar()));
    loop.exec();
    QPixmap pix;
    pix.loadFromData(imagereply.readAll());
    QLabel *myava1 = new QLabel;
    myava1->setPixmap(pix);
    myava1->setAlignment(Qt::AlignCenter);
    ui->TableWidgetCompareAchievements->setCellWidget(0,c_tableCompareColumnMy,myava1);
    ui->TableWidgetCompareAchievements->resizeRowToContents(0);
    QLabel *myava2 = new QLabel;
    myava2->setPixmap(pix);
    myava2->setAlignment(Qt::AlignCenter);
    myava2->setToolTip(Profile.GetPersonaname());
    ui->TableWidgetCompareFriends->setCellWidget(0,c_tableFriendsRowAvatars,myava2);


    SFriends frien(_id,false);
    SProfile profiless = frien.GetProfiles();
    _friendsCount=profiless.GetCount();
    ui->TableWidgetCompareFriends->setColumnCount(_friendsCount+2);
    for (int i=0;i<_friendsCount;i++) {
        ui->TableWidgetCompareFriends->setColumnWidth(i+2,33);
        _profiles.push_back(profiless.GetProfile(i));
    }//Сортировка по именам
    for (int i=0; i < _friendsCount-1; i++) {
        for (int j=0; j < _profiles.size()-i-1; j++) {
            if (_profiles[j].GetPersonaname() > _profiles[j+1].GetPersonaname()) {
                SProfile temp = _profiles[j];
                _profiles[j] = _profiles[j+1];
                _profiles[j+1] = temp;
            }
        }
    }
    ui->ProgressBarFriendsLoad->setMaximum(_profiles.size());
    ui->ProgressBarFriendsLoad->setValue(0);
    ui->ProgressBarFriendsLoad->setVisible(true);

    for (int i=0;i<_friendsCount;i++) {
        SGames *Games = new SGames;
        Games->SetIndex(i);
        Games->Set(_profiles[i].GetSteamid(),true,true,true);
        connect(Games,SIGNAL(s_finished(SGames*)),this,SLOT(LoadFriend(SGames*)));
    }

}
void FormAchievements::LoadFriend(SGames *Agames){
    disconnect(Agames,SIGNAL(s_finished(SGames*)),this,SLOT(LoadFriend(SGames*)));
    bool apply=false;
    for (int i=0;i<Agames->GetCount();i++) {//Проверка на наличие игры
        if(Agames->GetAppid(i)==_game.GetAppid()){
            apply=true;
            break;
        }
    }
    QPair<SProfile,FriendType> deb;
    deb.first=_profiles[Agames->GetIndex()];
    if(apply){
        deb.second=FriendType::haveGame;
        _type1++;
    } else {
        deb.second=FriendType::haventGame;
        _type2++;
    }
    _friends.push_back(deb);
    ui->ProgressBarFriendsLoad->setValue(ui->ProgressBarFriendsLoad->value()+1);
    if(ui->ProgressBarFriendsLoad->value()==_friendsCount)
        FinishLoadFriends();

}
void FormAchievements::FinishLoadFriends(){
    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    ui->ProgressBarFriendsLoad->setVisible(false);

    for(int i=0;i<_friends.size();i++) {
        QNetworkReply &imagereply = *manager.get(QNetworkRequest(_friends[i].first.GetAvatar()));
        loop.exec();
        QPixmap pix;
        pix.loadFromData(imagereply.readAll());
        QLabel *ava = new QLabel;
        ava->setPixmap(pix);
        ava->setToolTip(_friends[i].first.GetPersonaname());
        ava->setAlignment(Qt::AlignCenter);
        ui->TableWidgetCompareFriends->setCellWidget(0,i+2,ava);
        QTableWidgetItem *pItem(new QTableWidgetItem(tr("")));
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        pItem->setCheckState(Qt::Unchecked);
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->TableWidgetCompareFriends->setItem(c_tableFriendsRowCheckBox,i+2,pItem);
        ui->TableWidgetCompareFriends->setItem(c_tableFriendsRowID,i+2,new QTableWidgetItem(_friends[i].first.GetSteamid()));
        ui->TableWidgetCompareFriends->setColumnHidden(i+2,_friends[i].second==FriendType::haventGame);
    }
    disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    connect(ui->TableWidgetCompareFriends,&QTableWidget::cellChanged,this,&FormAchievements::on_TableWidgetCompareFriendsCellChanged);
    ui->TableWidgetCompareFriends->resizeColumnsToContents();
}
void FormAchievements::on_RadioButtonAll_clicked(){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        _fAchievements.SetData(i,c_filterReached,true);
        _fCompare.SetData(i+2,c_filterReached,true);
    }
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonReached_clicked(){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        _fAchievements.SetData(i,c_filterReached,ui->TableWidgetAchievements->item(i,c_tableAchievementColumnReached)->text().indexOf(".")>-1);
        _fCompare.SetData(i+2,c_filterReached,ui->TableWidgetCompareAchievements->item(i+2,c_tableCompareColumnMy)->text().indexOf(".")>-1);
        }
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonNotReached_clicked(){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        _fAchievements.SetData(i,c_filterReached,ui->TableWidgetAchievements->item(i,c_tableAchievementColumnReached)->text().indexOf(".")==-1);
        _fCompare.SetData(i+2,c_filterReached,ui->TableWidgetCompareAchievements->item(i+2,c_tableCompareColumnMy)->text().indexOf(".")==-1);
        }
    UpdateHiddenRows();
}

void FormAchievements::on_RadioButtonCompareFriendsAll_clicked(){
    for(int i=2;i<ui->TableWidgetCompareFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"All";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormAchievements::on_RadioButtonCompareFriendsReached_clicked(){
    for(int i=2;i<ui->TableWidgetCompareFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"Reached";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormAchievements::on_RadioButtonCompareFriendsNotReached_clicked(){
    for(int i=2;i<ui->TableWidgetCompareFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"NotReached";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormAchievements::on_RadioButtonFriendAll_Click(){
    QRadioButtonWithData *rb = static_cast<QRadioButtonWithData*>(sender());
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetCompareFriends->cellWidget(0,rb->GetData(0).toInt()))->toolTip();
    int col=0;
    for(int i=c_tableCompareColumnCount;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
        if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==Name){
            col=i;
            break;
        }
    }
    int filtercol=_fCompare.GetCol()-(ui->TableWidgetCompareAchievements->columnCount()-col);
    for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
        _fCompare.SetData(i,filtercol,true);
    }
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonFriendReached_Click(){
    QRadioButtonWithData *rb = static_cast<QRadioButtonWithData*>(sender());
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetCompareFriends->cellWidget(0,rb->GetData(0).toInt()))->toolTip();
    int col=0;
    for(int i=c_tableCompareColumnCount;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
        if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==Name){
            col=i;
            break;
        }
    }
    int filtercol=_fCompare.GetCol()-(ui->TableWidgetCompareAchievements->columnCount()-col);
    for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
        _fCompare.SetData(i,filtercol,ui->TableWidgetCompareAchievements->item(i,col)->text().indexOf(".")>-1);
    }
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonFriendNotReached_Click(){
    QRadioButtonWithData *rb = static_cast<QRadioButtonWithData*>(sender());
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetCompareFriends->cellWidget(0,rb->GetData(0).toInt()))->toolTip();
    int coll=0;
    for(int i=c_tableCompareColumnCount;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
        if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==Name){
            coll=i;
            break;
        }
    }
    int filtercol=_fCompare.GetCol()-(ui->TableWidgetCompareAchievements->columnCount()-coll);
    for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
        _fCompare.SetData(i,filtercol,ui->TableWidgetCompareAchievements->item(i,coll)->text().indexOf(".")==-1);
    }
    UpdateHiddenRows();
}
void FormAchievements::on_TableWidgetCompareFriendsCellChanged(int Arow, int Acolumn){
    if((Arow==1)&&(Acolumn>1)){
        int col=ui->TableWidgetCompareAchievements->columnCount();
        SProfile sProfile=_friends[Acolumn-2].first;
        if(ui->TableWidgetCompareFriends->item(Arow,Acolumn)->checkState()==Qt::Checked){
            ui->TableWidgetCompareAchievements->insertColumn(col);
            ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(col,new QTableWidgetItem(sProfile.GetPersonaname()));
            QNetworkAccessManager manager;
            QEventLoop loop;
            connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
            QNetworkReply &imagereply = *manager.get(QNetworkRequest(_friends[Acolumn-2].first.GetAvatar()));
            loop.exec();
            disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
            QPixmap pix;
            pix.loadFromData(imagereply.readAll());
            QLabel *ava = new QLabel;
            ava->setPixmap(pix);
            ava->setToolTip(_friends[Acolumn-2].first.GetPersonaname());
            ava->setAlignment(Qt::AlignCenter);
            ui->TableWidgetCompareAchievements->setCellWidget(0,col,ava);
            SAchievementsPlayer pla(QString::number(_game.GetAppid()),sProfile.GetSteamid());
            connect(&pla,SIGNAL(s_finished()), &loop, SLOT(quit()));
            loop.exec();
            disconnect(&pla,SIGNAL(s_finished()), &loop, SLOT(quit()));
            SAchievements ach=_achievements;
            ach.Set(pla);
            if(ProfileIsPublic(ach,col)){
                QRadioButtonWithData *rbAll = new QRadioButtonWithData();
                QRadioButtonWithData *rbReached = new QRadioButtonWithData();
                QRadioButtonWithData *rbNotReached = new QRadioButtonWithData();
                rbAll->setObjectName("RB"+QString::number(Acolumn)+"All");
                rbReached->setObjectName("RB"+QString::number(Acolumn)+"Reached");
                rbNotReached->setObjectName("RB"+QString::number(Acolumn)+"NotReached");
                rbAll->AddData("NumberFriend",QString::number(Acolumn));
                rbReached->AddData("NumberFriend",QString::number(Acolumn));
                rbNotReached->AddData("NumberFriend",QString::number(Acolumn));
                connect(rbAll,&QRadioButtonWithData::clicked,this,&FormAchievements::on_RadioButtonFriendAll_Click);
                connect(rbReached,&QRadioButtonWithData::clicked,this,&FormAchievements::on_RadioButtonFriendReached_Click);
                connect(rbNotReached,&QRadioButtonWithData::clicked,this,&FormAchievements::on_RadioButtonFriendNotReached_Click);
                rbAll->setChecked(true);
                QWidget *wd = new QWidget;
                QVBoxLayout *lay = new QVBoxLayout;
                wd->setObjectName("WD"+QString::number(Acolumn));
                lay->setObjectName("Lay"+QString::number(Acolumn));
                lay->addWidget(rbAll);
                lay->addWidget(rbReached);
                lay->addWidget(rbNotReached);
                lay->setMargin(1);
                wd->setLayout(lay);
                rbAll->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/all.png"));
                rbReached->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/reached.png"));
                rbNotReached->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/notreached.png"));
                ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowFilters,Acolumn,wd);
                ui->TableWidgetCompareFriends->resizeRowsToContents();
                ui->TableWidgetCompareFriends->resizeColumnsToContents();
            }
            _fCompare.SetCol(_fCompare.GetCol()+1);

            ui->TableWidgetCompareAchievements->setColumnWidth(col,80);
        } else {
            int coll=0;
            for(int i=c_tableCompareColumnCount;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
                if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==sProfile.GetPersonaname()){
                    coll=i;
                    ui->TableWidgetCompareAchievements->removeColumn(i);
                    break;
                }
            }
            if(findChild<QRadioButton*>("RB"+QString::number(Acolumn)+"All")){
                disconnect(findChild<QRadioButton*>("RB"+QString::number(Acolumn)+"All"),&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendAll_Click);
                disconnect(findChild<QRadioButton*>("RB"+QString::number(Acolumn)+"Reached"),&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendReached_Click);
                disconnect(findChild<QRadioButton*>("RB"+QString::number(Acolumn)+"NotReached"),&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendNotReached_Click);
                delete findChild<QRadioButton*>("RB"+QString::number(Acolumn)+"All");
                delete findChild<QRadioButton*>("RB"+QString::number(Acolumn)+"Reached");
                delete findChild<QRadioButton*>("RB"+QString::number(Acolumn)+"NotReached");
                delete findChild<QVBoxLayout*>("Lay"+QString::number(Acolumn));
                ui->TableWidgetCompareFriends->removeCellWidget(c_tableFriendsRowFilters,Acolumn);
                delete findChild<QWidget*>("WD"+QString::number(Acolumn));
                ui->TableWidgetCompareFriends->resizeRowsToContents();
                ui->TableWidgetCompareFriends->resizeColumnsToContents();
            }
            _fCompare.RemoveCol(_fCompare.GetCol()-(ui->TableWidgetCompareAchievements->columnCount()-coll+1));
            UpdateHiddenRows();
        }
    }
}
void FormAchievements::on_CheckBoxCompareAllFriends_stateChanged(int arg1){
    switch (arg1) {
        case 0:
            for (int i=0;i<_friends.size();i++)
                if(_friends[i].second==FriendType::haventGame)
                    ui->TableWidgetCompareFriends->setColumnHidden(i+2,true);
            break;
        case 2:
            for (int i=0;i<_friends.size();i++)
                if(_friends[i].second==FriendType::haventGame)
                    ui->TableWidgetCompareFriends->setColumnHidden(i+2,false);
            ui->TableWidgetCompareFriends->resizeColumnsToContents();
            break;
    }
}
#define SimpleCompareEnd }

#define System {
FormAchievements::~FormAchievements(){
    delete _categoryValuesLayout;
    delete ui;
}
void FormAchievements::closeEvent(QCloseEvent*){
    emit s_return_to_games(_unicNum);
    this->deleteLater();
}
void FormAchievements::ShowCategories(){
    _categoriesGame.Set(_game);
    QList<QString> list = _categoriesGame.GetTitles();
    while(ui->ComboBoxCategoriesCategory->count()>1){
        ui->ComboBoxCategoriesCategory->removeItem(1);
    }
    QFormLayout *layout1 = new QFormLayout;
    QFormLayout *layout2 = new QFormLayout;
    QWidget *widget1 = new QWidget;
    QWidget *widget2 = new QWidget;
    for(int i = 0; i < list.size(); i++){
        if(_categoriesGame.GetIsNoValues(i)==1){
            QCheckBoxWithData *chb = new QCheckBoxWithData(_categoriesGame.GetTitle(i));
            chb->setObjectName("Category"+QString::number(i));
            chb->AddData("NumberCategory",QString::number(i));
            connect(chb,&QCheckBoxWithData::stateChanged,this,&FormAchievements::on_CheckBoxCategory_Change);
            layout2->addRow(chb);
        } else {
            QComboBoxWithData *cb = new QComboBoxWithData;
            cb->addItem(tr("Не выбрано"));
            QJsonArray values=_categoriesGame.GetValues(i);
            for(int j=0;j<values.size();j++) {
                cb->addItem(values.at(j).toObject().value("Title").toString());
            }
            cb->setObjectName("Category"+QString::number(i));
            cb->AddData("NumberCategory",QString::number(i));
            connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(on_ComboBoxCategory_Change(int)));
            layout1->addRow(new QLabel(_categoriesGame.GetTitle(i)),cb);
        }
        ui->ComboBoxCategoriesCategory->addItem(_categoriesGame.GetTitle(i));
        }
    widget1->setLayout(layout1);
    widget2->setLayout(layout2);
    ui->ScrollAreaCategories->setWidget(widget1);
    ui->ScrollAreaCheckCategories->setWidget(widget2);

    ui->ScrollAreaCategories->setHidden((layout1->rowCount()==0));
    ui->ScrollAreaCheckCategories->setHidden((layout2->rowCount()==0));
    ui->ButtonChangeCategory->setEnabled(list.size()!=0);
    ui->ButtonDeleteAllCategories->setEnabled(list.size()!=0);

    _fAchievements.SetCol(list.size()+3);
    _fCompare.SetCol(list.size()+3+ui->TableWidgetCompareAchievements->columnCount()-(c_tableCompareColumnCount+1));
}
void FormAchievements::UpdateHiddenRows(){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        ui->TableWidgetAchievements->setRowHidden(i,!_fAchievements.GetData(i));
    }
    for(int i=0;i<ui->TableWidgetCompareAchievements->rowCount();i++) {
        ui->TableWidgetCompareAchievements->setRowHidden(i,!_fCompare.GetData(i));
    }
}
bool FormAchievements::ProfileIsPublic(SAchievements Aachievement, int Acol){
    int totalReach=0;
    int totalNotReach=0;
    for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
        int j=0;
        bool accept=false;
        for(;j<Aachievement.GetCount();j++){
            if(Aachievement.GetApiname(j)==ui->TableWidgetCompareAchievements->item(i,c_tableAchievementColumnAppid)->text()){
                accept=true;
                break;
                }
        }
        if(accept){
            QTableWidgetItem *item5;
            if(Aachievement.GetAchieved(j)==1){
                item5 = new QTableWidgetItem(tr("Получено %1").arg(Aachievement.GetUnlocktime(j).toString("yyyy.MM.dd hh:mm")));
                totalReach++;
                } else {
                item5 = new QTableWidgetItem(tr("Не получено"));
                totalNotReach++;
                }
            item5->setTextAlignment(Qt::AlignCenter);
            ui->TableWidgetCompareAchievements->setItem(i,Acol,item5);
        }
        }
    if((totalReach==0)&&(totalNotReach==0)){
        ui->TableWidgetCompareAchievements->setCellWidget(1,Acol, new QLabel("profile is \nnot public"));
        return false;
        } else {
        ui->TableWidgetCompareAchievements->setCellWidget(1,Acol, new QLabel(QString(" %1/%2\n%3%").arg(QString::number(totalReach))
                                                                             .arg(QString::number(totalReach+totalNotReach))
                                                                             .arg(QString::number(100.0*totalReach/(totalReach+totalNotReach)))));
        return true;
    }
}
#define SystemEnd }

#define Filter {
void FormAchievements::on_LineEditNameAchievements_textChanged(const QString& AnewText){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        _fAchievements.SetData(i,c_filterName,((ui->TableWidgetAchievements->item(i,c_filterName+2)->text().toLower().indexOf(AnewText.toLower())>-1)
                                               ||(ui->TableWidgetAchievements->item(i,c_tableAchievementColumnDescription)->text().toLower().indexOf(AnewText.toLower())>-1)));
        _fCompare.SetData(i+2,c_filterName,((ui->TableWidgetCompareAchievements->item(i+2,c_filterName+2)->text().toLower().indexOf(AnewText.toLower())>-1)
                                            ||(ui->TableWidgetCompareAchievements->item(i+2,c_tableCompareColumnDescription)->text().toLower().indexOf(AnewText.toLower())>-1)));
    }
    UpdateHiddenRows();
}
void FormAchievements::on_ButtonFindAchievement_clicked(){
    on_LineEditNameAchievements_textChanged(ui->LineEditNameAchievements->text());
}
void FormAchievements::on_ButtonAddCategory_clicked(){
    if(_typeCategory==CategoryType::none){
        _typeCategory=CategoryType::add;
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
        ui->CheckBoxCategoryOneValue->setChecked(false);

        ui->ComboBoxCategoriesCategory->setVisible(false);
        ui->ButtonDeleteCategory->setVisible(false);
        ui->LineEditTitleCategory->setEnabled(true);
        ui->ButtonAddValueCategory->setEnabled(true);

        ui->GroupBoxCategories->setTitle(tr("Добавить категорию"));
        ui->GroupBoxCategories->setVisible(true);
        ui->TableWidgetAchievements->setColumnCount(c_tableAchievementColumnNoValue+1);
        ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnNoValue,new QTableWidgetItem());
        for(int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
            QTableWidgetItem *pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->TableWidgetAchievements->setItem(j,c_tableAchievementColumnNoValue, pItem);
        }
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnNoValue,true);
    }
}
void FormAchievements::on_ButtonChangeCategory_clicked(){
    if(_typeCategory==CategoryType::none){
        _typeCategory=CategoryType::change;
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
        ui->CheckBoxCategoryOneValue->setChecked(false);

        ui->ComboBoxCategoriesCategory->setVisible(true);
        ui->ButtonDeleteCategory->setVisible(true);
        ui->LineEditTitleCategory->setEnabled(false);
        ui->ButtonAddValueCategory->setEnabled(false);

        ui->GroupBoxCategories->setTitle(tr("Изменить категорию"));
        ui->GroupBoxCategories->setVisible(true);
    }
}
void FormAchievements::on_ButtonUpdate_clicked(){
    _achievements.Update();
    PullTableWidget();
    ui->LabelGameOnline->setText(tr("Сейчас в игре :%1").arg(_game.GetNumberPlayers(true)));
    if(ui->RadioButtonReached->isChecked())
        ui->RadioButtonReached->setChecked(true);
    else if(ui->RadioButtonNotReached->isChecked())
        ui->RadioButtonNotReached->setChecked(true);
}
void FormAchievements::FavoritesClicked(){
    QButtonWithData *btn = static_cast<QButtonWithData*>(sender());
    int index=btn->GetData(0).toInt();
    QJsonObject gameO;
    QJsonObject newValue;
    gameO["id"]=_game.GetAppid();
    gameO["name"]=_game.GetName();
    newValue["id"]=_achievements.GetApiname(index);
    newValue["title"]=_achievements.GetDisplayname(index);
    newValue["description"]=_achievements.GetDescription(index);

    if(_favorites.AddValue(gameO,newValue,true)){
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}
void FormAchievements::on_ButtonCompare_clicked(){
    SwitchSimpleCompare(_simpleCompare);
}
void FormAchievements::on_CheckBoxShowFilter_stateChanged(int arg1){
    ui->GroupBoxFilter->setHidden(arg1==0);
}
void FormAchievements::on_ComboBoxCategory_Change(int Aindex){
    QComboBoxWithData *cb = static_cast<QComboBoxWithData*>(sender());
    if(_categoriesGame.GetCounts()>0){
        int categorynum = cb->GetData(0).toInt();
        if(Aindex!=0){
            QList<QString> achievementsName = _categoriesGame.GetValues(categorynum,Aindex-1);
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categorynum,false);
                _fCompare.SetData(i+2,c_filterEndConstValues+categorynum,false);
                for(int j=0;j<achievementsName.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,c_tableAchievementColumnAppid)->text()==achievementsName[j]){
                        _fAchievements.SetData(i,c_filterEndConstValues+categorynum,true);
                        _fCompare.SetData(i+2,c_filterEndConstValues+categorynum,true);
                        break;
                        }
                    }
            }
        } else {
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categorynum,true);
                _fCompare.SetData(i+2,c_filterEndConstValues+categorynum,true);
                }
        }
        UpdateHiddenRows();
    }
}
void FormAchievements::on_CheckBoxCategory_Change(int Aindex){
    QCheckBoxWithData *cb = static_cast<QCheckBoxWithData*>(sender());
    if(_categoriesGame.GetCounts()>0){
        int categorynum = cb->GetData(0).toInt();
        if(Aindex!=0){
            QList<QString> achievementsName = _categoriesGame.GetNoValues(categorynum);
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categorynum,false);
                _fCompare.SetData(i+2,c_filterEndConstValues+categorynum,false);
                for(int j=0;j<achievementsName.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,c_tableAchievementColumnAppid)->text()==achievementsName[j]){
                        _fAchievements.SetData(i,c_filterEndConstValues+categorynum,true);
                        _fCompare.SetData(i+2,c_filterEndConstValues+categorynum,true);
                        break;
                        }
                    }
            }
        } else {
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categorynum,true);
                _fCompare.SetData(i+2,c_filterEndConstValues+categorynum,true);
                }
        }
        UpdateHiddenRows();
    }
}
void FormAchievements::on_ButtonDeleteAllCategories_clicked(){
    QMessageBox messageBox(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите удалить все категории?"));
    QAbstractButton *btnYes = messageBox.addButton(tr("Да"),QMessageBox::YesRole);
    messageBox.addButton(tr("Отмена"),QMessageBox::NoRole);
    messageBox.exec();
    if(messageBox.clickedButton()==btnYes){
        QMessageBox messageBox(QMessageBox::Question,
                               tr("Внимание!"),
                               tr("Данные о категориях будут утеряны навсегда, вы точно хотите удалить все категории?"));
        QAbstractButton *btnYess = messageBox.addButton(tr("Да"),QMessageBox::YesRole);
        messageBox.addButton(tr("Отмена"),QMessageBox::NoRole);
        messageBox.exec();
        if(messageBox.clickedButton()==btnYess){
            _categoriesGame.DeleteAll();
            ShowCategories();
        }
    }
}
#define HideColumns {
void FormAchievements::on_CheckBoxCompareIcon_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnIcon,arg1==0);
    ui->TableWidgetCompareAchievements->setColumnHidden(c_tableCompareColumnIcon,arg1==0);
}
void FormAchievements::on_CheckBoxCompareTitle_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnTitle,arg1==0);
    ui->TableWidgetCompareAchievements->setColumnHidden(c_tableCompareColumnTitle,arg1==0);
}
void FormAchievements::on_CheckBoxCompareDescription_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnDescription,arg1==0);
    ui->TableWidgetCompareAchievements->setColumnHidden(c_tableCompareColumnDescription,arg1==0);
}
void FormAchievements::on_CheckBoxCompareTotalPercent_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnWorld,arg1==0);
    ui->TableWidgetCompareAchievements->setColumnHidden(c_tableCompareColumnWorld,arg1==0);
}
#define HideColumnsEnd }
#define Categorys {
void FormAchievements::on_ButtonAddValueCategory_clicked(){
    if((_typeCategory==CategoryType::add)||(_typeCategory==CategoryType::change)){
        ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()+1);
        ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem());
        for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
            QTableWidgetItem *pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, pItem);
            }
        int row = _categoryValuesLayout->rowCount();
        FormCategoryValue *value = new FormCategoryValue(row);
        _values.append(value);
        switch (row) {
            case 0:
                value->SetEnabledUpDown(EnabledUpDown::none);
                break;
            case 1:
                _values[row-1]->SetEnabledUpDown(EnabledUpDown::down);
                value->SetEnabledUpDown(EnabledUpDown::up);
                break;
            default:
                _values[row-1]->SetEnabledUpDown(EnabledUpDown::both);
                value->SetEnabledUpDown(EnabledUpDown::up);
        }
        connect(value,&FormCategoryValue::s_valuechange,this,&FormAchievements::on_FormCategoryValueChange);
        connect(value,&FormCategoryValue::s_visiblechange,this,&FormAchievements::on_FormCategoryVisibleChange);
        connect(value,&FormCategoryValue::s_positionchange,this,&FormAchievements::on_FormCategoryPositionChange);
        connect(value,&FormCategoryValue::s_selectchange,this,&FormAchievements::on_FormCategorySelectChange);
        connect(value,&FormCategoryValue::s_deleting,this,&FormAchievements::on_FormCategoryDeleting);
        _categoryValuesLayout->addRow(value);
    }
}
void FormAchievements::on_ButtonCancelCategory_clicked(){
    if(_typeCategory==CategoryType::add||_typeCategory==CategoryType::change){
        ui->GroupBoxCategories->setVisible(false);
        ui->ButtonAddCategory->setEnabled(true);
        QList<QString> list = _categoriesGame.GetTitles();
        ui->ButtonChangeCategory->setEnabled(list.size()!=0);
        ui->ButtonDeleteAllCategories->setEnabled(list.size()!=0);
        ui->ButtonCompare->setEnabled(true);
        while (!_categoryValuesLayout->isEmpty()) {
            _categoryValuesLayout->removeRow(0);
        }
        ui->LineEditTitleCategory->setText("");
        ui->ComboBoxCategoriesCategory->setCurrentIndex(0);
        _typeCategory=CategoryType::none;
        while(!_values.isEmpty())
            _values.remove(0);
        ui->TableWidgetAchievements->setColumnCount(c_tableAchievementColumnCount);
        //values.clear();
    }
}
void FormAchievements::on_ButtonAcceptCategory_clicked(){
    if(_typeCategory==CategoryType::add||_typeCategory==CategoryType::change){
        if(ui->LineEditTitleCategory->text()!=""){
            int targetCategory=-1;
            if(_typeCategory==CategoryType::change){
                targetCategory=ui->ComboBoxCategoriesCategory->currentIndex()-1;
            } else {
                targetCategory=_categoriesGame.GetCounts();
            }

            QList<QString> titles = _categoriesGame.GetTitles();
            bool accept=true;
            for(int i=0;i<titles.size();i++) {
                if((titles[i]==ui->LineEditTitleCategory->text())&&(i!=ui->ComboBoxCategoriesCategory->currentIndex()-1)){
                    accept=false;
                    break;
                }
            }
            if(accept){
                QJsonObject categoryNew;
                categoryNew["Title"]=ui->LineEditTitleCategory->text();
                QJsonArray valuesNew;
                QJsonArray noValuesNew;
                if(ui->CheckBoxCategoryOneValue->isChecked()){
                    categoryNew["IsNoValues"]=1;
                } else {
                    categoryNew["IsNoValues"]=0;
                    for(int i=c_tableAchievementColumnNoValue+1;i<ui->TableWidgetAchievements->columnCount();i++){
                        if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==""){
                            QMessageBox::warning(this,tr("Ошибка"),tr("Название значения пустое или повторяется!"));
                            return;
                            }
                        for(int j=c_tableAchievementColumnNoValue+1;j<i;j++){
                            if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->TableWidgetAchievements->horizontalHeaderItem(j)->text()){
                                QMessageBox::warning(this,tr("Ошибка"),tr("Название значения пустое или повторяется!"));
                                return;
                                }
                            }
                        }
                    }
                for(int j=0;j<ui->TableWidgetAchievements->rowCount();j++){
                    if(ui->TableWidgetAchievements->item(j,c_tableAchievementColumnNoValue)->checkState()){
                        noValuesNew.append(ui->TableWidgetAchievements->item(j,c_tableAchievementColumnAppid)->text());
                        }
                    }
                for(int i=c_tableAchievementColumnNoValue+1;i<ui->TableWidgetAchievements->columnCount();i++){
                    QJsonObject valueNew;
                    valueNew["Title"]=ui->TableWidgetAchievements->horizontalHeaderItem(i)->text();
                    QJsonArray achievementsNew;
                    for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                        if(ui->TableWidgetAchievements->item(j,i)->checkState()){
                            achievementsNew.append(ui->TableWidgetAchievements->item(j,c_tableAchievementColumnAppid)->text());
                            }
                    }
                    valueNew["Achievements"]=achievementsNew;
                    valuesNew.append(valueNew);
                    }
                categoryNew["Values"]=valuesNew;
                categoryNew["NoValues"]=noValuesNew;
                _categoriesGame.ChangeCategory(targetCategory,categoryNew);
                ui->LineEditTitleCategory->setText("");
                ui->LineEditTitleCategory->setEnabled(false);
                delete ui->ScrollAreaCategories->layout();
                delete ui->ScrollAreaCheckCategories->layout();
                ShowCategories();
                ui->LineEditNameAchievements->setText("");
                ui->RadioButtonAll->setChecked(true);
                ui->CheckBoxFavorites->setChecked(false);
                QMessageBox::information(this,tr("Успешно"),tr("Категория была %1!").arg(_typeCategory==CategoryType::add?tr("добавлена"):tr("изменена")));
                on_ButtonCancelCategory_clicked();
            } else
                QMessageBox::warning(this,tr("Ошибка"),tr("Такая категория уже есть!"));
        } else
            QMessageBox::warning(this,tr("Ошибка"),tr("Название категории пустое!"));
    }
}
void FormAchievements::on_ButtonDeleteCategory_clicked(){
    if(_typeCategory==CategoryType::change){
        QMessageBox::StandardButton btn=QMessageBox::question(this,tr("Внимание"),tr("Вы уверены, что хотите удалить категорию?"),QMessageBox::Yes|QMessageBox::No);
        if(btn==QMessageBox::No){
            return;
        }
        if(ui->ComboBoxCategoriesCategory->currentIndex()!=0){
            delete ui->ScrollAreaCategories->layout();
            delete ui->ScrollAreaCheckCategories->layout();
            _categoriesGame.DeleteCategory(ui->ComboBoxCategoriesCategory->currentIndex()-1);
            ShowCategories();
            ui->LineEditNameAchievements->setText("");
            ui->RadioButtonAll->setChecked(true);
            ui->CheckBoxFavorites->setChecked(false);
            QMessageBox::information(this,tr("Успешно"),tr("Категория была удалена!"));
            on_ButtonCancelCategory_clicked();
        }
    }
}
void FormAchievements::on_CheckBoxCategoryOneValue_stateChanged(int arg1){
    if(_typeCategory==CategoryType::add||_typeCategory==CategoryType::change){
        bool value;
        switch (arg1) {
            case 0:
                value=false;
                break;
            case 2:
                value=true;
        }
        ui->ButtonAddValueCategory->setEnabled(!value);
        ui->ScrollAreaValuesCategory->setEnabled(!value);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnNoValue,!value);
        for(int i=0;i<ui->TableWidgetAchievements->columnCount()-(c_tableAchievementColumnNoValue+1);i++) {
            ui->TableWidgetAchievements->setColumnHidden((c_tableAchievementColumnNoValue+1)+i,value);
        }
    }
}
void FormAchievements::on_LineEditTitleCategory_textChanged(const QString &arg1){
    if(ui->TableWidgetAchievements->columnCount()>c_tableAchievementColumnNoValue)
        ui->TableWidgetAchievements->horizontalHeaderItem(c_tableAchievementColumnNoValue)->setText(arg1);
}
void FormAchievements::on_ComboBoxCategoriesCategory_activated(int Aindex){
    if(_typeCategory==CategoryType::change){
        if(_categoriesGame.GetCounts()>0){
            ui->LineEditTitleCategory->setText(ui->ComboBoxCategoriesCategory->itemText(Aindex));
            while(!_categoryValuesLayout->isEmpty()){
                _categoryValuesLayout->removeRow(0);
            }
            ui->TableWidgetAchievements->setColumnCount(c_tableAchievementColumnNoValue);
            if(Aindex!=0){
                ui->ButtonAddValueCategory->setEnabled(true);
                ui->TableWidgetAchievements->setColumnCount((c_tableAchievementColumnNoValue+1));
                ui->LineEditTitleCategory->setEnabled(true);
                QList<QString> noValues = _categoriesGame.GetNoValues(Aindex-1);
                ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnNoValue,new QTableWidgetItem(_categoriesGame.GetTitle(Aindex-1)));
                for(int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                    QTableWidgetItem *pItem(new QTableWidgetItem(tr("Add")));
                    pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
                    bool accept=true;
                    for(int k=0;k<noValues.size();k++) {
                        if(ui->TableWidgetAchievements->item(j,c_tableAchievementColumnAppid)->text()==noValues[k]){
                            accept=false;
                            break;
                        }
                    }
                    pItem->setCheckState(accept?Qt::Unchecked:Qt::Checked);
                    ui->TableWidgetAchievements->setItem(j,c_tableAchievementColumnNoValue, pItem);
                }
                QJsonArray valuess = _categoriesGame.GetValues(Aindex-1);
                _values.clear();
                for(int i=0;i<valuess.size();i++) {
                    int row = _categoryValuesLayout->rowCount();
                    FormCategoryValue *value = new FormCategoryValue(row);
                    _values.append(value);
                    switch (row) {
                        case 0:
                            value->SetEnabledUpDown(EnabledUpDown::none);
                            break;
                        case 1:
                            _values[row-1]->SetEnabledUpDown(EnabledUpDown::down);
                            value->SetEnabledUpDown(EnabledUpDown::up);
                            break;
                        default:
                            _values[row-1]->SetEnabledUpDown(EnabledUpDown::both);
                            value->SetEnabledUpDown(EnabledUpDown::up);
                    }
                    connect(value,&FormCategoryValue::s_valuechange,this,&FormAchievements::on_FormCategoryValueChange);
                    connect(value,&FormCategoryValue::s_visiblechange,this,&FormAchievements::on_FormCategoryVisibleChange);
                    connect(value,&FormCategoryValue::s_positionchange,this,&FormAchievements::on_FormCategoryPositionChange);
                    connect(value,&FormCategoryValue::s_selectchange,this,&FormAchievements::on_FormCategorySelectChange);
                    connect(value,&FormCategoryValue::s_deleting,this,&FormAchievements::on_FormCategoryDeleting);

                    ui->TableWidgetAchievements->insertColumn(ui->TableWidgetAchievements->columnCount());
                    ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem(valuess[i].toObject().value("Title").toString()));
                    _categoryValuesLayout->addRow(value);
                    value->SetTitle(valuess[i].toObject().value("Title").toString());
                    for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                        QTableWidgetItem *pItem(new QTableWidgetItem(tr("Add")));
                        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
                        bool accept=true;
                        for (int k=0;k<valuess[i].toObject().value("Achievements").toArray().size();k++) {
                            if(ui->TableWidgetAchievements->item(j,c_tableAchievementColumnAppid)->text()==valuess[i].toObject().value("Achievements").toArray().at(k).toString()){
                                accept=false;
                                break;
                            }
                        }
                        pItem->setCheckState(accept?Qt::Unchecked:Qt::Checked);
                        ui->TableWidgetAchievements->setItem(j,ui->TableWidgetAchievements->columnCount()-1, pItem);
                    }
                }
                if(_categoriesGame.GetIsNoValues(Aindex-1)==1){
                    ui->CheckBoxCategoryOneValue->setChecked(true);
                    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnNoValue,false);
                    for(int i=0;i<ui->TableWidgetAchievements->columnCount()-(c_tableAchievementColumnNoValue+1);i++)
                        ui->TableWidgetAchievements->setColumnHidden((c_tableAchievementColumnNoValue+1)+i,true);
                } else {
                    ui->CheckBoxCategoryOneValue->setChecked(false);
                    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnNoValue,true);
                    for(int i=0;i<ui->TableWidgetAchievements->columnCount()-(c_tableAchievementColumnNoValue+1);i++)
                        ui->TableWidgetAchievements->setColumnHidden((c_tableAchievementColumnNoValue+1)+i,false);
                }
            } else
                ui->ButtonAddValueCategory->setEnabled(false);
        }
    }
}
void FormAchievements::on_CheckBoxCategoryVisibleAll_clicked(){
    bool ch = ui->CheckBoxCategoryVisibleAll->isChecked();
    for (int i=0;i<_values.size();
         _values[i++]->SetVisible(ch));
}
#define CategorysValues {
void FormAchievements::on_FormCategoryValueChange(int Apos, QString Avalue){
    ui->TableWidgetAchievements->horizontalHeaderItem((c_tableAchievementColumnNoValue+1)+Apos)->setText(Avalue);
}
void FormAchievements::on_FormCategoryVisibleChange(int Apos, bool Avisible){
    bool accept=true;
    for (int i=0;i<_values.size();i++) {
        if(!_values[i]->GetVisible()){
            accept=false;
            break;
        }
    }
    if(accept)
        ui->CheckBoxCategoryVisibleAll->setCheckState(Qt::Checked);
    else
        ui->CheckBoxCategoryVisibleAll->setCheckState(Qt::Unchecked);
    ui->TableWidgetAchievements->setColumnHidden((c_tableAchievementColumnNoValue+1)+Apos,!Avisible);
}
void FormAchievements::on_FormCategoryPositionChange(int Apos, int AposNew){
    if(AposNew<0||AposNew>ui->TableWidgetAchievements->columnCount()-(c_tableAchievementColumnNoValue+1)){
        QMessageBox::warning(this,"","Невозможно переместить значение");
    } else {
        for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
            Qt::CheckState pItem1 = ui->TableWidgetAchievements->item(j,(c_tableAchievementColumnNoValue+1)+Apos)->checkState();
            ui->TableWidgetAchievements->item(j,(c_tableAchievementColumnNoValue+1)+Apos)->setCheckState(
                        ui->TableWidgetAchievements->item(j,(c_tableAchievementColumnNoValue+1)+AposNew)->checkState());
            ui->TableWidgetAchievements->item(j,(c_tableAchievementColumnNoValue+1)+AposNew)->setCheckState(pItem1);
        }
        QString hh=ui->TableWidgetAchievements->horizontalHeaderItem((c_tableAchievementColumnNoValue+1)+Apos)->text();
        ui->TableWidgetAchievements->horizontalHeaderItem((c_tableAchievementColumnNoValue+1)+Apos)->setText(
                    ui->TableWidgetAchievements->horizontalHeaderItem((c_tableAchievementColumnNoValue+1)+AposNew)->text());
        ui->TableWidgetAchievements->horizontalHeaderItem((c_tableAchievementColumnNoValue+1)+AposNew)->setText(hh);

        std::swap(_values[Apos],_values[AposNew]);
        for (int i=0;i<_values.size();i++) {
            _categoryValuesLayout->addRow(_values[i]);
            _values[i]->SetPosition(i);
            if(_values.size()==1){
                _values[i]->SetEnabledUpDown(EnabledUpDown::none);
            } else if(_values.size()-1==i) {
                _values[i]->SetEnabledUpDown(EnabledUpDown::up);
            } else if(i==0) {
                _values[i]->SetEnabledUpDown(EnabledUpDown::down);
            } else {
                _values[i]->SetEnabledUpDown(EnabledUpDown::both);
            }
        }
    }
}
void FormAchievements::on_FormCategorySelectChange(int Apos, bool Aselect){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
        if(!ui->TableWidgetAchievements->isRowHidden(i))
            ui->TableWidgetAchievements->item(i,(c_tableAchievementColumnNoValue+1)+Apos)->setCheckState(Aselect?Qt::Checked:Qt::Unchecked);
    }
}
void FormAchievements::on_FormCategoryDeleting(int Apos){
    ui->TableWidgetAchievements->removeColumn((c_tableAchievementColumnNoValue+1)+Apos);
    _categoryValuesLayout->removeRow(Apos);
    _values.remove(Apos);
    for (int i=0;i<_values.size();i++) {
        _values[i]->SetPosition(i);
        if(_values.size()==1){
            _values[i]->SetEnabledUpDown(EnabledUpDown::none);
        } else if(_values.size()-1==i) {
            _values[i]->SetEnabledUpDown(EnabledUpDown::up);
        } else if(i==0) {
            _values[i]->SetEnabledUpDown(EnabledUpDown::down);
        } else {
            _values[i]->SetEnabledUpDown(EnabledUpDown::both);
        }
    }
}
#define CategoryValuesEnd }
#define CategoryEnd }
#define FilterEnd }

#define Function {
void FormAchievements::on_CheckBoxFavorites_stateChanged(int arg1){
    switch (arg1) {
        case 0:
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                _fAchievements.SetData(i,c_filterFavorite,true);
                _fCompare.SetData(i+2,c_filterFavorite,true);
            }
            break;
        case 2:
            QJsonObject gameO;
            gameO["id"]=_game.GetAppid();
            gameO["name"]=_game.GetName();
            QJsonArray val=_favorites.GetValues(gameO);
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                bool accept=false;
                for (int j=0;j<val.size();j++) {
                    if(val[j].toObject().value("id").toString()==_achievements.GetApiname(i)){
                        accept=true;
                        break;
                    }
                }
                _fAchievements.SetData(i,c_filterFavorite,accept);
                _fCompare.SetData(i+2,c_filterFavorite,accept);
            }
    }
    UpdateHiddenRows();
}
#define FunctionEnd }
