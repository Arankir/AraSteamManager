#include "formachievementwidget.h"
#include "ui_formachievementwidget.h"

FormAchievementWidget::FormAchievementWidget(SAchievement *aAchievement, int aGameId, QWidget *parent): QWidget(parent), ui(new Ui::FormAchievementWidget), _achievement(aAchievement),
_gameId(aGameId) {
    ui->setupUi(this);
    ui->LabelIcon->setPixmap(_achievement->getIcon(_gameId).scaled(32, 32));
    ui->LabelTitle->setText(_achievement->_displayName);
}

FormAchievementWidget::~FormAchievementWidget() {
    delete ui;
}


