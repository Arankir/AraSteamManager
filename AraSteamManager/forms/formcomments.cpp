#include "formcomments.h"
#include "ui_formcomments.h"

FormComments::FormComments(QWidget *parent): Form(parent), ui(new Ui::FormComments) {
    ui->setupUi(this);
}

FormComments::FormComments(const SProfile &profile, const SGame &game, const SAchievement &achievement, QWidget *parent) :
    Form(parent), ui(new Ui::FormComments), _game(game), _achievement(achievement), _profile(profile) {
    ui->setupUi(this);
    init();
}

FormComments::~FormComments() {
    qInfo() << "Форма комментариев удалилась";
    delete ui;
}

void FormComments::setData(const SProfile &aProfile, const SGame &aGame, const SAchievement &aAchievement) {
    _game = aGame;
    _achievement = aAchievement;
    _profile = aProfile;
    init();
}

void FormComments::init() {
    QStringList comment;
    if (_achievement == SAchievement()) {
        ui->FrameAchievement->setVisible(false);
        auto list = GameComment::load(_profile.steamID());
        auto iterator = std::find_if(list.begin(),
                                     list.end(),
                                     [=](const GameComment &gameComment) {
                                        return gameComment.gameId() == _game.sAppId();
                                    });
        if (iterator != list.end()) {
            comment = (*iterator).comment();
        }
    } else {
        ui->LabelAchievementTitle->setText(_achievement.displayName());
        ui->LabelAchievementDescription->setText(_achievement.description());
        ui->LabelAchievementAchieved->setText(_achievement.achieved() == 1 ? tr("Получено %1").arg(_achievement.unlockTime().toString(Settings::dateTimeFormatShort())) : tr("Не получено"));
        ui->FrameAchievement->setVisible(true);
        auto list = AchievementComment::load(_profile.steamID(), _game.sAppId());
        auto iterator = std::find_if(list.begin(),
                                     list.end(),
                                     [=](const AchievementComment &achievementComment) {
                                        return achievementComment.achievementId() == _achievement.apiName();
                                    });
        if (iterator != list.end()) {
            comment = (*iterator).comment();
        }
    }

    ui->LabelGameTitle->setText(_game.name());
    ui->LabelProfileName->setText(_profile.personaName());
    ui->TextEditComment->setPlainText(comment.join('\n'));
}

void FormComments::on_ButtonCancel_clicked() {
    close();
}

void FormComments::on_ButtonApply_clicked() {
    QStringList comment = ui->TextEditComment->toPlainText().split('\n');

    if (_achievement == SAchievement()) {
        GameComment::save(_profile.steamID(), GameComment(_game.sAppId(), _profile.steamID(), comment));
    } else {
        AchievementComment::save(_profile.steamID(), _game.sAppId(), AchievementComment(_profile.steamID(), _game.sAppId(), _achievement.apiName(), comment));
    }

    emit s_updateComments();
    close();
}

void FormComments::retranslate() {
    ui->retranslateUi(this);
//TODO не обнавляется описание ачивки
}

void FormComments::updateIcons() {

}

void FormComments::updateSettings() {

}
