#include "mainwindow.h"
#include "ui_mainwindow.h"

//    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
//qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//https://ru.stackoverflow.com/questions/952577/qt-network-ssl-qsslsocketconnecttohostencrypted-tls-initialization-failed

#define Constants {
constexpr int c_formsNone=0;
constexpr int c_formsGames=1;
constexpr int c_formsFriends=2;
constexpr int c_formsStatistic=3;
constexpr int c_formsFavorites=4;
constexpr int c_formsSettings=5;
#define ConstantsEnd }

#define Init {
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), _games(this){
    ui->setupUi(this);
    switch(_setting.GetTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
        default:
            _theme="white";
    }
    qApp->setStyleSheet(GetTheme());

//    int id = QFontDatabase::addApplicationFont("C:/font4.otf");
//    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
//    qApp->setFont(family);
//    QFont font = qApp->font();
//    font.setPointSize(c_fontSize);
//    font.setPixelSize(1);
//    qApp->setFont(font);
    InitComponents();
    if(_setting.GetMyProfile()!="none")
        GoToProfile(_setting.GetMyProfile(),QueryType::url);
}
void MainWindow::InitComponents(){
    _containerAchievementsForm = new FormContainerAchievements();
    _setting.CustomGeometry(QGuiApplication::primaryScreen()->geometry());
//    this->setWindowFlags(Qt::Window
//                         | Qt::WindowTitleHint
//                         | Qt::CustomizeWindowHint);
    ui->ButtonMinimize->setVisible(false);
    ui->ButtonMaximize->setVisible(false);
    ui->line->setVisible(false);
    ui->FormProgressBar->setVisible(false);
    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);
    ui->StackedWidgetForms->setCurrentIndex(0);

    this->setGeometry(_setting.GetMainWindowGeometry());
    //if((_setting.GetMainWindowPos().x()>QGuiApplication::primaryScreen()->geometry().width())||(_setting.GetMainWindowPos().y()>QGuiApplication::primaryScreen()->geometry().height()))
    //    ;//this->move(_setting.GetMainWindowPercentPos().x(),_setting.GetMainWindowPercentPos().y()-31);
    //else
    this->move(_setting.GetMainWindowPos().x(),_setting.GetMainWindowPos().y()-31);
#define Connects {
    connect(ui->ButtonFindProfile,&QPushButton::clicked,this,&MainWindow::ButtonFindProfile_Clicked);
    connect(ui->ButtonExit,&QPushButton::clicked,this,&MainWindow::ButtonExit_Clicked);
    connect(ui->ButtonGoToMyProfile,&QPushButton::clicked,this,&MainWindow::ButtonGoToMyProfile_Clicked);
    connect(ui->ButtonBack,&QPushButton::clicked,this,&MainWindow::ButtonBack_Clicked);
    connect(ui->ButtonNext,&QPushButton::clicked,this,&MainWindow::ButtonNext_Clicked);
    connect(ui->ButtonSettings,&QPushButton::clicked,this,&MainWindow::ButtonSettings_Clicked);
    connect(ui->ButtonUpdate,&QPushButton::clicked,this,&MainWindow::ButtonUpdate_Clicked);
    connect(ui->ButtonMaximize,&QPushButton::clicked,this,&MainWindow::ButtonMaximize_Clicked);
    connect(ui->ButtonMinimize,&QPushButton::clicked,this,&MainWindow::ButtonMinimize_Clicked);
#define ConnectsEnd }
#define Icons {
    ui->LabelLogo->setPixmap(QPixmap("://logo.png"));
    ui->ButtonUpdate->setIcon(QIcon("://"+_theme+"/update.png"));
    ui->ButtonGoToMyProfile->setIcon(QIcon("://"+_theme+"/home.png"));
    ui->ButtonFindProfile->setIcon(QIcon("://"+_theme+"/find_profile.png"));
    ui->ButtonSettings->setIcon(QIcon("://"+_theme+"/settings.png"));
    ui->ButtonExit->setIcon(QIcon("://"+_theme+"/exit.png"));
    ui->ButtonBack->setIcon(QIcon("://"+_theme+"/left.png"));
    ui->ButtonNext->setIcon(QIcon("://"+_theme+"/right.png"));
#define IconsEnd }
//    FormTablesHeaders *th = new FormTablesHeaders(2,3,4,5,false,true,false,true);
//    ui->ScrollAreaNone->setWidget(th);
}
#define InitEnd }

#define System {
QString MainWindow::GetTheme(){
    QString hoverGradient;
    QString backgroundGradient;
    QString blackGradient;
    QString pushButton;
    QString progressBar;
    QString forms;
    QString subContainers;
    QString labels;
    QString radioButtons;
    QString tabBar;
    QString checkBox;
    QString comboBox;
    QString lineEdit;
    QString tableWidget;
    QString headerView;
    QString groupBox;
    QString listWidget;
    switch(_setting.GetTheme()){
        case 1:{
            hoverGradient = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                        "stop: 0 #185077, "
                        "stop: 0.22 #387097, "
                        "stop: 0.88 #286087, "
                        "stop: 1.0 #185077); ";
            backgroundGradient = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                        "stop: 0 #213c57, "
                        "stop: 1.0 #1a2839); ";
            blackGradient = "qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, "
                        "stop: 0 #102b45, "
                        "stop: 0.8 #17314c, "
                        "stop: 1.0 #193048); ";
            pushButton =
                    "QPushButton{ "
                        "color: white; "
                        "background-color: #24547d; "
                    "} "
                    "QPushButton:disabled{ "
                        "background-color: #48525a; "
                    "} "
                    "QPushButton:pressed{ "
                        "background-color: #212121; "
                    "} "
                    "QPushButton:hover{ "
                        "background-color: #22748c; "
                        "background: "+hoverGradient+
                        "border: 1px solid #262626; "
                        "border-radius: 2px; "
                    "} "
                    ;
            progressBar =
                    "QProgressBar { "
                        "color: white; "
                        "background-color: rgba(26,26,26,255); "
                        "border: 1px solid grey; "
                        "border-radius: 7px; "
                        "text-align: center; "
                    "} "
                    "QProgressBar::chunk { "
                        "background-color: "+hoverGradient+
                        "border-radius: 6px; "
                    "} "
                    ;
            forms =
                    "QWidget[objectName=MainWindow],QWidget[objectName=FormContainerAchievements]{ "
                        "background-color: "+backgroundGradient+
                    "} "
                    ;
            subContainers =
                    "QScrollArea, QScrollArea > QWidget, QScrollArea > QWidget > QWidget, QWidget[isScrollArea=\"true\"]{ "
                        "background-color: rgba(255, 255, 255, 0); "
                    "} "
                    "QScrollArea { "
                        "border: 0px solid white; "
                    "} "
                    "QMessageBox{"
                        "background: black; "
                    "} "
                    ;
            labels =
                    "QLabel{"
                        "color: white; "
                    "} "
                    ;
            radioButtons =
                    "QRadioButton{"
                        "color: white; "
                        "background-color: rgba(255, 255, 255, 0); "
                        "border: 0px solid grey; "
                    "} "
                    "QRadioButton::indicator { "
                        "width: 15; "
                    "} "
                    "QRadioButton::indicator::unchecked { "
                        "image: url(://"+_theme+"/widgets/radiobutton_unchecked.png); "
                    "} "
                    "QRadioButton::indicator::checked { "
                        "image: url(://"+_theme+"/widgets/radiobutton_checked.png); "
                    "} "
                    "QRadioButton::hover { "
                        "color: "+hoverGradient+
                    "} "
                    ;
            tabBar =
                    "QTabWidget > QStackedWidget > QWidget, QTabWidget > QStackedWidget, QTabWidget, QWidget[objectName=FormStatistics] { "
                        "background-color: "+backgroundGradient+
                    "} "
                    "QTabBar::tab { "
                        "color: white; "
                        "background-color: #333333; "
                        "border: 1px solid black; "
                        "border-bottom-color: black; "
                        "border-top-left-radius: 4px; "
                        "border-top-right-radius: 4px; "
                        "min-width: 8ex; "
                        "padding: 2px; "
                    "} "
                    "QTabBar::tab:hover { "
                        "background: #434343; "
                    "} "
                    "QTabBar::tab:selected { "
                        "background: #213c57; "
                        "border-bottom-color: #213c57; "
                    "} "
                    "QTabBar::tab:!selected { "
                        "margin-top: 2px; "
                    "} "
                    "QTabBar::tab:selected { "
                        /* expand/overlap to the left and right by 4px */
                        "margin-left: -4px; "
                        "margin-right: -4px; "
                    "} "

                    "QTabBar::tab:first:selected { "
                        "margin-left: 0; "/* the first selected tab has nothing to overlap with on the left */
                    "} "

                    "QTabBar::tab:last:selected { "
                        "margin-right: 0; "/* the last selected tab has nothing to overlap with on the right */
                    "} "

                    "QTabBar::tab:only-one { "
                        "margin: 0; "/* if there is only one tab, we don't want overlapping margins */
                    "} "
                    ;
            checkBox =
                    "QCheckBox{ "
                        "background-color: rgba(255,255,255,0); "
                        "color: white; "
                    "} "
                    "QCheckBox::hover { "
                        "color: "+hoverGradient+
                    "} "
                    "QCheckBox::indicator { "
                        "width: 15; "
                    "} "
                    "QCheckBox::indicator::checked { "
                    "} "
                    "QCheckBox::indicator:unchecked { "
                        "image: url(://"+_theme+"/widgets/checkbox_uncheked.png); "
                    "} "
                    "QCheckBox::indicator:checked { "
                        "image: url(://"+_theme+"/widgets/checkbox_checked.png); "
                    "} "
                    ;
            comboBox =
                    "QComboBox { "
                        "border: 1px solid #232323; "
                        "border-radius: 3px; "
                        "background: "+hoverGradient+
                        "padding: 1px 23px 1px 3px; "
                        "min-width: 6em; "
                        "color: #ffffff; "
                    "} "
                    "QComboBox:item { "
                        "background-color: #387097; "
                    "} "
                    "QComboBox::hover { "
                        "background-color: "+hoverGradient+
                    "} "
                    "QComboBox:item:selected { "
                        "border: 1px solid #262626; "
                        "color: "+hoverGradient+
                    "} "
                    "QComboBox:item:checked { "
                        //"font-weight: bold; "
                    "} "
                    ;
            lineEdit =
                    "QLineEdit { "
                        "border: 1px solid #537ca6; "
                        "border-radius: 2px; "
                        "selection-background-color: #387097; "
                        "background-color: "+blackGradient+
                        "color: white; "
                    "} "
                    "QLineEdit:disabled { "
                        "selection-background-color: #387097; "
                        "background-color: #A0A0A0; "
                        "color: white; "
                    "} "
                    ;
            tableWidget =
                    "QTableWidget { "
                        "border: 1px solid #777777; "
                        "border-radius: 2px; "
                        "background-color: "+backgroundGradient+
                        "color: white; "
                    "} "
                    "QTableWidget::item { "
                        "border: 1px solid #777777; "
                        "border-top-color: transparent; "
                        "border-bottom-color: transparent; "
                        "background-color: #213c57; "
                    "} "
                    "QScrollBar:vertical { "
                        "border: 1px solid #999999; "
                        "background: "+hoverGradient+
                        "width:10px; "
                    "}"
                    "QScrollBar:horizontal { "
                        "border: 1px solid #999999; "
                        "background: "+hoverGradient+
                        "height:10px; "
                    "} "
                    ;
            headerView =
                    "QHeaderView::section { "
                        "background-color: #505050; "
                        "color: white; "
                        "padding-left: 4px; "
                        "border: 1px solid #6c6c6c; "
                    "} "
                    "QHeaderView { "
                        "selection-background-color: #303030; "
                        "background-color: #303030; "
                        "selection-color: #303030; "
                    "} "
                    ;
            groupBox =
                    "QGroupBox::title{ "
                        "color: white; "
                    "} "
                    ;
            listWidget =
                    "QListWidget { "
                        "border: 0px solid #cccccc; "
                        "border-radius: 8px; "
                        "background-color: "+backgroundGradient+
                    "} "
                    "QListWidget::item { "
                        "border-bottom: 1px solid #cccccc; "
                        "background-color: #213c57; "
                        "color: white; "
                    "} "
                    ;
            break;
            }
        case 2:
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
    return pushButton+progressBar+forms+subContainers+labels+radioButtons+tabBar+checkBox+comboBox+lineEdit+tableWidget+headerView+groupBox+listWidget;
}
void MainWindow::ProgressLoading(int a_progress,int){
    ui->FormProgressBar->setValue(a_progress);
}
void MainWindow::AddAchievements(SAchievementsPlayer achievements, SGame games){
    if(_achievementsCount==0){
        _containerAchievementsForm = new FormContainerAchievements();
        connect(_containerAchievementsForm,&FormContainerAchievements::s_removeAchievements,this,&MainWindow::RemoveAchievements);
        connect(_containerAchievementsForm,&FormContainerAchievements::s_formClose,this,&MainWindow::ContainerAchievementsClose);
        _windowChildCount++;
    }
    qDebug()<<static_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget())->GetProfile()._steamID;
    _containerAchievementsForm->AddFormAchievement(achievements,static_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget())->GetProfile()._steamID,games,_achievementsCount++);
    _containerAchievementsForm->show();
}
void MainWindow::RemoveAchievements(int index){
    _achievementsCount--;
}
void MainWindow::ContainerAchievementsClose(){
    _achievementsCount=0;
    disconnect(_containerAchievementsForm,&FormContainerAchievements::s_removeAchievements,this,&MainWindow::RemoveAchievements);
    disconnect(_containerAchievementsForm,&FormContainerAchievements::s_formClose,this,&MainWindow::ContainerAchievementsClose);
}
void MainWindow::ReturnFromAchievements(int a_num){
    disconnect(_achievementsForms[a_num],&FormAchievements::s_return_to_games,this,&MainWindow::ReturnFromAchievements);
    //delete achievementsforms[num];
}

void MainWindow::ShowGames(){
    _initGames=true;
    ui->FormProgressBar->setVisible(false);
    _blockedLoad=false;
    ui->StackedWidgetForms->setCurrentIndex(c_formsGames);
    ResizeScrollArea();
}
void MainWindow::ShowFriends(){
    _initFriends=true;
    ui->FormProgressBar->setVisible(false);
    _blockedLoad=false;
    ui->StackedWidgetForms->setCurrentIndex(c_formsFriends);
    ResizeScrollArea();
}
void MainWindow::ShowStatistic(){
    _initStatistics=true;
    ui->FormProgressBar->setVisible(false);
    _blockedLoad=false;
    ui->StackedWidgetForms->setCurrentIndex(c_formsStatistic);
    ResizeScrollArea();
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    //qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter;
    if(event->key() == 16777220)
        ButtonFindProfile_Clicked();
}
void MainWindow::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        ui->retranslateUi(this);
    }
}

void MainWindow::closeEvent(QCloseEvent *event){
    _setting.SetMainWindowParams(this->geometry());
    _setting.SyncronizeSettings();
    event->accept();
}
void MainWindow::moveEvent(QMoveEvent *){
//    _setting.SetMainWindowPos(event->pos());
}
void MainWindow::resizeEvent(QResizeEvent *){
    //    _setting.SetMainWindowParams(this->geometry(),this->pos(),QGuiApplication::primaryScreen()->geometry());
}

MainWindow::~MainWindow(){
    ReturnFromForms();
    if(_achievementsCount>0)
        delete _containerAchievementsForm;
    delete ui;
}
void MainWindow::ReturnFromForms(){
    if(_initGames){
        delete _gamesForm;
        _initGames=false;
    }
    if(_initFriends){
//        delete _friendsForm;
        _initFriends=false;
    }
    if(_initStatistics){
        delete _statisticsForm;
        _initStatistics=false;
    }
    if(_initFavorites){
        delete _favoritesForm;
        _initFavorites=false;
    }
    if(_initSettings){
        delete _settingsForm;
        _initSettings=false;
    }
    ui->StackedWidgetForms->setCurrentIndex(0);
}
void MainWindow::ResizeScrollArea(){
    if(ui->StackedWidgetForms->height()<400){
        QPropertyAnimation *animate = new QPropertyAnimation(this,"size");
        animate->setDuration(500);
        animate->setStartValue(QSize(this->width(),this->height()));
        animate->setEndValue(QSize(this->width(),this->height()-ui->StackedWidgetForms->height()+400));
        connect(animate,SIGNAL(finished),animate,SLOT(deleteLater));
        animate->start();
    }
}
void MainWindow::ButtonMaximize_Clicked(){
    if(!this->isMaximized())
        this->showMaximized();
    else
        this->showNormal();
}
void MainWindow::ButtonMinimize_Clicked(){
    if(!this->isMinimized())
        this->showMinimized();
    else
        this->showNormal();
}
#define SystemEnd }

#define Functions {
void MainWindow::ButtonFindProfile_Clicked(){
    QString profileid=ui->LineEditIdProfile->text().remove("https://").remove("steamcommunity.com").remove('\r');
    if(ui->LineEditIdProfile->text().indexOf("/id/",0)>-1){
        profileid=profileid.remove("/id/").remove("/");
        GoToProfile(profileid,QueryType::vanity);
    } else {
        if(ui->LineEditIdProfile->text().indexOf("/profiles/",0)>-1)
            profileid=profileid.remove("/profiles/").remove("/");
        GoToProfile(profileid,QueryType::url);
        }
    ReturnFromForms();
}
void MainWindow::GoToProfile(QString a_id, QueryType a_type){
    SProfiles newProfile(a_id,false,a_type);
    if(newProfile.GetStatus()==StatusValue::success){
        ReturnFromForms();
        if(ui->StackedWidgetProfiles->currentIndex()!=ui->StackedWidgetProfiles->count()-1)
            while(ui->StackedWidgetProfiles->count()-1!=ui->StackedWidgetProfiles->currentIndex())
                ui->StackedWidgetProfiles->removeWidget(ui->StackedWidgetProfiles->widget(ui->StackedWidgetProfiles->currentIndex()+1));
        FormProfile *newStackedProfile = new FormProfile(newProfile[0]);
        newStackedProfile->setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum));
        ui->StackedWidgetProfiles->addWidget(newStackedProfile);
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->count()-1);
        connect(newStackedProfile,&FormProfile::s_goToGames,this,&MainWindow::GoToGames);
        connect(newStackedProfile,&FormProfile::s_goToFriends,this,&MainWindow::GoToFriends);
        connect(newStackedProfile,&FormProfile::s_goToStatistic,this,&MainWindow::GoToStatistics);
        connect(newStackedProfile,&FormProfile::s_goToFavorites,this,&MainWindow::GoToFavorites);
        connect(newStackedProfile,&FormProfile::s_myProfileChange,this,&MainWindow::UpdateMyProfile);
        connect(this,&MainWindow::s_updateSettings,newStackedProfile,&FormProfile::UpdateVisibleInfo);
        connect(this,&MainWindow::s_updateSettings,newStackedProfile,&FormProfile::UpdateTheme);
        UpdateSettings();
        UpdateMyProfile();
        UpdateButtonsBackNext();
        qDebug()<<"Буфер профилей"<<ui->StackedWidgetProfiles->currentIndex()+1<<"/"<<ui->StackedWidgetProfiles->count();
        } else {
            QMessageBox::warning(this,tr("Ошибка"),tr("Не удаётся найти профиль!"));
            qDebug()<<newProfile.GetError();
        }
}
void MainWindow::UpdateButtonsBackNext(){
    ui->ButtonBack->setEnabled(ui->StackedWidgetProfiles->currentIndex()>0);
    ui->ButtonNext->setEnabled(ui->StackedWidgetProfiles->currentIndex()!=ui->StackedWidgetProfiles->count()-1);
}
void MainWindow::ButtonBack_Clicked(){
    if(ui->StackedWidgetProfiles->currentIndex()>0){
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex()-1);
        UpdateMyProfile();
        ReturnFromForms();
        UpdateButtonsBackNext();
    }
}
void MainWindow::ButtonNext_Clicked(){
    if(ui->StackedWidgetProfiles->currentIndex()<ui->StackedWidgetProfiles->count()){
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex()+1);
        UpdateMyProfile();
        ReturnFromForms();
        UpdateButtonsBackNext();
    }
}
void MainWindow::GoToGames(QString a_profileSteamid, SGames a_games){
    if(!_initGames){
        if(!_blockedLoad){
            _blockedLoad=true;
            ui->FormProgressBar->setMaximum(a_games.GetCount());
            _gamesForm = new FormGames(a_profileSteamid,a_games,this);
            connect(_gamesForm,&FormGames::s_finish,this,&MainWindow::ShowGames);
            connect(_gamesForm,&FormGames::s_achievementsLoaded,this,&MainWindow::ProgressLoading);
            connect(_gamesForm,&FormGames::s_showAchievements,this,&MainWindow::AddAchievements);
            ui->ScrollAreaGames->setWidget(_gamesForm);
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(c_formsNone);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsGames);
    }
}
void MainWindow::GoToFriends(QString a_prifileSteamid, SFriends a_friends){
    if(!_initFriends){
        if(!_blockedLoad){
            _blockedLoad=true;
            ui->FormProgressBar->setMaximum(a_friends.GetCount());
            _friendsForm = new FormFriends(a_prifileSteamid,a_friends,this);
            connect(_friendsForm,&FormFriends::s_go_to_profile,this,&MainWindow::GoToProfile);
            ui->ScrollAreaFriends->setWidget(_friendsForm);
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(c_formsNone);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsFriends);
    }
}
void MainWindow::GoToFavorites(){
    if(!_initFavorites){
        if(!_blockedLoad){
            _favoritesForm = new FormFavorites(this);
            ui->ScrollAreaFavorites->setWidget(_favoritesForm);
            //
            _initFavorites=true;
            ui->StackedWidgetForms->setCurrentIndex(c_formsFavorites);
            ResizeScrollArea();
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsFavorites);
    }
}
void MainWindow::GoToStatistics(QString a_prifileSteamid, SGames a_games, QString a_profileName){
    if(!_initStatistics){
        if(!_blockedLoad){
            _blockedLoad=true;
            ui->FormProgressBar->setMaximum(a_games.GetCount());
            _statisticsForm = new FormStatistics(a_prifileSteamid,a_games,a_profileName,this);
            ui->ScrollAreaStatistic->setWidget(_statisticsForm);
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(c_formsNone);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsStatistic);
    }
}

void MainWindow::UpdateMyProfile(){
    _setting.SyncronizeSettings();
    ui->ButtonGoToMyProfile->setEnabled(static_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget())->GetProfile()._steamID!=_setting.GetMyProfile());
    emit s_updateSettings();
}
void MainWindow::UpdateSettings(){
    _setting.SyncronizeSettings();
    switch (_setting.GetProfileInfoSize()) {
    case 0:{
        ui->StackedWidgetProfiles->setFixedHeight(35);
        break;
    }
    case 1:{
        ui->StackedWidgetProfiles->setFixedHeight(95);
        break;
    }
    case 2:{
        ui->StackedWidgetProfiles->setFixedHeight(155);
    }
    }
    emit s_updateSettings();
}
void MainWindow::ButtonSettings_Clicked(){
    if(!_initSettings){
        if(!_blockedLoad){
            _settingsForm = new FormSettings(this);
            connect(_settingsForm,&FormSettings::s_updateSettings,this,&MainWindow::UpdateSettings);
            ui->ScrollAreaSettings->setWidget(_settingsForm);
            //
            _initSettings=true;
            ui->StackedWidgetForms->setCurrentIndex(c_formsSettings);
            ResizeScrollArea();
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsSettings);
    }
}
void MainWindow::ButtonGoToMyProfile_Clicked(){
    if(_setting.GetMyProfile()!="none"){
        GoToProfile(_setting.GetMyProfile(),QueryType::url);
    } else {
        QMessageBox::warning(this,tr("Ошибка"),tr("Не удаётся найти профиль!"));
    }
}
void MainWindow::ButtonExit_Clicked(){
    qApp->closeAllWindows();
}
void MainWindow::ButtonUpdate_Clicked(){
    static_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget())->UpdateInfo();

}
#define FunctionsEnd }
