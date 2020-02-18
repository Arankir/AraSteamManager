#include "formachievements.h"
#include "ui_formachievements.h"
#define Constants {
const int c_filterName=0;
const int c_filterReached=1;
const int c_filterFavorite=2;
const int c_filterUniqueValue=3;
const int c_filterColumnCount=4;
const int c_filterEndConstValues=4;

const int c_tableAchievementColumnAppid=0;
const int c_tableAchievementColumnIcon=1;
const int c_tableAchievementColumnTitle=2;
const int c_tableAchievementColumnDescription=3;
const int c_tableAchievementColumnWorld=4;
const int c_tableAchievementColumnReachedMy=5;
const int c_tableAchievementColumnCount=6;

const int c_tableCategoryColumnNoValue=0;

const int c_tableFriendsRowAvatars=0;
const int c_tableFriendsRowCheckBox=1;
const int c_tableFriendsRowFilters=2;
const int c_tableFriendsRowID=3;
const int c_tableFriendsRowCount=4;
#define ConstantsEnd }

#define Init {
FormAchievements::FormAchievements(SAchievementsPlayer a_player, QString a_id, SGame a_game, int a_unicNum, QWidget *parent): QWidget(parent), ui(new Ui::FormAchievements){
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    _id=a_id;
    _game=a_game;
    _unicNum=a_unicNum;
    _achievements.Set(a_player);
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
    SProfile profileData(_id,false,QueryType::url);
    QLabel *profileAvatarCompare = new QLabel;
    profileAvatarCompare->setPixmap(RequestData(profileData.GetAvatar(),false).GetPixmap());
    profileAvatarCompare->setAlignment(Qt::AlignCenter);
    QLabel *profileAvatarFriend = new QLabel;
    profileAvatarFriend->setPixmap(RequestData(profileData.GetAvatar(),false).GetPixmap());
    profileAvatarFriend->setAlignment(Qt::AlignCenter);
    profileAvatarFriend->setToolTip(profileData.GetPersonaname());
    QLabel *allFriends = new QLabel("All");
    allFriends->setToolTip(tr("Достижения друзей"));
    allFriends->setScaledContents(true);
    allFriends->setFixedSize(32,32);
    #define LoadDataEnd }
    #define ConnectTables {
    connect(ui->TableWidgetHorizontalHeaderAchievements->horizontalHeader(),&QHeaderView::sectionResized,
            ui->TableWidgetAchievements->horizontalHeader(),[=](int logicalIndex, int, int newSize)
    {ui->TableWidgetAchievements->setColumnWidth(logicalIndex,newSize);});
//    connect(ui->TableWidgetHorizontalHeaderAchievements,&QTableWidget::hideColumn,
//            ui->TableWidgetAchievements,[=](int column)
//    {ui->TableWidgetAchievements->setColumnHidden(column,true);});
//    connect(ui->TableWidgetHorizontalHeaderAchievements,&QTableWidget::showColumn,
//            ui->TableWidgetAchievements,[=](int column)
//    {ui->TableWidgetAchievements->setColumnHidden(column,false);});
    connect(ui->TableWidgetAchievements->horizontalScrollBar(), &QScrollBar::rangeChanged,
            ui->TableWidgetHorizontalHeaderAchievements->horizontalScrollBar(), &QScrollBar::setRange);
    connect(ui->TableWidgetAchievements->horizontalScrollBar(), &QScrollBar::sliderMoved,
            ui->TableWidgetHorizontalHeaderAchievements->horizontalScrollBar(), &QScrollBar::setValue);
    connect(ui->TableWidgetAchievements->horizontalScrollBar(), &QScrollBar::valueChanged,
            ui->TableWidgetHorizontalHeaderAchievements->horizontalScrollBar(), &QScrollBar::setValue);
    connect(ui->TableWidgetAchievements->verticalScrollBar(), &QScrollBar::rangeChanged,
            ui->VerticalScrollBarTableAchievements, &QScrollBar::setRange);
    connect(ui->VerticalScrollBarTableAchievements, &QScrollBar::sliderMoved,
            ui->TableWidgetAchievements->verticalScrollBar(), &QScrollBar::setValue);
    connect(ui->VerticalScrollBarTableAchievements, &QScrollBar::valueChanged,
            ui->TableWidgetAchievements->verticalScrollBar(), &QScrollBar::setValue);

    connect(ui->VerticalScrollBarTableAchievements, &QScrollBar::sliderMoved,
            ui->TableWidgetCategory->verticalScrollBar(), &QScrollBar::setValue);
    connect(ui->VerticalScrollBarTableAchievements, &QScrollBar::valueChanged,
            ui->TableWidgetCategory->verticalScrollBar(), &QScrollBar::setValue);

    connect(ui->TableWidgetAchievements->verticalHeader(),&QHeaderView::sectionResized,
            ui->TableWidgetCategory->verticalHeader(),[=](int logicalIndex, int, int newSize)
    {ui->TableWidgetCategory->setRowHeight(logicalIndex,newSize);});
//    connect(ui->TableWidgetAchievements,&QTableWidget::hideRow,
//            ui->TableWidgetCategory,[=](int row)
//    {ui->TableWidgetCategory->setRowHidden(row,true);});
//    connect(ui->TableWidgetAchievements,&QTableWidget::showRow,
//            ui->TableWidgetCategory,[=](int row)
//    {ui->TableWidgetCategory->setRowHidden(row,false);});
    connect(ui->TableWidgetAchievements->verticalScrollBar(), &QScrollBar::rangeChanged,
            ui->TableWidgetCategory->verticalScrollBar(), &QScrollBar::setRange);
    connect(ui->TableWidgetAchievements->verticalScrollBar(), &QScrollBar::sliderMoved,
            ui->TableWidgetCategory->verticalScrollBar(), &QScrollBar::setValue);
    connect(ui->TableWidgetAchievements->verticalScrollBar(), &QScrollBar::valueChanged,
            ui->TableWidgetCategory->verticalScrollBar(), &QScrollBar::setValue);

    ui->TableWidgetHorizontalHeaderAchievements->setFixedHeight(ui->TableWidgetHorizontalHeaderAchievements->rowHeight(0)+40+15);
    #define ConnectTablesEnd }
    #define SetTableWidgetCategorySettings {
    ui->TableWidgetCategory->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetCategory->setSelectionMode(QAbstractItemView::NoSelection);
//    ui->TableWidgetCategory->setColumnCount(c_tableAchievementColumnCount);
//    ui->TableWidgetCategory->setHorizontalHeaderItem(c_tableAchievementColumnIcon,new QTableWidgetItem(""));
//    ui->TableWidgetCategory->setHorizontalHeaderItem(c_tableAchievementColumnTitle,new QTableWidgetItem(tr("Название")));
//    ui->TableWidgetCategory->setHorizontalHeaderItem(c_tableAchievementColumnDescription,new QTableWidgetItem(tr("Описание")));
//    ui->TableWidgetCategory->setHorizontalHeaderItem(c_tableAchievementColumnWorld,new QTableWidgetItem(tr("По миру")));
//    ui->TableWidgetCategory->setHorizontalHeaderItem(c_tableAchievementColumnReached,new QTableWidgetItem(tr("Получено")));
//    ui->TableWidgetCategory->setHorizontalHeaderItem(c_tableAchievementColumnFavorite,new QTableWidgetItem(tr("Избранное")));
//    ui->TableWidgetCategory->setColumnHidden(c_tableAchievementColumnAppid,true);
//    ui->TableWidgetCategory->setColumnWidth(c_tableAchievementColumnTitle,65);
//    ui->TableWidgetCategory->setColumnWidth(c_tableAchievementColumnTitle,100);
//    ui->TableWidgetCategory->setColumnWidth(c_tableAchievementColumnDescription,315);
//    ui->TableWidgetCategory->setColumnWidth(c_tableAchievementColumnReached,80);
//    ui->TableWidgetCategory->setColumnWidth(c_tableAchievementColumnFavorite,50);
    #define SetTableWidgetCategorySettingsEnd }
    #define SetTableWidgetAchievementsSettings {
    ui->TableWidgetAchievements->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetAchievements->setSelectionMode(QAbstractItemView::NoSelection);
    TableSetColumnCount(c_tableAchievementColumnCount);
    ui->TableWidgetHorizontalHeaderAchievements->setRowCount(2);
    ui->TableWidgetHorizontalHeaderAchievements->setCellWidget(0,c_tableAchievementColumnReachedMy,profileAvatarCompare);
    ui->TableWidgetHorizontalHeaderAchievements->setRowHeight(0,33);
    ui->TableWidgetHorizontalHeaderAchievements->setVerticalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetHorizontalHeaderAchievements->setVerticalHeaderItem(1,new QTableWidgetItem("%"));
    TableSetHorizontalHeaderText(c_tableAchievementColumnIcon,"");
    TableSetHorizontalHeaderText(c_tableAchievementColumnTitle,tr("Название"));
    TableSetHorizontalHeaderText(c_tableAchievementColumnDescription,tr("Описание"));
    TableSetHorizontalHeaderText(c_tableAchievementColumnWorld,tr("По миру"));
    TableSetHorizontalHeaderText(c_tableAchievementColumnReachedMy,profileData.GetPersonaname());
    TableSetColumnVisible(c_tableAchievementColumnAppid,false);
    ui->TableWidgetHorizontalHeaderAchievements->setColumnWidth(c_tableAchievementColumnIcon,65);
    ui->TableWidgetHorizontalHeaderAchievements->setColumnWidth(c_tableAchievementColumnTitle,100);
    ui->TableWidgetHorizontalHeaderAchievements->setColumnWidth(c_tableAchievementColumnDescription,315);
    ui->TableWidgetHorizontalHeaderAchievements->resizeColumnToContents(c_tableAchievementColumnWorld);
    ui->TableWidgetHorizontalHeaderAchievements->setColumnWidth(c_tableAchievementColumnReachedMy,80);
    #define SetTableWidgetAchievementsSettingsEnd }
    #define SetTableWidgetCompareFriendsSettings {
    ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setMinimumSize(0,180);
    ui->TableWidgetFriends->setColumnCount(2);
    ui->TableWidgetFriends->setRowCount(c_tableFriendsRowCount);
    ui->TableWidgetFriends->setRowHidden(c_tableFriendsRowID,true);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars,0,profileAvatarFriend);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars,1,allFriends);

    QVBoxLayout *layoutReachedFilter = new QVBoxLayout();
    FilterMyProfile = new FormCompareProfileFilter();
    connect(FilterMyProfile,&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickMy);
    FilterMyProfile->SetTitles(tr("Все достижения"),tr("Полученные достижения"),tr("Не полученные достижения"));
    layoutReachedFilter->addWidget(FilterMyProfile);
    ui->GroupBoxReachedFilter->setLayout(layoutReachedFilter);

    #define SetRadioButtonMyAchievementsSettings {
    FormCompareProfileFilter *myFilter = new FormCompareProfileFilter();
    myFilter->setObjectName("FormCompareProfileFilterMy");
    connect(myFilter,&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickMy);
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
    connect(pbFriendsAllAchievements,&QPushButton::clicked,this,&FormAchievements::on_ButtonCompareAllFriendsReach_clicked);
    QButtonWithData *pbFriendsReachedAchievements = new QButtonWithData("");
    pbFriendsReachedAchievements->setObjectName("PBFriendsReached");
    pbFriendsReachedAchievements->AddData("Appertain","Friends");
    pbFriendsReachedAchievements->AddData("Type","Reached");
    layoutFriendsAchievementsFilter->addWidget(pbFriendsReachedAchievements);
    connect(pbFriendsReachedAchievements,&QPushButton::clicked,this,&FormAchievements::on_ButtonCompareAllFriendsReach_clicked);
    QButtonWithData *pbFriendsNotReachedAchievements = new QButtonWithData("");
    pbFriendsNotReachedAchievements->setObjectName("PBFriendsNotReached");
    pbFriendsNotReachedAchievements->AddData("Appertain","Friends");
    pbFriendsNotReachedAchievements->AddData("Type","NotReached");
    connect(pbFriendsNotReachedAchievements,&QPushButton::clicked,this,&FormAchievements::on_ButtonCompareAllFriendsReach_clicked);
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
    //ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {background-image:url(images/filter_white.png)}");
    //ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(images/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->GroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(://"+_theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
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
    _favorites.SetPath("achievements");
    _setting.CreateFile(_setting._pathImagesAchievements+QString::number(_game.GetAppid()));
    _categoriesGame.Set(_game);
    ui->LabelGameLogo->setPixmap(RequestData("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                             QString::number(_game.GetAppid())+"/"+_game.GetImg_logo_url()+".jpg",false).GetPixmap());
    ui->GroupBoxCategories->setVisible(false);
    SwitchSimpleCompare(FormMode::compare);
    ui->ProgressBarFriendsLoad->setVisible(false);
    ui->LabelGameOnlineValue->setText(_game.GetNumberPlayers(false));
    ui->LabelGameTitle->setText(_game.GetName());
    ui->GroupBoxFilter->setEnabled(false);
    _achievements.SetIDs(QString::number(_game.GetAppid()),_id);
    _achievements.Set(SAchievementsPercentage(QString::number(_game.GetAppid()),false));
    connect(&_achievements,SIGNAL(s_finished()),this,SLOT(PullTableWidget()));
    Retranslate();
}
void FormAchievements::PullTableWidget(){
    if(_achievements.GetStatusFinish()==StatusValue::success){
        TableSetRowCount(_achievements.GetCount());
        for(int i=0;i<_achievements.GetCount();i++)
            ui->TableWidgetAchievements->setRowHeight(i,65);
        _fAchievements.SetRow(ui->TableWidgetAchievements->rowCount());
        _fCompare.SetRow(ui->TableWidgetAchievements->rowCount());
        ShowCategories(!_isFirstLoad);
        _isFirstLoad=false;
        Threading loadTable(this);
        QLabel *labelCompareSummary = new QLabel;
        ui->TableWidgetHorizontalHeaderAchievements->setCellWidget(1,c_tableAchievementColumnReachedMy,labelCompareSummary);
        loadTable.AddThreadAchievements(_achievements,ui->LabelTotalPersent,ui->TableWidgetAchievements,labelCompareSummary);
    } else {
        ui->TableWidgetAchievements->insertRow(0);
        ui->TableWidgetAchievements->setItem(c_tableAchievementColumnAppid,1,new QTableWidgetItem(tr("Ошибка")));
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnTitle,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnDescription,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnWorld,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnReachedMy,true);
        ui->GroupBoxFilter->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
    }
}
void FormAchievements::Retranslate(){
    ui->retranslateUi(this);
    FilterMyProfile->SetTitles(tr("Все достижения"),tr("Полученные достижения"),tr("Не полученные достижения"));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnIcon,new QTableWidgetItem(""));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnTitle,new QTableWidgetItem(tr("Название")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnDescription,new QTableWidgetItem(tr("Описание")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnWorld,new QTableWidgetItem(tr("По миру")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnReachedMy,new QTableWidgetItem(tr("Получено")));
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
    _achievements.Set(SAchievementsGlobal(QString::number(_game.GetAppid()),false));
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
void FormAchievements::OnFinish(){
    ui->GroupBoxFilter->setEnabled(true);
    ui->TableWidgetAchievements->resizeColumnToContents(c_tableAchievementColumnWorld);
    ui->TableWidgetAchievements->resizeRowsToContents();
    ui->TableWidgetAchievements->resizeColumnToContents(c_tableAchievementColumnIcon);
    int j=0;
    ui->TableWidgetAchievements->resizeRowsToContents();
    for (int i=0;i<_achievements.GetCount();i++) {
            QString achievementIcon=_achievements[i].GetIcon().mid(66,_achievements[i].GetIcon().length());
            QString pathImage=_setting._pathImagesAchievements+QString::number(_game.GetAppid())+"/"+achievementIcon.mid(achievementIcon.indexOf("/",1)+1,achievementIcon.length()-1);
            if(_achievements[i].GetDisplayname()!=""){
                if(!QFile::exists(pathImage)){
                    if(_numRequests<500){
                            RequestData *image = new RequestData(_achievements[i].GetIcon(),j,pathImage,true);
                            connect(image,&RequestData::s_finished,this,&FormAchievements::OnImageLoaded);
                            _request.append(image);
                            _numRequests++;
                            }
                        _numNow++;
                    }  else {
                        QLabel *achievementImage = new QLabel;
                        achievementImage->setPixmap(QPixmap(pathImage));
                        ui->TableWidgetAchievements->setCellWidget(j,c_tableAchievementColumnIcon,achievementImage);
                        ui->TableWidgetAchievements->resizeRowToContents(j);
                        ui->TableWidgetAchievements->resizeColumnToContents(c_tableAchievementColumnIcon);
                    }
                j++;
            } else {
                TableRemoveRow(ui->TableWidgetAchievements->rowCount()-1);
            }
        }
    FilterMyProfile->Update();
}
void FormAchievements::OnImageLoaded(RequestData *a_image){
    QPixmap image;
    image.loadFromData(a_image->GetAnswer());
    QLabel *achievementImage = new QLabel;
    achievementImage->setPixmap(image);
    QLabel *achievementImageCompare = new QLabel;
    achievementImageCompare->setPixmap(image);
    ui->TableWidgetAchievements->setCellWidget(a_image->GetRow(),c_tableAchievementColumnIcon,achievementImage);
    ui->TableWidgetAchievements->resizeRowToContents(a_image->GetRow());
    if(_numRequests==500&&_numNow<_achievements.GetCount()){
        QString achievementIcon=_achievements[_numNow].GetIcon().mid(66,_achievements[_numNow].GetIcon().length());
        QString pathImage=_setting._pathImagesAchievements+QString::number(_game.GetAppid())+"/"+achievementIcon.mid(achievementIcon.indexOf("/",1)+1,achievementIcon.length()-1);
        while (QFile::exists(pathImage))
            _numNow++;
        a_image->LoadImage(_achievements[_numNow].GetIcon(),_numNow,pathImage,true);
        _numNow++;
    } else {
        disconnect(a_image,&RequestData::s_finished,this,&FormAchievements::OnImageLoaded);
        a_image->deleteLater();
    }
}
#define InitEnd }

#define SimpleCompare {
void FormAchievements::SwitchSimpleCompare(FormMode a_simpleCompare){
    switch (a_simpleCompare) {
        case FormMode::compare:{
            ui->GroupBoxReachedFilter->setVisible(true);
            ui->TableWidgetCategory->setVisible(false);
            ui->CheckBoxCompareAllFriends->setVisible(false);
            ui->TableWidgetFriends->setVisible(false);
            ui->TableWidgetHorizontalHeaderAchievements->setVisible(false);
            ui->TableWidgetAchievements->verticalHeader()->setVisible(true);
            ui->TableWidgetAchievements->horizontalHeader()->setVisible(true);
            ui->ButtonAddCategory->setVisible(true);
            ui->ButtonChangeCategory->setVisible(true);
            ui->ButtonDeleteAllCategories->setVisible(true);
            ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
            _simpleCompare=FormMode::achievement;
            break;
        }
    case FormMode::achievement:
            ui->GroupBoxReachedFilter->setVisible(false);
            ui->TableWidgetCategory->setVisible(false);
            ui->CheckBoxCompareAllFriends->setVisible(true);
            ui->TableWidgetFriends->setVisible(true);
            ui->TableWidgetHorizontalHeaderAchievements->setVisible(true);
            ui->TableWidgetAchievements->verticalHeader()->setVisible(false);
            ui->TableWidgetAchievements->horizontalHeader()->setVisible(false);
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
    SProfile profile(_id,false,QueryType::url);
    ui->TableWidgetHorizontalHeaderAchievements->setHorizontalHeaderItem(c_tableAchievementColumnReachedMy,new QTableWidgetItem(profile.GetPersonaname()));
    QPixmap avatar = RequestData(profile.GetAvatar(),false).GetPixmap();
    QLabel *avatarAchievementsCompare = new QLabel;
    avatarAchievementsCompare->setPixmap(avatar);
    avatarAchievementsCompare->setAlignment(Qt::AlignCenter);
    ui->TableWidgetHorizontalHeaderAchievements->setCellWidget(0,c_tableAchievementColumnReachedMy,avatarAchievementsCompare);
    ui->TableWidgetHorizontalHeaderAchievements->resizeRowToContents(0);
    QLabel *avatarFriendsCompare = new QLabel;
    avatarFriendsCompare->setPixmap(avatar);
    avatarFriendsCompare->setAlignment(Qt::AlignCenter);
    avatarFriendsCompare->setToolTip(profile.GetPersonaname());
    ui->TableWidgetFriends->setCellWidget(0,c_tableFriendsRowAvatars,avatarFriendsCompare);

    _profilesFriends = SFriends(_id,false).GetProfiles();
    ui->TableWidgetFriends->setColumnCount(_profilesFriends.GetCount()+2);
    for (int i=0;i<_profilesFriends.GetCount();ui->TableWidgetFriends->setColumnWidth(i++,33));
    _profilesFriends.Sort();
    ui->ProgressBarFriendsLoad->setMaximum(_profilesFriends.GetCount());
    ui->ProgressBarFriendsLoad->setValue(0);
    ui->ProgressBarFriendsLoad->setVisible(true);

    for (int i=0;i<_profilesFriends.GetCount();i++) {
        SGames *gamesFriend = new SGames;
        gamesFriend->SetIndex(i);
        gamesFriend->Set(_profilesFriends[i].GetSteamid(),true,true,true);
        connect(gamesFriend,SIGNAL(s_finished(SGames*)),this,SLOT(LoadFriendGames(SGames*)));
    }
}
void FormAchievements::LoadFriendGames(SGames *a_games){
    disconnect(a_games,SIGNAL(s_finished(SGames*)),this,SLOT(LoadFriendGames(SGames*)));
    bool isGameExist=false;
    for (int i=0;i<a_games->GetCount();i++) {//Проверка на наличие игры
        if(a_games->GetAppid(i)==_game.GetAppid()){
            isGameExist=true;
            break;
        }
    }
    QPair<SProfile,FriendType> friendState;
    friendState.first=_profilesFriends[a_games->GetIndex()];
    if(isGameExist){
        friendState.second=FriendType::haveGame;
        _type1++;
    } else {
        friendState.second=FriendType::haventGame;
        _type2++;
    }
    _friends.push_back(friendState);
    ui->ProgressBarFriendsLoad->setValue(ui->ProgressBarFriendsLoad->value()+1);
    if(ui->ProgressBarFriendsLoad->value()==_profilesFriends.GetCount())
        FinishLoadFriends();

}
void FormAchievements::FinishLoadFriends(){
    ui->ProgressBarFriendsLoad->setVisible(false);
    for(int i=0;i<_friends.size();i++) {
        QLabel *avatarFriend = new QLabel;
        avatarFriend->setPixmap(RequestData(_friends[i].first.GetAvatar(),false).GetPixmap());
        avatarFriend->setToolTip(_friends[i].first.GetPersonaname());
        avatarFriend->setAlignment(Qt::AlignCenter);
        ui->TableWidgetFriends->setCellWidget(0,i+2,avatarFriend);
        QTableWidgetItem *itemCheck(new QTableWidgetItem(""));
        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
        itemCheck->setCheckState(Qt::Unchecked);
        itemCheck->setTextAlignment(Qt::AlignCenter);
        ui->TableWidgetFriends->setItem(c_tableFriendsRowCheckBox,i+2,itemCheck);
        ui->TableWidgetFriends->setItem(c_tableFriendsRowID,i+2,new QTableWidgetItem(_friends[i].first.GetSteamid()));
        ui->TableWidgetFriends->setColumnHidden(i+2,_friends[i].second==FriendType::haventGame);
    }
    connect(ui->TableWidgetFriends,&QTableWidget::cellChanged,this,&FormAchievements::on_TableWidgetCompareFriendsCellChanged);
    ui->TableWidgetFriends->resizeColumnsToContents();
    _loadCompare++;
    ui->TableWidgetFriends->setVisible(true);
}
void FormAchievements::CompareProfileFilterClickMy(QString, ReachedType a_type){
    switch (a_type) {
        case ReachedType::all:
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                _fAchievements.SetData(i,c_filterReached,true);
                _fCompare.SetData(i,c_filterReached,true);
            }
            break;
        case ReachedType::reached:
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                _fAchievements.SetData(i,c_filterReached,ui->TableWidgetAchievements->item(i,c_tableAchievementColumnReachedMy)->text().indexOf(".")>-1);
                _fCompare.SetData(i,c_filterReached,ui->TableWidgetAchievements->item(i,c_tableAchievementColumnReachedMy)->text().indexOf(".")>-1);
            }
            break;
        case ReachedType::notReached:
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                _fAchievements.SetData(i,c_filterReached,ui->TableWidgetAchievements->item(i,c_tableAchievementColumnReachedMy)->text().indexOf(".")==-1);
                _fCompare.SetData(i,c_filterReached,ui->TableWidgetAchievements->item(i,c_tableAchievementColumnReachedMy)->text().indexOf(".")==-1);
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
    for(int i=c_tableAchievementColumnCount;i<ui->TableWidgetAchievements->columnCount();i++) {
        if(ui->TableWidgetHorizontalHeaderAchievements->horizontalHeaderItem(i)->text()==name){
            columnFriend=i;
            break;
        }
    }
    int filtercol=_fCompare.GetCol()-(ui->TableWidgetAchievements->columnCount()-columnFriend);
    switch (a_type) {
        case ReachedType::all:
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                _fCompare.SetData(i,filtercol,true);
            }
            break;
        case ReachedType::reached:
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                _fCompare.SetData(i,filtercol,ui->TableWidgetAchievements->item(i,columnFriend)->text().indexOf(".")>-1);
            }
            break;
        case ReachedType::notReached:
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                _fCompare.SetData(i,filtercol,ui->TableWidgetAchievements->item(i,columnFriend)->text().indexOf(".")==-1);
            }
            break;
        default:
            break;
    }
    UpdateHiddenRows();
}
void FormAchievements::on_ButtonCompareAllFriendsReach_clicked(){
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
void FormAchievements::on_TableWidgetCompareFriendsCellChanged(int a_row, int a_column){
    if((a_row==1)&&(a_column>1)){
        int columnFriend=ui->TableWidgetAchievements->columnCount();
        SProfile profileFriend=_friends[a_column-2].first;
        if(ui->TableWidgetFriends->item(a_row,a_column)->checkState()==Qt::Checked){
            TableInsertColumn(columnFriend);
            ui->TableWidgetHorizontalHeaderAchievements->setHorizontalHeaderItem(columnFriend,new QTableWidgetItem(profileFriend.GetPersonaname()));
            QLabel *avatarFriend = new QLabel;
            avatarFriend->setPixmap(RequestData(_friends[a_column-2].first.GetAvatar(),false).GetPixmap());
            avatarFriend->setToolTip(_friends[a_column-2].first.GetPersonaname());
            avatarFriend->setAlignment(Qt::AlignCenter);
            ui->TableWidgetHorizontalHeaderAchievements->setCellWidget(0,columnFriend,avatarFriend);
            SAchievements achievementsFriends=_achievements;
            achievementsFriends.Set(SAchievementsPlayer(QString::number(_game.GetAppid()),profileFriend.GetSteamid(),false));
            if(SetFriendAchievements(achievementsFriends,columnFriend)){
                FormCompareProfileFilter *Filterfriend = new FormCompareProfileFilter();
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
            ui->TableWidgetHorizontalHeaderAchievements->setColumnWidth(columnFriend,80);
        } else {
            columnFriend=0;
            for(int i=c_tableAchievementColumnCount;i<ui->TableWidgetHorizontalHeaderAchievements->columnCount();i++) {
                if(ui->TableWidgetHorizontalHeaderAchievements->horizontalHeaderItem(i)->text()==profileFriend.GetPersonaname()){
                    columnFriend=i;
                    TableRemoveColumn(i);
                    break;
                }
            }
            if(findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(a_column))){
                disconnect(findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(a_column)),&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickFriends);
                ui->TableWidgetFriends->removeCellWidget(c_tableFriendsRowFilters,a_column);
                delete findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(a_column));
                ui->TableWidgetFriends->resizeColumnsToContents();
            }
            if(_fCompare.GetCol()>=columnFriend)
                _fCompare.RemoveCol(_fCompare.GetCol()-(ui->TableWidgetHorizontalHeaderAchievements->columnCount()-columnFriend+1));
            UpdateHiddenRows();
        }
    }
}
void FormAchievements::CreateCompareProfileFilter(bool a_accept, int a_column){
    if(a_accept){
        FormCompareProfileFilter *friendFilter = new FormCompareProfileFilter();
        friendFilter->setObjectName("FormCompareProfileFilterFriend"+QString::number(a_column));
        friendFilter->SetName(QString::number(a_column));
        connect(friendFilter,&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickFriends);
        ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters,a_column,friendFilter);
        ui->TableWidgetFriends->resizeRowsToContents();
        ui->TableWidgetFriends->resizeColumnsToContents();
    }
}
void FormAchievements::on_CheckBoxCompareAllFriends_stateChanged(int arg1){
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
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        int j=0;
        bool isAchievementExist=false;
        for(;j<a_achievement.GetCount();j++){
            if(a_achievement[j].GetApiname()==ui->TableWidgetAchievements->item(i,c_tableAchievementColumnAppid)->text()){
                isAchievementExist=true;
                break;
                }
        }
        if(isAchievementExist){
            QTableWidgetItem *itemReached;
            if(a_achievement[j].GetAchieved()==1){
                itemReached = new QTableWidgetItem(tr("Получено %1").arg(a_achievement[j].GetUnlocktime().toString("yyyy.MM.dd hh:mm")));
                itemReached->setToolTip(a_achievement[j].GetUnlocktime().toString("yyyy.MM.dd hh:mm"));
                totalReach++;
                } else {
                itemReached = new QTableWidgetItem(tr("Не получено"));
                totalNotReach++;
                }
            itemReached->setTextAlignment(Qt::AlignCenter);
            ui->TableWidgetAchievements->setItem(i,a_col,itemReached);
        }
        }
    if((totalReach==0)&&(totalNotReach==0)){
        ui->TableWidgetHorizontalHeaderAchievements->setItem(1,a_col, new QTableWidgetItem(QString("%1\n%2").arg(tr("Профиль не")).arg(tr("публичный"))));
        return false;
        } else {
        ui->TableWidgetHorizontalHeaderAchievements->setItem(1,a_col, new QTableWidgetItem(QString("%1/%2\n%3%").arg(QString::number(totalReach))
                                                                             .arg(QString::number(totalReach+totalNotReach))
                                                                             .arg(QString::number(100.0*totalReach/(totalReach+totalNotReach)))));
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
void FormAchievements::ShowCategories(bool a_saveDate){

    CategoriesGame oldCategories=_categoriesGame;
    _categoriesGame.Set(_game);
    if(a_saveDate){
        while(ui->ComboBoxCategoriesCategory->count()>1){
            ui->ComboBoxCategoriesCategory->removeItem(1);
        }
        for (int i=0;i<oldCategories.GetCount();i++) {
            if(oldCategories.GetIsNoValues(i)){
                QCheckBoxWithData *checkBoxCategory = findChild<QCheckBoxWithData*>("CheckBoxCategory"+QString::number(i));
                if(checkBoxCategory->text()!=oldCategories.GetTitle(i)){
                    bool checked=checkBoxCategory->isChecked();
                    delete checkBoxCategory;
                    QCheckBoxWithData *checkBoxCategoryNew = new QCheckBoxWithData(oldCategories.GetTitle(i));
                    checkBoxCategoryNew->setObjectName("CheckBoxCategory"+QString::number(i));
                    checkBoxCategoryNew->AddData("NumberCategory",QString::number(i));
                    connect(checkBoxCategoryNew,&QCheckBoxWithData::stateChanged,this,&FormAchievements::on_CheckBoxCategory_Change);
                    checkBoxCategoryNew->setCheckState(checked?Qt::Checked:Qt::Unchecked);
                    static_cast<QFormLayout*>(ui->ScrollAreaCheckCategories->layout())->addRow(checkBoxCategoryNew);
                }
            } else {
                QComboBoxWithData *comboBoxCategory = findChild<QComboBoxWithData*>("ComboBoxCategory"+QString::number(i));
                bool isEqual=true;
                for (int j=0;j<_categoriesGame.GetValues(i).count();j++) {
                    if(comboBoxCategory->itemText(j+1)!=_categoriesGame.GetValues(i).at(j).toObject().value("Title").toString()){
                        isEqual=false;
                        break;
                    }
                }
                if(!isEqual){
                    int currentIndex=comboBoxCategory->currentIndex();
                    delete comboBoxCategory;

                    QComboBoxWithData *comboBoxCategoryNew = new QComboBoxWithData;
                    comboBoxCategoryNew->addItem(tr("Не выбрано"));
                    QJsonArray values=_categoriesGame.GetValues(i);
                    for(int j=0;j<values.size();j++) {
                        comboBoxCategoryNew->addItem(values.at(j).toObject().value("Title").toString());
                    }
                    comboBoxCategoryNew->setObjectName("ComboBoxCategory"+QString::number(i));
                    comboBoxCategoryNew->AddData("NumberCategory",QString::number(i));
                    connect(comboBoxCategoryNew,SIGNAL(currentIndexChanged(int)),this,SLOT(on_ComboBoxCategory_Change(int)));
                    comboBoxCategoryNew->setCurrentIndex(currentIndex);
                    static_cast<QFormLayout*>(ui->ScrollAreaCategories->layout())->addRow(new QLabel(_categoriesGame.GetTitle(i)),comboBoxCategoryNew);
                }
            }
            ui->ComboBoxCategoriesCategory->addItem(_categoriesGame.GetTitle(i));
        }
    } else {
        while(ui->ComboBoxCategoriesCategory->count()>1){
            ui->ComboBoxCategoriesCategory->removeItem(1);
        }
        QFormLayout *layoutComboBox = new QFormLayout;
        QFormLayout *layoutCheckBox = new QFormLayout;
        for(int i=0; i<_categoriesGame.GetCount(); i++){
            if(_categoriesGame.GetIsNoValues(i)==1){
                QCheckBoxWithData *checkBoxCategory = new QCheckBoxWithData(_categoriesGame.GetTitle(i));
                checkBoxCategory->setObjectName("CheckBoxCategory"+QString::number(i));
                checkBoxCategory->AddData("NumberCategory",QString::number(i));
                connect(checkBoxCategory,&QCheckBoxWithData::stateChanged,this,&FormAchievements::on_CheckBoxCategory_Change);
                layoutCheckBox->addRow(checkBoxCategory);
            } else {
                QComboBoxWithData *comboBoxCategory = new QComboBoxWithData;
                comboBoxCategory->addItem(tr("Не выбрано"));
                QJsonArray values=_categoriesGame.GetValues(i);
                for(int j=0;j<values.size();j++) {
                    comboBoxCategory->addItem(values.at(j).toObject().value("Title").toString());
                }
                comboBoxCategory->setObjectName("ComboBoxCategory"+QString::number(i));
                comboBoxCategory->AddData("NumberCategory",QString::number(i));
                connect(comboBoxCategory,SIGNAL(currentIndexChanged(int)),this,SLOT(on_ComboBoxCategory_Change(int)));
                layoutComboBox->addRow(new QLabel(_categoriesGame.GetTitle(i)),comboBoxCategory);
            }
            ui->ComboBoxCategoriesCategory->addItem(_categoriesGame.GetTitle(i));
            }
        ui->ScrollAreaCategories->setLayout(layoutComboBox);
        ui->ScrollAreaCheckCategories->setLayout(layoutCheckBox);
    }

    ui->ScrollAreaCategories->setHidden(static_cast<QFormLayout*>(ui->ScrollAreaCategories->layout())->rowCount()==0);
    ui->ScrollAreaCheckCategories->setHidden(static_cast<QFormLayout*>(ui->ScrollAreaCheckCategories->layout())->rowCount()==0);
    ui->ButtonChangeCategory->setEnabled(_categoriesGame.GetCount()!=0);
    ui->ButtonDeleteAllCategories->setEnabled(_categoriesGame.GetCount()!=0);

    _fAchievements.SetCol(_categoriesGame.GetCount()+c_filterColumnCount);
    _fCompare.SetCol(_categoriesGame.GetCount()+c_filterColumnCount+ui->TableWidgetAchievements->columnCount()-c_tableAchievementColumnCount);
}
void FormAchievements::UpdateHiddenRows(){
    switch (_simpleCompare) {
    case FormMode::achievement:{
        if(_isUnique){
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                if(_fAchievements.GetData(i)){
                    bool isExist=false;
                    for (int j=0;j<ui->TableWidgetCategory->columnCount();j++) {
                        if(ui->TableWidgetCategory->item(i,j)->checkState()==Qt::Checked){
                            isExist=true;
                            break;
                        }
                    }
                    TableSetRowVisible(i,!isExist);
                } else {
                    TableSetRowVisible(i,false);
                }
            }
        } else {
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                TableSetRowVisible(i,_fAchievements.GetData(i));
            }
        }
        break;
    }
    case FormMode::compare:{
        for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
            TableSetRowVisible(i,_fCompare.GetData(i));
        }
        break;
    }
    }
}
void FormAchievements::TableSetColumnCount(int a_columns){
    ui->TableWidgetHorizontalHeaderAchievements->setColumnCount(a_columns);
    ui->TableWidgetAchievements->setColumnCount(a_columns);
}
void FormAchievements::TableInsertColumn(int a_columns){
    ui->TableWidgetHorizontalHeaderAchievements->insertColumn(a_columns);
    ui->TableWidgetAchievements->insertColumn(a_columns);
}
void FormAchievements::TableRemoveColumn(int a_columns){
    ui->TableWidgetHorizontalHeaderAchievements->removeColumn(a_columns);
    ui->TableWidgetAchievements->removeColumn(a_columns);
}
void FormAchievements::TableSetColumnVisible(int a_column, bool a_visible){
    ui->TableWidgetHorizontalHeaderAchievements->setColumnHidden(a_column,!a_visible);
    ui->TableWidgetAchievements->setColumnHidden(a_column,!a_visible);
}
void FormAchievements::TableSetHorizontalHeaderText(int a_index, QString a_text){
    ui->TableWidgetHorizontalHeaderAchievements->setHorizontalHeaderItem(a_index,new QTableWidgetItem(a_text));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(a_index,new QTableWidgetItem(a_text));
}

void FormAchievements::TableSetRowCount(int a_row){
    ui->TableWidgetAchievements->setRowCount(a_row);
    ui->TableWidgetCategory->setRowCount(a_row);
}
void FormAchievements::TableInsertRow(int a_row){
    ui->TableWidgetHorizontalHeaderAchievements->insertRow(a_row);
    ui->TableWidgetAchievements->insertRow(a_row);
}
void FormAchievements::TableRemoveRow(int a_row){
    ui->TableWidgetAchievements->removeRow(a_row);
    ui->TableWidgetCategory->removeRow(a_row);
}
void FormAchievements::TableSetRowVisible(int a_row, bool a_visible){
    ui->TableWidgetAchievements->setRowHidden(a_row,!a_visible);
    ui->TableWidgetCategory->setRowHidden(a_row,!a_visible);
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
    FormCategoryValue *newValue = new FormCategoryValue(rowValues);
    _values.append(newValue);
    switch (rowValues) {
        case 0:
            newValue->SetEnabledUpDown(EnabledUpDown::none);
            break;
        case 1:
            _values[rowValues-1]->SetEnabledUpDown(EnabledUpDown::down);
            newValue->SetEnabledUpDown(EnabledUpDown::up);
            break;
        default:
            _values[rowValues-1]->SetEnabledUpDown(EnabledUpDown::both);
            newValue->SetEnabledUpDown(EnabledUpDown::up);
    }
    connect(newValue,&FormCategoryValue::s_valuechange,this,&FormAchievements::on_FormCategoryValueChange);
    connect(newValue,&FormCategoryValue::s_visiblechange,this,&FormAchievements::on_FormCategoryVisibleChange);
    connect(newValue,&FormCategoryValue::s_positionchange,this,&FormAchievements::on_FormCategoryPositionChange);
    connect(newValue,&FormCategoryValue::s_selectchange,this,&FormAchievements::on_FormCategorySelectChange);
    connect(newValue,&FormCategoryValue::s_deleting,this,&FormAchievements::on_FormCategoryDeleting);
    connect(newValue,&FormCategoryValue::s_reverse,this,&FormAchievements::on_FormCategoryReverse);
    QListWidgetItem* item = new QListWidgetItem(ui->ListWidgetValuesCategory);
    item->setSizeHint(newValue->sizeHint());
    ui->ListWidgetValuesCategory->setItemWidget(item,newValue);
    return newValue;
}
#define SystemEnd }

#define Filter {
void FormAchievements::on_LineEditNameAchievements_textChanged(const QString& a_newText){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        _fAchievements.SetData(i,c_filterName,((ui->TableWidgetAchievements->item(i,c_filterName+2)->text().toLower().indexOf(a_newText.toLower())>-1)
                                               ||(ui->TableWidgetAchievements->item(i,c_tableAchievementColumnDescription)->text().toLower().indexOf(a_newText.toLower())>-1)));
        _fCompare.SetData(i,c_filterName,((ui->TableWidgetAchievements->item(i,c_filterName+2)->text().toLower().indexOf(a_newText.toLower())>-1)
                                            ||(ui->TableWidgetAchievements->item(i,c_tableAchievementColumnDescription)->text().toLower().indexOf(a_newText.toLower())>-1)));
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
        ui->TableWidgetCategory->setColumnCount(c_tableCategoryColumnNoValue+1);
        ui->TableWidgetCategory->setHorizontalHeaderItem(c_tableCategoryColumnNoValue,new QTableWidgetItem());
        ui->TableWidgetCategory->setVisible(true);
        for(int j=0;j<ui->TableWidgetCategory->rowCount();j++) {
            QTableWidgetItem *itemCheck(new QTableWidgetItem(tr("Add")));
            itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
            itemCheck->setCheckState(Qt::Unchecked);
            ui->TableWidgetCategory->setItem(j,c_tableCategoryColumnNoValue,itemCheck);
        }
        ui->TableWidgetCategory->setColumnHidden(c_tableCategoryColumnNoValue,true);
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
}
void FormAchievements::FavoritesClicked(){
    int achievementIndex=static_cast<QButtonWithData*>(sender())->GetData(0).toInt();
    QJsonObject gameObject;
    QJsonObject newValue;
    gameObject["id"]=_game.GetAppid();
    gameObject["name"]=_game.GetName();
    newValue["id"]=_achievements[achievementIndex].GetApiname();
    newValue["title"]=_achievements[achievementIndex].GetDisplayname();
    newValue["description"]=_achievements[achievementIndex].GetDescription();

    if(_favorites.AddValue(gameObject,newValue,true)){
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
void FormAchievements::on_ComboBoxCategory_Change(int a_index){
    if(_categoriesGame.GetCount()>0){
        int categoryIndex = static_cast<QComboBoxWithData*>(sender())->GetData(0).toInt();
        if(a_index!=0){
            QList<QString> achievementsName = _categoriesGame.GetValues(categoryIndex,a_index-1);
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categoryIndex,false);
                _fCompare.SetData(i,c_filterEndConstValues+categoryIndex,false);
                for(int j=0;j<achievementsName.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,c_tableAchievementColumnAppid)->text()==achievementsName[j]){
                        _fAchievements.SetData(i,c_filterEndConstValues+categoryIndex,true);
                        _fCompare.SetData(i,c_filterEndConstValues+categoryIndex,true);
                        break;
                        }
                    }
            }
        } else {
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categoryIndex,true);
                _fCompare.SetData(i,c_filterEndConstValues+categoryIndex,true);
                }
        }
        UpdateHiddenRows();
    }
}
void FormAchievements::on_CheckBoxCategory_Change(int a_index){
    if(_categoriesGame.GetCount()>0){
        int categorynum = static_cast<QCheckBoxWithData*>(sender())->GetData(0).toInt();
        if(a_index!=0){
            QList<QString> achievementsName = _categoriesGame.GetNoValues(categorynum);
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categorynum,false);
                _fCompare.SetData(i,c_filterEndConstValues+categorynum,false);
                for(int j=0;j<achievementsName.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,c_tableAchievementColumnAppid)->text()==achievementsName[j]){
                        _fAchievements.SetData(i,c_filterEndConstValues+categorynum,true);
                        _fCompare.SetData(i,c_filterEndConstValues+categorynum,true);
                        break;
                        }
                    }
            }
        } else {
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categorynum,true);
                _fCompare.SetData(i,c_filterEndConstValues+categorynum,true);
                }
        }
        UpdateHiddenRows();
    }
}
void FormAchievements::on_ButtonDeleteAllCategories_clicked(){
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
            ShowCategories(false);
        }
    }
}
#define HideColumns {
void FormAchievements::on_CheckBoxCompareIcon_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnIcon,arg1==0);
}
void FormAchievements::on_CheckBoxCompareTitle_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnTitle,arg1==0);
}
void FormAchievements::on_CheckBoxCompareDescription_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnDescription,arg1==0);
}
void FormAchievements::on_CheckBoxCompareTotalPercent_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnWorld,arg1==0);
}
#define HideColumnsEnd }
#define Categorys {
void FormAchievements::on_ButtonAddValueCategory_clicked(){
    if((_typeCategory==CategoryType::add)||(_typeCategory==CategoryType::change)){
        ui->TableWidgetCategory->setColumnCount(ui->TableWidgetCategory->columnCount()+1);
        ui->TableWidgetCategory->setHorizontalHeaderItem(ui->TableWidgetCategory->columnCount()-1,new QTableWidgetItem());
        for(int i=0;i<ui->TableWidgetCategory->rowCount();i++){
            QTableWidgetItem *itemCheck(new QTableWidgetItem(tr("Add")));
            itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
            itemCheck->setCheckState(Qt::Unchecked);
            ui->TableWidgetCategory->setItem(i,ui->TableWidgetCategory->columnCount()-1, itemCheck);
            }
        CreateValueCategory();
    }
}
void FormAchievements::on_ButtonCancelCategory_clicked(){
    if(_typeCategory==CategoryType::add||_typeCategory==CategoryType::change){
        ui->GroupBoxCategories->setVisible(false);
        ui->ButtonAddCategory->setEnabled(true);
        ui->ButtonChangeCategory->setEnabled(_categoriesGame.GetCount()!=0);
        ui->ButtonDeleteAllCategories->setEnabled(_categoriesGame.GetCount()!=0);
        ui->ButtonCompare->setEnabled(true);
        ui->ListWidgetValuesCategory->clear();
        ui->LineEditTitleCategory->setText("");
        ui->ComboBoxCategoriesCategory->setCurrentIndex(0);
        _typeCategory=CategoryType::none;
        while(!_values.isEmpty())
            _values.remove(0);
        ui->TableWidgetCategory->setColumnCount(0);
        ui->TableWidgetCategory->setVisible(false);
        on_CheckBoxCategoryUniqueValue_stateChanged(0);
        UpdateHiddenRows();
    }
}
void FormAchievements::on_ButtonAcceptCategory_clicked(){
    if(_typeCategory==CategoryType::add||_typeCategory==CategoryType::change){
        if(ui->LineEditTitleCategory->text()!=""){
            int targetCategory=-1;
            if(_typeCategory==CategoryType::change){
                targetCategory=ui->ComboBoxCategoriesCategory->currentIndex()-1;
            } else {
                targetCategory=_categoriesGame.GetCount();
            }

            QList<QString> titles = _categoriesGame.GetTitles();
            bool isUniqueTitle=true;
            for(int i=0;i<titles.size();i++) {
                if((titles[i]==ui->LineEditTitleCategory->text())&&(i!=ui->ComboBoxCategoriesCategory->currentIndex()-1)){
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
                    for(int i=c_tableCategoryColumnNoValue+1;i<ui->TableWidgetCategory->columnCount();i++){
                        if(ui->TableWidgetCategory->horizontalHeaderItem(i)->text()==""){
                            QMessageBox::warning(this,tr("Ошибка"),tr("Название значения пустое!"));
                            return;
                            }
                        for(int j=c_tableCategoryColumnNoValue+1;j<i;j++){
                            if(ui->TableWidgetCategory->horizontalHeaderItem(i)->text()==ui->TableWidgetCategory->horizontalHeaderItem(j)->text()){
                                QMessageBox::warning(this,tr("Ошибка"),tr("Название значения повторяется!"));
                                return;
                                }
                            }
                        }
                    }
                for(int j=0;j<ui->TableWidgetCategory->rowCount();j++){
                    if(ui->TableWidgetCategory->item(j,c_tableCategoryColumnNoValue)->checkState()){
                        noValuesNew.append(ui->TableWidgetAchievements->item(j,c_tableAchievementColumnAppid)->text());
                        }
                    }
                for(int i=c_tableCategoryColumnNoValue+1;i<ui->TableWidgetAchievements->columnCount();i++){
                    QJsonObject valueNew;
                    valueNew["Title"]=ui->TableWidgetCategory->horizontalHeaderItem(i)->text();
                    QJsonArray achievementsNew;
                    for (int j=0;j<ui->TableWidgetCategory->rowCount();j++) {
                        if(ui->TableWidgetCategory->item(j,i)->checkState()){
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
                ShowCategories(!_isFirstLoad);
                ui->LineEditNameAchievements->setText("");
                FilterMyProfile->SetType(ReachedType::all);
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
            ShowCategories(false);
            ui->LineEditNameAchievements->setText("");
            FilterMyProfile->SetType(ReachedType::all);
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
        ui->ListWidgetValuesCategory->setEnabled(!value);
        ui->TableWidgetCategory->setColumnHidden(c_tableCategoryColumnNoValue,!value);
        for(int i=0;i<ui->TableWidgetCategory->columnCount()-(c_tableCategoryColumnNoValue+1);i++) {
            ui->TableWidgetCategory->setColumnHidden((c_tableCategoryColumnNoValue+1)+i,value);
        }
    }
}
void FormAchievements::on_CheckBoxCategoryUniqueValue_stateChanged(int arg1){
    switch (arg1) {
    case 0:
        disconnect(ui->TableWidgetCategory,&QTableWidget::itemClicked,this,&FormAchievements::HideCheckedAchievement);
        _isUnique=false;
        for (int i=0;i<ui->TableWidgetCategory->rowCount();i++) {
            _fAchievements.SetData(i,c_filterUniqueValue,true);
        }
        break;
    case 2:
        connect(ui->TableWidgetCategory,&QTableWidget::itemClicked,this,&FormAchievements::HideCheckedAchievement);
        _isUnique=true;
        for (int i=0;i<ui->TableWidgetCategory->rowCount();i++) {
            for(int j=c_tableCategoryColumnNoValue+1;j<ui->TableWidgetCategory->columnCount();j++)
                if(ui->TableWidgetCategory->item(i,j)->checkState()==Qt::Checked)
                    _fAchievements.SetData(i,c_filterUniqueValue,false);
        }
        break;
    }
    UpdateHiddenRows();
}
void FormAchievements::on_LineEditTitleCategory_textChanged(const QString &arg1){
    if(ui->TableWidgetCategory->columnCount()>c_tableCategoryColumnNoValue)
        ui->TableWidgetCategory->horizontalHeaderItem(c_tableCategoryColumnNoValue)->setText(arg1);
}
void FormAchievements::on_ComboBoxCategoriesCategory_activated(int a_index){
    if(_typeCategory==CategoryType::change){
        if(_categoriesGame.GetCount()>0){
            ui->LineEditTitleCategory->setText(ui->ComboBoxCategoriesCategory->itemText(a_index));
            ui->ListWidgetValuesCategory->clear();
            ui->TableWidgetCategory->setColumnCount(c_tableCategoryColumnNoValue+1);
            if(a_index!=0){
                ui->ButtonAddValueCategory->setEnabled(true);
                ui->LineEditTitleCategory->setEnabled(true);
                QList<QString> noValues = _categoriesGame.GetNoValues(a_index-1);
                ui->TableWidgetCategory->setHorizontalHeaderItem(c_tableCategoryColumnNoValue,new QTableWidgetItem(_categoriesGame.GetTitle(a_index-1)));
                for(int j=0;j<ui->TableWidgetCategory->rowCount();j++) {
                    QTableWidgetItem *itemCheck = new QTableWidgetItem(tr("Add"));
                    itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
                    bool isAchievementCheck=true;
                    for(int k=0;k<noValues.size();k++) {
                        if(ui->TableWidgetCategory->item(j,c_tableAchievementColumnAppid)->text()==noValues[k]){
                            isAchievementCheck=false;
                            break;
                        }
                    }
                    itemCheck->setCheckState(isAchievementCheck?Qt::Unchecked:Qt::Checked);
                    ui->TableWidgetCategory->setItem(j,c_tableCategoryColumnNoValue, itemCheck);
                }
                QJsonArray valuesTitles = _categoriesGame.GetValues(a_index-1);
                while(!_values.isEmpty())
                    _values.remove(0);
                for(int i=0;i<valuesTitles.size();i++) {
                    FormCategoryValue *value = CreateValueCategory();
                    ui->TableWidgetCategory->insertColumn(ui->TableWidgetCategory->columnCount());
                    ui->TableWidgetCategory->setHorizontalHeaderItem(ui->TableWidgetCategory->columnCount()-1,new QTableWidgetItem(valuesTitles[i].toObject().value("Title").toString()));
                    value->SetTitle(valuesTitles[i].toObject().value("Title").toString());
                    for (int j=0;j<ui->TableWidgetCategory->rowCount();j++) {
                        QTableWidgetItem *itemCheck = new QTableWidgetItem(tr("Add"));
                        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
                        bool isAchievementCheck=true;
                        for (int k=0;k<valuesTitles[i].toObject().value("Achievements").toArray().size();k++) {
                            if(ui->TableWidgetCategory->item(j,c_tableAchievementColumnAppid)->text()==valuesTitles[i].toObject().value("Achievements").toArray().at(k).toString()){
                                isAchievementCheck=false;
                                break;
                            }
                        }
                        itemCheck->setCheckState(isAchievementCheck?Qt::Unchecked:Qt::Checked);
                        ui->TableWidgetCategory->setItem(j,ui->TableWidgetCategory->columnCount()-1, itemCheck);
                    }
                }
                if(_categoriesGame.GetIsNoValues(a_index-1)==1){
                    ui->CheckBoxCategoryOneValue->setChecked(true);
                    ui->TableWidgetCategory->setColumnHidden(c_tableCategoryColumnNoValue,false);
                    for(int i=0;i<ui->TableWidgetCategory->columnCount()-(c_tableCategoryColumnNoValue+1);i++)
                        ui->TableWidgetCategory->setColumnHidden((c_tableCategoryColumnNoValue+1)+i,true);
                } else {
                    ui->CheckBoxCategoryOneValue->setChecked(false);
                    ui->TableWidgetCategory->setColumnHidden(c_tableCategoryColumnNoValue,true);
                    for(int i=0;i<ui->TableWidgetCategory->columnCount()-(c_tableCategoryColumnNoValue+1);i++)
                        ui->TableWidgetCategory->setColumnHidden((c_tableCategoryColumnNoValue+1)+i,false);
                }
            } else
                ui->ButtonAddValueCategory->setEnabled(false);
        }
    }
}
void FormAchievements::on_CheckBoxCategoryVisibleAll_clicked(){
    bool check = ui->CheckBoxCategoryVisibleAll->isChecked();
    for (int i=0;i<_values.size();
         _values[i++]->SetVisible(check));
}
#define CategorysValues {
void FormAchievements::on_FormCategoryValueChange(int a_pos, QString a_value){
    ui->TableWidgetCategory->horizontalHeaderItem((c_tableCategoryColumnNoValue+1)+a_pos)->setText(a_value);
}
void FormAchievements::on_FormCategoryVisibleChange(int a_pos, bool a_visible){
    bool isAllVisible=true;
    for (int i=0;i<_values.size();i++) {
        if(!_values[i]->GetVisible()){
            isAllVisible=false;
            break;
        }
    }
    if(isAllVisible)
        ui->CheckBoxCategoryVisibleAll->setCheckState(Qt::Checked);
    else
        ui->CheckBoxCategoryVisibleAll->setCheckState(Qt::Unchecked);
    ui->TableWidgetCategory->setColumnHidden((c_tableCategoryColumnNoValue+1)+a_pos,!a_visible);
}
void FormAchievements::on_FormCategoryPositionChange(int a_pos, int a_posNew){
    if(a_posNew<0||a_posNew>ui->TableWidgetCategory->columnCount()-(c_tableCategoryColumnNoValue+1)){
        QMessageBox::warning(this,"",tr("Невозможно переместить значение"));
    } else {
        for (int j=0;j<ui->TableWidgetCategory->rowCount();j++) {
            Qt::CheckState tempCheckState = ui->TableWidgetCategory->item(j,(c_tableCategoryColumnNoValue+1)+a_pos)->checkState();
            ui->TableWidgetCategory->item(j,(c_tableCategoryColumnNoValue+1)+a_pos)->setCheckState(
                        ui->TableWidgetCategory->item(j,(c_tableCategoryColumnNoValue+1)+a_posNew)->checkState());
            ui->TableWidgetCategory->item(j,(c_tableCategoryColumnNoValue+1)+a_posNew)->setCheckState(tempCheckState);
        }
        QString tempHorisontalHeader=ui->TableWidgetCategory->horizontalHeaderItem((c_tableCategoryColumnNoValue+1)+a_pos)->text();
        ui->TableWidgetCategory->horizontalHeaderItem((c_tableCategoryColumnNoValue+1)+a_pos)->setText(
                    ui->TableWidgetCategory->horizontalHeaderItem((c_tableCategoryColumnNoValue+1)+a_posNew)->text());
        ui->TableWidgetCategory->horizontalHeaderItem((c_tableCategoryColumnNoValue+1)+a_posNew)->setText(tempHorisontalHeader);

        std::swap(_values[a_pos],_values[a_posNew]);
        for (int i=0;i<_values.size();i++) {
            QListWidgetItem* item = new QListWidgetItem(ui->ListWidgetValuesCategory);
            item->setSizeHint(_values[i]->sizeHint());
            ui->ListWidgetValuesCategory->setItemWidget(item,_values[i]);
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
void FormAchievements::on_FormCategorySelectChange(int a_pos, bool a_select){
    if(_isUnique){
        for (int i=0;i<ui->TableWidgetCategory->rowCount();i++) {
            if(!ui->TableWidgetCategory->isRowHidden(i)){
                ui->TableWidgetCategory->item(i,(c_tableCategoryColumnNoValue+1)+a_pos)->setCheckState(a_select?Qt::Checked:Qt::Unchecked);
                _fAchievements.SetData(i,c_filterUniqueValue,!a_select);
            }
        }
    } else {
        for (int i=0;i<ui->TableWidgetCategory->rowCount();i++) {
            if(!ui->TableWidgetCategory->isRowHidden(i))
                ui->TableWidgetCategory->item(i,(c_tableCategoryColumnNoValue+1)+a_pos)->setCheckState(a_select?Qt::Checked:Qt::Unchecked);
        }
    }
    UpdateHiddenRows();
}
void FormAchievements::on_FormCategoryDeleting(int a_pos){
    ui->TableWidgetCategory->removeColumn((c_tableCategoryColumnNoValue+1)+a_pos);
    QListWidgetItem* item = ui->ListWidgetValuesCategory->item(a_pos);
    ui->ListWidgetValuesCategory->removeItemWidget(item);
    _values.remove(a_pos);
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
void FormAchievements::on_FormCategoryReverse(int a_pos){
    for (int i=0;i<ui->TableWidgetCategory->rowCount();i++) {
        if(ui->TableWidgetCategory->item(i,(c_tableCategoryColumnNoValue+1)+a_pos)->checkState()==Qt::Checked)
            ui->TableWidgetCategory->item(i,(c_tableCategoryColumnNoValue+1)+a_pos)->setCheckState(Qt::Unchecked);
        else
            ui->TableWidgetCategory->item(i,(c_tableCategoryColumnNoValue+1)+a_pos)->setCheckState(Qt::Checked);
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
                _fCompare.SetData(i,c_filterFavorite,true);
            }
            break;
        case 2:
            QJsonObject gameObject;
            gameObject["id"]=_game.GetAppid();
            gameObject["name"]=_game.GetName();
            QJsonArray values=_favorites.GetValues(gameObject);
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                bool accept=false;
                for (int j=0;j<values.size();j++) {
                    if(values[j].toObject().value("id").toString()==_achievements[i].GetApiname()){
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
#define FunctionEnd }

void FormAchievements::on_horizontalScrollBar_sliderMoved(int a_position){
    ui->TableWidgetAchievements->horizontalScrollBar()->setSliderPosition(a_position);
    ui->TableWidgetHorizontalHeaderAchievements->horizontalScrollBar()->setSliderPosition(a_position);
}

void FormAchievements::on_ButtonFavorite_clicked(){
    if(_currentAchievementIndex>-1){
        QJsonObject gameObject;
        QJsonObject newValue;
        gameObject["id"]=_game.GetAppid();
        gameObject["name"]=_game.GetName();
        newValue["id"]=_achievements[_currentAchievementIndex].GetApiname();
        newValue["title"]=_achievements[_currentAchievementIndex].GetDisplayname();
        newValue["description"]=_achievements[_currentAchievementIndex].GetDescription();
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

void FormAchievements::on_TableWidgetAchievements_cellClicked(int row, int){
    _currentAchievement=ui->TableWidgetAchievements->item(row,c_tableAchievementColumnAppid)->text();
    _currentAchievementIndex=row;
    QJsonObject gameObject;
    gameObject["id"]=_game.GetAppid();
    gameObject["name"]=_game.GetName();
    QJsonArray favorites=_favorites.GetValues(gameObject);
    bool isFavorite=false;
    for(int i=0;i<favorites.size();i++){
        if(favorites[i].toObject().value("id").toString()==_currentAchievement){
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
