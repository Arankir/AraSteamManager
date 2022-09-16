#include "formcategoriesedit.h"
#include "ui_formcategoriesedit.h"
#include "classes/common/images.h"

#include <QMessageBox>

FormCategoriesEdit::FormCategoriesEdit(QWidget *aParent) : Form(aParent), ui(new Ui::FormCategoriesEdit) {
    ui->setupUi(this);
    init();
}

FormCategoriesEdit::~FormCategoriesEdit() {
    delete ui;
}

void FormCategoriesEdit::setAchievements(const SAchievements &aAchievements, const GameID &aGameId) {
    gameId_ = aGameId;
    achievements_ = aAchievements;
    achievementsToUi();
}

void FormCategoriesEdit::setVisibleItems(const QList<QString> &aItems) {
    visibleAchievements_ = aItems;
    updateHiddenItems();
}

void FormCategoriesEdit::achievementsToUi() {
    ui->ListWidgetAll->clear();
    ui->ListWidgetCategory->clear();
    for (auto &achievement: achievements_) {
        ui->ListWidgetAll->insertAchievement(achievement, gameId_);
    }
}

void FormCategoriesEdit::init() {
    ui->ListWidgetAll->setDropIndicatorShown(true);
    ui->ListWidgetAll->setDragEnabled(true);
    ui->ListWidgetAll->setDragDropMode(QAbstractItemView::DragDrop);
    ui->ListWidgetAll->setDefaultDropAction(Qt::DropAction::MoveAction);
    ui->ListWidgetAll->setWordWrap(true);

    ui->ListWidgetCategory->setDropIndicatorShown(true);
    ui->ListWidgetCategory->setDragEnabled(true);
    ui->ListWidgetCategory->setDragDropMode(QAbstractItemView::DragDrop);
    ui->ListWidgetCategory->setDefaultDropAction(Qt::DropAction::MoveAction);
    ui->ListWidgetCategory->setWordWrap(true);

    updateIcons();
#define Connects {
    connect(ui->ButtonCancelCategory,       &QPushButton::clicked,  this, &FormCategoriesEdit::buttonCancel_Clicked);
    connect(ui->ButtonAcceptCategory,       &QPushButton::clicked,  this, &FormCategoriesEdit::buttonAccept_Clicked);
#define ConnectsEnd }
}

//void FormCategoriesEdit::updateSettings(QFlags<changedSettings> aSettings) {
//    updateIcons();
//    emit s_settingsUpdated(aSettings);
//}

void FormCategoriesEdit::updateIcons() {
    ui->ButtonAcceptCategory->setIcon(QIcon(Images::apply()));
    ui->ButtonCancelCategory->setIcon(QIcon(Images::cancel()));
}

void FormCategoriesEdit::retranslate() {
    ui->retranslateUi(this);
}

int FormCategoriesEdit::indexFromRow(QListWidget *aListWidget, const int &aRow) {
    if (QListWidgetAchievement *achievement = dynamic_cast<QListWidgetAchievement*>(aListWidget->item(aRow))) {
        const QString apiName = achievement->achievement_->apiName();
        auto iterator = std::find_if(achievements_.begin(),
                                     achievements_.end(),
                                     [=](const SAchievement &achievement) {
                                        return achievement.apiName() == apiName;
                                     });
        if (iterator != achievements_.end()) {
            return iterator - achievements_.begin();
        }
    }
    return -1;
}

void FormCategoriesEdit::updateHiddenItems() {
    for(int row = 0; row < ui->ListWidgetAll->count(); ++row) {
        auto achievement = dynamic_cast<QListWidgetAchievement*>(ui->ListWidgetAll->item(row));
        if (achievement != nullptr) {
            QString apiName = achievement->achievement_->apiName();
            bool isVisible = std::any_of(visibleAchievements_.begin(),
                                        visibleAchievements_.end(),
                                        [=](const QString &api) {
                                            return api == apiName;
                                        });
            ui->ListWidgetAll->setRowHidden(row, !isVisible);
        }

    }
}

void FormCategoriesEdit::changeCategory(Category *aCategory) {
    currentCategory_ = aCategory;
    ui->labelCategoryTitle->setText(currentCategory_->title());
    ui->ListWidgetAll->clear();
    ui->ListWidgetCategory->clear();
    auto achievementList = static_cast<QSet<AchievementID> >(*aCategory);
    for(auto &achievement: achievements_) {
        bool isInCategory = std::any_of(achievementList.begin(),
                                        achievementList.end(),
                                        [=](const AchievementID &aAchievement) {
                                            return aAchievement == achievement.apiName();
                                        });
        if (isInCategory) {
            ui->ListWidgetCategory->insertAchievement(achievement, gameId_);
        } else {
            ui->ListWidgetAll->insertAchievement(achievement, gameId_);
        }
    }
}

#define Categorys {
void FormCategoriesEdit::buttonCancel_Clicked() {
    achievementsToUi();
}

void FormCategoriesEdit::buttonAccept_Clicked() {
    if (currentCategory_ == nullptr) {
        qWarning() << "on apply category does not exist";
        QMessageBox::warning(this, tr("Ошибка"), tr("Невозможно найти категорию!"));
        return;
    }
    QSet<AchievementID> categoryAchievements;
    for(int i = 0; i < ui->ListWidgetCategory->count(); ++i) {
        if (auto item = dynamic_cast<QListWidgetAchievement*>(ui->ListWidgetCategory->item(i))) {
            categoryAchievements.insert(item->achievement_->apiName());
        }
    }
    currentCategory_->clear();
    *currentCategory_ += (categoryAchievements);
    currentCategory_->root()->save();
    emit s_categoriesIsUpdated(true);

    buttonCancel_Clicked();
}
#define CategoryEnd }
