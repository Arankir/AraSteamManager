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
        case 2:
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
        default:
            QPalette darkPalette;
            darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
            darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
            darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
            darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(73, 73, 73),Qt::white,Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
            //                        тип               ,???      ,Кнопка            ,Разделители,???      ,???     ,цвет текста на кнопке,???  ,поле сзади     ,???
            qApp->setPalette(darkPalette);
            _theme="white";
    }
    InitComponents();
    if(_setting.GetStatus()==StatusValue::success){
        if(_setting.GetMyProfile()!="none")
            GoToProfile(_setting.GetMyProfile(),QueryType::url);
    }
}

#define Init {
void MainWindow::InitComponents(){
    ui->LabelLogo->setPixmap(QPixmap(":/program/program/logo.png"));
    ui->LabelAvatar->setText("");
    ui->LabelTimeCreated->setText("");
    ui->LabelPersonaState->setText("");
    ui->LabelLocCountryCode->setText("");
    ui->LabelProfileUrl->setText("");
    ui->LabelRealName->setText("");
    ui->Labellvl->setText("");
    ui->LabelBans->setText("");
    ui->ButtonBack->setText("");
    ui->ButtonNext->setText("");
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
    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);
    ui->ButtonFindProfile->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/find.png"));
    ui->ButtonFavorites->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/favorites.png"));
    ui->ButtonStatistics->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/statistic.png"));
    ui->ButtonSettings->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/settings.png"));
    ui->ButtonExit->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/exit.png"));
    ui->ButtonFriends->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/friends.png"));
    ui->ButtonGames->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/games.png"));
    ui->ButtonBack->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/left.png"));
    ui->ButtonNext->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/right.png"));
    //ui->LabelRealName->setTextFormat(Qt::RichText);!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //ui->LabelRealName->setText("<img src=\"images/program/cog4.png\">Hello!");!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
void MainWindow::ProgressLoading(int Aprogress,int){
    ui->FormProgressBar->setValue(Aprogress);
}
#define InitEnd }

#define System {
void MainWindow::ShowGames(){
    ui->FormProgressBar->setVisible(false);
    _gamesForm->setVisible(true);
    _windowChildCount++;
    ResizeScrollArea();
}
void MainWindow::ShowFriends(){
    ui->FormProgressBar->setVisible(false);
    _friendsForm->setVisible(true);
    _windowChildCount++;
    ResizeScrollArea();
}
void MainWindow::ShowStatistic(){
    ui->FormProgressBar->setVisible(false);
    _statisticsForm->setVisible(true);
    _windowChildCount++;
    ResizeScrollArea();
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    //qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter;
    if(event->key() == 16777220)
        on_ButtonFindProfile_clicked();
}
void MainWindow::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        Retranslate();
    }
}
void MainWindow::Retranslate(){
    if(_profile.GetStatus()==StatusValue::success)
        ProfileToUi(_profile);
    ui->ButtonBack->setText(tr("Назад"));
    ui->ButtonNext->setText(tr("Вперед"));
    ui->ButtonSetProfile->setText(tr("Это мой профиль"));
    ui->LineEditIdProfile->setPlaceholderText(tr("Введите Steamid"));
    ui->ButtonExit->setText(tr("Выход"));
    ui->ButtonFindProfile->setText(tr("Найти"));
}
MainWindow::~MainWindow(){
    ReturnFromForms();
    delete ui;
}
void MainWindow::ReturnFromForms(){
    if(_windowChildCount>0)
        switch(_windowChild){
            case WindowChildType::games:
                ReturnFromForm(_gamesForm);
                break;
            case WindowChildType::friends:
                ReturnFromForm(_friendsForm);
                break;
            case WindowChildType::favorites:
                ReturnFromForm(_favoritesForm);
                break;
            case WindowChildType::statistics:
                ReturnFromForm(_statisticsForm);
                break;
            case WindowChildType::settings:
                ReturnFromForm(_settingsForm);
                break;
            default:
                break;
        }
}
void MainWindow::ReturnFromForm(QWidget *Aform){
    disconnect(Aform);
    delete Aform;
    _windowChildCount--;
    _windowChild=WindowChildType::none;
}
void MainWindow::ResizeScrollArea(){
    if(ui->ScrollAreaForm->height()<400){
        QPropertyAnimation *anim = new QPropertyAnimation(this,"size");
        anim->setDuration(500);
        anim->setStartValue(QSize(this->width(),this->height()));
        anim->setEndValue(QSize(this->width(),this->height()-ui->ScrollAreaForm->height()+400));
        connect(anim,SIGNAL(finished),anim,SLOT(deleteLater));
        anim->start();
    }
}
#define SystemEnd }

#define Functions {
void MainWindow::on_ButtonFindProfile_clicked(){
    QString id=ui->LineEditIdProfile->text().remove("https://").remove("steamcommunity.com/").remove('\r');
    if(ui->LineEditIdProfile->text().indexOf("id",0)>-1){
        id=id.remove("id/").remove("/");
        GoToProfile(id,QueryType::vanity);
    } else {
        if(ui->LineEditIdProfile->text().indexOf("profiles",0)>-1)
            id=id.remove("profiles/").remove("/");
        GoToProfile(id,QueryType::url);
        }
    switch(_windowChild){
        case WindowChildType::games:
            ReturnFromForm(_gamesForm);
            break;
        case WindowChildType::friends:
            ReturnFromForm(_friendsForm);
            break;
        default:
            break;
    }
}
void MainWindow::GoToProfile(QString Aid, QueryType Atype){
    SProfile profile(Aid,false,Atype);
    if(profile.GetStatus()==StatusValue::success){
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
void MainWindow::ProfileToUi(SProfile Aprofile){
    _profile=Aprofile;
    _games.Clear();
    _friends.Clear();
    SBans Bans(Aprofile.GetSteamid(),false);
    SLevels Levels(Aprofile.GetSteamid());
    _games.Set(Aprofile.GetSteamid(),true,true,false);
    _friends.Set(Aprofile.GetSteamid(),false);
    //ui->LabelProfileUrl->setTextFormat(Qt::RichText);
    //ui->LabelProfileUrl->setText("<img src=\":/"+theme+"/program/"+theme+"/link.png\" width=\"15\" height=\"15\">"+Profile.GetProfileurl());
    ui->ButtonGames->setText(tr(" Игры (%1)").arg(_games.GetStatus()==StatusValue::success?QString::number(_games.GetCount()):"error"));
    ui->ButtonFriends->setText(tr(" Друзья (%1)").arg(_friends.GetStatus()==StatusValue::success?QString::number(_friends.GetCount()):"error"));
    if(!Aprofile.GetGameextrainfo().isEmpty()){
        ui->LabelPersonaState->setText(tr("В игре %1").arg(Aprofile.GetGameextrainfo()));
        ui->LabelPersonaState->setStyleSheet("color: rgb(137,183,83);");
    } else
        switch (Aprofile.GetPersonastate()) {
            case 0:
                ui->LabelPersonaState->setText(tr("Был в сети %1").arg(Aprofile.GetLastlogoff().toString("yyyy.MM.dd hh:mm:ss")));
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
    ui->LabelProfileUrl->setText(Aprofile.GetProfileurl());
    ui->Labellvl->setText(tr("Уровень: %1").arg(QString::number(Levels.GetLevel())));
    ui->LabelRealName->setText(tr("Настоящее имя: %1").arg(Aprofile.GetRealname()));
    ui->LabelTimeCreated->setText(tr("Аккаунт создан: %1").arg(Aprofile.GetTimecreated().toString("yyyy.MM.dd")));
    ui->LabelLocCountryCode->setText(tr("Язык: %1").arg(Aprofile.GetLoccountrycode()));
    switch (Aprofile.GetCommunityvisibilitystate()) {
        case 1:
            ui->LabelProfileVisibility->setText(tr("Скрытый"));
            ui->LabelProfileVisibility->setStyleSheet("color:red");
            break;
        case 3:
            ui->LabelProfileVisibility->setText(tr("Публичный"));
            ui->LabelProfileVisibility->setStyleSheet("color:green");
            break;
        case 8:
            ui->LabelProfileVisibility->setText(tr("Для друзей"));
            ui->LabelProfileVisibility->setStyleSheet("color:yellow");
            break;
        default:
            ui->LabelProfileVisibility->setText(tr("Неизвестно"));
            ui->LabelProfileVisibility->setStyleSheet("color:white");
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
    QNetworkReply &imagereply = *imagemanager.get(QNetworkRequest(Aprofile.GetAvatarmedium()));
    imageloop.exec();
    disconnect(&imagemanager, &QNetworkAccessManager::finished, &imageloop, &QEventLoop::quit);
    QPixmap img;
    img.loadFromData(imagereply.readAll());
    ui->LabelAvatar->setPixmap(img);
    ui->LabelNick->setText(Aprofile.GetPersonaname());
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

    ui->ButtonGames->setEnabled(_games.GetStatus()==StatusValue::success);
    ui->ButtonFriends->setEnabled(_friends.GetStatus()==StatusValue::success);
    ui->ButtonFavorites->setEnabled(true);
    ui->ButtonSetProfile->setEnabled(_setting.GetMyProfile()!=Aprofile.GetSteamid());
    ui->ButtonStatistics->setEnabled(true);
    ui->ButtonGoToMyProfile->setEnabled((_setting.GetMyProfile()!="none")&&(_setting.GetMyProfile()!=Aprofile.GetSteamid()));

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
    if(_windowChild!=WindowChildType::games){
        ReturnFromForms();
        _windowChild=WindowChildType::games;
        ui->FormProgressBar->setMaximum(_games.GetCount());
        _gamesForm = new FormGames(_profile.GetSteamid(),_games,this);
        connect(_gamesForm,&FormGames::s_return_to_profile,this,&MainWindow::ReturnFromForm);
        ui->ScrollAreaForm->setWidget(_gamesForm);
        ui->FormProgressBar->setVisible(true);
        _gamesForm->setVisible(false);
    }
}
void MainWindow::on_ButtonFriends_clicked(){
    if(_windowChild!=WindowChildType::friends){
        ReturnFromForms();
        _windowChild=WindowChildType::friends;
        ui->FormProgressBar->setMaximum(_friends.GetCount());
        _friendsForm = new FormFriends(_profile.GetSteamid(),_friends,this);
        connect(_friendsForm,&FormFriends::s_return_to_profile,this,&MainWindow::ReturnFromForm);
        connect(_friendsForm,&FormFriends::s_go_to_profile,this,&MainWindow::GoToProfile);
        ui->ScrollAreaForm->setWidget(_friendsForm);
        ui->FormProgressBar->setVisible(true);
        _friendsForm->setVisible(false);
    }
}
void MainWindow::on_ButtonFavorites_clicked(){
    if(_windowChild!=WindowChildType::favorites){
        ReturnFromForms();
        _windowChild=WindowChildType::favorites;
        //ui->FormProgressBar->setMaximum(Friends.GetCount());
        _favoritesForm = new FormFavorites(this);
        connect(_favoritesForm,&FormFavorites::s_return_to_profile,this,&MainWindow::ReturnFromForm);
        ui->ScrollAreaForm->setWidget(_favoritesForm);
        _windowChildCount++;
        //ui->FormProgressBar->setVisible(true);
        //favoritesform->setVisible(false);
    }
}
void MainWindow::on_ButtonStatistics_clicked(){
    if(_windowChild!=WindowChildType::statistics){
        ReturnFromForms();
        _windowChild=WindowChildType::statistics;
        ui->FormProgressBar->setMaximum(_games.GetCount());
        _statisticsForm = new FormStatistics(_profile.GetSteamid(),_games,_profile.GetPersonaname(),this);
        connect(_statisticsForm,&FormStatistics::s_return_to_profile,this,&MainWindow::ReturnFromForm);
        ui->ScrollAreaForm->setWidget(_statisticsForm);
        ui->FormProgressBar->setVisible(true);
        _statisticsForm->setVisible(false);
    }
}
void MainWindow::on_ButtonSettings_clicked(){
    if(_windowChild!=WindowChildType::settings){
        ReturnFromForms();
        _windowChild=WindowChildType::settings;
        //ui->FormProgressBar->setMaximum(Friends.GetCount());
        _settingsForm = new FormSettings(this);
        connect(_settingsForm,&FormSettings::s_return_to_profile,this,&MainWindow::ReturnFromForm);
        ui->ScrollAreaForm->setWidget(_settingsForm);
        _windowChildCount++;
        ResizeScrollArea();
        //ui->FormProgressBar->setVisible(true);
        //favoritesform->setVisible(false);
    }
}
void MainWindow::on_ButtonGoToMyProfile_clicked(){
    if(_setting.GetStatus()==StatusValue::success&&_setting.GetMyProfile()!="none"){
        switch(_windowChild){
            case WindowChildType::games:
                ReturnFromForm(_gamesForm);
                break;
            case WindowChildType::friends:
                ReturnFromForm(_friendsForm);
                break;
            default:
                break;
        }
        GoToProfile(_setting.GetMyProfile(),QueryType::url);
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

