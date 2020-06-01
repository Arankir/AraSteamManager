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
    InitComponents();
    if(_setting.GetMyProfile()!="none")
        GoToProfile(_setting.GetMyProfile(),QueryType::url);
}
void MainWindow::InitComponents(){
    _containerAchievementsForm = new FormContainerAchievements();
    _setting.CustomGeometry(QGuiApplication::primaryScreen()->geometry());
        int id = QFontDatabase::addApplicationFont(_setting.c_defaultFont);
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont font(family, 10);
        //font.setPointSize(12);
        //font.setPixelSize(12);
        qApp->setFont(font);
    ui->line->setVisible(false);
    ui->ButtonMinimize->setFlat(true);
    ui->ButtonMaximize->setFlat(true);
    ui->ButtonExit->setFlat(true);
    ui->FormProgressBar->setVisible(false);
    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);
    ui->StackedWidgetForms->setCurrentIndex(0);

    ui->ButtonMinimize->setFixedSize(QSize(23,23));
    ui->ButtonMaximize->setFixedSize(QSize(23,23));
    ui->ButtonExit->setFixedSize(QSize(23,23));
    this->setGeometry(_setting.GetMainWindowGeometry());
    this->move(_setting.GetMainWindowPos().x(),_setting.GetMainWindowPos().y());
    if(_setting.GetMainWindowMaximize())
        this->showMaximized();
    qApp->setStyleSheet(GetTheme());
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
}
#define InitEnd }

#define System {
QString MainWindow::GetTheme(){
    QString hoverGradient;
    QString backgroundGradient;
    QString backgroundGradientTitle;
    QString buttonGradient;
    QString buttonHoverGradient;
    QString progressbarGradient;
    QString blackGradient;
    QString tableWidgetRowGradient;
    QString tableWidgetAlterRowGradient;
    QString qss;
    switch(_setting.GetTheme()){
    case 1:{
#define gradients {
        buttonGradient = "qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0, "
                    "stop: 0 #136186, "
                    "stop: 0.5 #145c81, "
                    "stop: 1.0 #136186); ";
        buttonHoverGradient = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                    "stop: 0 #377097, "
                    "stop: 0.22 #377097, "
                    "stop: 0.88 #286087, "
                    "stop: 1.0 #286087); ";
        progressbarGradient = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                    "stop: 0 #136186, "
                    "stop: 0.25 #237196, "
                    "stop: 0.5 #3381A6, "
                    "stop: 0.75 #237196, "
                    "stop: 1.0 #136186); ";
        hoverGradient = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                    "stop: 0 #185077, "
                    "stop: 0.22 #387097, "
                    "stop: 0.88 #286087, "
                    "stop: 1.0 #185077); ";
        backgroundGradient = "qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, "
                    "stop: 0 #13273a, "
                    "stop: 0.12 #12324b, "
                    "stop: 0.5 #14384f, "
                    "stop: 0.83 #12324b, "
                    "stop: 1.0 #13273a); ";
        backgroundGradientTitle = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                    "stop: 0 #10131b, "
                    "stop: 0.5 #20232b, "
                    "stop: 1.0 #10131b); ";
        blackGradient = "qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, "
                    "stop: 0 #102b45, "
                    "stop: 0.8 #17314c, "
                    "stop: 1.0 #193048); ";
        tableWidgetRowGradient = "qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, "
                    "stop: 0 #102b45, "
                    "stop: 0.8 #17314c, "
                    "stop: 1.0 #193048); ";
        tableWidgetAlterRowGradient = "qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, "
                    "stop: 0 #203b55, "
                    "stop: 0.8 #27415c, "
                    "stop: 1.0 #294058); ";
#define gradientsend }
        qss =
#define button {
                "QPushButton{ "
                    "color: white; "
                    "background: "+buttonGradient+
                    "border: 1px outset #262626; "
                    "min-width: 25px; "
                    "min-height: 20px; "
                    "border-radius: 4px; "
                "} "
                "QPushButton:disabled{ "
                    "background-color: #48525a; "
                "} "
                "QPushButton:pressed{ "
                    "background-color: #212121; "
                "} "
                "QPushButton:hover{ "
                    "background-color: #dfe7ed; "
                    "background: "+buttonHoverGradient+
                    "border: 2px outset #262626; "
                    "border-radius: 4px; "
                "} "
                "QPushButton:flat { "
                    "background-color: none; "
                    //"border: none; "/* no border for a flat push button */
                "} "
#define buttonend }
#define progressbar {
                "QProgressBar { "
                    "color: white; "
                    "background-color: rgba(26,26,26,255); "
                    "border: 1px solid grey; "
                    "border-radius: 7px; "
                    "text-align: center; "
                "} "
                "QProgressBar::chunk { "
                    "background-color: "+progressbarGradient+
                    "border-radius: 6px; "
                "} "
#define progressbarend }
#define radiobutton {
                "QRadioButton{"
                    "color: white; "
                    "background-color: rgba(255, 255, 255, 0); "
                    "border: 0px solid grey; "
                "} "
                "QRadioButton::indicator { "
                    "width: 15; "
                "} "
                "QRadioButton::indicator::unchecked { "
                    "image: url(://"+_iconColor+"/widgets/radiobutton_unchecked.png); "
                "} "
                "QRadioButton::indicator::checked { "
                    "image: url(://"+_iconColor+"/widgets/radiobutton_checked.png); "
                "} "
                "QRadioButton::hover { "
                    "color: "+hoverGradient+
                "} "
#define radiobuttonend }
#define tabbar {
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
                "QTabBar::tab:selected { " /* expand/overlap to the left and right by 4px */
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
#define tabbarend }
#define checkbox {
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
                "QCheckBox::indicator:unchecked { "
                    "image: url(://"+_iconColor+"/widgets/checkbox_uncheked.png); "
                "} "
                "QCheckBox::indicator:checked { "
                    "image: url(://"+_iconColor+"/widgets/checkbox_checked.png); "
                "} "
#define checkboxend }
#define combobox {
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
#define comboboxend }
#define lineedit {
                "QLineEdit { "
                    "border: 1px solid #262626; "
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
                "QLineEdit:hover { "
                    "border: 1px solid #537ca6; "
                    "border-radius: 2px; "
                    "selection-background-color: #387097; "
                    "background-color: "+blackGradient+
                    "color: white; "
                "} "
#define lineeditend }
#define tablewidget {
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
#define tablewidgetend }
#define scrollbar {
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
#define scrollbarend }
#define headerview {
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
#define headerviewend }
                "QTableView{ "
                    "background-color: "+tableWidgetRowGradient+
                    "alternate-background-color: "+tableWidgetAlterRowGradient+
                "} "
                "QWidget[objectName=MainWindow],QWidget[objectName=FormContainerAchievements]{ "
                    "background-color: "+backgroundGradient+
                "} "
                "QTabWidget > QStackedWidget > QWidget, QTabWidget > QStackedWidget, QTabWidget, QWidget[objectName=FormStatistics] { "
                    "background-color: "+backgroundGradient+
                "} "
                "QFrame[accessibleName=TitleWindow]{ "
                    "background-color: "+backgroundGradientTitle+
                    "border: 0px solid white; "
                "} "
                "QScrollArea > QWidget, QScrollArea > QWidget > QWidget{ "
                    "background-color: rgba(255, 255, 255, 0); "
                "} "
                "QScrollArea { "
                    "border: 0px solid white; "
                    "background-color: rgba(255, 255, 255, 0); "
                "} "
                "QMessageBox{ "
                    "background: black; "
                "} "
                "QLabel{"
                    "color: white; "
                "} "
                "QGroupBox::title{ "
                    "color: white; "
                "} "
#define listwidget {
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
#define listwidgetend }
                ;
        _iconColor="white";
        break;
    }
    case 2:{
        _iconColor="black";
        break;
    }
    default:{
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
        _iconColor="white";
        break;
    }
    }
    SetIcons();
    return qss;
}
void MainWindow::SetIcons(){
    ui->LabelLogo->setPixmap(QPixmap("://logo.png"));
    ui->ButtonUpdate->setIcon(QIcon("://"+_iconColor+"/update.png"));
    ui->ButtonGoToMyProfile->setIcon(QIcon("://"+_iconColor+"/home.png"));
    ui->ButtonFindProfile->setIcon(QIcon("://"+_iconColor+"/find_profile.png"));
    ui->ButtonSettings->setIcon(QIcon("://"+_iconColor+"/settings.png"));
    ui->ButtonExit->setIcon(QIcon("://"+_iconColor+"/close_window.png"));
    ui->ButtonMinimize->setIcon(QIcon("://"+_iconColor+"/minimize_window.png"));
    if(this->isMaximized())
        ui->ButtonMaximize->setIcon(QIcon("://"+_iconColor+"/restore_window.png"));
    else
        ui->ButtonMaximize->setIcon(QIcon("://"+_iconColor+"/maximize_window.png"));
    ui->ButtonBack->setIcon(QIcon("://"+_iconColor+"/left.png"));
    ui->ButtonNext->setIcon(QIcon("://"+_iconColor+"/right.png"));
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

void MainWindow::ShowForm(bool &a_initForm, int a_widgetIndex, int a_widthWindow){
    a_initForm=true;
    ui->FormProgressBar->setVisible(false);
    _blockedLoad=false;
    ui->StackedWidgetForms->setCurrentIndex(a_widgetIndex);
    ResizeScrollArea(a_widthWindow);
}
void MainWindow::ShowGames(int a_width){
    ShowForm(_initGames, c_formsGames, a_width);
}
void MainWindow::ShowFriends(){
    ShowForm(_initFriends, c_formsFriends);
}
void MainWindow::ShowStatistic(){
    ShowForm(_initStatistics, c_formsStatistic);
}
void MainWindow::ReturnFromForms(){
    if(_initGames){
        disconnect(_gamesForm);
        delete _gamesForm;
        _initGames=false;
    }
    if(_initFriends){
        disconnect(_friendsForm);
        delete _friendsForm;
        _initFriends=false;
    }
    if(_initStatistics){
        disconnect(_statisticsForm);
        delete _statisticsForm;
        _initStatistics=false;
    }
    if(_initFavorites){
        disconnect(_favoritesForm);
        delete _favoritesForm;
        _initFavorites=false;
    }
    if(_initSettings){
        disconnect(_settingsForm);
        delete _settingsForm;
        _initSettings=false;
    }
    ui->StackedWidgetForms->setCurrentIndex(0);
}
void MainWindow::keyPressEvent(QKeyEvent *a_event){
    //qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter;
    if(a_event->key() == 16777220)
        ButtonFindProfile_Clicked();
}
void MainWindow::changeEvent(QEvent *a_event){
    if(a_event->type()==QEvent::LanguageChange){
        ui->retranslateUi(this);
    }
}
void MainWindow::closeEvent(QCloseEvent *a_event){
    _setting.SetMainWindowMaximize(this->isMaximized());
    if(this->isMaximized()){
        this->showNormal();
    }
    _setting.SetMainWindowParams(this->frameGeometry());
    _setting.SyncronizeSettings();
    a_event->accept();
}
void MainWindow::mousePressEvent(QMouseEvent *a_event){
//    if(a_event->button() == Qt::LeftButton){
//        QPoint winPt  = this->pos();
//        QPoint mousePt = a_event->globalPos();
//        _mousePos = mousePt - winPt;
//        //Если схватил сверху, разрешить перемещать окно
//        _moveWindow=std::move(_mousePos.y()<24);
//    } else {
//        _moveWindow=std::move(false);
//    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *a_event){
//    if(_moveWindow){//Перемещать окно
//        this->move(a_event->globalPos() - _mousePos);
//    }
}

MainWindow::~MainWindow(){
    ReturnFromForms();
    delete _containerAchievementsForm;
    delete ui;
}
void MainWindow::ResizeScrollArea(int a_width){
    if((ui->StackedWidgetForms->height()<400)||(ui->StackedWidgetForms->width()<a_width)){
        QPropertyAnimation *animate = new QPropertyAnimation(this,"size");
        animate->setDuration(500);
        animate->setStartValue(QSize(this->width(),this->height()));
        //qDebug()<<this->width()+a_width-ui->StackedWidgetForms->width()<<this->width()<<a_width<<ui->StackedWidgetForms->width();
        animate->setEndValue(QSize(this->width()+a_width-ui->StackedWidgetForms->width(),this->height()-ui->StackedWidgetForms->height()+400));
        connect(animate,SIGNAL(finished),animate,SLOT(deleteLater));
        animate->start();
    }
}
void MainWindow::ButtonMaximize_Clicked(){
    if(!this->isMaximized()){
        this->showMaximized();
        ui->ButtonMaximize->setIcon(QIcon("://"+_iconColor+"/restore_window.png"));
    } else {
        this->showNormal();
        ui->ButtonMaximize->setIcon(QIcon("://"+_iconColor+"/maximize_window.png"));
    }
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
    if(newProfile.getStatus()==StatusValue::success){
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
            qDebug()<<newProfile.getError();
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
            ui->FormProgressBar->setMaximum(a_games.getCount());
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
            ui->FormProgressBar->setMaximum(a_friends.getCount());
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
            ui->FormProgressBar->setMaximum(a_games.getCount());
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
    qApp->setStyleSheet(GetTheme());
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
