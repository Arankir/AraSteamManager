#include "formachievements.h"
#include "ui_formachievements.h"
#define Constants {
constexpr int c_filterName=0;
constexpr int c_filterReached=1;
constexpr int c_filterFavorite=2;
constexpr int c_filterUniqueValue=3;
constexpr int c_filterColumnCount=4;
constexpr int c_filterEndConstValues=4;

constexpr int c_tableAchievementColumnAppid=0;
constexpr int c_tableAchievementColumnIcon=1;
constexpr int c_tableAchievementColumnTitle=2;
constexpr int c_tableAchievementColumnDescription=3;
constexpr int c_tableAchievementColumnWorld=4;
constexpr int c_tableAchievementColumnReachedMy=5;
constexpr int c_tableAchievementColumnCount=6;

constexpr int c_tableCategoryColumnNoValue=c_tableAchievementColumnCount;

constexpr int c_tableFriendsRowAvatars=0;
constexpr int c_tableFriendsRowCheckBox=1;
constexpr int c_tableFriendsRowFilters=2;
constexpr int c_tableFriendsRowID=3;
constexpr int c_tableFriendsRowCount=4;
#define ConstantsEnd }

#define Init {
FormAchievements::FormAchievements(SAchievementsPlayer a_player, QString a_id, SGame a_game, int a_unicNum, QWidget *parent):QWidget(parent),ui(new Ui::FormAchievements),
                                _id(a_id),_game(a_game),_unicNum(a_unicNum),_achievements(a_player),_categoriesGame(_game){
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
    ui->LineEditNameAchievements->setFocus();
}
void FormAchievements::InitComponents(){
    #define LoadData {
    SProfiles profile(_id,false,QueryType::url);
    QLabel *allFriends = new QLabel("All",this);
    allFriends->setToolTip(tr("Достижения друзей"));
    allFriends->setScaledContents(true);
    allFriends->setFixedSize(32,32);
    QLabel *avatarAchievementsCompare = new QLabel(this);
    avatarAchievementsCompare->setAlignment(Qt::AlignCenter);
    QLabel *avatarFriendsCompare = new QLabel(this);
    avatarFriendsCompare->setAlignment(Qt::AlignCenter);
    avatarFriendsCompare->setToolTip(profile.GetPersonaname());
    new RequestImage(avatarAchievementsCompare,profile.GetAvatar(),this);
    new RequestImage(avatarFriendsCompare,profile.GetAvatar(),this);
    new RequestImage(ui->LabelGameLogo,"http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(_game._appID)+"/"+_game._img_logo_url+".jpg",this);
    #define LoadDataEnd }
    #define ConnectTables {
    _tableAchievements = new FormTablesHeaders(2,0,_game,_id,_achievements,TableType::standart,this);
    _tableAchievements->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    ui->LayoutTables->addWidget(_tableAchievements);
    _tableAchievements->ChangeHorizontalTitle(c_tableAchievementColumnReachedMy,profile.GetPersonaname());
    _tableAchievements->SetWidgetHorizontalHeader(0,c_tableAchievementColumnReachedMy,avatarAchievementsCompare);
    _tableAchievements->GetTableHH()->setRowHeight(0,33);
    #define ConnectTablesEnd }
    #define SetTableWidgetCompareFriendsSettings {
    ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setMinimumSize(0,180);
    ui->TableWidgetFriends->setColumnCount(2);
    ui->TableWidgetFriends->setRowCount(c_tableFriendsRowCount);
    ui->TableWidgetFriends->setRowHidden(c_tableFriendsRowID,true);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars,0,avatarFriendsCompare);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars,1,allFriends);

    QVBoxLayout *layoutReachedFilter = new QVBoxLayout(this);
    FilterMyProfile = new FormCompareProfileFilter(tr("Все достижения"),tr("Полученные достижения"),tr("Не полученные достижения"),this);
    connect(FilterMyProfile,&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickMy);
    layoutReachedFilter->addWidget(FilterMyProfile);
    ui->GroupBoxReachedFilter->setLayout(layoutReachedFilter);

    FormCompareProfileFilter *myFilter = new FormCompareProfileFilter(this);
    myFilter->setObjectName("FormCompareProfileFilterMy");
    connect(myFilter,&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickMy);
    #define SetRadioButtonFriendsAchievementsSettings {
    QWidget *widgetFriendsAchievementsFilter = new QWidget(this);
    QVBoxLayout *layoutFriendsAchievementsFilter = new QVBoxLayout(this);
    layoutFriendsAchievementsFilter->setMargin(1);
    layoutFriendsAchievementsFilter->setAlignment(Qt::AlignCenter);
    QButtonWithData *pbFriendsAllAchievements = new QButtonWithData("",this);
    pbFriendsAllAchievements->setObjectName("PBFriendsAll");
    pbFriendsAllAchievements->AddData("Appertain","Friends");
    pbFriendsAllAchievements->AddData("Type","All");
    pbFriendsAllAchievements->setChecked(true);
    layoutFriendsAchievementsFilter->addWidget(pbFriendsAllAchievements);
    connect(pbFriendsAllAchievements,&QPushButton::clicked,this,&FormAchievements::ButtonCompareAllFriendsReach_Clicked);
    QButtonWithData *pbFriendsReachedAchievements = new QButtonWithData("",this);
    pbFriendsReachedAchievements->setObjectName("PBFriendsReached");
    pbFriendsReachedAchievements->AddData("Appertain","Friends");
    pbFriendsReachedAchievements->AddData("Type","Reached");
    layoutFriendsAchievementsFilter->addWidget(pbFriendsReachedAchievements);
    connect(pbFriendsReachedAchievements,&QPushButton::clicked,this,&FormAchievements::ButtonCompareAllFriendsReach_Clicked);
    QButtonWithData *pbFriendsNotReachedAchievements = new QButtonWithData("",this);
    pbFriendsNotReachedAchievements->setObjectName("PBFriendsNotReached");
    pbFriendsNotReachedAchievements->AddData("Appertain","Friends");
    pbFriendsNotReachedAchievements->AddData("Type","NotReached");
    connect(pbFriendsNotReachedAchievements,&QPushButton::clicked,this,&FormAchievements::ButtonCompareAllFriendsReach_Clicked);
    layoutFriendsAchievementsFilter->addWidget(pbFriendsNotReachedAchievements);
    widgetFriendsAchievementsFilter->setLayout(layoutFriendsAchievementsFilter);
    #define SetRadioButtonFriendsAchievementsSettingsEnd }
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters,0,myFilter);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters,1,widgetFriendsAchievementsFilter);
    ui->TableWidgetFriends->resizeRowsToContents();
    ui->TableWidgetFriends->resizeColumnsToContents();
    #define SetTableWidgetCompareFriendsSettingsEnd }
    #define SetIcon {
    ui->ButtonCompare->setIcon(QIcon("://"+_theme+"/compare.png"));
    //ui->GroupBoxFilter->setStyleSheet(""QGroupBox[accessibleName=\"Filter\"]::title {image:url(://"+_theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->GroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(://"+_theme+"/filter.png); image-position:left; margin-top:12px;}");
    ui->ButtonAddCategory->setIcon(QIcon("://create.png"));
    ui->ButtonChangeCategory->setIcon(QIcon("://"+_theme+"/change.png"));
    ui->ButtonDeleteCategory->setIcon(QIcon("://delete.png"));
    ui->ButtonDeleteAllCategories->setIcon(QIcon("://"+_theme+"/delete_all.png"));
    ui->ButtonFindAchievement->setIcon(QIcon("://"+_theme+"/find.png"));
    ui->ButtonAddValueCategory->setIcon(QIcon("://create.png"));
    ui->ButtonAcceptCategory->setIcon(QIcon("://apply.png"));
    ui->ButtonCancelCategory->setIcon(QIcon("://cancel.png"));
    ui->ButtonUpdate->setIcon(QIcon("://"+_theme+"/update.png"));
    ui->ButtonFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
    allFriends->setPixmap(QPixmap("://"+_theme+"/friends.png"));
    pbFriendsAllAchievements->setIcon(QIcon("://"+_theme+"/all.png"));
    pbFriendsReachedAchievements->setIcon(QIcon("://"+_theme+"/reached.png"));
    pbFriendsNotReachedAchievements->setIcon(QIcon("://"+_theme+"/notreached.png"));
    #define SetIconEnd }
    #define Connects {
    connect(ui->ButtonUpdate,&QPushButton::clicked,this,&FormAchievements::ButtonUpdate_Clicked);
    connect(ui->CheckBoxCompareAllFriends,&QPushButton::clicked,this,&FormAchievements::CheckBoxCompareAllFriends_StateChanged);
    connect(ui->LineEditNameAchievements,&QLineEdit::textChanged,this,&FormAchievements::LineEditNameAchievements_TextChanged);
    connect(ui->ButtonFindAchievement,&QPushButton::clicked,this,&FormAchievements::ButtonFindAchievement_Clicked);
    connect(ui->ButtonAddCategory,&QPushButton::clicked,this,&FormAchievements::ButtonAddCategory_Clicked);
    connect(ui->ButtonChangeCategory,&QPushButton::clicked,this,&FormAchievements::ButtonChangeCategory_Clicked);
    connect(ui->ButtonCompare,&QPushButton::clicked,this,&FormAchievements::ButtonCompare_Clicked);
    connect(ui->CheckBoxShowFilter,&QCheckBox::stateChanged,this,&FormAchievements::CheckBoxShowFilter_StateChanged);
    connect(ui->ButtonDeleteAllCategories,&QPushButton::clicked,this,&FormAchievements::ButtonDeleteAllCategories_Clicked);
    connect(ui->CheckBoxCompareIcon,&QCheckBox::stateChanged,_tableAchievements,[=](int arg1){_tableAchievements->SetVisibleColumn(c_tableAchievementColumnIcon,arg1==2);});
    connect(ui->CheckBoxCompareTitle,&QCheckBox::stateChanged,_tableAchievements,[=](int arg1){_tableAchievements->SetVisibleColumn(c_tableAchievementColumnTitle,arg1==2);});
    connect(ui->CheckBoxCompareDescription,&QCheckBox::stateChanged,_tableAchievements,[=](int arg1){_tableAchievements->SetVisibleColumn(c_tableAchievementColumnDescription,arg1==2);});
    connect(ui->CheckBoxCompareTotalPercent,&QCheckBox::stateChanged,_tableAchievements,[=](int arg1){_tableAchievements->SetVisibleColumn(c_tableAchievementColumnWorld,arg1==2);});
    connect(ui->ButtonAddValueCategory,&QPushButton::clicked,this,&FormAchievements::ButtonAddValueCategory_Clicked);
    connect(ui->ButtonAcceptCategory,&QPushButton::clicked,this,&FormAchievements::ButtonAcceptCategory_Clicked);
    connect(ui->ButtonCancelCategory,&QPushButton::clicked,this,&FormAchievements::ButtonCancelCategory_Clicked);
    connect(ui->ButtonDeleteCategory,&QPushButton::clicked,this,&FormAchievements::ButtonDeleteCategory_Clicked);
    connect(ui->CheckBoxCategoryOneValue,&QCheckBox::stateChanged,this,&FormAchievements::CheckBoxCategoryOneValue_StateChanged);
    connect(ui->LineEditTitleCategory,&QLineEdit::textChanged,this,&FormAchievements::LineEditTitleCategory_TextChanged);
    connect(ui->ComboBoxCategories,SIGNAL(activated(int i)),this,SLOT(ComboBoxCategories_Activated(int i)));
    connect(ui->CheckBoxCategoryVisibleAll,&QCheckBox::clicked,this,&FormAchievements::CheckBoxCategoryVisibleAll_Clicked);
    connect(ui->CheckBoxFavorites,&QCheckBox::stateChanged,this,&FormAchievements::CheckBoxFavorites_StateChanged);
    connect(ui->CheckBoxCategoryUniqueValue,&QCheckBox::stateChanged,this,&FormAchievements::CheckBoxCategoryUniqueValue_StateChanged);
    connect(ui->ButtonFavorite,&QPushButton::clicked,this,&FormAchievements::ButtonFavorite_Clicked);
    connect(_tableAchievements,&FormTablesHeaders::s_contentCellClicked,this,&FormAchievements::TableAchievements_CellClicked);
    #define ConnectsEnd }
    _favorites.SetType("achievements");
    Settings::CreateDir(_setting._pathImagesAchievements+QString::number(_game._appID));
    ui->GroupBoxCategories->setVisible(false);
    SwitchSimpleCompare(FormMode::compare);
    ui->ProgressBarFriendsLoad->setVisible(false);
    ui->LabelGameOnlineValue->setText(_game.GetNumberPlayers(false));
    ui->LabelGameTitle->setText(_game._name);
    ui->GroupBoxFilter->setEnabled(false);
    ui->ButtonCompare->setMinimumHeight(21);
    _achievements._appid=QString::number(_game._appID);
    _achievements._id=_id;
    _achievements.Set(SAchievementsPercentage(QString::number(_game._appID),false));
    connect(&_achievements,SIGNAL(s_finished()),this,SLOT(PullTableWidget()));
    Retranslate();
}
void FormAchievements::PullTableWidget(){
    if(_achievements.GetStatusFinish()==StatusValue::success){
        _tableAchievements->SetRowCount(_achievements.GetCount());
        for(int i=0;i<_achievements.GetCount();i++)
            _tableAchievements->SetRowHeight(i,65);
        _fAchievements.SetRow(_tableAchievements->GetRowCount());
        _fCompare.SetRow(_tableAchievements->GetRowCount());
        ShowCategories();
        Threading loadTable(this);
        QLabel *labelCompareSummary = new QLabel(this);
        _tableAchievements->SetWidgetHorizontalHeader(1,c_tableAchievementColumnReachedMy,labelCompareSummary);
        loadTable.AddThreadAchievements(c_tableAchievementColumnAppid, c_tableAchievementColumnTitle, c_tableAchievementColumnDescription, c_tableAchievementColumnWorld, c_tableAchievementColumnReachedMy,
                                        _achievements,ui->LabelTotalPersent,_tableAchievements->GetTableContent(),labelCompareSummary);
    } else {
        _tableAchievements->SetRowCount(1);
        _tableAchievements->SetItemHorizontalHeader(c_tableAchievementColumnAppid,1,new QTableWidgetItem(tr("Ошибка")));
        _tableAchievements->SetVisibleColumn(c_tableAchievementColumnTitle,false);
        _tableAchievements->SetVisibleColumn(c_tableAchievementColumnDescription,false);
        _tableAchievements->SetVisibleColumn(c_tableAchievementColumnWorld,false);
        _tableAchievements->SetVisibleColumn(c_tableAchievementColumnReachedMy,false);
        ui->GroupBoxFilter->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
    }
}
void FormAchievements::Retranslate(){
    ui->retranslateUi(this);
    FilterMyProfile->SetTitles(tr("Все достижения"),tr("Полученные достижения"),tr("Не полученные достижения"));
    _tableAchievements->ChangeHorizontalTitle(c_tableAchievementColumnIcon,"");
    _tableAchievements->ChangeHorizontalTitle(c_tableAchievementColumnTitle,tr("Название"));
    _tableAchievements->ChangeHorizontalTitle(c_tableAchievementColumnDescription,tr("Описание"));
    _tableAchievements->ChangeHorizontalTitle(c_tableAchievementColumnWorld,tr("По миру"));
    //_tableAchievements->ChangeHorizontalTitle(c_tableAchievementColumnReachedMy,tr("Получено"));
    ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars,1)->setToolTip(tr("Достижения друзей"));
    switch (_simpleCompare) {
        case FormMode::compare:
            ui->ButtonCompare->setText(tr("Обратно"));
            break;
        case FormMode::achievement:
            ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
            break;
    }
    switch (_typeCategory) {
        case CategoryType::add:
            ui->GroupBoxCategories->setTitle(tr("Добавить категорию"));
            break;
        case CategoryType::change:
            ui->GroupBoxCategories->setTitle(tr("Изменить категорию"));
            break;
        default:
            break;
    }
    _achievements.Set(SAchievementsGlobal(QString::number(_game._appID),false));
}
void FormAchievements::ProgressLoading(int a_progress,int a_row){
    //qDebug()<<"Loading..."<<a_progress;
//    QButtonWithData *buttonFavorite = new QButtonWithData("");
//    buttonFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
//    buttonFavorite->setObjectName("ButtonFavorites&"+QString::number(a_row));
//    buttonFavorite->AddData("NumberGame",QString::number(a_row));
//    connect(buttonFavorite,&QButtonWithData::pressed,this,&FormAchievements::FavoritesClicked);
//    ui->TableWidgetCategory->setCellWidget(a_row,c_tableAchievementColumnFavorite,buttonFavorite);
}
void FormAchievements::OnFinish(int reached, int notReached){
    ui->GroupBoxFilter->setEnabled(true);
    QLabel *labelCompareSummary = new QLabel(this);
    _tableAchievements->SetWidgetHorizontalHeader(1,c_tableAchievementColumnReachedMy,labelCompareSummary);
    ui->LabelTotalPersent->setText(QString("%1/%2 = %3%").arg(QString::number(reached),QString::number(reached+notReached),QString::number(100.0*reached/(reached+notReached))));
    labelCompareSummary->setText(QString("%1/%2\n%3%").arg(QString::number(reached),QString::number(reached+notReached),QString::number(100.0*reached/(reached+notReached))));
    _tableAchievements->GetTableContent()->resizeRowsToContents();
    int j=0;
    for(auto &achievement: _achievements){
        QString achievementIcon=achievement._icon.mid(66,achievement._icon.length());
        QString pathImage=_setting._pathImagesAchievements+QString::number(_game._appID)+"/"+achievementIcon.mid(achievementIcon.indexOf("/",1)+1,achievementIcon.length()-1);
        QLabel *iconGame = new QLabel(this);
        _tableAchievements->GetTableContent()->setCellWidget(j,c_tableAchievementColumnIcon,iconGame);
        if(achievement._displayName!=""){
            if(!QFile::exists(pathImage)){
                iconGame->setBaseSize(QSize(64,64));
                new RequestImage(iconGame,achievement._icon,pathImage,true,this);
            }  else {
                iconGame->setPixmap(QPixmap(pathImage));
            }
            _tableAchievements->GetTableContent()->resizeRowToContents(j);
            if(_tableAchievements->GetTableContent()->rowHeight(j)<64)
                _tableAchievements->GetTableContent()->setRowHeight(j,64);
            j++;
        } else {
            _tableAchievements->SetRowCount(_tableAchievements->GetRowCount()-1);
        }
    }
    FilterMyProfile->Update();
}
#define InitEnd }

#define SimpleCompare {
void FormAchievements::SwitchSimpleCompare(FormMode a_simpleCompare){
    switch (a_simpleCompare) {
        case FormMode::compare:{
            ui->GroupBoxReachedFilter->setVisible(true);
            _tableAchievements->SetType(TableType::standart);
            ui->CheckBoxCompareAllFriends->setVisible(false);
            ui->TableWidgetFriends->setVisible(false);
            ui->ButtonAddCategory->setVisible(true);
            ui->ButtonChangeCategory->setVisible(true);
            ui->ButtonDeleteAllCategories->setVisible(true);
            ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
            _simpleCompare=FormMode::achievement;
            break;
        }
    case FormMode::achievement:
            ui->GroupBoxReachedFilter->setVisible(false);
            _tableAchievements->SetType(TableType::compare);
            ui->CheckBoxCompareAllFriends->setVisible(true);
            ui->TableWidgetFriends->setVisible(true);
            ui->ButtonAddCategory->setVisible(false);
            ui->ButtonChangeCategory->setVisible(false);
            ui->ButtonDeleteAllCategories->setVisible(false);
            ui->ButtonCompare->setText(tr("Обратно"));
            switch (_loadCompare) {
            case 0:
                ui->TableWidgetFriends->setVisible(false);
                LoadingCompare();
                break;
            case 1:
                ui->TableWidgetFriends->setVisible(true);
                break;
            default:
                ui->TableWidgetFriends->setVisible(true);
            }
            _simpleCompare=FormMode::compare;
            break;
    }
}
void FormAchievements::LoadingCompare(){
    _loadCompare++;

    _profilesFriends = SFriends(_id,false).GetProfiles();
    ui->TableWidgetFriends->setColumnCount(_profilesFriends.GetCount()+2);
    for (int i=0;i<_profilesFriends.GetCount()+2;ui->TableWidgetFriends->setColumnWidth(i++,33));
    _profilesFriends.Sort();
    ui->ProgressBarFriendsLoad->setMaximum(_profilesFriends.GetCount());
    ui->ProgressBarFriendsLoad->setValue(0);
    ui->ProgressBarFriendsLoad->setVisible(true);

    int index = 0;
    for(auto &profileFriend: _profilesFriends){
        SGames *gamesFriend = new SGames(this);
        gamesFriend->_index=index++;
        gamesFriend->Set(profileFriend._steamID,true,true,true);
        connect(gamesFriend,SIGNAL(s_finished(SGames*)),this,SLOT(LoadFriendGames(SGames*)));
    }
}
void FormAchievements::LoadFriendGames(SGames *a_games){
    disconnect(a_games,SIGNAL(s_finished(SGames*)),this,SLOT(LoadFriendGames(SGames*)));
    bool isGameExist=false;
    for (const auto &game: *a_games) {
        if(game._appID==_game._appID){
            isGameExist=true;
            break;
        }
    }
    QPair<SProfile,FriendType> friendState;
    friendState.first=_profilesFriends[a_games->_index];
    if(isGameExist){
        friendState.second=FriendType::haveGame;
        _type1++;
    } else {
        friendState.second=FriendType::haventGame;
        _type2++;
    }
    _friends.push_back(std::move(friendState));
    ui->ProgressBarFriendsLoad->setValue(ui->ProgressBarFriendsLoad->value()+1);
    if(ui->ProgressBarFriendsLoad->value()==_profilesFriends.GetCount())
        FinishLoadFriends();

}
void FormAchievements::FinishLoadFriends(){
    ui->ProgressBarFriendsLoad->setVisible(false);
    int row=2;
    for(auto &friendP: _friends){
        QLabel *avatarFriend = new QLabel(this);
        avatarFriend->setToolTip(friendP.first._personaName);
        avatarFriend->setAlignment(Qt::AlignCenter);
        new RequestImage(avatarFriend,friendP.first._avatar,this);
        ui->TableWidgetFriends->setCellWidget(0,row,avatarFriend);
        QTableWidgetItem *itemCheck(new QTableWidgetItem(""));
        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
        itemCheck->setCheckState(Qt::Unchecked);
        itemCheck->setTextAlignment(Qt::AlignCenter);
        ui->TableWidgetFriends->setItem(c_tableFriendsRowCheckBox,row,itemCheck);
        ui->TableWidgetFriends->setItem(c_tableFriendsRowID,row,new QTableWidgetItem(friendP.first._steamID));
        ui->TableWidgetFriends->setColumnHidden(row,friendP.second==FriendType::haventGame);
        row++;
    }
    connect(ui->TableWidgetFriends,&QTableWidget::cellChanged,this,&FormAchievements::TableWidgetCompareFriends_CellChanged);
    //ui->TableWidgetFriends->resizeColumnsToContents();
    _loadCompare++;
    ui->TableWidgetFriends->setVisible(true);
}
void FormAchievements::CompareProfileFilterClickMy(QString, ReachedType a_type){
    switch (a_type) {
        case ReachedType::all:
            for(int i=0;i<_tableAchievements->GetRowCount();i++){
                _fAchievements.SetData(i,c_filterReached,true);
                _fCompare.SetData(i,c_filterReached,true);
            }
            break;
        case ReachedType::reached:
            for(int i=0;i<_tableAchievements->GetRowCount();i++){
                _fAchievements.SetData(i,c_filterReached,_tableAchievements->ItemContent(i,c_tableAchievementColumnReachedMy)->text().indexOf(".")>-1);
                _fCompare.SetData(i,c_filterReached,_tableAchievements->ItemContent(i,c_tableAchievementColumnReachedMy)->text().indexOf(".")>-1);
            }
            break;
        case ReachedType::notReached:
            for(int i=0;i<_tableAchievements->GetRowCount();i++){
                _fAchievements.SetData(i,c_filterReached,_tableAchievements->ItemContent(i,c_tableAchievementColumnReachedMy)->text().indexOf(".")==-1);
                _fCompare.SetData(i,c_filterReached,_tableAchievements->ItemContent(i,c_tableAchievementColumnReachedMy)->text().indexOf(".")==-1);
            }
            break;
        default:
            break;
    }
    UpdateHiddenRows();
}
void FormAchievements::CompareProfileFilterClickFriends(QString a_name, ReachedType a_type){
    QString name=dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(0,a_name.toInt()))->toolTip();
    int columnFriend=0;
    for(int i=c_tableAchievementColumnCount;i<_tableAchievements->GetColumnCount();i++) {
        if(_tableAchievements->GetTableHH()->horizontalHeaderItem(i)->text()==name){
            columnFriend=i;
            break;
        }
    }
    int filtercol=_fCompare.GetCol()-(_tableAchievements->GetColumnCount()-columnFriend);
    switch (a_type) {
        case ReachedType::all:
            for(int i=0;i<_tableAchievements->GetRowCount();i++){
                _fCompare.SetData(i,filtercol,true);
            }
            break;
        case ReachedType::reached:
            for(int i=0;i<_tableAchievements->GetRowCount();i++){
                _fCompare.SetData(i,filtercol,_tableAchievements->ItemContent(i,columnFriend)->text().indexOf(".")>-1);
            }
            break;
        case ReachedType::notReached:
            for(int i=0;i<_tableAchievements->GetRowCount();i++){
                _fCompare.SetData(i,filtercol,_tableAchievements->ItemContent(i,columnFriend)->text().indexOf(".")==-1);
            }
            break;
        default:
            break;
    }
    UpdateHiddenRows();
}
void FormAchievements::ButtonCompareAllFriendsReach_Clicked(){
    QButtonWithData *senderButton=static_cast<QButtonWithData*>(sender());
    ReachedType setType=ReachedType::none;
    if(senderButton->GetData(1)=="All"){
        setType = ReachedType::all;
    } else if(senderButton->GetData(1)=="Reached"){
        setType = ReachedType::reached;
    } else if(senderButton->GetData(1)=="NotReached"){
        setType = ReachedType::notReached;
    }
    for(int i=2;i<ui->TableWidgetFriends->columnCount();i++) {
        if(findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(i))){
            findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(i))->SetType(setType);
        }
    }
}
void FormAchievements::TableWidgetCompareFriends_CellChanged(int a_row, int a_column){
    if((a_row==1)&&(a_column>1)){
        int columnFriend=_tableAchievements->GetColumnCount();
        SProfile profileFriend=_friends[a_column-2].first;
        if(ui->TableWidgetFriends->item(a_row,a_column)->checkState()==Qt::Checked){
            if(_tableAchievements->AddFriendColumn(profileFriend)){
                FormCompareProfileFilter *Filterfriend = new FormCompareProfileFilter(this);
                Filterfriend->setObjectName("FormCompareProfileFilterFriend"+QString::number(a_column));
                Filterfriend->SetName(QString::number(a_column));
                connect(Filterfriend,&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickFriends);
                ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters,a_column,Filterfriend);
                ui->TableWidgetFriends->resizeRowsToContents();
                ui->TableWidgetFriends->resizeColumnsToContents();
            }
//            Threading LoadFriendTable(this);
//            LoadFriendTable.AddThreadFriendAchievements(ui->TableWidgetAchievements,ach,col,c_tableCompareColumnAppid);
            _fCompare.SetCol(_fCompare.GetCol()+1);
            _tableAchievements->SetColumnWidth(columnFriend,80);
        } else {
            columnFriend=0;
            auto columns = _tableAchievements->GetFriendsColumns();
            int friendColumn=0;
            for (auto &column: columns) {
                if(_tableAchievements->GetTableHH()->horizontalHeaderItem(column)->text()==profileFriend._personaName){
                    columnFriend=column;
                    _tableAchievements->RemoveFriendColumn(friendColumn);
                    break;
                }
                friendColumn++;
            }
            if(findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(a_column))){
                disconnect(findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(a_column)),&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickFriends);
                ui->TableWidgetFriends->removeCellWidget(c_tableFriendsRowFilters,a_column);
                delete findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(a_column));
                ui->TableWidgetFriends->resizeColumnsToContents();
            }
            if(_fCompare.GetCol()>=columnFriend)
                _fCompare.RemoveCol(_fCompare.GetCol()-(_tableAchievements->GetColumnCount()-columnFriend+1));
            UpdateHiddenRows();
        }
    }
}
void FormAchievements::CreateCompareProfileFilter(bool a_accept, int a_column){
    if(a_accept){
        FormCompareProfileFilter *friendFilter = new FormCompareProfileFilter(this);
        friendFilter->setObjectName("FormCompareProfileFilterFriend"+QString::number(a_column));
        friendFilter->SetName(QString::number(a_column));
        connect(friendFilter,&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickFriends);
        ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters,a_column,friendFilter);
        ui->TableWidgetFriends->resizeRowsToContents();
        ui->TableWidgetFriends->resizeColumnsToContents();
    }
}
void FormAchievements::CheckBoxCompareAllFriends_StateChanged(int arg1){
    switch (arg1) {
        case 0:
            for (int i=0;i<_friends.size();i++)
                if(_friends[i].second==FriendType::haventGame)
                    ui->TableWidgetFriends->setColumnHidden(i+2,true);
            break;
        case 2:
            for (int i=0;i<_friends.size();i++)
                if(_friends[i].second==FriendType::haventGame)
                    ui->TableWidgetFriends->setColumnHidden(i+2,false);
            ui->TableWidgetFriends->resizeColumnsToContents();
            break;
    }
}

bool FormAchievements::SetFriendAchievements(SAchievements a_achievement, int a_col){
    int totalReach=0;
    int totalNotReach=0;
    for(int row=0;row<_tableAchievements->GetRowCount();row++){
        for(auto &achievement: a_achievement){
            if(achievement._apiName==_tableAchievements->ItemContent(row,c_tableAchievementColumnAppid)->text()){
                QTableWidgetItem *itemReached;
                if(achievement._achieved==1){
                    itemReached = new QTableWidgetItem(tr("Получено %1").arg(achievement._unlockTime.toString("yyyy.MM.dd hh:mm")));
                    itemReached->setToolTip(achievement._unlockTime.toString("yyyy.MM.dd hh:mm"));
                    totalReach++;
                    } else {
                    itemReached = new QTableWidgetItem(tr("Не получено"));
                    totalNotReach++;
                    }
                itemReached->setTextAlignment(Qt::AlignCenter);
                _tableAchievements->SetItemContent(row,a_col,itemReached);
                break;
            }
        }
    }
    if((totalReach==0)&&(totalNotReach==0)){
        _tableAchievements->SetItemHorizontalHeader(1,a_col, new QTableWidgetItem(QString("%1\n%2").arg(tr("Профиль не"),tr("публичный"))));
        return false;
        } else {
        _tableAchievements->SetItemHorizontalHeader(1,a_col, new QTableWidgetItem(QString("%1/%2\n%3%").arg(QString::number(totalReach),QString::number(totalReach+totalNotReach)
                                                                                                           ,QString::number(100.0*totalReach/(totalReach+totalNotReach)))));
        return true;
    }
}
#define SimpleCompareEnd }

#define System {
FormAchievements::~FormAchievements(){
    delete ui;
}
void FormAchievements::closeEvent(QCloseEvent*){
    emit s_return_to_games(_unicNum);
    this->deleteLater();
}
void FormAchievements::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        Retranslate();
    }
}
void FormAchievements::ShowCategories(){
    _categoriesGame.Update();
    QFormLayout *layoutComboBox = ui->layoutComboBoxCategories;
    QFormLayout *layoutCheckBox = ui->layoutCheckBoxCategories;
    while(ui->ComboBoxCategories->count()>1){
        ui->ComboBoxCategories->removeItem(1);
    }
    QList<QComboBoxWithData*> allComboBoxes = ui->ScrollAreaCategories->findChildren<QComboBoxWithData*>();
    QList<QCheckBoxWithData*> allCheckBoxes = ui->ScrollAreaCheckCategories->findChildren<QCheckBoxWithData*>();
    for (int i=0;i<_categoriesGame.GetCount();i++) {
        if(_categoriesGame.GetIsNoValues(i)){
            bool accept=false;
            for(QCheckBoxWithData *currentCheckBox: allCheckBoxes) {
                if(currentCheckBox->text()==_categoriesGame.GetTitle(i)){
                    allCheckBoxes.removeOne(currentCheckBox);
                    accept=true;
                    break;
                }
            }
            if(!accept){
                //Создать новый чекбокс
                QCheckBoxWithData *checkBoxCategoryNew = new QCheckBoxWithData(_categoriesGame.GetTitle(i),this);
                checkBoxCategoryNew->setObjectName("CheckBoxCategory"+QString::number(i));
                checkBoxCategoryNew->AddData("NumberCategory",QString::number(i));
                connect(checkBoxCategoryNew,&QCheckBoxWithData::stateChanged,this,&FormAchievements::CheckBoxCategory_StateChanged);
                layoutCheckBox->addRow(checkBoxCategoryNew);
            }
        } else {
            bool accept=false;
            for(QComboBoxWithData *currentComboBox: allComboBoxes) {
                qDebug()<<currentComboBox->GetData("TitleCategory")<<_categoriesGame.GetTitle(i);
                if(currentComboBox->GetData("TitleCategory")==_categoriesGame.GetTitle(i)){
                    QList<QString> values;
                    for(int j=currentComboBox->count()-1;j<_categoriesGame.GetValues(i).size();j++){
                        values.push_back(std::move(_categoriesGame.GetValues(i).at(j).toObject().value("Title").toString()));
                    }
                    for (int j=1;j<currentComboBox->count();j++) {
                        qDebug()<<"ShowCategories"<<i<<j<<currentComboBox->itemText(j)<<_categoriesGame.GetValues(i).at(j-1).toObject().value("Title").toString();
                        if(currentComboBox->itemText(j)!=_categoriesGame.GetValues(i).at(j-1).toObject().value("Title").toString()){
                            values.push_back(std::move(_categoriesGame.GetValues(i).at(j-1).toObject().value("Title").toString()));
                            currentComboBox->removeItem(j);
                        }
                    }
                    for(QString &item: values) {
                        currentComboBox->addItem(item);
                    }
                    allComboBoxes.removeOne(currentComboBox);
                    accept=true;
                    break;
                }
            }
            if(!accept){
                //Создать новый комбобокс
                QComboBoxWithData *comboBoxCategoryNew = new QComboBoxWithData(this);
                comboBoxCategoryNew->addItem(tr("Не выбрано"));
                QJsonArray values=_categoriesGame.GetValues(i);
                for(auto value: values){
                    comboBoxCategoryNew->addItem(value.toObject().value("Title").toString());
                }
                comboBoxCategoryNew->setObjectName("ComboBoxCategory"+QString::number(i));
                comboBoxCategoryNew->AddData("NumberCategory",QString::number(i));
                comboBoxCategoryNew->AddData("TitleCategory",_categoriesGame.GetTitle(i));
                connect(comboBoxCategoryNew,SIGNAL(currentIndexChanged(int)),this,SLOT(ComboBoxCategory_IndexChange(int)));
                layoutComboBox->addRow(new QLabel(_categoriesGame.GetTitle(i),this),comboBoxCategoryNew);
            }
        }
        ui->ComboBoxCategories->addItem(_categoriesGame.GetTitle(i));
    }

    for(QCheckBoxWithData *currentCheckBox: allCheckBoxes) {
        layoutCheckBox->removeRow(currentCheckBox);
    }
    for(QComboBoxWithData *currentComboBox: allComboBoxes) {
        layoutComboBox->removeRow(currentComboBox);
    }
    ui->ScrollAreaCategories->setHidden(layoutComboBox->rowCount()==0);
    ui->ScrollAreaCheckCategories->setHidden(layoutCheckBox->rowCount()==0);
    ui->ButtonChangeCategory->setEnabled(_categoriesGame.GetCount()!=0);
    ui->ButtonDeleteAllCategories->setEnabled(_categoriesGame.GetCount()!=0);

    _fAchievements.SetCol(_categoriesGame.GetCount()+c_filterColumnCount);
    _fCompare.SetCol(_categoriesGame.GetCount()+c_filterColumnCount+_tableAchievements->GetColumnCount()-c_tableAchievementColumnCount);
}
void FormAchievements::UpdateHiddenRows(){
    switch (_simpleCompare) {
    case FormMode::achievement:{
        if(_isUnique){
            for(int i=0;i<_tableAchievements->GetRowCount();i++){
                if(_fAchievements.GetData(i)){
                    bool isExist=false;
                    for (int j=c_tableAchievementColumnCount;j<_tableAchievements->GetColumnCount();j++) {
                        if(_tableAchievements->ItemContent(i,j)->checkState()==Qt::Checked){
                            isExist=true;
                            break;
                        }
                    }
                    _tableAchievements->SetVisibleRowContent(i,!isExist);
                } else {
                    _tableAchievements->SetVisibleRowContent(i,false);
                }
            }
        } else {
            for(int i=0;i<_tableAchievements->GetRowCount();i++){
                _tableAchievements->SetVisibleRowContent(i,_fAchievements.GetData(i));
            }
        }
        break;
    }
    case FormMode::compare:{
        for(int i=0;i<_tableAchievements->GetRowCount();i++) {
            _tableAchievements->SetVisibleRowContent(i,_fCompare.GetData(i));
        }
        break;
    }
    }
}

void FormAchievements::HideCheckedAchievement(QTableWidgetItem *a_item){
    if(a_item->column()>c_tableAchievementColumnCount){
        if(a_item->checkState()==Qt::Checked)
            _fAchievements.SetData(a_item->row(),c_filterUniqueValue,false);
    }
    UpdateHiddenRows();
}
FormCategoryValue *FormAchievements::CreateValueCategory(){
    int rowValues = ui->ListWidgetValuesCategory->count();//->rowCount();
    FormCategoryValue *newValue = new FormCategoryValue(rowValues,this);
    _values.append(std::move(newValue));
    UpdateValuesUpDown();
    connect(newValue,&FormCategoryValue::s_valuechange,this,&FormAchievements::FormCategoryValue_Change);
    connect(newValue,&FormCategoryValue::s_visiblechange,this,&FormAchievements::FormCategoryVisible_Change);
    connect(newValue,&FormCategoryValue::s_positionchange,this,&FormAchievements::FormCategoryPosition_Change);
    connect(newValue,&FormCategoryValue::s_selectchange,this,&FormAchievements::FormCategorySelect_Change);
    connect(newValue,&FormCategoryValue::s_deleting,this,&FormAchievements::FormCategoryDelete);
    connect(newValue,&FormCategoryValue::s_reverse,this,&FormAchievements::FormCategoryReverse);
    QListWidgetItem* item = new QListWidgetItem(ui->ListWidgetValuesCategory);
    item->setSizeHint(newValue->sizeHint());
    ui->ListWidgetValuesCategory->setItemWidget(item,newValue);
    return newValue;
}
#define SystemEnd }

#define Filter {
void FormAchievements::LineEditNameAchievements_TextChanged(const QString& a_newText){
    for(int i=0;i<_tableAchievements->GetRowCount();i++){
        _fAchievements.SetData(i,c_filterName,((_tableAchievements->ItemContent(i,c_filterName+2)->text().toLower().indexOf(a_newText.toLower())>-1)
                                               ||(_tableAchievements->ItemContent(i,c_tableAchievementColumnDescription)->text().toLower().indexOf(a_newText.toLower())>-1)));
        _fCompare.SetData(i,c_filterName,((_tableAchievements->ItemContent(i,c_filterName+2)->text().toLower().indexOf(a_newText.toLower())>-1)
                                            ||(_tableAchievements->ItemContent(i,c_tableAchievementColumnDescription)->text().toLower().indexOf(a_newText.toLower())>-1)));
    }
    UpdateHiddenRows();
}
void FormAchievements::ButtonFindAchievement_Clicked(){
    LineEditNameAchievements_TextChanged(ui->LineEditNameAchievements->text());
}
void FormAchievements::ButtonAddCategory_Clicked(){
    if(_typeCategory==CategoryType::none){
        _typeCategory=CategoryType::add;
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
        ui->CheckBoxCategoryOneValue->setChecked(false);

        ui->ComboBoxCategories->setVisible(false);
        ui->ButtonDeleteCategory->setVisible(false);
        ui->LineEditTitleCategory->setEnabled(true);
        ui->ButtonAddValueCategory->setEnabled(true);

        ui->GroupBoxCategories->setTitle(tr("Добавить категорию"));
        ui->GroupBoxCategories->setVisible(true);
        _tableAchievements->AddNoValueColumn();
        _tableAchievements->SetVisibleColumn(_tableAchievements->GetNoValueColumn(),false);
    }
}
void FormAchievements::ButtonChangeCategory_Clicked(){
    if(_typeCategory==CategoryType::none){
        _typeCategory=CategoryType::change;
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonDeleteAllCategories->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
        ui->CheckBoxCategoryOneValue->setChecked(false);

        ui->ComboBoxCategories->setVisible(true);
        ui->ButtonDeleteCategory->setVisible(true);
        ui->LineEditTitleCategory->setEnabled(false);
        ui->ButtonAddValueCategory->setEnabled(false);

        ui->GroupBoxCategories->setTitle(tr("Изменить категорию"));
        ui->GroupBoxCategories->setVisible(true);
    }
}
void FormAchievements::ButtonUpdate_Clicked(){
    _achievements.Update();
}
void FormAchievements::FavoritesClicked(){
    int achievementIndex=static_cast<QButtonWithData*>(sender())->GetData(0).toInt();
    QJsonObject gameObject;
    QJsonObject newValue;
    gameObject["id"]=_game._appID;
    gameObject["name"]=_game._name;
    newValue["id"]=_achievements[achievementIndex]._apiName;
    newValue["title"]=_achievements[achievementIndex]._displayName;
    newValue["description"]=_achievements[achievementIndex]._description;

    if(_favorites.AddValue(gameObject,newValue,true)){
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}
void FormAchievements::ButtonCompare_Clicked(){
    SwitchSimpleCompare(_simpleCompare);
}
void FormAchievements::CheckBoxShowFilter_StateChanged(int arg1){
    ui->GroupBoxFilter->setHidden(arg1==0);
}
void FormAchievements::ComboBoxCategory_IndexChange(int a_index){
    if(_categoriesGame.GetCount()>0){
        int categoryIndex = static_cast<QComboBoxWithData*>(sender())->GetData(0).toInt();
        if(a_index!=0){
            QList<QString> achievementsName = _categoriesGame.GetValues(categoryIndex,a_index-1);
            for(int i=0;i<_tableAchievements->GetRowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categoryIndex,false);
                _fCompare.SetData(i,c_filterEndConstValues+categoryIndex,false);
                for(auto &achievementName: achievementsName){
                    if(_tableAchievements->ItemContent(i,c_tableAchievementColumnAppid)->text()==achievementName){
                        _fAchievements.SetData(i,c_filterEndConstValues+categoryIndex,true);
                        _fCompare.SetData(i,c_filterEndConstValues+categoryIndex,true);
                        break;
                        }
                    }
            }
        } else {
            for(int i=0;i<_tableAchievements->GetRowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categoryIndex,true);
                _fCompare.SetData(i,c_filterEndConstValues+categoryIndex,true);
                }
        }
        UpdateHiddenRows();
    }
}
void FormAchievements::CheckBoxCategory_StateChanged(int a_index){
    if(_categoriesGame.GetCount()>0){
        int categorynum = static_cast<QCheckBoxWithData*>(sender())->GetData(0).toInt();
        if(a_index!=0){
            QList<QString> achievementsName = _categoriesGame.GetNoValues(categorynum);
            for(int i=0;i<_tableAchievements->GetRowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categorynum,false);
                _fCompare.SetData(i,c_filterEndConstValues+categorynum,false);
                for(auto &achievementName: achievementsName) {
                    if(_tableAchievements->ItemContent(i,c_tableAchievementColumnAppid)->text()==achievementName){
                        _fAchievements.SetData(i,c_filterEndConstValues+categorynum,true);
                        _fCompare.SetData(i,c_filterEndConstValues+categorynum,true);
                        break;
                        }
                    }
            }
        } else {
            for(int i=0;i<_tableAchievements->GetRowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categorynum,true);
                _fCompare.SetData(i,c_filterEndConstValues+categorynum,true);
                }
        }
        UpdateHiddenRows();
    }
}
void FormAchievements::ButtonDeleteAllCategories_Clicked(){
    QMessageBox deleteQuestion(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите удалить все категории?"));
    QAbstractButton *btnYes = deleteQuestion.addButton(tr("Да"),QMessageBox::YesRole);
    deleteQuestion.addButton(tr("Отмена"),QMessageBox::NoRole);
    deleteQuestion.exec();
    if(deleteQuestion.clickedButton()==btnYes){
        QMessageBox deleteSecondQuestion(QMessageBox::Question,
                               tr("Внимание!"),
                               tr("Данные о категориях будут утеряны навсегда, вы точно хотите удалить все категории?"));
        QAbstractButton *btnYess = deleteSecondQuestion.addButton(tr("Да"),QMessageBox::YesRole);
        deleteSecondQuestion.addButton(tr("Отмена"),QMessageBox::NoRole);
        deleteSecondQuestion.exec();
        if(deleteSecondQuestion.clickedButton()==btnYess){
            _categoriesGame.DeleteAll();
            ShowCategories();
        }
    }
}
#define Categorys {
void FormAchievements::ButtonAddValueCategory_Clicked(){
    if(_tableAchievements->GetType()==TableType::standart&&((_typeCategory==CategoryType::add)||(_typeCategory==CategoryType::change))){
        _tableAchievements->AddCategoryColumn();
        CreateValueCategory();
    }
}
void FormAchievements::ButtonCancelCategory_Clicked(){
    if(_typeCategory==CategoryType::add||_typeCategory==CategoryType::change){
        ui->GroupBoxCategories->setVisible(false);
        ui->ButtonAddCategory->setEnabled(true);
        ui->ButtonChangeCategory->setEnabled(_categoriesGame.GetCount()!=0);
        ui->ButtonDeleteAllCategories->setEnabled(_categoriesGame.GetCount()!=0);
        ui->ButtonCompare->setEnabled(true);
        ui->ListWidgetValuesCategory->clear();
        ui->LineEditTitleCategory->setText("");
        ui->ComboBoxCategories->setCurrentIndex(0);
        _typeCategory=CategoryType::none;
        while(!_values.isEmpty())
            _values.removeAt(0);
        _tableAchievements->SetColumnCount(c_tableAchievementColumnCount);
        CheckBoxCategoryUniqueValue_StateChanged(0);
        UpdateHiddenRows();
    }
}
void FormAchievements::ButtonAcceptCategory_Clicked(){
    if(_typeCategory==CategoryType::add||_typeCategory==CategoryType::change){
        if(ui->LineEditTitleCategory->text()!=""){
            int targetCategory=-1;
            if(_typeCategory==CategoryType::change){
                targetCategory=ui->ComboBoxCategories->currentIndex()-1;
            } else {
                targetCategory=_categoriesGame.GetCount();
            }

            QList<QString> titles = _categoriesGame.GetTitles();
            bool isUniqueTitle=true;
            for(int i=0;i<titles.size();i++) {
                if((titles[i]==ui->LineEditTitleCategory->text())&&(i!=ui->ComboBoxCategories->currentIndex()-1)){
                    isUniqueTitle=false;
                    break;
                }
            }
            if(isUniqueTitle){
                QJsonObject categoryNew;
                categoryNew["Title"]=ui->LineEditTitleCategory->text();
                QJsonArray valuesNew;
                QJsonArray noValuesNew;
                if(ui->CheckBoxCategoryOneValue->isChecked()){
                    categoryNew["IsNoValues"]=1;
                } else {
                    categoryNew["IsNoValues"]=0;
                    for(int i=c_tableCategoryColumnNoValue+1;i<_tableAchievements->GetColumnCount();i++){
                        if(_tableAchievements->GetTableContent()->horizontalHeaderItem(i)->text()==""){
                            QMessageBox::warning(this,tr("Ошибка"),tr("Название значения пустое!"));
                            return;
                            }
                        for(int j=c_tableCategoryColumnNoValue+1;j<i;j++){
                            if(_tableAchievements->GetTableContent()->horizontalHeaderItem(i)->text()==_tableAchievements->GetTableContent()->horizontalHeaderItem(j)->text()){
                                QMessageBox::warning(this,tr("Ошибка"),tr("Название значения повторяется!"));
                                return;
                                }
                            }
                        }
                    }
                for(int j=0;j<_tableAchievements->GetRowCount();j++){
                    if(_tableAchievements->ItemContent(j,c_tableCategoryColumnNoValue)->checkState()){
                        noValuesNew.append(std::move(_tableAchievements->ItemContent(j,c_tableAchievementColumnAppid)->text()));
                        }
                    }
                for(int i=c_tableCategoryColumnNoValue+1;i<_tableAchievements->GetColumnCount();i++){
                    QJsonObject valueNew;
                    valueNew["Title"]=_tableAchievements->GetTableContent()->horizontalHeaderItem(i)->text();
                    QJsonArray achievementsNew;
                    for (int j=0;j<_tableAchievements->GetRowCount();j++) {
                        if(_tableAchievements->ItemContent(j,i)->checkState()){
                            achievementsNew.append(std::move(_tableAchievements->ItemContent(j,c_tableAchievementColumnAppid)->text()));
                            }
                    }
                    valueNew["Achievements"]=achievementsNew;
                    valuesNew.append(std::move(valueNew));
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
                FilterMyProfile->SetType(ReachedType::all);
                ui->CheckBoxFavorites->setChecked(false);
                QMessageBox::information(this,tr("Успешно"),tr("Категория была %1!").arg(_typeCategory==CategoryType::add?tr("добавлена"):tr("изменена")));
                ButtonCancelCategory_Clicked();
            } else
                QMessageBox::warning(this,tr("Ошибка"),tr("Такая категория уже есть!"));
        } else
            QMessageBox::warning(this,tr("Ошибка"),tr("Название категории пустое!"));
    }
}
void FormAchievements::ButtonDeleteCategory_Clicked(){
    if(_typeCategory==CategoryType::change){
        QMessageBox::StandardButton btn=QMessageBox::question(this,tr("Внимание"),tr("Вы уверены, что хотите удалить категорию?"),QMessageBox::Yes|QMessageBox::No);
        if(btn==QMessageBox::No){
            return;
        }
        if(ui->ComboBoxCategories->currentIndex()!=0){
            _categoriesGame.DeleteCategory(ui->ComboBoxCategories->currentIndex()-1);
            ShowCategories();
            ui->LineEditNameAchievements->setText("");
            FilterMyProfile->SetType(ReachedType::all);
            ui->CheckBoxFavorites->setChecked(false);
            QMessageBox::information(this,tr("Успешно"),tr("Категория была удалена!"));
            ButtonCancelCategory_Clicked();
        }
    }
}
void FormAchievements::CheckBoxCategoryOneValue_StateChanged(int arg1){
    if(_typeCategory==CategoryType::add||_typeCategory==CategoryType::change){
        bool value=arg1==2;
        ui->ButtonAddValueCategory->setEnabled(!value);
        ui->ListWidgetValuesCategory->setEnabled(!value);
        _tableAchievements->SetVisibleColumn(c_tableCategoryColumnNoValue,value);
        for(int i=0;i<_tableAchievements->GetColumnCount()-(c_tableCategoryColumnNoValue+1);i++) {
            _tableAchievements->SetVisibleColumn((c_tableCategoryColumnNoValue+1)+i,!value);
        }
    }
}
void FormAchievements::CheckBoxCategoryUniqueValue_StateChanged(int arg1){
    switch (arg1) {
    case 0:
        disconnect(_tableAchievements->GetTableContent(),&QTableWidget::itemClicked,this,&FormAchievements::HideCheckedAchievement);
        _isUnique=false;
        for (int i=0;i<_tableAchievements->GetRowCount();i++) {
            _fAchievements.SetData(i,c_filterUniqueValue,true);
        }
        break;
    case 2:
        connect(_tableAchievements->GetTableContent(),&QTableWidget::itemClicked,this,&FormAchievements::HideCheckedAchievement);
        _isUnique=true;
        for (int i=0;i<_tableAchievements->GetRowCount();i++) {
            for(int j=c_tableCategoryColumnNoValue+1;j<_tableAchievements->GetColumnCount();j++)
                if(_tableAchievements->ItemContent(i,j)->checkState()==Qt::Checked)
                    _fAchievements.SetData(i,c_filterUniqueValue,false);
        }
        break;
    }
    UpdateHiddenRows();
}
void FormAchievements::LineEditTitleCategory_TextChanged(const QString &arg1){
    if(_tableAchievements->GetColumnCount()>c_tableCategoryColumnNoValue)
        _tableAchievements->ChangeHorizontalTitle(c_tableCategoryColumnNoValue,arg1);
}
void FormAchievements::ComboBoxCategories_Activated(int a_index){
    if(_typeCategory==CategoryType::change){
        if(_categoriesGame.GetCount()>0){
            ui->LineEditTitleCategory->setText(ui->ComboBoxCategories->itemText(a_index));
            ui->ListWidgetValuesCategory->clear();
            _tableAchievements->SetColumnCount(c_tableCategoryColumnNoValue+1);
            if(a_index!=0){
                ui->ButtonAddValueCategory->setEnabled(true);
                ui->LineEditTitleCategory->setEnabled(true);
                QList<QString> noValues = _categoriesGame.GetNoValues(a_index-1);
                _tableAchievements->ChangeHorizontalTitle(c_tableCategoryColumnNoValue,_categoriesGame.GetTitle(a_index-1));
                for(int j=0;j<_tableAchievements->GetRowCount();j++) {
                    QTableWidgetItem *itemCheck = new QTableWidgetItem(tr("Add"));
                    itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
                    bool isAchievementCheck=true;
                    for(int k=0;k<noValues.size();k++) {
                        if(_tableAchievements->ItemContent(j,c_tableAchievementColumnAppid)->text()==noValues[k]){
                            isAchievementCheck=false;
                            break;
                        }
                    }
                    itemCheck->setCheckState(isAchievementCheck?Qt::Unchecked:Qt::Checked);
                    _tableAchievements->SetItemContent(j,c_tableCategoryColumnNoValue, itemCheck);
                }
                QJsonArray valuesTitles = _categoriesGame.GetValues(a_index-1);
                while(!_values.isEmpty())
                    _values.removeAt(0);
                for(auto title: valuesTitles){
                    FormCategoryValue *value = CreateValueCategory();
                    _tableAchievements->AddCategoryColumn();
                    _tableAchievements->ChangeHorizontalTitle(_tableAchievements->GetColumnCount()-1,title.toObject().value("Title").toString());
                    value->SetTitle(title.toObject().value("Title").toString());
                    for (int j=0;j<_tableAchievements->GetRowCount();j++) {
                        QTableWidgetItem *itemCheck = new QTableWidgetItem(tr("Add"));
                        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
                        bool isAchievementCheck=true;
                        for(auto appid: title.toObject().value("Achievements").toArray()){
                            if(_tableAchievements->ItemContent(j,c_tableAchievementColumnAppid)->text()==appid.toString()){
                                isAchievementCheck=false;
                                break;
                            }
                        }
                        itemCheck->setCheckState(isAchievementCheck?Qt::Unchecked:Qt::Checked);
                        _tableAchievements->SetItemContent(j,_tableAchievements->GetColumnCount()-1, itemCheck);
                    }
                }
                if(_categoriesGame.GetIsNoValues(a_index-1)==1){
                    ui->CheckBoxCategoryOneValue->setChecked(true);
                    _tableAchievements->SetVisibleColumn(c_tableCategoryColumnNoValue,true);
                    for(int i=0;i<_tableAchievements->GetColumnCount()-(c_tableCategoryColumnNoValue+1);i++)
                        _tableAchievements->SetVisibleColumn((c_tableCategoryColumnNoValue+1)+i,false);
                } else {
                    ui->CheckBoxCategoryOneValue->setChecked(false);
                    _tableAchievements->SetVisibleColumn(c_tableCategoryColumnNoValue,false);
                    for(int i=0;i<_tableAchievements->GetColumnCount()-(c_tableCategoryColumnNoValue+1);i++)
                        _tableAchievements->SetVisibleColumn((c_tableCategoryColumnNoValue+1)+i,true);
                }
            } else
                ui->ButtonAddValueCategory->setEnabled(false);
        }
    }
}
void FormAchievements::CheckBoxCategoryVisibleAll_Clicked(){
    bool check = ui->CheckBoxCategoryVisibleAll->isChecked();
    for(auto &value: _values){
        value->SetVisible(check);
    }
}
void FormAchievements::UpdateValuesUpDown(int a_value){
    if(a_value==-1){
        for (int i=0;i<_values.size();i++) {
            switch (i) {
                case 0:{
                    _values[i]->SetEnabledUpDown(_values.size()==0?EnabledUpDown::none:EnabledUpDown::down);
                    break;
                }
                default:{
                    _values[i]->SetEnabledUpDown(_values.size()-1==i?EnabledUpDown::up:EnabledUpDown::both);
                }
            }
        }
    } else {
        switch (a_value) {
            case 0:{
                _values[a_value]->SetEnabledUpDown(_values.size()==0?EnabledUpDown::none:EnabledUpDown::down);
                break;
            }
            default:{
                _values[a_value]->SetEnabledUpDown(_values.size()-1==a_value?EnabledUpDown::up:EnabledUpDown::both);
            }
        }
    }
}
#define CategorysValues {
void FormAchievements::FormCategoryValue_Change(int a_pos, QString a_value){
    _tableAchievements->ChangeHorizontalTitle((c_tableCategoryColumnNoValue+1)+a_pos,a_value);
}
void FormAchievements::FormCategoryVisible_Change(int a_pos, bool a_visible){
    bool isAllVisible=true;
    for(auto &value: _values){
        if(!value->GetVisible()){
            isAllVisible=false;
            break;
        }
    }
    ui->CheckBoxCategoryVisibleAll->setCheckState(isAllVisible?Qt::Checked:Qt::Unchecked);
    _tableAchievements->SetVisibleColumn((c_tableCategoryColumnNoValue+1)+a_pos,a_visible);
}
void FormAchievements::FormCategoryPosition_Change(int a_pos, int a_posNew){
    if(a_posNew<0||a_posNew>_tableAchievements->GetColumnCount()-(c_tableCategoryColumnNoValue+1)){
        QMessageBox::warning(this,"",tr("Невозможно переместить значение"));
    } else {
        for (int j=0;j<_tableAchievements->GetRowCount();j++) {
            Qt::CheckState tempCheckState = _tableAchievements->ItemContent(j,(c_tableCategoryColumnNoValue+1)+a_pos)->checkState();
            _tableAchievements->ItemContent(j,(c_tableCategoryColumnNoValue+1)+a_pos)->setCheckState(
                        _tableAchievements->ItemContent(j,(c_tableCategoryColumnNoValue+1)+a_posNew)->checkState());
            _tableAchievements->ItemContent(j,(c_tableCategoryColumnNoValue+1)+a_posNew)->setCheckState(tempCheckState);
        }
        QString tempHorisontalHeader=_tableAchievements->GetTableContent()->horizontalHeaderItem((c_tableCategoryColumnNoValue+1)+a_pos)->text();
        _tableAchievements->GetTableContent()->horizontalHeaderItem((c_tableCategoryColumnNoValue+1)+a_pos)->setText(
                    _tableAchievements->GetTableContent()->horizontalHeaderItem((c_tableCategoryColumnNoValue+1)+a_posNew)->text());
        _tableAchievements->GetTableContent()->horizontalHeaderItem((c_tableCategoryColumnNoValue+1)+a_posNew)->setText(tempHorisontalHeader);

        ui->ListWidgetValuesCategory->blockSignals(true);
        std::swap(_values[a_pos],_values[a_posNew]);
        //ui->ListWidgetValuesCategory->clear();
        //QWidget *item1 = ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(a_pos));
        //QWidget *item2 = ui->ListWidgetValuesCategory->itemWidget(ui->ListWidgetValuesCategory->item(a_posNew));
        //ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(a_pos),item2);
        //ui->ListWidgetValuesCategory->setItemWidget(ui->ListWidgetValuesCategory->item(a_posNew),item1);
        //исправить!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//        for (int i=0;i<_values.size();i++) {
//            QListWidgetItem *item = new QListWidgetItem(ui->ListWidgetValuesCategory);//ui->ListWidgetValuesCategory->takeItem(0);
//            ui->ListWidgetValuesCategory->removeItemWidget(item);
//            item->setSizeHint(_values[i]->sizeHint());
//            _values[i]->SetPosition(i);
//            UpdateValuesUpDown(i);
//            ui->ListWidgetValuesCategory->setItemWidget(item,_values[i]);
//            qDebug()<<i<<item;
//        }
        //обновить данные на ListWidget
        ui->ListWidgetValuesCategory->blockSignals(false);
    }
}
void FormAchievements::FormCategorySelect_Change(int a_pos, bool a_select){
    if(_isUnique){
        for (int i=0;i<_tableAchievements->GetRowCount();i++) {
            if(!_tableAchievements->GetTableContent()->isRowHidden(i)){
                _tableAchievements->ItemContent(i,(c_tableCategoryColumnNoValue+1)+a_pos)->setCheckState(a_select?Qt::Checked:Qt::Unchecked);
                _fAchievements.SetData(i,c_filterUniqueValue,!a_select);
            }
        }
    } else {
        for (int i=0;i<_tableAchievements->GetRowCount();i++) {
            if(!_tableAchievements->GetTableContent()->isRowHidden(i))
                _tableAchievements->ItemContent(i,(c_tableCategoryColumnNoValue+1)+a_pos)->setCheckState(a_select?Qt::Checked:Qt::Unchecked);
        }
    }
    UpdateHiddenRows();
}
void FormAchievements::FormCategoryDelete(int a_pos){
    _tableAchievements->RemoveCategoryColumn(a_pos);
    QListWidgetItem* item = ui->ListWidgetValuesCategory->item(a_pos);
    ui->ListWidgetValuesCategory->removeItemWidget(item);
    delete item;
    _values.removeAt(a_pos);
    int pos=0;
    for(auto &value: _values){
        value->SetPosition(pos);
        if(_values.size()==1){
            value->SetEnabledUpDown(EnabledUpDown::none);
        } else if(_values.size()-1==pos) {
            value->SetEnabledUpDown(EnabledUpDown::up);
        } else if(pos==0) {
            value->SetEnabledUpDown(EnabledUpDown::down);
        } else {
            value->SetEnabledUpDown(EnabledUpDown::both);
        }
        pos++;
    }
}
void FormAchievements::FormCategoryReverse(int a_pos){
    for (int i=0;i<_tableAchievements->GetRowCount();i++) {
        if(_tableAchievements->ItemContent(i,(c_tableCategoryColumnNoValue+1)+a_pos)->checkState()==Qt::Checked)
            _tableAchievements->ItemContent(i,(c_tableCategoryColumnNoValue+1)+a_pos)->setCheckState(Qt::Unchecked);
        else
            _tableAchievements->ItemContent(i,(c_tableCategoryColumnNoValue+1)+a_pos)->setCheckState(Qt::Checked);
    }
}
#define CategoryValuesEnd }
#define CategoryEnd }
#define FilterEnd }

#define Function {
void FormAchievements::CheckBoxFavorites_StateChanged(int arg1){
    switch (arg1) {
        case 0:
            for (int i=0;i<_tableAchievements->GetRowCount();i++){
                _fAchievements.SetData(i,c_filterFavorite,true);
                _fCompare.SetData(i,c_filterFavorite,true);
            }
            break;
        case 2:
            QJsonObject gameObject;
            gameObject["id"]=_game._appID;
            gameObject["name"]=_game._name;
            QJsonArray values=_favorites.GetValues(gameObject);
            for (int i=0;i<_tableAchievements->GetRowCount();i++){
                bool accept=false;
                for(auto value: values){
                    if(value.toObject().value("id").toString()==_achievements[i]._apiName){
                        accept=true;
                        break;
                    }
                }
                _fAchievements.SetData(i,c_filterFavorite,accept);
                _fCompare.SetData(i,c_filterFavorite,accept);
            }
    }
    UpdateHiddenRows();
}
void FormAchievements::ButtonFavorite_Clicked(){
    if(_currentAchievementIndex>-1){
        QJsonObject gameObject;
        QJsonObject newValue;
        gameObject["id"]=_game._appID;
        gameObject["name"]=_game._name;
        newValue["id"]=_achievements[_currentAchievementIndex]._apiName;
        newValue["title"]=_achievements[_currentAchievementIndex]._displayName;
        newValue["description"]=_achievements[_currentAchievementIndex]._description;
        ui->ButtonFavorite->setFixedSize(ui->ButtonFavorite->size());
        if(_favorites.AddValue(gameObject,newValue,true)){
            //Категория добавилась
            ui->ButtonFavorite->setIcon(QIcon("://"+_theme+"/in_favorites.png"));
        } else {
            //Категория уже есть (удалилась)
            ui->ButtonFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
        }
    }
}
#define FunctionEnd }

void FormAchievements::TableAchievements_CellClicked(int row, int){
    _currentAchievement=_tableAchievements->ItemContent(row,c_tableAchievementColumnAppid)->text();
    _currentAchievementIndex=row;
    QJsonObject gameObject;
    gameObject["id"]=_game._appID;
    gameObject["name"]=_game._name;
    QJsonArray favorites=_favorites.GetValues(gameObject);
    bool isFavorite=false;
    for(auto favorite: favorites){
        if(favorite.toObject().value("id").toString()==_currentAchievement){
            isFavorite=true;
            break;
        }
    }
    ui->ButtonFavorite->setFixedSize(ui->ButtonFavorite->size());
    if(isFavorite){
        ui->ButtonFavorite->setIcon(QIcon("://"+_theme+"/in_favorites.png"));
    } else {
        ui->ButtonFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
    }
}
