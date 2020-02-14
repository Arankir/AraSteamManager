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
    Retranslate();
    ProfileToUi(_profile);
}

FormProfile::~FormProfile()
{
    delete ui;
}
void FormProfile::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        Retranslate();
    }
}
void FormProfile::Retranslate(){
    ui->retranslateUi(this);
    if(_profile.GetStatus()==StatusValue::success)
        ProfileToUi(_profile);
//    ui->ButtonSetProfile->setText(tr("Это мой профиль"));
//    ui->ButtonStatistics->setText(tr("Статистика"));
//    ui->ButtonFavorites->setText(tr("Избранное"));
}

void FormProfile::ProfileToUi(SProfile a_profile){
    _profile=a_profile;
    SBans bans(a_profile.GetSteamid(),false);
    SLevels levels(a_profile.GetSteamid());
    _games.Set(a_profile.GetSteamid(),true,true,false);
    _friends.Set(a_profile.GetSteamid(),false);
    ui->ButtonGames->setText(tr(" Игры (%1)").arg(_games.GetStatus()==StatusValue::success?QString::number(_games.GetCount()):tr("error")));
    ui->ButtonFriends->setText(tr(" Друзья (%1)").arg(_friends.GetStatus()==StatusValue::success?QString::number(_friends.GetCount()):tr("error")));
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
    ui->LabelProfileUrl->setText("<img height=15 style=\"vertical-align: top\" src=\"://"+_theme+"/link.png\"> <a href=\""+a_profile.GetProfileurl()+"\"><span style=\" text-decoration: underline; color:#2d7fc8;\">"+a_profile.GetProfileurl()+"</span></a>");
    ui->Labellvl->setText(tr("Уровень: %1").arg(QString::number(levels.GetLevel())));
    ui->LabelRealName->setText(tr("Настоящее имя: %1").arg(a_profile.GetRealname()));
    ui->LabelTimeCreated->setText(tr("Аккаунт создан: %1").arg(a_profile.GetTimecreated().toString("yyyy.MM.dd")));
    ui->LabelLocCountryCode->setText(tr("Язык: %1").arg(a_profile.GetLoccountrycode()));
    //Добавить описание при наведении
    switch (a_profile.GetCommunityvisibilitystate()) {
        case 1:
//            ui->LabelProfileVisibility->setText(tr("Скрытый"));
//            ui->LabelProfileVisibility->setStyleSheet("color: #6e0e0e");
            ui->LabelProfileVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Профиль"));
            break;
        case 3:
//            ui->LabelProfileVisibility->setText(tr("Публичный"));
//            ui->LabelProfileVisibility->setStyleSheet("color: #0e6e11");
            ui->LabelProfileVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Профиль"));
            break;
        case 8:
//            ui->LabelProfileVisibility->setText(tr("Для друзей"));
//            ui->LabelProfileVisibility->setStyleSheet("color: #6c6e0e");
            ui->LabelProfileVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_yellow.png\"> "+tr("Профиль"));
            break;
        default:
//            ui->LabelProfileVisibility->setText(tr("Неизвестно"));
//            ui->LabelProfileVisibility->setStyleSheet("color:white");
            ui->LabelProfileVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Профиль"));
        }
    switch (_games.GetStatus()){
    case StatusValue::success:{
        ui->ButtonGames->setEnabled(true);
        ui->ButtonStatistics->setEnabled(true);
        ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Игры"));
        break;
    }
    case StatusValue::error:{
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Игры"));
        break;
    }
    case StatusValue::none:{
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Игры"));
        break;
    }
    }
    switch (_friends.GetStatus()){
    case StatusValue::success:{
        ui->ButtonFriends->setEnabled(true);
        ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Друзья"));
        break;
    }
    case StatusValue::error:{
        ui->ButtonFriends->setEnabled(false);
        ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Друзья"));
        break;
    }
    case StatusValue::none:{
        ui->ButtonFriends->setEnabled(false);
        ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Друзья"));
        break;
    }
    }
    if(bans.GetVACBanned()){
        ui->LabelBans->setText(tr("VAC баны: %1| Последний %2 дней назад").arg(QString::number(bans.GetNumberOfVACBans())).arg(QString::number(bans.GetDaysSinceLastBan())));
        ui->LabelBans->setStyleSheet("color: #6e0e0e");
    } else {
        ui->LabelBans->setText(tr("VAC баны: Отсутствуют"));
        ui->LabelBans->setStyleSheet("color: #0e6e11");
    }

    ui->LabelAvatar->setPixmap(RequestData(a_profile.GetAvatarmedium(),false).GetPixmap());
    ui->LabelNick->setText(a_profile.GetPersonaname());

    UpdateVisibleInfo();
}

void FormProfile::SetProfile(SProfile a_profile){
    _profile=a_profile;
}

void FormProfile::UpdateTheme(){
    _setting.LoadSettings();
    switch(_setting.GetTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
    }
    ui->LabelProfileUrl->setText("<img height=15 style=\"vertical-align: top\" src=\"://"+_theme+"/link.png\"> <a href=\""+_profile.GetProfileurl()+"\"><span style=\" text-decoration: underline; color:#2d7fc8;\">"+_profile.GetProfileurl()+"</span></a>");
    ui->ButtonSetProfile->setIcon(QIcon("://"+_theme+"/set_home.png"));
    ui->ButtonFavorites->setIcon(QIcon("://"+_theme+"/favorites.png"));
    ui->ButtonStatistics->setIcon(QIcon("://"+_theme+"/statistic.png"));
    ui->ButtonFriends->setIcon(QIcon("://"+_theme+"/friends.png"));
    ui->ButtonGames->setIcon(QIcon("://"+_theme+"/games.png"));
}

void FormProfile::UpdateVisibleInfo(){
    _setting.LoadSettings();
    _visibleInfo=_setting.GetVisibleProfileInfo();
    ui->FrameInfo->setVisible(_visibleInfo);
    ui->ButtonSetProfile->setEnabled(_setting.GetMyProfile()!=_profile.GetSteamid());
}

void FormProfile::UpdateInfo(){
    _profile.Update(false);
    ProfileToUi(_profile);
}

void FormProfile::on_ButtonSetProfile_clicked(){
    if(_setting.SetMyProfile(_profile.GetSteamid())){
        ui->ButtonSetProfile->setEnabled(false);
        emit s_myProfileChange();
    }
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
