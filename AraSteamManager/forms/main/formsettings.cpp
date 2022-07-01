#include "formsettings.h"
#include "ui_formsettings.h"

#include "version.h"
#include "classes/steamApi/sapi.h"
#include "classes/common/theme.h"

#include <QColorDialog>

FormSettings::FormSettings(QWidget *aParent): Form(aParent), ui(new Ui::FormSettings) {
    ui->setupUi(this);
}

FormSettings::~FormSettings() {
    delete ui;
}

bool FormSettings::isInit() {
    return isInit_;
}

bool FormSettings::isLoaded() {
    return isInit_;
}

void FormSettings::init() {
    initCommonSettings();
    initExport();
    ui->tabWidget->setAttribute(Qt::WA_TranslucentBackground);

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
                SProfile profile = SProfile::load(fileName.remove(".txt"), SProfile::LoadType::id);
                QList<QString> hide;
                QRadioButtonWithData *profileHidden = new QRadioButtonWithData;
                profileHidden->setText(profile.personaName());
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
    connect(ui->ComboBoxTheme,              SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxThemeIndexChanged(int)));
    connect(ui->ComboBoxLanguage,           SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxLanguageIndexChanged(int)));

    connect(ui->comboBoxProfileInfo,        SIGNAL(currentIndexChanged(int)), this, SLOT(slideProfileSize_ValueChanged(int)));
    //connect(ui->ComboBoxMaxRows,            SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxMaxTableRows(int)));

    connect(ui->ButtonExportCategories, &QPushButton::clicked, this, &FormSettings::buttonExportCategories_Clicked);
    connect(ui->ButtonImportCategories, &QPushButton::clicked, this, &FormSettings::buttonImportCategories_Clicked);
    connect(this, &Form::s_settingsUpdated, ui->lineEdit_2, &MyLineEdit::updateSettings);
    connect(this, &Form::s_settingsUpdated, ui->lineEdit_3, &MyLineEdit::updateSettings);
    connect(this, &Form::s_settingsUpdated, ui->lineEdit_4, &MyLineEdit::updateSettings);
    connect(this, &Form::s_settingsUpdated, ui->lineEdit_5, &MyLineEdit::updateSettings);
    connect(this, &Form::s_settingsUpdated, ui->LineEditFindGame, &MyLineEdit::updateSettings);
    connect(this, &Form::s_settingsUpdated, ui->LineEditImportCategories, &MyLineEdit::updateSettings);
#define ConnectsEnd }
    retranslate();
    isInit_ = true;
}

void FormSettings::initCommonSettings() {
    ui->comboBoxProfileInfo->addItems(QStringList {tr("Минимум"), tr("Обычные"), tr("Максимум")});
    ui->tabWidget->setCurrentIndex(0);

    ui->labelVersion->setText(VER_PRODUCTVERSION_STR);

    ui->ComboBoxLanguage->addItems(QStringList {tr("English"), tr("Русский")});
    switch (Settings::language()) {
    case 1: {
        ui->ComboBoxLanguage->setCurrentIndex(0);
        break;
    }
    case 5: {
        ui->ComboBoxLanguage->setCurrentIndex(1);
        break;
    }
    default: {
        break;
    }
    }
    ui->ComboBoxTheme->addItems(QStringList {tr("Тёмная"), tr("Светлая"), tr("Синяя"), tr("Оранжевая"), tr("Малиновая"), tr("Лаймовая"), tr("Фиолетовая"), tr("Зеленая"), tr("Пользовательская")});
    ui->ComboBoxTheme->setItemData(0, blackTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(1, whiteTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(2, blueTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(3, orangeTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(4, crimsonTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(5, limeTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(6, purpleTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(7, greenTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(8, QColor(255, 255, 255, 20), Qt::DecorationRole);
    switch (Settings::theme()) {
    case 0: {
        ui->ComboBoxTheme->setCurrentIndex(8);
        break;
    }
    case 1: {
        ui->ComboBoxTheme->setCurrentIndex(2);
        break;
    }
    case 2: {
        ui->ComboBoxTheme->setCurrentIndex(1);
        break;
    }
    case 3: {
        ui->ComboBoxTheme->setCurrentIndex(0);
        break;
    }
    case 4: {
        ui->ComboBoxTheme->setCurrentIndex(3);
        break;
    }
    case 5: {
        ui->ComboBoxTheme->setCurrentIndex(4);
        break;
    }
    case 6: {
        ui->ComboBoxTheme->setCurrentIndex(5);
        break;
    }
    case 7: {
        ui->ComboBoxTheme->setCurrentIndex(6);
        break;
    }
    case 8: {
        ui->ComboBoxTheme->setCurrentIndex(7);
        break;
    }
    default: {
        break;
    }
    }
    ui->comboBoxProfileInfo->setCurrentIndex(Settings::profileInfoSize());
    ui->labelIcons8->setTextFormat(Qt::RichText);
//    QPalette darkPalette;
//    darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(73, 73, 73),Qt::white,Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
    //                        тип               ,???      ,Кнопка            ,Разделители,???      ,???     ,цвет текста на кнопке,???  ,поле сзади     ,???
    //ui->GroupBoxDarkTheme->setPalette(darkPalette);
    //ui->GroupBoxWhiteTheme->setPalette(style()->standardPalette());

}

void FormSettings::initExport() {
    ui->TreeWidgetExportCategories->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

    QDir dir(Paths::categories());
    for (auto &file: dir.entryInfoList(QDir::Files)) {
        QFile fileCategory(file.filePath());
        if (fileCategory.exists()) {
            if(fileCategory.open(QFile::ReadOnly)) {
                Category game(QJsonDocument().fromJson(fileCategory.readAll()).object());
                game.update();
                QTreeWidgetItem *item = new QTreeWidgetItem(ui->TreeWidgetExportCategories, QStringList() << game.gameName());
                item->setWhatsThis(0, QString::number(game.gameID()));
//                item->setWhatsThis(1, QString::number(-2));
                ui->TreeWidgetExportCategories->addTopLevelItem(item);
                for (auto &category: game.categories()) {
                    recursAddCategoryToTree(category, item, game.gameID());
                }
                fileCategory.close();
            }
        }
    }
}

int FormSettings::recursAddCategoryToTree(Category *aCategory, QTreeWidgetItem *aRoot, const int &aGameId) {
    QTreeWidgetItem *subItem;
    if (aRoot == nullptr) {
        subItem = new QTreeWidgetItem(ui->TreeWidgetExportCategories, QStringList() << aCategory->title());
    } else {
        subItem = new QTreeWidgetItem(aRoot, QStringList() << aCategory->title());
    }
    subItem->setWhatsThis(0,QString::number(aGameId));
//    subItem->setWhatsThis(1,QString::number(aCategory->order()));
    for(auto subCategory: aCategory->categories()) {
        recursAddCategoryToTree(subCategory, subItem, aGameId);
    }
    return 0;
}

void FormSettings::comboBoxThemeIndexChanged(int aIndex) {
    switch (aIndex) {
    case 0: {
        Settings::setTheme(3);
        break;
    }
    case 1: {
        Settings::setTheme(2);
        break;
    }
    case 2: {
        Settings::setTheme(1);
        break;
    }
    case 3: {
        Settings::setTheme(4);
        break;
    }
    case 4: {
        Settings::setTheme(5);
        break;
    }
    case 5: {
        Settings::setTheme(6);
        break;
    }
    case 6: {
        Settings::setTheme(7);
        break;
    }
    case 7: {
        Settings::setTheme(8);
        break;
    }
    case 8: {
        QColor themeColor = QColorDialog::getColor(Qt::white, this, tr("Выберите цвет"));
        customTheme(themeColor).save(Paths::documents() + "theme\\custom.json");
        Settings::setTheme(0);
        break;
    }
    default: {
        break;
    }
    }
    emit s_settingsUpdated(changedSettings::theme);
}

void FormSettings::comboBoxLanguageIndexChanged(int aIndex) {
    switch (aIndex) {
    case 0: {
        Settings::setLanguage(1);
        emit s_settingsUpdated(changedSettings::language);
        QTranslator *translator = new QTranslator;
        if (translator->load(":/AraSteamManager_en.qm")) {
            qApp->installTranslator(translator);
            ui->retranslateUi(this);
        } else {
            qWarning() << "error change language";
        }
        break;
    }
    case 1: {
        Settings::setLanguage(5);
        emit s_settingsUpdated(changedSettings::language);
        QTranslator *translator = new QTranslator;
        if (translator->load(":/AraSteamManager_ru.qm")) {
            qApp->installTranslator(translator);
            ui->retranslateUi(this);
        } else {
            qWarning() << "error change language";
        }
        break;
    }
    default: {
        break;
    }
    }
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
//    QJsonArray jArray;
//    for (auto &item: ui->TreeWidgetExportCategories->selectedItems()) {
//        Category2 categories(item->whatsThis(0).toInt());
//        int categoryOrder = item->whatsThis(1).toInt();
//        if (categoryOrder == -2) {
//            for (auto category: categories) {
//                ExportCategory eCategory(categories.gameID(), categories.game(), *category);
//                jArray.append(eCategory.toJson());
//            }
//        } else {
//            Category2 *category = categories.findCategory(categoryOrder);
//            if (category != nullptr) {
//                ExportCategory eCategory(categories.gameID(), categories.game(), *category);
//                jArray.append(eCategory.toJson());
//            }
//        }
//    }
//    ExportFileData efd;
//    efd.data = jArray;
//    efd.type = ExportType::categories;
//    efd.version = 1.0;
//    efd.date = QDateTime::currentDateTime();
//    return efd;
}

ExportFileData *FormSettings::getFileFromPath(QLineEdit *aLineEdit) {
    QString path;
    if (aLineEdit->text() == "") {
        path = QFileDialog::getOpenFileName(this, tr("Выбор файла для загрузки"), "", "*");
        if (path == "") {
            return nullptr;
        }
    } else {
        path = aLineEdit->text();
    }
    QFile fFile(path);
    if (!fFile.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("Невозможно найти указанный файл, или файл открыт в другом приложении!"));
        return nullptr;
    }
    ExportFileData *efd = new ExportFileData(ExportFileData::fromJson(QJsonDocument::fromJson(fFile.readAll()).object()));
    fFile.close();
    return efd;
}

void FormSettings::buttonImportCategories_Clicked() {
    ExportFileData *fileData = getFileFromPath(ui->LineEditImportCategories);
    if (fileData == nullptr) {
        return;
    }

    if (fileData->type != ExportType::categories) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("В выбранном файле нет категорий"));
        return;
    }

    QVector<ExportCategory> eCategories;
    for(const auto &category: fileData->data.toArray()) {
        eCategories.append(ExportCategory(category.toObject()));
    }

    if (eCategories.size() == 0) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("В выбранном файле не обнаружено категорий"));
        return;
    }

    QStringList slCategories;
    for (auto &category: eCategories) {
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
    for(const auto &eCategory: eCategories) {
        GameID gameId = eCategory.gameId;
        QString gameName = eCategory.gameName;
        Category categories(gameId, gameName);
        categories.addCategory(new Category(eCategory.category));
        categories.save();
    }
    QMessageBox::information(this, tr("Внимание!"), tr("Категории успешно добавлены!"));
}

void FormSettings::retranslate() {
    ui->retranslateUi(this);
    ui->ComboBoxTheme->setItemText(0, tr("Тёмная"));
    ui->ComboBoxTheme->setItemText(1, tr("Светлая"));
    ui->ComboBoxTheme->setItemText(2, tr("Синяя"));
    ui->ComboBoxTheme->setItemText(3, tr("Оранжевая"));
    ui->ComboBoxTheme->setItemText(4, tr("Малиновая"));
    ui->ComboBoxTheme->setItemText(5, tr("Лаймовая"));
    ui->ComboBoxTheme->setItemText(6, tr("Фиолетовая"));
    ui->ComboBoxTheme->setItemText(7, tr("Зеленая"));
    ui->ComboBoxTheme->setItemText(8, tr("Пользовательская"));

    if (this->findChild<QRadioButtonWithData*>("HiddenGames0") != 0) {
        QRadioButtonWithData *allHidden = this->findChild<QRadioButtonWithData*>("HiddenGames0");
        allHidden->setText(tr("Все профили"));
    }
    ui->labelIcons8->setText(tr("<html>"
                                    "<head/>"
                                    "<body>"
                                        "<p>"
                                            "Иконки для приложения были предоставлены сайтом "
                                            "<a href=https://icons8.ru/icons>"
                                                "<span style=\" text-decoration: underline; color:#2d7fc8;\"> "
                                                    "https://icons8.ru/icons"
                                                "</span>"
                                            "</a>"
                                        "</p>"
                                    "</body>"
                                "</html>"));
}

void FormSettings::checkBoxVisibleHiddenGames_StateChanged(int arg1) {
    Settings::setVisibleHiddenGames(arg1 / 2);
    emit s_settingsUpdated(changedSettings::visibleHiddenGame);
}

void FormSettings::radioButtonHiddenGames_Clicked() {
    QRadioButtonWithData *rbSender = dynamic_cast<QRadioButtonWithData*>(sender());
    if (rbSender) {
        int indexHiddenGame = rbSender->getData(0).toInt();
        auto &currentGame = _hiddenGames[indexHiddenGame];
        ui->TableWidgetGames->clear();
        ui->TableWidgetGames->setRowCount(currentGame.second.size());
        if(indexHiddenGame != 0) {
            SGames games = SGame::load(currentGame.first, true, true);
            for(auto &game: games) {
                if(currentGame.second.indexOf(QString::number(game.appId())) > -1) {
                    int setTo = currentGame.second.indexOf(QString::number(game.appId()));
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
                    button3->setObjectName("ButtonHide" + QString::number(indexHiddenGame) + "_" + QString::number(game.appId()));
                    button3->addData("NumberFileHiddenGame", QString::number(indexHiddenGame));
                    button3->addData("NumberHiddenGame", QString::number(game.appId()));
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
                        new RequestImageToLabel(iconGame, Sapi::gameImageUrl(list[0].toInt(), list[1]), path, true, true, this);
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
        fileSaveTo.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&fileSaveTo);
        foreach(const QString &game, _hiddenGames[index].second) {
            writeStream << game + "\n";
        }
        fileSaveTo.close();
        QMessageBox(QMessageBox::Information, tr("Успешно!"), tr("Политика видимости для игры обновлена!"));
    }
}

void FormSettings::checkBoxSaveImage_StateChanged(int arg1) {
    Settings::setSaveimage(arg1 == 2);
    emit s_settingsUpdated(changedSettings::saveImages);
}

void FormSettings::slideProfileSize_ValueChanged(int aValue) {
    Settings::setVisibleProfileInfo(aValue);
    emit s_settingsUpdated(changedSettings::profileInfo);
}

ExportCategory::ExportCategory(int aGameId, const QString &aGameName, const Category &aCategory):
gameId(aGameId), gameName(aGameName), category(aCategory) {

}

ExportCategory::ExportCategory(const QJsonObject &aObject) {
    fromJson(aObject);
}

ExportCategory::ExportCategory(const QString &aPathFile) {
    QFile file(aPathFile);
    if (file.open(QFile::ReadOnly)) {
        fromJson(QJsonDocument::fromJson(file.readAll()).object());
        file.close();
    }
}

void ExportCategory::fromJson(const QJsonObject &aObject) {
    gameId = aObject["gameId"].toInt();
    gameName = aObject["gameName"].toString();
    category = Category(aObject["category"].toObject());
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
    efd.date = QDateTime::fromString(aObject["date"].toString(), Settings::dateTimeFormat());
    return efd;
}

QJsonObject ExportFileData::toJson() {
    QJsonObject jObject;
    jObject["data"] = data;
    jObject["type"] = exportTypeToString(type);
    jObject["version"] = QString::number(version);
    jObject["date"] = date.toString(Settings::dateTimeFormat());
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
    return "";
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
