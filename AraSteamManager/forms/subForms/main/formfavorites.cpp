#include "formfavorites.h"
#include "ui_formfavorites.h"
#define Constants {
constexpr int c_tableFriendsColumnID = 0;
constexpr int c_tableFriendsColumnIcon = 1;
constexpr int c_tableFriendsColumnName = 2;
constexpr int c_tableFriendsColumnStatus = 3;
constexpr int c_tableFriendsColumnisPublic = 4;
constexpr int c_tableFriendsColumnGoTo = 5;
constexpr int c_tableFriendsColumnFavorite = 6;
constexpr int c_tableFriendsColumnCount = 7;

//const int c_filterName=0;
//const int c_filterStatus=1;
//const int c_filterPublic=2;
//const int c_filterFavorites=3;
//const int c_filterCount=4;
#define ConstantsEnd }

FormFavorites::FormFavorites(QWidget *parent): QWidget(parent), ui(new Ui::FormFavorites) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    initComponents();
}

FormFavorites::~FormFavorites() {
    delete ui;
}

bool FormFavorites::isInit() {
    return true;
}

bool FormFavorites::isLoaded() {
    return true;
}

void FormFavorites::initComponents() {
//    _games.setType("games");
//    _friends.setType("friends");
//    _achievements.setType("achievements");
//    QJsonArray gamesJ = _games.getValues();
//    QJsonArray friendsJ = _friends.getValues();
//    QJsonArray achievementsJ = _achievements.getValues();
    //сделать отдельным потоком
//    for (int i = 0; i < gamesJ.size(); ++i) {
//        //
//    }
    ui->TableWidgetFriends->setColumnCount(c_tableFriendsColumnCount);
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setColumnHidden(c_tableFriendsColumnID, true);
    ui->TableWidgetFriends->setColumnWidth(c_tableFriendsColumnIcon, 33);
    ui->TableWidgetFriends->setRowCount(_favorites.friends().count());
    for(FavoriteFriend steamFriend: _favorites.friends()) {
        SProfiles *Profiles = new SProfiles(steamFriend.friendId(), true, ProfileUrlType::id);
        connect(Profiles, SIGNAL(s_finished(SProfiles*)), this, SLOT(friendLoad(SProfiles*)));
    }
//    for (int i = 0; i < achievementsJ.size(); ++i) {
//        //
//    }
    retranslate();
}

void FormFavorites::friendLoad(SProfiles *aProfile) {
    QLabel *avatarFriend = new QLabel;
    avatarFriend->setBaseSize(QSize(32,32));
    ui->TableWidgetFriends->setCellWidget(_numRequests, c_tableFriendsColumnIcon, avatarFriend);
    avatarFriend->setPixmap((*aProfile)[0].pixmapAvatar());

    QTableWidgetItem *item4 = new QTableWidgetItem;
    if(!(*aProfile)[0].gameExtraInfo().isEmpty()) {
        item4->setText(tr("В игре"));
        item4->setForeground(QColor(137,183,83));
    } else
        switch ((*aProfile)[0].personaState()) {
        case 0:{
                item4->setText(tr("Не в сети"));
                item4->setForeground(QColor(76,77,79));
                break;
        }
        case 1:{
                item4->setText(tr("В сети"));
                item4->setForeground(QColor(87,203,222));
                break;
        }
        case 2:{
                item4->setText(tr("Не беспокоить"));
                item4->setForeground(QColor(129,85,96));
                break;
        }
        case 3:{
                item4->setText(tr("Нет на месте"));
                item4->setForeground(QColor(70,120,142));
                break;
        }
        case 4:{
                item4->setText(tr("Спит"));
                item4->setForeground(QColor(70,120,142));
                break;
        }
        case 5:{
                item4->setText(tr("Ожидает обмена"));
                item4->setForeground(Qt::darkMagenta);
                break;
        }
        case 6:{
                item4->setText(tr("Хочет поиграть"));
                item4->setForeground(Qt::darkMagenta);
                break;
        }
        }
    QTableWidgetItem *item5 = new QTableWidgetItem;
    switch((*aProfile)[0].communityVisibilityState()) {
        case 1:
            item5->setText(tr("Скрытый"));
            item5->setForeground(QColor(110,14,14));
            break;
        case 2:
            item5->setText(tr("Скрытый"));
            item5->setForeground(QColor(110,14,14));
            break;
        case 3:
            item5->setText(tr("Публичный"));
            item5->setForeground(QColor(14,110,17));
            break;
        case 8:
            item5->setText(tr("Скрытый"));
            item5->setForeground(QColor(110,14,14));
            break;
    }
    ui->TableWidgetFriends->setItem(_numRequests,c_tableFriendsColumnID, new QTableWidgetItem((*aProfile)[0].steamID()));
    ui->TableWidgetFriends->setItem(_numRequests,c_tableFriendsColumnName, new QTableWidgetItem((*aProfile)[0].personaName()));
    ui->TableWidgetFriends->setItem(_numRequests,c_tableFriendsColumnStatus, item4);
    ui->TableWidgetFriends->setItem(_numRequests,c_tableFriendsColumnisPublic, item5);
    ++_numRequests;
}

void FormFavorites::updateSettings() {
    Settings::syncronizeSettings();
    setIcons();
}

void FormFavorites::setIcons() {

}

void FormFavorites::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormFavorites::retranslate() {
    ui->retranslateUi(this);
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnID, new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnIcon, new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnName, new QTableWidgetItem(tr("Ник")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnStatus, new QTableWidgetItem(tr("Статус")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnisPublic, new QTableWidgetItem(tr("Профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnGoTo, new QTableWidgetItem(tr("На профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(c_tableFriendsColumnFavorite, new QTableWidgetItem(tr("Избранное")));
}

void FormFavorites::on_pushButton_clicked() {
    ui->label   ->setStyleSheet("color: rgb(" + ui->lineEdit->text() + ");");
    ui->label_2 ->setStyleSheet("color: rgb(" + ui->lineEdit->text() + ");");
}
