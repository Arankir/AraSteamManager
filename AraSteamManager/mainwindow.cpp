#include "mainwindow.h"
#include "ui_mainwindow.h"

//    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
//qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//QPushButton#pushButton {
//     background-url(Images/image1.png);
// }
// QPushButton#pushButton:pressed {
//     background-url(Images/image2.png);
// }
// QPushButton#pushButton:hover {
//      background-url(Images/image3.png);
// }


#define Init {
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
            qApp->setStyleSheet("QPushButton:hover{"
                                    "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                                "stop: 0 #3d8fa8, "
                                                                "stop: 0.48 #2d7f98, "
                                                                "stop: 0.52 #22748c, "
                                                                "stop: 1.0 #13657b); "
                                    "border: 1px solid #262626; "
                                    "border-radius: 2px; "
                                "} "
                                "QProgressBar { "
                                    "border: 1px solid grey; "
                                    "border-radius: 7px; "
                                    "text-align: center; "
                                "} "
                                "QProgressBar::chunk { "
                                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                                "stop: 0 #3d8fa8, "
                                                                "stop: 0.48 #2d7f98, "
                                                                "stop: 0.52 #22748c, "
                                                                "stop: 1.0 #13657b); "
                                    "border-radius: 6px; "
                                "} "
        //                        "QRadioButton::indicator { "
        //                            "width: 13px; "
        //                            "height: 13px; "
        //                            "border-radius: 1px; "
        //                        "} "
//                                "QRadioButton::indicator::unchecked { "
//                                    "background-color:       black; "
//                                    "border:                 1px solid white; "
//                                "} "
//                                "QRadioButton::indicator::checked { "
//                                    "background-color:       red; "
//                                    "border:                 1px solid white; "
//                                "} "
                                "QRadioButton::hover { "
                                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                            "stop: 0 #3d8fa8, "
                                                            "stop: 0.48 #2d7f98, "
                                                            "stop: 0.52 #22748c, "
                                                            "stop: 1.0 #13657b); "
                                "} "
                                //"QRadioButton::indicator:unchecked:hover { "
                                //    "image: url(:/images/radiobutton_unchecked_hover.png); "
                                //"} "
                                //"QRadioButton::indicator:unchecked:pressed { "
                                //    "image: url(:/images/radiobutton_unchecked_pressed.png); "
                                //"} "
                                //"QRadioButton::indicator:checked:hover { "
                                //    "image: url(:/images/radiobutton_checked_hover.png); "
                                //"} "
                                //"QRadioButton::indicator:checked:pressed { "
                                //    "image: url(:/images/radiobutton_checked_pressed.png); "
                                //"} "
                                "QTabBar::tab { "
                                    "border: 1px solid #262626; "
                                    "border-bottom-color: #6d6e6e; "
                                    "border-top-left-radius: 4px; "
                                    "border-top-right-radius: 4px; "
                                    "min-width: 8ex; "
                                    "padding: 2px; "
                                "} "

                                "QTabBar::tab:hover { "
                                    "background: #434343; "
                                "} "

                                "QTabBar::tab:selected { "
                                    "background: #434343; "
                                    "border-bottom-color: #434343; "
                                "} "

                                "QTabBar::tab:!selected { "
                                    "margin-top: 2px; "
                                "} "

                                "QCheckBox::hover { "
                                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                                        "stop: 0 #3d8fa8, "
                                                                        "stop: 0.48 #2d7f98, "
                                                                        "stop: 0.52 #22748c, "
                                                                        "stop: 1.0 #13657b); "
                                "} "

                                "QComboBox { "
                                    "border: 1px solid #262626; "
                                    "border-radius: 3px; "
                                    "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                                                                        "stop:0 #797979, "
                                                                        "stop:0.48 #696969, "
                                                                        "stop:0.52 #5e5e5e, "
                                                                        "stop:1 #4f4f4f); "
                                    "padding: 1px 23px 1px 3px; "
                                    "min-width: 6em; "
                                    "color: #ffffff; "
                                "} "

                                "QComboBox::hover { "
                                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                                    "stop: 0 #3d8fa8, "
                                                                    "stop: 0.48 #2d7f98, "
                                                                    "stop: 0.52 #22748c, "
                                                                    "stop: 1.0 #13657b); "
                                "} "
                                "QComboBox:item:selected { "
                                    "border: 1px solid #262626; "
                                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                                    "stop: 0 #3d8fa8, "
                                                                    "stop: 0.48 #2d7f98, "
                                                                    "stop: 0.52 #22748c, "
                                                                    "stop: 1.0 #13657b); "
                                "} "

                                "QComboBox:item:checked { "
                                    "font-weight: bold; "
                                "} "

                                "QLineEdit { "
                                    "selection-background-color: #2d7f98; "
                                "} "


//                                "QScrollArea {"
//                                    "background-color: rgba(255, 255, 255, 0); "
//                                "} "
                                );
//            this->setStyleSheet(""
//                                "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
//                                                                    "stop: 0 #23262c, "
//                                                                    "stop: 1.0 #1e2025); "
//                                "");
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

//    int id = QFontDatabase::addApplicationFont("C:/font4.otf");
//    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
//    qApp->setFont(family);
//    QFont font = qApp->font();
//    font.setPointSize(c_fontSize);
//    font.setPixelSize(1);
//    qApp->setFont(font);

    InitComponents();
    if(_setting.GetStatus()==StatusValue::success){
        if(_setting.GetMyProfile()!="none")
            GoToProfile(_setting.GetMyProfile(),QueryType::url);
    }
}
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
    ui->LabelNick->setStyleSheet("color: #1657d9;");
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
    Retranslate();
}
#define InitEnd }

#define System {
void MainWindow::ProgressLoading(int a_progress,int){
    ui->FormProgressBar->setValue(a_progress);
}
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
    ui->ButtonStatistics->setText(tr("Статистика"));
    ui->ButtonFavorites->setText(tr("Избранное"));
    ui->ButtonGoToMyProfile->setText(tr("На мой профиль"));
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
void MainWindow::ReturnFromForm(QWidget *a_form){
    disconnect(a_form);
    delete a_form;
    _windowChildCount--;
    _windowChild=WindowChildType::none;
}
void MainWindow::ResizeScrollArea(){
    if(ui->ScrollAreaForm->height()<400){
        QPropertyAnimation *animate = new QPropertyAnimation(this,"size");
        animate->setDuration(500);
        animate->setStartValue(QSize(this->width(),this->height()));
        animate->setEndValue(QSize(this->width(),this->height()-ui->ScrollAreaForm->height()+400));
        connect(animate,SIGNAL(finished),animate,SLOT(deleteLater));
        animate->start();
    }
}
#define SystemEnd }

#define Functions {
void MainWindow::on_ButtonFindProfile_clicked(){
    QString profileid=ui->LineEditIdProfile->text().remove("https://").remove("steamcommunity.com/").remove('\r');
    if(ui->LineEditIdProfile->text().indexOf("id",0)>-1){
        profileid=profileid.remove("id/").remove("/");
        GoToProfile(profileid,QueryType::vanity);
    } else {
        if(ui->LineEditIdProfile->text().indexOf("profiles",0)>-1)
            profileid=profileid.remove("profiles/").remove("/");
        GoToProfile(profileid,QueryType::url);
        }
    ReturnFromForms();
}
void MainWindow::GoToProfile(QString a_id, QueryType a_type){
    SProfile newProfile(a_id,false,a_type);
    if(newProfile.GetStatus()==StatusValue::success){
        if(_currentBufferProfile!=_bufferProfiles.size())
            while(_bufferProfiles.size()!=_currentBufferProfile)
                _bufferProfiles.takeAt(_currentBufferProfile);
        _bufferProfiles.append(newProfile);
        _currentBufferProfile=_bufferProfiles.size();
        UpdateSwitchingProfileEnabled();
        qDebug()<<"Буфер профилей"<<_currentBufferProfile<<"/"<<_bufferProfiles.size();
        ProfileToUi(newProfile);
        } else {
            QMessageBox::warning(this,tr("Ошибка"),tr("Не удаётся найти профиль!"));
        }
}
void MainWindow::ProfileToUi(SProfile a_profile){
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
    ui->LabelProfileUrl->setText("<a href=\""+a_profile.GetProfileurl()+"\"><span style=\" text-decoration: underline; color:#2d7fc8;\">"+a_profile.GetProfileurl()+"</span></a>");
    ui->Labellvl->setText(tr("Уровень: %1").arg(QString::number(levels.GetLevel())));
    ui->LabelRealName->setText(tr("Настоящее имя: %1").arg(a_profile.GetRealname()));
    ui->LabelTimeCreated->setText(tr("Аккаунт создан: %1").arg(a_profile.GetTimecreated().toString("yyyy.MM.dd")));
    ui->LabelLocCountryCode->setText(tr("Язык: %1").arg(a_profile.GetLoccountrycode()));
    switch (a_profile.GetCommunityvisibilitystate()) {
        case 1:
            ui->LabelProfileVisibility->setText(tr("Скрытый"));
            ui->LabelProfileVisibility->setStyleSheet("color: #6e0e0e");
            break;
        case 3:
            ui->LabelProfileVisibility->setText(tr("Публичный"));
            ui->LabelProfileVisibility->setStyleSheet("color: #0e6e11");
            break;
        case 8:
            ui->LabelProfileVisibility->setText(tr("Для друзей"));
            ui->LabelProfileVisibility->setStyleSheet("color: #6c6e0e");
            break;
        default:
            ui->LabelProfileVisibility->setText(tr("Неизвестно"));
            ui->LabelProfileVisibility->setStyleSheet("color:white");
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
    ui->ButtonSetProfile->setEnabled(_setting.GetMyProfile()!=a_profile.GetSteamid());
    ui->ButtonStatistics->setEnabled(true);
    ui->ButtonGoToMyProfile->setEnabled((_setting.GetMyProfile()!="none")&&(_setting.GetMyProfile()!=a_profile.GetSteamid()));
}
void MainWindow::UpdateSwitchingProfileEnabled(){
    ui->ButtonBack->setEnabled(_currentBufferProfile>=2);
    ui->ButtonNext->setEnabled(_currentBufferProfile!=_bufferProfiles.size());
}
void MainWindow::on_ButtonBack_clicked(){
    if(_currentBufferProfile>1){
        ui->ScrollAreaProfileInfo->setEnabled(false);
        ui->ButtonSetProfile->setEnabled(false);
        ProfileToUi(_bufferProfiles[--_currentBufferProfile-1]);
        UpdateSwitchingProfileEnabled();
    }
}
void MainWindow::on_ButtonNext_clicked(){
    if(_currentBufferProfile<_bufferProfiles.size()){
        ui->ScrollAreaProfileInfo->setEnabled(false);
        ui->ButtonSetProfile->setEnabled(false);
        ProfileToUi(_bufferProfiles[++_currentBufferProfile-1]);
        UpdateSwitchingProfileEnabled();
    }
}
void MainWindow::on_ButtonGames_clicked(){
    if(_windowChild!=WindowChildType::games){
        ReturnFromForms();
        _windowChild=WindowChildType::games;
        ui->FormProgressBar->setMaximum(_games.GetCount());
        _gamesForm = new FormGames(_profile.GetSteamid(),_games,this);
        connect(_gamesForm,&FormGames::s_return_to_profile,this,&MainWindow::ReturnFromForm);
        connect(_gamesForm,&FormGames::s_finish,this,&MainWindow::ShowGames);
        connect(_gamesForm,&FormGames::s_achievementsLoaded,this,&MainWindow::ProgressLoading);
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
        ResizeScrollArea();
        //ui->FormProgressBar->setVisible(true);
        //_favoritesForm->setVisible(false);
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
        //_settingsForm->setVisible(false);
    }
}
void MainWindow::on_ButtonGoToMyProfile_clicked(){
    if(_setting.GetStatus()==StatusValue::success&&_setting.GetMyProfile()!="none"){
        ReturnFromForms();
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
    qApp->closeAllWindows();
}
void MainWindow::on_ButtonUpdate_clicked(){
    _profile.Update(false);
    ProfileToUi(_profile);
}
#define FunctionsEnd }
