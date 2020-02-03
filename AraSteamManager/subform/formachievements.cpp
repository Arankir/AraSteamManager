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
const int c_tableCompareColumnCount=6;

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
    ui->TableWidgetCompareAchievements->setCellWidget(0,c_tableCompareColumnMy,profileAvatarCompare);
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
    ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowAvatars,0,profileAvatarFriend);
    ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowAvatars,1,allFriends);

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
    ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowFilters,0,myFilter);
    ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowFilters,1,widgetFriendsAchievementsFilter);
    ui->TableWidgetCompareFriends->resizeRowsToContents();
    ui->TableWidgetCompareFriends->resizeColumnsToContents();
    #define SetTableWidgetCompareFriendsSettingsEnd }
    #define InitCategoryValuesLayout {
    QWidget *widgetValuesCategory = new QWidget;
    _categoryValuesLayout = new QFormLayout;
    _categoryValuesLayout->setSpacing(0);
    _categoryValuesLayout->setContentsMargins(1,1,1,1);
    widgetValuesCategory->setLayout(_categoryValuesLayout);
    ui->ScrollAreaValuesCategory->setWidget(widgetValuesCategory);
    #define InitCategoryValuesLayoutEnd }
    #define SetIcon {
    ui->ButtonCompare->setIcon(QIcon("://"+_theme+"/compare.png"));
    //ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {background-image:url(images/filter_white.png)}");
    //ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(images/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->GroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(://"+_theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->ButtonAddCategory->setIcon(QIcon("://create.png"));
    ui->ButtonChangeCategory->setIcon(QIcon("://"+_theme+"/change.png"));
    ui->ButtonDeleteCategory->setIcon(QIcon("://delete.png"));
    ui->ButtonFindAchievement->setIcon(QIcon("://"+_theme+"/find.png"));
    ui->ButtonAddValueCategory->setIcon(QIcon("://create.png"));
    ui->ButtonAcceptCategory->setIcon(QIcon("://apply.png"));
    ui->ButtonCancelCategory->setIcon(QIcon("://cancel.png"));
    ui->ButtonUpdate->setIcon(QIcon("://"+_theme+"/update.png"));
    allFriends->setPixmap(QPixmap("://"+_theme+"/friends.png"));
    pbFriendsAllAchievements->setIcon(QIcon("://"+_theme+"/all.png"));
    pbFriendsReachedAchievements->setIcon(QIcon("://"+_theme+"/reached.png"));
    pbFriendsNotReachedAchievements->setIcon(QIcon("://"+_theme+"/notreached.png"));
    #define SetIconEnd }
    _favorites.SetPath("Files/Favorites/Achievements.json","Achievements");
    _setting.CreateFile("images/achievements/"+QString::number(_game.GetAppid()));
    _categoriesGame.Set(_game);
    ui->LabelGameLogo->setPixmap(RequestData("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                             QString::number(_game.GetAppid())+"/"+_game.GetImg_logo_url()+".jpg",false).GetPixmap());
    ui->GroupBoxCategories->setVisible(false);
    SwitchSimpleCompare(FormMode::compare);
    ui->ProgressBarFriendsLoad->setVisible(false);
    ui->LabelGameOnline->setText(tr("Сейчас в игре :%1").arg(_game.GetNumberPlayers(false)));
    ui->LabelGameTitle->setText(_game.GetName());
    ui->GroupBoxFilter->setEnabled(false);
    _achievements.SetIDs(QString::number(_game.GetAppid()),_id);
    _achievements.Set(SAchievementsPercentage(QString::number(_game.GetAppid()),false));
    connect(&_achievements,SIGNAL(s_finished()),this,SLOT(PullTableWidget()));
    Retranslate();
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
        Threading loadTable(this);
        QLabel *labelCompareSummary = new QLabel;
        ui->TableWidgetCompareAchievements->setCellWidget(1,c_tableCompareColumnMy,labelCompareSummary);
        loadTable.AddThreadAchievements(_achievements,ui->LabelTotalPersent,ui->TableWidgetAchievements,labelCompareSummary,ui->TableWidgetCompareAchievements);
    } else {
        ui->TableWidgetAchievements->insertRow(0);
        ui->TableWidgetAchievements->setItem(c_tableAchievementColumnAppid,1,new QTableWidgetItem(tr("Ошибка")));
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnTitle,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnDescription,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnWorld,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnReached,true);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnFavorite,true);
        ui->GroupBoxFilter->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
    }
}
void FormAchievements::Retranslate(){
    ui->CheckBoxShowFilter->setText(tr("Показать фильтр"));
    ui->GroupBoxFilter->setTitle(tr("      Фильтр"));
    ui->ButtonAddCategory->setText(tr("Добавить категорию"));
    ui->ButtonChangeCategory->setText(tr("Изменить категорию"));
    ui->ButtonDeleteAllCategories->setText(tr("Удалить все категории"));
    ui->ButtonUpdate->setText(tr("Обновить"));
    //ui->GroupBoxCompareShowedColumns->setTitle(tr("Видимые столбцы"));
    ui->CheckBoxCompareIcon->setText(tr("Иконка"));
    ui->CheckBoxCompareTitle->setText(tr("Название"));
    ui->CheckBoxCompareDescription->setText(tr("Описание"));
    ui->CheckBoxCompareTotalPercent->setText(tr("По миру"));
    FilterMyProfile->SetTitles(tr("Все достижения"),tr("Полученные достижения"),tr("Не полученные достижения"));
    ui->CheckBoxFavorites->setText(tr("Только избранное"));
    ui->CheckBoxCompareAllFriends->setText(tr("Все друзья"));
    ui->LineEditTitleCategory->setPlaceholderText(tr("Название категории"));
    ui->CheckBoxCategoryOneValue->setText(tr("Без значений"));
    ui->ButtonAddValueCategory->setText(tr("Добавить значение"));
    ui->ButtonCancelCategory->setText(tr("Отмена"));
    ui->ButtonDeleteCategory->setText(tr("Удалить категорию"));
    ui->CheckBoxCategoryVisibleAll->setText(tr("Показать всё"));
    ui->CheckBoxCategoryUniqueValue->setText(tr("Уникальные значения"));
    ui->ButtonAcceptCategory->setText(tr("Применить"));
    ui->LineEditNameAchievements->setPlaceholderText(tr("Достижение"));
    ui->ButtonFindAchievement->setText(tr(" Найти"));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnIcon,new QTableWidgetItem(""));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnTitle,new QTableWidgetItem(tr("Название")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnDescription,new QTableWidgetItem(tr("Описание")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnWorld,new QTableWidgetItem(tr("По миру")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnReached,new QTableWidgetItem(tr("Получено")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnFavorite,new QTableWidgetItem(tr("Избранное")));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(c_tableCompareColumnTitle,new QTableWidgetItem(tr("Название")));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(c_tableCompareColumnDescription,new QTableWidgetItem(tr("Описание")));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(c_tableCompareColumnWorld,new QTableWidgetItem(tr("По миру")));
    ui->TableWidgetCompareFriends->cellWidget(c_tableFriendsRowAvatars,1)->setToolTip(tr("Достижения друзей"));
    ui->LabelGameOnline->setText(tr("Сейчас в игре :%1").arg(_game.GetNumberPlayers(false)));
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
    qDebug()<<"Loading..."<<a_progress;
    QButtonWithData *buttonFavorite = new QButtonWithData("");
    buttonFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
    buttonFavorite->setObjectName("ButtonFavorites&"+QString::number(a_row));
    buttonFavorite->AddData("NumberGame",QString::number(a_row));
    connect(buttonFavorite,&QButtonWithData::pressed,this,&FormAchievements::FavoritesClicked);
    ui->TableWidgetAchievements->setCellWidget(a_row,c_tableAchievementColumnFavorite,buttonFavorite);
}
void FormAchievements::OnFinish(){
    ui->GroupBoxFilter->setEnabled(true);
    ui->TableWidgetAchievements->resizeColumnToContents(c_tableCompareColumnWorld);
    ui->TableWidgetAchievements->resizeRowsToContents();
    ui->TableWidgetAchievements->resizeColumnToContents(c_tableAchievementColumnIcon);
    int j=0;
    ui->TableWidgetCompareAchievements->resizeRowsToContents();
    for (int i=0;i<_achievements.GetCount();i++) {
            QString achievementIcon=_achievements[i].GetIcon().mid(66,_achievements[i].GetIcon().length());
            QString pathImage="images/achievements/"+QString::number(_game.GetAppid())+"/"+achievementIcon.mid(achievementIcon.indexOf("/",1)+1,achievementIcon.length()-1);
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
                        ui->TableWidgetAchievements->setCellWidget(j,c_tableCompareColumnIcon,achievementImage);
                        ui->TableWidgetAchievements->resizeRowToContents(j);
                        QLabel *achievementImageCompare = new QLabel;
                        achievementImageCompare->setPixmap(QPixmap(pathImage));
                        ui->TableWidgetCompareAchievements->setCellWidget(j+2,c_tableCompareColumnIcon,achievementImageCompare);
                        ui->TableWidgetCompareAchievements->resizeRowToContents(j);
                        ui->TableWidgetAchievements->resizeColumnToContents(c_tableAchievementColumnIcon);
                    }
                j++;
            } else {
                ui->TableWidgetAchievements->removeRow(ui->TableWidgetAchievements->rowCount()-1);
                ui->TableWidgetCompareAchievements->removeRow(ui->TableWidgetCompareAchievements->rowCount()-1);
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
    ui->TableWidgetCompareAchievements->setCellWidget(a_image->GetRow()+2,c_tableCompareColumnIcon,achievementImageCompare);
    ui->TableWidgetAchievements->resizeRowToContents(a_image->GetRow());
    ui->TableWidgetCompareAchievements->resizeRowToContents(a_image->GetRow()+2);
    ui->TableWidgetAchievements->resizeColumnToContents(c_tableAchievementColumnIcon);
    if(_numRequests==500&&_numNow<_achievements.GetCount()){
        QString achievementIcon=_achievements[_numNow].GetIcon().mid(66,_achievements[_numNow].GetIcon().length());
        QString pathImage="images/achievements/"+QString::number(_game.GetAppid())+"/"+achievementIcon.mid(achievementIcon.indexOf("/",1)+1,achievementIcon.length()-1);
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
            ui->TableWidgetAchievements->setVisible(true);
            ui->CheckBoxCompareAllFriends->setVisible(false);
            ui->TableWidgetCompareFriends->setVisible(false);
            ui->TableWidgetCompareAchievements->setVisible(false);
            ui->ButtonAddCategory->setVisible(true);
            ui->ButtonChangeCategory->setVisible(true);
            ui->ButtonDeleteAllCategories->setVisible(true);
            ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
            _simpleCompare=FormMode::achievement;
            break;
        }
    case FormMode::achievement:
            ui->GroupBoxReachedFilter->setVisible(false);
            ui->TableWidgetAchievements->setVisible(false);
            ui->CheckBoxCompareAllFriends->setVisible(true);
            ui->TableWidgetCompareAchievements->setVisible(true);
            ui->ButtonAddCategory->setVisible(false);
            ui->ButtonChangeCategory->setVisible(false);
            ui->ButtonDeleteAllCategories->setVisible(false);
            ui->ButtonCompare->setText(tr("Обратно"));
            switch (_loadCompare) {
            case 0:
                LoadingCompare();
                break;
            case 1:
                break;
            default:
                ui->TableWidgetCompareFriends->setVisible(true);
            }
            _simpleCompare=FormMode::compare;
            break;
    }
}
void FormAchievements::LoadingCompare(){
    _loadCompare++;
    SProfile profile(_id,false,QueryType::url);
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(c_tableCompareColumnMy,new QTableWidgetItem(profile.GetPersonaname()));
    QPixmap avatar = RequestData(profile.GetAvatar(),false).GetPixmap();
    QLabel *avatarAchievementsCompare = new QLabel;
    avatarAchievementsCompare->setPixmap(avatar);
    avatarAchievementsCompare->setAlignment(Qt::AlignCenter);
    ui->TableWidgetCompareAchievements->setCellWidget(0,c_tableCompareColumnMy,avatarAchievementsCompare);
    ui->TableWidgetCompareAchievements->resizeRowToContents(0);
    QLabel *avatarFriendsCompare = new QLabel;
    avatarFriendsCompare->setPixmap(avatar);
    avatarFriendsCompare->setAlignment(Qt::AlignCenter);
    avatarFriendsCompare->setToolTip(profile.GetPersonaname());
    ui->TableWidgetCompareFriends->setCellWidget(0,c_tableFriendsRowAvatars,avatarFriendsCompare);

    _profilesFriends = SFriends(_id,false).GetProfiles();
    ui->TableWidgetCompareFriends->setColumnCount(_profilesFriends.GetCount()+2);
    for (int i=0;i<_profilesFriends.GetCount();ui->TableWidgetCompareFriends->setColumnWidth(i++ +2,33));
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
        ui->TableWidgetCompareFriends->setCellWidget(0,i+2,avatarFriend);
        QTableWidgetItem *itemCheck(new QTableWidgetItem(""));
        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
        itemCheck->setCheckState(Qt::Unchecked);
        itemCheck->setTextAlignment(Qt::AlignCenter);
        ui->TableWidgetCompareFriends->setItem(c_tableFriendsRowCheckBox,i+2,itemCheck);
        ui->TableWidgetCompareFriends->setItem(c_tableFriendsRowID,i+2,new QTableWidgetItem(_friends[i].first.GetSteamid()));
        ui->TableWidgetCompareFriends->setColumnHidden(i+2,_friends[i].second==FriendType::haventGame);
    }
    connect(ui->TableWidgetCompareFriends,&QTableWidget::cellChanged,this,&FormAchievements::on_TableWidgetCompareFriendsCellChanged);
    ui->TableWidgetCompareFriends->resizeColumnsToContents();
    _loadCompare++;
    ui->TableWidgetCompareFriends->setVisible(true);
}
void FormAchievements::CompareProfileFilterClickMy(QString, ReachedType a_type){
    switch (a_type) {
        case ReachedType::all:
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                _fAchievements.SetData(i,c_filterReached,true);
                _fCompare.SetData(i+2,c_filterReached,true);
            }
            break;
        case ReachedType::reached:
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                _fAchievements.SetData(i,c_filterReached,ui->TableWidgetAchievements->item(i,c_tableAchievementColumnReached)->text().indexOf(".")>-1);
                _fCompare.SetData(i+2,c_filterReached,ui->TableWidgetCompareAchievements->item(i+2,c_tableCompareColumnMy)->text().indexOf(".")>-1);
            }
            break;
        case ReachedType::notReached:
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                _fAchievements.SetData(i,c_filterReached,ui->TableWidgetAchievements->item(i,c_tableAchievementColumnReached)->text().indexOf(".")==-1);
                _fCompare.SetData(i+2,c_filterReached,ui->TableWidgetCompareAchievements->item(i+2,c_tableCompareColumnMy)->text().indexOf(".")==-1);
            }
            break;
        default:
            break;
    }
    UpdateHiddenRows();
}
void FormAchievements::CompareProfileFilterClickFriends(QString a_name, ReachedType a_type){
    QString name=dynamic_cast<QLabel*>(ui->TableWidgetCompareFriends->cellWidget(0,a_name.toInt()))->toolTip();
    int columnFriend=0;
    for(int i=c_tableCompareColumnCount;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
        if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==name){
            columnFriend=i;
            break;
        }
    }
    int filtercol=_fCompare.GetCol()-(ui->TableWidgetCompareAchievements->columnCount()-columnFriend);
    switch (a_type) {
        case ReachedType::all:
            for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
                _fCompare.SetData(i,filtercol,true);
            }
            break;
        case ReachedType::reached:
            for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
                _fCompare.SetData(i,filtercol,ui->TableWidgetCompareAchievements->item(i,columnFriend)->text().indexOf(".")>-1);
            }
            break;
        case ReachedType::notReached:
            for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
                _fCompare.SetData(i,filtercol,ui->TableWidgetCompareAchievements->item(i,columnFriend)->text().indexOf(".")==-1);
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
    for(int i=2;i<ui->TableWidgetCompareFriends->columnCount();i++) {
        if(findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(i))){
            findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(i))->SetType(setType);
        }
    }
}
void FormAchievements::on_TableWidgetCompareFriendsCellChanged(int a_row, int a_column){
    if((a_row==1)&&(a_column>1)){
        int columnFriend=ui->TableWidgetCompareAchievements->columnCount();
        SProfile profileFriend=_friends[a_column-2].first;
        if(ui->TableWidgetCompareFriends->item(a_row,a_column)->checkState()==Qt::Checked){
            ui->TableWidgetCompareAchievements->insertColumn(columnFriend);
            ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(columnFriend,new QTableWidgetItem(profileFriend.GetPersonaname()));
            QLabel *avatarFriend = new QLabel;
            avatarFriend->setPixmap(RequestData(_friends[a_column-2].first.GetAvatar(),false).GetPixmap());
            avatarFriend->setToolTip(_friends[a_column-2].first.GetPersonaname());
            avatarFriend->setAlignment(Qt::AlignCenter);
            ui->TableWidgetCompareAchievements->setCellWidget(0,columnFriend,avatarFriend);
            SAchievements achievementsFriends=_achievements;
            achievementsFriends.Set(SAchievementsPlayer(QString::number(_game.GetAppid()),profileFriend.GetSteamid(),false));
            if(SetFriendAchievements(achievementsFriends,columnFriend)){
                FormCompareProfileFilter *Filterfriend = new FormCompareProfileFilter();
                Filterfriend->setObjectName("FormCompareProfileFilterFriend"+QString::number(a_column));
                Filterfriend->SetName(QString::number(a_column));
                connect(Filterfriend,&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickFriends);
                ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowFilters,a_column,Filterfriend);
                ui->TableWidgetCompareFriends->resizeRowsToContents();
                ui->TableWidgetCompareFriends->resizeColumnsToContents();
            }
//            Threading LoadFriendTable(this);
//            LoadFriendTable.AddThreadFriendAchievements(ui->TableWidgetCompareAchievements,ach,col,c_tableCompareColumnAppid);
            _fCompare.SetCol(_fCompare.GetCol()+1);
            ui->TableWidgetCompareAchievements->setColumnWidth(columnFriend,80);
        } else {
            columnFriend=0;
            for(int i=c_tableCompareColumnCount;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
                if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==profileFriend.GetPersonaname()){
                    columnFriend=i;
                    ui->TableWidgetCompareAchievements->removeColumn(i);
                    break;
                }
            }
            if(findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(a_column))){
                disconnect(findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(a_column)),&FormCompareProfileFilter::s_radioButtonChange,this,&FormAchievements::CompareProfileFilterClickFriends);
                ui->TableWidgetCompareFriends->removeCellWidget(c_tableFriendsRowFilters,a_column);
                delete findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend"+QString::number(a_column));
                ui->TableWidgetCompareFriends->resizeColumnsToContents();
            }
            if(_fCompare.GetCol()>=columnFriend)
                _fCompare.RemoveCol(_fCompare.GetCol()-(ui->TableWidgetCompareAchievements->columnCount()-columnFriend+1));
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
        ui->TableWidgetCompareFriends->setCellWidget(c_tableFriendsRowFilters,a_column,friendFilter);
        ui->TableWidgetCompareFriends->resizeRowsToContents();
        ui->TableWidgetCompareFriends->resizeColumnsToContents();
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
void FormAchievements::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        Retranslate();
    }
}
void FormAchievements::ShowCategories(){
    _categoriesGame.Set(_game);
    while(ui->ComboBoxCategoriesCategory->count()>1){
        ui->ComboBoxCategoriesCategory->removeItem(1);
    }
    QFormLayout *layoutComboBox = new QFormLayout;
    QFormLayout *layoutCheckBox = new QFormLayout;
    for(int i=0; i<_categoriesGame.GetCount(); i++){
        if(_categoriesGame.GetIsNoValues(i)==1){
            QCheckBoxWithData *checkBoxCategory = new QCheckBoxWithData(_categoriesGame.GetTitle(i));
            checkBoxCategory->setObjectName("Category"+QString::number(i));
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
            comboBoxCategory->setObjectName("Category"+QString::number(i));
            comboBoxCategory->AddData("NumberCategory",QString::number(i));
            connect(comboBoxCategory,SIGNAL(currentIndexChanged(int)),this,SLOT(on_ComboBoxCategory_Change(int)));
            layoutComboBox->addRow(new QLabel(_categoriesGame.GetTitle(i)),comboBoxCategory);
        }
        ui->ComboBoxCategoriesCategory->addItem(_categoriesGame.GetTitle(i));
        }
    QWidget *widgetCategoriesComboBox = new QWidget;
    QWidget *widgetCategoriesCheckBox = new QWidget;
    widgetCategoriesComboBox->setLayout(layoutComboBox);
    widgetCategoriesCheckBox->setLayout(layoutCheckBox);
    ui->ScrollAreaCategories->setWidget(widgetCategoriesComboBox);
    ui->ScrollAreaCheckCategories->setWidget(widgetCategoriesCheckBox);

    ui->ScrollAreaCategories->setHidden(layoutComboBox->rowCount()==0);
    ui->ScrollAreaCheckCategories->setHidden(layoutCheckBox->rowCount()==0);
    ui->ButtonChangeCategory->setEnabled(_categoriesGame.GetCount()!=0);
    ui->ButtonDeleteAllCategories->setEnabled(_categoriesGame.GetCount()!=0);

    _fAchievements.SetCol(_categoriesGame.GetCount()+c_filterColumnCount);
    _fCompare.SetCol(_categoriesGame.GetCount()+c_filterColumnCount+ui->TableWidgetCompareAchievements->columnCount()-(c_tableCompareColumnCount+1));
}
void FormAchievements::UpdateHiddenRows(){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        ui->TableWidgetAchievements->setRowHidden(i,!_fAchievements.GetData(i));
    }
    for(int i=0;i<ui->TableWidgetCompareAchievements->rowCount();i++) {
        ui->TableWidgetCompareAchievements->setRowHidden(i,!_fCompare.GetData(i));
    }
}
bool FormAchievements::SetFriendAchievements(SAchievements a_achievement, int a_col){
    int totalReach=0;
    int totalNotReach=0;
    for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
        int j=0;
        bool isAchievementExist=false;
        for(;j<a_achievement.GetCount();j++){
            if(a_achievement[j].GetApiname()==ui->TableWidgetCompareAchievements->item(i,c_tableAchievementColumnAppid)->text()){
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
            ui->TableWidgetCompareAchievements->setItem(i,a_col,itemReached);
        }
        }
    if((totalReach==0)&&(totalNotReach==0)){
        ui->TableWidgetCompareAchievements->setItem(1,a_col, new QTableWidgetItem(QString("%1\n%2").arg(tr("Профиль не")).arg(tr("публичный"))));
        return false;
        } else {
        ui->TableWidgetCompareAchievements->setItem(1,a_col, new QTableWidgetItem(QString("%1/%2\n%3%").arg(QString::number(totalReach))
                                                                             .arg(QString::number(totalReach+totalNotReach))
                                                                             .arg(QString::number(100.0*totalReach/(totalReach+totalNotReach)))));
        return true;
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
    int rowValues = _categoryValuesLayout->rowCount();
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
    _categoryValuesLayout->addRow(newValue);
    return newValue;
}
#define SystemEnd }

#define Filter {
void FormAchievements::on_LineEditNameAchievements_textChanged(const QString& a_newText){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        _fAchievements.SetData(i,c_filterName,((ui->TableWidgetAchievements->item(i,c_filterName+2)->text().toLower().indexOf(a_newText.toLower())>-1)
                                               ||(ui->TableWidgetAchievements->item(i,c_tableAchievementColumnDescription)->text().toLower().indexOf(a_newText.toLower())>-1)));
        _fCompare.SetData(i+2,c_filterName,((ui->TableWidgetCompareAchievements->item(i+2,c_filterName+2)->text().toLower().indexOf(a_newText.toLower())>-1)
                                            ||(ui->TableWidgetCompareAchievements->item(i+2,c_tableCompareColumnDescription)->text().toLower().indexOf(a_newText.toLower())>-1)));
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
            QTableWidgetItem *itemCheck(new QTableWidgetItem(tr("Add")));
            itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
            itemCheck->setCheckState(Qt::Unchecked);
            ui->TableWidgetAchievements->setItem(j,c_tableAchievementColumnNoValue,itemCheck);
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
                _fCompare.SetData(i+2,c_filterEndConstValues+categoryIndex,false);
                for(int j=0;j<achievementsName.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,c_tableAchievementColumnAppid)->text()==achievementsName[j]){
                        _fAchievements.SetData(i,c_filterEndConstValues+categoryIndex,true);
                        _fCompare.SetData(i+2,c_filterEndConstValues+categoryIndex,true);
                        break;
                        }
                    }
            }
        } else {
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                _fAchievements.SetData(i,c_filterEndConstValues+categoryIndex,true);
                _fCompare.SetData(i+2,c_filterEndConstValues+categoryIndex,true);
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
            QTableWidgetItem *itemCheck(new QTableWidgetItem(tr("Add")));
            itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
            itemCheck->setCheckState(Qt::Unchecked);
            ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, itemCheck);
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
        while (!_categoryValuesLayout->isEmpty()) {
            _categoryValuesLayout->removeRow(0);
        }
        ui->LineEditTitleCategory->setText("");
        ui->ComboBoxCategoriesCategory->setCurrentIndex(0);
        _typeCategory=CategoryType::none;
        while(!_values.isEmpty())
            _values.remove(0);
        //_values.clear();!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        ui->TableWidgetAchievements->setColumnCount(c_tableAchievementColumnCount);
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
            ShowCategories();
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
        ui->ScrollAreaValuesCategory->setEnabled(!value);
        ui->TableWidgetAchievements->setColumnHidden(c_tableAchievementColumnNoValue,!value);
        for(int i=0;i<ui->TableWidgetAchievements->columnCount()-(c_tableAchievementColumnNoValue+1);i++) {
            ui->TableWidgetAchievements->setColumnHidden((c_tableAchievementColumnNoValue+1)+i,value);
        }
    }
}
void FormAchievements::on_CheckBoxCategoryUniqueValue_stateChanged(int arg1){
    switch (arg1) {
    case 0:
        disconnect(ui->TableWidgetAchievements,&QTableWidget::itemClicked,this,&FormAchievements::HideCheckedAchievement);
        for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
            _fAchievements.SetData(i,c_filterUniqueValue,true);
        }
        break;
    case 2:
        connect(ui->TableWidgetAchievements,&QTableWidget::itemClicked,this,&FormAchievements::HideCheckedAchievement);
        for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
            for(int j=c_tableAchievementColumnCount+1;j<ui->TableWidgetAchievements->columnCount();j++)
                if(ui->TableWidgetAchievements->item(i,j)->checkState()==Qt::Checked)
                    _fAchievements.SetData(i,c_filterUniqueValue,false);
        }
        break;
    }
    UpdateHiddenRows();
}
void FormAchievements::on_LineEditTitleCategory_textChanged(const QString &arg1){
    if(ui->TableWidgetAchievements->columnCount()>c_tableAchievementColumnNoValue)
        ui->TableWidgetAchievements->horizontalHeaderItem(c_tableAchievementColumnNoValue)->setText(arg1);
}
void FormAchievements::on_ComboBoxCategoriesCategory_activated(int a_index){
    if(_typeCategory==CategoryType::change){
        if(_categoriesGame.GetCount()>0){
            ui->LineEditTitleCategory->setText(ui->ComboBoxCategoriesCategory->itemText(a_index));
            while(!_categoryValuesLayout->isEmpty()){
                _categoryValuesLayout->removeRow(0);
            }
            ui->TableWidgetAchievements->setColumnCount(c_tableAchievementColumnNoValue);
            if(a_index!=0){
                ui->ButtonAddValueCategory->setEnabled(true);
                ui->TableWidgetAchievements->setColumnCount((c_tableAchievementColumnNoValue+1));
                ui->LineEditTitleCategory->setEnabled(true);
                QList<QString> noValues = _categoriesGame.GetNoValues(a_index-1);
                ui->TableWidgetAchievements->setHorizontalHeaderItem(c_tableAchievementColumnNoValue,new QTableWidgetItem(_categoriesGame.GetTitle(a_index-1)));
                for(int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                    QTableWidgetItem *itemCheck = new QTableWidgetItem(tr("Add"));
                    itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
                    bool isAchievementCheck=true;
                    for(int k=0;k<noValues.size();k++) {
                        if(ui->TableWidgetAchievements->item(j,c_tableAchievementColumnAppid)->text()==noValues[k]){
                            isAchievementCheck=false;
                            break;
                        }
                    }
                    itemCheck->setCheckState(isAchievementCheck?Qt::Unchecked:Qt::Checked);
                    ui->TableWidgetAchievements->setItem(j,c_tableAchievementColumnNoValue, itemCheck);
                }
                QJsonArray valuesTitles = _categoriesGame.GetValues(a_index-1);
                _values.clear();
                for(int i=0;i<valuesTitles.size();i++) {
                    FormCategoryValue *value = CreateValueCategory();
                    ui->TableWidgetAchievements->insertColumn(ui->TableWidgetAchievements->columnCount());
                    ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem(valuesTitles[i].toObject().value("Title").toString()));
                    value->SetTitle(valuesTitles[i].toObject().value("Title").toString());
                    for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                        QTableWidgetItem *itemCheck = new QTableWidgetItem(tr("Add"));
                        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
                        bool isAchievementCheck=true;
                        for (int k=0;k<valuesTitles[i].toObject().value("Achievements").toArray().size();k++) {
                            if(ui->TableWidgetAchievements->item(j,c_tableAchievementColumnAppid)->text()==valuesTitles[i].toObject().value("Achievements").toArray().at(k).toString()){
                                isAchievementCheck=false;
                                break;
                            }
                        }
                        itemCheck->setCheckState(isAchievementCheck?Qt::Unchecked:Qt::Checked);
                        ui->TableWidgetAchievements->setItem(j,ui->TableWidgetAchievements->columnCount()-1, itemCheck);
                    }
                }
                if(_categoriesGame.GetIsNoValues(a_index-1)==1){
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
    bool check = ui->CheckBoxCategoryVisibleAll->isChecked();
    for (int i=0;i<_values.size();
         _values[i++]->SetVisible(check));
}
#define CategorysValues {
void FormAchievements::on_FormCategoryValueChange(int a_pos, QString a_value){
    ui->TableWidgetAchievements->horizontalHeaderItem((c_tableAchievementColumnNoValue+1)+a_pos)->setText(a_value);
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
    ui->TableWidgetAchievements->setColumnHidden((c_tableAchievementColumnNoValue+1)+a_pos,!a_visible);
}
void FormAchievements::on_FormCategoryPositionChange(int a_pos, int a_posNew){
    if(a_posNew<0||a_posNew>ui->TableWidgetAchievements->columnCount()-(c_tableAchievementColumnNoValue+1)){
        QMessageBox::warning(this,"",tr("Невозможно переместить значение"));
    } else {
        for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
            Qt::CheckState tempCheckState = ui->TableWidgetAchievements->item(j,(c_tableAchievementColumnNoValue+1)+a_pos)->checkState();
            ui->TableWidgetAchievements->item(j,(c_tableAchievementColumnNoValue+1)+a_pos)->setCheckState(
                        ui->TableWidgetAchievements->item(j,(c_tableAchievementColumnNoValue+1)+a_posNew)->checkState());
            ui->TableWidgetAchievements->item(j,(c_tableAchievementColumnNoValue+1)+a_posNew)->setCheckState(tempCheckState);
        }
        QString tempHorisontalHeader=ui->TableWidgetAchievements->horizontalHeaderItem((c_tableAchievementColumnNoValue+1)+a_pos)->text();
        ui->TableWidgetAchievements->horizontalHeaderItem((c_tableAchievementColumnNoValue+1)+a_pos)->setText(
                    ui->TableWidgetAchievements->horizontalHeaderItem((c_tableAchievementColumnNoValue+1)+a_posNew)->text());
        ui->TableWidgetAchievements->horizontalHeaderItem((c_tableAchievementColumnNoValue+1)+a_posNew)->setText(tempHorisontalHeader);

        std::swap(_values[a_pos],_values[a_posNew]);
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
void FormAchievements::on_FormCategorySelectChange(int a_pos, bool a_select){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
        if(!ui->TableWidgetAchievements->isRowHidden(i))
            ui->TableWidgetAchievements->item(i,(c_tableAchievementColumnNoValue+1)+a_pos)->setCheckState(a_select?Qt::Checked:Qt::Unchecked);
    }
}
void FormAchievements::on_FormCategoryDeleting(int a_pos){
    ui->TableWidgetAchievements->removeColumn((c_tableAchievementColumnNoValue+1)+a_pos);
    _categoryValuesLayout->removeRow(a_pos);
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
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
        if(ui->TableWidgetAchievements->item(i,(c_tableAchievementColumnNoValue+1)+a_pos)->checkState()==Qt::Checked)
            ui->TableWidgetAchievements->item(i,(c_tableAchievementColumnNoValue+1)+a_pos)->setCheckState(Qt::Unchecked);
        else
            ui->TableWidgetAchievements->item(i,(c_tableAchievementColumnNoValue+1)+a_pos)->setCheckState(Qt::Checked);
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
                _fCompare.SetData(i+2,c_filterFavorite,accept);
            }
    }
    UpdateHiddenRows();
}
#define FunctionEnd }

void FormAchievements::on_ComboBoxCategoriesCategory_activated(const QString &arg1)
{

}
