#ifndef FORMFAVORITES_H
#define FORMFAVORITES_H

#include "form.h"
#include "classes/files/favorites.h"
#include "classes/steamApi/structures/sprofile.h"

namespace FormFavoriteData {
    namespace tableGames {
        enum Columns {
            profileId = 0,
            gameId = 1,
            icon = 2,
            title = 3
        };
    }
    namespace tableProfiles {
        enum Columns {
            profileId = 0,
            icon = 1,
            title = 2,
            status = 3
        };
    }
    namespace treeAchievements {
        enum Columns {
            profile = 0,
            achievementId = 1,
            icon = 0,
            title = 2,
            description = 3,
            achieved = 4
        };
    }
}

namespace Ui {
class FormFavorites;
}

class FormFavorites : public Form {
    Q_OBJECT

public slots:
    void init();
    bool isInit();
    bool isLoaded();

    void updateIcons() override;
    void retranslate() override;
public:
    explicit FormFavorites(QWidget *parent = nullptr);
    ~FormFavorites();

    void update();
signals:
    void s_showAchievements(const ProfileID &, const SGame &);
    void s_goToProfile(const ProfileID &);

protected slots:
    QMenu *createMenuGames(const GameID &gameId, const ProfileID &profileId);
    QMenu *createMenuProfiles(const ProfileID &profileId);
    void goToGame(const GameID &gameId, const ProfileID &profileId);
    QMenu *createMenuAchievements(const GameID &gameId, const ProfileID &profileId, const AchievementID &achievementId);
private slots:
    SProfiles getProfilesFavoriteAchievements();
    void updateSettings(QFlags<changedSettings> settings) override;
private:
    Ui::FormFavorites *ui;

    FavoriteProfiles friendsFavorites_;
    FavoriteGames gamesFavorites_;
//    FavoriteAchievementsGames achievementsFavorites_;
    FavoriteAchievements achievementsFavorites_;

    void updateGames();
    void updateFriends();
    void updateAchievements();
};

#endif // FORMFAVORITES_H
