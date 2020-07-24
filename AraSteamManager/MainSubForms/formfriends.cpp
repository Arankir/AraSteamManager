#include "formfriends.h"
#include "ui_formfriends.h"

#define Constants {
constexpr int c_tableColumnID = 0;
constexpr int c_tableColumnIcon = 1;
constexpr int c_tableColumnName = 2;
constexpr int c_tableColumnAdded = 3;
constexpr int c_tableColumnStatus = 4;
constexpr int c_tableColumnisPublic = 5;
constexpr int c_tableColumnGoTo = 6;
constexpr int c_tableColumnFavorite = 7;
constexpr int c_tableColumnCount = 6;

constexpr int c_filterName = 0;
constexpr int c_filterStatus = 1;
constexpr int c_filterPublic = 2;
constexpr int c_filterFavorites = 3;
constexpr int c_filterCount = 4;
#define ConstantsEnd }

#define Init {
FormFriends::FormFriends(QString aId, SFriends aFriends, QWidget *aParent): QWidget(aParent), ui(new Ui::FormFriends), _id(aId), _friends(aFriends),
    _profiles(_friends.getProfiles()), _favorites("friends"), _filter(_friends.getCount(), c_filterCount) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    initComponents();
    ui->LineEditName->setFocus();
}

void FormFriends::initComponents() {
    ui->TableWidgetFriends->setColumnCount(c_tableColumnCount);
    retranslate();
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setRowCount(_friends.getCount());
    ui->TableWidgetFriends->setColumnHidden(c_tableColumnID, true);
    ui->TableWidgetFriends->setColumnWidth(c_tableColumnIcon, 33);
    _profiles.sort();
    ui->ButtonFriendGoTo->setFixedSize(QSize(25, 25));
    ui->ButtonFriendFavorite->setFixedSize(QSize(25, 25));
    setIcons();
#define Connects {
    connect(ui->TableWidgetFriends,   &QTableWidget::cellClicked,       this, &FormFriends::tableWidgetFriends_CellClicked);
    connect(ui->ButtonFriendGoTo,     &QPushButton::clicked,            this, &FormFriends::buttonFriendGoTo_Clicked);
    connect(ui->ButtonFriendFavorite, &QPushButton::clicked,            this, &FormFriends::buttonFriendFavorite_Clicked);
    connect(ui->CheckBoxOpenProfile,  &QCheckBox::stateChanged,         this, &FormFriends::checkBoxOpenProfile_StateChanged);
    connect(ui->ComboBoxStatus,       SIGNAL(activated(int)),           this, SLOT(comboBoxStatus_Activated(int)));
    connect(ui->LineEditName,         &QLineEdit::textChanged,          this, &FormFriends::lineEditName_TextChanged);
    connect(ui->ButtonFind,           &QPushButton::clicked,            this, &FormFriends::buttonFind_Clicked);
    connect(ui->CheckBoxFavorites,    &QCheckBox::stateChanged,         this, &FormFriends::checkBoxFavorites_StateChanged);
    connect(ui->TableWidgetFriends,   &QTableWidget::cellDoubleClicked, this, &FormFriends::tableWidgetFriends_CellDoubleClicked);
#define ConnectsEnd }
    createThread();
}

void FormFriends::onTablePulled() {
    ui->TableWidgetFriends->resizeColumnsToContents();
    int row = 0;
    for(auto &profile: _profiles) {
        QString path = _setting._pathImagesProfiles + profile._avatar.mid(72,20) + ".jpg";
        QLabel *avatarFriend = new QLabel(this);
        ui->TableWidgetFriends->setCellWidget(row, c_tableColumnIcon, avatarFriend);
        if(!QFile::exists(path)) {//Подумать над row==0
                avatarFriend->setBaseSize(QSize(32, 32));
                RequestImage* image = new RequestImage(avatarFriend, profile._avatar, path, true, this);
//                if(row==0)//не работает
//                    connect(image,&RequestImage::s_loadComplete,ui->TableWidgetFriends,[=](){
//                        TableWidgetFriends_CellClicked(0,0);
//                    });
            } else {
                avatarFriend->setPixmap(QPixmap(path));
//                if(row==0)
//                    TableWidgetFriends_CellClicked(0,0);
            }
        row++;
    }
    emit s_finish();
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
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnID, new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnIcon, new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnName, new QTableWidgetItem(tr("Ник")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnAdded, new QTableWidgetItem(tr("Добавлен")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnStatus, new QTableWidgetItem(tr("Статус")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnisPublic, new QTableWidgetItem(tr("Профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnGoTo, new QTableWidgetItem(tr("На профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnFavorite, new QTableWidgetItem(tr("Избранное")));
    friendToUi();
}

void FormFriends::updateSettings() {
    _setting.syncronizeSettings();
    setIcons();
}

void FormFriends::friendToUi() {
    int row = -1;
    for (int i = 0; i < ui->TableWidgetFriends->rowCount(); i++) {
        if(ui->TableWidgetFriends->item(i, c_tableColumnID)->text() == _currentFriend) {
            row = i;
            break;
        }
    }
    if(row > -1) {
        QLabel *lIconFriend =dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(row, c_tableColumnIcon));
        if (lIconFriend) {
            ui->LabelFriendIcon->setPixmap(*lIconFriend->pixmap());
        }
        int indexFriend = 0;
        _currentFriendIndex = -1;
        for(auto &profile: _profiles) {
            if(profile._steamID == _currentFriend) {
                _currentFriendIndex = indexFriend;
                ui->LabelFriendName->setText(profile._personaName);
                if(!profile._gameExtraInfo.isEmpty()) {
                    ui->LabelFriendStatus->setText(tr("В игре"));
                    ui->LabelFriendStatus->setStyleSheet("color: #89b753");
                } else
                    switch (profile._personaState) {
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
                switch(profile._communityVisibilityState) {
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

void FormFriends::setIcons() {
    ui->ButtonFind->setIcon(QIcon(_setting.getIconFindProfile()));
    ui->ButtonFriendGoTo->setIcon(QIcon(_setting.getIconGoTo()));
    ui->ButtonFriendFavorite->setIcon(QIcon(_setting.getIconIsNotFavorites()));
    ui->GroupBoxFilter->setStyleSheet("QGroupBox::title { "
                                        "image:url(" + _setting.getIconFilter() + ") 0 0 0 0 stretch stretch; "
                                        "image-position:left; "
                                        "margin-top:15px; "
                                      "}");
}

void FormFriends::createThread() {
    Threading *threadLoadTable = new Threading(this);
    threadLoadTable->AddThreadFriends(c_tableColumnID, c_tableColumnName, c_tableColumnAdded, c_tableColumnStatus, c_tableColumnisPublic, ui->TableWidgetFriends, _profiles, _friends);
    connect (threadLoadTable, &Threading::s_friends_progress, this, [=](int progress, int row) {
        ui->TableWidgetFriends->setRowHeight(row, 33);
        emit s_friendsLoaded(progress, row);
    });
    connect (threadLoadTable, &Threading::s_friends_finished, this, &FormFriends::onTablePulled);
}

void FormFriends::updateHiddenRows() {
    for (int i = 0; i < ui->TableWidgetFriends->rowCount(); i++) {
        ui->TableWidgetFriends->setRowHidden(i, !_filter.getData(i));
    }
}

void FormFriends::progressLoading(int aProgress,int aRow) {
    ui->TableWidgetFriends->setRowHeight(aRow, 33);
}
#define SystemEnd }

#define Filter {
void FormFriends::checkBoxOpenProfile_StateChanged(int aState) {
    if(aState == 2) {
        for (int i = 0; i < ui->TableWidgetFriends->rowCount(); i++) {
            _filter.setData(i, c_filterPublic, ui->TableWidgetFriends->item(i, c_tableColumnisPublic)->text().indexOf(tr("Публичный")) > -1);
        }
    } else {
        for (int i = 0; i < ui->TableWidgetFriends->rowCount(); i++) {
            _filter.setData(i,c_filterPublic, true);
        }
    }
    updateHiddenRows();
}

void FormFriends::comboBoxStatus_Activated(int aIndex) {
    if(aIndex != 0) {
        for (int i = 0; i < ui->TableWidgetFriends->rowCount(); i++) {
            _filter.setData(i, c_filterStatus, ui->ComboBoxStatus->currentText() == ui->TableWidgetFriends->item(i, c_tableColumnStatus)->text());
        }
    } else {
        for (int i = 0; i < ui->TableWidgetFriends->rowCount(); i++) {
            _filter.setData(i, c_filterStatus, true);
        }
    }
    updateHiddenRows();
}

void FormFriends::lineEditName_TextChanged(const QString &aNewText) {
    for (int i = 0; i < ui->TableWidgetFriends->rowCount(); i++) {
        _filter.setData(i, c_filterName, ui->TableWidgetFriends->item(i, c_tableColumnName)->text().toLower().indexOf(aNewText.toLower()) > -1);
    }
    updateHiddenRows();
}

void FormFriends::buttonFind_Clicked() {
    lineEditName_TextChanged(ui->LineEditName->text());
}

void FormFriends::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        for (int i = 0; i < ui->TableWidgetFriends->rowCount(); i++) {
            _filter.setData(i, c_filterFavorites, true);
        }
        break;
    }
    case 2: {
        QJsonArray values = _favorites.getValues();
        for (int i = 0; i < ui->TableWidgetFriends->rowCount(); i++) {
            bool isFavorite = false;
            for(QJsonValue value: values) {
                if(value.toObject().value("id").toString() == _profiles[i]._steamID) {
                    isFavorite = true;
                    break;
                }
            }
            _filter.setData(i, c_filterFavorites, isFavorite);
        }
        break;
    }
    }
    updateHiddenRows();
}
#define FilterEnd }

#define Functions {
void FormFriends::buttonFriendGoTo_Clicked() {
    if((!_blockedLoad) && (_currentFriend != "")) {
        //disconnect(sender(),SIGNAL(pressed()),this,SLOT(GoToProfileClicked()));
        _blockedLoad = true;
        emit s_go_to_profile(_currentFriend, ProfileUrlType::id);
        //emit s_return_to_profile(this);
    }
}

void FormFriends::buttonFriendFavorite_Clicked() {
    QJsonObject newValue;
    newValue["id"] = _profiles[_currentFriendIndex]._steamID;
    newValue["name"] = _profiles[_currentFriendIndex]._personaName;
    newValue["added"] = _friends[_currentFriendIndex]._friend_since.toString("yyyy.MM.dd hh:mm:ss");
    if(_favorites.addValue(newValue, true)) {
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}

void FormFriends::tableWidgetFriends_CellClicked(int aRow, int) {
    if(_currentFriend != ui->TableWidgetFriends->item(aRow, c_tableColumnID)->text()) {
        _currentFriend = ui->TableWidgetFriends->item(aRow, c_tableColumnID)->text();
        friendToUi();
    }
}

void FormFriends::tableWidgetFriends_CellDoubleClicked(int aRow, int) {
    _currentFriend = ui->TableWidgetFriends->item(aRow, c_tableColumnID)->text();
    buttonFriendGoTo_Clicked();
}
#define FunctionsEnd }
