#include "formprofile.h"
#include "ui_formprofile.h"

FormProfile::FormProfile(SProfile a_profile, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormProfile){
    ui->setupUi(this);
    _profile=a_profile;
    ui->LabelProfileVisibility->setTextFormat(Qt::RichText);
    ui->LabelGamesVisibility->setTextFormat(Qt::RichText);
    ui->LabelFriendsVisibility->setTextFormat(Qt::RichText);
    ui->LabelProfileUrl->setTextFormat(Qt::RichText);
    ui->LabelNick->setStyleSheet("color: #42a9c6;");
    ui->LabelPersonaState->setWordWrap(true);
    UpdateTheme();
    ProfileToUi(_profile);
}

FormProfile::~FormProfile(){
    delete ui;
}
void FormProfile::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        ui->retranslateUi(this);
        ui->ButtonGames->setText(tr(" Игры (%1)").arg(_games.GetStatus()==StatusValue::success?QString::number(_games.GetCount()):tr("???")));
        ui->ButtonFriends->setText(tr(" Друзья (%1)").arg(_friends.GetStatus()==StatusValue::success?QString::number(_friends.GetCount()):tr("???")));
        if(!_profile.GetGameextrainfo().isEmpty()){
            ui->LabelPersonaState->setText(tr("В игре %1").arg(_profile.GetGameextrainfo()));
            ui->LabelPersonaState->setStyleSheet("color: rgb(137,183,83);");
        } else
            switch (_profile.GetPersonastate()) {
                case 0:
                    ui->LabelPersonaState->setText(tr("Был в сети %1").arg(_profile.GetLastlogoff().toString("yyyy.MM.dd hh:mm:ss")));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(125,126,128);");
                    break;
                case 1:
                    ui->LabelPersonaState->setText(tr("В сети"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(87,203,222);");
                    break;
                case 2:
                    ui->LabelPersonaState->setText(tr("Не беспокоить"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(129,85,96);");
                    break;
                case 3:
                    ui->LabelPersonaState->setText(tr("Нет на месте"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
                case 4:
                    ui->LabelPersonaState->setText(tr("Спит"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                    break;
                case 5:
                    ui->LabelPersonaState->setText(tr("Ожидает обмена"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
                case 6:
                    ui->LabelPersonaState->setText(tr("Хочет поиграть"));
                    ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                    break;
            }

    }
}

void FormProfile::ProfileToUi(SProfile a_profile){
    _profile=a_profile;
    SBans bans(a_profile.GetSteamid(),false);
    SLevels levels(a_profile.GetSteamid());
    _games.Set(a_profile.GetSteamid(),true,true,false);
    _friends.Set(a_profile.GetSteamid(),false);
    ui->ButtonGames->setText(tr(" Игры (%1)").arg(_games.GetStatus()==StatusValue::success?QString::number(_games.GetCount()):tr("???")));
    ui->ButtonFriends->setText(tr(" Друзья (%1)").arg(_friends.GetStatus()==StatusValue::success?QString::number(_friends.GetCount()):tr("???")));
    if(!a_profile.GetGameextrainfo().isEmpty()){
        ui->LabelPersonaState->setText(tr("В игре %1").arg(a_profile.GetGameextrainfo()));
        ui->LabelPersonaState->setStyleSheet("color: rgb(137,183,83);");
    } else
        switch (a_profile.GetPersonastate()) {
            case 0:
                ui->LabelPersonaState->setText(tr("Был в сети %1").arg(a_profile.GetLastlogoff().toString("yyyy.MM.dd hh:mm:ss")));
                ui->LabelPersonaState->setStyleSheet("color: rgb(125,126,128);");
                break;
            case 1:
                ui->LabelPersonaState->setText(tr("В сети"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(87,203,222);");
                break;
            case 2:
                ui->LabelPersonaState->setText(tr("Не беспокоить"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(129,85,96);");
                break;
            case 3:
                ui->LabelPersonaState->setText(tr("Нет на месте"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                break;
            case 4:
                ui->LabelPersonaState->setText(tr("Спит"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                break;
            case 5:
                ui->LabelPersonaState->setText(tr("Ожидает обмена"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                break;
            case 6:
                ui->LabelPersonaState->setText(tr("Хочет поиграть"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                break;
        }
    ui->LabelProfileUrl->setText("<img height=13 style=\"vertical-align: top\" src=\"://"+_theme+"/link.png\"> <a href=\""+a_profile.GetProfileurl()+"\"><span style=\" text-decoration: underline; color:#2d7fc8;\">"+a_profile.GetProfileurl()+"</span></a>");
    ui->LabellvlValue->setText(QString::number(levels.GetLevel()));
    ui->LabelRealNameValue->setText(a_profile.GetRealname());
    ui->LabelTimeCreatedValue->setText(a_profile.GetTimecreated().toString("yyyy.MM.dd"));
    ui->LabelLocCountryCodeValue->setText(a_profile.GetLoccountrycode());
    QPixmap profileState;
    QPixmap gamesState;
    QPixmap friendsState;
    //Добавить описание при наведении
    switch (a_profile.GetCommunityvisibilitystate()) {
        case 1:
//            ui->LabelProfileVisibility->setText(tr("Скрытый"));
//            ui->LabelProfileVisibility->setStyleSheet("color: #6e0e0e");
            profileState.load("://state_red.png");
            break;
        case 3:
//            ui->LabelProfileVisibility->setText(tr("Публичный"));
//            ui->LabelProfileVisibility->setStyleSheet("color: #0e6e11");
            profileState.load("://state_green.png");
            break;
        case 8:
//            ui->LabelProfileVisibility->setText(tr("Для друзей"));
//            ui->LabelProfileVisibility->setStyleSheet("color: #6c6e0e");
            profileState.load("://state_yellow.png");
            break;
        default:
//            ui->LabelProfileVisibility->setText(tr("Неизвестно"));
//            ui->LabelProfileVisibility->setStyleSheet("color:white");
            profileState.load("://state_blue.png");
        }
    switch (_games.GetStatus()){
    case StatusValue::success:{
        ui->ButtonGames->setEnabled(true);
        ui->ButtonStatistics->setEnabled(true);
        gamesState.load("://state_green.png");
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Игры"));
        break;
    }
    case StatusValue::error:{
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        gamesState.load("://state_red.png");
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Игры"));
        break;
    }
    case StatusValue::none:{
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        gamesState.load("://state_blue.png");
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Игры"));
        break;
    }
    }
    switch (_friends.GetStatus()){
    case StatusValue::success:{
        ui->ButtonFriends->setEnabled(true);
        friendsState.load("://state_green.png");
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Друзья"));
        break;
    }
    case StatusValue::error:{
        ui->ButtonFriends->setEnabled(false);
        friendsState.load("://state_red.png");
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Друзья"));
        break;
    }
    case StatusValue::none:{
        ui->ButtonFriends->setEnabled(false);
        friendsState.load("://state_blue.png");
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Друзья"));
        break;
    }
    }
    ui->LabelProfileStatus->setPixmap(profileState.scaled(14,14));
    ui->LabelGamesStatus->setPixmap(gamesState.scaled(14,14));
    ui->LabelFriendsStatus->setPixmap(friendsState.scaled(14,14));
    if(bans.GetVACBanned()){
        ui->LabelBansNotNone->setText(QString::number(bans.GetNumberOfVACBans()));
        ui->LabelBansDays->setText(QString::number(bans.GetDaysSinceLastBan()));
        ui->LabelBansNotNone->setVisible(true);
        ui->LabelBansLast->setVisible(true);
        ui->LabelBansDays->setVisible(true);
        ui->LabelBansDaysAgo->setVisible(true);
        ui->LabelBansNone->setVisible(false);
//        ui->LabelBans->setText(tr("VAC баны: %1| Последний %2 дней назад").arg(QString::number(bans.GetNumberOfVACBans())).arg(QString::number(bans.GetDaysSinceLastBan())));
//        ui->LabelBans->setStyleSheet("color: #6e0e0e");
    } else {
        ui->LabelBansNotNone->setVisible(false);
        ui->LabelBansLast->setVisible(false);
        ui->LabelBansDays->setVisible(false);
        ui->LabelBansDaysAgo->setVisible(false);
        ui->LabelBansNone->setVisible(true);
//        ui->LabelBans->setText(tr("VAC баны: Отсутствуют"));
//        ui->LabelBans->setStyleSheet("color: #0e6e11");
    }

    ui->LabelAvatar->setPixmap(RequestData(a_profile.GetAvatarmedium(),false).GetPixmap());
    ui->LabelNick->setText(a_profile.GetPersonaname());

    UpdateVisibleInfo();
}

void FormProfile::SetProfile(SProfile a_profile){
    _profile=a_profile;
}

void FormProfile::UpdateTheme(){
    _setting.SyncronizeSettings();
    switch(_setting.GetTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
    }
    ui->LabelProfileUrl->setText("<img height=13 style=\"vertical-align: top\" src=\"://"+_theme+"/link.png\"> <a href=\""+_profile.GetProfileurl()+"\"><span style=\" text-decoration: underline; color:#2d7fc8;\">"+_profile.GetProfileurl()+"</span></a>");
    ui->ButtonSetProfile->setIcon(QIcon("://"+_theme+"/set_home.png"));
    ui->ButtonFavorites->setIcon(QIcon("://"+_theme+"/favorites.png"));
    ui->ButtonStatistics->setIcon(QIcon("://"+_theme+"/statistic.png"));
    ui->ButtonFriends->setIcon(QIcon("://"+_theme+"/friends.png"));
    ui->ButtonGames->setIcon(QIcon("://"+_theme+"/games.png"));
}

void FormProfile::UpdateVisibleInfo(){
    _setting.SyncronizeSettings();
    _visibleInfo=_setting.GetVisibleProfileInfo();
    ui->FrameInfo->setVisible(_visibleInfo);
    ui->ButtonSetProfile->setEnabled(_setting.GetMyProfile()!=_profile.GetSteamid());
}

void FormProfile::UpdateInfo(){
    _profile.Update(false);
    ProfileToUi(_profile);
}

void FormProfile::on_ButtonSetProfile_clicked(){
    _setting.SetMyProfile(_profile.GetSteamid());
    ui->ButtonSetProfile->setEnabled(false);
    emit s_myProfileChange();
}

void FormProfile::on_ButtonGames_clicked(){
    if(_games.GetStatus()==StatusValue::success){
        emit s_goToGames(_profile.GetSteamid(),_games);
    }
}

void FormProfile::on_ButtonFriends_clicked(){
    if(_friends.GetStatus()==StatusValue::success){
        emit s_goToFriends(_profile.GetSteamid(),_friends);
    }
}

void FormProfile::on_ButtonStatistics_clicked(){
    if(_games.GetStatus()==StatusValue::success){
        emit s_goToStatistic(_profile.GetSteamid(),_games,_profile.GetPersonaname());
    }
}

void FormProfile::on_ButtonFavorites_clicked(){
    if(true){
        emit s_goToFavorites();
    }
}
