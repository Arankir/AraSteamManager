#include "formachievements.h"
#include "ui_formachievements.h"
#define Constants {
constexpr int c_filterName = 0;
constexpr int c_filterReached = 1;
constexpr int c_filterFavorite = 2;
constexpr int c_filterUniqueValue = 3;
constexpr int c_filterColumnCount = 4;
constexpr int c_filterEndConstValues = 4;

constexpr int c_tableAchievementColumnAppid = 0;
constexpr int c_tableAchievementColumnIcon = 1;
constexpr int c_tableAchievementColumnTitle = 2;
constexpr int c_tableAchievementColumnDescription = 3;
constexpr int c_tableAchievementColumnWorld = 4;
constexpr int c_tableAchievementColumnReachedMy = 5;
constexpr int c_tableAchievementColumnCount = 6;

constexpr int c_tableCategoryColumnNoValue = c_tableAchievementColumnCount;

constexpr int c_tableFriendsRowAvatars = 0;
constexpr int c_tableFriendsRowCheckBox = 1;
constexpr int c_tableFriendsRowFilters = 2;
constexpr int c_tableFriendsRowID = 3;
constexpr int c_tableFriendsRowCount = 4;
#define ConstantsEnd }

#define Init {
FormAchievements::FormAchievements(SAchievementsPlayer aPlayer, QString aId, SGame aGame, int aUnicNum, QWidget *aParent): QWidget(aParent), ui(new Ui::FormAchievements),
_id(aId), _game(aGame), _unicNum(aUnicNum), _achievements(aPlayer), _categoriesGame(_game), _favorites("achievements") {
    ui->setupUi(this);
    initComponents();
    ui->LineEditNameAchievements->setFocus();
}

void FormAchievements::initComponents() {
    #define LoadData {
    this->setAttribute(Qt::WA_TranslucentBackground);
    SProfiles profile(_id, false, QueryType::url);
    QLabel *allFriends = new QLabel("All", this);
    allFriends->setToolTip(tr("Достижения друзей"));
    allFriends->setScaledContents(true);
    allFriends->setFixedSize(32, 32);
    QLabel *avatarAchievementsCompare = new QLabel(this);
    avatarAchievementsCompare->setAlignment(Qt::AlignCenter);
    QLabel *avatarFriendsCompare = new QLabel(this);
    avatarFriendsCompare->setAlignment(Qt::AlignCenter);
    avatarFriendsCompare->setToolTip(profile.getPersonaname());
    new RequestImage(avatarAchievementsCompare, profile.getAvatar(),this);
    new RequestImage(avatarFriendsCompare, profile.getAvatar(),this);
    new RequestImage(ui->LabelGameLogo, QString("http://media.steampowered.com/steamcommunity/public/images/apps/%1/%2.jpg").arg(QString::number(_game._appID), _game._img_logo_url), this);
    Settings::createDir(_setting._pathImagesAchievements + QString::number(_game._appID));
    ui->GroupBoxCategories->setVisible(false);
    ui->ProgressBarFriendsLoad->setVisible(false);
    ui->LabelGameOnlineValue->setText(_game.getNumberPlayers(false));
    ui->LabelGameTitle->setText(_game._name);
    ui->GroupBoxFilter->setEnabled(false);
    ui->ButtonCompare->setMinimumHeight(21);
    #define LoadDataEnd }
    #define ConnectTables {
    _achievements._appid = QString::number(_game._appID);
    _achievements._id = _id;
    _achievements.set(SAchievementsPercentage(QString::number(_game._appID), false));
    _achievements.update();
    //connect(&_achievements, SIGNAL(s_finished()), this, SLOT(pullTable()));
    _tableAchievements = new FormTablesHeaders(2, 0, _game, _id, _achievements, TableType::standart, this);
    connect(_tableAchievements, &FormTablesHeaders::s_tablePulled, this, &FormAchievements::onFinish);
    _tableAchievements->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    ui->LayoutTables->addWidget(_tableAchievements);
    _tableAchievements->changeHorizontalTitle(c_tableAchievementColumnReachedMy, profile.getPersonaname());
    _tableAchievements->setWidgetHorizontalHeader(0, c_tableAchievementColumnReachedMy, avatarAchievementsCompare);
    #define ConnectTablesEnd }
    #define SetTableWidgetCompareFriendsSettings {
    ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setMinimumSize(0, 180);
    ui->TableWidgetFriends->setColumnCount(2);
    ui->TableWidgetFriends->setRowCount(c_tableFriendsRowCount);
    ui->TableWidgetFriends->setRowHidden(c_tableFriendsRowID, true);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars, 0, avatarFriendsCompare);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowAvatars, 1, allFriends);

    QVBoxLayout *layoutReachedFilter = new QVBoxLayout(this);
    _filterMyProfile = new FormCompareProfileFilter(tr("Все достижения"), tr("Полученные достижения"), tr("Не полученные достижения"), this);
    connect(_filterMyProfile, &FormCompareProfileFilter::s_radioButtonChange, this, &FormAchievements::compareProfileFilterClickMy);
    layoutReachedFilter->addWidget(_filterMyProfile);
    ui->GroupBoxReachedFilter->setLayout(layoutReachedFilter);

    FormCompareProfileFilter *myFilter = new FormCompareProfileFilter(this);
    myFilter->setObjectName("FormCompareProfileFilterMy");
    connect(myFilter, &FormCompareProfileFilter::s_radioButtonChange, this, &FormAchievements::compareProfileFilterClickMy);
    #define SetRadioButtonFriendsAchievementsSettings {
    QWidget *widgetFriendsAchievementsFilter = new QWidget(this);
    QVBoxLayout *layoutFriendsAchievementsFilter = new QVBoxLayout(this);
    layoutFriendsAchievementsFilter->setMargin(1);
    layoutFriendsAchievementsFilter->setAlignment(Qt::AlignCenter);
    QButtonWithData *pbFriendsAllAchievements = new QButtonWithData("", this);
    pbFriendsAllAchievements->setObjectName("PBFriendsAll");
    pbFriendsAllAchievements->AddData("Appertain", "Friends");
    pbFriendsAllAchievements->AddData("Type", "All");
    pbFriendsAllAchievements->setChecked(true);
    layoutFriendsAchievementsFilter->addWidget(pbFriendsAllAchievements);
    connect(pbFriendsAllAchievements, &QPushButton::clicked, this, &FormAchievements::buttonCompareAllFriendsReach_Clicked);
    QButtonWithData *pbFriendsReachedAchievements = new QButtonWithData("", this);
    pbFriendsReachedAchievements->setObjectName("PBFriendsReached");
    pbFriendsReachedAchievements->AddData("Appertain", "Friends");
    pbFriendsReachedAchievements->AddData("Type", "Reached");
    layoutFriendsAchievementsFilter->addWidget(pbFriendsReachedAchievements);
    connect(pbFriendsReachedAchievements, &QPushButton::clicked, this, &FormAchievements::buttonCompareAllFriendsReach_Clicked);
    QButtonWithData *pbFriendsNotReachedAchievements = new QButtonWithData("", this);
    pbFriendsNotReachedAchievements->setObjectName("PBFriendsNotReached");
    pbFriendsNotReachedAchievements->AddData("Appertain", "Friends");
    pbFriendsNotReachedAchievements->AddData("Type", "NotReached");
    connect(pbFriendsNotReachedAchievements, &QPushButton::clicked, this, &FormAchievements::buttonCompareAllFriendsReach_Clicked);
    layoutFriendsAchievementsFilter->addWidget(pbFriendsNotReachedAchievements);
    widgetFriendsAchievementsFilter->setLayout(layoutFriendsAchievementsFilter);
    #define SetRadioButtonFriendsAchievementsSettingsEnd }
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, 0, myFilter);
    ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, 1, widgetFriendsAchievementsFilter);
    ui->TableWidgetFriends->resizeRowsToContents();
    ui->TableWidgetFriends->resizeColumnsToContents();
    #define SetTableWidgetCompareFriendsSettingsEnd }
    setTheme();
    #define Connects {
    connect(ui->ButtonUpdate, &QPushButton::clicked, this, &FormAchievements::buttonUpdate_Clicked);
    connect(ui->CheckBoxCompareAllFriends, &QCheckBox::stateChanged, this, &FormAchievements::checkBoxCompareAllFriends_StateChanged);
    connect(ui->LineEditNameAchievements, &QLineEdit::textChanged, this, &FormAchievements::lineEditNameAchievements_TextChanged);
    connect(ui->ButtonFindAchievement, &QPushButton::clicked, this, &FormAchievements::buttonFindAchievement_Clicked);
    connect(ui->ButtonAddCategory, &QPushButton::clicked, this, &FormAchievements::buttonAddCategory_Clicked);
    connect(ui->ButtonChangeCategory, &QPushButton::clicked, this, &FormAchievements::buttonChangeCategory_Clicked);
    connect(ui->ButtonCompare, &QPushButton::clicked, this, &FormAchievements::buttonCompare_Clicked);
    connect(ui->CheckBoxShowFilter, &QCheckBox::stateChanged, this, &FormAchievements::checkBoxShowFilter_StateChanged);
    connect(ui->ButtonDeleteAllCategories, &QPushButton::clicked, this, &FormAchievements::buttonDeleteAllCategories_Clicked);
    connect(ui->CheckBoxCompareIcon, &QCheckBox::stateChanged, _tableAchievements, [=](int arg1){_tableAchievements->setVisibleColumn(c_tableAchievementColumnIcon, arg1 == 2);});
    connect(ui->CheckBoxCompareTitle, &QCheckBox::stateChanged, _tableAchievements, [=](int arg1){_tableAchievements->setVisibleColumn(c_tableAchievementColumnTitle, arg1 == 2);});
    connect(ui->CheckBoxCompareDescription, &QCheckBox::stateChanged, _tableAchievements, [=](int arg1){_tableAchievements->setVisibleColumn(c_tableAchievementColumnDescription, arg1 == 2);});
    connect(ui->CheckBoxCompareTotalPercent, &QCheckBox::stateChanged, _tableAchievements, [=](int arg1){_tableAchievements->setVisibleColumn(c_tableAchievementColumnWorld, arg1 == 2);});
    connect(ui->ButtonAddValueCategory, &QPushButton::clicked, this, &FormAchievements::buttonAddValueCategory_Clicked);
    connect(ui->ButtonAcceptCategory, &QPushButton::clicked, this, &FormAchievements::buttonAcceptCategory_Clicked);
    connect(ui->ButtonCancelCategory, &QPushButton::clicked, this, &FormAchievements::buttonCancelCategory_Clicked);
    connect(ui->ButtonDeleteCategory, &QPushButton::clicked, this, &FormAchievements::buttonDeleteCategory_Clicked);
    connect(ui->CheckBoxCategoryOneValue, &QCheckBox::stateChanged, this, &FormAchievements::checkBoxCategoryOneValue_StateChanged);
    connect(ui->LineEditTitleCategory, &QLineEdit::textChanged, this, &FormAchievements::lineEditTitleCategory_TextChanged);
    connect(ui->ComboBoxCategories, SIGNAL(activated(int)), this, SLOT(comboBoxCategories_Activated(int)));
    connect(ui->CheckBoxCategoryVisibleAll, &QCheckBox::clicked, this, &FormAchievements::checkBoxCategoryVisibleAll_Clicked);
    connect(ui->CheckBoxFavorites, &QCheckBox::stateChanged, this, &FormAchievements::checkBoxFavorites_StateChanged);
    connect(ui->CheckBoxCategoryUniqueValue, &QCheckBox::stateChanged, this, &FormAchievements::checkBoxCategoryUniqueValue_StateChanged);
    connect(ui->ButtonFavorite, &QPushButton::clicked, this, &FormAchievements::buttonFavorite_Clicked);
    connect(_tableAchievements, &FormTablesHeaders::s_contentCellClicked, this,&FormAchievements::tableAchievements_CellClicked);
    #define ConnectsEnd }
    switchMode(FormMode::compare);
    showCategories();
    retranslate();
}

void FormAchievements::pullTable() {
    if (_tableAchievements->pullTable()) {
        showCategories();
    } else {
        ui->GroupBoxFilter->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
    }
}

void FormAchievements::retranslate() {
    ui->retranslateUi(this);
    _filterMyProfile->setTitles(tr("Все достижения"), tr("Полученные достижения"), tr("Не полученные достижения"));
    ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars, 1)->setToolTip(tr("Достижения друзей"));
    switch (_currentMode) {
    case FormMode::compare: {
        ui->ButtonCompare->setText(tr("Обратно"));
        break;
    }
    case FormMode::achievement: {
        ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
        break;
    }
    }
    switch (_typeCategory) {
    case CategoryType::add: {
        ui->GroupBoxCategories->setTitle(tr("Добавить категорию"));
        break;
    }
    case CategoryType::change: {
        ui->GroupBoxCategories->setTitle(tr("Изменить категорию"));
        break;
    }
    default: {
        break;
    }
    }
}

void FormAchievements::progressLoading(int aProgress, int aRow) {
    //qDebug()<<"Loading..."<<a_progress;
//    QButtonWithData *buttonFavorite = new QButtonWithData("");
//    buttonFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
//    buttonFavorite->setObjectName("ButtonFavorites&"+QString::number(a_row));
//    buttonFavorite->AddData("NumberGame",QString::number(a_row));
//    connect(buttonFavorite,&QButtonWithData::pressed,this,&FormAchievements::FavoritesClicked);
//    ui->TableWidgetCategory->setCellWidget(a_row,c_tableAchievementColumnFavorite,buttonFavorite);
}

void FormAchievements::onFinish(int reached, int notReached) {
    showCategories();
    if ((reached > 0) || (notReached > 0)) {
        ui->GroupBoxFilter->setEnabled(true);
        ui->LabelTotalPersent->setText(QString("%1/%2 = %3% ").arg(
                                           QString::number(reached),
                                           QString::number(reached + notReached),
                                           QString::number(100.0 * reached / (reached + notReached))));
        _filterMyProfile->update();
    }
}

QString FormAchievements::getProfile() {
    return _id;
}

int FormAchievements::getGameAppId() {
    return _game._appID;
}
#define InitEnd }

#define SimpleCompare {
void FormAchievements::switchMode(FormMode aMode) {
    switch (aMode) {
    case FormMode::compare: {
        ui->GroupBoxReachedFilter->setVisible(true);
        _tableAchievements->setType(TableType::standart);
        ui->CheckBoxCompareAllFriends->setVisible(false);
        ui->TableWidgetFriends->setVisible(false);
        ui->ButtonAddCategory->setVisible(true);
        ui->ButtonChangeCategory->setVisible(true);
        ui->ButtonDeleteAllCategories->setVisible(true);
        ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
        _currentMode = FormMode::achievement;
        break;
    }
    case FormMode::achievement: {
        ui->GroupBoxReachedFilter->setVisible(false);
        _tableAchievements->setType(TableType::compare);
        ui->CheckBoxCompareAllFriends->setVisible(true);
        ui->TableWidgetFriends->setVisible(true);
        ui->ButtonAddCategory->setVisible(false);
        ui->ButtonChangeCategory->setVisible(false);
        ui->ButtonDeleteAllCategories->setVisible(false);
        ui->ButtonCompare->setText(tr("Обратно"));
        switch (_loadCompare) {
        case 0: {
            ui->TableWidgetFriends->setVisible(false);
            loadingCompare();
            break;
        }
        case 1: {
            ui->TableWidgetFriends->setVisible(true);
            break;
        }
        default: {
            ui->TableWidgetFriends->setVisible(true);
        }
        }
        _currentMode = FormMode::compare;
        break;
    }
    }
}

void FormAchievements::loadingCompare() {
    _loadCompare++;

    _profilesFriends = SFriends(_id, false).getProfiles();
    ui->TableWidgetFriends->setColumnCount(_profilesFriends.getCount() + 2);
    for (int i = 0; i < _profilesFriends.getCount() + 2; i++) {
        ui->TableWidgetFriends->setColumnWidth(i, 33);
    }
    _profilesFriends.sort();
    ui->ProgressBarFriendsLoad->setMaximum(_profilesFriends.getCount());
    ui->ProgressBarFriendsLoad->setValue(0);
    ui->ProgressBarFriendsLoad->setVisible(true);

    int index = 0;
    for(auto &profileFriend: _profilesFriends) {
        SGames *gamesFriend = new SGames(this);
        gamesFriend->_index = index++;
        gamesFriend->set(profileFriend._steamID, true, true, true);
        connect(gamesFriend, SIGNAL(s_finished(SGames*)), this, SLOT(loadFriendGames(SGames*)));
    }
}

void FormAchievements::loadFriendGames(SGames *aGames) {
    disconnect(aGames, SIGNAL(s_finished(SGames*)), this, SLOT(loadFriendGames(SGames*)));
    bool isGameExist = false;
    for (const auto &game: *aGames) {
        if (game._appID == _game._appID) {
            isGameExist = true;
            break;
        }
    }
    QPair<SProfile, FriendType> friendState;
    friendState.first = _profilesFriends[aGames->_index];
    if (isGameExist) {
        friendState.second = FriendType::haveGame;
        _type1++;
    } else {
        friendState.second = FriendType::haventGame;
        _type2++;
    }
    _friends.push_back(std::move(friendState));
    ui->ProgressBarFriendsLoad->setValue(ui->ProgressBarFriendsLoad->value() + 1);
    if(ui->ProgressBarFriendsLoad->value() == _profilesFriends.getCount()) {
        finishLoadFriends();
    }
}

void FormAchievements::finishLoadFriends() {
    ui->ProgressBarFriendsLoad->setVisible(false);
    int row = 2;
    for(auto &friendP: _friends) {
        QLabel *avatarFriend = new QLabel(this);
        avatarFriend->setToolTip(friendP.first._personaName);
        avatarFriend->setAlignment(Qt::AlignCenter);
        new RequestImage(avatarFriend, friendP.first._avatar, this);
        ui->TableWidgetFriends->setCellWidget(0, row, avatarFriend);
        QTableWidgetItem *itemCheck(new QTableWidgetItem(""));
        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
        itemCheck->setCheckState(Qt::Unchecked);
        itemCheck->setTextAlignment(Qt::AlignCenter);
        ui->TableWidgetFriends->setItem(c_tableFriendsRowCheckBox, row, itemCheck);
        ui->TableWidgetFriends->setItem(c_tableFriendsRowID, row, new QTableWidgetItem(friendP.first._steamID));
        ui->TableWidgetFriends->setColumnHidden(row, friendP.second == FriendType::haventGame);
        row++;
    }
    connect(ui->TableWidgetFriends, &QTableWidget::cellChanged, this, &FormAchievements::tableWidgetCompareFriends_CellChanged);
    //ui->TableWidgetFriends->resizeColumnsToContents();
    _loadCompare++;
    ui->TableWidgetFriends->setVisible(true);
}

void FormAchievements::compareProfileFilterClickMy(QString, ReachedType aType) {
    _tableAchievements->updateFilterWithMyProfile(aType, true, true);
}

void FormAchievements::compareProfileFilterClickFriends(QString aName, ReachedType aType) {
    QLabel *friendAvatar = dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(0, aName.toInt()));
    if (friendAvatar) {
        QString name = friendAvatar->toolTip();
        _tableAchievements->updateFilterWithFriend(name, aType);
    } else {
        qDebug()<<"error FormAchievements::compareProfileFilterClickFriends("+aName+", "/*+QVariant::fromValue(aType).toString()+*/")";
    }
}

void FormAchievements::buttonCompareAllFriendsReach_Clicked() {
    QButtonWithData *senderButton = dynamic_cast<QButtonWithData*>(sender());
    if (senderButton) {
        ReachedType setType = ReachedType::none;
        if(senderButton->GetData(1) == "All") {
            setType = ReachedType::all;
        } else if (senderButton->GetData(1) == "Reached") {
            setType = ReachedType::reached;
        } else if (senderButton->GetData(1) == "NotReached") {
            setType = ReachedType::notReached;
        }
        for (int i = 2; i < ui->TableWidgetFriends->columnCount(); i++) {
            FormCompareProfileFilter *friendFilter = findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend" + QString::number(i));
            if (friendFilter) {
                friendFilter->setType(setType);
            } else {
                qDebug()<<"error FormAchievements::buttonCompareAllFriendsReach_Clicked() filterFriend";
            }
        }
    } else {
        qDebug()<<"error FormAchievements::buttonCompareAllFriendsReach_Clicked() sender";
    }
}

void FormAchievements::tableWidgetCompareFriends_CellChanged(int aRow, int aColumn) {
    if ((aRow == 1) && (aColumn > 1)) {
        SProfile profileFriend = _friends[aColumn - 2].first;
        if (ui->TableWidgetFriends->item(aRow, aColumn)->checkState() == Qt::Checked) {
            if (_tableAchievements->addFriendColumn(profileFriend)) {
                FormCompareProfileFilter *Filterfriend = new FormCompareProfileFilter(this);
                Filterfriend->setObjectName("FormCompareProfileFilterFriend" + QString::number(aColumn));
                Filterfriend->setName(QString::number(aColumn));
                connect(Filterfriend, &FormCompareProfileFilter::s_radioButtonChange, this, &FormAchievements::compareProfileFilterClickFriends);
                ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, aColumn, Filterfriend);
                ui->TableWidgetFriends->resizeRowsToContents();
                ui->TableWidgetFriends->resizeColumnsToContents();
            }
        } else {
            _tableAchievements->removeFriendColumn(profileFriend._personaName);
            FormCompareProfileFilter *friendFilter = findChild<FormCompareProfileFilter*>("FormCompareProfileFilterFriend" + QString::number(aColumn));
            if (friendFilter) {
                disconnect(friendFilter, &FormCompareProfileFilter::s_radioButtonChange, this, &FormAchievements::compareProfileFilterClickFriends);
                ui->TableWidgetFriends->removeCellWidget(c_tableFriendsRowFilters, aColumn);
                delete friendFilter;
                ui->TableWidgetFriends->resizeColumnsToContents();
            } else {
                qDebug()<<"error FormAchievements::tableWidgetCompareFriends_CellChanged("+QString::number(aRow)+", "+QString::number(aColumn)+") friendFilter";
            }
        }
    }
}

void FormAchievements::createCompareProfileFilter(bool aAccept, int aColumn) {
    if (aAccept) {
        FormCompareProfileFilter *friendFilter = new FormCompareProfileFilter(this);
        friendFilter->setObjectName("FormCompareProfileFilterFriend" + QString::number(aColumn));
        friendFilter->setName(QString::number(aColumn));
        connect(friendFilter, &FormCompareProfileFilter::s_radioButtonChange, this, &FormAchievements::compareProfileFilterClickFriends);
        ui->TableWidgetFriends->setCellWidget(c_tableFriendsRowFilters, aColumn, friendFilter);
        ui->TableWidgetFriends->resizeRowsToContents();
        ui->TableWidgetFriends->resizeColumnsToContents();
    }
}

void FormAchievements::checkBoxCompareAllFriends_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        for (int i = 0; i < _friends.size(); i++) {
            if(_friends[i].second == FriendType::haventGame) {
                ui->TableWidgetFriends->setColumnHidden(i + 2, true);
            }
        }
        break;
    }
    case 2: {
        for (int i = 0; i < _friends.size(); i++) {
            if (_friends[i].second == FriendType::haventGame) {
                ui->TableWidgetFriends->setColumnHidden(i + 2, false);
            }
        }
        ui->TableWidgetFriends->resizeColumnsToContents();
        break;
    }
    }
}

bool FormAchievements::setFriendAchievements(SAchievements aAchievements, int aColumn) {
    int totalReach = 0;
    int totalNotReach = 0;
    for (int row = 0; row < _tableAchievements->getRowCount(); row++) {
        for(auto &achievement: aAchievements) {
            if(achievement._apiName == _tableAchievements->itemContent(row, c_tableAchievementColumnAppid)->text()) {
                QTableWidgetItem *itemReached;
                if(achievement._achieved == 1) {
                    itemReached = new QTableWidgetItem(tr("Получено %1").arg(achievement._unlockTime.toString("yyyy.MM.dd hh:mm")));
                    itemReached->setToolTip(achievement._unlockTime.toString("yyyy.MM.dd hh:mm"));
                    totalReach++;
                } else {
                    itemReached = new QTableWidgetItem(tr("Не получено"));
                    totalNotReach++;
                }
                itemReached->setTextAlignment(Qt::AlignCenter);
                _tableAchievements->setItemContent(row, aColumn, itemReached);
                break;
            }
        }
    }
    if((totalReach == 0) && (totalNotReach == 0)) {
        _tableAchievements->setItemHorizontalHeader(1, aColumn, new QTableWidgetItem(QString("%1\n%2").arg(
                                                                                         tr("Профиль не"),
                                                                                         tr("публичный"))));
        return false;
    } else {
        _tableAchievements->setItemHorizontalHeader(1, aColumn, new QTableWidgetItem(QString("%1/%2\n%3%").arg(
                                                                                         QString::number(totalReach),
                                                                                         QString::number(totalReach + totalNotReach),
                                                                                         QString::number(100.0 * totalReach / (totalReach + totalNotReach)))));
        return true;
    }
}
#define SimpleCompareEnd }

#define System {
FormAchievements::~FormAchievements() {
    delete ui;
}

void FormAchievements::closeEvent(QCloseEvent*) {
    emit s_returnToGames(_unicNum);
    this->deleteLater();
}

void FormAchievements::changeEvent(QEvent *event) {
    if (event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormAchievements::showCategories() {
    _categoriesGame.update();
    QFormLayout *layoutComboBox = ui->layoutComboBoxCategories;
    QFormLayout *layoutCheckBox = ui->layoutCheckBoxCategories;
    while (ui->ComboBoxCategories->count() > 1) {
        ui->ComboBoxCategories->removeItem(1);
    }
    QList<QComboBoxWithData*> allComboBoxes = ui->ScrollAreaCategories->findChildren<QComboBoxWithData*>();
    QList<QCheckBoxWithData*> allCheckBoxes = ui->ScrollAreaCheckCategories->findChildren<QCheckBoxWithData*>();
    for (int i = 0; i < _categoriesGame.getCount(); i++) {
        if (_categoriesGame.getIsNoValues(i)) {
            bool accept = false;
            for (QCheckBoxWithData *currentCheckBox: allCheckBoxes) {
                if (currentCheckBox->text() == _categoriesGame.getTitle(i)) {
                    allCheckBoxes.removeOne(currentCheckBox);
                    accept = true;
                    break;
                }
            }
            if(!accept) {
                //Создать новый чекбокс
                QCheckBoxWithData *checkBoxCategoryNew = new QCheckBoxWithData(_categoriesGame.getTitle(i), this);
                checkBoxCategoryNew->setObjectName("CheckBoxCategory" + QString::number(i));
                checkBoxCategoryNew->AddData("NumberCategory", QString::number(i));
                connect(checkBoxCategoryNew, &QCheckBoxWithData::stateChanged, this, &FormAchievements::checkBoxCategory_StateChanged);
                layoutCheckBox->addRow(checkBoxCategoryNew);
            }
        } else {
            bool accept = false;
            for (QComboBoxWithData *currentComboBox: allComboBoxes) {
                if (currentComboBox->GetData("TitleCategory") == _categoriesGame.getTitle(i)) {
                    QList<QString> values;
                    for (int j = currentComboBox->count() - 1; j < _categoriesGame.getValues(i).size(); j++) {
                        values.push_back(std::move(_categoriesGame.getValues(i).at(j).toObject().value("Title").toString()));
                    }
                    for (int j = 1; j < currentComboBox->count(); j++) {
                        if(currentComboBox->itemText(j) != _categoriesGame.getValues(i).at(j - 1).toObject().value("Title").toString()) {
                            values.push_back(std::move(_categoriesGame.getValues(i).at(j - 1).toObject().value("Title").toString()));
                            currentComboBox->removeItem(j);
                        }
                    }
                    for(QString &item: values) {
                        currentComboBox->addItem(item);
                    }
                    allComboBoxes.removeOne(currentComboBox);
                    accept = true;
                    break;
                }
            }
            if (!accept) {
                //Создать новый комбобокс
                QComboBoxWithData *comboBoxCategoryNew = new QComboBoxWithData(this);
                comboBoxCategoryNew->addItem(tr("Не выбрано"));
                QJsonArray values = _categoriesGame.getValues(i);
                for (auto value: values) {
                    comboBoxCategoryNew->addItem(value.toObject().value("Title").toString());
                }
                comboBoxCategoryNew->setObjectName("ComboBoxCategory" + QString::number(i));
                comboBoxCategoryNew->AddData("NumberCategory", QString::number(i));
                comboBoxCategoryNew->AddData("TitleCategory", _categoriesGame.getTitle(i));
                connect(comboBoxCategoryNew, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxCategory_IndexChange(int)));
                layoutComboBox->addRow(new QLabel(_categoriesGame.getTitle(i), this), comboBoxCategoryNew);
            }
        }
        ui->ComboBoxCategories->addItem(_categoriesGame.getTitle(i));
    }

    for(QCheckBoxWithData *currentCheckBox: allCheckBoxes) {
        layoutCheckBox->removeRow(currentCheckBox);
    }
    for(QComboBoxWithData *currentComboBox: allComboBoxes) {
        layoutComboBox->removeRow(currentComboBox);
    }
    ui->ScrollAreaCategories->setHidden(layoutComboBox->rowCount() == 0);
    ui->ScrollAreaCheckCategories->setHidden(layoutCheckBox->rowCount() == 0);
    ui->ButtonChangeCategory->setEnabled(_categoriesGame.getCount() != 0);
    ui->ButtonDeleteAllCategories->setEnabled(_categoriesGame.getCount() != 0);

    _tableAchievements->updateFilterCategoriesColumns(_categoriesGame.getCount());
}

void FormAchievements::updateHiddenRows(){
    switch (_currentMode) {
    case FormMode::achievement: {
        if (_isUnique) {
            for (int i = 0; i < _tableAchievements->getRowCount(); i++) {
                if (_fAchievements.getData(i)) {
                    bool isExist = false;
                    for (int j = c_tableAchievementColumnCount; j < _tableAchievements->getColumnCount(); j++) {
                        if (_tableAchievements->itemContent(i, j)->checkState() == Qt::Checked) {
                            isExist = true;
                            break;
                        }
                    }
                    _tableAchievements->setVisibleRowContent(i, !isExist);
                } else {
                    _tableAchievements->setVisibleRowContent(i, false);
                }
            }
        } else {
            for (int i=0;i<_tableAchievements->getRowCount(); i++) {
                _tableAchievements->setVisibleRowContent(i, _fAchievements.getData(i));
            }
        }
        break;
    }
    case FormMode::compare: {
        for (int i = 0; i < _tableAchievements->getRowCount(); i++) {
            _tableAchievements->setVisibleRowContent(i, _fCompare.getData(i));
        }
        break;
    }
    }
}

void FormAchievements::hideCheckedAchievement(QTableWidgetItem *aItem) {
    if (aItem->column() > c_tableAchievementColumnCount) {
        if (aItem->checkState() == Qt::Checked) {
            _fAchievements.setData(aItem->row(), c_filterUniqueValue, false);
        }
    }
    updateHiddenRows();
}

FormCategoryValue *FormAchievements::createValueCategory() {
    int rowValues = ui->ListWidgetValuesCategory->count();//->rowCount();
    FormCategoryValue *newValue = new FormCategoryValue(rowValues, this);
    connect(newValue, &FormCategoryValue::s_valuechange, this, &FormAchievements::formCategoryValue_Change);
    connect(newValue, &FormCategoryValue::s_visiblechange, this, &FormAchievements::formCategoryVisible_Change);
    connect(newValue, &FormCategoryValue::s_positionchange, this, &FormAchievements::formCategoryPosition_Change);
    connect(newValue, &FormCategoryValue::s_selectchange, this, &FormAchievements::formCategorySelect_Change);
    connect(newValue, &FormCategoryValue::s_deleting, this, &FormAchievements::formCategoryDelete);
    connect(newValue, &FormCategoryValue::s_reverse, this, &FormAchievements::formCategoryReverse);
    _values.append(newValue);
    updateValuesUpDown();
    QListWidgetItem *item = new QListWidgetItem(ui->ListWidgetValuesCategory);
    item->setSizeHint(newValue->sizeHint());
    ui->ListWidgetValuesCategory->setItemWidget(item, newValue);
    return newValue;
}
#define SystemEnd }

#define Filter {
void FormAchievements::lineEditNameAchievements_TextChanged(const QString &aNewText) {
    _tableAchievements->updateFilterTextAchievement(aNewText, true, true);
}

void FormAchievements::buttonFindAchievement_Clicked() {
    lineEditNameAchievements_TextChanged(ui->LineEditNameAchievements->text());
}

void FormAchievements::buttonAddCategory_Clicked() {
    if ((_typeCategory == CategoryType::none) && (_currentMode == FormMode::achievement)) {
        _typeCategory = CategoryType::add;
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
        _tableAchievements->addNoValueColumn();
        _tableAchievements->setVisibleColumn(_tableAchievements->getNoValueColumn(), false);
    }
}

void FormAchievements::buttonChangeCategory_Clicked() {
    if ((_typeCategory == CategoryType::none) && (_currentMode == FormMode::achievement)) {
        _typeCategory = CategoryType::change;
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

void FormAchievements::buttonUpdate_Clicked() {
    _tableAchievements->update();
}

void FormAchievements::favoritesClicked() {
    QButtonWithData *button = dynamic_cast<QButtonWithData*>(sender());
    if (button) {
        int achievementIndex = button->GetData(0).toInt();
        QJsonObject gameObject;
        QJsonObject newValue;
        gameObject["id"] = _game._appID;
        gameObject["name"] = _game._name;
        newValue["id"] = _achievements[achievementIndex]._apiName;
        newValue["title"] = _achievements[achievementIndex]._displayName;
        newValue["description"] = _achievements[achievementIndex]._description;

        if (_favorites.addValue(gameObject, newValue, true)) {
            //Категория добавилась
        } else {
            //Категория уже есть (удалилась)
        }
        //Поменять картинку
    } else {
        qDebug()<<"error FormAchievements::favoritesClicked() senderButton";
    }
}

void FormAchievements::buttonCompare_Clicked() {
    switchMode(_currentMode);
}

void FormAchievements::checkBoxShowFilter_StateChanged(int arg1) {
    ui->GroupBoxFilter->setHidden(arg1 == 0);
}

void FormAchievements::comboBoxCategory_IndexChange(int aIndex) {
    if (_categoriesGame.getCount() > 0) {
        QComboBoxWithData *comboBox = dynamic_cast<QComboBoxWithData*>(sender());
        if (comboBox) {
            int categoryIndex = comboBox->GetData(0).toInt();
            if (aIndex != 0) {
                QList<QString> achievementsName = _categoriesGame.getValues(categoryIndex, aIndex - 1);
                _tableAchievements->updateFilterCategory(categoryIndex, false, achievementsName);
            } else {
                _tableAchievements->updateFilterCategory(categoryIndex, true);
            }
        } else {
            qDebug()<<"error FormAchievements::comboBoxCategory_IndexChange("+QString::number(aIndex)+") comboBox";
        }
    }
}

void FormAchievements::checkBoxCategory_StateChanged(int aIndex) {
    if (_categoriesGame.getCount() > 0) {
        QCheckBoxWithData *checkBox = dynamic_cast<QCheckBoxWithData*>(sender());
        if (checkBox) {
            int categoryIndex = checkBox->GetData(0).toInt();
            if (aIndex != 0) {
                QList<QString> achievementsName = _categoriesGame.getNoValues(categoryIndex);
                _tableAchievements->updateFilterCategory(categoryIndex, false, achievementsName);
            } else {
                _tableAchievements->updateFilterCategory(categoryIndex, true);
            }
        } else {
            qDebug()<<"error FormAchievements::checkBoxCategory_IndexChange("+QString::number(aIndex)+") checkBox";
        }
    }
}

void FormAchievements::buttonDeleteAllCategories_Clicked() {
    QMessageBox deleteQuestion(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите удалить все категории?"));
    QAbstractButton *btnYes = deleteQuestion.addButton(tr("Да"), QMessageBox::YesRole);
    deleteQuestion.addButton(tr("Отмена"), QMessageBox::NoRole);
    deleteQuestion.exec();
    if(deleteQuestion.clickedButton() == btnYes) {
        QMessageBox deleteSecondQuestion(QMessageBox::Question,
                               tr("Внимание!"),
                               tr("Данные о категориях будут утеряны навсегда, вы точно хотите удалить все категории?"));
        QAbstractButton *btnYess = deleteSecondQuestion.addButton(tr("Да"), QMessageBox::YesRole);
        deleteSecondQuestion.addButton(tr("Отмена"), QMessageBox::NoRole);
        deleteSecondQuestion.exec();
        if (deleteSecondQuestion.clickedButton() == btnYess) {
            _categoriesGame.deleteAll();
            showCategories();
        }
    }
}

#define Categorys {
void FormAchievements::buttonAddValueCategory_Clicked() {
    if ((_tableAchievements->getType() == TableType::standart) && ((_typeCategory == CategoryType::add) || (_typeCategory == CategoryType::change))) {
        _tableAchievements->addCategoryColumn();
        createValueCategory();
    }
}

void FormAchievements::buttonCancelCategory_Clicked() {
    if ((_typeCategory == CategoryType::add) || (_typeCategory == CategoryType::change)) {
        ui->GroupBoxCategories->setVisible(false);
        ui->ButtonAddCategory->setEnabled(true);
        ui->ButtonChangeCategory->setEnabled(_categoriesGame.getCount() != 0);
        ui->ButtonDeleteAllCategories->setEnabled(_categoriesGame.getCount() != 0);
        ui->ButtonCompare->setEnabled(true);
        ui->ListWidgetValuesCategory->clear();
        ui->LineEditTitleCategory->setText("");
        ui->ComboBoxCategories->setCurrentIndex(0);
        _typeCategory = CategoryType::none;
        while(!_values.isEmpty()) {
            _values.removeAt(0);
        }
        _tableAchievements->setColumnCount(c_tableAchievementColumnCount);
        checkBoxCategoryUniqueValue_StateChanged(0);
    }
}

void FormAchievements::buttonAcceptCategory_Clicked() {
    if (_typeCategory == CategoryType::add || _typeCategory == CategoryType::change) {
        if (ui->LineEditTitleCategory->text() != "") {
            int targetCategory = -1;
            if (_typeCategory == CategoryType::change) {
                targetCategory = ui->ComboBoxCategories->currentIndex() - 1;
            } else {
                targetCategory = _categoriesGame.getCount();
            }

            QList<QString> titles = _categoriesGame.getTitles();
            bool isUniqueTitle=true;
            for (int i = 0; i < titles.size(); i++) {
                if((titles[i] == ui->LineEditTitleCategory->text()) && (i != ui->ComboBoxCategories->currentIndex() - 1)) {
                    isUniqueTitle = false;
                    break;
                }
            }
            if (isUniqueTitle) {
                QJsonObject categoryNew;
                categoryNew["Title"] = ui->LineEditTitleCategory->text();
                QJsonArray valuesNew;
                QJsonArray noValuesNew;
                if (ui->CheckBoxCategoryOneValue->isChecked()) {
                    categoryNew["IsNoValues"] = 1;
                } else {
                    categoryNew["IsNoValues"] = 0;
                    for (int i = c_tableCategoryColumnNoValue + 1; i < _tableAchievements->getColumnCount(); i++) {
                        if (_tableAchievements->getHeaderText(i) == "") {
                            QMessageBox::warning(this, tr("Ошибка"), tr("Название значения пустое!"));
                            return;
                        }
                        for (int j = c_tableCategoryColumnNoValue + 1; j < i; j++) {
                            if (_tableAchievements->getHeaderText(i) == _tableAchievements->getHeaderText(j)) {
                                QMessageBox::warning(this, tr("Ошибка"), tr("Название значения повторяется!"));
                                return;
                            }
                        }
                    }
                }
                for (int j = 0; j < _tableAchievements->getRowCount(); j++) {
                    if (_tableAchievements->itemContent(j, c_tableCategoryColumnNoValue)->checkState()) {
                        noValuesNew.append(std::move(_tableAchievements->itemContent(j, c_tableAchievementColumnAppid)->text()));
                    }
                }
                for(int i = c_tableCategoryColumnNoValue + 1; i < _tableAchievements->getColumnCount(); i++) {
                    QJsonObject valueNew;
                    valueNew["Title"] = _tableAchievements->getHeaderText(i);
                    QJsonArray achievementsNew;
                    for (int j = 0; j < _tableAchievements->getRowCount(); j++) {
                        if(_tableAchievements->itemContent(j, i)->checkState()) {
                            achievementsNew.append(std::move(_tableAchievements->itemContent(j, c_tableAchievementColumnAppid)->text()));
                        }
                    }
                    valueNew["Achievements"] = achievementsNew;
                    valuesNew.append(std::move(valueNew));
                }
                categoryNew["Values"] = valuesNew;
                categoryNew["NoValues"] = noValuesNew;
                _categoriesGame.changeCategory(targetCategory, categoryNew);
                ui->LineEditTitleCategory->setText("");
                ui->LineEditTitleCategory->setEnabled(false);
                delete ui->ScrollAreaCategories->layout();
                delete ui->ScrollAreaCheckCategories->layout();
                showCategories();
                ui->LineEditNameAchievements->setText("");
                _filterMyProfile->setType(ReachedType::all);
                ui->CheckBoxFavorites->setChecked(false);
                QMessageBox::information(this, tr("Успешно"), tr("Категория была %1!").arg(_typeCategory == CategoryType::add ? tr("добавлена") : tr("изменена")));
                buttonCancelCategory_Clicked();
            } else {
                QMessageBox::warning(this, tr("Ошибка"), tr("Такая категория уже есть!"));
            }
        } else {
            QMessageBox::warning(this, tr("Ошибка"), tr("Название категории пустое!"));
        }
    }
}

void FormAchievements::buttonDeleteCategory_Clicked() {
    if (_typeCategory == CategoryType::change) {
        QMessageBox::StandardButton clickedButton = QMessageBox::question(this, tr("Внимание"), tr("Вы уверены, что хотите удалить категорию?"), QMessageBox::Yes | QMessageBox::No);
        if (clickedButton == QMessageBox::No) {
            return;
        }
        if (ui->ComboBoxCategories->currentIndex() != 0) {
            _categoriesGame.deleteCategory(ui->ComboBoxCategories->currentIndex() - 1);
            showCategories();
            ui->LineEditNameAchievements->setText("");
            _filterMyProfile->setType(ReachedType::all);
            ui->CheckBoxFavorites->setChecked(false);
            QMessageBox::information(this, tr("Успешно"), tr("Категория была удалена!"));
            buttonCancelCategory_Clicked();
        }
    }
}

void FormAchievements::checkBoxCategoryOneValue_StateChanged(int arg1) {
    if (_typeCategory == CategoryType::add || _typeCategory == CategoryType::change) {
        bool value = arg1 == 2;
        ui->ButtonAddValueCategory->setEnabled(!value);
        ui->ListWidgetValuesCategory->setEnabled(!value);
        _tableAchievements->setValuesMode(false);
    }
}

void FormAchievements::checkBoxCategoryUniqueValue_StateChanged(int arg1) {
    _tableAchievements->setUniqueMode(arg1 == 2);
}

void FormAchievements::lineEditTitleCategory_TextChanged(const QString &arg1) {
    if (_tableAchievements->getColumnCount() > c_tableCategoryColumnNoValue) {
        _tableAchievements->changeHorizontalTitle(c_tableCategoryColumnNoValue, arg1);
    }
}

void FormAchievements::comboBoxCategories_Activated(int aIndex) {
    if (_typeCategory == CategoryType::change) {
        if (_categoriesGame.getCount() > 0) {
            ui->LineEditTitleCategory->setText(ui->ComboBoxCategories->itemText(aIndex));
            ui->ListWidgetValuesCategory->clear();
            if (aIndex > 0) {
                ui->ButtonAddValueCategory->setEnabled(true);
                ui->LineEditTitleCategory->setEnabled(true);
                QList<QString> noValues = _categoriesGame.getNoValues(aIndex - 1);
                QJsonArray valuesTitles = _categoriesGame.getValues(aIndex - 1);
                _tableAchievements->categoryToTable(_categoriesGame.getTitle(aIndex - 1), noValues, valuesTitles, _categoriesGame.getIsNoValues(aIndex - 1));
                while(!_values.isEmpty()) {
                    _values.removeAt(0);
                }
                for(auto title: valuesTitles) {
                    FormCategoryValue *value = createValueCategory();
                    value->setTitle(title.toObject().value("Title").toString());
                }
            } else {
                _tableAchievements->setType(TableType::compare);
                _tableAchievements->setType(TableType::standart);
                ui->ButtonAddValueCategory->setEnabled(false);
            }
        }
    }
}

void FormAchievements::checkBoxCategoryVisibleAll_Clicked() {
    bool check = ui->CheckBoxCategoryVisibleAll->isChecked();
    for (auto &value: _values) {
        value->setVisible(check);
    }
}

void FormAchievements::updateValuesUpDown(int aValue) {
    if (aValue == -1) {
        for (int i = 0; i < _values.size(); i++) {
            switch (i) {
            case 0: {
                _values[i]->setEnabledUpDown(_values.size() == 0 ? EnabledUpDown::none : EnabledUpDown::down);
                break;
            }
            default: {
                _values[i]->setEnabledUpDown(_values.size() - 1 == i ? EnabledUpDown::up : EnabledUpDown::both);
            }
            }
        }
    } else {
        switch (aValue) {
        case 0: {
            _values[aValue]->setEnabledUpDown(_values.size() == 0 ? EnabledUpDown::none : EnabledUpDown::down);
            break;
        }
        default: {
            _values[aValue]->setEnabledUpDown(_values.size() - 1 == aValue ? EnabledUpDown::up : EnabledUpDown::both);
        }
        }
    }
}

#define CategorysValues {
void FormAchievements::formCategoryValue_Change(int aPos, QString aValue) {
    _tableAchievements->changeHorizontalTitle((c_tableCategoryColumnNoValue + 1) + aPos, aValue);
}

void FormAchievements::formCategoryVisible_Change(int aPos, bool aVisible) {
    bool isAllVisible = true;
    for (auto &value: _values) {
        if (!value->getVisible()) {
            isAllVisible = false;
            break;
        }
    }
    ui->CheckBoxCategoryVisibleAll->setCheckState(isAllVisible ? Qt::Checked : Qt::Unchecked);
    _tableAchievements->setVisibleColumn((c_tableCategoryColumnNoValue + 1) + aPos, aVisible);
}

void FormAchievements::formCategoryPosition_Change(int aPosOld, int aPosNew) {
    if(aPosNew < 0 || aPosNew > _tableAchievements->getColumnCount() - (c_tableCategoryColumnNoValue + 1)) {
        QMessageBox::warning(this, "Ошибка!", tr("Невозможно переместить значение"));
    } else {
        if (_tableAchievements->swapCategoryColumns(aPosOld, aPosNew)) {
            ui->ListWidgetValuesCategory->blockSignals(true);
            std::swap(_values[aPosOld], _values[aPosNew]);
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
}

void FormAchievements::formCategorySelect_Change(int aPos, bool aSelect) {
    _tableAchievements->setVisibleContentSelect(aPos, aSelect);
}

void FormAchievements::formCategoryDelete(int aPos) {
    _tableAchievements->removeCategoryColumn(aPos);
    QListWidgetItem* item = ui->ListWidgetValuesCategory->item(aPos);
    ui->ListWidgetValuesCategory->removeItemWidget(item);
    delete item;
    _values.removeAt(aPos);
    int pos = 0;
    for (auto &value: _values) {
        value->setPosition(pos);
        if (_values.size() == 1) {
            value->setEnabledUpDown(EnabledUpDown::none);
        } else if(_values.size() - 1 == pos) {
            value->setEnabledUpDown(EnabledUpDown::up);
        } else if(pos == 0) {
            value->setEnabledUpDown(EnabledUpDown::down);
        } else {
            value->setEnabledUpDown(EnabledUpDown::both);
        }
        pos++;
    }
}

void FormAchievements::formCategoryReverse(int aPos) {
    for (int i = 0; i < _tableAchievements->getRowCount(); i++) {
        QTableWidgetItem *item = _tableAchievements->itemContent(i, (c_tableCategoryColumnNoValue + 1) + aPos);
        item->setCheckState(item->checkState() == Qt::Checked ? Qt::Unchecked : Qt::Checked);
    }
}
#define CategoryValuesEnd }
#define CategoryEnd }
#define FilterEnd }

#define Function {
void FormAchievements::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        for (int i = 0; i < _tableAchievements->getRowCount(); i++) {
            _tableAchievements->updateFilterFavorite(i, true);
        }
        break;
    }
    case 2: {
        QJsonObject gameObject;
        gameObject["id"] = _game._appID;
        gameObject["name"] = _game._name;
        QJsonArray values = _favorites.getValues(gameObject);
        for (int i = 0; i < _tableAchievements->getRowCount(); i++) {
            bool accept = false;
            for (auto value: values) {
                if (value.toObject().value("id").toString() == _achievements[i]._apiName) {
                    accept = true;
                    break;
                }
            }
            _tableAchievements->updateFilterFavorite(i, accept);
        }
    }
    }
}

void FormAchievements::buttonFavorite_Clicked() {
    if (_currentAchievementIndex > -1) {
        QJsonObject gameObject;
        QJsonObject newValue;
        gameObject["id"] = _game._appID;
        gameObject["name"] = _game._name;
        newValue["id"] = _achievements[_currentAchievementIndex]._apiName;
        newValue["title"] = _achievements[_currentAchievementIndex]._displayName;
        newValue["description"] = _achievements[_currentAchievementIndex]._description;
        if (_favorites.addValue(gameObject, newValue, true)) {
            //Категория добавилась
            ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/in_favorites.png"));
        } else {
            //Категория уже есть (удалилась)
            ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/favorites.png"));
        }
    }
}
#define FunctionEnd }

void FormAchievements::tableAchievements_CellClicked(int row, int) {
    _currentAchievement = _tableAchievements->itemContent(row, c_tableAchievementColumnAppid)->text();
    _currentAchievementIndex = row;
    QJsonObject gameObject;
    gameObject["id"] = _game._appID;
    gameObject["name"] = _game._name;
    QJsonArray favorites = _favorites.getValues(gameObject);
    bool isFavorite = false;
    for (auto favorite: favorites) {
        if (favorite.toObject().value("id").toString() == _currentAchievement) {
            isFavorite = true;
            break;
        }
    }
    if (isFavorite) {
        ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/in_favorites.png"));
    } else {
        ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/favorites.png"));
    }
}

void FormAchievements::setTheme() {
    switch(_setting.getTheme()) {
    case 1: {
        _theme = "white";
        break;
    }
    case 2: {
        _theme = "black";
        break;
    }
    }
    setIcons();
}

void FormAchievements::setIcons() {
    ui->ButtonCompare->setIcon(QIcon("://" + _theme + "/compare.png"));
    //ui->GroupBoxFilter->setStyleSheet(""QGroupBox[accessibleName=\"Filter\"]::title {image:url(://"+_theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->GroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(://" + _theme + "/filter.png); image-position:left; margin-top:12px;}");
    ui->ButtonAddCategory->setIcon(QIcon("://create.png"));
    ui->ButtonChangeCategory->setIcon(QIcon("://" + _theme + "/change.png"));
    ui->ButtonDeleteCategory->setIcon(QIcon("://delete.png"));
    ui->ButtonDeleteAllCategories->setIcon(QIcon("://" + _theme + "/delete_all.png"));
    ui->ButtonFindAchievement->setIcon(QIcon("://" + _theme + "/find.png"));
    ui->ButtonAddValueCategory->setIcon(QIcon("://create.png"));
    ui->ButtonAcceptCategory->setIcon(QIcon("://apply.png"));
    ui->ButtonCancelCategory->setIcon(QIcon("://cancel.png"));
    ui->ButtonUpdate->setIcon(QIcon("://" + _theme + "/update.png"));
    ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/favorites.png"));
    QJsonObject gameObject;
    gameObject["id"] = _game._appID;
    gameObject["name"] = _game._name;
    QJsonArray favorites = _favorites.getValues(gameObject);
    bool isFavorite = false;
    for (auto favorite: favorites) {
        if (favorite.toObject().value("id").toString() == _currentAchievement) {
            isFavorite = true;
            break;
        }
    }
    if (isFavorite) {
        ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/in_favorites.png"));
    } else {
        ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/favorites.png"));
    }
    QLabel *friendsIcon = static_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(c_tableFriendsRowAvatars, 1));
    if (friendsIcon) {
        friendsIcon->setPixmap(QPixmap("://" + _theme + "/friends.png"));
    }
    QWidget *wFriendsFilter = dynamic_cast<QWidget*>(ui->TableWidgetFriends->cellWidget(c_tableFriendsRowFilters, 1));
    if (wFriendsFilter) {
        QButtonWithData *bFriendsAll = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(0)->widget());
        if (bFriendsAll) {
            bFriendsAll->setIcon(QIcon("://" + _theme + "/all.png"));
        } else {
            qDebug()<<"error FormAchievements::setIcons() bFriendsAll";
        }
        QButtonWithData *bFriendsReached = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(1)->widget());
        if (bFriendsReached) {
            bFriendsReached->setIcon(QIcon("://" + _theme + "/reached.png"));
        } else {
            qDebug()<<"error FormAchievements::setIcons() bFriendsReached";
        }
        QButtonWithData *bFriendsNotReached = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(2)->widget());
        if (bFriendsNotReached) {
            bFriendsNotReached->setIcon(QIcon("://" + _theme + "/notreached.png"));
        } else {
            qDebug()<<"error FormAchievements::setIcons() bFriendsNotReached";
        }
    } else {
        qDebug()<<"error FormAchievements::setIcons() wFriendsFilter";
    }
}
