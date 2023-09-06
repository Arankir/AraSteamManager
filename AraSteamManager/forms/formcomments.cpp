#include "formcomments.h"
#include "ui_formcomments.h"

FormComments::FormComments(QWidget *parent): Form(parent), ui(new Ui::FormComments) {
    ui->setupUi(this);
}

FormComments::FormComments(const ProfileID &aId, const SGame &game, const SAchievement &achievement, QWidget *parent) :
    Form(parent), ui(new Ui::FormComments), game_(game), achievement_(achievement), profileId_(aId) {
    ui->setupUi(this);
    init();
}

FormComments::~FormComments() {
    delete ui;
}

void FormComments::setData(const ProfileID &aId, const SGame &aGame, const SAchievement &aAchievement) {
    game_ = aGame;
    achievement_ = aAchievement;
    profileId_ = aId;
    init();
}

void FormComments::init() {
    QStringList comment;
    if (achievement_ == SAchievement()) {
        GameComments list(profileId_);
        auto iterator = std::find_if(list.begin(),
                                     list.end(),
                                     [this](const GameComment &gameComment) {
                                        return gameComment.gameId() == game_.appId();
                                    });
        if (iterator != list.end()) {
            comment = (*iterator).comment();
        }
    } else {
        QString toolTip = textToToolTip("<b>" + achievement_.displayName() + "</b>\n" +
                                        achievement_.description() + "\n" +
                                        (achievement_.achieved() ?
                                             tr("<font color=\"#00dd00\">Получено: %1</font>").arg(achievement_.unlockTime().toString(Settings::dateTimeFormat())) :
                                             tr("<font color=\"#dd0000\">Не получено</font>"))
                                        ).replace("\n", "<br>");
        ui->labelIcon->setPixmap(achievement_.icon(game_.appId()).scaled(32, 32));
        ui->labelIcon->setToolTip(toolTip);
        QList<AchievementComment> list = AchievementComments(profileId_).getCommentsFromGame(profileId_, game_.appId());
        auto iterator = std::find_if(list.begin(),
                                     list.end(),
                                     [this](const AchievementComment &achievementComment) {
                                        return achievementComment.achievementId() == achievement_.apiName();
                                    });
        if (iterator != list.end()) {
            comment = (*iterator).comment();
        }
    }

    ui->LabelGameTitle->setText(game_.name());
    ui->labelGameIcon->setPixmap(game_.pixmapIcon());
    SProfile profile = SProfile::load(profileId_);
    ui->LabelProfileName->setText(profile.personaName());
    ui->labelProfileIcon->setPixmap(profile.pixmapAvatar().scaled(32, 32));
    ui->TextEditComment->setPlainText(comment.join('\n'));
}

void FormComments::on_ButtonCancel_clicked() {
    close();
}

void FormComments::on_ButtonApply_clicked() {
    QStringList comment = ui->TextEditComment->toPlainText().split('\n');

    if (achievement_ == SAchievement()) {
        GameComments comments(profileId_);
        auto iterator = std::find_if(comments.begin(),
                                     comments.end(),
                                     [=, this](const GameComment &lComment) {
                                        return lComment.gameId() == game_.appId();
                                     });
        if (iterator != comments.end()) {
            comments.setComment(profileId_, game_.appId(), comment);
        } else {
            comments.append(GameComment(game_.appId(), game_.name(), game_.imgIconUrl(), profileId_, comment));
        }
//        GameComment::save(_profile, GameComment(_game.appId(), _profile, comment));
    } else {
        AchievementComments comments(profileId_);
        auto iterator = std::find_if(comments.begin(),
                                     comments.end(),
                                     [=, this](const AchievementComment &lComment) {
                                        return lComment.gameId() == game_.appId() && lComment.achievementId() == achievement_.apiName();
                                     });
        if (iterator != comments.end()) {
            comments.setComment(profileId_, game_.appId(), achievement_.apiName(), comment);
        } else {
            comments.append(AchievementComment(profileId_, game_.appId(), game_.name(), game_.imgIconUrl(), achievement_.apiName(), achievement_.displayName(), achievement_.iconPath(), comment));
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

//void FormComments::updateSettings(QFlags<changedSettings> aSettings) {
//    if (aSettings.testFlag(changedSettings::theme)) {
//        updateIcons();
//    }
//}
