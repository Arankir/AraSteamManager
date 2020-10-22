#include "mainwindow.h"
#include "ui_mainwindow.h"

//    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
//qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter << 16777220;
//qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//https://ru.stackoverflow.com/questions/952577/qt-network-ssl-qsslsocketconnecttohostencrypted-tls-initialization-failed

#define Constants {
constexpr int c_formsNone       = 0;
constexpr int c_formsGames      = 1;
constexpr int c_formsFriends    = 2;
constexpr int c_formsStatistic  = 3;
constexpr int c_formsFavorites  = 4;
constexpr int c_formsSettings   = 5;
#define ConstantsEnd }

#define Init {
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), _games(this) {
    ui->setupUi(this);
    initComponents();
    if (Settings::getMyProfile() != "none") {
        goToProfile(Settings::getMyProfile(), ProfileUrlType::id);
    }
}

void MainWindow::initComponents() {
    _containerAchievementsForm = new FormContainerAchievements();
    ui->line->setVisible(false);

    ui->ButtonMinimize  ->setFlat(true);
    ui->ButtonMaximize  ->setFlat(true);
    ui->ButtonExit      ->setFlat(true);

    ui->FormProgressBar->setVisible(false);
    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);
    ui->StackedWidgetForms->setCurrentIndex(0);

    ui->ButtonMinimize->setFixedSize(QSize(23, 23));
    ui->ButtonMaximize->setFixedSize(QSize(23, 23));
    ui->ButtonExit    ->setFixedSize(QSize(23, 23));
    this->setGeometry(Settings::getMainWindowGeometry());
    this->move(Settings::getMainWindowPos());
    if(Settings::getMainWindowMaximize()) {
        this->showMaximized();
    }
    qApp->setStyleSheet(getTheme());
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setColor(QColor(93, 170, 224, 255 * 0.7));
    shadowEffect->setOffset(0);
    shadowEffect->setBlurRadius(50);
    ui->FormProgressBar->setGraphicsEffect(shadowEffect);
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
    QString qss;
    switch(Settings::getTheme()) {
    case 1:{
//        hoverGradient = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
//                    "stop: 0 #185077, "
//                    "stop: 0.22 #387097, "
//                    "stop: 0.88 #286087, "
//                    "stop: 1.0 #185077); ";
        backgroundGradient = "qradialgradient("
                    "cx:0.5, cy:0.5, "
                    "radius: 0.9, "
                    "fx:0.4, fy:0.5, "
                    "stop:0 #12457c, "
                    //"stop:0.5 #12324b, "
                    "stop:1 #19253d); ";
        qss =
#define button {
                "QPushButton[text] { "
                    "padding-left: 0.3em; "
                "} "
                "QPushButton, QToolButton { "
                    "color: white; "
                    "background: qlineargradient(x1: -1, y1: -1, x2: 2, y2: 2, "
                        "stop: 0 #3998ec, "
                        "stop: 1.0 #235fcf); "
                    "border: 1px solid #262626; "
                    //"min-width: 25px; "
                    "min-height: 20px; "
                    "padding: 1 4 1 4; "
                    "border-radius: 1px; "
                "} "
                "QPushButton:hover, QToolButton:hover { "
                    "background-color: #dfe7ed; "
                    "background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, "
                        "stop: 0 #45bafd, "
                        "stop: 1.0 #3285e2); "
                "} "
                "QPushButton:pressed, QToolButton:pressed { "
                    //"background-color: #3698a7; "
                    "margin: 1px; "
                "} "
                "QPushButton:flat { "
                    "background-color: none; "
                    //"border: none; "
                "} "
                "QPushButton:disabled, QToolButton:disabled { "
                    "background-color: #48525a; "
                "} "
#define buttonend }
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
#define progressbar {
                "QProgressBar { "
                    "color: white; "
                    "background-color: #5daae0; "
                    "text-align: center; "
                "} "
                "QProgressBar::chunk { "
                    "background-color: #386584; "
                    "margin: 5px; "
                "} "
                "QProgressBar[accessibleName=BadAchievements] { "
                    "color: white; "
                    "background-color: #E44B4B; "
                    "text-align: center; "
                "} "
                "QProgressBar::chunk[accessibleName=BadAchievements] { "
                    "background-color: rgba(0,0,0,0); "
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
                    "image: url(" + Images::radioButtonUnchecked() + "); "
                "} "
                "QRadioButton::indicator::checked { "
                    "image: url(" + Images::radioButtonChecked() + "); "
                "} "
                "QRadioButton::indicator::unchecked:hover { "
                    "image: url(" + Images::radioButtonUncheckedHover() + "); "
                "} "
                "QRadioButton::indicator::checked:hover { "
                    "image: url(" + Images::radioButtonCheckedHover() + "); "
                "} "
                "QRadioButton::indicator::unchecked:pressed { "
                    "image: url(" + Images::radioButtonUncheckedPress() + "); "
                "} "
                "QRadioButton::indicator::checked:pressed { "
                    "image: url(" + Images::radioButtonCheckedPress() + "); "
                "} "
                "QRadioButton::hover { "
                    "color: #57CBDE"
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
                    "image: url(" + Images::checkBoxUnchecked() + "); "
                "} "
                "QCheckBox::indicator:checked { "
                    "image: url(" + Images::checkBoxChecked() + "); "
                "} "
                "QCheckBox::indicator:unchecked:hover { "
                    "image: url(" + Images::checkBoxUncheckedHover() + "); "
                "} "
                "QCheckBox::indicator:checked:hover { "
                    "image: url(" + Images::checkBoxCheckedHover() + "); "
                "} "
                "QCheckBox::indicator:unchecked:pressed { "
                    "image: url(" + Images::checkBoxUncheckedPress() + "); "
                "} "
                "QCheckBox::indicator:checked:pressed { "
                    "image: url(" + Images::checkBoxCheckedPress() + "); "
                "} "
#define checkboxend }
#define combobox {
                "QComboBox { "
                    "border: 1px solid #262626; "
                    "border-radius: 1px; "
                    "padding: 1px 18px 1px 3px; "
                    "color: #dddddd; "
                    "background: qlineargradient(x1: -1, y1: -1, x2: 2, y2: 2, "
                        "stop: 0 #3998ec, "
                        "stop: 1.0 #235fcf); "
                "} "
                "QComboBox:hover { "
                    "border: 1px solid #87b6ff; "
                "} "
                "QComboBox:on { "/* shift the text when the popup opens */
                    "padding-top: 3px; "
                    "padding-left: 4px; "
                "} "
                "QComboBox::drop-down { "
                    "subcontrol-origin: padding; "
                    "subcontrol-position: top right; "
                    "width: 15px; "

                    "border-left: 1px solid #dddddd; "
                    "border-top-right-radius: 1px; "
                    "padding-right: 4px; "
                    "border-bottom-right-radius: 1px; "
                "} "
                "QComboBox::down-arrow { "
                    "image: url(" + Images::comboBoxDown() + "); "
                    "width: 20px; "
                    "padding-left: 3px; "
                "} "
                "QComboBox::item { "
                    "border: 1px solid #262626; "
                    "border-radius: 4px; "
                    "background-color: #13243e; "
                    "height: 20px; "
                    "padding-left: -20px; "
                "} "
                "QMenu::item { "
                    "border: 1px solid #262626; "
                    "border-radius: 4px; "
                    "background-color: #13243e; "
                    "height: 20px; "
                    "color: #dddddd; "
                    "padding: 2 5 2 5; "
                "} "
                "QComboBox::item:selected, QMenu::item:selected { "
                    "border: 1px solid #87b6ff; "
                    "background-color: qlineargradient(x1: 0, y1: -2, x2: 0, y2: 1, "
                        "stop: 0 #2692ff, "
                        "stop: 1.0 #153257); "
                "} "
                "QComboBox::item:checked { "
                    "font: bold; "
                    "color: #87b6ff; "
                "} "
                "QComboBox QAbstractItemView { "
                    "border: 0px; "
                    "background-color: #262626; "
                    "border-bottom-left-radius: 4px; "
                    "border-bottom-right-radius: 4px; "
                "} "
                "QComboBox::indicator { "
                    "background-color: transparent; "
                    "selection-background-color: transparent; "
                    "color: transparent; "
                    "selection-color: transparent; "
                "} "
#define comboboxend }
#define tabbar {
                "QTabWidget::pane { "
                    "border: 1px solid black; "
                "} "
                "QTabBar::close-button { "
                   "subcontrol-position: right; "
                   "image: url(" + Images::closeWindow() + "); "
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
#define tablewidget {
#define headerview {
                "QHeaderView::section, QTableView QTableCornerButton::section { "
                    "background-color: #13243e; "
                    "color: #dddddd; "
                    "border: 1px solid #6c6c6c; "
                    "border-bottom: 0px solid #6c6c6c; "
                    "border-top: 0px solid #6c6c6c; "
                    "border-right: 0px solid #6c6c6c; "
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
#define tableview {
                "QTableView { "
                    "background-color: rgba(0, 0, 0, 0); "
                    "selection-background-color: rgba(0, 0, 0, 0); "
                    "border-radius: 2px; "
                    "border: 1px solid #777777; "
                "} "
                "QTableView#TableWidgetContent::indicator { "
                    "width: 40px; "
                    "height: 40px; "
                "} "
                "QTableView::indicator:unchecked { "
                    "image: url(" + Images::checkBoxUnchecked() + "); "
                "} "
                "QTableView::indicator:checked { "
                    "image: url(" + Images::checkBoxChecked() + "); "
                "} "
                "QTableView::indicator:unchecked:hover { "
                    "image: url(" + Images::checkBoxUncheckedHover() + "); "
                "} "
                "QTableView::indicator:checked:hover { "
                    "image: url(" + Images::checkBoxCheckedHover() + "); "
                "} "
                "QTableView::indicator:unchecked:pressed { "
                    "image: url(" + Images::checkBoxUncheckedPress() + "); "
                "} "
                "QTableView::indicator:checked:pressed { "
                    "image: url(" + Images::checkBoxCheckedPress() + "); "
                "} "
#define tableviewEnd }
                "QTableWidget { "
                    "border: 1px solid #777777; "
                    "border-radius: 2px; "
                    "color: #dddddd; "
                "} "
                "QTableWidget::item { "
                    "background-color: rgba(23, 26, 33, 0.5); "
                    //"color: #dddddd; "
                    "margin-top: 10px; "
                    "padding: 4px; "
                "} "
                "QTableWidget::item:alternate { "
                    "background-color: #1d2027; "
                "} "
                "QTableWidget::item:hover:!selected { "
                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, "
                        "stop: 0   rgba(23, 26, 33, 0.5), "
                        "stop: 0.5 rgba(43, 46, 53, 0.5), "
                        "stop: 1.0 rgba(23, 26, 33, 0.5)); "
                "} "
                "QTableWidget::item:alternate:hover:!selected { "
                    "background-color: qlineargradient(x1: -2, y1: -2, x2: 1, y2: 1, "
                        "stop: 0 #2692ff, "
                        "stop: 1.0 #1d2027); "
                "} "
                "QTableWidget::item:selected { "
                    "background-color: qlineargradient(x1: 0, y1: -2, x2: 0, y2: 1, "
                        "stop: 0   #2692ff, "
                        "stop: 1.0 #153257); "
                    "border: 1px solid #87b6ff; "
                    "border-right: 0px solid #87b6ff; "
                    "border-left: 0px solid #87b6ff; "
                "} "
#define tablewidgetend }
#define scrollbar {
                "QScrollBar:vertical, QScrollBar:horizontal { "
                    "border: 1px solid #999999; "
                    "background: #13273a; "
                "} "
                "QScrollBar:vertical { "
                    "width: 15px; "
                "}"
                "QScrollBar:horizontal { "
                    "height: 15px; "
                "} "

                "QScrollBar::handle:vertical, QScrollBar::handle:horizontal { "
                    "background: qlineargradient(x1: 0, y1: -1, x2: 0, y2: 2, "
                        "stop: 0 #3998ec, "
                        "stop: 1.0 #235fcf); "
                    "min-width: 15px; "
                    "min-height: 15px; "
                    //"border-radius: 6px; "
                "}"
                "QScrollBar::handle:vertical { "
                    "margin-top: 15px; "
                    "margin-bottom: 15px; "
                "}"
                "QScrollBar::handle:horizontal { "
                    "margin-right: 15; "
                    "margin-left: 15; "
                "}"
                "QScrollBar::add-line:vertical { "
                    "image: url(" + Images::scrollBarDown() + "); "
                "}"
                "QScrollBar::sub-line:vertical { "
                    "image: url(" + Images::scrollBarUp() + "); "
                "}"
                "QScrollBar::add-line:horizontal { "
                    "image: url(" + Images::scrollBarRight() + "); "
                "}"
                "QScrollBar::sub-line:horizontal { "
                    "image: url(" + Images::scrollBarLeft() + "); "
                "}"
#define scrollbarend }
                "QWidget#MainWindow, QWidget#FormContainerAchievements { "
                    "background-color: " + backgroundGradient +
                    "border: 1px solid rgb(87, 203, 222); "
                "} "
                "QTabWidget > QStackedWidget > QWidget, QTabWidget > QStackedWidget, QTabWidget, QWidget#FormStatistics { "
                    "background-color: " + backgroundGradient +
                    "border: 0px solid black; "
                "} "
                "QFrame { "
                    "border: 0px solid #000000; "
                    //"background-color: rgba(23, 26, 33, 0.5);"
                "} "
                "QFrame[accessibleName=TitleWindow] { "
                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                        "stop: 0 rgba(0, 0, 0, 0), "
                        //"stop: 0.5 #20232b, "
                        "stop: 1.0 rgba(0, 0, 0, 0)); "
                    "border: 1px solid rgb(87, 203, 222); "
                    "border-bottom: 0px; "
//                    "border-top: 0px; "
                "} "
                "QFrame#FrameProfileBaseInfo { "
                    "background-color: rgba(37, 60, 94, 0.5); "
                "} "
                "QFrame#FrameProfileMaximumInfo { "
                    "background-color: rgba(30, 41, 59, 0.5); "
                "} "
                "QFrame#FrameProfileButtons { "
                    "background-color: rgba(30, 41, 59, 0.5); "
                "} "
                "QFrame#FrameSelected { "
                    "background-color: rgba(23, 26, 33, 0.8); "
                "} "
                "QFrame#FrameCategories, QFrame#FrameEditCategory { "
                    "background-color: rgba(23, 26, 33, 0.8); "
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
                    "margin: 9 0 0 9; "
                "} "
//                "QGroupBox { "
//                    "padding-top: 18; "
//                    "border: none; "
//                    "background-color: rgba(23, 26, 33, 0.5); "
//                "} "
                "QGroupBox#GroupBoxFilter::title { "
                    "image: url(" + Images::filter() + "); "
                    "image-position: left; "
                    //"margin-top: 12px; "
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
    ui->LabelLogo->setPixmap(QPixmap(Images::logo()).scaled(30, 30));

//    ui->LabelLogo->setTextFormat(Qt::RichText);
//    ui->LabelLogo->setText("<img height=30 style=\"vertical-align: top\" src=\"" + _setting.getIconLogoColor() + "\"> "
//                                "<span style=\"vertical-align: bottom\">НАЯ ПРОГА</span>");
    ui->ButtonUpdate        ->setIcon(QIcon(Images::update()));
    ui->ButtonGoToMyProfile ->setIcon(QIcon(Images::home()));
    ui->ButtonFindProfile   ->setIcon(QIcon(Images::findProfile()));
    ui->ButtonSettings      ->setIcon(QIcon(Images::settings()));
    ui->ButtonExit          ->setIcon(QIcon(Images::closeWindow()));
    ui->ButtonMinimize      ->setIcon(QIcon(Images::minimizeWindow()));
    if (this->isMaximized()) {
        ui->ButtonMaximize  ->setIcon(QIcon(Images::normalizeWindow()));
    } else {
        ui->ButtonMaximize  ->setIcon(QIcon(Images::maximizeWindow()));
    }
    ui->ButtonBack          ->setIcon(QIcon(Images::left()));
    ui->ButtonNext          ->setIcon(QIcon(Images::right()));
}

void MainWindow::progressLoading(int aProgress, int) {
    ui->FormProgressBar->setValue(aProgress);
}

#define ContainerAchievementsStart {
void MainWindow::addAchievements(SAchievementsPlayer &aAchievements, SGame &aGames) {
    if (_containerAchievementsForm == nullptr) {
        createFormContainerAchievements();
    }
    FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
    if (currentProfile) {
        _containerAchievementsForm->addFormAchievement(aAchievements, currentProfile->getProfile(), aGames, _achievementsCount++);
        _containerAchievementsForm->show();
    }
}

void MainWindow::removeAchievements(int index) {
    Q_UNUSED(index);
    --_achievementsCount;
}

void MainWindow::containerAchievementsClose() {
    _achievementsCount = 0;
    disconnect(_containerAchievementsForm, &FormContainerAchievements::s_removeAchievements, this, &MainWindow::removeAchievements);
    disconnect(_containerAchievementsForm, &FormContainerAchievements::s_formClose,          this, &MainWindow::containerAchievementsClose);
    delete _containerAchievementsForm;
    _containerAchievementsForm = nullptr;
}

void MainWindow::returnFromAchievements(int aNum) {
    Q_UNUSED(aNum);
    //disconnect(_achievementsForms[aNum], &FormAchievements::s_returnToGames, this, &MainWindow::returnFromAchievements);
    disconnect(_containerAchievementsForm);
    delete _containerAchievementsForm;
    //delete achievementsforms[num];
}
#define ContainerAchievementsEnd }

#define FormsStart {

#define FormsCreateStart {
FormProfile *MainWindow::createFormProfile(SProfile &aProfile) {
    FormProfile *newFormProfile = new FormProfile(aProfile);
    newFormProfile->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum));
    connect(newFormProfile, &FormProfile::s_goToGames,       this,           &MainWindow::goToGames);
    connect(newFormProfile, &FormProfile::s_goToFriends,     this,           &MainWindow::goToFriends);
    connect(newFormProfile, &FormProfile::s_goToStatistic,   this,           &MainWindow::goToStatistics);
    connect(newFormProfile, &FormProfile::s_goToFavorites,   this,           &MainWindow::goToFavorites);
    connect(newFormProfile, &FormProfile::s_myProfileChange, this,           &MainWindow::updateSettings);
    connect(this,           &MainWindow::s_updateSettings,   newFormProfile, &FormProfile::updateSettings);
    return newFormProfile;
}

FormGames *MainWindow::createFormGames(SProfile &aProfile, SGames &aGames) {
    _gamesForm = new FormGames(aProfile, aGames, this);
    connect(this,       &MainWindow::s_updateSettings,    _gamesForm,   &FormGames::updateSettings);
    connect(_gamesForm, &FormGames::s_achievementsLoaded, this,         &MainWindow::progressLoading);
    connect(_gamesForm, &FormGames::s_showAchievements,   this,         &MainWindow::addAchievements);
    connect(_gamesForm, &FormGames::s_finish,             this,         [=](int aWidth) {
                                                                            showForm(c_formsGames, aWidth);
                                                                        });
    _gamesForm->setWhatsThis("FormGames");
    return _gamesForm;
}

FormFriends *MainWindow::createFormFriends(const QString &aId, SFriends &aFriends) {
    _friendsForm = new FormFriends(aId, aFriends, this);
    connect(this,         &MainWindow::s_updateSettings, _friendsForm,  &FormFriends::updateSettings);
    connect(_friendsForm, &FormFriends::s_friendsLoaded, this,          &MainWindow::progressLoading);
    connect(_friendsForm, &FormFriends::s_go_to_profile, this,          &MainWindow::goToProfile);
    connect(_friendsForm, &FormFriends::s_finish,        this,          [=]() {
                                                                            showForm(c_formsFriends);
                                                                        });
    _friendsForm->setWhatsThis("FormFriends");
    return _friendsForm;
}

FormFavorites *MainWindow::createFormFavorites() {
    _favoritesForm = new FormFavorites(this);
    connect(this, &MainWindow::s_updateSettings, _favoritesForm, &FormFavorites::updateSettings);
    _favoritesForm->setWhatsThis("FormFavorites");
    return _favoritesForm;
}

FormStatistics *MainWindow::createFormStatistics(const QString &aId, SGames &aGames, const QString &aName) {
    _statisticsForm = new FormStatistics(aId, aGames, aName, this);
    connect(this,            &MainWindow::s_updateSettings,       _statisticsForm,  &FormStatistics::updateSettings);
    connect(_statisticsForm, &FormStatistics::s_statisticsLoaded, this,             &MainWindow::progressLoading);
    connect(_statisticsForm, &FormStatistics::s_finish,           this,             [=]() {
                                                                                        showForm(c_formsStatistic);
                                                                                    });
    return _statisticsForm;
}

FormSettings *MainWindow::createFormSettings() {
    _settingsForm = new FormSettings(this);
    connect(_settingsForm, &FormSettings::s_updateSettings, this, &MainWindow::updateSettings);
    return _settingsForm;
}

FormContainerAchievements *MainWindow::createFormContainerAchievements() {
    _containerAchievementsForm = new FormContainerAchievements();
    connect(_containerAchievementsForm, &FormContainerAchievements::s_removeAchievements, this, &MainWindow::removeAchievements);
    connect(_containerAchievementsForm, &FormContainerAchievements::s_formClose,          this, &MainWindow::containerAchievementsClose);
    //++_windowChildCount;
    return _containerAchievementsForm;
}
#define FormsCreateEnd }

#define GoToFormStart {
void MainWindow::goToProfile(const QString &aId, ProfileUrlType aType) {
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
        qInfo() << "Буфер профилей" << ui->StackedWidgetProfiles->currentIndex() + 1 << "/" << ui->StackedWidgetProfiles->count();
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удаётся найти профиль!"));
        qWarning() << newProfile.getError();
    }
}

void MainWindow::goToGames(SProfile &aProfileSteamId, SGames &aGames) {
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

void MainWindow::goToFriends(const QString &aSteamId, SFriends &aFriends) {
    if(_friendsForm == nullptr) {
        if(!_blockedLoad) {
            _blockedLoad = true;
            ui->FormProgressBar->setMaximum(aFriends.getCount());
            ui->ScrollAreaFriends->setWidget(createFormFriends(aSteamId, aFriends));
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(c_formsNone);
            //showForm(c_formsFriends);
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

void MainWindow::goToStatistics(const QString &aId, SGames &aGames, const QString &aProfileName) {
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
        _friendsForm->deleteLater();
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
    if(aEvent->key() == Qt::Key_Enter) {
        buttonFindProfile_Clicked();
    }
}

void MainWindow::changeEvent(QEvent *aEvent) {
    if (aEvent->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}

void MainWindow::closeEvent(QCloseEvent *aEvent) {
    _setting.setMainWindowMaximize(this->isMaximized());
    if(this->isMaximized()) {
        this->showNormal();
    }
    _setting.setMainWindowParams(this->frameGeometry());
    Settings::syncronizeSettings();
    qInfo() << "Programm closed";
    aEvent->accept();
}
#define EventsEnd }

MainWindow::~MainWindow() {
    //может быть ошибка
    returnFromForms();
    _containerAchievementsForm->close();
    delete _containerAchievementsForm;
    delete ui;
}

void MainWindow::updateSettings() {
    Settings::syncronizeSettings();
//TODO исправить ресайз профилей на нормальный вариант
    switch (Settings::getProfileInfoSize()) {
    case 0: {
        ui->StackedWidgetProfiles->setFixedHeight(50);
        break;
    }
    case 1: {
        ui->StackedWidgetProfiles->setFixedHeight(140);
        break;
    }
    case 2: {
        ui->StackedWidgetProfiles->setFixedHeight(320);
        break;
    }
    }
    FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
    if (currentProfile) {
        ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile()._steamID != Settings::getMyProfile());
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
    ProfileUrlType type;
    if(ui->LineEditIdProfile->text().indexOf("/id/") > -1) {
        profileId = profileId.remove("/id/").remove("/");
        type = ProfileUrlType::vanity;
    } else {
        if(ui->LineEditIdProfile->text().indexOf("/profiles/") > -1) {
            profileId = profileId.remove("/profiles/").remove("/");
        }
        type = ProfileUrlType::id;
    }
    goToProfile(profileId, type);
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
        FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
        if (currentProfile) {
            ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile()._steamID != Settings::getMyProfile());
        }
        updateEnabledButtonsBackNext();
    }
}

void MainWindow::buttonNext_Clicked() {
    if(ui->StackedWidgetProfiles->currentIndex() < ui->StackedWidgetProfiles->count()) {
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex() + 1);
        returnFromForms();
        FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
        if (currentProfile) {
            ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile()._steamID != Settings::getMyProfile());
        }
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
    if(Settings::getMyProfile() != "none") {
        goToProfile(Settings::getMyProfile(), ProfileUrlType::id);
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
        ui->ButtonMaximize->setIcon(QIcon(Images::normalizeWindow()));
    } else {
        this->showNormal();
        ui->ButtonMaximize->setIcon(QIcon(Images::maximizeWindow()));
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
