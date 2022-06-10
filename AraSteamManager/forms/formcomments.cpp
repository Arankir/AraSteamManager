#include "formcomments.h"
#include "ui_formcomments.h"

FormComments::FormComments(QWidget *parent): Form(parent), ui(new Ui::FormComments) {
    ui->setupUi(this);
}

FormComments::FormComments(const ProfileID &aId, const SGame &game, const SAchievement &achievement, QWidget *parent) :
    Form(parent), ui(new Ui::FormComments), _game(game), _achievement(achievement), _profile(aId) {
    ui->setupUi(this);
    init();
}

FormComments::~FormComments() {
    delete ui;
}

void FormComments::setData(const ProfileID &aId, const SGame &aGame, const SAchievement &aAchievement) {
    _game = aGame;
    _achievement = aAchievement;
    _profile = aId;
    init();
}

void FormComments::init() {
    QStringList comment;
    if (_achievement == SAchievement()) {
        GameComments list(_profile);
        auto iterator = std::find_if(list.begin(),
                                     list.end(),
                                     [this](const GameComment &gameComment) {
                                        return gameComment.gameId() == _game.appId();
                                    });
        if (iterator != list.end()) {
            comment = (*iterator).comment();
        }
    } else {
        QString toolTip = textToToolTip("<b>" + _achievement.displayName() + "</b>\n" +
                                        _achievement.description() + "\n" +
                                        (_achievement.achieved() ?
                                             tr("<font color=\"#00dd00\">Получено: %1</font>").arg(_achievement.unlockTime().toString(Settings::dateTimeFormat())) :
                                             tr("<font color=\"#dd0000\">Не получено</font>"))
                                        ).replace("\n", "<br>");
        ui->labelIcon->setPixmap(_achievement.icon(_game.appId()).scaled(32, 32));
        ui->labelIcon->setToolTip(toolTip);
        auto list = AchievementComments(_profile).getCommentsFromGame(_profile, _game.appId());
        auto iterator = std::find_if(list.begin(),
                                     list.end(),
                                     [this](const AchievementComment &achievementComment) {
                                        return achievementComment.achievementId() == _achievement.apiName();
                                    });
        if (iterator != list.end()) {
            comment = (*iterator).comment();
        }
    }

    ui->LabelGameTitle->setText(_game.name());
    ui->labelGameIcon->setPixmap(_game.pixmapIcon());
    auto profile = SProfile::load(_profile);
    ui->LabelProfileName->setText(profile.personaName());
    ui->labelProfileIcon->setPixmap(profile.pixmapAvatar().scaled(32, 32));
    ui->TextEditComment->setPlainText(comment.join('\n'));
}

void FormComments::on_ButtonCancel_clicked() {
    close();
}

void FormComments::on_ButtonApply_clicked() {
    QStringList comment = ui->TextEditComment->toPlainText().split('\n');

    if (_achievement == SAchievement()) {
        GameComments comments(_profile);
        auto iterator = std::find_if(comments.begin(),
                                     comments.end(),
                                     [=, this](const GameComment &lComment) {
                                        return lComment.gameId() == _game.appId();
                                     });
        if (iterator != comments.end()) {
            comments.setComment(_profile, _game.appId(), comment);
        } else {
            comments.append(GameComment(_game.appId(), _profile, comment));
        }
//        GameComment::save(_profile, GameComment(_game.appId(), _profile, comment));
    } else {
        AchievementComments comments(_profile);
        auto iterator = std::find_if(comments.begin(),
                                     comments.end(),
                                     [=, this](const AchievementComment &lComment) {
                                        return lComment.gameId() == _game.appId() && lComment.achievementId() == _achievement.apiName();
                                     });
        if (iterator != comments.end()) {
            comments.setComment(_profile, _game.appId(), _achievement.apiName(), comment);
        } else {
            comments.append(AchievementComment(_profile, _game.appId(), _achievement.apiName(), comment));
        }
//        AchievementComment::save(_profile, _game.appId(), AchievementComment(_profile, _game.appId(), _achievement.apiName(), comment));
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

void FormComments::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}
