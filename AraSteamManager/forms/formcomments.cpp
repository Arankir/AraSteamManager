#include "formcomments.h"
#include "ui_formcomments.h"

FormComments::FormComments(const SProfile &profile, const SGame &game, SAchievement *achievement, QWidget *parent) :
    QWidget(parent), ui(new Ui::FormComments), _game(game), _achievement(achievement), _profile(profile), _comment(_profile.steamID()) {
    ui->setupUi(this);
    init();
}

FormComments::~FormComments() {
    qInfo() << "Форма комментариев удалилась";
    delete ui;
}

void FormComments::init() {
    QStringList comment;
    if (_achievement == nullptr) {
        ui->FrameAchievement->setVisible(false);
        comment = _comment.getGameComment(_game.sAppId(), _profile.steamID()).comment();
    } else {
        ui->LabelAchievementTitle->setText(_achievement->displayName());
        ui->LabelAchievementDescription->setText(_achievement->description());
        ui->LabelAchievementAchieved->setText(_achievement->achieved() == 1 ? tr("Получено %1").arg(_achievement->unlockTime().toString("yyyy.MM.dd hh:mm")) : tr("Не получено"));
        ui->FrameAchievement->setVisible(true);
        comment = _comment.getAchievementComment(_profile.steamID(), _game.sAppId(), _achievement->apiName()).comment();
    }

    ui->LabelGameTitle->setText(_game.name());
    ui->LabelProfileName->setText(_profile.personaName());
    ui->TextEditComment->setPlainText(comment.join('\n'));
}

void FormComments::on_ButtonCancel_clicked() {
    emit s_updateComments(false);
    parentWidget()->parentWidget()->close();
}

void FormComments::on_ButtonApply_clicked() {
    QStringList comment = ui->TextEditComment->toPlainText().split('\n');

    if (_achievement == nullptr) {
        _comment.setGameComment(_game.sAppId(), _profile.steamID(), comment);
    } else {
        _comment.setAchievementComment(_profile.steamID(), _game.sAppId(), _achievement->apiName(), comment);
    }

    _comment.save();
    emit s_updateComments(true);
    parentWidget()->parentWidget()->close();
}
