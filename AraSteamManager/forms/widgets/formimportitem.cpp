#include "formimportitem.h"
#include "ui_formimportitem.h"

#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sprofile.h"
#include <QMessageBox>

FormImportItem::FormImportItem(QWidget *parent) :
QWidget(parent),
ui(new Ui::FormImportItem) {
    ui->setupUi(this);
}

FormImportItem::FormImportItem(ImportExportData *aImportData, QWidget *aParent): QWidget(aParent), ui(new Ui::FormImportItem), importData_(aImportData) {
    ui->setupUi(this);
    init();
}

FormImportItem::~FormImportItem() {
    disconnect(ui->pushButtonFindProfile, &QPushButton::clicked, this, &FormImportItem::findProfile);
    delete ui;
}

void FormImportItem::init() {
    ui->pushButtonFindProfile->setIcon(QIcon(Images::findProfile()));
    if (importData_ == nullptr) {
        return;
    }
    switch(importData_->type.type) {
    case ImportExportType::category: {
        ui->labelType->setText(tr("Категория"));
        IECategory *import = dynamic_cast<IECategory*>(importData_);
        if (import == nullptr) {
            return;
        }
        ui->labelIcon->setPixmap(SGame::pixmapIcon(import->gameId, import->category.gameIcon()));
        ui->labelTitle->setText(tr("Игра: %1\n"
                                   "Категория: %2").arg(import->gameName, import->category.title()));
        ui->frameProfile->setVisible(false);
        break;
    }
    case ImportExportType::favorite_game: {
        ui->labelType->setText(tr("Избранная игра"));
        if (auto favoriteGameImport = dynamic_cast<IEFavoriteGame*>(importData_)) {
            ui->labelIcon->setPixmap(favoriteGameImport->favorite.iconPixmap());
            ui->labelTitle->setText(tr("%1").arg(favoriteGameImport->favorite.name()));
            ui->frameProfile->setVisible(true);
        }
        break;
    }
    case ImportExportType::favorite_profile: {
        ui->labelType->setText(tr("Избранный профиль"));
        if (auto favoriteProfileImport = dynamic_cast<IEFavoriteProfile*>(importData_)) {
            ProfileID id = favoriteProfileImport->favorite.profileId();
            SProfile profile = SProfile::load(id);
            ui->labelIcon->setPixmap(profile.pixmapAvatar());
            ui->labelTitle->setText(tr("%1").arg(profile.personaName()));
            ui->frameProfile->setVisible(false);
        }
        break;
    }
    case ImportExportType::favorite_achievement: {
        ui->labelType->setText(tr("Избранное достижение"));
        if (auto favoriteAchievementImport = dynamic_cast<IEFavoriteAchievement*>(importData_)) {
            ui->labelIcon->setPixmap(SAchievementSchema::icon(favoriteAchievementImport->favorite.game().appId, favoriteAchievementImport->favorite.icon()));
            ui->labelTitle->setText(tr("Игра: %2\n"
                                       "Достижение: %1").arg(favoriteAchievementImport->favorite.title(), favoriteAchievementImport->favorite.game().name));
            ui->frameProfile->setVisible(true);
        }
        break;
    }
    case ImportExportType::comment_game: {
        ui->labelType->setText(tr("Комментарий к игре"));
        IECommentGame *import = dynamic_cast<IECommentGame*>(importData_);
        if (import == nullptr) {
            return;
        }
        ui->labelIcon->setPixmap(import->comment.gameIcon());
        QString comment = import->comment.comment().length() > 10 ? (import->comment.comment().join(" ").left(7) + "...") : import->comment.comment().join(" ");
        ui->labelTitle->setText(tr("Игра: %1\n"
                                   "Комментарий: %2").arg(import->comment.gameName(), comment));
        ui->frameProfile->setVisible(true);
        break;
    }
    case ImportExportType::comment_achievement: {
        ui->labelType->setText(tr("Комментарий к достижению"));
        IECommentAchievement *import = dynamic_cast<IECommentAchievement*>(importData_);
        if (import == nullptr) {
            return;
        }
        ui->labelIcon->setPixmap(SAchievementSchema::icon(import->comment.gameId(), import->comment.icon()));
        QString comment = import->comment.comment().length() > 10 ? (import->comment.comment().join(" ").left(7) + "...") : import->comment.comment().join(" ");
        ui->labelTitle->setText(tr("Игра: %2\n"
                                   "Достижение: %1\n"
                                   "Комментарий: %3").arg(import->comment.title(), import->comment.gameName(), comment));
        ui->frameProfile->setVisible(true);
        break;
    }
    case ImportExportType::group: {
        ui->labelType->setText(tr("Группа"));
        IEGroup *import = dynamic_cast<IEGroup*>(importData_);
        if (import == nullptr) {
            return;
        }
        ProfileID id = import->group.profileId();
        SProfile profile = SProfile::load(id);
        ui->labelIcon->setPixmap(profile.pixmapAvatar());
        ui->labelTitle->setText(tr("Профиль: %2\n"
                                   "Группа: %1").arg(import->group.title(), profile.personaName()));
        ui->frameProfile->setVisible(false);
        break;
    }
    case ImportExportType::settings: {
        ui->labelType->setText(tr("Настройки"));
        ui->labelIcon->setPixmap(QPixmap());
        ui->labelTitle->setText(tr("Настройки"));
        ui->frameProfile->setVisible(false);
        break;
    }
    case ImportExportType::unknown: {
        ui->labelType->setText(tr("Ошибка"));
        ui->labelIcon->setPixmap(QPixmap());
        ui->labelTitle->setText(tr("Ошибка"));
        ui->frameProfile->setVisible(false);
        break;
    }
    }
    initProfile();
}

void FormImportItem::initProfile() {
    ui->labelProfileIcon->setPixmap(QPixmap());
    ui->labelProfileName->setText(tr("Выберите профиль"));
    connect(ui->pushButtonFindProfile, &QPushButton::clicked, this, &FormImportItem::findProfile);
}

void FormImportItem::findProfile() {
    ProfileID id = ui->lineEditProfile->text();
    SProfile::LoadType type = identifyProfileType(id);
    if (type == SProfile::LoadType::unknown) {
        qWarning() << "Не распознан профиль" << ui->lineEditProfile->text();
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось распознать синтаксис профиля"));
        return;
    }

    SProfile profile = SProfile::load(id, type);
    if(!profile.isNull()) {
        ui->labelProfileIcon->setPixmap(profile.pixmapAvatar());
        ui->labelProfileName->setText(profile.personaName());
        profileId_ = profile.steamId();
        if (importData_->type == ImportExportType::favorite_game) {
            if (auto data = dynamic_cast<IEFavoriteGame*>(importData_)) {
                data->favorite.steamId() = profileId_;
            }
        } else if (importData_->type == ImportExportType::comment_game) {
            if (auto data = dynamic_cast<IECommentGame*>(importData_)) {
                data->profile = profileId_;
            }
        }  else if (importData_->type == ImportExportType::comment_achievement) {
            if (auto data = dynamic_cast<IECommentAchievement*>(importData_)) {
                data->profile = profileId_;
            }
        }
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Нет данных о профиле!"));
        qWarning() << "profileError";
    }
}

bool FormImportItem::isChecked() {
    return ui->checkBox->isChecked();
}

bool FormImportItem::isNeedProfile() {
    if (!importData_) {
        return false;
    }
    if (importData_->type == ImportExportType::favorite_game ||
        importData_->type == ImportExportType::comment_game ||
        importData_->type == ImportExportType::comment_achievement) {
        return true;
    }
    return false;
}

bool FormImportItem::isProfileSelected() {
    return !profileId_.isEmpty();
}

ImportExportData *FormImportItem::importData() {
    return importData_;
}
