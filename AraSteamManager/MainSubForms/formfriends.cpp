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
FormFriends::FormFriends(QString aId, SFriends aFriends, QWidget *aParent): QWidget(aParent), ui(new Ui::FormFriends), _id(aId),  _favorites("friends"),
_filter(aFriends.getCount(), c_filterCount) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    initComponents(aFriends);
    ui->LineEditName->setFocus();
}

void FormFriends::initComponents(SFriends aFriends) {
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setColumnCount(c_tableColumnCount);
    ui->TableWidgetFriends->setColumnHidden(c_tableColumnID, true);

    SFriends friends(aFriends);
    SProfiles profiles(friends.getProfiles());
    profiles.sort();
    for(auto profile: profiles) {
        for (auto currentFriend: friends) {
            if (currentFriend._steamID == profile._steamID) {
                _frienddd.append(QPair<SFriend, SProfile>(currentFriend, profile));
            }
        }
    }
    ui->ButtonFriendGoTo->setFixedSize(QSize(32, 32));
    ui->ButtonFriendFavorite->setFixedSize(QSize(32, 32));
    setIcons();
#define Connects {
    connect(ui->ButtonFind,           &QPushButton::clicked,            this, &FormFriends::buttonFind_Clicked);
    connect(ui->ButtonFriendGoTo,     &QPushButton::clicked,            this, &FormFriends::buttonFriendGoTo_Clicked);
    connect(ui->ButtonFriendFavorite, &QPushButton::clicked,            this, &FormFriends::buttonFriendFavorite_Clicked);

    connect(ui->ButtonPageFirst,      &QPushButton::clicked,            this, &FormFriends::buttonPageFirst_Clicked);
    connect(ui->ButtonPageBack2,      &QPushButton::clicked,            this, &FormFriends::buttonPageBack2_Clicked);
    connect(ui->ButtonPageBack,       &QPushButton::clicked,            this, &FormFriends::buttonPageBack_Clicked);
    connect(ui->ButtonPageNext,       &QPushButton::clicked,            this, &FormFriends::buttonPageNext_Clicked);
    connect(ui->ButtonPageNext2,      &QPushButton::clicked,            this, &FormFriends::buttonPageNext2_Clicked);
    connect(ui->ButtonPageLast,       &QPushButton::clicked,            this, &FormFriends::buttonPageLast_Clicked);

    connect(ui->ComboBoxStatus,       SIGNAL(activated(int)),           this, SLOT(comboBoxStatus_Activated(int)));
    connect(ui->LineEditName,         &QLineEdit::textChanged,          this, &FormFriends::lineEditName_TextChanged);
    connect(ui->CheckBoxOpenProfile,  &QCheckBox::stateChanged,         this, &FormFriends::checkBoxOpenProfile_StateChanged);
    connect(ui->CheckBoxFavorites,    &QCheckBox::stateChanged,         this, &FormFriends::checkBoxFavorites_StateChanged);
    connect(ui->TableWidgetFriends,   &QTableWidget::cellClicked,       this, &FormFriends::tableWidgetFriends_CellClicked);
    //connect(ui->TableWidgetFriends,   &QTableWidget::cellDoubleClicked, this, &FormFriends::tableWidgetFriends_CellDoubleClicked);
#define ConnectsEnd }
    updateHiddenRows();
    retranslate();
    //TODO Подумать над row==0
}

void FormFriends::pullTable(int aTo, int aDo) {
    if (_visibleFriends.size() < aDo) {
        aDo = _visibleFriends.size();
    }
    ui->TableWidgetFriends->setRowCount(0);
    ui->TableWidgetFriends->setRowCount(aDo - aTo);
    if (_visibleFriends.size() > aTo) {
        int id = QFontDatabase::addApplicationFont(_setting.c_defaultFont);
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont font(family, 9);

        int row = 0;
        for (int i = aTo; i < aDo; i++) {
            QString savePath = _setting._pathImagesProfiles + _visibleFriends[i].second->_avatar.mid(_visibleFriends[i].second->_avatar.lastIndexOf("/") + 1, 40) + ".jpg";
            QLabel *avatarFriend = new QLabel();
            ui->TableWidgetFriends->setCellWidget(row, c_tableColumnIcon, avatarFriend);
            if(!QFile::exists(savePath)) {
                avatarFriend->setPixmap(_visibleFriends[i].second->getPixmapAvatar(savePath));
            } else {
                avatarFriend->setPixmap(QPixmap(savePath));
            }

            QTableWidgetItem *itemName = new QTableWidgetItem(_visibleFriends[i].second->_personaName);
            QTableWidgetItem *itemAdded = new QTableWidgetItem(_visibleFriends[i].first->_friend_since.toString("yyyy.MM.dd hh:mm"));
            QTableWidgetItem *itemState = getState(_visibleFriends[i].second->_gameExtraInfo, _visibleFriends[i].second->_personaState);
            QTableWidgetItem *itemPrivacy = getPrivacy(_visibleFriends[i].second->_communityVisibilityState);
            itemName->setFont(font);
            itemAdded->setFont(font);
            itemState->setFont(font);
            itemPrivacy->setFont(font);
            ui->TableWidgetFriends->setItem(row, c_tableColumnID, new QTableWidgetItem(_visibleFriends[i].second->_steamID));
            ui->TableWidgetFriends->setItem(row, c_tableColumnName, itemName);
            ui->TableWidgetFriends->setItem(row, c_tableColumnAdded, itemAdded);
            ui->TableWidgetFriends->setItem(row, c_tableColumnStatus, itemState);
            ui->TableWidgetFriends->setItem(row, c_tableColumnisPublic, itemPrivacy);
            ui->TableWidgetFriends->setRowHeight(row, 52);
            row++;
        }
        ui->TableWidgetFriends->resizeColumnsToContents();
        ui->TableWidgetFriends->setColumnWidth(c_tableColumnIcon, 32 + 8);
    }
}

QTableWidgetItem *FormFriends::getState(QString aGameExtraInfo, int aPersonaState) {
    QTableWidgetItem *item = new QTableWidgetItem;
    if (!aGameExtraInfo.isEmpty()) {
        item->setText(tr("В игре"));
        item->setForeground(QColor(137,183,83));
    } else
        switch (aPersonaState) {
        case 0:{
                item->setText(tr("Не в сети"));
                item->setForeground(QColor(76,77,79));
                break;
        }
        case 1:{
                item->setText(tr("В сети"));
                item->setForeground(QColor(87,203,222));
                break;
        }
        case 2:{
                item->setText(tr("Не беспокоить"));
                item->setForeground(QColor(129,85,96));
                break;
        }
        case 3:{
                item->setText(tr("Нет на месте"));
                item->setForeground(QColor(70,120,142));
                break;
        }
        case 4:{
                item->setText(tr("Спит"));
                item->setForeground(QColor(70,120,142));
                break;
        }
        case 5:{
                item->setText(tr("Ожидает обмена"));
                item->setForeground(Qt::darkMagenta);
                break;
        }
        case 6:{
                item->setText(tr("Хочет поиграть"));
                item->setForeground(Qt::darkMagenta);
                break;
        }
        }
    return item;
}

QTableWidgetItem *FormFriends::getPrivacy(int aCommunityVisibilityState) {
    QTableWidgetItem *item = new QTableWidgetItem;
    switch (aCommunityVisibilityState) {
    case 1:{
        item->setText(tr("Скрытый"));
        item->setForeground(QColor(155,44,44));
        break;
    }
    case 2:{
        item->setText(tr("Скрытый"));
        item->setForeground(QColor(155,44,44));
        break;
    }
    case 3:{
        item->setText(tr("Публичный"));
        item->setForeground(QColor(105,155,44));
        break;
    }
    case 8:{
        item->setText(tr("Скрытый"));
        item->setForeground(QColor(155,44,44));
        break;
    }
    }
    return item;
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
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnName, new QTableWidgetItem(tr("   НИК")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnAdded, new QTableWidgetItem(tr("   ДОБАВЛЕН")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnStatus, new QTableWidgetItem(tr("   СТАТУС")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnisPublic, new QTableWidgetItem(tr("   ПРОФИЛЬ")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnGoTo, new QTableWidgetItem(tr("   НА ПРОФИЛЬ")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableColumnFavorite, new QTableWidgetItem(tr("   ИЗБРАННОЕ")));
    ui->TableWidgetFriends->horizontalHeaderItem(c_tableColumnName)->setTextAlignment(Qt::AlignLeft);
    ui->TableWidgetFriends->horizontalHeaderItem(c_tableColumnAdded)->setTextAlignment(Qt::AlignLeft);
    ui->TableWidgetFriends->horizontalHeaderItem(c_tableColumnStatus)->setTextAlignment(Qt::AlignLeft);
    ui->TableWidgetFriends->horizontalHeaderItem(c_tableColumnisPublic)->setTextAlignment(Qt::AlignLeft);
    ui->TableWidgetFriends->horizontalHeaderItem(c_tableColumnName)->setTextAlignment(Qt::AlignVCenter);
    ui->TableWidgetFriends->horizontalHeaderItem(c_tableColumnAdded)->setTextAlignment(Qt::AlignVCenter);
    ui->TableWidgetFriends->horizontalHeaderItem(c_tableColumnStatus)->setTextAlignment(Qt::AlignVCenter);
    ui->TableWidgetFriends->horizontalHeaderItem(c_tableColumnisPublic)->setTextAlignment(Qt::AlignVCenter);
    friendToUi();
}

void FormFriends::updateSettings() {
    _setting.syncronizeSettings();
    updateHiddenRows();
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
        QLabel *lIconFriend = dynamic_cast<QLabel*>(ui->TableWidgetFriends->cellWidget(row, c_tableColumnIcon));
        if (lIconFriend) {
            ui->LabelFriendIcon->setPixmap(*lIconFriend->pixmap());
        }
        int indexFriend = 0;
        _currentFriendIndex = -1;
        for(auto &profile: _frienddd) {
            if(profile.second._steamID == _currentFriend) {
                _currentFriendIndex = indexFriend;
                ui->LabelFriendName->setText(profile.second._personaName);
                if(!profile.second._gameExtraInfo.isEmpty()) {
                    ui->LabelFriendStatus->setText(tr("В игре"));
                    ui->LabelFriendStatus->setStyleSheet("color: #89b753");
                } else
                    switch (profile.second._personaState) {
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
                switch(profile.second._communityVisibilityState) {
                case 1:{
                    ui->LabelFriendPublic->setText(tr("Скрытый"));
                    ui->LabelFriendPublic->setStyleSheet("color: #9b2c2c");
                    break;
                }
                case 2:{
                    ui->LabelFriendPublic->setText(tr("Скрытый"));
                    ui->LabelFriendPublic->setStyleSheet("color: #9b2c2c");
                    break;
                }
                case 3:{
                    ui->LabelFriendPublic->setText(tr("Публичный"));
                    ui->LabelFriendPublic->setStyleSheet("color: #699b2c");
                    break;
                }
                case 8:{
                    ui->LabelFriendPublic->setText(tr("Скрытый"));
                    ui->LabelFriendPublic->setStyleSheet("color: #9b2c2c");
                    break;
                }
                }
                break;
            }
            indexFriend++;
        }
    }
    //ui->TableWidgetFriends->setRowHeight(row, 1000);
}

void FormFriends::setIcons() {
    ui->ButtonFind->setIcon(QIcon(_setting.getIconFindProfile()));
    ui->ButtonFriendGoTo->setIcon(QIcon(_setting.getIconGoTo()));
    ui->ButtonFriendFavorite->setIcon(QIcon(_setting.getIconIsNotFavorites()));
}

void FormFriends::updateHiddenRows() {
    _visibleFriends.clear();
    int index = 0;
    for (auto &userFriend: _frienddd) {
        if (_filter.getData(index)) {
            _visibleFriends.append(QPair<SFriend*, SProfile*>(&userFriend.first, &userFriend.second));
        }
        index++;
    }

    calculateButtonPages();
    pullTable(_currentPage * _setting.getMaximumTableRows(), (_currentPage + 1) * _setting.getMaximumTableRows());
}

void FormFriends::calculateButtonPages() {
    int pages = _visibleFriends.size() / _setting.getMaximumTableRows() + 1;
    if (_currentPage >= pages) {
        _currentPage = pages - 1;
    }
    if (_currentPage < 0) {
        _currentPage = 0;
    }

    updateButtonsPages(_currentPage > 0, "1",
                       _currentPage > 3,
                       _currentPage > 2, QString::number(_currentPage - 1),
                       _currentPage > 1, QString::number(_currentPage),
                       true, QString::number(_currentPage + 1),
                       pages > (_currentPage + 1), QString::number(_currentPage + 2),
                       pages > (_currentPage + 2), QString::number(_currentPage + 3),
                       pages > (_currentPage + 4),
                       pages > (_currentPage + 3), QString::number(pages));
}

void FormFriends::updateButtonsPages(bool aFirst, QString aFirstText, bool aLabelDots1, bool aBack2, QString aBack2Text, bool aBack, QString aBackText,
                                     bool aCurrent, QString aCurrentText,
                                     bool aNext, QString aNextText, bool aNext2, QString aNext2Text, bool aLabelDots2, bool aLast, QString aLastText) {
    ui->ButtonPageFirst->setVisible(aFirst);
    ui->ButtonPageFirst->setText(aFirstText);

    ui->LabelBackDots->setVisible(aLabelDots1);

    ui->ButtonPageBack2->setVisible(aBack2);
    ui->ButtonPageBack2->setText(aBack2Text);

    ui->ButtonPageBack->setVisible(aBack);
    ui->ButtonPageBack->setText(aBackText);

    ui->ButtonPageNow->setVisible(aCurrent);
    ui->ButtonPageNow->setText(aCurrentText);

    ui->ButtonPageNext->setVisible(aNext);
    ui->ButtonPageNext->setText(aNextText);

    ui->ButtonPageNext2->setVisible(aNext2);
    ui->ButtonPageNext2->setText(aNext2Text);

    ui->LabelNextDots->setVisible(aLabelDots2);

    ui->ButtonPageLast->setVisible(aLast);
    ui->ButtonPageLast->setText(aLastText);
}

void FormFriends::buttonPageFirst_Clicked() {
    _currentPage = 0;
    calculateButtonPages();
    pullTable(_currentPage * _setting.getMaximumTableRows(), (_currentPage + 1) * _setting.getMaximumTableRows());
}

void FormFriends::buttonPageBack2_Clicked() {
    _currentPage -= 2;
    calculateButtonPages();
    pullTable(_currentPage * _setting.getMaximumTableRows(), (_currentPage + 1) * _setting.getMaximumTableRows());
}

void FormFriends::buttonPageBack_Clicked() {
    _currentPage--;
    calculateButtonPages();
    pullTable(_currentPage * _setting.getMaximumTableRows(), (_currentPage + 1) * _setting.getMaximumTableRows());
}

void FormFriends::buttonPageNext_Clicked() {
    _currentPage++;
    calculateButtonPages();
    pullTable(_currentPage * _setting.getMaximumTableRows(), (_currentPage + 1) * _setting.getMaximumTableRows());
}

void FormFriends::buttonPageNext2_Clicked() {
    _currentPage += 2;
    calculateButtonPages();
    pullTable(_currentPage * _setting.getMaximumTableRows(), (_currentPage + 1) * _setting.getMaximumTableRows());
}

void FormFriends::buttonPageLast_Clicked() {
    _currentPage = _visibleFriends.size() / _setting.getMaximumTableRows();
    calculateButtonPages();
    pullTable(_currentPage * _setting.getMaximumTableRows(), (_currentPage + 1) * _setting.getMaximumTableRows());
}

void FormFriends::progressLoading(int aProgress,int aRow) {
    ui->TableWidgetFriends->setRowHeight(aRow, 52);
}
#define SystemEnd }

#define Filter {
void FormFriends::checkBoxOpenProfile_StateChanged(int aState) {
    if(aState == 2) {
        for (int i = 0; i < _frienddd.count(); i++) {
            _filter.setData(i, c_filterPublic, _frienddd[i].second._communityVisibilityState == 3);
        }
    } else {
        for (int i = 0; i < _frienddd.count(); i++) {
            _filter.setData(i, c_filterPublic, true);
        }
    }
    updateHiddenRows();
}

void FormFriends::comboBoxStatus_Activated(int aIndex) {
    switch (aIndex) {
    case 0: {
        for (int i = 0; i < _frienddd.count(); i++) {
            _filter.setData(i, c_filterStatus, true);
        }
        break;
    }
    case 1: {
        for (int i = 0; i < _frienddd.count(); i++) {
            _filter.setData(i, c_filterStatus, !_frienddd[i].second._gameExtraInfo.isEmpty());
        }
        break;
    }
    default: {
        for (int i = 0; i < _frienddd.count(); i++) {
            _filter.setData(i, c_filterStatus, (_frienddd[i].second._personaState == ui->ComboBoxStatus->currentIndex() - 2) && (_frienddd[i].second._gameExtraInfo.isEmpty()));
        }
    }
    }
    updateHiddenRows();
}

void FormFriends::lineEditName_TextChanged(const QString &aNewText) {
    for (int i = 0; i < _frienddd.count(); i++) {
        _filter.setData(i, c_filterName, _frienddd[i].second._personaName.toLower().indexOf(aNewText.toLower()) > -1);
    }
    updateHiddenRows();
}

void FormFriends::buttonFind_Clicked() {
    lineEditName_TextChanged(ui->LineEditName->text());
}

void FormFriends::checkBoxFavorites_StateChanged(int arg1) {
    switch (arg1) {
    case 0: {
        for (int i = 0; i < _frienddd.count(); i++) {
            _filter.setData(i, c_filterFavorites, true);
        }
        break;
    }
    case 2: {
        QJsonArray values = _favorites.getValues();
        for (int i = 0; i < _frienddd.count(); i++) {
            bool isFavorite = false;
            for(QJsonValue value: values) {
                if(value.toObject().value("id").toString() == _frienddd[i].second._steamID) {
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
    newValue["id"] = _frienddd[_currentFriendIndex].second._steamID;
    newValue["name"] = _frienddd[_currentFriendIndex].second._personaName;
    newValue["added"] = _frienddd[_currentFriendIndex].first._friend_since.toString("yyyy.MM.dd hh:mm:ss");
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
