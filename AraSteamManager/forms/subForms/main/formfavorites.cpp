#include "formfavorites.h"
#include "ui_formfavorites.h"

FormFavorites::FormFavorites(QWidget *parent): Form(parent), ui(new Ui::FormFavorites) {
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
    ui->TableWidgetFriends->setColumnCount(ColumnFavoritesCount);
    ui->TableWidgetFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetFriends->setAlternatingRowColors(true);
    ui->TableWidgetFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetFriends->setColumnHidden(ColumnFavoritesID, true);
    ui->TableWidgetFriends->setColumnWidth(ColumnFavoritesIcon, 33);
    ui->TableWidgetFriends->setRowCount(_favorites.friends().count());
    foreach(const FavoriteFriend &steamFriend, _favorites.friends()) {
        SProfile::load(steamFriend.friendId(), SProfileRequestType::id, std::bind(&FormFavorites::friendLoad, this,  std::placeholders::_1));
//        SProfiles *Profiles = new SProfiles(steamFriend.friendId(), true, ProfileUrlType::id);
//        connect(Profiles, SIGNAL(s_finished(SProfiles*)), this, SLOT(friendLoad(SProfiles*)));
    }
//    for (int i = 0; i < achievementsJ.size(); ++i) {
//        //
//    }
    retranslate();
}

void FormFavorites::friendLoad(SProfile aProfile) {
    QLabel *avatarFriend = new QLabel;
    avatarFriend->setBaseSize(QSize(32,32));
    ui->TableWidgetFriends->setCellWidget(_numRequests, ColumnFavoritesIcon, avatarFriend);
    avatarFriend->setPixmap(aProfile.pixmapAvatar());

    QTableWidgetItem *item4 = new QTableWidgetItem;
    if(!aProfile.gameExtraInfo().isEmpty()) {
        item4->setText(tr("В игре"));
        item4->setForeground(QColor(137,183,83));
    } else
        switch (aProfile.personaState()) {
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
    switch(aProfile.communityVisibilityState()) {
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
    ui->TableWidgetFriends->setItem(_numRequests,ColumnFavoritesID, new QTableWidgetItem(aProfile.steamID()));
    ui->TableWidgetFriends->setItem(_numRequests,ColumnFavoritesName, new QTableWidgetItem(aProfile.personaName()));
    ui->TableWidgetFriends->setItem(_numRequests,ColumnFavoritesStatus, item4);
    ui->TableWidgetFriends->setItem(_numRequests,ColumnFavoritesIsPublic, item5);
    ++_numRequests;
}

void FormFavorites::updateSettings() {
    Settings::syncronizeSettings();
    updateIcons();
}

void FormFavorites::updateIcons() {

}

void FormFavorites::retranslate() {
    ui->retranslateUi(this);
    ui->TableWidgetFriends->setHorizontalHeaderItem(ColumnFavoritesID, new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(ColumnFavoritesIcon, new QTableWidgetItem(""));
    ui->TableWidgetFriends->setHorizontalHeaderItem(ColumnFavoritesName, new QTableWidgetItem(tr("Ник")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(ColumnFavoritesStatus, new QTableWidgetItem(tr("Статус")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(ColumnFavoritesIsPublic, new QTableWidgetItem(tr("Профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(ColumnFavoritesGoTo, new QTableWidgetItem(tr("На профиль")));
    ui->TableWidgetFriends->setHorizontalHeaderItem(ColumnFavoritesFavorite, new QTableWidgetItem(tr("Избранное")));
}

void FormFavorites::on_pushButton_clicked() {
    ui->label   ->setStyleSheet("color: rgb(" + ui->lineEdit->text() + ");");
    ui->label_2 ->setStyleSheet("color: rgb(" + ui->lineEdit->text() + ");");
}
