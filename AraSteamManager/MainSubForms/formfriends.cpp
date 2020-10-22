#include "formfriends.h"
#include "ui_formfriends.h"

#define Constants {
constexpr int c_tableColumnID       = 0;
constexpr int c_tableColumnIcon     = 1;
constexpr int c_tableColumnName     = 2;
constexpr int c_tableColumnAdded    = 3;
constexpr int c_tableColumnStatus   = 4;
constexpr int c_tableColumnisPublic = 5;
constexpr int c_tableColumnActions  = 6;
constexpr int c_tableColumnCount    = 7;

constexpr int c_filterName          = 0;
constexpr int c_filterStatus        = 1;
constexpr int c_filterPublic        = 2;
constexpr int c_filterFavorites     = 3;
constexpr int c_filterCount         = 4;
#define ConstantsEnd }

#define Init {
FormFriends::FormFriends(const QString &aId, SFriends &aFriends, QWidget *aParent): QWidget(aParent), ui(new Ui::FormFriends), _id(aId), _filter(aFriends.getCount(), c_filterCount) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    initComponents(aFriends);
    ui->LineEditName->setFocus();
}

void FormFriends::initComponents(SFriends &aFriends) {
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setColumnCount(c_tableColumnCount);
    ui->TableWidgetFriends->setColumnHidden(c_tableColumnID, true);
    ui->FrameSelected->setVisible(false);

    SFriends friends(aFriends);
    SProfiles profiles(friends.getProfiles());
    profiles.sort();
    for(auto &profile: profiles) {
        for (auto &currentFriend: friends) {
            if (currentFriend._steamID == profile._steamID) {
                _friends.append(QPair<SFriend, SProfile>(currentFriend, profile));
            }
        }
    }
    ui->TableWidgetFriends->setRowCount(_friends.count());
    ui->ButtonFriendGoTo->setFixedSize(QSize(32, 32));
    ui->ButtonFriendFavorite->setFixedSize(QSize(32, 32));
    setIcons();
#define Connects {
    connect(ui->ButtonFind,           &QPushButton::clicked,            this, &FormFriends::buttonFind_Clicked);
    connect(ui->ButtonFriendGoTo,     &QPushButton::clicked,            this, &FormFriends::buttonFriendGoTo_Clicked);
    connect(ui->ButtonFriendFavorite, &QPushButton::clicked,            this, &FormFriends::buttonFriendFavorite_Clicked);
    connect(ui->ComboBoxStatus,       SIGNAL(activated(int)),           this, SLOT(comboBoxStatus_Activated(int)));
    connect(ui->LineEditName,         &QLineEdit::textChanged,          this, &FormFriends::lineEditName_TextChanged);
    connect(ui->CheckBoxOpenProfile,  &QCheckBox::stateChanged,         this, &FormFriends::checkBoxOpenProfile_StateChanged);
    connect(ui->CheckBoxFavorites,    &QCheckBox::stateChanged,         this, &FormFriends::checkBoxFavorites_StateChanged);
    connect(ui->TableWidgetFriends,   &QTableWidget::cellClicked,       this, &FormFriends::tableWidgetFriends_CellClicked);
    //connect(ui->TableWidgetFriends,   &QTableWidget::cellDoubleClicked, this, &FormFriends::tableWidgetFriends_CellDoubleClicked);
#define ConnectsEnd }
    createThread();
}

void FormFriends::pullTable(int aTo, int aDo) {
    Q_UNUSED(aTo);
    Q_UNUSED(aDo);
//    if (_visibleFriends.size() < aDo) {
//        aDo = _visibleFriends.size();
//    }
//    ui->TableWidgetFriends->setRowCount(_visibleFriends.count());
//    ui->TableWidgetFriends->setRowCount(aDo - aTo);
//    if (_visibleFriends.size() > aTo) {
//        QFont font(Settings::getFontDefaultName(), 9);

//        int row = 0;
//        for (int i = aTo; i < aDo; ++i) {
//            QLabel *avatarFriend = new QLabel();
//            ui->TableWidgetFriends->setCellWidget(row, c_tableColumnIcon, avatarFriend);
//            avatarFriend->setPixmap(_visibleFriends[i].second->getPixmapAvatar());

//            QTableWidgetItem *itemName = new QTableWidgetItem(_visibleFriends[i].second->_personaName);
//            QTableWidgetItem *itemAdded = new QTableWidgetItem(_visibleFriends[i].first->_friend_since.toString("yyyy.MM.dd hh:mm"));
//            //QTableWidgetItem *itemState = getState(_visibleFriends[i].second->_gameExtraInfo, _visibleFriends[i].second->_personaState);
//            //QTableWidgetItem *itemPrivacy = getPrivacy(_visibleFriends[i].second->_communityVisibilityState);
//            itemName->setFont(font);
//            itemAdded->setFont(font);
//            //itemState->setFont(font);
//            //itemPrivacy->setFont(font);
//            ui->TableWidgetFriends->setItem(row, c_tableColumnID, new QTableWidgetItem(_visibleFriends[i].second->_steamID));
//            ui->TableWidgetFriends->setItem(row, c_tableColumnName, itemName);
//            ui->TableWidgetFriends->setItem(row, c_tableColumnAdded, itemAdded);
//            //ui->TableWidgetFriends->setItem(row, c_tableColumnStatus, itemState);
//            //ui->TableWidgetFriends->setItem(row, c_tableColumnisPublic, itemPrivacy);
//            ui->TableWidgetFriends->setRowHeight(row, 52);
//            ++row;
//        }
//        ui->TableWidgetFriends->resizeColumnsToContents();
//        ui->TableWidgetFriends->setColumnWidth(c_tableColumnIcon, 32 + 8);
//    }
}

void FormFriends::createThread() {
    Threading *threadLoadTable = new Threading(this);
    threadLoadTable->AddThreadFriends(c_tableColumnID, c_tableColumnName, c_tableColumnAdded, c_tableColumnStatus, c_tableColumnisPublic, ui->TableWidgetFriends, _friends);
    connect (threadLoadTable, &Threading::s_friends_progress, this, [=](int progress, int row) {
                                                                        ui->TableWidgetFriends->setRowHeight(row, 36 + 18);
                                                                        emit s_friendsLoaded(progress, row);
                                                                    });
    connect (threadLoadTable, &Threading::s_friends_finished, this, &FormFriends::onTablePulled);
}

void FormFriends::onTablePulled() {
    ui->TableWidgetFriends->resizeColumnsToContents();
    int row = 0;
    for(auto &profile: _friends) {
        QLabel *avatarFriend = new QLabel(this);
        avatarFriend->setPixmap(profile.second.getPixmapAvatar());

        ui->TableWidgetFriends->setCellWidget(row, c_tableColumnIcon,    avatarFriend);
        ui->TableWidgetFriends->setCellWidget(row, c_tableColumnActions, createFriendButtonMenu(profile, row));
        ++row;
    }
    ui->TableWidgetFriends->setColumnWidth(c_tableColumnIcon,    32 + 8);
    ui->TableWidgetFriends->setColumnWidth(c_tableColumnActions, 32 + 8);
    retranslate();
//TODO Подумать над row==0
    emit s_finish();
}

QPushButton *FormFriends::createFriendButtonMenu(const QPair<SFriend, SProfile> &aProfile, int aRow) {
    QPushButton *btn = new QPushButton("...");
    btn->setFont(QFont(Settings::getFontDefaultName(), 16));
    btn->setFlat(true);
    btn->setMaximumSize(QSize(46, 32));
    btn->setObjectName("TBtn" + QString::number(aRow));
    btn->setMenu(createMenu(aProfile));
    connect (btn, &QPushButton::clicked, this,    [=]() {
                                                        tableWidgetFriends_CellClicked(aRow, 0);
                                                    });
    connect (btn, &QPushButton::clicked, btn, &QPushButton::showMenu);
    return btn;
}

QMenu *FormFriends::createMenu(const QPair<SFriend, SProfile> &aProfile) {
    QMenu* menu = new QMenu(this);

    QAction *actionGoToProfile = new QAction(tr("Перейти на профиль"), this);
    actionGoToProfile->setIcon(QIcon(Images::goTo()));

    QAction *actionFavorites = new QAction(this);
    updateActionFavoriteData(actionFavorites, isProfileFavorite(aProfile));

    connect (actionFavorites,   &QAction::triggered, this, &FormFriends::buttonFriendFavorite_Clicked);
    connect (actionGoToProfile, &QAction::triggered, this, &FormFriends::buttonFriendGoTo_Clicked);

    menu -> addAction (actionGoToProfile);
    menu -> addAction (actionFavorites);
    return menu;
}
#define InitEnd }

#define System {
FormFriends::~FormFriends() {
    delete ui;
}

void FormFriends::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormFriends::closeEvent(QCloseEvent*) {
    emit s_return_to_profile(this);
    //delete this;
}

void FormFriends::retranslate() {
    ui->retranslateUi(this);
    ui->ComboBoxStatus->clear();
    ui->ComboBoxStatus->addItems(QStringList()<<tr("Статус") <<tr("В игре") <<tr("Не в сети") <<tr("В сети") <<tr("Не беспокоить")
                                              <<tr("Нет на месте") <<tr("Спит") <<tr("Ожидает обмена") <<tr("Хочет поиграть"));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnID,        new QTableWidgetItem(tr("")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnIcon,      new QTableWidgetItem(tr("")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnName,      new QTableWidgetItem(tr("   НИК")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnAdded,     new QTableWidgetItem(tr("   ДОБАВЛЕН")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnStatus,    new QTableWidgetItem(tr("   СТАТУС")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnisPublic,  new QTableWidgetItem(tr("   ПРОФИЛЬ")));
//    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnGoTo,      new QTableWidgetItem(tr("   НА ПРОФИЛЬ")));
//    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnFavorite,  new QTableWidgetItem(tr("   ИЗБРАННОЕ")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnActions,   new QTableWidgetItem(tr("")));
    ui->TableWidgetFriends->   horizontalHeaderItem(c_tableColumnName)      ->setTextAlignment(Qt::AlignLeft);
    ui->TableWidgetFriends->   horizontalHeaderItem(c_tableColumnAdded)     ->setTextAlignment(Qt::AlignLeft);
    ui->TableWidgetFriends->   horizontalHeaderItem(c_tableColumnStatus)    ->setTextAlignment(Qt::AlignLeft);
    ui->TableWidgetFriends->   horizontalHeaderItem(c_tableColumnisPublic)  ->setTextAlignment(Qt::AlignLeft);
    ui->TableWidgetFriends->   horizontalHeaderItem(c_tableColumnName)      ->setTextAlignment(Qt::AlignVCenter);
    ui->TableWidgetFriends->   horizontalHeaderItem(c_tableColumnAdded)     ->setTextAlignment(Qt::AlignVCenter);
    ui->TableWidgetFriends->   horizontalHeaderItem(c_tableColumnStatus)    ->setTextAlignment(Qt::AlignVCenter);
    ui->TableWidgetFriends->   horizontalHeaderItem(c_tableColumnisPublic)  ->setTextAlignment(Qt::AlignVCenter);
//    friendToUi();
}

void FormFriends::updateSettings() {
    Settings::syncronizeSettings();
    updateHiddenRows();
    setIcons();
}

void FormFriends::friendToUi() {
//    int row = -1;
//    for (int i = 0; i < ui->TableWidgetFriends->rowCount(); ++i) {
//        if(ui->TableWidgetFriends->item(i, c_tableColumnID)->text() == _currentFriend) {
//            row = i;
//            break;
//        }
//    }
//    if(row > -1) {
//        QLabel *lIconFriend = dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(row, c_tableColumnIcon));
//        if (lIconFriend) {
//            ui->LabelFriendIcon->setPixmap(*lIconFriend->pixmap());
//        }
//        int indexFriend = 0;
//        _currentFriendIndex = -1;
//        for(auto &profile: _friends) {
//            if(profile.second._steamID == _currentFriend) {
//                _currentFriendIndex = indexFriend;
//                ui->LabelFriendName->setText(profile.second._personaName);
//                if(!profile.second._gameExtraInfo.isEmpty()) {
//                    ui->LabelFriendStatus->setText(tr("В игре"));
//                    ui->LabelFriendStatus->setStyleSheet("color: #89b753");
//                } else
//                    switch (profile.second._personaState) {
//                    case 0:{
//                            ui->LabelFriendStatus->setText(tr("Не в сети"));
//                            ui->LabelFriendStatus->setStyleSheet("color: #4c4d4f");
//                            break;
//                    }
//                    case 1:{
//                            ui->LabelFriendStatus->setText(tr("В сети"));
//                            ui->LabelFriendStatus->setStyleSheet("color: #57cbde");
//                            break;
//                    }
//                    case 2:{
//                            ui->LabelFriendStatus->setText(tr("Не беспокоить"));
//                            ui->LabelFriendStatus->setStyleSheet("color: #815560");
//                            break;
//                    }
//                    case 3:{
//                            ui->LabelFriendStatus->setText(tr("Нет на месте"));
//                            ui->LabelFriendStatus->setStyleSheet("color: #46788e");
//                            break;
//                    }
//                    case 4:{
//                            ui->LabelFriendStatus->setText(tr("Спит"));
//                            ui->LabelFriendStatus->setStyleSheet("color: #46788e");
//                            break;
//                    }
//                    case 5:{
//                            ui->LabelFriendStatus->setText(tr("Ожидает обмена"));
//                            ui->LabelFriendStatus->setStyleSheet("color: #761e87");
//                            break;
//                    }
//                    case 6:{
//                            ui->LabelFriendStatus->setText(tr("Хочет поиграть"));
//                            ui->LabelFriendStatus->setStyleSheet("color: #761e87");
//                            break;
//                    }
//                    }
//                switch(profile.second._communityVisibilityState) {
//                case 1:{
//                    ui->LabelFriendPublic->setText(tr("Скрытый"));
//                    ui->LabelFriendPublic->setStyleSheet("color: #9b2c2c");
//                    break;
//                }
//                case 2:{
//                    ui->LabelFriendPublic->setText(tr("Скрытый"));
//                    ui->LabelFriendPublic->setStyleSheet("color: #9b2c2c");
//                    break;
//                }
//                case 3:{
//                    ui->LabelFriendPublic->setText(tr("Публичный"));
//                    ui->LabelFriendPublic->setStyleSheet("color: #699b2c");
//                    break;
//                }
//                case 8:{
//                    ui->LabelFriendPublic->setText(tr("Скрытый"));
//                    ui->LabelFriendPublic->setStyleSheet("color: #9b2c2c");
//                    break;
//                }
//                }
//                break;
//            }
//            ++indexFriend;
//        }
//    }
//    //ui->TableWidgetFriends->setRowHeight(row, 1000);
}

void FormFriends::setIcons() {
    ui->ButtonFind          ->setIcon(QIcon(Images::findProfile()));
    ui->ButtonFriendGoTo    ->setIcon(QIcon(Images::goTo()));
    ui->ButtonFriendFavorite->setIcon(QIcon(Images::isNotFavorites()));
}

void FormFriends::updateHiddenRows() {
    for (int i = 0; i < ui->TableWidgetFriends->rowCount(); ++i) {
        ui->TableWidgetFriends->setRowHidden(i, !_filter.getData(i));
    }
}

void FormFriends::progressLoading(int aProgress, int aRow) {
    Q_UNUSED(aProgress);
    ui->TableWidgetFriends->setRowHeight(aRow, 52);
}

bool FormFriends::isProfileFavorite(const QPair<SFriend, SProfile> &aProfile) {
    QList<FavoriteFriend> favoriteFriends = _favorites.getFriends();
    return std::any_of(favoriteFriends.begin(), favoriteFriends.end(), [=](const FavoriteFriend value) {
                                                                             return (value.getId() == aProfile.second._steamID) && (value.getUserId() == _id);
                                                                         });
//    QJsonArray values = _favorites.getValues();
//    return std::any_of(values.begin(), values.end(), [=](const QJsonValue value) {
//                                                         return value.toObject().value("id").toString() == aProfile.second._steamID;
//                                                     });
}

void FormFriends::updateActionFavoriteData(QAction *aAction, bool aIsFavorite) {
    if (aIsFavorite) {
        aAction->setText(tr("Удалить из избранного"));
        aAction->setIcon(QIcon(Images::isFavorites()));
    } else {
        aAction->setText(tr("Добавить в избранное"));
        aAction->setIcon(QIcon(Images::isNotFavorites()));
    }
}
#define SystemEnd }

#define Filter {
void FormFriends::checkBoxOpenProfile_StateChanged(int aState) {
    if(aState == 2) {
        for (int i = 0; i < _friends.count(); ++i) {
            _filter.setData(i, c_filterPublic, _friends[i].second._communityVisibilityState == 3);
        }
    } else {
        for (int i = 0; i < _friends.count(); ++i) {
            _filter.setData(i, c_filterPublic, true);
        }
    }
    updateHiddenRows();
}

void FormFriends::comboBoxStatus_Activated(int aIndex) {
    switch (aIndex) {
    case 0: {
        for (int i = 0; i < _friends.count(); ++i) {
            _filter.setData(i, c_filterStatus, true);
        }
        break;
    }
    case 1: {
        for (int i = 0; i < _friends.count(); ++i) {
            _filter.setData(i, c_filterStatus, !_friends[i].second._gameExtraInfo.isEmpty());
        }
        break;
    }
    default: {
        for (int i = 0; i < _friends.count(); ++i) {
            _filter.setData(i, c_filterStatus, (_friends[i].second._personaState == ui->ComboBoxStatus->currentIndex() - 2) && (_friends[i].second._gameExtraInfo.isEmpty()));
        }
    }
    }
    updateHiddenRows();
}

void FormFriends::lineEditName_TextChanged(const QString &aNewText) {
    for (int i = 0; i < _friends.count(); ++i) {
        _filter.setData(i, c_filterName, _friends[i].second._personaName.toLower().indexOf(aNewText.toLower()) > -1);
    }
    updateHiddenRows();
}

void FormFriends::buttonFind_Clicked() {
    lineEditName_TextChanged(ui->LineEditName->text());
}

void FormFriends::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        for (int i = 0; i < _friends.count(); ++i) {
            _filter.setData(i, c_filterFavorites, true);
        }
        break;
    }
    case 2: {
        for (int i = 0; i < _friends.count(); ++i) {
            _filter.setData(i, c_filterFavorites, isProfileFavorite(_friends[i]));
        }
        break;
    }
    }
    updateHiddenRows();
}
#define FilterEnd }

#define Functions {
void FormFriends::buttonFriendGoTo_Clicked() {
    if((!_blockedLoad) && (_currentFriend2->second._steamID != "")) {
        //disconnect(sender(),SIGNAL(pressed()),this,SLOT(GoToProfileClicked()));
        _blockedLoad = true;
        emit s_go_to_profile(_currentFriend2->second._steamID, ProfileUrlType::id);
        //emit s_return_to_profile(this);
    }
}

void FormFriends::buttonFriendFavorite_Clicked() {
    if (_currentFriend2->second._steamID != "") {
        QAction *action = dynamic_cast<QAction*>(sender());
//        QJsonObject newValue;
//        newValue["id"]      = _currentFriend2.second._steamID;
//        newValue["name"]    = _currentFriend2.second._personaName;
//        newValue["added"]   = _currentFriend2.first._friend_since.toString("yyyy.MM.dd hh:mm:ss");
        bool isFavorite = _favorites.addFriend(_id, _currentFriend2->second, _currentFriend2->first, true);
        if (action) {
            updateActionFavoriteData(action, isFavorite);
        }
    }
}

void FormFriends::tableWidgetFriends_CellClicked(int aRow, int) {
    if((_currentFriend2 == nullptr) || (_currentFriend2->second._steamID != ui->TableWidgetFriends->item(aRow, c_tableColumnID)->text())) {
        QString currentFriendName = ui->TableWidgetFriends->item(aRow, c_tableColumnID)->text();
        //friendToUi();
        auto iterator = std::find_if(_friends.begin(), _friends.end(), [=](const QPair<SFriend, SProfile> &sfriend) {
                                                                            return sfriend.second._steamID == currentFriendName;
                                                                        });
        if (iterator != _friends.end()) {
            _currentFriend2 = &*iterator;
        }
    }
}

void FormFriends::tableWidgetFriends_CellDoubleClicked(int aRow, int) {
    Q_UNUSED(aRow);
    //_currentFriend = ui->TableWidgetFriends->item(aRow, c_tableColumnID)->text();
    buttonFriendGoTo_Clicked();
}
#define FunctionsEnd }
