#ifndef FORMFAVORITES_H
#define FORMFAVORITES_H

#include <QWidget>
#include "classes/files/favorites.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sachievements.h"
#include "classes/network/requestimage.h"

enum tableFavoritesColumns {
    ColumnFavoritesID       = 0,
    ColumnFavoritesIcon     = 1,
    ColumnFavoritesName     = 2,
    ColumnFavoritesStatus   = 3,
    ColumnFavoritesIsPublic = 4,
    ColumnFavoritesGoTo     = 5,
    ColumnFavoritesFavorite = 6,
    ColumnFavoritesCount    = 7
};

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
    QMenu *createMenuGames(const GameID &aGameId, const ProfileID &aProfileId);
    QMenu *createMenuProfiles(const ProfileID &aProfileId);
    void goToGame(const GameID &aGameId, const ProfileID &aProfileId);
    QMenu *createMenuAchievements(const GameID &aGameId, const ProfileID &aProfileId, const AchievementID &aAchievementId);
private slots:
    SProfiles getProfilesFavoriteAchievements();
private:
    Ui::FormFavorites *ui;

    FavoriteProfiles _friendsFavorites;
    FavoriteGames _gamesFavorites;
    FavoriteAchievementsGames _achievementsFavorites;

    void updateGames();
    void updateFriends();
    void updateAchievements();
};

#endif // FORMFAVORITES_H
