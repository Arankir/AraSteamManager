#include "formsettings.h"
#include "ui_formsettings.h"

FormSettings::FormSettings(QWidget *aParent): QWidget(aParent), ui(new Ui::FormSettings) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    initComponents();
}

FormSettings::~FormSettings() {
    delete ui;
}

void FormSettings::initComponents() {
    switch (_setting.getLanguage()) {
    case 1: {
        ui->RadioButtonLanguageEnglish->setChecked(true);
        break;
    }
    case 5: {
        ui->RadioButtonLanguageRussian->setChecked(true);
        break;
    }
    default: {
        break;
    }
    }
    switch (_setting.getVisibleHiddenGames()) {
    case 0: {
        ui->CheckBoxVisibleHiddenGames->setChecked(false);
        break;
    }
    case 1: {
        ui->CheckBoxVisibleHiddenGames->setChecked(true);
        break;
    }
    default: {
        break;
    }
    }
    switch (_setting.getTheme()) {
    case 1: {
        ui->RadioButtonDarkTheme->setChecked(true);
        break;
    }
    case 2: {
        ui->RadioButtonLightTheme->setChecked(true);
        break;
    }
    default: {
        break;
    }
    }
    ui->SliderProfileSize->setValue(_setting.getProfileInfoSize());
    ui->CheckBoxSaveImage->setChecked(_setting.getSaveImages());
//    QPalette darkPalette;
//    darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(73, 73, 73),Qt::white,Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
    //                        тип               ,???      ,Кнопка            ,Разделители,???      ,???     ,цвет текста на кнопке,???  ,поле сзади     ,???
    //ui->GroupBoxDarkTheme->setPalette(darkPalette);
    //ui->GroupBoxWhiteTheme->setPalette(style()->standardPalette());

    ui->tabWidget->setAttribute(Qt::WA_TranslucentBackground);

    ui->labelIcons8->setTextFormat(Qt::RichText);
    QFormLayout *layout = new QFormLayout;
    QDir dirHiddenGames(_setting._pathHide);
    dirHiddenGames.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dirHiddenGames.setSorting(QDir::Name);
    if(dirHiddenGames.exists()){
        QPair<QString,QList<QString>> pair;
        pair.first = "All";
        pair.second = QList<QString>();
        if(QFile(_setting._pathHide + "All.txt").exists()) {
            QRadioButtonWithData *allHidden = new QRadioButtonWithData;
            allHidden->setText(tr("Все профили"));
            allHidden->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
            allHidden->setObjectName("HiddenGames0");
            allHidden->AddData("NumberFileHiddenGame","0");
            connect(allHidden, SIGNAL(clicked()), this, SLOT(radioButtonHiddenGames_Clicked()));
            layout->addWidget(allHidden);
            QFile fileHide1(_setting._pathHide + "All.txt");
            if(fileHide1.open(QIODevice::ReadOnly)) {
                while(!fileHide1.atEnd()) {
                    pair.second << QString::fromLocal8Bit(fileHide1.readLine()).remove("\r\n").remove("\n");
                }
                fileHide1.close();
            }
        }
        _hiddenGames.append(std::move(pair));

        QFileInfoList list = dirHiddenGames.entryInfoList();
        int number = 1;
        for(auto &file :list) {
            QString fileName = file.fileName();
            if(fileName != "All.txt") {
                QFile fileHide(_setting._pathHide + fileName);
                fileHide.open(QFile::ReadOnly);
                SProfiles profile(fileName.remove(".txt"), false, ProfileUrlType::id);
                QList<QString> hide;
                QRadioButtonWithData *profileHidden = new QRadioButtonWithData;
                profileHidden->setText(profile.getPersonaname());
                profileHidden->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
                profileHidden->setObjectName("HiddenGames" + QString::number(number));
                profileHidden->AddData("NumberFileHiddenGame", QString::number(number));
                connect(profileHidden, SIGNAL(clicked()), this, SLOT(radioButtonHiddenGames_Clicked()));
                layout->addWidget(profileHidden);
                while(!fileHide.atEnd()) {
                    hide << QString::fromLocal8Bit(fileHide.readLine()).remove("\r\n").remove("\n");
                }
                fileHide.close();
                QPair<QString,QList<QString>> pair;
                pair.first = fileName.remove(".txt");
                pair.second = hide;
                _hiddenGames.append(std::move(pair));
                number++;
            }
        }
    }
    ui->FrameProfilesHideGames->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    ui->FrameProfilesHideGames->setLayout(layout);

#define Connects {
    connect(ui->RadioButtonLanguageEnglish, &QRadioButton::clicked,   this, &FormSettings::radioButtonLanguageEnglish_Clicked);
    connect(ui->RadioButtonLanguageRussian, &QRadioButton::clicked,   this, &FormSettings::radioButtonLanguageRussian_Clicked);
    connect(ui->CheckBoxVisibleHiddenGames, &QCheckBox::stateChanged, this, &FormSettings::checkBoxVisibleHiddenGames_StateChanged);
    connect(ui->RadioButtonDarkTheme,       &QRadioButton::clicked,   this, &FormSettings::radioButtonDarkTheme_Clicked);
    connect(ui->RadioButtonLightTheme,      &QRadioButton::clicked,   this, &FormSettings::radioButtonLightTheme_Clicked);
    connect(ui->CheckBoxSaveImage,          &QCheckBox::stateChanged, this, &FormSettings::checkBoxSaveImage_StateChanged);
    connect(ui->SliderProfileSize,          &QSlider::valueChanged,   this, &FormSettings::slideProfileSize_ValueChanged);
#define ConnectsEnd }
    retranslate();
}

void FormSettings::changeEvent(QEvent *aEvent) {
    if(aEvent->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormSettings::retranslate() {
    ui->retranslateUi(this);

    if (this->findChild<QRadioButtonWithData*>("HiddenGames0") != 0) {
        QRadioButtonWithData *allHidden = this->findChild<QRadioButtonWithData*>("HiddenGames0");
        allHidden->setText(tr("Все профили"));
    }
    QString iconsColor = _setting.getIconsColor();
    ui->labelIcons8->setText("<html><head/><body><p>"
                             "Иконки для приложения были предоставлены сайтом "
                             "<img height=15 style=\"vertical-align: top\" src=\"://" + iconsColor + "/link.png\">"
                            "<a href=https://icons8.ru/icons>"
                            "<span style=\" text-decoration: underline; color:#2d7fc8;\"> "
                            "https://icons8.ru/icons"
                            "</span></a></p></body></html>");
}

void FormSettings::radioButtonLanguageEnglish_Clicked() {
    _setting.setLanguage(1);
    emit s_updateSettings();
    QTranslator *translator = new QTranslator;
    translator->load(":/AraSteamManager_en.qm");
    qApp->installTranslator(translator);
    //ui->retranslateUi(this);
    //QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::radioButtonLanguageRussian_Clicked() {
    _setting.setLanguage(5);
    emit s_updateSettings();
    QTranslator *translator = new QTranslator;
    translator->load(":/AraSteamManager_ru.qm");
    qApp->installTranslator(translator);
    //ui->retranslateUi(this);
    //QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::checkBoxVisibleHiddenGames_StateChanged(int arg1) {
    _setting.setVisibleHiddenGames(arg1 / 2);
    emit s_updateSettings();
}

void FormSettings::radioButtonDarkTheme_Clicked() {
    _setting.setTheme(1);
    emit s_updateSettings();
    QMessageBox::information(this, tr("Тема изменена"), tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::radioButtonLightTheme_Clicked() {
    _setting.setTheme(2);
    emit s_updateSettings();
    QMessageBox::information(this, tr("Тема изменена"), tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::radioButtonHiddenGames_Clicked() {
    QRadioButtonWithData *rbSender = dynamic_cast<QRadioButtonWithData*>(sender());
    if (rbSender) {
        int indexHiddenGame = rbSender->GetData(0).toInt();
        QString iconsColor = _setting.getIconsColor();
        auto &currentGame = _hiddenGames[indexHiddenGame];
        ui->TableWidgetGames->clear();
        ui->TableWidgetGames->setRowCount(currentGame.second.size());
        if(indexHiddenGame != 0) {
            SGames games(currentGame.first, true, true, false);
            for(auto &game: games) {
                if(currentGame.second.indexOf(QString::number(game._appID)) > -1) {
                    int setTo = currentGame.second.indexOf(QString::number(game._appID));
                    QString path = _setting._pathImagesIconGames + game._img_icon_url + ".jpg";
                    QLabel *iconGame = new QLabel;
                    iconGame->setBaseSize(QSize(32, 32));
                    ui->TableWidgetGames->setCellWidget(setTo, 0, iconGame);
                    if(!QFile::exists(path)) {
                        if(game._img_icon_url != "") {
                            new RequestImage(iconGame, "http://media.steampowered.com/steamcommunity/public/images/apps/" +
                                            QString::number(game._appID) + "/" + game._img_icon_url + ".jpg", path, true, this);
                        }
                    } else {
                        iconGame->setPixmap(QPixmap(path));
                    }
                    ui->TableWidgetGames->setItem(setTo, 1, new QTableWidgetItem(game._name));
                    ui->TableWidgetGames->setRowHeight(setTo, 33);

                    QButtonWithData *button1 = new QButtonWithData(tr("Достижения"));
                    button1->setMinimumSize(QSize(25, 25));
                    button1->setObjectName("ButtonAchievements" + QString::number(indexHiddenGame) + "_" + QString::number(setTo));
                    button1->AddData("NumberFileHiddenGame", QString::number(indexHiddenGame));
                    button1->AddData("NumberHiddenGame", QString::number(setTo));
                    connect(button1, &QButtonWithData::pressed, this, &FormSettings::achievementsClicked);
                    ui->TableWidgetGames->setCellWidget(setTo, 2, button1);

                    QButtonWithData *button3 = new QButtonWithData("");
                    button3->setIcon(QIcon("://" + iconsColor + "/hide.png"));
                    button3->setMinimumSize(QSize(25, 25));
                    button3->setObjectName("ButtonHide" + QString::number(indexHiddenGame) + "_" + QString::number(game._appID));
                    button3->AddData("NumberFileHiddenGame", QString::number(indexHiddenGame));
                    button3->AddData("NumberHiddenGame", QString::number(game._appID));
                    connect(button3, &QButtonWithData::pressed, this, &FormSettings::hideClicked);
                    ui->TableWidgetGames->setCellWidget(setTo, 3, button3);
                }
            }
        } else {
            //list[0]=_games[gamei].GetAppid()
            //list[1]=_games[gamei].GetImg_icon_url()
            //list[2]=_games[gamei].GetName()
            for (int i = 0; i < currentGame.second.size(); i++) {
                QStringList list = currentGame.second[i].split("%%");
                QString path = _setting._pathImagesIconGames + list[1] + ".jpg";
                QLabel *iconGame = new QLabel;
                iconGame->setBaseSize(QSize(32, 32));
                ui->TableWidgetGames->setCellWidget(i, 0, iconGame);
                if(!QFile::exists(path)) {
                    if(list[1] != "") {
                        new RequestImage(iconGame, "http://media.steampowered.com/steamcommunity/public/images/apps/" + list[0] + "/" + list[1] + ".jpg", path, true, this);
                    }
                } else {
                    iconGame->setPixmap(QPixmap(path));
                }
                ui->TableWidgetGames->setItem(i, 1, new QTableWidgetItem(list[2]));

                ui->TableWidgetGames->setRowHeight(i, 33);
                QButtonWithData *button1 = new QButtonWithData(tr("Достижения"));
                button1->setMinimumSize(QSize(25, 25));
                button1->setObjectName("ButtonAchievements" + QString::number(indexHiddenGame) + "_" + QString::number(i));
                button1->AddData("NumberFileHiddenGame", QString::number(indexHiddenGame));
                button1->AddData("NumberHiddenGame", QString::number(i));
                connect(button1, &QButtonWithData::pressed, this, &FormSettings::achievementsClicked);
                ui->TableWidgetGames->setCellWidget(i, 2, button1);

                QButtonWithData *button3 = new QButtonWithData("");
                button3->setIcon(QIcon("://" + iconsColor + "/hide.png"));
                button3->setMinimumSize(QSize(25, 25));
                button3->setObjectName("ButtonHide" + QString::number(indexHiddenGame) + "_" + list[0]);
                button3->AddData("NumberFileHiddenGame", QString::number(indexHiddenGame));
                button3->AddData("NumberHiddenGame", list[0]);
                connect(button3, &QButtonWithData::pressed, this, &FormSettings::hideClicked);
                ui->TableWidgetGames->setCellWidget(i, 3, button3);
            }
        }
        ui->TableWidgetGames->resizeColumnsToContents();
    }
}

void FormSettings::achievementsClicked() {
    QButtonWithData *pb = dynamic_cast<QButtonWithData*>(sender());
    if (pb) {

    }
    //int index=pb->objectName().mid(11).toInt();

}

void FormSettings::hideClicked() {
    QButtonWithData *pb = dynamic_cast<QButtonWithData*>(sender());
    if (pb) {
        int index = pb->GetData(0).toInt();
        int gameIndex = -1;
        QMessageBox messageBox(QMessageBox::Question, tr("Внимание!"), tr("Сделать игру видимой?"));
        QAbstractButton *btnProfile = messageBox.addButton(tr("Да"), QMessageBox::YesRole);
        messageBox.addButton(tr("Отмена"), QMessageBox::NoRole);
        messageBox.exec();
        if(messageBox.clickedButton() != btnProfile) {
            return;
        }
        for(int i = 0; i < _hiddenGames[index].second.size(); i++) {
            QStringList lineList = _hiddenGames[index].second[i].split("%%");
            if(lineList[0] == pb->GetData(1)) {
                gameIndex = i;
                break;
            }
        }
        //QString save=_hiddenGames[index].first+".txt";
        _hiddenGames[index].second.removeAt(gameIndex);
        ui->TableWidgetGames->removeRow(gameIndex);
        QFile fileSaveTo(_setting._pathHide + _hiddenGames[index].first + ".txt");
        fileSaveTo.open(QIODevice::WriteOnly| QIODevice::Text);
        QTextStream writeStream(&fileSaveTo);
        for(QString game: _hiddenGames[index].second) {
            writeStream <<game + "\n";
        }
        fileSaveTo.close();
        QMessageBox(QMessageBox::Information, tr("Успешно!"), tr("Политика видимости для игры обновлена!"));
    }
}

void FormSettings::checkBoxSaveImage_StateChanged(int arg1) {
    _setting.setSaveimage(arg1 == 2);
    emit s_updateSettings();
}

void FormSettings::slideProfileSize_ValueChanged(int aValue) {
    _setting.setVisibleProfileInfo(aValue);
    emit s_updateSettings();
}
