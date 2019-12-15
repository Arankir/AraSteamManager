#include "mainwindow.h"
#include "ui_mainwindow.h"
//    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
//qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
    switch(_setting.GetTheme()){
    case 1:{
        QPalette darkPalette;
        darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
        darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(73, 73, 73),Qt::white,Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
        //                        тип               ,???      ,Кнопка            ,Разделители,???      ,???     ,цвет текста на кнопке,???  ,поле сзади     ,???
        qApp->setPalette(darkPalette);
        _theme="white";
        break;
        }
    case 2:{
        _theme="black";
        // Настраиваем палитру для цветовых ролей элементов интерфейса
        //    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::WindowText, Qt::white);
        //    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        //    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        //    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        //    darkPalette.setColor(QPalette::Text, Qt::white);
        //    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ButtonText, Qt::white);
        //    darkPalette.setColor(QPalette::BrightText, Qt::red);
        //    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
        // Устанавливаем данную палитру
            // Для возврата к светлой палитре достаточно
            // будет установить стандартную палитру из темы оформления
            //qApp->setPalette(style()->standardPalette());
        break;
        }
    }
    InitComponents();
    if(_setting.GetStatus()=="success"){
        if(_setting.GetMyProfile()!="none")
            GoToProfile(_setting.GetMyProfile(),"url");
    }
}

#define Init {
void MainWindow::InitComponents(){
    ui->LabelAvatar->setText("");
    ui->LabelLogo->setPixmap(QPixmap(":/program/program/logo.png"));
    ui->LabelTimeCreated->setText("");
    ui->LabelPersonaState->setText("");
    ui->LabelLocCountryCode->setText("");
    ui->LabelProfileUrl->setText("");
    ui->LabelRealName->setText("");
    ui->Labellvl->setText("");
    ui->LabelBans->setText("");
    ui->LabelPersonaState->setWordWrap(true);
    ui->ButtonGames->setVisible(false);
    ui->ButtonFriends->setVisible(false);
    ui->ButtonFavorites->setVisible(false);
    ui->ButtonSetProfile->setVisible(false);
    ui->ButtonStatistics->setVisible(false);
    ui->ButtonGoToMyProfile->setVisible(false);
    //ui->ScrollAreaForm->setVisible(false);
    ui->LabelNick->setVisible(false);
    ui->line->setVisible(false);
    ui->LabelProfileVisibility->setVisible(false);
    ui->ScrollAreaProfileInfo->setVisible(false);
    ui->FormProgressBar->setVisible(false);
    ui->ButtonFindProfile->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/find.png"));
    ui->ButtonFavorites->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/favorites.png"));
    ui->ButtonStatistics->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/statistic.png"));
    ui->ButtonSettings->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/settings.png"));
    ui->ButtonExit->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/exit.png"));
    ui->ButtonFriends->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/friends.png"));
    ui->ButtonGames->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/games.png"));
    ui->ButtonBack->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/left.png"));
    ui->ButtonNext->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/right.png"));
    ui->ButtonBack->setText("");
    ui->ButtonNext->setText("");
    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);
    //ui->LabelRealName->setTextFormat(Qt::RichText);!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //ui->LabelRealName->setText("<img src=\"images/program/cog4.png\">Hello!");!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
void MainWindow::ProgressLoading(int p,int){
    ui->FormProgressBar->setValue(p);
}
#define InitEnd }

#define System {
void MainWindow::ShowGames(){
    ui->FormProgressBar->setVisible(false);
    _gamesForm->setVisible(true);
}
void MainWindow::ShowFriends(){
    ui->FormProgressBar->setVisible(false);
    _friendsForm->setVisible(true);
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    //qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter;
    if(event->key() == 16777220)
        on_ButtonFindProfile_clicked();
}
void MainWindow::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
    //    ui->retranslateUi(this);
    }
}
MainWindow::~MainWindow(){
    ReturnFromForms();
    delete ui;
}
void MainWindow::ReturnFromForms(){
    switch(_windowChild){
    case 1:{
        ReturnFromGames();
        break;
    }
    case 2:{
        ReturnFromFriends();
        break;
    }
    case 3:{
        ReturnFromFavorites();
        break;
    }
    case 4:{
        ReturnFromStatistics();
        break;
    }
    case 5:{
        ReturnFromSettings();
        break;
    }
    }
}
void MainWindow::ReturnFromGames(){
    disconnect(_gamesForm);
    delete _gamesForm;
    _windowChildCount--;
    _windowChild=0;
}
void MainWindow::ReturnFromFriends(){
    disconnect(_friendsForm);
    delete _friendsForm;
    _windowChildCount--;
    _windowChild=0;
}
void MainWindow::ReturnFromFavorites(){
    disconnect(_favoritesForm);
    delete _favoritesForm;
    _windowChildCount--;
    _windowChild=0;
}
void MainWindow::ReturnFromStatistics(){
    disconnect(_statisticsForm);
    delete _statisticsForm;
    _windowChildCount--;
    _windowChild=0;
}
void MainWindow::ReturnFromSettings(){
    disconnect(_settingsForm);
    delete _settingsForm;
    _windowChildCount--;
    _windowChild=0;
}
#define SystemEnd }

#define Functions {
void MainWindow::on_ButtonFindProfile_clicked(){
    QString id=ui->LineEditIdProfile->text().remove("https://").remove("steamcommunity.com/").remove('\r');
    if(ui->LineEditIdProfile->text().indexOf("id",0)>-1){
        id=id.remove("id/").remove("/");
        GoToProfile(id,"vanity");
    } else {
        if(ui->LineEditIdProfile->text().indexOf("profiles",0)>-1)
            id=id.remove("profiles/").remove("/");
        GoToProfile(id,"url");
        }
    switch(_windowChild){
    case 1:{
        ReturnFromGames();
        break;
    }
    case 2:{
        ReturnFromFriends();
        break;
    }
    }
}
void MainWindow::GoToProfile(QString AID, QString AType){
    SProfile profile(AID,false,AType);
    if(profile.GetStatus()=="success"){
        if(_currentBufferProfile!=_bufferProfiles.size())
            while(_bufferProfiles.size()!=_currentBufferProfile)
                _bufferProfiles.takeAt(_currentBufferProfile);
        _bufferProfiles.append(profile);
        _currentBufferProfile=_bufferProfiles.size();
        if(_currentBufferProfile==_bufferProfiles.size())
            ui->ButtonNext->setEnabled(false);
        else
            ui->ButtonNext->setEnabled(true);
        if(_currentBufferProfile<2)
            ui->ButtonBack->setEnabled(false);
        else
            ui->ButtonBack->setEnabled(true);
        qDebug()<<"Буфер профилей"<<_currentBufferProfile<<"/"<<_bufferProfiles.size();
        ProfileToUi(profile);
        } else {
            QMessageBox::warning(this,tr("Ошибка"),tr("Не удаётся найти профиль!"));
        }
}
void MainWindow::ProfileToUi(SProfile AProfile){
    _profile=AProfile;
    _games.Clear();
    _friends.Clear();
    SBans Bans(AProfile.GetSteamid(),false);
    SLevels Levels(AProfile.GetSteamid());
    _games.Set(AProfile.GetSteamid(),true,true,false);
    _friends.Set(AProfile.GetSteamid(),false);
    //ui->LabelProfileUrl->setTextFormat(Qt::RichText);
    //ui->LabelProfileUrl->setText("<img src=\":/"+theme+"/program/"+theme+"/link.png\" width=\"15\" height=\"15\">"+Profile.GetProfileurl());
    ui->ButtonGames->setText(tr(" Игры (%1)").arg(_games.GetStatus()=="success"?QString::number(_games.GetCount()):"error"));
    ui->ButtonFriends->setText(tr(" Друзья (%1)").arg(_friends.GetStatus()=="success"?QString::number(_friends.GetCount()):"error"));
    if(!AProfile.GetGameextrainfo().isEmpty()){
        ui->LabelPersonaState->setText(tr("В игре %1").arg(AProfile.GetGameextrainfo()));
        ui->LabelPersonaState->setStyleSheet("color: rgb(137,183,83);");
    } else
        switch (AProfile.GetPersonastate()) {
        case 0:{
                ui->LabelPersonaState->setText(tr("Был в сети %1").arg(AProfile.GetLastlogoff().toString("yyyy.MM.dd hh:mm:ss")));
                ui->LabelPersonaState->setStyleSheet("color: rgb(125,126,128);");
                break;
        }
        case 1:{
                ui->LabelPersonaState->setText(tr("В сети"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(87,203,222);");
                break;
        }
        case 2:{
                ui->LabelPersonaState->setText(tr("Не беспокоить"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(129,85,96);");
                break;
        }
        case 3:{
                ui->LabelPersonaState->setText(tr("Нет на месте"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                break;
        }
        case 4:{
                ui->LabelPersonaState->setText(tr("Спит"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                break;
        }
        case 5:{
                ui->LabelPersonaState->setText(tr("Ожидает обмена"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                break;
        }
        case 6:{
                ui->LabelPersonaState->setText(tr("Хочет поиграть"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                break;
        }
        }
    ui->LabelProfileUrl->setText(AProfile.GetProfileurl());
    ui->Labellvl->setText(tr("Уровень: %1").arg(QString::number(Levels.GetLevel())));
    ui->LabelRealName->setText(tr("Настоящее имя: %1").arg(AProfile.GetRealname()));
    ui->LabelTimeCreated->setText(tr("Аккаунт создан: %1").arg(AProfile.GetTimecreated().toString("yyyy.MM.dd")));
    ui->LabelLocCountryCode->setText(tr("Язык: %1").arg(AProfile.GetLoccountrycode()));
    switch (AProfile.GetCommunityvisibilitystate()) {
        case 1:{
            ui->LabelProfileVisibility->setText(tr("Скрытый"));
            ui->LabelProfileVisibility->setStyleSheet("color:red");
            break;
        }
        case 3:{
            ui->LabelProfileVisibility->setText(tr("Публичный"));
            ui->LabelProfileVisibility->setStyleSheet("color:green");
            break;
        }
        case 8:{
            ui->LabelProfileVisibility->setText(tr("Для друзей"));
            ui->LabelProfileVisibility->setStyleSheet("color:yellow");
            break;
        }
        default:{
            ui->LabelProfileVisibility->setText(tr("Неизвестно"));
            ui->LabelProfileVisibility->setStyleSheet("color:white");
        }
        }
    if(Bans.GetVACBanned()){
        ui->LabelBans->setText(tr("VAC баны: %1| Последний %2 дней назад").arg(QString::number(Bans.GetNumberOfVACBans())).arg(QString::number(Bans.GetDaysSinceLastBan())));
        ui->LabelBans->setStyleSheet("color:red");
    } else {
        ui->LabelBans->setText(tr("VAC баны: Отсутствуют"));
        ui->LabelBans->setStyleSheet("color:green");
    }

    QNetworkAccessManager imagemanager;
    QEventLoop imageloop;
    connect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
    QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(AProfile.GetAvatarmedium()));
    imageloop.exec();
    disconnect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
    QPixmap img;
    img.loadFromData(imagereply.readAll());
    ui->LabelAvatar->setPixmap(img);
    ui->LabelNick->setText(AProfile.GetPersonaname());
    //ui->LabelAvatar->setTextFormat(Qt::RichText);
    //ui->LabelAvatar->setText("<img src=\"images/profiles/main.png\"> "+Profile.GetPersonaname());
    //ui->LabelNick->setFont(QFont("MS Shell Dlg 2",14));
    ui->ButtonGames->setVisible(true);
    ui->ButtonFriends->setVisible(true);
    ui->ButtonFavorites->setVisible(true);
    ui->ButtonSetProfile->setVisible(true);
    ui->ButtonStatistics->setVisible(true);
    ui->ButtonGoToMyProfile->setVisible(true);
    ui->LabelNick->setVisible(true);
    ui->line->setVisible(true);
    ui->LabelProfileVisibility->setVisible(true);
    ui->ScrollAreaProfileInfo->setVisible(true);

    ui->ButtonGames->setEnabled(_games.GetStatus()=="success");
    ui->ButtonFriends->setEnabled(_friends.GetStatus()=="success");
    ui->ButtonFavorites->setEnabled(true);
    ui->ButtonSetProfile->setEnabled(_setting.GetMyProfile()!=AProfile.GetSteamid());
    ui->ButtonStatistics->setEnabled(true);
    ui->ButtonGoToMyProfile->setEnabled((_setting.GetMyProfile()!="none")&&(_setting.GetMyProfile()!=AProfile.GetSteamid()));

}
void MainWindow::on_ButtonBack_clicked(){
    if(_currentBufferProfile>1){
        ui->ButtonGames->setEnabled(false);
        ui->ButtonFriends->setEnabled(false);
        ui->ButtonFavorites->setEnabled(false);
        ui->ButtonSetProfile->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        ui->ButtonGoToMyProfile->setEnabled(false);
        ProfileToUi(_bufferProfiles[--_currentBufferProfile-1]);
        if(_currentBufferProfile==_bufferProfiles.size())
            ui->ButtonNext->setEnabled(false);
        else
            ui->ButtonNext->setEnabled(true);
        if(_currentBufferProfile<2)
            ui->ButtonBack->setEnabled(false);
        else
            ui->ButtonBack->setEnabled(true);
    }
}
void MainWindow::on_ButtonNext_clicked(){
    if(_currentBufferProfile<_bufferProfiles.size()){
        ui->ButtonGames->setEnabled(false);
        ui->ButtonFriends->setEnabled(false);
        ui->ButtonFavorites->setEnabled(false);
        ui->ButtonSetProfile->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        ui->ButtonGoToMyProfile->setEnabled(false);
        ProfileToUi(_bufferProfiles[++_currentBufferProfile-1]);
        if(_currentBufferProfile==_bufferProfiles.size())
            ui->ButtonNext->setEnabled(false);
        else
            ui->ButtonNext->setEnabled(true);
        if(_currentBufferProfile<2)
            ui->ButtonBack->setEnabled(false);
        else
            ui->ButtonBack->setEnabled(true);
    }
}
void MainWindow::on_ButtonGames_clicked(){
    if(_windowChild!=1){
        ReturnFromForms();
        _windowChild=1;
        ui->FormProgressBar->setMaximum(_games.GetCount());
        _gamesForm = new FormGames(_profile.GetSteamid(),_games,this);
        connect(_gamesForm,&FormGames::s_return_to_profile,this,&MainWindow::ReturnFromGames);
        ui->ScrollAreaForm->setWidget(_gamesForm);
        ui->FormProgressBar->setVisible(true);
        _gamesForm->setVisible(false);
    }
}
void MainWindow::on_ButtonFriends_clicked(){
    if(_windowChild!=2){
        ReturnFromForms();
        _windowChild=2;
        ui->FormProgressBar->setMaximum(_friends.GetCount());
        _friendsForm = new FormFriends(_profile.GetSteamid(),_friends,this);
        connect(_friendsForm,&FormFriends::s_return_to_profile,this,&MainWindow::ReturnFromFriends);
        connect(_friendsForm,&FormFriends::s_go_to_profile,this,&MainWindow::GoToProfile);
        ui->ScrollAreaForm->setWidget(_friendsForm);
        ui->FormProgressBar->setVisible(true);
        _friendsForm->setVisible(false);
    }
}
void MainWindow::on_ButtonFavorites_clicked(){
    if(_windowChild!=3){
        ReturnFromForms();
        _windowChild=3;
        //ui->FormProgressBar->setMaximum(Friends.GetCount());
        _favoritesForm = new FormFavorites(this);
        //connect(favoritesform,&FormFavorites::return_to_profile,this,&MainWindow::returnfromfavorites);
        ui->ScrollAreaForm->setWidget(_favoritesForm);
        //ui->FormProgressBar->setVisible(true);
        //favoritesform->setVisible(false);
    }
}
void MainWindow::on_ButtonStatistics_clicked(){
    if(_windowChild!=4){
        ReturnFromForms();
        _windowChild=4;
        //ui->FormProgressBar->setMaximum(Friends.GetCount());
        _statisticsForm = new FormStatistics(_profile.GetSteamid(),_games);
        //connect(favoritesform,&FormFavorites::return_to_profile,this,&MainWindow::returnfromfavorites);
        ui->ScrollAreaForm->setWidget(_statisticsForm);
        //ui->FormProgressBar->setVisible(true);
        //favoritesform->setVisible(false);
    }
}
void MainWindow::on_ButtonSettings_clicked(){
    if(_windowChild!=5){
        ReturnFromForms();
        _windowChild=5;
        //ui->FormProgressBar->setMaximum(Friends.GetCount());
        _settingsForm = new FormSettings();
        //connect(favoritesform,&FormFavorites::return_to_profile,this,&MainWindow::returnfromfavorites);
        ui->ScrollAreaForm->setWidget(_settingsForm);
        //ui->FormProgressBar->setVisible(true);
        //favoritesform->setVisible(false);
    }
}
void MainWindow::on_ButtonGoToMyProfile_clicked(){
    if(_setting.GetStatus()=="success"){
        GoToProfile(_setting.GetMyProfile(),"url");
    } else {
        QMessageBox::warning(this,tr("Ошибка"),tr("Не удаётся найти профиль!"));
    }
}
void MainWindow::on_ButtonSetProfile_clicked(){
    if(_setting.SetMyProfile(_profile.GetSteamid())){
        ui->ButtonSetProfile->setEnabled(false);
        ui->ButtonGoToMyProfile->setEnabled(false);
    }
}
void MainWindow::on_ButtonExit_clicked(){
    close();
}
#define FunctionsEnd }

