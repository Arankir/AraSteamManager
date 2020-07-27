#include "mainwindow.h"
#include "ui_mainwindow.h"

//    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
//qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//https://ru.stackoverflow.com/questions/952577/qt-network-ssl-qsslsocketconnecttohostencrypted-tls-initialization-failed

#define Constants {
constexpr int c_formsNone = 0;
constexpr int c_formsGames = 1;
constexpr int c_formsFriends = 2;
constexpr int c_formsStatistic = 3;
constexpr int c_formsFavorites = 4;
constexpr int c_formsSettings = 5;
#define ConstantsEnd }

#define Init {
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), _games(this) {
    ui->setupUi(this);
    initComponents();
    if (_setting.getMyProfile() != "none") {
        goToProfile(_setting.getMyProfile(), ProfileUrlType::id);
    }
}

void MainWindow::initComponents() {
    _containerAchievementsForm = new FormContainerAchievements();
    _setting.customGeometry(QGuiApplication::primaryScreen()->geometry());
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

    ui->ButtonMinimize->setFixedSize(QSize(23, 23));
    ui->ButtonMaximize->setFixedSize(QSize(23, 23));
    ui->ButtonExit->setFixedSize(QSize(23, 23));
    this->setGeometry(_setting.getMainWindowGeometry());
    this->move(_setting.getMainWindowPos().x(), _setting.getMainWindowPos().y());
    if(_setting.getMainWindowMaximize()) {
        this->showMaximized();
    }
    qApp->setStyleSheet(getTheme());
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setColor(QColor(93, 170, 224, 255 * 0.7));
    shadowEffect->setOffset(0);
    shadowEffect->setBlurRadius(50);
    ui->FormProgressBar->setGraphicsEffect(shadowEffect);
//    ui->FormProgressBar->setVisible(true);
//    ui->FormProgressBar->setValue(20);
//    ui->FormProgressBar->setMaximum(100);
    ui->FormProgressBar->
#define Connects {
    connect(ui->ButtonFindProfile,   &QPushButton::clicked, this, &MainWindow::buttonFindProfile_Clicked);
    connect(ui->ButtonExit,          &QPushButton::clicked, this, &MainWindow::buttonExit_Clicked);
    connect(ui->ButtonGoToMyProfile, &QPushButton::clicked, this, &MainWindow::buttonGoToMyProfile_Clicked);
    connect(ui->ButtonBack,          &QPushButton::clicked, this, &MainWindow::buttonBack_Clicked);
    connect(ui->ButtonNext,          &QPushButton::clicked, this, &MainWindow::buttonNext_Clicked);
    connect(ui->ButtonSettings,      &QPushButton::clicked, this, &MainWindow::buttonSettings_Clicked);
    connect(ui->ButtonUpdate,        &QPushButton::clicked, this, &MainWindow::buttonUpdate_Clicked);
    connect(ui->ButtonMaximize,      &QPushButton::clicked, this, &MainWindow::buttonMaximize_Clicked);
    connect(ui->ButtonMinimize,      &QPushButton::clicked, this, &MainWindow::buttonMinimize_Clicked);
#define ConnectsEnd }
}
#define InitEnd }

#define System {
QString MainWindow::getTheme() {
    QString hoverGradient;
    QString backgroundGradient;
    QString backgroundGradientTitle;
    QString buttonHoverGradient;
    QString tableWidgetRowGradient;
    QString tableWidgetAlterRowGradient;
    QString qss;
    switch(_setting.getTheme()) {
    case 1:{
#define gradients {
//        QpushButton{
//                  qproperty-icon:url(:/images/start.png);
//        }

//        QPushButton:hover
//        {
//                  qproperty-icon:url(:/images/start_hov.png);
//        }

        hoverGradient = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                    "stop: 0 #185077, "
                    "stop: 0.22 #387097, "
                    "stop: 0.88 #286087, "
                    "stop: 1.0 #185077); ";
        backgroundGradient = "qradialgradient("
                    "cx:0.5, cy:0.5, "
                    "radius: 0.8, "
                    "fx:0.4, fy:0.5, "
                    "stop:0 #12457c, "
                    //"stop:0.5 #12324b, "
                    "stop:1 #19253d); "
        /*"qradialgradient("
                    "cx:0.5, cy:0.5, "
                    "radius: 0.4, "
                    "fx:0.4, fy:0.5, "
                    "stop:0 #14384f, "
                    "stop:0.5 #12324b, "
                    "stop:1 #13273a); "*/
/*        "qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, "
                    "stop: 0 #DDDDFF, "
//                    "stop: 0.12 #12324b, "
//                    "stop: 0.5 #14384f, "
//                    "stop: 0.83 #12324b, "
                    "stop: 1.0 #0000FF); "*/;
        backgroundGradientTitle = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                    "stop: 0 #10131b, "
                    "stop: 0.5 #20232b, "
                    "stop: 1.0 #10131b); ";
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
                "QPushButton[text] { "
//                    "color: white; "
//                    "background: "+buttonGradient+
//                    "border: 1px solid #262626; "
//                    //"min-width: 25px; "
//                    "min-height: 20px; "
//                    "border-radius: 2px; "
                    "padding: 0em 0em 0em 0.3em; "
                "} "
                "QPushButton { "
                    "color: white; "
                    "background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, "
                        "stop: 0 #1c2686, "
                        "stop: 1.0 #46a8b7); "
                    "border: 1px solid #262626; "
                    //"min-width: 25px; "
                    "min-height: 20px; "
                    "border-radius: 2px; "
                "} "
                "QPushButton:hover { "
                    "background-color: #dfe7ed; "
                    "background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, "
                        "stop: 0 #326ba0, "
                        //"stop: 0.5 #268897, "
                        "stop: 1.0 #268897); "
                    //"border: 2px solid #262626; "
                    //"border-radius: 2px; "
                "} "
                "QPushButton:pressed { "
                    //"background-color: #3698a7; "
                    "margin: 1px; "
                "} "
                "QPushButton:flat { "
                    "background-color: none; "
                    //"border: none; "
                "} "
                "QPushButton:disabled { "
                    "background-color: #48525a; "
                "} "
#define buttonend }
#define progressbar {
                "QProgressBar { "
                    "color: white; "
                    "background-color: #5daae0; "
                    //"border: 1px solid black; "
                    //"border-radius: 7px; "
                    "text-align: center; "
                "} "
                "QProgressBar::chunk { "
                    "background-color: #386584; "
                    "margin: 5px; "/*qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                        "stop: 0 #1c2686, "
                        "stop: 0.5 #0681bb, "
                        "stop: 1.0 #1c2686); "*/
                    //"border-radius: 6px; "
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
                    "image: url(" + _setting.getIconRadioButtonUnchecked() + "); "
                "} "
                "QRadioButton::indicator::checked { "
                    "image: url(" + _setting.getIconRadioButtonChecked() + "); "
                "} "
                "QRadioButton::indicator::unchecked:hover { "
                    "image: url(" + _setting.getIconRadioButtonUncheckedHover() + "); "
                "} "
                "QRadioButton::indicator::checked:hover { "
                    "image: url(" + _setting.getIconRadioButtonCheckedHover() + "); "
                "} "
                "QRadioButton::indicator::unchecked:pressed { "
                    "image: url(" + _setting.getIconRadioButtonUncheckedPress() + "); "
                "} "
                "QRadioButton::indicator::checked:pressed { "
                    "image: url(" + _setting.getIconRadioButtonCheckedPress() + "); "
                "} "
                "QRadioButton::hover { "
                    "color: #57CBDE"//+hoverGradient+
                "} "
#define radiobuttonend }
#define checkbox {
                "QCheckBox{ "
                    "background-color: rgba(255,255,255,0); "
                    "color: white; "
                "} "
                "QCheckBox::hover { "
                    "color: #57CBDE"
                "} "
                "QCheckBox::indicator { "
                    "width: 15; "
                "} "
                "QCheckBox::indicator:unchecked { "
                    "image: url(" + _setting.getIconCheckBoxUnchecked() + "); "
                "} "
                "QCheckBox::indicator:checked { "
                    "image: url(" + _setting.getIconCheckBoxChecked() + "); "
                "} "
                "QCheckBox::indicator:unchecked:hover { "
                    "image: url(" + _setting.getIconCheckBoxUncheckedHover() + "); "
                "} "
                "QCheckBox::indicator:checked:hover { "
                    "image: url(" + _setting.getIconCheckBoxCheckedHover() + "); "
                "} "
                "QCheckBox::indicator:unchecked:pressed { "
                    "image: url(" + _setting.getIconCheckBoxUncheckedPress() + "); "
                "} "
                "QCheckBox::indicator:checked:pressed { "
                    "image: url(" + _setting.getIconCheckBoxCheckedPress() + "); "
                "} "
#define checkboxend }
#define tabbar {
                "QTabWidget::pane { "
                    "border: 1px solid black; "
                "} "
                "QTabBar::close-button { "
                   "subcontrol-position: right; "
                   "image: url(" + _setting.getIconCloseWindow() + "); "
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
                    "background: #09152d; "
                    "border-bottom-color: #13273a; "
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
#define combobox {
                "QComboBox { "
                    "border: 1px solid #232323; "
                    "border-radius: 3px; "
                    "background: " + hoverGradient +
                    "padding: 1px 23px 1px 3px; "
                    "min-width: 6em; "
                    "color: #dddddd; "
                "} "
                "QComboBox:item { "
                    "background-color: #387097; "
                "} "
                "QComboBox::hover { "
                    "background-color: " + hoverGradient +
                "} "
                "QComboBox:item:selected { "
                    "border: 1px solid #262626; "
                    "color: " + hoverGradient +
                "} "
                "QComboBox:item:checked { "
                    //"font-weight: bold; "
                "} "
#define comboboxend }
#define lineedit {
                "QLineEdit { "
                    "border: 1px solid qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, "
                        "stop: 0 #262626, "
                        "stop: 0.7 #262626, "
                        "stop: 0.99 rgba(255,255,255,0)); "
                    "border-right: 0px rgba(0,0,0,0); "
                    "border-radius: 0px; "
                    "selection-background-color: #387097; "
                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, "
                        "stop: 0 #13243e, "
                        "stop: 0.7 #13243e, "
                        "stop: 0.99 rgba(255,255,255,0)); "
                    "color: #dddddd; "
                "} "
                "QLineEdit:disabled { "
                    //"selection-background-color: #387097; "
                    "background-color: #A0A0A0; "
                    //"color: white; "
                "} "
                "QLineEdit:hover { "
                    "border: 1px solid qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, "
                        "stop: 0 #537ca6, "
                        "stop: 0.7 #537ca6, "
                        "stop: 0.99 rgba(255,255,255,0)); "
                    "border-right: 0px rgba(0,0,0,0); "
                    "border-radius: 0px; "
                    //"selection-background-color: #387097; "
                    //"background-color: " + lineEditGradient +
                    //"color: #638cb6; "
                "} "
#define lineeditend }
#define tablewidget {
#define tableview {
                "QTableView { "
                    "background-color: rgba(0, 0, 0, 0); "
                    "selection-background-color: rgba(0, 0, 0, 0); "
                    "border-radius: 2px; "
                "} "
                "QTableView#TableWidgetContent::indicator { "
                    "width: 40px; "
                    "height: 40px; "
                "} "
                "QTableView::indicator:unchecked { "
                    "image: url(" + _setting.getIconCheckBoxUnchecked() + "); "
                "} "
                "QTableView::indicator:checked { "
                    "image: url(" + _setting.getIconCheckBoxChecked() + "); "
                "} "
                "QTableView::indicator:unchecked:hover { "
                    "image: url(" + _setting.getIconCheckBoxUncheckedHover() + "); "
                "} "
                "QTableView::indicator:checked:hover { "
                    "image: url(" + _setting.getIconCheckBoxCheckedHover() + "); "
                "} "
                "QTableView::indicator:unchecked:pressed { "
                    "image: url(" + _setting.getIconCheckBoxUncheckedPress() + "); "
                "} "
                "QTableView::indicator:checked:pressed { "
                    "image: url(" + _setting.getIconCheckBoxCheckedPress() + "); "
                "} "
#define tableviewEnd }
                "QTableWidget { "
                    "border: 1px solid #777777; "
                    "border-radius: 2px; "
                    "color: #dddddd; "
                "} "
                "QTableWidget::item, QTableWidget::item:inactive { "
                    "border-bottom: 1px solid #87b6ff; "
                    "border-top: 1px solid #87b6ff; "
                    "background-color: rgba(23, 26, 33, 0.5); "
                    "border-left: 0px; "
                    "border-right: 0px; "
                    "margin-bottom: 10px; "
                    "padding: 4px; "
                "} "
                "QTableWidget::item:alternate { "
                    "background-color: #1d2027; "
                "} "
                "QTableWidget::item:hover:!selected { "
                    "background-color: qlineargradient(x1: -2, y1: -2, x2: 1, y2: 1, "
                        "stop: 0 #2692ff, "
                        "stop: 1.0 #171a21); "
                "} "
                "QTableWidget::item:alternate:hover:!selected { "
                    "background-color: qlineargradient(x1: -2, y1: -2, x2: 1, y2: 1, "
                        "stop: 0 #2692ff, "
                        "stop: 1.0 #1d2027); "
                "} "
                "QTableWidget::item:selected { "
                    "background-color: qlineargradient(x1: 0, y1: -2, x2: 0, y2: 1, "
                        "stop: 0 #2692ff, "
                        "stop: 1.0 #153257); "
                    "border: 1px solid #87b6ff; "
                    "border-right: 0px solid #87b6ff; "
                    "border-left: 0px solid #87b6ff; "
                    //"font: bold; "
                "} "
#define headerview {
                "QHeaderView::section, QTableView QTableCornerButton::section { "
                    "background-color: #13243e; "/*qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                        "stop: 0 #0061c3, "
                        "stop: 1.0 #002041); "*/
                    "color: #dddddd; "
                    //"padding-left: 4px; "
                    "border: 1px solid #6c6c6c; "
                    "border-bottom: 0px solid #6c6c6c; "
                    "border-top: 0px solid #6c6c6c; "
                    "border-left: 0px solid #6c6c6c; "
                "} "
                "QHeaderView::section:vertical { "
                    "margin-bottom: 10px; "
                "} "
                "QHeaderView { "
                    "selection-background-color: #303030; "
                    "background-color: #303030; "
                    "selection-color: #303030;"
                    "min-height: 30px; "
                "} "
#define headerviewend }
#define tablewidgetend }
#define scrollbar {
                "QScrollBar:vertical { "
                    "border: 1px solid #999999; "
                    "background: " + hoverGradient +
                    "width:10px; "
                "}"
                "QScrollBar:horizontal { "
                    "border: 1px solid #999999; "
                    "background: " + hoverGradient +
                    "height:10px; "
                "} "
#define scrollbarend }
                "QWidget#MainWindow, QWidget#FormContainerAchievements { "
                    "background-color: " + backgroundGradient +
                    "border: 1px solid #000000; "
                "} "
                "QTabWidget > QStackedWidget > QWidget, QTabWidget > QStackedWidget, QTabWidget, QWidget#FormStatistics { "
                    "background-color: " + backgroundGradient +
                    "border: 0px solid black; "
                "} "
                "QFrame { "
                    "border: 0px solid #000000; "
                "} "
                "QFrame[accessibleName=TitleWindow] { "
                    "background-color: " + backgroundGradientTitle +
                    "border: 1px solid #000000; "
                "} "
                "QScrollArea, QScrollArea > QWidget, QScrollArea > QWidget > QWidget { "
                    "background-color: rgba(0, 0, 0, 0); "
                    "border: 0px solid black; "
                "} "
                "QMessageBox { "
                    "background: black; "
                "} "
                "QLabel, QLabel:disabled {"
                    "color: white; "
                "} "
                "QGroupBox::title { "
                    "color: white; "
                "} "
#define listwidget {
                "QListWidget { "
                    "border: 0px solid #cccccc; "
                    "border-radius: 8px; "
                    "background-color: " + backgroundGradient +
                "} "
                "QListWidget::item { "
                    "border-bottom: 1px solid #cccccc; "
                    "background-color: #213c57; "
                    "color: white; "
                "} "
#define listwidgetend }
                ;
        break;
    }
    case 2:{
        break;
    }
    default: {
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
    setIcons();
    return qss;
}

void MainWindow::setIcons() {
    ui->LabelLogo->setPixmap(QPixmap(_setting.getIconLogoColor()));
    ui->ButtonUpdate->setIcon(QIcon(_setting.getIconUpdate()));
    ui->ButtonGoToMyProfile->setIcon(QIcon(_setting.getIconHome()));
    ui->ButtonFindProfile->setIcon(QIcon(_setting.getIconFindProfile()));
    ui->ButtonSettings->setIcon(QIcon(_setting.getIconSettings()));
    ui->ButtonExit->setIcon(QIcon(_setting.getIconCloseWindow()));
    ui->ButtonMinimize->setIcon(QIcon(_setting.getIconMinimizeWindow()));
    if(this->isMaximized()) {
        ui->ButtonMaximize->setIcon(QIcon(_setting.getIconNormalizeWindow()));
    } else {
        ui->ButtonMaximize->setIcon(QIcon(_setting.getIconMaximizeWindow()));
    }
    ui->ButtonBack->setIcon(QIcon(_setting.getIconLeft()));
    ui->ButtonNext->setIcon(QIcon(_setting.getIconRight()));
}

void MainWindow::progressLoading(int aProgress, int) {
    ui->FormProgressBar->setValue(aProgress);
}

#define ContainerAchievementsStart {
void MainWindow::addAchievements(SAchievementsPlayer aAchievements, SGame aGames) {
    if (_achievementsCount == 0) {
        _containerAchievementsForm = new FormContainerAchievements();
        connect(_containerAchievementsForm ,&FormContainerAchievements::s_removeAchievements, this, &MainWindow::removeAchievements);
        connect(_containerAchievementsForm, &FormContainerAchievements::s_formClose, this, &MainWindow::containerAchievementsClose);
        _windowChildCount++;
    }
    FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
    if (currentProfile) {
        _containerAchievementsForm->AddFormAchievement(aAchievements, currentProfile->getProfile(), aGames, _achievementsCount++);
        _containerAchievementsForm->show();
    }
}

void MainWindow::removeAchievements(int index) {
    _achievementsCount--;
}

void MainWindow::containerAchievementsClose() {
    _achievementsCount = 0;
    disconnect(_containerAchievementsForm, &FormContainerAchievements::s_removeAchievements, this, &MainWindow::removeAchievements);
    disconnect(_containerAchievementsForm, &FormContainerAchievements::s_formClose,          this, &MainWindow::containerAchievementsClose);
}

void MainWindow::returnFromAchievements(int aNum) {
    disconnect(_achievementsForms[aNum], &FormAchievements::s_returnToGames, this, &MainWindow::returnFromAchievements);
    //delete achievementsforms[num];
}
#define ContainerAchievementsEnd }

#define FormsStart {

#define FormsCreateStart {
FormProfile *MainWindow::createFormProfile(SProfile aProfile) {
    FormProfile *newFormProfile = new FormProfile(aProfile);
    newFormProfile->setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum));
    connect(newFormProfile, &FormProfile::s_goToGames,       this,           &MainWindow::goToGames);
    connect(newFormProfile, &FormProfile::s_goToFriends,     this,           &MainWindow::goToFriends);
    connect(newFormProfile, &FormProfile::s_goToStatistic,   this,           &MainWindow::goToStatistics);
    connect(newFormProfile, &FormProfile::s_goToFavorites,   this,           &MainWindow::goToFavorites);
    connect(newFormProfile, &FormProfile::s_myProfileChange, this,           &MainWindow::updateSettings);
    connect(this,           &MainWindow::s_updateSettings,   newFormProfile, &FormProfile::updateSettings);
    return newFormProfile;
}

FormGames *MainWindow::createFormGames(SProfile aProfile, SGames aGames) {
    _gamesForm = new FormGames(aProfile, aGames, this);
    connect(_gamesForm, &FormGames::s_finish,             this,       [=](int aWidth) {
        showForm(c_formsGames, aWidth);
    });
    connect(_gamesForm, &FormGames::s_achievementsLoaded, this,       &MainWindow::progressLoading);
    connect(_gamesForm, &FormGames::s_showAchievements,   this,       &MainWindow::addAchievements);
    connect(this,       &MainWindow::s_updateSettings,    _gamesForm, &FormGames::updateSettings);
    _gamesForm->setWhatsThis("FormGames");
    return _gamesForm;
}

FormFriends *MainWindow::createFormFriends(QString aId, SFriends aFriends) {
    _friendsForm = new FormFriends(aId, aFriends, this);
    connect(_friendsForm, &FormFriends::s_friendsLoaded, this,         &MainWindow::progressLoading);
    connect(_friendsForm, &FormFriends::s_finish,        this,         [=]() {
        showForm(c_formsFriends);
    });
    connect(_friendsForm, &FormFriends::s_go_to_profile, this,         &MainWindow::goToProfile);
    connect(this,         &MainWindow::s_updateSettings, _friendsForm, &FormFriends::updateSettings);
    _friendsForm->setWhatsThis("FormFriends");
    return _friendsForm;
}

FormFavorites *MainWindow::createFormFavorites() {
    _favoritesForm = new FormFavorites(this);
    connect(this, &MainWindow::s_updateSettings, _favoritesForm, &FormFavorites::updateSettings);
    _favoritesForm->setWhatsThis("FormFavorites");
    return _favoritesForm;
}

FormStatistics *MainWindow::createFormStatistics(QString aId, SGames aGames, QString aName) {
    _statisticsForm = new FormStatistics(aId, aGames, aName, this);
    connect(_statisticsForm, &FormStatistics::s_statisticsLoaded, this,            &MainWindow::progressLoading);
    connect(_statisticsForm, &FormStatistics::s_finish,           this,            [=]() {
        showForm(c_formsStatistic);
    });
    connect(this,            &MainWindow::s_updateSettings,       _statisticsForm, &FormStatistics::updateSettings);
    return _statisticsForm;
}

FormSettings *MainWindow::createFormSettings() {
    _settingsForm = new FormSettings(this);
    connect(_settingsForm, &FormSettings::s_updateSettings, this, &MainWindow::updateSettings);
    return _settingsForm;
}
#define FormsCreateEnd }

#define GoToFormStart {
void MainWindow::goToProfile(QString aId, ProfileUrlType aType) {
    SProfiles newProfile(aId, false, aType);
    if(newProfile.getStatus() == StatusValue::success) {
        returnFromForms();
        if(ui->StackedWidgetProfiles->currentIndex() != ui->StackedWidgetProfiles->count() - 1) {
            while(ui->StackedWidgetProfiles->count() - 1 != ui->StackedWidgetProfiles->currentIndex()) {
                ui->StackedWidgetProfiles->removeWidget(ui->StackedWidgetProfiles->widget(ui->StackedWidgetProfiles->currentIndex() + 1));
            }
        }
        ui->StackedWidgetProfiles->addWidget(createFormProfile(newProfile[0]));
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->count() - 1);
        updateSettings();
        updateEnabledButtonsBackNext();
        qDebug()<<"Буфер профилей"<<ui->StackedWidgetProfiles->currentIndex() + 1<<"/"<<ui->StackedWidgetProfiles->count();
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удаётся найти профиль!"));
        qDebug()<<newProfile.getError();
    }
}

void MainWindow::goToGames(SProfile aProfileSteamId, SGames aGames) {
    if(_gamesForm == nullptr) {
        if(!_blockedLoad) {
            _blockedLoad = true;
            ui->FormProgressBar->setMaximum(aGames.getCount());
            ui->ScrollAreaGames->setWidget(createFormGames(aProfileSteamId, aGames));
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(c_formsNone);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsGames);
    }
}

void MainWindow::goToFriends(QString aSteamId, SFriends aFriends) {
    if(_friendsForm == nullptr) {
        if(!_blockedLoad) {
            _blockedLoad = true;
            ui->FormProgressBar->setMaximum(aFriends.getCount());
            ui->ScrollAreaFriends->setWidget(createFormFriends(aSteamId, aFriends));
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(c_formsNone);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsFriends);
    }
}

void MainWindow::goToFavorites() {
    if(_favoritesForm == nullptr) {
        if(!_blockedLoad) {
            ui->ScrollAreaFavorites->setWidget(createFormFavorites());
            //
            ui->StackedWidgetForms->setCurrentIndex(c_formsFavorites);
            resizeScrollArea();
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsFavorites);
    }
}

void MainWindow::goToStatistics(QString aId, SGames aGames, QString aProfileName) {
    if(_statisticsForm == nullptr) {
        if(!_blockedLoad) {
            _blockedLoad = true;
            ui->FormProgressBar->setMaximum(aGames.getCount());
            ui->ScrollAreaStatistic->setWidget(createFormStatistics(aId, aGames, aProfileName));
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(c_formsNone);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsStatistic);
    }
}
#define GoToFormEnd }

void MainWindow::showForm(int aWidgetIndex, int aWidthWindow) {
    ui->FormProgressBar->setVisible(false);
    _blockedLoad = false;
    ui->StackedWidgetForms->setCurrentIndex(aWidgetIndex);
    resizeScrollArea(aWidthWindow);
}

void MainWindow::returnFromForms() {
    if(_gamesForm != nullptr) {
        disconnect(_gamesForm);
        delete _gamesForm;
        _gamesForm = nullptr;
    }
    if(_friendsForm != nullptr) {
        disconnect(_friendsForm);
        delete _friendsForm;
        _friendsForm = nullptr;
    }
    if(_statisticsForm != nullptr) {
        disconnect(_statisticsForm);
        delete _statisticsForm;
        _statisticsForm = nullptr;
    }
//    if(_favoritesForm != nullptr) {
//        disconnect(_favoritesForm);
//        delete _favoritesForm;
//        _favoritesForm = nullptr;
//    }
//    if(_settingsForm != nullptr) {
//        disconnect(_settingsForm);
//        delete _settingsForm;
//        _settingsForm = nullptr;
//    }
    ui->StackedWidgetForms->setCurrentIndex(0);
}
#define FormsEnd }

#define EventsStart {
void MainWindow::keyPressEvent(QKeyEvent *aEvent) {
    //qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter;
    if(aEvent->key() == 16777220) {
        buttonFindProfile_Clicked();
    }
}

void MainWindow::changeEvent(QEvent *aEvent) {
    if(aEvent->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}

void MainWindow::closeEvent(QCloseEvent *aEvent) {
    _setting.setMainWindowMaximize(this->isMaximized());
    if(this->isMaximized()) {
        this->showNormal();
    }
    _setting.setMainWindowParams(this->frameGeometry());
    _setting.syncronizeSettings();
    aEvent->accept();
}
#define EventsEnd }

MainWindow::~MainWindow() {
    returnFromForms();
    _containerAchievementsForm->close();
    delete _containerAchievementsForm;
    delete ui;
}

void MainWindow::updateSettings() {
    _setting.syncronizeSettings();
    switch (_setting.getProfileInfoSize()) {
    case 0:{
        ui->StackedWidgetProfiles->setFixedHeight(35);
        break;
    }
    case 1:{
        ui->StackedWidgetProfiles->setFixedHeight(100);
        break;
    }
    case 2:{
        ui->StackedWidgetProfiles->setFixedHeight(200);
    }
    }
    FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
    if (currentProfile) {
        ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile()._steamID != _setting.getMyProfile());
    }
    qApp->setStyleSheet(getTheme());
    emit s_updateSettings();
}

void MainWindow::resizeScrollArea(int aWidth) {
    if((ui->StackedWidgetForms->height() < 400) || (ui->StackedWidgetForms->width() < aWidth)) {
        //qDebug()<<this->width()+a_width-ui->StackedWidgetForms->width()<<this->width()<<a_width<<ui->StackedWidgetForms->width();
        QPropertyAnimation *animation = new QPropertyAnimation(this, "size");
        connect(animation, &QPropertyAnimation::finished, animation, &QPropertyAnimation::deleteLater);
        animation->setDuration(500);
        animation->setStartValue(QSize(this->width(), this->height()));
        animation->setEndValue(QSize(this->width() + aWidth - ui->StackedWidgetForms->width(), this->height() - ui->StackedWidgetForms->height() + 400));
        animation->start();
    }
}
#define SystemEnd }

#define Functions {
void MainWindow::buttonFindProfile_Clicked() {
    QString profileId = ui->LineEditIdProfile->text().remove("https://").remove("steamcommunity.com").remove('\r');
    if(ui->LineEditIdProfile->text().indexOf("/id/", 0) > -1) {
        profileId = profileId.remove("/id/").remove("/");
        goToProfile(profileId, ProfileUrlType::vanity);
    } else {
        if(ui->LineEditIdProfile->text().indexOf("/profiles/", 0) > -1) {
            profileId = profileId.remove("/profiles/").remove("/");
        }
        goToProfile(profileId, ProfileUrlType::id);
    }
    returnFromForms();
}

void MainWindow::updateEnabledButtonsBackNext() {
    ui->ButtonBack->setEnabled(ui->StackedWidgetProfiles->currentIndex() > 0);
    ui->ButtonNext->setEnabled(ui->StackedWidgetProfiles->currentIndex() != ui->StackedWidgetProfiles->count() - 1);
}

void MainWindow::buttonBack_Clicked() {
    if(ui->StackedWidgetProfiles->currentIndex() > 0) {
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex() - 1);
        returnFromForms();
        updateSettings();
        updateEnabledButtonsBackNext();
    }
}

void MainWindow::buttonNext_Clicked() {
    if(ui->StackedWidgetProfiles->currentIndex() < ui->StackedWidgetProfiles->count()) {
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex() + 1);
        returnFromForms();
        updateSettings();
        updateEnabledButtonsBackNext();
    }
}

void MainWindow::buttonSettings_Clicked() {
    if(_settingsForm == nullptr) {
        if(!_blockedLoad) {
            createFormSettings();
            ui->ScrollAreaSettings->setWidget(_settingsForm);
            //
            ui->StackedWidgetForms->setCurrentIndex(c_formsSettings);
            resizeScrollArea();
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsSettings);
    }
}

void MainWindow::buttonGoToMyProfile_Clicked() {
    if(_setting.getMyProfile() != "none") {
        goToProfile(_setting.getMyProfile(), ProfileUrlType::id);
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удаётся найти профиль!"));
    }
}

void MainWindow::buttonUpdate_Clicked() {
    FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
    if (currentProfile) {
        currentProfile->updateInfo();
    }
}

void MainWindow::buttonExit_Clicked() {
    qApp->closeAllWindows();
}

void MainWindow::buttonMaximize_Clicked() {
    if(!this->isMaximized()) {
        this->showMaximized();
        ui->ButtonMaximize->setIcon(QIcon(_setting.getIconNormalizeWindow()));
    } else {
        this->showNormal();
        ui->ButtonMaximize->setIcon(QIcon(_setting.getIconMaximizeWindow()));
    }
}

void MainWindow::buttonMinimize_Clicked() {
    if(!this->isMinimized()) {
        this->showMinimized();
    } else {
        this->showNormal();
    }
}
#define FunctionsEnd }
