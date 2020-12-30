#include "formsettings.h"
#include "ui_formsettings.h"

FormSettings::FormSettings(QWidget *aParent): QWidget(aParent), ui(new Ui::FormSettings) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    initComponents();
}

FormSettings::~FormSettings() {
    qInfo() << "Форма настроек удалилась";
    delete ui;
}

bool FormSettings::isInit() {
    return true;
}

bool FormSettings::isLoaded() {
    return true;
}

void FormSettings::initComponents() {
    //ui->ComboBoxMaxRows->addItems(QStringList()<<"10"<<"20"<<"50"<<"100"<<"200"<<"500");

    ui->tabWidget->setCurrentIndex(0);

    initExport();
    switch (Settings::language()) {
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
    switch (Settings::visibleHiddenGames()) {
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
    switch (Settings::theme()) {
    case 1: {
        ui->RadioButtonBlueTheme->setChecked(true);
        break;
    }
    case 2: {
        ui->RadioButtonLightTheme->setChecked(true);
        break;
    }
    case 3: {
        ui->RadioButtonDarkTheme->setChecked(true);
        break;
    }
    default: {
        break;
    }
    }
//    switch (_setting.getMaximumTableRows()) {
//    case 10: {
//        ui->ComboBoxMaxRows->setCurrentIndex(0);
//        break;
//    }
//    case 20: {
//        ui->ComboBoxMaxRows->setCurrentIndex(1);
//        break;
//    }
//    case 50: {
//        ui->ComboBoxMaxRows->setCurrentIndex(2);
//        break;
//    }
//    case 100: {
//        ui->ComboBoxMaxRows->setCurrentIndex(3);
//        break;
//    }
//    case 200: {
//        ui->ComboBoxMaxRows->setCurrentIndex(4);
//        break;
//    }
//    case 500: {
//        ui->ComboBoxMaxRows->setCurrentIndex(5);
//        break;
//    }
//    }
    ui->SliderProfileSize->setValue(Settings::profileInfoSize());
    ui->CheckBoxSaveImage->setChecked(Settings::saveImages());
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
    QDir dirHiddenGames(Paths::hiddenGames());
    dirHiddenGames.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dirHiddenGames.setSorting(QDir::Name);
    if(dirHiddenGames.exists()){
        QPair<QString,QList<QString>> pair;
        pair.first = "All";
        pair.second = QList<QString>();
        if(QFile(Paths::hiddenGames("All")).exists()) {
            QRadioButtonWithData *allHidden = new QRadioButtonWithData;
            allHidden->setText(tr("Все профили"));
            allHidden->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
            allHidden->setObjectName("HiddenGames0");
            allHidden->addData("NumberFileHiddenGame","0");
            connect(allHidden, SIGNAL(clicked()), this, SLOT(radioButtonHiddenGames_Clicked()));
            layout->addWidget(allHidden);
            QFile fileHide1(Paths::hiddenGames("All"));
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
        for(auto &file: list) {
            QString fileName = file.fileName();
            if(fileName != "All.txt") {
                QFile fileHide(Paths::hiddenGames(fileName));
                fileHide.open(QFile::ReadOnly);
                SProfiles profile(fileName.remove(".txt"), false, ProfileUrlType::id);
                QList<QString> hide;
                QRadioButtonWithData *profileHidden = new QRadioButtonWithData;
                profileHidden->setText(profile[0].personaName());
                profileHidden->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
                profileHidden->setObjectName("HiddenGames" + QString::number(number));
                profileHidden->addData("NumberFileHiddenGame", QString::number(number));
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
                ++number;
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
    connect(ui->RadioButtonBlueTheme,       &QRadioButton::clicked,   this, &FormSettings::radioButtonBlueTheme_Clicked);
    connect(ui->CheckBoxSaveImage,          &QCheckBox::stateChanged, this, &FormSettings::checkBoxSaveImage_StateChanged);
    connect(ui->SliderProfileSize,          &QSlider::valueChanged,   this, &FormSettings::slideProfileSize_ValueChanged);
    //connect(ui->ComboBoxMaxRows,            SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxMaxTableRows(int)));

    connect(ui->ButtonExportCategories, &QPushButton::clicked, this, &FormSettings::buttonExportCategories_Clicked);
    connect(ui->ButtonImportCategories, &QPushButton::clicked, this, &FormSettings::buttonImportCategories_Clicked);
#define ConnectsEnd }
    retranslate();
}

void FormSettings::initExport() {
    ui->TreeWidgetExportCategories->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

    QDir dir(Paths::categories());
    for (auto &file: dir.entryInfoList(QDir::Files)) {
        QFile fileCategory(file.filePath());
        if (fileCategory.exists()) {
            if(fileCategory.open(QFile::ReadOnly)) {
                auto s = fileCategory.readAll();
                Categories game(QJsonDocument().fromJson(s).object());
                QTreeWidgetItem *item = new QTreeWidgetItem(ui->TreeWidgetExportCategories, QStringList() << game.game());
                item->setWhatsThis(0, QString::number(game.gameID()));
                item->setWhatsThis(1, QString::number(-2));
                ui->TreeWidgetExportCategories->addTopLevelItem(item);
                int count = -2;
                for (auto &category: game) {
                    count = recursAddCategoryToTree(category, ++count, item, game.gameID());
                }
                fileCategory.close();
            }
        }
    }
}

int FormSettings::recursAddCategoryToTree(Category &aCategory, int aCount, QTreeWidgetItem *aRoot, const int &aGameId) {
    QTreeWidgetItem *subItem;
    if (aRoot == nullptr) {
        subItem = new QTreeWidgetItem(ui->TreeWidgetExportCategories, QStringList() << aCategory.title());
    } else {
        subItem = new QTreeWidgetItem(aRoot, QStringList() << aCategory.title());
    }
    subItem->setWhatsThis(0,QString::number(aGameId));
    subItem->setWhatsThis(1,QString::number(aCount + 1));
    for(auto &subCategory: aCategory) {
        aCount = recursAddCategoryToTree(subCategory, ++aCount, subItem, aGameId);
    }
    return aCount;
}

void FormSettings::buttonExportCategories_Clicked() {
    QString sFile = QFileDialog::getSaveFileName(this, tr("Место сохранения файла"), "", ".sas");
    if (sFile == "") {
        return;
    }
    ExportFileData exportData = createExportCategoriesJson();
    if (sFile.left(4) != ".sas") {
        sFile += ".sas";
    }
    QFile fFile(sFile);
    fFile.open(QFile::WriteOnly);
    fFile.write(QJsonDocument(exportData.toJson()).toJson());
    fFile.close();
    QMessageBox::information(this, tr("Успешно!"), tr("Файл успешно создан!"));
}

ExportFileData FormSettings::createExportCategoriesJson() {
    QJsonArray jArray;
    for (auto &item: ui->TreeWidgetExportCategories->selectedItems()) {
        Categories categories(item->whatsThis(0).toInt());
        int index = item->whatsThis(1).toInt();
        if (index == -2) {
            for (auto &category: categories) {
                ExportCategory eCategory {categories.gameID(), categories.game(), category};
                jArray.append(eCategory.toJson());
            }
        } else {
            Category *category = categories.categoryAtDirect(index);
            if (category != nullptr) {
                ExportCategory eCategory {categories.gameID(), categories.game(), *category};
                jArray.append(eCategory.toJson());
            }
        }
    }
    ExportFileData efd;
    efd.data = jArray;
    efd.type = ExportType::categories;
    efd.version = 1.0;
    efd.date = QDateTime::currentDateTime();
    return efd;
}

void FormSettings::buttonImportCategories_Clicked() {
    QString path;
    if (ui->LineEditImportCategories->text() == "") {
        path = QFileDialog::getOpenFileName(this, tr("Выбор файла для загрузки"), "", "*");
        if (path == "") {
            return;
        }
    } else {
        path = ui->LineEditImportCategories->text();
    }
    QFile fFile(path);
    if (!fFile.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("Невозможно найти указанный файл, или файл открыт в другом приложении!"));
        return;
    }
    ExportFileData efd = ExportFileData::fromJson(QJsonDocument::fromJson(fFile.readAll()).object());
    fFile.close();

    if (efd.type != ExportType::categories) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("В выбранном файле нет категорий"));
        return;
    }

    QList<ExportCategory> exportCategories;
    for (auto category: efd.data.toArray()) {
        exportCategories.append(std::move(ExportCategory::fromJson(category.toObject())));
    }

    if (exportCategories.size() == 0) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("В выбранном файле не обнаружено категорий"));
        return;
    }

    QStringList slCategories;
    for (auto &category: exportCategories) {
        slCategories.append(tr("Игра: %1, категория: %2").arg(category.gameName, category.category.title()));
    }
    QString questionText = tr("Обнаружены следующие категории: \n") + slCategories.join("\n") + ".";

    QMessageBox question(QMessageBox::Question,
                           tr("Внимание!"),
                           questionText);
    QAbstractButton *btnYes = question.addButton(tr("Добавить эти категории"), QMessageBox::YesRole);
    question.addButton(tr("Отмена"), QMessageBox::NoRole);
    question.exec();
    if(question.clickedButton() != btnYes) {
        return;
    }
    //Обновить категории
    for (auto eCategory: exportCategories) {
        int gameId = eCategory.gameId;
        Category category = eCategory.category;
        Categories categories(gameId);
        categories.addCategory(category);
        categories.save(categories.toJson());
    }
    QMessageBox::information(this, tr("Внимание!"), tr("Категории успешно добавлены!"));
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
    ui->labelIcons8->setText("<html><head/><body><p>"
                             "Иконки для приложения были предоставлены сайтом "
                             "<img height=15 style=\"vertical-align: top\" src=\"" + Images::link() + "\">"
                            "<a href=https://icons8.ru/icons>"
                            "<span style=\" text-decoration: underline; color:#2d7fc8;\"> "
                            "https://icons8.ru/icons"
                            "</span></a></p></body></html>");
}

void FormSettings::radioButtonLanguageEnglish_Clicked() {
    Settings::setLanguage(1);
    emit s_updateSettings();
    QTranslator *translator = new QTranslator;
    translator->load(":/AraSteamManager_en.qm");
    qApp->installTranslator(translator);
    ui->retranslateUi(this);
    //QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::radioButtonLanguageRussian_Clicked() {
    Settings::setLanguage(5);
    emit s_updateSettings();
    QTranslator *translator = new QTranslator;
    translator->load(":/AraSteamManager_ru.qm");
    qApp->installTranslator(translator);
    ui->retranslateUi(this);
    //QMessageBox::information(this,tr("Язык изменён"),tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::checkBoxVisibleHiddenGames_StateChanged(int arg1) {
    Settings::setVisibleHiddenGames(arg1 / 2);
    emit s_updateSettings();
}

void FormSettings::radioButtonDarkTheme_Clicked() {
    Settings::setTheme(3);
    emit s_updateSettings();
    //QMessageBox::information(this, tr("Тема изменена"), tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::radioButtonLightTheme_Clicked() {
    Settings::setTheme(2);
    emit s_updateSettings();
    //QMessageBox::information(this, tr("Тема изменена"), tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::radioButtonBlueTheme_Clicked() {
    Settings::setTheme(1);
    emit s_updateSettings();
    //QMessageBox::information(this, tr("Тема изменена"), tr("Для применения изменений перезапустите приложение!"));
}

void FormSettings::radioButtonHiddenGames_Clicked() {
    QRadioButtonWithData *rbSender = dynamic_cast<QRadioButtonWithData*>(sender());
    if (rbSender) {
        int indexHiddenGame = rbSender->getData(0).toInt();
        auto &currentGame = _hiddenGames[indexHiddenGame];
        ui->TableWidgetGames->clear();
        ui->TableWidgetGames->setRowCount(currentGame.second.size());
        if(indexHiddenGame != 0) {
            SGames games(currentGame.first, true, true, false);
            for(auto &game: games) {
                if(currentGame.second.indexOf(game.sAppId()) > -1) {
                    int setTo = currentGame.second.indexOf(game.sAppId());
                    QLabel *iconGame = new QLabel;
                    iconGame->setBaseSize(QSize(32, 32));
                    iconGame->setPixmap(game.pixmapIcon());
                    ui->TableWidgetGames->setCellWidget(setTo, 0, iconGame);
                    ui->TableWidgetGames->setItem(setTo, 1, new QTableWidgetItem(game.name()));
                    ui->TableWidgetGames->setRowHeight(setTo, 33);

                    QButtonWithData *button1 = new QButtonWithData(tr("Достижения"));
                    button1->setMinimumSize(QSize(25, 25));
                    button1->setObjectName("ButtonAchievements" + QString::number(indexHiddenGame) + "_" + QString::number(setTo));
                    button1->addData("NumberFileHiddenGame", QString::number(indexHiddenGame));
                    button1->addData("NumberHiddenGame", QString::number(setTo));
                    connect(button1, &QButtonWithData::pressed, this, &FormSettings::achievementsClicked);
                    ui->TableWidgetGames->setCellWidget(setTo, 2, button1);

                    QButtonWithData *button3 = new QButtonWithData("");
                    button3->setIcon(QIcon(Images::hide()));
                    button3->setMinimumSize(QSize(25, 25));
                    button3->setObjectName("ButtonHide" + QString::number(indexHiddenGame) + "_" + game.sAppId());
                    button3->addData("NumberFileHiddenGame", QString::number(indexHiddenGame));
                    button3->addData("NumberHiddenGame", game.sAppId());
                    connect(button3, &QButtonWithData::pressed, this, &FormSettings::hideClicked);
                    ui->TableWidgetGames->setCellWidget(setTo, 3, button3);
                }
            }
        } else {
            //list[0]=_games[gamei].GetAppid()
            //list[1]=_games[gamei].GetImg_icon_url()
            //list[2]=_games[gamei].GetName()
            for (int i = 0; i < currentGame.second.size(); ++i) {
                QStringList list = currentGame.second[i].split("%%");
                QString path = Paths::imagesGames(list[1]);
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
                button1->addData("NumberFileHiddenGame", QString::number(indexHiddenGame));
                button1->addData("NumberHiddenGame", QString::number(i));
                connect(button1, &QButtonWithData::pressed, this, &FormSettings::achievementsClicked);
                ui->TableWidgetGames->setCellWidget(i, 2, button1);

                QButtonWithData *button3 = new QButtonWithData("");
                button3->setIcon(QIcon(Images::hide()));
                button3->setMinimumSize(QSize(25, 25));
                button3->setObjectName("ButtonHide" + QString::number(indexHiddenGame) + "_" + list[0]);
                button3->addData("NumberFileHiddenGame", QString::number(indexHiddenGame));
                button3->addData("NumberHiddenGame", list[0]);
                connect(button3, &QButtonWithData::pressed, this, &FormSettings::hideClicked);
                ui->TableWidgetGames->setCellWidget(i, 3, button3);
            }
        }
        ui->TableWidgetGames->resizeColumnsToContents();
    }
}

void FormSettings::comboBoxMaxTableRows(int index) {
    Q_UNUSED(index);
//    _setting.setMaximumTableRows(ui->ComboBoxMaxRows->currentText().toInt());
//    emit s_updateSettings();
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
        int index = pb->getData(0).toInt();
        int gameIndex = -1;
        QMessageBox messageBox(QMessageBox::Question, tr("Внимание!"), tr("Сделать игру видимой?"));
        QAbstractButton *btnProfile = messageBox.addButton(tr("Да"), QMessageBox::YesRole);
        messageBox.addButton(tr("Отмена"), QMessageBox::NoRole);
        messageBox.exec();
        if(messageBox.clickedButton() != btnProfile) {
            return;
        }
        for(int i = 0; i < _hiddenGames[index].second.size(); ++i) {
            QStringList lineList = _hiddenGames[index].second[i].split("%%");
            if(lineList[0] == pb->getData(1)) {
                gameIndex = i;
                break;
            }
        }
        //QString save=_hiddenGames[index].first+".txt";
        _hiddenGames[index].second.removeAt(gameIndex);
        ui->TableWidgetGames->removeRow(gameIndex);
        QFile fileSaveTo(Paths::hiddenGames(_hiddenGames[index].first));
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
    Settings::setSaveimage(arg1 == 2);
    emit s_updateSettings();
}

void FormSettings::slideProfileSize_ValueChanged(int aValue) {
    Settings::setVisibleProfileInfo(aValue);
    emit s_updateSettings();
}

ExportCategory ExportCategory::fromJson(QJsonObject aObject) {
    return ExportCategory{aObject["gameId"].toInt(), aObject["gameName"].toString(), Category(aObject["category"].toObject())};
}

QJsonObject ExportCategory::toJson() {
    QJsonObject jObj;
    jObj["category"] = category.toJson();
    jObj["gameName"] = gameName;
    jObj["gameId"] = gameId;
    return jObj;
}

ExportFileData ExportFileData::fromJson(QJsonObject aObject) {
    ExportFileData efd;
    efd.data = aObject["data"];
    efd.type = stringToExportType(aObject["type"].toString());
    efd.version = aObject["version"].toString().toDouble();
    efd.date = QDateTime::fromString(aObject["date"].toString(), "yyyy.MM.dd hh:mm:ss");
    return efd;
}

QJsonObject ExportFileData::toJson() {
    QJsonObject jObject;
    jObject["data"] = data;
    jObject["type"] = exportTypeToString(type);
    jObject["version"] = QString::number(version);
    jObject["date"] = date.toString("yyyy.MM.dd hh:mm:ss");
    return jObject;
}

QString exportTypeToString(ExportType aType) {
    switch (aType) {
    case ExportType::unknown: {
        return "unknown";
    }
    case ExportType::categories: {
        return "categories";
    }
    case ExportType::favorites: {
        return "favorites";
    }
    case ExportType::comments: {
        return "comments";
    }
    case ExportType::groups: {
        return "groups";
    }
    case ExportType::multiple: {
        return "multiple";
    }
    }
}

ExportType stringToExportType(QString aType) {
    if (aType == "categories") {
        return ExportType::categories;
    } else if (aType == "favorites") {
        return ExportType::favorites;
    } else if (aType == "comments") {
        return ExportType::comments;
    } else if (aType == "groups") {
        return ExportType::groups;
    }  else if (aType == "multiple") {
        return ExportType::multiple;
    } else {
        return ExportType::unknown;
    }
}
