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

////StyleSheet
// QTextEdit[styleVariant="1"] {
// // Custom Style
// }
// QTextEdit{
// // Default Style
// }

//// connect pushbutton clicked(bool checked = false) signal to onPushButtonClicked
// onPushButtonClicked(bool checked)
// {
// if(checked)
// textEdit->setProperty("styleVariant", 1);
// else
// textEdit->setProperty("styleVariant", 0);
// }
#define Init {
MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
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
            _theme="white";
            hoverGradient = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                        "stop: 0 #185077, "
                        "stop: 0.22 #387097, "
                        "stop: 0.88 #286087, "
                        "stop: 1.0 #185077); ";
            backgroundGradient = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                        "stop: 0 #213c57, "
                        "stop: 1.0 #1a2839); ";
            blackGradient = "qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, "
                        "stop: 0 #202020, "
                        "stop: 0.8 #303030, "
                        "stop: 1.0 #505050); ";
            pushButton =
                "QPushButton{ "
                    "color: white; "
                    "background-color: #24547d; "
                    //"min-height: 20px; "
                    //"max-height: 20px; "
                "} "
                "QPushButton:disabled{ "
                    //"color: 323232; "
                    "background-color: #48525a; "
                "} "
                "QPushButton:pressed{ background-color: #212121; } "
                //"QPushButton:focus:pressed{ background-color: #212121; } "
                //"QPushButton:focus{ background-color: #3F3F3F; } "
                "QPushButton:hover{ "
                    "background-color: #22748c; "
                    "background: "+hoverGradient+
                    "border: 1px solid #262626; "
                    "border-radius: 2px; "
                    "} "
                //"QPushButton:checked{ background-color: pink; }"
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
                        "border: 1px solid black; "
                    "}"
                    "QMessageBox{"
                        "background: black; "
                    "}"
                    ;
            labels =
                    "QLabel{"
                        "color: white; "
                    "}"
                    ;
            radioButtons =
                    "QRadioButton{"
                        "color: white; "
                        "background-color: rgba(255, 255, 255, 0); "
                        "border: 0px solid grey; "
                    "}"
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
//                    "QRadioButton::indicator:unchecked:hover { "
//                        "image: url(:/images/radiobutton_unchecked_hover.png); "
//                    "} "
//                    "QRadioButton::indicator:unchecked:pressed { "
//                        "image: url(:/images/radiobutton_unchecked_pressed.png); "
//                    "} "
//                    "QRadioButton::indicator:checked:hover { "
//                        "image: url(:/images/radiobutton_checked_hover.png); "
//                    "} "
//                    "QRadioButton::indicator:checked:pressed { "
//                        "image: url(:/images/radiobutton_checked_pressed.png); "
//                    "} "
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
                    //            QTabWidget::pane {
                    //                border: 1px solid black;
                    //                background: white;
                    //            }
                    //            QTabWidget{
                    //                border: 1px solid black;
                    //                background: white;
                    //            }

                    //            QTabWidget::tab-bar:top {
                    //                top: 1px;
                    //            }

                    //            QTabWidget::tab-bar:bottom {
                    //                bottom: 1px;
                    //            }

                    //            QTabWidget::tab-bar:left {
                    //                right: 1px;
                    //            }

                    //            QTabWidget::tab-bar:right {
                    //                left: 1px;
                    //            }

                    //            QTabBar::tab {
                    //                border: 1px solid black;
                    //            }

                    //            QTabBar::tab:selected {
                    //                background: white;
                    //            }

                    //            QTabBar::tab:!selected {
                    //                background: silver;
                    //            }

                    //            QTabBar::tab:!selected:hover {
                    //                background: #999;
                    //            }

                    //            QTabBar::tab:top:!selected {
                    //                margin-top: 3px;
                    //            }

                    //            QTabBar::tab:bottom:!selected {
                    //                margin-bottom: 3px;
                    //            }

                    //            QTabBar::tab:top, QTabBar::tab:bottom {
                    //                min-width: 8ex;
                    //                margin-right: -1px;
                    //                padding: 5px 10px 5px 10px;
                    //            }

                    //            QTabBar::tab:top:selected {
                    //                border-bottom-color: none;
                    //            }

                    //            QTabBar::tab:bottom:selected {
                    //                border-top-color: none;
                    //            }

                    //            QTabBar::tab:top:last, QTabBar::tab:bottom:last,
                    //            QTabBar::tab:top:only-one, QTabBar::tab:bottom:only-one {
                    //                margin-right: 0;
                    //            }

                    //            QTabBar::tab:left:!selected {
                    //                margin-right: 3px;
                    //            }

                    //            QTabBar::tab:right:!selected {
                    //                margin-left: 3px;
                    //            }

                    //            QTabBar::tab:left, QTabBar::tab:right {
                    //                min-height: 8ex;
                    //                margin-bottom: -1px;
                    //                padding: 10px 5px 10px 5px;
                    //            }

                    //            QTabBar::tab:left:selected {
                    //                border-left-color: none;
                    //            }

                    //            QTabBar::tab:right:selected {
                    //                border-right-color: none;
                    //            }

                    //            QTabBar::tab:left:last, QTabBar::tab:right:last,
                    //            QTabBar::tab:left:only-one, QTabBar::tab:right:only-one {
                    //                margin-bottom: 0;
                    //            }
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
//                    QCheckBox::indicator:unchecked:hover {
//                        image: url(:/images/checkbox_unchecked_hover.png);
//                    }
//                    QCheckBox::indicator:unchecked:pressed {
//                        image: url(:/images/checkbox_unchecked_pressed.png);
//                    }
                    "QCheckBox::indicator:checked { "
                        "image: url(://"+_theme+"/widgets/checkbox_checked.png); "
                    "} "
//                    QCheckBox::indicator:checked:hover {
//                        image: url(:/images/checkbox_checked_hover.png);
//                    }
//                    QCheckBox::indicator:checked:pressed {
//                        image: url(:/images/checkbox_checked_pressed.png);
//                    }
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
                        "font-weight: bold; "
                    "} "
                    ;
            lineEdit =
                    "QLineEdit { "
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
                    "} "
                    "QTableWidget::item { "
                        //"border-bottom: 1px solid #cccccc; "
                        "border: 1px solid #777777; "
                        "background-color: #213c57; "//+backgroundGradient+
                        "color: white; "
                    "} "
//                    "QTableWidget::item:hover { "
//                        //"border: 1px solid #232323; "
//                        //"border-radius: 2px; "
//                        //"background-color: #ffffff; "
//                    "} "
                    "QScrollBar:vertical { "
                        "border: 1px solid #999999; "
                        "background: "+hoverGradient+
                        "width:10px; "
                        //"    margin: 0px 0px 0px 0px;"
                    "}"
                    "QScrollBar:horizontal { "
                        "border: 1px solid #999999; "
                        "background: "+hoverGradient+
                        "height:10px; "
                    "} "
//                    QScrollBar:vertical {
//                    border-color: rgb(227, 227, 227);
//                    border-width: 1px;
//                    border-style: solid;
//                    background-color: rgb(240, 240, 240);
//                    width: 15px;
//                    margin: 21px 0 21px 0;
//                    }
//                    QScrollBar::handle:vertical {
//                    background-color: rgb(200, 200, 200);
//                    min-height: 25px;
//                    }
//                    QScrollBar::add-line:vertical {
//                    border: 1px solid grey;
//                    background-color: rgb(241, 241, 241);
//                    height: 20px;
//                    subcontrol-position: bottom;
//                    subcontrol-origin: margin;
//                    }
//                    QScrollBar::sub-line:vertical {
//                    border: 1px solid grey;
//                    background-color: rgb(241, 241, 241);
//                    height: 20px;
//                    subcontrol-position: top;
//                    subcontrol-origin: margin;
//                    }
//                    QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
//                    background: none;
//                    }
//                    QScrollBar::up-arrow:vertical
//                    {
//                    image: url(:/BarIcon/Icons/uparrow.png);
//                    }
//                    QScrollBar::down-arrow:vertical
//                    {
//                    image: url(:/BarIcon/Icons/downarrow.png);
//                    }
//                    "QScrollBar:horizontal { "
//                    "border-color: rgb(227, 227, 227); "
//                    "border-width: 1px; "
//                    "border-style: solid; "
//                    "background-color: rgb(240, 240, 240); "
//                    "width: 15px; "
//                    "margin: 0px 21px 0 21px; "
//                    "} "
//                    QScrollBar::handle:horizontal {
//                    background-color: rgb(200, 200, 200);
//                    min-height: 25px;
//                    }
//                    QScrollBar::add-line:horizontal {
//                    border: 1px solid grey;
//                    background-color: rgb(241, 241, 241);
//                    width: 20px;
//                    subcontrol-position: right;
//                    subcontrol-origin: margin;
//                    }
//                    QScrollBar::sub-line:horizontal {
//                    border: 1px solid grey;
//                    background-color: rgb(241, 241, 241);
//                    width: 20px;
//                    subcontrol-position: left;
//                    subcontrol-origin: margin;
//                    }
//                    QScrollBar:left-arrow:horizontal
//                    {
//                    image: url(:/BarIcon/Icons/leftarrow.png);
//                    }
//                    QScrollBar::right-arrow:horizontal
//                    {
//                    image: url(:/BarIcon/Icons/rightarrow.png);
//                    }
//                    QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {
//                    background: none;
//                    }
                    ;
            headerView =
                    "QHeaderView::section { "
                        "background-color: #505050; "
                        "color: white; "
                        "padding-left: 4px; "
                        "border: 1px solid #6c6c6c; "
                    "} "
//                    "QHeaderView::section:checked { "
//                        //"background-color: red; "
//                    "} "
                    "QHeaderView { "
                        "selection-background-color: #303030; "
                        "background-color: #303030; "
                        "selection-color: #303030; "
                        //"color: red; "
                    "} "
//                    "QHeaderView::down-arrow { "
//                        "image: url(down_arrow.png); "
//                    "} "
//                    "QHeaderView::up-arrow { "
//                        "image: url(up_arrow.png); "
//                    "} "
                    ;
            groupBox =
                    "QGroupBox::title{ "
                        "color: white; "
                    "}"
                    ;
            listWidget =
                    "QListWidget { "
                        "border: 0px solid #cccccc; "
                        "border-radius: 8px; "
                        "background-color: "+backgroundGradient+
                    "} "
                    "QListWidget::item { "
                        "border-bottom: 1px solid #cccccc; "
                        "background-color: #213c57; "//+backgroundGradient+
                        "color: white; "
                    "} "
                    ;
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
    qApp->setStyleSheet(pushButton+progressBar+forms+subContainers+labels+radioButtons+tabBar+checkBox+comboBox+lineEdit+tableWidget+headerView+groupBox+listWidget);

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
    _containerAchievementsForm = new FormContainerAchievements();
    ui->LabelLogo->setPixmap(QPixmap("://logo.png"));
    ui->FormProgressBar->setVisible(false);
    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);
    ui->StackedWidgetForms->setCurrentIndex(0);
    ui->ButtonUpdate->setIcon(QIcon("://"+_theme+"/update.png"));
    ui->ButtonGoToMyProfile->setIcon(QIcon("://"+_theme+"/home.png"));
    ui->ButtonFindProfile->setIcon(QIcon("://"+_theme+"/find_profile.png"));
    ui->ButtonSettings->setIcon(QIcon("://"+_theme+"/settings.png"));
    ui->ButtonExit->setIcon(QIcon("://"+_theme+"/exit.png"));
    ui->ButtonBack->setIcon(QIcon("://"+_theme+"/left.png"));
    ui->ButtonNext->setIcon(QIcon("://"+_theme+"/right.png"));
    Retranslate();
}
#define InitEnd }

#define System {
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
    _containerAchievementsForm->AddFormAchievement(achievements,_profile.GetSteamid(),games,_achievementsCount++);
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
    ui->StackedWidgetForms->setCurrentIndex(1);
    ResizeScrollArea();
}
void MainWindow::ShowFriends(){
    _initFriends=true;
    ui->FormProgressBar->setVisible(false);
    _blockedLoad=false;
    ui->StackedWidgetForms->setCurrentIndex(2);
    ResizeScrollArea();
}
void MainWindow::ShowStatistic(){
    _initStatistics=true;
    ui->FormProgressBar->setVisible(false);
    _blockedLoad=false;
    ui->StackedWidgetForms->setCurrentIndex(3);
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
    ui->ButtonBack->setText(tr(""));
    ui->ButtonNext->setText(tr(""));
    ui->LineEditIdProfile->setPlaceholderText(tr("Введите Steamid"));
    ui->ButtonExit->setText(tr("Выход"));
    ui->ButtonFindProfile->setText(tr("Найти"));
    ui->ButtonGoToMyProfile->setText(tr(""));
}
MainWindow::~MainWindow(){
    ReturnFromForms();
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
        ReturnFromForms();
        if(ui->StackedWidgetProfiles->currentIndex()!=ui->StackedWidgetProfiles->count()-1)
            while(ui->StackedWidgetProfiles->count()-1!=ui->StackedWidgetProfiles->currentIndex())
                ui->StackedWidgetProfiles->removeWidget(ui->StackedWidgetProfiles->widget(ui->StackedWidgetProfiles->currentIndex()+1));
        FormProfile *newStackedProfile = new FormProfile(newProfile);
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
        //connect(this,&MainWindow::on_ButtonSetProfile_clicked,newStackedProfile,&FormProfile::SetProfile);
        //void UpdateTheme();
        //void UpdateVisibleInfo();
        qDebug()<<_setting.GetVisibleProfileInfo();
        ui->StackedWidgetProfiles->setFixedHeight(_setting.GetVisibleProfileInfo()?155:95);
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
void MainWindow::on_ButtonBack_clicked(){
    if(ui->StackedWidgetProfiles->currentIndex()>0){
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex()-1);
        UpdateMyProfile();
        ReturnFromForms();
        UpdateButtonsBackNext();
    }
}
void MainWindow::on_ButtonNext_clicked(){
    if(ui->StackedWidgetProfiles->currentIndex()<ui->StackedWidgetProfiles->count()){
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex()+1);
        UpdateMyProfile();
        ReturnFromForms();
        UpdateButtonsBackNext();
    }
}
void MainWindow::GoToGames(QString a_prifileSteamid, SGames a_games){
    if(!_initGames){
        if(!_blockedLoad){
            _blockedLoad=true;
            ui->FormProgressBar->setMaximum(a_games.GetCount());
            _gamesForm = new FormGames(a_prifileSteamid,a_games,this);
            connect(_gamesForm,&FormGames::s_finish,this,&MainWindow::ShowGames);
            connect(_gamesForm,&FormGames::s_achievementsLoaded,this,&MainWindow::ProgressLoading);
            connect(_gamesForm,&FormGames::s_showAchievements,this,&MainWindow::AddAchievements);
            ui->ScrollAreaGames->setWidget(_gamesForm);
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(0);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(1);
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
            ui->StackedWidgetForms->setCurrentIndex(0);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(2);
    }
}
void MainWindow::GoToFavorites(){
    if(!_initFavorites){
        if(!_blockedLoad){
            _favoritesForm = new FormFavorites(this);
            ui->ScrollAreaFavorites->setWidget(_favoritesForm);
            //
            _initFavorites=true;
            ui->StackedWidgetForms->setCurrentIndex(4);
            ResizeScrollArea();
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(4);
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
            ui->StackedWidgetForms->setCurrentIndex(0);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(3);
    }
}

void MainWindow::UpdateMyProfile(){
    _setting.LoadSettings();
    ui->ButtonGoToMyProfile->setEnabled(static_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget())->GetProfile().GetSteamid()!=_setting.GetMyProfile());
    emit s_updateSettings();
}
void MainWindow::UpdateSettings(){
    _setting.LoadSettings();
    ui->StackedWidgetProfiles->setFixedHeight(_setting.GetVisibleProfileInfo()?155:95);
    emit s_updateSettings();
}
void MainWindow::on_ButtonSettings_clicked(){
    if(!_initSettings){
        if(!_blockedLoad){
            _settingsForm = new FormSettings(this);
            connect(_settingsForm,&FormSettings::s_updateSettings,this,&MainWindow::UpdateSettings);
            ui->ScrollAreaSettings->setWidget(_settingsForm);
            //
            _initSettings=true;
            ui->StackedWidgetForms->setCurrentIndex(5);
            ResizeScrollArea();
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(5);
    }
}
void MainWindow::on_ButtonGoToMyProfile_clicked(){
    if(_setting.GetStatus()==StatusValue::success&&_setting.GetMyProfile()!="none"){
        GoToProfile(_setting.GetMyProfile(),QueryType::url);
    } else {
        QMessageBox::warning(this,tr("Ошибка"),tr("Не удаётся найти профиль!"));
    }
}
void MainWindow::on_ButtonExit_clicked(){
    qApp->closeAllWindows();
}
void MainWindow::on_ButtonUpdate_clicked(){
    static_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget())->UpdateInfo();
}
#define FunctionsEnd }
