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
                        "background-color: #202020; "
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
                        "border: 0px solid #cccccc; "
                        "border-radius: 8px; "
                        "background-color: "+backgroundGradient+
                    "} "
                    "QTableWidget::item { "
                        "border-bottom: 1px solid #cccccc; "
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
                        "width:10px; "
                        //"    margin: 0px 0px 0px 0px;"
                    "}"
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
    qApp->setStyleSheet(pushButton+progressBar+forms+subContainers+labels+radioButtons+tabBar+checkBox+comboBox+lineEdit+tableWidget+headerView+groupBox);

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
    ui->LabelLogo->setPixmap(QPixmap("://logo.png"));
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
    ui->LabelNick->setStyleSheet("color: #42a9c6;");
    ui->line->setVisible(false);
    ui->LabelProfileVisibility->setVisible(false);
    ui->ScrollAreaProfileInfo->setVisible(false);
    ui->FormProgressBar->setVisible(false);
    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);
    ui->LabelProfileUrl->setTextFormat(Qt::RichText);
    ui->ButtonUpdate->setIcon(QIcon("://"+_theme+"/update.png"));
    ui->ButtonGoToMyProfile->setIcon(QIcon("://"+_theme+"/home.png"));
    ui->ButtonSetProfile->setIcon(QIcon("://"+_theme+"/set_home.png"));
    ui->ButtonFindProfile->setIcon(QIcon("://"+_theme+"/find_profile.png"));
    ui->ButtonFavorites->setIcon(QIcon("://"+_theme+"/favorites.png"));
    ui->ButtonStatistics->setIcon(QIcon("://"+_theme+"/statistic.png"));
    ui->ButtonSettings->setIcon(QIcon("://"+_theme+"/settings.png"));
    ui->ButtonExit->setIcon(QIcon("://"+_theme+"/exit.png"));
    ui->ButtonFriends->setIcon(QIcon("://"+_theme+"/friends.png"));
    ui->ButtonGames->setIcon(QIcon("://"+_theme+"/games.png"));
    ui->ButtonBack->setIcon(QIcon("://"+_theme+"/left.png"));
    ui->ButtonNext->setIcon(QIcon("://"+_theme+"/right.png"));
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
            qDebug()<<newProfile.GetError();
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
    ui->LabelProfileUrl->setText("<img height=15 style=\"vertical-align: top\" src=\"://"+_theme+"/link.png\"> <a href=\""+a_profile.GetProfileurl()+"\"><span style=\" text-decoration: underline; color:#2d7fc8;\">"+a_profile.GetProfileurl()+"</span></a>");
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
    ui->ScrollAreaProfileInfo->setEnabled(true);
    ui->ButtonSetProfile->setEnabled(_setting.GetMyProfile()!=a_profile.GetSteamid());
    ui->ButtonStatistics->setEnabled(_games.GetStatus()==StatusValue::success);
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
