#include "achievementcompletedpiechart.h"
#include "classes/common/theme.h"

AchievementCompletedPieChart::AchievementCompletedPieChart() {
    noAchievements_ = addSlice(QColor(20,  20,  20));
    notStarted_ = addSlice(QColor(178, 50,  50));
    started_ = addSlice(QColor(205, 203, 31));
    completed_ = addSlice(QColor(85,  181, 62));

    connect(noAchievements_,&QPieSlice::clicked, this, [&]() {emit s_noAchievementsClicked();});
    connect(notStarted_,    &QPieSlice::clicked, this, [&]() {emit s_notStartedClicked();});
    connect(started_,       &QPieSlice::clicked, this, [&]() {emit s_startedClicked();});
    connect(completed_,     &QPieSlice::clicked, this, [&]() {emit s_completedClicked();});

    retranslate();
    updateTheme();
}

void AchievementCompletedPieChart::setNoAchievements(int aCount) {
    noAchievements_->setValue(aCount);
    slicesValueUpdated();
}

void AchievementCompletedPieChart::setNotStarted(int aCount) {
    notStarted_->setValue(aCount);
    slicesValueUpdated();
}

void AchievementCompletedPieChart::setStarted(int aCount) {
    started_->setValue(aCount);
    slicesValueUpdated();
}

void AchievementCompletedPieChart::setCompleted(int aCount) {
    completed_->setValue(aCount);
    slicesValueUpdated();
}

void AchievementCompletedPieChart::slicesValueUpdated() {
    int sum = 0;
    sum += noAchievements_->value();
    sum += notStarted_->value();
    sum += started_->value();
    sum += completed_->value();

    noAchievements_->setLabel(QString("%1%").arg(100.0 * noAchievements_->value() / sum, 0, 'f', 2));
    notStarted_->setLabel(QString("%1%").arg(100.0 * notStarted_->value() / sum, 0, 'f', 2));
    started_->setLabel(QString("%1%").arg(100.0 * started_->value() / sum, 0, 'f', 2));
    completed_->setLabel(QString("%1%").arg(100.0 * completed_->value() / sum, 0, 'f', 2));
}

void AchievementCompletedPieChart::clear() {
    noAchievements_->setValue(0);
    notStarted_->setValue(0);
    started_->setValue(0);
    completed_->setValue(0);
    slicesValueUpdated();
}

void AchievementCompletedPieChart::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateTheme();
    }
    PieChart::updateSettings(aSettings);
}

void AchievementCompletedPieChart::changeEvent(QEvent *aEvent) {
    if(aEvent->type() == QEvent::LanguageChange) {
        retranslate();
    }
    PieChart::changeEvent(aEvent);
}

void AchievementCompletedPieChart::retranslate() {
    noAchievements_->setLabel(tr("Нет достижений"));
    notStarted_->setLabel(tr("Не начато"));
    started_->setLabel(tr("Начато"));
    completed_->setLabel(tr("Закончено"));
}

void AchievementCompletedPieChart::updateIcons() {

}

void AchievementCompletedPieChart::updateTheme() {
    updateIcons();
}
