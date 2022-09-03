#include "formcategoriesedit.h"
#include "ui_formcategoriesedit.h"

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
    _achievements = aAchievements;
    achievementsToUi();
}

void FormCategoriesEdit::setVisibleItems(const QList<QString> &aItems) {
    _visibleAchievements = aItems;
    updateHiddenItems();
}

void FormCategoriesEdit::achievementsToUi() {
    ui->ListWidgetAll->clear();
    ui->ListWidgetCategory->clear();
    for (auto &achievement: _achievements) {
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
        const QString apiName = achievement->_achievement->apiName();
        auto iterator = std::find_if(_achievements.begin(),
                                     _achievements.end(),
                                     [=](const SAchievement &achievement) {
                                        return achievement.apiName() == apiName;
                                     });
        if (iterator != _achievements.end()) {
            return iterator - _achievements.begin();
        }
    }
    return -1;
}

void FormCategoriesEdit::updateHiddenItems() {
    for(int row = 0; row < ui->ListWidgetAll->count(); ++row) {
        auto achievement = dynamic_cast<QListWidgetAchievement*>(ui->ListWidgetAll->item(row));
        if (achievement != nullptr) {
            QString apiName = achievement->_achievement->apiName();
            bool isVisible = std::any_of(_visibleAchievements.begin(),
                                        _visibleAchievements.end(),
                                        [=](const QString &api) {
                                            return api == apiName;
                                        });
            ui->ListWidgetAll->setRowHidden(row, !isVisible);
        }

    }
}

void FormCategoriesEdit::changeCategory(Category *aCategory) {
    _currentCategory = aCategory;
    ui->labelCategoryTitle->setText(_currentCategory->title());
    ui->ListWidgetAll->clear();
    ui->ListWidgetCategory->clear();
    auto achievementList = static_cast<QSet<AchievementID> >(*aCategory);
    for(auto &achievement: _achievements) {
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
    if (_currentCategory == nullptr) {
        qWarning() << "on apply category does not exist";
        QMessageBox::warning(this, tr("Ошибка"), tr("Невозможно найти категорию!"));
        return;
    }
    QSet<AchievementID> categoryAchievements;
    for(int i = 0; i < ui->ListWidgetCategory->count(); ++i) {
        if (auto item = dynamic_cast<QListWidgetAchievement*>(ui->ListWidgetCategory->item(i))) {
            categoryAchievements.insert(item->_achievement->apiName());
        }
    }
    _currentCategory->clear();
    *_currentCategory += (categoryAchievements);
    _currentCategory->root()->save();
    emit s_categoriesIsUpdated(true);

    buttonCancel_Clicked();
}
#define CategoryEnd }
