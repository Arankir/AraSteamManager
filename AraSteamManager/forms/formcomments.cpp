#include "formcomments.h"
#include "ui_formcomments.h"

FormComments::FormComments(const SProfile &profile, const SGame &game, SAchievement *achievement, QWidget *parent) :
    QWidget(parent), ui(new Ui::FormComments), _game(game), _achievement(achievement), _profile(profile), _comment(_profile._steamID) {
    ui->setupUi(this);
    init();
}

FormComments::~FormComments() {
    delete ui;
}

void FormComments::init() {
    QStringList comment;
    if (_achievement == nullptr) {
        ui->FrameAchievement->setVisible(false);
        comment = _comment.getGameComment(_game.sAppId(), _profile._steamID).getComment();
    } else {
        ui->LabelAchievementTitle->setText(_achievement->_displayName);
        ui->LabelAchievementDescription->setText(_achievement->_description);
        ui->LabelAchievementAchieved->setText(_achievement->_achieved == 1 ? tr("Получено %1").arg(_achievement->_unlockTime.toString("yyyy.MM.dd hh:mm")) : tr("Не получено"));
        ui->FrameAchievement->setVisible(true);
        comment = _comment.getAchievementComment(_profile._steamID, _game.sAppId(), _achievement->_apiName).getComment();
    }

    ui->LabelGameTitle->setText(_game.name());
    ui->LabelProfileName->setText(_profile._personaName);
    ui->TextEditComment->setPlainText(comment.join('\n'));
}

void FormComments::on_ButtonCancel_clicked() {
    emit s_updateComments(false);
    close();
}

void FormComments::on_ButtonApply_clicked() {
    QStringList comment = ui->TextEditComment->toPlainText().split('\n');

    if (_achievement == nullptr) {
        _comment.setGameComment(_game.sAppId(), _profile._steamID, comment);
    } else {
        _comment.setAchievementComment(_profile._steamID, _game.sAppId(), _achievement->_apiName, comment);
    }

    _comment.save();
    emit s_updateComments(true);
    close();
}
